#pragma once

#include "samcpp/core/base_types.h"
#include "samcpp/core/coredefs.h"
#include "samcpp/core/pimpl.h"
#include "samcpp/core/status.h"

#include <memory>

ACCESSOR_DECL

namespace cae::core {

class CoordinateSystem {
  public:
    PIMPL_MOVE_ONLY(CoordinateSystem)

    ErrorCode getErrorCode();
    Status    define(CoordinateSystemType type);
    Status    inquire(CoordinateSystemType *type);
    Status    setOriginAndZAxis(double originCoord[3], double zAxisVector[3]);
    Status    setOriginAndVectors(double originCoord[3], double xVector[3], double xyVector[3]);
    Status    setOriginAndRotationAngles(double originCoord[3], double rotationAngles[3]);
    Status    setOriginAndDirectionCosines(double originCoord[3], double directionCosines[3][3]);
    Status    setTorusRadius(double radius);
    Status    getTorusRadius(double *radius);
    Status    computeDirectionCosines(double originCoord[3], double directionCosines[3][3]);
    Status    computeRotationAngles(double originCoord[3], double rotationAngles[3]);
    Status    getDirectionCosines(double originCoord[3], double directionCosines[3][3]);
    Status    getRotationAngles(double originCoord[3], double rotationAngles[3]);
    Status    transformToLocalSystem(double globalCoord[3], double localCoord[3]);
    Status    transformToGlobalSystem(double localCoord[3], double globalCoord[3]);
    Status    transformVectorToGlobalSystem(double globalCoord[3], double localVector[3], double globalVector[3]);
    Status    transformTensorToGlobalSystem(double globalCoord[3], double localTensor[6], double globalTensor[6]);
    Status    transformMatrixToGlobalSystem(double globalCoord[3], double localMatrix[9], double globalMatrix[9]);
    Status    transformVectorToLocalSystem(double globalCoord[3], double globalVector[3], double localVector[3]);
    Status    transformTensorToLocalSystem(double globalCoord[3], double globalTensor[6], double localTensor[6]);
    Status    transformMatrixToLocalSystem(double globalCoord[3], double globalMatrix[9], double localMatrix[9]);
    Status    setId(int id);
    Status    getId(int *id);
    Status    setName(const char *name);
    Status    getName(char name[]);
    Status    print();
    Status    copy(CoordinateSystem *from);
    Status    transform(double translation[3], double rotation[3][3]);

  private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // namespace cae::core
