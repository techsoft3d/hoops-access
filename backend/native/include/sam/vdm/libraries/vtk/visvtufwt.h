/* VTK header file */
#ifndef VISVTUFWT_DEF
#define VISVTUFWT_DEF

#include "sam/base/basedefs.h"
// this header contains variables shared by vdm_vtklib

#define VTK_DS_NONE              0
#define VTK_DS_STRUCTURED_POINTS 1
#define VTK_DS_STRUCTURED_GRID   2
#define VTK_DS_UNSTRUCTURED_GRID 3
#define VTK_DS_POLYDATA          4
#define VTK_DS_RECTILINEAR_GRID  5

#define VTKLIB_SHAPETRISTRIP -1

/* VTK cell types */
#define VTK_EMPTY_CELL                       0
#define VTK_VERTEX                           1
#define VTK_POLY_VERTEX                      2
#define VTK_LINE                             3
#define VTK_POLY_LINE                        4
#define VTK_TRIANGLE                         5
#define VTK_TRIANGLE_STRIP                   6
#define VTK_POLYGON                          7
#define VTK_PIXEL                            8
#define VTK_QUAD                             9
#define VTK_TETRA                            10
#define VTK_VOXEL                            11
#define VTK_HEXAHEDRON                       12
#define VTK_WEDGE                            13
#define VTK_PYRAMID                          14
#define VTK_PENTAGONAL_PRISM                 15
#define VTK_HEXAGONAL_PRISM                  16
#define VTK_QUADRATIC_EDGE                   21
#define VTK_QUADRATIC_TRIANGLE               22
#define VTK_QUADRATIC_QUAD                   23
#define VTK_QUADRATIC_TETRA                  24
#define VTK_QUADRATIC_HEXAHEDRON             25
#define VTK_QUADRATIC_WEDGE                  26
#define VTK_QUADRATIC_PYRAMID                27
#define VTK_BIQUADRATIC_QUAD                 28
#define VTK_TRIQUADRATIC_HEXAHEDRON          29
#define VTK_QUADRATIC_LINEAR_QUAD            30
#define VTK_QUADRATIC_LINEAR_WEDGE           31
#define VTK_BIQUADRATIC_QUADRATIC_WEDGE      32
#define VTK_BIQUADRATIC_QUADRATIC_HEXAHEDRON 33
#define VTK_BIQUADRATIC_TRIANGLE             34
#define VTK_CUBIC_LINE                       35
#define VTK_CONVEX_POINT_SET                 41
#define VTK_POLYHEDRON                       42
#define VTK_PARAMETRIC_CURVE                 51
#define VTK_PARAMETRIC_SURFACE               52
#define VTK_PARAMETRIC_TRI_SURFACE           53
#define VTK_PARAMETRIC_QUAD_SURFACE          54
#define VTK_PARAMETRIC_TETRA_REGION          55
#define VTK_PARAMETRIC_HEX_REGION            56
#define VTK_HIGHER_ORDER_EDGE                60
#define VTK_HIGHER_ORDER_TRIANGLE            61
#define VTK_HIGHER_ORDER_QUAD                62
#define VTK_HIGHER_ORDER_POLYGON             63
#define VTK_HIGHER_ORDER_TETRAHEDRON         64
#define VTK_HIGHER_ORDER_WEDGE               65
#define VTK_HIGHER_ORDER_PYRAMID             66
#define VTK_HIGHER_ORDER_HEXAHEDRON          67

typedef struct {
    Vint vtktype;
    Vint shape;
    Vint maxi;
    Vint maxj;
    Vint maxk;
    Vint permute;
    Vint usenpoints;
} vdm_VTKLib_EType;

static const vdm_VTKLib_EType etypes[] = {
/* VTK_EMPTY_CELL                       */
{VTK_VERTEX, SYS_SHAPEPOINT, 1, 0, 0, 0, 0},
{VTK_POLY_VERTEX, SYS_SHAPEPOINT, 0, 0, 0, 0, 1},
{VTK_LINE, SYS_SHAPELINE, 0, 0, 0, 0, 0},
{VTK_TRIANGLE, SYS_SHAPETRI, 0, 0, 0, 0, 0},
/* VTK_TRIANGLE_STRIP                   */
{VTK_POLYGON, SYS_SHAPEPOLYGON, 0, 0, 0, 0, 0},
{VTK_PIXEL, SYS_SHAPEQUAD, 0, 0, 0, 1, 0},
{VTK_QUAD, SYS_SHAPEQUAD, 0, 0, 0, 0, 0},
{VTK_TETRA, SYS_SHAPETET, 0, 0, 0, 0, 0},
{VTK_VOXEL, SYS_SHAPEHEX, 0, 0, 0, 1, 0},
{VTK_HEXAHEDRON, SYS_SHAPEHEX, 0, 0, 0, 0, 0},
{VTK_WEDGE, SYS_SHAPEWED, 0, 0, 0, 1, 0},
{VTK_PYRAMID, SYS_SHAPEPYR, 0, 0, 0, 0, 0},
/* VTK_PENTAGONAL_PRISM                 */
/* VTK_HEXAGONAL_PRISM                  */
{VTK_QUADRATIC_EDGE, SYS_SHAPELINE, 3, 0, 0, 1, 0},
{VTK_QUADRATIC_TRIANGLE, SYS_SHAPETRI, 3, 0, 0, 0, 0},
{VTK_QUADRATIC_QUAD, SYS_SHAPEQUAD, 3, 0, 0, 0, 0},
{VTK_QUADRATIC_TETRA, SYS_SHAPETET, 3, 0, 0, 0, 0},
{VTK_QUADRATIC_HEXAHEDRON, SYS_SHAPEHEX, 3, 0, 0, 0, 0},
{VTK_QUADRATIC_WEDGE, SYS_SHAPEWED, 3, 0, 0, 2, 0},
{VTK_QUADRATIC_PYRAMID, SYS_SHAPEPYR, 3, 0, 0, 0, 0},
{VTK_BIQUADRATIC_QUAD, SYS_SHAPEQUAD, 3, 3, 0, 2, 0},
{VTK_TRIQUADRATIC_HEXAHEDRON, SYS_SHAPEHEX, 3, 3, 3, 2, 0},
{VTK_QUADRATIC_LINEAR_QUAD, SYS_SHAPEQUAD, 3, 2, 0, 3, 0},
{VTK_QUADRATIC_LINEAR_WEDGE, SYS_SHAPEWED, 3, 0, 2, 3, 0},
/* VTK_BIQUADRATIC_QUADRATIC_WEDGE      */
/* VTK_BIQUADRATIC_QUADRATIC_HEXAHEDRON */
/* VTK_BIQUADRATIC_TRIANGLE             */
{VTK_CUBIC_LINE, SYS_SHAPELINE, 4, 0, 0, 2, 0},
{VTK_CONVEX_POINT_SET, SYS_SHAPEPOINT, 0, 0, 0, 0, 1},
{VTK_POLYHEDRON, SYS_SHAPEPOLYHED, 0, 0, 0, 0, 0},
/* VTK_PARAMETRIC_CURVE                 */
/* VTK_PARAMETRIC_SURFACE               */
/* VTK_PARAMETRIC_TRI_SURFACE           */
/* VTK_PARAMETRIC_QUAD_SURFACE          */
/* VTK_PARAMETRIC_TETRA_REGION          */
/* VTK_PARAMETRIC_HEX_REGION            */
/* VTK_HIGHER_ORDER_EDGE                */
/* VTK_HIGHER_ORDER_TRIANGLE            */
/* VTK_HIGHER_ORDER_QUAD                */
/* VTK_HIGHER_ORDER_POLYGON             */
/* VTK_HIGHER_ORDER_TETRAHEDRON         */
/* VTK_HIGHER_ORDER_WEDGE               */
/* VTK_HIGHER_ORDER_PYRAMID             */
/* VTK_HIGHER_ORDER_HEXAHEDRON          */
{0, 0, 0, 0, 0, 0, 0}};
#endif
