#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/vis/visdata.h"
#include "sam/vdm/vdm.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static void
print_histinfo(vdm_DataFun* datafun, vdm_Library* library, vis_IdTran* idtrannode, vis_IdTran* idtranelem);
static void
print_index(Vint enttype, vis_IdTran* idtran, vdm_DataFun* datafun, vdm_Library* library, vdm_Attribute* attribute);
static void
print_step(vdm_DataFun* datafun, vdm_Library* library, vdm_Attribute* attribute, Vint indep, Vchar* indepname,
           vdm_Attribute* attributev);

/*----------------------------------------------------------------------
                     Read and Print Results History Summary
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    char inputfile[256];
    vdm_NASLib* naslib = NULL;
    vdm_NatLib* natlib = NULL;
    vdm_SDRCLib* sdrclib = NULL;
    vdm_ANSLib* anslib = NULL;
    vdm_ABALib* abalib = NULL;
    vdm_DataFun* datafun = NULL;
    vdm_Library* library = NULL;
    Vint filetype;
    Vint i;
    Vint ndst, idst;
    Vint* ptrint = NULL;
    Vint numnp, numel;
    vis_IdTran *idtrannode = NULL, *idtranelem = NULL;

    /* check input arguments */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s inputfile\n", argv[0]);
        fprintf(stderr, " inputfile is blank, 'cantilever.unv' is assumed\n");
        strcpy(inputfile, "cantilever.unv");
    }
    else {
        strcpy(inputfile, argv[1]);
    }

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create data function object */
    datafun = vdm_DataFunBegin();

    /* determine file type from file extension */
    if (strstr(inputfile, ".unv") != NULL) {
        filetype = VDM_SDRC_UNIVERSAL;
        sdrclib = vdm_SDRCLibBegin();
        vdm_SDRCLibDataFun(sdrclib, datafun);
    }
    else if (strstr(inputfile, ".op2") != NULL) {
        filetype = VDM_NASTRAN_OUTPUT2;
        naslib = vdm_NASLibBegin();
        vdm_NASLibDataFun(naslib, datafun);
    }
    else if (strstr(inputfile, ".vdm") != NULL) {
        filetype = VDM_NATIVE;
        natlib = vdm_NatLibBegin();
        vdm_NatLibDataFun(natlib, datafun);
    }
    else if (strstr(inputfile, ".rst") != NULL) {
        filetype = VDM_ANSYS_RESULT;
        anslib = vdm_ANSLibBegin();
        vdm_ANSLibDataFun(anslib, datafun);
    }
    else if (strstr(inputfile, ".fil") != NULL) {
        filetype = VDM_ABAQUS_FIL;
        abalib = vdm_ABALibBegin();
        vdm_ABALibDataFun(abalib, datafun);
    }
    else {
        fprintf(stderr, "Error: Bad input file %s\n", inputfile);
        exit(1);
    }
    /* open library device */
    vdm_DataFunOpen(datafun, 0, inputfile, filetype);

    /* query number of nodes and elements */
    vdm_DataFunGetNumEntities(datafun, SYS_NODE, &numnp);
    vdm_DataFunGetNumEntities(datafun, SYS_ELEM, &numel);

    /* get library object */
    vdm_DataFunGetLibrary(datafun, &library);

    /* establish node identifiers */
    vdm_LibrarySearchDataset(library, "NID.N", 1, &idst, &ndst);
    idtrannode = vis_IdTranBegin();
    vis_IdTranDef(idtrannode, numnp);
    if (ndst) {
        ptrint = (Vint*)malloc(numnp * sizeof(Vint));
        vdm_DataFunReadDataset(datafun, idst, ptrint);
        for (i = 1; i <= numnp; i++) {
            vis_IdTranSetId(idtrannode, i, ptrint[i - 1]);
        }
        free(ptrint);
    }
    /* establish element identifiers */
    vdm_LibrarySearchDataset(library, "EID.E", 1, &idst, &ndst);
    idtranelem = vis_IdTranBegin();
    vis_IdTranDef(idtranelem, numel);
    if (ndst) {
        ptrint = (Vint*)malloc(numel * sizeof(Vint));
        vdm_DataFunReadDataset(datafun, idst, ptrint);
        for (i = 1; i <= numel; i++) {
            vis_IdTranSetId(idtranelem, i, ptrint[i - 1]);
        }
        free(ptrint);
    }
    /* print history information */
    print_histinfo(datafun, library, idtrannode, idtranelem);

    /* free IdTran objects */
    vis_IdTranEnd(idtrannode);
    vis_IdTranEnd(idtranelem);

    /* close library device */
    vdm_DataFunClose(datafun);

    /* free objects */
    vdm_DataFunEnd(datafun);
    if (filetype == VDM_SDRC_UNIVERSAL) {
        vdm_SDRCLibEnd(sdrclib);
    }
    else if (filetype == VDM_NASTRAN_OUTPUT2) {
        vdm_NASLibEnd(naslib);
    }
    else if (filetype == VDM_NATIVE) {
        vdm_NatLibEnd(natlib);
    }
    else if (filetype == VDM_ANSYS_RESULT) {
        vdm_ANSLibEnd(anslib);
    }
    else if (filetype == VDM_ABAQUS_FIL) {
        vdm_ABALibEnd(abalib);
    }
    return 0;
}

/*----------------------------------------------------------------------
                      print history information
----------------------------------------------------------------------*/
static void
print_histinfo(vdm_DataFun* datafun, vdm_Library* library, vis_IdTran* idtrannode, vis_IdTran* idtranelem)
{
    Vint i;
    vdm_Dataset* dataset;
    vdm_Attribute* attribute;
    vdm_Attribute* attributev;
    Vchar dsroot[DATASET_MAXNAME], caux[DATASET_MAXNAME];
    Vint type, hist, cplx, sect, enttype, subtype;
    Vint nqua, iqua[SYS_NQUA_MAX];
    Vchar cqua[DATASET_MAXNAME];
    Vint id1, id2, id3;
    Vchar dsname[DATASET_MAXNAME];
    Vlong lrec;
    Vint nrow, ncol, ntyp;
    Vchar cvalue[ATTRIBUTE_MAXVALUE];
    Vint numdatasets;
    Vint ndst, *idst;
    Vint natt, iatt;
    Vint indep, nattv, iattv;
    Vchar indepname[81];

    /* query maximum number of datasets */
    vdm_LibraryGetNumDatasets(library, &numdatasets);

    /* allocate array for dataset indices */
    idst = (Vint*)malloc(numdatasets * sizeof(Vint));

    /* search for all history related datasets */
    vdm_LibrarySearchDataset(library, "HIST.*", numdatasets, idst, &ndst);
    if (ndst == 0) {
        free(idst);
        return;
    }
    /* loop over history datasets */
    for (i = 0; i < ndst; i++) {
        vdm_LibraryGetDataset(library, idst[i], &dataset);

        /* identify result quantity information */
        vdm_DatasetResult(dataset, dsroot, &type, &hist, &nqua, iqua, cqua, &cplx, caux, &sect, &enttype, &subtype, &id1, &id2,
                          &id3);

        /* skip if not results type */
        if (type == SYS_RES_NONE) {
            continue;
        }
        /* skip if imaginary or phase */
        if (cplx) {
            continue;
        }
        /* print dataset name, etc. */
        vdm_DatasetInq(dataset, dsname, &lrec, &nrow, &ncol, &ntyp);
        printf("Dataset: %s\n", dsname);
        if (enttype == SYS_NODE) {
            printf("Node result\n");
        }
        else if (enttype == SYS_ELEM) {
            if (subtype == SYS_NONE) {
                printf("Element result\n");
            }
            else {
                printf("Element node result\n");
            }
        }
        /* query Contents */
        vdm_DatasetSearchAttribute(dataset, (Vchar*)"Contents", 1, &iatt, &natt);
        if (natt) {
            vdm_DatasetGetAttribute(dataset, iatt, &attribute);
            vdm_AttributeValueString(attribute, cvalue);
            printf("Contents: %s\n", cvalue);
        }
        /* query Link.Complex */
        vdm_DatasetSearchAttribute(dataset, (Vchar*)"Link.Complex", 1, &iatt, &natt);
        if (natt) {
            vdm_DatasetGetAttribute(dataset, iatt, &attribute);
            vdm_AttributeValueString(attribute, cvalue);
            printf("Link.Complex: %s\n", cvalue);
        }
        /* query Link.Index */
        vdm_DatasetSearchAttribute(dataset, (Vchar*)"Link.Index", 1, &iatt, &natt);
        if (natt) {
            vdm_DatasetGetAttribute(dataset, iatt, &attribute);
            if (enttype == SYS_NODE) {
                print_index(enttype, idtrannode, datafun, library, attribute);
            }
            else {
                print_index(enttype, idtranelem, datafun, library, attribute);
            }
        }
        /* query Link.Step */
        vdm_DatasetSearchAttribute(dataset, (Vchar*)"Link.Step", 1, &iatt, &natt);
        /* query Link to independent variable */
        vdm_DatasetSearchAttribute(dataset, (Vchar*)"Link.Time", 1, &iattv, &nattv);
        indep = 1;
        strcpy(indepname, "Time");
        if (nattv == 0) {
            vdm_DatasetSearchAttribute(dataset, (Vchar*)"Link.Frequency", 1, &iattv, &nattv);
            indep = 2;
            strcpy(indepname, "Frequency");
        }
        if (nattv == 0) {
            vdm_DatasetSearchAttribute(dataset, (Vchar*)"Link.LoadFactor", 1, &iattv, &nattv);
            indep = 3;
            strcpy(indepname, "LoadFactor");
        }
        if (natt) {
            vdm_DatasetGetAttribute(dataset, iatt, &attribute);
            if (nattv) {
                vdm_DatasetGetAttribute(dataset, iattv, &attributev);
                print_step(datafun, library, attribute, indep, indepname, attributev);
            }
            else {
                print_step(datafun, library, attribute, 0, NULL, NULL);
            }
        }
        printf("\n");
    }
    /* free memory */
    free(idst);
}

/*----------------------------------------------------------------------
                      print index dataset
----------------------------------------------------------------------*/
static void
print_index(Vint enttype, vis_IdTran* idtran, vdm_DataFun* datafun, vdm_Library* library, vdm_Attribute* attribute)
{
    Vint i;
    Vchar cvalue[ATTRIBUTE_MAXVALUE];
    Vint idst, ndst;
    vdm_Dataset* dataset;
    Vchar dsname[DATASET_MAXNAME];
    Vlong lrec;
    Vint nrow, ncol, ntyp;
    Vint index, id;
    Vint* inds;

    vdm_AttributeValueString(attribute, cvalue);
    vdm_LibrarySearchDataset(library, cvalue, 1, &idst, &ndst);
    vdm_LibraryGetDataset(library, idst, &dataset);

    /* ncol is the number of entities, nrow is 1 */
    vdm_DatasetInq(dataset, dsname, &lrec, &nrow, &ncol, &ntyp);

    /* read and print entity indices */
    inds = (Vint*)malloc(ncol * sizeof(Vint));
    vdm_DataFunReadDataset(datafun, idst, inds);

    /* use IdTran to get user id */
    for (i = 0; i < ncol; i++) {
        index = inds[i];
        vis_IdTranGetId(idtran, index, &id);
        if (enttype == SYS_NODE) {
            printf("node index= %d, id= %d\n", index, id);
        }
        else {
            printf("element index= %d, id= %d\n", index, id);
        }
    }

    free(inds);
}

/*----------------------------------------------------------------------
                      print step and independent variable datasets
----------------------------------------------------------------------*/
static void
print_step(vdm_DataFun* datafun, vdm_Library* library, vdm_Attribute* attribute, Vint indep, Vchar* indepname,
           vdm_Attribute* attributev)
{
    Vint i;
    Vchar cvalue[ATTRIBUTE_MAXVALUE], cvaluev[ATTRIBUTE_MAXVALUE];
    Vint idst, ndst, idstv, ndstv;
    vdm_Dataset *dataset = NULL, *datasetv = NULL;
    Vchar dsname[DATASET_MAXNAME];
    Vlong lrec;
    Vint nrow, ncol, ntyp;
    Vint* inds = NULL;
    Vfloat* indv = NULL;

    vdm_AttributeValueString(attribute, cvalue);
    vdm_LibrarySearchDataset(library, cvalue, 1, &idst, &ndst);
    vdm_LibraryGetDataset(library, idst, &dataset);

    /* ncol is the number of steps, nrow is 1 */
    vdm_DatasetInq(dataset, dsname, &lrec, &nrow, &ncol, &ntyp);

    /* read step numbers */
    inds = (Vint*)malloc(ncol * sizeof(Vint));
    vdm_DataFunReadDataset(datafun, idst, inds);

    /* read independent variable values */
    if (indep) {
        vdm_AttributeValueString(attributev, cvaluev);
        vdm_LibrarySearchDataset(library, cvaluev, 1, &idstv, &ndstv);
        vdm_LibraryGetDataset(library, idstv, &datasetv);
        vdm_DatasetInq(datasetv, dsname, &lrec, &nrow, &ncol, &ntyp);
        indv = (Vfloat*)malloc(ncol * sizeof(Vfloat));
        vdm_DataFunReadDataset(datafun, idstv, indv);
    }

    for (i = 0; i < ncol; i++) {
        printf("stepnumber= %d", inds[i]);
        if (indep) {
            printf(", %s= %e", indepname, indv[i]);
        }
        printf("\n");
    }

    free(inds);
    if (indep) {
        free(indv);
    }
}
