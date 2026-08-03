import EnvisionViewer from "@envision/EnvisionViewer";

export default function StepResult3D({ format }) {
  return (
    <div>
      <div className="flex items-center gap-2.5 mb-3.5">
        <span className="ml-auto text-xs text-gray-600 border border-gray-200 rounded px-3 py-1">
          {format.contour.resultName} ▾
        </span>
      </div>

      <div className="bg-gray-100 rounded-lg h-75 relative overflow-hidden">
        <EnvisionViewer formatId={format.id} />
      </div>

      <div className="flex justify-center items-center gap-2 mt-3.5">
        <span className="w-3.5 h-3.5 rounded-sm bg-[#e5484d]" />
        <span className="text-[11px] text-gray-400 mr-2.5">high</span>
        <span className="w-3.5 h-3.5 rounded-sm bg-[#f5a623]" />
        <span className="text-[11px] text-gray-400 mr-2.5">mid</span>
        <span className="w-3.5 h-3.5 rounded-sm bg-brand" />
        <span className="text-[11px] text-gray-400">
          low {format.contour.resultName.toLowerCase()}
        </span>
      </div>
    </div>
  );
}