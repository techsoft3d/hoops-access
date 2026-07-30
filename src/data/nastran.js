export const nastran = {
  id: 'nastran',
  label: 'NASTRAN',
  filename: 'chassis_assembly.bdf',
  rawLines: [
    { text: '$ NASTRAN INPUT FILE — CHASSIS_ASSEMBLY.bdf', type: 'comment' },
    { text: '$ GRID POINT DEFINITIONS', type: 'comment' },
    { text: 'GRID     1     0     0.0     0.0     0.0', type: 'code' },
    { text: 'GRID     2     0     1.0     0.0     0.0', type: 'code' },
    { text: 'GRID     3     0     1.0     0.5     0.0', type: 'code' },
    { text: 'GRID     4     0     0.0     0.5     0.0', type: 'code' },
    { text: 'GRID     5     0     0.0     0.0     0.4', type: 'code' },
    { text: '$ ELEMENT CONNECTIVITY', type: 'comment' },
    { text: 'CQUAD4   1     1     1     2     3   4', type: 'code' },
    { text: 'CQUAD4   2     1     4     3     6   5', type: 'code' },
    { text: '$ SHELL PROPERTIES', type: 'comment' },
    { text: 'PSHELL   1     1     0.004', type: 'code' },
    { text: '$ MATERIAL DEFINITION', type: 'comment' },
    { text: 'MAT1     1     2.1E5   8.0E4   0.30   7.85E-9', type: 'code' },
  ],
  tree: [
    {
      label: 'Part: Chassis',
      children: [
        { label: 'Shell group 1', color: 'blue' },
        { label: 'Shell group 2', color: 'gray' },
      ],
    },
    { label: 'Part: Engine mount', collapsed: true },
  ],
  table: {
    columns: ['Node', 'X', 'Y', 'Z'],
    rows: [
      { node: 1, x: 0.0, y: 0.0, z: 0.0, highlight: true },
      { node: 2, x: 1.0, y: 0.0, z: 0.0 },
      { node: 3, x: 1.0, y: 1.0, z: 0.0 },
    ],
  },
  contour: { resultName: 'Von Mises stress', placeholder: true },
};