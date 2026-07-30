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
      children: [
        { label: 'Element type SHELL181', color: 'blue' },
      ],
    },
    { label: 'Part: Engine mount', collapsed: true },
  ],

  table: {
    columns: ['Node', 'X', 'Y', 'Z'],
    rows: [
      { node: 1, x: 0.0, y: 0.0, z: 0.0, highlight: true },
      { node: 2, x: 1.0, y: 0.0, z: 0.0 },
      { node: 3, x: 1.0, y: 0.5, z: 0.0 },
    ],
  },

  contour: {
    resultName: 'Von Mises stress',
    placeholder: true,
  },
};