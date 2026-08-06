#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/vdm/vdm.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static void
printShellBeam(vis_Model* model);

/*----------------------------------------------------------------------
                      Compute Shell and Beam Local Coordinate Systems
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    char inputfile[256];
    vdm_ABAFil* abafil = NULL;
    vdm_ABALib* abalib = NULL;
    vdm_ANSFil* ansfil = NULL;
    vdm_ANSLib* anslib = NULL;
    vdm_NASFil* nasfil = NULL;
    vdm_NASLib* naslib = NULL;
    vdm_NatLib* natlib = NULL;
    vdm_SDRCLib* sdrclib = NULL;
    vdm_DataFun* datafun = NULL;
    vdm_LMan* lman = NULL;
    Vint filetype = 0;
    vis_Model* model = NULL;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s inputfile\n", argv[0]);
        fprintf(stderr, " inputfile is blank, 'shell.bdf' is assumed\n");
        strcpy(inputfile, "shell.bdf");
    }
    else {
        strcpy(inputfile, argv[1]);
    }

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create data function object */
    datafun = vdm_DataFunBegin();

    /* determine file type from file extension */
    if (strstr(inputfile, ".bdf") != NULL || strstr(inputfile, ".dat") != NULL) {
        filetype = VDM_NASTRAN_BULKDATA;
        nasfil = vdm_NASFilBegin();
        vdm_NASFilDataFun(nasfil, datafun);
        printf("Nastran Bulk Data File: %s\n", inputfile);
    }
    else if (strstr(inputfile, ".op2") != NULL) {
        filetype = VDM_NASTRAN_OUTPUT2;
        naslib = vdm_NASLibBegin();
        vdm_NASLibDataFun(naslib, datafun);
        printf("Nastran Output2 File: %s\n", inputfile);
    }
    else if (strstr(inputfile, ".vdm") != NULL) {
        filetype = VDM_NATIVE;
        natlib = vdm_NatLibBegin();
        vdm_NatLibDataFun(natlib, datafun);
        printf("Native File: %s\n", inputfile);
    }
    else if (strstr(inputfile, ".inp") != NULL) {
        filetype = VDM_ABAQUS_INPUT;
        abafil = vdm_ABAFilBegin();
        vdm_ABAFilDataFun(abafil, datafun);
        printf("Abaqus Input File: %s\n", inputfile);
    }
    else if (strstr(inputfile, ".fil") != NULL) {
        filetype = VDM_ABAQUS_FIL;
        abalib = vdm_ABALibBegin();
        vdm_ABALibDataFun(abalib, datafun);
        printf("Abaqus Binary (.fil) File: %s\n", inputfile);
    }
    else if (strstr(inputfile, ".cdb") != NULL) {
        filetype = VDM_ANSYS_INPUT;
        ansfil = vdm_ANSFilBegin();
        vdm_ANSFilDataFun(ansfil, datafun);
        printf("Ansys Input File: %s\n", inputfile);
    }
    else if (strstr(inputfile, ".rst") != NULL) {
        filetype = VDM_ANSYS_RESULT;
        anslib = vdm_ANSLibBegin();
        vdm_ANSLibDataFun(anslib, datafun);
        printf("Ansys Result (.rst) File: %s\n", inputfile);
    }
    else if (strstr(inputfile, ".unv") != NULL) {
        filetype = VDM_SDRC_UNIVERSAL;
        sdrclib = vdm_SDRCLibBegin();
        vdm_SDRCLibDataFun(sdrclib, datafun);
        printf("SDRC Universal File: %s\n", inputfile);
    }
    else {
        fprintf(stderr, "Error: Bad input file %s\n", inputfile);
        exit(1);
    }
    /* open library device */
    vdm_DataFunOpen(datafun, 0, inputfile, filetype);

    /* instance model object for finite element model */
    model = vis_ModelBegin();

    /* use Library Manager object to load model */
    lman = vdm_LManBegin();
    vdm_LManSetObject(lman, VDM_DATAFUN, datafun);
    vdm_LManLoadModel(lman, model);
    if (vdm_LManError(lman)) {
        fprintf(stderr, "Error: Unable to load model information\n");
        exit(1);
    }
    /* close library device and delete interface */
    vdm_DataFunClose(datafun);
    vdm_DataFunEnd(datafun);
    if (filetype == VDM_NASTRAN_BULKDATA) {
        vdm_NASFilEnd(nasfil);
    }
    else if (filetype == VDM_NASTRAN_OUTPUT2) {
        vdm_NASLibEnd(naslib);
    }
    else if (filetype == VDM_NATIVE) {
        vdm_NatLibEnd(natlib);
    }
    else if (filetype == VDM_ABAQUS_INPUT) {
        vdm_ABAFilEnd(abafil);
    }
    else if (filetype == VDM_ABAQUS_FIL) {
        vdm_ABALibEnd(abalib);
    }
    else if (filetype == VDM_ANSYS_INPUT) {
        vdm_ANSFilEnd(ansfil);
    }
    else if (filetype == VDM_ANSYS_RESULT) {
        vdm_ANSLibEnd(anslib);
    }
    else if (filetype == VDM_SDRC_UNIVERSAL) {
        vdm_SDRCLibEnd(sdrclib);
    }
    vdm_LManEnd(lman);

    /* print shell and beam systems */
    printShellBeam(model);
    /* delete objects registered in Model */
    vis_ModelDelete(model);
    /* destroy Model object itself */
    vis_ModelEnd(model);
    return 0;
}

/*----------------------------------------------------------------------
                      print shell and beam coordinate systems
----------------------------------------------------------------------*/
static void
computeShellBeam(Vint index, Vint featype, Vint cid, Vint shape, Vint maxi, Vint maxj, vis_ShellElem* shellelem,
                 vis_BeamElem* beamelem, vsy_HashTable* coordsyshash, vis_ElemDat* elemdat, Vfloat xe[][3], Vfloat tme[3][3])
{
    Vfloat xo[3], tm[3][3];
    vis_CoordSys* coordsys;
    Vint type;
    Vfloat vec[3];
    /* user defined coordinate system */
    if (cid > 0) {
        if (coordsyshash == NULL) {
            printf("Error: no HashTable of CoordSys objects\n");
            exit(0);
        }
        vsy_HashTableLookup(coordsyshash, cid, (Vobject**)&coordsys);
        if (coordsys == NULL) {
            printf("Error: no CoordSys object\n");
            exit(0);
        }
        vis_CoordSysOriginTriad(coordsys, xo, tm);
        type = SYS_ELEMSYS_VECTOR;
        vec[0] = tm[0][0];
        vec[1] = tm[0][1];
        vec[2] = tm[0][2];
        /* algorithmic */
    }
    else if (cid < 0) {
        type = cid;
        if (elemdat) {
            vis_ElemDatData(elemdat, index, 0, vec);
        }
        /* global, cid = 0 */
    }
    else {
        type = cid;
    }
    /* shell or beam */
    if (featype == SYS_ELEM_SHELL) {
        vis_ShellElemSetTopology(shellelem, shape, maxi, maxj);
        vis_ShellElemSetLocalSystem(shellelem, type, vec, 0.);
        vis_ShellElemDirCos(shellelem, SYS_ON, xe, (Vfloat(*)[3][3])tme);
    }
    else if (featype == SYS_ELEM_BEAM) {
        vis_BeamElemSetTopology(beamelem, shape, maxi);
        vis_BeamElemSetLocalSystem(beamelem, type, vec, 0.);
        vis_BeamElemDirCos(beamelem, SYS_ON, xe, VIS_NODATA, NULL, VIS_NODATA, NULL, (Vfloat(*)[3][3])tme);
    }
}

static void
printShellBeam(vis_Model* model)
{
    Vint i;
    Vint numnp, numel;
    Vint eid, csysid, cmatid, cmatflag;
    Vint featype;
    Vfloat xe[16][3], tme[3][3];
    Vint nix, ix[16];
    Vint shape, maxi, maxj, maxk;
    vis_Connect* connect;
    vis_ShellElem* shellelem;
    vis_BeamElem* beamelem;
    vsy_HashTable *elemdathash, *coordsyshash;
    vis_ElemDat *edcsysid = NULL, *edcmatid = NULL;

    vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);
    if (connect == NULL) {
        printf("Error: no Connect object\n");
        exit(0);
    }
    vis_ModelGetHashTable(model, VIS_ELEMDAT, &elemdathash);
    if (elemdathash) {
        vsy_HashTableLookup(elemdathash, SYS_PROP_ELEMVEC, (Vobject**)&edcsysid);
        vsy_HashTableLookup(elemdathash, SYS_PROP_MATLVEC, (Vobject**)&edcmatid);
    }
    vis_ModelGetHashTable(model, VIS_COORDSYS, &coordsyshash);

    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("Number of nodes=    %d\n", numnp);
    printf("Number of elements= %d\n", numel);
    shellelem = vis_ShellElemBegin();
    beamelem = vis_BeamElemBegin();

    /* process shell and beam elements */
    for (i = 1; i <= numel; i++) {
        vis_ConnectElemAssoc(connect, VIS_FEATYPE, 1, &i, &featype);
        if (featype != SYS_ELEM_SHELL && featype != SYS_ELEM_BEAM)
            continue;
        vis_ConnectTopology(connect, i, &shape, &maxi, &maxj, &maxk);
        vis_ConnectElemNode(connect, i, &nix, ix);
        vis_ConnectCoords(connect, nix, ix, xe);
        vis_ConnectElemAssoc(connect, VIS_USERID, 1, &i, &eid);
        vis_ConnectElemAssoc(connect, VIS_CSYSID, 1, &i, &csysid);
        vis_ConnectElemAssoc(connect, VIS_CMATFLAG, 1, &i, &cmatflag);
        vis_ConnectElemAssoc(connect, VIS_CMATID, 1, &i, &cmatid);
        /* element results in CSYSID system */
        computeShellBeam(i, featype, csysid, shape, maxi, maxj, shellelem, beamelem, coordsyshash, edcsysid, xe, tme);
        printf("element= %d, element result system= %d\n", eid, csysid);
        printf("x'= %10f %10f %10f\n", tme[0][0], tme[0][1], tme[0][2]);
        printf("y'= %10f %10f %10f\n", tme[1][0], tme[1][1], tme[1][2]);
        printf("z'= %10f %10f %10f\n", tme[2][0], tme[2][1], tme[2][2]);
        /* element CMATID system */
        if (cmatflag) {
            computeShellBeam(i, featype, cmatid, shape, maxi, maxj, shellelem, beamelem, coordsyshash, edcmatid, xe, tme);
            printf("element= %d, element material system= %d\n", eid, cmatid);
            printf("x'= %10f %10f %10f\n", tme[0][0], tme[0][1], tme[0][2]);
            printf("y'= %10f %10f %10f\n", tme[1][0], tme[1][1], tme[1][2]);
            printf("z'= %10f %10f %10f\n", tme[2][0], tme[2][1], tme[2][2]);
        }
    }
    vis_ShellElemEnd(shellelem);
    vis_BeamElemEnd(beamelem);
}
