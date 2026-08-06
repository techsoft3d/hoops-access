#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "sam/base/base.h"
#include "sam/vis/visdata.h"
#include "sam/vdm/vdm.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static void
print_fluent(vis_Model* model);
static void
check_2d(vis_Model* model, Vint* flag_2d);
static void
convert_2d(vis_Model* model);
static void
mod_partid_elemset(vis_Model* model);
static void
add_inter_nodeset(vis_Model* model);
static void
add_inter_elementset(vis_Model* model);
static void
process_ensight(vis_Model* model);
static void
process_shelltointer(vis_Model* model);
static void
process_contacttoshell(vis_Model* model);
static void
ignore_periodic1d(vis_Model* model);

/*----------------------------------------------------------------------
                     Read and Print Finite Element Model in Fluent Form
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    Vchar inputfile[256];
    Vchar suffix[256];
    Vint i, slen;

    vdm_NASFil* nasfil = NULL;
    vdm_NASLib* naslib = NULL;
    vdm_NatLib* natlib = NULL;
    vdm_SDRCLib* sdrclib = NULL;
    vdm_ANSFil* ansfil = NULL;
    vdm_ANSLib* anslib = NULL;
    vdm_ABAFil* abafil = NULL;
    vdm_ABALib* abalib = NULL;
    vdm_D3DFil* d3dfil = NULL;
    vdm_D3DLib* d3dlib = NULL;
    vdm_HMAFil* hmafil = NULL;
    vdm_STLFil* stlfil = NULL;
    vdm_PLOT3DLib* plot3dlib = NULL;
    vdm_FLUENTLib* fluentlib = NULL;
    vdm_EnSightLib* ensightlib = NULL;
    vdm_TecplotLib* tecplotlib = NULL;
    vdm_MarcLib* marclib = NULL;
    vdm_CGNSVLib* cgnsvlib = NULL;
    vdm_PatLib* patlib = NULL;
    vdm_RASLib* raslib = NULL;
    Vint ierr;

    vdm_DataFun* datafun = NULL;
    vdm_LMan* lman = NULL;
    Vint filetype;
    vis_Model* model = NULL;
    Vint flag_2d;

    /* check input arguments */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s inputfile\n", argv[0]);
        fprintf(stderr, " inputfile is blank, 'cantilever.unv' is assumed\n");
        strcpy(inputfile, "cantilever.unv");
    }
    else {
        strcpy(inputfile, argv[1]);
    }
    /* find suffix */
    slen = (Vint)strlen(inputfile);
    for (i = slen - 2; i != 0; i--) {
        if (inputfile[i] == '.') {
            strcpy(suffix, &inputfile[i]);
            break;
        }
    }

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create data function object */
    datafun = vdm_DataFunBegin();

    /* determine file type from file extension */
    if (strstr(suffix, ".unv") != NULL) {
        filetype = VDM_SDRC_UNIVERSAL;
        sdrclib = vdm_SDRCLibBegin();
        vdm_SDRCLibDataFun(sdrclib, datafun);
    }
    else if (strstr(suffix, ".dat") != NULL || strstr(suffix, ".bdf") != NULL || strstr(suffix, ".nas") != NULL) {
        filetype = VDM_NASTRAN_BULKDATA;
        nasfil = vdm_NASFilBegin();
        vdm_NASFilDataFun(nasfil, datafun);
    }
    else if (strstr(suffix, ".op2") != NULL) {
        filetype = VDM_NASTRAN_OUTPUT2;
        naslib = vdm_NASLibBegin();
        vdm_NASLibDataFun(naslib, datafun);
    }
    else if (strstr(suffix, ".vdm") != NULL) {
        filetype = VDM_NATIVE;
        natlib = vdm_NatLibBegin();
        vdm_NatLibDataFun(natlib, datafun);
    }
    else if (strstr(suffix, ".cdb") != NULL || strstr(suffix, ".ans") != NULL) {
        filetype = VDM_ANSYS_INPUT;
        ansfil = vdm_ANSFilBegin();
        vdm_ANSFilDataFun(ansfil, datafun);
    }
    else if (strstr(suffix, ".rst") != NULL || strstr(suffix, ".rth") != NULL || strstr(suffix, ".rmg") != NULL ||
             strstr(suffix, ".rfl") != NULL) {
        filetype = VDM_ANSYS_RESULT;
        anslib = vdm_ANSLibBegin();
        vdm_ANSLibDataFun(anslib, datafun);
    }
    else if (strstr(suffix, ".inp") != NULL) {
        filetype = VDM_ABAQUS_INPUT;
        abafil = vdm_ABAFilBegin();
        vdm_ABAFilDataFun(abafil, datafun);
    }
    else if (strstr(suffix, ".fil") != NULL) {
        filetype = VDM_ABAQUS_FIL;
        abalib = vdm_ABALibBegin();
        vdm_ABALibDataFun(abalib, datafun);
    }
    else if (strstr(suffix, ".odb") != NULL) {
        filetype = VDM_ABAQUS_ODB;
        abalib = vdm_ABALibBegin();
        vdm_ABALibDataFun(abalib, datafun);
    }
    else if (strstr(suffix, ".k") != NULL || strstr(suffix, ".dyn") != NULL) {
        filetype = VDM_LSTC_INPUT;
        d3dfil = vdm_D3DFilBegin();
        vdm_D3DFilDataFun(d3dfil, datafun);
    }
    else if (strstr(suffix, "d3plot") != NULL || strstr(suffix, "D3PLOT") != NULL) {
        filetype = VDM_LSTC_STATE;
        d3dlib = vdm_D3DLibBegin();
        vdm_D3DLibDataFun(d3dlib, datafun);
    }
    else if (strstr(suffix, ".hma") != NULL) {
        filetype = VDM_HYPERMESH_ASCII;
        hmafil = vdm_HMAFilBegin();
        vdm_HMAFilDataFun(hmafil, datafun);
    }
    else if (strstr(suffix, ".stl") != NULL) {
        filetype = VDM_STL;
        stlfil = vdm_STLFilBegin();
        vdm_STLFilDataFun(stlfil, datafun);
    }
    else if (strstr(suffix, ".STL") != NULL) {
        filetype = VDM_STLBIN;
        stlfil = vdm_STLFilBegin();
        vdm_STLFilDataFun(stlfil, datafun);
    }
    else if (strstr(suffix, ".x") != NULL || strstr(suffix, ".xyz") != NULL || strstr(suffix, ".p3d") != NULL ||
             strstr(suffix, ".bin") != NULL || strstr(suffix, ".grd") != NULL) {
        filetype = VDM_PLOT3D_GRID;
        plot3dlib = vdm_PLOT3DLibBegin();
        vdm_PLOT3DLibDataFun(plot3dlib, datafun);
    }
    else if (strstr(suffix, ".case") != NULL || strstr(suffix, ".encas") != NULL) {
        filetype = VDM_ENSIGHT;
        ensightlib = vdm_EnSightLibBegin();
        vdm_EnSightLibDataFun(ensightlib, datafun);
    }
    else if (strstr(suffix, ".plt") != NULL) {
        filetype = VDM_TECPLOT;
        tecplotlib = vdm_TecplotLibBegin();
        vdm_TecplotLibDataFun(tecplotlib, datafun);
    }
    else if (strstr(suffix, ".cas") != NULL || strstr(suffix, ".msh") != NULL) {
        filetype = VDM_FLUENT_MESH;
        fluentlib = vdm_FLUENTLibBegin();
        vdm_FLUENTLibDataFun(fluentlib, datafun);
    }
    else if (strstr(suffix, ".t16") != NULL || strstr(suffix, ".t19") != NULL) {
        filetype = VDM_MARC_POST;
        marclib = vdm_MarcLibBegin();
        vdm_MarcLibDataFun(marclib, datafun);
    }
    else if (strstr(suffix, ".cgns") != NULL) {
        filetype = VDM_CGNS;
        cgnsvlib = vdm_CGNSVLibBegin();
        vdm_CGNSVLibDataFun(cgnsvlib, datafun);
    }
    else if (strstr(suffix, ".out") != NULL) {
        filetype = VDM_PATRAN_NEUTRAL;
        patlib = vdm_PatLibBegin();
        vdm_PatLibDataFun(patlib, datafun);
    }
    else if (strstr(suffix, ".neu") != NULL) {
        filetype = VDM_MECHANICA_STUDY;
        raslib = vdm_RASLibBegin();
        vdm_RASLibDataFun(raslib, datafun);
    }
    else {
        fprintf(stderr, "Error: Bad input file %s\n", inputfile);
        exit(1);
    }
    /* double precision is used to represent node location */
    vdm_DataFunSetConvention(datafun, VDM_CONVENTION_DOUBLE | VDM_CONVENTION_CONVERTPOLY);
    /* open library device */
    vdm_DataFunOpen(datafun, 0, inputfile, filetype);

    /* check for error */
    ierr = vdm_DataFunError(datafun);
    if (ierr) {
        fprintf(stderr, "Error: opening file %s\n", inputfile);
        goto labelcleanup;
    }
    /* instance Model object for finite element model */
    model = vis_ModelBegin();

    /* use Library Manager object to load model */
    lman = vdm_LManBegin();
    vdm_LManSetObject(lman, VDM_DATAFUN, datafun);
    vdm_LManLoadModel(lman, model);

    /* check for 2D */
    check_2d(model, &flag_2d);
    /* force conversion to 2D */
    if (flag_2d) {
        convert_2d(model);
    }
    /* ignore CGNS periodic 1D line elements */
    if (filetype == VDM_CGNS) {
        ignore_periodic1d(model);
    }
    /* modify partid by element set,
       add interface elements for each node set */
    if (filetype == VDM_SDRC_UNIVERSAL || filetype == VDM_PATRAN_NEUTRAL) {
        mod_partid_elemset(model);
        add_inter_nodeset(model);
    }
    /* add interface elements for each node set */
    if (filetype == VDM_ABAQUS_INPUT || filetype == VDM_ANSYS_INPUT) {
        add_inter_nodeset(model);
    }
    if (filetype == VDM_ANSYS_RESULT) {
        process_contacttoshell(model);
    }
    /* Ensight file, merge nodes, convert shell to interface */
    if (filetype == VDM_ENSIGHT) {
        process_ensight(model);
        process_shelltointer(model);
    }
    /* NASTRAN .bdf file, convert shell to interface */
    if (filetype == VDM_NASTRAN_BULKDATA || filetype == VDM_TECPLOT || filetype == VDM_CGNS) {
        process_shelltointer(model);
    }
    /* add interface elements for each element entity set */
    if (filetype == VDM_CGNS || filetype == VDM_PLOT3D_GRID || filetype == VDM_STARCCM || filetype == VDM_FLUENT_MESH) {
        add_inter_elementset(model);
    }
    /* traverse Model and print in Fluent form */
    print_fluent(model);
    /* delete objects in Model created by LManLoadModel */
    vis_ModelDelete(model);
    vdm_LManEnd(lman);
    vis_ModelEnd(model);

    /* close library device */
labelcleanup:;
    vdm_DataFunClose(datafun);

    /* free objects */
    vdm_DataFunEnd(datafun);
    if (filetype == VDM_SDRC_UNIVERSAL) {
        vdm_SDRCLibEnd(sdrclib);
    }
    else if (filetype == VDM_NASTRAN_BULKDATA) {
        vdm_NASFilEnd(nasfil);
    }
    else if (filetype == VDM_NASTRAN_OUTPUT2) {
        vdm_NASLibEnd(naslib);
    }
    else if (filetype == VDM_NATIVE) {
        vdm_NatLibEnd(natlib);
    }
    else if (filetype == VDM_ANSYS_INPUT) {
        vdm_ANSFilEnd(ansfil);
    }
    else if (filetype == VDM_ANSYS_RESULT) {
        vdm_ANSLibEnd(anslib);
    }
    else if (filetype == VDM_ABAQUS_INPUT) {
        vdm_ABAFilEnd(abafil);
    }
    else if (filetype == VDM_ABAQUS_FIL || filetype == VDM_ABAQUS_ODB) {
        vdm_ABALibEnd(abalib);
    }
    else if (filetype == VDM_LSTC_INPUT) {
        vdm_D3DFilEnd(d3dfil);
    }
    else if (filetype == VDM_LSTC_STATE) {
        vdm_D3DLibEnd(d3dlib);
    }
    else if (filetype == VDM_HYPERMESH_ASCII) {
        vdm_HMAFilEnd(hmafil);
    }
    else if (filetype == VDM_STL || filetype == VDM_STLBIN) {
        vdm_STLFilEnd(stlfil);
    }
    else if (filetype == VDM_PLOT3D_GRID) {
        vdm_PLOT3DLibEnd(plot3dlib);
    }
    else if (filetype == VDM_FLUENT_MESH) {
        vdm_FLUENTLibEnd(fluentlib);
    }
    else if (filetype == VDM_ENSIGHT) {
        vdm_EnSightLibEnd(ensightlib);
    }
    else if (filetype == VDM_TECPLOT) {
        vdm_TecplotLibEnd(tecplotlib);
    }
    else if (filetype == VDM_MARC_POST) {
        vdm_MarcLibEnd(marclib);
    }
    else if (filetype == VDM_CGNS) {
        vdm_CGNSVLibEnd(cgnsvlib);
    }
    else if (filetype == VDM_PATRAN_NEUTRAL) {
        vdm_PatLibEnd(patlib);
    }
    else if (filetype == VDM_MECHANICA_STUDY) {
        vdm_RASLibEnd(raslib);
    }
    return 0;
}

/*----------------------------------------------------------------------
                      check 2d
----------------------------------------------------------------------*/
static void
check_2d(vis_Model* model, Vint* flag_2d)
{
    Vint n;
    vis_Connect* connect;
    Vint numnp, numel, ndim;
    Vint shape, maxi, maxj, maxk;
    Vdouble x[3];

    *flag_2d = 0;
    /* get connect object */
    vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);
    /* check for 2D */
    vis_ConnectDimension(connect, &ndim);
    if (ndim == 2) {
        return;
    }
    /* 3D, check for 2D */
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    /* 3D shapes */
    for (n = 1; n <= numel; n++) {
        vis_ConnectTopology(connect, n, &shape, &maxi, &maxj, &maxk);
        if (shape == SYS_SHAPETET || shape == SYS_SHAPEPYR || shape == SYS_SHAPEWED || shape == SYS_SHAPEHEX ||
            shape == SYS_SHAPEPOLYHED) {
            return;
        }
    }
    /* no 3D shapes, check for zero or very small z coordinate */
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    for (n = 1; n <= numnp; n++) {
        vis_ConnectCoordsdv(connect, 1, &n, (Vdouble(*)[3])x);
        if (fabs(x[2]) > 1.e-12) {
            return;
        }
    }
    *flag_2d = 1;
}

/*----------------------------------------------------------------------
                      convert 2d
----------------------------------------------------------------------*/
static void
convert_2d(vis_Model* model)
{
    Vint n;
    vis_Connect* connect;
    Vint numel;
    Vint shape, maxi, maxj, maxk;
    Vint featype;
    /* get connect object */
    vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);
    /* set 2D */
    vis_ConnectSetDimension(connect, 2);
    /* find out current number of elements */
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    /* loop through elements */
    /* convert 2d shells and membranes to solids */
    /* convert 1d beams and trusses to interfaces */
    for (n = 1; n <= numel; n++) {
        vis_ConnectTopology(connect, n, &shape, &maxi, &maxj, &maxk);
        vis_ConnectElemAssoc(connect, VIS_FEATYPE, 1, &n, &featype);
        if ((featype == VIS_ELEM_SHELL || featype == VIS_ELEM_MEMBRANE) && (shape == VIS_SHAPETRI || shape == VIS_SHAPEQUAD)) {
            vis_ConnectSetElemAssoc(connect, VIS_FEATYPE, n, SYS_ELEM_SOLID);
            vis_ConnectSetElemAssoc(connect, VIS_FEASPEC, n, 0);
        }
        if ((featype == VIS_ELEM_BEAM || featype == VIS_ELEM_TRUSS) && shape == VIS_SHAPELINE) {
            vis_ConnectSetElemAssoc(connect, VIS_FEATYPE, n, SYS_ELEM_INTER);
            vis_ConnectSetElemAssoc(connect, VIS_FEASPEC, n, SYS_INTER_WALL);
        }
    }
}

/*----------------------------------------------------------------------
                      modify part id for each element set
----------------------------------------------------------------------*/
static void
mod_partid_elemset(vis_Model* model)
{
    Vint n, m;
    Vint numel;
    Vint id;
    vsy_HashTable* esethash;
    vis_Connect* connect;
    vis_IdTran* idtran;
    Vint iset;
    Vint numindices;
    Vchar name[256];
    Vint maxpartid, partid;

    /* get connect object */
    vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    /* get hashtable of elem sets */
    vis_ModelGetHashTable(model, VIS_IDTRAN_ELEM, &esethash);
    if (esethash == NULL)
        return;
    /* find highest partid */
    maxpartid = 0;
    for (m = 1; m <= numel; m++) {
        vis_ConnectElemAssoc(connect, VIS_PARTID, 1, &m, &partid);
        if (partid > maxpartid)
            maxpartid = partid;
    }
    /* loop through elem sets */
    vsy_HashTableInitIter(esethash);
    while (vsy_HashTableNextIter(esethash, &iset, (Vobject**)&idtran), idtran) {
        vis_IdTranGetName(idtran, name);
        maxpartid += 1;
        vis_ConnectSetPartName(connect, maxpartid, name);
        vis_IdTranCount(idtran, IDTRAN_NUMINDICES, &numindices);
        for (n = 1; n <= numindices; n++) {
            vis_IdTranGetId(idtran, n, &id);
            vis_ConnectSetElemAssoc(connect, VIS_PARTID, id, maxpartid);
        }
    }
}

/*----------------------------------------------------------------------
                      ignore periodic 1D elements
----------------------------------------------------------------------*/
static void
ignore_periodic1d(vis_Model* model)
{
    vis_Connect* connect;
    Vint numel, n, featype, feaspec;

    vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    for (n = 1; n <= numel; ++n) {
        vis_ConnectElemAssoc(connect, VIS_FEATYPE, 1, &n, &featype);
        vis_ConnectElemAssoc(connect, VIS_FEASPEC, 1, &n, &feaspec);
        if (featype == SYS_ELEM_INTER && feaspec == SYS_INTER_PERIODIC) {
            vis_ConnectSetElemAssoc(connect, VIS_FEATYPE, n, SYS_ELEM_UNDEFINED);
        }
    }
}

/*----------------------------------------------------------------------
                      add interface elements for each node set
----------------------------------------------------------------------*/
static void
add_inter_nodeset(vis_Model* model)
{
    Vint i, j, n;
    vsy_HashTable* nsethash;
    vis_Connect* connect;
    vis_IdTran* idtran;
    Vint iset;
    Vint numnp, numel;
    Vint ndim;
    Vint index;
    Vint surftype, nfaces;
    vis_Group *groupsurf, *groupfree, *groupnode;
    Vint nix;
    Vint ix[VIS_MAXCELLNODE];
    Vint shape, maxi, maxj;
    Vint iwhole, numset, imatch;
    Vint featype, feaspec;
    Vint intel, newel;
    Vint namelen;
    Vchar name[256], namelow[256], namestg[256];
    Vint numpar, numchd;
    Vint maxpartid, partid;

    /* get connect object */
    vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);
    /* get hashtable of node sets */
    vis_ModelGetHashTable(model, VIS_IDTRAN_NODE, &nsethash);
    if (nsethash == NULL)
        return;

    /* find out current number of nodes and elements */
    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);

    /* determine spatial dimension and surface type */
    vis_ConnectDimension(connect, &ndim);
    if (ndim == 2) {
        surftype = SYS_EDGE;
    }
    else {
        surftype = SYS_FACE;
    }
    /* generate kernel */
    vis_ConnectKernel(connect, 0);

    /* generate working node groups */
    groupnode = vis_GroupBegin();
    vis_GroupDef(groupnode, numnp, SYS_NODE, SYS_NONE);

    /* generate group of surface element faces */
    groupsurf = vis_GroupBegin();
    vis_GroupDef(groupsurf, numel, SYS_ELEM, surftype);
    groupfree = vis_GroupBegin();
    vis_GroupDef(groupfree, numel, SYS_ELEM, surftype);
    if (surftype == SYS_EDGE) {
        vis_ConnectEdgeGroup(connect, CONNECT_ELEM, NULL, groupsurf);
    }
    else {
        vis_ConnectFaceGroup(connect, CONNECT_ELEM, NULL, groupsurf);
    }
    vis_GroupCount(groupsurf, &numpar, &numchd);

    /* no surface elements so use solid element faces */
    if (numpar == 0) {
        if (surftype == SYS_EDGE) {
            vis_ConnectEdgeGroup(connect, CONNECT_UNIQUE, NULL, groupsurf);
            vis_ConnectEdgeGroup(connect, CONNECT_FREE, NULL, groupfree);
        }
        else {
            vis_ConnectFaceGroup(connect, CONNECT_UNIQUE, NULL, groupsurf);
            vis_ConnectFaceGroup(connect, CONNECT_FREE, NULL, groupfree);
        }
    }
    /* find highest partid */
    maxpartid = 0;
    for (n = 1; n <= numel; n++) {
        vis_ConnectElemAssoc(connect, VIS_PARTID, 1, &n, &partid);
        if (partid > maxpartid)
            maxpartid = partid;
    }

    newel = numel;
    /* loop through node sets */
    vsy_HashTableInitIter(nsethash);
    while (vsy_HashTableNextIter(nsethash, &iset, (Vobject**)&idtran), idtran) {
        /* convert idtran to group for performance */
        vis_GroupClear(groupnode);
        vis_GroupIdTran(groupnode, idtran);
        iwhole = 1;
        /* process node sets which do not reference entire solid */
        for (n = 1; n <= numel; n++) {
            vis_ConnectElemAssoc(connect, VIS_FEATYPE, 1, &n, &featype);
            if (featype != SYS_ELEM_SOLID)
                continue;
            /* check to see if node set covers whole element */
            numset = 0;
            vis_ConnectElemNode(connect, n, &nix, ix);
            for (i = 0; i < nix; i++) {
                vis_GroupGetIndex(groupnode, ix[i], &index);
                if (index)
                    numset += 1;
            }
            if (numset != nix) {
                iwhole = 0;
                break;
            }
        }
        if (iwhole)
            continue;

        /* set interface special type */
        vis_IdTranGetName(idtran, name);

        /* convert name to lower case */
        /* convert _ to - */
        namelen = (int)strlen(name);
        for (i = 0; i < namelen; i++) {
            namelow[i] = (Vchar)tolower(name[i]);
            if (namelow[i] == '_')
                namelow[i] = '-';
        }
        /* set names from IDEAS and rampant export */
        if (strncmp(namelow, "symmetry", 8) == 0) {
            feaspec = SYS_INTER_SYMMETRY;
        }
        else if (strncmp(namelow, "inlet", 5) == 0 || strncmp(namelow, "pinlet", 6) == 0 ||
                 strncmp(namelow, "pressure-inlet", 14) == 0) {
            feaspec = SYS_INTER_INLET;
        }
        else if (strncmp(namelow, "outlet", 6) == 0 || strncmp(namelow, "poutlet", 7) == 0 ||
                 strncmp(namelow, "pressure-outlet", 15) == 0) {
            feaspec = SYS_INTER_OUTLET;
        }
        else if (strncmp(namelow, "fan", 3) == 0) {
            feaspec = SYS_INTER_FAN;
        }
        else if (strncmp(namelow, "velocity-inlet", 14) == 0 || strncmp(namelow, "vinlet", 6) == 0) {
            feaspec = SYS_INTER_INLET_VELOCITY;
        }
        else if (strncmp(namelow, "outflow", 7) == 0) {
            feaspec = SYS_INTER_OUTFLOW;
        }
        else {
            feaspec = SYS_INTER_WALL;
        }
        if (strncmp(namelow, "interior", 8) == 0) {
            continue;
        }
        /* create and set name */
        sprintf(namestg, "%s", name);
        maxpartid += 1;
        vis_ConnectSetPartName(connect, maxpartid, namestg);

        /* loop through unique element faces */
        for (n = 1; n <= numel; n++) {
            if (vis_GroupElem(groupsurf, n) == 0)
                continue;
            vis_ConnectElemNum(connect, surftype, n, &nfaces);

            /* loop through element faces */
            for (j = 1; j <= nfaces; j++) {
                if (vis_GroupElemEnt(groupsurf, n, j) == 0)
                    continue;
                if (numpar == 0) {
                    if (vis_GroupElemEnt(groupfree, n, j) == 0)
                        continue;
                }
                vis_ConnectElemCon(connect, surftype, n, j, &nix, ix);

                /* check each node on face for match in node set */
                imatch = 1;
                for (i = 0; i < nix; i++) {
                    vis_GroupGetIndex(groupnode, ix[i], &index);
                    if (index == 0) {
                        imatch = 0;
                        break;
                    }
                }
                if (imatch == 0)
                    continue;
                /* create interface element */
                if (nfaces != 1) {
                    vis_ConnectElemTopo(connect, surftype, n, j, &shape, &maxi, &maxj);
                    newel += 1;
                    vis_ConnectSetTopology(connect, newel, shape, maxi, maxj, 0);
                    vis_ConnectSetElemNode(connect, newel, ix);
                    intel = newel;
                }
                else {
                    intel = n;
                }
                vis_ConnectSetElemAssoc(connect, VIS_FEATYPE, intel, SYS_ELEM_INTER);
                vis_ConnectSetElemAssoc(connect, VIS_FEASPEC, intel, feaspec);
                vis_ConnectSetElemAssoc(connect, VIS_PARTID, intel, maxpartid);
            }
        }
    }
    /* destroy objects */
    vis_GroupEnd(groupsurf);
    vis_GroupEnd(groupfree);
    vis_GroupEnd(groupnode);
}

/*----------------------------------------------------------------------
                      add interface elements for each element entity set
----------------------------------------------------------------------*/
static void
add_inter_elementset(vis_Model* model)
{
    Vint i, n;
    vsy_HashTable* eenthash;
    vis_Connect* connect;
    Vint numel;
    Vint iset;
    vis_IdTran* idtran;
    Vint nument, enttype, subtype;
    Vint featype, feaspec, partid, maxpartid;
    Vint id, no;
    Vint shape, maxi, maxj;
    Vint nix;
    Vint ix[VIS_MAXCELLNODE];
    Vchar name[256];

    /* get connect object */
    vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    /* get hashtable of elem sets */
    vis_ModelGetHashTable(model, VIS_IDTRAN_ELEMENT, &eenthash);
    if (eenthash == NULL)
        return;

    /* find highest partid */
    maxpartid = 0;
    for (n = 1; n <= numel; n++) {
        vis_ConnectElemAssoc(connect, VIS_PARTID, 1, &n, &partid);
        if (partid > maxpartid)
            maxpartid = partid;
    }
    /* loop through element entity sets */
    vsy_HashTableInitIter(eenthash);
    while (vsy_HashTableNextIter(eenthash, &iset, (Vobject**)&idtran), idtran) {
        vis_IdTranGetName(idtran, name);
        vis_IdTranGetEntType(idtran, &enttype, &subtype);
        vis_IdTranGetType(idtran, &featype);
        vis_IdTranGetSpec(idtran, &feaspec);
        maxpartid += 1;
        vis_ConnectSetPartName(connect, maxpartid, name);
        vis_IdTranInq(idtran, &nument);
        for (i = 1; i <= nument; i++) {
            vis_IdTranGetId(idtran, i, &id);
            vis_IdTranGetEnt(idtran, i, &no);
            vis_ConnectElemTopo(connect, subtype, id, no, &shape, &maxi, &maxj);
            vis_ConnectElemCon(connect, subtype, id, no, &nix, ix);
            numel += 1;
            vis_ConnectSetTopology(connect, numel, shape, maxi, maxj, 0);
            vis_ConnectSetElemNode(connect, numel, ix);
            vis_ConnectSetElemAssoc(connect, VIS_FEATYPE, numel, featype);
            vis_ConnectSetElemAssoc(connect, VIS_FEASPEC, numel, feaspec);
            vis_ConnectSetElemAssoc(connect, VIS_PARTID, numel, maxpartid);
        }
    }
}

/*----------------------------------------------------------------------
                      merge nodes and change shell elements to interfaces
----------------------------------------------------------------------*/
static void
process_ensight(vis_Model* model)
{
    vis_Connect* connect;

    vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);
    /* merge all coincident nodes */
    vis_ConnectSetParamf(connect, CONNECT_TOLERANCE, .0000001f);
    vis_ConnectMerge(connect, NULL);
}

/*----------------------------------------------------------------------
                      change shell elements to interfaces
----------------------------------------------------------------------*/
static void
process_shelltointer(vis_Model* model)
{
    Vint i, n;
    Vint numel, featype, feaspec, partid;
    vis_Connect* connect;
    Vint namelen;
    Vchar name[256], namelow[256];

    vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);
    /* change shell elements to interface elements */
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    for (n = 1; n <= numel; n++) {
        vis_ConnectElemAssoc(connect, VIS_FEATYPE, 1, &n, &featype);
        vis_ConnectElemAssoc(connect, VIS_PARTID, 1, &n, &partid);
        /* shell and inter only */
        if (featype != SYS_ELEM_SHELL && featype != SYS_ELEM_INTER)
            continue;
        /* no partid */
        if (partid == 0)
            continue;
        vis_ConnectPartName(connect, partid, name);
        namelen = (int)strlen(name);
        for (i = 0; i < namelen; i++) {
            namelow[i] = (Vchar)tolower(name[i]);
        }
        vis_ConnectElemAssoc(connect, VIS_FEASPEC, 1, &n, &feaspec);
        if (strncmp(namelow, "sym", 3) == 0 || strncmp(namelow, "symmetry", 8) == 0) {
            feaspec = SYS_INTER_SYMMETRY;
        }
        else if (strncmp(namelow, "pi", 2) == 0 || strncmp(namelow, "inlet", 5) == 0 || strncmp(namelow, "pinlet", 6) == 0 ||
                 strncmp(namelow, "pressure-inlet", 14) == 0) {
            feaspec = SYS_INTER_INLET_PRESSURE;
        }
        else if (strncmp(namelow, "po", 2) == 0 || strncmp(namelow, "outlet", 6) == 0 || strncmp(namelow, "poutlet", 7) == 0 ||
                 strncmp(namelow, "pressure-outlet", 15) == 0) {
            feaspec = SYS_INTER_OUTLET_PRESSURE;
        }
        else if (strncmp(namelow, "fan", 3) == 0) {
            feaspec = SYS_INTER_FAN;
        }
        else if (strncmp(namelow, "vinlet", 6) == 0 || strncmp(namelow, "velocity-inlet", 14) == 0) {
            feaspec = SYS_INTER_INLET_VELOCITY;
        }
        else if (strncmp(namelow, "outflow", 7) == 0) {
            feaspec = SYS_INTER_OUTFLOW;
        }
        else if (strncmp(namelow, "inte", 4) == 0 || strncmp(namelow, "baff", 4) == 0 || strncmp(namelow, "peri", 4) == 0 ||
                 strncmp(namelow, "interface", 9) == 0) {
            feaspec = SYS_INTER_INTERFACE;
        }
        else if (strncmp(namelow, "mass", 4) == 0 || strncmp(namelow, "mass-flow-inlet", 15) == 0) {
            feaspec = SYS_INTER_INLET_MASSFLOW;
        }
        else if (strncmp(namelow, "axis", 4) == 0) {
            feaspec = SYS_INTER_AXIS;
        }
        else if (strncmp(namelow, "fan", 3) == 0) {
            feaspec = SYS_INTER_FAN;
        }
        else if (strncmp(namelow, "pfield", 6) == 0 || strncmp(namelow, "pressure-far-field", 12) == 0) {
            feaspec = SYS_INTER_PRESSURE_FARFIELD;
        }
        else if (featype == SYS_ELEM_SHELL) {
            feaspec = SYS_INTER_WALL;
        }
        if (featype == SYS_ELEM_SHELL) {
            vis_ConnectSetElemAssoc(connect, VIS_FEATYPE, n, SYS_ELEM_INTER);
        }
        vis_ConnectSetElemAssoc(connect, VIS_FEASPEC, n, feaspec);
    }
}

/*----------------------------------------------------------------------
                      change contact elements to plot
----------------------------------------------------------------------*/
static void
process_contacttoshell(vis_Model* model)
{
    Vint n;
    Vint numel, featype, feaspec;
    vis_Connect* connect;

    vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);
    /* change shell elements to interface elements */
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    for (n = 1; n <= numel; n++) {
        vis_ConnectElemAssoc(connect, VIS_FEATYPE, 1, &n, &featype);
        vis_ConnectElemAssoc(connect, VIS_FEASPEC, 1, &n, &feaspec);
        if (featype == SYS_ELEM_INTER && feaspec == SYS_INTER_CONTACT) {
            vis_ConnectSetElemAssoc(connect, VIS_FEATYPE, n, SYS_ELEM_SHELL);
            vis_ConnectSetElemAssoc(connect, VIS_FEASPEC, n, 0);
        }
    }
}

/*----------------------------------------------------------------------
                      traverse and print in Fluent form
----------------------------------------------------------------------*/
static void
print_fluent(vis_Model* model)
{
    Vint i, j, k;
    vdm_FLUENTLib* fluentlibw;
    Vint ndim;
    Vint numcell, numface, numnode;
    Vint numcellzone, numfacezone;
    Vint zoneid, ifirst, ilast, type, etype, ftype;
    Vint num, nfx, nx, lenv;
    Vint *e = NULL, *v = NULL, *cr = NULL, *cl = NULL;
    Vdouble* x = NULL;
    Vchar zname[256];
    Vchar path[256];
    FILE* fd;
    /* open output file */
    strcpy(path, "exam6.msh");
    fd = fopen(path, "w");
    if (fd == NULL) {
        fprintf(stderr, "Can not open output file: %s\n", path);
        exit(1);
    }
    /* instance FLUENTLib for access */
    fluentlibw = vdm_FLUENTLibBegin();
    /* initialize */
    vdm_FLUENTLibInit(fluentlibw, model);

    /* grid, dimensions */
    fprintf(fd, "(0 \"Grid:\")\n");
    vdm_FLUENTLibDimension(fluentlibw, &ndim);
    fprintf(fd, "(0 \"Dimensions:\")\n");
    fprintf(fd, "(2 %d)\n", ndim);
    fprintf(fd, "\n");

    /* overall cell, face, node */
    vdm_FLUENTLibNumEntities(fluentlibw, &numcell, &numface, &numnode);
    if (numcell == 0) {
        fprintf(fd, "(12 (0 0 0 0))\n");
    }
    else {
        fprintf(fd, "(12 (0 1 %x 0))\n", numcell);
    }
    fprintf(fd, "(13 (0 1 %x 0))\n", numface);
    fprintf(fd, "(10 (0 1 %x 0 %d))\n", numnode, ndim);

    /* write nodes */
    fprintf(fd, "\n");
    fprintf(fd, "(10 (1 1 %x 1 %d)(\n", numnode, ndim);
    x = (Vdouble*)malloc(numnode * (ndim * sizeof(Vdouble)));
    vdm_FLUENTLibNode(fluentlibw, x);
    /* print 1 node to a line */
    for (i = 0; i < numnode; i++) {
        if (ndim == 2) {
            fprintf(fd, "%16.9e %16.9e", x[2 * i], x[2 * i + 1]);
        }
        else {
            fprintf(fd, "%25.16e %25.16e %25.16e", x[3 * i], x[3 * i + 1], x[3 * i + 2]);
        }
        if (i + 1 != numnode) {
            fprintf(fd, "\n");
        }
    }
    fprintf(fd, "))\n");
    free(x);

    /* get number of cell zones and face zones */
    vdm_FLUENTLibNumCellZone(fluentlibw, &numcellzone);
    vdm_FLUENTLibNumFaceZone(fluentlibw, &numfacezone);

    /* write faces, cycle through face zones */
    for (i = 1; i <= numfacezone; i++) {
        fprintf(fd, "\n");
        vdm_FLUENTLibFaceZoneParam(fluentlibw, i, &ifirst, &ilast, &type, &ftype);
        /* assign zoneid */
        zoneid = i + numcellzone;
        fprintf(fd, "(13 (%x %x %x %x %x)(\n", zoneid, ifirst, ilast, type, ftype);
        num = ilast - ifirst + 1;
        /* allocate memory */
        /* variable or polygon face type */
        if (ftype == 0 || ftype == 5) {
            e = (Vint*)malloc(num * sizeof(Vint));
            vdm_FLUENTLibFaceZoneType(fluentlibw, i, e);
            lenv = 0;
            for (j = 0; j < num; j++) {
                lenv += e[j];
            }
        }
        else {
            lenv = ftype * num;
        }
        v = (Vint*)malloc(lenv * sizeof(Vint));
        cl = (Vint*)malloc(num * sizeof(Vint));
        cr = (Vint*)malloc(num * sizeof(Vint));
        /* get face zone data */
        vdm_FLUENTLibFaceZone(fluentlibw, i, v, cr, cl);
        nx = 0;
        for (j = 0; j < num; j++) {
            /* variable or polygon face type */
            if (ftype == 0 || ftype == 5) {
                fprintf(fd, "%x ", e[j]);
                nfx = e[j];
                /* constant face type */
            }
            else {
                nfx = ftype;
            }
            /* face vertices */
            for (k = 0; k < nfx; k++) {
                fprintf(fd, "%x ", v[nx++]);
            }
            /* face adjacent cells */
            fprintf(fd, "%x %x", cr[j], cl[j]);
            if (j + 1 == num) {
                fprintf(fd, "))\n");
            }
            else {
                fprintf(fd, "\n");
            }
        }
        /* free memory */
        free(v);
        free(cl);
        free(cr);
        if (ftype == 0 || ftype == 5) {
            free(e);
        }
    }

    /* write cells, cycle through cell zones */
    for (i = 1; i <= numcellzone; i++) {
        fprintf(fd, "\n");
        vdm_FLUENTLibCellZoneParam(fluentlibw, i, &ifirst, &ilast, &type, &etype);
        /* assign zoneid */
        zoneid = i;
        /* constant element type */
        if (etype != 0) {
            fprintf(fd, "(12 (%x %x %x %x %x))\n", zoneid, ifirst, ilast, type, etype);
            /* variable element type */
        }
        else {
            fprintf(fd, "(12 (%x %x %x %x %x)(\n", zoneid, ifirst, ilast, type, etype);
            num = ilast - ifirst + 1;
            e = (Vint*)malloc(num * sizeof(Vint));
            vdm_FLUENTLibCellZoneType(fluentlibw, i, e);
            /* print 10 to a line */
            for (j = 1; j <= num; j++) {
                fprintf(fd, "%d ", e[j - 1]);
                if (j % 10 == 0 || j == num) {
                    fprintf(fd, "\n");
                }
            }
            fprintf(fd, "))\n");
            free(e);
        }
    }
    fprintf(fd, "\n");

    /* write zones */
    fprintf(fd, "(0 \"Zones:\")\n");
    for (i = 1; i <= numcellzone; i++) {
        vdm_FLUENTLibCellZoneName(fluentlibw, i, zname);
        zoneid = i;
        fprintf(fd, "(45 (%d %s)())\n", zoneid, zname);
    }
    for (i = 1; i <= numfacezone; i++) {
        vdm_FLUENTLibFaceZoneName(fluentlibw, i, zname);
        zoneid = i + numcellzone;
        fprintf(fd, "(45 (%d %s)())\n", zoneid, zname);
    }
    /* summarize to standard output */
    printf("Zones:\n");
    for (i = 1; i <= numcellzone; i++) {
        vdm_FLUENTLibCellZoneName(fluentlibw, i, zname);
        zoneid = i;
        printf("%d %s\n", zoneid, zname);
    }
    for (i = 1; i <= numfacezone; i++) {
        vdm_FLUENTLibFaceZoneName(fluentlibw, i, zname);
        zoneid = i + numcellzone;
        printf("%d %s\n", zoneid, zname);
    }
    /* terminate */
    vdm_FLUENTLibTerm(fluentlibw);
    /* delete */
    vdm_FLUENTLibEnd(fluentlibw);
    /* close file */
    fclose(fd);
}
