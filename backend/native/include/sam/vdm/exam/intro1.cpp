#include <stdio.h>
#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/vis/visdata.h"
#include "sam/vdm/vdm.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                     Read and Print Finite Element Node Coordinates
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    char inputFile[256];
    /* check input arguments */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s inputfile\n", argv[0]);
        fprintf(stderr, " inputfile is blank, 'bumper.unv' is assumed\n");
        strcpy(inputFile, "bumper.unv");
    }
    else {
        strcpy(inputFile, argv[1]);
    }

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* Open file using Library Manager */
    vdm_LMan* lman = vdm_LManBegin();
    vdm_LManOpenFile(lman, inputFile, nullptr);

    /* check for error */
    Vint ierr = vdm_LManError(lman);
    if (ierr) {
        fprintf(stderr, "Error: opening file %s\n", inputFile);
        vdm_LManCloseFile(lman);
        vdm_LManEnd(lman);
        exit(1);
    }

    /* instance Model object for finite element model */
    vis_Model* model = vis_ModelBegin();
    vdm_LManLoadModel(lman, model);

    /* get Connect object created in Model */
    vis_Connect* connect;
    vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);

    /* check for errors */
    ierr = vis_ModelError(model);
    if (ierr) {
        printf("Error: Unable to get connect object from model\n");
        vis_ModelDelete(model);
        vis_ModelEnd(model);
        vdm_LManCloseFile(lman);
        vdm_LManEnd(lman);
        exit(1);
    }

    /* get number of nodes */
    Vint numnp;
    vis_ConnectNumber(connect, SYS_NODE, &numnp);

    /* print first and last node coordinates */
    printf("Node Coordinates\n");

    Vdouble coords[3];

    /* print first node */
    Vint nodeId = 1;
    vis_ConnectCoordsdv(connect, 1, &nodeId, &coords);
    printf("%10d %12f %12f %12f\n", 1, coords[0], coords[1], coords[2]);

    /* print last node */
    vis_ConnectCoordsdv(connect, 1, &numnp, &coords);
    printf("%10d %12f %12f %12f\n", numnp, coords[0], coords[1], coords[2]);

    /* clean-up */
    vis_ModelDelete(model);
    vis_ModelEnd(model);
    vdm_LManCloseFile(lman);
    vdm_LManEnd(lman);

    return 0;
}
