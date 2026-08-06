#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static void
print_info(vis_Connect* connect, vsy_HashTable* ht, vsy_Concat* cc);

typedef struct Tobj {
    vis_Connect* connect;
    Vint numnp;
    Vint numel;
    vsy_HashTable* hashtable;
    vsy_Concat* concat;
} Tobj;

static void
TPolygonData(Tobj* t, Vint type, Vint npts, Vfloat x[][3], Vint nrws, Vfloat d[], Vint vflag, Vfloat v[])
{
    Vint i;
    Vint ix[8];
    void* pntr;
    /* set element topology */
    t->numel += 1;
    if (npts == 4) {
        vis_ConnectSetTopology(t->connect, t->numel, VIS_SHAPETET, 0, 0, 0);
    }
    else if (npts == 5) {
        vis_ConnectSetTopology(t->connect, t->numel, VIS_SHAPEPYR, 0, 0, 0);
    }
    else if (npts == 6) {
        vis_ConnectSetTopology(t->connect, t->numel, VIS_SHAPEWED, 0, 0, 0);
    }
    else if (npts == 8) {
        vis_ConnectSetTopology(t->connect, t->numel, VIS_SHAPEHEX, 0, 0, 0);
    }
    /* set node coordinates */
    for (i = 0; i < npts; i++) {
        t->numnp += 1;
        ix[i] = t->numnp;
        vis_ConnectSetCoords(t->connect, t->numnp, x[i]);
    }
    /* set element node connectivity */
    vis_ConnectSetElemNode(t->connect, t->numel, ix);

    /* store data */
    vsy_ConcatAdd(t->concat, nrws * npts * sizeof(Vfloat), d);
    vsy_ConcatRef(t->concat, &pntr);
    vsy_HashTableInsert(t->hashtable, t->numel, pntr);
}

/*----------------------------------------------------------------------
                      Clip Finite Elements to a Volume
----------------------------------------------------------------------*/
int
main()
{
    vgl_DrawFun* df;
    vis_VisContext* vc;
    vis_Cell* cell;
    vis_IsoClip* isoclip;
    vis_DataInt* dataint;
    vis_CoordSys* coordsys;

    Vfloat xc[8][3], d[8];
    Vfloat xo[3], tm[3][3];
    int i, j, k, n;
    Tobj tobj;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create draw function, with user object tobj */
    df = vgl_DrawFunBegin();
    vgl_DrawFunSetObj(df, (Vobject*)&tobj);
    vgl_DrawFunAPI(df, DRAWFUN_APIRETURN);
    vgl_DrawFunSet(df, DRAWFUN_POLYGONDATA, (Vfunc*)TPolygonData);

    tobj.connect = vis_ConnectBegin();
    tobj.numel = 0;
    tobj.numnp = 0;
    tobj.hashtable = vsy_HashTableBegin();
    tobj.concat = vsy_ConcatBegin();

    /* vis context and set attributes */
    vc = vis_VisContextBegin();
    vis_VisContextSetDraw(vc, VIS_OFF);
    vis_VisContextSetFlags(vc, VIS_CREATEPOLYHEDRON);

    /* define a cylindrical coordinate system */
    coordsys = vis_CoordSysBegin();
    vis_CoordSysDef(coordsys, SYS_CYLINDRICAL);
    xo[0] = 4.;
    xo[1] = 4.;
    xo[2] = 0.;
    tm[0][0] = 1.;
    tm[1][0] = 0.;
    tm[2][0] = 0.;
    tm[0][1] = 0.;
    tm[1][1] = 1.;
    tm[2][1] = 0.;
    tm[0][2] = 0.;
    tm[1][2] = 0.;
    tm[2][2] = 1.;
    vis_CoordSysSetOriginTriad(coordsys, xo, tm);

    /* isosurface clipping object */
    isoclip = vis_IsoClipBegin();
    vis_IsoClipSetCoordSys(isoclip, 0, coordsys);
    vis_IsoClipSetCoordSys(isoclip, 1, coordsys);
    vis_IsoClipSetCoordSys(isoclip, 2, coordsys);
    /* clip to a cylinder, radius=3.5, bottom=2.2, top=7.8 */
    vis_IsoClipSetType(isoclip, 0, ISOCLIP_X, ISOCLIP_HITHER, 3.5f);
    vis_IsoClipSetType(isoclip, 1, ISOCLIP_Z, ISOCLIP_YON, 2.2f);
    vis_IsoClipSetType(isoclip, 2, ISOCLIP_Z, ISOCLIP_HITHER, 7.8f);

    /* data interpolation object for scalar field */
    dataint = vis_DataIntBegin();
    vis_DataIntSetDataPtr(dataint, 0, 1, d);

    /* create cell object and set objects */
    cell = vis_CellBegin();
    vis_CellSetObject(cell, VGL_DRAWFUN, df);
    vis_CellSetObject(cell, VIS_VISCONTEXT, vc);
    vis_CellSetObject(cell, VIS_ISOCLIP, isoclip);
    vis_CellSetObject(cell, VIS_DATAINT, dataint);
    vis_CellSetTopology(cell, VIS_SHAPEHEX, 2, 0, 0);

    /* process cell volumes, 1000 unit cubes */
    for (k = 0; k < 10; k++) {
        for (j = 0; j < 10; j++) {
            for (i = 0; i < 10; i++) {
                xc[0][0] = (Vfloat)i;
                xc[0][1] = (Vfloat)j;
                xc[0][2] = (Vfloat)k;
                xc[1][0] = (Vfloat)i + 1;
                xc[1][1] = (Vfloat)j;
                xc[1][2] = (Vfloat)k;
                xc[2][0] = (Vfloat)i + 1;
                xc[2][1] = (Vfloat)j + 1;
                xc[2][2] = (Vfloat)k;
                xc[3][0] = (Vfloat)i;
                xc[3][1] = (Vfloat)j + 1;
                xc[3][2] = (Vfloat)k;
                xc[4][0] = (Vfloat)i;
                xc[4][1] = (Vfloat)j;
                xc[4][2] = (Vfloat)k + 1;
                xc[5][0] = (Vfloat)i + 1;
                xc[5][1] = (Vfloat)j;
                xc[5][2] = (Vfloat)k + 1;
                xc[6][0] = (Vfloat)i + 1;
                xc[6][1] = (Vfloat)j + 1;
                xc[6][2] = (Vfloat)k + 1;
                xc[7][0] = (Vfloat)i;
                xc[7][1] = (Vfloat)j + 1;
                xc[7][2] = (Vfloat)k + 1;
                /* generate a scalar data field, x + y**2 */
                for (n = 0; n < 8; n++) {
                    d[n] = xc[n][0] + xc[n][1] * xc[n][1];
                }
                vis_CellCurv(cell, xc);
            }
        }
    }
    /* print some information about the resulting polyhedra */
    print_info(tobj.connect, tobj.hashtable, tobj.concat);

    /* clean up tobj */
    vis_ConnectEnd(tobj.connect);
    vsy_HashTableEnd(tobj.hashtable);
    vsy_ConcatEnd(tobj.concat);

    /* free all objects */
    vgl_DrawFunEnd(df);
    vis_VisContextEnd(vc);
    vis_CellEnd(cell);
    vis_IsoClipEnd(isoclip);
    vis_DataIntEnd(dataint);
    vis_CoordSysEnd(coordsys);
    return 0;
}

/*----------------------------------------------------------------------
                      print volume information
----------------------------------------------------------------------*/
static void
print_info(vis_Connect* connect, vsy_HashTable* ht, vsy_Concat* cc)
{
    Vint i;
    Vint index;
    Vint numnp, numel;
    vis_ElemChk* elemchk;
    vis_GridFun* gf;
    Vfloat s[ELEMCHK_MAX];
    Vfloat volume;
    Vint nix, ix[8];
    Vfloat *d, x[8][3];

    /* write NASTRAN bulk data file of polyhedra */
    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "exam9a.bdf");

    vis_ConnectNumber(connect, SYS_NODE, &numnp);
    vis_ConnectNumber(connect, SYS_ELEM, &numel);
    printf("number of nodes= %d\n", numnp);
    printf("number of elems= %d\n", numel);

    /* compute volume */
    gf = vis_GridFunBegin();
    vis_ConnectGridFun(connect, gf);
    elemchk = vis_ElemChkBegin();
    vis_ElemChkSetObject(elemchk, VIS_GRIDFUN, gf);
    vis_ElemChkSetType(elemchk, ELEMCHK_JACOBIAN_SUM, SYS_ON);
    volume = 0.;
    for (i = 1; i <= numel; i++) {
        vis_ElemChkData(elemchk, i, s);
        volume += s[ELEMCHK_JACOBIAN_SUM];
    }
    printf("volume= %f\n", volume);

    /* delete objects */
    vis_GridFunEnd(gf);
    vis_ElemChkEnd(elemchk);

    /* print data and coordinates of first polyhedron*/
    index = 1;
    vsy_HashTableLookup(ht, index, (Vobject**)&d);
    vis_ConnectElemNode(connect, index, &nix, ix);
    vis_ConnectCoords(connect, nix, ix, x);
    for (i = 0; i < nix; i++) {
        printf(" x= %f, y= %f, z= %f, d= %f\n", x[i][0], x[i][1], x[i][2], d[i]);
    }
}
