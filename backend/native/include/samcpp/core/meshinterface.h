#pragma once

#include "samcpp/core/base_types.h"
#include "samcpp/core/coredefs.h"
#include "samcpp/core/pimpl.h"
#include "samcpp/core/status.h"

#include <memory>

ACCESSOR_DECL

namespace cae::core {

class MeshInterface {
  public:
    PIMPL_MOVE_ONLY(MeshInterface)

    /// Function type identifiers for mesh interface
    enum class Function {
        GET_ENTITY_COUNT = GRIDFUN_NUMBER,                               ///< Get the number of entities (nodes/elements)
        GET_TOPOLOGY = GRIDFUN_TOPOLOGY,                                 ///< Get element topology information
        GET_ELEMENT_NODES = GRIDFUN_ELEMNODE,                            ///< Get node indices for an element
        GET_MAX_ELEMENT_NODES = GRIDFUN_MAXELEMNODE,                     ///< Get maximum number of nodes in any element
        GET_COORDINATES = GRIDFUN_COORDS,                                ///< Get node coordinates (float precision)
        GET_NODE_ASSOCIATION = GRIDFUN_NODEASSOC,                        ///< Get node association information
        GET_ELEMENT_ASSOCIATION = GRIDFUN_ELEMASSOC,                     ///< Get element association information
        GET_ELEMENT_ENTITY_COUNT = GRIDFUN_ELEMNUM,                      ///< Get number of entities (faces/edges/nodes) in an element
        GET_ELEMENT_ENTITY_CONNECTIVITY = GRIDFUN_ELEMCON,               ///< Get node connectivity for an element entity
        GET_ELEMENT_ENTITY_TOPOLOGY = GRIDFUN_ELEMTOPO,                  ///< Get topology of an element entity
        GET_ADJACENT_ELEMENTS = GRIDFUN_ELEMADJ,                         ///< Get elements adjacent to a specified element
        GET_MAX_ELEMENT_COUNT_CONNECTED_TO_NODE = GRIDFUN_MAXNODEELEM,   ///< Get maximum number of elements connected to any node
        GET_ELEMENTS_CONNECTED_TO_NODE = GRIDFUN_NODEELEM,               ///< Get elements connected to a node
        GET_EXTENT = GRIDFUN_EXTENT,                                     ///< Get spatial extent (float precision)
        GET_ELEMENT_ENTITY_CONNECTION_NUMBERS = GRIDFUN_ELEMCNN,         ///< Get connection numbers for an element entity
        GET_ELEMENTS_ADJACENT_TO_NODE = GRIDFUN_NODEADJ,                 ///< Get elements adjacent to a set of nodes
        GET_COORDINATES_DOUBLE_PRECISION = GRIDFUN_COORDSDV,             ///< Get node coordinates (double precision)
        SET_ERROR = GRIDFUN_ERROR,                                       ///< Set error handling function
        GET_ELEMENT_NODE_COUNT = GRIDFUN_NUMELEMNODE,                    ///< Get number of nodes in an element
        GET_ELEMENT_COUNT_CONNECTED_TO_NODE = GRIDFUN_NUMNODEELEM,       ///< Get number of elements connected to a node
        GET_ELEMENT_ENTITY_CORNER_CONNECTION_NUMBERS = GRIDFUN_ELEMCORN, ///< Get corner connection numbers for an element entity
        GET_DIMENSION = GRIDFUN_DIMENSION,                               ///< Get dimensionality of the model
        GET_EXTENT_DOUBLE_PRECISION = GRIDFUN_EXTENTDV,                  ///< Get spatial extent (double precision)
        GET_ELEMENT_ENTITY_ASSOCIATION = GRIDFUN_ELEMENTASSOC,           ///< Get association for an element entity
        GET_INTEGRATION_POINT_COUNT = GRIDFUN_NUMEIP,                    ///< Get number of integration points in an element
        GET_PARTNAME = GRIDFUN_PARTNAME,                                 ///< Get name of a part
        GET_PARTNAME_COUNT = GRIDFUN_NUMPARTNAME,                        ///< Get number of named parts
        GET_PART_INFORMATION = GRIDFUN_ITHPARTNAME,                      ///< Get part information by index
    };

    ErrorCode getErrorCode();
    Status    initialize();
    Status    setFunction(Function functionType, Vfunc *function);
    Status    getFunction(Function functionType, Vfunc **function);
    Status    copy(MeshInterface *from);

    Status getEntityCount(EntityType type, int *count);
    Status getTopology(int index, int *shape, int *maxi, int *maxj, int *maxk);
    Status getMaxElementNodes(int *max);
    Status getElementNodes(int index, int *nodeCount, int nodeIndexes[]);
    Status getCoordinates(int indexCount, int indexes[], float coordinates[][3]);
    Status getCoordinates(int indexCount, int indexes[], double coordinates[][3]);
    Status getNodeAssociation(NodeAssociationType type, int indexCount, int indexes[], int associations[]);
    Status getElementAssociation(ElementAssociationType type, int indexCount, int indexes[], int associations[]);
    Status getMaxElementCountConnectedToNode(int *max);
    Status getElementsConnectedToNode(int nodeIndex, int *elementCount, int elementIndexes[]);
    Status getAdjacentElements(EntityType entityType, int elementIndex, int entityNumber, int *elementCount, int elementIndexes[]);
    Status getElementEntityCount(EntityType entityType, int index, int *count);
    Status getElementEntityConnectivity(EntityType entityType, int index, int entityNumber, int *nodeCount, int nodeIndexes[]);
    Status getElementEntityConnectionNumbers(EntityType entityType, int index, int entityNumber, int *nodeCount, int connectionNumbers[]);
    Status getElementEntityTopology(EntityType entityType, int index, int entityNumber, int *shape, int *maxi, int *maxj);
    Status getExtent(Group *group, float extent[2][3]);
    Status getExtent(Group *group, double extent[2][3]);
    Status getElementNodeCount(int index, int *count);
    Status getElementCountConnectedToNode(int nodeIndex, int *count);
    Status getElementsAdjacentToNodes(int nodeIndexCount, int nodeIndexes[], int *elementIndexCount, int elementIndexes[]);
    Status getElementEntityCornerConnectionNumbers(EntityType entityType, int index, int entityNumber, int *nodeCount, int connectionNumbers[]);
    Status getDimension(int *count);
    Status getElementEntityAssociation(ElementAssociationType type, EntityType entityType, int index, int entityNumber, int *association);
    Status getIntegrationPointCount(int index, int *count);
    Status getPartName(int partId, char name[]);
    Status getPartNameCount(int *count);
    Status getPartInformation(int index, int *partId, char name[]);

    Status setFunctionError(UnaryIntFunction *function);
    Status setFunctionGetEntityCount(GetEntityCountFunction *function);
    Status setFunctionGetTopology(GetTopologyFunction *function);
    Status setFunctionGetMaxElementNodes(GetMaxElementNodesFunction *function);
    Status setFunctionGetElementNodes(GetElementNodesFunction *function);
    Status setFunctionGetCoordinatesFloat(GetCoordinatesFloatFunction *function);
    Status setFunctionGetCoordinatesDouble(GetCoordinatesDoubleFunction *function);
    Status setFunctionGetNodeAssociation(GetNodeAssociationFunction *function);
    Status setFunctionGetElementAssociation(GetElementAssociationFunction *function);
    Status setFunctionGetMaxElementCountConnectedToNode(GetMaxElementCountConnectedToNodeFunction *function);
    Status setFunctionGetElementsConnectedToNode(GetElementsConnectedToNodeFunction *function);
    Status setFunctionGetAdjacentElements(GetAdjacentElementsFunction *function);
    Status setFunctionGetElementEntityCount(GetElementEntityCountFunction *function);
    Status setFunctionGetElementEntityConnectivity(GetElementEntityConnectivityFunction *function);
    Status setFunctionGetElementEntityConnectionNumbers(GetElementEntityConnectionNumbersFunction *function);
    Status setFunctionGetElementEntityTopology(GetElementEntityTopologyFunction *function);
    Status setFunctionGetExtentFloat(GetExtentFloatFunction *function);
    Status setFunctionGetExtentDouble(GetExtentDoubleFunction *function);
    Status setFunctionGetElementNodeCount(GetElementNodeCountFunction *function);
    Status setFunctionGetElementCountConnectedToNode(GetElementCountConnectedToNodeFunction *function);
    Status setFunctionGetElementsAdjacentToNodes(GetElementsAdjacentToNodesFunction *function);
    Status setFunctionGetElementEntityCornerConnectionNumbers(GetElementEntityCornerConnectionNumbersFunction *function);
    Status setFunctionGetDimension(GetDimensionFunction *function);
    Status setFunctionGetElementEntityAssociation(GetElementEntityAssociationFunction *function);
    Status setFunctionGetIntegrationPointCount(GetIntegrationPointCountFunction *function);
    Status setFunctionGetPartName(GetPartNameFunction *function);
    Status setFunctionGetPartNameCount(GetPartNameCountFunction *function);
    Status setFunctionGetPartInformation(GetPartInformationFunction *function);
    Status setFunctionSetError(SetErrorFunction *function);

  private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // namespace cae::core
