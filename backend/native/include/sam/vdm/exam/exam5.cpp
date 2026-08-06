#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/vdm/vdm.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Open and Append Files
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    vdm_LMan* lman;
    /* primary libraries */
    vdm_SDRCLib* sdrclib = NULL;
    vdm_RASLib* raslib = NULL;
    vdm_ABALib* abalib = NULL;
    vdm_ABAFil* abafil = NULL;
    vdm_ANSLib* anslib = NULL;
    vdm_ANSFil* ansfil = NULL;
    vdm_D3DFil* d3dfil = NULL;
    vdm_D3DLib* d3dlib = NULL;
    vdm_NASLib* naslib = NULL;
    vdm_NatLib* natlib = NULL;
    vdm_NASFil* nasfil = NULL;
    vdm_STLFil* stlfil = NULL;
    vdm_PAMLib* pamlib = NULL;
    vdm_PatLib* patlib = NULL;
    vdm_PLOT3DLib* plot3dlib = NULL;
    vdm_FLUENTLib* fluentlib = NULL;
    vdm_CGNSVLib* cgnsvlib = NULL;
    vdm_EnSightLib* ensightlib = NULL;
    vdm_STARCCMLib* starccmlib = NULL;
    vdm_SAMCEFLib* samceflib = NULL;
    vdm_TecplotLib* tecplotlib = NULL;
    vdm_MarcLib* marclib = NULL;
    vdm_DataFun* datafun = NULL;
    vdm_Library* library = NULL;
    Vint filetype, filetype1;
    Vint ierr;
    Vint i;
    Vint id1, id2, id3;

    /* determine input file type */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s pathname appendpathname\n", argv[0]);
        exit(0);
    }

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create data function object */
    datafun = vdm_DataFunBegin();

    /* determine first file type from file extension */
    if (strstr(argv[1], ".bdf") != NULL || strstr(argv[1], ".dat") != NULL) {
        filetype = VDM_NASTRAN_BULKDATA;
        nasfil = vdm_NASFilBegin();
        vdm_NASFilDataFun(nasfil, datafun);
    }
    else if (strstr(argv[1], ".op2") != NULL || strstr(argv[1], ".OP2") != NULL) {
        filetype = VDM_NASTRAN_OUTPUT2;
        naslib = vdm_NASLibBegin();
        vdm_NASLibDataFun(naslib, datafun);
    }
    else if (strstr(argv[1], ".rst") != NULL) {
        filetype = VDM_ANSYS_RESULT;
        anslib = vdm_ANSLibBegin();
        vdm_ANSLibDataFun(anslib, datafun);
    }
    else if (strstr(argv[1], ".cdb") != NULL) {
        filetype = VDM_ANSYS_INPUT;
        ansfil = vdm_ANSFilBegin();
        vdm_ANSFilDataFun(ansfil, datafun);
    }
    else if (strstr(argv[1], ".fil") != NULL) {
        filetype = VDM_ABAQUS_FIL;
        abalib = vdm_ABALibBegin();
        vdm_ABALibDataFun(abalib, datafun);
    }
    else if (strstr(argv[1], ".inp") != NULL) {
        filetype = VDM_ABAQUS_INPUT;
        abafil = vdm_ABAFilBegin();
        vdm_ABAFilDataFun(abafil, datafun);
    }
    else if (strstr(argv[1], ".odb") != NULL) {
        filetype = VDM_ABAQUS_ODB;
        abalib = vdm_ABALibBegin();
        vdm_ABALibDataFun(abalib, datafun);
    }
    else if (strstr(argv[1], ".k") != NULL || strstr(argv[1], ".key") != NULL || strstr(argv[1], ".dyn") != NULL ||
             strstr(argv[1], ".DYN") != NULL) {
        filetype = VDM_LSTC_INPUT;
        d3dfil = vdm_D3DFilBegin();
        vdm_D3DFilDataFun(d3dfil, datafun);
    }
    else if (strstr(argv[1], "d3plot") != NULL) {
        filetype = VDM_LSTC_STATE;
        d3dlib = vdm_D3DLibBegin();
        vdm_D3DLibDataFun(d3dlib, datafun);
    }
    else if (strstr(argv[1], ".neu") != NULL) {
        filetype = VDM_MECHANICA_STUDY;
        raslib = vdm_RASLibBegin();
        vdm_RASLibDataFun(raslib, datafun);
    }
    else if (strstr(argv[1], ".des") != NULL) {
        filetype = SYS_SAMCEF;
        samceflib = vdm_SAMCEFLibBegin();
        vdm_SAMCEFLibDataFun(samceflib, datafun);
    }
    else if (strstr(argv[1], ".unv") != NULL || strstr(argv[1], ".bun") != NULL) {
        filetype = VDM_SDRC_UNIVERSAL;
        sdrclib = vdm_SDRCLibBegin();
        vdm_SDRCLibDataFun(sdrclib, datafun);
    }
    else if (strstr(argv[1], ".stl") != NULL) {
        filetype = VDM_STL;
        stlfil = vdm_STLFilBegin();
        vdm_STLFilDataFun(stlfil, datafun);
    }
    else if (strstr(argv[1], ".STL") != NULL) {
        filetype = VDM_STLBIN;
        stlfil = vdm_STLFilBegin();
        vdm_STLFilDataFun(stlfil, datafun);
    }
    else if (strstr(argv[1], ".vdm") != NULL) {
        filetype = VDM_NATIVE;
        natlib = vdm_NatLibBegin();
        vdm_NatLibDataFun(natlib, datafun);
    }
    else if (strstr(argv[1], ".dsy") != NULL || strstr(argv[1], ".DSY") != NULL) {
        filetype = VDM_PAM_DAISY;
        pamlib = vdm_PAMLibBegin();
        vdm_PAMLibDataFun(pamlib, datafun);
    }
    else if (strstr(argv[1], ".out") != NULL) {
        filetype = VDM_PATRAN_NEUTRAL;
        patlib = vdm_PatLibBegin();
        vdm_PatLibDataFun(patlib, datafun);
    }
    else if (strstr(argv[1], ".x") != NULL) {
        filetype = VDM_PLOT3D_GRID;
        plot3dlib = vdm_PLOT3DLibBegin();
        vdm_PLOT3DLibSetGridType(plot3dlib, PLOT3DLIB_MULTIPLE, 3, SYS_OFF);
        vdm_PLOT3DLibDataFun(plot3dlib, datafun);
    }
    else if (strstr(argv[1], ".cas") != NULL) {
        filetype = VDM_FLUENT_MESH;
        fluentlib = vdm_FLUENTLibBegin();
        vdm_FLUENTLibDataFun(fluentlib, datafun);
    }
    else if (strstr(argv[1], ".cgns") != NULL) {
        filetype = VDM_CGNS;
        cgnsvlib = vdm_CGNSVLibBegin();
        vdm_CGNSVLibDataFun(cgnsvlib, datafun);
    }
    else if (strstr(argv[1], ".encas") != NULL) {
        filetype = VDM_ENSIGHT;
        ensightlib = vdm_EnSightLibBegin();
        vdm_EnSightLibDataFun(ensightlib, datafun);
    }
    else if (strstr(argv[1], ".ccm") != NULL) {
        filetype = VDM_STARCCM;
        starccmlib = vdm_STARCCMLibBegin();
        vdm_STARCCMLibDataFun(starccmlib, datafun);
    }
    else if (strstr(argv[1], ".plt") != NULL) {
        filetype = VDM_TECPLOT;
        tecplotlib = vdm_TecplotLibBegin();
        vdm_TecplotLibDataFun(tecplotlib, datafun);
    }
    else if (strstr(argv[1], ".t16") != NULL) {
        filetype = VDM_MARC_POST;
        marclib = vdm_MarcLibBegin();
        vdm_MarcLibDataFun(marclib, datafun);
    }
    else {
        fprintf(stderr, "Error: Bad input file %s\n", argv[1]);
        exit(0);
    }
    /* set conventions */
    vdm_DataFunSetConvention(datafun, VDM_CONVENTION_SPARSE);

    /* open library device */
    vdm_DataFunOpen(datafun, 0, argv[1], filetype);
    vdm_DataFunGetLibrary(datafun, &library);

    /* check for error */
    ierr = vdm_DataFunError(datafun);
    if (ierr) {
        fprintf(stderr, "Error: opening file %s\n", argv[1]);
        exit(0);
    }
    /* instance lman object */
    lman = vdm_LManBegin();
    vdm_LManSetObject(lman, VDM_DATAFUN, datafun);
    vdm_LManSetParami(lman, LMAN_VERBOSE, SYS_ON);
    vdm_LManTOC(lman, "*");

    /* append library devices */
    for (i = 2; i < argc; i++) {
        if (strstr(argv[i], ".op2") != NULL || strstr(argv[i], ".OP2") != NULL) {
            filetype1 = VDM_NASTRAN_OUTPUT2;
        }
        else if (strstr(argv[i], ".unv") != NULL || strstr(argv[i], ".bun") != NULL || strstr(argv[i], ".bud") != NULL) {
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
        else if (strstr(argv[i], ".dat") != NULL || strstr(argv[i], ".cas") != NULL) {
            filetype1 = VDM_FLUENT_MESH;
        }
        else if (strstr(argv[i], ".cgns") != NULL) {
            filetype1 = VDM_CGNS;
        }
        else {
            fprintf(stderr, "Error: Bad input file %s\n", argv[i]);
            exit(0);
        }
        /* set Ids computation for certain appended file types */
        if (filetype1 == VDM_CGNS) {
            vdm_LibraryMaxIds(library, &id1, &id2, &id3);
            vdm_DataFunSetIds(datafun, VDM_IDS_BASE, id1 + 1, 0, 0);
        }
        vdm_DataFunAppend(datafun, argv[i], filetype1);

        /* check for error */
        ierr = vdm_DataFunError(datafun);
        if (ierr) {
            fprintf(stderr, "Error: appending file %s to file %s\n", argv[i], argv[1]);
            exit(0);
        }
        vdm_LManTOC(lman, "*");
    }
    /* now export all datasets */
    vdm_LManExport(lman, (Vchar*)"*", (Vchar*)"exam5.exp");
    vdm_LManEnd(lman);

    /* close library device */
    vdm_DataFunClose(datafun);

    /* free objects */
    vdm_DataFunEnd(datafun);

    if (filetype == VDM_NASTRAN_BULKDATA) {
        vdm_NASFilEnd(nasfil);
    }
    else if (filetype == VDM_SDRC_UNIVERSAL) {
        vdm_SDRCLibEnd(sdrclib);
    }
    else if (filetype == VDM_MECHANICA_STUDY) {
        vdm_RASLibEnd(raslib);
    }
    else if (filetype == VDM_ABAQUS_FIL) {
        vdm_ABALibEnd(abalib);
    }
    else if (filetype == VDM_ABAQUS_INPUT) {
        vdm_ABAFilEnd(abafil);
    }
    else if (filetype == VDM_ANSYS_RESULT) {
        vdm_ANSLibEnd(anslib);
    }
    else if (filetype == VDM_ANSYS_INPUT) {
        vdm_ANSFilEnd(ansfil);
    }
    else if (filetype == VDM_NASTRAN_OUTPUT2) {
        vdm_NASLibEnd(naslib);
    }
    else if (filetype == VDM_LSTC_INPUT) {
        vdm_D3DFilEnd(d3dfil);
    }
    else if (filetype == VDM_LSTC_STATE) {
        vdm_D3DLibEnd(d3dlib);
    }
    else if (filetype == VDM_NATIVE) {
        vdm_NatLibEnd(natlib);
    }
    else if (filetype == VDM_PAM_DAISY) {
        vdm_PAMLibEnd(pamlib);
    }
    else if (filetype == VDM_PATRAN_NEUTRAL) {
        vdm_PatLibEnd(patlib);
    }
    else if (filetype == VDM_PLOT3D_GRID) {
        vdm_PLOT3DLibEnd(plot3dlib);
    }
    else if (filetype == VDM_FLUENT_MESH) {
        vdm_FLUENTLibEnd(fluentlib);
    }
    else if (filetype == VDM_CGNS) {
        vdm_CGNSVLibEnd(cgnsvlib);
    }
    else if (filetype == VDM_SAMCEF) {
        vdm_SAMCEFLibEnd(samceflib);
    }
    else if (filetype == VDM_ENSIGHT) {
        vdm_EnSightLibEnd(ensightlib);
    }
    else if (filetype == VDM_STARCCM) {
        vdm_STARCCMLibEnd(starccmlib);
    }
    else if (filetype == VDM_TECPLOT) {
        vdm_TecplotLibEnd(tecplotlib);
    }
    else if (filetype == VDM_MARC_POST) {
        vdm_MarcLibEnd(marclib);
    }
    return 0;
}
