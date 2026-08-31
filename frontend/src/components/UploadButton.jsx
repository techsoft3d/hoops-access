function UploadIcon() {
  return (
    <svg viewBox="0 0 24 24" className="w-4 h-4 shrink-0" fill="none" stroke="currentColor" strokeWidth="2" strokeLinecap="round" strokeLinejoin="round">
      <path d="M12 16V4M12 4l-4 4M12 4l4 4" />
      <path d="M4 20h16" />
    </svg>
  );
}

export default function UploadButton({ onUpload, isActive, fileName }) {
  return (
    <label className="inline-flex items-center justify-center gap-2 text-[13px] font-semibold uppercase tracking-widest text-white px-7 py-3 bg-brand hover:bg-brand-hover transition-colors cursor-pointer max-w-full">
      <UploadIcon />
      <span className={'truncate ' + (isActive ? 'normal-case tracking-normal' : '')}>
        {isActive ? fileName : 'Upload your own file'}
      </span>
      <input
        type="file"
        className="hidden"
        onChange={(e) => {
          const file = e.target.files?.[0];
          if (file) onUpload(file);
          e.target.value = '';
        }}
      />
    </label>
  );
}
