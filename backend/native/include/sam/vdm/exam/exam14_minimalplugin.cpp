#ifdef CEE_SAM_DATA_PROVIDER_FRAMEWORK
#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/vdm/vdm.h"
#include "sam/vdm/plugins/pluginmanager.h"
#include "sam/vdm/datafile.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                     Plugin use example
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    Vchar pluginLibraryPath[SYS_MAXPATHCHAR] = {0};

    /* check input arguments */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s cdp_MinimalPluginPath\n", argv[0]);
        fprintf(stderr, " cdp_MinimalPluginPath is blank, 'cdp_MinimalPlugin' is assumed\n");
        strcpy(pluginLibraryPath, "cdp_MinimalPlugin");
    }
    else {
        strcpy(pluginLibraryPath, argv[1]);
    }

    /* Set the license */
    vsy_LicenseValidate(HOOPS_LICENSE);

    /* Look for the plugin */
    vdm_PluginManager* pluginManager = vdm_PluginManagerBegin();
    /* Set the error level as INFO=3 */
    vdm_PluginManagerSetErrorLevel(pluginManager, 3);
    vdm_PluginManagerLoadPlugin(pluginManager, pluginLibraryPath);
    Vint error = vdm_PluginManagerError(pluginManager);
    if (error) {
        vdm_PluginManagerEnd(pluginManager);
        fprintf(stderr, "%s file does not exists. The library extension must not be included in the path.\n", pluginLibraryPath);
        exit(1);
    }

    vdm_LMan* libraryManager = vdm_LManBegin();
    vdm_LManOpenFile(libraryManager, (Vchar*)"MINIMAL", nullptr);
    /* check for error */
    Vint ierr = vdm_LManError(libraryManager);
    if (ierr) {
        fprintf(stderr, "Error: opening MinimalPlugin \n");
        vdm_LManCloseFile(libraryManager);
        vdm_LManEnd(libraryManager);
        vdm_PluginManagerEnd(pluginManager);
        exit(1);
    }

    /* Print table of contents */
    vdm_LManSetParami(libraryManager, LMAN_VERBOSE, SYS_ON);
    vdm_LManTOC(libraryManager, "*");

    /* Load state 1: temperature */
    {
        vis_State* stateTemperature = vis_StateBegin();
        vdm_LManLoadStateFromName(libraryManager, (Vchar*)"TEMP.N", stateTemperature);
        Vfloat values[2] = {0};
        Vint nodeIdsCount = 2;
        Vint nodeIds[2] = {2, 4};
        vis_StateData(stateTemperature, nodeIdsCount, nodeIds, values);
        printf("Temperature:\n");
        /*  Node 2:   2.000000e+00  */
        printf("Node %d: %14e\n", nodeIds[0], values[0]);
        /*  Node 4:   4.000000e+00  */
        printf("Node %d: %14e\n", nodeIds[1], values[1]);
        vis_StateEnd(stateTemperature);
    }

    /* Load state 2: displacement */
    {
        vis_State* stateDisplacement = vis_StateBegin();
        vdm_LManLoadStateFromName(libraryManager, (Vchar*)"D.N", stateDisplacement);
        Vfloat values[3] = {0};
        Vint nodeIdsCount = 1;
        Vint nodeIds[1] = {3};
        vis_StateData(stateDisplacement, nodeIdsCount, nodeIds, values);
        printf("Displacement:\n");
        /* Node 3:   0.000000e+00,  -2.000000e+00,   5.000000e-01 */
        printf("Node %d: %14e, %14e, %14e\n", nodeIds[0], values[0], values[1], values[2]);
        vis_StateEnd(stateDisplacement);
    }

    /* Load state 3: stresses */
    {
        vis_State* stateStresses = vis_StateBegin();
        vdm_LManLoadStateFromName(libraryManager, (Vchar*)"S.EL", stateStresses);
        Vfloat values[6 * 3] = {0};
        Vint elementIdsCount = 1;
        Vint elementIds[1] = {2};
        vis_StateData(stateStresses, elementIdsCount, elementIds, values);

        /* Retrieve the connect */
        vis_Connect* connect = nullptr;
        vdm_LManGetConnect(libraryManager, &connect);

        /* check for error */
        ierr = vdm_LManError(libraryManager);
        if (ierr) {
            fprintf(stderr, "Error: loading mesh info\n");
            vis_StateEnd(stateStresses);
            vdm_LManEnd(libraryManager);
            vdm_PluginManagerEnd(pluginManager);
            exit(1);
        }

        /* Retrieve the element user id */
        Vint elementUserId = 0;
        vis_ConnectElemAssoc(connect, VIS_USERID, 1, &elementIds[0], &elementUserId);

        /* Retrieve the element connectivity */
        Vint numberOfElementNodes = 0;
        Vint elementNodes[3] = {0};
        vis_ConnectElemNode(connect, elementIds[0], &numberOfElementNodes, elementNodes);

        printf("Stress:\n");
        for (unsigned i = 0; i < 3; ++i) {
            /* Retrieve the node user id */
            Vint nodeUserId = 0;
            vis_ConnectNodeAssoc(connect, VIS_USERID, 1, &elementNodes[i], &nodeUserId);

            /* Element 17, Node   3: 3.000000e+01,   0.000000e+00,  0.000000e+00,  0.000000e+00,  0.000000e+00,  0.000000e+00 */
            /* Element 17, Node   5: 0.000000e+00,   0.000000e+00,  5.000000e+00,  0.000000e+00,  0.000000e+00,  0.000000e+00 */
            /* Element 17, Node  11: 0.000000e+00,  -1.000000e+01,  0.000000e+00,  0.000000e+00,  0.000000e+00,  0.000000e+00 */
            printf("Element %d, Node %3d: %14e, %14e, %14e, %14e, %14e, %14e\n", elementUserId, nodeUserId, values[6 * i + 0],
                   values[6 * i + 1], values[6 * i + 2], values[6 * i + 3], values[6 * i + 4], values[6 * i + 5]);
        }
        vis_StateEnd(stateStresses);
    }

    /* Free memory */
    vdm_LManCloseFile(libraryManager);
    vdm_LManEnd(libraryManager);
    vdm_PluginManagerEnd(pluginManager);

    return 0;
}

#endif
