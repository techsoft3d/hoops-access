#include "sam/base/base.h"
#include "sam/vdm/vdm.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static Vchar* vdmname[] = {(Vchar*)"VDM_NATIVE",          (Vchar*)"VDM_LSTC_STATE",      (Vchar*)"VDM_ABAQUS_FILBIN",
                           (Vchar*)"VDM_ABAQUS_INPUT",    (Vchar*)"VDM_NASTRAN_OUTPUT2", (Vchar*)"VDM_NASTRAN_BULKDATA",
                           (Vchar*)"VDM_SDRC_UNIVERSAL",  (Vchar*)"VDM_PAM_DAISY",       (Vchar*)"VDM_ANSYS_RESULT",
                           (Vchar*)"VDM_MECHANICA_STUDY", (Vchar*)"VDM_PAT_NEUTRAL",     NULL};

static Vint vdmtype[] = {VDM_NATIVE,          VDM_LSTC_STATE,       VDM_ABAQUS_FILBIN,  VDM_ABAQUS_INPUT,
                         VDM_NASTRAN_OUTPUT2, VDM_NASTRAN_BULKDATA, VDM_SDRC_UNIVERSAL, VDM_PAM_DAISY,
                         VDM_ANSYS_RESULT,    VDM_MECHANICA_STUDY,  VDM_PAT_NEUTRAL};

/*----------------------------------------------------------------------
                      Export all Datasets
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    vdm_LMan* lman;

    vdm_SDRCLib* sdrclib = NULL;
    vdm_RASLib* raslib = NULL;
    vdm_D3DLib* d3dlib = NULL;
    vdm_ABALib* abalib = NULL;
    vdm_ABAFil* abafil = NULL;
    vdm_ANSLib* anslib = NULL;
    vdm_NASLib* naslib = NULL;
    vdm_NASFil* nasfil = NULL;
    vdm_PatLib* patlib = NULL;
    vdm_PAMLib* pamlib = NULL;
    vdm_NatLib* natlib = NULL;

    Vint i;
    vdm_DataFun* datafun;
    char inputfile[256];
    Vint filetype = 0;

    /* determine input file type */
    if (argc < 3) {
        fprintf(stderr, "Usage: %s filetype pathname\n", argv[0]);
        fprintf(stderr, " VDM_SDRC_UNIVERSAL bumper.unv is assumed\n");
        filetype = VDM_SDRC_UNIVERSAL;
        strcpy(inputfile, "bumper.unv");
    }
    else {
        for (i = 0; vdmname[i]; i++) {
            if (!strcmp(argv[1], vdmname[i])) {
                filetype = vdmtype[i];
                strcpy(inputfile, argv[2]);
                break;
            }
        }
        if (vdmname[i] == NULL) {
            fprintf(stderr, "Error: %s unrecognized file type\n", argv[0]);
        }
    }

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create data function object */
    datafun = vdm_DataFunBegin();

    /* create library device and fill data functions */
    if (filetype == VDM_SDRC_UNIVERSAL) {
        sdrclib = vdm_SDRCLibBegin();
        vdm_SDRCLibDataFun(sdrclib, datafun);
    }
    else if (filetype == VDM_MECHANICA_STUDY) {
        raslib = vdm_RASLibBegin();
        vdm_RASLibDataFun(raslib, datafun);
    }
    else if (filetype == VDM_LSTC_STATE) {
        d3dlib = vdm_D3DLibBegin();
        vdm_D3DLibDataFun(d3dlib, datafun);
    }
    else if (filetype == VDM_ABAQUS_FILBIN) {
        abalib = vdm_ABALibBegin();
        vdm_ABALibDataFun(abalib, datafun);
    }
    else if (filetype == VDM_ABAQUS_INPUT) {
        abafil = vdm_ABAFilBegin();
        vdm_ABAFilDataFun(abafil, datafun);
    }
    else if (filetype == VDM_ANSYS_RESULT) {
        anslib = vdm_ANSLibBegin();
        vdm_ANSLibDataFun(anslib, datafun);
    }
    else if (filetype == VDM_PAT_NEUTRAL) {
        patlib = vdm_PatLibBegin();
        vdm_PatLibDataFun(patlib, datafun);
    }
    else if (filetype == VDM_NASTRAN_OUTPUT2) {
        naslib = vdm_NASLibBegin();
        vdm_NASLibDataFun(naslib, datafun);
    }
    else if (filetype == VDM_NASTRAN_BULKDATA) {
        nasfil = vdm_NASFilBegin();
        vdm_NASFilDataFun(nasfil, datafun);
    }
    else if (filetype == VDM_PAM_DAISY) {
        pamlib = vdm_PAMLibBegin();
        vdm_PAMLibDataFun(pamlib, datafun);
    }
    else if (filetype == VDM_NATIVE) {
        natlib = vdm_NatLibBegin();
        vdm_NatLibDataFun(natlib, datafun);
    }

    /* open library device */
    vdm_DataFunOpen(datafun, 0, inputfile, filetype);

    /* check for error */
    if (vdm_DataFunError(datafun)) {
        fprintf(stderr, "Error: opening file %s\n", inputfile);

        /* load model */
    }
    else {
        lman = vdm_LManBegin();
        vdm_LManSetObject(lman, VDM_DATAFUN, datafun);
        vdm_LManSetParami(lman, LMAN_VERBOSE, SYS_ON);
        vdm_LManTOC(lman, "*");
        vdm_LManExport(lman, (Vchar*)"*", (Vchar*)"exam4.exp");
        vdm_LManEnd(lman);
    }
    /* close library device */
    vdm_DataFunClose(datafun);

    /* free objects */
    vdm_DataFunEnd(datafun);

    if (filetype == VDM_SDRC_UNIVERSAL) {
        vdm_SDRCLibEnd(sdrclib);
    }
    else if (filetype == VDM_MECHANICA_STUDY) {
        vdm_RASLibEnd(raslib);
    }
    else if (filetype == VDM_LSTC_STATE) {
        vdm_D3DLibEnd(d3dlib);
    }
    else if (filetype == VDM_ABAQUS_FILBIN) {
        vdm_ABALibEnd(abalib);
    }
    else if (filetype == VDM_ABAQUS_INPUT) {
        vdm_ABAFilEnd(abafil);
    }
    else if (filetype == VDM_ANSYS_RESULT) {
        vdm_ANSLibEnd(anslib);
    }
    else if (filetype == VDM_PAT_NEUTRAL) {
        vdm_PatLibEnd(patlib);
    }
    else if (filetype == VDM_NASTRAN_OUTPUT2) {
        vdm_NASLibEnd(naslib);
    }
    else if (filetype == VDM_NASTRAN_BULKDATA) {
        vdm_NASFilEnd(nasfil);
    }
    else if (filetype == VDM_PAM_DAISY) {
        vdm_PAMLibEnd(pamlib);
    }
    else if (filetype == VDM_NATIVE) {
        vdm_NatLibEnd(natlib);
    }
    return 0;
}
