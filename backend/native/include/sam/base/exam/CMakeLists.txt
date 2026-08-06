cmake_minimum_required(VERSION 3.21)

project(${PROJECT_NAME}Examples)

# Setup projects
# ----------------------------------------------------------

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CEE_SAM_BASE_EXAMPLES
    exam1.cpp
    exam2.cpp
    exam3.cpp
    exam4.cpp
    exam6.cpp
    exam7.cpp
    exam8.cpp
    exam9.cpp
    exam9a.cpp
    exam10.cpp
    exam11.cpp
    exam12.cpp
    exam13.cpp
    exam14.cpp
    exam15.cpp
    exam16.cpp
    exam17.cpp
    exam18.cpp
    exam19.cpp
    exam20.cpp
    exam22.cpp
    exam23.cpp
    exam24.cpp
    exam25.cpp
    exam26.cpp
)

set(CEE_SAM_BASE_CPP_INTERFACE_EXAMPLES
    exam1cc.cpp
    exam4cc.cpp
    exam5cc.cpp
    exam23cc.cpp
)

set(CEE_SAM_BASE_CS_INTERFACE_EXAMPLES
    ${CEE_SAM_SRC_SAM_ROOT}/base/exam/exam1cs.cs
)

set(CEE_SAM_APP_SOURCE_FILES ${CEE_SAM_BASE_EXAMPLES})
if (CEE_SAM_INTERFACE_CSHARP)
    set(CEE_SAM_APP_SOURCE_FILES ${CEE_SAM_APP_SOURCE_FILES} ${CEE_SAM_BASE_CS_INTERFACE_EXAMPLES})
endif()
if (CEE_SAM_INTERFACE_CPP)
    set(CEE_SAM_APP_SOURCE_FILES ${CEE_SAM_APP_SOURCE_FILES} ${CEE_SAM_BASE_CPP_INTERFACE_EXAMPLES})
endif()
if (CEE_SAM_VERBOSE_LOGGING)
    message(STATUS "   - Files: ${CEE_SAM_APP_SOURCE_FILES}")
endif()

# Add all examples automatically
foreach(CEE_SAM_APP_SOURCE_FILE ${CEE_SAM_APP_SOURCE_FILES})

    # Get meta data
    get_filename_component(CEE_SAM_APP_SOURCE_BASENAME  ${CEE_SAM_APP_SOURCE_FILE} NAME_WE)
    set(CEE_SAM_APP_TARGET "base_${CEE_SAM_APP_SOURCE_BASENAME}")

    if(CEE_SAM_VERBOSE_LOGGING)
        message(STATUS "   - ${CEE_SAM_APP_TARGET}")
    endif()

    # Set up project
    if (${CEE_SAM_APP_SOURCE_FILE} IN_LIST CEE_SAM_BASE_EXAMPLES)
        add_executable(${CEE_SAM_APP_TARGET} ${CEE_SAM_APP_SOURCE_FILE})
        target_compile_definitions(${CEE_SAM_APP_TARGET} PRIVATE ${CEE_SAM_COMPILE_DEFINITIONS})
        target_include_directories(${CEE_SAM_APP_TARGET} PRIVATE ${CEE_SAM_SOURCES_INCLUDES})
        target_include_directories(${CEE_SAM_APP_TARGET} PRIVATE ${CEE_SAM_INTERNAL_INCLUDES})
        target_include_directories(${CEE_SAM_APP_TARGET} SYSTEM PRIVATE ${CEE_SAM_EXTERNAL_INCLUDES})
        set_compile_option(${CEE_SAM_APP_TARGET})
        set_sanitizer_compile_option(${CEE_SAM_APP_TARGET})
        if(CEE_SAM_PROPERTIES_LINK_FLAGS)
            target_link_options(${CEE_SAM_APP_TARGET} PRIVATE ${CEE_SAM_PROPERTIES_LINK_FLAGS})
        endif()
    endif()
    
    # Configure CSharp
    if (${CEE_SAM_APP_SOURCE_FILE} IN_LIST CEE_SAM_BASE_CS_INTERFACE_EXAMPLES)
    
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
        
        # Make sure root csharp directory exists
        if(NOT EXISTS "${CEE_SAM_SRC_SAM_BASE_CSHARP}")
            file(MAKE_DIRECTORY "${CEE_SAM_SRC_SAM_BASE_CSHARP}")
        endif()

        # Add vsy.cs, creating a dummy file if not already exists (Will be generated later)
        if (NOT EXISTS "${CEE_SAM_SRC_SAM_BASE_CSHARP}/vsy.cs")
            file(TOUCH "${CEE_SAM_SRC_SAM_BASE_CSHARP}/vsy.cs")
        endif()
        if (NOT EXISTS "${CEE_SAM_SRC_SAM_BASE_CSHARP}/hoops_license.cs")
            file(TOUCH "${CEE_SAM_SRC_SAM_BASE_CSHARP}/hoops_license.cs")
        endif()
        target_sources(${CEE_SAM_APP_TARGET} PRIVATE "${CEE_SAM_SRC_SAM_BASE_CSHARP}/vsy.cs")
        
        # Add licence
        target_sources(${CEE_SAM_APP_TARGET} PRIVATE "${CEE_SAM_SRC_SAM_BASE_CSHARP}/hoops_license.cs")
    endif()
    
    # Configure C++
    if (${CEE_SAM_APP_SOURCE_FILE} IN_LIST CEE_SAM_BASE_CPP_INTERFACE_EXAMPLES)
        message(FATAL_ERROR "   - CPP interface not yet implemented (${CEE_SAM_APP_SOURCE_FILE})")
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
    
    if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
        target_link_libraries(${CEE_SAM_APP_TARGET} PRIVATE stdc++fs Threads::Threads stdc++ ${CMAKE_DL_LIBS})
    endif()
    set_property(TARGET ${CEE_SAM_APP_TARGET} PROPERTY FOLDER "Examples/${PROJECT_NAME}")

    # Set PATH in Visual Studio and Visual Studio Code
    set_visual_studio_path(${CEE_SAM_APP_TARGET})
    set_visual_studio_code_path(${CEE_SAM_APP_TARGET})
    
endforeach(CEE_SAM_APP_SOURCE_FILE ${CEE_SAM_APP_SOURCE_FILES})
