import PrimaryButton from './PrimaryButton';
import { useState, useEffect, useMemo } from 'react';

const PREVIEW_BYTES = 2048;

function looksBinary(bytes, sampleSize = 1024) {
  const sample = bytes.subarray(0, Math.min(bytes.length, sampleSize));
  if (sample.length === 0) 
    return false;

  let suspicious = 0;
  for (let i = 0; i < sample.length; i++) {
    const b = sample[i];
    if (b === 0) 
      return true;
    const isText = (b >= 32 && b <= 126) || b === 9 || b === 10 || b === 13;
    if (!isText) 
      suspicious++;
  }

  return suspicious / sample.length > 0.1;
}


function buildHexRows(bytes, totalBytes, maxBytes = PREVIEW_BYTES) {
  const rows = [];
  const limit = Math.min(bytes.length, maxBytes);

  for (let offset = 0; offset < limit; offset += 16) {
    const row = Array.from(bytes.slice(offset, offset + 16));
    rows.push({ offset, bytes: row });
  }

  return { rows, truncated: totalBytes > maxBytes, remaining: totalBytes - maxBytes };
}

function isPrintable(byte) {
  return byte >= 32 && byte <= 126;
}

function HexDump({ bytes, totalBytes = bytes.length }) {
  const { rows, truncated, remaining } = buildHexRows(bytes, totalBytes);

  return (
    <div>
      {rows.map((row) => (
        <div key={row.offset} className="flex gap-4">
          <span className="text-gray-600 select-none">
            {row.offset.toString(16).padStart(8, '0')}
          </span>
          <span className="flex-1">
            {row.bytes.map((b, i) => (
              <span
                key={i}
                className={isPrintable(b) ? 'text-amber-400' : 'text-gray-500'}
              >
                {b.toString(16).padStart(2, '0')}{' '}
              </span>
            ))}
            {/* pad out short final row so the ascii sidebar still lines up */}
            {Array.from({ length: 16 - row.bytes.length }).map((_, i) => (
              <span key={`pad-${i}`}>{'   '}</span>
            ))}
          </span>
          <span className="text-gray-600 select-none">|</span>
          <span>
            {row.bytes.map((b, i) => (
              <span
                key={i}
                className={isPrintable(b) ? 'text-amber-400' : 'text-gray-500'}
              >
                {isPrintable(b) ? String.fromCharCode(b) : '.'}
              </span>
            ))}
          </span>
          <span className="text-gray-600 select-none">|</span>
        </div>
      ))}
      {truncated && (
        <div className="text-gray-500 mt-1">... ({remaining} more bytes not shown)</div>
      )}
    </div>
  );
}

function TextPreview({ bytes, totalBytes = bytes.length, maxBytes = PREVIEW_BYTES }) {
  const limit = Math.min(bytes.length, maxBytes);
  const text = new TextDecoder('utf-8').decode(bytes.subarray(0, limit));
  const truncated = totalBytes > maxBytes;
  const remaining = totalBytes - maxBytes;

  return (
    <div>
      <pre className="whitespace-pre-wrap wrap-break-word font-mono">{text}</pre>
      {truncated && (
        <div className="text-gray-500 mt-1">... ({remaining} more bytes not shown)</div>
      )}
    </div>
  );
}

export default function StepRawFile({ format, uploadedFile, onNext, collapsed, onExpand, isExtracting, extractError }) {
  const [binaryBytes, setBinaryBytes] = useState(null);
  const [totalBytes, setTotalBytes] = useState(0);

  useEffect(() => {
      setBinaryBytes(null);
      if (uploadedFile) {
        uploadedFile.slice(0, PREVIEW_BYTES).arrayBuffer().then((buffer) => {
          setTotalBytes(uploadedFile.size);
          setBinaryBytes(new Uint8Array(buffer));
        });
      } else {
        fetch(format.samplePath)
          .then((response) => response.arrayBuffer())
          .then((buffer) => {
            setTotalBytes(buffer.byteLength);
            setBinaryBytes(new Uint8Array(buffer));
          });
      }
  }, [format, uploadedFile]);

  const isBinary = useMemo(() => 
    (binaryBytes ? looksBinary(binaryBytes) : false)
    ,[binaryBytes]);
  const filename = uploadedFile ? uploadedFile.name : format.filename;

  if (collapsed) {
    return (
      <div className="bg-gray-50 border border-gray-200 rounded-lg px-3.5 py-2 flex items-center gap-2.5 mb-4.5">
        <span className="text-[11px] text-gray-400 font-mono truncate">
          {filename}
        </span>
        <button
          onClick={onExpand}
          className="ml-auto text-[11px] font-semibold text-brand shrink-0"
        >
          Source ↑
        </button>
      </div>
    );
  }

  return (
    <div>
      <div className="bg-[#1a1a1a] rounded-lg overflow-hidden">
        {/* editor chrome header */}
        <div className="flex items-center px-4 py-2.5 border-b border-white/10">
          <div className="flex gap-1.5">
            <span className="w-2.5 h-2.5 rounded-full bg-[#e5484d]" />
            <span className="w-2.5 h-2.5 rounded-full bg-[#f5a623]" />
            <span className="w-2.5 h-2.5 rounded-full bg-[#3dd66b]" />
          </div>
          <span className="ml-auto text-[11px] text-gray-500 font-mono">
            {filename}
          </span>
        </div>

        {/* code body */}
        <div className="dark-scrollbar px-5 py-4 font-mono text-[13px] leading-relaxed overflow-x-auto overflow-y-auto whitespace-pre-wrap text-gray-300 max-h-190">
          {binaryBytes
            ? (isBinary
                ? <HexDump bytes={binaryBytes} totalBytes={totalBytes} />
                : <TextPreview bytes={binaryBytes} totalBytes={totalBytes} />)
            : 'Loading...'}
        </div>
      </div>

      <div className="mt-2.5 text-[11px] text-gray-400 font-mono">
        <div className="mb-1">
          {isBinary
            ? `Raw bytes of ${filename}, shown as hex — this file is binary`
            : `Contents of ${filename}, shown as text`}
        </div>
      </div>

      {extractError && (
        <p className="text-center text-[12px] text-red-500 mt-3">
          {extractError}
        </p>
      )}

      <div className="flex justify-center mt-6">
        <PrimaryButton onClick={onNext} disabled={isExtracting}>
          {isExtracting ? 'Extracting...' : 'Extract with HOOPS Access'}
        </PrimaryButton>
      </div>
    </div>
  );
}