export default function PrimaryButton({ children, onClick }) {
  return (
    <button
      onClick={onClick}
      className="text-[13px] font-semibold uppercase tracking-widest text-white px-5 sm:px-7 py-2.5 sm:py-3 bg-brand hover:bg-brand-hover transition-colors"
    >
      {children}
    </button>
  );
}