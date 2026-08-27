import { formatList } from '../data';
import StepIndicator from './StepIndicator';

export default function FormatSelector({ activeId, onChange, onUpload, isUploadActive, uploadedFileName }) {
  return (
      <div className="flex items-center justify-center px-8 py-4 gap-4 mb-5">
      {formatList.map((format) => {
        const isActive = !isUploadActive && format.label === activeId;
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
      <label
        className={
          'text-xs font-bold px-5.5 py-2.5 rounded-full transition-colors cursor-pointer truncate max-w-45 ' +
          (isUploadActive
            ? 'border-2 border-brand text-brand bg-white'
            : 'border border-gray-200 bg-gray-100 text-gray-500 hover:bg-gray-200')
        }
      >
        {isUploadActive ? uploadedFileName : 'Upload your own file'}
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
      </div>
  );
}