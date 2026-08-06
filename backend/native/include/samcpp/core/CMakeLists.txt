cmake_minimum_required(VERSION 3.21)

project(Core)
message(STATUS "Configuring ${PROJECT_NAME}...")

# Include Core source code
# ----------------------------------------------------------
set(CEE_SAMCPP_CORE_SOURCE_FILES 
    # common includes
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/status.cpp
    # class includes
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/analyticsurface_cpp.cpp
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/mesh_cpp.cpp
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/interactionpair_cpp.cpp
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/coordinatesystem_cpp.cpp
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/elementdata_cpp.cpp
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/elementproperty_cpp.cpp
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/globalproperty_cpp.cpp
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/meshinterface_cpp.cpp
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/group_cpp.cpp
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/hashtable_cpp.cpp
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/idtranslator_cpp.cpp
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/initialconditioncase_cpp.cpp
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/inthashtable_cpp.cpp
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/intvector_cpp.cpp
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/license_cpp.cpp
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/list_cpp.cpp
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/loadcase_cpp.cpp
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/materialproperty_cpp.cpp
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/model_cpp.cpp
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/multipointconstraintcase_cpp.cpp
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/restraintcase_cpp.cpp
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/resultmetadata_cpp.cpp
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/rigidbody_cpp.cpp
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/solutionproperty_cpp.cpp
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/state_cpp.cpp
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/tablefunction_cpp.cpp
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/units_cpp.cpp
)

set(CEE_SAMCPP_CORE_PUBLIC_HEADER_FILES 
    # common includes
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/base_types.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/error.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/status.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/pimpl.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/pointer.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/core.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/coredefs.h
    # class includes
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/analyticsurface.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/mesh.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/interactionpair.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/coordinatesystem.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/elementdata.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/elementproperty.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/globalproperty.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/meshinterface.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/group.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/hashtable.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/idtranslator.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/initialconditioncase.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/inthashtable.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/intvector.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/license.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/list.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/loadcase.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/materialproperty.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/model.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/multipointconstraintcase.h 
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/restraintcase.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/resultmetadata.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/rigidbody.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/solutionproperty.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/state.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/tablefunction.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/units.h
)

set(CEE_SAMCPP_CORE_HEADER_FILES 
    ${CEE_SAMCPP_CORE_PUBLIC_HEADER_FILES}
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/private/cwrapper.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/private/accessor.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/private/private_pimpl.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/private/templateparameters.h
    # class includes
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/private/analyticsurface_decl.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/private/mesh_decl.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/private/interactionpair_decl.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/private/coordinatesystem_decl.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/private/elementdata_decl.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/private/elementproperty_decl.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/private/globalproperty_decl.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/private/meshinterface_decl.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/private/group_decl.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/private/hashtable_decl.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/private/idtranslator_decl.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/private/initialconditioncase_decl.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/private/inthashtable_decl.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/private/intvector_decl.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/private/list_decl.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/private/loadcase_decl.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/private/materialproperty_decl.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/private/model_decl.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/private/multipointconstraintcase_decl.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/private/restraintcase_decl.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/private/resultmetadata_decl.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/private/rigidbody_decl.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/private/solutionproperty_decl.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/private/state_decl.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/private/tablefunction_decl.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/core/private/units_decl.h
)

# Remove files from Cppcheck
if (DEFINED CPP_CHECK_FLAG)
    message(STATUS " - Removing some files for cppcheck")
endif()

# Setup project
# ----------------------------------------------------------

set(CEE_SAMCPP_CORE_SOURCE_FILES_TO_PARENT ${CEE_SAMCPP_CORE_SOURCE_FILES} PARENT_SCOPE)
set(CEE_SAM_ALL_SOURCE_FILES ${CEE_SAM_ALL_SOURCE_FILES} ${CEE_SAMCPP_CORE_SOURCE_FILES} PARENT_SCOPE)
set(CEE_SAMCPP_CORE_PUBLIC_HEADER_FILES ${CEE_SAMCPP_CORE_PUBLIC_HEADER_FILES} PARENT_SCOPE)
set(CEE_SAMCPP_CORE_HEADER_FILES ${CEE_SAMCPP_CORE_HEADER_FILES} PARENT_SCOPE)
set(CEE_SAM_ALL_HEADER_FILES ${CEE_SAM_ALL_HEADER_FILES} ${CEE_SAMCPP_CORE_HEADER_FILES} PARENT_SCOPE)
