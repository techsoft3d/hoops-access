#include "sam/base/base.h"
#include "sam/vdm/vdm.h"

/*----------------------------------------------------------------------
                      List all Datasets
----------------------------------------------------------------------*/
int
main()
{
    vdm_SDRCLib* sdrclib;
    vdm_DataFun* datafun;
    vdm_Library* library;
    vdm_Dataset* dataset;
    Vint filetype;
    Vint numnp, numel;
    Vint numdatasets, numattributes;
    Vchar dsname[DATASET_MAXNAME];
    Vlong lrec;
    Vint nrow, ncol, ntyp;

    int i;

    /* create data function object */
    datafun = new vdm_DataFun;

    /* create SDRC Universal File library device */
    filetype = VDM_SDRC_UNIVERSAL;
    sdrclib = new vdm_SDRCLib;
    sdrclib->DataFun(datafun);

    /* open library device */
    datafun->Open(0, "bumper.unv", filetype);

    /* get number of nodes and elements */
    datafun->GetNumEntities(SYS_NODE, &numnp);
    datafun->GetNumEntities(SYS_ELEM, &numel);
    printf("Number of nodes    = %10d\n", numnp);
    printf("Number of elements = %10d\n", numel);

    /* get library object */
    datafun->GetLibrary(&library);

    /* get number of datasets on library */
    library->GetNumDatasets(&numdatasets);

    /* print heading */
    printf("Number of datasets = %10d\n", numdatasets);
    printf("  Seq     LRec  NRow     NCol  NTyp  NAtt  Name\n");

    /* loop through datasets */
    for (i = 0; i < numdatasets; i++) {
        library->GetDataset(i, &dataset);
        dataset->Inq(dsname, &lrec, &nrow, &ncol, &ntyp);
        dataset->GetNumAttributes(&numattributes);
        printf("%5d %8lld %5d %8d %5d %5d  %s\n", i, lrec, nrow, ncol, ntyp, numattributes, dsname);
    }
    /* close library device */
    datafun->Close();

    /* free objects */
    delete datafun;
    delete sdrclib;
    return 0;
}
