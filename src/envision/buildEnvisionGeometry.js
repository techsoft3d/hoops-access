// buildEnvisionGeometry.js
//
// Converts a geometry object (see geometryData.js) into a cee.usg.Geometry
// that can be attached to a cee.usg.State and rendered by Envision.
//
// This is the one place that knows how to translate "node id" (your data's
// language) into "array index" (Envision's language) — everything else in
// the app can keep using node ids.

/**
 * @param {object} cee - the global window.cee object
 * @param {object} geometryData - one entry from geometryByFormat, e.g. geometryByFormat.nastran
 * @returns {{ geometry: cee.usg.Geometry, partRefToIndex: Record<string, number> }}
 */
export default function buildEnvisionGeometry(cee, geometryData) {
  const geometry = new cee.usg.Geometry();
  const partRefToIndex = {};

  for (let partIdx = 0; partIdx < geometryData.parts.length; ++partIdx) {
    const partDef = geometryData.parts[partIdx];

    // 1. Collect the unique node ids used by THIS part, in a stable order.
    //    This becomes the part's own local node array.
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

    // 2. Build the flat nodeArr: x0,y0,z0, x1,y1,z1, ...
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

    // 3. Build elementNodeIndexArr and elementTypeArr (node count per element).
    //    Elements can have different sizes (quads, triangles, etc), so we use
    //    elementTypeArr rather than the singleElementType shortcut.
    const elementNodeIndexArr = [];
    const elementTypeArr = [];
    for (const element of partDef.elements) {
      elementTypeArr.push(element.length);
      for (const nodeId of element) {
        elementNodeIndexArr.push(nodeIdToLocalIndex[nodeId]);
      }
    }

    // 4. Create the mesh and part, matching the pattern in HOOPS's usg.Geometry example
    const mesh = new cee.usg.Mesh(nodeArr, elementTypeArr, elementNodeIndexArr);
    const part = geometry.addPart();
    part.mesh = mesh;
    part.settings.color = new cee.Color3(0.6, 0.65, 0.7);
    part.settings.drawStyle = cee.usg.DrawStyle.SURFACE_OUTLINE_MESH;

    partRefToIndex[partDef.partRef] = partIdx;
  }

  return { geometry, partRefToIndex };
}
