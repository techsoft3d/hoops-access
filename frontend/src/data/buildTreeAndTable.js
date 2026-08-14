export function buildTreeAndTable(geometryData) {
  const tree = [
    {
      label: 'Model',
      children: [
        {
          label: 'Mesh',
          children: geometryData.parts.map((part) => ({
            label: part.label,
            children: part.elements.map((element, i) => ({
              label: `Element ${i + 1}`,
              nodeIds: element,
            })),
          })),
        },
      ],
    },
  ];

  const table = {
    columns: ['Node', 'X', 'Y', 'Z'],
    rows: Object.entries(geometryData.nodes).map(([nodeId, coords]) => ({
      node: nodeId,
      x: coords[0],
      y: coords[1],
      z: coords[2],
    })),
  };

  return { tree, table };
}