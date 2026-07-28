import { formatList } from '../data';

export default function FormatSelector({ activeId, onChange }) {
  return (
    <div className="flex gap-2 mb-5">
      {formatList.map((format) => {
        const isActive = format.id === activeId;
        return (
          <button
            key={format.id}
            onClick={() => onChange(format.id)}
            className={
              'text-xs font-normal px-3.5 py-1.5 rounded-full transition-colors ' +
              (isActive
                ? 'border-2 border-brand text-brand bg-white'
                : 'border border-gray-200 bg-gray-100 text-gray-500 hover:bg-gray-200')
            }
          >
            {format.label}
          </button>
        );
      })}
    </div>
  );
}