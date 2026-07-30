export const ansys = {
  id: 'ansys',
  label: 'ANSYS',
  filename: 'chassis_assembly.dat',
  keywords: ['N,', 'ET,', 'R,', 'MP,', 'E,', 'EX', 'PRXY', 'SHELL181'],
  rawLines: [
    { text: '! ANSYS COMMAND INPUT — CHASSIS_ASSEMBLY.dat', type: 'comment' },
    { text: '! NODE DEFINITIONS', type: 'comment' },
    { text: 'N,1,0.0,0.0,0.0', type: 'code' },
    { text: 'N,2,1.0,0.0,0.0', type: 'code' },
    { text: 'N,3,1.0,0.5,0.0', type: 'code' },
    { text: 'N,4,0.0,0.5,0.0', type: 'code' },
    { text: 'N,5,0.0,0.0,0.4', type: 'code' },
    { text: '! ELEMENT TYPE AND PROPERTIES', type: 'comment' },
    { text: 'ET,1,SHELL181', type: 'code' },
    { text: 'R,1,0.004', type: 'code' },
    { text: '! MATERIAL DEFINITION', type: 'comment' },
    { text: 'MP,EX,1,2.1E5', type: 'code' },
    { text: 'MP,PRXY,1,0.30', type: 'code' },
    { text: '! ELEMENT CONNECTIVITY', type: 'comment' },
    { text: 'E,1,2,3,4', type: 'code' },
    { text: 'E,4,3,6,5', type: 'code' },
  ],

  tree: [
    {
      label: 'Part: Chassis',
      nodeIds: [1, 2, 3, 4, 5],
      children: [
        { label: 'Element type SHELL181 (elem 1)', nodeIds: [1, 2, 3] },
        { label: 'Element type SHELL181 (elem 2)', nodeIds: [4, 5] },
      ],
    },
    {
      label: 'Part: Engine mount',
      nodeIds: [6, 7, 8, 9],
      children: [
        { label: 'Element type SHELL181 (elem 3)', nodeIds: [6, 7, 8, 9] },
      ],
    },
    {
      label: 'Material 1',
      nodeIds: [1, 2, 3, 4, 5, 6, 7, 8, 9],
      children: [
        { label: 'EX = 2.1E5, PRXY = 0.30', nodeIds: [1, 2, 3, 4, 5, 6, 7, 8, 9] },
      ],
    },
  ],

  table: {
    columns: ['Node', 'X', 'Y', 'Z'],
    rows: [
      { node: 1, x: 0.0, y: 0.0, z: 0.0, highlight: true },
      { node: 2, x: 1.0, y: 0.0, z: 0.0 },
      { node: 3, x: 1.0, y: 0.5, z: 0.0 },
      { node: 4, x: 0.0, y: 0.5, z: 0.0 },
      { node: 5, x: 0.0, y: 0.0, z: 0.4 },
      { node: 6, x: 2.0, y: 0.0, z: 0.0 },
      { node: 7, x: 3.0, y: 0.0, z: 0.0 },
      { node: 8, x: 3.0, y: 0.5, z: 0.0 },
      { node: 9, x: 2.0, y: 0.5, z: 0.0 },
    ],
  },

  contour: {
    resultName: 'Von Mises stress',
    placeholder: true,
  },
};