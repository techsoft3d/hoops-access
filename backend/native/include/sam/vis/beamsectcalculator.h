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
/* BeamSectCalculator object */

#ifndef BEAMSECTCALCULATOR_DEF
#define BEAMSECTCALCULATOR_DEF

#include "sam/vis/sysmat.h"
#include "sam/vis/visdefs.h"

/* defines for maximums */
#define BEAMSECT_MAXPROPS   16
#define BEAMSECT_MAXDIMES   14
#define BEAMSECT_MAXFILLETS 10

/* defines for builtin sections */
#define BEAMSECT_PROPS       0
#define BEAMSECT_GEOMETRY    1
#define BEAMSECT_BOX         2
#define BEAMSECT_ANGLE       3
#define BEAMSECT_IBEAM       4
#define BEAMSECT_CIRCLE      5
#define BEAMSECT_TUBE        6
#define BEAMSECT_PANEL       7
#define BEAMSECT_RECTANGLE   8
#define BEAMSECT_TRAPEZOID   9
#define BEAMSECT_HEXAGON     10
#define BEAMSECT_TEE         11
#define BEAMSECT_ZEE         12
#define BEAMSECT_CHANNEL     13
#define BEAMSECT_SECTOR      14
#define BEAMSECT_ELLIPSE     15
#define BEAMSECT_HAT         16
#define BEAMSECT_CROSS       17
#define BEAMSECT_DBOX        18
#define BEAMSECT_HAT1        19
#define BEAMSECT_QUAD        20
#define BEAMSECT_HATG        21
#define BEAMSECT_SOLIDHEXA   22
#define BEAMSECT_RECTTUBE    23
#define BEAMSECT_HATT        24
#define BEAMSECT_SEGMENTS    25
#define BEAMSECT_MAXSECTIONS 26

/* defines for state retrieval */
#define BEAMSECT_TORSION  0
#define BEAMSECT_FLEXURE1 1
#define BEAMSECT_FLEXURE2 2

/* defines for parameters */
#define BEAMSECT_QUALITYGRID   0
#define BEAMSECT_AXESBASIC     1
#define BEAMSECT_AXESPRINCIPAL 2
#define BEAMSECT_SHEARCENTER   3
#define BEAMSECT_CENTROID      4
#define BEAMSECT_POLYLINE      5
#define BEAMSECT_EDGELENGTH    6

#define BEAMSECT_TRIMESHWRITE    8
#define BEAMSECT_MESHSMOOTH      9
#define BEAMSECT_ERRORTOL        10
#define BEAMSECT_MAXERRITER      11
#define BEAMSECT_REFINE          12
#define BEAMSECT_NUMELEMENTS     13
#define BEAMSECT_NASTRANWRITE    14
#define BEAMSECT_VABS            15
#define BEAMSECT_MAXELEMENTS     16
#define BEAMSECT_TRIMESHFILETYPE 17

#define BEAMSECT_CENTROID_NONE   0
#define BEAMSECT_CENTROID_CIRCLE 1
#define BEAMSECT_CENTROID_SPHERE 2

/* defines for return values */
#define BEAMSECT_ERROR   0
#define BEAMSECT_EDGELEN 1
#define BEAMSECT_NUMITER 2

/* defines for properties */
#define BEAMSECT_PROP_A        0
#define BEAMSECT_PROP_IYY      1
#define BEAMSECT_PROP_IZZ      2
#define BEAMSECT_PROP_IYZ      3
#define BEAMSECT_PROP_ANG      4
#define BEAMSECT_PROP_J        5
#define BEAMSECT_PROP_KSY      6
#define BEAMSECT_PROP_KSZ      7
#define BEAMSECT_PROP_KSYZ     8
#define BEAMSECT_PROP_EY       9
#define BEAMSECT_PROP_EZ       10
#define BEAMSECT_PROP_DSY      11
#define BEAMSECT_PROP_DSZ      12
#define BEAMSECT_PROP_CW       13
#define BEAMSECT_PROP_NEUTRALY 14
#define BEAMSECT_PROP_NEUTRALZ 15

struct vis_BeamSectCalculator {
    Vint ierr;
    Vint type;
    Vdouble dimes[BEAMSECT_MAXDIMES];
    Vdouble props[BEAMSECT_MAXPROPS];
    Vint dimereflecty, dimereflectz;
    Vdouble dimeangle, sinang, cosang;
    Vdouble dmat[21];
    Vdouble cmatinv[21];
    vsy_HashTable* elas;
    Vint midiso; /* =1 default, =0 non-one loop mid */
    vsy_IntHash* etype;
    Vint iscomp;
    Vint numloops;
    Vint maxloops;
    Vint* sizloops;
    Vint* midloops;
    Vint** conloops;
    Vint geomfromdime; /* geometry from SetDimension */
    Vint numfillets;
    Vint addfillethole;                      /* added fillet is a hole */
    Vdouble fillets[BEAMSECT_MAXFILLETS][3]; /* xc, yc, r of each fillet */

    Vint numsegs;

    Vint maxpoints;
    Vdouble (*points)[3];
    Vint numpoints;
    Vint* filletpoints;
    Vint* roundpoints;
    Vint* scr;
    Vfloat (*xgs)[3];

    Vint numtris;
    Vint* contris;
    vis_TriangleGeneration* triangleGeneration;

    Vint vabs;

    /*internal mesh*/
    vis_Connect* connect;
    Vdouble area, xcen, ycen;
    Vdouble edgelength; /* user specified edge length */
    Vint numelements;   /* user specified edge length */
    Vint maxelements;   /* maximum number of elements */
    Vint meshsmooth;    /* smooth */
    Vdouble edgelen;
    Vint* order;

    Vint trimeshwrite;    /* write TriMesh file */
    Vint nastranwrite;    /* write Nastran file */
    Vint trimeshFileType; /* TriMesh file type(s) to write */

    /* Prop Composite calculator*/
    vis_IdTran* idtranr;
    vis_SysMat* vecs[8];
    Vint maxerriter;
    Vint refine;
    Vdouble errortol;
    Vint nint[2];
    Vdouble r[2][9][2];
    Vdouble w[2][9];
    Vdouble h[2][9][9];
    Vdouble phr[2][9][9][2];
    Vdouble error;
    Vint numiter;
    Vdouble e2E[4][6];
    Vdouble ep2E[4][6];
    Vdouble epp2E[4][6];

    /*Prop Iso*/
    vis_IdTran* idtran;
    vis_State* statet;
    vis_State* state1;
    vis_State* state2;
    vis_State* stated;
    vis_SysMat *s1, *s2, *s3;
    Vdouble avec[6];
    Vdouble dvec[4];
    Vdouble dens;

#ifdef __cplusplus
  public:
    VKI_EXTERN
    vis_BeamSectCalculator(void);
    VKI_EXTERN void*
    operator new(size_t);
    VKI_EXTERN ~vis_BeamSectCalculator(void);
    VKI_EXTERN void
    operator delete(void*);
    VKI_EXTERN Vint
    Error();
    VKI_EXTERN void Def(Vint);
    VKI_EXTERN void
    SetPointdv(Vint, Vdouble*);
    VKI_EXTERN void
    SetDimensionsdv(Vdouble*);
    VKI_EXTERN void SetReflect(Vint, Vint);
    VKI_EXTERN void
    SetLoop(Vint, Vint, Vint, Vint*);
    VKI_EXTERN void SetRotatedv(Vdouble);
    VKI_EXTERN void
    SetElasPropdv(Vint, Vint, Vdouble*);
    VKI_EXTERN void
    Props(void);
    VKI_EXTERN void
    SetPropsdv(Vdouble*, Vdouble*);
    VKI_EXTERN void
    GetPropsdv(Vdouble*, Vdouble*);
    VKI_EXTERN void SetParamd(Vint, Vdouble);
    VKI_EXTERN void SetParami(Vint, Vint);
    VKI_EXTERN void
    GetNum(Vint*, Vint*, Vint*, Vint*, Vint*, Vint*);
    VKI_EXTERN void
    FreeGeometry(void);
#endif
};

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vis_BeamSectCalculator*
vis_BeamSectCalculatorBegin(void);
VKI_EXTERN void
vis_BeamSectCalculator_Construct(vis_BeamSectCalculator* p);
VKI_EXTERN void
vis_BeamSectCalculatorEnd(vis_BeamSectCalculator* p);
VKI_EXTERN void
vis_BeamSectCalculator_Destruct(vis_BeamSectCalculator* p);
VKI_EXTERN Vint
vis_BeamSectCalculatorError(vis_BeamSectCalculator* p);
VKI_EXTERN void
vis_BeamSectCalculatorDef(vis_BeamSectCalculator* p, Vint type);
VKI_EXTERN void
vis_BeamSectCalculatorSetPointdv(vis_BeamSectCalculator* p, Vint id, Vdouble x[2]);
VKI_EXTERN void
vis_BeamSectCalculatorSetDimensionsdv(vis_BeamSectCalculator* p, Vdouble dimes[]);
VKI_EXTERN void
vis_BeamSectCalculatorSetReflect(vis_BeamSectCalculator* p, Vint reflecty, Vint reflectz);
VKI_EXTERN void
vis_BeamSectCalculatorSetLoop(vis_BeamSectCalculator* p, Vint id, Vint mid, Vint npts, Vint ix[]);
VKI_EXTERN void
vis_BeamSectCalculatorSetRotatedv(vis_BeamSectCalculator* p, Vdouble angle);
VKI_EXTERN void
vis_BeamSectCalculatorProps(vis_BeamSectCalculator* p);
VKI_EXTERN void
vis_BeamSectCalculatorSetPropsdv(vis_BeamSectCalculator* p, Vdouble props[], Vdouble dmat[21]);
VKI_EXTERN void
vis_BeamSectCalculatorGetPropsdv(vis_BeamSectCalculator* p, Vdouble props[], Vdouble dmat[21]);
VKI_EXTERN void
vis_BeamSectCalculatorFreeGeometry(vis_BeamSectCalculator* p);
VKI_EXTERN void
vis_BeamSectCalculatorSetElasPropdv(vis_BeamSectCalculator* p, Vint mid, Vint type, Vdouble elas[]);
VKI_EXTERN void
vis_BeamSectCalculatorSetParamd(vis_BeamSectCalculator* p, Vint ptype, Vdouble dparam);
VKI_EXTERN void
vis_BeamSectCalculatorSetParami(vis_BeamSectCalculator* p, Vint ptype, Vint iparam);
VKI_EXTERN void
vis_BeamSectCalculatorGetNum(vis_BeamSectCalculator* p, Vint* npoints, Vint* nloops, Vint* npolylines, Vint* ntris,
                             Vint* nqualpnts, Vint* nqualtris);

#ifdef __cplusplus
}
#endif

#endif
