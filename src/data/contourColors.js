// contourColors.js
//
// Single source of truth for the high/mid/low contour colors, so the 3D
// coloring and the legend swatches in StepResult3D can never drift apart.

export const CONTOUR_COLORS = {
  low: "#14b8a6", // TODO: swap for your exact tailwind "brand" hex if it differs
  mid: "#f5a623",
  high: "#e5484d",
};

/** Converts a "#rrggbb" string into an {r,g,b} object in the 0..1 range cee.Color3/Color4 expect. */
export function hexToUnitRgb(hex) {
  const clean = hex.replace("#", "");
  const r = parseInt(clean.slice(0, 2), 16) / 255;
  const g = parseInt(clean.slice(2, 4), 16) / 255;
  const b = parseInt(clean.slice(4, 6), 16) / 255;
  return { r, g, b };
}
