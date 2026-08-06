cmake_minimum_required(VERSION 3.21)

project(${PROJECT_NAME}Examples)


# Setup projects
# ----------------------------------------------------------
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# CMP0057 Allows use of IN_LIST operator
cmake_policy(SET CMP0057 NEW)


### VISUALIZATION EXAMPLES, USING VGL or not 

set(CEE_SAM_VIS_EXAMPLES_NO_VGL
    exam17.cpp
    exam38avdm.cpp
    exam38bvdm.cpp
    exam38cvdm.cpp
    exam58vdm.cpp
)

set(CEE_SAM_VIS_EXAMPLES_VGL
    intro1.cpp
    exam1.cpp
    exam1vgl.cpp
    exam2.cpp
    exam3.cpp
    exam3a.cpp
    exam3b.cpp
    exam4.cpp
    exam4a.cpp
    exam5.cpp
    exam5a.cpp
    exam5b.cpp
    exam5c.cpp
    exam5dvgl.cpp
    exam5e.cpp
    exam5vgl.cpp
    exam5vglpar.cpp
    exam6.cpp
    exam7.cpp
    exam7a.cpp
    exam7b.cpp
    exam8.cpp
    exam8avgl.cpp
    exam9.cpp
    exam9a.cpp
    exam9b.cpp
    exam10.cpp
    exam10a.cpp
    exam10b.cpp
    exam10cvgl.cpp
    exam10vgl.cpp
    exam11.cpp
    exam11avgl.cpp
    exam12.cpp
    exam13.cpp
    exam13a.cpp
    exam13b.cpp
    exam13c.cpp
    exam13d.cpp
    exam13e.cpp
    exam13f.cpp
    exam13g.cpp
    exam14.cpp
    exam14a.cpp
    exam14b.cpp
    exam14d.cpp
    exam15avgl.cpp
    exam15vgl.cpp
    exam16.cpp
    exam16avgl.cpp
    exam16bvgl.cpp
    exam16cvgl.cpp
    exam18.cpp
    exam18a.cpp
    exam18b.cpp
    exam18c.cpp
    exam19a.cpp
    exam19vgl.cpp
    exam30.cpp
    exam30avgl.cpp
    exam30bvgl.cpp
    exam30cvgl.cpp
    exam30ddev.cpp
    exam30edev.cpp
    exam32d.cpp
    exam40vdm.cpp
    exam59vgl.cpp
)
list(APPEND CEE_SAM_VIS_EXAMPLES ${CEE_SAM_VIS_EXAMPLES_NO_VGL})
if(NOT CEE_SAM_OPTION_NOVGLTOOLS)
    list(APPEND CEE_SAM_VIS_EXAMPLES ${CEE_SAM_VIS_EXAMPLES_VGL})
endif()

### VISMODEL, VISDATA EXAMPLES
set(CEE_SAM_VISDATA_EXAMPLES_NO_VGL
    exam21.cpp
    exam22.cpp
    exam23.cpp
    exam23a.cpp
    exam23b.cpp
    exam23c.cpp
    exam23d.cpp
    exam23e.cpp
    exam24.cpp
    exam24a.cpp
    exam25.cpp
    exam25a.cpp
    exam25b.cpp
    exam25c.cpp
    exam25d.cpp
    exam25e.cpp
    exam26.cpp
    exam26a.cpp
    exam26b.cpp
    exam26c.cpp
    exam26e.cpp
    exam26f.cpp
    exam26g.cpp
    exam27.cpp
    exam28.cpp
    exam29.cpp
    exam31.cpp
    exam31a.cpp
    exam32.cpp
    exam32a.cpp
    exam32b.cpp
    exam32c.cpp
    exam33.cpp
    exam33a.cpp
    exam33b.cpp
    exam34.cpp
    exam34a.cpp
    exam35.cpp
    exam36.cpp
    exam36a.cpp
    exam37.cpp
    exam38.cpp
    exam39.cpp
    exam39a.cpp
    exam39b.cpp
    exam39c.cpp
    exam53.cpp
    exam53a.cpp
    exam54.cpp
    exam56.cpp
    exam57.cpp
)
set(CEE_SAM_VISDATA_EXAMPLES_VGL
    exam26d.cpp
    exam27a.cpp
    exam55.cpp
)
list(APPEND CEE_SAM_VISDATA_EXAMPLES ${CEE_SAM_VISDATA_EXAMPLES_NO_VGL})
if(NOT CEE_SAM_OPTION_NOVGLTOOLS)
    list(APPEND CEE_SAM_VISDATA_EXAMPLES ${CEE_SAM_VISDATA_EXAMPLES_VGL})
endif()

## MESH EXAMPLES

set(CEE_SAM_VISMESH_EXAMPLES
    exam41.cpp
    exam41a.cpp
    exam41b.cpp
    exam42.cpp
    exam42a.cpp
    exam42b.cpp
    exam42c.cpp
    exam43.cpp
    exam43a.cpp
    exam43b.cpp
    exam43c.cpp
    exam43d.cpp
    exam43e.cpp
    exam43f.cpp
    exam43g.cpp
    exam44.cpp
    exam44a.cpp
    exam44b.cpp
    exam44c.cpp
    exam44d.cpp
    exam44e.cpp
    exam45.cpp
    exam45a.cpp
    exam45b.cpp
    exam45c.cpp
    exam45d.cpp
    exam46.cpp
    exam47a.cpp
    exam47b.cpp
    exam47c.cpp
    exam47d.cpp
    exam47e.cpp
    exam47_GenerateSurfMesh.cpp
    exam47_GenerateSurfMeshParallel.cpp
    exam48.cpp
    exam48a.cpp
    exam48b.cpp
    exam48c.cpp
    exam48d.cpp
    exam48e.cpp
    exam48f.cpp
    exam48g.cpp
    exam49vdm.cpp
    exam50.cpp
    exam51.cpp
    exam60.cpp
    exam60a.cpp
    exam61.cpp
    exam61a.cpp
    exam61b.cpp
    exam62.cpp
    exam63.cpp
)

set(CEE_SAM_VIS_CS_INTERFACE_EXAMPLES
    ${CEE_SAM_SRC_SAM_ROOT}/vis/exam/intro1cs.cs
    ${CEE_SAM_SRC_SAM_ROOT}/vis/exam/exam41cs.cs
    ${CEE_SAM_SRC_SAM_ROOT}/vis/exam/exam1vglcs.cs
)

# Define sources with parasolid dependency
if(CEE_SAM_OPTION_PARASOLID)
    set(SOURCES_USING_PARASOLID exam52pk.cpp exam52ParasolidBoxes.cpp)
endif()

# Define sources with hoops dependency
if(CEE_SAM_OPTION_HOOPS)
    set(SOURCES_USING_HOOPS exam52HEmain.cpp)
endif()

set(CEE_SAM_VISMESH_THIRDPARTY_EXAMPLES
    exam52acis.cpp
    exam52capri.cpp
    exam52occ.cpp
    exam52pg.cpp
)

#--------------------------------------------------------------
# Examples testing the visData; visModel objects
#--------------------------------------------------------------
file(GLOB APP_SOURCES ${CEE_SAM_VISDATA_EXAMPLES})
foreach(appsrc ${APP_SOURCES})
    
    # Get source and target name
    get_filename_component(appsrc ${appsrc} NAME)
    get_filename_component(CEE_SAM_APP_SOURCE_BASENAME  ${appsrc} NAME_WE)
    set(appname "vis_${CEE_SAM_APP_SOURCE_BASENAME}")

    if(CEE_SAM_VERBOSE_LOGGING)
        message(STATUS "   - ${appname}")
    endif()
    
    add_executable(${appname} ${appsrc})  
    set_compile_option(${appname})
    set_sanitizer_compile_option(${appname})
    target_compile_definitions(${appname} PRIVATE ${CEE_SAM_COMPILE_DEFINITIONS})
    target_include_directories(${appname} PRIVATE ${CEE_SAM_SOURCES_INCLUDES})
    target_include_directories(${appname} PRIVATE ${CEE_SAM_INTERNAL_INCLUDES})
    target_include_directories(${appname} SYSTEM PRIVATE ${CEE_SAM_EXTERNAL_INCLUDES})
    if(CEE_SAM_PROPERTIES_LINK_FLAGS)
        target_link_options(${appname} PRIVATE ${CEE_SAM_PROPERTIES_LINK_FLAGS})
    endif()
    
    if(NOT CEE_SAM_OPTION_LINK_FROM_SAM_LIB)
        if(${CEE_SAM_BUILD_CONFIGURATION} MATCHES "Static")
            target_link_libraries(${appname} PRIVATE ${CEE_SAM_STATIC_LIBRARY_NAME})
        else()
            target_link_libraries(${appname} PRIVATE ${CEE_SAM_LIBRARY_NAME})
        endif()
        target_link_libraries(${appname} PRIVATE ${CEE_SAM_INTERNAL_LIBRARIES})
    endif()
    target_link_libraries(${appname} PRIVATE ${CEE_SAM_EXTERNAL_LIBRARIES})
    if(${CEE_SAM_BUILD_CONFIGURATION} MATCHES "Static")
        target_link_libraries(${appname} PRIVATE ${CEE_SAM_GLEW_LIBRARY})
    endif()
    set_property(TARGET ${appname} PROPERTY FOLDER "Examples/VisToolsDataExamples")
    
    if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
        target_link_libraries(${appname} PRIVATE stdc++fs Threads::Threads stdc++ ${CMAKE_DL_LIBS})
    endif()

    # Set PATH in Visual Studio and Visual Studio Code
    set_visual_studio_path(${appname})
    set_visual_studio_code_path(${appname})
    
endforeach(appsrc ${APP_SOURCES})


#--------------------------------------------------------------
# Examples testing the visMesh objects
#--------------------------------------------------------------
file(GLOB APP_SOURCES ${CEE_SAM_VISMESH_EXAMPLES} ${CEE_SAM_VISMESH_THIRDPARTY_EXAMPLES} ${SOURCES_USING_PARASOLID} ${SOURCES_USING_HOOPS})
foreach(appsrc ${APP_SOURCES})
    
    if(NOT CEE_SAM_OPTION_CAPRI)
        if("${appsrc}" MATCHES "exam52capri.cpp")
            continue()
        endif()
    endif()

    if(NOT CEE_SAM_OPTION_SPATIAL)
        if("${appsrc}" MATCHES "exam52acis.cpp")
            continue()
        endif()
    endif()

    if(NOT CEE_SAM_OPTION_OPEN_CASCADE)
        if("${appsrc}" MATCHES "exam52occ.cpp")
            continue()
        endif()
    endif()

    if(NOT CEE_SAM_OPTION_PARASOLID)
        if("${appsrc}" MATCHES "exam52pk.cpp")
            continue()
        endif()
    endif()

    if(NOT CEE_SAM_OPTION_PARASOLID)
        if("${appsrc}" MATCHES "exam52ParasolidBoxes.cpp")
            continue()
        endif()
    endif()

    if(NOT CEE_SAM_OPTION_POLYGONICA)
        if("${appsrc}" MATCHES "exam52pg.cpp")
            continue()
        endif()
    endif()

    if(NOT CEE_SAM_OPTION_HOOPS)
        if("${appsrc}" MATCHES "exam52HEmain.cpp")
            continue()
        endif()
    endif()
    
    # Get source and target name
    get_filename_component(appsrc ${appsrc} NAME)
    get_filename_component(CEE_SAM_APP_SOURCE_BASENAME  ${appsrc} NAME_WE)
    set(appname "vis_${CEE_SAM_APP_SOURCE_BASENAME}")


    if(CEE_SAM_VERBOSE_LOGGING)
        message(STATUS "   - ${appname}")
    endif()
    
    add_executable(${appname} ${appsrc})
    target_compile_definitions(${appname} PRIVATE ${CEE_SAM_COMPILE_DEFINITIONS})
    target_include_directories(${appname} PRIVATE ${CEE_SAM_SOURCES_INCLUDES})
    target_include_directories(${appname} PRIVATE ${CEE_SAM_INTERNAL_INCLUDES})
    target_include_directories(${appname} SYSTEM PRIVATE ${CEE_SAM_EXTERNAL_INCLUDES})
    set_compile_option(${appname})
    set_sanitizer_compile_option(${appname})
    if(CEE_SAM_PROPERTIES_LINK_FLAGS)
        target_link_options(${appname} PRIVATE ${CEE_SAM_PROPERTIES_LINK_FLAGS})
    endif()
    
    if(CEE_SAM_OPTION_PARASOLID AND "${appsrc}" IN_LIST SOURCES_USING_PARASOLID)
        target_link_libraries(${appname} PRIVATE ${CEE_SAM_OPTION_PARASOLID_LIBRARY})
        target_include_directories(${appname} PRIVATE ${CEE_SAM_OPTION_PARASOLID_INCLUDE_DIR})
    endif()
    
    if(CEE_SAM_OPTION_OPEN_CASCADE AND "${appsrc}" MATCHES "exam52occ.cpp")
        target_include_directories(${appname} PRIVATE ${OpenCASCADE_INCLUDE_DIR})
        target_link_libraries(${appname} PRIVATE ${OpenCASCADE_FoundationClasses_LIBRARIES} ${OpenCASCADE_ModelingData_LIBRARIES} ${OpenCASCADE_ModelingAlgorithms_LIBRARIES} ${OpenCASCADE_Visualization_LIBRARIES})
    endif()
    
    if(CEE_SAM_OPTION_HOOPS AND "${appsrc}" IN_LIST SOURCES_USING_HOOPS)
        target_compile_definitions(${appname} PRIVATE CEE_SAM_HOOPS_BINARIES="${CEE_SAM_OPTION_HOOPS_BINARY_DIR}")
        target_include_directories(${appname} PRIVATE ${CEE_SAM_OPTION_HOOPS_INCLUDE_DIR})
        target_include_directories(${appname} PRIVATE ${CEE_SAM_SRC_SAM_ROOT})
    endif()
    
    if(NOT CEE_SAM_OPTION_LINK_FROM_SAM_LIB)
        if(${CEE_SAM_BUILD_CONFIGURATION} MATCHES "Static")
            target_link_libraries(${appname} PRIVATE ${CEE_SAM_STATIC_LIBRARY_NAME})
        else()
            target_link_libraries(${appname} PRIVATE ${CEE_SAM_LIBRARY_NAME})
        endif()
        target_link_libraries(${appname} PRIVATE ${CEE_SAM_INTERNAL_LIBRARIES})
    endif()
    target_link_libraries(${appname} PRIVATE ${CEE_SAM_EXTERNAL_LIBRARIES})
    if(${CEE_SAM_BUILD_CONFIGURATION} MATCHES "Static")
        target_link_libraries(${appname} PRIVATE ${CEE_SAM_GLEW_LIBRARY})
    endif()
    set_property(TARGET ${appname} PROPERTY FOLDER "Examples/VisToolsMeshExamples")

    if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
        target_link_libraries(${appname} PRIVATE stdc++fs Threads::Threads stdc++ ${CMAKE_DL_LIBS})
    endif()

    # Set PATH in Visual Studio and Visual Studio Code
    set_visual_studio_path(${appname})
    set_visual_studio_code_path(${appname})
    
    if("${appsrc}" MATCHES "exam52HEmain.cpp")
        target_sources(${appname} PRIVATE exam52HE.cpp)
    endif()

    
endforeach(appsrc ${APP_SOURCES})

#--------------------------------------------------------------
# Examples testing the Visualization objects
#--------------------------------------------------------------
file(GLOB APP_SOURCES ${CEE_SAM_VIS_EXAMPLES} )
foreach(appsrc ${APP_SOURCES})

    if(CEE_SAM_OPTION_NOVGLTOOLS)
        if("${appsrc}" MATCHES "glwin.cpp")
            continue()
        endif()
    endif()
    
    # Get source and target name
    get_filename_component(appsrc ${appsrc} NAME)
    get_filename_component(CEE_SAM_APP_SOURCE_BASENAME  ${appsrc} NAME_WE)
    set(appname "vis_${CEE_SAM_APP_SOURCE_BASENAME}")

    if(CEE_SAM_VERBOSE_LOGGING)
        message(STATUS "   - ${appname}")
    endif()
    
    if(CEE_SAM_OPTION_NOVGLTOOLS)
        add_executable(${appname} ${appsrc})
    else()
        add_executable(${appname} ${appsrc} glwin.cpp)
    endif() 

    target_compile_definitions(${appname} PRIVATE ${CEE_SAM_COMPILE_DEFINITIONS})
    target_include_directories(${appname} PRIVATE ${CEE_SAM_SOURCES_INCLUDES})
    target_include_directories(${appname} PRIVATE ${CEE_SAM_INTERNAL_INCLUDES})
    target_include_directories(${appname} SYSTEM PRIVATE ${CEE_SAM_EXTERNAL_INCLUDES})
    set_compile_option(${appname})
    set_sanitizer_compile_option(${appname})
    if(CEE_SAM_PROPERTIES_LINK_FLAGS)
        target_link_options(${appname} PRIVATE ${CEE_SAM_PROPERTIES_LINK_FLAGS})
    endif()
    
    if(NOT CEE_SAM_OPTION_LINK_FROM_SAM_LIB)
        if(${CEE_SAM_BUILD_CONFIGURATION} MATCHES "Static")
            target_link_libraries(${appname} PRIVATE ${CEE_SAM_STATIC_LIBRARY_NAME})
        else()
            target_link_libraries(${appname} PRIVATE ${CEE_SAM_LIBRARY_NAME})
        endif()
        target_link_libraries(${appname} PRIVATE ${CEE_SAM_INTERNAL_LIBRARIES})
    endif()
    target_link_libraries(${appname} PRIVATE ${CEE_SAM_EXTERNAL_LIBRARIES})
    if(${CEE_SAM_BUILD_CONFIGURATION} MATCHES "Static")
        target_link_libraries(${appname} PRIVATE ${CEE_SAM_GLEW_LIBRARY})
    endif()
    set_property(TARGET ${appname} PROPERTY FOLDER "Examples/VisToolsExamples")

    if(CEE_SAM_OPTION_PARASOLID AND "${appsrc}" IN_LIST SOURCES_USING_PARASOLID)
        target_link_libraries(${appname} PRIVATE ${CEE_SAM_OPTION_PARASOLID_LIBRARY})
        target_include_directories(${appname} PRIVATE ${CEE_SAM_OPTION_PARASOLID_INCLUDE_DIR})
    endif()
    
    if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
        target_link_libraries(${appname} PRIVATE stdc++fs Threads::Threads stdc++ ${CMAKE_DL_LIBS})
    endif()

    # Set PATH in Visual Studio and Visual Studio Code
    set_visual_studio_path(${appname})
    set_visual_studio_code_path(${appname})
    
endforeach(appsrc ${APP_SOURCES})

#--------------------------------------------------------------
# Examples testing C#
#--------------------------------------------------------------
if (CEE_SAM_INTERFACE_CSHARP)
    foreach(CEE_SAM_APP_SOURCE_FILE ${CEE_SAM_VIS_CS_INTERFACE_EXAMPLES})

        # Configure the CSharp file, create a temporary .csin file to configure
        if(NOT EXISTS "${CEE_SAM_APP_SOURCE_FILE}in")
            configure_file(${CEE_SAM_APP_SOURCE_FILE} ${CEE_SAM_APP_SOURCE_FILE}in COPYONLY)
        endif()
        configure_file(${CEE_SAM_APP_SOURCE_FILE}in ${CEE_SAM_APP_SOURCE_FILE})

        # Get source and target name
        get_filename_component(CEE_SAM_APP_SOURCE_FILE ${CEE_SAM_APP_SOURCE_FILE} NAME)
        get_filename_component(CEE_SAM_APP_SOURCE_BASENAME  ${CEE_SAM_APP_SOURCE_FILE} NAME_WE)
        set(CEE_SAM_APP_TARGET "vis_${CEE_SAM_APP_SOURCE_BASENAME}")
    
        if(CEE_SAM_VERBOSE_LOGGING)
            message(STATUS "   - ${CEE_SAM_APP_TARGET}")
        endif()
        
        # Set up project
        add_executable(${CEE_SAM_APP_TARGET} ${CEE_SAM_APP_SOURCE_FILE})
        target_compile_definitions(${CEE_SAM_APP_TARGET} PRIVATE ${CEE_SAM_COMPILE_DEFINITIONS})
        
        # Create variable to the csharp folder
        set(CEE_SAM_SRC_SAM_BASE_CSHARP ${CEE_SAM_SRC_SAM_ROOT}/base/csharp)
        set(CEE_SAM_SRC_SAM_VIS_CSHARP ${CEE_SAM_SRC_SAM_ROOT}/vis/csharp)
        set(CEE_SAM_SRC_SAM_VIS_LEGACY_CSHARP ${CEE_SAM_SRC_LEGACY_ROOT}/vis/csharp)
        
        # Make sure root csharp directory exists
        if(NOT EXISTS "${CEE_SAM_SRC_SAM_VIS_CSHARP}")
            file(MAKE_DIRECTORY "${CEE_SAM_SRC_SAM_VIS_CSHARP}")
        endif()

        # Add vsy.cs, creating a dummy file if not already exists (Will be generated later)
        if (NOT EXISTS "${CEE_SAM_SRC_SAM_BASE_CSHARP}/vsy.cs")
            file(TOUCH "${CEE_SAM_SRC_SAM_BASE_CSHARP}/vsy.cs")
        endif()
        target_sources(${CEE_SAM_APP_TARGET} PRIVATE "${CEE_SAM_SRC_SAM_BASE_CSHARP}/vsy.cs")
        
        # Add vis.cs, creating a dummy file if not already exist (Will be generated later)
        if (NOT EXISTS "${CEE_SAM_SRC_SAM_VIS_CSHARP}/vis.cs")
            file(TOUCH "${CEE_SAM_SRC_SAM_VIS_CSHARP}/vis.cs")
        endif()
        target_sources(${CEE_SAM_APP_TARGET} PRIVATE "${CEE_SAM_SRC_SAM_VIS_CSHARP}/vis.cs")
        
        # Add vislegacy.cs, creating a dummy file if not already exist (Will be generated later)
        if (NOT EXISTS "${CEE_SAM_SRC_SAM_VIS_LEGACY_CSHARP}/vislegacy.cs")
            file(TOUCH "${CEE_SAM_SRC_SAM_VIS_LEGACY_CSHARP}/vislegacy.cs")
        endif()
        target_sources(${CEE_SAM_APP_TARGET} PRIVATE "${CEE_SAM_SRC_SAM_VIS_LEGACY_CSHARP}/vislegacy.cs")
        
        # Add vgl
        if("${CEE_SAM_APP_SOURCE_FILE}" MATCHES "exam1vglcs.cs" OR "${CEE_SAM_APP_SOURCE_FILE}" MATCHES "intro1cs.cs")
            set(CEE_SAM_SRC_SAM_VGL_CSHARP ${CEE_SAM_SRC_LEGACY_ROOT}/vgl/csharp)
            # Add vgl.cs, creating a dummy file if not already exist (Will be generated later)
            if (NOT EXISTS "${CEE_SAM_SRC_SAM_VGL_CSHARP}/vgl.cs")
                file(TOUCH "${CEE_SAM_SRC_SAM_VGL_CSHARP}/vgl.cs")
            endif()
            target_sources(${CEE_SAM_APP_TARGET} PRIVATE "${CEE_SAM_SRC_SAM_VGL_CSHARP}/vgl.cs")
            set_property(TARGET ${CEE_SAM_APP_TARGET} PROPERTY FOLDER "Examples/VisToolsExamples")
        # Add msh
        elseif("${CEE_SAM_APP_SOURCE_FILE}" MATCHES "exam41cs.cs")
            set(CEE_SAM_SRC_SAM_MSH_CSHARP ${CEE_SAM_SRC_SAM_ROOT}/msh/csharp)
            # Add msh.cs, creating a dummy file if not already exist (Will be generated later)
            if (NOT EXISTS "${CEE_SAM_SRC_SAM_MSH_CSHARP}/msh.cs")
                file(TOUCH "${CEE_SAM_SRC_SAM_MSH_CSHARP}/msh.cs")
            endif()
            target_sources(${CEE_SAM_APP_TARGET} PRIVATE "${CEE_SAM_SRC_SAM_MSH_CSHARP}/msh.cs")
            set_property(TARGET ${CEE_SAM_APP_TARGET} PROPERTY FOLDER "Examples/VisToolsMeshExamples")
        else()
            set_property(TARGET ${CEE_SAM_APP_TARGET} PROPERTY FOLDER "Examples/VisToolsDataExamples")
        endif()
        
        # Add licence
        target_sources(${CEE_SAM_APP_TARGET} PRIVATE "${CEE_SAM_SRC_SAM_BASE_CSHARP}/hoops_license.cs")
        
        if(NOT CEE_SAM_OPTION_LINK_FROM_SAM_LIB)
            if(${CEE_SAM_BUILD_CONFIGURATION} MATCHES "Static")
                target_link_libraries(${CEE_SAM_APP_TARGET} PRIVATE ${CEE_SAM_STATIC_LIBRARY_NAME})
            else()
                target_link_libraries(${CEE_SAM_APP_TARGET} PRIVATE ${CEE_SAM_LIBRARY_NAME})
            endif()
            target_link_libraries(${CEE_SAM_APP_TARGET} PRIVATE ${CEE_SAM_INTERNAL_LIBRARIES})
        endif()
        target_link_libraries(${CEE_SAM_APP_TARGET} PRIVATE ${CEE_SAM_EXTERNAL_LIBRARIES})
        if(${CEE_SAM_BUILD_CONFIGURATION} MATCHES "Static")
            target_link_libraries(${CEE_SAM_APP_TARGET} PRIVATE ${CEE_SAM_GLEW_LIBRARY})
        endif()
        
        if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
            target_link_libraries(${CEE_SAM_APP_TARGET} PRIVATE stdc++fs Threads::Threads stdc++ ${CMAKE_DL_LIBS})
        endif()
    
        # Add paths to the third party DLLs for Visual Studio
        if(MSVC AND CEE_SAM_EXTERNAL_LIBRARIES_BIN_PATHS)
            set_target_properties(${CEE_SAM_APP_TARGET} PROPERTIES VS_DEBUGGER_ENVIRONMENT "PATH=${CEE_SAM_EXTERNAL_LIBRARIES_BIN_PATHS};%PATH%")
        endif()
        
    endforeach(CEE_SAM_APP_SOURCE_FILE ${APP_SOURCES})
endif()
