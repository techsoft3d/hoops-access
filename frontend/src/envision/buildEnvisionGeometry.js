// Converts a geometry object (see geometryData.js) into a cee.usg.Geometry
// that can be attached to a cee.usg.State and rendered by Envision.
//
// Translates node ids (our data's language) into array indices (Envision's).

/**
 * @param {object} cee - the global window.cee object
 * @param {object} geometryData - one entry from geometryByFormat, e.g. geometryByFormat.nastran
 * @returns {{ geometry: cee.usg.Geometry, partRefToIndex: Record<string, number>, nodeIdsByPartIndex: number[][] }}
 */
export function buildEnvisionGeometry(cee, geometryData) {
  const geometry = new cee.usg.Geometry();
  const partRefToIndex = {};
  const nodeIdsByPartIndex = [];

  for (let partIdx = 0; partIdx < geometryData.parts.length; ++partIdx) {
    const partDef = geometryData.parts[partIdx];

    // 1. Collect this part's unique node ids, in order of first appearance.
    const nodeIdsInPart = []; 
    const nodeIdToLocalIndex = {}; 
    for (const element of partDef.elements) {
      for (const nodeId of element) {
        if (!(nodeId in nodeIdToLocalIndex)) {
          nodeIdToLocalIndex[nodeId] = nodeIdsInPart.length;
          nodeIdsInPart.push(nodeId);
        }
      }
    }

    // 2. Flatten node coordinates: x0,y0,z0, x1,y1,z1, ...
    const nodeArr = [];
    for (const nodeId of nodeIdsInPart) {
      const coord = geometryData.nodes[nodeId];
      if (!coord) {
        throw new Error(
          `Part "${partDef.label}" references node id ${nodeId}, but it's missing from geometryData.nodes`
        );
      }
      nodeArr.push(coord[0], coord[1], coord[2]);
    }

    // 3. Build element connectivity (as local indices) and node counts per element.
    const elementNodeIndexArr = []; // flattened list of local node indices for all elements in this part
    const elementTypeArr = []; //  how many corners each face has
    for (const element of partDef.elements) {
      elementTypeArr.push(element.length);
      for (const nodeId of element) {
        elementNodeIndexArr.push(nodeIdToLocalIndex[nodeId]);
      }
    }

    // 4. Create the mesh and part.
    const mesh = new cee.usg.Mesh(nodeArr, elementTypeArr, elementNodeIndexArr);
    const part = geometry.addPart();
    part.mesh = mesh;
    part.settings.color = new cee.Color3(0.6, 0.65, 0.7);
    part.settings.drawStyle = cee.usg.DrawStyle.SURFACE_OUTLINE_MESH;

    partRefToIndex[partDef.partRef] = partIdx;
    nodeIdsByPartIndex.push(nodeIdsInPart);
  }

  return { geometry, partRefToIndex, nodeIdsByPartIndex };
}