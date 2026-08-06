#define NOMINMAX
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/msh/msh.h"
#include "sam/base/system.h"
#include "sam/hoops_license.h"

/* Enum to select connects to be exported */
enum struct exportConnects { none, finalMesh, allConnects };

/* Create cube coordinates for a specified edge size */
static void
getCubeNodesCoordinates(std::vector<std::vector<Vdouble>>& cubeNodesCoordinates, Vdouble cubeEdgeSize)
{
    cubeNodesCoordinates.clear();
    static std::vector<std::vector<Vdouble>> cubeNodesCoordinatesBase = {{0., 0., 0.}, {1., 0., 0.}, {0., 1., 0.}, {1., 1., 0.},
                                                                         {0., 0., 1.}, {1., 0., 1.}, {0., 1., 1.}, {1., 1., 1.}};
    for (std::vector<Vdouble> coord: cubeNodesCoordinatesBase) {
        for (auto& value: coord) {
            value *= cubeEdgeSize;
        }
        cubeNodesCoordinates.push_back(coord);
    }
}

/* Cube input triangles */
static Vint cubeInitialElements[12][3] = {{1, 5, 3}, {3, 5, 7}, {4, 6, 2}, {8, 6, 4}, {1, 2, 5}, {5, 2, 6},
                                          {7, 4, 3}, {8, 4, 7}, {1, 4, 2}, {4, 1, 3}, {5, 8, 7}, {5, 6, 8}};

static Vint cubePreservedEdges[12][3] = {{1, 0, 1}, {0, 1, 1}, {0, 1, 1}, {1, 0, 1}, {1, 0, 1}, {0, 1, 1},
                                         {0, 1, 1}, {1, 0, 1}, {0, 1, 1}, {0, 1, 1}, {0, 1, 1}, {1, 1, 0}};

/* Helper to set element associations */
static void
setElementAssociation(vis_Connect* connect, Vint type, Vint value)
{
    Vint elementCount = 0;
    vis_ConnectNumber(connect, SYS_ELEM, &elementCount);
    for (Vint i = 1; i <= elementCount; i++) {
        vis_ConnectSetElemAssoc(connect, type, i, value);
    }
}

/* Function to mesh the surface of cube 1 */
static void
meshCube1(vis_Connect** surfaceConnect, Vdouble edgeLength, Vdouble cubeEdgeSize)
{
    msh_SurfMesh* surfmesh = msh_SurfMeshBegin();
    msh_SurfMeshDef(surfmesh, 8, 12);

    /* Define points */
    std::vector<std::vector<Vdouble>> cubeNodesCoordinates;
    getCubeNodesCoordinates(cubeNodesCoordinates, cubeEdgeSize);
    for (Vint i = 0; i < 8; i++) {
        msh_SurfMeshSetPoint(surfmesh, i + 1, cubeNodesCoordinates[i].data(), 1);
    }

    /* Define triangle connectivity */
    for (Vint i = 0; i < 12; i++) {
        msh_SurfMeshSetTri(surfmesh, i + 1, cubeInitialElements[i], cubePreservedEdges[i]);
    }

    /* Set mesh parameters */
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_EDGELENGTH, edgeLength);
    msh_SurfMeshSetParami(surfmesh, VIS_MESH_MAXI, 2);

    /* Create Connect object */
    if (!*surfaceConnect) {
        *surfaceConnect = vis_ConnectBegin();
    }

    vis_ConnectPre(*surfaceConnect, SYS_DOUBLE);
    vis_ConnectDef(*surfaceConnect, 0, 0);

    /* Generate the surface mesh */
    msh_SurfMeshGenerate(surfmesh, *surfaceConnect);

    msh_SurfMeshEnd(surfmesh);

    /* Set the property ID */
    setElementAssociation(*surfaceConnect, VIS_PROPID, 1);
}

/* Function to get the subset of a connect based on X position */
static vis_Connect*
getSubSetConnectFromAnotherConnectBasedOnXposition(vis_Connect* connectContainsAllSurface, const Vdouble xtarget)
{
    /* tolerance to detect nodes */
    constexpr Vdouble tolerance = 0.000001;
    Vint elementCount = 0;
    vis_ConnectNumber(connectContainsAllSurface, SYS_ELEM, &elementCount);

    vis_Group* filteredElementsGroup = vis_GroupBegin();

    vis_GroupDef(filteredElementsGroup, elementCount, SYS_ELEM, SYS_NONE);

    Vint nodesPerElement = 3;
    std::vector<Vint> connectivity(nodesPerElement, 0);
    for (Vint elementindex = 1; elementindex <= elementCount; ++elementindex) {
        vis_ConnectElemNode(connectContainsAllSurface, elementindex, &nodesPerElement, connectivity.data());

        std::vector<Vdouble> coordinates(static_cast<Vlong>(nodesPerElement) * 3LL);

        vis_ConnectCoordsdv(connectContainsAllSurface, nodesPerElement, connectivity.data(), (Vdouble(*)[3])coordinates.data());

        if (fabs(coordinates[nodesPerElement * 0LL + 0] - xtarget) < tolerance &&
            fabs(coordinates[nodesPerElement * 1LL + 0] - xtarget) < tolerance &&
            fabs(coordinates[nodesPerElement * 2LL + 0] - xtarget) < tolerance) {
            vis_GroupSetIndex(filteredElementsGroup, elementindex, SYS_ON);
        }
    }

    vis_IdTran* idtrannode = vis_IdTranBegin();
    vis_Connect* filteredElementsConnect = vis_ConnectBegin();
    vis_ConnectSubset(connectContainsAllSurface, filteredElementsGroup, filteredElementsConnect, idtrannode);
    vis_IdTranEnd(idtrannode);
    vis_GroupEnd(filteredElementsGroup);

    return filteredElementsConnect;
}

/* Function to get the shared face connect between the two cubes */
static void
cube1SharedFace(vis_Connect* connectCube1, vis_Connect** connectFace)
{
    *connectFace = getSubSetConnectFromAnotherConnectBasedOnXposition(connectCube1, 1.0);
}

/* Function to mesh the surface of cube 2 by using the shared face from cube 1 */
static Vint
meshCube2(vis_Connect** surfaceConnectCube2, Vdouble edgeLength, vis_Connect* connectSharedFace, Vdouble cubeEdgeSize)
{
    /* Get the free edges and nodes from the shared face connect */
    vis_Group* freeNodesGroup = NULL;
    vis_Group* freeEdgesGroup = NULL;
    Vint freeNodesCount = 0;
    Vint nodeCount = 0;
    {
        vis_ConnectNumber(connectSharedFace, SYS_NODE, &nodeCount);
        Vint elementCount = 0;
        vis_ConnectNumber(connectSharedFace, SYS_ELEM, &elementCount);

        freeEdgesGroup = vis_GroupBegin();
        vis_GroupDef(freeEdgesGroup, elementCount, SYS_ELEM, SYS_EDGE);
        vis_ConnectKernel(connectSharedFace, 0);
        vis_ConnectEdgeGroup(connectSharedFace, CONNECT_FREE, NULL, freeEdgesGroup);

        freeNodesGroup = vis_GroupBegin();
        vis_GroupDef(freeNodesGroup, nodeCount, SYS_NODE, SYS_NONE);
        vis_ConnectNodeGroup(connectSharedFace, CONNECT_UNIQUE, freeEdgesGroup, freeNodesGroup);

        Vint childCount = 0;
        vis_GroupCount(freeNodesGroup, &freeNodesCount, &childCount);
    }

    /* Compute the edge size of the shared face */
    Vdouble conectExtent[2][3] = {{0}};
    vis_ConnectExtentdv(connectSharedFace, freeNodesGroup, conectExtent);
    Vdouble maxExtent = 0;
    for (Vint i = 0; i < 3; i++) {
        maxExtent = std::max(maxExtent, std::abs(conectExtent[0][i] - conectExtent[1][i]));
    }
    bool differentEdgeSizes = maxExtent != cubeEdgeSize;

    /* Create a surface mesher of all the faces of cube 2 EXCEPT the shared face */
    msh_SurfMesh* surfmesh = msh_SurfMeshBegin();
    msh_SurfMeshDef(surfmesh, 8 + freeNodesCount, differentEdgeSizes ? 12 : 12 - 2);

    /* Define points */
    std::vector<std::vector<Vdouble>> cubeNodesCoordinates;
    getCubeNodesCoordinates(cubeNodesCoordinates, cubeEdgeSize);
    for (Vint i = 0; i < 8; i++) {
        /* Shift the cube by 1 unit in X direction */
        Vdouble xcNew[3] = {cubeNodesCoordinates[i][0] + 1.0, cubeNodesCoordinates[i][1], cubeNodesCoordinates[i][2]};
        msh_SurfMeshSetPoint(surfmesh, i + 1, xcNew, 1);
    }

    if (freeEdgesGroup && freeNodesGroup) {
        /* Set the nodes of the free edges of the shared surface in the surface mesher and set them as preserved */
        Vint currentLocalNodeAddedCount = 0;
        /* Map to keep track of the new node IDs */
        std::map<Vint, Vint> nodeIdMap;
        std::map<Vint, Vint> surfmeshNodeIdToconnectNodeId;
        for (Vint i = 1; i <= nodeCount; i++) {
            if (vis_GroupNode(freeNodesGroup, i)) {
                Vdouble coord[3];
                vis_ConnectCoordsdv(connectSharedFace, 1, &i, &coord);
                currentLocalNodeAddedCount++;
                msh_SurfMeshSetPoint(surfmesh, 8 + currentLocalNodeAddedCount, coord, 1);
                /* Store the mapping from old to new node ID */
                nodeIdMap[i] = 8 + currentLocalNodeAddedCount;
                surfmeshNodeIdToconnectNodeId[8 + currentLocalNodeAddedCount] = i;
            }
        }

        /* Set the free edges of the shared surface in the surface mesher and set them as to be recovered */
        Vint nParent = 0;
        Vint freeEdgesCount = 0;
        vis_GroupCount(freeNodesGroup, &nParent, &freeEdgesCount);
        std::vector<std::vector<Vint>> edgesConnectivity;
        for (Vint i = 1; i <= nParent; i++) {
            if (vis_GroupElem(freeEdgesGroup, i)) {
                Vint nedge = 0;
                vis_ConnectElemNum(connectSharedFace, SYS_EDGE, i, &nedge);
                for (Vint no = 1; no <= nedge; no++) {
                    Vint flag = 0;
                    vis_GroupGetEntFlag(freeEdgesGroup, i, no, &flag);
                    if (flag) {
                        Vint nix = 0;
                        Vint ixelno[2] = {0};
                        vis_ConnectElemCon(connectSharedFace, SYS_EDGE, i, no, &nix, ixelno);
                        for (Vint j = 0; j < nix; j++) {
                            ixelno[j] = nodeIdMap[ixelno[j]];
                        }
                        edgesConnectivity.push_back({ixelno[0], ixelno[1]});
                    }
                }
            }
        }

        /* Process edges to recover */
        if (edgesConnectivity.size() > 0) {
            /* If cube sizes are different, we need to compute the boundary of the shared face in order to trim it out */
            /* of the cube 2 */
            if (differentEdgeSizes) {
                /* Fill loopConnectivity to create an ordered closed path, surrounding the path to be removed */
                std::vector<Vint> loopConnectivity;
                loopConnectivity.push_back(edgesConnectivity.front()[0]);
                loopConnectivity.push_back(edgesConnectivity.front()[1]);
                edgesConnectivity.erase(edgesConnectivity.begin());
                while (!edgesConnectivity.empty()) {
                    Vint nodeIdToFind = loopConnectivity.back();
                    bool foundFlag = false;
                    for (Vuint i = 0; i < edgesConnectivity.size(); ++i) {
                        if (edgesConnectivity[i][0] == nodeIdToFind) {
                            loopConnectivity.push_back(edgesConnectivity[i][1]);
                            edgesConnectivity.erase(edgesConnectivity.begin() + i);
                            foundFlag = true;
                            break;
                        }
                        else if (edgesConnectivity[i][1] == nodeIdToFind) {
                            loopConnectivity.push_back(edgesConnectivity[i][0]);
                            edgesConnectivity.erase(edgesConnectivity.begin() + i);
                            foundFlag = true;
                            break;
                        }
                    }
                    if (!foundFlag) {
                        std::cerr << "Loop processing failed" << std::endl;
                        return 1;
                    }
                }

                /* Compute the area of the patch to be removed */
                /* Normal to cube pointing outward at the patch to be removed */
                Vdouble normal[3] = {-1, 0, 0};
                Vdouble area = 0;
                for (Vuint i = 1; i < loopConnectivity.size(); ++i) {
                    Vdouble coord1[3] = {0};
                    vis_ConnectCoordsdv(connectSharedFace, 1, &surfmeshNodeIdToconnectNodeId[loopConnectivity[i - 1LL]], &coord1);
                    Vdouble coord2[3] = {0};
                    vis_ConnectCoordsdv(connectSharedFace, 1, &surfmeshNodeIdToconnectNodeId[loopConnectivity[i]], &coord2);

                    Vdouble cross[3] = {0};
                    CROSS3(coord1, coord2, cross);
                    SCALE3(cross, 0.5);
                    area += DOT3(cross, normal);
                }

                /* The area must be negative for a hole, otherwise we reverse the loop order */
                if (area > 0) {
                    std::reverse(loopConnectivity.begin(), loopConnectivity.end());
                }

                Vint trimflag = SYS_ON;
                Vint midsideNodesLocationFlag = SYS_OFF;
                msh_SurfMeshSetEdge(surfmesh, trimflag, static_cast<Vint>(loopConnectivity.size()), loopConnectivity.data(),
                                    midsideNodesLocationFlag, NULL);
            }
            else {
                /* We set all the shared face boundary edges as to be recovered */
                Vint trimflag = SYS_OFF;
                Vint midsideNodesLocationFlag = SYS_OFF;
                for (auto& edge: edgesConnectivity) {
                    msh_SurfMeshSetEdge(surfmesh, trimflag, static_cast<Vint>(edge.size()), edge.data(), midsideNodesLocationFlag,
                                        NULL);
                }
            }
        }
    }
    if (freeNodesGroup) {
        vis_GroupEnd(freeNodesGroup);
    }
    if (freeEdgesGroup) {
        vis_GroupEnd(freeEdgesGroup);
    }

    /* Define triangle connectivity */
    /* Starting from 2, because 0 and 1 are used for the shared face (when edge sizes are identical) */
    Vint startIndex = differentEdgeSizes ? 0 : 2;
    for (Vint i = startIndex; i < 12; i++) {
        msh_SurfMeshSetTri(surfmesh, i - startIndex + 1, cubeInitialElements[i], cubePreservedEdges[i]);
    }

    /* Set mesh parameters */
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_EDGELENGTH, edgeLength);
    msh_SurfMeshSetParami(surfmesh, VIS_MESH_MAXI, 2);

    /* Create Connect object */
    if (!*surfaceConnectCube2) {
        *surfaceConnectCube2 = vis_ConnectBegin();
    }

    vis_ConnectPre(*surfaceConnectCube2, SYS_DOUBLE);
    vis_ConnectDef(*surfaceConnectCube2, 0, 0);

    /* Generate */
    msh_SurfMeshGenerate(surfmesh, *surfaceConnectCube2);

    /* Append the shared face to the surface mesh of all other faces of cube 2 */
    vis_ConnectAppend(*surfaceConnectCube2, connectSharedFace);
    vis_ConnectMerge(*surfaceConnectCube2, NULL);

    msh_SurfMeshEnd(surfmesh);

    /* Set the property ID */
    setElementAssociation(*surfaceConnectCube2, VIS_PROPID, 2);

    return 0;
}

/* Generate a tetmesh from a surface mesh */
static Vint
generateTetMesh(vis_Connect* connectSurfMesh, vis_Connect* connectTetMesh, Vdouble edgeLength)
{
    /* Create tetmesh object */
    msh_TetMesh* tetMesh = msh_TetMeshBegin();
    Vint nodeCount = 0, triangleCount = 0;
    vis_ConnectNumber(connectSurfMesh, SYS_NODE, &nodeCount);
    vis_ConnectNumber(connectSurfMesh, SYS_ELEM, &triangleCount);
    msh_TetMeshDef(tetMesh, nodeCount, triangleCount, 2);

    /* Define nodes */
    Vdouble x[3] = {0., 0., 0.};
    for (Vint i = 1; i <= nodeCount; i++) {
        vis_ConnectCoordsdv(connectSurfMesh, 1, &i, (Vdouble(*)[3])x);
        msh_TetMeshSetNode(tetMesh, i, x);
    }

    Vint maxElementNodeCount = 0;
    vis_ConnectMaxElemNode(connectSurfMesh, &maxElementNodeCount);

    /* Allocate connectivity vector with maximum size */
    std::vector<Vint> connectivity(maxElementNodeCount);

    /* Define triangles */
    for (Vint i = 1; i <= triangleCount; i++) {
        Vint elementNodeCount = 0;
        vis_ConnectElemNode(connectSurfMesh, i, &elementNodeCount, connectivity.data());
        if (elementNodeCount == 3) {
            msh_TetMeshSetTri(tetMesh, i, connectivity.data());
        }
    }

    /* Allow unconnected nodes */
    msh_TetMeshSetParami(tetMesh, TETMESH_UNCONNECT, SYS_ON);
    /* Repair inconsistent input triangles normal */
    msh_TetMeshSetParami(tetMesh, VIS_MESH_REPAIRINCONS, SYS_ON);
    msh_TetMeshSetParamd(tetMesh, VIS_MESH_EDGELENGTH, edgeLength);

    /* Generate the volume mesh */
    msh_TetMeshGenerate(tetMesh, connectTetMesh);

    Vint error = msh_TetMeshError(tetMesh);
    msh_TetMeshEnd(tetMesh);

    if (error != SYS_ERROR_NONE) {
        std::cerr << "TetMesh error: " << error << std::endl;
        return 1;
    }

    return 0;
}

/* Function to mesh the two cubes and return a connect with the tet mesh of both cubes */
static vis_Connect*
tetMeshCubes(vis_Connect* connectCube1, Vdouble edgeLengthCube1, vis_Connect* connectCube2, Vdouble edgeLengthCube2)
{
    /* Generate Cube 1 */
    vis_Connect* connectVolumeCube1 = vis_ConnectBegin();
    Vint cube1Status = generateTetMesh(connectCube1, connectVolumeCube1, edgeLengthCube1);
    if (cube1Status != 0) {
        return NULL;
    }
    setElementAssociation(connectVolumeCube1, VIS_PROPID, 1);

    /* Generate Cube 2 */
    vis_Connect* connectVolumeCube2 = vis_ConnectBegin();
    Vint cube2Status = generateTetMesh(connectCube2, connectVolumeCube2, edgeLengthCube2);
    if (cube2Status != 0) {
        return NULL;
    }
    setElementAssociation(connectVolumeCube2, VIS_PROPID, 2);

    /* Append the two volume meshes together */
    vis_ConnectAppend(connectVolumeCube1, connectVolumeCube2);
    if (connectVolumeCube2) {
        vis_ConnectEnd(connectVolumeCube2);
    }

    return connectVolumeCube1;
}

/* Function to mesh two cubes in contact */
extern void
meshCubesInContact(exportConnects exportGeneratedConnects, Vdouble cube1EdgeSize, Vdouble cube2EdgeSize,
                   const std::string& exampleName)
{
    Vdouble edgeLengthCube1 = 0.4;
    Vdouble edgeLengthCube2 = 0.15;

    /* Generate the first cube */
    vis_Connect* connectCube1 = NULL;
    meshCube1(&connectCube1, edgeLengthCube1, cube1EdgeSize);
    if (exportGeneratedConnects == exportConnects::allConnects) {
        vis_ConnectWrite(connectCube1, SYS_NASTRAN_BULKDATA,
                         std::string("cube1_").append(exampleName).append("Cubes.bdf").c_str());
    }

    /* Get the X face of the first cube */
    vis_Connect* connectSharedFace = NULL;
    cube1SharedFace(connectCube1, &connectSharedFace);
    if (exportGeneratedConnects == exportConnects::allConnects) {
        vis_ConnectWrite(connectSharedFace, SYS_NASTRAN_BULKDATA,
                         std::string("cube1SharedFace_").append(exampleName).append("identicalCubes.bdf").c_str());
    }

    /* Generate the second cube by using the shared face from the first cube */
    vis_Connect* connectCube2 = NULL;
    Vint meshCube2Status = meshCube2(&connectCube2, edgeLengthCube2, connectSharedFace, cube2EdgeSize);
    if (meshCube2Status != 0) {
        return;
    }
    if (exportGeneratedConnects == exportConnects::allConnects) {
        vis_ConnectWrite(connectCube2, SYS_NASTRAN_BULKDATA,
                         std::string("cube2_").append(exampleName).append("Cubes.bdf").c_str());
    }

    /* tetmesh and Append both cubes together */
    vis_Connect* connectCubes = tetMeshCubes(connectCube1, edgeLengthCube1, connectCube2, edgeLengthCube2);
    if (exportGeneratedConnects == exportConnects::allConnects || exportGeneratedConnects == exportConnects::finalMesh) {
        vis_ConnectWrite(connectCubes, SYS_NASTRAN_BULKDATA,
                         std::string("cubes_").append(exampleName).append("Cubes.bdf").c_str());
    }

    /* Print the number of elements and nodes */
    Vint elementCount = 0;
    Vint nodeCount = 0;
    vis_ConnectInq(connectCubes, &nodeCount, &elementCount);
    std::cout << exampleName << " cube sizes: " << elementCount << " elements and " << nodeCount << " nodes generated."
              << std::endl;

    /* Clean */
    if (connectCube1) {
        vis_ConnectEnd(connectCube1);
    }
    if (connectSharedFace) {
        vis_ConnectEnd(connectSharedFace);
    }
    if (connectCube2) {
        vis_ConnectEnd(connectCube2);
    }
    if (connectCubes) {
        vis_ConnectEnd(connectCubes);
    }
}

int
main()
{
    vsy_LicenseValidate(HOOPS_LICENSE);

    /* Mesh two identical cubes in contact */
    Vdouble cube1EdgeSize = 1.0;
    Vdouble cube2EdgeSize = 1.0;
    meshCubesInContact(exportConnects::finalMesh, cube1EdgeSize, cube2EdgeSize, "identical");

    /* Mesh two different cubes in contact */
    cube1EdgeSize = 1.0;
    cube2EdgeSize = 2.0;
    meshCubesInContact(exportConnects::finalMesh, cube1EdgeSize, cube2EdgeSize, "different");

    return 0;
}
