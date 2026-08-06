#include <stdio.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"
#include <vector>
#include <string>

/*----------------------------------------------------------------------
        Generate a Surface Mesh in Parallel
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    vsy_LicenseValidate(HOOPS_LICENSE);

    std::string filename = argv[1]; // Expecting "PATH_to/walek.srf";
    constexpr Vint threadCount = 4;
    constexpr Vdouble targetEdgeLength = 0.6;
    std::vector<Vint> partitionStrategy = {16, 16};

    /* create Connect object */
    vis_Connect* connect = vis_ConnectBegin();
    vis_ConnectPre(connect, SYS_DOUBLE);
    vis_ConnectDef(connect, 0, 0);

    /* create SurfMesh object */
    msh_SurfMesh* surfmesh = msh_SurfMeshBegin();

    msh_SurfMeshRead(surfmesh, SYS_ASCII, filename.c_str());
    Vint errorFlag = msh_SurfMeshError(surfmesh);
    if (errorFlag) {
        printf("A problem occurred during reading of input file\n");
        exit(errorFlag);
    }

    /* set mesh parameters */
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_EDGELENGTH, targetEdgeLength);

    /* Define the parallel strategy. Set the number of partitions per iteration of the algorithm.*/
    msh_SurfMeshSetPartitionStrategy(surfmesh, static_cast<Vint>(partitionStrategy.size()), partitionStrategy.data());

    /* Define the number of threads to use during the parallel computation and call Experimental Generate */
    msh_SurfMeshSetNumThreads(surfmesh, threadCount);
    msh_SurfMeshGenerate(surfmesh, connect);

    errorFlag = msh_SurfMeshError(surfmesh);

    if (errorFlag) {
        printf("A problem occurred during execution of parallel surfmesher\n");
    }

    /*Optionally, print some recorded data available in a dictionary report*/
    vsy_DblDict* keyValueDict = nullptr;
    msh_SurfMeshGetExecutionReport(surfmesh, &keyValueDict);
    // vsy_DblDictPrint(keyValueDict);

    /* print output nodes and elements */
    Vint nodeCount = 0;
    Vint elementCount = 0;
    vis_ConnectNumber(connect, SYS_NODE, &nodeCount);
    vis_ConnectNumber(connect, SYS_ELEM, &elementCount);
    printf("nodeCount= %d, elementCount= %d\n", nodeCount, elementCount);

    // EXPECTED output
    /*
     * Percentage of Compliant Elements [%], v= 98.278854
     * Percentage of Non-Compliant Elements [%], v= 1.721146
     * Total Surfmesher Time [s], v= 58.630623
     * Iteration 3 Time[s], v= 14.753183
     * Iteration 2 Time[s], v= 4.554247
     * Iteration 1 Time[s], v= 38.485378
     * nodeCount= 923153, elementCount= 1846298
     */

    /* write generated mesh in NASTRAN bulk data format */
    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "example47_SurfMeshParallel.bdf");

    /* end objects */
    vis_ConnectEnd(connect);
    msh_SurfMeshEnd(surfmesh);
    return 0;
}
