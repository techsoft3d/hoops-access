#ifdef VKI_LIBAPI_HOOPS

#define INITIALIZE_A3D_API
#include <A3DSDKIncludes.h>
#include <A3DSDKErrorCodes.h>

#include <cassert>
#include <cstring>
#include <cstdio>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <float.h>
#include <vector>
#include <iterator>

#include "sam/base/base.h"
#include "sam/base/system.h"
#include "sam/msh/msh.h"

#include "exam52HE.h"

#define VECMOVE(x, y)  \
    (y)[0] = (x).m_dX; \
    (y)[1] = (x).m_dY; \
    (y)[2] = (x).m_dZ
#define VECLOAD(x, y) \
    (y).m_dX = x[0];  \
    (y).m_dY = x[1];  \
    (y).m_dZ = x[2]
#define VECCROSS(x, y, z)                       \
    (z)[0] = (x)[1] * (y)[2] - (x)[2] * (y)[1]; \
    (z)[1] = (x)[2] * (y)[0] - (x)[0] * (y)[2]; \
    (z)[2] = (x)[0] * (y)[1] - (x)[1] * (y)[0]
#define VECSCALE(x, s) \
    (x)[0] *= (s);     \
    (x)[1] *= (s);     \
    (x)[2] *= (s)

static bool isPrintEnabled = false;
static std::string hoopsLicense = "";

void
example52HE::setPrintEnabled(bool flag)
{
    isPrintEnabled = flag;
}

void
example52HE::setHoopsLicense(const std::string& license)
{
    hoopsLicense = license;
}

/* Topo Context Scale */
static Vdouble dscale = 1.;

/* Matrix */
static A3DVector3dData
CrossProduct(const A3DVector3dData* X, const A3DVector3dData* Y)
{
    A3DVector3dData Z;
    Z.m_dX = X->m_dY * Y->m_dZ - X->m_dZ * Y->m_dY;
    Z.m_dY = X->m_dZ * Y->m_dX - X->m_dX * Y->m_dZ;
    Z.m_dZ = X->m_dX * Y->m_dY - X->m_dY * Y->m_dX;
    return Z;
}

class A3DMatrix4x4 {
  public:
    double m_adM[16];
    // column first
    // m_adM[0] = m00    m_adM[4] = m01    m_adM[8] = m02    m_adM[12] = m03
    // m_adM[1] = m10    m_adM[5] = m11    m_adM[9] = m12    m_adM[13] = m13
    // m_adM[2] = m20    m_adM[6] = m21    m_adM[10] = m22   m_adM[14] = m23
    // m_adM[3] = m30    m_adM[7] = m31    m_adM[11] = m32   m_adM[15] = m33

    A3DMatrix4x4()
    {
        memset(m_adM, 0, sizeof(double) * 16);
        m_adM[0] = m_adM[5] = m_adM[10] = m_adM[15] = 1;
    }

    A3DMatrix4x4
    operator*(const A3DMatrix4x4& matrix) const
    {
        A3DMatrix4x4 result;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                result.m_adM[i + 4 * j] = 0.;
                for (int k = 0; k < 4; k++)
                    result.m_adM[i + 4 * j] += m_adM[i + 4 * k] * matrix.m_adM[k + 4 * j];
            }
        }
        return result;
    }
};

/* Utils */
static A3DEEntityType
GetEntityType(A3DEntity const* ntt)
{
    A3DEEntityType entity_type = kA3DTypeUnknown;
    A3DEntityGetType(ntt, &entity_type);
    return entity_type;
}

static A3DMiscTransformation*
GetTransformation(A3DEntity* ntt)
{
    A3DMiscTransformation* xform = NULL;
    A3DEEntityType entity_type = GetEntityType(ntt);
    if (kA3DTypeAsmProductOccurrence == entity_type) {
        A3DAsmProductOccurrenceData po_data;
        A3D_INITIALIZE_DATA(A3DAsmProductOccurrenceData, po_data);
        A3DAsmProductOccurrenceGet(ntt, &po_data);
        if (NULL != po_data.m_pLocation) {
            xform = po_data.m_pLocation;
        }
        else if (NULL != po_data.m_pPrototype) {
            xform = GetTransformation(po_data.m_pPrototype);
        }
        A3DAsmProductOccurrenceGet(NULL, &po_data);
    }
    else if (kA3DTypeRiBrepModel == entity_type || kA3DTypeRiPolyBrepModel == entity_type) {
        A3DRiRepresentationItemData ri_data;
        A3D_INITIALIZE_DATA(A3DRiRepresentationItemData, ri_data);
        A3DRiRepresentationItemGet(ntt, &ri_data);
        if (NULL != ri_data.m_pCoordinateSystem) {
            A3DRiCoordinateSystemData ri_cs_data;
            A3D_INITIALIZE_DATA(A3DRiCoordinateSystemData, ri_cs_data);
            A3DRiCoordinateSystemGet(ri_data.m_pCoordinateSystem, &ri_cs_data);
            xform = ri_cs_data.m_pTransformation;
            A3DRiCoordinateSystemGet(NULL, &ri_cs_data);
        }
        A3DRiRepresentationItemGet(NULL, &ri_data);
    }
    return xform;
}

static void
stInitMatrixFromMiscTransformation(A3DMiscTransformation const* pMiscTransformation, A3DMatrix4x4& sMatrix)
{
    if (pMiscTransformation) {
        // A3DStatus iRet = A3D_SUCCESS;
        A3DEEntityType eType = GetEntityType(pMiscTransformation);

        switch (eType) {
            case kA3DTypeMiscCartesianTransformation: {
                A3DMiscCartesianTransformationData sData;
                A3D_INITIALIZE_DATA(A3DMiscCartesianTransformationData, sData);

                /*iRet =*/A3DMiscCartesianTransformationGet(pMiscTransformation, &sData);

                double dMirror = (sData.m_ucBehaviour & kA3DTransformationMirror) ? -1. : 1.;

                A3DVector3dData sZVector;
                memset(sMatrix.m_adM, 0, 16 * sizeof(double));
                sZVector = CrossProduct(&(sData.m_sXVector), &(sData.m_sYVector));

                sMatrix.m_adM[12] = sData.m_sOrigin.m_dX;
                sMatrix.m_adM[13] = sData.m_sOrigin.m_dY;
                sMatrix.m_adM[14] = sData.m_sOrigin.m_dZ;

                sMatrix.m_adM[0] = sData.m_sXVector.m_dX * sData.m_sScale.m_dX;
                sMatrix.m_adM[1] = sData.m_sXVector.m_dY * sData.m_sScale.m_dX;
                sMatrix.m_adM[2] = sData.m_sXVector.m_dZ * sData.m_sScale.m_dX;

                sMatrix.m_adM[4] = sData.m_sYVector.m_dX * sData.m_sScale.m_dY;
                sMatrix.m_adM[5] = sData.m_sYVector.m_dY * sData.m_sScale.m_dY;
                sMatrix.m_adM[6] = sData.m_sYVector.m_dZ * sData.m_sScale.m_dY;

                sMatrix.m_adM[8] = dMirror * sZVector.m_dX * sData.m_sScale.m_dZ;
                sMatrix.m_adM[9] = dMirror * sZVector.m_dY * sData.m_sScale.m_dZ;
                sMatrix.m_adM[10] = dMirror * sZVector.m_dZ * sData.m_sScale.m_dZ;

                sMatrix.m_adM[15] = 1.;

                /*iRet =*/A3DMiscCartesianTransformationGet(NULL, &sData);
            } break;

            case kA3DTypeMiscGeneralTransformation: {
                A3DMiscGeneralTransformationData sData;
                A3D_INITIALIZE_DATA(A3DMiscGeneralTransformationData, sData);

                /*iRet =*/A3DMiscGeneralTransformationGet(pMiscTransformation, &sData);

                memcpy(&(sMatrix.m_adM[0]), sData.m_adCoeff, 16 * sizeof(double));

                /*iRet =*/A3DMiscGeneralTransformationGet(NULL, &sData);
            } break;

            default:
                break;
        }
    }
}

static A3DMatrix4x4
ComputeNetMatrix(std::vector<A3DEntity*> const& entities)
{
    A3DMatrix4x4 m;
    for (A3DUns32 idx = 0u; idx < entities.size(); ++idx) {
        A3DMiscTransformation* xform = GetTransformation(entities[idx]);
        if (NULL != xform) {
            A3DMatrix4x4 this_matrix;
            stInitMatrixFromMiscTransformation(xform, this_matrix);
            m = m * this_matrix;
        }
    }
    return m;
}

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunneeded-internal-declaration"
#endif
static char const*
GetName(A3DEntity* ntt)
{
    if (NULL == ntt) {
        return NULL;
    }

    A3DRootBaseData root_base_data;
    A3D_INITIALIZE_DATA(A3DRootBaseData, root_base_data);
    A3DRootBaseGet(ntt, &root_base_data);
    char const* name = root_base_data.m_pcName;
    A3DRootBaseGet(NULL, &root_base_data);

    if (NULL == name && kA3DTypeAsmProductOccurrence == GetEntityType(ntt)) {
        A3DAsmProductOccurrenceData po_data;
        A3D_INITIALIZE_DATA(A3DAsmProductOccurrenceData, po_data);
        A3DAsmProductOccurrenceGet(ntt, &po_data);
        name = GetName(po_data.m_pPrototype);
        A3DAsmProductOccurrenceGet(NULL, &po_data);
    }

    return name;
}
#if defined(__clang__)
#pragma clang diagnostic pop
#endif

/* ForEach */
typedef std::vector<A3DEntity*> A3DEntityArray;
typedef A3DBool (*ForEachCallback)(A3DEntityArray ntts, vis_Connect* connect);
A3DBool
ForEachRepresentationItem(A3DAsmModelFile* model_file, ForEachCallback cb, vis_Connect* connect);

static A3DAsmPartDefinition*
GetPartDefinition(A3DAsmProductOccurrence* po)
{
    A3DAsmPartDefinition* part = NULL;

    A3DAsmProductOccurrenceData po_data;
    A3D_INITIALIZE_DATA(A3DAsmProductOccurrenceData, po_data);
    if (A3DAsmProductOccurrenceGet(po, &po_data) != A3D_SUCCESS) {
        return NULL;
    }

    if (NULL != po_data.m_pPart) {
        part = po_data.m_pPart;
    }
    else if (NULL != po_data.m_pPrototype) {
        part = GetPartDefinition(po_data.m_pPrototype);
    }

    A3DAsmProductOccurrenceGet(NULL, &po_data);

    return part;
}

static A3DBool
TraverseRepresentationItem(A3DRiRepresentationItem* ri, A3DEntityArray entities, ForEachCallback cb, vis_Connect* connect)
{
    if (NULL == ri) {
        return A3D_FALSE;
    }

    entities.push_back(ri);

    A3DEEntityType entity_type = GetEntityType(ri);
    if (kA3DTypeRiSet == entity_type) {
        A3DRiSetData ri_set_data;
        A3D_INITIALIZE_DATA(A3DRiSetData, ri_set_data);
        A3DRiSetGet(ri, &ri_set_data);
        for (A3DUns32 idx = 0u; idx < ri_set_data.m_uiRepItemsSize; ++idx) {
            TraverseRepresentationItem(ri_set_data.m_ppRepItems[idx], entities, cb, connect);
        }
        A3DRiSetGet(NULL, &ri_set_data);
    }
    else if (kA3DTypeRiBrepModel == entity_type || kA3DTypeRiPolyBrepModel == entity_type) {
        if (cb) {
            cb(entities, connect);
        }
    }

    return A3D_TRUE;
}

static A3DBool
TraversePartDefinition(A3DAsmPartDefinition* part, A3DEntityArray entities, ForEachCallback cb, vis_Connect* connect)
{
    if (NULL == part) {
        return A3D_FALSE;
    }

    A3DAsmPartDefinitionData part_def_data;
    A3D_INITIALIZE_DATA(A3DAsmPartDefinitionData, part_def_data);
    if (A3DAsmPartDefinitionGet(part, &part_def_data) != A3D_SUCCESS) {
        return A3D_FALSE;
    }

    entities.push_back(part);

    for (A3DUns32 idx = 0u; idx < part_def_data.m_uiRepItemsSize; ++idx) {
        TraverseRepresentationItem(part_def_data.m_ppRepItems[idx], entities, cb, connect);
    }

    if (A3DAsmPartDefinitionGet(NULL, &part_def_data) != A3D_SUCCESS) {
        return A3D_FALSE;
    }

    return A3D_TRUE;
}

static A3DBool
TraverseProductOccurrence(A3DAsmProductOccurrence* po, A3DEntityArray entities, ForEachCallback cb, vis_Connect* connect)
{
    if (NULL == po) {
        return A3D_FALSE;
    }

    entities.push_back(po);

    A3DAsmPartDefinition* part = GetPartDefinition(po);
    if (NULL != part) {
        TraversePartDefinition(part, entities, cb, connect);
    }

    A3DAsmProductOccurrenceData po_data;
    A3D_INITIALIZE_DATA(A3DAsmProductOccurrenceData, po_data);
    if (A3DAsmProductOccurrenceGet(po, &po_data) != A3D_SUCCESS) {
        return A3D_FALSE;
    }

    for (A3DUns32 idx = 0u; idx < po_data.m_uiPOccurrencesSize; ++idx) {
        TraverseProductOccurrence(po_data.m_ppPOccurrences[idx], entities, cb, connect);
    }

    if (A3DAsmProductOccurrenceGet(NULL, &po_data) != A3D_SUCCESS) {
        return A3D_FALSE;
    }

    return A3D_TRUE;
}

A3DBool
ForEachRepresentationItem(A3DAsmModelFile* model_file, ForEachCallback cb, vis_Connect* connect)
{
    if (NULL == model_file) {
        return A3D_FALSE;
    }

    A3DEntityArray entities;
    A3DAsmModelFileData model_file_data;
    A3D_INITIALIZE_DATA(A3DAsmModelFileData, model_file_data);
    if (A3DAsmModelFileGet(model_file, &model_file_data) != A3D_SUCCESS) {
        printf("Unable to get model file data.");
        return A3D_FALSE;
    }

    entities.push_back(model_file);

    for (A3DUns32 idx = 0u; idx < model_file_data.m_uiPOccurrencesSize; ++idx) {
        TraverseProductOccurrence(model_file_data.m_ppPOccurrences[idx], entities, cb, connect);
    }

    if (A3DAsmModelFileGet(NULL, &model_file_data) != A3D_SUCCESS) {
        printf("Unable to release model file data.");
        return A3D_FALSE;
    }

    return A3D_TRUE;
}

/* DumpSurface */
void
DumpVector(A3DVector2dData const& v)
{
    printf("%f, %f", v.m_dX, v.m_dY);
}

void
DumpVector(A3DVector3dData const& v)
{
    printf("%f, %f, %f", v.m_dX, v.m_dY, v.m_dZ);
}

void
DumpDomain(A3DDomainData const& domain)
{
    printf("Min (u, v): ");
    DumpVector(domain.m_sMin);
    printf("\nMax (u, v): ");
    DumpVector(domain.m_sMax);
    printf("\n");
}

void
DumpParameterization(A3DUVParameterizationData const& param_data)
{
    printf("Swap UV: %d, %f * u + %f, %f * v + %f\n", param_data.m_bSwapUV, param_data.m_dUCoeffA, param_data.m_dUCoeffB,
           param_data.m_dVCoeffA, param_data.m_dVCoeffB);
    DumpDomain(param_data.m_sUVDomain);
}

void
DumpTransform(A3DMiscCartesianTransformationData const& xform)
{
    printf("Behavior flags: %d\n", xform.m_ucBehaviour);
    printf("Origin: ");
    DumpVector(xform.m_sOrigin);
    printf("\nX: ");
    DumpVector(xform.m_sXVector);
    printf("\nY: ");
    DumpVector(xform.m_sYVector);
    printf("\nScale: ");
    DumpVector(xform.m_sScale);
    printf("\n");
}

void
DumpSphere(A3DSurfBase* surface)
{
    printf("Sphere\n");
    A3DSurfSphereData sphere_data;
    A3D_INITIALIZE_DATA(A3DSurfSphereData, sphere_data);
    A3DSurfSphereGet(surface, &sphere_data);
    DumpParameterization(sphere_data.m_sParam);
    DumpTransform(sphere_data.m_sTrsf);
    printf("Radius: %f\n", sphere_data.m_dRadius);
    A3DSurfSphereGet(NULL, &sphere_data);
}

void
DumpTorus(A3DSurfBase* surface)
{
    printf("Torus\n");
    A3DSurfTorusData torus_data;
    A3D_INITIALIZE_DATA(A3DSurfTorusData, torus_data);
    A3DSurfTorusGet(surface, &torus_data);
    DumpParameterization(torus_data.m_sParam);
    DumpTransform(torus_data.m_sTrsf);
    printf("Major Radius: %f, Minor Radius: %f\n", torus_data.m_dMajorRadius, torus_data.m_dMinorRadius);
    A3DSurfTorusGet(NULL, &torus_data);
}

void
DumpCone(A3DSurfBase* surface)
{
    printf("Cone\n");
    A3DSurfConeData cone_data;
    A3D_INITIALIZE_DATA(A3DSurfConeData, cone_data);
    A3DSurfConeGet(surface, &cone_data);
    DumpParameterization(cone_data.m_sParam);
    DumpTransform(cone_data.m_sTrsf);
    printf("InsideOut: %d, Radius: %f, SemiAngle: %f\n", cone_data.m_bInsideOut, cone_data.m_dRadius, cone_data.m_dSemiAngle);
    A3DSurfConeGet(NULL, &cone_data);
}

void
DumpCylinder(A3DSurfBase* surface)
{
    printf("Cylinder\n");
    A3DSurfCylinderData cyl_data;
    A3D_INITIALIZE_DATA(A3DSurfCylinderData, cyl_data);
    A3DSurfCylinderGet(surface, &cyl_data);
    DumpParameterization(cyl_data.m_sParam);
    DumpTransform(cyl_data.m_sTrsf);
    printf("Radius: %f\n", cyl_data.m_dRadius);
    A3DSurfCylinderGet(NULL, &cyl_data);
}

void
DumpPlane(A3DSurfBase* surface)
{
    printf("Plane\n");
    A3DSurfPlaneData plane_data;
    A3D_INITIALIZE_DATA(A3DSurfPlaneData, plane_data);
    A3DSurfPlaneGet(surface, &plane_data);
    DumpParameterization(plane_data.m_sParam);
    DumpTransform(plane_data.m_sTrsf);
    A3DSurfPlaneGet(NULL, &plane_data);
}

void
DumpSurface(A3DSurfBase* surface, Vint sense, Vint* conicid, Vint* hasconic, msh_SurfMesh* surfmesh)
{
    Vdouble xo[3], ax[3], dt[3], dr[3];
    Vdouble radius, angle, param, angler, d, tanang, rlz;

    A3DEEntityType surface_type = GetEntityType(surface);
    /* enter conic section */
    *hasconic = 0;
    switch (surface_type) {
        case kA3DTypeSurfSphere: {
            A3DSurfSphereData sphere_data;
            A3D_INITIALIZE_DATA(A3DSurfSphereData, sphere_data);
            A3DSurfSphereGet(surface, &sphere_data);
            VECMOVE(sphere_data.m_sTrsf.m_sOrigin, xo);
            VECSCALE(xo, dscale);
            VECMOVE(sphere_data.m_sTrsf.m_sXVector, dr);
            VECMOVE(sphere_data.m_sTrsf.m_sYVector, dt);
            VECCROSS(dr, dt, ax);
            radius = sphere_data.m_dRadius;
            radius *= dscale;
            *conicid += 1;
            *hasconic = 1;
            msh_SurfMeshSetConic(surfmesh, *conicid, SURFMESH_CONIC_SPHERE, sense, xo, ax, dr, radius, 0.);
            A3DSurfSphereGet(NULL, &sphere_data);
        }
            if (isPrintEnabled) {
                DumpSphere(surface);
            }
            break;
        case kA3DTypeSurfTorus: {
            A3DSurfTorusData torus_data;
            A3D_INITIALIZE_DATA(A3DSurfTorusData, torus_data);
            A3DSurfTorusGet(surface, &torus_data);
            VECMOVE(torus_data.m_sTrsf.m_sOrigin, xo);
            VECSCALE(xo, dscale);
            VECMOVE(torus_data.m_sTrsf.m_sXVector, dr);
            VECMOVE(torus_data.m_sTrsf.m_sYVector, dt);
            VECCROSS(dr, dt, ax);
            radius = torus_data.m_dMinorRadius;
            radius *= dscale;
            param = torus_data.m_dMajorRadius;
            param *= dscale;
            *conicid += 1;
            *hasconic = 1;
            msh_SurfMeshSetConic(surfmesh, *conicid, SURFMESH_CONIC_TORUS, sense, xo, ax, dr, radius, param);
            A3DSurfTorusGet(NULL, &torus_data);
        }
            if (isPrintEnabled) {
                DumpTorus(surface);
            }
            break;
        case kA3DTypeSurfCone: {
            A3DSurfConeData cone_data;
            A3D_INITIALIZE_DATA(A3DSurfConeData, cone_data);
            A3DSurfConeGet(surface, &cone_data);
            VECMOVE(cone_data.m_sTrsf.m_sOrigin, xo);
            VECSCALE(xo, dscale);
            VECMOVE(cone_data.m_sTrsf.m_sXVector, dr);
            VECMOVE(cone_data.m_sTrsf.m_sYVector, dt);
            VECCROSS(dr, dt, ax);
            angler = cone_data.m_dSemiAngle;
            angle = RAD2DEG(angler);
            if (angle < 0.) {
                angle = -angle;
                angler = -angler;
                VECSCALE(ax, -1.);
            }
            radius = cone_data.m_dRadius;
            radius *= dscale;
            /* position origin at apex if radius non-zero */
            if (radius) {
                tanang = tan(angler);
                d = radius / tanang;
                rlz = 1. / sqrt(ax[0] * ax[0] + ax[1] * ax[1] + ax[2] * ax[2]);
                VECSCALE(ax, rlz);
                xo[0] -= d * ax[0];
                xo[1] -= d * ax[1];
                xo[2] -= d * ax[2];
            }
            *conicid += 1;
            *hasconic = 1;
            msh_SurfMeshSetConic(surfmesh, *conicid, SURFMESH_CONIC_CONE, sense, xo, ax, dr, angle, 0.);
            A3DSurfConeGet(NULL, &cone_data);
        }
            if (isPrintEnabled) {
                DumpCone(surface);
            }
            break;
        case kA3DTypeSurfCylinder: {
            A3DSurfCylinderData cyl_data;
            A3D_INITIALIZE_DATA(A3DSurfCylinderData, cyl_data);
            A3DSurfCylinderGet(surface, &cyl_data);
            VECMOVE(cyl_data.m_sTrsf.m_sOrigin, xo);
            VECSCALE(xo, dscale);
            VECMOVE(cyl_data.m_sTrsf.m_sXVector, dr);
            VECMOVE(cyl_data.m_sTrsf.m_sYVector, dt);
            VECCROSS(dr, dt, ax);
            radius = cyl_data.m_dRadius;
            radius *= dscale;
            *conicid += 1;
            *hasconic = 1;
            msh_SurfMeshSetConic(surfmesh, *conicid, SURFMESH_CONIC_CYLINDER, sense, xo, ax, dr, radius, 0.);
            A3DSurfCylinderGet(NULL, &cyl_data);
        }
            if (isPrintEnabled) {
                DumpCylinder(surface);
            }
            break;
        case kA3DTypeSurfPlane: {
            A3DSurfPlaneData plane_data;
            A3D_INITIALIZE_DATA(A3DSurfPlaneData, plane_data);
            A3DSurfPlaneGet(surface, &plane_data);
            VECMOVE(plane_data.m_sTrsf.m_sOrigin, xo);
            VECSCALE(xo, dscale);
            VECMOVE(plane_data.m_sTrsf.m_sXVector, dr);
            VECMOVE(plane_data.m_sTrsf.m_sYVector, dt);
            VECCROSS(dr, dt, ax);
            *conicid += 1;
            *hasconic = 1;
            msh_SurfMeshSetConic(surfmesh, *conicid, SURFMESH_CONIC_PLANE, sense, xo, ax, dr, 0., 0.);
            A3DSurfPlaneGet(NULL, &plane_data);
        }
            if (isPrintEnabled) {
                DumpPlane(surface);
            }
            break;
        default:
            break;
    }
}
/* DumpTess */
static A3DBool
DumpTessBase(A3DTessBase* tess_base, msh_SurfMesh* surfmesh)
{
    if (NULL == tess_base) {
        return A3D_FALSE;
    }

    A3DTessBaseData tess_base_data;
    A3D_INITIALIZE_DATA(A3DTessBaseData, tess_base_data);
    if (A3D_SUCCESS != A3DTessBaseGet(tess_base, &tess_base_data)) {
        return A3D_FALSE;
    }
    /* insert tesselation points */
    Vint npnt = 0;
    for (A3DUns32 n = 0; n < tess_base_data.m_uiCoordSize; n += 3) {
        npnt += 1;
        msh_SurfMeshSetPoint(surfmesh, npnt, &tess_base_data.m_pdCoords[n], 0);
    }

    if (A3D_SUCCESS != A3DTessBaseGet(NULL, &tess_base_data)) {
        return A3D_FALSE;
    }

    return A3D_TRUE;
}

std::vector<A3DTopoEdge*>
GetEdges(A3DTopoFace* face)
{
    A3DTopoFaceData face_data;
    A3D_INITIALIZE_DATA(A3DTopoFaceData, face_data);
    if (A3D_SUCCESS != A3DTopoFaceGet(face, &face_data)) {
        return std::vector<A3DTopoEdge*>();
    }

    std::vector<A3DTopoEdge*> edges;
    for (A3DUns32 lidx = 0u; lidx < face_data.m_uiLoopSize; ++lidx) {
        A3DTopoLoopData loop_data;
        A3D_INITIALIZE_DATA(A3DTopoLoopData, loop_data);
        A3DTopoLoopGet(face_data.m_ppLoops[lidx], &loop_data);
        for (A3DUns32 cidx = 0u; cidx < loop_data.m_uiCoEdgeSize; ++cidx) {
            A3DTopoCoEdgeData coedge_data;
            A3D_INITIALIZE_DATA(A3DTopoCoEdgeData, coedge_data);
            A3DTopoCoEdgeGet(loop_data.m_ppCoEdges[cidx], &coedge_data);
            edges.push_back(coedge_data.m_pEdge);
            A3DTopoCoEdgeGet(NULL, &coedge_data);
        }
        A3DTopoLoopGet(NULL, &loop_data);
    }

    if (A3D_SUCCESS != A3DTopoFaceGet(NULL, &face_data)) {
        return std::vector<A3DTopoEdge*>();
    }

    return edges;
}

static A3DBool
DumpTess3D(A3DTess3D* tess_3d, A3DTopoBrepData* topo_brep_data, std::vector<A3DTopoShell*> const& shells, A3DUns32 const n_faces,
           A3DTopoFace** topo_faces, msh_SurfMesh* surfmesh)
{
    Vint i, n;
    Vint ntri, ix[3], efl[3], nedge, ixe[2], ixs, iedge;
    Vint itri, no;
    Vint sense, conicid, hasconic;
    Vdouble vt[3][3], xs[3], ve[2][3];
    vsy_IntVHash* edgehash;
    vsy_IntVec *trinum, *trino;

    if (NULL == tess_3d) {
        return A3D_FALSE;
    }
    A3DTess3DData tess_3d_data;
    A3D_INITIALIZE_DATA(A3DTess3DData, tess_3d_data);
    if (A3D_SUCCESS != A3DTess3DGet(tess_3d, &tess_3d_data)) {
        return A3D_FALSE;
    }
    A3DTopoShellData shell_data;
    A3D_INITIALIZE_DATA(A3DTopoShellData, shell_data);
    if (!shells.empty()) {
        A3DTopoShellGet(shells[0], &shell_data);
    }
    A3DUns32 shell_idx = 1u;
    A3DUns32 face_idx_offset_for_shell = 0u;

    /* hashtable for edges */
    edgehash = vsy_IntVHashBegin();
    vsy_IntVHashDef(edgehash, 2, 100);
    /* lists of an attached tri for each edge */
    trinum = vsy_IntVecBegin();
    trino = vsy_IntVecBegin();
    /* loop through faces */
    conicid = 0;
    hasconic = 0;
    nedge = 0;
    ntri = 0;
    for (A3DUns32 idx = 0u; idx < tess_3d_data.m_uiFaceTessSize; ++idx) {
        TessFaceDataHelper h(tess_3d_data.m_psFaceTessData[idx], tess_3d_data.m_puiTriangulatedIndexes,
                             tess_3d_data.m_puiWireIndexes);
        if (isPrintEnabled) {
            printf("Face #%d\n", idx);
        }

        A3DTopoFace* topo_face = idx < n_faces ? topo_faces[idx] : NULL;
        A3DTopoFaceData face_data;
        A3D_INITIALIZE_DATA(A3DTopoFaceData, face_data);
        A3DTopoFaceGet(topo_face, &face_data);
        /* detect a conic section associated with face */
        if (!shells.empty() && idx >= (face_idx_offset_for_shell + shell_data.m_uiFaceSize)) {
            face_idx_offset_for_shell += shell_data.m_uiFaceSize;
            A3DTopoShellGet(NULL, &shell_data);
            assert(shell_idx < shells.size());
            A3DTopoShellGet(shells[shell_idx++], &shell_data);
        }

        hasconic = 0;
        if (!shells.empty()) {
            bool const face_orientation = (shell_data.m_pucOrientationWithShell[idx - face_idx_offset_for_shell] != 0);
            if (isPrintEnabled) {
                printf("Oriented with shell? %s\n", face_orientation ? "Yes" : "No");
            }
            if (face_orientation) {
                sense = 1;
            }
            else {
                sense = -1;
            }
            DumpSurface(face_data.m_pSurface, sense, &conicid, &hasconic, surfmesh);
        }
        A3DTopoFaceGet(NULL, &face_data);

        if (isPrintEnabled) {
            if (!h.vertices().empty()) {
                printf("Node indices = [");
                for (A3DUns32 nidx = 0u; nidx < h.vertices().size() - 1; ++nidx) {
                    printf("%d, ", h.vertices()[nidx]);
                }
                printf("%d]\n", h.vertices().back());
            }
            else {
                printf("No vertices. (?)\n");
            }

            if (!h.normals().empty()) {
                printf("Normal indices = [");
                for (A3DUns32 nidx = 0u; nidx < h.normals().size() - 1; ++nidx) {
                    printf("%d, ", h.normals()[nidx]);
                }
                printf("%d]\n", h.normals().back());
            }
            else {
                printf("No normals. (?)\n");
            }
        }
        /* enter triangle connectivity, associated conic section */
        for (n = 0; n < (Vint)h.vertices().size(); n += 3) {
            ntri += 1;
            ix[0] = h.vertices()[n] / 3 + 1;
            ix[1] = h.vertices()[n + 1LL] / 3 + 1;
            ix[2] = h.vertices()[n + 2LL] / 3 + 1;
            efl[0] = 0;
            efl[1] = 0;
            efl[2] = 0;
            msh_SurfMeshSetTri(surfmesh, ntri, ix, efl);
            /* enter tri edges in hash */
            for (i = 0; i < 3; i++) {
                if (ix[i] < ix[(i + 1) % 3]) {
                    ixe[0] = ix[i];
                    ixe[1] = ix[(i + 1) % 3];
                }
                else {
                    ixe[1] = ix[i];
                    ixe[0] = ix[(i + 1) % 3];
                }
                vsy_IntVHashLookup(edgehash, ixe, &iedge);
                if (iedge == 0) {
                    nedge += 1;
                    vsy_IntVHashInsert(edgehash, ixe, nedge);
                    vsy_IntVecSet(trinum, nedge, ntri);
                    vsy_IntVecSet(trino, nedge, i + 1);
                }
            }

            ix[0] = h.normals()[n];
            ix[1] = h.normals()[n + 1LL];
            ix[2] = h.normals()[n + 2LL];
            for (i = 0; i < 3; i++) {
                vt[i][0] = tess_3d_data.m_pdNormals[ix[i]];
                vt[i][1] = tess_3d_data.m_pdNormals[ix[i] + 1];
                vt[i][2] = tess_3d_data.m_pdNormals[ix[i] + 2];
            }
            msh_SurfMeshSetTriNorm(surfmesh, ntri, vt);
            if (hasconic) {
                msh_SurfMeshSetTriConic(surfmesh, ntri, conicid);
            }
        }
        /* set face index association plus 1 */
        msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOFACE, ntri, SYS_FACE, 0, idx + 1);
        std::vector<A3DTopoEdge*> topo_edges = idx < n_faces ? GetEdges(topo_faces[idx]) : std::vector<A3DTopoEdge*>();

        A3DUns32 topo_edge_idx = 0u;
        for (A3DUns32 lidx = 0u; lidx < h.loops().size(); ++lidx) {
            TessFaceDataHelper::TessLoop const& loop = h.loops()[lidx];
            if (isPrintEnabled) {
                printf("Loop #%d has %ld edges.\n", lidx, (long)loop._edges.size());
            }
            for (A3DUns32 eidx = 0u; eidx < loop._edges.size(); ++eidx) {
                TessFaceDataHelper::TessEdge const& edge = loop._edges[eidx];
                if (isPrintEnabled) {
                    printf(" Edge #%d = [", eidx);
                    printf("%d (start vertex), ", edge._vertices[0]);
                    for (A3DUns32 vidx = 1u; vidx < edge._vertices.size() - 1; ++vidx) {
                        printf("%d, ", edge._vertices[vidx]);
                    }
                    printf("%d (end vertex)]\n", edge._vertices.back());
                }
                A3DTopoEdge* topo_edge = topo_edge_idx < topo_edges.size() ? topo_edges[topo_edge_idx++] : NULL;
                A3DTopoEdgeData topo_edge_data;
                A3DCrvBase const* curve = NULL;
                if (topo_edge) {
                    A3D_INITIALIZE_DATA(A3DTopoEdgeData, topo_edge_data);
                    A3DTopoEdgeGet(topo_edge, &topo_edge_data);
                    A3DTopoEdgeGetOrCompute3DCurve(topo_brep_data, topo_edge, &curve);
                }
                /* find edge, lookup triangle and edge number and preserve */
                for (n = 0; n < (Vint)edge._vertices.size() - 1; n++) {
                    ixe[0] = edge._vertices[n] / 3 + 1;
                    ixe[1] = edge._vertices[n + 1LL] / 3 + 1;
                    if (ixe[1] < ixe[0]) {
                        ixs = ixe[0];
                        ixe[0] = ixe[1];
                        ixe[1] = ixs;
                    }
                    vsy_IntVHashLookup(edgehash, ixe, &iedge);
                    if (iedge) {
                        vsy_IntVecGet(trinum, iedge, &itri);
                        vsy_IntVecGet(trino, iedge, &no);
                        msh_SurfMeshSetTriAssoc(surfmesh, VIS_GEOEDGE, itri, SYS_EDGE, no, itri);
                        Vint ixt[3], eflag[3];
                        msh_SurfMeshGetTri(surfmesh, itri, ixt, eflag);
                        for (i = 0; i < 3; i++) {
                            if (ixt[i] == ixe[0] && ixt[(i + 1) % 3] == ixe[1]) {
                            }
                            else if (ixt[i] == ixe[1] && ixt[(i + 1) % 3] == ixe[0]) {
                                ixs = ixe[0];
                                ixe[0] = ixe[1];
                                ixe[1] = ixs;
                            }
                        }
                        /* compute tangents */
#define EXAM52HE_TANGENTS
#ifdef EXAM52HE_TANGENTS
                        if (curve) {
                            Vint pflag;
                            A3DVector3dData pnt, eval_result[2];
                            A3DUns32 puiNbSol;
                            A3DDouble *ppdSolParameter, *ppdSolDistance;
                            for (i = 0; i < 2; i++) {
                                msh_SurfMeshGetPoint(surfmesh, ixe[i], xs, &pflag);
                                xs[0] /= dscale;
                                xs[1] /= dscale;
                                xs[2] /= dscale;
                                VECLOAD(xs, pnt);
                                A3DCrvProjectPoint(curve, &pnt, &puiNbSol, &ppdSolParameter, &ppdSolDistance);
                                /* GHF */
                                if (*ppdSolDistance > .1) {
                                    printf("ixe= %d, ppdSolDistance= %f\n", ixe[i], *ppdSolDistance);
                                    exit(0);
                                }
                                A3D_INITIALIZE_ARRAY_DATA(A3DVector3dData, eval_result, 2);
                                A3DCrvEvaluate(curve, ppdSolParameter[0], 1, eval_result);
                                A3DCrvProjectPoint(NULL, &pnt, &puiNbSol, &ppdSolParameter, &ppdSolDistance);
                                VECMOVE(eval_result[1], ve[i]);
                            }
                            msh_SurfMeshSetTriTang(surfmesh, itri, no, ve);
                        }
#endif
                    }
                }
                /* preserve edge endpoints */
                ixs = edge._vertices[0] / 3 + 1;
                msh_SurfMeshSetPointAssoc(surfmesh, VIS_GEOVERT, ixs, ixs);
                ixs = edge._vertices[edge._vertices.size() - 1] / 3 + 1;
                msh_SurfMeshSetPointAssoc(surfmesh, VIS_GEOVERT, ixs, ixs);
            }
        }
    }
    /* delete objects */
    vsy_IntVHashEnd(edgehash);
    vsy_IntVecEnd(trinum);
    vsy_IntVecEnd(trino);

    if (!shells.empty()) {
        A3DTopoShellGet(NULL, &shell_data);
    }
    if (A3D_SUCCESS != A3DTess3DGet(NULL, &tess_3d_data)) {
        return A3D_FALSE;
    }
    return A3D_TRUE;
}

std::vector<A3DTopoShell*>
getShells(A3DTopoBrepData* topo_brep_data)
{
    std::vector<A3DTopoShell*> result;
    A3DTopoBrepDataData brep_data_data;
    A3D_INITIALIZE_DATA(A3DTopoBrepDataData, brep_data_data);
    A3DTopoBrepDataGet(topo_brep_data, &brep_data_data);
    for (A3DUns32 idx = 0u; idx < brep_data_data.m_uiConnexSize; ++idx) {
        A3DTopoConnexData connex_data;
        A3D_INITIALIZE_DATA(A3DTopoConnexData, connex_data);
        A3DTopoConnexGet(brep_data_data.m_ppConnexes[idx], &connex_data);
        std::copy(connex_data.m_ppShells, connex_data.m_ppShells + connex_data.m_uiShellSize, std::back_inserter(result));
        A3DTopoConnexGet(NULL, &connex_data);
    }
    A3DTopoBrepDataGet(NULL, &brep_data_data);
    return result;
}

A3DBool
DumpIndexedMesh(A3DRiRepresentationItem* ri, vis_Connect* connect)
{
    Vint numpnts, numtris;
    Vint solidflag = 0;
    msh_SurfMesh* surfmesh;

    A3DRiRepresentationItemData ri_data;
    A3D_INITIALIZE_DATA(A3DRiRepresentationItemData, ri_data);
    if (A3D_SUCCESS != A3DRiRepresentationItemGet(ri, &ri_data)) {
        return A3D_FALSE;
    }
    /* instance SurfMesh object */
    surfmesh = msh_SurfMeshBegin();
    /* count coords to get number of points */
    A3DTessBase* tess_base = ri_data.m_pTessBase;
    A3DTessBaseData tess_base_data;
    A3D_INITIALIZE_DATA(A3DTessBaseData, tess_base_data);
    if (A3D_SUCCESS != A3DTessBaseGet(tess_base, &tess_base_data)) {
        return A3D_FALSE;
    }
    numpnts = tess_base_data.m_uiCoordSize / 3;
    A3DTessBaseGet(NULL, &tess_base_data);

    if (A3D_SUCCESS != A3DRiRepresentationItemGet(NULL, &ri_data)) {
        return A3D_FALSE;
    }
    A3DEEntityType entity_type = GetEntityType(tess_base);
    if (kA3DTypeTess3D != entity_type) {
        return A3D_FALSE;
    }

    A3DTopoBrepData* topo_brep_data = NULL;
    if (kA3DTypeRiBrepModel == GetEntityType(ri)) {
        A3DRiBrepModelData ri_brep_model_data;
        A3D_INITIALIZE_DATA(A3DRiBrepModelData, ri_brep_model_data);
        A3DRiBrepModelGet(ri, &ri_brep_model_data);
        topo_brep_data = ri_brep_model_data.m_pBrepData;
        /* set solid flag, if solid attempt a tetmesh */
        solidflag = ri_brep_model_data.m_bSolid;
        A3DRiBrepModelGet(NULL, &ri_brep_model_data);
    }

    A3DTopoBodyData topo_body_data;
    A3D_INITIALIZE_DATA(A3DTopoBodyData, topo_body_data);
    A3DTopoBodyGet(topo_brep_data, &topo_body_data);
    A3DTopoContext* topo_context = topo_body_data.m_pContext;
    A3DTopoBodyGet(NULL, &topo_body_data);

    A3DTopoContextData topo_context_data;
    A3D_INITIALIZE_DATA(A3DTopoContextData, topo_context_data);
    A3DTopoContextGet(topo_context, &topo_context_data);
    if (topo_context_data.m_bHaveScale) {
        if (isPrintEnabled) {
            printf("Topo Context Scale: %f\n", topo_context_data.m_dScale);
            printf("This scale must be applied to all surface/curve definitions (no tessellation).\n");
        }
        dscale = topo_context_data.m_dScale;
    }
    A3DTopoContextGet(NULL, &topo_context_data);

    A3DUns32 n_faces = 0u;
    A3DTopoFace** faces = NULL;
    A3DTopoBrepDataGetFaces(topo_brep_data, &n_faces, &faces);
    if (n_faces == 0) {
        printf("Input file does not contain B-Rep Geometry.\n");
    }
    /* count triangles */
    A3DTess3DData tess_3d_data;
    A3D_INITIALIZE_DATA(A3DTess3DData, tess_3d_data);
    if (A3D_SUCCESS != A3DTess3DGet(tess_base, &tess_3d_data)) {
        return A3D_FALSE;
    }
    numtris = 0;
    for (A3DUns32 idx = 0u; idx < tess_3d_data.m_uiFaceTessSize; ++idx) {
        TessFaceDataHelper h(tess_3d_data.m_psFaceTessData[idx], tess_3d_data.m_puiTriangulatedIndexes,
                             tess_3d_data.m_puiWireIndexes);
        A3DTopoFace* topo_face = idx < n_faces ? faces[idx] : NULL;
        A3DTopoFaceData face_data;
        A3D_INITIALIZE_DATA(A3DTopoFaceData, face_data);
        A3DTopoFaceGet(topo_face, &face_data);
        A3DTopoFaceGet(NULL, &face_data);
        numtris += (Vint)h.vertices().size() / 3;
    }
    printf("Number of tesselation points=    %d\n", numpnts);
    printf("Number of tesselation triangles= %d\n", numtris);
    msh_SurfMeshDef(surfmesh, numpnts, numtris);
    /* load point coordinates */
    DumpTessBase(tess_base, surfmesh);

    std::vector<A3DTopoShell*> shells = getShells(topo_brep_data);
    /* load tesselation and geometry data */
    DumpTess3D(tess_base, topo_brep_data, shells, n_faces, faces, surfmesh);
    A3DTess3DGet(NULL, &tess_3d_data);
    /* get internal Connect object to compute extent */
    /* used only to get a reasonable target element size */
    Vdouble extent[2][3], dv[3], dl, edgelen, minedgelen;
    Vint maxi;
    Vint numsurfpnts, numsurftris;
    Vint numtetpnts, numtets;
    vis_Connect* connectint;
    vis_Connect* connectsurf;

    /* compute extent */
    msh_SurfMeshGetConnect(surfmesh, &connectint);
    vis_ConnectExtentdv(connectint, NULL, extent);
    dv[0] = extent[1][0] - extent[0][0];
    dv[1] = extent[1][1] - extent[0][1];
    dv[2] = extent[1][2] - extent[0][2];
    dl = sqrt(dv[0] * dv[0] + dv[1] * dv[1] + dv[2] * dv[2]);
    /* set target edge length to .05 of diagonal length */
    edgelen = .05 * dl;
    minedgelen = .2 * edgelen;
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_EDGELENGTH, edgelen);
    msh_SurfMeshSetParamd(surfmesh, VIS_MESH_MINEDGELENGTH, minedgelen);
    /* generate parabolic elements */
    maxi = 3;
    msh_SurfMeshSetParami(surfmesh, VIS_MESH_MAXI, maxi);
    /* try to mate possible free faces */
    msh_SurfMeshSetParami(surfmesh, SURFMESH_MATE, SURFMESH_MATE_FREE);
    /* generate */
#define EXAM52HE_MESH
#ifdef EXAM52HE_MESH
    msh_SurfMeshWrite(surfmesh, SYS_ASCII, "exam52HE.srf");
    /* instance Connect object for surface mesh, and generate */
    connectsurf = vis_ConnectBegin();
    vis_ConnectPre(connectsurf, SYS_DOUBLE);
    msh_SurfMeshGenerate(surfmesh, connectsurf);
    if (msh_SurfMeshError(surfmesh)) {
        printf("surf mesh generation error\n");
        return 0;
    }
    else {
        printf("surf mesh generation complete\n");
    }
    /* print number of surface nodes and elements */
    vis_ConnectNumber(connectsurf, SYS_NODE, &numsurfpnts);
    vis_ConnectNumber(connectsurf, SYS_ELEM, &numsurftris);
    printf(" Number of nodes= %d\n", numsurfpnts);
    printf(" Number of tris = %d\n", numsurftris);
    /* write to a Nastran bulk data file */
    vis_ConnectWrite(connectsurf, SYS_NASTRAN_BULKDATA, "exam52HEsurf.bdf");
    msh_SurfMeshEnd(surfmesh);
    /* now attempt a tet mesh if a solid */
    if (solidflag) {
        msh_TetMesh* tetmesh;
        vis_Connect* connecttet;
        /* create TetMesh object */
        tetmesh = msh_TetMeshBegin();
        msh_TetMeshDef(tetmesh, numsurfpnts, numsurftris, maxi);
        /* Fill TetMesh object with generated points on surface */
        msh_TetMeshConnect(tetmesh, connectsurf);
        /* set mesh parameters */
        msh_TetMeshSetParami(tetmesh, VIS_MESH_MAXI, maxi);
        msh_TetMeshSetParamd(tetmesh, VIS_MESH_EDGELENGTH, edgelen);
        /* create Connect object to hold generated tet mesh */
        connecttet = vis_ConnectBegin();
        vis_ConnectPre(connecttet, SYS_DOUBLE);
        /* generate mesh */
        msh_TetMeshGenerate(tetmesh, connecttet);
        if (msh_TetMeshError(tetmesh)) {
            printf("tet mesh generation error\n");
            return 0;
            /* GHF
                     exit(1);
            */
        }
        else {
            printf("tet mesh generation complete\n");
        }
        vis_ConnectNumber(connecttet, SYS_NODE, &numtetpnts);
        vis_ConnectNumber(connecttet, SYS_ELEM, &numtets);
        printf(" Number of nodes= %d\n", numtetpnts);
        printf(" Number of tets = %d\n", numtets);
        /* write generated tet mesh in NASTRAN bulk data format */
        vis_ConnectWrite(connecttet, SYS_NASTRAN_BULKDATA, "exam52HEtet.bdf");
        vis_ConnectAppend(connect, connecttet);
        vis_ConnectEnd(connecttet);
        msh_TetMeshEnd(tetmesh);
    }
    else {
        vis_ConnectAppend(connect, connectsurf);
    }
    vis_ConnectEnd(connectsurf);

#else
    msh_SurfMeshEnd(surfmesh);
#endif

    A3DTopoBrepDataGetFaces(NULL, &n_faces, &faces);
    n_faces = 0u;
    faces = NULL;

    return A3D_TRUE;
}

A3DBool
RepresentationItemCallback(A3DEntityArray entities, vis_Connect* connect);

/* the location of HOOPS exchange libraries */
/* can be overridden on the command line */
#ifdef VKI_LIBAPI_HOOPS_BINARIES
static char excfld[] = VKI_LIBAPI_HOOPS_BINARIES;
#else
static char excfld[] = "";
#endif

int
example52HE::run_example52HE(int argc, char* argv[])
{
    char const* exchange_folder = excfld;
    char const* input_file = NULL;
    for (int idx = 1; idx < argc; ++idx) {
        if (0 == strcmp("--exchange", argv[idx]) && idx + 1 <= argc - 1) {
            exchange_folder = argv[++idx];
            continue;
        }
        else if (NULL != input_file) {
            printf("Unrecognized command line argument: %s\n", argv[idx]);
            return -1;
        }
        else {
            input_file = argv[idx];
        }
    }

    if (NULL == exchange_folder) {
        printf("Provide the locations of the Exchange libraries use: --exchange.\n");
        return -1;
    }
    if (NULL == input_file) {
        printf("Provide the input file as an argument.\n");
        return -1;
    }
    A3DBool const exchange_loaded = A3DSDKLoadLibrary(exchange_folder);
    if (!exchange_loaded) {
        printf("Unable to load exchange libraries from the folder \"%s\"\n", exchange_folder);
        return -1;
    }

    A3DStatus const license_result = A3DLicPutUnifiedLicense(hoopsLicense.c_str());
    if (license_result != A3D_SUCCESS) {
        printf("Unable to unlock exchange using the current license.\n");
        return -1;
    }

    A3DStatus const initialize_result = A3DDllInitialize(A3D_DLL_MAJORVERSION, A3D_DLL_MINORVERSION);
    if (initialize_result != A3D_SUCCESS) {
        printf("Unable to initilize exchange due to library version mismatch.\n");
        return -1;
    }
    A3DRWParamsLoadData load_options;
    A3D_INITIALIZE_DATA(A3DRWParamsLoadData, load_options);

    /* load tesselations for solids and surfaces */
    load_options.m_sGeneral.m_bReadSolids = true;
    load_options.m_sGeneral.m_bReadSurfaces = true;
    load_options.m_sGeneral.m_eReadGeomTessMode = kA3DReadGeomAndTess;

    // tessellation options
    load_options.m_sTessellation.m_bAccurateTessellation = true;
    load_options.m_sTessellation.m_eTessellationLevelOfDetail = kA3DTessLODMedium;

    A3DAsmModelFile* model_file = NULL;
    A3DStatus const load_status = A3DAsmModelFileLoadFromFile(input_file, &load_options, &model_file);
    if (load_status != A3D_SUCCESS) {
        printf("Unable to load the provided file: %s\n", A3DMiscGetErrorMsg(load_status));
        return -1;
    }
    printf("Successfully loaded input file.\n");
    printf("%s\n", input_file);
    /* instance Connect object to accumulate generated meshes */
    vis_Connect* connect;
    connect = vis_ConnectBegin();
    vis_ConnectPre(connect, SYS_DOUBLE);
    /* basic item loop */
    ForEachRepresentationItem(model_file, RepresentationItemCallback, connect);
    /* write accumulated mesh */
    vis_ConnectWrite(connect, SYS_NASTRAN_BULKDATA, "exam52HE.bdf");
    vis_ConnectEnd(connect);
    A3DStatus const unload_status = A3DAsmModelFileDelete(model_file);
    if (unload_status != A3D_SUCCESS) {
        printf("Unable to unload the model file.\n");
    }
    model_file = NULL;

    A3DDllTerminate();
#ifdef EXAM52HE_UNLOADLIBRARY
    A3DSDKUnloadLibrary();
#endif
    return 0;
}

A3DBool
RepresentationItemCallback(A3DEntityArray entities, vis_Connect* connect)
{
    for (A3DUns32 idx = 0u; idx < entities.size() - 1; ++idx) {
        /* GHF
              std::string const n = GetName( entities[idx] );
              printf( "%s, ", n.empty() ? "<unnamed>" : n.c_str() );
        */
    }
    /* GHF
       std::string const n = GetName( entities.back() );
       printf( "%s\n", n.empty() ? "<unnamed>" : n.c_str() );
    */

    A3DMatrix4x4 const n_m = ComputeNetMatrix(entities);
    if (isPrintEnabled) {
        printf("Net transform:\n");
        printf("[%f %f %f %f\n", n_m.m_adM[0], n_m.m_adM[1], n_m.m_adM[2], n_m.m_adM[3]);
        printf(" %f %f %f %f\n", n_m.m_adM[4], n_m.m_adM[5], n_m.m_adM[6], n_m.m_adM[7]);
        printf(" %f %f %f %f\n", n_m.m_adM[8], n_m.m_adM[9], n_m.m_adM[10], n_m.m_adM[11]);
        printf(" %f %f %f %f]\n", n_m.m_adM[12], n_m.m_adM[13], n_m.m_adM[14], n_m.m_adM[15]);
    }
    /* enter tesselation geometry */
    DumpIndexedMesh(entities.back(), connect);
    return A3D_TRUE;
}

#endif