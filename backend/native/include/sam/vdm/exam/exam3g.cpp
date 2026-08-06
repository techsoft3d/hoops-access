#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/vis/visdata.h"
#include "sam/vdm/vdm.h"
#include "sam/vdm/datafile.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static void
print_displacement(vdm_LMan* lman, vdm_Library* library, vis_Model* model);

static void
print_temp_gradient(vdm_LMan* lman, vdm_Library* library, vis_Model* model);
static void
print_stress(vdm_LMan* lman, vdm_Library* library, vis_Model* model);
static void
print_result(vdm_LMan* lman, vdm_Library* library, vis_Model* model);
static void
print_section(Vint lpos, Vint isec);
static void
print_attributes(vdm_Dataset* dataset);

/*----------------------------------------------------------------------
                     Read and Print Results State Data
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
        fprintf(stderr, " inputfile is blank, 'cantilever.unv' is assumed\n");
        strcpy(inputfile, "cantilever.unv");
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
        vdm_DataFunClose(datafun);
        datafileterm(filetype, datafun);
        vdm_DataFunEnd(datafun);
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

    /* access and print displacments */
    print_displacement(lman, library, model);
    /* access and print temperature gradients */
    print_temp_gradient(lman, library, model);

    /* access and print stresses */
    print_stress(lman, library, model);
    /* access and print all results */
    print_result(lman, library, model);

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
                      print displacments
----------------------------------------------------------------------*/
static void
print_displacement(vdm_LMan* lman, vdm_Library* library, vis_Model* model)
{
    vdm_Dataset* dataset;
    Vchar dsname[DATASET_MAXNAME];
    Vlong lrec;
    Vint nrow, ncol, ntyp;
    Vint numdatasets;
    Vint ndst_d;
    Vint* idst_d;
    Vint numids, ids[3];
    Vint numnp, nodenumber;
    Vint cid;
    Vint i, n;
    vis_Connect* connect;
    vsy_HashTable* hashcsys;
    vis_IdTran* idtrannsys;
    vis_GridFun* gridfun;
    vis_State* state;
    vis_RProp* rprop;
    Vfloat dvec[6], dmag, rmag;
    Vint nument, enttype, subtype, datatype;
    Vint system;
    Vint thermalflag;

    /* determine maximum number of datasets */
    vdm_LibraryGetNumDatasets(library, &numdatasets);

    /* allocate array for dataset indices */
    idst_d = (Vint*)malloc(numdatasets * sizeof(Vint));

    /* search for displacement results datasets */
    thermalflag = 0;
    vdm_LibrarySearchDataset(library, "D.*N:*", numdatasets, idst_d, &ndst_d);
    /* if no displacement, search for temperature */
    if (ndst_d == 0) {
        thermalflag = 1;
        vdm_LibrarySearchDataset(library, "TEMP.*N:*", numdatasets, idst_d, &ndst_d);
    }

    if (ndst_d == 0) {
        free(idst_d);
        return;
    }
    /* get Connect object created in Model */
    vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);
    vis_ConnectNumber(connect, SYS_NODE, &numnp);

    /* create a grid function object */
    gridfun = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gridfun);

    /* get HashTable of CoordSys objects */
    vis_ModelGetHashTable(model, VIS_COORDSYS, &hashcsys);

    /* install coordinate system ids into IdTran object */
    idtrannsys = vis_IdTranBegin();
    vis_IdTranDef(idtrannsys, numnp);
    for (i = 1; i <= numnp; i++) {
        vis_ConnectNodeAssoc(connect, VIS_CSYSID, 1, &i, &cid);
        vis_IdTranSetId(idtrannsys, i, cid);
    }
    /* create state */
    state = vis_StateBegin();

    /* initialize result property object */
    rprop = vis_RPropBegin();
    vis_RPropDef(rprop, SYS_NODE, SYS_NONE);

    /* print first, middle and last node */
    numids = 3;
    ids[0] = 1;
    ids[1] = numnp / 2;
    ids[2] = numnp;

    /* loop over displacement datasets */
    for (i = 0; i < ndst_d; i++) {
        vdm_LibraryGetDataset(library, idst_d[i], &dataset);
        vdm_DatasetInq(dataset, dsname, &lrec, &nrow, &ncol, &ntyp);

        /* print header */
        printf("\n\nDataset: %s\n", dsname);
        if (thermalflag == 0) {
            printf("\nDisplacements\n");
        }
        else {
            printf("\nTemperatures\n");
        }

        /* load state */
        vis_RPropSetDatasetIndex(rprop, idst_d[i]);
        vdm_LManLoadState(lman, state, rprop);
        vis_StateInq(state, &nument, &enttype, &subtype, &datatype);

        /* loop over requested nodes */
        for (n = 0; n < numids; n++) {
            if (ids[n] == 0)
                continue;
            vis_ConnectNodeAssoc(connect, VIS_USERID, 1, &ids[n], &nodenumber);
            printf("%8d", nodenumber);
            vis_StateSetDerive(state, datatype);

            if (datatype == VIS_SCALAR) {
                vis_StateData(state, 1, &ids[n], dvec);
                printf("%14e\n", dvec[0]);
                /* vector type */
            }
            else if (datatype == VIS_VECTOR) {
                /* print components */
                vis_StateData(state, 1, &ids[n], dvec);
                printf("%14e %14e %14e", dvec[0], dvec[1], dvec[2]);
                /* print magnitude */
                vis_StateSetDerive(state, VIS_VECTOR_MAG);
                vis_StateData(state, 1, &ids[n], &dmag);
                printf("  magnitude= %14e\n", dmag);
                /* six dof vector type */
            }
            else if (datatype == VIS_SIXDOF) {
                /* print components */
                vis_StateData(state, 1, &ids[n], dvec);
                printf("%14e %14e %14e  %14e %14e %14e", dvec[0], dvec[1], dvec[2], dvec[3], dvec[4], dvec[5]);
                /* print magnitudes */
                vis_StateSetDerive(state, VIS_SIXDOF_TMAG);
                vis_StateData(state, 1, &ids[n], &dmag);
                vis_StateSetDerive(state, VIS_SIXDOF_RMAG);
                vis_StateData(state, 1, &ids[n], &rmag);
                printf("  magnitudes= %14e %14e\n", dmag, rmag);
            }
        }
        printf("\n");

        /* print global components if originally local components */

        /* the system is set in State by LManLoadState */
        vis_StateGetSystem(state, &system);
        if (system == STATE_LOCAL) {
            vis_StateSetObject(state, VIS_GRIDFUN, gridfun);
            vis_StateSetHashTable(state, VIS_COORDSYS, hashcsys);
            vis_StateSetObject(state, VIS_IDTRAN, idtrannsys);
            vis_StateTransform(state, STATE_GLOBAL, NULL);
            /* loop over requested nodes */
            vis_StateSetDerive(state, datatype);
            printf("global system\n");
            for (n = 0; n < numids; n++) {
                if (ids[n] == 0)
                    continue;
                vis_ConnectNodeAssoc(connect, VIS_USERID, 1, &ids[n], &nodenumber);
                printf("%8d", nodenumber);
                /* vector type */
                if (datatype == VIS_VECTOR) {
                    vis_StateData(state, 1, &ids[n], dvec);
                    printf("%14e %14e %14e\n", dvec[0], dvec[1], dvec[2]);
                    /* six dof vector type */
                }
                else if (datatype == VIS_SIXDOF) {
                    vis_StateData(state, 1, &ids[n], dvec);
                    printf("%14e %14e %14e  %14e %14e %14e\n", dvec[0], dvec[1], dvec[2], dvec[3], dvec[4], dvec[5]);
                }
            }
            printf("\n");
        }
        /* print attributes */
        print_attributes(dataset);
    }

    /* free memory */
    vis_GridFunEnd(gridfun);
    vis_IdTranEnd(idtrannsys);
    vis_StateEnd(state);
    vis_RPropEnd(rprop);
    free(idst_d);
}

/*----------------------------------------------------------------------
                      load element coordinate system indices
----------------------------------------------------------------------*/
static void
load_idtrancid(vdm_LMan* lman, vdm_Library* library, vis_RProp* rprop, vis_IdTran* idtrancid)
{
    Vint m;
    Vchar cidname[DATASET_MAXNAME];
    Vint ids, nds;
    vdm_Dataset* dataset;
    vdm_DataFun* datafun;
    Vint ncol;
    Vint* pcid;
    /* get name of coordinate system id dataset */
    vis_RPropValueString(rprop, RPROP_LINK_CID, cidname);
    /* find dataset */
    vdm_LibrarySearchDataset(library, cidname, 1, &ids, &nds);
    vdm_LibraryGetDataset(library, ids, &dataset);
    vdm_DatasetGetNCol(dataset, &ncol);
    vdm_LManGetObject(lman, VDM_DATAFUN, (Vobject**)&datafun);
    pcid = (Vint*)malloc(ncol * sizeof(Vint));
    vdm_DataFunReadDataset(datafun, ids, pcid);
    for (m = 1; m <= ncol; m++) {
        vis_IdTranSetId(idtrancid, m, pcid[m - 1]);
    }
    free(pcid);
}

/*----------------------------------------------------------------------
                      load rotation angle vector
----------------------------------------------------------------------*/
static void
load_staterotang(vdm_LMan* lman, vdm_Library* library, vis_RProp* rprop, vis_State* staterotang)
{
    Vchar raname[DATASET_MAXNAME];
    Vint ids, nds;
    vdm_Dataset* dataset;
    vis_RProp* rproprotang;
    Vint enttype, subtype;
    /* get name of rotation angle dataset */
    vis_RPropValueString(rprop, RPROP_LINK_ROTANG, raname);
    /* find dataset */
    vdm_LibrarySearchDataset(library, raname, 1, &ids, &nds);
    vdm_LibraryGetDataset(library, ids, &dataset);
    vdm_DatasetEntType(dataset, &enttype, &subtype);
    /* read rotation angles */
    rproprotang = vis_RPropBegin();
    vis_RPropDef(rproprotang, enttype, subtype);
    vis_RPropSetDatasetIndex(rproprotang, ids);
    vdm_LManLoadState(lman, staterotang, rproprotang);
    vis_RPropEnd(rproprotang);
}

/*----------------------------------------------------------------------
                      print temperature gradients
----------------------------------------------------------------------*/
static void
print_temp_gradient(vdm_LMan* lman, vdm_Library* library, vis_Model* model)
{
    vdm_Dataset* dataset;
    Vchar dsname[DATASET_MAXNAME];
    Vlong lrec;
    Vint nrow, ncol, ntyp;
    Vint numdatasets;
    Vint ndst_d;
    Vint* idst_d;
    Vint numids, ids[3];
    Vint numel, elemnumber;
    Vint i, n;
    vis_Connect* connect;
    vsy_HashTable *hashcsys, *hasheldt;
    vis_IdTran* idtranesys;
    vis_GridFun* gridfun;
    vis_State* state;
    vis_RProp* rprop;
    Vfloat dvec[3], dmag;
    Vint system;

    /* determine maximum number of datasets */
    vdm_LibraryGetNumDatasets(library, &numdatasets);

    /* allocate array for dataset indices */
    idst_d = (Vint*)malloc(numdatasets * sizeof(Vint));

    /* search for temp gradient results datasets */
    vdm_LibrarySearchDataset(library, "TEMP_GRAD.*E:*", numdatasets, idst_d, &ndst_d);

    if (ndst_d == 0) {
        free(idst_d);
        return;
    }
    /* get Connect object created in Model */
    vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);

    /* create a grid function object */
    gridfun = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gridfun);

    /* get HashTable of CoordSys objects */
    vis_ModelGetHashTable(model, VIS_COORDSYS, &hashcsys);
    /* get HashTable of ElemDat objects */
    vis_ModelGetHashTable(model, VIS_ELEMDAT, &hasheldt);

    /* coordinate system ids */
    idtranesys = vis_IdTranBegin();
    vis_IdTranDef(idtranesys, numel);

    /* create state */
    state = vis_StateBegin();

    /* initialize result property object */
    rprop = vis_RPropBegin();
    vis_RPropDef(rprop, SYS_ELEM, SYS_NONE);

    /* print first, middle and last element */
    numids = 3;
    ids[0] = 1;
    ids[1] = numel / 2;
    ids[2] = numel;

    /* loop over datasets */
    for (i = 0; i < ndst_d; i++) {
        vdm_LibraryGetDataset(library, idst_d[i], &dataset);
        vdm_DatasetInq(dataset, dsname, &lrec, &nrow, &ncol, &ntyp);

        /* print header */
        printf("\n\nDataset: %s\n", dsname);
        printf("\nTemperature Gradients\n");

        /* load state */
        vis_RPropSetDatasetIndex(rprop, idst_d[i]);
        vdm_LManLoadState(lman, state, rprop);

        /* loop over requested elements */
        for (n = 0; n < numids; n++) {
            if (ids[n] == 0)
                continue;
            vis_ConnectElemAssoc(connect, VIS_USERID, 1, &ids[n], &elemnumber);
            printf("%8d %8d", ids[n], elemnumber);
            vis_StateSetDerive(state, VIS_VECTOR);
            /* print components */
            vis_StateData(state, 1, &ids[n], dvec);
            printf("%14e %14e %14e", dvec[0], dvec[1], dvec[2]);
            /* print magnitude */
            vis_StateSetDerive(state, VIS_VECTOR_MAG);
            vis_StateData(state, 1, &ids[n], &dmag);
            printf("  magnitude= %14e\n", dmag);
        }
        printf("\n");

        /* print global components if originally local components */

        /* the system is set in State by LManLoadState */
        vis_StateGetSystem(state, &system);
        if (system == STATE_LOCAL) {
            vis_StateSetObject(state, VIS_GRIDFUN, gridfun);
            vis_StateSetHashTable(state, VIS_COORDSYS, hashcsys);
            vis_StateSetHashTable(state, VIS_ELEMDAT, hasheldt);
            load_idtrancid(lman, library, rprop, idtranesys);
            vis_StateSetObject(state, VIS_IDTRAN, idtranesys);
            vis_StateTransform(state, STATE_GLOBAL, NULL);
            /* loop over requested elements */
            vis_StateSetDerive(state, VIS_VECTOR);
            printf("global system\n");
            for (n = 0; n < numids; n++) {
                if (ids[n] == 0)
                    continue;
                vis_ConnectElemAssoc(connect, VIS_USERID, 1, &ids[n], &elemnumber);
                printf("%8d %8d", ids[n], elemnumber);
                vis_StateData(state, 1, &ids[n], dvec);
                printf("%14e %14e %14e\n", dvec[0], dvec[1], dvec[2]);
            }
            printf("\n");
        }
        /* print attributes */
        print_attributes(dataset);
    }

    /* free memory */
    vis_GridFunEnd(gridfun);
    vis_IdTranEnd(idtranesys);
    vis_StateEnd(state);
    vis_RPropEnd(rprop);
    free(idst_d);
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
    Vint nds, ndst_s;
    Vint* idst_s = NULL;
    Vint numids, ids[3];
    Vint nix;
    Vint numel, maxelno, elemnumber, complexmode;
    Vint i, j, n;
    vis_Connect* connect = NULL;
    vsy_HashTable *hashcsys = NULL, *hasheldt = NULL, *hasheprop = NULL;
    vis_IdTran* idtranesys = NULL;
    vis_GridFun* gridfun = NULL;
    vis_State* state = NULL;
    vis_State* staterotang = NULL;
    vis_RProp* rprop = NULL;
    Vfloat(*sten)[6], *smean = NULL, (*cten)[12];
    Vint system;
    Vint enttype, subtype;

    /* determine maximum number of datasets */
    vdm_LibraryGetNumDatasets(library, &numdatasets);

    /* allocate array for dataset indices */
    idst_s = (Vint*)malloc(numdatasets * sizeof(Vint));

    /* search for stress results datasets */
    vdm_LibrarySearchDataset(library, "S.*EL:*", numdatasets, idst_s, &nds);
    vdm_LibrarySearchDataset(library, "S.*E:*", numdatasets, &idst_s[nds], &ndst_s);
    ndst_s += nds;
    if (ndst_s == 0) {
        free(idst_s);
        return;
    }
    /* get Connect object created in Model */
    vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);

    /* find maximum number of element nodes */
    vis_ConnectMaxElemNode(connect, &maxelno);

    /* allocate arrays to fit maximum element node data */
    sten = (Vfloat(*)[6])malloc(2 * maxelno * 6 * sizeof(Vfloat));
    cten = (Vfloat(*)[12])sten;
    smean = (Vfloat*)malloc(maxelno * sizeof(Vfloat));

    /* create a grid function object */
    gridfun = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gridfun);

    /* get HashTable of CoordSys objects */
    vis_ModelGetHashTable(model, VIS_COORDSYS, &hashcsys);
    /* get HashTable of ElemDat objects */
    vis_ModelGetHashTable(model, VIS_ELEMDAT, &hasheldt);
    /* get HashTable of EProp objects */
    vis_ModelGetHashTable(model, VIS_EPROP, &hasheprop);

    /* element coordinate system ids into IdTran object */
    idtranesys = vis_IdTranBegin();
    vis_IdTranDef(idtranesys, numel);

    /* create state and install GridFun object */
    state = vis_StateBegin();
    vis_StateSetObject(state, VIS_GRIDFUN, gridfun);

    /* instance result property object */
    rprop = vis_RPropBegin();

    /* print first, middle and last element */
    numids = 3;
    ids[0] = 1;
    ids[1] = numel / 2;
    ids[2] = numel;
    /* loop over stress datasets */
    for (i = 0; i < ndst_s; i++) {
        vdm_LibraryGetDataset(library, idst_s[i], &dataset);
        vdm_DatasetInq(dataset, dsname, &lrec, &nrow, &ncol, &ntyp);
        if (nrow != 6)
            continue;
        vdm_DatasetEntType(dataset, &enttype, &subtype);

        /* print header */
        printf("\n\nDataset: %s\n", dsname);
        printf("\nStresses\n");

        /* set entity type and dataset index */
        vis_RPropDef(rprop, enttype, subtype);
        vis_RPropSetDatasetIndex(rprop, idst_s[i]);
        /* load state */
        vdm_LManLoadState(lman, state, rprop);
        vis_StateGetComplexMode(state, &complexmode);

        /* print stress components first */
        vis_StateSetDerive(state, VIS_TENSOR);

        /* loop over requested elements */
        for (n = 0; n < numids; n++) {
            if (ids[n] == 0)
                continue;
            vis_ConnectElemAssoc(connect, VIS_USERID, 1, &ids[n], &elemnumber);
            printf("%8d, component stresses\n", elemnumber);

            nix = 1;
            /* if element node get number of nodes */
            if (subtype == SYS_NODE) {
                vis_ConnectElemNum(connect, SYS_NODE, ids[n], &nix);
            }
            vis_StateData(state, 1, &ids[n], (Vfloat*)sten);

            /* loop over nodes in element */
            for (j = 0; j < nix; j++) {
                if (complexmode == SYS_COMPLEX_REAL) {
                    printf(" %12.5e %12.5e %12.5e %12.5e %12.5e %12.5e\n", sten[j][0], sten[j][1], sten[j][2], sten[j][3],
                           sten[j][4], sten[j][5]);
                }
                else {
                    printf(" %12.5e %12.5e(i) %12.5e %12.5e(i) %12.5e %12.5e(i)\n", cten[j][0], cten[j][1], cten[j][2],
                           cten[j][3], cten[j][4], cten[j][5]);
                    printf(" %12.5e %12.5e(i) %12.5e %12.5e(i) %12.5e %12.5e(i)\n", cten[j][6], cten[j][7], cten[j][8],
                           cten[j][9], cten[j][10], cten[j][11]);
                }
            }
        }
        /* skip derived quantities if complex data */
        if (complexmode != SYS_COMPLEX_REAL)
            continue;
        /* print mean stress second */
        vis_StateSetDerive(state, VIS_TENSOR_MEAN);

        /* loop over requested elements */
        for (n = 0; n < numids; n++) {
            if (ids[n] == 0)
                continue;
            vis_ConnectElemAssoc(connect, VIS_USERID, 1, &ids[n], &elemnumber);
            printf("%8d, mean stress\n", elemnumber);

            nix = 1;
            /* if element node get number of nodes */
            if (subtype == SYS_NODE) {
                vis_ConnectElemNum(connect, SYS_NODE, ids[n], &nix);
            }
            vis_StateData(state, 1, &ids[n], smean);

            /* loop over nodes in element */
            for (j = 0; j < nix; j++) {
                printf(" %12.5e\n", smean[j]);
            }
        }
        printf("\n");
        vis_StateSetDerive(state, VIS_TENSOR);

        /* print stress in global if originally in local */
        /* the system is set in State by LManLoadState */
        vis_StateGetSystem(state, &system);
        if (system == STATE_LOCAL || system == STATE_ROTANG) {
            vis_StateSetObject(state, VIS_GRIDFUN, gridfun);
            if (system == STATE_LOCAL) {
                vis_StateSetHashTable(state, VIS_COORDSYS, hashcsys);
                vis_StateSetHashTable(state, VIS_ELEMDAT, hasheldt);
                load_idtrancid(lman, library, rprop, idtranesys);
                vis_StateSetObject(state, VIS_IDTRAN, idtranesys);
            }
            else if (system == STATE_ROTANG) {
                staterotang = vis_StateBegin();
                vis_StateSetObject(staterotang, VIS_GRIDFUN, gridfun);
                load_staterotang(lman, library, rprop, staterotang);
                vis_StateSetObject(state, VIS_STATE_ROTANG, staterotang);
            }
            vis_StateTransform(state, STATE_GLOBAL, NULL);
            printf("global system\n");

            /* loop over requested elements */
            for (n = 0; n < numids; n++) {
                if (ids[n] == 0)
                    continue;
                vis_ConnectElemAssoc(connect, VIS_USERID, 1, &ids[n], &elemnumber);
                printf("%8d, component stresses\n", elemnumber);

                nix = 1;
                /* if element node get number of nodes */
                if (subtype == SYS_NODE) {
                    vis_ConnectElemNum(connect, SYS_NODE, ids[n], &nix);
                }
                vis_StateData(state, 1, &ids[n], (Vfloat*)sten);

                /* loop over nodes in element */
                for (j = 0; j < nix; j++) {
                    printf(" %12.5e %12.5e %12.5e %12.5e %12.5e %12.5e\n", sten[j][0], sten[j][1], sten[j][2], sten[j][3],
                           sten[j][4], sten[j][5]);
                }
            }
        }
        printf("\n");
        if (system == STATE_ROTANG) {
            vis_StateEnd(staterotang);
        }
        /* print in material system */
        vis_StateSetHashTable(state, VIS_COORDSYS, hashcsys);
        vis_StateSetHashTable(state, VIS_ELEMDAT, hasheldt);
        vis_StateSetObject(state, VIS_IDTRAN, NULL);
        vis_StateTransform(state, STATE_MATERIAL, NULL);
        if (vis_StateError(state))
            continue;
        /* loop over requested elements */
        printf("material system\n");
        for (n = 0; n < numids; n++) {
            if (ids[n] == 0)
                continue;
            vis_ConnectElemAssoc(connect, VIS_USERID, 1, &ids[n], &elemnumber);
            printf("%8d, component stresses\n", elemnumber);

            nix = 1;
            /* if element node get number of nodes */
            if (subtype == SYS_NODE) {
                vis_ConnectElemNum(connect, SYS_NODE, ids[n], &nix);
            }
            vis_StateData(state, 1, &ids[n], (Vfloat*)sten);

            /* loop over nodes in element */
            for (j = 0; j < nix; j++) {
                printf(" %12.5e %12.5e %12.5e %12.5e %12.5e %12.5e\n", sten[j][0], sten[j][1], sten[j][2], sten[j][3], sten[j][4],
                       sten[j][5]);
            }
        }
        /* print attributes */
        print_attributes(dataset);
    }
    /* free memory */
    vis_GridFunEnd(gridfun);
    vis_IdTranEnd(idtranesys);
    vis_StateEnd(state);
    vis_RPropEnd(rprop);
    free(idst_s);
    free(sten);
    free(smean);
}

/*----------------------------------------------------------------------
                      print link to section, layers
----------------------------------------------------------------------*/
static void
print_linksection(vdm_LMan* lman, vdm_Library* library, vdm_Dataset* dataset)
{
    Vint i, m;
    Vint iat, nat, iatl, natl;
    vdm_Attribute* attribute = NULL;
    vdm_Dataset *datasetsect = NULL, *datasetlays = NULL;
    Vint idssect, ndssect;
    Vint idslays, ndslays, ind;
    Vint ipos, ilay;
    Vint *psec = NULL, *play = NULL;
    Vchar dsname[DATASET_MAXNAME];
    Vchar cvalue[ATTRIBUTE_MAXVALUE];
    Vlong lrec, lreclays;
    Vint nrow, ncol, ntyp;
    vdm_DataFun* datafun = NULL;
    Vint lpos, nsec;
    static const Vchar* lposnames[12] = {"Sec", "Mid", "BT ", "BMT", "Ipt", "BM ", "MT ", "Bot", "Top", "B1M", "M1T", "B5T"};
    /* look for Link to Section */
    vdm_DatasetSearchAttribute(dataset, (Vchar*)"Link.Section", 1, &iat, &nat);
    if (nat == 0)
        return;
    /* look for Link to Layers */
    vdm_DatasetSearchAttribute(dataset, (Vchar*)"Link.Layers", 1, &iatl, &natl);
    /* read section dataset */
    vdm_DatasetGetAttribute(dataset, iat, &attribute);
    vdm_AttributeValueString(attribute, cvalue);
    vdm_LibrarySearchDataset(library, cvalue, 1, &idssect, &ndssect);
    vdm_LibraryGetDataset(library, idssect, &datasetsect);
    vdm_DatasetInq(datasetsect, dsname, &lrec, &nrow, &ncol, &ntyp);
    psec = (Vint*)malloc(ncol * sizeof(Vint));
    vdm_LManGetObject(lman, VDM_DATAFUN, (Vobject**)&datafun);
    vdm_DataFunReadDataset(datafun, idssect, psec);
    /* read layers dataset */
    if (natl) {
        vdm_DatasetGetAttribute(dataset, iatl, &attribute);
        vdm_AttributeValueString(attribute, cvalue);
        vdm_LibrarySearchDataset(library, cvalue, 1, &idslays, &ndslays);
        vdm_LibraryGetDataset(library, idslays, &datasetlays);
        vdm_DatasetGetLRec(datasetlays, &lreclays);
        play = (Vint*)malloc(lreclays * sizeof(Vint));
        vdm_DataFunReadDataset(datafun, idslays, play);
    }
    /* print first element with 2 or more sections */
    /* loop over elements */
    ind = 0;
    for (m = 0; m < ncol; m++) {
        lpos = (psec[m] >> 24) & 0xff;
        nsec = psec[m] & 0xffffff;
        if (nsec >= 2) {
            printf("Section information\n");
            printf("elem= %d, nsec= %d\n", m + 1, nsec);
            for (i = 0; i < nsec; i++) {
                if (natl == 0) {
                    if (lpos == SYS_LAYERPOSITION_BOTTOP) {
                        if (i % 2 == 0) {
                            ipos = SYS_LAYERPOSITION_BOT;
                        }
                        else {
                            ipos = SYS_LAYERPOSITION_TOP;
                        }
                        ilay = i / 2 + 1;
                    }
                    else if (lpos == SYS_LAYERPOSITION_BOTMID) {
                        if (i % 2 == 0) {
                            ipos = SYS_LAYERPOSITION_BOT;
                        }
                        else {
                            ipos = SYS_LAYERPOSITION_MID;
                        }
                        ilay = i / 2 + 1;
                    }
                    else if (lpos == SYS_LAYERPOSITION_MIDTOP) {
                        if (i % 2 == 0) {
                            ipos = SYS_LAYERPOSITION_MID;
                        }
                        else {
                            ipos = SYS_LAYERPOSITION_TOP;
                        }
                        ilay = i / 2 + 1;
                    }
                    else if (lpos == SYS_LAYERPOSITION_BOTMIDTOP) {
                        if (i % 3 == 0) {
                            ipos = SYS_LAYERPOSITION_BOT;
                        }
                        else if (i % 3 == 1) {
                            ipos = SYS_LAYERPOSITION_MID;
                        }
                        else {
                            ipos = SYS_LAYERPOSITION_TOP;
                        }
                        ilay = i / 3 + 1;
                    }
                    else if (lpos == SYS_LAYERPOSITION_B5T) {
                        if (i % 5 == 0) {
                            ipos = SYS_LAYERPOSITION_BOT;
                        }
                        else if (i % 5 == 1) {
                            ipos = SYS_LAYERPOSITION_B1M;
                        }
                        else if (i % 5 == 2) {
                            ipos = SYS_LAYERPOSITION_MID;
                        }
                        else if (i % 5 == 3) {
                            ipos = SYS_LAYERPOSITION_M1T;
                        }
                        else {
                            ipos = SYS_LAYERPOSITION_TOP;
                        }
                        ilay = i / 5 + 1;
                    }
                    else {
                        ipos = lpos;
                        ilay = i + 1;
                    }
                }
                else {
                    ipos = (play[ind + i] >> 24) & 0xff;
                    ilay = play[ind + i] & 0xffffff;
                }
                printf("section= %d, layer= %d, position= %s\n", i + 1, ilay, lposnames[ipos]);
            }
            break;
        }
        ind += nsec;
    }
    free(psec);
    if (natl) {
        free(play);
    }
}

/*----------------------------------------------------------------------
                      print result
----------------------------------------------------------------------*/
static void
print_result(vdm_LMan* lman, vdm_Library* library, vis_Model* model)
{
    Vint i, j, k, n;
    vdm_Dataset* dataset;
    Vchar dsname[DATASET_MAXNAME];
    Vchar dsroot[DATASET_MAXNAME];
    Vchar caux[DATASET_MAXNAME];
    Vchar dime[DATASET_MAXNAME];
    Vchar andata[ATTRIBUTE_MAXVALUE];
    Vchar ancont[ATTRIBUTE_MAXVALUE];
    Vlong lrec;
    Vint nrow, ncol, ntyp;
    Vint numdatasets;
    Vint index, id = 0, elnoid;
    Vint maxelno, nix, *ix;
    vis_Connect* connect;
    vis_GridFun* gridfun;
    vis_State* state;
    vis_RProp* rprop;
    Vint type, hist, cplx, sect, nument, enttype, subtype, datatype;
    Vint nqua, iqua[SYS_NQUA_MAX];
    Vchar cqua[DATASET_MAXNAME];
    Vint id1, id2, id3;
    Vint system, flag, stat;
    Vint ncmp, nsec;
    Vfloat* res;
    Vint *pos, *lay;
    Vint mres, msec, maxdat, maxloc, maxsec;
    Vint numno, ne[VIS_MAX_MAXJ];

    /* determine maximum number of datasets */
    vdm_LibraryGetNumDatasets(library, &numdatasets);

    /* get Connect object created in Model */
    vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);

    /* find maximum number of element nodes */
    vis_ConnectMaxElemNode(connect, &maxelno);

    /* allocate connectivity array to fit maximum number */
    ix = (Vint*)malloc(maxelno * sizeof(Vint));

    /* create a grid function object */
    gridfun = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gridfun);

    /* create state and install GridFun object */
    state = vis_StateBegin();
    vis_StateSetObject(state, VIS_GRIDFUN, gridfun);

    /* create result property object */
    rprop = vis_RPropBegin();

    /* pointer for returned results data */
    res = NULL;
    pos = NULL;
    lay = NULL;
    mres = 0;
    msec = 0;
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

        /* get DataType attribute */
        vdm_DatasetDataType(dataset, andata, &datatype);

        /* get Contents attribute */
        vdm_DatasetContents(dataset, ancont);

        /* get result physical dimensions */
        vdm_DatasetDimensions(dataset, dime);

        /* print dataset name */
        printf("\n\nDataset: %s\n", dsname);

        /* print DataType, Contents and dimensions */
        printf("DataType: %s\n", andata);
        printf("Contents: %s\n", ancont);
        printf("Dimensions: %s\n", dime);
        /* skip history datasets */
        if (hist) {
            continue;
        }
        /* skip non-entity datasets */
        if (enttype == 0) {
            print_attributes(dataset);
            continue;
        }
        /* skip dof parent datasets */
        if (enttype == SYS_DOF) {
            print_attributes(dataset);
            continue;
        }
        /* print section and layer position */
        /* useful for obtaining section information without
           needing to load the entire State */
        if (sect == SYS_ELEMSEC_ALL) {
            print_linksection(lman, library, dataset);
        }
        /* load state from dataset */
        vis_RPropDef(rprop, enttype, subtype);
        vis_RPropSetDatasetIndex(rprop, i);
        vdm_LManLoadState(lman, state, rprop);

        /* number of entities, datatype */
        vis_StateInq(state, &nument, &enttype, &subtype, &datatype);

        /* maximum data size, number of locations and sections */
        vis_StateDataMax(state, &maxdat, &maxloc, &maxsec);
        if (maxdat > mres) {
            mres = maxdat;
            res = (Vfloat*)realloc(res, mres * sizeof(Vfloat));
        }
        if (maxsec > msec) {
            msec = maxsec;
            pos = (Vint*)realloc(pos, msec * sizeof(Vint));
            lay = (Vint*)realloc(lay, msec * sizeof(Vint));
        }
        /* query local or global system */
        vis_StateGetSystem(state, &system);
        if (system == STATE_GLOBAL) {
            printf("system= Global\n");
        }
        else {
            printf("system= Local\n");
        }
        /* query engineering strain flag */
        vis_StateGetEngineeringStrain(state, &flag);
        if (flag) {
            printf("strain= Engineering\n");
        }
        /* query number of components */
        vis_StateNumDerive(state, &ncmp);

        /* return all sections */
        vis_StateSetSection(state, 0);

        /* loop through all entities */
        for (index = 1; index <= nument; index++) {
            /* select entities to ignore for whatever reason */
            if (index != 1)
                continue;
            /* print entity id */
            if (enttype == SYS_NODE) {
                vis_ConnectNodeAssoc(connect, VIS_USERID, 1, &index, &id);
                printf("node= %d\n", id);
            }
            else if (enttype == SYS_ELEM || enttype == SYS_FACE || enttype == SYS_EDGE) {
                vis_ConnectElemAssoc(connect, VIS_USERID, 1, &index, &id);
                printf("elem= %d\n", id);
            }
            else if (enttype == SYS_MODE) {
                printf("mode= %d\n", id);
            }
            /* see if data defined */
            vis_StateDataStat(state, 1, &index, &stat);
            if (stat == 0) {
                printf(" no data\n");
                continue;
            }
            /* get results data for entity */
            vis_StateData(state, 1, &index, res);
            /* print data */
            /* data at node */
            if (enttype == SYS_NODE) {
                for (j = 0; j < ncmp; j++) {
                    printf(" %e", res[j]);
                }
                printf("\n");
                /* data at element face or edge */
            }
            else if (enttype == SYS_FACE || enttype == SYS_EDGE) {
                vis_StateDataEnt(state, index, &numno, ne);
                /* element face or edge */
                if (subtype == SYS_NONE) {
                    for (k = 0; k < numno; k++) {
                        printf("%4d", ne[k]);
                        for (j = 0; j < ncmp; j++) {
                            printf(" %e", res[k * ncmp + j]);
                        }
                        printf("\n");
                    }
                    /* element face or edge node */
                }
                else {
                    for (k = 0; k < numno; k++) {
                        printf("%4d", ne[k]);
                        vis_ConnectElemCon(connect, enttype, index, ne[k], &nix, ix);
                        for (n = 0; n < nix; n++) {
                            printf("%4d", n + 1);
                            for (j = 0; j < ncmp; j++) {
                                printf(" %e", res[k * ncmp * nix + n * ncmp + j]);
                            }
                            printf("\n");
                        }
                    }
                }
                /* data at element */
            }
            else if (enttype == SYS_ELEM) {
                /* get number of sections */
                vis_StateDataSect(state, 1, &index, &nsec);
                /* get layer position */
                vis_StateDataLayers(state, index, pos, lay);
                /* element */
                if (subtype == SYS_NONE) {
                    for (k = 0; k < nsec; k++) {
                        if (nsec > 1) {
                            print_section(pos[k], lay[k]);
                        }
                        for (j = 0; j < ncmp; j++) {
                            printf(" %e", res[k * ncmp + j]);
                        }
                        printf("\n");
                    }
                    /* element node */
                }
                else {
                    vis_ConnectElemNode(connect, index, &nix, ix);
                    for (k = 0; k < nsec; k++) {
                        if (nsec > 1) {
                            print_section(pos[k], lay[k]);
                        }
                        for (n = 0; n < nix; n++) {
                            vis_ConnectNodeAssoc(connect, VIS_USERID, 1, &ix[n], &elnoid);
                            printf("node= %d\n", elnoid);
                            for (j = 0; j < ncmp; j++) {
                                printf(" %e", res[k * ncmp * nix + n * ncmp + j]);
                            }
                            printf("\n");
                        }
                    }
                }
                /* data at mode */
            }
            else if (enttype == SYS_MODE) {
                for (j = 0; j < ncmp; j++) {
                    printf(" %e", res[j]);
                }
                printf("\n");
            }
        }
        /* print attributes */
        print_attributes(dataset);
    }
    /* free memory */
    vis_GridFunEnd(gridfun);
    vis_StateEnd(state);
    vis_RPropEnd(rprop);
    if (res) {
        free(res);
    }
    if (pos) {
        free(pos);
        free(lay);
    }
    free(ix);
}

/*----------------------------------------------------------------------
                      print section and type
----------------------------------------------------------------------*/
static void
print_section(Vint lpos, Vint isec)
{
    printf("section= %d", isec);
    if (lpos == SYS_LAYERPOSITION_NONE) {
        printf(" none");
    }
    else if (lpos == SYS_LAYERPOSITION_MID) {
        printf(" middle");
    }
    else if (lpos == SYS_LAYERPOSITION_BOT) {
        printf(" bottom");
    }
    else if (lpos == SYS_LAYERPOSITION_TOP) {
        printf(" top");
    }
    else if (lpos == SYS_LAYERPOSITION_INTPNT) {
        printf(" eip");
    }
    printf("\n");
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
