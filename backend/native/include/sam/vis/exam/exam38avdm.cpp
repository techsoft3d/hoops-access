#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/visdata.h"
#include "sam/vdm/vdm.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"
/*
                 6------7
                /.     /.\
  y            / .    / . \
  |           /  .   /  .  \8------9
  --x        /   1../...2../|      | \
 /         13-----14-----15 |      |  \
z           |  .   |  .   |.|      |   \
            | .    | .    | 3------4-----5
            |.     |.     |/
           10-----11-----12
*/
#define MAX_ELEM 4
#define MAX_NODE 15

static Vint conn[MAX_ELEM][8] = {
{1, 2, 7, 6, 10, 11, 14, 13}, {2, 3, 8, 7, 11, 12, 15, 14}, {3, 4, 9, 8, 0, 0, 0, 0}, {4, 5, 9, 0, 0, 0, 0, 0}};

static Vint shap[MAX_ELEM] = {VIS_SHAPEHEX, VIS_SHAPEHEX, VIS_SHAPEQUAD, VIS_SHAPETRI};

static Vint etyp[MAX_ELEM] = {VIS_ELEM_SOLID, VIS_ELEM_SOLID, VIS_ELEM_SHELL, VIS_ELEM_SHELL};

static Vfloat coords[MAX_NODE][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 1.}, {3., 0., 1.}, {4., 0., 1.},
                                     {0., 1., 0.}, {1., 1., 0.}, {2., 1., 1.}, {3., 1., 1.}, {0., 0., 2.},
                                     {1., 0., 2.}, {2., 0., 2.}, {0., 1., 2.}, {1., 1., 2.}, {2., 1., 2.}};

/*----------------------------------------------------------------------
                      Export Simple Finite Element Model and Results
----------------------------------------------------------------------*/
int
main()
{
    Vint i, j, k;
    vis_Connect* connect;
    vis_Model* model;
    vis_State *staten, *stateen;
    vis_RProp *rpropn, *rpropen;
    vis_GridFun* gf;
    Vint nix, ix[8], nsec = 0;
    Vfloat enstress[8][6];

    vdm_LMan* lman;
    vdm_DataFun* datafun;
    vdm_NASLib* naslib;
    vdm_SDRCLib* sdrclib;
    vdm_CGNSVLib* cgnsvlib;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create connect object */
    connect = vis_ConnectBegin();
    vis_ConnectDef(connect, MAX_NODE, MAX_ELEM);

    /* set topology and connectivity */
    for (i = 0; i < MAX_ELEM; i++) {
        vis_ConnectSetTopology(connect, i + 1, shap[i], 2, 0, 0);
        vis_ConnectSetElemNode(connect, i + 1, conn[i]);
        vis_ConnectSetElemAssoc(connect, VIS_FEATYPE, i + 1, etyp[i]);
    }
    /* set node coordinates */
    for (i = 0; i < MAX_NODE; i++) {
        vis_ConnectSetCoords(connect, i + 1, coords[i]);
    }

    /* create model object and install connect object */
    model = vis_ModelBegin();
    vis_ModelSetObject(model, VIS_CONNECT, connect);

    /* write model data */
    vis_ModelWrite(model, SYS_SDRC_UNIVERSAL, (Vchar*)"exam38avdm.unv1");

    /* create a grid function object */
    gf = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gf);

    /* create a node vector state */
    staten = vis_StateBegin();
    vis_StateDef(staten, MAX_NODE, SYS_NODE, SYS_NONE, VIS_VECTOR);
    vis_StateSetObject(staten, VIS_GRIDFUN, gf);

    /* use node coordinates as "displacements" for convenience */
    for (i = 0; i < MAX_NODE; i++) {
        vis_StateSetData(staten, i + 1, coords[i]);
    }
    /* create result property for node state */
    rpropn = vis_RPropBegin();
    vis_RPropDef(rpropn, SYS_NODE, SYS_NONE);
    /* set displacement quantity */
    vis_RPropSetType(rpropn, SYS_RES_D);
    /* set ids, eg. step 1, increment 1 */
    vis_RPropSetIds(rpropn, 1, 1, 0);
    vis_RPropSetValued(rpropn, RPROP_TIME, 1.);
    vis_RPropSetValuec(rpropn, RPROP_TITLE, (Vchar*)"Displacements under load case 1");

    /* write node state data */
    /* SDRC, previous file can be appended to */
    vis_StateWrite(staten, rpropn, SYS_SDRC_UNIVERSAL, "exam38avdm.unv1");

    /* create an element node state */
    stateen = vis_StateBegin();
    vis_StateDef(stateen, MAX_ELEM, SYS_ELEM, SYS_NODE, VIS_TENSOR);
    vis_StateSetObject(stateen, VIS_GRIDFUN, gf);

    /* set number of sections for solids and shells */
    for (i = 0; i < MAX_ELEM; i++) {
        if (etyp[i] == VIS_ELEM_SOLID) {
            nsec = 1;
        }
        else if (etyp[i] == VIS_ELEM_SHELL) {
            nsec = 2;
        }
        vis_StateSetDataSect(stateen, i + 1, nsec);
    }
    /* use node coordinates as "stress" for convenience */
    for (i = 0; i < MAX_ELEM; i++) {
        vis_ConnectElemNode(connect, i + 1, &nix, ix);
        /* gather */
        if (etyp[i] == VIS_ELEM_SOLID) {
            for (j = 0; j < nix; j++) {
                enstress[j][0] = coords[ix[j] - 1][0];
                enstress[j][1] = coords[ix[j] - 1][1];
                enstress[j][2] = coords[ix[j] - 1][2];
                enstress[j][3] = 0.;
                enstress[j][4] = 0.;
                enstress[j][5] = 0.;
            }
            /* double coordinates for second section for shells */
        }
        else if (etyp[i] == VIS_ELEM_SHELL) {
            for (k = 0; k < 2; k++) {
                for (j = 0; j < nix; j++) {
                    enstress[k * nix + j][0] = (k + 1) * coords[ix[j] - 1][0];
                    enstress[k * nix + j][1] = (k + 1) * coords[ix[j] - 1][1];
                    enstress[k * nix + j][2] = 0.;
                    enstress[k * nix + j][3] = (k + 1) * coords[ix[j] - 1][2];
                    enstress[k * nix + j][4] = 0.;
                    enstress[k * nix + j][5] = 0.;
                }
            }
        }
        vis_StateSetData(stateen, i + 1, (Vfloat*)enstress);
    }
    /* create result property for element node state */
    rpropen = vis_RPropBegin();
    vis_RPropDef(rpropen, SYS_ELEM, SYS_NODE);
    /* set stress quantity */
    vis_RPropSetType(rpropen, SYS_RES_S);
    /* set ids, eg. step 1, increment 1 */
    vis_RPropSetIds(rpropen, 1, 1, 0);
    vis_RPropSetValued(rpropen, RPROP_TIME, 1.);
    /* set name of section dataset */
    vis_RPropSetValuec(rpropen, RPROP_LINK_SECTION, (Vchar*)"ELEM.SECT.E:1");
    vis_RPropSetValuec(rpropen, RPROP_TITLE, (Vchar*)"Stress under load case 1");

    /* write element node state data */
    /* SDRC, previous file can be appended to */
    vis_StateWrite(stateen, rpropen, SYS_SDRC_UNIVERSAL, "exam38avdm.unv1");

    /* now export to VdmTools supported results files */
    datafun = vdm_DataFunBegin();
    lman = vdm_LManBegin();
    vdm_LManSetObject(lman, VDM_DATAFUN, datafun);

    /* write to NASTRAN .op2 */
    naslib = vdm_NASLibBegin();
    vdm_NASLibDataFun(naslib, datafun);
    vdm_DataFunSetStatus(datafun, VDM_STATUS_NEW);
    vdm_DataFunOpen(datafun, 0, (Vchar*)"exam38avdm.op2", SYS_NASTRAN_OUTPUT2);
    vdm_LManSaveModel(lman, model);
    vdm_LManSaveState(lman, staten, rpropn);
    vdm_LManSaveState(lman, stateen, rpropen);
    vdm_DataFunClose(datafun);
    vdm_NASLibEnd(naslib);

    /* write to SDRC .unv */
    sdrclib = vdm_SDRCLibBegin();
    vdm_SDRCLibDataFun(sdrclib, datafun);
    vdm_DataFunSetStatus(datafun, VDM_STATUS_NEW);
    vdm_DataFunOpen(datafun, 0, (Vchar*)"exam38avdm.unv", SYS_SDRC_UNIVERSAL);
    vdm_LManSaveModel(lman, model);
    vdm_LManSaveState(lman, staten, rpropn);
    vdm_LManSaveState(lman, stateen, rpropen);
    vdm_DataFunClose(datafun);
    vdm_SDRCLibEnd(sdrclib);

    /* write to CGNS .cgns */
    cgnsvlib = vdm_CGNSVLibBegin();
    vdm_CGNSVLibDataFun(cgnsvlib, datafun);
    vdm_DataFunSetStatus(datafun, VDM_STATUS_NEW);
    vdm_DataFunOpen(datafun, 0, (Vchar*)"exam38avdm.cgns", SYS_CGNS);
    if (vdm_DataFunError(datafun) == 0) {
        vdm_LManSaveModel(lman, model);
        vdm_LManSaveState(lman, staten, rpropn);
        vdm_LManSaveState(lman, stateen, rpropen);
        vdm_DataFunClose(datafun);
    }
    vdm_CGNSVLibEnd(cgnsvlib);

    /* end objects */
    vis_ModelEnd(model);
    vis_ConnectEnd(connect);
    vis_StateEnd(staten);
    vis_RPropEnd(rpropn);
    vis_StateEnd(stateen);
    vis_RPropEnd(rpropen);
    vis_GridFunEnd(gf);

    vdm_DataFunEnd(datafun);
    vdm_LManEnd(lman);
    return 0;
}
