cmake_minimum_required(VERSION 3.21)

project(Access)
message(STATUS "Configuring ${PROJECT_NAME}...")

# Include Access source code
# ----------------------------------------------------------
set(CEE_SAMCPP_ACCESS_SOURCE_FILES 
    ${CEE_SAM_SRC_SAMCPP_ROOT}/access/datasource_cpp.cpp
    ${CEE_SAM_SRC_SAMCPP_ROOT}/access/options_cpp.cpp
    ${CEE_SAM_SRC_SAMCPP_ROOT}/access/unrecognizeddata_cpp.cpp
)

set(CEE_SAMCPP_ACCESS_PUBLIC_HEADER_FILES 
    # common includes
    ${CEE_SAM_SRC_SAMCPP_ROOT}/access/access.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/access/accessdefs.h
    # class includes
    ${CEE_SAM_SRC_SAMCPP_ROOT}/access/datasource.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/access/options.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/access/unrecognizeddata.h
)

set(CEE_SAMCPP_ACCESS_HEADER_FILES 
    ${CEE_SAMCPP_ACCESS_PUBLIC_HEADER_FILES}
    # class includes
    ${CEE_SAM_SRC_SAMCPP_ROOT}/access/private/options_decl.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/access/private/datasource_decl.h
    ${CEE_SAM_SRC_SAMCPP_ROOT}/access/private/unrecognizeddata_decl.h
)

# Remove files from Cppcheck
if (DEFINED CPP_CHECK_FLAG)
    message(STATUS " - Removing some files for cppcheck")
endif()

# Setup project
# ----------------------------------------------------------

set(CEE_SAMCPP_ACCESS_SOURCE_FILES_TO_PARENT ${CEE_SAMCPP_ACCESS_SOURCE_FILES} PARENT_SCOPE)
set(CEE_SAM_ALL_SOURCE_FILES ${CEE_SAM_ALL_SOURCE_FILES} ${CEE_SAMCPP_ACCESS_SOURCE_FILES} PARENT_SCOPE)
set(CEE_SAMCPP_ACCESS_PUBLIC_HEADER_FILES ${CEE_SAMCPP_ACCESS_PUBLIC_HEADER_FILES} PARENT_SCOPE)
set(CEE_SAMCPP_ACCESS_HEADER_FILES ${CEE_SAMCPP_ACCESS_HEADER_FILES} PARENT_SCOPE)
set(CEE_SAM_ALL_HEADER_FILES ${CEE_SAM_ALL_HEADER_FILES} ${CEE_SAMCPP_ACCESS_HEADER_FILES} PARENT_SCOPE)
