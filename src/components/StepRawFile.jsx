import PrimaryButton from './PrimaryButton';

// crude keyword highlighter: colors known NASTRAN keywords blue, numbers amber
function highlightLine(text) {
  const keywords = ['GRID', 'CQUAD4', 'PSHELL', 'MAT1'];
  return text.split(/(\s+)/).map((token, i) => {
    if (keywords.includes(token)) {
      return <span key={i} className="text-blue-400">{token}</span>;
    }
    if (/^-?\d/.test(token)) {
      return <span key={i} className="text-amber-400">{token}</span>;
    }
    return token;
  });
}

export default function StepRawFile({ format, onNext, collapsed, onExpand }) {
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
      <p className="text-[13px] font-light text-gray-600 mb-2.5 text-center">
        {format.rawCaption}
      </p>

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
        <div className="px-5 py-4 font-mono text-[13px] leading-relaxed overflow-x-auto">
          {format.rawLines.map((line, i) => (
            <div key={i} className="flex gap-4">
              <span className="text-gray-600 select-none w-5 text-right shrink-0">
                {String(i + 1).padStart(2, '0')}
              </span>
              <span
                className={
                  line.type === 'comment' ? 'text-green-500' : 'text-gray-300'
                }
              >
                {line.type === 'code' ? highlightLine(line.text) : line.text}
              </span>
            </div>
          ))}
        </div>
      </div>

      <div className="flex justify-center mt-6">
        <PrimaryButton onClick={onNext}>
          Extract with HOOPS Access
        </PrimaryButton>
      </div>
    </div>
  );
}