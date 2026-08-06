#pragma once

#include "samcpp/core/base_types.h"
#include "samcpp/core/coredefs.h"
#include "samcpp/core/pimpl.h"
#include "samcpp/core/status.h"

#include <memory>

ACCESSOR_DECL

namespace cae::core {

class LoadCase {
  public:
    PIMPL_MOVE_ONLY(LoadCase)

    constexpr static int CONCENTRATED_LOAD_TYPES_COUNT = LCASE_CONC_MAX;
    constexpr static int DISTRIBUTED_LOAD_TYPES_COUNT = LCASE_DIST_MAX;
    constexpr static int ELEMENT_LOAD_TYPES_COUNT = LCASE_ELEM_MAX;

    /// Concentrated load type
    enum class ConcentratedLoadType {
        FORCE = LCASE_FORCE,   ///< Vector of applied force
        MOMENT = LCASE_MOMENT, ///< Vector of applied moment
        HEAT = LCASE_HEAT,     ///< Scalar applied heat
        TEMP = LCASE_TEMP,     ///< Scalar temperature
        SCALAR = LCASE_CSCA,   ///< Generic scalar
        VECTOR = LCASE_CVEC    ///< Generic vector
    };

    /// Distributed load type
    enum class DistributedLoadType {
        TRACTION = LCASE_TRAC,                            ///< Traction load
        PRESSURE = LCASE_PRES,                            ///< Pressure load
        TANGENTIALFORCE = LCASE_TANGFORCE,                ///< Tangential force
        TANGENTIALMOMENT = LCASE_TANGMOMENT,              ///< Tangential moment
        HEATFLUX = LCASE_HEATFLUX,                        ///< Heat flux
        HEATCONVECTION = LCASE_HEATCONV,                  ///< Heat convection
        HEATRADIATION = LCASE_HEATRAD,                    ///< Heat radiation
        MOMENT = LCASE_DMOM,                              ///< Distributed moment
        SCALAR = LCASE_DSCA,                              ///< Generic scalar
        VECTOR = LCASE_DVEC,                              ///< Generic vector
        HEATRAD_ABSORPTIVITY = LCASE_HEATRAD_ABSORPTIVITY ///< Heat radiation with absorptivity
    };

    /// Element load type
    enum class ElementLoadType {
        BODYFORCE = LCASE_ACCLELEM,     ///< Body force/acceleration load
        HEATGENERATION = LCASE_HEATELEM ///< Volumetric heat generation load
    };

    ErrorCode getErrorCode();
    Status    setMeshInterface(MeshInterface *functions);
    Status    getMeshInterface(MeshInterfacePtr &functions);
    Status    setComplexMode(ComplexMode mode);
    Status    getComplexMode(ComplexMode *mode);
    Status    hasComplexData(int *flag);
    Status    setConcentratedLoad(int nodeIndex, ConcentratedLoadType type, double values[]);
    Status    setConcentratedLoadTableIdentifier(int nodeIndex, ConcentratedLoadType type, int id[]);
    Status    getConcentratedLoadTableIdentifiersCount(ConcentratedLoadType type, int *count);
    Status    addConcentratedLoad(int nodeIndex, ConcentratedLoadType type, double values[]);
    Status    getConcentratedLoadMaxNodeIndex(ConcentratedLoadType type, int *maxNodeIndex);
    Status    initializeConcentratedLoadIterator(ConcentratedLoadType type);
    Status    nextConcentratedLoadItem(ConcentratedLoadType type, int *nodeIndex);
    Status    hasConcentratedLoad(int nodeIndex, ConcentratedLoadType type, int *flag);
    Status    getConcentratedLoadType(int nodeIndex, int *typeCount, ConcentratedLoadType types[]);
    Status    getConcentratedLoad(int nodeIndex, ConcentratedLoadType type, double values[]);
    Status    getConcentratedLoadTableIdentifier(int nodeIndex, ConcentratedLoadType type, int id[]);
    Status    setDistributedLoad(EntityType entityType, int elementIndex, int entityNumber, DistributedLoadType type, double values[]);
    Status    setDistributedLoadTableIdentifier(EntityType entityType, int elementIndex, int entityNumber, DistributedLoadType type, int id[]);
    Status    addDistributedLoad(EntityType entityType, int elementIndex, int entityNumber, DistributedLoadType type, double values[]);
    Status    getDistributedLoadMaxElementIndex(EntityType entityType, DistributedLoadType type, int *maxElementIndex);
    Status    initializeDistributedLoadIterator(EntityType entityType, DistributedLoadType type);
    Status    nextDistributedLoadItem(EntityType entityType, DistributedLoadType type, int *elementIndex);
    Status    hasDistributedLoad(EntityType entityType, int elementIndex, DistributedLoadType type, int *flags);
    int       hasDistributedLoadOnEntity(EntityType entityType, int elementIndex, DistributedLoadType type, int entityNumber);
    Status    getDistributedLoadType(EntityType entityType, int elementIndex, int entityNumber, int *typeCount, DistributedLoadType types[]);
    Status    getDistributedLoad(EntityType entityType, int elementIndex, int entityNumber, DistributedLoadType type, int elementNodeflag, double values[]);
    Status    getDistributedLoadTableIdentifier(EntityType entityType, int elementIndex, int entityNumber, DistributedLoadType type, int id[]);
    Status    setElementLoad(int elementIndex, ElementLoadType type, double values[]);
    Status    setElemTableIdentifier(int elementIndex, ElementLoadType type, int id[]);
    Status    addElementLoad(int elementIndex, ElementLoadType type, double values[]);
    Status    getElementLoadMaxIndex(ElementLoadType type, int *maxElementIndex);
    Status    initializeElementLoadIterator(ElementLoadType type);
    Status    nextElementLoadItem(ElementLoadType type, int *elementIndex);
    Status    hasElementLoad(int elementIndex, ElementLoadType type, int *flag);
    Status    getElementLoadTypes(int elementIndex, int *typeCount, ElementLoadType types[]);
    Status    getElementLoad(int elementIndex, ElementLoadType type, double values[]);
    Status    getElementLoadTableIdentifier(int elementIndex, ElementLoadType type, int id[]);
    Status    setAccelerations(double gravity[3], double centerOfRotation[3], double angularVelocity[3], double angularAcceleration[3]);
    Status    hasAccelerations(int *flag);
    Status    getAccelerations(double gravity[3], double centerOfRotation[3], double angularVelocity[3], double angularAcceleration[3]);
    Status    getConcentratedLoadNodeGroup(Group *inputNodeGroup, Group *outputNodeGroup);
    Status    getElementLoadElementGroup(Group *inputElementGroup, Group *outputElementGroup);
    Status    getDistributedLoadFaceGroup(Group *inputFaceGroup, Group *outputFaceGroup);
    Status    getDistributedLoadEdgeGroup(Group *inputEdgeGroup, Group *outputEdgeGroup);
    Status    clearConcentratedLoad(ConcentratedLoadType type);
    Status    clearDistributedLoad(DistributedLoadType type);
    Status    clearElementLoad(ElementLoadType type);
    Status    clearAccelerations();
    Status    clear();
    Status    hasLoadcaseSpecified(int *flag);
    Status    add(LoadCase *add);
    Status    setId(int id);
    Status    getId(int *id);
    Status    setName(const char *name);
    Status    getName(char name[]);
    Status    print();

  private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // namespace cae::core
