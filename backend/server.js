
const express = require('express');
const multer = require('multer');
const { execFile } = require('child_process');
const path = require('path');
const fs = require('fs');
const cors = require('cors');
const app = express();

app.use(cors());

const MAX_UPLOAD_BYTES = 250 * 1024 * 1024;

const storage = multer.diskStorage({
  destination: (req, file, cb) => {
    cb(null, 'uploads/');
  },
  filename: (req, file, cb) => {
    cb(null, Date.now() + '-' + file.originalname);
  },
});

const upload = multer({ storage, limits: { fileSize: MAX_UPLOAD_BYTES } });

app.post('/translate', upload.single('file'), (req, res) => {

      if (!req.file) {
        return res.status(400).json({ error: 'No file uploaded' });
    }

    const cliPath = path.join(__dirname, 'native', 'bin', 'access_cli');
    const libDir = path.join(__dirname, 'native', 'lib');

    const ldLibraryPath = [
        path.join(libDir, 'abaqus-odb_api'),
        path.join(libDir, 'intelmkl'),
        path.join(libDir, 'intelopenmp'),
    ].join(':');

    execFile(cliPath, [req.file.path], { env: { LD_LIBRARY_PATH: ldLibraryPath }, maxBuffer: MAX_UPLOAD_BYTES }, (err, stdout, stderr) => {
        fs.unlink(req.file.path, (unlinkErr) => {
        if (unlinkErr)
            console.error('Failed to delete temp file:', unlinkErr);
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

app.listen(3000, () => {
    console.log('Server running on http://localhost:3000');
});

