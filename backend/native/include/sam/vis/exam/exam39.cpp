#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"
/*
                 4------5------6
       r        /.     /.     /.
       e       / .    / .    / .
       s      /  .   /  .   /  .
       t     /   1../...2../...3
       r    20-----21-----22  /    +--- pressure 50.
       a    |  .   |  .   |  /
       i    | .    | .    | /
       t    |.     |.     |/
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
static Vint conn[MAX_ELEM][8] = {{1, 2, 5, 4, 7, 8, 21, 20}, {2, 3, 6, 5, 8, 9, 22, 21}};

/* user element ids */
static Vint eid[MAX_ELEM] = {10, 20};
/* element topologies */
static Vint shap[MAX_ELEM] = {VIS_SHAPEHEX, VIS_SHAPEHEX};
static Vint maxi[MAX_ELEM] = {2, 2};
/* element types */
static Vint featype[MAX_ELEM] = {VIS_ELEM_SOLID, VIS_ELEM_SOLID};

/* element property ids */
static Vint pid[MAX_ELEM] = {1, 1};
/* node coordinates */
static Vdouble coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 0.}, {0., 1., 0.}, {1., 1., 0.}, {2., 1., 0.},
                                      {0., 0., 2.}, {1., 0., 2.}, {2., 0., 2.}, {0., 1., 2.}, {1., 1., 2.}, {2., 1., 2.}};

/* user node ids */
static Vint nid[MAX_NODE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 20, 21, 22};

/*----------------------------------------------------------------------
                      Export a simple linear static solveable Model
----------------------------------------------------------------------*/
int
main()
{
    Vint i;
    vis_Model* model;
    vis_Connect* connect;
    vis_GridFun* gf;
    vis_MProp* mprop;
    vis_EProp* eprop;
    vis_SProp* sprop;
    vis_RCase* rcase;
    vis_LCase* lcase;
    vsy_HashTable *ephash, *mphash, *rchash, *lchash;
    vsy_List* splist;
    Vdouble pres[4];
    Vint nix, conntran[8];
    Vint id;
    Vint res[2];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create connect object */
    connect = vis_ConnectBegin();
    vis_ConnectPre(connect, SYS_DOUBLE);
    vis_ConnectDef(connect, MAX_NODE, MAX_ELEM);

    /* set node coordinates and user ids */
    for (i = 0; i < MAX_NODE; i++) {
        vis_ConnectSetCoordsdv(connect, i + 1, coords[i]);
        vis_ConnectSetNodeAssoc(connect, VIS_USERID, i + 1, nid[i]);
    }
    /* set element topologies */
    for (i = 0; i < MAX_ELEM; i++) {
        vis_ConnectSetTopology(connect, i + 1, shap[i], maxi[i], 0, 0);
    }
    /* set element node connectivity and associations */
    for (i = 0; i < MAX_ELEM; i++) {
        /* translate connectivity in user ids to
           1,...,MAX_NODE index space */
        vis_ConnectElemNum(connect, SYS_NODE, i + 1, &nix);
        vis_ConnectNodeIndices(connect, nix, conn[i], conntran);
        vis_ConnectSetElemNode(connect, i + 1, conntran);
        vis_ConnectSetElemAssoc(connect, VIS_USERID, i + 1, eid[i]);
        vis_ConnectSetElemAssoc(connect, VIS_FEATYPE, i + 1, featype[i]);
        vis_ConnectSetElemAssoc(connect, VIS_PROPID, i + 1, pid[i]);
    }

    /* create model object hierarchy */
    model = vis_ModelBegin();

    /* hashtables of element and material properties */
    ephash = vsy_HashTableBegin();
    mphash = vsy_HashTableBegin();

    /* hashtables of restraint and load cases */
    rchash = vsy_HashTableBegin();
    lchash = vsy_HashTableBegin();

    /* list of solution procedures */
    splist = vsy_ListBegin();

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

    /* GridFun for use with LCase objects with element loads */
    gf = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gf);

    /* restraint case 1 */
    /* fix nodes 1, 4, 7, 20 in x */
    /* fix node 4 in z, node 7 in y */
    rcase = vis_RCaseBegin();
    vis_ConnectNodeIndex(connect, 1, &id);
    vis_RCaseSetSPC(rcase, id, SYS_DOF_TX, RCASE_FIXED, NULL, 0);
    vis_RCaseSetSPC(rcase, id, SYS_DOF_TY, RCASE_FIXED, NULL, 0);
    vis_RCaseSetSPC(rcase, id, SYS_DOF_TZ, RCASE_FIXED, NULL, 0);
    vis_ConnectNodeIndex(connect, 4, &id);
    vis_RCaseSetSPC(rcase, id, SYS_DOF_TX, RCASE_FIXED, NULL, 0);
    vis_RCaseSetSPC(rcase, id, SYS_DOF_TZ, RCASE_FIXED, NULL, 0);
    vis_ConnectNodeIndex(connect, 7, &id);
    vis_RCaseSetSPC(rcase, id, SYS_DOF_TX, RCASE_FIXED, NULL, 0);
    vis_RCaseSetSPC(rcase, id, SYS_DOF_TY, RCASE_FIXED, NULL, 0);
    vis_ConnectNodeIndex(connect, 20, &id);
    vis_RCaseSetSPC(rcase, id, SYS_DOF_TX, RCASE_FIXED, NULL, 0);
    vsy_HashTableInsert(rchash, 1, rcase);

    /* load case 1 */
    /* uniform pressure on face 6 element 20 */
    /* register GridFun object with LCase */
    lcase = vis_LCaseBegin();
    vis_LCaseSetObject(lcase, VIS_GRIDFUN, gf);
    pres[0] = 50.;
    pres[1] = 50.;
    pres[2] = 50.;
    pres[3] = 50.;
    vis_ConnectElemIndex(connect, 20, &id);
    vis_LCaseSetDistdv(lcase, SYS_FACE, id, 6, LCASE_PRES, pres);
    vsy_HashTableInsert(lchash, 1, lcase);

    /* solution step 1 */
    sprop = vis_SPropBegin();
    vis_SPropDef(sprop, SYS_SOL_STATIC);
    vis_SPropSetValuei(sprop, SPROP_ANALYSIS, SYS_ANALYSIS_STRUCTURAL);
    vis_SPropSetValuei(sprop, SPROP_CASEID, 1);
    vis_SPropSetValuei(sprop, SPROP_RCASE, 1);
    vis_SPropSetValued(sprop, SPROP_RCASE_FACTOR, 1.);
    vis_SPropSetValuei(sprop, SPROP_LCASE_NUM, 1);
    vis_SPropSetValuei(sprop, SPROP_LCASE, 1);
    vis_SPropSetValued(sprop, SPROP_LCASE_FACTOR, 1.);
    /* output requests, displacement, stress */
    res[0] = SYS_RES_D;
    res[1] = SYS_RES_S;
    vis_SPropSetValuei(sprop, SPROP_RESPRINT_NUM, 2);
    vis_SPropSetValueiv(sprop, SPROP_RESPRINT, res);
    vis_SPropSetValuei(sprop, SPROP_RESFILE_NUM, 2);
    vis_SPropSetValueiv(sprop, SPROP_RESFILE, res);
    vsy_ListInsert(splist, 1, sprop);

    /* register Connect in Model */
    vis_ModelSetObject(model, VIS_CONNECT, connect);

    /* register property hashtables in Model */
    vis_ModelSetHashTable(model, VIS_MPROP, mphash);
    vis_ModelSetHashTable(model, VIS_EPROP, ephash);

    /* register case hashtables in Model */
    vis_ModelSetHashTable(model, VIS_RCASE, rchash);
    vis_ModelSetHashTable(model, VIS_LCASE, lchash);

    /* register solution property list in Model */
    vis_ModelSetList(model, VIS_SPROP, splist);

    /* write NASTRAN Bulk Data File */
    vis_ModelWrite(model, SYS_NASTRAN_BULKDATA, (Vchar*)"exam39.bdf");
    /* write ABAQUS Input Data File */
    vis_ModelWrite(model, SYS_ABAQUS_INPUT, (Vchar*)"exam39.inp");
    /* write ANSYS Input Data File */
    vis_ModelWrite(model, SYS_ANSYS_INPUT, (Vchar*)"exam39.cdb");
    /* write LS-DYNA Input Data File */
    vis_ModelWrite(model, SYS_LSTC_INPUT, (Vchar*)"exam39.k");

    /* end objects */
    vis_GridFunEnd(gf);
    /* Use convenience routine ModelDelete to destroy
       all objects registered in Model */
    vis_ModelDelete(model);
    /* finally destroy Model object */
    vis_ModelEnd(model);
    return 0;
}
