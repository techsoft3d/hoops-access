export const fluent = {
  id: 'fluent',
  label: 'FLUENT',
  filename: 'chassis_flow.cas',
  keywords: ['(10', '(12', '(13', '(0', '(1'],
  rawLines: [
    { text: '; FLUENT CASE FILE — CHASSIS_FLOW.cas', type: 'comment' },
    { text: '; Conjugate heat transfer study: engine mount bracket under airflow', type: 'comment' },
    { text: '; MESH HEADER (node indices in hex)', type: 'comment' },
    { text: '(10 (0 1 c 0 0 3))', type: 'code' },
    { text: '(12 (0 1 2 0 0))', type: 'code' },
    { text: '(13 (0 1 3 0 3))', type: 'code' },
    { text: '; NODE COORDINATES — base plate (wetted by cooling air)', type: 'comment' },
    { text: '(0.0 -0.5 0.0)', type: 'code' },
    { text: '(2.0 -0.5 0.0)', type: 'code' },
    { text: '(2.0 0.5 0.0)', type: 'code' },
    { text: '(0.0 0.5 0.0)', type: 'code' },
    { text: '; NODE COORDINATES — mounting boss (solid, no fluid contact)', type: 'comment' },
    { text: '(0.7 -0.3 0.0)', type: 'code' },
    { text: '(1.3 -0.3 0.0)', type: 'code' },
    { text: '(1.3 0.3 0.0)', type: 'code' },
    { text: '(0.7 0.3 0.0)', type: 'code' },
    { text: '(0.7 -0.3 0.4)', type: 'code' },
    { text: '(1.3 -0.3 0.4)', type: 'code' },
    { text: '(1.3 0.3 0.4)', type: 'code' },
    { text: '(0.7 0.3 0.4)', type: 'code' },
  ],

  tree: [
    {
      label: 'Domain: Fluid',
      partRef: 'chassis',
      nodeIds: [1, 2, 3, 4],
      children: [
        { label: 'Zone 1 (plate surface, wall)', nodeIds: [1, 2, 3] },
        { label: 'Zone 2 (cooling air inlet)', nodeIds: [4] },
      ],
    },
    {
      label: 'Domain: Solid',
      partRef: 'engineMount',
      nodeIds: [5, 6, 7, 8, 9, 10, 11, 12],
      children: [
        { label: 'Zone 3 (mounting boss)', nodeIds: [5, 6, 7, 8, 9, 10, 11, 12] },
      ],
    },
    {
      label: 'Boundary conditions',
      partRef: null,
      nodeIds: [1, 2, 3],
      children: [
        { label: 'Zone 1: no-slip wall', nodeIds: [1, 2, 3] },
      ],
    },
  ],

  table: {
    columns: ['Node', 'X', 'Y', 'Z'],
    rows: [
      { node: 1, x: 0.0, y: -0.5, z: 0.0, highlight: true },
      { node: 2, x: 2.0, y: -0.5, z: 0.0 },
      { node: 3, x: 2.0, y: 0.5, z: 0.0 },
      { node: 4, x: 0.0, y: 0.5, z: 0.0 },
      { node: 5, x: 0.7, y: -0.3, z: 0.0 },
      { node: 6, x: 1.3, y: -0.3, z: 0.0 },
      { node: 7, x: 1.3, y: 0.3, z: 0.0 },
      { node: 8, x: 0.7, y: 0.3, z: 0.0 },
      { node: 9, x: 0.7, y: -0.3, z: 0.4 },
      { node: 10, x: 1.3, y: -0.3, z: 0.4 },
      { node: 11, x: 1.3, y: 0.3, z: 0.4 },
      { node: 12, x: 0.7, y: 0.3, z: 0.4 },
    ],
  },

  contour: {
    resultName: 'Pressure',
    placeholder: true,
  },
};