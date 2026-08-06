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
                     Load Model and Results and Save to Native File
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    char inputfile[256];
    char outputfile[256];
    vdm_DataFun* datafun;
    vdm_Library* library;
    vdm_LMan* lman;
    Vint filetype;
    Vint numnp, numel;
    vis_Model* model;
    vis_Connect* connect;
    Vint ierr;
    vdm_DataFun* datafunw;
    vdm_LMan* lmanw;
    vdm_NatLib* natlib;
    Vint filetypew;

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
    /* select native file type, use file extension .vdm */
    filetypew = VDM_NATIVE;
    /* uncomment below for HDF5 file type, use .vh5 */
    /* filetypew = VDM_NATIVE_HDF5; */

    /* create output data function object */
    datafunw = vdm_DataFunBegin();
    natlib = vdm_NatLibBegin();
    vdm_NatLibDataFun(natlib, datafunw);
    /* new file */
    vdm_DataFunSetStatus(datafunw, VDM_STATUS_NEW);
    /* open library device */
    vdm_DataFunOpen(datafunw, 0, outputfile, filetypew);
    /* check for error */
    ierr = vdm_DataFunError(datafunw);
    if (ierr) {
        fprintf(stderr, "Error: opening file %s\n", outputfile);
        exit(1);
    }
    /* use Library Manager object to save model */
    lmanw = vdm_LManBegin();
    vdm_LManSetObject(lmanw, VDM_DATAFUN, datafunw);
    vdm_LManSetParami(lmanw, LMAN_SAVERESULT_PRE, SYS_DOUBLE);

    /* instance Model object for simulation model */
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

    /* save model */
    vdm_LManSaveModel(lmanw, model);
    /* load and save all results */
    loadandsave_result(lman, lmanw, library, model);

    /* close library devices */
    vdm_DataFunClose(datafun);
    vdm_DataFunClose(datafunw);

    /* delete objects in Model created by LManLoadModel */
    vis_ModelDelete(model);

    datafileterm(filetype, datafun);
    /* free objects */
    vdm_DataFunEnd(datafun);
    vdm_LManEnd(lman);
    vis_ModelEnd(model);

    vdm_DataFunEnd(datafunw);
    vdm_LManEnd(lmanw);
    vdm_NatLibEnd(natlib);
    return 0;
}

/*----------------------------------------------------------------------
                      load and save results
----------------------------------------------------------------------*/
static void
loadandsave_result(vdm_LMan* lman, vdm_LMan* lmanw, vdm_Library* library, vis_Model* model)
{
    Vint i;
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
    Vint type, hist, cplx, sect, enttype, subtype, datatype;
    Vint nqua, iqua[SYS_NQUA_MAX];
    Vchar cqua[DATASET_MAXNAME];
    Vint id1, id2, id3;

    /* determine maximum number of datasets */
    vdm_LibraryGetNumDatasets(library, &numdatasets);

    /* get Connect object created in Model */
    vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);

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
        if (iredmat) {
            vdm_LManLoadRedMat(lman, redmat, rprop);
            vdm_LManSaveRedMat(lmanw, redmat, rprop);
        }
        else if (istate) {
            vdm_LManLoadState(lman, state, rprop);
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
