#pragma once

#include "sam/base/basedefs.h"
#include "sam/vis/gridfun.h"

namespace cae::core {

using NullaryFunction = Vfunc;
using UnaryIntFunction = VfuncInt;
using UnaryFunction = Vfunc1;
using BinaryFunction = Vfunc2;

using GetEntityCountFunction = VGridFunNumber;
using GetTopologyFunction = VGridFunTopology;
using GetMaxElementNodesFunction = VGridFunMaxElemNode;
using GetElementNodesFunction = VGridFunElemNode;
using GetCoordinatesFloatFunction = VGridFunCoords;
using GetCoordinatesDoubleFunction = VGridFunCoordsdv;
using GetNodeAssociationFunction = VGridFunNodeAssoc;
using GetElementAssociationFunction = VGridFunElemAssoc;
using GetMaxElementCountConnectedToNodeFunction = VGridFunMaxNodeElem;
using GetElementsConnectedToNodeFunction = VGridFunNodeElem;
using GetAdjacentElementsFunction = VGridFunElemAdj;
using GetElementEntityCountFunction = VGridFunElemNum;
using GetElementEntityConnectivityFunction = VGridFunElemCon;
using GetElementEntityConnectionNumbersFunction = VGridFunElemCnn;
using GetElementEntityTopologyFunction = VGridFunElemTopo;
using GetExtentFloatFunction = VGridFunExtent;
using GetElementNodeCountFunction = VGridFunNumElemNode;
using GetElementCountConnectedToNodeFunction = VGridFunNumNodeElem;
using GetElementsAdjacentToNodesFunction = VGridFunNodeAdj;
using GetElementEntityCornerConnectionNumbersFunction = VGridFunElemCorn;
using GetDimensionFunction = VGridFunDimension;
using GetExtentDoubleFunction = VGridFunExtentdv;
using GetElementEntityAssociationFunction = VGridFunElemEntAssoc;
using GetIntegrationPointCountFunction = VGridFunNumEIP;
using GetPartNameFunction = VGridFunPartName;
using GetPartNameCountFunction = VGridFunNumPartName;
using GetPartInformationFunction = VGridFunIthPartName;
using SetErrorFunction = VGridFunError;

} // namespace cae::core
