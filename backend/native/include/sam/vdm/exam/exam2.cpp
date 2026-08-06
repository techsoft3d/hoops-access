#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/vis/visdata.h"
#include "sam/vdm/vdm.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static void
printNodes(vis_Connect* connect);
static void
printElements(vis_Connect* connect);

/*----------------------------------------------------------------------
                      Read and Print Model Data
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    char inputfile[256];
    vis_Model* model = NULL;
    vis_Connect* connect = NULL;
    vdm_LMan* lman = NULL;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s inputfile\n", argv[0]);
        fprintf(stderr, " inputfile is blank, 'bumper.unv' is assumed\n");
        strcpy(inputfile, "bumper.unv");
    }
    else {
        strcpy(inputfile, argv[1]);
    }

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* Open file */
    lman = vdm_LManBegin();
    vdm_LManOpenFile(lman, inputfile, NULL);

    /* check for error */
    Vint ierr = vdm_LManError(lman);
    if (ierr) {
        fprintf(stderr, "Error: opening file %s\n", inputfile);
        vdm_LManCloseFile(lman);
        vdm_LManEnd(lman);
        exit(1);
    }

    /* instance model object for finite element model */
    model = vis_ModelBegin();

    /* use Library Manager object to load model */
    vdm_LManLoadModel(lman, model);
    if (vdm_LManError(lman)) {
        fprintf(stderr, "Error: Unable to load model information\n");
        exit(1);
    }

    /* get Connect object and print nodes and elements */
    vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);
    if (connect != NULL) {
        printNodes(connect);
        printElements(connect);
    }
    /* delete objects registered in Model */
    vis_ModelDelete(model);
    /* destroy Model object itself */
    vis_ModelEnd(model);
    /* close library device and delete interface */
    vdm_LManCloseFile(lman);
    vdm_LManEnd(lman);
    return 0;
}

/*----------------------------------------------------------------------
                      print nodes
----------------------------------------------------------------------*/
static void
printNodes(vis_Connect* connect)
{
    Vint i;
    Vint numnp;
    Vint nid, cid;
    Vint featype;
    Vdouble x[3];

    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    printf("Number of nodes=    %d\n", numnp);
    /* nodes: coordinates, user id and
       displacement coordinate system id */
    printf("\nNodes\n");
    for (i = 1; i <= numnp; i++) {
        vis_ConnectCoordsdv(connect, 1, &i, (Vdouble(*)[3])x);
        vis_ConnectNodeAssoc(connect, VIS_USERID, 1, &i, &nid);
        vis_ConnectNodeAssoc(connect, VIS_CSYSID, 1, &i, &cid);
        printf("id= %d, cid= %d, x= %e %e %e\n", nid, cid, x[0], x[1], x[2]);
        /* check for scalar node */
        vis_ConnectNodeAssoc(connect, VIS_FEATYPE, 1, &i, &featype);
        if (featype == SYS_NODE_SCALAR) {
            printf("featype= Scalar node\n");
        }
    }
}

/*----------------------------------------------------------------------
                      print elements
----------------------------------------------------------------------*/
static void
printElements(vis_Connect* connect)
{
    Vint i, j;
    Vint numel;
    Vint cid;
    Vint eid, pid, mid, partid;
    Vint featype;
    Vint maxelemnode;
    Vint nix, *ix, *ux;
    Vint shape, maxi, maxj, maxk;

    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("Number of elements= %d\n", numel);
    /* elements: connectivity, user id, material and
       property id, etc. */
    printf("\nElements\n");
    vis_ConnectMaxElemNode(connect, &maxelemnode);
    /* allocate vectors for internal node ids and user ids */
    ix = (Vint*)malloc(maxelemnode * sizeof(Vint));
    ux = (Vint*)malloc(maxelemnode * sizeof(Vint));
    for (i = 1; i <= numel; i++) {
        vis_ConnectTopology(connect, i, &shape, &maxi, &maxj, &maxk);
        vis_ConnectElemNode(connect, i, &nix, ix);
        vis_ConnectElemAssoc(connect, VIS_USERID, 1, &i, &eid);
        vis_ConnectElemAssoc(connect, VIS_PARTID, 1, &i, &partid);
        vis_ConnectElemAssoc(connect, VIS_PROPID, 1, &i, &pid);
        vis_ConnectElemAssoc(connect, VIS_MATLID, 1, &i, &mid);
        vis_ConnectElemAssoc(connect, VIS_CSYSID, 1, &i, &cid);
        vis_ConnectElemAssoc(connect, VIS_FEATYPE, 1, &i, &featype);
        printf("id= %d, partid= %d, pid= %d, mid= %d, cid= %d, nodes= %d\n", eid, partid, pid, mid, cid, nix);
        /* interpret shape */
        if (shape == SYS_SHAPEPOINT) {
            printf(" shape= Point(s):");
        }
        else if (shape == SYS_SHAPELINE) {
            printf(" shape= Line:");
        }
        else if (shape == SYS_SHAPETRI) {
            printf(" shape= Triangle:");
        }
        else if (shape == SYS_SHAPEQUAD) {
            printf(" shape= Quadrilateral:");
        }
        else if (shape == SYS_SHAPETET) {
            printf(" shape= Tetrahedron:");
        }
        else if (shape == SYS_SHAPEPYR) {
            printf(" shape= Pyramid:");
        }
        else if (shape == SYS_SHAPEWED) {
            printf(" shape= Pentahedron:");
        }
        else if (shape == SYS_SHAPEHEX) {
            printf(" shape= Hexahedron:");
        }
        else if (shape == SYS_SHAPEPOLYGON) {
            printf(" shape= Polygon:");
        }
        else if (shape == SYS_SHAPEPOLYHED) {
            printf(" shape= Polyhedron:");
        }
        printf("  maxi= %d, maxj= %d, maxk= %d\n", maxi, maxj, maxk);
        /* convert internal index to user id */
        vis_ConnectNodeAssoc(connect, VIS_USERID, nix, ix, ux);
        /* print element connectivity */
        printf(" connectivity=");
        for (j = 0; j < nix; j++) {
            printf(" %d", ux[j]);
        }
        printf("\n");
    }
    /* free vectors */
    free(ix);
    free(ux);
}
