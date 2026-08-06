#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/visdata.h"
#include "sam/vdm/vdm.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"
/*
  y            4------5------6
  |           /.     /.     /|
  --x        / .    / .    / |
 /         10-----11-----12  |
z           |  1...|..2...|..3
            | .    | .    | /
            |.     |.     |/
            7------8------9
*/
#define MAX_ELEM 12
#define MAX_NODE 12

static Vint conn[MAX_ELEM][8] = {{1, 2, 5, 4, 7, 8, 11, 10}, {2, 3, 6, 5, 8, 9, 12, 11}, {1, 4, 5, 2, 0, 0, 0, 0},
                                 {2, 5, 6, 3, 0, 0, 0, 0},   {4, 10, 11, 5, 0, 0, 0, 0}, {5, 11, 12, 6, 0, 0, 0, 0},
                                 {10, 7, 8, 11, 0, 0, 0, 0}, {11, 8, 9, 12, 0, 0, 0, 0}, {7, 1, 2, 8, 0, 0, 0, 0},
                                 {8, 2, 3, 9, 0, 0, 0, 0},   {3, 6, 12, 9, 0, 0, 0, 0},  {1, 4, 10, 7, 0, 0, 0, 0}};

static Vint shap[MAX_ELEM] = {SYS_SHAPEHEX,  SYS_SHAPEHEX,  SYS_SHAPEQUAD, SYS_SHAPEQUAD, SYS_SHAPEQUAD, SYS_SHAPEQUAD,
                              SYS_SHAPEQUAD, SYS_SHAPEQUAD, SYS_SHAPEQUAD, SYS_SHAPEQUAD, SYS_SHAPEQUAD, SYS_SHAPEQUAD};

static Vint etyp[MAX_ELEM] = {VIS_ELEM_SOLID, VIS_ELEM_SOLID, VIS_ELEM_INTER, VIS_ELEM_INTER, VIS_ELEM_INTER, VIS_ELEM_INTER,
                              VIS_ELEM_INTER, VIS_ELEM_INTER, VIS_ELEM_INTER, VIS_ELEM_INTER, VIS_ELEM_INTER, VIS_ELEM_INTER};

static Vint espc[MAX_ELEM] = {SYS_SOLID_FLUID, SYS_SOLID_FLUID, SYS_INTER_WALL,   SYS_INTER_WALL,
                              SYS_INTER_WALL,  SYS_INTER_WALL,  SYS_INTER_WALL,   SYS_INTER_WALL,
                              SYS_INTER_WALL,  SYS_INTER_WALL,  SYS_INTER_OUTLET, SYS_INTER_INLET};

static Vint prop[MAX_ELEM] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 7};

static Vfloat coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 0.}, {0., 1., 0.}, {1., 1., 0.}, {2., 1., 0.},
                                     {0., 0., 2.}, {1., 0., 2.}, {2., 0., 2.}, {0., 1., 2.}, {1., 1., 2.}, {2., 1., 2.}};

/*----------------------------------------------------------------------
                      Export Simple CFD Finite Element Model and Results
----------------------------------------------------------------------*/
int
main()
{
    Vint i;
    vis_Connect* connect;
    vis_Model* model;
    vis_State *staten, *statee, *stateg;
    vis_RProp *rpropn, *rprope, *rpropg;
    vis_GridFun* gf;

    vdm_LMan* lman;
    vdm_DataFun* datafun;
    vdm_SDRCLib* sdrclib;
    vdm_CGNSVLib* cgnsvlib;
    vdm_FLUENTLib* fluentlib;
    vdm_EnSightLib* ensightlib;
    vdm_TecplotLib* tecplotlib;
    vdm_NatLib* natlib;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create connect object */
    connect = vis_ConnectBegin();
    vis_ConnectDef(connect, MAX_NODE, MAX_ELEM);

    /* set topology and connectivity */
    for (i = 0; i < MAX_ELEM; i++) {
        vis_ConnectSetTopology(connect, i + 1, shap[i], 2, 0, 0);
        vis_ConnectSetElemNode(connect, i + 1, conn[i]);
        vis_ConnectSetElemAssoc(connect, VIS_FEATYPE, i + 1, etyp[i]);
        vis_ConnectSetElemAssoc(connect, VIS_FEASPEC, i + 1, espc[i]);
        vis_ConnectSetElemAssoc(connect, VIS_PROPID, i + 1, prop[i]);
        vis_ConnectSetElemAssoc(connect, VIS_PARTID, i + 1, prop[i]);
        if (espc[i] == SYS_INTER_OUTLET) {
            vis_ConnectSetPartName(connect, prop[i], (Vchar*)"outlet");
        }
    }
    /* set node coordinates */
    for (i = 0; i < MAX_NODE; i++) {
        vis_ConnectSetCoords(connect, i + 1, coords[i]);
    }
    /* create model object and install connect object */
    model = vis_ModelBegin();
    vis_ModelSetObject(model, VIS_CONNECT, connect);

    /* create a grid function object */
    gf = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gf);

    /* create a node vector state */
    staten = vis_StateBegin();
    vis_StateDef(staten, MAX_NODE, SYS_NODE, SYS_NONE, VIS_VECTOR);
    vis_StateSetObject(staten, VIS_GRIDFUN, gf);

    /* use node coordinates as "velocity" for convenience */
    for (i = 0; i < MAX_NODE; i++) {
        vis_StateSetData(staten, i + 1, coords[i]);
    }
    /* create result property for node velocity state */
    rpropn = vis_RPropBegin();
    vis_RPropDef(rpropn, SYS_NODE, SYS_NONE);
    /* set velocity quantity */
    vis_RPropSetType(rpropn, SYS_RES_V);
    /* set ids, eg. step 1 */
    vis_RPropSetIds(rpropn, 1, 0, 0);
    vis_RPropSetValuec(rpropn, RPROP_TITLE, (Vchar*)"Velocity step 1");

    /* create a element scalar pressure state */
    statee = vis_StateBegin();
    vis_StateDef(statee, MAX_ELEM, SYS_ELEM, SYS_NONE, VIS_SCALAR);
    vis_StateSetObject(statee, VIS_GRIDFUN, gf);
    /* use element number as "pressure" for convenience */
    for (i = 0; i < MAX_ELEM; i++) {
        Vfloat s;
        s = (Vfloat)i + 1;
        vis_StateSetData(statee, i + 1, &s);
    }
    /* create result property for element pressure state */
    rprope = vis_RPropBegin();
    vis_RPropDef(rprope, SYS_ELEM, SYS_NONE);
    vis_RPropSetType(rprope, SYS_RES_PRES);
    vis_RPropSetIds(rprope, 1, 0, 0);
    vis_RPropSetValuec(rprope, RPROP_TITLE, (Vchar*)"Pressure step 1");

    /* create a element scalar generic state */
    stateg = vis_StateBegin();
    vis_StateDef(stateg, MAX_ELEM, SYS_ELEM, SYS_NONE, VIS_SCALAR);
    vis_StateSetObject(stateg, VIS_GRIDFUN, gf);
    /* use negative element number as data for convenience */
    for (i = 0; i < MAX_ELEM; i++) {
        Vfloat s;
        s = (Vfloat)i + 1;
        vis_StateSetData(stateg, i + 1, &s);
    }
    /* create result property for element generic state */
    rpropg = vis_RPropBegin();
    vis_RPropDef(rpropg, SYS_ELEM, SYS_NONE);
    vis_RPropSetType(rpropg, SYS_RES_UNKNOWN);
    vis_RPropSetQual(rpropg, 0, NULL, (Vchar*)"MyGenericData");
    vis_RPropSetIds(rpropg, 1, 0, 0);
    vis_RPropSetValuec(rpropg, RPROP_TITLE, (Vchar*)"GenericData step 1");

    /* now export to VdmTools supported results files */
    datafun = vdm_DataFunBegin();
    lman = vdm_LManBegin();
    vdm_LManSetObject(lman, VDM_DATAFUN, datafun);

    /* write to SDRC .unv */
    sdrclib = vdm_SDRCLibBegin();
    vdm_SDRCLibDataFun(sdrclib, datafun);
    vdm_DataFunSetStatus(datafun, VDM_STATUS_NEW);
    vdm_DataFunOpen(datafun, 0, (Vchar*)"exam38bvdm.unv", SYS_SDRC_UNIVERSAL);
    vdm_LManSaveModel(lman, model);
    vdm_LManSaveState(lman, staten, rpropn);
    vdm_LManSaveState(lman, statee, rprope);
    vdm_LManSaveState(lman, stateg, rpropg);
    vdm_DataFunClose(datafun);
    vdm_SDRCLibEnd(sdrclib);

    /* write to CGNS .cgns */
    cgnsvlib = vdm_CGNSVLibBegin();
    vdm_CGNSVLibDataFun(cgnsvlib, datafun);
    vdm_DataFunSetStatus(datafun, VDM_STATUS_NEW);
    vdm_DataFunOpen(datafun, 0, (Vchar*)"exam38bvdm.cgns", SYS_CGNS);
    if (vdm_DataFunError(datafun) == 0) {
        vdm_LManSaveModel(lman, model);
        vdm_LManSaveState(lman, staten, rpropn);
        vdm_LManSaveState(lman, statee, rprope);
        vdm_LManSaveState(lman, stateg, rpropg);
    }
    vdm_DataFunClose(datafun);
    vdm_CGNSVLibEnd(cgnsvlib);

    /* write to FLUENT .msh */
    fluentlib = vdm_FLUENTLibBegin();
    vdm_FLUENTLibDataFun(fluentlib, datafun);
    vdm_DataFunSetStatus(datafun, VDM_STATUS_NEW);
    vdm_DataFunOpen(datafun, 0, (Vchar*)"exam38bvdm.msh", SYS_FLUENT_MESH);
    vdm_LManSaveModel(lman, model);
    vdm_LManSaveState(lman, staten, rpropn);
    vdm_LManSaveState(lman, statee, rprope);
    vdm_LManSaveState(lman, stateg, rpropg);
    vdm_DataFunClose(datafun);
    vdm_FLUENTLibEnd(fluentlib);

    /* write to EnSight .case */
    ensightlib = vdm_EnSightLibBegin();
    vdm_EnSightLibDataFun(ensightlib, datafun);
    vdm_DataFunSetStatus(datafun, VDM_STATUS_NEW);
    vdm_DataFunOpen(datafun, 0, (Vchar*)"exam38bvdm.case", SYS_ENSIGHT);
    vdm_LManSaveModel(lman, model);
    vdm_LManSaveState(lman, staten, rpropn);
    vdm_LManSaveState(lman, statee, rprope);
    vdm_LManSaveState(lman, stateg, rpropg);
    vdm_DataFunClose(datafun);
    vdm_EnSightLibEnd(ensightlib);

    /* write to Tecplot .plt */
    tecplotlib = vdm_TecplotLibBegin();
    vdm_TecplotLibDataFun(tecplotlib, datafun);
    vdm_DataFunSetStatus(datafun, VDM_STATUS_NEW);
    vdm_DataFunOpen(datafun, 0, (Vchar*)"exam38bvdm.plt", SYS_TECPLOT);
    vdm_LManSaveModel(lman, model);
    vdm_LManSaveState(lman, staten, rpropn);
    vdm_LManSaveState(lman, statee, rprope);
    vdm_LManSaveState(lman, stateg, rpropg);
    vdm_DataFunClose(datafun);
    vdm_TecplotLibEnd(tecplotlib);

    /* write to Native .vdm */
    natlib = vdm_NatLibBegin();
    vdm_NatLibDataFun(natlib, datafun);
    vdm_DataFunSetStatus(datafun, VDM_STATUS_NEW);
    vdm_DataFunOpen(datafun, 0, (Vchar*)"exam38bvdm.vdm", SYS_NATIVE);
    vdm_LManSaveModel(lman, model);
    vdm_LManSaveState(lman, staten, rpropn);
    vdm_LManSaveState(lman, statee, rprope);
    vdm_LManSaveState(lman, stateg, rpropg);
    vdm_DataFunClose(datafun);
    vdm_NatLibEnd(natlib);

    /* end objects */
    vis_ModelEnd(model);
    vis_ConnectEnd(connect);
    vis_StateEnd(staten);
    vis_StateEnd(statee);
    vis_StateEnd(stateg);
    vis_RPropEnd(rpropn);
    vis_RPropEnd(rprope);
    vis_RPropEnd(rpropg);
    vis_GridFunEnd(gf);

    vdm_DataFunEnd(datafun);
    vdm_LManEnd(lman);
    return 0;
}
