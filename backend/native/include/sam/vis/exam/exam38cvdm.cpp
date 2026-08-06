#include <stdio.h>
#include "sam/base/base.h"
#include "sam/base/vututil.h"
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

static const Vint elementCount = 4;
static const Vint nodeCount = 15;

static Vint conn[elementCount][8] = {
{1, 2, 7, 6, 10, 11, 14, 13}, {2, 3, 8, 7, 11, 12, 15, 14}, {3, 4, 9, 8, 0, 0, 0, 0}, {4, 5, 9, 0, 0, 0, 0, 0}};

static Vint shap[elementCount] = {VIS_SHAPEHEX, VIS_SHAPEHEX, VIS_SHAPEQUAD, VIS_SHAPETRI};

static Vint etyp[elementCount] = {VIS_ELEM_SOLID, VIS_ELEM_SOLID, VIS_ELEM_SHELL, VIS_ELEM_SHELL};

static Vfloat coords[nodeCount][3] = {{0., 0., 0.}, {1., 0., 0.}, {2., 0., 1.}, {3., 0., 1.}, {4., 0., 1.},
                                      {0., 1., 0.}, {1., 1., 0.}, {2., 1., 1.}, {3., 1., 1.}, {0., 0., 2.},
                                      {1., 0., 2.}, {2., 0., 2.}, {0., 1., 2.}, {1., 1., 2.}, {2., 1., 2.}};

namespace exam38Writer1 {
    // typedef struct exm38cvdm_Writer exm38cvdm_Writer;

    struct customWriter1 {
        /* this vis_WriterFun must at the beginning and must not be a pointer */
        vis_WriterFun writerInterface;

        vdm_DataFun* datafun;
        vdm_LMan* lman;
        vdm_NASLib* naslib;
    };

    static void
    openNASLibfile(customWriter1* p)
    {
        /* open op2 file for output model and results */
        p->datafun = vdm_DataFunBegin();
        p->lman = vdm_LManBegin();
        p->naslib = vdm_NASLibBegin();
        vdm_NASLibDataFun(p->naslib, p->datafun);
        vdm_DataFunSetStatus(p->datafun, VDM_STATUS_NEW);
        vdm_DataFunOpen(p->datafun, 0, (Vchar*)"exam38cvdm.op2", VDM_NASTRAN_OUTPUT2);
        vdm_LManSetObject(p->lman, VDM_DATAFUN, p->datafun);
    }

    static void
    writeModel(customWriter1* p, vis_Model* model)
    {
        /* Using lman to save the model */
        /* Could be replaced by any custom writer */
        vdm_LManSaveModel(p->lman, model);
    }

    static void
    writeState(customWriter1* p, vis_State* state, vis_RProp* rprop)
    {
        /* Using lman to save the state */
        /* Could be replaced by any custom writer */
        vdm_LManSaveState(p->lman, state, rprop);
    }

    static customWriter1*
    writerBegin()
    {
        customWriter1* p = (customWriter1*)vut_mallocMem(sizeof(customWriter1));
        openNASLibfile(p);

        /* Set the needed write functions */
        vis_WriterFunSetWriteModelFunction(&p->writerInterface, (VFuncWriterWriteModel*)writeModel);
        vis_WriterFunSetWriteStateFunction(&p->writerInterface, (VFuncWriterWriteState*)writeState);

        return p;
    }

    static void
    writerClose(customWriter1* p)
    {
        /* Close the op2 file for output model and results */
        if (p->datafun) {
            vdm_DataFunClose(p->datafun);
        }
        if (p->datafun) {
            vdm_DataFunEnd(p->datafun);
            p->datafun = NULL;
        }
        if (p->naslib) {
            vdm_NASLibEnd(p->naslib);
            p->naslib = NULL;
        }
        if (p->lman) {
            vdm_LManEnd(p->lman);
            p->lman = NULL;
        }
        if (p) {
            vut_freeMem(p);
        }
    }

} // namespace exam38Writer1

namespace exam38Writer2 {

    static void
    writeModel(vis_WriterFun* /*p*/, vis_Model* model)
    {
        /* Use this function to only print the model information */
        vis_ModelPrint(model);
    }

    static void
    writeState(vis_WriterFun* /*p*/, vis_State* state, vis_RProp* rprop)
    {
        /* Use this function to only print the state and rprop information */
        vis_StatePrint(state);
        vis_RPropPrint(rprop);
    }

    static vis_WriterFun*
    writerBegin()
    {
        vis_WriterFun* p = vis_WriterFunBegin();

        /* Set the needed write functions */
        vis_WriterFunSetWriteModelFunction(p, (VFuncWriterWriteModel*)writeModel);
        vis_WriterFunSetWriteStateFunction(p, (VFuncWriterWriteState*)writeState);

        return p;
    }
} // namespace exam38Writer2

/*----------------------------------------------------------------------
                  Export Simple Finite Element Model and Results
----------------------------------------------------------------------*/
int
main()
{
    Vint i = 0, j = 0, k = 0;
    vis_Connect* connect = nullptr;
    vis_Model* model = nullptr;
    vis_State *staten = nullptr, *stateen = nullptr;
    vis_RProp *rpropn = nullptr, *rpropen = nullptr;
    vis_GridFun* gf = nullptr;
    Vint nix = 0, ix[8] = {0}, nsec = 0;
    Vfloat enstress[8][6] = {{0}};

    vsy_LicenseValidate(HOOPS_LICENSE);

    exam38Writer1::customWriter1* writer1 = exam38Writer1::writerBegin();
    vis_WriterFun* writer2 = exam38Writer2::writerBegin();

    /* create connect object */
    connect = vis_ConnectBegin();
    vis_ConnectDef(connect, nodeCount, elementCount);

    /* set topology and connectivity */
    for (i = 0; i < elementCount; i++) {
        vis_ConnectSetTopology(connect, i + 1, shap[i], 2, 0, 0);
        vis_ConnectSetElemNode(connect, i + 1, conn[i]);
        vis_ConnectSetElemAssoc(connect, VIS_FEATYPE, i + 1, etyp[i]);
    }
    /* set node coordinates */
    for (i = 0; i < nodeCount; i++) {
        vis_ConnectSetCoords(connect, i + 1, coords[i]);
    }

    /* create model object and install connect object */
    model = vis_ModelBegin();
    vis_ModelSetObject(model, VIS_CONNECT, connect);

    /* write model data */
    vis_WriterFunWriteModel((vis_WriterFun*)writer1, model);
    vis_WriterFunWriteModel(writer2, model);

    /* create a grid function object */
    gf = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gf);

    /* create a node vector state */
    staten = vis_StateBegin();
    vis_StateDef(staten, nodeCount, SYS_NODE, SYS_NONE, VIS_VECTOR);
    vis_StateSetObject(staten, VIS_GRIDFUN, gf);

    /* use node coordinates as "displacements" for convenience */
    for (i = 0; i < nodeCount; i++) {
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
    vis_WriterFunWriteState((vis_WriterFun*)writer1, staten, rpropn);
    vis_WriterFunWriteState(writer2, staten, rpropn);

    /* create an element node state */
    stateen = vis_StateBegin();
    vis_StateDef(stateen, elementCount, SYS_ELEM, SYS_NODE, VIS_TENSOR);
    vis_StateSetObject(stateen, VIS_GRIDFUN, gf);

    /* set number of sections for solids and shells */
    for (i = 0; i < elementCount; i++) {
        if (etyp[i] == VIS_ELEM_SOLID) {
            nsec = 1;
        }
        else if (etyp[i] == VIS_ELEM_SHELL) {
            nsec = 2;
        }
        vis_StateSetDataSect(stateen, i + 1, nsec);
    }
    /* use node coordinates as "stress" for convenience */
    for (i = 0; i < elementCount; i++) {
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
    vis_WriterFunWriteState((vis_WriterFun*)writer1, stateen, rpropen);
    vis_WriterFunWriteState(writer2, stateen, rpropen);

    /* end objects */
    vis_ModelEnd(model);
    vis_ConnectEnd(connect);
    vis_StateEnd(staten);
    vis_RPropEnd(rpropn);
    vis_StateEnd(stateen);
    vis_RPropEnd(rpropen);
    vis_GridFunEnd(gf);
    exam38Writer1::writerClose(writer1);
    vis_WriterFunEnd(writer2);

    return 0;
}
