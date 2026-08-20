import PrimaryButton from './PrimaryButton';
import { useState, useEffect } from 'react';

function highlightLine(text) {
  return text.split(/(\s+)/).map((token, i) => {
    if (/^-?\d/.test(token)) {
      return <span key={i} className="text-amber-400">{token}</span>;
    }
    return token;
  });
}

// Renders bytes the way a real hex editor would: offset | hex bytes | ascii,
// 16 bytes per row. Non-printable bytes show as "." in the ascii column.
function formatHexDump(bytes, maxBytes = 2048) {
  const lines = [];
  const limit = Math.min(bytes.length, maxBytes);

  for (let offset = 0; offset < limit; offset += 16) {
    const row = bytes.slice(offset, offset + 16);

    const offsetStr = offset.toString(16).padStart(8, '0');

    const hexStr = Array.from(row)
      .map((b) => b.toString(16).padStart(2, '0'))
      .join(' ')
      .padEnd(16 * 3 - 1, ' ');

    const asciiStr = Array.from(row)
      .map((b) => (b >= 32 && b <= 126 ? String.fromCharCode(b) : '.'))
      .join('');

    lines.push(`${offsetStr}  ${hexStr}  |${asciiStr}|`);
  }

  if (bytes.length > maxBytes) {
    lines.push(`... (${bytes.length - maxBytes} more bytes not shown)`);
  }

  return lines.join('\n');
}

export default function StepRawFile({ format, onNext, collapsed, onExpand, isExtracting, extractError }) {
  const [text, setText] = useState('');

  useEffect(() => {
    if (format.isBinary) {
      fetch(format.samplePath)
        .then((response) => response.arrayBuffer())
        .then((buffer) => setText(formatHexDump(new Uint8Array(buffer))));
    } else {
      fetch(format.samplePath)
        .then((response) => response.text())
        .then((data) => setText(data));
    }
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
        <div className="px-5 py-4 font-mono text-[13px] leading-relaxed overflow-x-auto whitespace-pre-wrap text-gray-300">
          {!text
            ? 'Loading...'
            : format.isBinary
              ? text
              : text.split('\n').map((line, i) => (
                  <div key={i}>{highlightLine(line)}</div>
                ))}
        </div>
      </div>

      <div className="mt-2.5 text-[11px] text-gray-400 font-mono">
        <div className="mb-1">
          {format.isBinary
            ? `Bytes of ${format.label} file, shown as hex`
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