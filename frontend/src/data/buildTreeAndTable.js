export function buildTreeAndTable(geometryData) {
  const partNodes = geometryData.parts.map((part, partIndex) => {
    const elementNodes = part.elements.map((element) => ({
      label: `${element.shape} ${element.id}`,
      nodeIds: element.nodes,
    }));

    // A part's nodeIds is the union of every node id used by its elements.
    const partNodeIdSet = new Set();
    elementNodes.forEach((el) => el.nodeIds.forEach((id) => partNodeIdSet.add(id)));

    return {
      label: part.label,
      nodeIds: Array.from(partNodeIdSet),
      partIndex, // position in geometryData.parts — matches buildEnvisionGeometry's part order
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