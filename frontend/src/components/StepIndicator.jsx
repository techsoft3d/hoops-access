const titles = {
  2: "Structured output",
  3: "3D result",
};

const steps = {
  raw: 1,
  structured: 2,
  "3D": 3,
};

export default function StepIndicator({ step, format }) {
  const total = 3;
  return (
    <div className="mb-6 flex items-center justify-between flex-wrap gap-2 border-b border-hairline pb-4">
      <div className="flex items-baseline gap-3">
        <span className="font-mono text-sm font-bold text-brand">
          {String(steps[step]).padStart(2, "0")}
          <span className="font-normal text-mutedtext"> / {String(total).padStart(2, "0")}</span>
        </span>
        <span className="text-sm font-semibold text-darkneutral">
          {steps[step] === 1 ? `Raw ${format.label} input file` : titles[steps[step]]}
        </span>
      </div>
      <div className="flex items-center gap-1.5">
        {Array.from({ length: total }).map((_, i) => (
          <span
            key={i}
            className={
              "h-1.5 rounded-full transition-all " +
              (i + 1 === steps[step] ? "w-6 bg-brand" : 
                i + 1 < steps[step] ? "w-1.5 bg-brand/50" : 
                "w-1.5 bg-hairline")
            }
          />
        ))}
      </div>
    </div>
  );
}