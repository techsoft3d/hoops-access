/*********************************************************************
 *                                                                   *
 *                          DevTools 3.1.0                           *
 *                                                                   *
 *  These coded instructions, statements and computer programs       *
 *  contain unpublished proprietary information of Tech Soft 3D,     *
 *  and are protected by Federal copyright law.  They may not be     *
 *  disclosed to third parties or copied or duplicated in any form,  *
 *  in whole or in part, without the prior written consent of        *
 *  Tech Soft 3D.                                                    *
 *                                                                   *
 *                 Copyright (C) 2026, Tech Soft 3D                  *
 *                                                                   *
 *********************************************************************/
#ifndef DYNAMIC_LIBRARY_LOADER_H
#define DYNAMIC_LIBRARY_LOADER_H

#include "sam/base/stdcontainers.h"
#include <stdexcept>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#define LIBRARY_LOAD(path)      LoadLibraryA(path)
#define LIBRARY_UNLOAD(lib)     FreeLibrary(lib)
#define GET_FUNCTION(lib, name) GetProcAddress(lib, name)
typedef HMODULE sharedLibrary;
#else
#include <dlfcn.h>
#define LIBRARY_LOAD(name)      dlopen(name, RTLD_LAZY)
#define LIBRARY_UNLOAD(lib)     dlclose(lib)
#define GET_FUNCTION(lib, name) dlsym(lib, name)
typedef void* sharedLibrary;
#endif

class DynamicLibraryLoader {
  public:
    sharedLibrary libraryHandle = nullptr;

    /* Constructor initializes with a library path to load*/
    DynamicLibraryLoader(const vsy::string& library_path);
    ~DynamicLibraryLoader();

    /*Load a function from the library by name, as a specific function pointer type*/
    template<typename FunctionT>
    FunctionT
    loadFunction(const vsy::string& function_name)
    {
        /*Cross-platform function loading with error checking*/
        auto func = reinterpret_cast<FunctionT>(GET_FUNCTION(libraryHandle, function_name.c_str()));
        if (!func) {
            throw std::runtime_error(("Failed to load function: " + function_name).data());
        }
        return func;
    }
};

#endif
