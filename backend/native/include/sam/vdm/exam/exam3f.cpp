#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/vis/visdata.h"
#include "sam/vdm/vdm.h"
#include "sam/vdm/datafile.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static void
print_hist(vdm_DataFun* datafun, vdm_Library* library, vis_Model* model);

/*----------------------------------------------------------------------
                     Read and Print Modal and Panel Contribution Results
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

    /* check input arguments */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s inputfile [appendfile]\n", argv[0]);
        exit(1);
    }
    else {
        strcpy(inputfile, argv[1]);
    }

    vsy_LicenseValidate(HOOPS_LICENSE);

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

    /* access and print modal contribution histories */
    print_hist(datafun, library, model);

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
                      print histories
----------------------------------------------------------------------*/
static void
print_hist(vdm_DataFun* datafun, vdm_Library* library, vis_Model* model)
{
    Vint i, j, k, n;
    vdm_Dataset *dataset, *datasetlink;
    Vchar dsname[DATASET_MAXNAME];
    Vchar dsroot[DATASET_MAXNAME];
    Vchar caux[DATASET_MAXNAME];
    Vchar andata[ATTRIBUTE_MAXVALUE];
    Vchar ancont[ATTRIBUTE_MAXVALUE];
    Vchar dslink[DATASET_MAXNAME];
    Vint ids[2], nds, ind;
    Vlong lrec, lreclink;
    Vint nrow, ncol, ntyp, nrowlink, ncollink, ntyplink;
    Vint numdatasets;
    Vint type, hist, cplx, sect, enttype, subtype, datatype;
    Vint nqua, iqua[SYS_NQUA_MAX];
    Vchar cqua[DATASET_MAXNAME];
    Vint id1, id2, id3;
    Vfloat *res, *freq;
    Vint maxres, maxdat, maxfreq;
    Vint complexflag;
    Vint iatts[2], natts;
    vdm_Attribute* attribute;
    Vint nodeid;

    /* determine maximum number of datasets */
    vdm_LibraryGetNumDatasets(library, &numdatasets);

    /* pointer for returned results data */
    res = NULL;
    maxres = 0;
    freq = NULL;
    maxfreq = 0;
    /* loop over datasets */
    for (i = 0; i < numdatasets; i++) {
        vdm_LibraryGetDataset(library, i, &dataset);

        /* identify result quantity */
        vdm_DatasetResult(dataset, dsroot, &type, &hist, &nqua, iqua, cqua, &cplx, caux, &sect, &enttype, &subtype, &id1, &id2,
                          &id3);
        /* test for no result */
        if (type == SYS_RES_NONE) {
            continue;
        }
        /* skip non-history datasets */
        if (hist == 0) {
            continue;
        }
        /* skip anything but mode and panel entities */
        if (enttype != SYS_MODE && enttype != SYS_PANEL) {
            continue;
        }
        /* get dataset name and parameters */
        vdm_DatasetInq(dataset, dsname, &lrec, &nrow, &ncol, &ntyp);

        /* get DataType attribute */
        vdm_DatasetDataType(dataset, andata, &datatype);

        /* get Contents attribute */
        vdm_DatasetContents(dataset, ancont);

        /* print dataset name */
        printf("\n\nDataset: %s\n", dsname);

        /* print DataType and Contents */
        printf("DataType: %s\n", andata);
        printf("Contents: %s\n", ancont);

        /* test overall result type */
        if (type == SYS_RES_D) {
            printf("result: Displacement\n");
        }
        else if (type == SYS_RES_V) {
            printf("result: Velocity\n");
        }
        else if (type == SYS_RES_A) {
            printf("result: Acceleration\n");
        }
        else if (type == SYS_RES_PRES) {
            printf("result: Pressure\n");
        }
        /* test qualifiers */
        for (n = 0; n < nqua; n++) {
            if (iqua[n] == SYS_QUA_TX) {
                printf("qualifier: TX component\n");
            }
            else if (iqua[n] == SYS_QUA_TY) {
                printf("qualifier: TY component\n");
            }
            else if (iqua[n] == SYS_QUA_TZ) {
                printf("qualifier: TZ component\n");
            }
            else if (iqua[n] == SYS_QUA_RX) {
                printf("qualifier: RX component\n");
            }
            else if (iqua[n] == SYS_QUA_RY) {
                printf("qualifier: RY component\n");
            }
            else if (iqua[n] == SYS_QUA_RZ) {
                printf("qualifier: RZ component\n");
            }
            else if (iqua[n] == SYS_QUA_ABS) {
                printf("qualifier: Abs\n");
            }
            else if (iqua[n] == SYS_QUA_NORM) {
                printf("qualifier: Norm\n");
            }
            else if (iqua[n] == SYS_QUA_MODAL) {
                printf("qualifier: Modal\n");
            }
            else if (iqua[n] == SYS_QUA_PANEL) {
                printf("qualifier: Panel\n");
            }
        }
        /* parse cqua, "Node-n */
        if (cqua[0] != '\0') {
            sscanf(&cqua[5], "%d", &nodeid);
            printf("node= %d\n", nodeid);
        }
        /* find link to associated response frequencies */
        /* there should be a frequency for each column in the history */
        vdm_DatasetSearchAttribute(dataset, (Vchar*)"Link.Frequency", 1, iatts, &natts);
        if (natts) {
            vdm_DatasetGetAttribute(dataset, iatts[0], &attribute);
            vdm_AttributeValueString(attribute, dslink);
            vdm_LibrarySearchDataset(library, dslink, 1, ids, &nds);
            vdm_LibraryGetDataset(library, ids[0], &datasetlink);
            vdm_DatasetInq(datasetlink, dslink, &lreclink, &nrowlink, &ncollink, &ntyplink);
            maxdat = (Vint)(lreclink * sizeof(Vfloat));
            if (maxdat > maxfreq) {
                maxfreq = maxdat;
                freq = (Vfloat*)realloc(freq, maxfreq * sizeof(Vfloat));
            }
            vdm_DataFunReadDataset(datafun, ids[0], freq);
        }
        /* compute length of data in dataset */
        complexflag = 0;
        maxdat = (Vint)(lrec * sizeof(Vfloat));
        if (cplx == SYS_COMPLEX_REALIMAGINARY || cplx == SYS_COMPLEX_MAGNITUDEPHASE) {
            complexflag = 1;
            maxdat *= 2;
        }
        if (maxdat > maxres) {
            maxres = maxdat;
            res = (Vfloat*)realloc(res, maxres * sizeof(Vfloat));
        }
        /* read data */
        vdm_DataFunReadDataset(datafun, i, res);
        ind = 0;
        for (j = 0; j < ncol; j++) {
            for (k = 0; k < nrow; k++) {
                if (natts) {
                    printf("frequency= %e\n", freq[j]);
                }
                if (complexflag == 0) {
                    printf("col= %d, row= %d, val= %e\n", j, k, res[ind]);
                }
                else {
                    printf("col= %d, row= %d, val= %e %e(i)\n", j, k, res[2 * ind], res[2 * ind + 1]);
                }
                ind += 1;
            }
        }
    }
    /* free memory */
    free(res);
    free(freq);
}
