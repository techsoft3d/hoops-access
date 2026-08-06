#pragma once

#include "samcpp/access/accessdefs.h"
#include "samcpp/core/base_types.h"
#include "samcpp/core/coredefs.h"
#include "samcpp/core/pimpl.h"
#include "samcpp/core/pointer.h"
#include "samcpp/core/status.h"

#include <memory>

ACCESSOR_DECL

namespace cae::access {

class DataSource {
  public:
    /// Integer parameters of DataSource.
    enum class IntegerParameter {
        NONZERO = LMAN_NONZERO,                              ///< List only dataset columns that contain at least one non-zero entry.
        INDEXSTART = LMAN_INDEXSTART,                        ///< First 1-based dataset column included when printing dataset contents.
        INDEXSTOP = LMAN_INDEXSTOP,                          ///< Last 1-based dataset column included when printing dataset contents.
        VERBOSE = LMAN_VERBOSE,                              ///< Table of contents verbosity. Default to:  \enumref2{OFF,cae::core::Flag::OFF}
        SAVEMODEL_PRECISION = LMAN_SAVEMODEL_PRE,            ///< Precision option for model.
        FOCUSCONN = LMAN_FOCUSCONN,                          ///< Convert FOCUS element connectivity. Default to:  \enumref2{OFF,cae::core::Flag::OFF}
        NODATAVALUE = LMAN_NODATAVAL,                        ///< Flag undefined result data. Default to:  \enumref2{ON,cae::core::Flag::ON}
        RETAINMESH = LMAN_RETAINCONNECT,                     ///< Retain and reuse Mesh. Default to:  \enumref2{OFF,cae::core::Flag::OFF}
        LOADRESULT_PRECISION = LMAN_LOADRESULT_PRE,          ///< State precision for loadState. Default to:  \enumref2{FLOAT,cae::core::DataType::FLOAT}
        LOADMODEL_LOAD = LMAN_LOADMODEL_LOAD,                ///< Load all loads. Default to:  \enumref2{ON,cae::core::Flag::ON}
        LOADMODEL_RESTRAINS = LMAN_LOADMODEL_REST,           ///< Load all restraints and multipoint constraints. Default to:  \enumref2{ON,cae::core::Flag::ON}
        LOADMODEL_ELEMENTGEOMETRY = LMAN_LOADMODEL_ELEMGEOM, ///< Load shell/beam geometry. Default to:  \enumref2{ON,cae::core::Flag::ON}
        LOADMODEL_SET = LMAN_LOADMODEL_SET,                  ///< Load node, element, and entity sets. Default to:  \enumref2{ON,cae::core::Flag::ON}
        SAVEMODEL_CASE = LMAN_SAVEMODEL_CASE,                ///< Wrap saved model data in per-case containers ("Case n").
        SAVERESULT_CASE = LMAN_SAVERESULT_CASE,              ///< When saving states, add case/mode containers based on the result identifiers.
        SAVERESULT_PRECISION = LMAN_SAVERESULT_PRE,          ///< Precision option for results while saving.
        LOADMODEL_PRECISION = LMAN_LOADMODEL_PRE,            ///< Precision option for mesh data when loading models.
        CHECK = LMAN_CHECK,                                  ///< With nodata detection enabled, emit undefined entries while loading states.
        LOADMODEL_STORE = LMAN_LOADMODEL_STORE               ///< Store the loaded model. Default to:  \enumref2{ON,cae::core::Flag::ON}
    };

    /// Mesh traversal operations for changing the active mesh.
    enum class MeshTraversalOperation {
        PUSH = LMAN_MESH_LIB_PUSH, ///< Change to child mesh
        POP = LMAN_MESH_LIB_POP,   ///< Change to parent mesh
        TOP = LMAN_MESH_LIB_TOP    ///< Change to root mesh
    };

    PIMPL_MOVE_ONLY(DataSource)

    cae::core::ErrorCode getErrorCode();
    cae::core::Status    openFile(const char *file, Options *options);
    cae::core::Status    appendFile(const char *file);
    cae::core::Status    getStateCount(int *count);
    cae::core::Status    closeFile();
    cae::core::Status    getUnrecognizedData(UnrecognizedDataPtr &unrecognizedData);
    cae::core::Status    setIntegerParameter(IntegerParameter parameter, int value);
    cae::core::Status    exportAscii(const char *name, const char *path);
    cae::core::Status    importAscii(const char *path);
    cae::core::Status    printTableOfContents(const char *name);
    cae::core::Status    printDatasetList(const char *name);
    cae::core::Status    loadModel(cae::core::Model *model);
    cae::core::Status    saveModel(cae::core::Model *model);
    cae::core::Status    loadState(const char *stateName, cae::core::State *state);
    cae::core::Status    getStateNames(cae::core::ListPtr<char> &stateNames);
    cae::core::Status    loadStateSubset(cae::core::IdTranslator *subset, const char *stateName, cae::core::State *state);
    cae::core::Status    saveFile(const char *filename, Options *options);
    cae::core::Status    searchState(const char *stateName, int max, int stateIds[], int *num);
    cae::core::Status    searchMeshIds(int max, int idsts[], int *num);
    cae::core::Status    applyMeshTraversalOperation(MeshTraversalOperation operation, int meshId);
    cae::core::Status    getMetadata(int stateId, cae::core::ResultMetadata *metadata);
    cae::core::Status    getMetadata(const char *stateName, cae::core::ResultMetadata *metadata);
    cae::core::Status    getMesh(cae::core::MeshPtr &mesh);
    cae::core::Status    inquire(char *path, cae::core::FileFormat *type);

  private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // namespace cae::access
