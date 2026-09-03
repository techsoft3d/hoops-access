
const express = require('express');
const multer = require('multer');
const { execFile } = require('child_process');
const path = require('path');
const fs = require('fs');
const cors = require('cors');
const app = express();

app.use(express.static(path.join(__dirname, '../frontend/dist')));

app.use(cors());

const MAX_UPLOAD_BYTES = 250 * 1024 * 1024;

// Some formats reference sibling files.
// So every file in one request needs to land in the SAME directory, 
// with its ORIGINAL name intact, while still not colliding with other
// requests. A per-request subdirectory gets both at once.
const storage = multer.diskStorage({
  destination: (req, file, cb) => {
    if (!req.uploadDir) {
      req.uploadDir = path.join('uploads', `${Date.now()}-${Math.random().toString(36).slice(2)}`);
      fs.mkdirSync(req.uploadDir, { recursive: true });
    }
    cb(null, req.uploadDir);
  },
  filename: (req, file, cb) => {
    cb(null, file.originalname);
  },
});

const upload = multer({ storage, limits: { fileSize: MAX_UPLOAD_BYTES } });

app.post('/translate', upload.fields([{ name: 'file', maxCount: 1 }, { name: 'dependencies', maxCount: 20 }]), (req, res) => {

    const mainFile = req.files?.file?.[0];
    if (!mainFile) {
        return res.status(400).json({ error: 'No file uploaded' });
    }

    const cliPath = path.join(__dirname, 'native', 'bin', 'access_cli');
    const libDir = path.join(__dirname, 'native', 'lib');

    const ldLibraryPath = [
        path.join(libDir, 'abaqus-odb_api'),
        path.join(libDir, 'intelmkl', 'lib'),
        path.join(libDir, 'intelopenmp', 'lib'),
    ].join(':');

    execFile(cliPath, [mainFile.path], { env: { LD_LIBRARY_PATH: ldLibraryPath }, maxBuffer: MAX_UPLOAD_BYTES }, (err, stdout, stderr) => {
        fs.rm(req.uploadDir, { recursive: true, force: true }, (rmErr) => {
        if (rmErr)
            console.error('Failed to delete temp upload dir:', rmErr);
        });

        if (err) {
            console.error('access_cli failed:', stderr);
            return res.status(500).json({ error: 'access_cli failed', details: stderr});
        }

        try {
            const parsedData = JSON.parse(stdout);
            res.json(parsedData);
        } catch (parseErr) {
            console.error('Failed to parse access_cli output as JSON:', parseErr);
            res.status(500).json({ error: 'Invalid JSON from access_cli', rawOutput: stdout });
        }
    });

});

app.use((err, req, res, next) => {
    if (err instanceof multer.MulterError) {
        return res.status(400).json({ error: err.code === 'LIMIT_FILE_SIZE' ? 'File too large' : err.message });
    }
    next(err);
});

app.listen(8180, () => {
    console.log('Server running on http://localhost:8180');
});

