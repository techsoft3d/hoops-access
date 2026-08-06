cmake_minimum_required(VERSION 3.21)

project(${PROJECT_NAME}Examples)

# Setup projects
# ----------------------------------------------------------

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CEE_SAM_VDM_EXAMPLES
    intro1.cpp
    exam1.cpp
    exam2.cpp
    exam3.cpp
    exam3a.cpp
    exam3b.cpp
    exam3c.cpp
    exam3d.cpp
    exam3e.cpp
    exam3f.cpp
    exam3g.cpp
    exam4.cpp
    exam4a.cpp
    exam4odb.cpp
    exam5.cpp
    exam5a.cpp
    exam6.cpp
    exam7.cpp
    exam8.cpp
    exam8a1.cpp
    exam8a2.cpp
    exam9.cpp
    exam10.cpp
    exam10a.cpp
    exam11.cpp
    exam12.cpp
    exam12a.cpp
    exam12bclient.cpp
    exam12bserver.cpp
    exam13.cpp
    exam14_minimalplugin.cpp
	exam14a_vtkplugin.cpp
    exam15.cpp
)

set(CEE_SAM_VDM_EXAMPLES_CPP
    tutorial_first_program.cpp
    tutorial_table_of_contents.cpp
    tutorial_file_translation.cpp
    tutorial_read_model_data.cpp
    tutorial_read_result_data.cpp
)

set(CEE_SAM_VDM_CPP_INTERFACE_EXAMPLES
    exam1cc.cpp
)

set(CEE_SAM_VDM_CS_INTERFACE_EXAMPLES
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/exam/exam1cs.cs
)

set(CEE_SAM_APP_SOURCE_FILES ${CEE_SAM_VDM_EXAMPLES})
if(CEE_SAM_SAMCPP)
    set(CEE_SAM_APP_SOURCE_FILES ${CEE_SAM_APP_SOURCE_FILES} ${CEE_SAM_VDM_EXAMPLES_CPP})
    set(CEE_SAM_VDM_EXAMPLES ${CEE_SAM_VDM_EXAMPLES} ${CEE_SAM_VDM_EXAMPLES_CPP})
endif()
if (CEE_SAM_INTERFACE_CSHARP)
    set(CEE_SAM_APP_SOURCE_FILES ${CEE_SAM_APP_SOURCE_FILES} ${CEE_SAM_VDM_CS_INTERFACE_EXAMPLES})
endif()
if (CEE_SAM_INTERFACE_CPP)
    set(CEE_SAM_APP_SOURCE_FILES ${CEE_SAM_APP_SOURCE_FILES} ${CEE_SAM_VDM_CPP_INTERFACE_EXAMPLES})
endif()
if (CEE_SAM_VERBOSE_LOGGING)
    message(STATUS "   - Files: ${CEE_SAM_APP_SOURCE_FILES}")
endif()

# Add all examples automatically
foreach(CEE_SAM_APP_SOURCE_FILE ${CEE_SAM_APP_SOURCE_FILES})

    # Ignore due to missing VDM_ZLIBCOMPRESS
    if("${CEE_SAM_APP_SOURCE_FILE}" MATCHES "exam12bclient.cpp")
        continue()
    endif()

    # Get meta data
    get_filename_component(CEE_SAM_APP_SOURCE_BASENAME  ${CEE_SAM_APP_SOURCE_FILE} NAME_WE)
    set(CEE_SAM_APP_TARGET "vdm_${CEE_SAM_APP_SOURCE_BASENAME}")

    if(CEE_SAM_VERBOSE_LOGGING)
        message(STATUS "   - ${CEE_SAM_APP_TARGET}")
    endif()

    # Configure CSharp
    if (${CEE_SAM_APP_SOURCE_FILE} IN_LIST CEE_SAM_VDM_CS_INTERFACE_EXAMPLES)

        # Configure the CSharp file, create a temporary .csin file to configure
        if(NOT EXISTS "${CEE_SAM_APP_SOURCE_FILE}in")
            configure_file(${CEE_SAM_APP_SOURCE_FILE} ${CEE_SAM_APP_SOURCE_FILE}in COPYONLY)
        endif()
        configure_file(${CEE_SAM_APP_SOURCE_FILE}in ${CEE_SAM_APP_SOURCE_FILE})

        # add CSharp executable
        add_executable(${CEE_SAM_APP_TARGET} ${CEE_SAM_APP_SOURCE_FILE})
        target_compile_definitions(${CEE_SAM_APP_TARGET} PRIVATE ${CEE_SAM_COMPILE_DEFINITIONS})
        
        # Create variable to the csharp folder
        set(CEE_SAM_SRC_SAM_BASE_CSHARP ${CEE_SAM_SRC_SAM_ROOT}/base/csharp)
        set(CEE_SAM_SRC_SAM_VDM_CSHARP ${CEE_SAM_SRC_SAM_ROOT}/vdm/csharp)
        
        # Make sure root csharp directory exists
        if(NOT EXISTS "${CEE_SAM_SRC_SAM_VDM_CSHARP}")
            file(MAKE_DIRECTORY "${CEE_SAM_SRC_SAM_VDM_CSHARP}")
        endif()

        # Add vsy.cs, creating a dummy file if not already exists (Will be generated later)
        if (NOT EXISTS "${CEE_SAM_SRC_SAM_BASE_CSHARP}/vsy.cs")
            file(TOUCH "${CEE_SAM_SRC_SAM_BASE_CSHARP}/vsy.cs")
        endif()
        target_sources(${CEE_SAM_APP_TARGET} PRIVATE "${CEE_SAM_SRC_SAM_BASE_CSHARP}/vsy.cs")

        # Add vdm.cs, creating a dummy file if not already exist (Will be generated later)
        if (NOT EXISTS "${CEE_SAM_SRC_SAM_VDM_CSHARP}/vdm.cs")
            file(TOUCH "${CEE_SAM_SRC_SAM_VDM_CSHARP}/vdm.cs")
        endif()
        target_sources(${CEE_SAM_APP_TARGET} PRIVATE "${CEE_SAM_SRC_SAM_VDM_CSHARP}/vdm.cs")
        
        # Add licence
        target_sources(${CEE_SAM_APP_TARGET} PRIVATE "${CEE_SAM_SRC_SAM_BASE_CSHARP}/hoops_license.cs")
    endif()

    # Configure C++
    if (${CEE_SAM_APP_SOURCE_FILE} IN_LIST CEE_SAM_VDM_CPP_INTERFACE_EXAMPLES)
        add_executable(${CEE_SAM_APP_TARGET} ${CEE_SAM_APP_SOURCE_FILE})
        target_compile_definitions(${CEE_SAM_APP_TARGET} PRIVATE ${CEE_SAM_COMPILE_DEFINITIONS})
        target_include_directories(${CEE_SAM_APP_TARGET} PRIVATE ${CEE_SAM_SOURCES_INCLUDES})
        target_include_directories(${CEE_SAM_APP_TARGET} PRIVATE ${CEE_SAM_INTERNAL_INCLUDES})
        target_include_directories(${CEE_SAM_APP_TARGET} SYSTEM PRIVATE ${CEE_SAM_EXTERNAL_INCLUDES})
        if(CEE_SAM_PROPERTIES_LINK_FLAGS)
            target_link_options(${CEE_SAM_APP_TARGET} PRIVATE ${CEE_SAM_PROPERTIES_LINK_FLAGS})
        endif()
        
        set_compile_option(${CEE_SAM_APP_TARGET})
        message(FATAL_ERROR "   - CPP interface not yet implemented (${CEE_SAM_APP_SOURCE_FILE})")
    endif()

    # Configure C
    if (${CEE_SAM_APP_SOURCE_FILE} IN_LIST CEE_SAM_VDM_EXAMPLES)
        add_executable(${CEE_SAM_APP_TARGET} ${CEE_SAM_APP_SOURCE_FILE})
        target_compile_definitions(${CEE_SAM_APP_TARGET} PRIVATE ${CEE_SAM_COMPILE_DEFINITIONS})
        target_include_directories(${CEE_SAM_APP_TARGET} PRIVATE ${CEE_SAM_SOURCES_INCLUDES})
        target_include_directories(${CEE_SAM_APP_TARGET} PRIVATE ${CEE_SAM_INTERNAL_INCLUDES})
        target_include_directories(${CEE_SAM_APP_TARGET} SYSTEM PRIVATE ${CEE_SAM_EXTERNAL_INCLUDES})
        if(CEE_SAM_PROPERTIES_LINK_FLAGS)
            target_link_options(${CEE_SAM_APP_TARGET} PRIVATE ${CEE_SAM_PROPERTIES_LINK_FLAGS})
        endif()
        
        set_compile_option(${CEE_SAM_APP_TARGET})
        set_sanitizer_compile_option(${CEE_SAM_APP_TARGET})
    endif()

    if(NOT CEE_SAM_OPTION_LINK_FROM_SAM_LIB)
        if(${CEE_SAM_BUILD_CONFIGURATION} MATCHES "Static")
            target_link_libraries(${CEE_SAM_APP_TARGET} PRIVATE ${CEE_SAM_STATIC_LIBRARY_NAME})
        else()
            target_link_libraries(${CEE_SAM_APP_TARGET} PRIVATE ${CEE_SAM_LIBRARY_NAME})
        endif()
        target_link_libraries(${CEE_SAM_APP_TARGET} PRIVATE ${CEE_SAM_INTERNAL_LIBRARIES})
    endif()
    target_link_libraries(${CEE_SAM_APP_TARGET} PRIVATE ${CEE_SAM_EXTERNAL_LIBRARIES})
    
    if(${CMAKE_SYSTEM_NAME} MATCHES "Linux" AND CEE_SAM_READER_SAMCEF)
        target_link_libraries(${CEE_SAM_APP_TARGET} PRIVATE dl)
    endif()
    if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
        target_link_libraries(${CEE_SAM_APP_TARGET} PRIVATE stdc++fs Threads::Threads stdc++ ${CMAKE_DL_LIBS})
    endif()
    if(${CEE_SAM_BUILD_CONFIGURATION} MATCHES "Static")
        target_link_libraries(${CEE_SAM_APP_TARGET} PRIVATE ${CEE_SAM_GLEW_LIBRARY})
    endif()
    set_property(TARGET ${CEE_SAM_APP_TARGET} PROPERTY FOLDER "Examples/${PROJECT_NAME}")
    
    # Copy MinimalPlugin to the current runtime directory
    if ("${CEE_SAM_APP_SOURCE_FILE}" MATCHES "exam14.cpp" AND CEE_SAM_DATA_PROVIDER_FRAMEWORK AND CEE_SAM_PROVIDER_EXAMPLES)
        if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
            get_target_property(MinimalPluginLibraryOutputDirectory MinimalPlugin LIBRARY_OUTPUT_DIRECTORY)
            get_target_property(MinimalPluginRuntimeOutputDirectory ${CEE_SAM_APP_TARGET} RUNTIME_OUTPUT_DIRECTORY)
            add_custom_command(
                TARGET ${CEE_SAM_APP_TARGET}
                POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy ${MinimalPluginLibraryOutputDirectory}/cdp_*.so ${MinimalPluginRuntimeOutputDirectory})
        endif()
    endif() 
    
    # Set PATH in Visual Studio and Visual Studio Code
    set_visual_studio_path(${CEE_SAM_APP_TARGET})
    set_visual_studio_code_path(${CEE_SAM_APP_TARGET})
    
endforeach(CEE_SAM_APP_SOURCE_FILE ${CEE_SAM_APP_SOURCE_FILES})
