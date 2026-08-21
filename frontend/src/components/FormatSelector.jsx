import { formatList } from '../data';
import StepIndicator from './StepIndicator';

export default function FormatSelector({ activeId, onChange }) {
  return (
      <div className="flex items-center justify-center px-8 py-4 gap-4 mb-5">
      {formatList.map((format) => {
        const isActive = format.label === activeId;
        return (
          <button
            key={format.label}
            onClick={() => onChange(format.label)}
            className={
              'text-xs font-bold px-5.5 py-2.5 rounded-full transition-colors ' +
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