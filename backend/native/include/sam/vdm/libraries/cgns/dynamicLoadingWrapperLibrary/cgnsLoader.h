#ifndef CGNSLOADER_H
#define CGNSLOADER_H

#include <memory>
#include <mutex>
#include <cstddef>
#include <filesystem>
#include "sam/base/system.h"
#include "sam/base/base.h"
#include "sam/base/stdcontainers.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#include <unistd.h>
#include <limits.h>
#ifndef PATH_MAX
#define PATH_MAX 4096
#endif
#endif

#include "cgnslib.h"

inline vsy::string
GetLibraryPath()
{
    // Check environment variable first
    const char* cgns_lib_dir = getenv("CEE_SAM_READER_CGNS_LIBRARY_DIR");
    if (cgns_lib_dir) {
        std::filesystem::path env_dir(cgns_lib_dir);

#ifdef _WIN32
        vsy::vector<vsy::string> candidates = {"cgnsdll.dll"};
#else
        vsy::vector<vsy::string> candidates = {"libcgns.so", "libcgns.so.4", "libcgns.so.4.2.3"};
#endif

        // Try all candidates in the environment directory
        for (const auto& name: candidates) {
            std::filesystem::path env_path = env_dir / name;
            if (std::filesystem::exists(env_path)) {
                return vsy::string(env_path.string().c_str());
            }
        }
    }

    // Try candidate libraries in current directory/system PATH
#ifdef _WIN32
    vsy::vector<vsy::string> candidates = {"cgnsdll.dll"};
#else
    vsy::vector<vsy::string> candidates = {"libcgns.so", "libcgns.so.4", "libcgns.so.4.2.3"};
#endif

    for (const auto& name: candidates) {
        if (std::filesystem::exists(name)) {
            return name;
        }
    }

    // Fall back to system PATH search
#ifdef _WIN32
    return "cgnsdll.dll";
#else
    return "libcgns.so";
#endif
}

class cgnsLoader {
  public:
    cgnsLoader(): handle_(nullptr)
    {
        vsy::string libraryPath = GetLibraryPath();
        static Vchar func[] = "cgnsLoader::cgnsLoader";

#ifdef _WIN32
        handle_ = LoadLibraryA(libraryPath.c_str());
        if (!handle_) {
            DWORD error = GetLastError();
            vsy::string errorMsg =
            "Failed to load CGNS DLL '" + libraryPath + "'. Error code: " + vsy::string(std::to_string(error).c_str());
            HANDLEERR0(func, SYS_ERROR_LOAD, errorMsg.c_str());
            return;
        }
#else
        handle_ = dlopen(libraryPath.c_str(), RTLD_LAZY);
        if (!handle_) {
            const char* error = dlerror();
            vsy::string errorMsg =
            "Failed to load CGNS library '" + libraryPath + "': " + vsy::string(error ? error : "Unknown error");
            HANDLEERR0(func, SYS_ERROR_LOAD, errorMsg.c_str());
            return;
        }
#endif
        try {
            load_all();
        }
        catch (...) {
            // Clean up handle if loading fails
#ifdef _WIN32
            if (handle_)
                FreeLibrary(handle_);
#else
            if (handle_)
                dlclose(handle_);
#endif
            handle_ = nullptr;
            return;
        }
    }

    ~cgnsLoader()
    {
#ifdef _WIN32
        if (handle_)
            FreeLibrary(handle_);
#else
        if (handle_)
            dlclose(handle_);
#endif
    }

    // Prevent copying and moving
    cgnsLoader(const cgnsLoader&) = delete;
    cgnsLoader&
    operator=(const cgnsLoader&) = delete;
    cgnsLoader(cgnsLoader&&) = delete;
    cgnsLoader&
    operator=(cgnsLoader&&) = delete;

  private:
#ifdef _WIN32
    HMODULE handle_;
#else
    void* handle_;
#endif
    void
    load_all()
    {
#ifdef _WIN32
        auto sym_cg_is_cgns = GetProcAddress(handle_, "cg_is_cgns");
        if (!sym_cg_is_cgns)
            throw std::runtime_error("cg_is_cgns not found");
#else
        auto sym_cg_is_cgns = dlsym(handle_, "cg_is_cgns");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_is_cgns_ = reinterpret_cast<int (*)(const char* filename, int* file_type)>(sym_cg_is_cgns);
#ifdef _WIN32
        auto sym_cg_open = GetProcAddress(handle_, "cg_open");
        if (!sym_cg_open)
            throw std::runtime_error("cg_open not found");
#else
        auto sym_cg_open = dlsym(handle_, "cg_open");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_open_ = reinterpret_cast<int (*)(const char* filename, int mode, int* fn)>(sym_cg_open);
#ifdef _WIN32
        auto sym_cg_version = GetProcAddress(handle_, "cg_version");
        if (!sym_cg_version)
            throw std::runtime_error("cg_version not found");
#else
        auto sym_cg_version = dlsym(handle_, "cg_version");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_version_ = reinterpret_cast<int (*)(int fn, float* FileVersion)>(sym_cg_version);
#ifdef _WIN32
        auto sym_cg_precision = GetProcAddress(handle_, "cg_precision");
        if (!sym_cg_precision)
            throw std::runtime_error("cg_precision not found");
#else
        auto sym_cg_precision = dlsym(handle_, "cg_precision");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_precision_ = reinterpret_cast<int (*)(int fn, int* precision)>(sym_cg_precision);
#ifdef _WIN32
        auto sym_cg_close = GetProcAddress(handle_, "cg_close");
        if (!sym_cg_close)
            throw std::runtime_error("cg_close not found");
#else
        auto sym_cg_close = dlsym(handle_, "cg_close");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_close_ = reinterpret_cast<int (*)(int fn)>(sym_cg_close);
#ifdef _WIN32
        auto sym_cg_save_as = GetProcAddress(handle_, "cg_save_as");
        if (!sym_cg_save_as)
            throw std::runtime_error("cg_save_as not found");
#else
        auto sym_cg_save_as = dlsym(handle_, "cg_save_as");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_save_as_ = reinterpret_cast<int (*)(int fn, const char* filename, int file_type, int follow_links)>(sym_cg_save_as);
#ifdef _WIN32
        auto sym_cg_set_file_type = GetProcAddress(handle_, "cg_set_file_type");
        if (!sym_cg_set_file_type)
            throw std::runtime_error("cg_set_file_type not found");
#else
        auto sym_cg_set_file_type = dlsym(handle_, "cg_set_file_type");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_set_file_type_ = reinterpret_cast<int (*)(int file_type)>(sym_cg_set_file_type);
#ifdef _WIN32
        auto sym_cg_get_file_type = GetProcAddress(handle_, "cg_get_file_type");
        if (!sym_cg_get_file_type)
            throw std::runtime_error("cg_get_file_type not found");
#else
        auto sym_cg_get_file_type = dlsym(handle_, "cg_get_file_type");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_get_file_type_ = reinterpret_cast<int (*)(int fn, int* file_type)>(sym_cg_get_file_type);
#ifdef _WIN32
        auto sym_cg_root_id = GetProcAddress(handle_, "cg_root_id");
        if (!sym_cg_root_id)
            throw std::runtime_error("cg_root_id not found");
#else
        auto sym_cg_root_id = dlsym(handle_, "cg_root_id");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_root_id_ = reinterpret_cast<int (*)(int fn, double* rootid)>(sym_cg_root_id);
#ifdef _WIN32
        auto sym_cg_get_cgio = GetProcAddress(handle_, "cg_get_cgio");
        if (!sym_cg_get_cgio)
            throw std::runtime_error("cg_get_cgio not found");
#else
        auto sym_cg_get_cgio = dlsym(handle_, "cg_get_cgio");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_get_cgio_ = reinterpret_cast<int (*)(int fn, int* cgio_num)>(sym_cg_get_cgio);
#ifdef _WIN32
        auto sym_cg_configure = GetProcAddress(handle_, "cg_configure");
        if (!sym_cg_configure)
            throw std::runtime_error("cg_configure not found");
#else
        auto sym_cg_configure = dlsym(handle_, "cg_configure");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_configure_ = reinterpret_cast<int (*)(int what, void* value)>(sym_cg_configure);
#ifdef _WIN32
        auto sym_cg_error_handler = GetProcAddress(handle_, "cg_error_handler");
        if (!sym_cg_error_handler)
            throw std::runtime_error("cg_error_handler not found");
#else
        auto sym_cg_error_handler = dlsym(handle_, "cg_error_handler");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_error_handler_ = reinterpret_cast<int (*)(void (*)(int, char*))>(sym_cg_error_handler);
#ifdef _WIN32
        auto sym_cg_set_compress = GetProcAddress(handle_, "cg_set_compress");
        if (!sym_cg_set_compress)
            throw std::runtime_error("cg_set_compress not found");
#else
        auto sym_cg_set_compress = dlsym(handle_, "cg_set_compress");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_set_compress_ = reinterpret_cast<int (*)(int compress)>(sym_cg_set_compress);
#ifdef _WIN32
        auto sym_cg_get_compress = GetProcAddress(handle_, "cg_get_compress");
        if (!sym_cg_get_compress)
            throw std::runtime_error("cg_get_compress not found");
#else
        auto sym_cg_get_compress = dlsym(handle_, "cg_get_compress");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_get_compress_ = reinterpret_cast<int (*)(int* compress)>(sym_cg_get_compress);
#ifdef _WIN32
        auto sym_cg_set_path = GetProcAddress(handle_, "cg_set_path");
        if (!sym_cg_set_path)
            throw std::runtime_error("cg_set_path not found");
#else
        auto sym_cg_set_path = dlsym(handle_, "cg_set_path");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_set_path_ = reinterpret_cast<int (*)(const char* path)>(sym_cg_set_path);
#ifdef _WIN32
        auto sym_cg_add_path = GetProcAddress(handle_, "cg_add_path");
        if (!sym_cg_add_path)
            throw std::runtime_error("cg_add_path not found");
#else
        auto sym_cg_add_path = dlsym(handle_, "cg_add_path");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_add_path_ = reinterpret_cast<int (*)(const char* path)>(sym_cg_add_path);
#ifdef _WIN32
        auto sym_cg_get_name = GetProcAddress(handle_, "cg_get_name");
        if (!sym_cg_get_name)
            throw std::runtime_error("cg_get_name not found");
#else
        auto sym_cg_get_name = dlsym(handle_, "cg_get_name");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_get_name_ = reinterpret_cast<const char* (*)(int nnames, const char** names, int type)>(sym_cg_get_name);
#ifdef _WIN32
        auto sym_cg_MassUnitsName = GetProcAddress(handle_, "cg_MassUnitsName");
        if (!sym_cg_MassUnitsName)
            throw std::runtime_error("cg_MassUnitsName not found");
#else
        auto sym_cg_MassUnitsName = dlsym(handle_, "cg_MassUnitsName");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_MassUnitsName_ = reinterpret_cast<const char* (*)(CGNS_ENUMT(MassUnits_t) type)>(sym_cg_MassUnitsName);
#ifdef _WIN32
        auto sym_cg_LengthUnitsName = GetProcAddress(handle_, "cg_LengthUnitsName");
        if (!sym_cg_LengthUnitsName)
            throw std::runtime_error("cg_LengthUnitsName not found");
#else
        auto sym_cg_LengthUnitsName = dlsym(handle_, "cg_LengthUnitsName");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_LengthUnitsName_ = reinterpret_cast<const char* (*)(CGNS_ENUMT(LengthUnits_t) type)>(sym_cg_LengthUnitsName);
#ifdef _WIN32
        auto sym_cg_TimeUnitsName = GetProcAddress(handle_, "cg_TimeUnitsName");
        if (!sym_cg_TimeUnitsName)
            throw std::runtime_error("cg_TimeUnitsName not found");
#else
        auto sym_cg_TimeUnitsName = dlsym(handle_, "cg_TimeUnitsName");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_TimeUnitsName_ = reinterpret_cast<const char* (*)(CGNS_ENUMT(TimeUnits_t) type)>(sym_cg_TimeUnitsName);
#ifdef _WIN32
        auto sym_cg_TemperatureUnitsName = GetProcAddress(handle_, "cg_TemperatureUnitsName");
        if (!sym_cg_TemperatureUnitsName)
            throw std::runtime_error("cg_TemperatureUnitsName not found");
#else
        auto sym_cg_TemperatureUnitsName = dlsym(handle_, "cg_TemperatureUnitsName");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_TemperatureUnitsName_ =
        reinterpret_cast<const char* (*)(CGNS_ENUMT(TemperatureUnits_t) type)>(sym_cg_TemperatureUnitsName);
#ifdef _WIN32
        auto sym_cg_AngleUnitsName = GetProcAddress(handle_, "cg_AngleUnitsName");
        if (!sym_cg_AngleUnitsName)
            throw std::runtime_error("cg_AngleUnitsName not found");
#else
        auto sym_cg_AngleUnitsName = dlsym(handle_, "cg_AngleUnitsName");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_AngleUnitsName_ = reinterpret_cast<const char* (*)(CGNS_ENUMT(AngleUnits_t) type)>(sym_cg_AngleUnitsName);
#ifdef _WIN32
        auto sym_cg_ElectricCurrentUnitsName = GetProcAddress(handle_, "cg_ElectricCurrentUnitsName");
        if (!sym_cg_ElectricCurrentUnitsName)
            throw std::runtime_error("cg_ElectricCurrentUnitsName not found");
#else
        auto sym_cg_ElectricCurrentUnitsName = dlsym(handle_, "cg_ElectricCurrentUnitsName");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_ElectricCurrentUnitsName_ =
        reinterpret_cast<const char* (*)(CGNS_ENUMT(ElectricCurrentUnits_t) type)>(sym_cg_ElectricCurrentUnitsName);
#ifdef _WIN32
        auto sym_cg_SubstanceAmountUnitsName = GetProcAddress(handle_, "cg_SubstanceAmountUnitsName");
        if (!sym_cg_SubstanceAmountUnitsName)
            throw std::runtime_error("cg_SubstanceAmountUnitsName not found");
#else
        auto sym_cg_SubstanceAmountUnitsName = dlsym(handle_, "cg_SubstanceAmountUnitsName");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_SubstanceAmountUnitsName_ =
        reinterpret_cast<const char* (*)(CGNS_ENUMT(SubstanceAmountUnits_t) type)>(sym_cg_SubstanceAmountUnitsName);
#ifdef _WIN32
        auto sym_cg_LuminousIntensityUnitsName = GetProcAddress(handle_, "cg_LuminousIntensityUnitsName");
        if (!sym_cg_LuminousIntensityUnitsName)
            throw std::runtime_error("cg_LuminousIntensityUnitsName not found");
#else
        auto sym_cg_LuminousIntensityUnitsName = dlsym(handle_, "cg_LuminousIntensityUnitsName");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_LuminousIntensityUnitsName_ =
        reinterpret_cast<const char* (*)(CGNS_ENUMT(LuminousIntensityUnits_t) type)>(sym_cg_LuminousIntensityUnitsName);
#ifdef _WIN32
        auto sym_cg_DataClassName = GetProcAddress(handle_, "cg_DataClassName");
        if (!sym_cg_DataClassName)
            throw std::runtime_error("cg_DataClassName not found");
#else
        auto sym_cg_DataClassName = dlsym(handle_, "cg_DataClassName");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_DataClassName_ = reinterpret_cast<const char* (*)(CGNS_ENUMT(DataClass_t) type)>(sym_cg_DataClassName);
#ifdef _WIN32
        auto sym_cg_GridLocationName = GetProcAddress(handle_, "cg_GridLocationName");
        if (!sym_cg_GridLocationName)
            throw std::runtime_error("cg_GridLocationName not found");
#else
        auto sym_cg_GridLocationName = dlsym(handle_, "cg_GridLocationName");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_GridLocationName_ = reinterpret_cast<const char* (*)(CGNS_ENUMT(GridLocation_t) type)>(sym_cg_GridLocationName);
#ifdef _WIN32
        auto sym_cg_BCDataTypeName = GetProcAddress(handle_, "cg_BCDataTypeName");
        if (!sym_cg_BCDataTypeName)
            throw std::runtime_error("cg_BCDataTypeName not found");
#else
        auto sym_cg_BCDataTypeName = dlsym(handle_, "cg_BCDataTypeName");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_BCDataTypeName_ = reinterpret_cast<const char* (*)(CGNS_ENUMT(BCDataType_t) type)>(sym_cg_BCDataTypeName);
#ifdef _WIN32
        auto sym_cg_GridConnectivityTypeName = GetProcAddress(handle_, "cg_GridConnectivityTypeName");
        if (!sym_cg_GridConnectivityTypeName)
            throw std::runtime_error("cg_GridConnectivityTypeName not found");
#else
        auto sym_cg_GridConnectivityTypeName = dlsym(handle_, "cg_GridConnectivityTypeName");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_GridConnectivityTypeName_ =
        reinterpret_cast<const char* (*)(CGNS_ENUMT(GridConnectivityType_t) type)>(sym_cg_GridConnectivityTypeName);
#ifdef _WIN32
        auto sym_cg_PointSetTypeName = GetProcAddress(handle_, "cg_PointSetTypeName");
        if (!sym_cg_PointSetTypeName)
            throw std::runtime_error("cg_PointSetTypeName not found");
#else
        auto sym_cg_PointSetTypeName = dlsym(handle_, "cg_PointSetTypeName");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_PointSetTypeName_ = reinterpret_cast<const char* (*)(CGNS_ENUMT(PointSetType_t) type)>(sym_cg_PointSetTypeName);
#ifdef _WIN32
        auto sym_cg_GoverningEquationsTypeName = GetProcAddress(handle_, "cg_GoverningEquationsTypeName");
        if (!sym_cg_GoverningEquationsTypeName)
            throw std::runtime_error("cg_GoverningEquationsTypeName not found");
#else
        auto sym_cg_GoverningEquationsTypeName = dlsym(handle_, "cg_GoverningEquationsTypeName");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_GoverningEquationsTypeName_ =
        reinterpret_cast<const char* (*)(CGNS_ENUMT(GoverningEquationsType_t) type)>(sym_cg_GoverningEquationsTypeName);
#ifdef _WIN32
        auto sym_cg_ModelTypeName = GetProcAddress(handle_, "cg_ModelTypeName");
        if (!sym_cg_ModelTypeName)
            throw std::runtime_error("cg_ModelTypeName not found");
#else
        auto sym_cg_ModelTypeName = dlsym(handle_, "cg_ModelTypeName");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_ModelTypeName_ = reinterpret_cast<const char* (*)(CGNS_ENUMT(ModelType_t) type)>(sym_cg_ModelTypeName);
#ifdef _WIN32
        auto sym_cg_BCTypeName = GetProcAddress(handle_, "cg_BCTypeName");
        if (!sym_cg_BCTypeName)
            throw std::runtime_error("cg_BCTypeName not found");
#else
        auto sym_cg_BCTypeName = dlsym(handle_, "cg_BCTypeName");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_BCTypeName_ = reinterpret_cast<const char* (*)(CGNS_ENUMT(BCType_t) type)>(sym_cg_BCTypeName);
#ifdef _WIN32
        auto sym_cg_DataTypeName = GetProcAddress(handle_, "cg_DataTypeName");
        if (!sym_cg_DataTypeName)
            throw std::runtime_error("cg_DataTypeName not found");
#else
        auto sym_cg_DataTypeName = dlsym(handle_, "cg_DataTypeName");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_DataTypeName_ = reinterpret_cast<const char* (*)(CGNS_ENUMT(DataType_t) type)>(sym_cg_DataTypeName);
#ifdef _WIN32
        auto sym_cg_ElementTypeName = GetProcAddress(handle_, "cg_ElementTypeName");
        if (!sym_cg_ElementTypeName)
            throw std::runtime_error("cg_ElementTypeName not found");
#else
        auto sym_cg_ElementTypeName = dlsym(handle_, "cg_ElementTypeName");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_ElementTypeName_ = reinterpret_cast<const char* (*)(CGNS_ENUMT(ElementType_t) type)>(sym_cg_ElementTypeName);
#ifdef _WIN32
        auto sym_cg_ZoneTypeName = GetProcAddress(handle_, "cg_ZoneTypeName");
        if (!sym_cg_ZoneTypeName)
            throw std::runtime_error("cg_ZoneTypeName not found");
#else
        auto sym_cg_ZoneTypeName = dlsym(handle_, "cg_ZoneTypeName");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_ZoneTypeName_ = reinterpret_cast<const char* (*)(CGNS_ENUMT(ZoneType_t) type)>(sym_cg_ZoneTypeName);
#ifdef _WIN32
        auto sym_cg_RigidGridMotionTypeName = GetProcAddress(handle_, "cg_RigidGridMotionTypeName");
        if (!sym_cg_RigidGridMotionTypeName)
            throw std::runtime_error("cg_RigidGridMotionTypeName not found");
#else
        auto sym_cg_RigidGridMotionTypeName = dlsym(handle_, "cg_RigidGridMotionTypeName");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_RigidGridMotionTypeName_ =
        reinterpret_cast<const char* (*)(CGNS_ENUMT(RigidGridMotionType_t) type)>(sym_cg_RigidGridMotionTypeName);
#ifdef _WIN32
        auto sym_cg_ArbitraryGridMotionTypeName = GetProcAddress(handle_, "cg_ArbitraryGridMotionTypeName");
        if (!sym_cg_ArbitraryGridMotionTypeName)
            throw std::runtime_error("cg_ArbitraryGridMotionTypeName not found");
#else
        auto sym_cg_ArbitraryGridMotionTypeName = dlsym(handle_, "cg_ArbitraryGridMotionTypeName");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_ArbitraryGridMotionTypeName_ =
        reinterpret_cast<const char* (*)(CGNS_ENUMT(ArbitraryGridMotionType_t) type)>(sym_cg_ArbitraryGridMotionTypeName);
#ifdef _WIN32
        auto sym_cg_SimulationTypeName = GetProcAddress(handle_, "cg_SimulationTypeName");
        if (!sym_cg_SimulationTypeName)
            throw std::runtime_error("cg_SimulationTypeName not found");
#else
        auto sym_cg_SimulationTypeName = dlsym(handle_, "cg_SimulationTypeName");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_SimulationTypeName_ = reinterpret_cast<const char* (*)(CGNS_ENUMT(SimulationType_t) type)>(sym_cg_SimulationTypeName);
#ifdef _WIN32
        auto sym_cg_WallFunctionTypeName = GetProcAddress(handle_, "cg_WallFunctionTypeName");
        if (!sym_cg_WallFunctionTypeName)
            throw std::runtime_error("cg_WallFunctionTypeName not found");
#else
        auto sym_cg_WallFunctionTypeName = dlsym(handle_, "cg_WallFunctionTypeName");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_WallFunctionTypeName_ =
        reinterpret_cast<const char* (*)(CGNS_ENUMT(WallFunctionType_t) type)>(sym_cg_WallFunctionTypeName);
#ifdef _WIN32
        auto sym_cg_AreaTypeName = GetProcAddress(handle_, "cg_AreaTypeName");
        if (!sym_cg_AreaTypeName)
            throw std::runtime_error("cg_AreaTypeName not found");
#else
        auto sym_cg_AreaTypeName = dlsym(handle_, "cg_AreaTypeName");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_AreaTypeName_ = reinterpret_cast<const char* (*)(CGNS_ENUMT(AreaType_t) type)>(sym_cg_AreaTypeName);
#ifdef _WIN32
        auto sym_cg_AverageInterfaceTypeName = GetProcAddress(handle_, "cg_AverageInterfaceTypeName");
        if (!sym_cg_AverageInterfaceTypeName)
            throw std::runtime_error("cg_AverageInterfaceTypeName not found");
#else
        auto sym_cg_AverageInterfaceTypeName = dlsym(handle_, "cg_AverageInterfaceTypeName");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_AverageInterfaceTypeName_ =
        reinterpret_cast<const char* (*)(CGNS_ENUMT(AverageInterfaceType_t) type)>(sym_cg_AverageInterfaceTypeName);
#ifdef _WIN32
        auto sym_cg_nbases = GetProcAddress(handle_, "cg_nbases");
        if (!sym_cg_nbases)
            throw std::runtime_error("cg_nbases not found");
#else
        auto sym_cg_nbases = dlsym(handle_, "cg_nbases");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_nbases_ = reinterpret_cast<int (*)(int fn, int* nbases)>(sym_cg_nbases);
#ifdef _WIN32
        auto sym_cg_base_read = GetProcAddress(handle_, "cg_base_read");
        if (!sym_cg_base_read)
            throw std::runtime_error("cg_base_read not found");
#else
        auto sym_cg_base_read = dlsym(handle_, "cg_base_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_base_read_ =
        reinterpret_cast<int (*)(int file_number, int B, char* basename, int* cell_dim, int* phys_dim)>(sym_cg_base_read);
#ifdef _WIN32
        auto sym_cg_base_id = GetProcAddress(handle_, "cg_base_id");
        if (!sym_cg_base_id)
            throw std::runtime_error("cg_base_id not found");
#else
        auto sym_cg_base_id = dlsym(handle_, "cg_base_id");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_base_id_ = reinterpret_cast<int (*)(int fn, int B, double* base_id)>(sym_cg_base_id);
#ifdef _WIN32
        auto sym_cg_base_write = GetProcAddress(handle_, "cg_base_write");
        if (!sym_cg_base_write)
            throw std::runtime_error("cg_base_write not found");
#else
        auto sym_cg_base_write = dlsym(handle_, "cg_base_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_base_write_ =
        reinterpret_cast<int (*)(int file_number, const char* basename, int cell_dim, int phys_dim, int* B)>(sym_cg_base_write);
#ifdef _WIN32
        auto sym_cg_cell_dim = GetProcAddress(handle_, "cg_cell_dim");
        if (!sym_cg_cell_dim)
            throw std::runtime_error("cg_cell_dim not found");
#else
        auto sym_cg_cell_dim = dlsym(handle_, "cg_cell_dim");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_cell_dim_ = reinterpret_cast<int (*)(int fn, int B, int* cell_dim)>(sym_cg_cell_dim);
#ifdef _WIN32
        auto sym_cg_nzones = GetProcAddress(handle_, "cg_nzones");
        if (!sym_cg_nzones)
            throw std::runtime_error("cg_nzones not found");
#else
        auto sym_cg_nzones = dlsym(handle_, "cg_nzones");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_nzones_ = reinterpret_cast<int (*)(int fn, int B, int* nzones)>(sym_cg_nzones);
#ifdef _WIN32
        auto sym_cg_zone_read = GetProcAddress(handle_, "cg_zone_read");
        if (!sym_cg_zone_read)
            throw std::runtime_error("cg_zone_read not found");
#else
        auto sym_cg_zone_read = dlsym(handle_, "cg_zone_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_zone_read_ = reinterpret_cast<int (*)(int fn, int B, int Z, char* zonename, cgsize_t* size)>(sym_cg_zone_read);
#ifdef _WIN32
        auto sym_cg_zone_type = GetProcAddress(handle_, "cg_zone_type");
        if (!sym_cg_zone_type)
            throw std::runtime_error("cg_zone_type not found");
#else
        auto sym_cg_zone_type = dlsym(handle_, "cg_zone_type");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_zone_type_ = reinterpret_cast<int (*)(int file_number, int B, int Z, CGNS_ENUMT(ZoneType_t) * type)>(sym_cg_zone_type);
#ifdef _WIN32
        auto sym_cg_zone_id = GetProcAddress(handle_, "cg_zone_id");
        if (!sym_cg_zone_id)
            throw std::runtime_error("cg_zone_id not found");
#else
        auto sym_cg_zone_id = dlsym(handle_, "cg_zone_id");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_zone_id_ = reinterpret_cast<int (*)(int fn, int B, int Z, double* zone_id)>(sym_cg_zone_id);
#ifdef _WIN32
        auto sym_cg_zone_write = GetProcAddress(handle_, "cg_zone_write");
        if (!sym_cg_zone_write)
            throw std::runtime_error("cg_zone_write not found");
#else
        auto sym_cg_zone_write = dlsym(handle_, "cg_zone_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_zone_write_ =
        reinterpret_cast<int (*)(int fn, int B, const char* zonename, const cgsize_t* size, CGNS_ENUMT(ZoneType_t) type, int* Z)>(
        sym_cg_zone_write);
#ifdef _WIN32
        auto sym_cg_index_dim = GetProcAddress(handle_, "cg_index_dim");
        if (!sym_cg_index_dim)
            throw std::runtime_error("cg_index_dim not found");
#else
        auto sym_cg_index_dim = dlsym(handle_, "cg_index_dim");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_index_dim_ = reinterpret_cast<int (*)(int fn, int B, int Z, int* index_dim)>(sym_cg_index_dim);
#ifdef _WIN32
        auto sym_cg_nfamilies = GetProcAddress(handle_, "cg_nfamilies");
        if (!sym_cg_nfamilies)
            throw std::runtime_error("cg_nfamilies not found");
#else
        auto sym_cg_nfamilies = dlsym(handle_, "cg_nfamilies");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_nfamilies_ = reinterpret_cast<int (*)(int file_number, int B, int* nfamilies)>(sym_cg_nfamilies);
#ifdef _WIN32
        auto sym_cg_family_read = GetProcAddress(handle_, "cg_family_read");
        if (!sym_cg_family_read)
            throw std::runtime_error("cg_family_read not found");
#else
        auto sym_cg_family_read = dlsym(handle_, "cg_family_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_family_read_ =
        reinterpret_cast<int (*)(int file_number, int B, int F, char* family_name, int* nboco, int* ngeos)>(sym_cg_family_read);
#ifdef _WIN32
        auto sym_cg_family_write = GetProcAddress(handle_, "cg_family_write");
        if (!sym_cg_family_write)
            throw std::runtime_error("cg_family_write not found");
#else
        auto sym_cg_family_write = dlsym(handle_, "cg_family_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_family_write_ =
        reinterpret_cast<int (*)(int file_number, int B, const char* family_name, int* F)>(sym_cg_family_write);
#ifdef _WIN32
        auto sym_cg_nfamily_names = GetProcAddress(handle_, "cg_nfamily_names");
        if (!sym_cg_nfamily_names)
            throw std::runtime_error("cg_nfamily_names not found");
#else
        auto sym_cg_nfamily_names = dlsym(handle_, "cg_nfamily_names");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_nfamily_names_ = reinterpret_cast<int (*)(int file_number, int B, int F, int* nnames)>(sym_cg_nfamily_names);
#ifdef _WIN32
        auto sym_cg_family_name_read = GetProcAddress(handle_, "cg_family_name_read");
        if (!sym_cg_family_name_read)
            throw std::runtime_error("cg_family_name_read not found");
#else
        auto sym_cg_family_name_read = dlsym(handle_, "cg_family_name_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_family_name_read_ =
        reinterpret_cast<int (*)(int file_number, int B, int F, int N, char* name, char* family)>(sym_cg_family_name_read);
#ifdef _WIN32
        auto sym_cg_family_name_write = GetProcAddress(handle_, "cg_family_name_write");
        if (!sym_cg_family_name_write)
            throw std::runtime_error("cg_family_name_write not found");
#else
        auto sym_cg_family_name_write = dlsym(handle_, "cg_family_name_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_family_name_write_ =
        reinterpret_cast<int (*)(int file_number, int B, int F, const char* name, const char* family)>(sym_cg_family_name_write);
#ifdef _WIN32
        auto sym_cg_node_family_write = GetProcAddress(handle_, "cg_node_family_write");
        if (!sym_cg_node_family_write)
            throw std::runtime_error("cg_node_family_write not found");
#else
        auto sym_cg_node_family_write = dlsym(handle_, "cg_node_family_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_node_family_write_ = reinterpret_cast<int (*)(const char* family_name, int* F)>(sym_cg_node_family_write);
#ifdef _WIN32
        auto sym_cg_node_nfamilies = GetProcAddress(handle_, "cg_node_nfamilies");
        if (!sym_cg_node_nfamilies)
            throw std::runtime_error("cg_node_nfamilies not found");
#else
        auto sym_cg_node_nfamilies = dlsym(handle_, "cg_node_nfamilies");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_node_nfamilies_ = reinterpret_cast<int (*)(int* nfamilies)>(sym_cg_node_nfamilies);
#ifdef _WIN32
        auto sym_cg_node_family_read = GetProcAddress(handle_, "cg_node_family_read");
        if (!sym_cg_node_family_read)
            throw std::runtime_error("cg_node_family_read not found");
#else
        auto sym_cg_node_family_read = dlsym(handle_, "cg_node_family_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_node_family_read_ =
        reinterpret_cast<int (*)(int F, char* family_name, int* nFamBC, int* nGeo)>(sym_cg_node_family_read);
#ifdef _WIN32
        auto sym_cg_node_family_name_write = GetProcAddress(handle_, "cg_node_family_name_write");
        if (!sym_cg_node_family_name_write)
            throw std::runtime_error("cg_node_family_name_write not found");
#else
        auto sym_cg_node_family_name_write = dlsym(handle_, "cg_node_family_name_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_node_family_name_write_ =
        reinterpret_cast<int (*)(const char* node_name, const char* family_name)>(sym_cg_node_family_name_write);
#ifdef _WIN32
        auto sym_cg_node_nfamily_names = GetProcAddress(handle_, "cg_node_nfamily_names");
        if (!sym_cg_node_nfamily_names)
            throw std::runtime_error("cg_node_nfamily_names not found");
#else
        auto sym_cg_node_nfamily_names = dlsym(handle_, "cg_node_nfamily_names");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_node_nfamily_names_ = reinterpret_cast<int (*)(int* nnames)>(sym_cg_node_nfamily_names);
#ifdef _WIN32
        auto sym_cg_node_family_name_read = GetProcAddress(handle_, "cg_node_family_name_read");
        if (!sym_cg_node_family_name_read)
            throw std::runtime_error("cg_node_family_name_read not found");
#else
        auto sym_cg_node_family_name_read = dlsym(handle_, "cg_node_family_name_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_node_family_name_read_ =
        reinterpret_cast<int (*)(int N, char* node_name, char* family_name)>(sym_cg_node_family_name_read);
#ifdef _WIN32
        auto sym_cg_famname_read = GetProcAddress(handle_, "cg_famname_read");
        if (!sym_cg_famname_read)
            throw std::runtime_error("cg_famname_read not found");
#else
        auto sym_cg_famname_read = dlsym(handle_, "cg_famname_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_famname_read_ = reinterpret_cast<int (*)(char* family_name)>(sym_cg_famname_read);
#ifdef _WIN32
        auto sym_cg_famname_write = GetProcAddress(handle_, "cg_famname_write");
        if (!sym_cg_famname_write)
            throw std::runtime_error("cg_famname_write not found");
#else
        auto sym_cg_famname_write = dlsym(handle_, "cg_famname_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_famname_write_ = reinterpret_cast<int (*)(const char* family_name)>(sym_cg_famname_write);
#ifdef _WIN32
        auto sym_cg_nmultifam = GetProcAddress(handle_, "cg_nmultifam");
        if (!sym_cg_nmultifam)
            throw std::runtime_error("cg_nmultifam not found");
#else
        auto sym_cg_nmultifam = dlsym(handle_, "cg_nmultifam");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_nmultifam_ = reinterpret_cast<int (*)(int* nfams)>(sym_cg_nmultifam);
#ifdef _WIN32
        auto sym_cg_multifam_read = GetProcAddress(handle_, "cg_multifam_read");
        if (!sym_cg_multifam_read)
            throw std::runtime_error("cg_multifam_read not found");
#else
        auto sym_cg_multifam_read = dlsym(handle_, "cg_multifam_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_multifam_read_ = reinterpret_cast<int (*)(int N, char* name, char* family)>(sym_cg_multifam_read);
#ifdef _WIN32
        auto sym_cg_multifam_write = GetProcAddress(handle_, "cg_multifam_write");
        if (!sym_cg_multifam_write)
            throw std::runtime_error("cg_multifam_write not found");
#else
        auto sym_cg_multifam_write = dlsym(handle_, "cg_multifam_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_multifam_write_ = reinterpret_cast<int (*)(const char* name, const char* family)>(sym_cg_multifam_write);
#ifdef _WIN32
        auto sym_cg_fambc_read = GetProcAddress(handle_, "cg_fambc_read");
        if (!sym_cg_fambc_read)
            throw std::runtime_error("cg_fambc_read not found");
#else
        auto sym_cg_fambc_read = dlsym(handle_, "cg_fambc_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_fambc_read_ =
        reinterpret_cast<int (*)(int file_number, int B, int F, int BC, char* fambc_name, CGNS_ENUMT(BCType_t) * bocotype)>(
        sym_cg_fambc_read);
#ifdef _WIN32
        auto sym_cg_fambc_write = GetProcAddress(handle_, "cg_fambc_write");
        if (!sym_cg_fambc_write)
            throw std::runtime_error("cg_fambc_write not found");
#else
        auto sym_cg_fambc_write = dlsym(handle_, "cg_fambc_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_fambc_write_ =
        reinterpret_cast<int (*)(int file_number, int B, int F, const char* fambc_name, CGNS_ENUMT(BCType_t) bocotype, int* BC)>(
        sym_cg_fambc_write);
#ifdef _WIN32
        auto sym_cg_node_fambc_read = GetProcAddress(handle_, "cg_node_fambc_read");
        if (!sym_cg_node_fambc_read)
            throw std::runtime_error("cg_node_fambc_read not found");
#else
        auto sym_cg_node_fambc_read = dlsym(handle_, "cg_node_fambc_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_node_fambc_read_ =
        reinterpret_cast<int (*)(int BC, char* fambc_name, CGNS_ENUMT(BCType_t) * bocotype)>(sym_cg_node_fambc_read);
#ifdef _WIN32
        auto sym_cg_node_fambc_write = GetProcAddress(handle_, "cg_node_fambc_write");
        if (!sym_cg_node_fambc_write)
            throw std::runtime_error("cg_node_fambc_write not found");
#else
        auto sym_cg_node_fambc_write = dlsym(handle_, "cg_node_fambc_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_node_fambc_write_ =
        reinterpret_cast<int (*)(const char* fambc_name, CGNS_ENUMT(BCType_t) bocotype, int* BC)>(sym_cg_node_fambc_write);
#ifdef _WIN32
        auto sym_cg_geo_read = GetProcAddress(handle_, "cg_geo_read");
        if (!sym_cg_geo_read)
            throw std::runtime_error("cg_geo_read not found");
#else
        auto sym_cg_geo_read = dlsym(handle_, "cg_geo_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_geo_read_ = reinterpret_cast<int (*)(int file_number, int B, int F, int G, char* geo_name, char** geo_file,
                                                char* CAD_name, int* npart)>(sym_cg_geo_read);
#ifdef _WIN32
        auto sym_cg_geo_write = GetProcAddress(handle_, "cg_geo_write");
        if (!sym_cg_geo_write)
            throw std::runtime_error("cg_geo_write not found");
#else
        auto sym_cg_geo_write = dlsym(handle_, "cg_geo_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_geo_write_ = reinterpret_cast<int (*)(int file_number, int B, int F, const char* geo_name, const char* filename,
                                                 const char* CADname, int* G)>(sym_cg_geo_write);
#ifdef _WIN32
        auto sym_cg_node_geo_read = GetProcAddress(handle_, "cg_node_geo_read");
        if (!sym_cg_node_geo_read)
            throw std::runtime_error("cg_node_geo_read not found");
#else
        auto sym_cg_node_geo_read = dlsym(handle_, "cg_node_geo_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_node_geo_read_ =
        reinterpret_cast<int (*)(int G, char* geo_name, char** geo_file, char* CAD_name, int* npart)>(sym_cg_node_geo_read);
#ifdef _WIN32
        auto sym_cg_node_geo_write = GetProcAddress(handle_, "cg_node_geo_write");
        if (!sym_cg_node_geo_write)
            throw std::runtime_error("cg_node_geo_write not found");
#else
        auto sym_cg_node_geo_write = dlsym(handle_, "cg_node_geo_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_node_geo_write_ =
        reinterpret_cast<int (*)(const char* geo_name, const char* filename, const char* CADname, int* G)>(sym_cg_node_geo_write);
#ifdef _WIN32
        auto sym_cg_part_read = GetProcAddress(handle_, "cg_part_read");
        if (!sym_cg_part_read)
            throw std::runtime_error("cg_part_read not found");
#else
        auto sym_cg_part_read = dlsym(handle_, "cg_part_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_part_read_ = reinterpret_cast<int (*)(int file_number, int B, int F, int G, int P, char* part_name)>(sym_cg_part_read);
#ifdef _WIN32
        auto sym_cg_part_write = GetProcAddress(handle_, "cg_part_write");
        if (!sym_cg_part_write)
            throw std::runtime_error("cg_part_write not found");
#else
        auto sym_cg_part_write = dlsym(handle_, "cg_part_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_part_write_ =
        reinterpret_cast<int (*)(int file_number, int B, int F, int G, const char* part_name, int* P)>(sym_cg_part_write);
#ifdef _WIN32
        auto sym_cg_node_part_read = GetProcAddress(handle_, "cg_node_part_read");
        if (!sym_cg_node_part_read)
            throw std::runtime_error("cg_node_part_read not found");
#else
        auto sym_cg_node_part_read = dlsym(handle_, "cg_node_part_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_node_part_read_ = reinterpret_cast<int (*)(int G, int P, char* part_name)>(sym_cg_node_part_read);
#ifdef _WIN32
        auto sym_cg_node_part_write = GetProcAddress(handle_, "cg_node_part_write");
        if (!sym_cg_node_part_write)
            throw std::runtime_error("cg_node_part_write not found");
#else
        auto sym_cg_node_part_write = dlsym(handle_, "cg_node_part_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_node_part_write_ = reinterpret_cast<int (*)(int G, const char* part_name, int* P)>(sym_cg_node_part_write);
#ifdef _WIN32
        auto sym_cg_ngrids = GetProcAddress(handle_, "cg_ngrids");
        if (!sym_cg_ngrids)
            throw std::runtime_error("cg_ngrids not found");
#else
        auto sym_cg_ngrids = dlsym(handle_, "cg_ngrids");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_ngrids_ = reinterpret_cast<int (*)(int file_number, int B, int Z, int* ngrids)>(sym_cg_ngrids);
#ifdef _WIN32
        auto sym_cg_grid_read = GetProcAddress(handle_, "cg_grid_read");
        if (!sym_cg_grid_read)
            throw std::runtime_error("cg_grid_read not found");
#else
        auto sym_cg_grid_read = dlsym(handle_, "cg_grid_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_grid_read_ = reinterpret_cast<int (*)(int file_number, int B, int Z, int G, char* gridname)>(sym_cg_grid_read);
#ifdef _WIN32
        auto sym_cg_grid_write = GetProcAddress(handle_, "cg_grid_write");
        if (!sym_cg_grid_write)
            throw std::runtime_error("cg_grid_write not found");
#else
        auto sym_cg_grid_write = dlsym(handle_, "cg_grid_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_grid_write_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, const char* zcoorname, int* G)>(sym_cg_grid_write);
#ifdef _WIN32
        auto sym_cg_grid_bounding_box_read = GetProcAddress(handle_, "cg_grid_bounding_box_read");
        if (!sym_cg_grid_bounding_box_read)
            throw std::runtime_error("cg_grid_bounding_box_read not found");
#else
        auto sym_cg_grid_bounding_box_read = dlsym(handle_, "cg_grid_bounding_box_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_grid_bounding_box_read_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int G, CGNS_ENUMT(DataType_t) type, void* boundingbox)>(
        sym_cg_grid_bounding_box_read);
#ifdef _WIN32
        auto sym_cg_grid_bounding_box_write = GetProcAddress(handle_, "cg_grid_bounding_box_write");
        if (!sym_cg_grid_bounding_box_write)
            throw std::runtime_error("cg_grid_bounding_box_write not found");
#else
        auto sym_cg_grid_bounding_box_write = dlsym(handle_, "cg_grid_bounding_box_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_grid_bounding_box_write_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int G, CGNS_ENUMT(DataType_t) type, void* boundingbox)>(
        sym_cg_grid_bounding_box_write);
#ifdef _WIN32
        auto sym_cg_ncoords = GetProcAddress(handle_, "cg_ncoords");
        if (!sym_cg_ncoords)
            throw std::runtime_error("cg_ncoords not found");
#else
        auto sym_cg_ncoords = dlsym(handle_, "cg_ncoords");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_ncoords_ = reinterpret_cast<int (*)(int fn, int B, int Z, int* ncoords)>(sym_cg_ncoords);
#ifdef _WIN32
        auto sym_cg_coord_info = GetProcAddress(handle_, "cg_coord_info");
        if (!sym_cg_coord_info)
            throw std::runtime_error("cg_coord_info not found");
#else
        auto sym_cg_coord_info = dlsym(handle_, "cg_coord_info");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_coord_info_ =
        reinterpret_cast<int (*)(int fn, int B, int Z, int C, CGNS_ENUMT(DataType_t) * type, char* coordname)>(sym_cg_coord_info);
#ifdef _WIN32
        auto sym_cg_coord_read = GetProcAddress(handle_, "cg_coord_read");
        if (!sym_cg_coord_read)
            throw std::runtime_error("cg_coord_read not found");
#else
        auto sym_cg_coord_read = dlsym(handle_, "cg_coord_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_coord_read_ = reinterpret_cast<int (*)(int fn, int B, int Z, const char* coordname, CGNS_ENUMT(DataType_t) type,
                                                  const cgsize_t* rmin, const cgsize_t* rmax, void* coord)>(sym_cg_coord_read);
#ifdef _WIN32
        auto sym_cg_coord_general_read = GetProcAddress(handle_, "cg_coord_general_read");
        if (!sym_cg_coord_general_read)
            throw std::runtime_error("cg_coord_general_read not found");
#else
        auto sym_cg_coord_general_read = dlsym(handle_, "cg_coord_general_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_coord_general_read_ =
        reinterpret_cast<int (*)(int fn, int B, int Z, const char* coordname, const cgsize_t* s_rmin, const cgsize_t* s_rmax,
                                 CGNS_ENUMT(DataType_t) m_type, int m_numdim, const cgsize_t* m_dimvals, const cgsize_t* m_rmin,
                                 const cgsize_t* m_rmax, void* coord_ptr)>(sym_cg_coord_general_read);
#ifdef _WIN32
        auto sym_cg_coord_id = GetProcAddress(handle_, "cg_coord_id");
        if (!sym_cg_coord_id)
            throw std::runtime_error("cg_coord_id not found");
#else
        auto sym_cg_coord_id = dlsym(handle_, "cg_coord_id");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_coord_id_ = reinterpret_cast<int (*)(int fn, int B, int Z, int C, double* coord_id)>(sym_cg_coord_id);
#ifdef _WIN32
        auto sym_cg_coord_write = GetProcAddress(handle_, "cg_coord_write");
        if (!sym_cg_coord_write)
            throw std::runtime_error("cg_coord_write not found");
#else
        auto sym_cg_coord_write = dlsym(handle_, "cg_coord_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_coord_write_ = reinterpret_cast<int (*)(int fn, int B, int Z, CGNS_ENUMT(DataType_t) type, const char* coordname,
                                                   const void* coord_ptr, int* C)>(sym_cg_coord_write);
#ifdef _WIN32
        auto sym_cg_coord_partial_write = GetProcAddress(handle_, "cg_coord_partial_write");
        if (!sym_cg_coord_partial_write)
            throw std::runtime_error("cg_coord_partial_write not found");
#else
        auto sym_cg_coord_partial_write = dlsym(handle_, "cg_coord_partial_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_coord_partial_write_ =
        reinterpret_cast<int (*)(int fn, int B, int Z, CGNS_ENUMT(DataType_t) type, const char* coordname, const cgsize_t* rmin,
                                 const cgsize_t* rmax, const void* coord_ptr, int* C)>(sym_cg_coord_partial_write);
#ifdef _WIN32
        auto sym_cg_coord_general_write = GetProcAddress(handle_, "cg_coord_general_write");
        if (!sym_cg_coord_general_write)
            throw std::runtime_error("cg_coord_general_write not found");
#else
        auto sym_cg_coord_general_write = dlsym(handle_, "cg_coord_general_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_coord_general_write_ =
        reinterpret_cast<int (*)(int fn, int B, int Z, const char* coordname, CGNS_ENUMT(DataType_t) s_type, const cgsize_t* rmin,
                                 const cgsize_t* rmax, CGNS_ENUMT(DataType_t) m_type, int m_numdim, const cgsize_t* m_dims,
                                 const cgsize_t* m_rmin, const cgsize_t* m_rmax, const void* coord_ptr, int* C)>(
        sym_cg_coord_general_write);
#ifdef _WIN32
        auto sym_cg_nsections = GetProcAddress(handle_, "cg_nsections");
        if (!sym_cg_nsections)
            throw std::runtime_error("cg_nsections not found");
#else
        auto sym_cg_nsections = dlsym(handle_, "cg_nsections");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_nsections_ = reinterpret_cast<int (*)(int file_number, int B, int Z, int* nsections)>(sym_cg_nsections);
#ifdef _WIN32
        auto sym_cg_section_read = GetProcAddress(handle_, "cg_section_read");
        if (!sym_cg_section_read)
            throw std::runtime_error("cg_section_read not found");
#else
        auto sym_cg_section_read = dlsym(handle_, "cg_section_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_section_read_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int S, char* SectionName, CGNS_ENUMT(ElementType_t) * type,
                                 cgsize_t * start, cgsize_t * end, int* nbndry, int* parent_flag)>(sym_cg_section_read);
#ifdef _WIN32
        auto sym_cg_elements_read = GetProcAddress(handle_, "cg_elements_read");
        if (!sym_cg_elements_read)
            throw std::runtime_error("cg_elements_read not found");
#else
        auto sym_cg_elements_read = dlsym(handle_, "cg_elements_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_elements_read_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int S, cgsize_t* elements, cgsize_t* parent_data)>(
        sym_cg_elements_read);
#ifdef _WIN32
        auto sym_cg_poly_elements_read = GetProcAddress(handle_, "cg_poly_elements_read");
        if (!sym_cg_poly_elements_read)
            throw std::runtime_error("cg_poly_elements_read not found");
#else
        auto sym_cg_poly_elements_read = dlsym(handle_, "cg_poly_elements_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_poly_elements_read_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int S, cgsize_t* elements, cgsize_t* connect_offset,
                                 cgsize_t* parent_data)>(sym_cg_poly_elements_read);
#ifdef _WIN32
        auto sym_cg_section_write = GetProcAddress(handle_, "cg_section_write");
        if (!sym_cg_section_write)
            throw std::runtime_error("cg_section_write not found");
#else
        auto sym_cg_section_write = dlsym(handle_, "cg_section_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_section_write_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, const char* SectionName, CGNS_ENUMT(ElementType_t) type,
                                 cgsize_t start, cgsize_t end, int nbndry, const cgsize_t* elements, int* S)>(
        sym_cg_section_write);
#ifdef _WIN32
        auto sym_cg_poly_section_write = GetProcAddress(handle_, "cg_poly_section_write");
        if (!sym_cg_poly_section_write)
            throw std::runtime_error("cg_poly_section_write not found");
#else
        auto sym_cg_poly_section_write = dlsym(handle_, "cg_poly_section_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_poly_section_write_ = reinterpret_cast<int (*)(
        int file_number, int B, int Z, const char* SectionName, CGNS_ENUMT(ElementType_t) type, cgsize_t start, cgsize_t end,
        int nbndry, const cgsize_t* elements, const cgsize_t* connect_offset, int* S)>(sym_cg_poly_section_write);
#ifdef _WIN32
        auto sym_cg_section_general_write = GetProcAddress(handle_, "cg_section_general_write");
        if (!sym_cg_section_general_write)
            throw std::runtime_error("cg_section_general_write not found");
#else
        auto sym_cg_section_general_write = dlsym(handle_, "cg_section_general_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_section_general_write_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, const char* SectionName, const CGNS_ENUMT(ElementType_t) type,
                                 const CGNS_ENUMT(DataType_t) elementDataType, cgsize_t start, cgsize_t end,
                                 cgsize_t elementDataSize, int nbndry, int* S)>(sym_cg_section_general_write);
#ifdef _WIN32
        auto sym_cg_section_initialize = GetProcAddress(handle_, "cg_section_initialize");
        if (!sym_cg_section_initialize)
            throw std::runtime_error("cg_section_initialize not found");
#else
        auto sym_cg_section_initialize = dlsym(handle_, "cg_section_initialize");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_section_initialize_ = reinterpret_cast<int (*)(int file_number, int B, int Z, int S)>(sym_cg_section_initialize);
#ifdef _WIN32
        auto sym_cg_parent_data_write = GetProcAddress(handle_, "cg_parent_data_write");
        if (!sym_cg_parent_data_write)
            throw std::runtime_error("cg_parent_data_write not found");
#else
        auto sym_cg_parent_data_write = dlsym(handle_, "cg_parent_data_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_parent_data_write_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int S, const cgsize_t* parent_data)>(sym_cg_parent_data_write);
#ifdef _WIN32
        auto sym_cg_npe = GetProcAddress(handle_, "cg_npe");
        if (!sym_cg_npe)
            throw std::runtime_error("cg_npe not found");
#else
        auto sym_cg_npe = dlsym(handle_, "cg_npe");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_npe_ = reinterpret_cast<int (*)(CGNS_ENUMT(ElementType_t) type, int* npe)>(sym_cg_npe);
#ifdef _WIN32
        auto sym_cg_ElementDataSize = GetProcAddress(handle_, "cg_ElementDataSize");
        if (!sym_cg_ElementDataSize)
            throw std::runtime_error("cg_ElementDataSize not found");
#else
        auto sym_cg_ElementDataSize = dlsym(handle_, "cg_ElementDataSize");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_ElementDataSize_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int S, cgsize_t* ElementDataSize)>(sym_cg_ElementDataSize);
#ifdef _WIN32
        auto sym_cg_section_partial_write = GetProcAddress(handle_, "cg_section_partial_write");
        if (!sym_cg_section_partial_write)
            throw std::runtime_error("cg_section_partial_write not found");
#else
        auto sym_cg_section_partial_write = dlsym(handle_, "cg_section_partial_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_section_partial_write_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, const char* SectionName, CGNS_ENUMT(ElementType_t) type,
                                 cgsize_t start, cgsize_t end, int nbndry, int* S)>(sym_cg_section_partial_write);
#ifdef _WIN32
        auto sym_cg_elements_partial_write = GetProcAddress(handle_, "cg_elements_partial_write");
        if (!sym_cg_elements_partial_write)
            throw std::runtime_error("cg_elements_partial_write not found");
#else
        auto sym_cg_elements_partial_write = dlsym(handle_, "cg_elements_partial_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_elements_partial_write_ =
        reinterpret_cast<int (*)(int fn, int B, int Z, int S, cgsize_t start, cgsize_t end, const cgsize_t* elements)>(
        sym_cg_elements_partial_write);
#ifdef _WIN32
        auto sym_cg_elements_general_write = GetProcAddress(handle_, "cg_elements_general_write");
        if (!sym_cg_elements_general_write)
            throw std::runtime_error("cg_elements_general_write not found");
#else
        auto sym_cg_elements_general_write = dlsym(handle_, "cg_elements_general_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_elements_general_write_ =
        reinterpret_cast<int (*)(int fn, int B, int Z, int S, cgsize_t start, cgsize_t end, CGNS_ENUMT(DataType_t) m_type,
                                 const void* elements)>(sym_cg_elements_general_write);
#ifdef _WIN32
        auto sym_cg_poly_elements_partial_write = GetProcAddress(handle_, "cg_poly_elements_partial_write");
        if (!sym_cg_poly_elements_partial_write)
            throw std::runtime_error("cg_poly_elements_partial_write not found");
#else
        auto sym_cg_poly_elements_partial_write = dlsym(handle_, "cg_poly_elements_partial_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_poly_elements_partial_write_ =
        reinterpret_cast<int (*)(int fn, int B, int Z, int S, cgsize_t start, cgsize_t end, const cgsize_t* elements,
                                 const cgsize_t* connect_offset)>(sym_cg_poly_elements_partial_write);
#ifdef _WIN32
        auto sym_cg_poly_elements_general_write = GetProcAddress(handle_, "cg_poly_elements_general_write");
        if (!sym_cg_poly_elements_general_write)
            throw std::runtime_error("cg_poly_elements_general_write not found");
#else
        auto sym_cg_poly_elements_general_write = dlsym(handle_, "cg_poly_elements_general_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_poly_elements_general_write_ =
        reinterpret_cast<int (*)(int fn, int B, int Z, int S, cgsize_t start, cgsize_t end, CGNS_ENUMT(DataType_t) m_type,
                                 const void* elements, const void* connect_offset)>(sym_cg_poly_elements_general_write);
#ifdef _WIN32
        auto sym_cg_parent_data_partial_write = GetProcAddress(handle_, "cg_parent_data_partial_write");
        if (!sym_cg_parent_data_partial_write)
            throw std::runtime_error("cg_parent_data_partial_write not found");
#else
        auto sym_cg_parent_data_partial_write = dlsym(handle_, "cg_parent_data_partial_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_parent_data_partial_write_ =
        reinterpret_cast<int (*)(int fn, int B, int Z, int S, cgsize_t start, cgsize_t end, const cgsize_t* ParentData)>(
        sym_cg_parent_data_partial_write);
#ifdef _WIN32
        auto sym_cg_elements_partial_read = GetProcAddress(handle_, "cg_elements_partial_read");
        if (!sym_cg_elements_partial_read)
            throw std::runtime_error("cg_elements_partial_read not found");
#else
        auto sym_cg_elements_partial_read = dlsym(handle_, "cg_elements_partial_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_elements_partial_read_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int S, cgsize_t start, cgsize_t end, cgsize_t* elements,
                                 cgsize_t* parent_data)>(sym_cg_elements_partial_read);
#ifdef _WIN32
        auto sym_cg_poly_elements_partial_read = GetProcAddress(handle_, "cg_poly_elements_partial_read");
        if (!sym_cg_poly_elements_partial_read)
            throw std::runtime_error("cg_poly_elements_partial_read not found");
#else
        auto sym_cg_poly_elements_partial_read = dlsym(handle_, "cg_poly_elements_partial_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_poly_elements_partial_read_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int S, cgsize_t start, cgsize_t end, cgsize_t* elements,
                                 cgsize_t* connect_offset, cgsize_t* parent_data)>(sym_cg_poly_elements_partial_read);
#ifdef _WIN32
        auto sym_cg_elements_general_read = GetProcAddress(handle_, "cg_elements_general_read");
        if (!sym_cg_elements_general_read)
            throw std::runtime_error("cg_elements_general_read not found");
#else
        auto sym_cg_elements_general_read = dlsym(handle_, "cg_elements_general_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_elements_general_read_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int S, cgsize_t start, cgsize_t end,
                                 CGNS_ENUMT(DataType_t) m_type, void* elements)>(sym_cg_elements_general_read);
#ifdef _WIN32
        auto sym_cg_poly_elements_general_read = GetProcAddress(handle_, "cg_poly_elements_general_read");
        if (!sym_cg_poly_elements_general_read)
            throw std::runtime_error("cg_poly_elements_general_read not found");
#else
        auto sym_cg_poly_elements_general_read = dlsym(handle_, "cg_poly_elements_general_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_poly_elements_general_read_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int S, cgsize_t start, cgsize_t end,
                                 CGNS_ENUMT(DataType_t) m_type, void* elements, void* connect_offset)>(
        sym_cg_poly_elements_general_read);
#ifdef _WIN32
        auto sym_cg_parent_elements_general_read = GetProcAddress(handle_, "cg_parent_elements_general_read");
        if (!sym_cg_parent_elements_general_read)
            throw std::runtime_error("cg_parent_elements_general_read not found");
#else
        auto sym_cg_parent_elements_general_read = dlsym(handle_, "cg_parent_elements_general_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_parent_elements_general_read_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int S, cgsize_t start, cgsize_t end,
                                 CGNS_ENUMT(DataType_t) m_type, void* parelem)>(sym_cg_parent_elements_general_read);
#ifdef _WIN32
        auto sym_cg_parent_elements_position_general_read = GetProcAddress(handle_, "cg_parent_elements_position_general_read");
        if (!sym_cg_parent_elements_position_general_read)
            throw std::runtime_error("cg_parent_elements_position_general_read not found");
#else
        auto sym_cg_parent_elements_position_general_read = dlsym(handle_, "cg_parent_elements_position_general_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_parent_elements_position_general_read_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int S, cgsize_t start, cgsize_t end,
                                 CGNS_ENUMT(DataType_t) m_type, void* parface)>(sym_cg_parent_elements_position_general_read);
#ifdef _WIN32
        auto sym_cg_ElementPartialSize = GetProcAddress(handle_, "cg_ElementPartialSize");
        if (!sym_cg_ElementPartialSize)
            throw std::runtime_error("cg_ElementPartialSize not found");
#else
        auto sym_cg_ElementPartialSize = dlsym(handle_, "cg_ElementPartialSize");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_ElementPartialSize_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int S, cgsize_t start, cgsize_t end, cgsize_t* ElementDataSize)>(
        sym_cg_ElementPartialSize);
#ifdef _WIN32
        auto sym_cg_nsols = GetProcAddress(handle_, "cg_nsols");
        if (!sym_cg_nsols)
            throw std::runtime_error("cg_nsols not found");
#else
        auto sym_cg_nsols = dlsym(handle_, "cg_nsols");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_nsols_ = reinterpret_cast<int (*)(int fn, int B, int Z, int* nsols)>(sym_cg_nsols);
#ifdef _WIN32
        auto sym_cg_sol_info = GetProcAddress(handle_, "cg_sol_info");
        if (!sym_cg_sol_info)
            throw std::runtime_error("cg_sol_info not found");
#else
        auto sym_cg_sol_info = dlsym(handle_, "cg_sol_info");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_sol_info_ =
        reinterpret_cast<int (*)(int fn, int B, int Z, int S, char* solname, CGNS_ENUMT(GridLocation_t) * location)>(
        sym_cg_sol_info);
#ifdef _WIN32
        auto sym_cg_sol_id = GetProcAddress(handle_, "cg_sol_id");
        if (!sym_cg_sol_id)
            throw std::runtime_error("cg_sol_id not found");
#else
        auto sym_cg_sol_id = dlsym(handle_, "cg_sol_id");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_sol_id_ = reinterpret_cast<int (*)(int fn, int B, int Z, int S, double* sol_id)>(sym_cg_sol_id);
#ifdef _WIN32
        auto sym_cg_sol_write = GetProcAddress(handle_, "cg_sol_write");
        if (!sym_cg_sol_write)
            throw std::runtime_error("cg_sol_write not found");
#else
        auto sym_cg_sol_write = dlsym(handle_, "cg_sol_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_sol_write_ =
        reinterpret_cast<int (*)(int fn, int B, int Z, const char* solname, CGNS_ENUMT(GridLocation_t) location, int* S)>(
        sym_cg_sol_write);
#ifdef _WIN32
        auto sym_cg_sol_size = GetProcAddress(handle_, "cg_sol_size");
        if (!sym_cg_sol_size)
            throw std::runtime_error("cg_sol_size not found");
#else
        auto sym_cg_sol_size = dlsym(handle_, "cg_sol_size");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_sol_size_ = reinterpret_cast<int (*)(int fn, int B, int Z, int S, int* data_dim, cgsize_t* dim_vals)>(sym_cg_sol_size);
#ifdef _WIN32
        auto sym_cg_sol_ptset_info = GetProcAddress(handle_, "cg_sol_ptset_info");
        if (!sym_cg_sol_ptset_info)
            throw std::runtime_error("cg_sol_ptset_info not found");
#else
        auto sym_cg_sol_ptset_info = dlsym(handle_, "cg_sol_ptset_info");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_sol_ptset_info_ =
        reinterpret_cast<int (*)(int fn, int B, int Z, int S, CGNS_ENUMT(PointSetType_t) * ptset_type, cgsize_t * npnts)>(
        sym_cg_sol_ptset_info);
#ifdef _WIN32
        auto sym_cg_sol_ptset_read = GetProcAddress(handle_, "cg_sol_ptset_read");
        if (!sym_cg_sol_ptset_read)
            throw std::runtime_error("cg_sol_ptset_read not found");
#else
        auto sym_cg_sol_ptset_read = dlsym(handle_, "cg_sol_ptset_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_sol_ptset_read_ = reinterpret_cast<int (*)(int fn, int B, int Z, int S, cgsize_t* pnts)>(sym_cg_sol_ptset_read);
#ifdef _WIN32
        auto sym_cg_sol_ptset_write = GetProcAddress(handle_, "cg_sol_ptset_write");
        if (!sym_cg_sol_ptset_write)
            throw std::runtime_error("cg_sol_ptset_write not found");
#else
        auto sym_cg_sol_ptset_write = dlsym(handle_, "cg_sol_ptset_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_sol_ptset_write_ =
        reinterpret_cast<int (*)(int fn, int B, int Z, const char* solname, CGNS_ENUMT(GridLocation_t) location,
                                 CGNS_ENUMT(PointSetType_t) ptset_type, cgsize_t npnts, const cgsize_t* pnts, int* S)>(
        sym_cg_sol_ptset_write);
#ifdef _WIN32
        auto sym_cg_nfields = GetProcAddress(handle_, "cg_nfields");
        if (!sym_cg_nfields)
            throw std::runtime_error("cg_nfields not found");
#else
        auto sym_cg_nfields = dlsym(handle_, "cg_nfields");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_nfields_ = reinterpret_cast<int (*)(int fn, int B, int Z, int S, int* nfields)>(sym_cg_nfields);
#ifdef _WIN32
        auto sym_cg_field_info = GetProcAddress(handle_, "cg_field_info");
        if (!sym_cg_field_info)
            throw std::runtime_error("cg_field_info not found");
#else
        auto sym_cg_field_info = dlsym(handle_, "cg_field_info");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_field_info_ =
        reinterpret_cast<int (*)(int fn, int B, int Z, int S, int F, CGNS_ENUMT(DataType_t) * type, char* fieldname)>(
        sym_cg_field_info);
#ifdef _WIN32
        auto sym_cg_field_read = GetProcAddress(handle_, "cg_field_read");
        if (!sym_cg_field_read)
            throw std::runtime_error("cg_field_read not found");
#else
        auto sym_cg_field_read = dlsym(handle_, "cg_field_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_field_read_ =
        reinterpret_cast<int (*)(int fn, int B, int Z, int S, const char* fieldname, CGNS_ENUMT(DataType_t) type,
                                 const cgsize_t* rmin, const cgsize_t* rmax, void* field_ptr)>(sym_cg_field_read);
#ifdef _WIN32
        auto sym_cg_field_general_read = GetProcAddress(handle_, "cg_field_general_read");
        if (!sym_cg_field_general_read)
            throw std::runtime_error("cg_field_general_read not found");
#else
        auto sym_cg_field_general_read = dlsym(handle_, "cg_field_general_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_field_general_read_ =
        reinterpret_cast<int (*)(int fn, int B, int Z, int S, const char* fieldname, const cgsize_t* s_rmin,
                                 const cgsize_t* s_rmax, CGNS_ENUMT(DataType_t) m_type, int m_numdim, const cgsize_t* m_dimvals,
                                 const cgsize_t* m_rmin, const cgsize_t* m_rmax, void* field_ptr)>(sym_cg_field_general_read);
#ifdef _WIN32
        auto sym_cg_field_id = GetProcAddress(handle_, "cg_field_id");
        if (!sym_cg_field_id)
            throw std::runtime_error("cg_field_id not found");
#else
        auto sym_cg_field_id = dlsym(handle_, "cg_field_id");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_field_id_ = reinterpret_cast<int (*)(int fn, int B, int Z, int S, int F, double* field_id)>(sym_cg_field_id);
#ifdef _WIN32
        auto sym_cg_field_write = GetProcAddress(handle_, "cg_field_write");
        if (!sym_cg_field_write)
            throw std::runtime_error("cg_field_write not found");
#else
        auto sym_cg_field_write = dlsym(handle_, "cg_field_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_field_write_ = reinterpret_cast<int (*)(int fn, int B, int Z, int S, CGNS_ENUMT(DataType_t) type,
                                                   const char* fieldname, const void* field_ptr, int* F)>(sym_cg_field_write);
#ifdef _WIN32
        auto sym_cg_field_partial_write = GetProcAddress(handle_, "cg_field_partial_write");
        if (!sym_cg_field_partial_write)
            throw std::runtime_error("cg_field_partial_write not found");
#else
        auto sym_cg_field_partial_write = dlsym(handle_, "cg_field_partial_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_field_partial_write_ =
        reinterpret_cast<int (*)(int fn, int B, int Z, int S, CGNS_ENUMT(DataType_t) type, const char* fieldname,
                                 const cgsize_t* rmin, const cgsize_t* rmax, const void* field_ptr, int* F)>(
        sym_cg_field_partial_write);
#ifdef _WIN32
        auto sym_cg_field_general_write = GetProcAddress(handle_, "cg_field_general_write");
        if (!sym_cg_field_general_write)
            throw std::runtime_error("cg_field_general_write not found");
#else
        auto sym_cg_field_general_write = dlsym(handle_, "cg_field_general_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_field_general_write_ = reinterpret_cast<int (*)(
        int fn, int B, int Z, int S, const char* fieldname, CGNS_ENUMT(DataType_t) s_type, const cgsize_t* rmin,
        const cgsize_t* rmax, CGNS_ENUMT(DataType_t) m_type, int m_numdim, const cgsize_t* m_dims, const cgsize_t* m_rmin,
        const cgsize_t* m_rmax, const void* field_ptr, int* F)>(sym_cg_field_general_write);
#ifdef _WIN32
        auto sym_cg_nsubregs = GetProcAddress(handle_, "cg_nsubregs");
        if (!sym_cg_nsubregs)
            throw std::runtime_error("cg_nsubregs not found");
#else
        auto sym_cg_nsubregs = dlsym(handle_, "cg_nsubregs");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_nsubregs_ = reinterpret_cast<int (*)(int fn, int B, int Z, int* nsubreg)>(sym_cg_nsubregs);
#ifdef _WIN32
        auto sym_cg_subreg_info = GetProcAddress(handle_, "cg_subreg_info");
        if (!sym_cg_subreg_info)
            throw std::runtime_error("cg_subreg_info not found");
#else
        auto sym_cg_subreg_info = dlsym(handle_, "cg_subreg_info");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_subreg_info_ = reinterpret_cast<int (*)(int fn, int B, int Z, int S, char* regname, int* dimension,
                                                   CGNS_ENUMT(GridLocation_t) * location, CGNS_ENUMT(PointSetType_t) * ptset_type,
                                                   cgsize_t * npnts, int* bcname_len, int* gcname_len)>(sym_cg_subreg_info);
#ifdef _WIN32
        auto sym_cg_subreg_ptset_read = GetProcAddress(handle_, "cg_subreg_ptset_read");
        if (!sym_cg_subreg_ptset_read)
            throw std::runtime_error("cg_subreg_ptset_read not found");
#else
        auto sym_cg_subreg_ptset_read = dlsym(handle_, "cg_subreg_ptset_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_subreg_ptset_read_ = reinterpret_cast<int (*)(int fn, int B, int Z, int S, cgsize_t* pnts)>(sym_cg_subreg_ptset_read);
#ifdef _WIN32
        auto sym_cg_subreg_bcname_read = GetProcAddress(handle_, "cg_subreg_bcname_read");
        if (!sym_cg_subreg_bcname_read)
            throw std::runtime_error("cg_subreg_bcname_read not found");
#else
        auto sym_cg_subreg_bcname_read = dlsym(handle_, "cg_subreg_bcname_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_subreg_bcname_read_ = reinterpret_cast<int (*)(int fn, int B, int Z, int S, char* bcname)>(sym_cg_subreg_bcname_read);
#ifdef _WIN32
        auto sym_cg_subreg_gcname_read = GetProcAddress(handle_, "cg_subreg_gcname_read");
        if (!sym_cg_subreg_gcname_read)
            throw std::runtime_error("cg_subreg_gcname_read not found");
#else
        auto sym_cg_subreg_gcname_read = dlsym(handle_, "cg_subreg_gcname_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_subreg_gcname_read_ = reinterpret_cast<int (*)(int fn, int B, int Z, int S, char* gcname)>(sym_cg_subreg_gcname_read);
#ifdef _WIN32
        auto sym_cg_subreg_ptset_write = GetProcAddress(handle_, "cg_subreg_ptset_write");
        if (!sym_cg_subreg_ptset_write)
            throw std::runtime_error("cg_subreg_ptset_write not found");
#else
        auto sym_cg_subreg_ptset_write = dlsym(handle_, "cg_subreg_ptset_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_subreg_ptset_write_ =
        reinterpret_cast<int (*)(int fn, int B, int Z, const char* regname, int dimension, CGNS_ENUMT(GridLocation_t) location,
                                 CGNS_ENUMT(PointSetType_t) ptset_type, cgsize_t npnts, const cgsize_t* pnts, int* S)>(
        sym_cg_subreg_ptset_write);
#ifdef _WIN32
        auto sym_cg_subreg_bcname_write = GetProcAddress(handle_, "cg_subreg_bcname_write");
        if (!sym_cg_subreg_bcname_write)
            throw std::runtime_error("cg_subreg_bcname_write not found");
#else
        auto sym_cg_subreg_bcname_write = dlsym(handle_, "cg_subreg_bcname_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_subreg_bcname_write_ =
        reinterpret_cast<int (*)(int fn, int B, int Z, const char* regname, int dimension, const char* bcname, int* S)>(
        sym_cg_subreg_bcname_write);
#ifdef _WIN32
        auto sym_cg_subreg_gcname_write = GetProcAddress(handle_, "cg_subreg_gcname_write");
        if (!sym_cg_subreg_gcname_write)
            throw std::runtime_error("cg_subreg_gcname_write not found");
#else
        auto sym_cg_subreg_gcname_write = dlsym(handle_, "cg_subreg_gcname_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_subreg_gcname_write_ =
        reinterpret_cast<int (*)(int fn, int B, int Z, const char* regname, int dimension, const char* gcname, int* S)>(
        sym_cg_subreg_gcname_write);
#ifdef _WIN32
        auto sym_cg_nzconns = GetProcAddress(handle_, "cg_nzconns");
        if (!sym_cg_nzconns)
            throw std::runtime_error("cg_nzconns not found");
#else
        auto sym_cg_nzconns = dlsym(handle_, "cg_nzconns");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_nzconns_ = reinterpret_cast<int (*)(int fn, int B, int Z, int* nzconns)>(sym_cg_nzconns);
#ifdef _WIN32
        auto sym_cg_zconn_read = GetProcAddress(handle_, "cg_zconn_read");
        if (!sym_cg_zconn_read)
            throw std::runtime_error("cg_zconn_read not found");
#else
        auto sym_cg_zconn_read = dlsym(handle_, "cg_zconn_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_zconn_read_ = reinterpret_cast<int (*)(int fn, int B, int Z, int C, char* name)>(sym_cg_zconn_read);
#ifdef _WIN32
        auto sym_cg_zconn_write = GetProcAddress(handle_, "cg_zconn_write");
        if (!sym_cg_zconn_write)
            throw std::runtime_error("cg_zconn_write not found");
#else
        auto sym_cg_zconn_write = dlsym(handle_, "cg_zconn_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_zconn_write_ = reinterpret_cast<int (*)(int fn, int B, int Z, const char* name, int* C)>(sym_cg_zconn_write);
#ifdef _WIN32
        auto sym_cg_zconn_get = GetProcAddress(handle_, "cg_zconn_get");
        if (!sym_cg_zconn_get)
            throw std::runtime_error("cg_zconn_get not found");
#else
        auto sym_cg_zconn_get = dlsym(handle_, "cg_zconn_get");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_zconn_get_ = reinterpret_cast<int (*)(int fn, int B, int Z, int* C)>(sym_cg_zconn_get);
#ifdef _WIN32
        auto sym_cg_zconn_set = GetProcAddress(handle_, "cg_zconn_set");
        if (!sym_cg_zconn_set)
            throw std::runtime_error("cg_zconn_set not found");
#else
        auto sym_cg_zconn_set = dlsym(handle_, "cg_zconn_set");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_zconn_set_ = reinterpret_cast<int (*)(int fn, int B, int Z, int C)>(sym_cg_zconn_set);
#ifdef _WIN32
        auto sym_cg_nholes = GetProcAddress(handle_, "cg_nholes");
        if (!sym_cg_nholes)
            throw std::runtime_error("cg_nholes not found");
#else
        auto sym_cg_nholes = dlsym(handle_, "cg_nholes");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_nholes_ = reinterpret_cast<int (*)(int fn, int B, int Z, int* nholes)>(sym_cg_nholes);
#ifdef _WIN32
        auto sym_cg_hole_info = GetProcAddress(handle_, "cg_hole_info");
        if (!sym_cg_hole_info)
            throw std::runtime_error("cg_hole_info not found");
#else
        auto sym_cg_hole_info = dlsym(handle_, "cg_hole_info");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_hole_info_ =
        reinterpret_cast<int (*)(int fn, int B, int Z, int Ii, char* holename, CGNS_ENUMT(GridLocation_t) * location,
                                 CGNS_ENUMT(PointSetType_t) * ptset_type, int* nptsets, cgsize_t* npnts)>(sym_cg_hole_info);
#ifdef _WIN32
        auto sym_cg_hole_read = GetProcAddress(handle_, "cg_hole_read");
        if (!sym_cg_hole_read)
            throw std::runtime_error("cg_hole_read not found");
#else
        auto sym_cg_hole_read = dlsym(handle_, "cg_hole_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_hole_read_ = reinterpret_cast<int (*)(int fn, int B, int Z, int Ii, cgsize_t* pnts)>(sym_cg_hole_read);
#ifdef _WIN32
        auto sym_cg_hole_id = GetProcAddress(handle_, "cg_hole_id");
        if (!sym_cg_hole_id)
            throw std::runtime_error("cg_hole_id not found");
#else
        auto sym_cg_hole_id = dlsym(handle_, "cg_hole_id");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_hole_id_ = reinterpret_cast<int (*)(int fn, int B, int Z, int Ii, double* hole_id)>(sym_cg_hole_id);
#ifdef _WIN32
        auto sym_cg_hole_write = GetProcAddress(handle_, "cg_hole_write");
        if (!sym_cg_hole_write)
            throw std::runtime_error("cg_hole_write not found");
#else
        auto sym_cg_hole_write = dlsym(handle_, "cg_hole_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_hole_write_ = reinterpret_cast<int (*)(int fn, int B, int Z, const char* holename, CGNS_ENUMT(GridLocation_t) location,
                                                  CGNS_ENUMT(PointSetType_t) ptset_type, int nptsets, cgsize_t npnts,
                                                  const cgsize_t* pnts, int* Ii)>(sym_cg_hole_write);
#ifdef _WIN32
        auto sym_cg_nconns = GetProcAddress(handle_, "cg_nconns");
        if (!sym_cg_nconns)
            throw std::runtime_error("cg_nconns not found");
#else
        auto sym_cg_nconns = dlsym(handle_, "cg_nconns");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_nconns_ = reinterpret_cast<int (*)(int fn, int B, int Z, int* nconns)>(sym_cg_nconns);
#ifdef _WIN32
        auto sym_cg_conn_info = GetProcAddress(handle_, "cg_conn_info");
        if (!sym_cg_conn_info)
            throw std::runtime_error("cg_conn_info not found");
#else
        auto sym_cg_conn_info = dlsym(handle_, "cg_conn_info");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_conn_info_ = reinterpret_cast<int (*)(
        int file_number, int B, int Z, int Ii, char* connectname, CGNS_ENUMT(GridLocation_t) * location,
        CGNS_ENUMT(GridConnectivityType_t) * type, CGNS_ENUMT(PointSetType_t) * ptset_type, cgsize_t * npnts, char* donorname,
        CGNS_ENUMT(ZoneType_t) * donor_zonetype, CGNS_ENUMT(PointSetType_t) * donor_ptset_type,
        CGNS_ENUMT(DataType_t) * donor_datatype, cgsize_t * ndata_donor)>(sym_cg_conn_info);
#ifdef _WIN32
        auto sym_cg_conn_read = GetProcAddress(handle_, "cg_conn_read");
        if (!sym_cg_conn_read)
            throw std::runtime_error("cg_conn_read not found");
#else
        auto sym_cg_conn_read = dlsym(handle_, "cg_conn_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_conn_read_ = reinterpret_cast<int (*)(int file_number, int B, int Z, int Ii, cgsize_t* pnts,
                                                 CGNS_ENUMT(DataType_t) donor_datatype, cgsize_t* donor_data)>(sym_cg_conn_read);
#ifdef _WIN32
        auto sym_cg_conn_id = GetProcAddress(handle_, "cg_conn_id");
        if (!sym_cg_conn_id)
            throw std::runtime_error("cg_conn_id not found");
#else
        auto sym_cg_conn_id = dlsym(handle_, "cg_conn_id");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_conn_id_ = reinterpret_cast<int (*)(int fn, int B, int Z, int Ii, double* conn_id)>(sym_cg_conn_id);
#ifdef _WIN32
        auto sym_cg_conn_write = GetProcAddress(handle_, "cg_conn_write");
        if (!sym_cg_conn_write)
            throw std::runtime_error("cg_conn_write not found");
#else
        auto sym_cg_conn_write = dlsym(handle_, "cg_conn_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_conn_write_ = reinterpret_cast<int (*)(
        int file_number, int B, int Z, const char* connectname, CGNS_ENUMT(GridLocation_t) location,
        CGNS_ENUMT(GridConnectivityType_t) type, CGNS_ENUMT(PointSetType_t) ptset_type, cgsize_t npnts, const cgsize_t* pnts,
        const char* donorname, CGNS_ENUMT(ZoneType_t) donor_zonetype, CGNS_ENUMT(PointSetType_t) donor_ptset_type,
        CGNS_ENUMT(DataType_t) donor_datatype, cgsize_t ndata_donor, const cgsize_t* donor_data, int* Ii)>(sym_cg_conn_write);
#ifdef _WIN32
        auto sym_cg_conn_write_short = GetProcAddress(handle_, "cg_conn_write_short");
        if (!sym_cg_conn_write_short)
            throw std::runtime_error("cg_conn_write_short not found");
#else
        auto sym_cg_conn_write_short = dlsym(handle_, "cg_conn_write_short");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_conn_write_short_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, const char* connectname, CGNS_ENUMT(GridLocation_t) location,
                                 CGNS_ENUMT(GridConnectivityType_t) type, CGNS_ENUMT(PointSetType_t) ptset_type, cgsize_t npnts,
                                 const cgsize_t* pnts, const char* donorname, int* Ii)>(sym_cg_conn_write_short);
#ifdef _WIN32
        auto sym_cg_conn_read_short = GetProcAddress(handle_, "cg_conn_read_short");
        if (!sym_cg_conn_read_short)
            throw std::runtime_error("cg_conn_read_short not found");
#else
        auto sym_cg_conn_read_short = dlsym(handle_, "cg_conn_read_short");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_conn_read_short_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int Ii, cgsize_t* pnts)>(sym_cg_conn_read_short);
#ifdef _WIN32
        auto sym_cg_n1to1 = GetProcAddress(handle_, "cg_n1to1");
        if (!sym_cg_n1to1)
            throw std::runtime_error("cg_n1to1 not found");
#else
        auto sym_cg_n1to1 = dlsym(handle_, "cg_n1to1");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_n1to1_ = reinterpret_cast<int (*)(int fn, int B, int Z, int* n1to1)>(sym_cg_n1to1);
#ifdef _WIN32
        auto sym_cg_1to1_read = GetProcAddress(handle_, "cg_1to1_read");
        if (!sym_cg_1to1_read)
            throw std::runtime_error("cg_1to1_read not found");
#else
        auto sym_cg_1to1_read = dlsym(handle_, "cg_1to1_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_1to1_read_ = reinterpret_cast<int (*)(int fn, int B, int Z, int Ii, char* connectname, char* donorname,
                                                 cgsize_t* range, cgsize_t* donor_range, int* transform)>(sym_cg_1to1_read);
#ifdef _WIN32
        auto sym_cg_1to1_id = GetProcAddress(handle_, "cg_1to1_id");
        if (!sym_cg_1to1_id)
            throw std::runtime_error("cg_1to1_id not found");
#else
        auto sym_cg_1to1_id = dlsym(handle_, "cg_1to1_id");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_1to1_id_ = reinterpret_cast<int (*)(int fn, int B, int Z, int Ii, double* one21_id)>(sym_cg_1to1_id);
#ifdef _WIN32
        auto sym_cg_1to1_write = GetProcAddress(handle_, "cg_1to1_write");
        if (!sym_cg_1to1_write)
            throw std::runtime_error("cg_1to1_write not found");
#else
        auto sym_cg_1to1_write = dlsym(handle_, "cg_1to1_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_1to1_write_ =
        reinterpret_cast<int (*)(int fn, int B, int Z, const char* connectname, const char* donorname, const cgsize_t* range,
                                 const cgsize_t* donor_range, const int* transform, int* Ii)>(sym_cg_1to1_write);
#ifdef _WIN32
        auto sym_cg_n1to1_global = GetProcAddress(handle_, "cg_n1to1_global");
        if (!sym_cg_n1to1_global)
            throw std::runtime_error("cg_n1to1_global not found");
#else
        auto sym_cg_n1to1_global = dlsym(handle_, "cg_n1to1_global");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_n1to1_global_ = reinterpret_cast<int (*)(int fn, int B, int* n1to1_global)>(sym_cg_n1to1_global);
#ifdef _WIN32
        auto sym_cg_1to1_read_global = GetProcAddress(handle_, "cg_1to1_read_global");
        if (!sym_cg_1to1_read_global)
            throw std::runtime_error("cg_1to1_read_global not found");
#else
        auto sym_cg_1to1_read_global = dlsym(handle_, "cg_1to1_read_global");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_1to1_read_global_ =
        reinterpret_cast<int (*)(int fn, int B, char** connectname, char** zonename, char** donorname, cgsize_t** range,
                                 cgsize_t** donor_range, int** transform)>(sym_cg_1to1_read_global);
#ifdef _WIN32
        auto sym_cg_nbocos = GetProcAddress(handle_, "cg_nbocos");
        if (!sym_cg_nbocos)
            throw std::runtime_error("cg_nbocos not found");
#else
        auto sym_cg_nbocos = dlsym(handle_, "cg_nbocos");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_nbocos_ = reinterpret_cast<int (*)(int fn, int B, int Z, int* nbocos)>(sym_cg_nbocos);
#ifdef _WIN32
        auto sym_cg_boco_info = GetProcAddress(handle_, "cg_boco_info");
        if (!sym_cg_boco_info)
            throw std::runtime_error("cg_boco_info not found");
#else
        auto sym_cg_boco_info = dlsym(handle_, "cg_boco_info");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_boco_info_ = reinterpret_cast<int (*)(
        int fn, int B, int Z, int BC, char* boconame, CGNS_ENUMT(BCType_t) * bocotype, CGNS_ENUMT(PointSetType_t) * ptset_type,
        cgsize_t * npnts, int* NormalIndex, cgsize_t* NormalListSize, CGNS_ENUMT(DataType_t) * NormalDataType, int* ndataset)>(
        sym_cg_boco_info);
#ifdef _WIN32
        auto sym_cg_boco_read = GetProcAddress(handle_, "cg_boco_read");
        if (!sym_cg_boco_read)
            throw std::runtime_error("cg_boco_read not found");
#else
        auto sym_cg_boco_read = dlsym(handle_, "cg_boco_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_boco_read_ =
        reinterpret_cast<int (*)(int fn, int B, int Z, int BC, cgsize_t* pnts, void* NormalList)>(sym_cg_boco_read);
#ifdef _WIN32
        auto sym_cg_boco_id = GetProcAddress(handle_, "cg_boco_id");
        if (!sym_cg_boco_id)
            throw std::runtime_error("cg_boco_id not found");
#else
        auto sym_cg_boco_id = dlsym(handle_, "cg_boco_id");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_boco_id_ = reinterpret_cast<int (*)(int fn, int B, int Z, int BC, double* boco_id)>(sym_cg_boco_id);
#ifdef _WIN32
        auto sym_cg_boco_write = GetProcAddress(handle_, "cg_boco_write");
        if (!sym_cg_boco_write)
            throw std::runtime_error("cg_boco_write not found");
#else
        auto sym_cg_boco_write = dlsym(handle_, "cg_boco_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_boco_write_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, const char* boconame, CGNS_ENUMT(BCType_t) bocotype,
                                 CGNS_ENUMT(PointSetType_t) ptset_type, cgsize_t npnts, const cgsize_t* pnts, int* BC)>(
        sym_cg_boco_write);
#ifdef _WIN32
        auto sym_cg_boco_normal_write = GetProcAddress(handle_, "cg_boco_normal_write");
        if (!sym_cg_boco_normal_write)
            throw std::runtime_error("cg_boco_normal_write not found");
#else
        auto sym_cg_boco_normal_write = dlsym(handle_, "cg_boco_normal_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_boco_normal_write_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int BC, const int* NormalIndex, int NormalListFlag,
                                 CGNS_ENUMT(DataType_t) NormalDataType, const void* NormalList)>(sym_cg_boco_normal_write);
#ifdef _WIN32
        auto sym_cg_boco_gridlocation_read = GetProcAddress(handle_, "cg_boco_gridlocation_read");
        if (!sym_cg_boco_gridlocation_read)
            throw std::runtime_error("cg_boco_gridlocation_read not found");
#else
        auto sym_cg_boco_gridlocation_read = dlsym(handle_, "cg_boco_gridlocation_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_boco_gridlocation_read_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int BC, CGNS_ENUMT(GridLocation_t) * location)>(
        sym_cg_boco_gridlocation_read);
#ifdef _WIN32
        auto sym_cg_boco_gridlocation_write = GetProcAddress(handle_, "cg_boco_gridlocation_write");
        if (!sym_cg_boco_gridlocation_write)
            throw std::runtime_error("cg_boco_gridlocation_write not found");
#else
        auto sym_cg_boco_gridlocation_write = dlsym(handle_, "cg_boco_gridlocation_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_boco_gridlocation_write_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int BC, CGNS_ENUMT(GridLocation_t) location)>(
        sym_cg_boco_gridlocation_write);
#ifdef _WIN32
        auto sym_cg_dataset_read = GetProcAddress(handle_, "cg_dataset_read");
        if (!sym_cg_dataset_read)
            throw std::runtime_error("cg_dataset_read not found");
#else
        auto sym_cg_dataset_read = dlsym(handle_, "cg_dataset_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_dataset_read_ =
        reinterpret_cast<int (*)(int fn, int B, int Z, int BC, int DS, char* name, CGNS_ENUMT(BCType_t) * BCType,
                                 int* DirichletFlag, int* NeumannFlag)>(sym_cg_dataset_read);
#ifdef _WIN32
        auto sym_cg_dataset_write = GetProcAddress(handle_, "cg_dataset_write");
        if (!sym_cg_dataset_write)
            throw std::runtime_error("cg_dataset_write not found");
#else
        auto sym_cg_dataset_write = dlsym(handle_, "cg_dataset_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_dataset_write_ = reinterpret_cast<int (*)(int file_number, int B, int Z, int BC, const char* name,
                                                     CGNS_ENUMT(BCType_t) BCType, int* Dset)>(sym_cg_dataset_write);
#ifdef _WIN32
        auto sym_cg_bcdataset_write = GetProcAddress(handle_, "cg_bcdataset_write");
        if (!sym_cg_bcdataset_write)
            throw std::runtime_error("cg_bcdataset_write not found");
#else
        auto sym_cg_bcdataset_write = dlsym(handle_, "cg_bcdataset_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_bcdataset_write_ =
        reinterpret_cast<int (*)(const char* name, CGNS_ENUMT(BCType_t) BCType, CGNS_ENUMT(BCDataType_t) BCDataType)>(
        sym_cg_bcdataset_write);
#ifdef _WIN32
        auto sym_cg_bcdataset_info = GetProcAddress(handle_, "cg_bcdataset_info");
        if (!sym_cg_bcdataset_info)
            throw std::runtime_error("cg_bcdataset_info not found");
#else
        auto sym_cg_bcdataset_info = dlsym(handle_, "cg_bcdataset_info");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_bcdataset_info_ = reinterpret_cast<int (*)(int* n_dataset)>(sym_cg_bcdataset_info);
#ifdef _WIN32
        auto sym_cg_bcdataset_read = GetProcAddress(handle_, "cg_bcdataset_read");
        if (!sym_cg_bcdataset_read)
            throw std::runtime_error("cg_bcdataset_read not found");
#else
        auto sym_cg_bcdataset_read = dlsym(handle_, "cg_bcdataset_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_bcdataset_read_ =
        reinterpret_cast<int (*)(int index, char* name, CGNS_ENUMT(BCType_t) * BCType, int* DirichletFlag, int* NeumannFlag)>(
        sym_cg_bcdataset_read);
#ifdef _WIN32
        auto sym_cg_bcdata_write = GetProcAddress(handle_, "cg_bcdata_write");
        if (!sym_cg_bcdata_write)
            throw std::runtime_error("cg_bcdata_write not found");
#else
        auto sym_cg_bcdata_write = dlsym(handle_, "cg_bcdata_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_bcdata_write_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int BC, int Dset, CGNS_ENUMT(BCDataType_t) BCDataType)>(
        sym_cg_bcdata_write);
#ifdef _WIN32
        auto sym_cg_ndiscrete = GetProcAddress(handle_, "cg_ndiscrete");
        if (!sym_cg_ndiscrete)
            throw std::runtime_error("cg_ndiscrete not found");
#else
        auto sym_cg_ndiscrete = dlsym(handle_, "cg_ndiscrete");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_ndiscrete_ = reinterpret_cast<int (*)(int file_number, int B, int Z, int* ndiscrete)>(sym_cg_ndiscrete);
#ifdef _WIN32
        auto sym_cg_discrete_read = GetProcAddress(handle_, "cg_discrete_read");
        if (!sym_cg_discrete_read)
            throw std::runtime_error("cg_discrete_read not found");
#else
        auto sym_cg_discrete_read = dlsym(handle_, "cg_discrete_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_discrete_read_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int D, char* discrete_name)>(sym_cg_discrete_read);
#ifdef _WIN32
        auto sym_cg_discrete_write = GetProcAddress(handle_, "cg_discrete_write");
        if (!sym_cg_discrete_write)
            throw std::runtime_error("cg_discrete_write not found");
#else
        auto sym_cg_discrete_write = dlsym(handle_, "cg_discrete_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_discrete_write_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, const char* discrete_name, int* D)>(sym_cg_discrete_write);
#ifdef _WIN32
        auto sym_cg_discrete_size = GetProcAddress(handle_, "cg_discrete_size");
        if (!sym_cg_discrete_size)
            throw std::runtime_error("cg_discrete_size not found");
#else
        auto sym_cg_discrete_size = dlsym(handle_, "cg_discrete_size");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_discrete_size_ =
        reinterpret_cast<int (*)(int fn, int B, int Z, int D, int* data_dim, cgsize_t* dim_vals)>(sym_cg_discrete_size);
#ifdef _WIN32
        auto sym_cg_discrete_ptset_info = GetProcAddress(handle_, "cg_discrete_ptset_info");
        if (!sym_cg_discrete_ptset_info)
            throw std::runtime_error("cg_discrete_ptset_info not found");
#else
        auto sym_cg_discrete_ptset_info = dlsym(handle_, "cg_discrete_ptset_info");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_discrete_ptset_info_ =
        reinterpret_cast<int (*)(int fn, int B, int Z, int D, CGNS_ENUMT(PointSetType_t) * ptset_type, cgsize_t * npnts)>(
        sym_cg_discrete_ptset_info);
#ifdef _WIN32
        auto sym_cg_discrete_ptset_read = GetProcAddress(handle_, "cg_discrete_ptset_read");
        if (!sym_cg_discrete_ptset_read)
            throw std::runtime_error("cg_discrete_ptset_read not found");
#else
        auto sym_cg_discrete_ptset_read = dlsym(handle_, "cg_discrete_ptset_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_discrete_ptset_read_ =
        reinterpret_cast<int (*)(int fn, int B, int Z, int D, cgsize_t* pnts)>(sym_cg_discrete_ptset_read);
#ifdef _WIN32
        auto sym_cg_discrete_ptset_write = GetProcAddress(handle_, "cg_discrete_ptset_write");
        if (!sym_cg_discrete_ptset_write)
            throw std::runtime_error("cg_discrete_ptset_write not found");
#else
        auto sym_cg_discrete_ptset_write = dlsym(handle_, "cg_discrete_ptset_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_discrete_ptset_write_ =
        reinterpret_cast<int (*)(int fn, int B, int Z, const char* discrete_name, CGNS_ENUMT(GridLocation_t) location,
                                 CGNS_ENUMT(PointSetType_t) ptset_type, cgsize_t npnts, const cgsize_t* pnts, int* D)>(
        sym_cg_discrete_ptset_write);
#ifdef _WIN32
        auto sym_cg_n_rigid_motions = GetProcAddress(handle_, "cg_n_rigid_motions");
        if (!sym_cg_n_rigid_motions)
            throw std::runtime_error("cg_n_rigid_motions not found");
#else
        auto sym_cg_n_rigid_motions = dlsym(handle_, "cg_n_rigid_motions");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_n_rigid_motions_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int* n_rigid_motions)>(sym_cg_n_rigid_motions);
#ifdef _WIN32
        auto sym_cg_rigid_motion_read = GetProcAddress(handle_, "cg_rigid_motion_read");
        if (!sym_cg_rigid_motion_read)
            throw std::runtime_error("cg_rigid_motion_read not found");
#else
        auto sym_cg_rigid_motion_read = dlsym(handle_, "cg_rigid_motion_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_rigid_motion_read_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int R, char* name, CGNS_ENUMT(RigidGridMotionType_t) * type)>(
        sym_cg_rigid_motion_read);
#ifdef _WIN32
        auto sym_cg_rigid_motion_write = GetProcAddress(handle_, "cg_rigid_motion_write");
        if (!sym_cg_rigid_motion_write)
            throw std::runtime_error("cg_rigid_motion_write not found");
#else
        auto sym_cg_rigid_motion_write = dlsym(handle_, "cg_rigid_motion_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_rigid_motion_write_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, const char* name, CGNS_ENUMT(RigidGridMotionType_t) type,
                                 int* R)>(sym_cg_rigid_motion_write);
#ifdef _WIN32
        auto sym_cg_n_arbitrary_motions = GetProcAddress(handle_, "cg_n_arbitrary_motions");
        if (!sym_cg_n_arbitrary_motions)
            throw std::runtime_error("cg_n_arbitrary_motions not found");
#else
        auto sym_cg_n_arbitrary_motions = dlsym(handle_, "cg_n_arbitrary_motions");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_n_arbitrary_motions_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int* n_arbitrary_motions)>(sym_cg_n_arbitrary_motions);
#ifdef _WIN32
        auto sym_cg_arbitrary_motion_read = GetProcAddress(handle_, "cg_arbitrary_motion_read");
        if (!sym_cg_arbitrary_motion_read)
            throw std::runtime_error("cg_arbitrary_motion_read not found");
#else
        auto sym_cg_arbitrary_motion_read = dlsym(handle_, "cg_arbitrary_motion_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_arbitrary_motion_read_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int A, char* name, CGNS_ENUMT(ArbitraryGridMotionType_t) * type)>(
        sym_cg_arbitrary_motion_read);
#ifdef _WIN32
        auto sym_cg_arbitrary_motion_write = GetProcAddress(handle_, "cg_arbitrary_motion_write");
        if (!sym_cg_arbitrary_motion_write)
            throw std::runtime_error("cg_arbitrary_motion_write not found");
#else
        auto sym_cg_arbitrary_motion_write = dlsym(handle_, "cg_arbitrary_motion_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_arbitrary_motion_write_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, const char* amotionname,
                                 CGNS_ENUMT(ArbitraryGridMotionType_t) type, int* A)>(sym_cg_arbitrary_motion_write);
#ifdef _WIN32
        auto sym_cg_simulation_type_read = GetProcAddress(handle_, "cg_simulation_type_read");
        if (!sym_cg_simulation_type_read)
            throw std::runtime_error("cg_simulation_type_read not found");
#else
        auto sym_cg_simulation_type_read = dlsym(handle_, "cg_simulation_type_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_simulation_type_read_ =
        reinterpret_cast<int (*)(int file_number, int B, CGNS_ENUMT(SimulationType_t) * type)>(sym_cg_simulation_type_read);
#ifdef _WIN32
        auto sym_cg_simulation_type_write = GetProcAddress(handle_, "cg_simulation_type_write");
        if (!sym_cg_simulation_type_write)
            throw std::runtime_error("cg_simulation_type_write not found");
#else
        auto sym_cg_simulation_type_write = dlsym(handle_, "cg_simulation_type_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_simulation_type_write_ =
        reinterpret_cast<int (*)(int file_number, int B, CGNS_ENUMT(SimulationType_t) type)>(sym_cg_simulation_type_write);
#ifdef _WIN32
        auto sym_cg_biter_read = GetProcAddress(handle_, "cg_biter_read");
        if (!sym_cg_biter_read)
            throw std::runtime_error("cg_biter_read not found");
#else
        auto sym_cg_biter_read = dlsym(handle_, "cg_biter_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_biter_read_ = reinterpret_cast<int (*)(int file_number, int B, char* bitername, int* nsteps)>(sym_cg_biter_read);
#ifdef _WIN32
        auto sym_cg_biter_write = GetProcAddress(handle_, "cg_biter_write");
        if (!sym_cg_biter_write)
            throw std::runtime_error("cg_biter_write not found");
#else
        auto sym_cg_biter_write = dlsym(handle_, "cg_biter_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_biter_write_ =
        reinterpret_cast<int (*)(int file_number, int B, const char* bitername, int nsteps)>(sym_cg_biter_write);
#ifdef _WIN32
        auto sym_cg_ziter_read = GetProcAddress(handle_, "cg_ziter_read");
        if (!sym_cg_ziter_read)
            throw std::runtime_error("cg_ziter_read not found");
#else
        auto sym_cg_ziter_read = dlsym(handle_, "cg_ziter_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_ziter_read_ = reinterpret_cast<int (*)(int file_number, int B, int Z, char* zitername)>(sym_cg_ziter_read);
#ifdef _WIN32
        auto sym_cg_ziter_write = GetProcAddress(handle_, "cg_ziter_write");
        if (!sym_cg_ziter_write)
            throw std::runtime_error("cg_ziter_write not found");
#else
        auto sym_cg_ziter_write = dlsym(handle_, "cg_ziter_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_ziter_write_ = reinterpret_cast<int (*)(int file_number, int B, int Z, const char* zitername)>(sym_cg_ziter_write);
#ifdef _WIN32
        auto sym_cg_gravity_read = GetProcAddress(handle_, "cg_gravity_read");
        if (!sym_cg_gravity_read)
            throw std::runtime_error("cg_gravity_read not found");
#else
        auto sym_cg_gravity_read = dlsym(handle_, "cg_gravity_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_gravity_read_ = reinterpret_cast<int (*)(int file_number, int B, float* gravity_vector)>(sym_cg_gravity_read);
#ifdef _WIN32
        auto sym_cg_gravity_write = GetProcAddress(handle_, "cg_gravity_write");
        if (!sym_cg_gravity_write)
            throw std::runtime_error("cg_gravity_write not found");
#else
        auto sym_cg_gravity_write = dlsym(handle_, "cg_gravity_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_gravity_write_ = reinterpret_cast<int (*)(int file_number, int B, float const* gravity_vector)>(sym_cg_gravity_write);
#ifdef _WIN32
        auto sym_cg_axisym_read = GetProcAddress(handle_, "cg_axisym_read");
        if (!sym_cg_axisym_read)
            throw std::runtime_error("cg_axisym_read not found");
#else
        auto sym_cg_axisym_read = dlsym(handle_, "cg_axisym_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_axisym_read_ = reinterpret_cast<int (*)(int file_number, int B, float* ref_point, float* axis)>(sym_cg_axisym_read);
#ifdef _WIN32
        auto sym_cg_axisym_write = GetProcAddress(handle_, "cg_axisym_write");
        if (!sym_cg_axisym_write)
            throw std::runtime_error("cg_axisym_write not found");
#else
        auto sym_cg_axisym_write = dlsym(handle_, "cg_axisym_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_axisym_write_ =
        reinterpret_cast<int (*)(int file_number, int B, float const* ref_point, float const* axis)>(sym_cg_axisym_write);
#ifdef _WIN32
        auto sym_cg_rotating_read = GetProcAddress(handle_, "cg_rotating_read");
        if (!sym_cg_rotating_read)
            throw std::runtime_error("cg_rotating_read not found");
#else
        auto sym_cg_rotating_read = dlsym(handle_, "cg_rotating_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_rotating_read_ = reinterpret_cast<int (*)(float* rot_rate, float* rot_center)>(sym_cg_rotating_read);
#ifdef _WIN32
        auto sym_cg_rotating_write = GetProcAddress(handle_, "cg_rotating_write");
        if (!sym_cg_rotating_write)
            throw std::runtime_error("cg_rotating_write not found");
#else
        auto sym_cg_rotating_write = dlsym(handle_, "cg_rotating_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_rotating_write_ = reinterpret_cast<int (*)(float const* rot_rate, float const* rot_center)>(sym_cg_rotating_write);
#ifdef _WIN32
        auto sym_cg_bc_wallfunction_read = GetProcAddress(handle_, "cg_bc_wallfunction_read");
        if (!sym_cg_bc_wallfunction_read)
            throw std::runtime_error("cg_bc_wallfunction_read not found");
#else
        auto sym_cg_bc_wallfunction_read = dlsym(handle_, "cg_bc_wallfunction_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_bc_wallfunction_read_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int BC, CGNS_ENUMT(WallFunctionType_t) * WallFunctionType)>(
        sym_cg_bc_wallfunction_read);
#ifdef _WIN32
        auto sym_cg_bc_wallfunction_write = GetProcAddress(handle_, "cg_bc_wallfunction_write");
        if (!sym_cg_bc_wallfunction_write)
            throw std::runtime_error("cg_bc_wallfunction_write not found");
#else
        auto sym_cg_bc_wallfunction_write = dlsym(handle_, "cg_bc_wallfunction_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_bc_wallfunction_write_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int BC, CGNS_ENUMT(WallFunctionType_t) WallFunctionType)>(
        sym_cg_bc_wallfunction_write);
#ifdef _WIN32
        auto sym_cg_bc_area_read = GetProcAddress(handle_, "cg_bc_area_read");
        if (!sym_cg_bc_area_read)
            throw std::runtime_error("cg_bc_area_read not found");
#else
        auto sym_cg_bc_area_read = dlsym(handle_, "cg_bc_area_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_bc_area_read_ = reinterpret_cast<int (*)(int file_number, int B, int Z, int BC, CGNS_ENUMT(AreaType_t) * AreaType,
                                                    float* SurfaceArea, char* RegionName)>(sym_cg_bc_area_read);
#ifdef _WIN32
        auto sym_cg_bc_area_write = GetProcAddress(handle_, "cg_bc_area_write");
        if (!sym_cg_bc_area_write)
            throw std::runtime_error("cg_bc_area_write not found");
#else
        auto sym_cg_bc_area_write = dlsym(handle_, "cg_bc_area_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_bc_area_write_ = reinterpret_cast<int (*)(int file_number, int B, int Z, int BC, CGNS_ENUMT(AreaType_t) AreaType,
                                                     float SurfaceArea, const char* RegionName)>(sym_cg_bc_area_write);
#ifdef _WIN32
        auto sym_cg_conn_periodic_read = GetProcAddress(handle_, "cg_conn_periodic_read");
        if (!sym_cg_conn_periodic_read)
            throw std::runtime_error("cg_conn_periodic_read not found");
#else
        auto sym_cg_conn_periodic_read = dlsym(handle_, "cg_conn_periodic_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_conn_periodic_read_ = reinterpret_cast<int (*)(int file_number, int B, int Z, int Ii, float* RotationCenter,
                                                          float* RotationAngle, float* Translation)>(sym_cg_conn_periodic_read);
#ifdef _WIN32
        auto sym_cg_conn_periodic_write = GetProcAddress(handle_, "cg_conn_periodic_write");
        if (!sym_cg_conn_periodic_write)
            throw std::runtime_error("cg_conn_periodic_write not found");
#else
        auto sym_cg_conn_periodic_write = dlsym(handle_, "cg_conn_periodic_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_conn_periodic_write_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int Ii, float const* RotationCenter, float const* RotationAngle,
                                 float const* Translation)>(sym_cg_conn_periodic_write);
#ifdef _WIN32
        auto sym_cg_1to1_periodic_write = GetProcAddress(handle_, "cg_1to1_periodic_write");
        if (!sym_cg_1to1_periodic_write)
            throw std::runtime_error("cg_1to1_periodic_write not found");
#else
        auto sym_cg_1to1_periodic_write = dlsym(handle_, "cg_1to1_periodic_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_1to1_periodic_write_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int Ii, float const* RotationCenter, float const* RotationAngle,
                                 float const* Translation)>(sym_cg_1to1_periodic_write);
#ifdef _WIN32
        auto sym_cg_1to1_periodic_read = GetProcAddress(handle_, "cg_1to1_periodic_read");
        if (!sym_cg_1to1_periodic_read)
            throw std::runtime_error("cg_1to1_periodic_read not found");
#else
        auto sym_cg_1to1_periodic_read = dlsym(handle_, "cg_1to1_periodic_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_1to1_periodic_read_ = reinterpret_cast<int (*)(int file_number, int B, int Z, int Ii, float* RotationCenter,
                                                          float* RotationAngle, float* Translation)>(sym_cg_1to1_periodic_read);
#ifdef _WIN32
        auto sym_cg_conn_average_read = GetProcAddress(handle_, "cg_conn_average_read");
        if (!sym_cg_conn_average_read)
            throw std::runtime_error("cg_conn_average_read not found");
#else
        auto sym_cg_conn_average_read = dlsym(handle_, "cg_conn_average_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_conn_average_read_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int Ii,
                                 CGNS_ENUMT(AverageInterfaceType_t) * AverageInterfaceType)>(sym_cg_conn_average_read);
#ifdef _WIN32
        auto sym_cg_conn_average_write = GetProcAddress(handle_, "cg_conn_average_write");
        if (!sym_cg_conn_average_write)
            throw std::runtime_error("cg_conn_average_write not found");
#else
        auto sym_cg_conn_average_write = dlsym(handle_, "cg_conn_average_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_conn_average_write_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int Ii, CGNS_ENUMT(AverageInterfaceType_t) AverageInterfaceType)>(
        sym_cg_conn_average_write);
#ifdef _WIN32
        auto sym_cg_1to1_average_write = GetProcAddress(handle_, "cg_1to1_average_write");
        if (!sym_cg_1to1_average_write)
            throw std::runtime_error("cg_1to1_average_write not found");
#else
        auto sym_cg_1to1_average_write = dlsym(handle_, "cg_1to1_average_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_1to1_average_write_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int Ii, CGNS_ENUMT(AverageInterfaceType_t) AverageInterfaceType)>(
        sym_cg_1to1_average_write);
#ifdef _WIN32
        auto sym_cg_1to1_average_read = GetProcAddress(handle_, "cg_1to1_average_read");
        if (!sym_cg_1to1_average_read)
            throw std::runtime_error("cg_1to1_average_read not found");
#else
        auto sym_cg_1to1_average_read = dlsym(handle_, "cg_1to1_average_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_1to1_average_read_ =
        reinterpret_cast<int (*)(int file_number, int B, int Z, int Ii,
                                 CGNS_ENUMT(AverageInterfaceType_t) * AverageInterfaceType)>(sym_cg_1to1_average_read);
#ifdef _WIN32
        auto sym_cg_goto = GetProcAddress(handle_, "cg_goto");
        if (!sym_cg_goto)
            throw std::runtime_error("cg_goto not found");
#else
        auto sym_cg_goto = dlsym(handle_, "cg_goto");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_goto_ = reinterpret_cast<int (*)(int file_number, int B, ...)>(sym_cg_goto);
#ifdef _WIN32
        auto sym_cg_goto_f08 = GetProcAddress(handle_, "cg_goto_f08");
        if (!sym_cg_goto_f08)
            throw std::runtime_error("cg_goto_f08 not found");
#else
        auto sym_cg_goto_f08 = dlsym(handle_, "cg_goto_f08");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_goto_f08_ = reinterpret_cast<int (*)(int file_number, int B, ...)>(sym_cg_goto_f08);
#ifdef _WIN32
        auto sym_cg_gorel = GetProcAddress(handle_, "cg_gorel");
        if (!sym_cg_gorel)
            throw std::runtime_error("cg_gorel not found");
#else
        auto sym_cg_gorel = dlsym(handle_, "cg_gorel");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_gorel_ = reinterpret_cast<int (*)(int file_number, ...)>(sym_cg_gorel);
#ifdef _WIN32
        auto sym_cg_gorel_f08 = GetProcAddress(handle_, "cg_gorel_f08");
        if (!sym_cg_gorel_f08)
            throw std::runtime_error("cg_gorel_f08 not found");
#else
        auto sym_cg_gorel_f08 = dlsym(handle_, "cg_gorel_f08");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_gorel_f08_ = reinterpret_cast<int (*)(int file_number, ...)>(sym_cg_gorel_f08);
#ifdef _WIN32
        auto sym_cg_gopath = GetProcAddress(handle_, "cg_gopath");
        if (!sym_cg_gopath)
            throw std::runtime_error("cg_gopath not found");
#else
        auto sym_cg_gopath = dlsym(handle_, "cg_gopath");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_gopath_ = reinterpret_cast<int (*)(int file_number, const char* path)>(sym_cg_gopath);
#ifdef _WIN32
        auto sym_cg_golist = GetProcAddress(handle_, "cg_golist");
        if (!sym_cg_golist)
            throw std::runtime_error("cg_golist not found");
#else
        auto sym_cg_golist = dlsym(handle_, "cg_golist");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_golist_ = reinterpret_cast<int (*)(int file_number, int B, int depth, char** label, int* num)>(sym_cg_golist);
#ifdef _WIN32
        auto sym_cg_where = GetProcAddress(handle_, "cg_where");
        if (!sym_cg_where)
            throw std::runtime_error("cg_where not found");
#else
        auto sym_cg_where = dlsym(handle_, "cg_where");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_where_ = reinterpret_cast<int (*)(int* file_number, int* B, int* depth, char** label, int* num)>(sym_cg_where);
#ifdef _WIN32
        auto sym_cg_convergence_read = GetProcAddress(handle_, "cg_convergence_read");
        if (!sym_cg_convergence_read)
            throw std::runtime_error("cg_convergence_read not found");
#else
        auto sym_cg_convergence_read = dlsym(handle_, "cg_convergence_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_convergence_read_ = reinterpret_cast<int (*)(int* iterations, char** NormDefinitions)>(sym_cg_convergence_read);
#ifdef _WIN32
        auto sym_cg_convergence_write = GetProcAddress(handle_, "cg_convergence_write");
        if (!sym_cg_convergence_write)
            throw std::runtime_error("cg_convergence_write not found");
#else
        auto sym_cg_convergence_write = dlsym(handle_, "cg_convergence_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_convergence_write_ = reinterpret_cast<int (*)(int iterations, const char* NormDefinitions)>(sym_cg_convergence_write);
#ifdef _WIN32
        auto sym_cg_state_read = GetProcAddress(handle_, "cg_state_read");
        if (!sym_cg_state_read)
            throw std::runtime_error("cg_state_read not found");
#else
        auto sym_cg_state_read = dlsym(handle_, "cg_state_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_state_read_ = reinterpret_cast<int (*)(char** StateDescription)>(sym_cg_state_read);
#ifdef _WIN32
        auto sym_cg_state_write = GetProcAddress(handle_, "cg_state_write");
        if (!sym_cg_state_write)
            throw std::runtime_error("cg_state_write not found");
#else
        auto sym_cg_state_write = dlsym(handle_, "cg_state_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_state_write_ = reinterpret_cast<int (*)(const char* StateDescription)>(sym_cg_state_write);
#ifdef _WIN32
        auto sym_cg_equationset_read = GetProcAddress(handle_, "cg_equationset_read");
        if (!sym_cg_equationset_read)
            throw std::runtime_error("cg_equationset_read not found");
#else
        auto sym_cg_equationset_read = dlsym(handle_, "cg_equationset_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_equationset_read_ =
        reinterpret_cast<int (*)(int* EquationDimension, int* GoverningEquationsFlag, int* GasModelFlag, int* ViscosityModelFlag,
                                 int* ThermalConductivityModelFlag, int* TurbulenceClosureFlag, int* TurbulenceModelFlag)>(
        sym_cg_equationset_read);
#ifdef _WIN32
        auto sym_cg_equationset_chemistry_read = GetProcAddress(handle_, "cg_equationset_chemistry_read");
        if (!sym_cg_equationset_chemistry_read)
            throw std::runtime_error("cg_equationset_chemistry_read not found");
#else
        auto sym_cg_equationset_chemistry_read = dlsym(handle_, "cg_equationset_chemistry_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_equationset_chemistry_read_ =
        reinterpret_cast<int (*)(int* ThermalRelaxationFlag, int* ChemicalKineticsFlag)>(sym_cg_equationset_chemistry_read);
#ifdef _WIN32
        auto sym_cg_equationset_elecmagn_read = GetProcAddress(handle_, "cg_equationset_elecmagn_read");
        if (!sym_cg_equationset_elecmagn_read)
            throw std::runtime_error("cg_equationset_elecmagn_read not found");
#else
        auto sym_cg_equationset_elecmagn_read = dlsym(handle_, "cg_equationset_elecmagn_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_equationset_elecmagn_read_ =
        reinterpret_cast<int (*)(int* ElecFldModelFlag, int* MagnFldModelFlag, int* ConductivityModelFlag)>(
        sym_cg_equationset_elecmagn_read);
#ifdef _WIN32
        auto sym_cg_equationset_write = GetProcAddress(handle_, "cg_equationset_write");
        if (!sym_cg_equationset_write)
            throw std::runtime_error("cg_equationset_write not found");
#else
        auto sym_cg_equationset_write = dlsym(handle_, "cg_equationset_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_equationset_write_ = reinterpret_cast<int (*)(int EquationDimension)>(sym_cg_equationset_write);
#ifdef _WIN32
        auto sym_cg_governing_read = GetProcAddress(handle_, "cg_governing_read");
        if (!sym_cg_governing_read)
            throw std::runtime_error("cg_governing_read not found");
#else
        auto sym_cg_governing_read = dlsym(handle_, "cg_governing_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_governing_read_ =
        reinterpret_cast<int (*)(CGNS_ENUMT(GoverningEquationsType_t) * EquationsType)>(sym_cg_governing_read);
#ifdef _WIN32
        auto sym_cg_governing_write = GetProcAddress(handle_, "cg_governing_write");
        if (!sym_cg_governing_write)
            throw std::runtime_error("cg_governing_write not found");
#else
        auto sym_cg_governing_write = dlsym(handle_, "cg_governing_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_governing_write_ =
        reinterpret_cast<int (*)(CGNS_ENUMT(GoverningEquationsType_t) Equationstype)>(sym_cg_governing_write);
#ifdef _WIN32
        auto sym_cg_diffusion_read = GetProcAddress(handle_, "cg_diffusion_read");
        if (!sym_cg_diffusion_read)
            throw std::runtime_error("cg_diffusion_read not found");
#else
        auto sym_cg_diffusion_read = dlsym(handle_, "cg_diffusion_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_diffusion_read_ = reinterpret_cast<int (*)(int* diffusion_model)>(sym_cg_diffusion_read);
#ifdef _WIN32
        auto sym_cg_diffusion_write = GetProcAddress(handle_, "cg_diffusion_write");
        if (!sym_cg_diffusion_write)
            throw std::runtime_error("cg_diffusion_write not found");
#else
        auto sym_cg_diffusion_write = dlsym(handle_, "cg_diffusion_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_diffusion_write_ = reinterpret_cast<int (*)(const int* diffusion_model)>(sym_cg_diffusion_write);
#ifdef _WIN32
        auto sym_cg_model_read = GetProcAddress(handle_, "cg_model_read");
        if (!sym_cg_model_read)
            throw std::runtime_error("cg_model_read not found");
#else
        auto sym_cg_model_read = dlsym(handle_, "cg_model_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_model_read_ =
        reinterpret_cast<int (*)(const char* ModelLabel, CGNS_ENUMT(ModelType_t) * ModelType)>(sym_cg_model_read);
#ifdef _WIN32
        auto sym_cg_model_write = GetProcAddress(handle_, "cg_model_write");
        if (!sym_cg_model_write)
            throw std::runtime_error("cg_model_write not found");
#else
        auto sym_cg_model_write = dlsym(handle_, "cg_model_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_model_write_ =
        reinterpret_cast<int (*)(const char* ModelLabel, CGNS_ENUMT(ModelType_t) ModelType)>(sym_cg_model_write);
#ifdef _WIN32
        auto sym_cg_narrays = GetProcAddress(handle_, "cg_narrays");
        if (!sym_cg_narrays)
            throw std::runtime_error("cg_narrays not found");
#else
        auto sym_cg_narrays = dlsym(handle_, "cg_narrays");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_narrays_ = reinterpret_cast<int (*)(int* narrays)>(sym_cg_narrays);
#ifdef _WIN32
        auto sym_cg_array_info = GetProcAddress(handle_, "cg_array_info");
        if (!sym_cg_array_info)
            throw std::runtime_error("cg_array_info not found");
#else
        auto sym_cg_array_info = dlsym(handle_, "cg_array_info");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_array_info_ = reinterpret_cast<int (*)(int A, char* ArrayName, CGNS_ENUMT(DataType_t) * DataType, int* DataDimension,
                                                  cgsize_t* DimensionVector)>(sym_cg_array_info);
#ifdef _WIN32
        auto sym_cg_array_read = GetProcAddress(handle_, "cg_array_read");
        if (!sym_cg_array_read)
            throw std::runtime_error("cg_array_read not found");
#else
        auto sym_cg_array_read = dlsym(handle_, "cg_array_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_array_read_ = reinterpret_cast<int (*)(int A, void* Data)>(sym_cg_array_read);
#ifdef _WIN32
        auto sym_cg_array_read_as = GetProcAddress(handle_, "cg_array_read_as");
        if (!sym_cg_array_read_as)
            throw std::runtime_error("cg_array_read_as not found");
#else
        auto sym_cg_array_read_as = dlsym(handle_, "cg_array_read_as");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_array_read_as_ = reinterpret_cast<int (*)(int A, CGNS_ENUMT(DataType_t) type, void* Data)>(sym_cg_array_read_as);
#ifdef _WIN32
        auto sym_cg_array_general_read = GetProcAddress(handle_, "cg_array_general_read");
        if (!sym_cg_array_general_read)
            throw std::runtime_error("cg_array_general_read not found");
#else
        auto sym_cg_array_general_read = dlsym(handle_, "cg_array_general_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_array_general_read_ = reinterpret_cast<int (*)(
        int A, const cgsize_t* s_rmin, const cgsize_t* s_rmax, CGNS_ENUMT(DataType_t) m_type, int m_numdim,
        const cgsize_t* m_dimvals, const cgsize_t* m_rmin, const cgsize_t* m_rmax, void* data)>(sym_cg_array_general_read);
#ifdef _WIN32
        auto sym_cg_array_write = GetProcAddress(handle_, "cg_array_write");
        if (!sym_cg_array_write)
            throw std::runtime_error("cg_array_write not found");
#else
        auto sym_cg_array_write = dlsym(handle_, "cg_array_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_array_write_ = reinterpret_cast<int (*)(const char* ArrayName, CGNS_ENUMT(DataType_t) DataType, int DataDimension,
                                                   const cgsize_t* DimensionVector, const void* Data)>(sym_cg_array_write);
#ifdef _WIN32
        auto sym_cg_array_general_write = GetProcAddress(handle_, "cg_array_general_write");
        if (!sym_cg_array_general_write)
            throw std::runtime_error("cg_array_general_write not found");
#else
        auto sym_cg_array_general_write = dlsym(handle_, "cg_array_general_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_array_general_write_ =
        reinterpret_cast<int (*)(const char* arrayname, CGNS_ENUMT(DataType_t) s_type, int s_numdim, const cgsize_t* s_dimvals,
                                 const cgsize_t* s_rmin, const cgsize_t* s_rmax, CGNS_ENUMT(DataType_t) m_type, int m_numdim,
                                 const cgsize_t* m_dimvals, const cgsize_t* m_rmin, const cgsize_t* m_rmax, const void* data)>(
        sym_cg_array_general_write);
#ifdef _WIN32
        auto sym_cg_nuser_data = GetProcAddress(handle_, "cg_nuser_data");
        if (!sym_cg_nuser_data)
            throw std::runtime_error("cg_nuser_data not found");
#else
        auto sym_cg_nuser_data = dlsym(handle_, "cg_nuser_data");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_nuser_data_ = reinterpret_cast<int (*)(int* nuser_data)>(sym_cg_nuser_data);
#ifdef _WIN32
        auto sym_cg_user_data_read = GetProcAddress(handle_, "cg_user_data_read");
        if (!sym_cg_user_data_read)
            throw std::runtime_error("cg_user_data_read not found");
#else
        auto sym_cg_user_data_read = dlsym(handle_, "cg_user_data_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_user_data_read_ = reinterpret_cast<int (*)(int Index, char* user_data_name)>(sym_cg_user_data_read);
#ifdef _WIN32
        auto sym_cg_user_data_write = GetProcAddress(handle_, "cg_user_data_write");
        if (!sym_cg_user_data_write)
            throw std::runtime_error("cg_user_data_write not found");
#else
        auto sym_cg_user_data_write = dlsym(handle_, "cg_user_data_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_user_data_write_ = reinterpret_cast<int (*)(const char* user_data_name)>(sym_cg_user_data_write);
#ifdef _WIN32
        auto sym_cg_nintegrals = GetProcAddress(handle_, "cg_nintegrals");
        if (!sym_cg_nintegrals)
            throw std::runtime_error("cg_nintegrals not found");
#else
        auto sym_cg_nintegrals = dlsym(handle_, "cg_nintegrals");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_nintegrals_ = reinterpret_cast<int (*)(int* nintegrals)>(sym_cg_nintegrals);
#ifdef _WIN32
        auto sym_cg_integral_read = GetProcAddress(handle_, "cg_integral_read");
        if (!sym_cg_integral_read)
            throw std::runtime_error("cg_integral_read not found");
#else
        auto sym_cg_integral_read = dlsym(handle_, "cg_integral_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_integral_read_ = reinterpret_cast<int (*)(int IntegralDataIndex, char* IntegralDataName)>(sym_cg_integral_read);
#ifdef _WIN32
        auto sym_cg_integral_write = GetProcAddress(handle_, "cg_integral_write");
        if (!sym_cg_integral_write)
            throw std::runtime_error("cg_integral_write not found");
#else
        auto sym_cg_integral_write = dlsym(handle_, "cg_integral_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_integral_write_ = reinterpret_cast<int (*)(const char* IntegralDataName)>(sym_cg_integral_write);
#ifdef _WIN32
        auto sym_cg_rind_read = GetProcAddress(handle_, "cg_rind_read");
        if (!sym_cg_rind_read)
            throw std::runtime_error("cg_rind_read not found");
#else
        auto sym_cg_rind_read = dlsym(handle_, "cg_rind_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_rind_read_ = reinterpret_cast<int (*)(int* RindData)>(sym_cg_rind_read);
#ifdef _WIN32
        auto sym_cg_rind_write = GetProcAddress(handle_, "cg_rind_write");
        if (!sym_cg_rind_write)
            throw std::runtime_error("cg_rind_write not found");
#else
        auto sym_cg_rind_write = dlsym(handle_, "cg_rind_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_rind_write_ = reinterpret_cast<int (*)(const int* RindData)>(sym_cg_rind_write);
#ifdef _WIN32
        auto sym_cg_ndescriptors = GetProcAddress(handle_, "cg_ndescriptors");
        if (!sym_cg_ndescriptors)
            throw std::runtime_error("cg_ndescriptors not found");
#else
        auto sym_cg_ndescriptors = dlsym(handle_, "cg_ndescriptors");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_ndescriptors_ = reinterpret_cast<int (*)(int* ndescriptors)>(sym_cg_ndescriptors);
#ifdef _WIN32
        auto sym_cg_descriptor_read = GetProcAddress(handle_, "cg_descriptor_read");
        if (!sym_cg_descriptor_read)
            throw std::runtime_error("cg_descriptor_read not found");
#else
        auto sym_cg_descriptor_read = dlsym(handle_, "cg_descriptor_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_descriptor_read_ =
        reinterpret_cast<int (*)(int descr_no, char* descr_name, char** descr_text)>(sym_cg_descriptor_read);
#ifdef _WIN32
        auto sym_cg_descriptor_write = GetProcAddress(handle_, "cg_descriptor_write");
        if (!sym_cg_descriptor_write)
            throw std::runtime_error("cg_descriptor_write not found");
#else
        auto sym_cg_descriptor_write = dlsym(handle_, "cg_descriptor_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_descriptor_write_ = reinterpret_cast<int (*)(const char* descr_name, const char* descr_text)>(sym_cg_descriptor_write);
#ifdef _WIN32
        auto sym_cg_nunits = GetProcAddress(handle_, "cg_nunits");
        if (!sym_cg_nunits)
            throw std::runtime_error("cg_nunits not found");
#else
        auto sym_cg_nunits = dlsym(handle_, "cg_nunits");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_nunits_ = reinterpret_cast<int (*)(int* nunits)>(sym_cg_nunits);
#ifdef _WIN32
        auto sym_cg_units_read = GetProcAddress(handle_, "cg_units_read");
        if (!sym_cg_units_read)
            throw std::runtime_error("cg_units_read not found");
#else
        auto sym_cg_units_read = dlsym(handle_, "cg_units_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_units_read_ = reinterpret_cast<int (*)(CGNS_ENUMT(MassUnits_t) * mass, CGNS_ENUMT(LengthUnits_t) * length,
                                                  CGNS_ENUMT(TimeUnits_t) * time, CGNS_ENUMT(TemperatureUnits_t) * temperature,
                                                  CGNS_ENUMT(AngleUnits_t) * angle)>(sym_cg_units_read);
#ifdef _WIN32
        auto sym_cg_units_write = GetProcAddress(handle_, "cg_units_write");
        if (!sym_cg_units_write)
            throw std::runtime_error("cg_units_write not found");
#else
        auto sym_cg_units_write = dlsym(handle_, "cg_units_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_units_write_ =
        reinterpret_cast<int (*)(CGNS_ENUMT(MassUnits_t) mass, CGNS_ENUMT(LengthUnits_t) length, CGNS_ENUMT(TimeUnits_t) time,
                                 CGNS_ENUMT(TemperatureUnits_t) temperature, CGNS_ENUMT(AngleUnits_t) angle)>(sym_cg_units_write);
#ifdef _WIN32
        auto sym_cg_unitsfull_read = GetProcAddress(handle_, "cg_unitsfull_read");
        if (!sym_cg_unitsfull_read)
            throw std::runtime_error("cg_unitsfull_read not found");
#else
        auto sym_cg_unitsfull_read = dlsym(handle_, "cg_unitsfull_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_unitsfull_read_ =
        reinterpret_cast<int (*)(CGNS_ENUMT(MassUnits_t) * mass, CGNS_ENUMT(LengthUnits_t) * length,
                                 CGNS_ENUMT(TimeUnits_t) * time, CGNS_ENUMT(TemperatureUnits_t) * temperature,
                                 CGNS_ENUMT(AngleUnits_t) * angle, CGNS_ENUMT(ElectricCurrentUnits_t) * current,
                                 CGNS_ENUMT(SubstanceAmountUnits_t) * amount, CGNS_ENUMT(LuminousIntensityUnits_t) * intensity)>(
        sym_cg_unitsfull_read);
#ifdef _WIN32
        auto sym_cg_unitsfull_write = GetProcAddress(handle_, "cg_unitsfull_write");
        if (!sym_cg_unitsfull_write)
            throw std::runtime_error("cg_unitsfull_write not found");
#else
        auto sym_cg_unitsfull_write = dlsym(handle_, "cg_unitsfull_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_unitsfull_write_ = reinterpret_cast<int (*)(
        CGNS_ENUMT(MassUnits_t) mass, CGNS_ENUMT(LengthUnits_t) length, CGNS_ENUMT(TimeUnits_t) time,
        CGNS_ENUMT(TemperatureUnits_t) temperature, CGNS_ENUMT(AngleUnits_t) angle, CGNS_ENUMT(ElectricCurrentUnits_t) current,
        CGNS_ENUMT(SubstanceAmountUnits_t) amount, CGNS_ENUMT(LuminousIntensityUnits_t) intensity)>(sym_cg_unitsfull_write);
#ifdef _WIN32
        auto sym_cg_exponents_info = GetProcAddress(handle_, "cg_exponents_info");
        if (!sym_cg_exponents_info)
            throw std::runtime_error("cg_exponents_info not found");
#else
        auto sym_cg_exponents_info = dlsym(handle_, "cg_exponents_info");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_exponents_info_ = reinterpret_cast<int (*)(CGNS_ENUMT(DataType_t) * DataType)>(sym_cg_exponents_info);
#ifdef _WIN32
        auto sym_cg_nexponents = GetProcAddress(handle_, "cg_nexponents");
        if (!sym_cg_nexponents)
            throw std::runtime_error("cg_nexponents not found");
#else
        auto sym_cg_nexponents = dlsym(handle_, "cg_nexponents");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_nexponents_ = reinterpret_cast<int (*)(int* numexp)>(sym_cg_nexponents);
#ifdef _WIN32
        auto sym_cg_exponents_read = GetProcAddress(handle_, "cg_exponents_read");
        if (!sym_cg_exponents_read)
            throw std::runtime_error("cg_exponents_read not found");
#else
        auto sym_cg_exponents_read = dlsym(handle_, "cg_exponents_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_exponents_read_ = reinterpret_cast<int (*)(void* exponents)>(sym_cg_exponents_read);
#ifdef _WIN32
        auto sym_cg_exponents_write = GetProcAddress(handle_, "cg_exponents_write");
        if (!sym_cg_exponents_write)
            throw std::runtime_error("cg_exponents_write not found");
#else
        auto sym_cg_exponents_write = dlsym(handle_, "cg_exponents_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_exponents_write_ =
        reinterpret_cast<int (*)(CGNS_ENUMT(DataType_t) DataType, const void* exponents)>(sym_cg_exponents_write);
#ifdef _WIN32
        auto sym_cg_expfull_read = GetProcAddress(handle_, "cg_expfull_read");
        if (!sym_cg_expfull_read)
            throw std::runtime_error("cg_expfull_read not found");
#else
        auto sym_cg_expfull_read = dlsym(handle_, "cg_expfull_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_expfull_read_ = reinterpret_cast<int (*)(void* exponents)>(sym_cg_expfull_read);
#ifdef _WIN32
        auto sym_cg_expfull_write = GetProcAddress(handle_, "cg_expfull_write");
        if (!sym_cg_expfull_write)
            throw std::runtime_error("cg_expfull_write not found");
#else
        auto sym_cg_expfull_write = dlsym(handle_, "cg_expfull_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_expfull_write_ =
        reinterpret_cast<int (*)(CGNS_ENUMT(DataType_t) DataType, const void* exponents)>(sym_cg_expfull_write);
#ifdef _WIN32
        auto sym_cg_conversion_info = GetProcAddress(handle_, "cg_conversion_info");
        if (!sym_cg_conversion_info)
            throw std::runtime_error("cg_conversion_info not found");
#else
        auto sym_cg_conversion_info = dlsym(handle_, "cg_conversion_info");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_conversion_info_ = reinterpret_cast<int (*)(CGNS_ENUMT(DataType_t) * DataType)>(sym_cg_conversion_info);
#ifdef _WIN32
        auto sym_cg_conversion_read = GetProcAddress(handle_, "cg_conversion_read");
        if (!sym_cg_conversion_read)
            throw std::runtime_error("cg_conversion_read not found");
#else
        auto sym_cg_conversion_read = dlsym(handle_, "cg_conversion_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_conversion_read_ = reinterpret_cast<int (*)(void* ConversionFactors)>(sym_cg_conversion_read);
#ifdef _WIN32
        auto sym_cg_conversion_write = GetProcAddress(handle_, "cg_conversion_write");
        if (!sym_cg_conversion_write)
            throw std::runtime_error("cg_conversion_write not found");
#else
        auto sym_cg_conversion_write = dlsym(handle_, "cg_conversion_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_conversion_write_ =
        reinterpret_cast<int (*)(CGNS_ENUMT(DataType_t) DataType, const void* ConversionFactors)>(sym_cg_conversion_write);
#ifdef _WIN32
        auto sym_cg_dataclass_read = GetProcAddress(handle_, "cg_dataclass_read");
        if (!sym_cg_dataclass_read)
            throw std::runtime_error("cg_dataclass_read not found");
#else
        auto sym_cg_dataclass_read = dlsym(handle_, "cg_dataclass_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_dataclass_read_ = reinterpret_cast<int (*)(CGNS_ENUMT(DataClass_t) * dataclass)>(sym_cg_dataclass_read);
#ifdef _WIN32
        auto sym_cg_dataclass_write = GetProcAddress(handle_, "cg_dataclass_write");
        if (!sym_cg_dataclass_write)
            throw std::runtime_error("cg_dataclass_write not found");
#else
        auto sym_cg_dataclass_write = dlsym(handle_, "cg_dataclass_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_dataclass_write_ = reinterpret_cast<int (*)(CGNS_ENUMT(DataClass_t) dataclass)>(sym_cg_dataclass_write);
#ifdef _WIN32
        auto sym_cg_gridlocation_read = GetProcAddress(handle_, "cg_gridlocation_read");
        if (!sym_cg_gridlocation_read)
            throw std::runtime_error("cg_gridlocation_read not found");
#else
        auto sym_cg_gridlocation_read = dlsym(handle_, "cg_gridlocation_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_gridlocation_read_ = reinterpret_cast<int (*)(CGNS_ENUMT(GridLocation_t) * GridLocation)>(sym_cg_gridlocation_read);
#ifdef _WIN32
        auto sym_cg_gridlocation_write = GetProcAddress(handle_, "cg_gridlocation_write");
        if (!sym_cg_gridlocation_write)
            throw std::runtime_error("cg_gridlocation_write not found");
#else
        auto sym_cg_gridlocation_write = dlsym(handle_, "cg_gridlocation_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_gridlocation_write_ = reinterpret_cast<int (*)(CGNS_ENUMT(GridLocation_t) GridLocation)>(sym_cg_gridlocation_write);
#ifdef _WIN32
        auto sym_cg_ordinal_read = GetProcAddress(handle_, "cg_ordinal_read");
        if (!sym_cg_ordinal_read)
            throw std::runtime_error("cg_ordinal_read not found");
#else
        auto sym_cg_ordinal_read = dlsym(handle_, "cg_ordinal_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_ordinal_read_ = reinterpret_cast<int (*)(int* Ordinal)>(sym_cg_ordinal_read);
#ifdef _WIN32
        auto sym_cg_ordinal_write = GetProcAddress(handle_, "cg_ordinal_write");
        if (!sym_cg_ordinal_write)
            throw std::runtime_error("cg_ordinal_write not found");
#else
        auto sym_cg_ordinal_write = dlsym(handle_, "cg_ordinal_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_ordinal_write_ = reinterpret_cast<int (*)(int Ordinal)>(sym_cg_ordinal_write);
#ifdef _WIN32
        auto sym_cg_ptset_info = GetProcAddress(handle_, "cg_ptset_info");
        if (!sym_cg_ptset_info)
            throw std::runtime_error("cg_ptset_info not found");
#else
        auto sym_cg_ptset_info = dlsym(handle_, "cg_ptset_info");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_ptset_info_ = reinterpret_cast<int (*)(CGNS_ENUMT(PointSetType_t) * ptset_type, cgsize_t * npnts)>(sym_cg_ptset_info);
#ifdef _WIN32
        auto sym_cg_ptset_write = GetProcAddress(handle_, "cg_ptset_write");
        if (!sym_cg_ptset_write)
            throw std::runtime_error("cg_ptset_write not found");
#else
        auto sym_cg_ptset_write = dlsym(handle_, "cg_ptset_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_ptset_write_ = reinterpret_cast<int (*)(CGNS_ENUMT(PointSetType_t) ptset_type, cgsize_t npnts, const cgsize_t* pnts)>(
        sym_cg_ptset_write);
#ifdef _WIN32
        auto sym_cg_ptset_read = GetProcAddress(handle_, "cg_ptset_read");
        if (!sym_cg_ptset_read)
            throw std::runtime_error("cg_ptset_read not found");
#else
        auto sym_cg_ptset_read = dlsym(handle_, "cg_ptset_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_ptset_read_ = reinterpret_cast<int (*)(cgsize_t* pnts)>(sym_cg_ptset_read);
#ifdef _WIN32
        auto sym_cg_is_link = GetProcAddress(handle_, "cg_is_link");
        if (!sym_cg_is_link)
            throw std::runtime_error("cg_is_link not found");
#else
        auto sym_cg_is_link = dlsym(handle_, "cg_is_link");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_is_link_ = reinterpret_cast<int (*)(int* path_length)>(sym_cg_is_link);
#ifdef _WIN32
        auto sym_cg_link_read = GetProcAddress(handle_, "cg_link_read");
        if (!sym_cg_link_read)
            throw std::runtime_error("cg_link_read not found");
#else
        auto sym_cg_link_read = dlsym(handle_, "cg_link_read");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_link_read_ = reinterpret_cast<int (*)(char** filename, char** link_path)>(sym_cg_link_read);
#ifdef _WIN32
        auto sym_cg_link_write = GetProcAddress(handle_, "cg_link_write");
        if (!sym_cg_link_write)
            throw std::runtime_error("cg_link_write not found");
#else
        auto sym_cg_link_write = dlsym(handle_, "cg_link_write");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_link_write_ =
        reinterpret_cast<int (*)(const char* nodename, const char* filename, const char* name_in_file)>(sym_cg_link_write);
#ifdef _WIN32
        auto sym_cg_delete_node = GetProcAddress(handle_, "cg_delete_node");
        if (!sym_cg_delete_node)
            throw std::runtime_error("cg_delete_node not found");
#else
        auto sym_cg_delete_node = dlsym(handle_, "cg_delete_node");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_delete_node_ = reinterpret_cast<int (*)(const char* node_name)>(sym_cg_delete_node);
#ifdef _WIN32
        auto sym_cg_free = GetProcAddress(handle_, "cg_free");
        if (!sym_cg_free)
            throw std::runtime_error("cg_free not found");
#else
        auto sym_cg_free = dlsym(handle_, "cg_free");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_free_ = reinterpret_cast<int (*)(void* data)>(sym_cg_free);
#ifdef _WIN32
        auto sym_cg_get_error = GetProcAddress(handle_, "cg_get_error");
        if (!sym_cg_get_error)
            throw std::runtime_error("cg_get_error not found");
#else
        auto sym_cg_get_error = dlsym(handle_, "cg_get_error");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_get_error_ = reinterpret_cast<const char* (*)(void)>(sym_cg_get_error);
#ifdef _WIN32
        auto sym_cg_error_exit = GetProcAddress(handle_, "cg_error_exit");
        if (!sym_cg_error_exit)
            throw std::runtime_error("cg_error_exit not found");
#else
        auto sym_cg_error_exit = dlsym(handle_, "cg_error_exit");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_error_exit_ = reinterpret_cast<void (*)(void)>(sym_cg_error_exit);
#ifdef _WIN32
        auto sym_cg_error_print = GetProcAddress(handle_, "cg_error_print");
        if (!sym_cg_error_print)
            throw std::runtime_error("cg_error_print not found");
#else
        auto sym_cg_error_print = dlsym(handle_, "cg_error_print");
        if (char* e = dlerror())
            throw std::runtime_error(e);
#endif
        cg_error_print_ = reinterpret_cast<void (*)(void)>(sym_cg_error_print);
    }

  public:
    int (*cg_is_cgns_)(const char* filename, int* file_type) = nullptr;
    int (*cg_open_)(const char* filename, int mode, int* fn) = nullptr;
    int (*cg_version_)(int fn, float* FileVersion) = nullptr;
    int (*cg_precision_)(int fn, int* precision) = nullptr;
    int (*cg_close_)(int fn) = nullptr;
    int (*cg_save_as_)(int fn, const char* filename, int file_type, int follow_links) = nullptr;
    int (*cg_set_file_type_)(int file_type) = nullptr;
    int (*cg_get_file_type_)(int fn, int* file_type) = nullptr;
    int (*cg_root_id_)(int fn, double* rootid) = nullptr;
    int (*cg_get_cgio_)(int fn, int* cgio_num) = nullptr;
    int (*cg_configure_)(int what, void* value) = nullptr;
    int (*cg_error_handler_)(void (*)(int, char*)) = nullptr;
    int (*cg_set_compress_)(int compress) = nullptr;
    int (*cg_get_compress_)(int* compress) = nullptr;
    int (*cg_set_path_)(const char* path) = nullptr;
    int (*cg_add_path_)(const char* path) = nullptr;
    const char* (*cg_get_name_)(int nnames, const char** names, int type) = nullptr;
    const char* (*cg_MassUnitsName_)(CGNS_ENUMT(MassUnits_t) type) = nullptr;
    const char* (*cg_LengthUnitsName_)(CGNS_ENUMT(LengthUnits_t) type) = nullptr;
    const char* (*cg_TimeUnitsName_)(CGNS_ENUMT(TimeUnits_t) type) = nullptr;
    const char* (*cg_TemperatureUnitsName_)(CGNS_ENUMT(TemperatureUnits_t) type) = nullptr;
    const char* (*cg_AngleUnitsName_)(CGNS_ENUMT(AngleUnits_t) type) = nullptr;
    const char* (*cg_ElectricCurrentUnitsName_)(CGNS_ENUMT(ElectricCurrentUnits_t) type) = nullptr;
    const char* (*cg_SubstanceAmountUnitsName_)(CGNS_ENUMT(SubstanceAmountUnits_t) type) = nullptr;
    const char* (*cg_LuminousIntensityUnitsName_)(CGNS_ENUMT(LuminousIntensityUnits_t) type) = nullptr;
    const char* (*cg_DataClassName_)(CGNS_ENUMT(DataClass_t) type) = nullptr;
    const char* (*cg_GridLocationName_)(CGNS_ENUMT(GridLocation_t) type) = nullptr;
    const char* (*cg_BCDataTypeName_)(CGNS_ENUMT(BCDataType_t) type) = nullptr;
    const char* (*cg_GridConnectivityTypeName_)(CGNS_ENUMT(GridConnectivityType_t) type) = nullptr;
    const char* (*cg_PointSetTypeName_)(CGNS_ENUMT(PointSetType_t) type) = nullptr;
    const char* (*cg_GoverningEquationsTypeName_)(CGNS_ENUMT(GoverningEquationsType_t) type) = nullptr;
    const char* (*cg_ModelTypeName_)(CGNS_ENUMT(ModelType_t) type) = nullptr;
    const char* (*cg_BCTypeName_)(CGNS_ENUMT(BCType_t) type) = nullptr;
    const char* (*cg_DataTypeName_)(CGNS_ENUMT(DataType_t) type) = nullptr;
    const char* (*cg_ElementTypeName_)(CGNS_ENUMT(ElementType_t) type) = nullptr;
    const char* (*cg_ZoneTypeName_)(CGNS_ENUMT(ZoneType_t) type) = nullptr;
    const char* (*cg_RigidGridMotionTypeName_)(CGNS_ENUMT(RigidGridMotionType_t) type) = nullptr;
    const char* (*cg_ArbitraryGridMotionTypeName_)(CGNS_ENUMT(ArbitraryGridMotionType_t) type) = nullptr;
    const char* (*cg_SimulationTypeName_)(CGNS_ENUMT(SimulationType_t) type) = nullptr;
    const char* (*cg_WallFunctionTypeName_)(CGNS_ENUMT(WallFunctionType_t) type) = nullptr;
    const char* (*cg_AreaTypeName_)(CGNS_ENUMT(AreaType_t) type) = nullptr;
    const char* (*cg_AverageInterfaceTypeName_)(CGNS_ENUMT(AverageInterfaceType_t) type) = nullptr;
    int (*cg_nbases_)(int fn, int* nbases) = nullptr;
    int (*cg_base_read_)(int file_number, int B, char* basename, int* cell_dim, int* phys_dim) = nullptr;
    int (*cg_base_id_)(int fn, int B, double* base_id) = nullptr;
    int (*cg_base_write_)(int file_number, const char* basename, int cell_dim, int phys_dim, int* B) = nullptr;
    int (*cg_cell_dim_)(int fn, int B, int* cell_dim) = nullptr;
    int (*cg_nzones_)(int fn, int B, int* nzones) = nullptr;
    int (*cg_zone_read_)(int fn, int B, int Z, char* zonename, cgsize_t* size) = nullptr;
    int (*cg_zone_type_)(int file_number, int B, int Z, CGNS_ENUMT(ZoneType_t) * type) = nullptr;
    int (*cg_zone_id_)(int fn, int B, int Z, double* zone_id) = nullptr;
    int (*cg_zone_write_)(int fn, int B, const char* zonename, const cgsize_t* size, CGNS_ENUMT(ZoneType_t) type,
                          int* Z) = nullptr;
    int (*cg_index_dim_)(int fn, int B, int Z, int* index_dim) = nullptr;
    int (*cg_nfamilies_)(int file_number, int B, int* nfamilies) = nullptr;
    int (*cg_family_read_)(int file_number, int B, int F, char* family_name, int* nboco, int* ngeos) = nullptr;
    int (*cg_family_write_)(int file_number, int B, const char* family_name, int* F) = nullptr;
    int (*cg_nfamily_names_)(int file_number, int B, int F, int* nnames) = nullptr;
    int (*cg_family_name_read_)(int file_number, int B, int F, int N, char* name, char* family) = nullptr;
    int (*cg_family_name_write_)(int file_number, int B, int F, const char* name, const char* family) = nullptr;
    int (*cg_node_family_write_)(const char* family_name, int* F) = nullptr;
    int (*cg_node_nfamilies_)(int* nfamilies) = nullptr;
    int (*cg_node_family_read_)(int F, char* family_name, int* nFamBC, int* nGeo) = nullptr;
    int (*cg_node_family_name_write_)(const char* node_name, const char* family_name) = nullptr;
    int (*cg_node_nfamily_names_)(int* nnames) = nullptr;
    int (*cg_node_family_name_read_)(int N, char* node_name, char* family_name) = nullptr;
    int (*cg_famname_read_)(char* family_name) = nullptr;
    int (*cg_famname_write_)(const char* family_name) = nullptr;
    int (*cg_nmultifam_)(int* nfams) = nullptr;
    int (*cg_multifam_read_)(int N, char* name, char* family) = nullptr;
    int (*cg_multifam_write_)(const char* name, const char* family) = nullptr;
    int (*cg_fambc_read_)(int file_number, int B, int F, int BC, char* fambc_name, CGNS_ENUMT(BCType_t) * bocotype) = nullptr;
    int (*cg_fambc_write_)(int file_number, int B, int F, const char* fambc_name, CGNS_ENUMT(BCType_t) bocotype,
                           int* BC) = nullptr;
    int (*cg_node_fambc_read_)(int BC, char* fambc_name, CGNS_ENUMT(BCType_t) * bocotype) = nullptr;
    int (*cg_node_fambc_write_)(const char* fambc_name, CGNS_ENUMT(BCType_t) bocotype, int* BC) = nullptr;
    int (*cg_geo_read_)(int file_number, int B, int F, int G, char* geo_name, char** geo_file, char* CAD_name,
                        int* npart) = nullptr;
    int (*cg_geo_write_)(int file_number, int B, int F, const char* geo_name, const char* filename, const char* CADname,
                         int* G) = nullptr;
    int (*cg_node_geo_read_)(int G, char* geo_name, char** geo_file, char* CAD_name, int* npart) = nullptr;
    int (*cg_node_geo_write_)(const char* geo_name, const char* filename, const char* CADname, int* G) = nullptr;
    int (*cg_part_read_)(int file_number, int B, int F, int G, int P, char* part_name) = nullptr;
    int (*cg_part_write_)(int file_number, int B, int F, int G, const char* part_name, int* P) = nullptr;
    int (*cg_node_part_read_)(int G, int P, char* part_name) = nullptr;
    int (*cg_node_part_write_)(int G, const char* part_name, int* P) = nullptr;
    int (*cg_ngrids_)(int file_number, int B, int Z, int* ngrids) = nullptr;
    int (*cg_grid_read_)(int file_number, int B, int Z, int G, char* gridname) = nullptr;
    int (*cg_grid_write_)(int file_number, int B, int Z, const char* zcoorname, int* G) = nullptr;
    int (*cg_grid_bounding_box_read_)(int file_number, int B, int Z, int G, CGNS_ENUMT(DataType_t) type,
                                      void* boundingbox) = nullptr;
    int (*cg_grid_bounding_box_write_)(int file_number, int B, int Z, int G, CGNS_ENUMT(DataType_t) type,
                                       void* boundingbox) = nullptr;
    int (*cg_ncoords_)(int fn, int B, int Z, int* ncoords) = nullptr;
    int (*cg_coord_info_)(int fn, int B, int Z, int C, CGNS_ENUMT(DataType_t) * type, char* coordname) = nullptr;
    int (*cg_coord_read_)(int fn, int B, int Z, const char* coordname, CGNS_ENUMT(DataType_t) type, const cgsize_t* rmin,
                          const cgsize_t* rmax, void* coord) = nullptr;
    int (*cg_coord_general_read_)(int fn, int B, int Z, const char* coordname, const cgsize_t* s_rmin, const cgsize_t* s_rmax,
                                  CGNS_ENUMT(DataType_t) m_type, int m_numdim, const cgsize_t* m_dimvals, const cgsize_t* m_rmin,
                                  const cgsize_t* m_rmax, void* coord_ptr) = nullptr;
    int (*cg_coord_id_)(int fn, int B, int Z, int C, double* coord_id) = nullptr;
    int (*cg_coord_write_)(int fn, int B, int Z, CGNS_ENUMT(DataType_t) type, const char* coordname, const void* coord_ptr,
                           int* C) = nullptr;
    int (*cg_coord_partial_write_)(int fn, int B, int Z, CGNS_ENUMT(DataType_t) type, const char* coordname, const cgsize_t* rmin,
                                   const cgsize_t* rmax, const void* coord_ptr, int* C) = nullptr;
    int (*cg_coord_general_write_)(int fn, int B, int Z, const char* coordname, CGNS_ENUMT(DataType_t) s_type,
                                   const cgsize_t* rmin, const cgsize_t* rmax, CGNS_ENUMT(DataType_t) m_type, int m_numdim,
                                   const cgsize_t* m_dims, const cgsize_t* m_rmin, const cgsize_t* m_rmax, const void* coord_ptr,
                                   int* C) = nullptr;
    int (*cg_nsections_)(int file_number, int B, int Z, int* nsections) = nullptr;
    int (*cg_section_read_)(int file_number, int B, int Z, int S, char* SectionName, CGNS_ENUMT(ElementType_t) * type,
                            cgsize_t* start, cgsize_t* end, int* nbndry, int* parent_flag) = nullptr;
    int (*cg_elements_read_)(int file_number, int B, int Z, int S, cgsize_t* elements, cgsize_t* parent_data) = nullptr;
    int (*cg_poly_elements_read_)(int file_number, int B, int Z, int S, cgsize_t* elements, cgsize_t* connect_offset,
                                  cgsize_t* parent_data) = nullptr;
    int (*cg_section_write_)(int file_number, int B, int Z, const char* SectionName, CGNS_ENUMT(ElementType_t) type,
                             cgsize_t start, cgsize_t end, int nbndry, const cgsize_t* elements, int* S) = nullptr;
    int (*cg_poly_section_write_)(int file_number, int B, int Z, const char* SectionName, CGNS_ENUMT(ElementType_t) type,
                                  cgsize_t start, cgsize_t end, int nbndry, const cgsize_t* elements,
                                  const cgsize_t* connect_offset, int* S) = nullptr;
    int (*cg_section_general_write_)(int file_number, int B, int Z, const char* SectionName, const CGNS_ENUMT(ElementType_t) type,
                                     const CGNS_ENUMT(DataType_t) elementDataType, cgsize_t start, cgsize_t end,
                                     cgsize_t elementDataSize, int nbndry, int* S) = nullptr;
    int (*cg_section_initialize_)(int file_number, int B, int Z, int S) = nullptr;
    int (*cg_parent_data_write_)(int file_number, int B, int Z, int S, const cgsize_t* parent_data) = nullptr;
    int (*cg_npe_)(CGNS_ENUMT(ElementType_t) type, int* npe) = nullptr;
    int (*cg_ElementDataSize_)(int file_number, int B, int Z, int S, cgsize_t* ElementDataSize) = nullptr;
    int (*cg_section_partial_write_)(int file_number, int B, int Z, const char* SectionName, CGNS_ENUMT(ElementType_t) type,
                                     cgsize_t start, cgsize_t end, int nbndry, int* S) = nullptr;
    int (*cg_elements_partial_write_)(int fn, int B, int Z, int S, cgsize_t start, cgsize_t end,
                                      const cgsize_t* elements) = nullptr;
    int (*cg_elements_general_write_)(int fn, int B, int Z, int S, cgsize_t start, cgsize_t end, CGNS_ENUMT(DataType_t) m_type,
                                      const void* elements) = nullptr;
    int (*cg_poly_elements_partial_write_)(int fn, int B, int Z, int S, cgsize_t start, cgsize_t end, const cgsize_t* elements,
                                           const cgsize_t* connect_offset) = nullptr;
    int (*cg_poly_elements_general_write_)(int fn, int B, int Z, int S, cgsize_t start, cgsize_t end,
                                           CGNS_ENUMT(DataType_t) m_type, const void* elements,
                                           const void* connect_offset) = nullptr;
    int (*cg_parent_data_partial_write_)(int fn, int B, int Z, int S, cgsize_t start, cgsize_t end,
                                         const cgsize_t* ParentData) = nullptr;
    int (*cg_elements_partial_read_)(int file_number, int B, int Z, int S, cgsize_t start, cgsize_t end, cgsize_t* elements,
                                     cgsize_t* parent_data) = nullptr;
    int (*cg_poly_elements_partial_read_)(int file_number, int B, int Z, int S, cgsize_t start, cgsize_t end, cgsize_t* elements,
                                          cgsize_t* connect_offset, cgsize_t* parent_data) = nullptr;
    int (*cg_elements_general_read_)(int file_number, int B, int Z, int S, cgsize_t start, cgsize_t end,
                                     CGNS_ENUMT(DataType_t) m_type, void* elements) = nullptr;
    int (*cg_poly_elements_general_read_)(int file_number, int B, int Z, int S, cgsize_t start, cgsize_t end,
                                          CGNS_ENUMT(DataType_t) m_type, void* elements, void* connect_offset) = nullptr;
    int (*cg_parent_elements_general_read_)(int file_number, int B, int Z, int S, cgsize_t start, cgsize_t end,
                                            CGNS_ENUMT(DataType_t) m_type, void* parelem) = nullptr;
    int (*cg_parent_elements_position_general_read_)(int file_number, int B, int Z, int S, cgsize_t start, cgsize_t end,
                                                     CGNS_ENUMT(DataType_t) m_type, void* parface) = nullptr;
    int (*cg_ElementPartialSize_)(int file_number, int B, int Z, int S, cgsize_t start, cgsize_t end,
                                  cgsize_t* ElementDataSize) = nullptr;
    int (*cg_nsols_)(int fn, int B, int Z, int* nsols) = nullptr;
    int (*cg_sol_info_)(int fn, int B, int Z, int S, char* solname, CGNS_ENUMT(GridLocation_t) * location) = nullptr;
    int (*cg_sol_id_)(int fn, int B, int Z, int S, double* sol_id) = nullptr;
    int (*cg_sol_write_)(int fn, int B, int Z, const char* solname, CGNS_ENUMT(GridLocation_t) location, int* S) = nullptr;
    int (*cg_sol_size_)(int fn, int B, int Z, int S, int* data_dim, cgsize_t* dim_vals) = nullptr;
    int (*cg_sol_ptset_info_)(int fn, int B, int Z, int S, CGNS_ENUMT(PointSetType_t) * ptset_type, cgsize_t* npnts) = nullptr;
    int (*cg_sol_ptset_read_)(int fn, int B, int Z, int S, cgsize_t* pnts) = nullptr;
    int (*cg_sol_ptset_write_)(int fn, int B, int Z, const char* solname, CGNS_ENUMT(GridLocation_t) location,
                               CGNS_ENUMT(PointSetType_t) ptset_type, cgsize_t npnts, const cgsize_t* pnts, int* S) = nullptr;
    int (*cg_nfields_)(int fn, int B, int Z, int S, int* nfields) = nullptr;
    int (*cg_field_info_)(int fn, int B, int Z, int S, int F, CGNS_ENUMT(DataType_t) * type, char* fieldname) = nullptr;
    int (*cg_field_read_)(int fn, int B, int Z, int S, const char* fieldname, CGNS_ENUMT(DataType_t) type, const cgsize_t* rmin,
                          const cgsize_t* rmax, void* field_ptr) = nullptr;
    int (*cg_field_general_read_)(int fn, int B, int Z, int S, const char* fieldname, const cgsize_t* s_rmin,
                                  const cgsize_t* s_rmax, CGNS_ENUMT(DataType_t) m_type, int m_numdim, const cgsize_t* m_dimvals,
                                  const cgsize_t* m_rmin, const cgsize_t* m_rmax, void* field_ptr) = nullptr;
    int (*cg_field_id_)(int fn, int B, int Z, int S, int F, double* field_id) = nullptr;
    int (*cg_field_write_)(int fn, int B, int Z, int S, CGNS_ENUMT(DataType_t) type, const char* fieldname, const void* field_ptr,
                           int* F) = nullptr;
    int (*cg_field_partial_write_)(int fn, int B, int Z, int S, CGNS_ENUMT(DataType_t) type, const char* fieldname,
                                   const cgsize_t* rmin, const cgsize_t* rmax, const void* field_ptr, int* F) = nullptr;
    int (*cg_field_general_write_)(int fn, int B, int Z, int S, const char* fieldname, CGNS_ENUMT(DataType_t) s_type,
                                   const cgsize_t* rmin, const cgsize_t* rmax, CGNS_ENUMT(DataType_t) m_type, int m_numdim,
                                   const cgsize_t* m_dims, const cgsize_t* m_rmin, const cgsize_t* m_rmax, const void* field_ptr,
                                   int* F) = nullptr;
    int (*cg_nsubregs_)(int fn, int B, int Z, int* nsubreg) = nullptr;
    int (*cg_subreg_info_)(int fn, int B, int Z, int S, char* regname, int* dimension, CGNS_ENUMT(GridLocation_t) * location,
                           CGNS_ENUMT(PointSetType_t) * ptset_type, cgsize_t* npnts, int* bcname_len, int* gcname_len) = nullptr;
    int (*cg_subreg_ptset_read_)(int fn, int B, int Z, int S, cgsize_t* pnts) = nullptr;
    int (*cg_subreg_bcname_read_)(int fn, int B, int Z, int S, char* bcname) = nullptr;
    int (*cg_subreg_gcname_read_)(int fn, int B, int Z, int S, char* gcname) = nullptr;
    int (*cg_subreg_ptset_write_)(int fn, int B, int Z, const char* regname, int dimension, CGNS_ENUMT(GridLocation_t) location,
                                  CGNS_ENUMT(PointSetType_t) ptset_type, cgsize_t npnts, const cgsize_t* pnts, int* S) = nullptr;
    int (*cg_subreg_bcname_write_)(int fn, int B, int Z, const char* regname, int dimension, const char* bcname,
                                   int* S) = nullptr;
    int (*cg_subreg_gcname_write_)(int fn, int B, int Z, const char* regname, int dimension, const char* gcname,
                                   int* S) = nullptr;
    int (*cg_nzconns_)(int fn, int B, int Z, int* nzconns) = nullptr;
    int (*cg_zconn_read_)(int fn, int B, int Z, int C, char* name) = nullptr;
    int (*cg_zconn_write_)(int fn, int B, int Z, const char* name, int* C) = nullptr;
    int (*cg_zconn_get_)(int fn, int B, int Z, int* C) = nullptr;
    int (*cg_zconn_set_)(int fn, int B, int Z, int C) = nullptr;
    int (*cg_nholes_)(int fn, int B, int Z, int* nholes) = nullptr;
    int (*cg_hole_info_)(int fn, int B, int Z, int Ii, char* holename, CGNS_ENUMT(GridLocation_t) * location,
                         CGNS_ENUMT(PointSetType_t) * ptset_type, int* nptsets, cgsize_t* npnts) = nullptr;
    int (*cg_hole_read_)(int fn, int B, int Z, int Ii, cgsize_t* pnts) = nullptr;
    int (*cg_hole_id_)(int fn, int B, int Z, int Ii, double* hole_id) = nullptr;
    int (*cg_hole_write_)(int fn, int B, int Z, const char* holename, CGNS_ENUMT(GridLocation_t) location,
                          CGNS_ENUMT(PointSetType_t) ptset_type, int nptsets, cgsize_t npnts, const cgsize_t* pnts,
                          int* Ii) = nullptr;
    int (*cg_nconns_)(int fn, int B, int Z, int* nconns) = nullptr;
    int (*cg_conn_info_)(int file_number, int B, int Z, int Ii, char* connectname, CGNS_ENUMT(GridLocation_t) * location,
                         CGNS_ENUMT(GridConnectivityType_t) * type, CGNS_ENUMT(PointSetType_t) * ptset_type, cgsize_t* npnts,
                         char* donorname, CGNS_ENUMT(ZoneType_t) * donor_zonetype, CGNS_ENUMT(PointSetType_t) * donor_ptset_type,
                         CGNS_ENUMT(DataType_t) * donor_datatype, cgsize_t* ndata_donor) = nullptr;
    int (*cg_conn_read_)(int file_number, int B, int Z, int Ii, cgsize_t* pnts, CGNS_ENUMT(DataType_t) donor_datatype,
                         cgsize_t* donor_data) = nullptr;
    int (*cg_conn_id_)(int fn, int B, int Z, int Ii, double* conn_id) = nullptr;
    int (*cg_conn_write_)(int file_number, int B, int Z, const char* connectname, CGNS_ENUMT(GridLocation_t) location,
                          CGNS_ENUMT(GridConnectivityType_t) type, CGNS_ENUMT(PointSetType_t) ptset_type, cgsize_t npnts,
                          const cgsize_t* pnts, const char* donorname, CGNS_ENUMT(ZoneType_t) donor_zonetype,
                          CGNS_ENUMT(PointSetType_t) donor_ptset_type, CGNS_ENUMT(DataType_t) donor_datatype,
                          cgsize_t ndata_donor, const cgsize_t* donor_data, int* Ii) = nullptr;
    int (*cg_conn_write_short_)(int file_number, int B, int Z, const char* connectname, CGNS_ENUMT(GridLocation_t) location,
                                CGNS_ENUMT(GridConnectivityType_t) type, CGNS_ENUMT(PointSetType_t) ptset_type, cgsize_t npnts,
                                const cgsize_t* pnts, const char* donorname, int* Ii) = nullptr;
    int (*cg_conn_read_short_)(int file_number, int B, int Z, int Ii, cgsize_t* pnts) = nullptr;
    int (*cg_n1to1_)(int fn, int B, int Z, int* n1to1) = nullptr;
    int (*cg_1to1_read_)(int fn, int B, int Z, int Ii, char* connectname, char* donorname, cgsize_t* range, cgsize_t* donor_range,
                         int* transform) = nullptr;
    int (*cg_1to1_id_)(int fn, int B, int Z, int Ii, double* one21_id) = nullptr;
    int (*cg_1to1_write_)(int fn, int B, int Z, const char* connectname, const char* donorname, const cgsize_t* range,
                          const cgsize_t* donor_range, const int* transform, int* Ii) = nullptr;
    int (*cg_n1to1_global_)(int fn, int B, int* n1to1_global) = nullptr;
    int (*cg_1to1_read_global_)(int fn, int B, char** connectname, char** zonename, char** donorname, cgsize_t** range,
                                cgsize_t** donor_range, int** transform) = nullptr;
    int (*cg_nbocos_)(int fn, int B, int Z, int* nbocos) = nullptr;
    int (*cg_boco_info_)(int fn, int B, int Z, int BC, char* boconame, CGNS_ENUMT(BCType_t) * bocotype,
                         CGNS_ENUMT(PointSetType_t) * ptset_type, cgsize_t* npnts, int* NormalIndex, cgsize_t* NormalListSize,
                         CGNS_ENUMT(DataType_t) * NormalDataType, int* ndataset) = nullptr;
    int (*cg_boco_read_)(int fn, int B, int Z, int BC, cgsize_t* pnts, void* NormalList) = nullptr;
    int (*cg_boco_id_)(int fn, int B, int Z, int BC, double* boco_id) = nullptr;
    int (*cg_boco_write_)(int file_number, int B, int Z, const char* boconame, CGNS_ENUMT(BCType_t) bocotype,
                          CGNS_ENUMT(PointSetType_t) ptset_type, cgsize_t npnts, const cgsize_t* pnts, int* BC) = nullptr;
    int (*cg_boco_normal_write_)(int file_number, int B, int Z, int BC, const int* NormalIndex, int NormalListFlag,
                                 CGNS_ENUMT(DataType_t) NormalDataType, const void* NormalList) = nullptr;
    int (*cg_boco_gridlocation_read_)(int file_number, int B, int Z, int BC, CGNS_ENUMT(GridLocation_t) * location) = nullptr;
    int (*cg_boco_gridlocation_write_)(int file_number, int B, int Z, int BC, CGNS_ENUMT(GridLocation_t) location) = nullptr;
    int (*cg_dataset_read_)(int fn, int B, int Z, int BC, int DS, char* name, CGNS_ENUMT(BCType_t) * BCType, int* DirichletFlag,
                            int* NeumannFlag) = nullptr;
    int (*cg_dataset_write_)(int file_number, int B, int Z, int BC, const char* name, CGNS_ENUMT(BCType_t) BCType,
                             int* Dset) = nullptr;
    int (*cg_bcdataset_write_)(const char* name, CGNS_ENUMT(BCType_t) BCType, CGNS_ENUMT(BCDataType_t) BCDataType) = nullptr;
    int (*cg_bcdataset_info_)(int* n_dataset) = nullptr;
    int (*cg_bcdataset_read_)(int index, char* name, CGNS_ENUMT(BCType_t) * BCType, int* DirichletFlag,
                              int* NeumannFlag) = nullptr;
    int (*cg_bcdata_write_)(int file_number, int B, int Z, int BC, int Dset, CGNS_ENUMT(BCDataType_t) BCDataType) = nullptr;
    int (*cg_ndiscrete_)(int file_number, int B, int Z, int* ndiscrete) = nullptr;
    int (*cg_discrete_read_)(int file_number, int B, int Z, int D, char* discrete_name) = nullptr;
    int (*cg_discrete_write_)(int file_number, int B, int Z, const char* discrete_name, int* D) = nullptr;
    int (*cg_discrete_size_)(int fn, int B, int Z, int D, int* data_dim, cgsize_t* dim_vals) = nullptr;
    int (*cg_discrete_ptset_info_)(int fn, int B, int Z, int D, CGNS_ENUMT(PointSetType_t) * ptset_type,
                                   cgsize_t* npnts) = nullptr;
    int (*cg_discrete_ptset_read_)(int fn, int B, int Z, int D, cgsize_t* pnts) = nullptr;
    int (*cg_discrete_ptset_write_)(int fn, int B, int Z, const char* discrete_name, CGNS_ENUMT(GridLocation_t) location,
                                    CGNS_ENUMT(PointSetType_t) ptset_type, cgsize_t npnts, const cgsize_t* pnts,
                                    int* D) = nullptr;
    int (*cg_n_rigid_motions_)(int file_number, int B, int Z, int* n_rigid_motions) = nullptr;
    int (*cg_rigid_motion_read_)(int file_number, int B, int Z, int R, char* name,
                                 CGNS_ENUMT(RigidGridMotionType_t) * type) = nullptr;
    int (*cg_rigid_motion_write_)(int file_number, int B, int Z, const char* name, CGNS_ENUMT(RigidGridMotionType_t) type,
                                  int* R) = nullptr;
    int (*cg_n_arbitrary_motions_)(int file_number, int B, int Z, int* n_arbitrary_motions) = nullptr;
    int (*cg_arbitrary_motion_read_)(int file_number, int B, int Z, int A, char* name,
                                     CGNS_ENUMT(ArbitraryGridMotionType_t) * type) = nullptr;
    int (*cg_arbitrary_motion_write_)(int file_number, int B, int Z, const char* amotionname,
                                      CGNS_ENUMT(ArbitraryGridMotionType_t) type, int* A) = nullptr;
    int (*cg_simulation_type_read_)(int file_number, int B, CGNS_ENUMT(SimulationType_t) * type) = nullptr;
    int (*cg_simulation_type_write_)(int file_number, int B, CGNS_ENUMT(SimulationType_t) type) = nullptr;
    int (*cg_biter_read_)(int file_number, int B, char* bitername, int* nsteps) = nullptr;
    int (*cg_biter_write_)(int file_number, int B, const char* bitername, int nsteps) = nullptr;
    int (*cg_ziter_read_)(int file_number, int B, int Z, char* zitername) = nullptr;
    int (*cg_ziter_write_)(int file_number, int B, int Z, const char* zitername) = nullptr;
    int (*cg_gravity_read_)(int file_number, int B, float* gravity_vector) = nullptr;
    int (*cg_gravity_write_)(int file_number, int B, float const* gravity_vector) = nullptr;
    int (*cg_axisym_read_)(int file_number, int B, float* ref_point, float* axis) = nullptr;
    int (*cg_axisym_write_)(int file_number, int B, float const* ref_point, float const* axis) = nullptr;
    int (*cg_rotating_read_)(float* rot_rate, float* rot_center) = nullptr;
    int (*cg_rotating_write_)(float const* rot_rate, float const* rot_center) = nullptr;
    int (*cg_bc_wallfunction_read_)(int file_number, int B, int Z, int BC,
                                    CGNS_ENUMT(WallFunctionType_t) * WallFunctionType) = nullptr;
    int (*cg_bc_wallfunction_write_)(int file_number, int B, int Z, int BC,
                                     CGNS_ENUMT(WallFunctionType_t) WallFunctionType) = nullptr;
    int (*cg_bc_area_read_)(int file_number, int B, int Z, int BC, CGNS_ENUMT(AreaType_t) * AreaType, float* SurfaceArea,
                            char* RegionName) = nullptr;
    int (*cg_bc_area_write_)(int file_number, int B, int Z, int BC, CGNS_ENUMT(AreaType_t) AreaType, float SurfaceArea,
                             const char* RegionName) = nullptr;
    int (*cg_conn_periodic_read_)(int file_number, int B, int Z, int Ii, float* RotationCenter, float* RotationAngle,
                                  float* Translation) = nullptr;
    int (*cg_conn_periodic_write_)(int file_number, int B, int Z, int Ii, float const* RotationCenter, float const* RotationAngle,
                                   float const* Translation) = nullptr;
    int (*cg_1to1_periodic_write_)(int file_number, int B, int Z, int Ii, float const* RotationCenter, float const* RotationAngle,
                                   float const* Translation) = nullptr;
    int (*cg_1to1_periodic_read_)(int file_number, int B, int Z, int Ii, float* RotationCenter, float* RotationAngle,
                                  float* Translation) = nullptr;
    int (*cg_conn_average_read_)(int file_number, int B, int Z, int Ii,
                                 CGNS_ENUMT(AverageInterfaceType_t) * AverageInterfaceType) = nullptr;
    int (*cg_conn_average_write_)(int file_number, int B, int Z, int Ii,
                                  CGNS_ENUMT(AverageInterfaceType_t) AverageInterfaceType) = nullptr;
    int (*cg_1to1_average_write_)(int file_number, int B, int Z, int Ii,
                                  CGNS_ENUMT(AverageInterfaceType_t) AverageInterfaceType) = nullptr;
    int (*cg_1to1_average_read_)(int file_number, int B, int Z, int Ii,
                                 CGNS_ENUMT(AverageInterfaceType_t) * AverageInterfaceType) = nullptr;
    int (*cg_goto_)(int file_number, int B, ...) = nullptr;
    int (*cg_goto_f08_)(int file_number, int B, ...) = nullptr;
    int (*cg_gorel_)(int file_number, ...) = nullptr;
    int (*cg_gorel_f08_)(int file_number, ...) = nullptr;
    int (*cg_gopath_)(int file_number, const char* path) = nullptr;
    int (*cg_golist_)(int file_number, int B, int depth, char** label, int* num) = nullptr;
    int (*cg_where_)(int* file_number, int* B, int* depth, char** label, int* num) = nullptr;
    int (*cg_convergence_read_)(int* iterations, char** NormDefinitions) = nullptr;
    int (*cg_convergence_write_)(int iterations, const char* NormDefinitions) = nullptr;
    int (*cg_state_read_)(char** StateDescription) = nullptr;
    int (*cg_state_write_)(const char* StateDescription) = nullptr;
    int (*cg_equationset_read_)(int* EquationDimension, int* GoverningEquationsFlag, int* GasModelFlag, int* ViscosityModelFlag,
                                int* ThermalConductivityModelFlag, int* TurbulenceClosureFlag,
                                int* TurbulenceModelFlag) = nullptr;
    int (*cg_equationset_chemistry_read_)(int* ThermalRelaxationFlag, int* ChemicalKineticsFlag) = nullptr;
    int (*cg_equationset_elecmagn_read_)(int* ElecFldModelFlag, int* MagnFldModelFlag, int* ConductivityModelFlag) = nullptr;
    int (*cg_equationset_write_)(int EquationDimension) = nullptr;
    int (*cg_governing_read_)(CGNS_ENUMT(GoverningEquationsType_t) * EquationsType) = nullptr;
    int (*cg_governing_write_)(CGNS_ENUMT(GoverningEquationsType_t) Equationstype) = nullptr;
    int (*cg_diffusion_read_)(int* diffusion_model) = nullptr;
    int (*cg_diffusion_write_)(const int* diffusion_model) = nullptr;
    int (*cg_model_read_)(const char* ModelLabel, CGNS_ENUMT(ModelType_t) * ModelType) = nullptr;
    int (*cg_model_write_)(const char* ModelLabel, CGNS_ENUMT(ModelType_t) ModelType) = nullptr;
    int (*cg_narrays_)(int* narrays) = nullptr;
    int (*cg_array_info_)(int A, char* ArrayName, CGNS_ENUMT(DataType_t) * DataType, int* DataDimension,
                          cgsize_t* DimensionVector) = nullptr;
    int (*cg_array_read_)(int A, void* Data) = nullptr;
    int (*cg_array_read_as_)(int A, CGNS_ENUMT(DataType_t) type, void* Data) = nullptr;
    int (*cg_array_general_read_)(int A, const cgsize_t* s_rmin, const cgsize_t* s_rmax, CGNS_ENUMT(DataType_t) m_type,
                                  int m_numdim, const cgsize_t* m_dimvals, const cgsize_t* m_rmin, const cgsize_t* m_rmax,
                                  void* data) = nullptr;
    int (*cg_array_write_)(const char* ArrayName, CGNS_ENUMT(DataType_t) DataType, int DataDimension,
                           const cgsize_t* DimensionVector, const void* Data) = nullptr;
    int (*cg_array_general_write_)(const char* arrayname, CGNS_ENUMT(DataType_t) s_type, int s_numdim, const cgsize_t* s_dimvals,
                                   const cgsize_t* s_rmin, const cgsize_t* s_rmax, CGNS_ENUMT(DataType_t) m_type, int m_numdim,
                                   const cgsize_t* m_dimvals, const cgsize_t* m_rmin, const cgsize_t* m_rmax,
                                   const void* data) = nullptr;
    int (*cg_nuser_data_)(int* nuser_data) = nullptr;
    int (*cg_user_data_read_)(int Index, char* user_data_name) = nullptr;
    int (*cg_user_data_write_)(const char* user_data_name) = nullptr;
    int (*cg_nintegrals_)(int* nintegrals) = nullptr;
    int (*cg_integral_read_)(int IntegralDataIndex, char* IntegralDataName) = nullptr;
    int (*cg_integral_write_)(const char* IntegralDataName) = nullptr;
    int (*cg_rind_read_)(int* RindData) = nullptr;
    int (*cg_rind_write_)(const int* RindData) = nullptr;
    int (*cg_ndescriptors_)(int* ndescriptors) = nullptr;
    int (*cg_descriptor_read_)(int descr_no, char* descr_name, char** descr_text) = nullptr;
    int (*cg_descriptor_write_)(const char* descr_name, const char* descr_text) = nullptr;
    int (*cg_nunits_)(int* nunits) = nullptr;
    int (*cg_units_read_)(CGNS_ENUMT(MassUnits_t) * mass, CGNS_ENUMT(LengthUnits_t) * length, CGNS_ENUMT(TimeUnits_t) * time,
                          CGNS_ENUMT(TemperatureUnits_t) * temperature, CGNS_ENUMT(AngleUnits_t) * angle) = nullptr;
    int (*cg_units_write_)(CGNS_ENUMT(MassUnits_t) mass, CGNS_ENUMT(LengthUnits_t) length, CGNS_ENUMT(TimeUnits_t) time,
                           CGNS_ENUMT(TemperatureUnits_t) temperature, CGNS_ENUMT(AngleUnits_t) angle) = nullptr;
    int (*cg_unitsfull_read_)(CGNS_ENUMT(MassUnits_t) * mass, CGNS_ENUMT(LengthUnits_t) * length, CGNS_ENUMT(TimeUnits_t) * time,
                              CGNS_ENUMT(TemperatureUnits_t) * temperature, CGNS_ENUMT(AngleUnits_t) * angle,
                              CGNS_ENUMT(ElectricCurrentUnits_t) * current, CGNS_ENUMT(SubstanceAmountUnits_t) * amount,
                              CGNS_ENUMT(LuminousIntensityUnits_t) * intensity) = nullptr;
    int (*cg_unitsfull_write_)(CGNS_ENUMT(MassUnits_t) mass, CGNS_ENUMT(LengthUnits_t) length, CGNS_ENUMT(TimeUnits_t) time,
                               CGNS_ENUMT(TemperatureUnits_t) temperature, CGNS_ENUMT(AngleUnits_t) angle,
                               CGNS_ENUMT(ElectricCurrentUnits_t) current, CGNS_ENUMT(SubstanceAmountUnits_t) amount,
                               CGNS_ENUMT(LuminousIntensityUnits_t) intensity) = nullptr;
    int (*cg_exponents_info_)(CGNS_ENUMT(DataType_t) * DataType) = nullptr;
    int (*cg_nexponents_)(int* numexp) = nullptr;
    int (*cg_exponents_read_)(void* exponents) = nullptr;
    int (*cg_exponents_write_)(CGNS_ENUMT(DataType_t) DataType, const void* exponents) = nullptr;
    int (*cg_expfull_read_)(void* exponents) = nullptr;
    int (*cg_expfull_write_)(CGNS_ENUMT(DataType_t) DataType, const void* exponents) = nullptr;
    int (*cg_conversion_info_)(CGNS_ENUMT(DataType_t) * DataType) = nullptr;
    int (*cg_conversion_read_)(void* ConversionFactors) = nullptr;
    int (*cg_conversion_write_)(CGNS_ENUMT(DataType_t) DataType, const void* ConversionFactors) = nullptr;
    int (*cg_dataclass_read_)(CGNS_ENUMT(DataClass_t) * dataclass) = nullptr;
    int (*cg_dataclass_write_)(CGNS_ENUMT(DataClass_t) dataclass) = nullptr;
    int (*cg_gridlocation_read_)(CGNS_ENUMT(GridLocation_t) * GridLocation) = nullptr;
    int (*cg_gridlocation_write_)(CGNS_ENUMT(GridLocation_t) GridLocation) = nullptr;
    int (*cg_ordinal_read_)(int* Ordinal) = nullptr;
    int (*cg_ordinal_write_)(int Ordinal) = nullptr;
    int (*cg_ptset_info_)(CGNS_ENUMT(PointSetType_t) * ptset_type, cgsize_t* npnts) = nullptr;
    int (*cg_ptset_write_)(CGNS_ENUMT(PointSetType_t) ptset_type, cgsize_t npnts, const cgsize_t* pnts) = nullptr;
    int (*cg_ptset_read_)(cgsize_t* pnts) = nullptr;
    int (*cg_is_link_)(int* path_length) = nullptr;
    int (*cg_link_read_)(char** filename, char** link_path) = nullptr;
    int (*cg_link_write_)(const char* nodename, const char* filename, const char* name_in_file) = nullptr;
    int (*cg_delete_node_)(const char* node_name) = nullptr;
    int (*cg_free_)(void* data) = nullptr;
    const char* (*cg_get_error_)(void) = nullptr;
    void (*cg_error_exit_)(void) = nullptr;
    void (*cg_error_print_)(void) = nullptr;
};

#endif // CGNSLOADER_H