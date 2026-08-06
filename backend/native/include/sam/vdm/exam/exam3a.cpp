#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/vis/visdata.h"
#include "sam/vdm/vdm.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static void
print_displacement(vdm_LMan* lman, vdm_Library* library, vis_Model* model);
static void
print_stress(vdm_LMan* lman, vdm_Library* library, vis_Model* model);
static void
print_attributes(vdm_Dataset* dataset);

/*----------------------------------------------------------------------
                     Read and Print Results History Data
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    char inputfile[256];
    Vint filetype;
    vdm_NASLib* naslib = NULL;
    vdm_NatLib* natlib = NULL;
    vdm_SDRCLib* sdrclib = NULL;
    vdm_ANSLib* anslib = NULL;
    vdm_ABALib* abalib = NULL;
    vdm_D3DLib* d3dlib = NULL;
    vdm_DataFun* datafun = NULL;
    vdm_Library* library = NULL;
    vdm_LMan* lman = NULL;
    vis_Model* model = NULL;

    /* check input arguments */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s inputfile\n", argv[0]);
        fprintf(stderr, " inputfile is blank, 'rod.op2' is assumed\n");
        strcpy(inputfile, "rod.op2");
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
    else if (strstr(inputfile, "d3thdt") != NULL) {
        filetype = VDM_LSTC_HISTORY;
        d3dlib = vdm_D3DLibBegin();
        vdm_D3DLibDataFun(d3dlib, datafun);
    }
    else {
        fprintf(stderr, "Error: Bad input file %s\n", inputfile);
        exit(1);
    }
    /* open library device */
    vdm_DataFunOpen(datafun, 0, inputfile, filetype);

    /* instance Model object for finite element model */
    model = vis_ModelBegin();

    /* use Library Manager object to load model */
    lman = vdm_LManBegin();
    vdm_LManSetObject(lman, VDM_DATAFUN, datafun);
    vdm_LManLoadModel(lman, model);

    /* get library object */
    vdm_DataFunGetLibrary(datafun, &library);

    /* access and print displacment history */
    print_displacement(lman, library, model);

    /* access and print stress history */
    print_stress(lman, library, model);

    /* close library device */
    vdm_DataFunClose(datafun);

    /* delete objects in Model created by LManLoadModel */
    vis_ModelDelete(model);

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
    else if (filetype == VDM_LSTC_HISTORY) {
        vdm_D3DLibEnd(d3dlib);
    }
    vdm_LManEnd(lman);
    vis_ModelEnd(model);
    return 0;
}

/*----------------------------------------------------------------------
                      print displacment history
----------------------------------------------------------------------*/
static void
print_displacement(vdm_LMan* lman, vdm_Library* library, vis_Model* model)
{
    Vint i, j, k, n;
    vdm_Dataset* dataset;
    Vchar dsname[DATASET_MAXNAME];
    Vlong lrec;
    Vint nrow, ncol, ntyp;
    Vint numdatasets;
    Vint ndst;
    Vint* idst;
    Vint *inds, *stps;
    Vfloat* tstp;
    Vint nodenumber;
    vis_Connect* connect;
    vis_GridFun* gridfun;
    vis_History* history;
    vis_RProp* rprop;
    Vfloat dvec[6], dmag, rmag;
    Vint nstat, stat[6];
    Vint numstp, nument, enttype, subtype, datatype;
    Vchar indepname[81];
    Vint thermalflag;

    /* query maximum number of datasets */
    vdm_LibraryGetNumDatasets(library, &numdatasets);

    /* allocate array for dataset indices */
    idst = (Vint*)malloc(numdatasets * sizeof(Vint));

    /* search for node history results datasets */
    /* displacement, velocity, accleration */
    thermalflag = 0;
    vdm_LibrarySearchDataset(library, "HIST.D.*N:*", numdatasets, idst, &ndst);
    if (ndst == 0) {
        vdm_LibrarySearchDataset(library, "HIST.V.*N:*", numdatasets, idst, &ndst);
    }
    if (ndst == 0) {
        vdm_LibrarySearchDataset(library, "HIST.A.*N:*", numdatasets, idst, &ndst);
    }
    /* if no displacement, search for temperature */
    if (ndst == 0) {
        thermalflag = 1;
        vdm_LibrarySearchDataset(library, "HIST.TEMP.*N:*", numdatasets, idst, &ndst);
    }
    if (ndst == 0) {
        free(idst);
        return;
    }
    /* get Connect object created in Model */
    vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);

    /* create a grid function object */
    gridfun = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gridfun);

    /* create history */
    history = vis_HistoryBegin();
    vis_HistorySetObject(history, VIS_GRIDFUN, gridfun);

    /* initialize result property object */
    rprop = vis_RPropBegin();
    vis_RPropDef(rprop, SYS_NODE, SYS_NONE);

    /* loop over displacement datasets */
    for (i = 0; i < ndst; i++) {
        vdm_LibraryGetDataset(library, idst[i], &dataset);
        vdm_DatasetInq(dataset, dsname, &lrec, &nrow, &ncol, &ntyp);

        /* print header */
        printf("\n\nDataset: %s\n", dsname);
        if (thermalflag == 0) {
            printf("\nDisplacement History\n");
        }
        else {
            printf("\nTemperature History\n");
        }
        /* load history */
        vis_RPropSetDatasetName(rprop, dsname);
        vdm_LManLoadHistory(lman, history, rprop);

        /* query history for number of steps, indices, etc. */
        vis_HistoryInq(history, &numstp, &nument, &enttype, &subtype, &datatype);

        /* get step numbers */
        stps = (Vint*)malloc(numstp * sizeof(Vint));
        vis_HistorySteps(history, &numstp, stps);

        /* get independent variable */
        tstp = (Vfloat*)malloc(numstp * sizeof(Vfloat));
        vis_HistoryIndepSteps(history, tstp);
        vis_HistoryGetIndepName(history, indepname);

        /* get index numbers */
        inds = (Vint*)malloc(nument * sizeof(Vint));
        vis_HistoryIndices(history, &nument, inds);

        /* loop over nodes */
        for (n = 0; n < nument; n++) {
            vis_ConnectNodeAssoc(connect, VIS_USERID, 1, &inds[n], &nodenumber);
            printf("node= %8d\n", nodenumber);
            /* get defined components and count them */
            vis_HistoryDataStat(history, inds[n], stat);
            nstat = 0;
            for (k = 0; k < nrow; k++) {
                if (stat[k])
                    nstat++;
            }
            if (nstat == 0) {
                printf("No data\n");
                continue;
            }
            /* loop over steps */
            for (j = 0; j < numstp; j++) {
                vis_HistorySetDerive(history, datatype);
                printf("step= %4d", stps[j]);
                if (indepname[0] != '\0') {
                    printf(" %s= %f", indepname, tstp[j]);
                }
                else {
                    printf("\n");
                }
                vis_HistoryData(history, stps[j], 1, &inds[n], dvec);
                /* print only defined datatype components */
                if (nstat != nrow) {
                    for (k = 0; k < nrow; k++) {
                        if (stat[k] == 0) {
                            printf("   no data     ");
                        }
                        else {
                            printf("%14e ", dvec[k]);
                        }
                    }
                    printf("\n");
                    continue;
                }
                /* print complete datatype */
                /* scalar type */
                if (datatype == VIS_SCALAR) {
                    printf("%14e\n", dvec[0]);
                    /* vector type */
                }
                else if (datatype == VIS_VECTOR) {
                    /* print components */
                    printf("%14e %14e %14e", dvec[0], dvec[1], dvec[2]);
                    /* print magnitude */
                    vis_HistorySetDerive(history, VIS_VECTOR_MAG);
                    vis_HistoryData(history, stps[j], 1, &inds[n], &dmag);
                    printf("  mag= %14e\n", dmag);
                    /* six dof vector type */
                }
                else if (datatype == VIS_SIXDOF) {
                    /* print components */
                    printf("%14e %14e %14e %14e %14e %14e", dvec[0], dvec[1], dvec[2], dvec[3], dvec[4], dvec[5]);
                    /* print magnitudes */
                    vis_HistorySetDerive(history, VIS_SIXDOF_TMAG);
                    vis_HistoryData(history, stps[j], 1, &inds[n], &dmag);
                    vis_HistorySetDerive(history, VIS_SIXDOF_RMAG);
                    vis_HistoryData(history, stps[j], 1, &inds[n], &rmag);
                    printf("  mag= %14e %14e\n", dmag, rmag);
                }
            }
        }
        printf("\n");
        free(tstp);
        free(stps);
        free(inds);

        /* print attributes */
        print_attributes(dataset);
    }

    /* free memory */
    vis_GridFunEnd(gridfun);
    vis_HistoryEnd(history);
    vis_RPropEnd(rprop);
    free(idst);
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
    Vint ndst;
    Vint* idst;
    Vint *inds, *stps;
    Vfloat* tstp;
    Vint nix, *ix, *ixd;
    Vint elemnumber;
    Vint i, j, k, m, n;
    vis_Connect* connect;
    vis_GridFun* gridfun;
    vis_History* history;
    vis_RProp* rprop;
    Vint maxelno;
    Vfloat* sten;
    Vint nstat, *stat;
    Vint numstp, nument, enttype, subtype, datatype;
    Vchar indepname[81];
    Vint thermalflag;

    /* determine maximum number of datasets */
    vdm_LibraryGetNumDatasets(library, &numdatasets);

    /* allocate array for dataset indices */
    idst = (Vint*)malloc(numdatasets * sizeof(Vint));

    /* search for stress,strain results datasets */
    thermalflag = 0;
    subtype = SYS_NODE;
    vdm_LibrarySearchDataset(library, "HIST.S*.*EL:*", numdatasets, idst, &ndst);
    if (ndst == 0) {
        vdm_LibrarySearchDataset(library, "HIST.E*.*EL:*", numdatasets, idst, &ndst);
    }
    if (ndst == 0) {
        thermalflag = 1;
        subtype = SYS_NONE;
        vdm_LibrarySearchDataset(library, "HIST.HEAT_FLUX.*E:*", numdatasets, idst, &ndst);
    }
    if (ndst == 0) {
        free(idst);
        return;
    }
    /* get Connect object created in Model */
    vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);

    /* find maximum number of element nodes */
    vis_ConnectMaxElemNode(connect, &maxelno);
    /* allocate arrays for maximum element node stress data */
    sten = (Vfloat*)malloc(maxelno * 6LL * sizeof(Vfloat));
    stat = (Vint*)malloc(maxelno * 6LL * sizeof(Vint));
    /* allocate arrays for maximum element node connectivity */
    ix = (Vint*)malloc(maxelno * sizeof(Vint));
    ixd = (Vint*)malloc(maxelno * sizeof(Vint));

    /* create a grid function object */
    gridfun = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gridfun);

    /* create history and install GridFun object */
    history = vis_HistoryBegin();
    vis_HistorySetObject(history, VIS_GRIDFUN, gridfun);

    /* initialize result property object */
    rprop = vis_RPropBegin();
    vis_RPropDef(rprop, SYS_ELEM, subtype);

    /* loop over stress datasets */
    for (i = 0; i < ndst; i++) {
        vdm_LibraryGetDataset(library, idst[i], &dataset);
        vdm_DatasetInq(dataset, dsname, &lrec, &nrow, &ncol, &ntyp);

        /* print header */
        printf("\n\nDataset: %s\n", dsname);
        if (thermalflag == 0) {
            printf("\nStress History\n");
        }
        else {
            printf("\nHeat Flux History\n");
        }

        vis_RPropSetDatasetName(rprop, dsname);
        vdm_LManLoadHistory(lman, history, rprop);

        /* query history for number of steps, indices, etc. */
        vis_HistoryInq(history, &numstp, &nument, &enttype, &subtype, &datatype);

        /* get step numbers */
        stps = (Vint*)malloc(numstp * sizeof(Vint));
        vis_HistorySteps(history, &numstp, stps);

        /* get independent variable */
        tstp = (Vfloat*)malloc(numstp * sizeof(Vfloat));
        vis_HistoryIndepSteps(history, tstp);
        vis_HistoryGetIndepName(history, indepname);

        /* get index numbers */
        inds = (Vint*)malloc(nument * sizeof(Vint));
        vis_HistoryIndices(history, &nument, inds);

        /* loop over elements */
        for (n = 0; n < nument; n++) {
            vis_ConnectElemAssoc(connect, VIS_USERID, 1, &inds[n], &elemnumber);
            printf("elem= %8d\n", elemnumber);
            /* single node or element value */
            if (subtype == SYS_NONE) {
                nix = 1;
                /* get nodes in element and query user node ids */
            }
            else {
                vis_ConnectElemNode(connect, inds[n], &nix, ix);
                vis_ConnectNodeAssoc(connect, VIS_USERID, nix, ix, ixd);
            }
            /* get defined components and count them */
            vis_HistoryDataStat(history, inds[n], stat);
            nstat = 0;
            for (k = 0; k < nrow * nix; k++) {
                if (stat[k])
                    nstat++;
            }
            if (nstat == 0) {
                printf("No data\n");
                continue;
            }
            /* loop over steps */
            for (j = 0; j < numstp; j++) {
                vis_HistorySetDerive(history, datatype);
                printf("step= %4d", stps[j]);
                if (indepname[0] != '\0') {
                    printf(" %s= %f\n", indepname, tstp[j]);
                }
                else {
                    printf("\n");
                }
                vis_HistoryData(history, stps[j], 1, &inds[n], (Vfloat*)sten);

                /* node or element */
                if (subtype == SYS_NONE) {
                    for (k = 0; k < nrow; k++) {
                        if (stat[k] == 0) {
                            printf("  no data    ");
                        }
                        else {
                            printf("%12.5e ", sten[k]);
                        }
                    }
                    printf("\n");
                    /* element node */
                }
                else {
                    for (m = 0; m < nix; m++) {
                        printf(" %8d ", ixd[m]);
                        for (k = 0; k < nrow; k++) {
                            if (stat[m * nrow + k] == 0) {
                                printf("  no data    ");
                            }
                            else {
                                printf("%12.5e ", sten[m * nrow + k]);
                            }
                        }
                        printf("\n");
                    }
                }
            }
        }
        printf("\n");
        free(tstp);
        free(stps);
        free(inds);
        /* print attributes */
        print_attributes(dataset);
    }
    /* free memory */
    vis_GridFunEnd(gridfun);
    vis_HistoryEnd(history);
    vis_RPropEnd(rprop);
    free(idst);
    free(sten);
    free(stat);
    free(ix);
    free(ixd);
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
