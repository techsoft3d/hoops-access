#pragma once

#include "samcpp/core/base_types.h"
#include "samcpp/core/coredefs.h"
#include "samcpp/core/pimpl.h"
#include "samcpp/core/pointer.h"
#include "samcpp/core/status.h"

#include <memory>

ACCESSOR_DECL

namespace cae::core {

class Model {
  public:
    PIMPL_MOVE_ONLY(Model)

    /// \brief Model element data properties
    enum class ElementDataType {
        THICKNESS = SYS_PROP_THICKNESS,     ///< Thickness
        OFFSET = SYS_PROP_OFFSET,           ///< Nodal scalar offset
        NORMAL = SYS_PROP_NORMAL,           ///< Normal vector
        FIBER_BOTTOM = SYS_PROP_FIBERBOT,   ///< Location of shell bottom, usually for output
        FIBER_TOP = SYS_PROP_FIBERTOP,      ///< Location of shell top, usually for output
        ELEMENT_VECTOR = SYS_PROP_ELEMVEC,  ///< Element local system orientation vector
        MATERIAL_VECTOR = SYS_PROP_MATLVEC, ///< Material local system orientation vector
        END_A_VECTOR = SYS_PROP_ENDAX,      ///< End point A position or offset vector
        END_B_VECTOR = SYS_PROP_ENDBX,      ///< End point B position or offset vector
        OFFSET_VECTOR = SYS_PROP_OFFSETVEC  ///< Nodal offset vector
    };

    ErrorCode getErrorCode();
    Status    setMesh(Mesh *mesh);
    Status    getMesh(MeshPtr &mesh);
    Status    setUnits(Units *units);
    Status    getUnits(UnitsPtr &units);
    Status    setGlobalProperties(GlobalProperty *properties);
    Status    getGlobalProperties(GlobalPropertyPtr &properties);
    Status    setCoordinateSystems(HashTable<CoordinateSystem> *coordinateSystems);
    Status    getCoordinateSystems(HashTablePtr<CoordinateSystem> &coordinateSystems);
    Status    setRestraintCases(HashTable<RestraintCase> *restraintCases);
    Status    getRestraintCases(HashTablePtr<RestraintCase> &restraintCases);
    Status    setMultipointConstraintCases(HashTable<MultipointConstraintCase> *multipointConstraintCases);
    Status    getMultipointConstraintCases(HashTablePtr<MultipointConstraintCase> &multipointConstraintCases);
    Status    setLoadCases(HashTable<LoadCase> *loadCases);
    Status    getLoadCases(HashTablePtr<LoadCase> &loadCases);
    Status    setInitialConditionCases(HashTable<InitialConditionCase> *initialConditionCases);
    Status    getInitialConditionCases(HashTablePtr<InitialConditionCase> &initialConditionCases);
    Status    setMaterialProperties(HashTable<MaterialProperty> *materialProperties);
    Status    getMaterialProperties(HashTablePtr<MaterialProperty> &materialProperties);
    Status    setElementProperties(HashTable<ElementProperty> *elementProperties);
    Status    getElementProperties(HashTablePtr<ElementProperty> &elementProperties);
    Status    setTableFunctions(HashTable<TableFunction> *tableFunctions);
    Status    getTableFunctions(HashTablePtr<TableFunction> &tableFunctions);
    Status    setElementData(HashTable<ElementData> *elementData);
    Status    getElementData(HashTablePtr<ElementData> &elementData);
    Status    setNodeSets(HashTable<IdTranslator> *nodeSets);
    Status    getNodeSets(HashTablePtr<IdTranslator> &nodeSets);
    Status    setElementSets(HashTable<IdTranslator> *elementSets);
    Status    getElementSets(HashTablePtr<IdTranslator> &elementSets);
    Status    setElementEntitySets(HashTable<IdTranslator> *elementEntitySets);
    Status    getElementEntitySets(HashTablePtr<IdTranslator> &elementEntitySets);
    Status    setInteractionPairs(HashTable<InteractionPair> *interactionPairs);
    Status    getInteractionPairs(HashTablePtr<InteractionPair> &interactionPairs);
    Status    setRigidBodies(HashTable<RigidBody> *rigidBodies);
    Status    getRigidBodies(HashTablePtr<RigidBody> &rigidBodies);
    Status    setAnalyticSurfaces(HashTable<AnalyticSurface> *analyticSurfaces);
    Status    getAnalyticSurfaces(HashTablePtr<AnalyticSurface> &analyticSurfaces);
    Status    setSolutionPropertiesList(List<SolutionProperty> *propertyList);
    Status    getSolutionPropertiesList(ListPtr<SolutionProperty> &propertyList);
    Status    setMeshInterface(MeshInterface *functions);
    Status    getMeshInterface(MeshInterfacePtr &functions);
    Status    setSourceType(FileFormat libraryType);
    Status    getSourceType(FileFormat *libraryType);
    Status    write(FileFormat libraryType, const char *path);
    Status    deleteStorage();
    Status    print();
    Status    printSummary();
    Status    getElementThickness(int id, double thickness[]);
    Status    getElementOffset(int id, double offset[]);

  private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // namespace cae::core
