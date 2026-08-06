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
/* VisTools utility functions header file */

#ifndef VISUTIL_DEF
#define VISUTIL_DEF

#include "sam/base/basedefs.h"
#include "sam/vis/coordsys.h"

#ifdef __cplusplus
extern "C" {
#endif

VKI_EXTERN void
vis_computeNormdv(Vint npts, Vdouble x[][3], Vdouble vd[3]);
VKI_EXTERN void
vis_reallocVdouble(Vint nument, Vint nrows, Vint* maxent, Vdouble** pntent, Vint* ierr);
VKI_EXTERN void
vis_reallocVfloat(Vint nument, Vint nrows, Vint* maxent, Vfloat** pntent, Vint* ierr);
VKI_EXTERN void
vis_reallocVint(Vint nument, Vint* maxent, Vint** pntent, Vint* ierr);
VKI_EXTERN void
vis_reallocVlong(Vint nument, Vint* maxent, Vlong** pntent, Vint* ierr);
VKI_EXTERN void
vis_reallocVshort(Vint nument, Vint* maxent, Vshort** pntent, Vint* ierr);
VKI_EXTERN void
vis_reallocVchar(Vint nument, Vint* maxent, Vchar** pntent, Vint* ierr);
VKI_EXTERN void
vis_reallocBits(Vint nument, Vint* maxent, Vuchar** pntent, Vint* ierr);
VKI_EXTERN void
vis_labelFormatString(Vint format, Vfloat s, Vchar* cstg);
VKI_EXTERN void
vis_valueFormatString(Vint format, Vfloat s, Vchar* cstg);
VKI_EXTERN void
vis_valueBracketBackground(Vint nrows, Vint ncols, Vint dcx, Vint dcy, Vint dcbl[4][3], Vint dcbr[4][3], Vint dcb[4][3]);
VKI_EXTERN void
vis_offsetText(Vchar* string, Vint textbox[2], Vint position, Vint dc[3]);
VKI_EXTERN void
vis_unitNormal(Vfloat v[3]);
VKI_EXTERN void
vis_averageCoord(Vint npts, Vfloat x[][3], Vfloat xc[3]);
VKI_EXTERN void
vis_averageData(Vint npts, Vint nrws, Vfloat d[], Vfloat dc[]);
VKI_EXTERN void
vis_averageDatadv(Vint npts, Vint nrws, Vdouble d[], Vdouble dc[]);
VKI_EXTERN void
vis_centroidData(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vint npts, Vint nrws, Vfloat d[], Vfloat dc[]);
VKI_EXTERN void
vis_centroidDatadv(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vint npts, Vint nrws, Vdouble d[], Vdouble dc[]);
VKI_EXTERN void
vis_minimumData(Vint absfl, Vint npts, Vint nrws, Vfloat d[], Vfloat dc[]);
VKI_EXTERN void
vis_minimumDatadv(Vint absfl, Vint npts, Vint nrws, Vdouble d[], Vdouble dc[]);
VKI_EXTERN void
vis_maximumData(Vint absfl, Vint npts, Vint nrws, Vfloat d[], Vfloat dc[]);
VKI_EXTERN void
vis_maximumDatadv(Vint absfl, Vint npts, Vint nrws, Vdouble d[], Vdouble dc[]);
VKI_EXTERN void
vis_constantDatadv(Vint npts, Vint nrws, Vdouble d[], Vint* constflag);
VKI_EXTERN void
vis_shrinkCoord(Vint npts, Vfloat x[][3], Vfloat xc[3], Vfloat s);
VKI_EXTERN void
vis_computeArea(Vint npts, Vfloat x[][3], Vfloat* area);
VKI_EXTERN void
vis_computeAreadv(Vint npts, Vdouble x[][3], Vdouble* area);
VKI_EXTERN void
vis_computeArea2Dimdv(Vint npts, Vdouble x[][2], Vdouble* area);
VKI_EXTERN void
vis_computeVolume(Vint npts, Vfloat x[][3], Vfloat* volume);
VKI_EXTERN void
vis_computeVolumedv(Vint npts, Vdouble x[][3], Vdouble* volume);
VKI_EXTERN void
vis_edgelenFace(Vint shape, Vdouble x[][3], Vdouble* lenmin, Vdouble* lenmax);
VKI_EXTERN void
vis_computeMetricTriangle(Vdouble vn[3], Vdouble x[][3], Vdouble* metric);
VKI_EXTERN void
vis_computeMetricQuad(Vdouble vn[3], Vdouble x[][3], Vdouble* metric);
VKI_EXTERN void
vis_computeMetric(Vint shape, Vdouble vn[3], Vdouble x[][3], Vdouble* metric);
VKI_EXTERN void
vis_computeAngle(Vint shape, Vdouble vn[3], Vdouble x[][3], Vdouble eln[], Vdouble ang[], Vint* kmax, Vdouble* angmax);
VKI_EXTERN void
vis_computeAngleA(Vint shape, Vdouble vn[3], Vdouble x[][3], Vdouble ang[], Vint* kmax, Vdouble* angmax);
VKI_EXTERN void
vis_computeAngleNorm(Vdouble vn[3], Vdouble x[3][3], Vdouble* ang);
VKI_EXTERN void
vis_closeObtuse(Vdouble x[3][3], Vint* kmax, Vdouble* clmax, Vint* iobtuse, Vint* iclose);
VKI_EXTERN void
vis_baseHeight(Vdouble x[3][3], Vdouble* b, Vdouble* h);
VKI_EXTERN void
vis_swapNorm(Vdouble x[4][3], Vdouble vno[2][3], Vint iso[4], Vdouble vns[2][3], Vint iss[4]);
VKI_EXTERN void
vis_swapImprove(Vdouble x[4][3], Vdouble* ango, Vdouble* angs, Vint* flag);
VKI_EXTERN void
vis_swapImproveXYPlane(Vdouble x[4][3], Vdouble* ango, Vdouble* angs, Vint* flag);
VKI_EXTERN void
vis_tangentEdge(Vint maxi, Vfloat x[][3], Vfloat v[][3]);
VKI_EXTERN void
vis_tangentEdgedv(Vint maxi, Vdouble x[][3], Vdouble v[][3]);
VKI_EXTERN void
vis_tangentEdgeNC(Vint maxi, Vfloat x[][3], Vfloat r, Vfloat v[3]);
VKI_EXTERN void
vis_tangent1D(Vint maxi, Vfloat x[][3], Vfloat r, Vfloat t[3]);
VKI_EXTERN void
vis_normalFaceNC(Vint shape, Vint maxi, Vint maxj, Vfloat x[][3], Vfloat r[2], Vfloat v[3]);
VKI_EXTERN void
vis_normalFacet(Vint npts, Vfloat x[][3], Vint vflag, Vfloat v[][3], Vfloat vn[3]);
VKI_EXTERN void
vis_normalFacetdv(Vint npts, Vdouble x[][3], Vint vflag, Vdouble v[][3], Vdouble vn[3]);
VKI_EXTERN void
vis_normalTriPardv(Vdouble xe[6][3], Vdouble ve[6][3]);
VKI_EXTERN void
vis_coordElemNC(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vfloat x[][3], Vfloat r[3], Vfloat xr[3]);
VKI_EXTERN void
vis_centerFace(Vint shape, Vint maxi, Vint maxj, Vfloat x[][3], Vint vflag, Vfloat v[][3], Vfloat xc[3], Vint flag, Vfloat vc[3]);
VKI_EXTERN void
vis_normgrad3D(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vfloat s[], Vfloat x[][3], Vint nflag, Vfloat v[][3]);
VKI_EXTERN void
vis_normgrad2DN(Vint shape, Vint maxi, Vint maxj, Vfloat s[], Vfloat x[][3], Vint nflag, Vfloat v[][3]);
VKI_EXTERN void
vis_normgrad1DN(Vint maxi, Vfloat s[], Vfloat x[][3], Vint nflag, Vfloat v[][3]);
VKI_EXTERN void
vis_coord1D(Vint maxi, Vfloat x[][3], Vfloat r, Vfloat xp[3]);
VKI_EXTERN void
vis_coord2D(Vint shape, Vint maxi, Vint maxj, Vfloat x[][3], Vfloat r[2], Vfloat xp[3]);
VKI_EXTERN void
vis_getTriIx(Vint maxi, Vint i, Vint j, Vint* ntri, Vint ii[2][3]);
VKI_EXTERN void
vis_getQuadIx(Vint maxi, Vint i, Vint j, Vint ii[4]);
VKI_EXTERN void
vis_getHexIx(Vint maxi, Vint maxj, Vint i, Vint j, Vint k, Vint ii[8]);
VKI_EXTERN void
vis_utilGetHexJx(Vint maxi, Vint maxj, Vint ii[8]);
VKI_EXTERN void
vis_utilGetWedJx(Vint maxi, Vint i, Vint j, Vint* nwed, Vint ii[2][6]);
VKI_EXTERN void
vis_utilGetPyrJx(Vint maxi, Vint i, Vint j, Vint k, Vint* nvol, Vint nii[4], Vint ii[4][5]);
VKI_EXTERN void
vis_utilGetTetJx(Vint maxi, Vint i, Vint j, Vint k, Vint* nvol, Vint ii[6][4]);
VKI_EXTERN void
vis_refineLine(Vint refine, Vint maxi, Vint nrws, Vfloat x[], Vfloat xr[]);
VKI_EXTERN void
vis_refineQuad(Vint refine, Vint maxi, Vint maxj, Vint nrws, Vfloat x[], Vfloat xr[]);
VKI_EXTERN void
vis_utilHFunQuad(Vint refine, Vint maxi, Vint maxj, Vint indi, Vint indj, Vfloat h[]);
VKI_EXTERN void
vis_refineTri(Vint refine, Vint maxi, Vint nrws, Vfloat x[], Vfloat xr[]);
VKI_EXTERN void
vis_utilHFunTri(Vint refine, Vint maxi, Vint indi, Vint indj, Vfloat h[]);
VKI_EXTERN void
vis_refineHex(Vint refine, Vint maxi, Vint maxj, Vint maxk, Vint nrws, Vfloat x[], Vfloat xr[]);
VKI_EXTERN void
vis_utilHFunHex(Vint refine, Vint maxi, Vint maxj, Vint maxk, Vint indi, Vint indj, Vint indk, Vfloat h[]);
VKI_EXTERN void
vis_refineWed(Vint refine, Vint maxi, Vint maxk, Vint nrws, Vfloat x[], Vfloat xr[]);
VKI_EXTERN void
vis_utilHFunWed(Vint refine, Vint maxi, Vint maxk, Vint indi, Vint indj, Vint indk, Vfloat h[]);
VKI_EXTERN void
vis_refineTet(Vint refine, Vint maxi, Vint nrws, Vfloat x[], Vfloat xr[]);
VKI_EXTERN void
vis_refine2D(Vint refine, Vint shape, Vint maxi, Vint maxj, Vint nrws, Vfloat x[], Vfloat xr[]);
VKI_EXTERN void
vis_refine3D(Vint refine, Vint shape, Vint maxi, Vint maxj, Vint maxk, Vint nrws, Vfloat x[], Vfloat xr[]);
VKI_EXTERN void
vis_interpolate3(Vint npts, Vfloat h[], Vfloat s[][3], Vfloat sout[3]);
VKI_EXTERN void
vis_interpolateN(Vint npts, Vfloat h[], Vint n, Vfloat s[], Vfloat sout[]);
VKI_EXTERN void
vis_coordArr2Lag(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vfloat xe[][3], Vfloat xl[][3]);
VKI_EXTERN void
vis_shapeLinArr(Vint isw, Vint maxi, Vfloat r, Vfloat h[], Vfloat phr[], Vint* njx, Vint jx[]);
VKI_EXTERN void
vis_shape2DArr(Vint isw, Vint shape, Vint maxi, Vint maxj, Vfloat r[2], Vfloat h[], Vfloat phr[][2], Vint* njx, Vint jx[]);
VKI_EXTERN void
vis_shape3DArr(Vint isw, Vint shape, Vint maxi, Vint maxj, Vint maxk, Vfloat r[3], Vfloat h[], Vfloat phr[][3], Vint* njx,
               Vint jx[]);
VKI_EXTERN void
vis_shape3DArrdv(Vint isw, Vint shape, Vint maxi, Vint maxj, Vint maxk, Vdouble r[3], Vdouble h[], Vdouble phr[][3], Vint* njx,
                 Vint jx[]);
VKI_EXTERN void
vis_arclen1DNGendv(Vint maxi, Vdouble x[][3], Vdouble r, Vdouble* s);
VKI_EXTERN void
vis_midpnt1DNGendv(Vint maxi, Vdouble x[][3], Vdouble xm[3]);
VKI_EXTERN void
vis_div1DNNormdv(Vdouble xl[2][3], Vdouble vl[2][3], Vint iop, Vint ndiv, Vdouble x[][3], Vdouble v[][3]);
VKI_EXTERN void
vis_div1DNTangdv(Vdouble xl[2][3], Vdouble tl[2][3], Vint iop, Vint ndiv, Vdouble x[][3], Vdouble v[][3]);
VKI_EXTERN void
vis_invertNC3D(Vint npts, Vfloat xe[][3], Vfloat xs[3], Vfloat r[3], Vfloat ri[3], Vint* nv, Vfloat v[][3], Vint* ierr);
VKI_EXTERN void
vis_invertNC2Dim(Vint npts, Vfloat xe[][2], Vfloat xs[2], Vfloat r[2], Vfloat ri[2], Vint* nv, Vfloat v[][2], Vint* ierr);
VKI_EXTERN void
vis_invertNCLindv(Vdouble xe[][3], Vdouble xs[3], Vdouble* r, Vdouble x[3], Vint* ierr);
VKI_EXTERN void
vis_invertNCLinPardv(Vdouble xe[][3], Vdouble xs[3], Vdouble* r, Vdouble x[3], Vint* ierr);
VKI_EXTERN void
vis_invertNCTri2Dimdv(Vdouble xe[][2], Vdouble xs[2], Vdouble r[2], Vint* ierr);
VKI_EXTERN void
vis_invertNCTridv(Vdouble xe[][3], Vdouble xs[3], Vdouble r[2], Vdouble x[3], Vint* ierr);
VKI_EXTERN void
vis_invertNCTriPardv(Vdouble xe[][3], Vdouble xs[3], Vdouble r[2], Vdouble x[3], Vint* ierr);
VKI_EXTERN void
vis_invertNCQuaddv(Vdouble xe[][3], Vdouble xs[3], Vdouble r[2], Vdouble x[3], Vint* ierr);
VKI_EXTERN void
vis_invertNCTetdv(Vdouble xe[][3], Vdouble xs[3], Vdouble r[3], Vint* ierr);
VKI_EXTERN void
vis_invertNC1DArr(Vint maxi, Vfloat xe[], Vfloat xs, Vfloat* r, Vfloat* ri, Vint* ierr);
VKI_EXTERN void
vis_invertNC1DNArr(Vint maxi, Vfloat xe[][3], Vfloat xs[3], Vfloat* r, Vfloat* ri, Vint* ierr);
VKI_EXTERN void
vis_invertNC2DNArr(Vint shape, Vint maxi, Vint maxj, Vfloat xe[][3], Vfloat xs[3], Vfloat r[2], Vfloat ri[2], Vint* ierr);
VKI_EXTERN void
vis_invertNC3DArr(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vfloat xe[][3], Vfloat xs[3], Vfloat r[3], Vfloat ri[3],
                  Vint* ierr);
VKI_EXTERN void
vis_inter3DArrPoint(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vfloat x[][3], Vfloat xp[3], Vfloat dtol, Vfloat r[3],
                    Vfloat xi[3], Vfloat xd[3], Vint* status);
VKI_EXTERN void
vis_inter2DNArrPoint(Vint shape, Vint maxi, Vint maxj, Vfloat x[][3], Vfloat xp[3], Vfloat dtol, Vfloat r[2], Vfloat xi[3],
                     Vfloat xd[3], Vint* status);
VKI_EXTERN void
vis_inter1DNArrPoint(Vint maxi, Vfloat x[][3], Vfloat xp[3], Vfloat dtol, Vfloat* r, Vfloat xi[3], Vfloat xd[3], Vint* status);
VKI_EXTERN void
vis_inter0DNArrPoint(Vint maxi, Vfloat x[][3], Vfloat xp[3], Vfloat dtol, Vint* ipt, Vfloat xi[3], Vfloat xd[3], Vint* status);
VKI_EXTERN void
vis_inter2DNArrLine(Vint shape, Vint maxi, Vint maxj, Vfloat x[][3], Vfloat xl[2][3], Vfloat dtol, Vfloat r[2], Vfloat xi[3],
                    Vfloat xd[3], Vint* status);
VKI_EXTERN void
vis_inter1DNArrLine(Vint maxi, Vfloat x[][3], Vfloat xl[2][3], Vfloat dtol, Vfloat* r, Vfloat xi[3], Vfloat xd[3], Vint* status);
VKI_EXTERN void
vis_inter0DNArrLine(Vint maxi, Vfloat x[][3], Vfloat xl[2][3], Vfloat dtol, Vint* ipt, Vfloat xi[3], Vfloat xd[3], Vint* status);
VKI_EXTERN void
vis_cellLinArr(Vint maxi, Vfloat r, Vint* ic, Vfloat* rc, Vint* njx, Vint jx[]);
VKI_EXTERN void
vis_cellTriArr(Vint maxi, Vfloat r[2], Vint* ic, Vint* jc, Vint* nc);
VKI_EXTERN void
vis_cellQuadArr(Vint maxi, Vint maxj, Vfloat r[2], Vint* ic, Vint* jc);
VKI_EXTERN void
vis_cellTetArr(Vint maxi, Vfloat r[3], Vint* ic, Vint* jc, Vint* kc, Vint* nc);
VKI_EXTERN void
vis_cellTetArrdv(Vint maxi, Vdouble r[3], Vint* ic, Vint* jc, Vint* kc, Vint* nc);
VKI_EXTERN void
vis_cellWedArr(Vint maxi, Vint maxk, Vfloat r[3], Vint* ic, Vint* jc, Vint* kc, Vint* nc);
VKI_EXTERN void
vis_cellWedArrdv(Vint maxi, Vint maxk, Vdouble r[3], Vint* ic, Vint* jc, Vint* kc, Vint* nc);
VKI_EXTERN void
vis_cellHexArr(Vint maxi, Vint maxj, Vint maxk, Vfloat r[3], Vint* ic, Vint* jc, Vint* kc);
VKI_EXTERN void
vis_cellHexArrdv(Vint maxi, Vint maxj, Vint maxk, Vdouble r[3], Vint* ic, Vint* jc, Vint* kc);
VKI_EXTERN void
vis_cell2DArr(Vint shape, Vint maxi, Vint maxj, Vfloat r[2], Vint* ic, Vint* jc, Vint* nc);
VKI_EXTERN void
vis_cell3DArr(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vfloat r[3], Vint* ic, Vint* jc, Vint* kc, Vint* nc);
VKI_EXTERN void
vis_adjTriArr(Vint ic, Vint jc, Vint nc, Vint iedge, Vint* ia, Vint* ja, Vint* na);
VKI_EXTERN void
vis_adjQuadArr(Vint ic, Vint jc, Vint iedge, Vint* ia, Vint* ja);
VKI_EXTERN void
vis_adjTetArr(Vint ic, Vint jc, Vint kc, Vint nc, Vint iface, Vint* ia, Vint* ja, Vint* ka, Vint* na);
VKI_EXTERN void
vis_adjWedArr(Vint ic, Vint jc, Vint kc, Vint nc, Vint iface, Vint* ia, Vint* ja, Vint* ka, Vint* na);
VKI_EXTERN void
vis_adjHexArr(Vint ic, Vint jc, Vint kc, Vint iface, Vint* ia, Vint* ja, Vint* ka);
VKI_EXTERN void
vis_adj2DArr(Vint shape, Vint ic, Vint jc, Vint nc, Vint iedge, Vint* ia, Vint* ja, Vint* na);
VKI_EXTERN void
vis_adj3DArr(Vint shape, Vint ic, Vint jc, Vint kc, Vint nc, Vint iface, Vint* ia, Vint* ja, Vint* ka, Vint* na);
VKI_EXTERN void
vis_conTriArr(Vint maxi, Vint ic, Vint jc, Vint nc, Vint* njx, Vint jx[]);
VKI_EXTERN void
vis_conmTriArr(Vint maxi, Vint ic, Vint jc, Vint* nt, Vint* njx, Vint jx[][3]);
VKI_EXTERN void
vis_connTriArr(Vint maxi, Vint ic, Vint jc, Vint* njx, Vint jx[]);
VKI_EXTERN void
vis_conQuadArr(Vint maxi, Vint maxj, Vint ic, Vint jc, Vint* njx, Vint jx[]);
VKI_EXTERN void
vis_conTetArr(Vint maxi, Vint ic, Vint jc, Vint kc, Vint nc, Vint* njx, Vint jx[]);
VKI_EXTERN void
vis_conWedArr(Vint maxi, Vint maxk, Vint ic, Vint jc, Vint kc, Vint nc, Vint* njx, Vint jx[]);
VKI_EXTERN void
vis_conHexArr(Vint maxi, Vint maxj, Vint maxk, Vint ic, Vint jc, Vint kc, Vint* njx, Vint jx[]);
VKI_EXTERN void
vis_con2DArr(Vint shape, Vint maxi, Vint maxj, Vint ic, Vint jc, Vint nc, Vint* njx, Vint jx[]);
VKI_EXTERN void
vis_con3DArr(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vint ic, Vint jc, Vint kc, Vint nc, Vint* njx, Vint jx[]);
VKI_EXTERN void
vis_tranLinArr(Vint iop, Vint maxi, Vint ic, Vfloat* rc, Vfloat* r);
VKI_EXTERN void
vis_tranTriArr(Vint iop, Vint maxi, Vint ic, Vint jc, Vint nc, Vfloat rc[2], Vfloat r[2]);
VKI_EXTERN void
vis_tranQuadArr(Vint iop, Vint maxi, Vint maxj, Vint ic, Vint jc, Vfloat rc[2], Vfloat r[2]);
VKI_EXTERN void
vis_tranTetArr(Vint iop, Vint maxi, Vint ic, Vint jc, Vint kc, Vint nc, Vfloat rc[3], Vfloat r[3]);
VKI_EXTERN void
vis_tranTetArrdv(Vint iop, Vint maxi, Vint ic, Vint jc, Vint kc, Vint nc, Vdouble rc[3], Vdouble r[3]);
VKI_EXTERN void
vis_tranWedArr(Vint iop, Vint maxi, Vint maxk, Vint ic, Vint jc, Vint kc, Vint nc, Vfloat rc[3], Vfloat r[3]);
VKI_EXTERN void
vis_tranWedArrdv(Vint iop, Vint maxi, Vint maxk, Vint ic, Vint jc, Vint kc, Vint nc, Vdouble rc[3], Vdouble r[3]);
VKI_EXTERN void
vis_tranHexArr(Vint iop, Vint maxi, Vint maxj, Vint maxk, Vint ic, Vint jc, Vint kc, Vfloat rc[3], Vfloat r[3]);
VKI_EXTERN void
vis_tranHexArrdv(Vint iop, Vint maxi, Vint maxj, Vint maxk, Vint ic, Vint jc, Vint kc, Vdouble rc[3], Vdouble r[3]);
VKI_EXTERN void
vis_tran2DArr(Vint iop, Vint shape, Vint maxi, Vint maxj, Vint ic, Vint jc, Vint nc, Vfloat rc[2], Vfloat r[2]);
VKI_EXTERN void
vis_tran3DArr(Vint iop, Vint shape, Vint maxi, Vint maxj, Vint maxk, Vint ic, Vint jc, Vint kc, Vint nc, Vfloat rc[3],
              Vfloat r[3]);
VKI_EXTERN void
vis_GVector3DGen(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vfloat xe[][3], Vfloat r[3], Vfloat g[][3]);
VKI_EXTERN void
vis_GVector3DGendv(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vdouble xe[][3], Vdouble r[3], Vdouble g[][3]);
VKI_EXTERN void
vis_GVector2DNGen(Vint shape, Vint maxi, Vint maxj, Vfloat xe[][3], Vfloat r[2], Vfloat g[][3]);
VKI_EXTERN void
vis_GVector2DNGendv(Vint shape, Vint maxi, Vint maxj, Vdouble xe[][3], Vdouble r[2], Vdouble g[][3]);
VKI_EXTERN void
vis_GVector1DNGen(Vint maxi, Vfloat xe[][3], Vfloat r, Vfloat g[][3]);
VKI_EXTERN void
vis_GVector2DGen(Vint shape, Vint maxi, Vint maxj, Vfloat xe[][2], Vfloat r[2], Vfloat g[][2]);
VKI_EXTERN void
vis_GMatrix3DGen(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vint npts, Vfloat xe[][3], Vfloat r[3], Vfloat g[][3][9]);
VKI_EXTERN void
vis_nodeDJ3DGendv(Vint isw, Vint shape, Vint maxi, Vint maxj, Vint maxk, Vdouble xt[][3], Vdouble dc[], Vint* ierr);
VKI_EXTERN void
vis_checkDJ3DSerPardv(Vint isw, Vint shape, Vdouble xt[][3], Vdouble dc[]);
VKI_EXTERN void
vis_nodeDJ2DGendv(Vint isw, Vint shape, Vint maxi, Vint maxj, Vdouble xt[][3], Vdouble dc[], Vint* ierr);
VKI_EXTERN void
vis_nodeDJ1DGendv(Vint isw, Vint shape, Vint maxi, Vdouble xt[][3], Vdouble dc[], Vint* ierr);
VKI_EXTERN void
vis_nameDataType(Vint datatype, Vchar name[]);
VKI_EXTERN void
vis_distCellPoint(Vint np, Vfloat x[][3], Vfloat xp[3], Vfloat r[3], Vfloat xi[3], Vfloat xd[3], Vfloat* dist);
VKI_EXTERN void
vis_distLinePoint(Vfloat ln[2][3], Vfloat pt[3], Vfloat* r, Vfloat ptint[3], Vfloat offset[3], Vfloat* p_dist);
VKI_EXTERN void
vis_distLineLine(Vfloat line_1[2][3], Vfloat line_2[][3], Vfloat* local_coord, Vfloat int_pt[3], Vfloat offset[3],
                 Vfloat* p_dist);
VKI_EXTERN void
vis_distLineLinedv(Vdouble line1[2][3], Vdouble line2[][3], Vdouble* rloc1, Vdouble* rloc2, Vdouble intpt1[3], Vdouble intpt2[3],
                   Vint* parallel);
VKI_EXTERN void
vis_distLineLinePardv(Vdouble line1[][3], Vdouble line2[][3], Vdouble* rloc1, Vdouble* rloc2, Vdouble intpt1[3],
                      Vdouble intpt2[3], Vint* parallel);
VKI_EXTERN void
vis_distLineLine2Dim(Vdouble line1[2][2], Vdouble line2[][2], Vint* ipar, Vdouble* dist, Vdouble intpt[2]);
VKI_EXTERN void
vis_distLinePoint2Dim(Vdouble ln[2][2], Vdouble pt[2], Vdouble intpt[2], Vdouble* dist);
VKI_EXTERN void
vis_distLinePointdv(Vdouble ln[2][3], Vdouble pt[3], Vdouble ptint[3], Vdouble* r, Vdouble* p_dist);
VKI_EXTERN void
vis_distLinePointPardv(Vdouble ln[3][3], Vdouble pt[3], Vdouble intpt[3], Vdouble* r, Vdouble* dist);
VKI_EXTERN void
vis_pointOnLinedv(Vdouble xl[2][3], Vdouble xp[3], Vdouble tol, Vint* code, Vint* ient, Vdouble xi[3], Vint* ierr);
VKI_EXTERN void
vis_pointOnLinePardv(Vdouble xl[3][3], Vdouble xp[3], Vdouble tol, Vint* code, Vint* ient, Vdouble xi[3], Vint* ierr);
VKI_EXTERN void
vis_dropLinePointdv(Vdouble ln[2][3], Vdouble pt[3], Vdouble intpt[3], Vdouble* w);
VKI_EXTERN void
vis_distLineTridv(Vdouble xt[3][3], Vdouble xl[2][3], Vint* ipar, Vdouble* dist, Vdouble xi[3]);
VKI_EXTERN void
vis_testPointXray2Dim(Vdouble pt[2], Vdouble pl[2][2], Vint* in);
VKI_EXTERN void
vis_testPointXrayTri(Vdouble pn[3], Vdouble pt[3][3], Vint* in);
VKI_EXTERN void
vis_distPolyLine(Vint num_pts, Vfloat pts[][3], Vfloat line[][3], Vfloat local_coords[2], Vfloat int_pt[3], Vfloat offset[3],
                 Vfloat* p_dist, Vint* intersect);
VKI_EXTERN void
vis_distPolyPoint(Vint num_pts, Vfloat pts[][3], Vfloat point[3], Vfloat local_coords[2], Vfloat int_pt[3], Vfloat offset[3],
                  Vfloat* p_dist);
VKI_EXTERN void
vis_intersectLineTridv(Vdouble xt[3][3], Vdouble xl[2][3], Vdouble tol, Vdouble xi[3], Vint* code, Vint* ient, Vint* ierr);
VKI_EXTERN void
vis_intersectLineTriPardv(Vdouble xt[6][3], Vdouble xl[3][3], Vdouble tol, Vdouble xi[3], Vint* code, Vint* ient, Vint* ierr);
VKI_EXTERN void
vis_pointOnTridv(Vdouble xt[3][3], Vdouble xp[3], Vdouble tol, Vint* code, Vint* ient, Vdouble xi[3], Vint* ierr);
VKI_EXTERN void
vis_pointOnTriPardv(Vdouble xt[6][3], Vdouble xp[3], Vdouble tol, Vint* code, Vint* ient, Vdouble xi[3], Vint* ierr);
VKI_EXTERN void
vis_deriveVector(Vint ipre, void* d, Vint derive, Vint index, Vdouble s[]);
VKI_EXTERN void
vis_deriveTensor(Vint ipre, void* d, Vint derive, Vint estrn, Vint index, Vdouble s[]);
VKI_EXTERN void
vis_deriveGeneral(Vint ipre, void* d, Vint derive, Vint index, Vdouble s[]);
VKI_EXTERN void
vis_deriveSixDof(Vint ipre, void* d, Vint derive, Vint index, Vdouble s[]);
VKI_EXTERN void
vis_deriveElemRes(Vint ipre, void* d, Vint derive, Vint index, Vdouble s[]);
VKI_EXTERN void
vis_deriveScalars(Vint ipre, Vint nrws, void* d, Vint derive, Vint index, Vdouble s[]);
VKI_EXTERN void
vis_aliasInit(vis_GridFun* gf, Vint* aliasnode, Vint* aliaselem);
VKI_EXTERN void
vis_aliasNode(vis_GridFun* gf, Vint aliasnode, Vint numindices, Vint indices[], Vint ids[]);
VKI_EXTERN void
vis_aliasElem(vis_GridFun* gf, Vint aliaselem, Vint numindices, Vint indices[], Vint ids[]);
VKI_EXTERN void
vis_lineEq2D(Vfloat p1[2], Vfloat p2[2], Vfloat* a, Vfloat* b, Vfloat* c);
VKI_EXTERN void
vis_insideRect2D(Vfloat x[4][2], Vfloat y[4][2], Vint* inside);
VKI_EXTERN void
vis_intersectRect2D(Vfloat c[4][2], Vfloat d[4][2], Vint* interflag);
VKI_EXTERN void
vis_cyclicCompute(Vdouble x1[][3], Vdouble xp1[], Vdouble vp1[3], Vdouble x2[][3], Vdouble xp2[], Vdouble vp2[3], Vdouble tol,
                  Vdouble xt[3], Vdouble tm[3][3], Vint* ierr);
VKI_EXTERN void
vis_matchIdTran(vsy_HashTable* sethash, vis_IdTran* idtran, vis_IdTran** idtranmatch, vsy_BitVec* sethashUniqueUsage);
VKI_EXTERN void
vis_matchIdTranInterSurf(vsy_HashTable* sethash, vis_IdTran* idtran, vis_IdTran** idtranmatch, vsy_BitVec* sethashUniqueUsage);
VKI_EXTERN void
vis_modAngles(Vdouble a1, Vdouble y1, Vdouble* a2);
VKI_EXTERN void
vis_computeMPCTwoPoints(vis_Connect* p, Vint nix, vis_RCase* rcase, Vint nedofs, Vdouble savedcoeff[], Vint* MPCnodesIndexes,
                        Vint* MPCnodesLocations, Vint avoidOtherMpcs, vis_Group* mpcNodeGroup, vsy_IntVec* mpcPerNodeVec,
                        Vint* n1, Vint* n2);
VKI_EXTERN void
vis_computeMPCThreePoints(vis_Connect* p, Vint nix, vis_RCase* rcase, Vint nedofs, Vdouble savedcoeff[], Vint* MPCnodesIndexes,
                          Vint* MPCnodesLocations, Vint avoidOtherMpcs, vis_Group* mpcNodeGroup, vsy_IntVec* mpcPerNodeVec,
                          Vint* n1, Vint* n2, Vint* n3);
VKI_EXTERN Vint
vis_getPatchAveragedNormal(vis_Connect* connect, Vdouble normalAveraged[3], Vdouble maxAngleVariation);
VKI_EXTERN Vint
vis_getPatchCentroid(vis_Connect* connect, Vdouble centroid[3]);
VKI_EXTERN void
vis_connectAppendSolidOnly(vis_Connect* p, vis_Connect* connectToAppend);
VKI_EXTERN Vint
vis_validStateParentAndChildTypes(Vint parentType, Vint childType);
VKI_EXTERN Vint
vis_validStateDatatype(Vint dataType);
VKI_EXTERN Vint
vis_validDatasetDatatype(Vint datasetDataType);
VKI_EXTERN void
vis_reverseArrayI(Vint* array, Vlong size);
VKI_EXTERN void
vis_computeShellAndMembranesLocalDirectionCosines(vis_Connect* connect, Vint index, vsy_HashTable* coordSystemHashtable,
                                                  vis_ElemDat* materialSystemData, Vdouble coords[][3], Vdouble tme[3][3],
                                                  Vint* ierr);

#ifdef __cplusplus
}
#endif

#endif
