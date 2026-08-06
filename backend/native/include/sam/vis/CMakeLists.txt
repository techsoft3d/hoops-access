cmake_minimum_required(VERSION 3.21)

project(VisTools)
message(STATUS "Configuring ${PROJECT_NAME}...")


# Include Vis source code
# ----------------------------------------------------------
set(CEE_SAM_VISDATA_SOURCE_FILES
    ${CEE_SAM_SRC_SAM_ROOT}/vis/assoc.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/asurf.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/bandopt.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/beamsectcalculator.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/chash.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/connect.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/coordsys.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/cpair.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/dataint.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/elemchk.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/elemdat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/eprop.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/geomfun.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/gprop.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/gridfun.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/group.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/history.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/icase.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/idtran.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/lcase.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/massprp.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/mcase.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/meshcon.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/meshsize.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/meshmetric.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/model.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/modelchk.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/mprop.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/pntloc.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/range.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/rbody.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/rcase.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/redmat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/resultInformation.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/rprop.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/space.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/sprop.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/state.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/sysmat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/tcurve.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/units.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/uprop.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/visshar.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/visutil.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/zstate.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/connectPartitionner.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/writerfun.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/resultmetadata.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/resultMetadataImpl.cpp
)

set(CEE_SAM_VISWRITER_SOURCE_FILES
    ${CEE_SAM_SRC_SAM_ROOT}/vis/writers/abafwt.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/writers/ansfwt.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/writers/d3dfwt.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/writers/fluentlwt.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/writers/nasfwt.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/writers/objfwt.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/writers/patlwt.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/writers/rasfwt.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/writers/sdrclwt.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vis/writers/stlfwt.cpp
)

set(CEE_SAM_VISMESH_SOURCE_FILES
    ${CEE_SAM_SRC_SAM_ROOT}/vis/trianglegeneration.cpp
)

set(CEE_SAM_VIS_PUBLIC_HEADER_FILES 
    ${CEE_SAM_SRC_SAM_ROOT}/vis/assoc.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/asurf.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/asurfdefs.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/bandopt.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/beamsectcalculator.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/chash.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/connect.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/connectdefs.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/coordsys.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/cpair.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/cpairdefs.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/dataint.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/elemchk.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/elemdat.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/elemdatdefs.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/eprop.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/epropdefs.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/geomfun.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/gprop.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/gpropdefs.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/gridfun.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/gridfundefs.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/group.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/groupdefs.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/history.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/icase.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/icasedefs.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/idtran.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/idtrandefs.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/lcase.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/lcasedefs.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/massprp.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/mcase.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/mcasedefs.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/meshcon.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/meshmetric.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/meshsize.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/model.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/modelchk.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/mprop.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/mpropdefs.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/pntloc.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/range.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/rbody.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/rbodydefs.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/rcase.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/rcasedefs.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/redmat.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/resultInformation.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/resultmetadata.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/rprop.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/space.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/sprop.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/spropdefs.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/state.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/statedefs.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/sysmat.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/tcurve.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/tcurvedefs.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/trianglegeneration.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/units.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/unitsdefs.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/uprop.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/vis.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/visdata.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/visdefs.h  
    ${CEE_SAM_SRC_SAM_ROOT}/vis/visshar.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/visutil.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/writerfun.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/zstate.h
)

set(CEE_SAM_VIS_HEADER_FILES 
    ${CEE_SAM_VIS_PUBLIC_HEADER_FILES}
    ${CEE_SAM_SRC_SAM_ROOT}/vis/connectPartitionner.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/writers/abafwt.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/writers/ansfwt.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/writers/d3dfwt.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/writers/fluentlwt.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/writers/nasfwt.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/writers/objfwt.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/writers/patlwt.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/writers/rasfwt.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/resultMetadataImpl.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/writers/sdrclwt.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/writers/stlfwt.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/writers/visansfwt.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/writers/visd3dfwt.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/writers/visnasfwt.h
    ${CEE_SAM_SRC_SAM_ROOT}/vis/writers/vispamfwt.h
)

set(CEE_SAM_VIS_SOURCE_FILES ${CEE_SAM_VISDATA_SOURCE_FILES} ${CEE_SAM_VISWRITER_SOURCE_FILES} ${CEE_SAM_VISMESH_SOURCE_FILES})

# Include C++ interface
# ----------------------------------------------------------
set(CEE_SAM_VIS_SOURCE_CPLUSPLUS_FILES_FILTER cplusplus/*.cxx)
file(GLOB CEE_SAM_VIS_SOURCE_CPLUSPLUS_FILES ${CEE_SAM_VIS_SOURCE_CPLUSPLUS_FILES_FILTER})
list(APPEND CEE_SAM_VIS_SOURCE_FILES ${CEE_SAM_VIS_SOURCE_CPLUSPLUS_FILES})

# Include Fortran interface
# ----------------------------------------------------------
if(CEE_SAM_INTERFACE_FORTRAN)
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/fortran/)
        message(STATUS " - Adding Fortran interface")
        set(CEE_SAM_VIS_SOURCE_FORTRAN_FILES_FILTER fortran/*.c)
    else()
        message(WARNING " - Fortran interface files does not exist")
    endif()
endif()

# Include C# interface
# ----------------------------------------------------------
if(CEE_SAM_INTERFACE_CSHARP)
    # Create csharp folder
    set(CEE_SAM_VIS_CS_FOLDER ${CEE_SAM_SRC_SAM_ROOT}/vis/csharp)
    if (NOT EXISTS ${CEE_SAM_VIS_CS_FOLDER})
        file(MAKE_DIRECTORY ${CEE_SAM_VIS_CS_FOLDER})
    endif()
    
    # Get cs file
    if(EXISTS ${CEE_SAM_VIS_CS_FOLDER})
        message(STATUS " - Adding C# interface")
        set(CEE_SAM_VIS_SOURCE_CS_FILE ${CEE_SAM_VIS_CS_FOLDER}/vis.cs)
        if (NOT EXISTS ${CEE_SAM_VIS_SOURCE_CS_FILE})
            file(TOUCH "${CEE_SAM_VIS_SOURCE_CS_FILE}")
        endif()
        if (NOT EXISTS ${CEE_SAM_VIS_SOURCE_CS_FILE})
            message(FATAL_ERROR "Unable to create csharp file ${CEE_SAM_VIS_SOURCE_CS_FILE}!")
        endif()
    else()
        message(WARNING " - C# interface files does not exist")
    endif()
endif()

# Include example programs
# ----------------------------------------------------------
if(CEE_SAM_EXAMPLES)
    if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/exam/CMakeLists.txt")
        message(STATUS " - Adding example programs")
        add_subdirectory(exam)
    endif()
endif()


# Include qual programs
# ----------------------------------------------------------
if(CEE_SAM_QUAL)
    if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/qual/CMakeLists.txt")
        message(STATUS " - Adding qual programs")
        add_subdirectory(qual)
    endif()
endif()


# Include test programs
# ----------------------------------------------------------
if(CEE_SAM_TEST)
    if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test/CMakeLists.txt")
        message(STATUS " - Adding test programs")
        add_subdirectory(test)
    endif()
endif()


# Setup project
# ----------------------------------------------------------
set(CEE_SAM_VIS_SOURCE_FILES_TO_PARENT ${CEE_SAM_VIS_SOURCE_FILES} PARENT_SCOPE)
set(CEE_SAM_VISDATA_SOURCE_FILES_TO_PARENT ${CEE_SAM_VISDATA_SOURCE_FILES} PARENT_SCOPE)
set(CEE_SAM_VISWRITER_SOURCE_FILES_TO_PARENT ${CEE_SAM_VISWRITER_SOURCE_FILES} PARENT_SCOPE)
set(CEE_SAM_VISMESH_SOURCE_FILES_TO_PARENT ${CEE_SAM_VISMESH_SOURCE_FILES} PARENT_SCOPE)
set(CEE_SAM_ALL_SOURCE_FILES ${CEE_SAM_ALL_SOURCE_FILES} ${CEE_SAM_VIS_SOURCE_FILES} PARENT_SCOPE)
set(CEE_SAM_VIS_PUBLIC_HEADER_FILES ${CEE_SAM_VIS_PUBLIC_HEADER_FILES} PARENT_SCOPE)
set(CEE_SAM_VIS_HEADER_FILES ${CEE_SAM_VIS_HEADER_FILES} PARENT_SCOPE)
set(CEE_SAM_ALL_HEADER_FILES ${CEE_SAM_ALL_HEADER_FILES} ${CEE_SAM_VIS_HEADER_FILES} PARENT_SCOPE)

if(CEE_SAM_INTERFACE_FORTRAN)
    file(GLOB CEE_SAM_VIS_SOURCE_FORTRAN_FILES ${CEE_SAM_VIS_SOURCE_FORTRAN_FILES_FILTER})
    set(CEE_SAM_ALL_SOURCE_FORTRAN_FILES ${CEE_SAM_ALL_SOURCE_FORTRAN_FILES} ${CEE_SAM_VIS_SOURCE_FORTRAN_FILES} PARENT_SCOPE)
endif()

if(CEE_SAM_INTERFACE_CSHARP)
    set(CEE_SAM_ALL_SOURCE_CS_FILES ${CEE_SAM_ALL_SOURCE_CS_FILES} ${CEE_SAM_VIS_SOURCE_CS_FILE} PARENT_SCOPE)
endif()
