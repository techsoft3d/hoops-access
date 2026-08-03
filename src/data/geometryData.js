// geometryData.js
//
// This file holds ONLY the 3D geometry (node coordinates + element connectivity).
// It is intentionally separate from the file-browser UI data (nastran.js, ansys.js, etc.)
// so that sensitive/full mesh data never has to pass through the UI's table/tree/rawLines.
//
// The two files are linked by a shared contract:
//   - node ids here match the "node" column in each format's table.rows
//   - part labels here match the top-level "label" entries in each format's tree
//
// For this demo, all four formats (nastran/fluent/ansys/abaqus) describe the same
// fake chassis, so they share one geometry object. In real usage, each format's
// parser would produce its own geometry object with the same shape.

const chassisGeometry = {
  // nodeId -> [x, y, z]. Keys match table.rows[i].node in the UI files.
  nodes: {
    1: [0.0, 0.0, 0.0],
    2: [1.0, 0.0, 0.0],
    3: [1.0, 0.5, 0.0],
    4: [0.0, 0.5, 0.0],
    5: [0.0, 0.0, 0.4],
    6: [2.0, 0.0, 0.0],
    7: [3.0, 0.0, 0.0],
    8: [3.0, 0.5, 0.0],
    9: [2.0, 0.5, 0.0],
  },

  // One entry per part. "partRef" matches the top-level tree[i].partRef in the
  // UI files — it's the stable key, since the display label changes per format
  // (NASTRAN/ANSYS/ABAQUS say "Part: Chassis", FLUENT says "Domain: Fluid",
  // but both point at partRef: "chassis"). "elements" are lists of node ids
  // (not array indices — the converter below handles that translation).
  //
  // Note: each element only ever references nodes from within its own part.
  // Mixing nodes across parts (e.g. a chassis node + an engine-mount node in
  // the same element) produces a warped, physically nonsensical shape.
  parts: [
    {
      partRef: "chassis",
      label: "Chassis",
      elements: [
        [1, 2, 3, 4], // base plate (quad)
        [1, 4, 5],    // vertical flange (triangle)
      ],
    },
    {
      partRef: "engineMount",
      label: "Engine mount",
      elements: [
        [6, 7, 8], // mount panel A (triangle)
        [6, 8, 9], // mount panel B (triangle)
      ],
    },
  ],
};

// All four formats point at the same shape for now. Once you have real parsers,
// each key would hold its own geometry object built from that format's actual data.
export const geometryByFormat = {
  nastran: chassisGeometry,
  fluent: chassisGeometry,
  ansys: chassisGeometry,
  abaqus: chassisGeometry,
};

