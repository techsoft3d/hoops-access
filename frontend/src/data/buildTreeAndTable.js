// Property values are either a single number or an array (e.g. a 6x6
// stiffness matrix) — arrays get joined into a readable, capped string so a
// single tree row never blows up to hundreds of characters.
function formatPropertyValue(value, maxItems = 6) {
  if (!Array.isArray(value)) return String(value);
  const shown = value.slice(0, maxItems).map((v) => String(v));
  return value.length > maxItems
    ? `[${shown.join(', ')}, … (${value.length} total)]`
    : `[${shown.join(', ')}]`;
}

// Maps materialId/propertyId (as carried on each element in geometryData.parts)
// back to the elements that actually reference them — the only way to make a
// nameless, no-fields-set Material/Property row mean anything concrete.
function buildUsageMaps(parts, elementProperties) {
  // Some formats (e.g. beams, or this Abaqus foam model) only carry the
  // material link on the property, not directly on the element — so fall
  // back to element -> property -> material when the direct link is unset.
  const materialIdByPropertyId = new Map();
  (elementProperties || []).forEach((prop) => {
    if (prop.materialId) materialIdByPropertyId.set(prop.id, prop.materialId);
  });

  const byMaterialId = new Map();
  const byPropertyId = new Map();

  parts.forEach((part) => {
    part.elements.forEach((element) => {
      const label = `${element.shape} ${element.id}`;

      const materialId = element.materialId || materialIdByPropertyId.get(element.propertyId);
      if (materialId) {
        if (!byMaterialId.has(materialId)) byMaterialId.set(materialId, []);
        byMaterialId.get(materialId).push(label);
      }
      if (element.propertyId) {
        if (!byPropertyId.has(element.propertyId)) byPropertyId.set(element.propertyId, []);
        byPropertyId.get(element.propertyId).push(label);
      }
    });
  });

  return { byMaterialId, byPropertyId };
}

function formatUsageLabel(labels, maxItems = 6) {
  if (!labels || labels.length === 0) return null;
  const shown = labels.slice(0, maxItems).join(', ');
  return labels.length > maxItems
    ? `Used by ${labels.length} elements: ${shown}, …`
    : `Used by: ${shown}`;
}

function buildPropertyGroupNodes(entries, fallbackLabel, usageMap) {
  return entries.map((entry) => {
    const baseLabel = entry.name || `${fallbackLabel} ${entry.id}`;
    const children = Object.entries(entry.properties || {}).map(([key, value]) => ({
      label: `${key}: ${formatPropertyValue(value)}`,
      nodeIds: [],
    }));

    const usageLabel = usageMap && formatUsageLabel(usageMap.get(entry.id));
    if (usageLabel) {
      children.push({ label: usageLabel, nodeIds: [] });
    }

    return {
      label: entry.type ? `${baseLabel} (${entry.type})` : baseLabel,
      nodeIds: [],
      children,
    };
  });
}

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

  const modelChildren = [meshNode];

  const { byMaterialId, byPropertyId } = buildUsageMaps(geometryData.parts, geometryData.elementProperties);

  const materialNodes = buildPropertyGroupNodes(geometryData.materials || [], 'Material', byMaterialId);
  if (materialNodes.length > 0) {
    modelChildren.push({ label: 'Materials', nodeIds: [], children: materialNodes });
  }

  const elementPropertyNodes = buildPropertyGroupNodes(geometryData.elementProperties || [], 'Property', byPropertyId);
  if (elementPropertyNodes.length > 0) {
    modelChildren.push({ label: 'Element Properties', nodeIds: [], children: elementPropertyNodes });
  }

  const interactionPairNodes = buildPropertyGroupNodes(geometryData.interactionPairs || [], 'Interaction Pair');
  if (interactionPairNodes.length > 0) {
    modelChildren.push({ label: 'Interaction Pairs', nodeIds: [], children: interactionPairNodes });
  }

  const modelNode = {
    label: 'Model',
    nodeIds: meshNode.nodeIds,
    children: modelChildren,
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