/*********************************************************************
 *                                                                   *
 *                          DevTools 3.1.0                           *
 *                                                                   *
 *  These coded instructions, statements and computer programs       *
 *  contain unpublished proprietary information of Tech Soft 3D,     *
 *  and are protected by Federal copyright law.  They may not be     *
 *  disclosed to third parties or copied or duplicated in any form,  *
 *  in whole or in part, without the prior written consent of        *
 *  Tech Soft 3D.                                                    *
 *                                                                   *
 *                 Copyright (C) 2026, Tech Soft 3D                  *
 *                                                                   *
 *********************************************************************/
/* VisTools shared functions header file */

#ifndef VISSHAR_DEF
#define VISSHAR_DEF

#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"

#ifdef __cplusplus
extern "C" {
#endif

VKI_EXTERN Vint
VIS_numDimeShape(Vint shape);
VKI_EXTERN Vint
VIS_shapeNumCorn2D(Vint num);
VKI_EXTERN Vint
VIS_numEdgeShape(Vint shape);
VKI_EXTERN Vint
VIS_numCornShape(Vint shape);
VKI_EXTERN Vint
VIS_numFaceShape(Vint shape);
VKI_EXTERN Vint
VIS_numVecsElemSys(Vint num);
VKI_EXTERN Vint
VIS_numRowsDataType(Vint num);
VKI_EXTERN Vint
VIS_numRowsElemSys(Vint num);
VKI_EXTERN Vint
VIS_shapeNumCorn3D(Vint num);
/* inline methods */
extern Vint vis_nvalscplxtype[7];
#define VIS_numValsCplxType(num) vis_nvalscplxtype[(num)]
extern Vint vis_nposlay[12];
#define VIS_numPosLay(num) vis_nposlay[(num)]
extern Vint vis_classDofTag[SYS_DOF_MAX];
#define VIS_classDofTag(num) vis_classDofTag[(num)]

VKI_EXTERN void
vis_compMisMid(Vint shape, Vint* npe, Vint* maxi, Vint* maxj, Vint ix[]);
VKI_EXTERN void
vis_restMisMid(Vint shape, Vint* npe, Vint* maxi, Vint* maxj, Vint ix[]);
VKI_EXTERN void
vis_renumMisMid(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vint* nix, Vint ix[]);
VKI_EXTERN void
vis_shapeMisMid(Vint isw, Vint shape, Vint maxi, Vint maxj, Vint maxk, Vfloat h[], Vint ndim, Vfloat phr[]);
VKI_EXTERN void
vis_shapeMisMiddv(Vint isw, Vint shape, Vint maxi, Vint maxj, Vint maxk, Vdouble h[], Vint ndim, Vdouble phr[]);
VKI_EXTERN void
vis_numberNode(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vint* nnodes);
VKI_EXTERN void
vis_numberCornNode(Vint shape, Vint maxi, Vint* nnodes);
VKI_EXTERN void
vis_numberEdge(Vint shape, Vint maxj, Vint* nedges);
VKI_EXTERN void
vis_numberFace(Vint shape, Vint maxk, Vint* nfaces);
VKI_EXTERN void
vis_getEdgeFace(Vint shape, Vint iedge, Vint* njx, Vint jx[]);
VKI_EXTERN void
vis_getFaceEdge(Vint shape, Vint iface, Vint* njx, Vint jx[]);
VKI_EXTERN void
vis_cornerNode(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vint ix[]);
VKI_EXTERN void
vis_getEdgeTopo(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vint iedge, Vint* maxie);
VKI_EXTERN void
vis_getFaceTopo(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vint iface, Vint* shapef, Vint* maxif, Vint* maxjf);
VKI_EXTERN void
vis_allEdgeNode(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vint iedge, Vint* nedgepts, Vint edgepts[]);
VKI_EXTERN void
vis_allFaceNode(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vint iface, Vint* nfacepts, Vint facepts[]);
VKI_EXTERN void
vis_allFaceNodePolyhed(Vint maxi, Vint maxk, Vint iface, Vint ifx[], Vint* nfacepts, Vint facepts[]);
VKI_EXTERN void
vis_cornerEdgeNode(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vint iedge, Vint edgepts[]);
VKI_EXTERN void
vis_cornerFaceNode(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vint iface, Vint* nfacepts, Vint facepts[]);
VKI_EXTERN void
vis_convertTopo(Vint topo, Vint* shape, Vint* maxi, Vint* maxj, Vint* maxk);
VKI_EXTERN void
vis_computeTopo(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vint* topo);
VKI_EXTERN void
vis_convertSect(Vint sect, Vint* lpos, Vint* nsec);
VKI_EXTERN void
vis_computeSect(Vint lpos, Vint nsec, Vint* sect);
VKI_EXTERN void
vis_numLayPosSect(Vint lpos, Vint* nsec);
VKI_EXTERN void
vis_parLine(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vint* nlines, Vint nodes[][3]);
VKI_EXTERN void
vis_cubicLine(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vint* nlines, Vint nodes[][4]);
VKI_EXTERN void
vis_reverseEdgeNode(Vint maxi, Vint ix[]);
VKI_EXTERN void
vis_reverseFaceNode(Vint shape, Vint maxi, Vint maxj, Vint ix[]);
VKI_EXTERN void
vis_metricNC(Vint shape, Vint* mdim, Vfloat rm[]);
VKI_EXTERN void
vis_metricNCdv(Vint shape, Vint* mdim, Vdouble rm[]);
VKI_EXTERN void
vis_centNC(Vint shape, Vfloat rst[]);
VKI_EXTERN void
vis_centNCdv(Vint shape, Vdouble rst[]);
VKI_EXTERN void
vis_cornerNC(Vint shape, Vfloat rst[][3]);
VKI_EXTERN void
vis_elemNCdv(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vdouble rst[][3]);
VKI_EXTERN void
vis_elemNCPolygondv(Vint maxi, Vdouble rst[][3]);
VKI_EXTERN void
vis_elemNCPolyheddv(Vint maxi, Vint ix[], Vdouble rst[][3]);
VKI_EXTERN void
vis_elemNC(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vfloat rst[][3]);
VKI_EXTERN void
vis_elemNCPolygon(Vint maxi, Vfloat rst[][3]);
VKI_EXTERN void
vis_elemNCPolyhed(Vint maxi, Vint ix[], Vfloat rst[][3]);
VKI_EXTERN void
vis_minmaxNCdv(Vint shape, Vdouble rmin[], Vdouble rmax[]);
VKI_EXTERN void
vis_boundNC(Vint shape, Vfloat ri[], Vfloat rmin[], Vfloat rmax[], Vint* ierr);
VKI_EXTERN void
vis_boundNCdv(Vint shape, Vdouble ri[], Vdouble rmin[], Vdouble rmax[], Vint* ierr);
VKI_EXTERN void
vis_faceNC(Vint shape, Vfloat r[], Vfloat rp[]);
VKI_EXTERN void
vis_shapeLin(Vint isw, Vfloat r, Vfloat h[2], Vfloat phr[2]);
VKI_EXTERN void
vis_shapeTri(Vint isw, Vfloat r[2], Vfloat h[3], Vfloat phr[3][2]);
VKI_EXTERN void
vis_shapeQuad(Vint isw, Vfloat r[2], Vfloat h[4], Vfloat phr[4][2]);
VKI_EXTERN void
vis_shapeTet(Vint isw, Vfloat r[3], Vfloat h[4], Vfloat phr[4][3]);
VKI_EXTERN void
vis_shapePyr(Vint isw, Vfloat r[3], Vfloat h[5], Vfloat phr[5][3]);
VKI_EXTERN void
vis_shapeWed(Vint isw, Vfloat r[3], Vfloat h[6], Vfloat phr[6][3]);
VKI_EXTERN void
vis_shapeHex(Vint isw, Vfloat r[3], Vfloat h[8], Vfloat phr[8][3]);
VKI_EXTERN void
vis_shapeTriSer(Vint isw, Vint mside, Vfloat rs[2], Vfloat h[], Vfloat phr[][2]);
VKI_EXTERN void
vis_shapeQuadSer(Vint isw, Vint mside, Vfloat r[2], Vfloat h[], Vfloat phr[][2]);
VKI_EXTERN void
vis_shapeTetSer(Vint isw, Vint mside, Vfloat rs[3], Vfloat h[], Vfloat phr[][3]);
VKI_EXTERN void
vis_shapePyrSer(Vint isw, Vint mside, Vfloat rs[3], Vfloat h[], Vfloat phr[][3]);
VKI_EXTERN void
vis_shapeWedSer(Vint isw, Vint mside, Vfloat rs[3], Vfloat h[], Vfloat phr[][3]);
VKI_EXTERN void
vis_shapeHexSer(Vint isw, Vint mside, Vfloat r1[3], Vfloat h[], Vfloat phr[][3]);
VKI_EXTERN void
vis_shapeLinLag(Vint isw, Vint mside, Vfloat r, Vfloat h[], Vfloat phr[]);
VKI_EXTERN void
vis_shapeTriLag(Vint isw, Vint mside, Vfloat r[2], Vfloat h[], Vfloat phr[][2]);
VKI_EXTERN void
vis_shapeQuadLag(Vint isw, Vint maxi, Vint maxj, Vfloat r[2], Vfloat h[], Vfloat phr[][2]);
VKI_EXTERN void
vis_shapeTetLag(Vint isw, Vint mside, Vfloat r[3], Vfloat h[], Vfloat phr[][3]);
VKI_EXTERN void
vis_shapePyrLag(Vint isw, Vint mside, Vfloat rs[3], Vfloat h[], Vfloat phr[][3]);
VKI_EXTERN void
vis_shapeWedLag(Vint isw, Vint maxi, Vint maxk, Vfloat r[3], Vfloat h[], Vfloat phr[][3]);
VKI_EXTERN void
vis_shapeHexLag(Vint isw, Vint maxi, Vint maxj, Vint maxk, Vfloat r[3], Vfloat h[], Vfloat phr[][3]);
VKI_EXTERN void
vis_shapeWedSerLag(Vint isw, Vint maxi, Vint maxk, Vfloat r[3], Vfloat h[], Vfloat phr[][3]);
VKI_EXTERN void
vis_shapeHexSerLag(Vint isw, Vint maxi, Vint maxk, Vfloat r[3], Vfloat h[], Vfloat phr[][3]);
VKI_EXTERN void
vis_shapeLindv(Vint isw, Vdouble r, Vdouble h[2], Vdouble phr[2]);
VKI_EXTERN void
vis_shapeTridv(Vint isw, Vdouble r[2], Vdouble h[3], Vdouble phr[3][2]);
VKI_EXTERN void
vis_shapeQuaddv(Vint isw, Vdouble r[2], Vdouble h[4], Vdouble phr[4][2]);
VKI_EXTERN void
vis_shapeTetdv(Vint isw, Vdouble r[3], Vdouble h[4], Vdouble phr[4][3]);
VKI_EXTERN void
vis_shapePyrdv(Vint isw, Vdouble r[3], Vdouble h[5], Vdouble phr[5][3]);
VKI_EXTERN void
vis_shapeWeddv(Vint isw, Vdouble r[3], Vdouble h[6], Vdouble phr[6][3]);
VKI_EXTERN void
vis_shapeHexdv(Vint isw, Vdouble r[3], Vdouble h[8], Vdouble phr[8][3]);
VKI_EXTERN void
vis_shapeTriSerdv(Vint isw, Vint mside, Vdouble rs[2], Vdouble h[], Vdouble phr[][2]);
VKI_EXTERN void
vis_shapeQuadSerdv(Vint isw, Vint mside, Vdouble r[2], Vdouble h[], Vdouble phr[][2]);
VKI_EXTERN void
vis_shapeTetSerdv(Vint isw, Vint mside, Vdouble rs[3], Vdouble h[], Vdouble phr[][3]);
VKI_EXTERN void
vis_shapePyrSerdv(Vint isw, Vint mside, Vdouble rs[3], Vdouble h[], Vdouble phr[][3]);
VKI_EXTERN void
vis_shapeWedSerdv(Vint isw, Vint mside, Vdouble rs[3], Vdouble h[], Vdouble phr[][3]);
VKI_EXTERN void
vis_shapeHexSerdv(Vint isw, Vint mside, Vdouble r1[3], Vdouble h[], Vdouble phr[][3]);
VKI_EXTERN void
vis_shapeLinLagdv(Vint isw, Vint mside, Vdouble r, Vdouble h[], Vdouble phr[]);
VKI_EXTERN void
vis_shapeTriLagdv(Vint isw, Vint mside, Vdouble r[2], Vdouble h[], Vdouble phr[][2]);
VKI_EXTERN void
vis_shapeQuadLagdv(Vint isw, Vint maxi, Vint maxj, Vdouble r[2], Vdouble h[], Vdouble phr[][2]);
VKI_EXTERN void
vis_shapeTetLagdv(Vint isw, Vint mside, Vdouble r[3], Vdouble h[], Vdouble phr[][3]);
VKI_EXTERN void
vis_shapePyrLagdv(Vint isw, Vint mside, Vdouble rs[3], Vdouble h[], Vdouble phr[][3]);
VKI_EXTERN void
vis_shapeWedLagdv(Vint isw, Vint maxi, Vint maxk, Vdouble r[3], Vdouble h[], Vdouble phr[][3]);
VKI_EXTERN void
vis_shapeHexLagdv(Vint isw, Vint maxi, Vint maxj, Vint maxk, Vdouble r[3], Vdouble h[], Vdouble phr[][3]);
VKI_EXTERN void
vis_shapeWedSerLagdv(Vint isw, Vint maxi, Vint maxk, Vdouble r[3], Vdouble h[], Vdouble phr[][3]);
VKI_EXTERN void
vis_shapeHexSerLagdv(Vint isw, Vint maxi, Vint maxk, Vdouble r[3], Vdouble h[], Vdouble phr[][3]);
VKI_EXTERN void
vis_shape2D(Vint isw, Vint npts, Vfloat r[2], Vfloat h[], Vfloat phr[][2]);
VKI_EXTERN void
vis_shape3D(Vint isw, Vint npts, Vfloat r[3], Vfloat h[], Vfloat phr[][3]);
VKI_EXTERN void
vis_shape1DGen(Vint isw, Vint maxi, Vfloat r, Vfloat h[], Vfloat phr[]);
VKI_EXTERN void
vis_shapePolygon(Vint isw, Vint maxi, Vfloat r[], Vfloat h[], Vfloat phr[][2]);
VKI_EXTERN void
vis_shape2DGen(Vint isw, Vint shape, Vint maxi, Vint maxj, Vfloat r[2], Vfloat h[], Vfloat phr[][2]);
VKI_EXTERN void
vis_shape3DGen(Vint isw, Vint shape, Vint maxi, Vint maxj, Vint maxk, Vfloat r[3], Vfloat h[], Vfloat phr[][3]);
VKI_EXTERN void
vis_shape1DGendv(Vint isw, Vint maxi, Vdouble r, Vdouble h[], Vdouble phr[]);
VKI_EXTERN void
vis_shapePolyhed(Vint isw, Vint ix[], Vint maxi, Vfloat r[], Vfloat h[], Vfloat phr[][3]);
VKI_EXTERN void
vis_shapePolyheddv(Vint isw, Vint ix[], Vint maxi, Vdouble r[], Vdouble h[], Vdouble phr[][3]);
VKI_EXTERN void
vis_shape2DGendv(Vint isw, Vint shape, Vint maxi, Vint maxj, Vdouble r[2], Vdouble h[], Vdouble phr[][2]);
VKI_EXTERN void
vis_shape3DGendv(Vint isw, Vint shape, Vint maxi, Vint maxj, Vint maxk, Vdouble r[3], Vdouble h[], Vdouble phr[][3]);
VKI_EXTERN void
vis_length1DGendv(Vint maxi, Vdouble x[][3], Vdouble* length);
VKI_EXTERN void
vis_dist1DGendv(Vint maxi, Vdouble x[][3], Vint nrws, Vdouble v[], Vdouble f[]);
VKI_EXTERN void
vis_invdist1DGendv(Vint maxi, Vdouble x[][3], Vint nrws, Vdouble f[], Vdouble v[]);
VKI_EXTERN void
vis_dist2DGendv(Vint shape, Vint maxi, Vint maxj, Vdouble x[][3], Vint nrws, Vdouble v[], Vdouble f[]);
VKI_EXTERN void
vis_invdist2DGendv(Vint shape, Vint maxi, Vint maxj, Vdouble x[][3], Vint nrws, Vdouble f[], Vdouble v[]);
VKI_EXTERN void
vis_dist3DGendv(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vdouble x[][3], Vint nrws, Vdouble v[], Vdouble f[]);
VKI_EXTERN void
vis_invdist3DGendv(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vdouble x[][3], Vint nrws, Vdouble f[], Vdouble v[]);
VKI_EXTERN void
vis_permuteElem(Vint iop, Vint nixe, Vint* ir, Vint ixe[], Vint ix[]);
VKI_EXTERN void
vis_permuteElemData(Vint iop, Vint nixe, Vint nrws, Vint* ir, Vfloat de[], Vfloat d[]);
VKI_EXTERN void
vis_permuteElemDatadv(Vint iop, Vint nixe, Vint nrws, Vint* ir, Vdouble de[], Vdouble d[]);
VKI_EXTERN void
vis_convertPyrtoHex(Vint* shape, Vint maxi, Vint* nix, Vint ix[]);
VKI_EXTERN void
vis_convertPyrtoHexEnt(Vint enttype, Vint pyrno, Vint* hexno);
VKI_EXTERN void
vis_convertInter(Vint* shape, Vint* maxi, Vint* maxj, Vint* maxk, Vint* nix, Vint ix[]);
VKI_EXTERN void
vis_buildElemfromFace(Vint shape, Vint shapef, Vint nfx, Vint ifx[], Vint nix, Vint ix[]);
VKI_EXTERN void
vis_convertElemtoPoly(Vint shape, Vint ix[], Vint* npx, Vint ixp[]);
VKI_EXTERN void
vis_facexPolyhed(Vint maxi, Vfloat x[][3], Vint ix[], Vint* nfx, Vint ifx[]);
VKI_EXTERN void
vis_facexPolyheddv(Vint maxi, Vdouble x[][3], Vint ix[], Vint* nfx, Vint ifx[]);
VKI_EXTERN void
vis_facePolyhed(Vint maxi, Vint ix[], Vint* nfx, Vint ifx[]);
VKI_EXTERN void
vis_fill2DSer(Vint shape, Vint maxi, Vint maxj, Vint nrws, Vfloat x[], Vfloat xf[]);
VKI_EXTERN void
vis_fill3DSer(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vint nrws, Vfloat x[], Vfloat xf[]);
VKI_EXTERN void
vis_fillCorner(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vint nrws, Vdouble xc[]);
VKI_EXTERN void
vis_fillCornerf(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vint nrws, Vfloat xc[]);
VKI_EXTERN void
vis_fillCornerAngle(Vint shape, Vint maxi, Vint maxj, Vdouble xc[]);
VKI_EXTERN void
vis_clampfill2DSer(Vint shape, Vint maxi, Vfloat s[]);
VKI_EXTERN void
vis_clampfill3DSer(Vint shape, Vint maxi, Vint maxk, Vfloat s[]);
VKI_EXTERN void
vis_fill2DPoly(Vint maxi, Vint nrws, Vfloat x[], Vfloat xf[]);
VKI_EXTERN void
vis_fill3DPoly(Vint maxi, Vint maxj, Vint ix[], Vint nrws, Vfloat x[], Vfloat xf[]);
VKI_EXTERN void
vis_proj2DIntpts2Node(Vint irule, Vint nquads, Vint shape, Vint maxi, Vint maxj, Vdouble prj[16][16], Vint* ier);
VKI_EXTERN void
vis_extr2DIntpts2Node(Vint nquads, Vint nnodes, Vint nr, Vdouble prj[16][16], Vdouble vq[], Vdouble vn[]);
VKI_EXTERN void
vis_proj1DIntpts2Node(Vint irule, Vint nquads, Vint maxi, Vdouble prj[3][3], Vint* ier);
VKI_EXTERN void
vis_extr1DIntpts2Node(Vint nquads, Vint nnodes, Vint nr, Vdouble prj[3][3], Vdouble vq[], Vdouble vn[]);
VKI_EXTERN void
vis_proj3DIntpts2Node(Vint nquads, Vint shape, Vint maxi, Vint maxj, Vint maxk, Vdouble prj[64][64], Vint* ier);
VKI_EXTERN void
vis_extr3DIntpts2Node(Vint nquads, Vint nnodes, Vint nr, Vdouble prj[64][64], Vdouble vq[], Vdouble vn[]);
VKI_EXTERN void
vis_rotZTensor(Vdouble phi, Vdouble tens[]);
VKI_EXTERN void
vis_rotZVector(Vdouble phi, Vdouble vec[]);
VKI_EXTERN void
vis_rotNVector(Vdouble phi, Vdouble vn[3], Vdouble vec[]);
VKI_EXTERN void
vis_transDMatrix(Vdouble dinit[21], Vdouble T[6][6], Vdouble dfinal[21]);
VKI_EXTERN void
vis_transStrain3D2(Vdouble r[3][3], Vint isEngineerStrain, Vdouble t[6][6]);
VKI_EXTERN void
vis_rotZDMatrix(Vdouble phi, Vdouble d[]);
VKI_EXTERN void
vis_rotZKMatrix(Vint ipat, Vdouble phi, Vdouble d[]);
VKI_EXTERN void
vis_condDMatrix(Vint ipat, Vint cond[], Vdouble d[]);
VKI_EXTERN void
vis_computeDMatrix(Vint type, Vdouble props[], Vdouble d[], Vint* ierr);
VKI_EXTERN void
vis_coord1DGendv(Vint maxi, Vdouble x[][3], Vdouble r, Vdouble xp[3]);
VKI_EXTERN void
vis_coord2DGendv(Vint shape, Vint maxi, Vint maxj, Vdouble x[][3], Vdouble r[2], Vdouble xp[3]);
VKI_EXTERN void
vis_coord3DGendv(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vdouble x[][3], Vdouble r[3], Vdouble xp[3]);
VKI_EXTERN void
vis_tangent1DGen(Vint maxi, Vfloat x[][3], Vfloat r, Vfloat v[3]);
VKI_EXTERN void
vis_tangent1DGendv(Vint maxi, Vdouble x[][3], Vdouble r, Vdouble v[3]);
VKI_EXTERN void
vis_curvature1DGen(Vint maxi, Vfloat x[][3], Vfloat v[][3], Vfloat r, Vfloat vk[3], Vfloat* rk, Vfloat pk[3]);
VKI_EXTERN void
vis_curvature1DGendv(Vint maxi, Vdouble x[][3], Vdouble v[][3], Vdouble r, Vdouble vk[3], Vdouble* rk, Vdouble pk[3]);
VKI_EXTERN void
vis_curvature2DGen(Vint shape, Vint maxi, Vint maxj, Vfloat x[][3], Vfloat v[][3], Vfloat r[2], Vfloat vk[3], Vfloat rk[2],
                   Vfloat pk[2][3]);
VKI_EXTERN void
vis_curvatureTridv(Vdouble x[][3], Vdouble v[][3], Vdouble r[2], Vdouble vk[3], Vdouble rk[2], Vdouble pk[2][3]);
VKI_EXTERN void
vis_curvatureTrinewdv(Vdouble x[][3], Vdouble v[][3], Vdouble r[2], Vdouble vk[3], Vdouble rk[2], Vdouble pk[2][3]);
VKI_EXTERN void
vis_coordsysTridv(Vint npts, Vdouble x[][3], Vdouble v[][3], Vdouble cl, Vint* type, Vdouble cp[3], Vdouble z[3], Vdouble* rad,
                  Vint* idir, Vdouble* c);
VKI_EXTERN void
vis_normal2DGen(Vint shape, Vint maxi, Vint maxj, Vfloat x[][3], Vfloat r[2], Vfloat v[3]);
VKI_EXTERN void
vis_normal2DGendv(Vint shape, Vint maxi, Vint maxj, Vdouble x[][3], Vdouble r[2], Vdouble v[3]);
VKI_EXTERN void
vis_normalEdge(Vint maxi, Vfloat x[][3], Vfloat v[][3]);
VKI_EXTERN void
vis_normalFace(Vint shape, Vint maxi, Vint maxj, Vfloat x[][3], Vfloat v[][3]);
VKI_EXTERN void
vis_normalFacedv(Vint shape, Vint maxi, Vint maxj, Vdouble x[][3], Vdouble v[][3]);
VKI_EXTERN void
vis_recoverNormal(Vfloat d1[3], Vfloat d2[3], Vdouble vd[3]);
VKI_EXTERN void
vis_recoverNormaldv(Vdouble d1[3], Vdouble d2[3], Vdouble vd[3]);
VKI_EXTERN void
vis_areaFacedv(Vint shape, Vint maxi, Vint maxj, Vdouble x[][3], Vdouble* area);
VKI_EXTERN void
vis_volumePolyheddv(Vint maxi, Vint ix[], Vdouble x[][3], Vdouble* vol);
VKI_EXTERN void
vis_Jacobian3D(Vint npts, Vfloat phr[][3], Vfloat x[][3], Vfloat g[3][3]);
VKI_EXTERN void
vis_Jacobian3Dds(Vint npts, Vdouble phr[][3], Vfloat x[][3], Vdouble g[3][3]);
VKI_EXTERN void
vis_Jacobian3Ddv(Vint npts, Vdouble phr[][3], Vdouble x[][3], Vdouble g[3][3]);
VKI_EXTERN void
vis_Jacobian2Dim(Vint npts, Vfloat phr[][2], Vfloat x[][2], Vfloat g[2][2]);
VKI_EXTERN void
vis_Jacobian2Dimdv(Vint npts, Vdouble phr[][2], Vdouble x[][2], Vdouble g[2][2]);
VKI_EXTERN void
vis_Jacobian2DN(Vint npts, Vfloat phr[][2], Vfloat x[][3], Vfloat g[2][3]);
VKI_EXTERN void
vis_Jacobian2DNds(Vint npts, Vdouble phr[][2], Vfloat x[][3], Vdouble g[2][3]);
VKI_EXTERN void
vis_Jacobian1DN(Vint npts, Vfloat phr[], Vfloat x[][3], Vfloat g[3]);
VKI_EXTERN void
vis_Jacobian1DNds(Vint npts, Vdouble phr[], Vfloat x[][3], Vdouble g[3]);
VKI_EXTERN void
vis_Jacobian2DNdv(Vint npts, Vdouble phr[][2], Vdouble x[][3], Vdouble g[2][3]);
VKI_EXTERN void
vis_Jacobian1DNdv(Vint npts, Vdouble phr[], Vdouble x[][3], Vdouble g[3]);
VKI_EXTERN void
vis_detJacobian3D(Vint isw, Vfloat px[3][3], Vfloat xi[3][3], Vfloat* det);
VKI_EXTERN void
vis_detJacobian3Ddv(Vint isw, Vdouble px[3][3], Vdouble xi[3][3], Vdouble* det);
VKI_EXTERN void
vis_detJacobian2D(Vint isw, Vfloat px[2][2], Vfloat xi[2][2], Vfloat* det);
VKI_EXTERN void
vis_detJacobian2Ddv(Vint isw, Vdouble px[2][2], Vdouble xi[2][2], Vdouble* det);
VKI_EXTERN void
vis_detJacobian2DN(Vint isw, Vfloat px[2][3], Vfloat xi[3][2], Vfloat* det);
VKI_EXTERN void
vis_detJacobian2DNdv(Vint isw, Vdouble px[2][3], Vdouble xi[3][2], Vdouble* det);
VKI_EXTERN void
vis_detJacobian1DN(Vint isw, Vfloat px[3], Vfloat xi[3], Vfloat* det);
VKI_EXTERN void
vis_detJacobian1DNdv(Vint isw, Vdouble px[3], Vdouble xi[3], Vdouble* det);
VKI_EXTERN void
vis_invertNC1DNGen(Vint maxi, Vfloat xe[][3], Vfloat xs[3], Vfloat* r, Vfloat* ri, Vfloat xp[3], Vint* ierr);
VKI_EXTERN void
vis_invertNC1DNGendv(Vint maxi, Vdouble xe[][3], Vdouble xs[3], Vdouble* r, Vdouble* ri, Vdouble xp[3], Vint* ierr);
VKI_EXTERN void
vis_invertNC2DPoly(Vint maxi, Vfloat xe[][3], Vfloat xs[3], Vfloat r[2], Vfloat ri[2], Vfloat xp[3], Vint* ierr);
VKI_EXTERN void
vis_invertNC2DPolydv(Vint maxi, Vdouble xe[][3], Vdouble xs[3], Vdouble r[2], Vdouble ri[2], Vdouble xp[3], Vint* ierr);
VKI_EXTERN void
vis_invertNC2DNGen(Vint shape, Vint maxi, Vint maxj, Vint npts, Vfloat xe[][3], Vfloat xs[3], Vfloat r[2], Vfloat ri[2],
                   Vfloat xp[3], Vint* ierr);
VKI_EXTERN void
vis_invertNC2DNGendv(Vint shape, Vint maxi, Vint maxj, Vint npts, Vdouble xe[][3], Vdouble xs[3], Vdouble r[2], Vdouble ri[2],
                     Vdouble xp[3], Vint* ierr);
VKI_EXTERN void
vis_invertNC3DPoly(Vint ix[], Vint maxi, Vfloat xe[][3], Vfloat xs[3], Vfloat r[3], Vfloat ri[3], Vint* ierr);
VKI_EXTERN void
vis_invertNC3DPolydv(Vint ix[], Vint maxi, Vdouble xe[][3], Vdouble xs[3], Vdouble r[3], Vdouble ri[3], Vint* ierr);
VKI_EXTERN void
vis_invertNC3DGen(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vint npts, Vfloat xe[][3], Vfloat xs[3], Vfloat r[3], Vfloat ri[3],
                  Vint* ierr);
VKI_EXTERN void
vis_invertNC3DGendv(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vint npts, Vdouble xe[][3], Vdouble xs[3], Vdouble r[3],
                    Vdouble ri[3], Vint* ierr);
VKI_EXTERN void
vis_intersectLinePerpdv(Vdouble line[2][3], Vdouble pnt[3], Vdouble* rloc, Vdouble intpt[3]);
VKI_EXTERN void
vis_intersectLineVectdv(Vdouble line[2][3], Vdouble pnt[3], Vdouble vec[3], Vdouble* rloc, Vdouble intpt[3], Vint* code);
VKI_EXTERN void
vis_intersectLineLine(Vint maxi, Vfloat x[][3], Vint lmaxi, Vfloat xl[][3], Vfloat* r, Vfloat* ri, Vfloat* rl, Vfloat* rli,
                      Vfloat xp[3], Vfloat xpl[3], Vint* ierr);
VKI_EXTERN void
vis_intersectLineLinedv(Vint maxi, Vdouble x[][3], Vint lmaxi, Vdouble xl[][3], Vdouble* r, Vdouble* ri, Vdouble* rl,
                        Vdouble* rli, Vdouble xp[3], Vdouble xpl[3], Vint* ierr);
VKI_EXTERN void
vis_intersectLineFace(Vint shape, Vint maxi, Vint maxj, Vint npts, Vfloat x[][3], Vint lmaxi, Vfloat xl[][3], Vfloat r[2],
                      Vfloat ri[2], Vfloat* rl, Vfloat* rli, Vfloat xp[3], Vfloat xpl[3], Vint* ierr);
VKI_EXTERN void
vis_intersectLineFacedv(Vint shape, Vint maxi, Vint maxj, Vint npts, Vdouble x[][3], Vint lmaxi, Vdouble xl[][3], Vdouble r[2],
                        Vdouble ri[2], Vdouble* rl, Vdouble* rli, Vdouble xp[3], Vdouble xpl[3], Vint* ierr);
VKI_EXTERN void
vis_system0DSetdv(Vint npre, Vint type, void* v, Vdouble angle, Vint* ltyp, Vdouble lvec[], Vdouble* lang, Vint* ierr);
VKI_EXTERN void
vis_system0DGendv(Vint type, Vdouble orientationVectors[], Vdouble angle, Vdouble x[3], Vdouble tm[3][3]);
VKI_EXTERN void
vis_system1DSetdv(Vint maxi, Vint npre, Vint type, void* v, Vdouble angle, Vint* ltyp, Vdouble lvec[], Vdouble* lang, Vint* ierr);
VKI_EXTERN void
vis_system1DGendv(Vint maxi, Vint type, Vdouble orientationVectors[], Vdouble angle, Vdouble x[][3], Vdouble r, Vdouble tm[3][3]);
VKI_EXTERN void
vis_system2DSetdv(Vint shape, Vint maxi, Vint maxj, Vint npre, Vint type, void* v, Vdouble angle, Vint* ltyp, Vdouble lvec[],
                  Vdouble* lang, Vint* ierr);
VKI_EXTERN void
vis_system2DGendv(Vint shape, Vint maxi, Vint maxj, Vint type, Vdouble orientationVectors[], Vdouble angle, Vdouble x[][3],
                  Vdouble r[2], Vdouble tm[3][3]);
VKI_EXTERN void
vis_system3DSetdv(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vint npre, Vint type, void* v, Vdouble angle, Vint* ltyp,
                  Vdouble lvec[], Vdouble* lang, Vint* ierr);
VKI_EXTERN void
vis_system3DGendv(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vint type, Vdouble orientationVectors[], Vdouble angle,
                  Vdouble x[][3], Vdouble r[3], Vdouble tm[3][3]);
VKI_EXTERN void
vis_intptsTridv(Vint intpt, Vint numpts, Vdouble r[2], Vdouble w[2]);
VKI_EXTERN void
vis_intptsTetdv(Vint intpt, Vint numpts, Vdouble r[3], Vdouble w[3]);
VKI_EXTERN void
vis_intptsPyrdv(Vint intpt, Vint numpts, Vdouble r[3], Vdouble w[3]);
VKI_EXTERN void
vis_intpts1Ddv(Vint rule, Vint intpt, Vint numpts, Vdouble* r, Vdouble* w);
VKI_EXTERN void
vis_intpts2Ddv(Vint rule, Vint shape, Vint intpt, Vint numpts, Vdouble r[2], Vdouble w[2]);
VKI_EXTERN void
vis_intpts3Ddv(Vint shape, Vint intpt, Vint numpts, Vdouble r[3], Vdouble w[3]);
VKI_EXTERN void
vis_numpts2D(Vint rule, Vint norder, Vint shape, Vint* numpts);
VKI_EXTERN void
vis_numpts3D(Vint norder, Vint shape, Vint* numpts);
VKI_EXTERN void
vis_numpts3DPolyhed(Vint ix[], Vint nix, Vint* numpts);
VKI_EXTERN void
vis_intpts3DPolyheddv(Vint intpt, Vdouble r[3], Vdouble w[3]);
VKI_EXTERN void
vis_circumCircle2Dim(Vdouble x[3][2], Vdouble xc[2], Vdouble* rad);
VKI_EXTERN void
vis_circumCircle(Vdouble x[3][3], Vdouble xc[3], Vdouble* rad);
VKI_EXTERN void
vis_circumSphere(Vdouble x[4][3], Vdouble xc[3], Vdouble* rad);
VKI_EXTERN void
vis_inSphere(Vdouble x[4][3], Vdouble xp[3], Vint* insphere);
VKI_EXTERN void
vis_minAngle(Vdouble x[3][3], Vint* kmn, Vdouble* ang);
VKI_EXTERN void
vis_maxAngle(Vdouble x[3][3], Vint* kmx, Vdouble* ang);
VKI_EXTERN void
vis_minmaxAngleXYPlane(Vdouble x[3][3], Vint* kmn, Vdouble* angn, Vint* kmx, Vdouble* angx);
VKI_EXTERN void
vis_allAngle(Vdouble x[3][3], Vint* kmin, Vint* kmax, Vdouble d[3][3], Vdouble sl[3], Vdouble ang[3]);
VKI_EXTERN void
vis_dropPerpendicular(Vdouble x[3][3], Vint kmax, Vdouble* w, Vdouble xp[3]);
VKI_EXTERN void
vis_transCtrl(Vdouble s[3][3], Vint npts, Vdouble x[][3]);
VKI_EXTERN void
vis_curvature1DG(Vfloat pxr[3], Vfloat pxrr[3], Vfloat vk[3], Vfloat* rk, Vint* ierr);
VKI_EXTERN void
vis_curvature2DG(Vfloat pxr[2][3], Vfloat pxrr[3][3], Vfloat vk[3], Vfloat rk[3], Vint* ierr);
VKI_EXTERN void
vis_lineBezier(Vint isw, Vint maxi, Vfloat r, Vfloat x[][3], Vfloat xr[3], Vfloat pxr[3], Vfloat pxrr[3]);
VKI_EXTERN void
vis_quadBezier(Vint isw, Vint maxi, Vint maxj, Vfloat r[2], Vfloat x[][3], Vfloat xr[3], Vfloat pxr[2][3], Vfloat pxrr[3][3]);
VKI_EXTERN void
vis_triBezier(Vint isw, Vint maxi, Vfloat r[2], Vfloat x[][3], Vfloat xr[3], Vfloat pxr[2][3], Vfloat pxrr[2][3]);
VKI_EXTERN void
vis_solveSpline(Vint maxi, Vfloat xe[][3], Vint vcflag, Vfloat vc[2][3], Vfloat sx[], Vfloat sy[], Vfloat sz[], Vfloat u[]);
VKI_EXTERN void
vis_lineSpline(Vint isw, Vint maxi, Vfloat r, Vfloat sx[], Vfloat sy[], Vfloat sz[], Vfloat u[], Vfloat xe[][3], Vfloat x[3],
               Vfloat pxr[3], Vfloat pxrr[3]);
VKI_EXTERN void
vis_coefNURBS(Vint isw, Vint maxi, Vint nrdi, Vfloat r, Vfloat u[], Vint* mbrk, Vfloat h[], Vfloat phr[], Vfloat phrr[]);
VKI_EXTERN void
vis_lineNURBS(Vint isw, Vint maxi, Vint nrdi, Vfloat r, Vfloat u[], Vfloat x[][3], Vfloat w[], Vfloat xr[3], Vfloat pxr[3],
              Vfloat pxrr[3]);
VKI_EXTERN void
vis_quadNURBS(Vint isw, Vint maxi, Vint maxj, Vint nrdi, Vint nrdj, Vfloat r[2], Vfloat u[], Vfloat v[], Vfloat x[][3],
              Vfloat w[], Vfloat xr[3], Vfloat pxr[2][3], Vfloat pxrr[3][3]);
VKI_EXTERN void
vis_lineLagrange(Vint isw, Vint maxi, Vfloat r, Vfloat x[][3], Vfloat xr[3], Vfloat pxr[3], Vfloat pxrr[3]);
VKI_EXTERN void
vis_quadLagrange(Vint isw, Vint maxi, Vint maxj, Vfloat r[2], Vfloat x[][3], Vfloat xr[3], Vfloat pxr[2][3], Vfloat pxrr[3][3]);
VKI_EXTERN void
vis_lineHermitedv(Vint isw, Vdouble r, Vdouble x[][3], Vdouble t[][3], Vdouble xr[3], Vdouble pxr[3], Vdouble pxrr[3]);
VKI_EXTERN void
vis_formatF(Vdouble d, Vint nc, Vint cf, Vchar dstg[], Vint* ierr);
VKI_EXTERN void
vis_formatE(Vdouble d, Vint nc, Vint ne, Vint ce, Vint cf, Vchar dstg[]);
VKI_EXTERN void
vis_formatG(Vdouble d, Vint nc, Vint ce, Vint cf, Vchar dstg[]);
VKI_EXTERN void
vis_edge2DGenPar(Vint shape, Vint maxi, Vint maxj, Vint no, Vdouble r, Vdouble rs[2]);
VKI_EXTERN void
vis_tetangDihedral(Vdouble x[4][3], Vint iop, Vdouble ang[6], Vint* kmin, Vdouble* angmin);
VKI_EXTERN void
vis_tetedgeAlt(Vdouble x[4][3], Vint iop, Vint* kmax, Vdouble* edgealt);
VKI_EXTERN void
vis_triedgeAlt(Vdouble x[3][3], Vint iop, Vint* kmax, Vdouble* edgealt);
VKI_EXTERN void
vis_quadWarp(Vdouble x[4][3], Vdouble* warp1, Vdouble* warp2, Vdouble* wmax);
VKI_EXTERN void
vis_skewFace(Vint shape, Vdouble x[][3], Vdouble* skew);
VKI_EXTERN void
vis_resName(Vint type, Vchar stg[]);
VKI_EXTERN void
vis_resContents(Vint type, Vchar stg[]);
VKI_EXTERN void
vis_resAbbr(Vint type, Vint nabb, Vchar stg[]);
VKI_EXTERN void
vis_resDTyp(Vint type, Vint* dtyp);
VKI_EXTERN void
vis_resNCmp(Vint type, Vint* ncmp);
VKI_EXTERN void
vis_resDime(Vint type, Vchar stg[]);
VKI_EXTERN void
vis_qualName(Vint type, Vchar stg[]);
VKI_EXTERN void
vis_qualContents(Vint type, Vchar stg[]);
VKI_EXTERN void
vis_qualVal(Vint type, Vchar name[], Vint* dtype);
VKI_EXTERN void
vis_dataName(Vint datatype, Vchar name[]);
VKI_EXTERN void
vis_dataLabel(Vint datatype, Vint icmp, Vchar stg[]);
VKI_EXTERN void
vis_parseDatasetName(Vchar dsname[], Vchar root[], Vint* hist, Vint* type, Vint* nqua, Vint iqua[], Vchar cqua[], Vint* cplx,
                     Vint* sect, Vchar caux[], Vint* enttype, Vint* subtype, Vint* id1, Vint* id2, Vint* id3);
VKI_EXTERN void
vis_parseDatasetIds(Vchar dsname[], Vint* id1, Vint* id2, Vint* id3);
VKI_EXTERN void
vis_createDatasetName(Vint hist, Vint type, Vint nqua, Vint iqua[], const Vchar* cqua, Vint cplx, Vint enttype, Vint subtype,
                      Vint id1, Vint id2, Vint id3, Vchar dname[]);
VKI_EXTERN void
vis_createContents(Vint type, Vint nqua, Vint iqua[], const Vchar* cqua, Vchar contents[]);
VKI_EXTERN void
vis_equiEdgedv(Vint shape, Vdouble vol, Vdouble* h);
VKI_EXTERN void
vis_orderFace3(Vint npe, Vint ifx[], Vint nfx[3]);
VKI_EXTERN void
vis_exitTridv(Vdouble r[3], Vint* ki, Vint* ke, Vint* kn);
VKI_EXTERN void
vis_computePlaneEqQuad(Vdouble plane_eq[4], Vdouble size, Vdouble pts[4][3]);
VKI_EXTERN void
vis_clipTriangle(Vfloat xmin, Vfloat xmax, Vfloat ymin, Vfloat ymax, Vfloat zmin, Vfloat zmax, Vfloat xa[3], Vfloat xb[3],
                 Vfloat xc[3], Vint* nr, Vfloat r[][2], Vint* iclp, Vint* ivis);
VKI_EXTERN void
vis_clipPlane(Vfloat xmin, Vfloat xmax, Vint nb, Vfloat x[], Vfloat b[][2], Vint* nr, Vfloat r[][2], Vint* iclp, Vint* ivis);
VKI_EXTERN void
vis_clipLine(Vfloat xmin, Vfloat xmax, Vfloat ymin, Vfloat ymax, Vfloat zmin, Vfloat zmax, Vfloat xa[3], Vfloat xb[3], Vfloat* te,
             Vfloat* tl, Vint* iclp, Vint* ivis);
VKI_EXTERN Vint
vis_clipt(Vfloat den, Vfloat num, Vfloat* te, Vfloat* tl, Vint* iclp);

#ifdef __cplusplus
}
#endif

#endif
