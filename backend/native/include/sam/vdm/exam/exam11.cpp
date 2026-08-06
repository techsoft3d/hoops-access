#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vdm/vdm.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/* flag to always open all domains */
static Vint openall = 0;

/*----------------------------------------------------------------------
                      Reading Multiple Domains
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    char inputfile[256];
    vdm_OpenFOAMLib *openfoamlib = NULL, **ofdom = NULL;
    vdm_SDRCLib *sdrclib = NULL, **sddom = NULL;
    vdm_DataFun *datafun = NULL, **dfdom = NULL;
    vdm_Library* library = NULL;
    Vint filetype, numdomains, n;

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
    if (strstr(inputfile, "controlDict") != NULL) {
        filetype = SYS_OPENFOAM;
        openfoamlib = vdm_OpenFOAMLibBegin();
        vdm_OpenFOAMLibDataFun(openfoamlib, datafun);
        printf("OpenFOAM File: %s\n", inputfile);
    }
    else if (strstr(inputfile, ".unv") != NULL) {
        filetype = SYS_SDRC_UNIVERSAL;
        sdrclib = vdm_SDRCLibBegin();
        vdm_SDRCLibDataFun(sdrclib, datafun);
        printf("SDRC Universal File: %s\n", inputfile);
    }
    else {
        fprintf(stderr, "Error: Bad input file %s\n", inputfile);
        exit(1);
    }
    /* query file for number of domains */
    vdm_DataFunNumDomains(datafun, inputfile, filetype, &numdomains);
    printf("numdom= %d\n", numdomains);
    /* open all domains */
    if (numdomains == 0 || openall) {
        printf("Opening all domains\n");
        vdm_DataFunOpen(datafun, 0, inputfile, filetype);
        vdm_DataFunGetLibrary(datafun, &library);
        vdm_LibraryTOC(library, "*", 0);
        vdm_DataFunClose(datafun);
        /* open individual domains, each may be in parallel */
    }
    else {
        printf("Opening individual domains\n");
        /* instance multiple datafun objects */
        dfdom = (vdm_DataFun**)malloc(numdomains * sizeof(vdm_DataFun*));
        for (n = 0; n < numdomains; n++) {
            dfdom[n] = vdm_DataFunBegin();
        }
        if (filetype == SYS_SDRC_UNIVERSAL) {
            sddom = (vdm_SDRCLib**)malloc(numdomains * sizeof(vdm_SDRCLib*));
            for (n = 0; n < numdomains; n++) {
                sddom[n] = vdm_SDRCLibBegin();
                vdm_SDRCLibDataFun(sddom[n], dfdom[n]);
            }
        }
        else if (filetype == SYS_OPENFOAM) {
            ofdom = (vdm_OpenFOAMLib**)malloc(numdomains * sizeof(vdm_OpenFOAMLib*));
            for (n = 0; n < numdomains; n++) {
                ofdom[n] = vdm_OpenFOAMLibBegin();
                vdm_OpenFOAMLibDataFun(ofdom[n], dfdom[n]);
            }
        }
        /* open all datafun objects */
        for (n = 0; n < numdomains; n++) {
            printf("Opening file for processor= %d\n", n + 1);
            vdm_DataFunOpen(dfdom[n], n + 1, inputfile, filetype);
        }
        /* work with each datafun: in this case, print TOC */
        for (n = 0; n < numdomains; n++) {
            printf("\nWorking with processor= %d\n", n + 1);
            vdm_DataFunGetLibrary(dfdom[n], &library);
            vdm_LibraryTOC(library, "*", 0);
        }
        /* close all datafun objects */
        for (n = 0; n < numdomains; n++) {
            printf("Closing file for processor= %d\n", n + 1);
            vdm_DataFunClose(dfdom[n]);
        }
        /* delete multiple datafun objects */
        if (filetype == SYS_SDRC_UNIVERSAL) {
            for (n = 0; n < numdomains; n++) {
                vdm_SDRCLibEnd(sddom[n]);
            }
            free(sddom);
        }
        else if (filetype == SYS_OPENFOAM) {
            for (n = 0; n < numdomains; n++) {
                vdm_OpenFOAMLibEnd(ofdom[n]);
            }
            free(ofdom);
        }
        for (n = 0; n < numdomains; n++) {
            vdm_DataFunEnd(dfdom[n]);
        }
        free(dfdom);
    }
    /* delete initial interface */
    printf("Cleaning up\n");
    vdm_DataFunEnd(datafun);
    if (filetype == SYS_OPENFOAM) {
        vdm_OpenFOAMLibEnd(openfoamlib);
    }
    else if (filetype == SYS_SDRC_UNIVERSAL) {
        vdm_SDRCLibEnd(sdrclib);
    }
    return 0;
}
