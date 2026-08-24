import PrimaryButton from './PrimaryButton';
import { useState, useEffect } from 'react';

// Turns raw bytes into structured rows (offset + 16 bytes each), 
// so each byte can be colored individually: 
// readable ASCII bytes in one color, 
// everything else dimmed.
function buildHexRows(bytes, maxBytes = 2048) {
  const rows = [];
  const limit = Math.min(bytes.length, maxBytes);

  for (let offset = 0; offset < limit; offset += 16) {
    const row = Array.from(bytes.slice(offset, offset + 16));
    rows.push({ offset, bytes: row });
  }

  return { rows, truncated: bytes.length > maxBytes, remaining: bytes.length - maxBytes };
}

function isPrintable(byte) {
  return byte >= 32 && byte <= 126;
}

function HexDump({ bytes }) {
  const { rows, truncated, remaining } = buildHexRows(bytes);

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

export default function StepRawFile({ format, onNext, collapsed, onExpand, isExtracting, extractError }) {
  const [binaryBytes, setBinaryBytes] = useState(null);

  useEffect(() => {
      setBinaryBytes(null);
      fetch(format.samplePath)
        .then((response) => response.arrayBuffer())
        .then((buffer) => setBinaryBytes(new Uint8Array(buffer)));
  }, [format]);

  if (collapsed) {
    return (
      <div className="bg-gray-50 border border-gray-200 rounded-lg px-3.5 py-2 flex items-center gap-2.5 mb-4.5">
        <span className="text-[11px] text-gray-400 font-mono truncate">
          {format.filename}
        </span>
        <button
          onClick={onExpand}
          className="ml-auto text-[11px] font-semibold text-brand shrink-0"
        >
          {format.label} source ↑
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
            {format.filename}
          </span>
        </div>

        {/* code body */}
        <div className="dark-scrollbar px-5 py-4 font-mono text-[13px] leading-relaxed overflow-x-auto overflow-y-auto whitespace-pre-wrap text-gray-300 max-h-190">
          {binaryBytes ? <HexDump bytes={binaryBytes} /> : 'Loading...'}
        </div>
      </div>

      <div className="mt-2.5 text-[11px] text-gray-400 font-mono">
        <div className="mb-1">
          {format.isBinary
            ? `Raw bytes of the ${format.label} file, shown as hex,the actual file is binary`
            : `Sample ${format.label} file`}
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