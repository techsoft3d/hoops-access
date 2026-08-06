#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/vdm/vdm.h"
#ifndef VKI_NOVGLTOOLS
#include "legacy/vgl/vgl.h"
#include "legacy/vis/prorender.h"
#endif
#include "sam/vfx/vfx.h"
#include "sam/vdm/datafile.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static void
loadandsave(vdm_LMan* lman, vdm_DataFun* datafun, vdm_LMan* lmanw, vdm_DataFun* datafunw);
#ifndef VKI_NOVGLTOOLS
static void
modelimage(vdm_LMan* lman, vdm_DataFun* datafun, vdm_LMan* lmanw, vdm_DataFun* datafunw);
#endif

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
    /* native file type, use .vdm */
    filetypew = VDM_NATIVE;
    /* native HDF5 file type, use .vh5 */
    /*
       filetypew = VDM_NATIVE_HDF5;
    */
    /* create output data function object */
    datafunw = vdm_DataFunBegin();
    natlib = vdm_NatLibBegin();
    vdm_NatLibDataFun(natlib, datafunw);
    /* new file */
    vdm_DataFunSetStatus(datafunw, VDM_STATUS_NEW);
    /*
       vdm_DataFunSetMode (datafunw,VDM_ZLIBCOMPRESS,SYS_ON);
    */
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

    /* use Library Manager object to load model */
    lman = vdm_LManBegin();
    vdm_LManSetObject(lman, VDM_DATAFUN, datafun);

    /* get library object */
    vdm_DataFunGetLibrary(datafun, &library);

    /* create model image */
#ifndef VKI_NOVGLTOOLS
    modelimage(lman, datafun, lmanw, datafunw);
#endif
    /* load and save all datasets */
    loadandsave(lman, datafun, lmanw, datafunw);

    /* close library devices */
    vdm_DataFunClose(datafun);
    vdm_DataFunClose(datafunw);

    datafileterm(filetype, datafun);
    /* free objects */
    vdm_DataFunEnd(datafun);
    vdm_LManEnd(lman);

    vdm_DataFunEnd(datafunw);
    vdm_LManEnd(lmanw);
    vdm_NatLibEnd(natlib);
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
            vdm_DataFunPushContainer(dfw, (Vchar*)"Model");
            nlev += 1;
            vdm_DataFunPushContainer(dfw, anmodel);
            nlev += 1;
            /* a result dataset */
        }
        else {
            vdm_DataFunPushContainer(dfw, (Vchar*)"Results");
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
        d = vut_MemoryMalloc((size_t)sizeofd);
        if (d == NULL) {
            break;
        }
        /* read */
        vdm_DataFunReadDataset(df, i, d);
        if (vdm_DataFunError(df))
            break;
        vdm_DataFunWriteDataset(dfw, idst, d);
        vut_MemoryFree(d);
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
#ifndef VKI_NOVGLTOOLS
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
    d = (Vuchar*)vut_MemoryMalloc((size_t)lrec * 3);
    ind = 0;
    for (j = ncol - 1; j >= 0; j--) {
        for (i = 0; i < nrow; i++) {
            vgl_FBufferGetPixel(fbuffer, i, j, (Vuint*)rgb);
            d[ind++] = rgb[0];
            d[ind++] = rgb[1];
            d[ind++] = rgb[2];
        }
    }
    vdm_DataFunPushContainer(dfw, (Vchar*)"Model");
    vdm_DataFunDefDataset(dfw, "QUARTERVIEW.IMG", lrec, nrow, ncol, SYS_24BIT, &idst);
    vdm_DataFunWriteDataset(dfw, idst, d);
    vdm_DataFunPopContainer(dfw);
    vut_MemoryFree(d);
    /* clean up */
    vis_ProRenderEnd(prorender);
    vis_ModelDelete(model);
    vis_ModelEnd(model);
}
#endif
