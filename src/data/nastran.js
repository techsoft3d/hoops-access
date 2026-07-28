export const nastran = {
  id: 'nastran',
  label: 'NASTRAN',
  raw: `GRID           1        0      0.0      0.0      0.0
GRID           2        0      1.0      0.0      0.0
GRID           3        0      1.0      1.0      0.0
CQUAD4         1        1       1       2       3
PSHELL         1        1      0.1
MAT1           1  30000000.            0.3`,
  rawCaption: 'Raw NASTRAN input file, model data as written by the solver',
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
  apiCall: 'Model.GetDataset("X.N")',
  contour: { resultName: 'Von Mises stress', placeholder: true },
};