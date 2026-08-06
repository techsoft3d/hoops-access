#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/vis/visdata.h"
#include "sam/vdm/vdm.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static void
printGProp(vis_GProp* gprop);
static void
printConnect(vis_Connect* connect);
static void
printIdTran(vsy_HashTable* nehash);
static void
printCoordSys(vsy_HashTable* coordsyshash);
static void
printUnits(vis_Units* units);
static void
printEProp(vsy_HashTable* ephash);
static void
printMProp(vsy_HashTable* mphash);
static void
printTCurve(vsy_HashTable* tchash);
static void
printElemDat(vsy_HashTable* edhash, vis_Connect* connect);
static void
printLCase(vsy_HashTable* lchash, vis_Connect* connect);
static void
printRCase(vsy_HashTable* rchash, vis_Connect* connect);
static void
printMCase(vsy_HashTable* mchash, vis_Connect* connect);
static void
printCPair(vsy_HashTable* cphash, vis_Connect* connect);
static void
printRBody(vsy_HashTable* rbhash, vis_Connect* connect);
static void
printASurf(vsy_HashTable* ashash, vis_Connect* connect);
static void
printSProp(vsy_List* splist);

/*----------------------------------------------------------------------
                      Traverse and print contents of a Model object
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    char inputfile[256];
    vdm_ABAFil* abafil = NULL;
    vdm_ABALib* abalib = NULL;
    vdm_ANSFil* ansfil = NULL;
    vdm_ANSLib* anslib = NULL;
    vdm_D3DFil* d3dfil = NULL;
    vdm_D3DLib* d3dlib = NULL;
    vdm_NASFil* nasfil = NULL;
    vdm_PAMFil* pamfil = NULL;
    vdm_NASLib* naslib = NULL;
    vdm_NatLib* natlib = NULL;
    vdm_RASLib* raslib = NULL;
    vdm_MarcLib* marclib = NULL;
    vdm_SDRCLib* sdrclib = NULL;
    vdm_PatLib* patlib = NULL;
    vdm_CGNSVLib* cgnsvlib = NULL;
    vdm_FLUENTLib* fluentlib = NULL;
    vdm_DataFun* datafun = NULL;
    vdm_LMan* lman = NULL;
    Vint filetype = 0;
    vis_Model* model = NULL;
    vis_GProp* gprop = NULL;
    vis_Connect* connect = NULL;
    vis_Units* units = NULL;
    vsy_HashTable* coordsyshash = NULL;
    vsy_HashTable* eprophash = NULL;
    vsy_HashTable* mprophash = NULL;
    vsy_HashTable* tcurvehash = NULL;
    vsy_HashTable* lcasehash = NULL;
    vsy_HashTable* rcasehash = NULL;
    vsy_HashTable* mcasehash = NULL;
    vsy_HashTable* cpairhash = NULL;
    vsy_HashTable* rbodyhash = NULL;
    vsy_HashTable* asurfhash = NULL;
    vsy_HashTable* elemdathash = NULL;
    vsy_HashTable* nsethash = NULL;
    vsy_HashTable* esethash = NULL;
    vsy_HashTable* eenthash = NULL;
    vsy_List* sproplist = NULL;

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
    else if (strstr(inputfile, ".pc") != NULL) {
        filetype = VDM_PAM_INPUT;
        pamfil = vdm_PAMFilBegin();
        vdm_PAMFilDataFun(pamfil, datafun);
        printf("PAM Input File: %s\n", inputfile);
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
    else if (strstr(inputfile, ".odb") != NULL) {
        filetype = VDM_ABAQUS_ODB;
        abalib = vdm_ABALibBegin();
        vdm_ABALibDataFun(abalib, datafun);
        printf("Abaqus Output (.odb) File: %s\n", inputfile);
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
    else if (strstr(inputfile, ".k") != NULL) {
        filetype = VDM_LSTC_INPUT;
        d3dfil = vdm_D3DFilBegin();
        vdm_D3DFilDataFun(d3dfil, datafun);
        printf("LS-DYNA Input File: %s\n", inputfile);
    }
    else if (strstr(inputfile, "d3plot") != NULL) {
        filetype = VDM_LSTC_STATE;
        d3dlib = vdm_D3DLibBegin();
        vdm_D3DLibDataFun(d3dlib, datafun);
        printf("LS-DYNA State Database: %s\n", inputfile);
    }
    else if (strstr(inputfile, ".neu") != NULL) {
        filetype = VDM_MECHANICA_STUDY;
        raslib = vdm_RASLibBegin();
        vdm_RASLibDataFun(raslib, datafun);
        printf("PTC Mechanica Study: %s\n", inputfile);
    }
    else if (strstr(inputfile, ".unv") != NULL || strstr(inputfile, ".bun") != NULL) {
        filetype = VDM_SDRC_UNIVERSAL;
        sdrclib = vdm_SDRCLibBegin();
        vdm_SDRCLibDataFun(sdrclib, datafun);
        printf("SDRC Universal File: %s\n", inputfile);
    }
    else if (strstr(inputfile, ".out") != NULL) {
        filetype = VDM_PATRAN_NEUTRAL;
        patlib = vdm_PatLibBegin();
        vdm_PatLibDataFun(patlib, datafun);
        printf("MSC/PATRAN Neutral File: %s\n", inputfile);
    }
    else if (strstr(inputfile, ".cgns") != NULL) {
        filetype = VDM_CGNS;
        cgnsvlib = vdm_CGNSVLibBegin();
        vdm_CGNSVLibDataFun(cgnsvlib, datafun);
        printf("CGNS Data File: %s\n", inputfile);
    }
    else if (strstr(inputfile, ".cas") != NULL || strstr(inputfile, ".msh") != NULL) {
        filetype = VDM_FLUENT_MESH;
        fluentlib = vdm_FLUENTLibBegin();
        vdm_FLUENTLibDataFun(fluentlib, datafun);
        printf("Fluent Mesh File: %s\n", inputfile);
    }
    else if (strstr(inputfile, ".t16") != NULL || strstr(inputfile, ".t19") != NULL) {
        filetype = VDM_MARC_POST;
        marclib = vdm_MarcLibBegin();
        vdm_MarcLibDataFun(marclib, datafun);
        printf("Marc File: %s\n", inputfile);
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
    else if (filetype == VDM_PAM_INPUT) {
        vdm_PAMFilEnd(pamfil);
    }
    else if (filetype == VDM_ABAQUS_INPUT) {
        vdm_ABAFilEnd(abafil);
    }
    else if (filetype == VDM_ABAQUS_FIL) {
        vdm_ABALibEnd(abalib);
    }
    else if (filetype == VDM_ABAQUS_ODB) {
        vdm_ABALibEnd(abalib);
    }
    else if (filetype == VDM_ANSYS_INPUT) {
        vdm_ANSFilEnd(ansfil);
    }
    else if (filetype == VDM_ANSYS_RESULT) {
        vdm_ANSLibEnd(anslib);
    }
    else if (filetype == VDM_LSTC_INPUT) {
        vdm_D3DFilEnd(d3dfil);
    }
    else if (filetype == VDM_LSTC_STATE) {
        vdm_D3DLibEnd(d3dlib);
    }
    else if (filetype == VDM_MECHANICA_STUDY) {
        vdm_RASLibEnd(raslib);
    }
    else if (filetype == VDM_SDRC_UNIVERSAL) {
        vdm_SDRCLibEnd(sdrclib);
    }
    else if (filetype == VDM_PATRAN_NEUTRAL) {
        vdm_PatLibEnd(patlib);
    }
    else if (filetype == VDM_CGNS) {
        vdm_CGNSVLibEnd(cgnsvlib);
    }
    else if (filetype == VDM_FLUENT_MESH) {
        vdm_FLUENTLibEnd(fluentlib);
    }
    else if (filetype == VDM_MARC_POST) {
        vdm_MarcLibEnd(marclib);
    }
    vdm_LManEnd(lman);

    /* traverse Model object */
    /* global properties */
    vis_ModelGetObject(model, VIS_GPROP, (Vobject**)&gprop);
    if (gprop != NULL) {
        printGProp(gprop);
    }
    /* get Connect object and print nodes and elements */
    vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);
    if (connect != NULL) {
        printConnect(connect);
    }
    /* node sets */
    vis_ModelGetHashTable(model, VIS_IDTRAN_NODE, &nsethash);
    if (nsethash != NULL) {
        printIdTran(nsethash);
    }
    /* element sets */
    vis_ModelGetHashTable(model, VIS_IDTRAN_ELEM, &esethash);
    if (esethash != NULL) {
        printIdTran(esethash);
    }
    /* element entity sets */
    vis_ModelGetHashTable(model, VIS_IDTRAN_ELEMENT, &eenthash);
    if (eenthash != NULL) {
        printIdTran(eenthash);
    }
    /* coordinate systems */
    vis_ModelGetHashTable(model, VIS_COORDSYS, &coordsyshash);
    if (coordsyshash != NULL) {
        printCoordSys(coordsyshash);
    }
    /* units */
    vis_ModelGetObject(model, VIS_UNITS, (Vobject**)&units);
    if (units != NULL) {
        printUnits(units);
    }
    /* element properties */
    vis_ModelGetHashTable(model, VIS_EPROP, &eprophash);
    if (eprophash != NULL) {
        printEProp(eprophash);
    }
    /* material properties */
    vis_ModelGetHashTable(model, VIS_MPROP, &mprophash);
    if (mprophash != NULL) {
        printMProp(mprophash);
    }
    /* tabular functions */
    vis_ModelGetHashTable(model, VIS_TCURVE, &tcurvehash);
    if (tcurvehash != NULL) {
        printTCurve(tcurvehash);
    }
    /* element data */
    vis_ModelGetHashTable(model, VIS_ELEMDAT, &elemdathash);
    if (elemdathash != NULL) {
        printElemDat(elemdathash, connect);
    }
    /* load cases */
    vis_ModelGetHashTable(model, VIS_LCASE, &lcasehash);
    if (lcasehash != NULL) {
        printLCase(lcasehash, connect);
    }
    /* restraint cases */
    vis_ModelGetHashTable(model, VIS_RCASE, &rcasehash);
    if (rcasehash != NULL) {
        printRCase(rcasehash, connect);
    }
    /* multipoint constraint cases */
    vis_ModelGetHashTable(model, VIS_MCASE, &mcasehash);
    if (mcasehash != NULL) {
        printMCase(mcasehash, connect);
    }
    /* contact pairs */
    vis_ModelGetHashTable(model, VIS_CPAIR, &cpairhash);
    if (cpairhash != NULL) {
        printCPair(cpairhash, connect);
    }
    /* rigid bodies */
    vis_ModelGetHashTable(model, VIS_RBODY, &rbodyhash);
    if (rbodyhash != NULL) {
        printRBody(rbodyhash, connect);
    }
    /* analytic surfaces */
    vis_ModelGetHashTable(model, VIS_ASURF, &asurfhash);
    if (asurfhash != NULL) {
        printASurf(asurfhash, connect);
    }
    /* solution properties */
    vis_ModelGetList(model, VIS_SPROP, &sproplist);
    if (sproplist != NULL) {
        printSProp(sproplist);
    }
    /* delete objects registered in Model */
    vis_ModelDelete(model);
    /* destroy Model object itself */
    vis_ModelEnd(model);
    return 0;
}

/*----------------------------------------------------------------------
                      print nodes and elements
----------------------------------------------------------------------*/
static void
printConnect(vis_Connect* connect)
{
    Vint i, j, k;
    Vint numnp, numel;
    Vint nid, cid;
    Vint eid, pid, mid, partid;
    Vint featype;
    Vchar extname[9];
    Vdouble x[3];
    Vint maxelemnode;
    Vint nix, *ix, *ux;
    Vint shape, maxi, maxj, maxk;
    Vint nfaces;
    Vint numpartname;
    Vchar partname[256];
    Vint numpartijk, ijk[3];

    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("\n");
    printf("Number of nodes=    %d\n", numnp);
    printf("Number of elements= %d\n", numel);
    /* nodes: coordinates, user id and
       displacement coordinate system id */
    printf("\nNodes\n");
    for (i = 1; i <= numnp; i++) {
        vis_ConnectCoordsdv(connect, 1, &i, (Vdouble(*)[3])x);
        vis_ConnectNodeAssoc(connect, VIS_USERID, 1, &i, &nid);
        vis_ConnectNodeAssoc(connect, VIS_CSYSID, 1, &i, &cid);
        printf("id= %d, cid= %d, x= %e %e %e\n", nid, cid, x[0], x[1], x[2]);
        /* check for scalar node */
        vis_ConnectNodeAssoc(connect, VIS_FEATYPE, 1, &i, &featype);
        if (featype == SYS_NODE_SCALAR) {
            printf("featype= Scalar node\n");
        }
    }
    /* elements: connectivity, user id, material and
       property id, etc. */
    printf("\nElements\n");
    vis_ConnectMaxElemNode(connect, &maxelemnode);
    /* allocate vectors for internal node ids and user ids */
    ix = (Vint*)malloc(maxelemnode * sizeof(Vint));
    ux = (Vint*)malloc(maxelemnode * sizeof(Vint));
    for (i = 1; i <= numel; i++) {
        vis_ConnectTopology(connect, i, &shape, &maxi, &maxj, &maxk);
        vis_ConnectElemNode(connect, i, &nix, ix);
        vis_ConnectElemAssoc(connect, VIS_USERID, 1, &i, &eid);
        vis_ConnectElemAssoc(connect, VIS_PARTID, 1, &i, &partid);
        vis_ConnectElemAssoc(connect, VIS_PROPID, 1, &i, &pid);
        vis_ConnectElemAssoc(connect, VIS_MATLID, 1, &i, &mid);
        vis_ConnectElemAssoc(connect, VIS_CSYSID, 1, &i, &cid);
        vis_ConnectElemAssoc(connect, VIS_FEATYPE, 1, &i, &featype);
        printf("id= %d, partid= %d, pid= %d, mid= %d, cid= %d, nodes= %d\n", eid, partid, pid, mid, cid, nix);
        /* interpret shape */
        if (shape == SYS_SHAPEPOINT) {
            printf(" shape= Point(s):");
        }
        else if (shape == SYS_SHAPELINE) {
            printf(" shape= Line:");
        }
        else if (shape == SYS_SHAPETRI) {
            printf(" shape= Triangle:");
        }
        else if (shape == SYS_SHAPEQUAD) {
            printf(" shape= Quadrilateral:");
        }
        else if (shape == SYS_SHAPETET) {
            printf(" shape= Tetrahedron:");
        }
        else if (shape == SYS_SHAPEPYR) {
            printf(" shape= Pyramid:");
        }
        else if (shape == SYS_SHAPEWED) {
            printf(" shape= Pentahedron:");
        }
        else if (shape == SYS_SHAPEHEX) {
            printf(" shape= Hexahedron:");
        }
        else if (shape == SYS_SHAPEPOLYGON) {
            printf(" shape= Polygon:");
        }
        else if (shape == SYS_SHAPEPOLYHED) {
            printf(" shape= Polyhedron:");
        }
        printf("  maxi= %d, maxj= %d, maxk= %d\n", maxi, maxj, maxk);
        /* interpret featype */
        if (featype == SYS_ELEM_SOLID) {
            printf(" featype= Solid\n");
        }
        else if (featype == SYS_ELEM_SHELL) {
            printf(" featype= Shell\n");
        }
        else if (featype == SYS_ELEM_MEMBRANE) {
            printf(" featype= Membrane\n");
        }
        else if (featype == SYS_ELEM_BEAM) {
            printf(" featype= Beam\n");
        }
        else if (featype == SYS_ELEM_TRUSS) {
            printf(" featype= Truss\n");
        }
        else if (featype == SYS_ELEM_GAP) {
            printf(" featype= Gap\n");
        }
        else if (featype == SYS_ELEM_SPRINGDASHPOT) {
            printf(" featype= Spring Dashpot\n");
        }
        else if (featype == SYS_ELEM_RIGID) {
            printf(" featype= Rigid\n");
        }
        else if (featype == SYS_ELEM_CONSTRAINT) {
            printf(" featype= Constraint\n");
        }
        else if (featype == SYS_ELEM_PLOT) {
            printf(" featype= Plot\n");
        }
        else if (featype == SYS_ELEM_MASS) {
            printf(" featype= Mass\n");
        }
        else if (featype == SYS_ELEM_INTER) {
            printf(" featype= Interface\n");
        }
        /* get external name */
        vis_ConnectElemAssoc(connect, VIS_EXTNAMEA, 1, &i, (Vint*)extname);
        vis_ConnectElemAssoc(connect, VIS_EXTNAMEB, 1, &i, (Vint*)&extname[4]);
        extname[8] = '\0';
        printf(" extname= %s\n", extname);
        /* convert internal index to user id */
        vis_ConnectNodeAssoc(connect, VIS_USERID, nix, ix, ux);
        /* print element connectivity */
        printf(" connectivity=");
        for (j = 0; j < nix; j++) {
            printf(" %d", ux[j]);
        }
        printf("\n");
        /* print element face connectivity */
        vis_ConnectElemNum(connect, SYS_FACE, i, &nfaces);
        printf(" number of faces= %d\n", nfaces);
        for (k = 1; k <= nfaces; k++) {
            vis_ConnectElemCon(connect, SYS_FACE, i, k, &nix, ix);
            vis_ConnectElemTopo(connect, SYS_FACE, i, k, &shape, &maxi, &maxj);
            printf(" face= %d\n", k);
            if (shape == SYS_SHAPETRI) {
                printf("   shape= Triangle:");
            }
            else if (shape == SYS_SHAPEQUAD) {
                printf("   shape= Quadrilateral:");
            }
            else if (shape == SYS_SHAPEPOLYGON) {
                printf(" shape= Polygon:");
            }
            printf("  maxi= %d, maxj= %d\n", maxi, maxj);
            /* convert internal index to user id */
            vis_ConnectNodeAssoc(connect, VIS_USERID, nix, ix, ux);
            printf("   connectivity=");
            for (j = 0; j < nix; j++) {
                printf(" %d", ux[j]);
            }
            printf("\n");
        }
    }
    /* list part names */
    vis_ConnectNumPartName(connect, &numpartname);
    for (i = 1; i <= numpartname; i++) {
        vis_ConnectIthPartName(connect, i, &partid, partname);
        printf("partid= %d, partname= %s\n", partid, partname);
    }
    /* list part ijk structure */
    vis_ConnectNumPartIJK(connect, &numpartijk);
    for (i = 1; i <= numpartijk; i++) {
        vis_ConnectIthPartIJK(connect, i, &partid, ijk);
        printf("partid= %d, partijk= %d %d %d\n", partid, ijk[0], ijk[1], ijk[2]);
    }

    /* free vectors */
    free(ix);
    free(ux);
}

/*----------------------------------------------------------------------
                      print uprop
----------------------------------------------------------------------*/
static void
printUProp(vis_UProp* uprop)
{
    Vint i, j;
    Vint num, nval, dtype;
    Vchar name[256];
    Vchar cval[256];
    Vfloat fval[16];
    Vint ival[16];

    vis_UPropNum(uprop, &num);
    printf("number of user properties= %d\n", num);
    for (i = 1; i <= num; i++) {
        vis_UPropGetType(uprop, i, name, &nval, &dtype);
        printf("property= %d\n", i);
        printf(" name= %s\n", name);
        printf(" nval= %d\n", nval);
        printf(" dtype= %d\n", dtype);
        if (dtype == SYS_INTEGER) {
            vis_UPropValueInteger(uprop, i, ival);
            for (j = 0; j < nval; j++) {
                printf(" ival= %d\n", ival[j]);
            }
        }
        else if (dtype == SYS_FLOAT) {
            vis_UPropValueFloat(uprop, i, fval);
            for (j = 0; j < nval; j++) {
                printf(" fval= %e\n", fval[j]);
            }
        }
        else if (dtype == SYS_CHAR) {
            vis_UPropValueString(uprop, i, cval);
            printf(" cval= %s\n", cval);
        }
    }
}

/*----------------------------------------------------------------------
                      print set
----------------------------------------------------------------------*/
static void
printIdTran(vsy_HashTable* nehash)
{
    Vint i;
    Vint iset;
    Vint nument;
    Vint id, no;
    vis_IdTran* idtran;
    vis_UProp* uprop;
    Vint enttype, subtype;
    Vint type, spec;
    Vchar name[256];

    vsy_HashTableInitIter(nehash);
    while (vsy_HashTableNextIter(nehash, &iset, (Vobject**)&idtran), idtran) {
        /* print set name, etc. */
        vis_IdTranGetEntType(idtran, &enttype, &subtype);
        vis_IdTranGetName(idtran, name);
        if (enttype == SYS_NODE && subtype == SYS_NONE) {
            printf("\nNode Set, iset= %d, Name= %s\n", iset, name);
        }
        else if (enttype == SYS_ELEM && subtype == SYS_NONE) {
            printf("\nElement Set, iset= %d, Name= %s\n", iset, name);
        }
        else if (enttype == SYS_ELEM && subtype == SYS_EDGE) {
            printf("\nElement Edge Set, iset= %d, Name= %s\n", iset, name);
        }
        else if (enttype == SYS_ELEM && subtype == SYS_FACE) {
            printf("\nElement Face Set, iset= %d, Name= %s\n", iset, name);
        }
        /* print type and spec */
        vis_IdTranGetType(idtran, &type);
        vis_IdTranGetSpec(idtran, &spec);
        printf("type= %d, spec= %d\n", type, spec);
        /* print possible user defined data */
        vis_IdTranGetUProp(idtran, &uprop);
        if (uprop) {
            printUProp(uprop);
        }
        /* print entity indices in set */
        /* note, these are not the node or element user id */
        vis_IdTranInq(idtran, &nument);
        for (i = 1; i <= nument; i++) {
            vis_IdTranGetId(idtran, i, &id);
            if (subtype == SYS_NONE) {
                printf("id= %d\n", id);
            }
            else {
                vis_IdTranGetEnt(idtran, i, &no);
                printf("id= %d, no= %d\n", id, no);
            }
        }
    }
}

/*----------------------------------------------------------------------
                      print coordinate systems
----------------------------------------------------------------------*/
static void
printCoordSys(vsy_HashTable* cshash)
{
    vis_CoordSys* coordsys;
    Vint id;
    Vint type;
    Vdouble x[3], tm[3][3];

    printf("\nCoordinate Systems\n");
    vsy_HashTableInitIter(cshash);
    while (vsy_HashTableNextIter(cshash, &id, (Vobject**)&coordsys), coordsys) {
        printf("id= %d, type= ", id);
        vis_CoordSysInq(coordsys, &type);
        if (type == SYS_CARTESIAN) {
            printf(" Cartesian\n");
        }
        else if (type == SYS_CYLINDRICAL) {
            printf(" Cylindrical\n");
        }
        else if (type == SYS_SPHERICAL) {
            printf(" Spherical\n");
        }
        else if (type == SYS_SPHERICAL_ALT) {
            printf(" Spherical Alternate\n");
        }
        else if (type == SYS_TOROIDAL) {
            printf(" Toroidal\n");
        }
        else if (type == SYS_CYLINDRICAL_ALT) {
            printf(" Cylindrical Alternate\n");
        }
        vis_CoordSysOriginTriaddv(coordsys, x, tm);
        printf(" origin= %e %e %e\n", x[0], x[1], x[2]);
        printf(" dircos= %e %e %e\n", tm[0][0], tm[1][0], tm[2][0]);
        printf("         %e %e %e\n", tm[0][1], tm[1][1], tm[2][1]);
        printf("         %e %e %e\n", tm[0][2], tm[1][2], tm[2][2]);
    }
}

/*----------------------------------------------------------------------
                      print global properties
----------------------------------------------------------------------*/
static void
printGProp(vis_GProp* gprop)
{
    Vint i;
    Vint flag;
    Vint iparams[2];
    Vfloat fparams[3];
    Vdouble dparams[3];
    Vchar cparams[81];
    Vint user_num, user_ith, userdimenum, userdime, userdatatype;
    Vint symmnum, *isymm;

    printf("\nGProp\n");

    vis_GPropValueFlag(gprop, GPROP_TITLE, &flag);
    if (flag) {
        vis_GPropValueString(gprop, GPROP_TITLE, cparams);
        printf("TITLE: %s\n", cparams);
    }
    vis_GPropValueFlag(gprop, GPROP_SUBTITLE, &flag);
    if (flag) {
        vis_GPropValueString(gprop, GPROP_SUBTITLE, cparams);
        printf("SUBTITLE: %s\n", cparams);
    }
    vis_GPropValueFlag(gprop, GPROP_2DPLANE, &flag);
    if (flag) {
        vis_GPropValueInteger(gprop, GPROP_2DPLANE, iparams);
        printf("2DPLANE: %d\n", iparams[0]);
    }
    vis_GPropValueFlag(gprop, GPROP_2DTYPE, &flag);
    if (flag) {
        vis_GPropValueInteger(gprop, GPROP_2DTYPE, iparams);
        printf("2DTYPE: %d\n", iparams[0]);
    }
    /* cyclic symmetry information */
    vis_GPropValueFlag(gprop, GPROP_CYCLIC_NSEC, &flag);
    if (flag) {
        vis_GPropValueInteger(gprop, GPROP_CYCLIC_NSEC, iparams);
        printf("CYCLIC_NSEC: %d\n", iparams[0]);
    }
    vis_GPropValueFlag(gprop, GPROP_CYCLIC_ORIG, &flag);
    if (flag) {
        vis_GPropValueFloat(gprop, GPROP_CYCLIC_ORIG, fparams);
        printf("CYCLIC_ORIG: %e %e %e\n", fparams[0], fparams[1], fparams[2]);
    }
    vis_GPropValueFlag(gprop, GPROP_CYCLIC_AXIS, &flag);
    if (flag) {
        vis_GPropValueFloat(gprop, GPROP_CYCLIC_AXIS, fparams);
        printf("CYCLIC_AXIS: %e %e %e\n", fparams[0], fparams[1], fparams[2]);
    }
    /* generalized symmetry set information */
    vis_GPropValueFlag(gprop, GPROP_SYMM_NUM, &flag);
    if (flag) {
        vis_GPropValueInteger(gprop, GPROP_SYMM_NUM, &symmnum);
        printf("SYMM_NUM: %d\n", symmnum);
        isymm = (Vint*)malloc(symmnum * sizeof(Vint));
        vis_GPropValueFlag(gprop, GPROP_SYMM_ID, &flag);
        if (flag) {
            vis_GPropValueInteger(gprop, GPROP_SYMM_ID, isymm);
            printf("SYMM_ID:");
            for (i = 0; i < symmnum; i++) {
                printf(" %d", isymm[i]);
            }
            printf("\n");
        }
        vis_GPropValueFlag(gprop, GPROP_SYMM_NSEC, &flag);
        if (flag) {
            vis_GPropValueInteger(gprop, GPROP_SYMM_NSEC, isymm);
            printf("SYMM_NSEC:");
            for (i = 0; i < symmnum; i++) {
                printf(" %d", isymm[i]);
            }
            printf("\n");
        }
        free(isymm);
        /* other GPROP_SYMM_XXX are similar */
    }
    /* user defined scalar values */
    vis_GPropValueFlag(gprop, GPROP_USER_NUM, &flag);
    if (flag) {
        vis_GPropValueInteger(gprop, GPROP_USER_NUM, &user_num);
        for (user_ith = 0; user_ith < user_num; user_ith++) {
            vis_GPropValueInteger(gprop, GPROP_USERDIMENUM + user_ith, &userdimenum);
            if (userdimenum > 1)
                continue;
            vis_GPropValueInteger(gprop, GPROP_USERDIME + user_ith, &userdime);
            if (userdime > 1)
                continue;
            vis_GPropValueString(gprop, GPROP_USERNAME + user_ith, cparams);
            printf("user name= %s\n", cparams);
            vis_GPropValueInteger(gprop, GPROP_USERDATATYPE + user_ith, &userdatatype);
            if (userdatatype == SYS_INTEGER) {
                vis_GPropValueInteger(gprop, GPROP_USERDATA + user_ith, iparams);
                printf("user data= %d\n", iparams[0]);
            }
            else if (userdatatype == SYS_DOUBLE || userdatatype == SYS_FLOAT) {
                vis_GPropValueDouble(gprop, GPROP_USERDATA + user_ith, dparams);
                printf("user data= %le\n", dparams[0]);
            }
        }
    }
}

/*----------------------------------------------------------------------
                      print units
----------------------------------------------------------------------*/
static void
printUnits(vis_Units* units)
{
    Vint length, mass, time, temp, angle, charge;
    Vint clength, cmass, ctime, ctemp, cangle, ccharge;
    Vdouble lengthfac, massfac, timefac, tempfac, tempoff, anglefac, chargefac;
    Vchar cstg[33];

    printf("\nUnits\n");
    /* get basic unit types */
    vis_UnitsGetBase(units, UNITS_LENGTH, &length);
    vis_UnitsGetBase(units, UNITS_MASS, &mass);
    vis_UnitsGetBase(units, UNITS_TIME, &time);
    vis_UnitsGetBase(units, UNITS_TEMP, &temp);
    vis_UnitsGetBase(units, UNITS_ANGLE, &angle);
    vis_UnitsGetBase(units, UNITS_CHARGE, &charge);

    /* print */
    vis_UnitsGetDesc(units, UNITS_LENGTH, length, cstg);
    printf("length type= %d, %s\n", length, cstg);
    vis_UnitsGetDesc(units, UNITS_MASS, mass, cstg);
    printf("mass type=  %d, %s\n", mass, cstg);
    vis_UnitsGetDesc(units, UNITS_TIME, time, cstg);
    printf("time type=  %d, %s\n", time, cstg);
    vis_UnitsGetDesc(units, UNITS_TEMP, temp, cstg);
    printf("temp type=  %d, %s\n", temp, cstg);
    vis_UnitsGetDesc(units, UNITS_ANGLE, angle, cstg);
    printf("angle type= %d, %s\n", angle, cstg);
    vis_UnitsGetDesc(units, UNITS_CHARGE, charge, cstg);
    printf("charge type= %d, %s\n", charge, cstg);

    /* get conversion unit types */
    vis_UnitsGetConv(units, UNITS_LENGTH, &clength);
    vis_UnitsGetConv(units, UNITS_MASS, &cmass);
    vis_UnitsGetConv(units, UNITS_TIME, &ctime);
    vis_UnitsGetConv(units, UNITS_TEMP, &ctemp);
    vis_UnitsGetConv(units, UNITS_ANGLE, &cangle);
    vis_UnitsGetConv(units, UNITS_CHARGE, &ccharge);
    /* print all generically */
    printf("length type= %d\n", clength);
    printf("mass type=   %d\n", cmass);
    printf("time type=   %d\n", ctime);
    printf("temp type=   %d\n", ctemp);
    printf("angle type=  %d\n", cangle);
    printf("charge type= %d\n", ccharge);

    /* get conversion unit factors, offset */
    vis_UnitsGetFactor(units, UNITS_LENGTH, &lengthfac);
    vis_UnitsGetFactor(units, UNITS_MASS, &massfac);
    vis_UnitsGetFactor(units, UNITS_TIME, &timefac);
    vis_UnitsGetFactor(units, UNITS_TEMP, &tempfac);
    vis_UnitsGetFactor(units, UNITS_TEMP_OFFSET, &tempoff);
    vis_UnitsGetFactor(units, UNITS_ANGLE, &anglefac);
    vis_UnitsGetFactor(units, UNITS_CHARGE, &chargefac);
    /* print */
    printf("length factor= %e\n", lengthfac);
    printf("mass factor=   %e\n", massfac);
    printf("time factor=   %e\n", timefac);
    printf("temp factor=   %e\n", tempfac);
    printf("temp offset=   %e\n", tempoff);
    printf("angle factor=  %e\n", anglefac);
    printf("charge factor= %e\n", chargefac);
}

/*----------------------------------------------------------------------
                      print element properties
----------------------------------------------------------------------*/
static void
printEProp(vsy_HashTable* ephash)
{
    Vint i, j, k;
    vis_EProp* eprop;
    Vint id;
    Vint eptype;
    Vint ntypes, *type;
    Vint flag, nval, nloc, dtyp;
    Vchar ename[256], name[64];
    Vint iparams[100];
    Vdouble dparams[100];
    Vchar cval[256];

    printf("\nElement Properties\n");
    vsy_HashTableInitIter(ephash);
    while (vsy_HashTableNextIter(ephash, &id, (Vobject**)&eprop), eprop) {
        printf("id= %d, type= ", id);
        vis_EPropInq(eprop, &eptype);
        if (eptype == SYS_ELEM_SOLID) {
            printf(" Solid Property\n");
        }
        else if (eptype == SYS_ELEM_SHELL) {
            printf(" Shell Property\n");
        }
        else if (eptype == SYS_ELEM_MEMBRANE) {
            printf(" Membrane Property\n");
        }
        else if (eptype == SYS_ELEM_BEAM) {
            printf(" Beam Property\n");
        }
        else if (eptype == SYS_ELEM_TRUSS) {
            printf(" Truss Property\n");
        }
        else if (eptype == VIS_ELEM_SPRINGDASHPOT) {
            printf(" Spring Dashpot Property\n");
        }
        else if (eptype == SYS_ELEM_RIGID) {
            printf(" Rigid Property\n");
        }
        else if (eptype == SYS_ELEM_MASS) {
            printf(" Mass Property\n");
        }
        vis_EPropGetName(eprop, ename);
        if (ename[0] != '\0') {
            printf("name= %s", ename);
        }
        vis_EPropValueTypeNum(eprop, &ntypes);
        type = (Vint*)malloc(ntypes * sizeof(Vint));
        vis_EPropValueType(eprop, &ntypes, type);

        /* loop through types generically */
        for (i = 0; i < ntypes; i++) {
            vis_EPropValueName(eprop, type[i], name);
            printf("\n name= %s\n", name);
            vis_EPropValueFlag(eprop, type[i], &flag);
            if (flag == EPROP_UNDEFINED) {
                printf("Undefined\n");
            }
            else {
                vis_EPropValueParams(eprop, type[i], &nval, &nloc, &dtyp);
                printf(" nval= %d, nloc= %d\n", nval, nloc);
                /* check for too many values for array size */
                if (nval * nloc > 100)
                    continue;
                /* integer valued */
                if (dtyp == SYS_INTEGER) {
                    printf(" Integer\n");
                    vis_EPropValueInteger(eprop, type[i], iparams);
                    for (k = 0; k < nloc; k++) {
                        if (nloc > 1)
                            printf(" Location= %d\n", k);
                        for (j = 0; j < nval; j++) {
                            printf("  value= %d\n", iparams[k * nval + j]);
                        }
                    }
                    /* real valued */
                }
                else if (dtyp == SYS_REAL) {
                    vis_EPropValueDouble(eprop, type[i], dparams);
                    printf(" Real\n");
                    for (k = 0; k < nloc; k++) {
                        if (nloc > 1)
                            printf(" Location= %d\n", k);
                        for (j = 0; j < nval; j++) {
                            printf("  value= %e\n", dparams[k * nval + j]);
                        }
                    }
                    /* character valued */
                }
                else if (dtyp == SYS_CHAR) {
                    vis_EPropValueString(eprop, type[i], cval);
                    printf(" Character\n");
                    printf("  value= %s\n", cval);
                }
            }
        }
        free(type);
    }
}

/*----------------------------------------------------------------------
                      print material properties
----------------------------------------------------------------------*/
static void
printMProp(vsy_HashTable* mphash)
{
    Vint i, j;
    vis_MProp* mprop;
    Vint id;
    Vint mptype;
    Vint ntypes, *type;
    Vint flag, nval, dtyp;
    Vchar mname[256], name[64];
    Vint iparams[100];
    Vdouble dparams[100];
    Vint tid;

    printf("\nMaterial Properties\n");
    vsy_HashTableInitIter(mphash);
    while (vsy_HashTableNextIter(mphash, &id, (Vobject**)&mprop), mprop) {
        printf("id= %d, type= ", id);
        vis_MPropInq(mprop, &mptype);
        if (mptype == SYS_MAT_ISOTROPIC) {
            printf(" Isotropic Property\n");
        }
        else if (mptype == SYS_MAT_ORTHOTROPIC) {
            printf(" Orthotropic Property\n");
        }
        else if (mptype == SYS_MAT_ANISOTROPIC) {
            printf(" Anisotropic Property\n");
        }
        vis_MPropGetName(mprop, mname);
        if (mname[0] != '\0') {
            printf("name= %s", mname);
        }
        vis_MPropValueTypeNum(mprop, &ntypes);
        type = (Vint*)malloc(ntypes * sizeof(Vint));
        vis_MPropValueType(mprop, &ntypes, type);

        /* loop through types */
        for (i = 0; i < ntypes; i++) {
            vis_MPropValueName(mprop, type[i], name);
            printf("\n name = %s\n", name);
            vis_MPropValueFlag(mprop, type[i], &flag);
            if (flag == MPROP_UNDEFINED) {
                printf("Undefined\n");
            }
            else if (flag == MPROP_VALUE) {
                vis_MPropValueParams(mprop, type[i], &nval, &dtyp);
                printf(" nval= %d\n", nval);
                /* check for too many values for array size */
                if (nval > 100)
                    continue;
                /* integer valued */
                if (dtyp == SYS_INTEGER) {
                    printf(" Integer\n");
                    vis_MPropValueInteger(mprop, type[i], iparams);
                    for (j = 0; j < nval; j++) {
                        printf("  value= %d\n", iparams[j]);
                    }
                    /* real valued */
                }
                else if (dtyp == SYS_REAL) {
                    vis_MPropValueDouble(mprop, type[i], dparams);
                    printf(" Real\n");
                    for (j = 0; j < nval; j++) {
                        printf("  value= %e\n", dparams[j]);
                    }
                }
            }
            else if (flag == MPROP_IDENTIFIER) {
                vis_MPropValueId(mprop, type[i], &tid);
                printf(" TCurve identifier= %d\n", tid);
            }
        }
        free(type);
    }
}

/*----------------------------------------------------------------------
                      print tabular functions
----------------------------------------------------------------------*/
static void
printTCurve(vsy_HashTable* tchash)
{
    Vint i, j;
    vis_TCurve* tcurve;
    Vint id;
    Vint tctype, nval, npts;
    Vdouble t, val[100];

    printf("\nTabular Funtions\n");
    vsy_HashTableInitIter(tchash);
    while (vsy_HashTableNextIter(tchash, &id, (Vobject**)&tcurve), tcurve) {
        vis_TCurveInq(tcurve, &tctype, &nval);
        printf("id= %d, nval= %d, type= ", id, nval);
        /* check for too many values for array size */
        if (nval > 100)
            continue;
        if (tctype == TCURVE_PWLINEAR) {
            printf(" Piecewise Linear Function\n");
        }
        /* print function values */
        vis_TCurveNum(tcurve, &npts);
        printf("npts= %d\n", npts);
        /* loop through points one at a time */
        for (i = 1; i <= npts; i++) {
            vis_TCurveIndepdv(tcurve, 1, &i, &t);
            printf("point= %d, t= %e, v= ", i, t);
            /* evaluate function at this point */
            vis_TCurveEvaldv(tcurve, 1, &t, val);
            for (j = 0; j < nval; j++) {
                printf(" %e", val[j]);
            }
            printf("\n");
        }
    }
}

/*----------------------------------------------------------------------
                      print element data
----------------------------------------------------------------------*/
static void
printElemDat(vsy_HashTable* edhash, vis_Connect* connect)
{
    Vint i, j;
    vis_ElemDat* elemdat;
    Vint id;
    Vint iprop;
    Vint numel;
    Vint flags;
    Vdouble thk[9], vec[9][3], fib[9];
    Vint nix, ix[9], ux[9];
    Vint nument, enttype, subtype, datatype;

    vis_ConnectNumber(connect, SYS_ELEM, &numel);

    printf("\nElement Data\n");
    vsy_HashTableInitIter(edhash);
    while (vsy_HashTableNextIter(edhash, &iprop, (Vobject**)&elemdat), elemdat) {
        vis_ElemDatInq(elemdat, &nument, &enttype, &subtype, &datatype);
        /* element thickness, surface elements */
        if (iprop == SYS_PROP_THICKNESS) {
            printf("\nElement Thicknesses\n");
            for (i = 1; i <= numel; i++) {
                vis_ElemDatDataStat(elemdat, i, 1, &flags);
                if (flags == 0)
                    continue;
                vis_ConnectElemAssoc(connect, VIS_USERID, 1, &i, &id);
                printf("elem= %d\n", id);
                vis_ElemDatDatadv(elemdat, i, 1, thk);
                if (subtype == SYS_NONE) {
                    printf(" thickness= %e\n", thk[0]);
                }
                else {
                    vis_ConnectElemNode(connect, i, &nix, ix);
                    vis_ConnectNodeAssoc(connect, VIS_USERID, nix, ix, ux);
                    for (j = 0; j < nix; j++) {
                        printf(" node= %d, thickness= %e\n", ux[j], thk[j]);
                    }
                }
            }
            /* element offset vectors */
        }
        else if (iprop == SYS_PROP_OFFSETVEC) {
            printf("\nElement Offset Vectors\n");
            for (i = 1; i <= numel; i++) {
                vis_ElemDatDataStat(elemdat, i, 1, &flags);
                if (flags == 0)
                    continue;
                vis_ConnectElemAssoc(connect, VIS_USERID, 1, &i, &id);
                printf("elem= %d\n", id);
                vis_ElemDatDatadv(elemdat, i, 1, (Vdouble*)vec);
                if (subtype == SYS_NONE) {
                    printf(" offset vector= %e %e %e\n", vec[0][0], vec[0][1], vec[0][2]);
                }
                else {
                    vis_ConnectElemNode(connect, i, &nix, ix);
                    vis_ConnectNodeAssoc(connect, VIS_USERID, nix, ix, ux);
                    for (j = 0; j < nix; j++) {
                        printf(" node= %d, offset vector= %e %e %e\n", ux[j], vec[j][0], vec[j][1], vec[j][2]);
                    }
                }
            }
            /* element orientation vectors */
        }
        else if (iprop == SYS_PROP_ELEMVEC) {
            printf("\nElement Orientation Vectors\n");
            for (i = 1; i <= numel; i++) {
                vis_ElemDatDataStat(elemdat, i, 1, &flags);
                if (flags == 0)
                    continue;
                vis_ConnectElemAssoc(connect, VIS_USERID, 1, &i, &id);
                printf("elem= %d\n", id);
                vis_ElemDatDatadv(elemdat, i, 1, (Vdouble*)vec);
                if (subtype == SYS_NONE) {
                    printf(" orientation vector= %e %e %e\n", vec[0][0], vec[0][1], vec[0][2]);
                }
                else {
                    vis_ConnectElemNode(connect, i, &nix, ix);
                    vis_ConnectNodeAssoc(connect, VIS_USERID, nix, ix, ux);
                    for (j = 0; j < nix; j++) {
                        printf(" node= %d, orientation vector= %e %e %e\n", ux[j], vec[j][0], vec[j][1], vec[j][2]);
                    }
                }
            }
            /* element material orientation vectors */
        }
        else if (iprop == SYS_PROP_MATLVEC) {
            printf("\nElement Material Orientation Vectors\n");
            /* element bottom and top fiber locations */
        }
        else if (iprop == SYS_PROP_FIBERBOT || iprop == SYS_PROP_FIBERTOP) {
            printf("\nElement Fiber Locations\n");
            for (i = 1; i <= numel; i++) {
                vis_ElemDatDataStat(elemdat, i, 1, &flags);
                if (flags == 0)
                    continue;
                vis_ConnectElemAssoc(connect, VIS_USERID, 1, &i, &id);
                printf("elem= %d\n", id);
                vis_ElemDatDatadv(elemdat, i, 1, fib);
                if (subtype == SYS_NONE) {
                    if (iprop == SYS_PROP_FIBERBOT) {
                        printf(" fiber (bottom)= %e\n", fib[0]);
                    }
                    else {
                        printf(" fiber (top)= %e\n", fib[0]);
                    }
                }
                else {
                    vis_ConnectElemNode(connect, i, &nix, ix);
                    vis_ConnectNodeAssoc(connect, VIS_USERID, nix, ix, ux);
                    for (j = 0; j < nix; j++) {
                        if (iprop == SYS_PROP_FIBERBOT) {
                            printf(" node= %d, fiber (bottom)= %e\n", ux[j], fib[j]);
                        }
                        else {
                            printf(" node= %d, fiber (top)= %e\n", ux[j], fib[j]);
                        }
                    }
                }
            }
        }
    }
}

/*----------------------------------------------------------------------
                      print load cases
----------------------------------------------------------------------*/
static void
printLCase(vsy_HashTable* lchash, vis_Connect* connect)
{
    Vint i, j, k;
    vis_LCase* lcase;
    Vint id;
    Vint maxindex;
    Vint flags;
    Vint nface;
    Vint nixf, ixf[9], uxf[9];
    Vdouble v[2 * 3 * 9];
    Vdouble grav[3], cent[3], w[3], wdot[3];
    Vint complexflag, complexmode;

    printf("\nLoad Cases\n");
    vsy_HashTableInitIter(lchash);
    while (vsy_HashTableNextIter(lchash, &id, (Vobject**)&lcase), lcase) {
        printf("id= %d\n", id);
        /* determine if complex data */
        vis_LCaseGetComplex(lcase, &complexflag);
        vis_LCaseGetComplexMode(lcase, &complexmode);
        /* concentrated forces, illustrate possible complex */
        vis_LCaseConcMax(lcase, LCASE_FORCE, &maxindex);
        for (i = 1; i <= maxindex; i++) {
            vis_LCaseConcFlag(lcase, i, LCASE_FORCE, &flags);
            if (flags == 0)
                continue;
            vis_ConnectNodeAssoc(connect, VIS_USERID, 1, &i, &id);
            if (complexflag) {
                vis_LCaseSetComplexMode(lcase, SYS_COMPLEX_REALIMAGINARY);
                vis_LCaseConcdv(lcase, i, LCASE_FORCE, v);
                printf("node= %d, force vector= %e %e(i) %e %e(i) %e %e(i)\n", id, v[0], v[1], v[2], v[3], v[4], v[5]);
                vis_LCaseSetComplexMode(lcase, complexmode);
            }
            else {
                vis_LCaseConcdv(lcase, i, LCASE_FORCE, v);
                printf("node= %d, force vector= %e %e %e\n", id, v[0], v[1], v[2]);
            }
        }
        /* concentrated moments */
        vis_LCaseConcMax(lcase, LCASE_MOMENT, &maxindex);
        for (i = 1; i <= maxindex; i++) {
            vis_LCaseConcFlag(lcase, i, LCASE_MOMENT, &flags);
            if (flags == 0)
                continue;
            vis_LCaseConcdv(lcase, i, LCASE_MOMENT, v);
            vis_ConnectNodeAssoc(connect, VIS_USERID, 1, &i, &id);
            printf("node= %d, moment vector= %e %e %e\n", id, v[0], v[1], v[2]);
        }
        /* pressure loads */
        vis_LCaseDistMax(lcase, SYS_FACE, LCASE_PRES, &maxindex);
        for (i = 1; i <= maxindex; i++) {
            vis_LCaseDistFlag(lcase, SYS_FACE, i, LCASE_PRES, &flags);
            if (flags == 0)
                continue;
            vis_ConnectElemAssoc(connect, VIS_USERID, 1, &i, &id);
            vis_ConnectElemNum(connect, SYS_FACE, i, &nface);
            for (j = 1; j <= nface; j++) {
                if (vis_LCaseDistFlagEnt(lcase, SYS_FACE, i, LCASE_PRES, j) == 0)
                    continue;
                vis_LCaseDistdv(lcase, SYS_FACE, i, j, LCASE_PRES, 0, v);
                vis_ConnectElemCon(connect, SYS_FACE, i, j, &nixf, ixf);
                vis_ConnectNodeAssoc(connect, VIS_USERID, nixf, ixf, uxf);
                printf("elem= %d, face= %d\n", id, j);
                for (k = 0; k < nixf; k++) {
                    printf(" node= %d, pressure= %e\n", uxf[k], v[k]);
                }
            }
        }
        /* traction loads */
        vis_LCaseDistMax(lcase, SYS_FACE, LCASE_TRAC, &maxindex);
        for (i = 1; i <= maxindex; i++) {
            vis_LCaseDistFlag(lcase, SYS_FACE, i, LCASE_TRAC, &flags);
            if (flags == 0)
                continue;
            vis_ConnectElemAssoc(connect, VIS_USERID, 1, &i, &id);
            vis_ConnectElemNum(connect, SYS_FACE, i, &nface);
            for (j = 1; j <= nface; j++) {
                if (vis_LCaseDistFlagEnt(lcase, SYS_FACE, i, LCASE_TRAC, j) == 0)
                    continue;
                vis_LCaseDistdv(lcase, SYS_FACE, i, j, LCASE_TRAC, 0, v);
                vis_ConnectElemCon(connect, SYS_FACE, i, j, &nixf, ixf);
                vis_ConnectNodeAssoc(connect, VIS_USERID, nixf, ixf, uxf);
                printf("elem= %d, face= %d\n", id, j);
                for (k = 0; k < nixf; k++) {
                    printf(" node= %d, traction vector= %e %e %e\n", uxf[k], v[3 * k], v[3 * k + 1], v[3 * k + 2]);
                }
            }
        }
        /* accelerations */
        vis_LCaseAccelFlag(lcase, &flags);
        if (flags) {
            vis_LCaseAcceldv(lcase, grav, cent, w, wdot);
            if (grav[0] != 0. || grav[1] != 0. || grav[2] != 0.) {
                printf(" gravity vector= %e %e %e\n", grav[0], grav[1], grav[2]);
            }
            printf(" center of rotation= %e %e %e\n", cent[0], cent[1], cent[2]);
            if (w[0] != 0. || w[1] != 0. || w[2] != 0.) {
                printf(" angular velocity vector= %e %e %e\n", w[0], w[1], w[2]);
            }
            if (wdot[0] != 0. || wdot[1] != 0. || wdot[2] != 0.) {
                printf(" angular acceleration vector= %e %e %e\n", wdot[0], wdot[1], wdot[2]);
            }
        }
    }
}

/*----------------------------------------------------------------------
                      print restraint cases
----------------------------------------------------------------------*/
static void
printRCase(vsy_HashTable* rchash, vis_Connect* connect)
{
    Vint i, j;
    vis_RCase* rcase;
    Vint id;
    Vint maxindex;
    Vint numtags, tag[SYS_DOF_MAX];
    Vint nid;
    Vint rtype, master;
    Vdouble value;

    printf("\nRestraint Cases\n");
    vsy_HashTableInitIter(rchash);
    while (vsy_HashTableNextIter(rchash, &id, (Vobject**)&rcase), rcase) {
        printf("id= %d\n", id);
        vis_RCaseSPCMax(rcase, &maxindex);
        for (i = 1; i <= maxindex; i++) {
            vis_RCaseSPCTag(rcase, i, &numtags, tag);
            if (numtags == 0)
                continue;
            vis_ConnectNodeAssoc(connect, VIS_USERID, 1, &i, &nid);
            /* loop through dof tags */
            for (j = 0; j < numtags; j++) {
                vis_RCaseSPCdv(rcase, i, tag[j], &rtype, &value, &master);
                if (rtype == RCASE_FIXED) {
                    printf(" node= %d, fixed dof tag= %d\n", nid, tag[j]);
                }
                else if (rtype == RCASE_APPLIED) {
                    printf(" node= %d, applied dof tag= %d, value= %e\n", nid, tag[j], value);
                }
            }
        }
    }
}

/*----------------------------------------------------------------------
                      print multipoint constraint cases
----------------------------------------------------------------------*/
static void
printMCase(vsy_HashTable* mchash, vis_Connect* connect)
{
    Vint i, j;
    vis_MCase* mcase;
    Vint id;
    Vint maxindex, maxterms, maxrhs;
    Vint type, nterms;
    Vint nid;
    Vint *ix, *ig;
    Vdouble* c;
    Vdouble rhs;

    printf("\nMultipoint Constraint Cases\n");
    vsy_HashTableInitIter(mchash);
    while (vsy_HashTableNextIter(mchash, &id, (Vobject**)&mcase), mcase) {
        printf("id= %d\n", id);
        vis_MCaseMax(mcase, &maxindex, &maxterms, &maxrhs);
        ix = (Vint*)malloc(maxterms * sizeof(Vint));
        ig = (Vint*)malloc(maxterms * sizeof(Vint));
        c = (Vdouble*)malloc(maxterms * sizeof(Vdouble));
        for (i = 1; i <= maxindex; i++) {
            vis_MCaseNum(mcase, i, &nterms);
            if (nterms) {
                vis_MCaseType(mcase, i, &type);
                /* constraint equation */
                if (type == MCASE_MPC) {
                    vis_MCaseMPCdv(mcase, i, &nterms, ix, ig, c, &rhs);
                    printf("index= %d, nterms= %d, rhs= %f\n", i, nterms, rhs);
                    for (j = 0; j < nterms; j++) {
                        vis_ConnectNodeAssoc(connect, VIS_USERID, 1, &ix[j], &nid);
                        printf(" ix= %d, tag= %d, c= %f\n", nid, ig[j], c[j]);
                    }
                    /* constraint node based entity */
                }
                else {
                    vis_MCaseCon(mcase, i, &type, &nterms, ix);
                    printf("index= %d, type= %d, nterms= %d\n", i, type, nterms);
                    for (j = 0; j < nterms; j++) {
                        vis_ConnectNodeAssoc(connect, VIS_USERID, 1, &ix[j], &nid);
                        printf(" ix= %d\n", nid);
                    }
                }
            }
        }
        free(ix);
        free(ig);
        free(c);
    }
}

/*----------------------------------------------------------------------
                      print contact pairs
----------------------------------------------------------------------*/
static void
printCPair(vsy_HashTable* cphash, vis_Connect* connect)
{
    Vint i;
    vis_CPair* cpair;
    Vint id, asid;
    Vint mastent, slavent, ctype;
    Vint index, numno, no[32];

    printf("\nContact Pairs\n");
    vsy_HashTableInitIter(cphash);
    while (vsy_HashTableNextIter(cphash, &id, (Vobject**)&cpair), cpair) {
        printf("id= %d\n", id);
        vis_CPairInq(cpair, &mastent, &slavent);
        if (mastent == SYS_EDGE) {
            printf(" Master Edge\n");
        }
        else if (mastent == SYS_FACE) {
            printf(" Master Face\n");
        }
        else if (mastent == SYS_ASURF) {
            vis_CPairMasterASurf(cpair, &asid);
            printf(" Master Analytic Surface id= %d\n", asid);
        }
        if (slavent == SYS_NONE) {
            printf(" Slave None\n");
        }
        else if (slavent == SYS_NODE) {
            printf(" Slave Node\n");
        }
        else if (slavent == SYS_EDGE) {
            printf(" Slave Edge\n");
        }
        else if (slavent == SYS_FACE) {
            printf(" Slave Face\n");
        }
        vis_CPairGetType(cpair, &ctype);
        if (ctype == CPAIR_CONTACT) {
            printf(" Contact Pair\n");
        }
        else if (ctype == CPAIR_COSIM) {
            printf(" Co-simulation Pair\n");
        }
        else if (ctype == CPAIR_CYCLIC) {
            printf(" Cyclic Symmetry Pair\n");
        }
        /* traverse master entities */
        if (mastent == SYS_EDGE || mastent == SYS_FACE) {
            vis_CPairMasterInitIter(cpair);
            while (vis_CPairMasterNextIter(cpair, &index), index) {
                printf("master elem= %d\n", index);
                vis_CPairMasterEnt(cpair, index, &numno, no);
                printf("elem face or edge= ");
                for (i = 0; i < numno; i++) {
                    printf(" %d", no[i]);
                }
                printf("\n");
            }
        }
        /* traverse slave entities */
        if (slavent) {
            vis_CPairSlaveInitIter(cpair);
            while (vis_CPairSlaveNextIter(cpair, &index), index) {
                if (slavent == SYS_NODE) {
                    printf("slave node= %d\n", index);
                }
                else {
                    printf("slave elem= %d\n", index);
                    vis_CPairSlaveEnt(cpair, index, &numno, no);
                    printf("elem face or edge= ");
                    for (i = 0; i < numno; i++) {
                        printf(" %d", no[i]);
                    }
                    printf("\n");
                }
            }
            /* traverse slave nodes */
            vis_CPairSlaveNodeInitIter(cpair);
            while (vis_CPairSlaveNodeNextIter(cpair, &index), index) {
                printf("slave node= %d\n", index);
            }
        }
    }
}

/*----------------------------------------------------------------------
                      print rigid bodies
----------------------------------------------------------------------*/
static void
printRBody(vsy_HashTable* rbhash, vis_Connect* connect)
{
    vis_RBody* rbody;
    Vint id;
    Vint enttype, refnode, asid, numelem, nument, numnode;

    printf("\nRigid Bodies\n");
    vsy_HashTableInitIter(rbhash);
    while (vsy_HashTableNextIter(rbhash, &id, (Vobject**)&rbody), rbody) {
        printf("id= %d\n", id);
        vis_RBodyInq(rbody, &enttype);
        if (enttype == SYS_EDGE) {
            printf(" Element Edge\n");
        }
        else if (enttype == SYS_FACE) {
            printf(" Element Face\n");
        }
        else if (enttype == SYS_ELEM) {
            printf(" Element\n");
        }
        vis_RBodyElemNum(rbody, &numelem, &nument);
        if (numelem) {
            printf("Number of elements= %d\n", numelem);
            printf("Number of element entities= %d\n", nument);
        }
        vis_RBodyASurf(rbody, &asid);
        if (asid) {
            printf("Analytic Surface id= %d\n", asid);
        }

        vis_RBodyNodeNum(rbody, &numnode);
        if (numnode) {
            printf("Number of nodes= %d\n", numnode);
        }

        vis_RBodyGetRefNode(rbody, &refnode);
        printf(" Ref Node= %d\n", refnode);
    }
}

/*----------------------------------------------------------------------
                      print analytic surfaces
----------------------------------------------------------------------*/
static void
printASurf(vsy_HashTable* ashash, vis_Connect* connect)
{
    vis_ASurf* asurf;
    Vint id, type;
    Vchar name[64];
    Vdouble x[3], r;
    Vdouble a[3], b[3], c[3], length, width, height, radius;
    Vint numpnt, numseg;

    printf("\nAnalytic Surfaces\n");
    vsy_HashTableInitIter(ashash);
    while (vsy_HashTableNextIter(ashash, &id, (Vobject**)&asurf), asurf) {
        printf("id= %d\n", id);
        vis_ASurfInq(asurf, &type);
        vis_ASurfGetName(asurf, name);
        if (name[0] != '\0') {
            printf("name= %s\n", name);
        }
        if (type == ASURF_SPHERE) {
            vis_ASurfGetSpheredv(asurf, x, &r);
            printf("Sphere, id= %d, x= %f %f %f, r= %f\n", id, x[0], x[1], x[2], r);
        }
        else if (type == ASURF_CYLINDER) {
            vis_ASurfGetCylinderdv(asurf, a, b, c, &radius, &height);
            printf("Cylinder, id= %d, a= %f %f %f\n", id, a[0], a[1], a[2]);
            printf("                  b= %f %f %f\n", b[0], b[1], b[2]);
            printf("                  c= %f %f %f\n", c[0], c[1], c[2]);
            printf("                  radius= %f\n", radius);
            printf("                  height= %f\n", height);
        }
        else if (type == ASURF_PLANE) {
            vis_ASurfGetPlanedv(asurf, a, b, c, &length, &width);
            printf("Plane, id= %d, a= %f %f %f\n", id, a[0], a[1], a[2]);
            printf("               b= %f %f %f\n", b[0], b[1], b[2]);
            printf("               c= %f %f %f\n", c[0], c[1], c[2]);
            printf("               length= %f, width= %f\n", length, width);
        }
        else if (type == ASURF_BOX) {
            vis_ASurfGetBoxdv(asurf, a, b, c, &length, &width, &height);
            printf("Box, id= %d, a= %f %f %f\n", id, a[0], a[1], a[2]);
            printf("             b= %f %f %f\n", b[0], b[1], b[2]);
            printf("             c= %f %f %f\n", c[0], c[1], c[2]);
            printf("             length= %f, width= %f, height= %f\n", length, width, height);
        }
        else if (type == ASURF_SEGMENT) {
            vis_ASurfNumPoints(asurf, &numpnt);
            vis_ASurfNumSegments(asurf, &numseg);
            printf("Segment, id= %d, numpnts= %d, numseg= %d\n", id, numpnt, numseg);
        }
        else if (type == ASURF_SEGMENT_REV) {
            vis_ASurfNumPoints(asurf, &numpnt);
            vis_ASurfNumSegments(asurf, &numseg);
            printf("Segment Rev, id= %d, numpnts= %d, numseg= %d\n", id, numpnt, numseg);
            vis_ASurfGetSegmentRevdv(asurf, a, b, c);
            printf("             a= %f %f %f\n", a[0], a[1], a[2]);
            printf("             b= %f %f %f\n", b[0], b[1], b[2]);
            printf("             c= %f %f %f\n", c[0], c[1], c[2]);
        }
        else if (type == ASURF_SEGMENT_RULE) {
            vis_ASurfNumPoints(asurf, &numpnt);
            vis_ASurfNumSegments(asurf, &numseg);
            printf("Segment Rule, id= %d, numpnts= %d, numseg= %d\n", id, numpnt, numseg);
            vis_ASurfGetSegmentRuledv(asurf, a, b, c);
            printf("             a= %f %f %f\n", a[0], a[1], a[2]);
            printf("             b= %f %f %f\n", b[0], b[1], b[2]);
            printf("             c= %f %f %f\n", c[0], c[1], c[2]);
        }
    }
}

/*----------------------------------------------------------------------
                      print solution properties
----------------------------------------------------------------------*/
static void
printSProp(vsy_List* splist)
{
    Vint i, j;
    vis_SProp* sprop;
    Vint id;
    Vint sptype;
    Vint ntypes, *type;
    Vint flag, nval, dtyp;
    Vchar name[64];
    Vint iparams[100];
    Vdouble dparams[100];
    Vchar cparams[81];

    printf("\nSolution Properties\n");
    vsy_ListInitIter(splist);
    while (vsy_ListNextIter(splist, &id, (Vobject**)&sprop), sprop) {
        printf("id= %d, type= ", id);
        vis_SPropInq(sprop, &sptype);
        if (sptype == SYS_SOL_STATIC) {
            printf(" Static Analysis Property\n");
        }
        else if (sptype == SYS_SOL_VIBRATION) {
            printf(" Vibration Analysis Property\n");
        }
        else if (sptype == SYS_SOL_BUCKLING) {
            printf(" Buckling Analysis Property\n");
        }
        else if (sptype == SYS_SOL_TRANSIENT) {
            printf(" Transient Analysis Property\n");
        }
        vis_SPropValueTypeNum(sprop, &ntypes);
        type = (Vint*)malloc(ntypes * sizeof(Vint));
        vis_SPropValueType(sprop, &ntypes, type);

        /* loop through types generically */
        for (i = 0; i < ntypes; i++) {
            vis_SPropValueName(sprop, type[i], name);
            printf("\n name = %s\n", name);
            vis_SPropValueFlag(sprop, type[i], &flag);
            if (flag == SPROP_UNDEFINED) {
                printf("Undefined\n");
            }
            else {
                vis_SPropValueParams(sprop, type[i], &nval, &dtyp);
                printf(" nval= %d\n", nval);
                /* check for too many values for array size */
                if (nval > 100)
                    continue;
                /* integer valued */
                if (dtyp == SYS_INTEGER) {
                    printf(" Integer\n");
                    vis_SPropValueInteger(sprop, type[i], iparams);
                    for (j = 0; j < nval; j++) {
                        printf("  value= %d\n", iparams[j]);
                    }
                    /* real valued */
                }
                else if (dtyp == SYS_REAL) {
                    vis_SPropValueDouble(sprop, type[i], dparams);
                    printf(" Real\n");
                    for (j = 0; j < nval; j++) {
                        printf("  value= %e\n", dparams[j]);
                    }
                    /* character valued */
                }
                else if (dtyp == SYS_CHAR) {
                    vis_SPropValueString(sprop, type[i], cparams);
                    printf("  value= %s\n", cparams);
                }
            }
        }
        free(type);
    }
}
