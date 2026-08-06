#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"
/*
                 5------6
                /.     /.\
               / .    / . \
              /  .   /  .  \70------80
             /   1../...2../|       |  \
           12-----13-----14 |       |    \
            |  .   |  .   |.|       |      \
            | .    | .    | 30------40------15-----18
            |.     |.     |/
            9-----10-----11
            \      /    /
             \tet /wed /
              \  /    /
               16----17
*/
#define MAX_ELEM 7
#define MAX_NODE 18

/* element connectivity */
static Vint conn[MAX_ELEM][8] = {{1, 2, 6, 5, 9, 10, 13, 12}, {2, 30, 70, 6, 10, 11, 14, 13}, {30, 40, 80, 70, 0, 0, 0, 0},
                                 {40, 15, 80, 0, 0, 0, 0, 0}, {9, 10, 13, 16, 0, 0, 0, 0},    {10, 13, 16, 11, 14, 17, 0, 0},
                                 {15, 18, 0, 0, 0, 0, 0, 0}};

/* user element ids */
static Vint eid[MAX_ELEM] = {10, 11, 20, 21, 30, 31, 100};

/* element topologies */
static Vint shap[MAX_ELEM] = {VIS_SHAPEHEX, VIS_SHAPEHEX, VIS_SHAPEQUAD, VIS_SHAPETRI, VIS_SHAPETET, VIS_SHAPEWED, VIS_SHAPELINE};
static Vint maxi[MAX_ELEM] = {0, 0, 0, 0, 0, 0, 0};

/* element types */
static Vint featype[MAX_ELEM] = {VIS_ELEM_SOLID, VIS_ELEM_SOLID, VIS_ELEM_SHELL, VIS_ELEM_SHELL,
                                 VIS_ELEM_SOLID, VIS_ELEM_SOLID, VIS_ELEM_BEAM};

/* element specs */
static Vint feaspec[MAX_ELEM] = {0, 0, 0, 0, 0, 0, 0};

/* element property ids */
static Vint pid[MAX_ELEM] = {1, 1, 2, 2, 1, 1, 3};

/* element coordinate system indicators and ids */
static Vint ecid[MAX_ELEM] = {0, 0, 0, 0, 0, 0, SYS_ELEMSYS_VECTOR};

/* node coordinates */
static Vdouble coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 1.}, {3., 0., 1.}, {0., 1., 0.}, {1., 1., 0.},
                                      {2., 1., 1.}, {3., 1., 1.}, {0., 0., 2.}, {1., 0., 2.}, {2., 0., 2.}, {0., 1., 2.},
                                      {1., 1., 2.}, {2., 1., 2.}, {4., 0., 1.}, {1., 0., 3.}, {2., 0., 3.}, {5., 0., 1.}};

/* user node ids */
static Vint nid[MAX_NODE] = {1, 2, 30, 40, 5, 6, 70, 80, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};

/*----------------------------------------------------------------------
                      Manage a Heat Transfer Finite Element Model Using Model
----------------------------------------------------------------------*/
int
main()
{
    Vint i;
    vis_Model* model;
    vis_Connect* connect;
    vis_ElemDat *elemdatthk, *elemdatvec;
    vis_GridFun* gf;
    vis_MProp* mprop;
    vis_EProp* eprop;
    vis_SProp* sprop;
    vis_ICase* icase;
    vis_RCase* rcase;
    vis_LCase* lcase;
    vsy_HashTable *ephash, *mphash, *edhash, *ichash, *rchash, *lchash;
    vsy_List* splist;
    Vdouble cflux;
    Vdouble thk[4];
    Vdouble vec[3], flux[4], conv[8];
    Vdouble val;
    Vint tag;
    vis_IdTran *idtrannode, *idtranelem;
    Vint nix, conntran[8];
    Vint id;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create connect object */
    connect = vis_ConnectBegin();
    vis_ConnectPre(connect, SYS_DOUBLE);
    vis_ConnectDef(connect, MAX_NODE, MAX_ELEM);

    /* set up user node and element id translation */
    idtrannode = vis_IdTranBegin();
    for (i = 0; i < MAX_NODE; i++) {
        vis_IdTranSetId(idtrannode, i + 1, nid[i]);
    }
    idtranelem = vis_IdTranBegin();
    for (i = 0; i < MAX_ELEM; i++) {
        vis_IdTranSetId(idtranelem, i + 1, eid[i]);
    }
    /* set node coordinates */
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
        vis_ConnectElemNum(connect, SYS_NODE, i + 1, &nix);
        vis_IdTranIndices(idtrannode, nix, conn[i], conntran);
        vis_ConnectSetElemNode(connect, i + 1, conntran);
        vis_ConnectSetElemAssoc(connect, VIS_USERID, i + 1, eid[i]);
        vis_ConnectSetElemAssoc(connect, VIS_FEATYPE, i + 1, featype[i]);
        vis_ConnectSetElemAssoc(connect, VIS_FEASPEC, i + 1, feaspec[i]);
        vis_ConnectSetElemAssoc(connect, VIS_PROPID, i + 1, pid[i]);
        vis_ConnectSetElemAssoc(connect, VIS_CSYSID, i + 1, ecid[i]);
    }

    /* create model object hierarchy */
    model = vis_ModelBegin();

    /* hashtables of element and material properties */
    ephash = vsy_HashTableBegin();
    mphash = vsy_HashTableBegin();

    /* hashtables of element data */
    edhash = vsy_HashTableBegin();

    /* hashtables of initial condition, restraint, load cases */
    ichash = vsy_HashTableBegin();
    rchash = vsy_HashTableBegin();
    lchash = vsy_HashTableBegin();

    /* list of solution procedures */
    splist = vsy_ListBegin();

    /* material 1 */
    mprop = vis_MPropBegin();
    vis_MPropDef(mprop, SYS_MAT_ISOTROPIC);
    vis_MPropSetValued(mprop, MPROP_K, 1.e+3);
    vsy_HashTableInsert(mphash, 1, mprop);

    /* solid property 1 */
    eprop = vis_EPropBegin();
    vis_EPropDef(eprop, VIS_ELEM_SOLID);
    vis_EPropSetValuei(eprop, EPROP_MID, 1);
    vsy_HashTableInsert(ephash, 1, eprop);

    /* shell property 2 */
    eprop = vis_EPropBegin();
    vis_EPropDef(eprop, VIS_ELEM_SHELL);
    vis_EPropSetValuei(eprop, EPROP_MID, 1);
    vis_EPropSetValued(eprop, EPROP_THICKNESS, .5);
    vsy_HashTableInsert(ephash, 2, eprop);

    /* beam property 3 */
    eprop = vis_EPropBegin();
    vis_EPropDef(eprop, VIS_ELEM_BEAM);
    vis_EPropSetValuei(eprop, EPROP_MID, 1);
    vis_EPropSetValued(eprop, EPROP_AREA, 2.0);
    vsy_HashTableInsert(ephash, 3, eprop);

    /* GridFun for element data objects */
    gf = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gf);

    /* ElemDat of shell element node thickness */
    elemdatthk = vis_ElemDatBegin();
    vis_ElemDatDef(elemdatthk, MAX_ELEM, SYS_ELEM, SYS_NODE, SYS_SCALAR);
    vis_ElemDatSetObject(elemdatthk, VIS_GRIDFUN, gf);

    /* ElemDat of beam element orientation vectors */
    elemdatvec = vis_ElemDatBegin();
    vis_ElemDatDef(elemdatvec, MAX_ELEM, SYS_ELEM, SYS_NONE, SYS_VECTOR);
    vis_ElemDatSetObject(elemdatvec, VIS_GRIDFUN, gf);

    /* shell element 21 is tapered */
    thk[0] = .5;
    thk[1] = .3;
    thk[2] = .5;
    vis_IdTranIndex(idtranelem, 21, &id);
    vis_ElemDatSetDatadv(elemdatthk, id, 0, thk);
    vsy_HashTableInsert(edhash, SYS_PROP_THICKNESS, elemdatthk);

    /* beam element 100 orientation vector */
    vec[0] = 0.;
    vec[1] = 1.;
    vec[2] = 0.;
    vis_IdTranIndex(idtranelem, 100, &id);
    vis_ElemDatSetDatadv(elemdatvec, id, 0, vec);
    vsy_HashTableInsert(edhash, SYS_PROP_ELEMVEC, elemdatvec);

    /* restraint case 1 */
    rcase = vis_RCaseBegin();
    val = 120.;
    for (i = 1; i <= 3; i++) {
        vis_RCaseSetSPCdv(rcase, i, SYS_DOF_TEMP, RCASE_APPLIED, &val, 0);
    }
    vsy_HashTableInsert(rchash, 1, rcase);

    /* load case 1 */
    lcase = vis_LCaseBegin();

    /* concentrated flux on node 12 */
    cflux = 2.;
    vis_IdTranIndex(idtrannode, 12, &id);
    vis_LCaseSetConcdv(lcase, id, LCASE_HEAT, &cflux);

    /* initial condition case number 2,
       try to avoid using load or restraint case number */
    icase = vis_ICaseBegin();
    tag = SYS_DOF_TEMP;
    val = 120.;
    for (i = 1; i <= MAX_NODE; i++) {
        vis_ICaseSetSPVdv(icase, i, ICASE_DOF, 1, &tag, &val);
    }
    vsy_HashTableInsert(ichash, 2, icase);

    /* register GridFun object with LCase */
    vis_LCaseSetObject(lcase, VIS_GRIDFUN, gf);
    /* uniform edge flux on edge 1 element 20 */
    flux[0] = 50.;
    flux[1] = 50.;
    vis_IdTranIndex(idtranelem, 20, &id);
    vis_LCaseSetDistdv(lcase, SYS_EDGE, id, 1, LCASE_HEATFLUX, flux);
    /* uniform edge flux on edge 1 element 21 */
    vis_IdTranIndex(idtranelem, 21, &id);
    vis_LCaseSetDistdv(lcase, SYS_EDGE, id, 1, LCASE_HEATFLUX, flux);
    /* uniform face convection on face 2 element 10 */
    conv[0] = 100.;
    conv[1] = 4.;
    conv[2] = 100.;
    conv[3] = 4.;
    conv[4] = 100.;
    conv[5] = 4.;
    conv[6] = 100.;
    conv[7] = 4.;
    vis_IdTranIndex(idtranelem, 10, &id);
    vis_LCaseSetDistdv(lcase, SYS_FACE, id, 2, LCASE_HEATCONV, conv);
    vsy_HashTableInsert(lchash, 1, lcase);

    /* solution step 1 */
    sprop = vis_SPropBegin();
    vis_SPropDef(sprop, SYS_SOL_TRANSIENT);
    vis_SPropSetValuei(sprop, SPROP_ANALYSIS, SYS_ANALYSIS_THERMAL);
    vis_SPropSetValuei(sprop, SPROP_CASEID, 1);
    vis_SPropSetValuei(sprop, SPROP_ICASE, 2);
    vis_SPropSetValuei(sprop, SPROP_RCASE, 1);
    vis_SPropSetValued(sprop, SPROP_RCASE_FACTOR, 1.);
    vis_SPropSetValuei(sprop, SPROP_LCASE_NUM, 1);
    vis_SPropSetValuei(sprop, SPROP_LCASE, 1);
    vis_SPropSetValued(sprop, SPROP_LCASE_FACTOR, 1.);
    vis_SPropSetValued(sprop, SPROP_TIME_INIT, 0.);
    vis_SPropSetValued(sprop, SPROP_TIME_STEP, .1);
    vis_SPropSetValued(sprop, SPROP_TIME_TERM, 2.);
    vsy_ListInsert(splist, 1, sprop);

    /* register Connect in Model */
    vis_ModelSetObject(model, VIS_CONNECT, connect);

    /* register property hashtables in Model */
    vis_ModelSetHashTable(model, VIS_MPROP, mphash);
    vis_ModelSetHashTable(model, VIS_EPROP, ephash);

    /* register element data hashtables in Model */
    vis_ModelSetHashTable(model, VIS_ELEMDAT, edhash);

    /* register case hashtables in Model */
    vis_ModelSetHashTable(model, VIS_ICASE, ichash);
    vis_ModelSetHashTable(model, VIS_RCASE, rchash);
    vis_ModelSetHashTable(model, VIS_LCASE, lchash);

    /* register solution property list in Model */
    vis_ModelSetList(model, VIS_SPROP, splist);

    /* print to standard output */
    vis_ModelPrint(model);
    /* write NASTRAN Bulk Data File */
    vis_ModelWrite(model, SYS_NASTRAN_BULKDATA, (Vchar*)"exam39c.bdf");
    /* write ABAQUS Input Data File */
    vis_ModelWrite(model, SYS_ABAQUS_INPUT, (Vchar*)"exam39c.inp");
    /* write ANSYS Input Data File */
    vis_ModelWrite(model, SYS_ANSYS_INPUT, (Vchar*)"exam39c.cdb");
    /* write Ideas Universal File */
    vis_ModelWrite(model, SYS_SDRC_UNIVERSAL, (Vchar*)"exam39c.unv");
    /* write PATRAN Neutral File */
    vis_ModelWrite(model, SYS_PATRAN_NEUTRAL, (Vchar*)"exam39c.out");

    /* end objects */
    vis_IdTranEnd(idtrannode);
    vis_IdTranEnd(idtranelem);
    vis_GridFunEnd(gf);
    vis_ModelDelete(model);
    vis_ModelEnd(model);
    return 0;
}
