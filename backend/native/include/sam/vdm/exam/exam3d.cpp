#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/vis/visdata.h"
#include "sam/vdm/vdm.h"
#include "sam/vdm/datafile.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static void
print_redmat(vdm_LMan* lman, vdm_Library* library, vis_Model* model);

/*----------------------------------------------------------------------
                     Read and Print Reduced Matrix Data
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    Vint i;
    char inputfile[256];
    vdm_DataFun* datafun;
    vdm_Library* library;
    vdm_LMan* lman;
    Vint filetype, filetype1;
    Vint numnp, numel;
    vis_Model* model;
    vis_Connect* connect;
    Vint ierr;
    /* check input arguments */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s inputfile [appendfile]\n", argv[0]);
        exit(0);
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
        exit(0);
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
    /* look for appended file */
    for (i = 2; i < argc; i++) {
        if (strstr(argv[i], ".op2") != NULL) {
            filetype1 = VDM_NASTRAN_OUTPUT2;
        }
        else if (strstr(argv[i], ".unv") != NULL || strstr(argv[i], ".bun") != NULL) {
            filetype1 = VDM_SDRC_UNIVERSAL;
        }
        else if (strstr(argv[i], ".vdm") != NULL) {
            filetype1 = VDM_NATIVE;
        }
        else if (strstr(argv[i], ".dis") != NULL) {
            filetype1 = VDM_PATRAN_RESULT;
        }
        else if (strstr(argv[i], ".q") != NULL) {
            filetype1 = VDM_PLOT3D_SOLUTION;
        }
        else if (strstr(argv[i], ".dat") != NULL) {
            filetype1 = VDM_FLUENT_MESH;
        }
        else if (strstr(argv[i], ".cgns") != NULL) {
            filetype1 = VDM_CGNS;
        }
        else {
            fprintf(stderr, "Error: Bad appended file %s\n", argv[i]);
            exit(0);
        }
        vdm_DataFunAppend(datafun, argv[i], filetype1);
        /* check for error */
        ierr = vdm_DataFunError(datafun);
        if (ierr) {
            fprintf(stderr, "Error: appending file %s to file %s\n", argv[i], argv[1]);
            exit(0);
        }
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

    /* access and print reduced matrices and vectors */
    print_redmat(lman, library, model);

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
                      print reduced matrices and vectors
----------------------------------------------------------------------*/
static void
print_redmat(vdm_LMan* lman, vdm_Library* library, vis_Model* model)
{
    Vint i, j, k, n;
    vdm_Dataset* dataset;
    Vchar dsname[DATASET_MAXNAME];
    Vchar dsroot[DATASET_MAXNAME];
    Vchar caux[DATASET_MAXNAME];
    Vchar andata[ATTRIBUTE_MAXVALUE];
    Vchar ancont[ATTRIBUTE_MAXVALUE];
    Vlong lrec;
    Vint nrow, ncol, ntyp;
    Vint ncols, *cols;
    Vint numdatasets;
    Vint ndofs, redmattype, index, doftag, sparse;
    Vint nval;
    Vlong nent;
    Vfloat fv[2];
    vis_RedMat* redmat;
    vis_RProp* rprop;
    Vint type, hist, cplx, sect, enttype, subtype, datatype;
    Vint nqua, iqua[SYS_NQUA_MAX];
    Vchar cqua[DATASET_MAXNAME];
    Vint id1, id2, id3;

    /* determine maximum number of datasets */
    vdm_LibraryGetNumDatasets(library, &numdatasets);

    /* create redmat */
    redmat = vis_RedMatBegin();

    /* create result property object */
    rprop = vis_RPropBegin();

    /* loop over datasets */
    for (n = 0; n < numdatasets; n++) {
        vdm_LibraryGetDataset(library, n, &dataset);

        /* identify result quantity */
        vdm_DatasetResult(dataset, dsroot, &type, &hist, &nqua, iqua, cqua, &cplx, caux, &sect, &enttype, &subtype, &id1, &id2,
                          &id3);
        /* not a matrix result */
        if (type != SYS_RES_K_MAT && type != SYS_RES_M_MAT && type != SYS_RES_D_MAT && type != SYS_RES_L_VEC) {
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

        /* load state from dataset */
        vis_RPropDef(rprop, SYS_DOF, SYS_NONE);
        vis_RPropSetDatasetIndex(rprop, n);
        vdm_LManLoadRedMat(lman, redmat, rprop);
        /* number of entities, datatype */
        vis_RedMatInq(redmat, &ndofs, &redmattype);
        /* number of matrix entries, number of values per entry */
        /* nval = 1 real, nval= 2 complex */
        vis_RedMatNum(redmat, &nent, &nval);
        vis_RedMatSparse(redmat, &sparse);

        /* sparse matrix */
        if (redmattype == SYS_MATRIX_SYMM && sparse) {
            cols = (Vint*)malloc(ndofs * sizeof(Vint));
            for (i = 1; i <= ndofs; i++) {
                vis_RedMatGetDof(redmat, i, &index, &doftag);
                printf("   i= %2d, index= %d, doftag= %d\n", i, index, doftag);
                vis_RedMatDataCols(redmat, i, &ncols, cols);
                for (k = 0; k < ncols; ++k) {
                    j = cols[k];
                    printf("   row= %d, col= %d", i, j);
                    vis_RedMatData(redmat, i, j, fv);
                    if (nval == 1) {
                        printf("  fv= %11.4e\n", fv[0]);
                    }
                    else if (nval == 2) {
                        printf("  fv= %11.4e %11.4e(i)\n", fv[0], fv[1]);
                    }
                }
            }
            free(cols);
            continue;
        }
        /* not sparse */
        /* loop through dofs */
        for (j = 1; j <= ndofs; j++) {
            vis_RedMatGetDof(redmat, j, &index, &doftag);
            printf("   j= %2d, index= %d, doftag= %d\n", j, index, doftag);
            if (redmattype == SYS_VECTOR) {
                i = 1;
                printf("   i= %d, j= %d", i, j);
                vis_RedMatData(redmat, i, j, fv);
                if (nval == 1) {
                    printf("  fv= %11.4e\n", fv[0]);
                }
                else if (nval == 2) {
                    printf("  fv= %11.4e %11.4e(i)\n", fv[0], fv[1]);
                }
            }
            else if (redmattype == SYS_MATRIX_DIAG) {
                i = j;
                printf("   i= %d, j= %d", i, j);
                vis_RedMatData(redmat, i, j, fv);
                if (nval == 1) {
                    printf("  fv= %11.4e\n", fv[0]);
                }
                else if (nval == 2) {
                    printf("  fv= %11.4e %11.4e(i)\n", fv[0], fv[1]);
                }
            }
            else if (redmattype == SYS_MATRIX_SYMM) {
                for (i = 1; i <= j; ++i) {
                    printf("   i= %d, j= %d", i, j);
                    vis_RedMatData(redmat, i, j, fv);
                    if (nval == 1) {
                        printf("  fv= %11.4e\n", fv[0]);
                    }
                    else if (nval == 2) {
                        printf("  fv= %11.4e %11.4e(i)\n", fv[0], fv[1]);
                    }
                }
            }
        }
    }
    /* free memory */
    vis_RedMatEnd(redmat);
    vis_RPropEnd(rprop);
}
