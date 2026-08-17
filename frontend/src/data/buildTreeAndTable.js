export function buildTreeAndTable(geometryData) {
  const partNodes = geometryData.parts.map((part) => {
    const elementNodes = part.elements.map((element, i) => ({
      label: `Element ${i + 1}`,
      nodeIds: element,
    }));

    // A part's nodeIds is the union of every node id used by its elements.
    const partNodeIdSet = new Set();
    elementNodes.forEach((el) => el.nodeIds.forEach((id) => partNodeIdSet.add(id)));

    return {
      label: part.label,
      nodeIds: Array.from(partNodeIdSet),
      children: elementNodes,
    };
  });

  // The mesh's nodeIds is the union of every part's nodeIds.
  const meshNodeIdSet = new Set();
  partNodes.forEach((part) => part.nodeIds.forEach((id) => meshNodeIdSet.add(id)));

  const meshNode = {
    label: 'Mesh',
    nodeIds: Array.from(meshNodeIdSet),
    children: partNodes,
  };

  // The model's nodeIds is just the mesh's, since Mesh is currently the
  // only thing under Model.
  const modelNode = {
    label: 'Model',
    nodeIds: meshNode.nodeIds,
    children: [meshNode],
  };

  const tree = [modelNode];

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