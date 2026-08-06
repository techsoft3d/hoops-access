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
 
#ifndef VMLUTIL_DEF
#define VMLUTIL_DEF
#include "sam/base/basedefs.h"
#ifdef __cplusplus
extern "C" { 
#endif
extern void vml_dircos3pointsdv(Vdouble tm[3][3],Vint
iop,Vdouble x1[3],Vdouble x2[3],Vdouble x3[3],Vint*
ierr);extern void vml_dircos3axis(Vfloat tm[3][3],Vint
axis,Vfloat angle);extern void vml_dircos3axisdv(Vdouble
tm[3][3],Vint axis,Vdouble angle);extern void vml_dircos3vector(Vfloat
tm[3][3],Vfloat vect[3],Vfloat angle,Vint* ierr);extern
void vml_dircos3vectordv(Vdouble tm[3][3],Vdouble vect[3],
Vdouble angle,Vint* ierr);extern void vml_dircos3angledv(Vdouble
axial[3],Vdouble tm[3][3]);extern void vml_angle3dircosdv(Vdouble
tm[3][3],Vdouble axial[3]);extern void vml_angle2sincosdv(Vdouble
fsin,Vdouble fcos,Vdouble* angle);extern void vml_dircos3ANSYS(Vfloat
tm[3][3],Vint ndim,Vfloat angle[3],Vint* key);extern
void vml_dircos3ANSYSdv(Vdouble tm[3][3],Vint ndim,
Vdouble angle[3],Vint* key);extern void vml_euler3ANSYS(Vdouble
angle[3],Vdouble tm[3][3]);extern void vml_euler3NXNastran(Vdouble
THET[3],Vdouble ROT[3][3]);extern void vml_dircos3axial(Vfloat
tm[3][3],Vfloat axial[3]);extern void vml_dircos3axialdv(Vdouble
tm[3][3],Vdouble axial[3]);extern void vml_dircos3Rodrigues(Vdouble
tm[3][3],Vdouble phi,Vdouble v[3]);extern void vml_dircos3bisectdv(Vdouble
tm[3][3],Vint npts,Vdouble x[][3]);extern void vml_dircos3projectdv(Vdouble
tm[3][3],Vdouble v[3]);extern void vml_dircos3shellclosedv(Vdouble
tm[3][3],Vdouble t[3]);extern void vml_dircos3beamclosedv(Vdouble
tm[3][3],Vdouble t[3]);extern void vml_dircos3beamclose(Vfloat
tm[3][3],Vfloat t[3]);extern void vml_dircos3shellvecdv(Vdouble
tm[3][3],Vdouble t[3],Vdouble v[3],Vint* ierr);extern
void vml_dircos3beamstandv(Vdouble tm[3][3],Vdouble
t[3]);extern void vml_dircos3beamvecdv(Vdouble tm[3][3],
Vdouble t[3],Vdouble v[3],Vint* ierr);extern void vml_angle3midsidedv(Vdouble
v1[3],Vdouble v2[3],Vdouble vm[3]);extern void vml_btdbd(Vdouble
s[],Vdouble g[],Vdouble em[],Vint ns,Vint nf,Vdouble
dj);extern Vint vml_compute_eigenvalues(int iswirl,
Vdouble A[3][3],Vdouble eigenvalue[3]);extern Vint vml_compute_real_eigenvector(Vdouble
a[3][3],Vdouble val,Vdouble vec[3]);extern void vml_compute_complex_eigenvectors(Vdouble
m[3][3],Vdouble vals[3],Vdouble vecs[3][3]);extern void
vml_polar3d(Vdouble F[3][3],Vdouble R[3][3],Vdouble
U[6],Vdouble eigval[3],Vdouble eigvec[3][3],Vint* ierr);
extern void vml_eigenSym2(Vfloat T[3],Vint absfl,Vfloat
sig[2],Vint vecfl,Vfloat dir[2][2]);extern void vml_eigenSym2d(Vdouble
T[3],Vint absfl,Vdouble sig[2],Vint vecfl,Vdouble dir[2][2]);
extern void vml_eigenSym3(Vfloat T[6],Vint absfl,Vfloat
sig[3],Vint vecfl,Vfloat dir[3][3]);extern void vml_eigenSym3d(Vdouble
T[6],Vint absfl,Vdouble sig[3],Vint vecfl,Vdouble dir[3][3]);
extern void vml_rotGivensd(Vint n,Vdouble r[],Vdouble*
u,Vint iu,Vdouble* v,Vint iv);extern void vml_eigenSymd(Vint
n,Vdouble* a,Vdouble* b,Vdouble* e,Vdouble* x,Vdouble*
w,Vint* np,Vint* ip,Vint* ierr);extern void vml_tran3(Vfloat
a[3][3]);extern void vml_tran3d(Vdouble a[3][3]);extern
void vml_tran6d(Vdouble a[6][6]);extern void vml_invert4(Vfloat
a[4][4],Vfloat ainv[4][4],Vint* ising);extern void vml_factorFull(Vdouble
a[],Vint neq,Vint* ier);extern void vml_factorFullPen(Vdouble
a[],Vint neq);extern void vml_backFull(Vdouble a[],
Vdouble b[],Vint neq);extern Vdouble vml_dot(Vdouble
a[],Vdouble b[],Vint neq);extern void vml_factorLU(Vdouble
a[],Vint n,Vint indx[],Vdouble* d,Vdouble vv[],Vint*
ier);extern void vml_solveLU(Vdouble a[],Vint n,Vint
indx[],Vdouble b[]);extern void vml_invertSymd(Vdouble
a[],Vint nmax,Vint* ising);extern void vml_condSymd(Vdouble*
d,Vint nr,Vint n);extern void vml_invertUSymd(Vdouble
a[],Vint nmax,Vint* ising);extern void vml_copy4(Vfloat
a[4][4],Vfloat b[4][4]);extern void vml_multf3(Vfloat
a[3][3],Vfloat b[3][3],Vfloat c[3][3]);extern void vml_multft3(Vfloat
a[3][3],Vfloat b[3][3],Vfloat c[3][3]);extern void vml_multf3t(Vfloat
a[3][3],Vfloat b[3][3],Vfloat c[3][3]);extern void vml_multtran4(Vfloat
a[4][4],Vfloat b[4][4],Vfloat c[4][4]);extern void vml_mult3AtBd(Vdouble
a[3][3],Vdouble b[3][3],Vdouble c[3][3]);extern void
vml_mult3ABtd(Vdouble a[3][3],Vdouble b[3][3],Vdouble
c[3][3]);extern void vml_mult3ABd(Vdouble a[3][3],Vdouble
b[3][3],Vdouble c[3][3]);extern void vml_mult3AtBtd(Vdouble
a[3][3],Vdouble b[3][3],Vdouble c[3][3]);extern void
vml_mult2AtBd(Vdouble a[2][2],Vdouble b[2][2],Vdouble
c[2][2]);extern void vml_mult2ABtd(Vdouble a[2][2],
Vdouble b[2][2],Vdouble c[2][2]);extern void vml_mult2ABd(Vdouble
a[2][2],Vdouble b[2][2],Vdouble c[2][2]);extern void
vml_mult2AtBtd(Vdouble a[2][2],Vdouble b[2][2],Vdouble
c[2][2]);extern void vml_mult6vd(Vdouble t[6][6],Vdouble
a[6],Vdouble b[6]);extern void vml_multt6vd(Vdouble
t[6][6],Vdouble a[6],Vdouble b[6]);extern void vml_mult4(Vfloat
a[4][4],Vfloat b[4][4],Vfloat c[4][4]);extern void vml_mult4vec(Vfloat
a[4][4],Vfloat b[4],Vfloat c[4]);extern void vml_max3vec(Vfloat
x[3],Vfloat* xmax);extern void vml_min3vec(Vfloat x[3],
Vfloat* xmin);extern void vml_multMatrix1(Vint num,
Vfloat g[],Vfloat d[],Vfloat* dg);extern void vml_multMatrix1d(Vint
num,Vdouble g[],Vdouble d[],Vdouble* dg);extern void
vml_multMatrix2(Vint num,Vfloat g[][2],Vfloat d[],Vfloat
dg[2]);extern void vml_multMatrix2d(Vint num,Vdouble
g[][2],Vdouble d[],Vdouble dg[2]);extern void vml_multMatrix2x2(Vint
num,Vfloat g[][2],Vfloat d[][2],Vfloat dg[2][2]);extern
void vml_multMatrix3(Vint num,Vfloat g[][3],Vfloat d[],
Vfloat dg[3]);extern void vml_multMatrix3ds(Vint num,
Vfloat g[][3],Vdouble d[],Vdouble dg[3]);extern void
vml_multMatrix3x3(Vint num,Vfloat g[][3],Vfloat d[][3],
Vfloat dg[3][3]);extern void vml_multMatrix9(Vint num,
Vfloat g[][9],Vfloat d[],Vfloat dg[9]);extern void vml_multMatrix3d(Vint
num,Vdouble g[][3],Vdouble d[],Vdouble dg[3]);extern
void vml_gatherData(Vint ndrows,Vfloat sd[],Vint npts,
Vint ii[],Vfloat sde[]);extern void vml_gatherDatadv(Vint
ndrows,Vdouble sd[],Vint npts,Vint ii[],Vdouble sde[]);
VKI_EXTERN void vml_gatherCoord(Vfloat x[][3],Vint npts,
Vint ii[],Vfloat xe[][3]);extern void vml_gatherCoordsdv(Vfloat
x[][3],Vint npts,Vint ii[],Vdouble xe[][3]);extern void
vml_gatherCoorddv(Vdouble x[][3],Vint npts,Vint ii[],
Vdouble xe[][3]);extern void vml_gatherCon(Vint ix[],
Vint npts,Vint ii[],Vint ixe[]);extern void vml_minmaxScalarData(Vfloat
s[],Vint npts,Vfloat* smin,Vfloat* smax);extern void
vml_clampScalarData(Vfloat s[],Vint npts,Vfloat smin,
Vfloat smax);VKI_EXTERN void vml_averageCoord(Vfloat
x[][3],Vint npts,Vfloat xc[3]);VKI_EXTERN void vml_averageCoorddv(Vdouble
x[][3],Vint npts,Vdouble xc[3]);extern void vml_averageData(Vint
ndrows,Vfloat s[],Vint npts,Vfloat sc[]);extern void
vml_averageDatadv(Vint ndrows,Vdouble s[],Vint npts,
Vdouble sc[]);extern void vml_scatterData(Vint ndrows,
Vfloat sde[],Vint npts,Vint ii[],Vfloat sd[]);extern
void vml_scatterDatadv(Vint ndrows,Vdouble sde[],Vint
npts,Vint ii[],Vdouble sd[]);extern void vml_scatterCent(Vint
ndrows,Vfloat sde[],Vint npts,Vint ii[],Vfloat sd[]);
extern void vml_tridiag(Vfloat r[],Vint n,Vfloat sol[]);
extern void vml_eigenu2(Vfloat a[2][2],Vint* num_real,
Vcomplex eval[2],Vcomplex evec[2][2]);extern void vml_eigenu3d(Vdouble
a[3][3],Vint opt,Vint* num_real,Vdcomplex eval[3],Vdcomplex
evec[3][3],Vint* stat);extern void vml_intersectLineLine(Vdouble
xl1[2][3],Vdouble xl2[2][3],Vdouble xi1[3],Vdouble xi2[3],
Vint* intersect);extern void vml_extentBoxd(Vint npts,
Vdouble x[][3],Vdouble extent[2][3]);extern void vml_mp2ri(Vfloat
mag,Vfloat phase,Vfloat* r,Vfloat* imag);extern void
vml_ri2mp(Vfloat r,Vfloat imag,Vfloat* mag,Vfloat* phase);
extern void vml_mp2rid(Vdouble mag,Vdouble phase,Vdouble*
r,Vdouble* imag);extern void vml_ri2mpd(Vdouble r,Vdouble
imag,Vdouble* mag,Vdouble* phase);extern void vml_multSymdv(Vdouble
d[],Vdouble x[],Vint num,Vdouble y[]);
#ifdef __cplusplus
}
#endif
#define fuzz_factor 1.0e-7
#define Zero_test1(result,term1) if (fabs(result)<=\
fuzz_factor * fabs(term1)) result = 0.0
#define Zero_test2(result,term1,term2) if (fabs(result)\
<= fuzz_factor * (fabs(term1)+ fabs(term2))) result\
= 0.0
#define Zero_test3(result,term1,term2,term3) if (fabs(result)\
<= fuzz_factor * (fabs(term1)+ fabs(term2)+ fabs(term3)))\
 result = 0.0
#define Zero_test4(result,term1,term2,term3,term4) if\
(fabs(result)<= fuzz_factor * (fabs(term1)+ fabs(term2)\
+ fabs(term3)+ fabs(term4))) result = 0.0
#define Zero_test6(result,term1,term2,term3,term4,term5,\
term6) if (fabs(result)<= fuzz_factor * (fabs(term1)\
+ fabs(term2)+ fabs(term3)+ fabs(term4)+ fabs(term5)\
+ fabs(term6))) result = 0.0
#endif

