#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/vis/visdata.h"
#include "sam/vdm/vdm.h"
#include "sam/vdm/datafile.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static void
print_particle(vdm_LMan* lman, vdm_Library* library);

/*----------------------------------------------------------------------
                     Read and Print Particle Data
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    char inputfile[256] = {0};
    vdm_DataFun* datafun = NULL;
    vdm_Library* library = NULL;
    vdm_LMan* lman = NULL;
    Vint filetype, ierr;
    /* check input arguments */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s inputfile\n", argv[0]);
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
    /* use Library Manager object */
    lman = vdm_LManBegin();
    vdm_LManSetObject(lman, VDM_DATAFUN, datafun);

    /* get library object */
    vdm_DataFunGetLibrary(datafun, &library);

    /* access and print particle results */
    print_particle(lman, library);

    /* close library device */
    vdm_DataFunClose(datafun);

    datafileterm(filetype, datafun);
    /* free objects */
    vdm_DataFunEnd(datafun);

    vdm_LManEnd(lman);
    return 0;
}

/*----------------------------------------------------------------------
                      print particle scalars and vectors
----------------------------------------------------------------------*/
static void
print_particle(vdm_LMan* lman, vdm_Library* library)
{
    Vint i, n;
    vdm_Dataset* dataset;
    Vchar dsname[DATASET_MAXNAME];
    Vchar dsroot[DATASET_MAXNAME];
    Vchar caux[DATASET_MAXNAME];
    Vchar andata[ATTRIBUTE_MAXVALUE];
    Vchar ancont[ATTRIBUTE_MAXVALUE];
    Vlong lrec;
    Vint nrow, ncol, ntyp;
    Vint numdatasets;
    Vint nument;
    vis_RProp* rprop;
    vis_State* state;
    Vfloat fv[16];
    Vint type, hist, cplx, sect, enttype, subtype, datatype;
    Vint nqua, iqua[SYS_NQUA_MAX];
    Vchar cqua[DATASET_MAXNAME];
    Vint id1, id2, id3;

    /* determine maximum number of datasets */
    vdm_LibraryGetNumDatasets(library, &numdatasets);

    /* create state */
    state = vis_StateBegin();

    /* create result property object */
    rprop = vis_RPropBegin();

    /* loop over datasets */
    for (n = 0; n < numdatasets; n++) {
        vdm_LibraryGetDataset(library, n, &dataset);

        /* identify result quantity */
        vdm_DatasetResult(dataset, dsroot, &type, &hist, &nqua, iqua, cqua, &cplx, caux, &sect, &enttype, &subtype, &id1, &id2,
                          &id3);
        /* not a particle result */
        if (enttype != SYS_PARTICLE) {
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
        vis_RPropDef(rprop, SYS_PARTICLE, SYS_NONE);
        vis_RPropSetDatasetIndex(rprop, n);
        vdm_LManLoadState(lman, state, rprop);

        vis_StateInq(state, &nument, &enttype, &subtype, &datatype);
        /* loop over entities */
        for (i = 1; i <= nument; i++) {
            /* check for entities to be printed */
            if (i != 1 && i != nument) {
                continue;
            }
            vis_StateData(state, 1, &i, fv);
            if (datatype == VIS_SCALAR) {
                printf("particle= %d, scalar= %14e\n", i, fv[0]);
                /* vector type */
            }
            else if (datatype == VIS_VECTOR) {
                printf("particle= %d, vector= %14e %14e %14e\n", i, fv[0], fv[1], fv[2]);
            }
        }
    }
    /* free memory */
    vis_StateEnd(state);
    vis_RPropEnd(rprop);
}
