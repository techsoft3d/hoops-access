#pragma once

#include "samcpp/core/base_types.h"
#include "samcpp/core/coredefs.h"
#include "samcpp/core/pimpl.h"
#include "samcpp/core/status.h"

#include <memory>

ACCESSOR_DECL

namespace cae::core {

class Mesh {
  public:
    PIMPL_MOVE_ONLY(Mesh)

    /**
     * \details Integer properties for mesh configuration.
     */
    enum class IntegerParameter {
        REDEFINE_TOPOLOGY = CONNECT_REDEFINETOPO, ///< Redefine mesh topology after initial definition.
        EXACT_ADJACENCY = CONNECT_EXACTADJACENCY, ///< Use exact adjacency for element connectivity.
        LAYER_ASSOCIATION = CONNECT_LAYERASSOC,   ///< Enable layer association for mesh entities.
        ZERO_USER_ID = CONNECT_ZEROUSERID         ///< Use zero-based user IDs for mesh entities.
    };

    /**
     * \details Floating point properties for mesh configuration.
     */
    enum class FloatParameter {
        TOLERANCE = CONNECT_TOLERANCE, ///< Tolerance for geometric operations.
        SIZE = CONNECT_SIZE            ///< Arc length or size parameter for mesh entities.
    };

    /**
     * \details Operating mode for the mesh.
     */
    enum class Mode {
        STATIC = CONNECT_STATIC,  ///< Static mode (no dynamic updates).
        DYNAMIC = CONNECT_DYNAMIC ///< Dynamic mode (supports updates).
    };

    /**
     * \details Operations for extracting mesh regions.
     */
    enum class RegionOperation {
        UNCONNECTED_REGIONS = CONNECT_FREEBODY,          ///< Extract unconnected regions (free bodies).
        TOPOLOGICALLY_SIMILAR_BODIES = CONNECT_TOPOBODY, ///< Extract topologically similar bodies.
        NODAL_AVERAGING_REGIONS = CONNECT_MAP,           ///< Extract regions for nodal averaging.
        USER_ID = CONNECT_USERID                         ///< Extract regions by user-defined ID.
    };

    /**
     * \details Operations for creating or querying mesh groups.
     */
    enum class GroupOperation {
        FIRST_ENTITY_OCCURRENCE = CONNECT_UNIQUE,                               ///< Select first occurrence of each entity.
        FREE_ENTITIES = CONNECT_FREE,                                           ///< Select entities not connected to others.
        CONNECTED_ENTITIES = CONNECT_ELEM,                                      ///< Select entities connected to elements.
        FEATURE = CONNECT_FEATURE,                                              ///< Select feature entities (e.g., sharp edges).
        ASSOCIATION = CONNECT_ASSOC,                                            ///< Select entities by association value.
        ELEMENTS_OF_SHAPE = CONNECT_SHAPE,                                      ///< Select elements of a given shape.
        ELEMENTS_OF_DIMENSION = CONNECT_DIMENSION,                              ///< Select elements of a given dimension.
        WITHIN_EXTENT = CONNECT_EXTENT,                                         ///< Select entities within a spatial extent.
        ENTITIES_WITH_ALL_NODES_IN_GROUP = CONNECT_CONTAINED,                   ///< Entities with all nodes in a group.
        ENTITIES_USED_BY_N_ELEMENTS = CONNECT_USE,                              ///< Entities used by N elements.
        CONNECTED_TO_N_NODES = CONNECT_CONNECTED,                               ///< Entities connected to N nodes.
        INCONSISTENT_2D_ELEMENTS = CONNECT_INCONSISTENT,                        ///< 2D elements with inconsistent orientation.
        CURVATURE_DISCONTINUITY = CONNECT_CURVATURE,                            ///< Entities at curvature discontinuity.
        ENTITIES_PROPAGATING_FROM_SEED = CONNECT_SEED,                          ///< Entities reached by flood fill from a seed.
        NONMANIFOLD = CONNECT_NONMAN,                                           ///< Nonmanifold entities.
        CORNER_NODES = CONNECT_CORNER,                                          ///< Corner nodes in the mesh.
        ENTITIES_WITH_ANY_ASSOCIATION_VALUE = CONNECT_ASSOCANY,                 ///< Entities with any association value.
        DIFFERING_ASSOCIATION = CONNECT_ASSOCDIFF,                              ///< Entities with differing association values.
        ELEMENTS_WITH_EDGE_FACE_INTERSECTIONS = CONNECT_INTERSECT,              ///< Elements with edge/face intersections.
        FIRST_ENTITY_OCCURRENCE_PER_FACE_ASSOCIATION = CONNECT_UNIQUEASSOCDIFF, ///< First entity per face association.
        FEATURE_ENTITY_PER_ASSOCIATION = CONNECT_FEATUREASSOCDIFF,              ///< Feature entity per association.
        FIRST_ENTITY_OCCURRENCE_PER_ENTITY_ASSOCIATION = CONNECT_UNIQUEASSOC,   ///< First entity per entity association.
        FEATURE_BOUND_FLOOD_FILL_ENTITIES = CONNECT_FLOOD                       ///< Entities from feature-bound flood fill.
    };

    /**
     * \details Integer parameters for mesh groups.
     */
    enum class GroupIntegerParameter {
        ASSOCIATION_ID = CONNECT_ASSOCID,                        ///< Association ID for group selection.
        USE_NORMALS_IN_FEATURE_DETECTION = CONNECT_FEATURESENSE, ///< Use normals for feature detection.
        USED_ENTITY_COUNT = CONNECT_NUMBER,                      ///< Number of used entities in group.
        SEED_NODE = CONNECT_SEEDNODE,                            ///< Seed node for region growing.
        ONLY_CURVATURE_FROM_FLAT = CONNECT_CURVATUREFLAT,        ///< Only use curvature from flat regions.
        SEED_ELEMENT = CONNECT_SEEDELEM,                         ///< Seed element for region growing.
        SEED_EDGE = CONNECT_SEEDEDGE,                            ///< Seed edge for region growing.
        SEED_FACE = CONNECT_SEEDFACE,                            ///< Seed face for region growing.
        NONMANIFOLD_EDGES_AS_FEATURE = CONNECT_FEATURENONMAN,    ///< Treat nonmanifold edges as features.
        INCLUDE_FREE_ENTITIES = CONNECT_ASSOCFREE                ///< Include free entities in group.
    };

    /**
     * \details Floating point parameters for mesh groups.
     */
    enum class GroupFloatParameter {
        FEATURE_ANGLE = CONNECT_FEATUREANGLE,      ///< Feature angle threshold for detection.
        TOLERANCE = CONNECT_GROUP_TOLERANCE,       ///< Tolerance for group operations.
        CURVATURE_CHANGE = CONNECT_CURVATURECHANGE ///< Curvature change threshold.
    };

    /**
     * \details Floating point array parameters for mesh groups.
     */
    enum class GroupFloatArrayParameter {
        EXTENT = CONNECT_GROUP_EXTENT ///< Extent (bounding box) for group selection.
    };

    /**
     * \details Built-In shapes for mesh generation.
     */
    enum class DemoShape {
        CUBE = CONNECT_DEMO_CUBE,         ///< Cube shape.
        CYLINDER = CONNECT_DEMO_CYLINDER, ///< Cylinder shape.
        SPHERE = CONNECT_DEMO_SPHERE      ///< Sphere shape.
    };

    /**
     * \details Supported formats for mesh reading.
     */
    enum class ReadFormat {
        ASCII = CONNECT_READ_ASCII,           ///< ASCII format.
        BINARY = CONNECT_READ_BINARY,         ///< Binary format.
        STL = CONNECT_READ_STL,               ///< STL format (ASCII).
        STL_BINARY = CONNECT_READ_STL_BINARY, ///< STL format (binary).
        OBJ = CONNECT_READ_OBJ                ///< OBJ format.
    };

    /**
     * \details Supported formats for mesh writing.
     */
    enum class WriteFormat {
        ASCII = CONNECT_WRITE_ASCII,                       ///< ASCII format.
        BINARY = CONNECT_WRITE_BINARY,                     ///< Binary format.
        ABAQUS_INPUT = CONNECT_WRITE_ABAQUS_INPUT,         ///< ABAQUS input file.
        ANSYS_INPUT = CONNECT_WRITE_ANSYS_INPUT,           ///< ANSYS input file.
        LS_DYNA_INPUT = CONNECT_WRITE_LS_DYNA_INPUT,       ///< LS-DYNA input file.
        NASTRAN_BULKDATA = CONNECT_WRITE_NASTRAN_BULKDATA, ///< NASTRAN bulk data file.
        PATRAN_NEUTRAL = CONNECT_WRITE_PATRAN_NEUTRAL,     ///< PATRAN neutral file.
        SDRC_UNIVERSAL = CONNECT_WRITE_SDRC_UNIVERSAL      ///< SDRC universal file.
    };

    ErrorCode getErrorCode();
    Status    setPrecision(Precision precision);
    Status    getPrecision(Precision *precision);
    Status    define(int nodeCount, int elementCount);
    Status    inquire(int *nodeCount, int *elementCount);
    Status    setOperatingMode(Mode mode);
    Status    setState(State *state);
    Status    getState(StatePtr &state);
    Status    setMeshInterface(MeshInterface *functions);
    Status    getMeshInterface(MeshInterfacePtr &functions);
    Status    setFloatParameter(FloatParameter type, float parameter);
    Status    setIntegerParameter(IntegerParameter type, int parameter);
    Status    getEntityCount(EntityType type, int *count);
    Status    setDimension(int count);
    Status    kernelExists(bool *kernelExists);
    Status    setTopology(int index, ElementShape shape, int maxi, int maxj, int maxk);
    Status    getTopology(int index, ElementShape *shape, int *maxi, int *maxj, int *maxk);
    Status    deleteElement(int index);
    Status    isElementDefined(int index, int *flag);
    Status    generateElement(int *index);
    Status    setIntegrationPointCount(int index, int count);
    Status    getIntegrationPointCount(int index, int *count);
    Status    setElementNodes(int index, int nodeIndexes[]);
    Status    getMaxElementNodes(int *max);
    Status    getElementNodeCount(int index, int *count);
    Status    getElementNodes(int index, int *nodeCount, int nodeIndexes[]);
    Status    setCoordinates(int index, float coordinates[3]);
    Status    setCoordinates(int index, double coordinates[3]);
    Status    getCoordinates(int indexCount, int indexes[], float coordinates[][3]);
    Status    getCoordinates(int indexCount, int indexes[], double coordinates[][3]);
    Status    getNodeIndex(int id, int *index);
    Status    getElementIndex(int id, int *index);
    Status    setPartName(int partId, const char *name);
    Status    getPartName(int partId, char name[]);
    Status    getPartNameCount(int *count);
    Status    getPartInformation(int index, int *partId, char name[]);
    Status    setPartIJK(int partId, int ijk[3]);
    Status    getPartIJK(int partId, int ijk[]);
    Status    getPartIJKCount(int *count);
    Status    getPartIJKFromPartIndex(int index, int *partId, int ijk[]);
    Status    deleteNode(int index);
    Status    isNodeDefined(int index, int *flag);
    Status    generateNode(int *index);
    Status    setElementEntityAssociation(ElementAssociationType type, EntityType entityType, int index, int entityNumber, int association);
    Status    addElementEntityAssociation(ElementAssociationType type, EntityType entityType, int index, int entityNumber, int association);
    Status    getElementEntityAssociationCount(ElementAssociationType type, EntityType entityType, int index, int entityNumber, int *count);
    Status    deleteElementEntityAssociation(ElementAssociationType type, EntityType entityType, int index, int entityNumber);
    Status    getElementEntityAssociation(ElementAssociationType type, EntityType entityType, int index, int entityNumber, int *association);
    Status    getAllElementEntityAssociations(ElementAssociationType type, EntityType entityType, int index, int entityNumber, int *count, int associations[]);
    Status    getDimension(int *count);
    Status    runDemo(DemoShape shape, float factor, ElementShape elementShape, int numi, int numj, int numk);
    Status    read(ReadFormat format, const char *path);
    Status    generateKernel();
    Status    clearKernel();
    Status    write(WriteFormat format, const char *path);
    Status    getMaxElementCountConnectedToNode(int *max);
    Status    getElementCountConnectedToNode(int nodeIndex, int *count);
    Status    getElementsConnectedToNode(int nodeIndex, int *elementCount, int elementIndexes[]);
    Status    getAdjacentElements(EntityType entityType, int elementIndex, int entityNumber, int *elementCount, int elementIndexes[]);
    Status    getAdjacentElementsToFace(EntityType entityType, int elementIndex, int entityNumber, int *elementCount, int elementIndexes[], int localFaceIds[]);
    Status    getAdjacentElementEntities(EntityType entityType, int elementIndex, int entityNumber, int *elementCount, int elementIndexes[], int elementEntityNumbers[]);
    Status    getAdjacentElementEntitiesUsingCornerNodesOnly(EntityType entityType, int elementIndex, int entityNumber, int *elementCount, int elementIndexes[], int elementEntityNumbers[],
                                                             int cornerNodesOnlyFlag);
    Status    getElementsAdjacentToNodes(int nodeIndexCount, int nodeIndexes[], int *elementIndexCount, int elementIndexes[]);
    Status    getElementEntityCount(EntityType entityType, int index, int *count);
    Status    getElementEntityConnectivity(EntityType entityType, int index, int entityNumber, int *nodeCount, int nodeIndexes[]);
    Status    getElementEntityConnectionNumbers(EntityType entityType, int index, int entityNumber, int *nodeCount, int connectionNumbers[]);
    Status    getElementEntityCornerConnectionNumbers(EntityType entityType, int index, int entityNumber, int *nodeCount, int connectionNumbers[]);
    Status    getElementEntityTopology(EntityType entityType, int index, int entityNumber, ElementShape *shape, int *maxi, int *maxj);
    Status    setElementFaceNormals(int elementIndex, int faceNumber, float normals[][3]);
    Status    setElementFaceNormals(int elementIndex, int faceNumber, double normals[][3]);
    Status    isElementFaceNormalsDefined(int elementIndex, int faceNumber, int *flag);
    Status    getElementFaceNormals(int elementIndex, int faceNumber, float normals[][3]);
    Status    getElementFaceNormals(int elementIndex, int faceNumber, double normals[][3]);
    Status    setElementEdgeTangent(int elementIndex, int edgeNumber, float tangents[][3]);
    Status    setElementEdgeTangent(int elementIndex, int edgeNumber, double tangents[][3]);
    Status    isElementEdgeTangentDefined(int elementIndex, int edgeNumber, int *flag);
    Status    getElementEdgeTangent(int elementIndex, int edgeNumber, float tangents[][3]);
    Status    getElementEdgeTangent(int elementIndex, int edgeNumber, double tangents[][3]);
    Status    getExtent(Group *group, float extent[2][3]);
    Status    getExtent(Group *group, double extent[2][3]);
    Status    getExtentLocation(Group *group, float extent[2][3], int nodeIndexes[2][3]);
    Status    getExtentLocationInCoordinateSystem(Group *group, CoordinateSystem *coordinateSystem, float extent[2][3], int nodeIndexes[2][3]);
    Status    setGroupFloatParameter(GroupFloatParameter parameter, float value);
    Status    setGroupFloatParameterArray(GroupFloatArrayParameter parameter, float values[]);
    Status    setGroupIntegerParameter(GroupIntegerParameter parameter, int value);
    Status    setGroupElementAssociationType(ElementAssociationType type);
    Status    setGroupNodeAssociationType(NodeAssociationType type);
    Status    setSeedGroup(Group *object);
    Status    mergeWithNodeMapping(Group *group, IdTranslator *previousToNewNodeIndices);
    Status    merge(Group *group);
    Status    getElementGroup(GroupOperation operation, Group *inputGroup, Group *outputGroup);
    Status    getFaceGroup(GroupOperation operation, Group *inputGroup, Group *outputGroup);
    Status    getEdgeGroup(GroupOperation operation, Group *inputGroup, Group *outputGroup);
    Status    getNodeGroup(GroupOperation operation, Group *inputGroup, Group *outputGroup);
    Status    getElementRegion(RegionOperation operation, Group *inputGroup, IdTranslator *elementRegion);
    Status    getNodeRegion(RegionOperation operation, Group *inputGroup, IdTranslator *elementRegion);
    Status    splitElement(EntityType entityType, int elementIndex, int entityNumber, int nodeINdex);
    Status    getElementSize(EntityType entityType, int elementIndex, int entityNumber, double *size);
    Status    copy(Mesh *from);
    Status    append(Mesh *from);
    Status    extractSubset(Group *group, Mesh *subset, IdTranslator *childToParentNodeIndices);
    Status    extractSubsetWithElementMapping(Group *group, Mesh *subset, IdTranslator *childToParentNodeIndices, IdTranslator *childToParentElementIndices);
    Status    print();
    Status    printSummary();
    Status    tesselate(Mesh *input);
    Status    getMeshInterfacePointers(MeshInterface *functions);
    int       checkElementIndex(int index, const char *errorFunction);
    Status    getIntersectionPlane(double planeEquation[4], Group *inputGroup, Group *outputGroup);
    Status    setThreadCount(int count);

    template <auto AssociationType, typename AssociationValue>
    Status setNodeAssociation(int index, AssociationValue association);

    template <auto AssociationType, typename AssociationValue>
    Status getNodeAssociation(int indexCount, int indexes[], AssociationValue associations[]);

    template <auto AssociationType, typename AssociationValue>
    Status addNodeAssociation(int index, AssociationValue association);

    template <auto AssociationType>
    Status deleteNodeAssociation(int index);

    template <auto AssociationType>
    Status getNodeAssociationCount(int index, int *count);

    template <auto AssociationType, typename AssociationValue>
    Status getAllNodeAssociations(int index, int *count, AssociationValue associations[]);

    template <auto AssociationType, typename AssociationValue>
    Status setElementAssociation(int index, AssociationValue association);

    template <auto AssociationType, typename AssociationValue>
    Status getElementAssociation(int indexCount, int indexes[], AssociationValue associations[]);

    template <auto AssociationType, typename AssociationValue>
    Status addElementAssociation(int index, AssociationValue association);

    template <auto AssociationType>
    Status deleteElementAssociation(int index);

    template <auto AssociationType>
    Status getElementAssociationCount(int index, int *count);

    template <auto AssociationType, typename AssociationValue>
    Status getAllElementAssociations(int index, int *count, AssociationValue associations[]);

  private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // namespace cae::core
