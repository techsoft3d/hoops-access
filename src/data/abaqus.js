export const abaqus = {
  id: 'abaqus',
  label: 'ABAQUS',
  filename: 'chassis_assembly.inp',
  keywords: ['*NODE', '*ELEMENT', '*SHELL', 'SECTION,', '*MATERIAL', '*ELASTIC', 'TYPE=S4', 'ELSET=SHELL1', 'MATERIAL=STEEL', 'NAME=STEEL', 'NSET=ALL'],
  rawLines: [
    { text: '** ABAQUS INPUT DECK — CHASSIS_ASSEMBLY.inp', type: 'comment' },
    { text: '** NODE DEFINITIONS', type: 'comment' },
    { text: '*NODE, NSET=ALL', type: 'code' },
    { text: '1, 0.0, 0.0, 0.0', type: 'code' },
    { text: '2, 1.0, 0.0, 0.0', type: 'code' },
    { text: '3, 1.0, 0.5, 0.0', type: 'code' },
    { text: '4, 0.0, 0.5, 0.0', type: 'code' },
    { text: '5, 0.0, 0.0, 0.4', type: 'code' },
    { text: '** ELEMENT CONNECTIVITY', type: 'comment' },
    { text: '*ELEMENT, TYPE=S4, ELSET=SHELL1', type: 'code' },
    { text: '1, 1, 2, 3, 4', type: 'code' },
    { text: '2, 4, 3, 6, 5', type: 'code' },
    { text: '** SHELL PROPERTIES', type: 'comment' },
    { text: '*SHELL SECTION, ELSET=SHELL1, MATERIAL=STEEL', type: 'code' },
    { text: '0.004', type: 'code' },
    { text: '** MATERIAL DEFINITION', type: 'comment' },
    { text: '*MATERIAL, NAME=STEEL', type: 'code' },
    { text: '*ELASTIC', type: 'code' },
    { text: '2.1E5, 0.30', type: 'code' },
  ],

  tree: [
    {
      label: 'Part: Chassis',
      nodeIds: [1, 2, 3, 4, 5],
      children: [
        { label: 'Shell set SHELL1 (elem 1)', nodeIds: [1, 2, 3] },
        { label: 'Shell set SHELL1 (elem 2)', nodeIds: [4, 5] },
      ],
    },
    {
      label: 'Part: Engine mount',
      nodeIds: [6, 7, 8, 9],
      children: [
        { label: 'Shell set SHELL2', nodeIds: [6, 7, 8, 9] },
      ],
    },
    {
      label: 'Material: STEEL',
      nodeIds: [1, 2, 3, 4, 5, 6, 7, 8, 9],
      children: [
        { label: 'E = 2.1E5, ν = 0.30', nodeIds: [1, 2, 3, 4, 5, 6, 7, 8, 9] },
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