#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"
/*
                 5------6
                /.     /.\
               / .    / . \
              /  .   /  .  \70------80             20
             /   1../...2../|       |  \           |
           12-----13-----14 |       |    \        rbe2
            |  .   |  .   |.|       |      \       |
            | .    | .    | 30------40------15-----18
            |.     |.     |/                 |\      \
            9-----10-----11                  rbe3      \
            \      /    /                    |  \        \
             \tet /wed /                    21   22       19
              \  /    /
               16----17
*/
#define MAX_ELEM 11
#define MAX_NODE 22

/* element connectivity */
static Vint conn[MAX_ELEM][8] = {{1, 2, 6, 5, 9, 10, 13, 12}, {2, 30, 70, 6, 10, 11, 14, 13}, {30, 40, 80, 70, 0, 0, 0, 0},
                                 {40, 15, 80, 0, 0, 0, 0, 0}, {9, 10, 13, 16, 0, 0, 0, 0},    {10, 13, 16, 11, 14, 17, 0, 0},
                                 {15, 18, 0, 0, 0, 0, 0, 0},  {18, 0, 0, 0, 0, 0, 0, 0},      {18, 19, 0, 0, 0, 0, 0, 0},
                                 {18, 20, 0, 0, 0, 0, 0, 0},  {15, 21, 22, 0, 0, 0, 0, 0}};

/* user element ids */
static Vint eid[MAX_ELEM] = {10, 11, 20, 21, 30, 31, 100, 101, 102, 103, 104};

/* element topologies */
static Vint shap[MAX_ELEM] = {VIS_SHAPEHEX,  VIS_SHAPEHEX,   VIS_SHAPEQUAD, VIS_SHAPETRI,   VIS_SHAPETET,  VIS_SHAPEWED,
                              VIS_SHAPELINE, VIS_SHAPEPOINT, VIS_SHAPELINE, VIS_SHAPEPOINT, VIS_SHAPEPOINT};
static Vint maxi[MAX_ELEM] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3};

/* element types */
static Vint featype[MAX_ELEM] = {VIS_ELEM_SOLID,         VIS_ELEM_SOLID, VIS_ELEM_SHELL, VIS_ELEM_SHELL,
                                 VIS_ELEM_SOLID,         VIS_ELEM_SOLID, VIS_ELEM_BEAM,  VIS_ELEM_MASS,
                                 VIS_ELEM_SPRINGDASHPOT, VIS_ELEM_RIGID, VIS_ELEM_RIGID};

/* element specs */
static Vint feaspec[MAX_ELEM] = {0, 0, 0, 0, 0, 0, 0, 0, SYS_SPRINGDASHPOT_LINK, SYS_RIGID_KINE, SYS_RIGID_DIST};

/* element property ids */
static Vint pid[MAX_ELEM] = {1, 1, 2, 2, 1, 1, 3, 4, 5, 6, 8};

/* element coordinate system indicators and ids */
static Vint ecid[MAX_ELEM] = {0, 0, 0, 0, 0, 0, SYS_ELEMSYS_VECTOR, 0, 1, 0, 0};

/* node coordinates */
static Vdouble coords[MAX_NODE][3] = {{0., 0., 0.},  {1., 0., 0.}, {2., 0., 1.},  {3., 0., 1.},  {0., 1., 0.}, {1., 1., 0.},
                                      {2., 1., 1.},  {3., 1., 1.}, {0., 0., 2.},  {1., 0., 2.},  {2., 0., 2.}, {0., 1., 2.},
                                      {1., 1., 2.},  {2., 1., 2.}, {4., 0., 1.},  {1., 0., 3.},  {2., 0., 3.}, {5., 0., 1.},
                                      {6., -1., 1.}, {5., 1., 1.}, {4., -1., 1.}, {4.5, -1., 1.}};

/* user node ids */
static Vint nid[MAX_NODE] = {1, 2, 30, 40, 5, 6, 70, 80, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22};

/*----------------------------------------------------------------------
                      Manage a Structural Finite Element Model Using Model
----------------------------------------------------------------------*/
int
main()
{
    Vint i;
    vis_Model* model;
    vis_Connect* connect;
    vis_Units* units;
    vis_ElemDat *elemdatthk, *elemdatvec;
    vis_GridFun* gf;
    vis_CoordSys* coordsys;
    vis_MProp* mprop;
    vis_EProp* eprop;
    vis_SProp* sprop;
    vis_RCase* rcase;
    vis_LCase* lcase;
    vis_CPair* cpair;
    vsy_HashTable *cshash, *ephash, *mphash, *edhash, *rchash, *lchash, *cphash;
    vsy_List* splist;
    Vdouble xo[3], tm[3][3];
    Vdouble force[3], temp;
    Vdouble thk[3];
    Vdouble vec[3], pres[4];
    Vint dofflag[2];
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

    /* hashtables of coordinate systems */
    cshash = vsy_HashTableBegin();

    /* hashtables of element and material properties */
    ephash = vsy_HashTableBegin();
    mphash = vsy_HashTableBegin();

    /* hashtables of element data */
    edhash = vsy_HashTableBegin();

    /* hashtables of restraint and load cases */
    rchash = vsy_HashTableBegin();
    lchash = vsy_HashTableBegin();

    /* hashtable of contact pairs */
    cphash = vsy_HashTableBegin();

    /* list of solution procedures */
    splist = vsy_ListBegin();

    /* units */
    units = vis_UnitsBegin();
    vis_UnitsSetBase(units, UNITS_LENGTH, UNITS_LENGTH_MILLIMETER);
    vis_UnitsSetBase(units, UNITS_MASS, UNITS_MASS_KILOGRAM);
    vis_UnitsSetBase(units, UNITS_TEMP, UNITS_TEMP_KELVIN);

    /* coordinate system 1 for spring element */
    coordsys = vis_CoordSysBegin();
    vis_CoordSysDef(coordsys, SYS_CARTESIAN);
    xo[0] = 0.;
    xo[1] = 0.;
    xo[2] = 0.;
    tm[0][0] = .7071;
    tm[0][1] = -.7071;
    tm[0][2] = 0.;
    tm[1][0] = .7071;
    tm[1][1] = .7071;
    tm[1][2] = 0.;
    tm[2][0] = 0.;
    tm[2][1] = 0.;
    tm[2][2] = 1.;
    vis_CoordSysSetOriginTriaddv(coordsys, xo, tm);
    vsy_HashTableInsert(cshash, 1, coordsys);

    /* material 1 */
    mprop = vis_MPropBegin();
    vis_MPropDef(mprop, SYS_MAT_ISOTROPIC);
    vis_MPropSetValued(mprop, MPROP_E, 1.e+7);
    vis_MPropSetValued(mprop, MPROP_NU, .3);
    vis_MPropSetValued(mprop, MPROP_DENSITY, 0.0000133);
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

    /* mass property 4 */
    eprop = vis_EPropBegin();
    vis_EPropDef(eprop, VIS_ELEM_MASS);
    vis_EPropSetValued(eprop, EPROP_MASS, 3.0);
    vsy_HashTableInsert(ephash, 4, eprop);

    /* spring property 5 */
    eprop = vis_EPropBegin();
    vis_EPropDef(eprop, VIS_ELEM_SPRINGDASHPOT);
    /* x-translation at node 1, y-translation at node 2 */
    vis_EPropSetValuei(eprop, EPROP_DOF1, SYS_DOF_TX);
    vis_EPropSetValuei(eprop, EPROP_DOF2, SYS_DOF_TY);
    vis_EPropSetValued(eprop, EPROP_STIFF, 100000.0);
    vsy_HashTableInsert(ephash, 5, eprop);

    /* rigid (RBE2 type) element property 6 */
    eprop = vis_EPropBegin();
    vis_EPropDef(eprop, SYS_ELEM_RIGID);
    vis_EPropSetValuei(eprop, EPROP_DOFFLAG_NUM, 2);
    /* x,y,z translations and rotations at independent node */
    dofflag[0] = (1 << (SYS_DOF_TX - 1)) | (1 << (SYS_DOF_TY - 1)) | (1 << (SYS_DOF_TZ - 1)) | (1 << (SYS_DOF_RX - 1)) |
                 (1 << (SYS_DOF_RY - 1)) | (1 << (SYS_DOF_RZ - 1));
    dofflag[1] = 0;
    vis_EPropSetValueiv(eprop, EPROP_DOFFLAG_IND, dofflag);
    /* x,y,z translations at dependent node */
    dofflag[0] = 0;
    dofflag[1] = (1 << (SYS_DOF_TX - 1)) | (1 << (SYS_DOF_TY - 1)) | (1 << (SYS_DOF_TZ - 1));
    vis_EPropSetValueiv(eprop, EPROP_DOFFLAG_DEP, dofflag);
    /* optional penalty, may or may not be used */
    vis_EPropSetValued(eprop, EPROP_PENALTY, 1.0e+12);
    vsy_HashTableInsert(ephash, 6, eprop);

    /* gap property 7 */
    eprop = vis_EPropBegin();
    vis_EPropDef(eprop, VIS_ELEM_GAP);
    vis_EPropSetValuei(eprop, EPROP_NOSLIP, SYS_ON);
    vis_EPropSetValuei(eprop, EPROP_NOSEPARATION, SYS_ON);
    vsy_HashTableInsert(ephash, 7, eprop);

    /* rigid (RBE3 type) element property 8 */
    eprop = vis_EPropBegin();
    vis_EPropDef(eprop, SYS_ELEM_RIGID);
    vis_EPropSetValuei(eprop, EPROP_DOFFLAG_NUM, 2);
    /* x,y,z translations and rotations at reference node */
    dofflag[0] = (1 << (SYS_DOF_TX - 1)) | (1 << (SYS_DOF_TY - 1)) | (1 << (SYS_DOF_TZ - 1)) | (1 << (SYS_DOF_RX - 1)) |
                 (1 << (SYS_DOF_RY - 1)) | (1 << (SYS_DOF_RZ - 1));
    dofflag[1] = 0;
    vis_EPropSetValueiv(eprop, EPROP_DOFFLAG_DEP, dofflag);
    /* x,y,z translations at distributing nodes */
    dofflag[0] = 0;
    dofflag[1] = (1 << (SYS_DOF_TX - 1)) | (1 << (SYS_DOF_TY - 1)) | (1 << (SYS_DOF_TZ - 1));
    vis_EPropSetValueiv(eprop, EPROP_DOFFLAG_IND, dofflag);
    vis_EPropSetValued(eprop, EPROP_DOFFLAG_WGTS, 2.);
    /* optional penalty, may or may not be used */
    vis_EPropSetValued(eprop, EPROP_PENALTY, 1.0e+12);
    vsy_HashTableInsert(ephash, 8, eprop);

    /* GridFun */
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

    /* contact pair, hex element 11 face 6 and shell element 20
       use gap property 7 */
    cpair = vis_CPairBegin();
    vis_CPairDef(cpair, SYS_FACE, SYS_FACE);
    vis_CPairSetObject(cpair, VIS_GRIDFUN, gf);
    vis_IdTranIndex(idtranelem, 11, &id);
    vis_CPairSetMaster(cpair, id, 6);
    vis_IdTranIndex(idtranelem, 20, &id);
    vis_CPairSetSlaveElem(cpair, id, 1);
    vis_CPairSetValuei(cpair, CPAIR_PID, 7);
    vis_CPairSetValued(cpair, CPAIR_ADJUST, .1);
    vis_CPairSetValuei(cpair, CPAIR_ID, 10);
    vsy_HashTableInsert(cphash, 1, cpair);

    /* restraint case 1 */
    rcase = vis_RCaseBegin();
    for (i = 1; i <= 3; i++) {
        vis_RCaseSetSPC(rcase, i, SYS_DOF_TX, RCASE_FIXED, NULL, 0);
        vis_RCaseSetSPC(rcase, i, SYS_DOF_TY, RCASE_FIXED, NULL, 0);
        vis_RCaseSetSPC(rcase, i, SYS_DOF_TZ, RCASE_FIXED, NULL, 0);
    }
    vsy_HashTableInsert(rchash, 1, rcase);

    /* load case 1 */
    lcase = vis_LCaseBegin();

    /* concentrated force on node 12 */
    force[0] = 1.;
    force[1] = 2.;
    force[2] = 3.;
    vis_IdTranIndex(idtrannode, 12, &id);
    vis_LCaseSetConcdv(lcase, id, LCASE_FORCE, force);

    /* temperatures on nodes 16 and 17 */
    vis_IdTranIndex(idtrannode, 16, &id);
    temp = 100.;
    vis_LCaseSetConcdv(lcase, id, LCASE_TEMP, &temp);
    vis_IdTranIndex(idtrannode, 17, &id);
    temp = 200.;
    vis_LCaseSetConcdv(lcase, id, LCASE_TEMP, &temp);

    /* uniform pressure on face 2 element 10 */
    /* register GridFun object with LCase */
    vis_LCaseSetObject(lcase, VIS_GRIDFUN, gf);
    pres[0] = 50.;
    pres[1] = 50.;
    pres[2] = 50.;
    pres[3] = 50.;
    vis_IdTranIndex(idtranelem, 10, &id);
    vis_LCaseSetDistdv(lcase, SYS_FACE, id, 2, LCASE_PRES, pres);
    vsy_HashTableInsert(lchash, 1, lcase);

    /* solution step 1 */
    sprop = vis_SPropBegin();
    vis_SPropDef(sprop, SYS_SOL_STATIC);
    vis_SPropSetValuei(sprop, SPROP_CASEID, 1);
    vis_SPropSetValuei(sprop, SPROP_NONLINEAR, 1);
    vis_SPropSetValuei(sprop, SPROP_RCASE, 1);
    vis_SPropSetValued(sprop, SPROP_RCASE_FACTOR, 1.);
    vis_SPropSetValuei(sprop, SPROP_LCASE_NUM, 1);
    vis_SPropSetValuei(sprop, SPROP_LCASE, 1);
    vis_SPropSetValued(sprop, SPROP_LCASE_FACTOR, 1.);
    vis_SPropSetValuei(sprop, SPROP_CONTACT_NUM, 1);
    vis_SPropSetValuei(sprop, SPROP_CONTACT_CASE, 10);
    vis_SPropSetValued(sprop, SPROP_TIME_INIT, .2);
    vis_SPropSetValued(sprop, SPROP_TIME_STEP, .1);
    vis_SPropSetValued(sprop, SPROP_TIME_TERM, 1.);
    vsy_ListInsert(splist, 1, sprop);

    /* register Connect in Model */
    vis_ModelSetObject(model, VIS_CONNECT, connect);

    /* register Units in Model */
    vis_ModelSetObject(model, VIS_UNITS, units);

    /* register coordinate system hashtables in Model */
    vis_ModelSetHashTable(model, VIS_COORDSYS, cshash);

    /* register property hashtables in Model */
    vis_ModelSetHashTable(model, VIS_MPROP, mphash);
    vis_ModelSetHashTable(model, VIS_EPROP, ephash);

    /* register element data hashtables in Model */
    vis_ModelSetHashTable(model, VIS_ELEMDAT, edhash);

    /* register case hashtables in Model */
    vis_ModelSetHashTable(model, VIS_RCASE, rchash);
    vis_ModelSetHashTable(model, VIS_LCASE, lchash);

    /* register contact pair hashtable in Model */
    vis_ModelSetHashTable(model, VIS_CPAIR, cphash);

    /* register solution property list in Model */
    vis_ModelSetList(model, VIS_SPROP, splist);

    /* print to standard output */
    vis_ModelPrint(model);
    /* write NASTRAN Bulk Data File */
    vis_ModelWrite(model, SYS_NASTRAN_BULKDATA, (Vchar*)"exam39a.bdf");
    /* write ABAQUS Input Data File */
    vis_ModelWrite(model, SYS_ABAQUS_INPUT, (Vchar*)"exam39a.inp");
    /* write ANSYS Input Data File */
    vis_ModelWrite(model, SYS_ANSYS_INPUT, (Vchar*)"exam39a.cdb");
    /* write Ideas Universal File */
    vis_ModelWrite(model, SYS_SDRC_UNIVERSAL, (Vchar*)"exam39a.unv");
    /* write PATRAN Neutral File */
    vis_ModelWrite(model, SYS_PATRAN_NEUTRAL, (Vchar*)"exam39a.out");
    /* write LS-DYNA Input Data File */
    vis_ModelWrite(model, SYS_LSTC_INPUT, (Vchar*)"exam39a.k");

    /* end objects */
    vis_IdTranEnd(idtrannode);
    vis_IdTranEnd(idtranelem);
    vis_GridFunEnd(gf);
    vis_ModelDelete(model);
    vis_ModelEnd(model);
    return 0;
}
