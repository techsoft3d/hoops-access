/* CGNS Library object */
#ifndef CGNVS_CONVERTER_DEF
#define CGNVS_CONVERTER_DEF

#include <stdio.h>

#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/base/base.h"
#include "sam/vis/connect.h"
#include "sam/base/timer.h"
#include "sam/vdm/libraries/cgns/cgnsvdefs.h"

#define MAX_ALLOWED_NEIGHBORS                  16
#define ELEMENTDATA_RESIZEFACTOR               1.2  /* Memory Resize factor for struct ElementData */
#define FACEDATA_RESIZFACTOR                   1.1  /* Memory Resize factor for struct FaceData */
#define PARALLELCONV_FACESHARINGTHREADS_RSZLEN 8000 /* Memory Resize length for struct faceSharingThreads */
#define CONVERTER_MAX_THREAD_COUNT             64   /* maximum number of threads to be used in the converter */

struct vdm_FaceAdjacency {
    Vint owner;
    Vint neighbor;
    Vint neighborLocalFaceId;
};

struct vdm_ElementData {
    /* Element Face List -> Contains data to describe Polyhedra following CGNS format NFACE_n. Each element is described by its
       list of faces. Each of these faces connectivity will be written separately with CGNS type NGON_n.
       faceOffsets(size=elementCount +1) is the table to access to elementFaceIndices table(size=totalElementFacesCount).
             1st face of element iel: elementFaceIndices[faceOffsets[iel  ]  ]
            last face of element iel: elementFaceIndices[faceOffsets[iel+1]-1]  */
    adaptNumericArray* faceOffsets;
    adaptNumericArray* faceIds; /* Size: used=totalElementFacesCount  Allocated=allocatedElementFacesNumber
                                 faceIds<0 if face connectivity order is reversed for this element */

    Vint elementCount;
    size_t totalElementFacesCount;
    size_t allocatedElementFacesNumber;
};

struct vdm_FaceData {
    /* Node Face List -> Contains data to describe Polygon faces connectivity following CGNS format NGON_n
    Each face is described by its connectivity (list fo nodes).
    nodeOffsets(size=uniqueFaceCount +1) is the table to access to nodeIndices table(size=totalFaceNodesCount).
             1st node of face iface: nodeIndices[nodeOffsets[iface  ]  ]
            last node of face iface: nodeIndices[nodeOffsets[iface+1]-1]  */
    adaptNumericArray* nodeOffsets; /* Size: used=uniqueFaceCount+1   Allocated=allocatedFacesNumber*/
    Vint* nodeIndices;              /* Size: used=totalFaceNodesCount   Allocated=allocatedFaceNodesNumber*/
    size_t uniqueFaceCount;
    size_t allocatedFacesNumber; /* (shoud be equal to allocationAdjacencySize) */
    size_t totalFaceNodesCount;
    size_t allocatedFaceNodesNumber;

    vdm_FaceAdjacency*
    adjacentsElements; /* Elements sharing the same face [supposed to be only 2], input=face index output=two elements indices*/
    size_t allocationAdjacencySize; /* allocation for tables adjacentsElements */

    size_t multipleNeighborsFaceCount; /* number of faces with non expected behavior(more than 1 neighbor) */
};

struct vdm_Partitionner {
    Vint threadCount;
    Vint itemCount;
    Vlong itemBegins[CONVERTER_MAX_THREAD_COUNT];
    Vlong itemEnds[CONVERTER_MAX_THREAD_COUNT];
    Vint itemType;   /* SYS_ELEMENT, SYS_NODE....*/
    Vint threadSize; /* MIN(1,itemCount/threadCount)  the last threads may be >threadSize or = 0 if threadCount>itemCount */
};

struct vdm_ParallelConverter {
    vis_Connect* connect;
    Vint* polyToElementList; /* sorted list of polygon & polyhedra */
    Vint* elementToPolyList; /* inverse of polyToElementList */

    vdm_ElementData elementData;
    vdm_FaceData faceData;

    Vint elementBegin;
    Vint elementEnd;

    Vlong* faceSharingThreads; /*List of faces being shared by two threads*/
    Vlong faceSharingThreadsCount;
    Vlong faceSharingThreadAllocationSize;
    Vint myThreadIndex;
};

struct vdm_CGNSPolyData {
    vdm_FaceData faceData;
    vdm_ElementData elementData;
    Vint ierr;
};

struct vdm_PolyConnectToCGNSConverter {
    vis_Connect* connect;
    Vint* polyToElementList; /* sorted list of polygon & polyhedra (gives index) */
    Vint* elementToPolyList; /* inverse of pidpoly (gives Id) */

    vdm_Partitionner partitionner;
    vdm_ParallelConverter* parallelConverters; /*List of parallel converter*/
    Vint converterCount;

    Vint ierr;
};

#ifdef __cplusplus
extern "C" {
#endif
/* vdm_PolyConnectToCGNSConverter */
void
vdm_PolyConnectToCGNSConverter_setThreadCount(vdm_PolyConnectToCGNSConverter* p, Vint threadCount);
void
vdm_PolyConnectToCGNSConverter_constructData(vdm_PolyConnectToCGNSConverter* p, vsy_Timer* timer, vis_Connect* connect,
                                             Vint* polyToElementList, Vint* elementToPolyList, Vint polyhedronCount,
                                             Vint polygonCount);
void
vdm_PolyConnectToCGNSConverter_destroyData(vdm_PolyConnectToCGNSConverter* converter);

void
vdm_PolyConnectToCGNSConverter_gatherData(vdm_PolyConnectToCGNSConverter* p, vdm_CGNSPolyData** polyData);

/* vdm_FaceData */
void
vdm_FaceData_allocateFaceAdjacencies(vdm_FaceData* faceData, size_t uniqueFaceCount);
void
vdm_FaceData_reallocateFaceAdjacencies(vdm_FaceData* faceData, size_t uniqueFaceIndex);
void
vdm_FaceData_deallocateFaceAdjacencies(vdm_FaceData* faceData);

void
vdm_FaceData_allocateFacenodes(vdm_FaceData* faceData, size_t facesCount, size_t FaceNodesCount);
void
vdm_FaceData_reallocateFacenodes(vdm_FaceData* faceData, size_t uniqueFaceIndex, Vint faceNodeCount);
void
vdm_FaceData_deallocateFaceNodes(vdm_FaceData* faceData);

void
vdm_FaceData_registerFaceAdjacencies(vdm_FaceData* faceData, size_t faceIndex, Vint ownerId, Vint neighborId,
                                     Vint localNeighbface);
void
vdm_FaceData_registerFaceNodes(vdm_FaceData* faceData, size_t uniqueFaceIndex, Vint facenodeCount, Vint* facenodeIndices);
void
vdm_FaceData_registerFaceNodeIndices(vdm_FaceData* faceData, size_t uniqueFaceIndex, Vint facenodeCount, Vint* facenodeIndices);

/*vdm_ElementData */
void
vdm_ElementData_allocate(vdm_ElementData* elementData, Vint elementCount, size_t sizeElementfacesCount);
void
vdm_ElementData_reallocateElementFaceIds(vdm_ElementData* elementData, size_t sizeElementfacesCount);
void
vdm_ElementData_deallocate(vdm_ElementData* elementData);

void
vdm_ElementData_registerFaceId(vdm_ElementData* elementData, Vint partitionElementIndex, Vint localfaceIndex, Vlong uniqueFaceId);
void
vdm_ElementData_registerElementFaceCount(vdm_ElementData* elementData, Vint partitionElementIndex, Vint elementfaceCount);

/*vdm_Partitionner*/
void
vdm_Partitionner_create(vdm_Partitionner* partitionner, Vint itemCount, Vint threadCount, Vint itemType);
void
vdm_Partitionner_getThreadPartition(vdm_Partitionner* partitionner, Vint threadIndex, Vint* itemBegin, Vint* itemEnd);
void
vdm_Partitionner_findPartitionForGlobalIndex(vdm_Partitionner* partitionner, Vint globalItemIndex, Vint* threadIndex,
                                             Vint* localItemIndex);

/* vdm_CGNSPolyData */
void
vdm_CGNSPolyData_allocate(vdm_CGNSPolyData** polyData, size_t totaluniqueFaces, size_t totalFacenodes, size_t totalelements,
                          size_t totalElementfaces);
void
vdm_CGNSPolyData_deallocate(vdm_CGNSPolyData** polyData);
#ifdef __cplusplus
}
#endif

#endif
