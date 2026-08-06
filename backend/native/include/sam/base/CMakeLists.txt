cmake_minimum_required(VERSION 3.21)

project(Base)
message(STATUS "Configuring ${PROJECT_NAME}...")


# Include Base source code
# ----------------------------------------------------------
set(CEE_SAM_BASE_SOURCE_FILES 
    ${CEE_SAM_SRC_SAM_ROOT}/base/adtree.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/bitvec.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/buildOptions.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/calc.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/concat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/csystem.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/cvect.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/datatable.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/dbldict.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/dblhash.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/dblvec.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/dictionary.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/echo.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/error.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/f2cutil.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/filetext.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/fltvec.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/hashtable.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/heap.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/heapind.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/htmltext.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/intdict.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/inthash.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/intque.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/intstack.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/intvec.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/intvhash.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/latextext.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/license.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/licensePrivate.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/linecon.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/linklist.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/list.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/log.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/machinfo.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/name.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/plaintext.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/pqueue.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/pred.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/print.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/progress.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/propset.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/ptask.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/random.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/redpre.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/regexp.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/stack.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/strutil.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/textfun.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/texttee.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/timer.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/track.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/tree.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/tricon.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/vertloc.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/vhashtable.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/vmlblas.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/vmllapack.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/vmlmetis.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/vmlngnumeric.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/vmlngsymbolic.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/vmlngutil.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/vmltmetis.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/vmlutil.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/vquad.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/vsocket.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/vsy_threadpool.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/vututil.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/zmem.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/base/dynamicLibraryLoader.cpp
)

set(CEE_SAM_BASE_PUBLIC_HEADER_FILES 
    ${CEE_SAM_SRC_SAM_ROOT}/base/ThreadPool.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/adtree.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/base.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/basedefs.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/bitvec.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/buildOptions.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/calc.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/concat.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/csystem.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/cvect.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/datatable.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/dbldict.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/dblhash.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/dblvec.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/dictionary.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/echo.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/error.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/f2cutil.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/filetext.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/fltvec.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/hashtable.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/heap.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/heapind.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/htmltext.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/intdict.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/inthash.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/inthashdefs.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/intque.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/intstack.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/intvec.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/intvhash.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/latextext.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/license.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/licensePrivate.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/linecon.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/linklist.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/list.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/log.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/machinfo.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/name.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/plaintext.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/pqueue.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/pred.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/print.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/progress.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/propset.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/ptask.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/random.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/redpre.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/regexp.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/stack.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/strutil.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/system.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/textfun.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/texttee.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/timer.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/track.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/tree.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/tricon.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/version.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/vertloc.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/vhashtable.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/vkifortran.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/vmlblas.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/vmllapack.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/vmlmetis.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/vmlng.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/vmlngutil.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/vmltmetis.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/vmlutil.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/vmlzblas.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/vquad.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/vsocket.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/vsy_threadpool.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/vututil.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/zmem.h
)

# Remove files from Cppcheck
if (DEFINED CPP_CHECK_FLAG)
    message(STATUS " - Removing some files for cppcheck")
    list(REMOVE_ITEM CEE_SAM_BASE_SOURCE_FILES ${CEE_SAM_SRC_SAM_ROOT}/base/vmltmetis.cpp)
endif()

set(CEE_SAM_BASE_HEADER_FILES 
    ${CEE_SAM_BASE_PUBLIC_HEADER_FILES}
    ${CEE_SAM_SRC_SAM_ROOT}/base/dynamicLibraryLoader.h
    ${CEE_SAM_SRC_SAM_ROOT}/base/allocator.h
	${CEE_SAM_SRC_SAM_ROOT}/base/stdcontainers.h
)

set(CEE_SAM_SRC_SAM_BLOSC_ROOT ${CEE_SAM_SRC_SAM_ROOT}/base/ext/hdf5-blosc)
set(CEE_SAM_BASE_BLOSC_SOURCE_FILES 
    ${CEE_SAM_SRC_SAM_BLOSC_ROOT}/blosc_filter.c
)

# Include C++ interface
# ----------------------------------------------------------
set(CEE_SAM_BASE_SOURCE_CPLUSPLUS_FILES_FILTER cplusplus/*.cxx)
file(GLOB CEE_SAM_BASE_SOURCE_CPLUSPLUS_FILES ${CEE_SAM_BASE_SOURCE_CPLUSPLUS_FILES_FILTER})
list(APPEND CEE_SAM_BASE_SOURCE_FILES ${CEE_SAM_BASE_SOURCE_CPLUSPLUS_FILES})


# Include blosc filter if activated
# ----------------------------------------------------------
if(CEE_SAM_OPTION_BLOSC AND CEE_SAM_OPTION_HDF5)
    list(APPEND CEE_SAM_BASE_SOURCE_FILES ${CEE_SAM_BASE_BLOSC_SOURCE_FILES})
endif()

# Include Fortran interface
# ----------------------------------------------------------
if(CEE_SAM_INTERFACE_FORTRAN)
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/fortran/)
        message(STATUS " - Adding Fortran interface")
        set(CEE_SAM_BASE_SOURCE_FORTRAN_FILES_FILTER fortran/*.c)
    else()
        message(WARNING " - Fortran interface files does not exist")
    endif()
endif()

# Include C# interface
# ----------------------------------------------------------
if(CEE_SAM_INTERFACE_CSHARP)
    # Create csharp folder
    set(CEE_SAM_BASE_CS_FOLDER ${CEE_SAM_SRC_SAM_ROOT}/base/csharp)
    if (NOT EXISTS ${CEE_SAM_BASE_CS_FOLDER})
        file(MAKE_DIRECTORY ${CEE_SAM_BASE_CS_FOLDER})
    endif()
    
    # Get cs file
    if(EXISTS ${CEE_SAM_BASE_CS_FOLDER})
        message(STATUS " - Adding C# interface")
        set(CEE_SAM_BASE_SOURCE_CS_FILE ${CEE_SAM_BASE_CS_FOLDER}/vsy.cs)
        if (NOT EXISTS ${CEE_SAM_BASE_SOURCE_CS_FILE})
            file(TOUCH "${CEE_SAM_BASE_SOURCE_CS_FILE}")
        endif()
        if (NOT EXISTS ${CEE_SAM_BASE_CS_FOLDER}/hoops_license.cs)
            file(TOUCH "${CEE_SAM_BASE_CS_FOLDER}/hoops_license.cs")
        endif()
        if (NOT EXISTS ${CEE_SAM_BASE_SOURCE_CS_FILE})
            message(FATAL_ERROR "Unable to create csharp file ${CEE_SAM_BASE_SOURCE_CS_FILE}!")
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


# Setup project
# ----------------------------------------------------------

list(FILTER CEE_SAM_BASE_SOURCE_FILES EXCLUDE REGEX ".*\\dummy.cpp")
set(CEE_SAM_BASE_SOURCE_FILES_TO_PARENT ${CEE_SAM_BASE_SOURCE_FILES} PARENT_SCOPE)
set(CEE_SAM_ALL_SOURCE_FILES ${CEE_SAM_ALL_SOURCE_FILES} ${CEE_SAM_BASE_SOURCE_FILES} PARENT_SCOPE)
set(CEE_SAM_BASE_PUBLIC_HEADER_FILES ${CEE_SAM_BASE_PUBLIC_HEADER_FILES} PARENT_SCOPE)
set(CEE_SAM_BASE_HEADER_FILES ${CEE_SAM_BASE_HEADER_FILES} PARENT_SCOPE)
set(CEE_SAM_ALL_HEADER_FILES ${CEE_SAM_ALL_HEADER_FILES} ${CEE_SAM_BASE_HEADER_FILES} PARENT_SCOPE)

if(CEE_SAM_INTERFACE_FORTRAN)
    file(GLOB CEE_SAM_BASE_SOURCE_FORTRAN_FILES ${CEE_SAM_BASE_SOURCE_FORTRAN_FILES_FILTER})
    set(CEE_SAM_ALL_SOURCE_FORTRAN_FILES ${CEE_SAM_ALL_SOURCE_FORTRAN_FILES} ${CEE_SAM_BASE_SOURCE_FORTRAN_FILES} PARENT_SCOPE)
endif()

if(CEE_SAM_INTERFACE_CSHARP)
    set(CEE_SAM_ALL_SOURCE_CS_FILES ${CEE_SAM_ALL_SOURCE_CS_FILES} ${CEE_SAM_BASE_SOURCE_CS_FILE} PARENT_SCOPE)
endif()
