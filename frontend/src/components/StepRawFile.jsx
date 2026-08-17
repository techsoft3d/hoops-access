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

export default function StepRawFile({ format, onNext, collapsed, onExpand, isExtracting, extractError }) {
  const [text, setText] = useState('');
   useEffect(() => {
      fetch(format.samplePath)
      .then(response => response.text())
      .then(data => setText(data));
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
        <div className="px-5 py-4 font-mono text-[13px] leading-relaxed overflow-x-auto  whitespace-pre-wrap text-gray-300">
         {text ? text.split('\n').map((line, i) => (
            <div key={i}>{highlightLine(line)}</div>
          )) : 'Loading...'}
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