#include "sam/base/system.h"
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/vdm/vdm.h"
#include "sam/vdm/datafile.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                   Compress and Uncompress Results with ZState
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    vis_ZState* zstate;
    vis_Connect* connect;
    vis_GridFun* gridfun;
    vis_Model* model;
    vis_State* state;
    vis_RProp* rprop;
    vdm_DataFun* datafun;
    vdm_LMan* lman;
    vdm_Library* library;
    vdm_Dataset* dataset;
    vis_IdTran* idtran;
    Vuchar *bkernel, *bstate;
    Vint filetype, ierr, numdatasets, numnp, numel, idst, i, j;
    Vint nodeinc, eleminc, pid;
    Vchar root[256], cqua[256], caux[256], dsname[DATASET_MAXNAME];
    Vint type, hist, nqua, iqua[SYS_NQUA_MAX], sect, enttype, subtype, cplx;
    Vint id1, id2, id3;
    Vlong lrec;
    Vint nrow, ncol, dtype;
    Vulong nbytes, newbytes;
    Vfloat value[100];
    Vfloat ratio;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s results_file\n", argv[0]);
        return 1;
    }
    /* open results file */
    datafiletype(argv[1], &filetype);
    if (filetype == 0) {
        fprintf(stderr, "Error: Bad input file %s\n", argv[1]);
        return 1;
    }

    vsy_LicenseValidate(HOOPS_LICENSE);

    datafun = vdm_DataFunBegin();
    datafileinit(filetype, datafun);
    vdm_DataFunOpen(datafun, 0, argv[1], filetype);
    ierr = vdm_DataFunError(datafun);
    if (ierr) {
        fprintf(stderr, "Error: opening file %s\n", argv[1]);
        return 1;
    }
    printf("Processing file= %s\n", argv[1]);
    vdm_DataFunNumDatasets(datafun, &numdatasets);
    vdm_DataFunGetLibrary(datafun, &library);

    /* extract model/connect */
    lman = vdm_LManBegin();
    vdm_LManSetObject(lman, VDM_DATAFUN, (Vobject*)datafun);
    model = vis_ModelBegin();
    vdm_LManLoadModel(lman, model);
    vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("   numnp= %d\n", numnp);
    printf("   numel= %d\n", numel);
    nodeinc = numnp / 10;
    if (nodeinc == 0) {
        nodeinc = 1;
    }
    eleminc = numel / 10;
    if (eleminc == 0) {
        eleminc = 1;
    }

    /* create GridFun */
    gridfun = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gridfun);

    /* create State and RProp */
    rprop = vis_RPropBegin();
    state = vis_StateBegin();
    vis_StateSetObject(state, VIS_GRIDFUN, (Vobject*)gridfun);

    /* create ZState and Def it for nodal data */
    zstate = vis_ZStateBegin();
    vis_ZStateSetObject(zstate, VIS_GRIDFUN, (Vobject*)gridfun);

    /* Setup for nodal results */
    vis_ZStateDef(zstate, numnp, SYS_NODE, SYS_NONE);

    /* create ZState kernel and save it */
    vis_ZStateKernel(zstate, NULL);
    vis_ZStateLngKernel(zstate, &nbytes);
    printf("   Nodal kernel size= %lld bytes\n", nbytes);
    bkernel = (Vuchar*)malloc(nbytes * sizeof(Vuchar));
    vis_ZStateSaveKernel(zstate, bkernel, &newbytes);
    vis_ZStateEnd(zstate);

    /* load ZState kernel */
    zstate = vis_ZStateBegin();
    vis_ZStateSetObject(zstate, VIS_GRIDFUN, (Vobject*)gridfun);
    vis_ZStateLoadKernel(zstate, bkernel);
    free(bkernel);

    /* loop over all nodal states */
    vis_RPropDef(rprop, SYS_NODE, SYS_NONE);
    for (idst = 0; idst < numdatasets; idst++) {
        vdm_LibraryGetDataset(library, idst, &dataset);
        vdm_DatasetResult(dataset, root, &type, &hist, &nqua, iqua, cqua, &cplx, caux, &sect, &enttype, &subtype, &id1, &id2,
                          &id3);

        /* skip non-result datasets */
        if (type == SYS_RES_NONE)
            continue;

        /* skip non-nodal results */
        if (enttype != SYS_NODE || subtype != SYS_NONE)
            continue;

        /* load this nodal state */
        vdm_DatasetInq(dataset, dsname, &lrec, &nrow, &ncol, &dtype);
        printf("   Dataset= %s\n", dsname);
        vis_RPropSetDatasetName(rprop, dsname);
        vdm_LManLoadState(lman, state, rprop);
        printf("      Original values:\n");
        for (i = 1; i <= numnp; i += nodeinc) {
            vis_StateData(state, 1, &i, value);
            printf("      %10d", i);
            for (j = 0; j < nrow; ++j) {
                printf(" %11.4e", value[j]);
            }
            printf("\n");
        }

        /* compress and save coordinate state */
        vis_ZStateState(zstate, state);
        vis_ZStateLngState(zstate, &nbytes);
        printf("      Original   state size= %lld bytes\n", lrec * sizeof(Vfloat));
        printf("      Compressed state size= %lld bytes\n", nbytes);
        ratio = (Vfloat)((lrec * sizeof(Vfloat)) / (Vfloat)nbytes);
        printf("      Compression ratio= %f\n", ratio);
        bstate = (Vuchar*)malloc(nbytes * sizeof(Vuchar));
        vis_ZStateSaveState(zstate, state, bstate, &newbytes);

        /* clean-up ZState and State */
        vis_StateEnd(state);

        /* instance new ZState and State to reload */
        state = vis_StateBegin();
        vis_StateSetObject(state, VIS_GRIDFUN, (Vobject*)gridfun);
        vis_ZStateLoadState(zstate, bstate, state);
        free(bstate);

        /* compare compressed and uncompressed values */
        printf("      Compressed values:\n");
        for (i = 1; i <= numnp; i += nodeinc) {
            vis_StateData(state, 1, &i, value);
            printf("      %10d", i);
            for (j = 0; j < nrow; ++j) {
                printf(" %11.4e", value[j]);
            }
            printf("\n");
        }
    }
    /* Setup for element results */
    vis_ZStateDef(zstate, numel, SYS_ELEM, SYS_NONE);

    /* Create idtran and assign propid */
    idtran = vis_IdTranBegin();
    vis_IdTranDef(idtran, numel);
    for (i = 1; i <= numel; ++i) {
        vis_ConnectElemAssoc(connect, VIS_PROPID, 1, &i, &pid);
        vis_IdTranSetId(idtran, i, pid + 1);
    }
    /* create ZState kernel and save it */
    vis_ZStateKernel(zstate, idtran);
    vis_IdTranEnd(idtran);

    vis_ZStateLngKernel(zstate, &nbytes);
    printf("   Element kernel size= %lld bytes\n", nbytes);
    bkernel = (Vuchar*)malloc(nbytes * sizeof(Vuchar));
    vis_ZStateSaveKernel(zstate, bkernel, &newbytes);
    vis_ZStateEnd(zstate);

    /* load ZState kernel */
    zstate = vis_ZStateBegin();
    vis_ZStateSetObject(zstate, VIS_GRIDFUN, (Vobject*)gridfun);
    vis_ZStateLoadKernel(zstate, bkernel);
    free(bkernel);

    /* loop over all element states */
    vis_RPropDef(rprop, SYS_ELEM, SYS_NONE);
    for (idst = 0; idst < numdatasets; idst++) {
        vdm_LibraryGetDataset(library, idst, &dataset);
        vdm_DatasetResult(dataset, root, &type, &hist, &nqua, iqua, cqua, &cplx, caux, &sect, &enttype, &subtype, &id1, &id2,
                          &id3);

        /* skip non-result datasets */
        if (type == SYS_RES_NONE)
            continue;

        /* skip non-element results */
        if (enttype != SYS_ELEM || subtype != SYS_NONE)
            continue;

        /* load this nodal state */
        vdm_DatasetInq(dataset, dsname, &lrec, &nrow, &ncol, &dtype);
        printf("   Dataset= %s\n", dsname);
        vis_RPropSetDatasetName(rprop, dsname);
        vdm_LManLoadState(lman, state, rprop);
        printf("      Original values:\n");
        for (i = 1; i <= numel; i += eleminc) {
            vis_StateData(state, 1, &i, value);
            printf("      %10d", i);
            for (j = 0; j < nrow; ++j) {
                printf(" %11.4e", value[j]);
            }
            printf("\n");
        }

        /* compress and save coordinate state */
        vis_ZStateState(zstate, state);
        vis_ZStateLngState(zstate, &nbytes);
        printf("      Original   state size= %lld bytes\n", lrec * sizeof(Vfloat));
        printf("      Compressed state size= %lld bytes\n", nbytes);
        ratio = (Vfloat)((lrec * sizeof(Vfloat)) / (Vfloat)nbytes);
        printf("      Compression ratio= %f\n", ratio);
        bstate = (Vuchar*)malloc(nbytes * sizeof(Vuchar));
        vis_ZStateSaveState(zstate, state, bstate, &newbytes);

        /* clean-up ZState and State */
        vis_StateEnd(state);
        state = vis_StateBegin();
        vis_StateSetObject(state, VIS_GRIDFUN, (Vobject*)gridfun);
        vis_ZStateLoadState(zstate, bstate, state);
        free(bstate);

        /* compare compressed and uncompressed values */
        printf("      Compressed values:\n");
        for (i = 1; i <= numel; i += eleminc) {
            vis_StateData(state, 1, &i, value);
            printf("      %10d", i);
            for (j = 0; j < nrow; ++j) {
                printf(" %11.4e", value[j]);
            }
            printf("\n");
        }
    }
    vdm_DataFunClose(datafun);

    /* clean-up */
    vis_RPropEnd(rprop);
    vis_StateEnd(state);
    vis_ZStateEnd(zstate);
    vis_ModelDelete(model);
    vis_ModelEnd(model);
    vis_GridFunEnd(gridfun);
    vdm_LManEnd(lman);
    datafileterm(filetype, datafun);
    vdm_DataFunEnd(datafun);
    return 0;
}
