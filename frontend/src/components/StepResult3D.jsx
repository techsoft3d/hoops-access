import EnvisionViewer from "../envision/EnvisionViewer";

export default function StepResult3D({ geometryData }) {
  return (
    <div>
      <div className="bg-gray-100 rounded-lg h-136 relative overflow-hidden">
        {geometryData ? (
          <EnvisionViewer geometryData={geometryData} />
        ) : (
          <p className="flex items-center justify-center h-full text-[13px] text-gray-400">
            Waiting for Access to structure the file...
          </p>
        )}
      </div>
    </div>
  );
}