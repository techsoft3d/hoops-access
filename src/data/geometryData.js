// geometryData.js
//
// This file holds ONLY the 3D geometry (node coordinates + element connectivity).
// It is intentionally separate from the file-browser UI data (nastran.js, ansys.js, etc.)
// so that sensitive/full mesh data never has to pass through the UI's table/tree/rawLines.
//
// The two files are linked by a shared contract:
//   - node ids here match the "node" column in each format's table.rows
//   - top-level parts here match tree[i].partRef in each format's tree (a stable key,
//     independent of the display label, since "Part: X" vs "Domain: X" differ by format)
//
// The object represented: a small engine-mount bracket assembly —
//   - Chassis: a flat mounting plate (bolts to the chassis rail)
//   - Engine mount: a raised rectangular boss welded on top of the plate
//     (this is what the engine actually sits on)

const bracketGeometry = {
  // nodeId -> [x, y, z]. Keys match table.rows[i].node in the UI files.
  nodes: {
    // Base plate corners (flat, z = 0)
    1: [0.0, -0.5, 0.0],
    2: [2.0, -0.5, 0.0],
    3: [2.0, 0.5, 0.0],
    4: [0.0, 0.5, 0.0],
    // Mounting boss — bottom corners (sits centered on the plate, z = 0)
    5: [0.7, -0.3, 0.0],
    6: [1.3, -0.3, 0.0],
    7: [1.3, 0.3, 0.0],
    8: [0.7, 0.3, 0.0],
    // Mounting boss — top corners (z = 0.4, i.e. the boss is 0.4m tall)
    9: [0.7, -0.3, 0.4],
    10: [1.3, -0.3, 0.4],
    11: [1.3, 0.3, 0.4],
    12: [0.7, 0.3, 0.4],
  },

  // One entry per part. "elements" are lists of node ids (not array indices —
  // buildEnvisionGeometry.js handles that translation). All elements here are
  // quads (4 nodes each) — a fabricated sheet-metal bracket modeled with shell
  // elements per face, which is standard practice for this kind of part.
  parts: [
    {
      partRef: "chassis",
      label: "Chassis",
      elements: [
        [1, 2, 3, 4], // base plate
      ],
    },
    {
      partRef: "engineMount",
      label: "Engine mount",
      elements: [
        [9, 10, 11, 12], // top face of the boss
        [5, 6, 10, 9],   // side wall A
        [6, 7, 11, 10],  // side wall B
        [7, 8, 12, 11],  // side wall C
        [8, 5, 9, 12],   // side wall D
      ],
    },
  ],
};

export const geometryByFormat = {
  nastran: bracketGeometry,
  fluent: bracketGeometry,
  ansys: bracketGeometry,
  abaqus: bracketGeometry,
};