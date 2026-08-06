#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/msh/msh.h"
#include "sam/vdm/vdm.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/* points defining corners of cantilever beam */
static Vdouble pnts[8][3] = {{0., 0., 0.},  {1., 0., 0.},  {0., 1., 0.},  {1., 1., 0.},
                             {0., 0., 10.}, {1., 0., 10.}, {0., 1., 10.}, {1., 1., 10.}};

/* triangles defining surface of cantilever beam */
static Vint tris[12][3] = {{1, 5, 3}, {3, 5, 7}, {4, 6, 2}, {8, 6, 4}, {1, 2, 5}, {5, 2, 6},
                           {7, 4, 3}, {8, 4, 7}, {1, 4, 2}, {4, 1, 3}, {5, 8, 7}, {5, 6, 8}};

/* triangles edges to be preserved */
static Vint efls[12][3] = {{1, 0, 1}, {0, 1, 1}, {0, 1, 1}, {1, 0, 1}, {1, 0, 0}, {0, 0, 1},
                           {0, 1, 0}, {0, 0, 1}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

/*----------------------------------------------------------------------
                      Generate 3D Volume Tet Model and Write to .vdm File
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    Vint i, k;
    msh_SurfMesh* surfmesh;
    msh_TetMesh* tetmesh;
    vis_Connect* connectsurf;
    vis_Group *groupface, *groupnode;

    vis_Model* model;
    vis_Connect* connect;
    vis_GridFun* gridfun;
    vis_MProp* mprop;
    vis_EProp* eprop;
    vis_SProp* sprop;
    vis_RCase* rcase;
    vis_LCase* lcase;
    vsy_HashTable *mphash, *ephash, *rchash, *lchash;
    vsy_List* splist;

    vdm_DataFun* datafun;
    vdm_NatLib* natlib;
    vdm_LMan* lman;

    Vint numpnts, numtris;
    Vdouble x[3];
    Vint nix, tri[6];
    Vint numsurfpnts, numsurftris;
    Vint numtetpnts, numtets;
    Vint flag, flagno, maxi;
    Vdouble edgelen;
    Vchar outpath[256];
    Vint no;
    Vint aid;
    Vdouble v[10][3], temp;

    /* check for proper number of arguments */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s outputfile\n", argv[0]);
        fprintf(stderr, " outputfile is blank, exam49vdm.vdm is assumed\n");
        strcpy(outpath, "exam49vdm.vdm");
    }
    else {
        strcpy(outpath, argv[1]);
    }

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* element order */
    maxi = 3;

    numpnts = 8;
    numtris = 12;
    /* instance surf mesher */
    surfmesh = msh_SurfMeshBegin();
    msh_SurfMeshDef(surfmesh, numpnts, numtris);

    /* define input points */
    for (i = 1; i <= numpnts; i++) {
        msh_SurfMeshSetPoint(surfmesh, i, pnts[i - 1], 0);
    }

    /* define input triangles and preserved edge flags */
    for (i = 1; i <= numtris; i++) {
        msh_SurfMeshSetTri(surfmesh, i, tris[i - 1], efls[i - 1]);
    }
    /* define node associations at z=0. for restraints */
    msh_SurfMeshSetTriAssoc(surfmesh, VIS_MISCID1, 9, SYS_FACE, 0, 1);
    msh_SurfMeshSetTriAssoc(surfmesh, VIS_MISCID1, 10, SYS_FACE, 0, 1);

    /* define node associations at z=10. for loads */
    msh_SurfMeshSetTriAssoc(surfmesh, VIS_MISCID2, 11, SYS_FACE, 0, 1);
    msh_SurfMeshSetTriAssoc(surfmesh, VIS_MISCID2, 12, SYS_FACE, 0, 1);

    /* instance Connect object to hold generated surface tris */
    connectsurf = vis_ConnectBegin();
    vis_ConnectPre(connectsurf, SYS_DOUBLE);
    vis_ConnectDef(connectsurf, 0, 0);

    /* set target edge length */
    edgelen = .50;
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_EDGELENGTH, edgelen);
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_MINEDGELENGTH, .2 * edgelen);

    /* set span angles, etc. */
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_SPANANGLE, 30.);
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_MINANGLE, 20.);
    msh_SurfMeshSetParami(surfmesh, VIS_MESH_MAXI, maxi);

    /* generate quality surface mesh */
    msh_SurfMeshGenerate(surfmesh, connectsurf);
    if (msh_SurfMeshError(surfmesh)) {
        printf("surface mesh generation error\n");
        exit(1);
    }
    else {
        printf("surface mesh generation complete\n");
    }
    /* find out the number of generated nodes and elements */
    vis_ConnectNumber(connectsurf, SYS_NODE, &numsurfpnts);
    vis_ConnectNumber(connectsurf, SYS_ELEM, &numsurftris);
    printf(" Number of nodes= %d\n", numsurfpnts);
    printf(" Number of tris = %d\n", numsurftris);

    /* create TetMesh object */
    tetmesh = msh_TetMeshBegin();
    msh_TetMeshDef(tetmesh, numsurfpnts, numsurftris, maxi);

    /* fill TetMesh object with generated points on surface */
    for (i = 1; i <= numsurfpnts; i++) {
        vis_ConnectCoordsdv(connectsurf, 1, &i, (Vdouble(*)[3])x);
        msh_TetMeshSetNode(tetmesh, i, x);
    }
    /* fill TetMesh object with generated triangles */
    for (i = 1; i <= numsurftris; i++) {
        vis_ConnectElemNode(connectsurf, i, &nix, tri);
        msh_TetMeshSetTri(tetmesh, i, tri);
    }
    /* create Connect object to hold generated tet mesh */
    connect = vis_ConnectBegin();
    vis_ConnectPre(connect, SYS_DOUBLE);
    vis_ConnectDef(connect, 0, 0);

    msh_TetMeshSetParamd(tetmesh, VIS_MESH_EDGELENGTH, edgelen);

    /* generate mesh */
    msh_TetMeshGenerate(tetmesh, connect);
    if (msh_TetMeshError(tetmesh)) {
        printf("tet mesh generation error\n");
        exit(1);
    }
    else {
        printf("tet mesh generation complete\n");
    }
    /* find out the number of generated nodes and elements */
    vis_ConnectNumber(connect, SYS_NODE, &numtetpnts);
    vis_ConnectNumber(connect, SYS_ELEM, &numtets);
    printf(" Number of nodes= %d\n", numtetpnts);
    printf(" Number of tets = %d\n", numtets);

    vis_ConnectKernel(connect, 0);

    /* set property identifier 1 for each element */
    for (i = 1; i <= numtets; i++) {
        vis_ConnectSetElemAssoc(connect, VIS_PROPID, i, 1);
    }
    /* instance a GridFun object */
    gridfun = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gridfun);

    /* create Model object hierarchy */
    model = vis_ModelBegin();

    /* material and element property hash tables */
    mphash = vsy_HashTableBegin();
    ephash = vsy_HashTableBegin();

    /* restraint and load case hash tables */
    rchash = vsy_HashTableBegin();
    lchash = vsy_HashTableBegin();

    /* solution property list */
    splist = vsy_ListBegin();

    /* isotropic material 1 */
    mprop = vis_MPropBegin();
    vis_MPropDef(mprop, SYS_MAT_ISOTROPIC);
    vis_MPropSetValued(mprop, MPROP_E, 1.e+7);
    vis_MPropSetValued(mprop, MPROP_NU, .3);
    vis_MPropSetValued(mprop, MPROP_DENSITY, 0.0000133);
    vis_MPropSetValued(mprop, MPROP_A, 0.000254);
    vis_MPropSetValued(mprop, MPROP_TREF, 70.0);
    vsy_HashTableInsert(mphash, 1, mprop);

    /* solid property 1 */
    eprop = vis_EPropBegin();
    vis_EPropDef(eprop, VIS_ELEM_SOLID);
    vis_EPropSetValuei(eprop, EPROP_MID, 1);
    vsy_HashTableInsert(ephash, 1, eprop);

    /* restraint case 1 */
    rcase = vis_RCaseBegin();
    for (i = 1; i <= numsurfpnts; i++) {
        vis_ConnectNodeAssoc(connectsurf, VIS_MISCID1, 1, &i, &aid);
        if (aid) {
            vis_RCaseSetSPC(rcase, i, SYS_DOF_TX, RCASE_FIXED, NULL, 0);
            vis_RCaseSetSPC(rcase, i, SYS_DOF_TY, RCASE_FIXED, NULL, 0);
            vis_RCaseSetSPC(rcase, i, SYS_DOF_TZ, RCASE_FIXED, NULL, 0);
        }
    }
    vsy_HashTableInsert(rchash, 1, rcase);

    /* load node associations to query for element faces */
    groupnode = vis_GroupBegin();
    vis_GroupDef(groupnode, numtetpnts, SYS_NODE, SYS_NONE);
    for (i = 1; i <= numsurfpnts; i++) {
        vis_ConnectNodeAssoc(connectsurf, VIS_MISCID2, 1, &i, &aid);
        vis_GroupSetIndex(groupnode, i, aid);
    }
    /* build face group to query for element faces */
    groupface = vis_GroupBegin();
    vis_GroupDef(groupface, numtets, SYS_ELEM, SYS_FACE);
    vis_ConnectFaceGroup(connect, CONNECT_CONTAINED, groupnode, groupface);

    /* load case 1, distributed load */
    lcase = vis_LCaseBegin();
    vis_LCaseSetObject(lcase, VIS_GRIDFUN, gridfun);
    for (k = 0; k < 10; k++) {
        v[k][0] = 0.;
        v[k][1] = 1.;
        v[k][2] = 0.;
    }
    for (i = 1; i <= numtets; i++) {
        vis_GroupGetIndex(groupface, i, &flag);
        if (flag == 0)
            continue;
        for (no = 1; no <= 6; no++) {
            vis_GroupGetEntFlag(groupface, i, no, &flagno);
            if (flagno) {
                vis_LCaseSetDistdv(lcase, SYS_FACE, i, no, LCASE_TRAC, (Vdouble*)v);
            }
        }
    }
    vsy_HashTableInsert(lchash, 1, lcase);

    /* load case 2, thermal load, soak temperature of 1000. */
    lcase = vis_LCaseBegin();
    temp = 1000.;
    for (i = 1; i <= numtetpnts; i++) {
        vis_LCaseSetConcdv(lcase, i, LCASE_TEMP, &temp);
    }
    vsy_HashTableInsert(lchash, 2, lcase);

    /* solution step 1 */
    sprop = vis_SPropBegin();
    vis_SPropDef(sprop, SYS_SOL_STATIC);
    vis_SPropSetValuec(sprop, SPROP_TITLE, (Vchar*)"Example 49");
    vis_SPropSetValuei(sprop, SPROP_ANALYSIS, SYS_ANALYSIS_STRUCTURAL);
    vis_SPropSetValuei(sprop, SPROP_RCASE, 1);
    vis_SPropSetValued(sprop, SPROP_RCASE_FACTOR, 1.);
    vis_SPropSetValuei(sprop, SPROP_LCASE_NUM, 1);
    vis_SPropSetValuei(sprop, SPROP_LCASE, 1);
    vis_SPropSetValued(sprop, SPROP_LCASE_FACTOR, 1.);
    vsy_ListInsert(splist, 1, sprop);

    /* solution step 2 */
    sprop = vis_SPropBegin();
    vis_SPropDef(sprop, SYS_SOL_STATIC);
    vis_SPropSetValuei(sprop, SPROP_ANALYSIS, SYS_ANALYSIS_STRUCTURAL);
    vis_SPropSetValuei(sprop, SPROP_RCASE, 1);
    vis_SPropSetValued(sprop, SPROP_RCASE_FACTOR, 1.);
    vis_SPropSetValuei(sprop, SPROP_LCASE_NUM, 1);
    vis_SPropSetValuei(sprop, SPROP_LCASE, 2);
    vis_SPropSetValued(sprop, SPROP_LCASE_FACTOR, 1.);
    vis_SPropSetValuei(sprop, SPROP_THERMALSTRAIN, SYS_ON);
    vsy_ListInsert(splist, 2, sprop);
    /* register Connect in Model */
    vis_ModelSetObject(model, VIS_CONNECT, connect);

    /* register property hashtables and lists in Model */
    vis_ModelSetHashTable(model, VIS_MPROP, mphash);
    vis_ModelSetHashTable(model, VIS_EPROP, ephash);
    vis_ModelSetList(model, VIS_SPROP, splist);

    /* register case hashtables in Model */
    vis_ModelSetHashTable(model, VIS_RCASE, rchash);
    vis_ModelSetHashTable(model, VIS_LCASE, lchash);
    printf("model definition complete\n");

    /* write NASTRAN Bulk Data File */
    vis_ModelWrite(model, SYS_NASTRAN_BULKDATA, (Vchar*)"exam49vdm.bdf");
    printf("model written to NASTRAN Bulk Data file %s\n", "exam49vdm.bdf");
    vis_ModelWrite(model, SYS_ABAQUS_INPUT, (Vchar*)"exam49vdm.inp");
    printf("model written to ABAQUS Input Data file %s\n", "exam49vdm.inp");

    /* save model to .vdm */
    natlib = vdm_NatLibBegin();
    datafun = vdm_DataFunBegin();
    lman = vdm_LManBegin();
    vdm_NatLibDataFun(natlib, datafun);
    vdm_DataFunSetConvention(datafun, VDM_CONVENTION_DOUBLE);
    vdm_DataFunSetStatus(datafun, VDM_STATUS_NEW);
    vdm_DataFunOpen(datafun, 0, outpath, VDM_NATIVE);
    vdm_LManSetObject(lman, VDM_DATAFUN, datafun);
    vdm_LManSaveModel(lman, model);
    vdm_DataFunClose(datafun);
    vdm_LManEnd(lman);
    vdm_DataFunEnd(datafun);
    vdm_NatLibEnd(natlib);
    printf("model saved on native .vdm output file %s\n", outpath);

    /* delete objects */
    msh_SurfMeshEnd(surfmesh);
    vis_ConnectEnd(connectsurf);
    msh_TetMeshEnd(tetmesh);
    vis_GridFunEnd(gridfun);
    vis_GroupEnd(groupface);
    vis_GroupEnd(groupnode);

    /* delete model heirarchy */
    vis_ConnectEnd(connect);
    vsy_HashTableForEach(ephash, (void (*)(Vobject*))vis_EPropEnd);
    vsy_HashTableEnd(ephash);
    vsy_HashTableForEach(mphash, (void (*)(Vobject*))vis_MPropEnd);
    vsy_HashTableEnd(mphash);
    vsy_ListForEach(splist, (void (*)(Vobject*))vis_SPropEnd);
    vsy_ListEnd(splist);
    vsy_HashTableForEach(rchash, (void (*)(Vobject*))vis_RCaseEnd);
    vsy_HashTableEnd(rchash);
    vsy_HashTableForEach(lchash, (void (*)(Vobject*))vis_LCaseEnd);
    vsy_HashTableEnd(lchash);
    vis_ModelEnd(model);
    return 0;
}
