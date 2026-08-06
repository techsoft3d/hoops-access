#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/vis/visdata.h"
#include "sam/vdm/vdm.h"
#include "sam/vdm/datafile.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static void
print_stress(vdm_LMan* lman, vdm_Library* library, vis_Model* model);

/*----------------------------------------------------------------------
                     Read and Transform Stress/Strain State Data
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    char inputfile[256];
    vdm_DataFun* datafun;
    vdm_Library* library;
    vdm_LMan* lman;
    Vint filetype;
    Vint numnp, numel;
    vis_Model* model;
    vis_Connect* connect;
    Vint ierr;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* check input arguments */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s inputfile [appendfile]\n", argv[0]);
        fprintf(stderr, " inputfile is blank, 'cantilever.unv' is assumed\n");
        strcpy(inputfile, "cantilever.unv");
    }
    else {
        strcpy(inputfile, argv[1]);
    }
    /* create data function object */
    datafun = vdm_DataFunBegin();

    datafiletype(inputfile, &filetype);
    if (filetype == 0) {
        fprintf(stderr, "Error: Bad input file %s\n", inputfile);
        exit(1);
    }
    datafileinit(filetype, datafun);
    /* set convention to support sparse datasets */
    vdm_DataFunSetConvention(datafun, VDM_CONVENTION_SPARSE);
    /* open library device */
    vdm_DataFunOpen(datafun, 0, inputfile, filetype);
    /* check for error */
    ierr = vdm_DataFunError(datafun);
    if (ierr) {
        fprintf(stderr, "Error: opening file %s\n", inputfile);
        exit(0);
    }
    /* instance Model object for finite element model */
    model = vis_ModelBegin();

    /* use Library Manager object to load model */
    lman = vdm_LManBegin();
    vdm_LManSetObject(lman, VDM_DATAFUN, datafun);
    vdm_LManLoadModel(lman, model);

    /* get Connect object created in Model */
    vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("number of nodes= %d\n", numnp);
    printf("number of elems= %d\n", numel);

    /* get library object */
    vdm_DataFunGetLibrary(datafun, &library);

    /* access and transform stress results */
    print_stress(lman, library, model);

    /* close library device */
    vdm_DataFunClose(datafun);

    /* delete objects in Model created by LManLoadModel */
    vis_ModelDelete(model);

    datafileterm(filetype, datafun);
    /* free objects */
    vdm_DataFunEnd(datafun);

    vdm_LManEnd(lman);
    vis_ModelEnd(model);
    return 0;
}

/*----------------------------------------------------------------------
                      load coordinate system indices
----------------------------------------------------------------------*/
static void
load_idtrancid(vdm_LMan* lman, vdm_Library* library, vis_RProp* rprop, vis_IdTran* idtrancid)
{
    Vint m;
    Vchar cidname[DATASET_MAXNAME];
    Vint ids, nds;
    vdm_Dataset* dataset;
    vdm_DataFun* datafun;
    Vint ncol;
    Vint* pcid;
    /* get name of coordinate system id dataset */
    vis_RPropValueString(rprop, RPROP_LINK_CID, cidname);
    /* find dataset */
    vdm_LibrarySearchDataset(library, cidname, 1, &ids, &nds);
    vdm_LibraryGetDataset(library, ids, &dataset);
    vdm_DatasetGetNCol(dataset, &ncol);
    vdm_LManGetObject(lman, VDM_DATAFUN, (Vobject**)&datafun);
    pcid = (Vint*)malloc(ncol * sizeof(Vint));
    vdm_DataFunReadDataset(datafun, ids, pcid);
    for (m = 1; m <= ncol; m++) {
        vis_IdTranSetId(idtrancid, m, pcid[m - 1]);
    }
    free(pcid);
}

/*----------------------------------------------------------------------
                      load rotation angle vector
----------------------------------------------------------------------*/
static void
load_staterotang(vdm_LMan* lman, vdm_Library* library, vis_RProp* rprop, vis_State* staterotang)
{
    Vchar raname[DATASET_MAXNAME];
    Vint ids, nds;
    vdm_Dataset* dataset;
    vis_RProp* rproprotang;
    Vint enttype, subtype;
    /* get name of rotation angle dataset */
    vis_RPropValueString(rprop, RPROP_LINK_ROTANG, raname);
    /* find dataset */
    vdm_LibrarySearchDataset(library, raname, 1, &ids, &nds);
    vdm_LibraryGetDataset(library, ids, &dataset);
    vdm_DatasetEntType(dataset, &enttype, &subtype);
    /* read rotation angles */
    rproprotang = vis_RPropBegin();
    vis_RPropDef(rproprotang, enttype, subtype);
    vis_RPropSetDatasetIndex(rproprotang, ids);
    vdm_LManLoadState(lman, staterotang, rproprotang);
    vis_RPropEnd(rproprotang);
}

/*----------------------------------------------------------------------
                      print stresses
----------------------------------------------------------------------*/
static void
print_stress(vdm_LMan* lman, vdm_Library* library, vis_Model* model)
{
    vdm_Dataset* dataset;
    Vchar dsname[DATASET_MAXNAME];
    Vlong lrec;
    Vint nrow, ncol, ntyp;
    Vint numdatasets;
    Vint nds, ndst_s;
    Vint* idst_s = NULL;
    Vint numids, ids[3];
    Vint nix;
    Vint numel, maxelno, elemnumber;
    Vint i, j, n;
    vis_Connect* connect = NULL;
    vsy_HashTable *hashcsys = NULL, *hasheldt = NULL;
    vis_IdTran* idtranesys = NULL;
    vis_GridFun* gridfun = NULL;
    vis_State* state = NULL;
    vis_State* staterotang = NULL;
    vis_RProp* rprop = NULL;
    Vfloat(*sten)[6];
    Vint system;
    Vint enttype, subtype;
    Vint cmatflag, cmatid, matflag;

    /* determine maximum number of datasets */
    vdm_LibraryGetNumDatasets(library, &numdatasets);

    /* allocate array for dataset indices */
    idst_s = (Vint*)malloc(numdatasets * sizeof(Vint));

    /* search for stress results datasets */
    vdm_LibrarySearchDataset(library, "S.*EL:*", numdatasets, idst_s, &nds);
    vdm_LibrarySearchDataset(library, "S.*E:*", numdatasets, &idst_s[nds], &ndst_s);
    ndst_s += nds;
    if (ndst_s == 0) {
        free(idst_s);
        return;
    }
    /* get Connect object created in Model */
    vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);

    /* find maximum number of element nodes */
    vis_ConnectMaxElemNode(connect, &maxelno);

    /* allocate arrays to fit maximum element node data */
    sten = (Vfloat(*)[6])malloc(maxelno * 6 * sizeof(Vfloat));

    /* create a grid function object */
    gridfun = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gridfun);

    /* get HashTable of CoordSys objects */
    vis_ModelGetHashTable(model, VIS_COORDSYS, &hashcsys);
    /* get HashTable of ElemDat objects */
    vis_ModelGetHashTable(model, VIS_ELEMDAT, &hasheldt);

    /* install coordinate system ids into IdTran object */
    idtranesys = vis_IdTranBegin();
    vis_IdTranDef(idtranesys, numel);

    /* create state and install GridFun object */
    state = vis_StateBegin();
    vis_StateSetObject(state, VIS_GRIDFUN, gridfun);

    /* instance result property object */
    rprop = vis_RPropBegin();

    /* print first, middle and last element */
    /* customize these ids if necessary */
    numids = 3;
    ids[0] = 1;
    ids[1] = numel / 2;
    ids[2] = numel;

    /* loop over stress datasets */
    for (i = 0; i < ndst_s; i++) {
        vdm_LibraryGetDataset(library, idst_s[i], &dataset);
        vdm_DatasetInq(dataset, dsname, &lrec, &nrow, &ncol, &ntyp);
        if (nrow != 6)
            continue;
        vdm_DatasetEntType(dataset, &enttype, &subtype);

        /* print header */
        printf("\n\nDataset: %s\n", dsname);
        printf("\nStresses\n");

        /* set entity type and dataset index */
        vis_RPropDef(rprop, enttype, subtype);
        vis_RPropSetDatasetIndex(rprop, idst_s[i]);
        /* load state */
        vdm_LManLoadState(lman, state, rprop);
        /* get the system set in State by LManLoadState */
        vis_StateGetSystem(state, &system);
        if (system == STATE_LOCAL) {
            printf("local system\n");
        }
        else if (system == STATE_ROTANG) {
            printf("RotAng system\n");
        }
        else if (system == STATE_GLOBAL) {
            printf("global system\n");
        }
        /* print stress components first */
        vis_StateSetDerive(state, VIS_TENSOR);

        /* loop over requested elements */
        for (n = 0; n < numids; n++) {
            if (ids[n] == 0)
                continue;
            vis_ConnectElemAssoc(connect, VIS_USERID, 1, &ids[n], &elemnumber);
            printf("%8d, component stresses\n", elemnumber);

            nix = 1;
            /* if element node get number of nodes */
            if (subtype == SYS_NODE) {
                vis_ConnectElemNum(connect, SYS_NODE, ids[n], &nix);
            }
            vis_StateData(state, 1, &ids[n], (Vfloat*)sten);

            /* loop over nodes in element */
            for (j = 0; j < nix; j++) {
                printf(" %12.5e %12.5e %12.5e %12.5e %12.5e %12.5e\n", sten[j][0], sten[j][1], sten[j][2], sten[j][3], sten[j][4],
                       sten[j][5]);
            }
        }
        /* print stress in global if originally in local */
        if (system == STATE_LOCAL || system == STATE_ROTANG) {
            vis_StateSetObject(state, VIS_GRIDFUN, gridfun);
            vis_StateSetHashTable(state, VIS_COORDSYS, hashcsys);
            vis_StateSetHashTable(state, VIS_ELEMDAT, hasheldt);
            if (system == STATE_LOCAL) {
                load_idtrancid(lman, library, rprop, idtranesys);
                vis_StateSetObject(state, VIS_IDTRAN, idtranesys);
            }
            else if (system == STATE_ROTANG) {
                staterotang = vis_StateBegin();
                vis_StateSetObject(staterotang, VIS_GRIDFUN, gridfun);
                load_staterotang(lman, library, rprop, staterotang);
                vis_StateSetObject(state, VIS_STATE_ROTANG, staterotang);
            }
            vis_StateTransform(state, STATE_GLOBAL, NULL);
            printf("global system\n");
            matflag = 0;

            /* loop over requested elements */
            for (n = 0; n < numids; n++) {
                if (ids[n] == 0)
                    continue;
                vis_ConnectElemAssoc(connect, VIS_USERID, 1, &ids[n], &elemnumber);
                printf("%8d, component stresses\n", elemnumber);
                /* check for material system */
                vis_ConnectElemAssoc(connect, VIS_CMATFLAG, 1, &ids[n], &cmatflag);
                if (cmatflag) {
                    vis_ConnectElemAssoc(connect, VIS_CMATID, 1, &ids[n], &cmatid);
                    if (cmatid)
                        matflag = 1;
                }

                nix = 1;
                /* if element node get number of nodes */
                if (subtype == SYS_NODE) {
                    vis_ConnectElemNum(connect, SYS_NODE, ids[n], &nix);
                }
                vis_StateData(state, 1, &ids[n], (Vfloat*)sten);

                /* loop over nodes in element */
                for (j = 0; j < nix; j++) {
                    printf(" %12.5e %12.5e %12.5e %12.5e %12.5e %12.5e\n", sten[j][0], sten[j][1], sten[j][2], sten[j][3],
                           sten[j][4], sten[j][5]);
                }
            }
            if (matflag == 0)
                continue;
            /* now transform to material */
            vis_StateTransform(state, STATE_MATERIAL, NULL);
            printf("material system\n");
            for (n = 0; n < numids; n++) {
                if (ids[n] == 0)
                    continue;
                vis_ConnectElemAssoc(connect, VIS_USERID, 1, &ids[n], &elemnumber);
                printf("%8d, component stresses\n", elemnumber);
                nix = 1;
                if (subtype == SYS_NODE) {
                    vis_ConnectElemNum(connect, SYS_NODE, ids[n], &nix);
                }
                vis_StateData(state, 1, &ids[n], (Vfloat*)sten);
                for (j = 0; j < nix; j++) {
                    printf(" %12.5e %12.5e %12.5e %12.5e %12.5e %12.5e\n", sten[j][0], sten[j][1], sten[j][2], sten[j][3],
                           sten[j][4], sten[j][5]);
                }
            }
        }
        printf("\n");
        if (system == STATE_ROTANG) {
            vis_StateEnd(staterotang);
        }
    }
    /* free memory */
    vis_GridFunEnd(gridfun);
    vis_IdTranEnd(idtranesys);
    vis_StateEnd(state);
    vis_RPropEnd(rprop);
    free(idst_s);
    free(sten);
}
