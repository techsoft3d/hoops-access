#pragma once

#include "samcpp/core/base_types.h"
#include "samcpp/core/pimpl.h"
#include "samcpp/core/status.h"

#include <memory>

ACCESSOR_DECL

namespace cae::core {

class AnalyticSurface {
  public:
    /// Surface type
    enum class Type {
        SEGMENTED = ASURF_SEGMENT,                ///< Two-dimensional segmented surface
        SEGMENTED_RULE = ASURF_SEGMENT_RULE,      ///< Segmented ruled surface
        SEGMENTED_REVOLUTION = ASURF_SEGMENT_REV, ///< Segmented surface of revolution
        PLANE = ASURF_PLANE,                      ///< Planar surface
        BOX = ASURF_BOX,                          ///< Box surface
        SPHERE = ASURF_SPHERE,                    ///< Spherical surface
        CYLINDER = ASURF_CYLINDER,                ///< Cylindrical surface
        CONE = ASURF_CONE,                        ///< Conical surface
        FACET = ASURF_FACET,                      ///< Facetted surface
        NURBS = ASURF_NURBS                       ///< NURBS surface
    };

    /// Segment type for surface profiles
    enum class SegmentType {
        LINE = ASURF_SEG_LINE,      ///< Straight line segment
        ARC = ASURF_SEG_ARC,        ///< Circular arc segment
        PARABOLIC = ASURF_SEG_PARAB ///< Parabolic segment
    };
    /// Facet type for facetted surfaces
    enum class FacetType {
        LINEAR_TRIANGLE = ASURF_FACET_TRI,             ///< Linear triangle facet
        PARABOLIC_TRIANGLE = ASURF_FACET_PARATRI,      ///< Parabolic triangle facet
        LINEAR_QUADRILATERAL = ASURF_FACET_QUAD,       ///< Linear quadrilateral facet
        PARABOLIC_QUADRILATERAL = ASURF_FACET_PARAQUAD ///< Parabolic quadrilateral facet
    };
    /// NURBS type
    enum class NurbsType {
        LINE = ASURF_NURBS_LINE,   ///< NURBS line
        SURFACE = ASURF_NURBS_SURF ///< NURBS surface
    };

    PIMPL_MOVE_ONLY(AnalyticSurface)

    ErrorCode getErrorCode();
    Status    define(Type type);
    Status    inquire(Type *type);
    Status    setName(const char *name);
    Status    getName(char name[]);
    Status    setPoint(int id, double coord[3]);
    Status    getPoint(int id, double coord[3]);
    Status    getPointCount(int *count);
    Status    setSegment(int id, SegmentType type, int connectivity[]);
    Status    getSegment(int id, SegmentType *type, int connectivity[]);
    Status    getSegmentCount(int *count);
    Status    setSegmentRuleAxis(double a[3], double b[3], double c[3]);
    Status    getSegmentRuleAxis(double a[3], double b[3], double c[3]);
    Status    setSegmentRevolutionAxis(double a[3], double b[3], double c[3]);
    Status    getSegmentRevolutionAxis(double a[3], double b[3], double c[3]);
    Status    setSegmentFilletRadius(double r);
    Status    getSegmentFilletRadius(double *r);
    Status    setPlane(double a[3], double b[3], double c[3], double length, double width);
    Status    getPlane(double a[3], double b[3], double c[3], double *length, double *width);
    Status    setBox(double a[3], double b[3], double c[3], double length, double width, double height);
    Status    getBox(double a[3], double b[3], double c[3], double *length, double *width, double *height);
    Status    setCylinder(double a[3], double b[3], double c[3], double radius, double height);
    Status    getCylinder(double a[3], double b[3], double c[3], double *radius, double *height);
    Status    setCone(double a[3], double b[3], double c[3], double r1, double r2, double height);
    Status    getCone(double a[3], double b[3], double c[3], double *r1, double *r2, double *height);
    Status    setSphere(double center[3], double radius);
    Status    getSphere(double center[3], double *radius);
    Status    print();
    Status    setNURBS(int id, NurbsType type, int uPointCount, int uOrder, int vPointCount, int vOrder, int connectivity[], double homoWeights[], double knots[], int trimLoopsCount, int trimList[]);
    Status    getNURBSCount(int *count);
    Status    getMaxNURBSOrder(int *maxOrder);
    Status    getNurbsPointsAndTrimLoops(int id, NurbsType *type, int *uPointCount, int *uOrder, int *vPointCount, int *vOrder, int *trimLoopsCount);
    Status    getNURBS(int id, NurbsType *type, int *uPointCount, int *uOrder, int *vPointCount, int *vOrder, int connectivity[], double homoWeights[], double knots[], int *ntrim, int trimlist[]);
    Status    setNURBSTrimLoop(int id, int pointCount, int points[]);
    Status    getNURBSTrimLoopCount(int *count);
    Status    getNURBSTrimLoopPointCount(int id, int *pointCount);
    Status    getNURBSTrimLoop(int id, int *pointCount, int points[]);
    Status    setFacet(int id, FacetType type, int connectivity[]);
    Status    getFacetCount(int *count);
    Status    getFacet(int id, FacetType *type, int connectivity[]);

  private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // namespace cae::core
