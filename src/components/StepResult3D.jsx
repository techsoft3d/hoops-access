import EnvisionViewer from "../envision/EnvisionViewer";
import { geometryByFormat, getScalarRange } from "../data/geometryData";

export default function StepResult3D({ format }) {
  const resultName = format.contour.resultName;
  const range = getScalarRange(geometryByFormat[format.id], resultName);

  return (
    <div>
      <div className="flex items-center gap-2.5 mb-3.5">
        <span className="ml-auto text-xs text-gray-600 border border-gray-200 rounded px-3 py-1">
          {resultName}
        </span>
      </div>

      <div className="bg-gray-100 rounded-lg h-[34rem] relative overflow-hidden">
        <EnvisionViewer formatId={format.id} resultName={resultName} />
      </div>

      <div className="flex justify-center items-center gap-2 mt-3.5">
        <span className="w-3.5 h-3.5 rounded-sm bg-[#e5484d]" />
        <span className="text-[11px] text-gray-400 mr-2.5">
          high{range ? ` (${range.max})` : ""}
        </span>
        <span className="w-3.5 h-3.5 rounded-sm bg-[#f5a623]" />
        <span className="text-[11px] text-gray-400 mr-2.5">mid</span>
        <span className="w-3.5 h-3.5 rounded-sm bg-brand" />
        <span className="text-[11px] text-gray-400">
          low{range ? ` (${range.min})` : ""} {resultName.toLowerCase()}
        </span>
      </div>
    </div>
  );
}