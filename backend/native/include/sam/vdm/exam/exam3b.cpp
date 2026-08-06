#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/vdm/vdm.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static void
print_toc(vdm_DataFun* datafun);
static void
print_attributes(vdm_Dataset* dataset);
static void
print_model(vdm_DataFun* datafun);

/*----------------------------------------------------------------------
                     Read and Print Remeshing Results
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    char inputfile[256];
    vdm_MarcLib* marclib = NULL;
    vdm_D3DLib* d3dlib = NULL;
    vdm_EnSightLib* ensightlib = NULL;
    vdm_DataFun* datafun = NULL;
    Vint filetype = 0;
    Vint numnp, numel;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s inputfile\n", argv[0]);
        fprintf(stderr, " inputfile is blank, 'impact.t19' is assumed\n");
        strcpy(inputfile, "impact.t19");
    }
    else {
        strcpy(inputfile, argv[1]);
    }

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create data function object */
    datafun = vdm_DataFunBegin();

    /* determine file type from file extension */
    if (strstr(inputfile, "d3plot") != NULL) {
        filetype = SYS_LSTC_STATE;
        d3dlib = vdm_D3DLibBegin();
        vdm_D3DLibDataFun(d3dlib, datafun);
    }
    else if (strstr(inputfile, ".t16") != NULL || strstr(inputfile, ".t19") != NULL) {
        filetype = SYS_MARC_POST;
        marclib = vdm_MarcLibBegin();
        vdm_MarcLibDataFun(marclib, datafun);
    }
    else if (strstr(inputfile, ".case") != NULL || strstr(inputfile, ".encas") != NULL) {
        filetype = SYS_ENSIGHT;
        ensightlib = vdm_EnSightLibBegin();
        vdm_EnSightLibDataFun(ensightlib, datafun);
    }
    else {
        fprintf(stderr, "Error: Bad input file %s\n", inputfile);
        exit(1);
    }
    /* open library device */
    vdm_DataFunOpen(datafun, 0, inputfile, filetype);

    /* get number of nodes and elements */
    vdm_DataFunGetNumEntities(datafun, SYS_NODE, &numnp);
    vdm_DataFunGetNumEntities(datafun, SYS_ELEM, &numel);
    printf("number of nodes= %d\n", numnp);
    printf("number of elems= %d\n", numel);

    /* traverse tables of contents */
    print_toc(datafun);
    /* load model and states */
    print_model(datafun);

    /* close library device */
    vdm_DataFunClose(datafun);

    /* free objects */
    vdm_DataFunEnd(datafun);
    if (filetype == SYS_LSTC_STATE) {
        vdm_D3DLibEnd(d3dlib);
    }
    else if (filetype == SYS_MARC_POST) {
        vdm_MarcLibEnd(marclib);
    }
    else if (filetype == SYS_ENSIGHT) {
        vdm_EnSightLibEnd(ensightlib);
    }
    return 0;
}

/*----------------------------------------------------------------------
                      print toc
----------------------------------------------------------------------*/
static void
print_toc(vdm_DataFun* datafun)
{
    Vint i;
    vdm_Library* library;
    vdm_Dataset* dataset;
    Vint numdatasets;
    Vchar dsname[DATASET_MAXNAME];
    Vlong lrec;
    Vint nrow, ncol, ntyp;
    Vint type;
    Vfloat* d;

    vdm_DataFunGetLibrary(datafun, &library);
    vdm_LibraryGetNumDatasets(library, &numdatasets);
    /* loop through datasets */
    for (i = 0; i < numdatasets; i++) {
        vdm_LibraryGetDataset(library, i, &dataset);
        vdm_DatasetInq(dataset, dsname, &lrec, &nrow, &ncol, &ntyp);
        printf("\n\nDataset: %s\n", dsname);
        printf("lrec= %lld, nrow= %d, ncol= %d, ntyp= %d\n", lrec, nrow, ncol, ntyp);
        print_attributes(dataset);
        /* library dataset */
        if (ntyp == SYS_NODATATYPE) {
            vdm_DataFunLibDataset(datafun, VDM_LIBDATASET_PUSH, i);
            print_toc(datafun);
            vdm_DataFunLibDataset(datafun, VDM_LIBDATASET_POP, 0);
            /* possible displacement or coordinate result dataset */
        }
        else {
            vdm_DatasetResType(dataset, &type);
            if (type == SYS_RES_X || type == SYS_RES_D) {
                d = (Vfloat*)malloc((size_t)lrec * sizeof(Vfloat));
                vdm_DataFunReadDataset(datafun, i, d);
                printf("d[0]= %e, d[1]= %e, d[2]= %e\n", d[0], d[1], d[2]);
                free(d);
            }
        }
    }
}

/*----------------------------------------------------------------------
                      print dataset attributes
----------------------------------------------------------------------*/
static void
print_attributes(vdm_Dataset* dataset)
{
    int j, k;
    vdm_Attribute* attribute;
    Vint numatts;
    Vint atleng, attype;
    Vchar atname[ATTRIBUTE_MAXNAME];
    Vchar cvalue[ATTRIBUTE_MAXVALUE];
    Vint* ivalue = (Vint*)cvalue;
    Vfloat* rvalue = (Vfloat*)cvalue;
    Vdouble* dvalue = (Vdouble*)cvalue;

    /* loop over attributes */
    vdm_DatasetGetNumAttributes(dataset, &numatts);
    for (j = 0; j < numatts; j++) {
        vdm_DatasetGetAttribute(dataset, j, &attribute);
        vdm_AttributeInq(attribute, atname, &atleng, &attype);
        printf("    Attribute: %s\n               ", atname);
        if (attype == SYS_INTEGER) {
            vdm_AttributeValueInteger(attribute, ivalue);
            for (k = 0; k < atleng; k++)
                printf("%i  ", ivalue[k]);
        }
        else if (attype == SYS_FLOAT) {
            vdm_AttributeValueFloat(attribute, rvalue);
            for (k = 0; k < atleng; k++)
                printf("%e  ", rvalue[k]);
        }
        else if (attype == SYS_CHAR) {
            vdm_AttributeValueString(attribute, cvalue);
            printf("%s  ", cvalue);
        }
        else if (attype == SYS_DOUBLE) {
            vdm_AttributeValueDouble(attribute, dvalue);
            for (k = 0; k < atleng; k++)
                printf("%e  ", dvalue[k]);
        }
        printf("\n");
    }
}

/*----------------------------------------------------------------------
                      print model and coordinates
----------------------------------------------------------------------*/
static void
print_model(vdm_DataFun* datafun)
{
    Vint i, j;
    vdm_Library* library;
    vdm_Dataset* dataset;
    Vchar dsname[DATASET_MAXNAME];
    Vint numdatasets;
    Vlong lrec;
    Vint nrow, ncol, ntyp, type;
    vdm_LMan* lman;
    vis_Model* model;
    vis_Connect* connect;
    vis_GridFun* gridfun;
    vis_State* state;
    vis_RProp* rprop;
    Vint enttype, subtype, numel, numnp;
    Vint id, ndat, nloc, nsec;
    Vfloat d[16];

    /* instance Model object for finite element model */
    model = vis_ModelBegin();
    /* use Library Manager object to load model */
    lman = vdm_LManBegin();
    vdm_LManSetObject(lman, VDM_DATAFUN, datafun);
    vdm_LManLoadModel(lman, model);
    /* get Connect object created in Model */
    vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    printf("numel= %d\n", numel);
    printf("numnp= %d\n", numnp);
    /* create a grid function object */
    gridfun = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gridfun);

    vdm_DataFunGetLibrary(datafun, &library);
    vdm_LibraryGetNumDatasets(library, &numdatasets);
    /* loop through datasets */
    for (i = 0; i < numdatasets; i++) {
        vdm_LibraryGetDataset(library, i, &dataset);
        vdm_DatasetInq(dataset, dsname, &lrec, &nrow, &ncol, &ntyp);
        /* library dataset */
        if (ntyp == SYS_NODATATYPE) {
            printf("\n\nLib Dataset: %s\n", dsname);
            vdm_DataFunLibDataset(datafun, VDM_LIBDATASET_PUSH, i);
            print_model(datafun);
            vdm_DataFunLibDataset(datafun, VDM_LIBDATASET_POP, 0);
            /* possible coordinate dataset */
        }
        else {
            vdm_DatasetResType(dataset, &type);
            vdm_DatasetEntType(dataset, &enttype, &subtype);
            if (enttype != SYS_NODE)
                continue;
            if (type == SYS_RES_X) {
                printf("\n\nCoordinate Dataset: %s\n", dsname);
                state = vis_StateBegin();
                vis_StateSetObject(state, VIS_GRIDFUN, gridfun);
                rprop = vis_RPropBegin();
                vis_RPropDef(rprop, SYS_NODE, SYS_NONE);
                vis_RPropSetDatasetIndex(rprop, i);
                vdm_LManLoadState(lman, state, rprop);
                /* print coordinates for first node */
                id = 1;
                vis_StateDataNum(state, id, &ndat, &nloc, &nsec);
                vis_StateData(state, 1, &id, d);
                printf("node 1, x= ");
                for (j = 0; j < ndat; j++) {
                    printf(" %e", d[j]);
                }
                printf("\n");
                vis_StateEnd(state);
                vis_RPropEnd(rprop);
            }
        }
    }
    vis_ModelDelete(model);
    vis_ModelEnd(model);
    vis_GridFunEnd(gridfun);
    vdm_LManEnd(lman);
}
