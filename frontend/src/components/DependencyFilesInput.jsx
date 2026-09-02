// Some formats reference sibling files by their own internal directive
// Optional: most files are self-contained and never need this.
export default function DependencyFilesInput({ files, onChange }) {
  function handlePick(e) {
    const picked = Array.from(e.target.files || []);
    if (picked.length > 0) onChange([...files, ...picked]);
    e.target.value = '';
  }

  function removeAt(index) {
    onChange(files.filter((_, i) => i !== index));
  }

  return (
    <div className="flex flex-col items-center gap-2 mb-5 -mt-1">
      <label className="inline-flex items-center gap-1.5 text-[11px] font-semibold text-brand border border-dashed border-brand/50 rounded-full px-4 py-1.5 cursor-pointer hover:bg-brand/5 transition-colors">
        <span className="text-[13px] leading-none">+</span>
        Attach dependency files (for *include / INCLUDE references)
        <input type="file" multiple className="hidden" onChange={handlePick} />
      </label>

      {files.length > 0 && (
        <div className="flex flex-col gap-1 w-full max-w-150">
          {files.map((file, index) => (
            <div
              key={`${file.name}-${index}`}
              className="flex items-center gap-2 text-[11px] text-gray-600 bg-gray-50 border border-gray-200 rounded-md px-2.5 py-1.5"
            >
              <span className="truncate flex-1">{file.name}</span>
              <button
                type="button"
                onClick={() => removeAt(index)}
                aria-label={`Remove ${file.name}`}
                className="text-red-500 font-semibold shrink-0"
              >
                ×
              </button>
            </div>
          ))}
          {files.length > 1 && (
            <button
              type="button"
              onClick={() => onChange([])}
              className="self-center text-[11px] text-gray-400 hover:text-red-500 transition-colors"
            >
              Clear all
            </button>
          )}
        </div>
      )}
    </div>
  );
}
