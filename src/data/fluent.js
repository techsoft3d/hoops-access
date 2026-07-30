export const fluent = {
  id: 'fluent',
  label: 'FLUENT',
  filename: 'chassis_flow.cas',
  keywords: ['(10', '(12', '(13', '(0', '(1'],
  rawLines: [
    { text: '; FLUENT CASE FILE — CHASSIS_FLOW.cas', type: 'comment' },
    { text: '; MESH HEADER', type: 'comment' },
    { text: '(10 (0 1 5 0 0 3))', type: 'code' },
    { text: '(12 (0 1 2 0 0))', type: 'code' },
    { text: '(13 (0 1 3 0 3))', type: 'code' },
    { text: '; NODE COORDINATES', type: 'comment' },
    { text: '(0.0 0.0 0.0)', type: 'code' },
    { text: '(1.0 0.0 0.0)', type: 'code' },
    { text: '(1.0 0.5 0.0)', type: 'code' },
    { text: '(0.0 0.5 0.0)', type: 'code' },
    { text: '(0.0 0.0 0.4)', type: 'code' },
  ],

  tree: [
    {
      label: 'Domain: Fluid',
      children: [
        { label: 'Zone 1 (wall)', color: 'blue' },
      ],
    },
    { label: 'Domain: Solid', collapsed: true },
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
    resultName: 'Pressure',
    placeholder: true,
  },
};