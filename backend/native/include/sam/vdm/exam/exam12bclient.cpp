#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/vdm/vdm.h"
#include "legacy/vgl/vgl.h"
#include "sam/vfx/vfx.h"
#include "datafile.h"

#define BUFSIZE 256

static Vint magic = 1234;

/* data structure for server */
typedef struct {
    vsy_VSocket* vsocket;
    Vint cid;
} exam12bstruct;

/* monitor function for server */
extern void
exam12bmonitor(vdm_DataIPC* p, Vobject* obj)
{
    Vint ierr;

    ierr = vdm_DataIPCError(p);
    if (ierr) {
        vdm_DataIPCAbort(p);
    }
}
/* read and write functions for server */
extern void
exam12breads(exam12bstruct* inst, Vint num, Vchar* buf)
{
    vsy_VSocketRead(inst->vsocket, inst->cid, num, buf);
}
extern void
exam12bwrites(exam12bstruct* inst, Vint num, Vchar* buf)
{
    vsy_VSocketWrite(inst->vsocket, inst->cid, num, buf);
}

/* read and write functions for client */
extern void
exam12breadc(vsy_VSocket* vsocket, Vint num, Vchar* buf)
{
    vsy_VSocketRead(vsocket, 0, num, buf);
}
extern void
exam12bwritec(vsy_VSocket* vsocket, Vint num, Vchar* buf)
{
    vsy_VSocketWrite(vsocket, 0, num, buf);
}

/* 4-byte swapping function */
static void
exam12bswap4(Vchar* num)
{
    Vchar c;

    c = num[0];
    num[0] = num[3];
    num[3] = c;
    c = num[1];
    num[1] = num[2];
    num[2] = c;
}

static void
loadandsave(vdm_LMan* lman, vdm_DataFun* datafun, vdm_LMan* lmanw, vdm_DataFun* datafunw);
static void
modelimage(vdm_LMan* lman, vdm_DataFun* datafun, vdm_LMan* lmanw, vdm_DataFun* datafunw);

/*----------------------------------------------------------------------
                     Load Model and Results and Save to Native File
----------------------------------------------------------------------*/
int
clientdriver(int argc, char** argv, vdm_DataFun* datafunw)
{
    char inputfile[256];
    char outputfile[256];
    vdm_DataFun* datafun;
    vdm_Library* library;
    vdm_LMan* lman;
    Vint filetype;
    Vint ierr;
    vdm_LMan* lmanw;

    /* check input arguments */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s inputfile\n", argv[0]);
        exit(1);
    }
    else {
        strcpy(inputfile, argv[1]);
    }
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
    /* open remote file */
    sprintf(outputfile, "%s.vh5", inputfile);
    vdm_DataFunSetStatus(datafunw, VDM_STATUS_NEW);
    vdm_DataFunOpen(datafunw, 0, outputfile, VDM_NATIVE_HDF5);
    vdm_DataFunSetMode(datafunw, VDM_ZLIBCOMPRESS, SYS_ON);

    /* use Library Manager object to save model */
    lmanw = vdm_LManBegin();
    vdm_LManSetObject(lmanw, VDM_DATAFUN, datafunw);

    /* use Library Manager object to load model */
    lman = vdm_LManBegin();
    vdm_LManSetObject(lman, VDM_DATAFUN, datafun);

    /* get library object */
    vdm_DataFunGetLibrary(datafun, &library);

    /* load and save all datasets */
    modelimage(lman, datafun, lmanw, datafunw);
    /* load and save all datasets */
    loadandsave(lman, datafun, lmanw, datafunw);

    /* close library devices */
    vdm_DataFunClose(datafun);
    vdm_DataFunClose(datafunw);

    datafileterm(filetype, datafun);
    /* free objects */
    vdm_DataFunEnd(datafun);
    vdm_LManEnd(lman);
    vdm_LManEnd(lmanw);
    return 0;
}

/*----------------------------------------------------------------------
                      load and save results
----------------------------------------------------------------------*/
static void
loadandsave(vdm_LMan* lman, vdm_DataFun* df, vdm_LMan* lmanw, vdm_DataFun* dfw)
{
    Vint i, j, k;
    vdm_Library* library;
    vdm_Dataset* dataset;
    vdm_Attribute* attribute;
    Vchar dsname[DATASET_MAXNAME], atname[ATTRIBUTE_MAXNAME];
    Vchar andesc[ATTRIBUTE_MAXVALUE];
    Vchar ancont[ATTRIBUTE_MAXVALUE];
    Vchar anmodel[ATTRIBUTE_MAXVALUE];
    Vlong lrec;
    Vint nrow, ncol, ntyp;
    Vint numdatasets, numattributes;
    Vint enttype, subtype;
    Vint id1, id2, id3;
    Vint nlev;
    Vint nbytes, idst;
    Vlong sizeofd;
    void* d;
    Vint atleng, attype, iatt;
    Vchar cvalue[ATTRIBUTE_MAXVALUE];
    Vchar cstg[256];

    /* determine maximum number of datasets */
    vdm_DataFunGetLibrary(df, &library);
    vdm_LibraryGetNumDatasets(library, &numdatasets);
    nlev = 0;
    /* loop over datasets */
    for (i = 0; i < numdatasets; i++) {
        vdm_LibraryGetDataset(library, i, &dataset);
        vdm_DatasetInq(dataset, dsname, &lrec, &nrow, &ncol, &ntyp);
        vdm_DatasetEntType(dataset, &enttype, &subtype);
        /* get model attribute to use as container under Model */
        vdm_DatasetModel(dataset, anmodel);
        /* get description attribute to print progress */
        printf("processing dataset= %s\n", dsname);
        vdm_DatasetDescription(dataset, andesc);
        printf("description= %s\n", andesc);
        /* library dataset */
        if (enttype == SYS_LIBRARY) {
            if (nlev) {
                for (k = 0; k < nlev; k++) {
                    vdm_DataFunPopContainer(dfw);
                }
                nlev = 0;
            }
            vdm_LManMakeLibDataset(lmanw, dsname, &idst);
            vdm_DataFunLibDataset(dfw, VDM_LIBDATASET_PUSH, idst);
            vdm_DataFunLibDataset(df, VDM_LIBDATASET_PUSH, i);
            loadandsave(lman, df, lmanw, dfw);
            vdm_DataFunLibDataset(dfw, VDM_LIBDATASET_POP, 0);
            vdm_DataFunLibDataset(df, VDM_LIBDATASET_POP, 0);
            continue;
        }
        /* create and push readability containers */
        /* a model dataset */
        if (anmodel[0] != '\0') {
            vdm_DataFunPushContainer(dfw, "Model");
            nlev += 1;
            vdm_DataFunPushContainer(dfw, anmodel);
            nlev += 1;
            /* a result dataset */
        }
        else {
            vdm_DataFunPushContainer(dfw, "Results");
            nlev += 1;
            vdm_DatasetContents(dataset, ancont);
            if (ancont[0] != '\0') {
                vdm_DatasetIds(dataset, &id1, &id2, &id3);
                sprintf(cstg, "Case %d", id1);
                vdm_DataFunPushContainer(dfw, cstg);
                nlev += 1;
                if (id2) {
                    sprintf(cstg, "Mode %d", id2);
                    vdm_DataFunPushContainer(dfw, cstg);
                    nlev += 1;
                }
            }
        }
        vut_SizeofDataType(ntyp, &nbytes);
        sizeofd = lrec * nbytes;
        vdm_DatasetGetNumAttributes(dataset, &numattributes);
        /* define dataset */
        vdm_DataFunDefDataset(dfw, dsname, lrec, nrow, ncol, ntyp, &idst);
        /* attributes */
        for (j = 0; j < numattributes; j++) {
            vdm_DatasetGetAttribute(dataset, j, &attribute);
            vdm_AttributeInq(attribute, atname, &atleng, &attype);
            vdm_AttributeGet(attribute, (void*)cvalue);
            vdm_DataFunDefAttribute(dfw, idst, atname, atleng, attype, &iatt);
            vdm_DataFunSetAttVal(dfw, idst, iatt, cvalue);
        }
        /* read dataset */
        d = vut_mallocMem((size_t)sizeofd);
        if (d == NULL) {
            break;
        }
        /* read */
        vdm_DataFunReadDataset(df, i, d);
        if (vdm_DataFunError(df))
            break;
        vdm_DataFunWriteDataset(dfw, idst, d);
        vut_freeMem(d);
        /* pop readability containers */
        for (k = 0; k < nlev; k++) {
            vdm_DataFunPopContainer(dfw);
        }
        nlev = 0;
    }
}

/*----------------------------------------------------------------------
                      generate model image
----------------------------------------------------------------------*/
static void
modelimage(vdm_LMan* lman, vdm_DataFun* df, vdm_LMan* lmanw, vdm_DataFun* dfw)
{
    Vint i, j;
    vis_Model* model;
    vis_ProRender* prorender;
    vgl_FBuffer* fbuffer;
    Vint nrow, ncol;
    Vlong lrec;
    Vint idst;
    Vint ind;
    Vuchar* d;
    Vuchar rgb[4];
    /* instance Model object for finite element model */
    model = vis_ModelBegin();
    vdm_LManLoadModel(lman, model);

    prorender = vis_ProRenderBegin();
    vis_ProRenderSetDimension(prorender, 480, 360);
    vis_ProRenderSetObject(prorender, VIS_MODEL, model);
    /* generate model retained graphics data */
    vis_ProRenderModel(prorender);
    /* render graphics data to image file */
    vis_ProRenderSetLookAt(prorender, 1., 1., 1., 0., 0., 0., 0., 0., 1.);
    vis_ProRenderDraw(prorender);
    vis_ProRenderGetFBuffer(prorender, &fbuffer);
    /* create and write dataset */
    /* define dataset */
    vgl_FBufferInq(fbuffer, &nrow, &ncol);
    lrec = nrow * ncol;
    d = vut_mallocMem((size_t)lrec * 3);
    ind = 0;
    for (j = ncol - 1; j >= 0; j--) {
        for (i = 0; i < nrow; i++) {
            vgl_FBufferGetPixel(fbuffer, i, j, (Vuint*)rgb);
            d[ind++] = rgb[0];
            d[ind++] = rgb[1];
            d[ind++] = rgb[2];
        }
    }
    vdm_DataFunPushContainer(dfw, "Model");
    vdm_DataFunDefDataset(dfw, "QUARTERVIEW.IMG", lrec, nrow, ncol, SYS_24BIT, &idst);
    vdm_DataFunWriteDataset(dfw, idst, d);
    vdm_DataFunPopContainer(dfw);
    vut_freeMem(d);
    /* clean up */
    vis_ProRenderEnd(prorender);
    vis_ModelDelete(model);
    vis_ModelEnd(model);
}

/*----------------------------------------------------------------------
                       Remotely Access Any File Format
----------------------------------------------------------------------*/
int
main(int argc, char* argv[])
{
    vdm_DataFun* datafunw;
    vdm_DataIPC* dataipc;
    vsy_VSocket* vsocket;
    Vchar hostname[BUFSIZE];
    Vint flag, swap, imagic;

    /* create output data function object */
    datafunw = vdm_DataFunBegin();
    dataipc = vdm_DataIPCBegin();
    vdm_DataIPCDataFun(dataipc, datafunw);

    /* Get info about this host */
    vut_MachInfoHostName(&flag, hostname);
    if (flag == 0) {
        printf("Unable to retrieve host name\n");
        return 1;
    }
    /* Instance and set up VSocket */
    vsocket = vsy_VSocketBegin();
    vsy_VSocketSetParami(vsocket, VSOCKET_WAITTIME, 1000);
    vsy_VSocketDef(vsocket, VSOCKET_CLIENT, VSOCKET_NET);
    vsy_VSocketSetNet(vsocket, 53222, hostname);
    vsy_VSocketOpen(vsocket);
    if (vsy_VSocketError(vsocket)) {
        vsy_VSocketEnd(vsocket);
        return 1;
    }
    /* send magic number */
    vsy_VSocketWrite(vsocket, 0, sizeof(Vint), (Vchar*)&magic);

    /* receive magic number */
    swap = 0;
    vsy_VSocketRead(vsocket, 0, sizeof(Vint), (Vchar*)&imagic);
    if (imagic != magic) {
        exam12bswap4((Vchar*)&imagic);
        if (imagic != magic) {
            vsy_VSocketClose(vsocket, 0);
            return 1;
        }
        else {
            swap = 1;
        }
    }
    /* create data function object */
    datafunw = vdm_DataFunBegin();
    dataipc = vdm_DataIPCBegin();
    vdm_DataIPCSetSwap(dataipc, swap);
    vdm_DataIPCDef(dataipc, DATAIPC_CLIENT);
    vdm_DataIPCDataFun(dataipc, datafunw);

    vdm_DataIPCSetFunction(dataipc, DATAIPC_FUN_WRITE, (Vfunc*)exam12bwritec, (Vobject*)vsocket);
    vdm_DataIPCSetFunction(dataipc, DATAIPC_FUN_READ, (Vfunc*)exam12breadc, (Vobject*)vsocket);

    /* create remote file */
    clientdriver(argc, argv, datafunw);

    vdm_DataIPCStopServer(dataipc);
    vsy_VSocketClose(vsocket, 0);

    /* free objects */
    vdm_DataFunEnd(datafunw);
    vdm_DataIPCEnd(dataipc);
    vsy_VSocketEnd(vsocket);
    return 0;
}
