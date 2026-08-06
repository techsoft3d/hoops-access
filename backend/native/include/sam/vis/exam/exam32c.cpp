#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"
/*
                 5------6
                /.     /.\
  y            / .    / . \
  |           /  .   /  .  \7------8
  --x        /   1../...2../|      |
 /         12-----13-----14 |      |
z           |  .   |  .   |.|      |
            | .    | .    | 3------4
            |.     |.     |/
            9-----10-----11
*/

#define MAX_ELEM 3
#define MAX_NODE 14

static Vint conn[MAX_ELEM][8] = {{1, 2, 6, 5, 9, 10, 13, 12}, {2, 3, 7, 6, 10, 11, 14, 13}, {3, 4, 8, 7, 0, 0, 0, 0}};

static Vint shap[MAX_ELEM] = {VIS_SHAPEHEX, VIS_SHAPEHEX, VIS_SHAPEQUAD};

static Vfloat coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 1.}, {3., 0., 1.}, {0., 1., 0.},
                                     {1., 1., 0.}, {2., 1., 1.}, {3., 1., 1.}, {0., 0., 2.}, {1., 0., 2.},
                                     {2., 0., 2.}, {0., 1., 2.}, {1., 1., 2.}, {2., 1., 2.}};

/*----------------------------------------------------------------------
                      Manage Complex Loads Using LCase
----------------------------------------------------------------------*/
int
main()
{
    vis_Connect* connect;
    vis_GridFun* gf;
    vis_LCase* lcase;
    vis_Group *nodegroup, *facegroup, *edgegroup, *elemgroup;
    Vint i, j;
    Vdouble formom[2 * 6], dist[2 * 3 * 4], body[2 * 3 * 8];
    Vint index, no, flags, flagno;
    Vint numtypes, types[3];
    Vdouble values[2 * 3 * 8];
    Vint tid[2];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create connect object */
    connect = vis_ConnectBegin();
    vis_ConnectDef(connect, MAX_NODE, MAX_ELEM);

    /* set topologies */
    for (i = 0; i < MAX_ELEM; i++) {
        vis_ConnectSetTopology(connect, i + 1, shap[i], 2, 0, 0);
    }
    /* set element node connectivity */
    for (i = 0; i < MAX_ELEM; i++) {
        vis_ConnectSetElemNode(connect, i + 1, conn[i]);
    }
    /* set node coordinates */
    for (i = 0; i < MAX_NODE; i++) {
        vis_ConnectSetCoords(connect, i + 1, coords[i]);
    }
    /* create gridfun object */
    gf = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gf);

    /* instance LCase object */
    lcase = vis_LCaseBegin();
    vis_LCaseSetObject(lcase, VIS_GRIDFUN, gf);

    /* real and imaginary parts */
    vis_LCaseSetComplexMode(lcase, SYS_COMPLEX_REALIMAGINARY);
    /* specify concentrated nodal force and moment at node 2 */
    formom[0] = 1.;
    formom[1] = 11.;
    formom[2] = 2.;
    formom[3] = 21.;
    formom[4] = 3.;
    formom[5] = 31.;
    vis_LCaseSetConcdv(lcase, 2, LCASE_FORCE, formom);
    formom[0] = 4.;
    formom[1] = 41.;
    formom[2] = 5.;
    formom[3] = 51.;
    formom[4] = 6.;
    formom[5] = 61.;
    vis_LCaseSetConcdv(lcase, 2, LCASE_MOMENT, formom);

    /* specify pressure on face 2 of element 1 */
    dist[0] = 100.;
    dist[1] = 101.;
    dist[2] = 200.;
    dist[3] = 201.;
    dist[4] = 300.;
    dist[5] = 301.;
    dist[6] = 400.;
    dist[7] = 401.;
    vis_LCaseSetDistdv(lcase, SYS_FACE, 1, 2, LCASE_PRES, dist);
    /* set specific table id's for real/imaginary parts */
    tid[0] = 1;
    tid[1] = 2;
    vis_LCaseSetDistTId(lcase, SYS_FACE, 1, 2, LCASE_PRES, tid);

    /* specify varying moment along edge 1 of element 3 */
    dist[0] = 20.;
    dist[1] = 30.;
    dist[2] = 21.;
    dist[3] = 31.;
    vis_LCaseSetDistdv(lcase, SYS_EDGE, 3, 1, LCASE_TANGMOMENT, dist);

    /* body force for element 3,
       complex vector at each of 4 nodes on element */
    body[0] = 100.;
    body[1] = 101.;
    body[2] = 0.;
    body[3] = 0.;
    body[4] = 0.;
    body[5] = 0.;
    body[6] = 200.;
    body[7] = 201.;
    body[8] = 0.;
    body[9] = 0.;
    body[10] = 0.;
    body[11] = 0.;
    body[12] = 200.;
    body[13] = 201.;
    body[14] = 0.;
    body[15] = 0.;
    body[16] = 0.;
    body[17] = 0.;
    body[18] = 100.;
    body[19] = 101.;
    body[20] = 0.;
    body[21] = 0.;
    body[22] = 0.;
    body[23] = 0.;
    vis_LCaseSetElemdv(lcase, 3, LCASE_ACCLELEM, body);

    /* query concentrated nodal loads */
    nodegroup = vis_GroupBegin();
    vis_GroupDef(nodegroup, MAX_NODE, SYS_NODE, SYS_NONE);
    vis_GroupClear(nodegroup);

    /* group of nodes with concentrated loads */
    vis_LCaseNodeGroup(lcase, NULL, nodegroup);

    /* iterate through node group */
    printf("\nConcentrated Loads\n");
    vis_GroupInitIndex(nodegroup);
    while (vis_GroupNextIndex(nodegroup, &index, &flags), index) {
        printf("node= %d\n", index);
        vis_LCaseConcType(lcase, index, &numtypes, types);

        /* loop through load types */
        for (i = 0; i < numtypes; i++) {
            vis_LCaseConcdv(lcase, index, types[i], values);
            printf(" values= %f %f(i) %f %f(i) %f %f(i)\n", values[0], values[1], values[2], values[3], values[4], values[5]);
        }
    }
    /* query element loads */
    elemgroup = vis_GroupBegin();
    vis_GroupDef(elemgroup, MAX_ELEM, SYS_ELEM, SYS_NONE);
    vis_GroupClear(elemgroup);

    /* group of elements with element body loads */
    vis_LCaseElemGroup(lcase, NULL, elemgroup);

    /* iterate through element group */
    printf("\nElement Loads\n");
    vis_GroupInitIndex(elemgroup);
    while (vis_GroupNextIndex(elemgroup, &index, &flags), index) {
        printf("elem= %d\n", index);
        vis_LCaseElemType(lcase, index, &numtypes, types);

        /* loop through load types */
        for (i = 0; i < numtypes; i++) {
            vis_LCaseElemdv(lcase, index, types[i], values);
            for (j = 0; j < 4; j++) {
                printf(" %f %f(i) %f %f(i) %f %f(i)\n", values[2 * 3 * j], values[2 * 3 * j + 1], values[2 * 3 * j + 2],
                       values[2 * 3 * j + 3], values[2 * 3 * j + 4], values[2 * 3 * j + 5]);
            }
        }
    }
    /* query element face distributed loads */
    facegroup = vis_GroupBegin();
    vis_GroupDef(facegroup, MAX_ELEM, SYS_ELEM, SYS_FACE);
    vis_GroupClear(facegroup);

    /* group of element faces with distributed loads */
    vis_LCaseFaceGroup(lcase, NULL, facegroup);

    /* iterate through element face group */
    printf("\nElement Face Loads\n");
    vis_GroupInitIndex(facegroup);
    while (vis_GroupNextIndex(facegroup, &index, &flags), index) {
        printf("elem= %d\n", index);

        /* loop through faces */
        for (no = 1; no <= 6; no++) {
            vis_GroupGetEntFlag(facegroup, index, no, &flagno);
            if (flagno == 0)
                continue;
            printf(" face= %d\n", no);
            vis_LCaseDistType(lcase, SYS_FACE, index, no, &numtypes, types);

            /* loop through load types */
            for (i = 0; i < numtypes; i++) {
                vis_LCaseDistdv(lcase, SYS_FACE, index, no, types[i], 0, values);
                vis_LCaseDistTId(lcase, SYS_FACE, index, no, types[i], tid);
                if (types[i] == LCASE_PRES) {
                    printf("  type= Pressure\n");
                    for (j = 0; j < 4; j++) {
                        printf(" %f %f(i)\n", values[2 * j], values[2 * j + 1]);
                    }
                    printf(" %d %d(i)\n", tid[0], tid[1]);
                }
                else if (types[i] == LCASE_TRAC) {
                    printf("  type= Traction\n");
                    for (j = 0; j < 4; j++) {
                        printf(" %f %f(i) %f %f(i) %f %f(i)\n", values[2 * 3 * j], values[2 * 3 * j + 1], values[2 * 3 * j + 2],
                               values[2 * 3 * j + 3], values[2 * 3 * j + 4], values[2 * 3 * j + 5]);
                    }
                }
            }
        }
    }

    /* query element edge distributed loads */
    edgegroup = vis_GroupBegin();
    vis_GroupDef(edgegroup, MAX_ELEM, SYS_ELEM, SYS_EDGE);
    vis_GroupClear(edgegroup);

    /* group of element edges with distributed loads */
    vis_LCaseEdgeGroup(lcase, NULL, edgegroup);

    /* iterate through element edge group */
    printf("\nElement Edge Loads\n");
    vis_GroupInitIndex(edgegroup);
    while (vis_GroupNextIndex(edgegroup, &index, &flags), index) {
        printf("elem= %d\n", index);

        /* loop through edges */
        for (no = 1; no <= 12; no++) {
            vis_GroupGetEntFlag(edgegroup, index, no, &flagno);
            if (flagno == 0)
                continue;
            printf(" edge= %d\n", no);
            vis_LCaseDistType(lcase, SYS_EDGE, index, no, &numtypes, types);

            /* loop through load types */
            for (i = 0; i < numtypes; i++) {
                vis_LCaseDistdv(lcase, SYS_EDGE, index, no, types[i], 0, values);
                if (types[i] == LCASE_TANGMOMENT) {
                    printf("  type= Tangent Moment\n");
                    for (j = 0; j < 2; j++) {
                        printf(" %f %f(i)\n", values[2 * j], values[2 * j + 1]);
                    }
                }
            }
        }
    }
    /* end objects */
    vis_ConnectEnd(connect);
    vis_GridFunEnd(gf);
    vis_LCaseEnd(lcase);
    vis_GroupEnd(nodegroup);
    vis_GroupEnd(elemgroup);
    vis_GroupEnd(facegroup);
    vis_GroupEnd(edgegroup);
    return 0;
}
