#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"
/*
                 4------5------6
                /.     /.     /.
               / .    / .    / .
              /  .   /  .   /  .
             /   1../...2../...3
            10-----11-----12  /
            |  .   |  .   |  /
            | .    | .    | /
            |.     |.     |/
            7------8------9

         y
         |
         --- x
       /
      z
*/
#define MAX_ELEM 2
#define MAX_NODE 12

/* element connectivity */
static Vint conn[MAX_ELEM][8] = {{1, 2, 5, 4, 7, 8, 11, 10}, {2, 3, 6, 5, 8, 9, 12, 11}};

/* element topologies */
static Vint shap[MAX_ELEM] = {VIS_SHAPEHEX, VIS_SHAPEHEX};
static Vint maxi[MAX_ELEM] = {2, 2};
/* element types */
static Vint featype[MAX_ELEM] = {VIS_ELEM_SOLID, VIS_ELEM_SOLID};

/* element property ids */
static Vint pid[MAX_ELEM] = {1, 1};
/* node coordinates */
static Vdouble coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 0.}, {0., 1., 0.}, {1., 1., 0.}, {2., 1., 0.},
                                      {0., 0., 3.}, {1., 0., 3.}, {2., 0., 3.}, {0., 1., 3.}, {1., 1., 3.}, {2., 1., 3.}};

/*----------------------------------------------------------------------
                      Model Mass Properties Using MassPrp
----------------------------------------------------------------------*/
int
main()
{
    Vint i;
    vis_Model* model;
    vis_Connect* connect;
    vis_MassPrp* massprp;
    vis_MProp* mprop;
    vis_EProp* eprop;
    vsy_HashTable *ephash, *mphash;
    Vfloat vtot, mtot, xcom[3], mten[6];
    Vfloat mpri[3], tm[3][3];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create connect object */
    connect = vis_ConnectBegin();
    vis_ConnectPre(connect, SYS_DOUBLE);
    vis_ConnectDef(connect, MAX_NODE, MAX_ELEM);

    /* set node coordinates and user ids */
    for (i = 0; i < MAX_NODE; i++) {
        vis_ConnectSetCoordsdv(connect, i + 1, coords[i]);
    }
    /* set element topologies */
    for (i = 0; i < MAX_ELEM; i++) {
        vis_ConnectSetTopology(connect, i + 1, shap[i], maxi[i], 0, 0);
    }
    /* set element node connectivity and associations */
    for (i = 0; i < MAX_ELEM; i++) {
        vis_ConnectSetElemNode(connect, i + 1, conn[i]);
        vis_ConnectSetElemAssoc(connect, VIS_FEATYPE, i + 1, featype[i]);
        vis_ConnectSetElemAssoc(connect, VIS_PROPID, i + 1, pid[i]);
    }

    /* create model object hierarchy */
    model = vis_ModelBegin();

    /* hashtables of properties */
    mphash = vsy_HashTableBegin();
    ephash = vsy_HashTableBegin();

    /* material 1 */
    mprop = vis_MPropBegin();
    vis_MPropDef(mprop, SYS_MAT_ISOTROPIC);
    vis_MPropSetValued(mprop, MPROP_E, 1.e+7);
    vis_MPropSetValued(mprop, MPROP_NU, .3);
    vis_MPropSetValued(mprop, MPROP_DENSITY, 1.e-05);
    vsy_HashTableInsert(mphash, 1, mprop);

    /* solid property 1 */
    eprop = vis_EPropBegin();
    vis_EPropDef(eprop, VIS_ELEM_SOLID);
    vis_EPropSetValuei(eprop, EPROP_MID, 1);
    vsy_HashTableInsert(ephash, 1, eprop);

    /* register Connect in Model */
    vis_ModelSetObject(model, VIS_CONNECT, connect);

    /* register property hashtables in Model */
    vis_ModelSetHashTable(model, VIS_MPROP, mphash);
    vis_ModelSetHashTable(model, VIS_EPROP, ephash);

    /* compute and print mass properties */
    massprp = vis_MassPrpBegin();
    vis_MassPrpSetObject(massprp, VIS_MODEL, model);
    vis_MassPrpCompute(massprp, NULL, &vtot, &mtot, xcom, mten);

    printf("Total volume   = %e\n", vtot);
    printf("Total mass     = %e\n", mtot);
    printf("Center of mass = %e %e %e\n", xcom[0], xcom[1], xcom[2]);
    printf("Inertia tensor = %e %e %e\n", mten[0], mten[1], mten[2]);
    printf("                 %e %e %e\n", mten[3], mten[4], mten[5]);

    /* compute principal values and directions */
    vis_MassPrpPrincipal(massprp, mten, mpri, tm);
    printf("Principal values = %e %e %e\n", mpri[0], mpri[1], mpri[2]);
    printf("Principal directions = %e %e %e\n", tm[0][0], tm[0][1], tm[0][2]);
    printf("                     = %e %e %e\n", tm[1][0], tm[1][1], tm[1][2]);
    printf("                     = %e %e %e\n", tm[2][0], tm[2][1], tm[2][2]);

    /* delete objects */
    vis_MassPrpEnd(massprp);
    /* Use convenience routine ModelDelete to destroy
       all objects registered in Model */
    vis_ModelDelete(model);
    /* finally destroy Model object */
    vis_ModelEnd(model);
    return 0;
}
