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
/* Mesh metric object */

#ifndef METRIC_DEF
#define METRIC_DEF

#include "sam/base/base.h"
#include "sam/vis/visdefs.h"

/* defines for comparison operations */
#define VIS_MESHMETRIC_COMPARISON_NONE                 0
#define VIS_MESHMETRIC_COMPARISON_LESSTHANOREQUAL      1
#define VIS_MESHMETRIC_COMPARISON_GREATERTHANOREQUAL   2
#define VIS_MESHMETRIC_COMPARISON_EQUALWITHINTOLERANCE 3
#define VIS_MESHMETRIC_COMPARISON_MAX                  4

struct vis_MeshMetric {
    vsy_BitVec* compliance;
    vsy_DblVec* values;
    Vdouble referenceValue;
    Vdouble relativeTolerance;
    Vchar name[SYS_MAXNAME];
    Vint comparisonOperation;
    Vint errorCode;

#ifdef __cplusplus
  public:
    VKI_EXTERN
    vis_MeshMetric(void);
    VKI_EXTERN void*
    operator new(size_t);
    VKI_EXTERN ~vis_MeshMetric(void);
    VKI_EXTERN void
    operator delete(void*);
    VKI_EXTERN Vint
    Error();
    VKI_EXTERN Vint Complies(Vint);
    VKI_EXTERN Vdouble Value(Vint);
    VKI_EXTERN void Def(Vint, Vdouble, Vchar[], Vint);
    VKI_EXTERN void
    Inq(Vint*, Vdouble*, Vchar[], Vint*);
    VKI_EXTERN void Set(Vint, Vdouble);
    VKI_EXTERN void SetRelativeTolerance(Vdouble);
    VKI_EXTERN Vdouble
    RelativeTolerance();
    VKI_EXTERN Vdouble
    Min();
    VKI_EXTERN Vdouble
    Max();
    VKI_EXTERN Vdouble
    Average();
    VKI_EXTERN Vdouble
    StandardDeviation();
    VKI_EXTERN Vdouble
    ComplianceRatio();
#endif
};

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vis_MeshMetric*
vis_MeshMetricBegin(void);
VKI_EXTERN void
vis_MeshMetricDef(vis_MeshMetric* p, Vint elementCount, Vdouble referenceValue, Vchar name[], Vint comparisonOperation);
VKI_EXTERN void
vis_MeshMetricInq(vis_MeshMetric* p, Vint* elementCount, Vdouble* referenceValue, Vchar name[], Vint* comparisonOperation);
VKI_EXTERN void
vis_MeshMetric_Construct(vis_MeshMetric* p);
VKI_EXTERN void
vis_MeshMetricEnd(vis_MeshMetric* p);
VKI_EXTERN void
vis_MeshMetric_Destruct(vis_MeshMetric* p);
VKI_EXTERN Vint
vis_MeshMetricError(vis_MeshMetric* p);
VKI_EXTERN Vint
vis_MeshMetricComplies(vis_MeshMetric* p, Vint elementIndex);
VKI_EXTERN Vdouble
vis_MeshMetricValue(vis_MeshMetric* p, Vint elementIndex);
VKI_EXTERN void
vis_MeshMetricSet(vis_MeshMetric* p, Vint elementIndex, Vdouble value);
VKI_EXTERN Vdouble
vis_MeshMetricMin(vis_MeshMetric* p);
VKI_EXTERN Vdouble
vis_MeshMetricMax(vis_MeshMetric* p);
VKI_EXTERN Vdouble
vis_MeshMetricAverage(vis_MeshMetric* p);
VKI_EXTERN Vdouble
vis_MeshMetricStandardDeviation(vis_MeshMetric* p);
VKI_EXTERN Vdouble
vis_MeshMetricComplianceRatio(vis_MeshMetric* p);
VKI_EXTERN void
vis_MeshMetricSetRelativeTolerance(vis_MeshMetric* p, Vdouble relativeTolerance);
VKI_EXTERN Vdouble
vis_MeshMetricRelativeTolerance(vis_MeshMetric* p);

#ifdef __cplusplus
}
#endif

#endif
