#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/vis/visdata.h"
#include "sam/vdm/vdm.h"
#include "sam/vdm/datafile.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static void
loadandsave_result(vdm_LMan* lman, vdm_LMan* lmanw, vdm_Library* library, vis_Model* model);

/*----------------------------------------------------------------------
                     Load Model and Results and Save to any format
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    char inputfile[256];
    char outputfile[256];
    vdm_DataFun* datafun = NULL;
    vdm_Library* library;
    vdm_LMan* lman = NULL;
    Vint filetype;
    Vint numnp, numel;
    vis_Model* model = NULL;
    vis_Connect* connect;
    Vint ierr;
    vdm_DataFun* datafunw = NULL;
    vdm_LMan* lmanw = NULL;
    Vint filetypew = 0;

    /* check input arguments */
    if (argc < 3) {
        fprintf(stderr, "Usage: %s inputfile outputfile\n", argv[0]);
        exit(1);
    }
    else {
        strcpy(inputfile, argv[1]);
        strcpy(outputfile, argv[2]);
    }

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create input data function object */
    datafun = vdm_DataFunBegin();
    datafiletype(inputfile, &filetype);
    if (filetype == 0) {
        fprintf(stderr, "Error: Bad input file %s\n", inputfile);
        goto labelcleanup;
    }
    datafileinit(filetype, datafun);
    vdm_DataFunOpen(datafun, 0, inputfile, filetype);
    ierr = vdm_DataFunError(datafun);
    if (ierr) {
        fprintf(stderr, "Error: opening file %s\n", inputfile);
        goto labelcleanup;
    }
    /* instance Model object for simulation model */
    model = vis_ModelBegin();

    /* use Library Manager object to load model */
    lman = vdm_LManBegin();
    vdm_LManSetObject(lman, VDM_DATAFUN, datafun);
    vdm_LManLoadModel(lman, model);

    /* create output data function object */
    datafunw = vdm_DataFunBegin();
    datafiletype(outputfile, &filetypew);
    if (filetypew == 0) {
        fprintf(stderr, "Error: Bad output file %s\n", outputfile);
        goto labelcleanup;
    }
    datafileinit(filetypew, datafunw);
    vdm_DataFunSetStatus(datafunw, VDM_STATUS_NEW);
    vdm_DataFunOpen(datafunw, 0, outputfile, filetypew);
    ierr = vdm_DataFunError(datafunw);
    if (ierr) {
        fprintf(stderr, "Error: opening file %s\n", outputfile);
        goto labelcleanup;
    }
    /* use Library Manager object to save model */
    lmanw = vdm_LManBegin();
    vdm_LManSetObject(lmanw, VDM_DATAFUN, datafunw);
    vdm_LManSetParami(lmanw, LMAN_SAVERESULT_PRE, SYS_DOUBLE);

    /* get Connect object created in Model */
    vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("number of nodes= %d\n", numnp);
    printf("number of elems= %d\n", numel);

    /* get library object */
    vdm_DataFunGetLibrary(datafun, &library);

    /* save model */
    vdm_LManSaveModel(lmanw, model);
    /* load and save all results */
    loadandsave_result(lman, lmanw, library, model);

    /* close library devices */
    vdm_DataFunClose(datafun);
    vdm_DataFunClose(datafunw);

labelcleanup:
    /* delete objects in Model created by LManLoadModel */
    if (model) {
        vis_ModelDelete(model);
        vis_ModelEnd(model);
    }

    if (datafun) {
        datafileterm(filetype, datafun);
        vdm_DataFunEnd(datafun);
    }
    if (datafunw) {
        datafileterm(filetypew, datafunw);
        vdm_DataFunEnd(datafunw);
    }
    /* free objects */
    if (lman) {
        vdm_LManEnd(lman);
    }
    if (lmanw) {
        vdm_LManEnd(lmanw);
    }
    return 0;
}

/*----------------------------------------------------------------------
                      load and save results
----------------------------------------------------------------------*/
static void
loadandsave_result(vdm_LMan* lman, vdm_LMan* lmanw, vdm_Library* library, vis_Model* model)
{
    Vint i, isys;
    vdm_Dataset* dataset;
    Vchar dsname[DATASET_MAXNAME];
    Vchar dsroot[DATASET_MAXNAME];
    Vchar caux[DATASET_MAXNAME];
    Vchar andata[ATTRIBUTE_MAXVALUE];
    Vchar ancont[ATTRIBUTE_MAXVALUE];
    Vchar andesc[ATTRIBUTE_MAXVALUE];
    Vlong lrec;
    Vint nrow, ncol, ntyp;
    Vint numdatasets;
    Vint istate, ihistory, iredmat;
    vis_Connect* connect;
    vis_GridFun* gridfun;
    vis_State* state;
    vis_History* history;
    vis_RedMat* redmat;
    vis_RProp* rprop;
    vis_SProp* sprop;
    Vint type, hist, cplx, sect, enttype, subtype, datatype;
    Vint nqua, iqua[SYS_NQUA_MAX];
    Vchar cqua[DATASET_MAXNAME];
    Vint id1, id2, id3;
    vsy_HashTable *csh, *edh;
    vsy_List* spl;
    Vint soltyp, nantyp;
    /* determine maximum number of datasets */
    vdm_LibraryGetNumDatasets(library, &numdatasets);

    /* get Connect object created in Model */
    vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);
    vis_ModelGetHashTable(model, VIS_COORDSYS, &csh);
    vis_ModelGetHashTable(model, VIS_ELEMDAT, &edh);
    vis_ModelGetList(model, VIS_SPROP, &spl);
    /* check analysis and solution type of first solution */
    soltyp = SYS_SOL_NONE;
    nantyp = SYS_ANALYSIS_NONE;
    if (spl) {
        vsy_ListRef(spl, 1, (Vobject**)&sprop);
        if (sprop) {
            vis_SPropInq(sprop, &soltyp);
            vis_SPropValueInteger(sprop, SPROP_ANALYSIS, &nantyp);
        }
    }
    /* create a grid function object */
    gridfun = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gridfun);

    /* create state and install GridFun object */
    state = vis_StateBegin();
    vis_StateSetObject(state, VIS_GRIDFUN, gridfun);
    /* create history and install GridFun object */
    history = vis_HistoryBegin();
    vis_HistorySetObject(history, VIS_GRIDFUN, gridfun);
    /* create redmat object */
    redmat = vis_RedMatBegin();

    /* create result property object */
    rprop = vis_RPropBegin();

    /* loop over datasets */
    for (i = 0; i < numdatasets; i++) {
        vdm_LibraryGetDataset(library, i, &dataset);

        /* identify result quantity */
        vdm_DatasetResult(dataset, dsroot, &type, &hist, &nqua, iqua, cqua, &cplx, caux, &sect, &enttype, &subtype, &id1, &id2,
                          &id3);
        /* not a result */
        if (type == SYS_RES_NONE) {
            continue;
        }
        /* get dataset name and parameters */
        vdm_DatasetInq(dataset, dsname, &lrec, &nrow, &ncol, &ntyp);
        /* get Description attribute, Model datasets only */
        vdm_DatasetDescription(dataset, andesc);
        /* a model dataset */
        if (andesc[0] != '\0') {
            continue;
        }

        istate = 0;
        ihistory = 0;
        iredmat = 0;
        /* RedMat */
        if (enttype == SYS_DOF) {
            iredmat = 1;
            /* Node, Element, Mode, Panel, Particle History or State */
        }
        else if (enttype == SYS_NODE || enttype == SYS_ELEM || enttype == SYS_MODE || enttype == SYS_PANEL ||
                 enttype == SYS_PARTICLE) {
            if (hist) {
                ihistory = 1;
            }
            else {
                istate = 1;
            }
        }
        /* get DataType attribute */
        vdm_DatasetDataType(dataset, andata, &datatype);

        /* get Contents attribute */
        vdm_DatasetContents(dataset, ancont);

        /* print dataset name */
        printf("\n\nDataset: %s\n", dsname);

        /* print DataType and Contents */
        printf("DataType: %s\n", andata);
        printf("Contents: %s\n", ancont);

        /* load from dataset */
        vis_RPropDef(rprop, enttype, subtype);
        vis_RPropSetDatasetIndex(rprop, i);
        vis_RPropSetSolution(rprop, soltyp);
        vis_RPropSetAnalysis(rprop, nantyp);
        if (iredmat) {
            vdm_LManLoadRedMat(lman, redmat, rprop);
            vdm_LManSaveRedMat(lmanw, redmat, rprop);
        }
        else if (istate) {
            vdm_LManLoadState(lman, state, rprop);
            vis_StateGetSystem(state, &isys);
            if (isys == STATE_LOCAL) {
                vis_StateSetHashTable(state, VIS_COORDSYS, csh);
                vis_StateSetHashTable(state, VIS_ELEMDAT, edh);
            }
            vdm_LManSaveState(lmanw, state, rprop);
        }
        else if (ihistory) {
            vdm_LManLoadHistory(lman, history, rprop);
            vdm_LManSaveHistory(lmanw, history, rprop);
        }
    }
    /* free memory */
    vis_GridFunEnd(gridfun);
    vis_StateEnd(state);
    vis_HistoryEnd(history);
    vis_RedMatEnd(redmat);
    vis_RPropEnd(rprop);
}
