#pragma once

/**
 * @brief CGNS Dynamic Loading Wrapper
 *
 * This file provides inline wrapper functions that forward CGNS API calls to the dynamically
 * loaded CGNS library. It creates a drop-in replacement for the standard cgnslib.h header
 * but uses dynamic loading under the hood.
 *
 * The wrapper automatically handles:
 * - Dynamic loading of cgnsdll.dll from CEE_SAM_READER_CGNS_LIBRARY_DIR if set or the system PATH at runtime
 * - Singleton pattern for library instance management
 * - Thread-safe initialization on first CGNS function call
 * - Error handling for library loading failures using SAM's error system
 * - Full API compatibility with CGNS library
 *
 * Usage:
 * - This header is automatically included when CEE_SAM_CGNS_DYNAMIC_LOADING is defined
 * - Call CGNS functions normally (e.g., cg_open(), cg_close(), cg_goto(), etc.)
 * - Functions automatically forward to the dynamically loaded CGNS library instance
 * - Library loading happens lazily on first function call, not at include time
 * - No CGNS library needs to be linked at compile time
 *
 * @note Maintains 100% API compatibility with the standard CGNS interface.
 * @note Requires cgnsdll.dll to be available preferably in the directory specified by
 * CEE_SAM_READER_CGNS_LIBRARY_DIR, or alternatively in the system PATH at runtime.
 */

#include <cstdarg>
#include <cstddef>
#include <cstring>
#include <filesystem>
#include <memory>
#include <mutex>
#include "cgnsLoader.h"
#include "sam/base/system.h"

inline cgnsLoader&
Lib()
{
    static std::once_flag initialized;
    static std::unique_ptr<cgnsLoader> instance;
    static int init_error = 0;

    std::call_once(initialized, []() {
        try {
            instance = std::make_unique<cgnsLoader>();
        }
        catch (...) {
            init_error = 1;
        }
    });

    if (init_error || !instance) {
        static Vchar func[] = "cgnsLoader::Lib";
        HANDLEERR0(func, SYS_ERROR_LOAD, "CGNS library failed to initialize");
        static cgnsLoader dummy_instance;
        return dummy_instance;
    }

    return *instance;
}

extern "C" {
inline int
cg_is_cgns(const char* filename, int* file_type)
{
    return Lib().cg_is_cgns_(filename, file_type);
}

inline int
cg_open(const char* filename, int mode, int* fn)
{
    return Lib().cg_open_(filename, mode, fn);
}

inline int
cg_version(int fn, float* FileVersion)
{
    return Lib().cg_version_(fn, FileVersion);
}

inline int
cg_precision(int fn, int* precision)
{
    return Lib().cg_precision_(fn, precision);
}

inline int
cg_close(int fn)
{
    return Lib().cg_close_(fn);
}

inline int
cg_save_as(int fn, const char* filename, int file_type, int follow_links)
{
    return Lib().cg_save_as_(fn, filename, file_type, follow_links);
}

inline int
cg_set_file_type(int file_type)
{
    return Lib().cg_set_file_type_(file_type);
}

inline int
cg_get_file_type(int fn, int* file_type)
{
    return Lib().cg_get_file_type_(fn, file_type);
}

inline int
cg_root_id(int fn, double* rootid)
{
    return Lib().cg_root_id_(fn, rootid);
}

inline int
cg_get_cgio(int fn, int* cgio_num)
{
    return Lib().cg_get_cgio_(fn, cgio_num);
}

inline int
cg_configure(int what, void* value)
{
    return Lib().cg_configure_(what, value);
}

inline int
cg_error_handler(void (*handler)(int, char*))
{
    return Lib().cg_error_handler_(handler);
}

inline int
cg_set_compress(int compress)
{
    return Lib().cg_set_compress_(compress);
}

inline int
cg_get_compress(int* compress)
{
    return Lib().cg_get_compress_(compress);
}

inline int
cg_set_path(const char* path)
{
    return Lib().cg_set_path_(path);
}

inline int
cg_add_path(const char* path)
{
    return Lib().cg_add_path_(path);
}

inline const char*
cg_get_name(int nnames, const char** names, int type)
{
    return Lib().cg_get_name_(nnames, names, type);
}

inline const char*
cg_MassUnitsName(CGNS_ENUMT(MassUnits_t) type)
{
    return Lib().cg_MassUnitsName_(type);
}

inline const char*
cg_LengthUnitsName(CGNS_ENUMT(LengthUnits_t) type)
{
    return Lib().cg_LengthUnitsName_(type);
}

inline const char*
cg_TimeUnitsName(CGNS_ENUMT(TimeUnits_t) type)
{
    return Lib().cg_TimeUnitsName_(type);
}

inline const char*
cg_TemperatureUnitsName(CGNS_ENUMT(TemperatureUnits_t) type)
{
    return Lib().cg_TemperatureUnitsName_(type);
}

inline const char*
cg_AngleUnitsName(CGNS_ENUMT(AngleUnits_t) type)
{
    return Lib().cg_AngleUnitsName_(type);
}

inline const char*
cg_ElectricCurrentUnitsName(CGNS_ENUMT(ElectricCurrentUnits_t) type)
{
    return Lib().cg_ElectricCurrentUnitsName_(type);
}

inline const char*
cg_SubstanceAmountUnitsName(CGNS_ENUMT(SubstanceAmountUnits_t) type)
{
    return Lib().cg_SubstanceAmountUnitsName_(type);
}

inline const char*
cg_LuminousIntensityUnitsName(CGNS_ENUMT(LuminousIntensityUnits_t) type)
{
    return Lib().cg_LuminousIntensityUnitsName_(type);
}

inline const char*
cg_DataClassName(CGNS_ENUMT(DataClass_t) type)
{
    return Lib().cg_DataClassName_(type);
}

inline const char*
cg_GridLocationName(CGNS_ENUMT(GridLocation_t) type)
{
    return Lib().cg_GridLocationName_(type);
}

inline const char*
cg_BCDataTypeName(CGNS_ENUMT(BCDataType_t) type)
{
    return Lib().cg_BCDataTypeName_(type);
}

inline const char*
cg_GridConnectivityTypeName(CGNS_ENUMT(GridConnectivityType_t) type)
{
    return Lib().cg_GridConnectivityTypeName_(type);
}

inline const char*
cg_PointSetTypeName(CGNS_ENUMT(PointSetType_t) type)
{
    return Lib().cg_PointSetTypeName_(type);
}

inline const char*
cg_GoverningEquationsTypeName(CGNS_ENUMT(GoverningEquationsType_t) type)
{
    return Lib().cg_GoverningEquationsTypeName_(type);
}

inline const char*
cg_ModelTypeName(CGNS_ENUMT(ModelType_t) type)
{
    return Lib().cg_ModelTypeName_(type);
}

inline const char*
cg_BCTypeName(CGNS_ENUMT(BCType_t) type)
{
    return Lib().cg_BCTypeName_(type);
}

inline const char*
cg_DataTypeName(CGNS_ENUMT(DataType_t) type)
{
    return Lib().cg_DataTypeName_(type);
}

inline const char*
cg_ElementTypeName(CGNS_ENUMT(ElementType_t) type)
{
    return Lib().cg_ElementTypeName_(type);
}

inline const char*
cg_ZoneTypeName(CGNS_ENUMT(ZoneType_t) type)
{
    return Lib().cg_ZoneTypeName_(type);
}

inline const char*
cg_RigidGridMotionTypeName(CGNS_ENUMT(RigidGridMotionType_t) type)
{
    return Lib().cg_RigidGridMotionTypeName_(type);
}

inline const char*
cg_ArbitraryGridMotionTypeName(CGNS_ENUMT(ArbitraryGridMotionType_t) type)
{
    return Lib().cg_ArbitraryGridMotionTypeName_(type);
}

inline const char*
cg_SimulationTypeName(CGNS_ENUMT(SimulationType_t) type)
{
    return Lib().cg_SimulationTypeName_(type);
}

inline const char*
cg_WallFunctionTypeName(CGNS_ENUMT(WallFunctionType_t) type)
{
    return Lib().cg_WallFunctionTypeName_(type);
}

inline const char*
cg_AreaTypeName(CGNS_ENUMT(AreaType_t) type)
{
    return Lib().cg_AreaTypeName_(type);
}

inline const char*
cg_AverageInterfaceTypeName(CGNS_ENUMT(AverageInterfaceType_t) type)
{
    return Lib().cg_AverageInterfaceTypeName_(type);
}

inline int
cg_nbases(int fn, int* nbases)
{
    return Lib().cg_nbases_(fn, nbases);
}

inline int
cg_base_read(int file_number, int B, char* basename, int* cell_dim, int* phys_dim)
{
    return Lib().cg_base_read_(file_number, B, basename, cell_dim, phys_dim);
}

inline int
cg_base_id(int fn, int B, double* base_id)
{
    return Lib().cg_base_id_(fn, B, base_id);
}

inline int
cg_base_write(int file_number, const char* basename, int cell_dim, int phys_dim, int* B)
{
    return Lib().cg_base_write_(file_number, basename, cell_dim, phys_dim, B);
}

inline int
cg_cell_dim(int fn, int B, int* cell_dim)
{
    return Lib().cg_cell_dim_(fn, B, cell_dim);
}

inline int
cg_nzones(int fn, int B, int* nzones)
{
    return Lib().cg_nzones_(fn, B, nzones);
}

inline int
cg_zone_read(int fn, int B, int Z, char* zonename, cgsize_t* size)
{
    return Lib().cg_zone_read_(fn, B, Z, zonename, size);
}

inline int
cg_zone_type(int file_number, int B, int Z, CGNS_ENUMT(ZoneType_t) * type)
{
    return Lib().cg_zone_type_(file_number, B, Z, type);
}

inline int
cg_zone_id(int fn, int B, int Z, double* zone_id)
{
    return Lib().cg_zone_id_(fn, B, Z, zone_id);
}

inline int
cg_zone_write(int fn, int B, const char* zonename, const cgsize_t* size, CGNS_ENUMT(ZoneType_t) type, int* Z)
{
    return Lib().cg_zone_write_(fn, B, zonename, size, type, Z);
}

inline int
cg_index_dim(int fn, int B, int Z, int* index_dim)
{
    return Lib().cg_index_dim_(fn, B, Z, index_dim);
}

inline int
cg_nfamilies(int file_number, int B, int* nfamilies)
{
    return Lib().cg_nfamilies_(file_number, B, nfamilies);
}

inline int
cg_family_read(int file_number, int B, int F, char* family_name, int* nboco, int* ngeos)
{
    return Lib().cg_family_read_(file_number, B, F, family_name, nboco, ngeos);
}

inline int
cg_family_write(int file_number, int B, const char* family_name, int* F)
{
    return Lib().cg_family_write_(file_number, B, family_name, F);
}

inline int
cg_nfamily_names(int file_number, int B, int F, int* nnames)
{
    return Lib().cg_nfamily_names_(file_number, B, F, nnames);
}

inline int
cg_family_name_read(int file_number, int B, int F, int N, char* name, char* family)
{
    return Lib().cg_family_name_read_(file_number, B, F, N, name, family);
}

inline int
cg_family_name_write(int file_number, int B, int F, const char* name, const char* family)
{
    return Lib().cg_family_name_write_(file_number, B, F, name, family);
}

inline int
cg_node_family_write(const char* family_name, int* F)
{
    return Lib().cg_node_family_write_(family_name, F);
}

inline int
cg_node_nfamilies(int* nfamilies)
{
    return Lib().cg_node_nfamilies_(nfamilies);
}

inline int
cg_node_family_read(int F, char* family_name, int* nFamBC, int* nGeo)
{
    return Lib().cg_node_family_read_(F, family_name, nFamBC, nGeo);
}

inline int
cg_node_family_name_write(const char* node_name, const char* family_name)
{
    return Lib().cg_node_family_name_write_(node_name, family_name);
}

inline int
cg_node_nfamily_names(int* nnames)
{
    return Lib().cg_node_nfamily_names_(nnames);
}

inline int
cg_node_family_name_read(int N, char* node_name, char* family_name)
{
    return Lib().cg_node_family_name_read_(N, node_name, family_name);
}

inline int
cg_famname_read(char* family_name)
{
    return Lib().cg_famname_read_(family_name);
}

inline int
cg_famname_write(const char* family_name)
{
    return Lib().cg_famname_write_(family_name);
}

inline int
cg_nmultifam(int* nfams)
{
    return Lib().cg_nmultifam_(nfams);
}

inline int
cg_multifam_read(int N, char* name, char* family)
{
    return Lib().cg_multifam_read_(N, name, family);
}

inline int
cg_multifam_write(const char* name, const char* family)
{
    return Lib().cg_multifam_write_(name, family);
}

inline int
cg_fambc_read(int file_number, int B, int F, int BC, char* fambc_name, CGNS_ENUMT(BCType_t) * bocotype)
{
    return Lib().cg_fambc_read_(file_number, B, F, BC, fambc_name, bocotype);
}

inline int
cg_fambc_write(int file_number, int B, int F, const char* fambc_name, CGNS_ENUMT(BCType_t) bocotype, int* BC)
{
    return Lib().cg_fambc_write_(file_number, B, F, fambc_name, bocotype, BC);
}

inline int
cg_node_fambc_read(int BC, char* fambc_name, CGNS_ENUMT(BCType_t) * bocotype)
{
    return Lib().cg_node_fambc_read_(BC, fambc_name, bocotype);
}

inline int
cg_node_fambc_write(const char* fambc_name, CGNS_ENUMT(BCType_t) bocotype, int* BC)
{
    return Lib().cg_node_fambc_write_(fambc_name, bocotype, BC);
}

inline int
cg_geo_read(int file_number, int B, int F, int G, char* geo_name, char** geo_file, char* CAD_name, int* npart)
{
    return Lib().cg_geo_read_(file_number, B, F, G, geo_name, geo_file, CAD_name, npart);
}

inline int
cg_geo_write(int file_number, int B, int F, const char* geo_name, const char* filename, const char* CADname, int* G)
{
    return Lib().cg_geo_write_(file_number, B, F, geo_name, filename, CADname, G);
}

inline int
cg_node_geo_read(int G, char* geo_name, char** geo_file, char* CAD_name, int* npart)
{
    return Lib().cg_node_geo_read_(G, geo_name, geo_file, CAD_name, npart);
}

inline int
cg_node_geo_write(const char* geo_name, const char* filename, const char* CADname, int* G)
{
    return Lib().cg_node_geo_write_(geo_name, filename, CADname, G);
}

inline int
cg_part_read(int file_number, int B, int F, int G, int P, char* part_name)
{
    return Lib().cg_part_read_(file_number, B, F, G, P, part_name);
}

inline int
cg_part_write(int file_number, int B, int F, int G, const char* part_name, int* P)
{
    return Lib().cg_part_write_(file_number, B, F, G, part_name, P);
}

inline int
cg_node_part_read(int G, int P, char* part_name)
{
    return Lib().cg_node_part_read_(G, P, part_name);
}

inline int
cg_node_part_write(int G, const char* part_name, int* P)
{
    return Lib().cg_node_part_write_(G, part_name, P);
}

inline int
cg_ngrids(int file_number, int B, int Z, int* ngrids)
{
    return Lib().cg_ngrids_(file_number, B, Z, ngrids);
}

inline int
cg_grid_read(int file_number, int B, int Z, int G, char* gridname)
{
    return Lib().cg_grid_read_(file_number, B, Z, G, gridname);
}

inline int
cg_grid_write(int file_number, int B, int Z, const char* zcoorname, int* G)
{
    return Lib().cg_grid_write_(file_number, B, Z, zcoorname, G);
}

inline int
cg_grid_bounding_box_read(int file_number, int B, int Z, int G, CGNS_ENUMT(DataType_t) type, void* boundingbox)
{
    return Lib().cg_grid_bounding_box_read_(file_number, B, Z, G, type, boundingbox);
}

inline int
cg_grid_bounding_box_write(int file_number, int B, int Z, int G, CGNS_ENUMT(DataType_t) type, void* boundingbox)
{
    return Lib().cg_grid_bounding_box_write_(file_number, B, Z, G, type, boundingbox);
}

inline int
cg_ncoords(int fn, int B, int Z, int* ncoords)
{
    return Lib().cg_ncoords_(fn, B, Z, ncoords);
}

inline int
cg_coord_info(int fn, int B, int Z, int C, CGNS_ENUMT(DataType_t) * type, char* coordname)
{
    return Lib().cg_coord_info_(fn, B, Z, C, type, coordname);
}

inline int
cg_coord_read(int fn, int B, int Z, const char* coordname, CGNS_ENUMT(DataType_t) type, const cgsize_t* rmin,
              const cgsize_t* rmax, void* coord)
{
    return Lib().cg_coord_read_(fn, B, Z, coordname, type, rmin, rmax, coord);
}

inline int
cg_coord_general_read(int fn, int B, int Z, const char* coordname, const cgsize_t* s_rmin, const cgsize_t* s_rmax,
                      CGNS_ENUMT(DataType_t) m_type, int m_numdim, const cgsize_t* m_dimvals, const cgsize_t* m_rmin,
                      const cgsize_t* m_rmax, void* coord_ptr)
{
    return Lib().cg_coord_general_read_(fn, B, Z, coordname, s_rmin, s_rmax, m_type, m_numdim, m_dimvals, m_rmin, m_rmax,
                                        coord_ptr);
}

inline int
cg_coord_id(int fn, int B, int Z, int C, double* coord_id)
{
    return Lib().cg_coord_id_(fn, B, Z, C, coord_id);
}

inline int
cg_coord_write(int fn, int B, int Z, CGNS_ENUMT(DataType_t) type, const char* coordname, const void* coord_ptr, int* C)
{
    return Lib().cg_coord_write_(fn, B, Z, type, coordname, coord_ptr, C);
}

inline int
cg_coord_partial_write(int fn, int B, int Z, CGNS_ENUMT(DataType_t) type, const char* coordname, const cgsize_t* rmin,
                       const cgsize_t* rmax, const void* coord_ptr, int* C)
{
    return Lib().cg_coord_partial_write_(fn, B, Z, type, coordname, rmin, rmax, coord_ptr, C);
}

inline int
cg_coord_general_write(int fn, int B, int Z, const char* coordname, CGNS_ENUMT(DataType_t) s_type, const cgsize_t* rmin,
                       const cgsize_t* rmax, CGNS_ENUMT(DataType_t) m_type, int m_numdim, const cgsize_t* m_dims,
                       const cgsize_t* m_rmin, const cgsize_t* m_rmax, const void* coord_ptr, int* C)
{
    return Lib().cg_coord_general_write_(fn, B, Z, coordname, s_type, rmin, rmax, m_type, m_numdim, m_dims, m_rmin, m_rmax,
                                         coord_ptr, C);
}

inline int
cg_nsections(int file_number, int B, int Z, int* nsections)
{
    return Lib().cg_nsections_(file_number, B, Z, nsections);
}

inline int
cg_section_read(int file_number, int B, int Z, int S, char* SectionName, CGNS_ENUMT(ElementType_t) * type, cgsize_t* start,
                cgsize_t* end, int* nbndry, int* parent_flag)
{
    return Lib().cg_section_read_(file_number, B, Z, S, SectionName, type, start, end, nbndry, parent_flag);
}

inline int
cg_elements_read(int file_number, int B, int Z, int S, cgsize_t* elements, cgsize_t* parent_data)
{
    return Lib().cg_elements_read_(file_number, B, Z, S, elements, parent_data);
}

inline int
cg_poly_elements_read(int file_number, int B, int Z, int S, cgsize_t* elements, cgsize_t* connect_offset, cgsize_t* parent_data)
{
    return Lib().cg_poly_elements_read_(file_number, B, Z, S, elements, connect_offset, parent_data);
}

inline int
cg_section_write(int file_number, int B, int Z, const char* SectionName, CGNS_ENUMT(ElementType_t) type, cgsize_t start,
                 cgsize_t end, int nbndry, const cgsize_t* elements, int* S)
{
    return Lib().cg_section_write_(file_number, B, Z, SectionName, type, start, end, nbndry, elements, S);
}

inline int
cg_poly_section_write(int file_number, int B, int Z, const char* SectionName, CGNS_ENUMT(ElementType_t) type, cgsize_t start,
                      cgsize_t end, int nbndry, const cgsize_t* elements, const cgsize_t* connect_offset, int* S)
{
    return Lib().cg_poly_section_write_(file_number, B, Z, SectionName, type, start, end, nbndry, elements, connect_offset, S);
}

inline int
cg_section_general_write(int file_number, int B, int Z, const char* SectionName, const CGNS_ENUMT(ElementType_t) type,
                         const CGNS_ENUMT(DataType_t) elementDataType, cgsize_t start, cgsize_t end, cgsize_t elementDataSize,
                         int nbndry, int* S)
{
    return Lib().cg_section_general_write_(file_number, B, Z, SectionName, type, elementDataType, start, end, elementDataSize,
                                           nbndry, S);
}

inline int
cg_section_initialize(int file_number, int B, int Z, int S)
{
    return Lib().cg_section_initialize_(file_number, B, Z, S);
}

inline int
cg_parent_data_write(int file_number, int B, int Z, int S, const cgsize_t* parent_data)
{
    return Lib().cg_parent_data_write_(file_number, B, Z, S, parent_data);
}

inline int
cg_npe(CGNS_ENUMT(ElementType_t) type, int* npe)
{
    return Lib().cg_npe_(type, npe);
}

inline int
cg_ElementDataSize(int file_number, int B, int Z, int S, cgsize_t* ElementDataSize)
{
    return Lib().cg_ElementDataSize_(file_number, B, Z, S, ElementDataSize);
}

inline int
cg_section_partial_write(int file_number, int B, int Z, const char* SectionName, CGNS_ENUMT(ElementType_t) type, cgsize_t start,
                         cgsize_t end, int nbndry, int* S)
{
    return Lib().cg_section_partial_write_(file_number, B, Z, SectionName, type, start, end, nbndry, S);
}

inline int
cg_elements_partial_write(int fn, int B, int Z, int S, cgsize_t start, cgsize_t end, const cgsize_t* elements)
{
    return Lib().cg_elements_partial_write_(fn, B, Z, S, start, end, elements);
}

inline int
cg_elements_general_write(int fn, int B, int Z, int S, cgsize_t start, cgsize_t end, CGNS_ENUMT(DataType_t) m_type,
                          const void* elements)
{
    return Lib().cg_elements_general_write_(fn, B, Z, S, start, end, m_type, elements);
}

inline int
cg_poly_elements_partial_write(int fn, int B, int Z, int S, cgsize_t start, cgsize_t end, const cgsize_t* elements,
                               const cgsize_t* connect_offset)
{
    return Lib().cg_poly_elements_partial_write_(fn, B, Z, S, start, end, elements, connect_offset);
}

inline int
cg_poly_elements_general_write(int fn, int B, int Z, int S, cgsize_t start, cgsize_t end, CGNS_ENUMT(DataType_t) m_type,
                               const void* elements, const void* connect_offset)
{
    return Lib().cg_poly_elements_general_write_(fn, B, Z, S, start, end, m_type, elements, connect_offset);
}

inline int
cg_parent_data_partial_write(int fn, int B, int Z, int S, cgsize_t start, cgsize_t end, const cgsize_t* ParentData)
{
    return Lib().cg_parent_data_partial_write_(fn, B, Z, S, start, end, ParentData);
}

inline int
cg_elements_partial_read(int file_number, int B, int Z, int S, cgsize_t start, cgsize_t end, cgsize_t* elements,
                         cgsize_t* parent_data)
{
    return Lib().cg_elements_partial_read_(file_number, B, Z, S, start, end, elements, parent_data);
}

inline int
cg_poly_elements_partial_read(int file_number, int B, int Z, int S, cgsize_t start, cgsize_t end, cgsize_t* elements,
                              cgsize_t* connect_offset, cgsize_t* parent_data)
{
    return Lib().cg_poly_elements_partial_read_(file_number, B, Z, S, start, end, elements, connect_offset, parent_data);
}

inline int
cg_elements_general_read(int file_number, int B, int Z, int S, cgsize_t start, cgsize_t end, CGNS_ENUMT(DataType_t) m_type,
                         void* elements)
{
    return Lib().cg_elements_general_read_(file_number, B, Z, S, start, end, m_type, elements);
}

inline int
cg_poly_elements_general_read(int file_number, int B, int Z, int S, cgsize_t start, cgsize_t end, CGNS_ENUMT(DataType_t) m_type,
                              void* elements, void* connect_offset)
{
    return Lib().cg_poly_elements_general_read_(file_number, B, Z, S, start, end, m_type, elements, connect_offset);
}

inline int
cg_parent_elements_general_read(int file_number, int B, int Z, int S, cgsize_t start, cgsize_t end, CGNS_ENUMT(DataType_t) m_type,
                                void* parelem)
{
    return Lib().cg_parent_elements_general_read_(file_number, B, Z, S, start, end, m_type, parelem);
}

inline int
cg_parent_elements_position_general_read(int file_number, int B, int Z, int S, cgsize_t start, cgsize_t end,
                                         CGNS_ENUMT(DataType_t) m_type, void* parface)
{
    return Lib().cg_parent_elements_position_general_read_(file_number, B, Z, S, start, end, m_type, parface);
}

inline int
cg_ElementPartialSize(int file_number, int B, int Z, int S, cgsize_t start, cgsize_t end, cgsize_t* ElementDataSize)
{
    return Lib().cg_ElementPartialSize_(file_number, B, Z, S, start, end, ElementDataSize);
}

inline int
cg_nsols(int fn, int B, int Z, int* nsols)
{
    return Lib().cg_nsols_(fn, B, Z, nsols);
}

inline int
cg_sol_info(int fn, int B, int Z, int S, char* solname, CGNS_ENUMT(GridLocation_t) * location)
{
    return Lib().cg_sol_info_(fn, B, Z, S, solname, location);
}

inline int
cg_sol_id(int fn, int B, int Z, int S, double* sol_id)
{
    return Lib().cg_sol_id_(fn, B, Z, S, sol_id);
}

inline int
cg_sol_write(int fn, int B, int Z, const char* solname, CGNS_ENUMT(GridLocation_t) location, int* S)
{
    return Lib().cg_sol_write_(fn, B, Z, solname, location, S);
}

inline int
cg_sol_size(int fn, int B, int Z, int S, int* data_dim, cgsize_t* dim_vals)
{
    return Lib().cg_sol_size_(fn, B, Z, S, data_dim, dim_vals);
}

inline int
cg_sol_ptset_info(int fn, int B, int Z, int S, CGNS_ENUMT(PointSetType_t) * ptset_type, cgsize_t* npnts)
{
    return Lib().cg_sol_ptset_info_(fn, B, Z, S, ptset_type, npnts);
}

inline int
cg_sol_ptset_read(int fn, int B, int Z, int S, cgsize_t* pnts)
{
    return Lib().cg_sol_ptset_read_(fn, B, Z, S, pnts);
}

inline int
cg_sol_ptset_write(int fn, int B, int Z, const char* solname, CGNS_ENUMT(GridLocation_t) location,
                   CGNS_ENUMT(PointSetType_t) ptset_type, cgsize_t npnts, const cgsize_t* pnts, int* S)
{
    return Lib().cg_sol_ptset_write_(fn, B, Z, solname, location, ptset_type, npnts, pnts, S);
}

inline int
cg_nfields(int fn, int B, int Z, int S, int* nfields)
{
    return Lib().cg_nfields_(fn, B, Z, S, nfields);
}

inline int
cg_field_info(int fn, int B, int Z, int S, int F, CGNS_ENUMT(DataType_t) * type, char* fieldname)
{
    return Lib().cg_field_info_(fn, B, Z, S, F, type, fieldname);
}

inline int
cg_field_read(int fn, int B, int Z, int S, const char* fieldname, CGNS_ENUMT(DataType_t) type, const cgsize_t* rmin,
              const cgsize_t* rmax, void* field_ptr)
{
    return Lib().cg_field_read_(fn, B, Z, S, fieldname, type, rmin, rmax, field_ptr);
}

inline int
cg_field_general_read(int fn, int B, int Z, int S, const char* fieldname, const cgsize_t* s_rmin, const cgsize_t* s_rmax,
                      CGNS_ENUMT(DataType_t) m_type, int m_numdim, const cgsize_t* m_dimvals, const cgsize_t* m_rmin,
                      const cgsize_t* m_rmax, void* field_ptr)
{
    return Lib().cg_field_general_read_(fn, B, Z, S, fieldname, s_rmin, s_rmax, m_type, m_numdim, m_dimvals, m_rmin, m_rmax,
                                        field_ptr);
}

inline int
cg_field_id(int fn, int B, int Z, int S, int F, double* field_id)
{
    return Lib().cg_field_id_(fn, B, Z, S, F, field_id);
}

inline int
cg_field_write(int fn, int B, int Z, int S, CGNS_ENUMT(DataType_t) type, const char* fieldname, const void* field_ptr, int* F)
{
    return Lib().cg_field_write_(fn, B, Z, S, type, fieldname, field_ptr, F);
}

inline int
cg_field_partial_write(int fn, int B, int Z, int S, CGNS_ENUMT(DataType_t) type, const char* fieldname, const cgsize_t* rmin,
                       const cgsize_t* rmax, const void* field_ptr, int* F)
{
    return Lib().cg_field_partial_write_(fn, B, Z, S, type, fieldname, rmin, rmax, field_ptr, F);
}

inline int
cg_field_general_write(int fn, int B, int Z, int S, const char* fieldname, CGNS_ENUMT(DataType_t) s_type, const cgsize_t* rmin,
                       const cgsize_t* rmax, CGNS_ENUMT(DataType_t) m_type, int m_numdim, const cgsize_t* m_dims,
                       const cgsize_t* m_rmin, const cgsize_t* m_rmax, const void* field_ptr, int* F)
{
    return Lib().cg_field_general_write_(fn, B, Z, S, fieldname, s_type, rmin, rmax, m_type, m_numdim, m_dims, m_rmin, m_rmax,
                                         field_ptr, F);
}

inline int
cg_nsubregs(int fn, int B, int Z, int* nsubreg)
{
    return Lib().cg_nsubregs_(fn, B, Z, nsubreg);
}

inline int
cg_subreg_info(int fn, int B, int Z, int S, char* regname, int* dimension, CGNS_ENUMT(GridLocation_t) * location,
               CGNS_ENUMT(PointSetType_t) * ptset_type, cgsize_t* npnts, int* bcname_len, int* gcname_len)
{
    return Lib().cg_subreg_info_(fn, B, Z, S, regname, dimension, location, ptset_type, npnts, bcname_len, gcname_len);
}

inline int
cg_subreg_ptset_read(int fn, int B, int Z, int S, cgsize_t* pnts)
{
    return Lib().cg_subreg_ptset_read_(fn, B, Z, S, pnts);
}

inline int
cg_subreg_bcname_read(int fn, int B, int Z, int S, char* bcname)
{
    return Lib().cg_subreg_bcname_read_(fn, B, Z, S, bcname);
}

inline int
cg_subreg_gcname_read(int fn, int B, int Z, int S, char* gcname)
{
    return Lib().cg_subreg_gcname_read_(fn, B, Z, S, gcname);
}

inline int
cg_subreg_ptset_write(int fn, int B, int Z, const char* regname, int dimension, CGNS_ENUMT(GridLocation_t) location,
                      CGNS_ENUMT(PointSetType_t) ptset_type, cgsize_t npnts, const cgsize_t* pnts, int* S)
{
    return Lib().cg_subreg_ptset_write_(fn, B, Z, regname, dimension, location, ptset_type, npnts, pnts, S);
}

inline int
cg_subreg_bcname_write(int fn, int B, int Z, const char* regname, int dimension, const char* bcname, int* S)
{
    return Lib().cg_subreg_bcname_write_(fn, B, Z, regname, dimension, bcname, S);
}

inline int
cg_subreg_gcname_write(int fn, int B, int Z, const char* regname, int dimension, const char* gcname, int* S)
{
    return Lib().cg_subreg_gcname_write_(fn, B, Z, regname, dimension, gcname, S);
}

inline int
cg_nzconns(int fn, int B, int Z, int* nzconns)
{
    return Lib().cg_nzconns_(fn, B, Z, nzconns);
}

inline int
cg_zconn_read(int fn, int B, int Z, int C, char* name)
{
    return Lib().cg_zconn_read_(fn, B, Z, C, name);
}

inline int
cg_zconn_write(int fn, int B, int Z, const char* name, int* C)
{
    return Lib().cg_zconn_write_(fn, B, Z, name, C);
}

inline int
cg_zconn_get(int fn, int B, int Z, int* C)
{
    return Lib().cg_zconn_get_(fn, B, Z, C);
}

inline int
cg_zconn_set(int fn, int B, int Z, int C)
{
    return Lib().cg_zconn_set_(fn, B, Z, C);
}

inline int
cg_nholes(int fn, int B, int Z, int* nholes)
{
    return Lib().cg_nholes_(fn, B, Z, nholes);
}

inline int
cg_hole_info(int fn, int B, int Z, int Ii, char* holename, CGNS_ENUMT(GridLocation_t) * location,
             CGNS_ENUMT(PointSetType_t) * ptset_type, int* nptsets, cgsize_t* npnts)
{
    return Lib().cg_hole_info_(fn, B, Z, Ii, holename, location, ptset_type, nptsets, npnts);
}

inline int
cg_hole_read(int fn, int B, int Z, int Ii, cgsize_t* pnts)
{
    return Lib().cg_hole_read_(fn, B, Z, Ii, pnts);
}

inline int
cg_hole_id(int fn, int B, int Z, int Ii, double* hole_id)
{
    return Lib().cg_hole_id_(fn, B, Z, Ii, hole_id);
}

inline int
cg_hole_write(int fn, int B, int Z, const char* holename, CGNS_ENUMT(GridLocation_t) location,
              CGNS_ENUMT(PointSetType_t) ptset_type, int nptsets, cgsize_t npnts, const cgsize_t* pnts, int* Ii)
{
    return Lib().cg_hole_write_(fn, B, Z, holename, location, ptset_type, nptsets, npnts, pnts, Ii);
}

inline int
cg_nconns(int fn, int B, int Z, int* nconns)
{
    return Lib().cg_nconns_(fn, B, Z, nconns);
}

inline int
cg_conn_info(int file_number, int B, int Z, int Ii, char* connectname, CGNS_ENUMT(GridLocation_t) * location,
             CGNS_ENUMT(GridConnectivityType_t) * type, CGNS_ENUMT(PointSetType_t) * ptset_type, cgsize_t* npnts, char* donorname,
             CGNS_ENUMT(ZoneType_t) * donor_zonetype, CGNS_ENUMT(PointSetType_t) * donor_ptset_type,
             CGNS_ENUMT(DataType_t) * donor_datatype, cgsize_t* ndata_donor)
{
    return Lib().cg_conn_info_(file_number, B, Z, Ii, connectname, location, type, ptset_type, npnts, donorname, donor_zonetype,
                               donor_ptset_type, donor_datatype, ndata_donor);
}

inline int
cg_conn_read(int file_number, int B, int Z, int Ii, cgsize_t* pnts, CGNS_ENUMT(DataType_t) donor_datatype, cgsize_t* donor_data)
{
    return Lib().cg_conn_read_(file_number, B, Z, Ii, pnts, donor_datatype, donor_data);
}

inline int
cg_conn_id(int fn, int B, int Z, int Ii, double* conn_id)
{
    return Lib().cg_conn_id_(fn, B, Z, Ii, conn_id);
}

inline int
cg_conn_write(int file_number, int B, int Z, const char* connectname, CGNS_ENUMT(GridLocation_t) location,
              CGNS_ENUMT(GridConnectivityType_t) type, CGNS_ENUMT(PointSetType_t) ptset_type, cgsize_t npnts,
              const cgsize_t* pnts, const char* donorname, CGNS_ENUMT(ZoneType_t) donor_zonetype,
              CGNS_ENUMT(PointSetType_t) donor_ptset_type, CGNS_ENUMT(DataType_t) donor_datatype, cgsize_t ndata_donor,
              const cgsize_t* donor_data, int* Ii)
{
    return Lib().cg_conn_write_(file_number, B, Z, connectname, location, type, ptset_type, npnts, pnts, donorname,
                                donor_zonetype, donor_ptset_type, donor_datatype, ndata_donor, donor_data, Ii);
}

inline int
cg_conn_write_short(int file_number, int B, int Z, const char* connectname, CGNS_ENUMT(GridLocation_t) location,
                    CGNS_ENUMT(GridConnectivityType_t) type, CGNS_ENUMT(PointSetType_t) ptset_type, cgsize_t npnts,
                    const cgsize_t* pnts, const char* donorname, int* Ii)
{
    return Lib().cg_conn_write_short_(file_number, B, Z, connectname, location, type, ptset_type, npnts, pnts, donorname, Ii);
}

inline int
cg_conn_read_short(int file_number, int B, int Z, int Ii, cgsize_t* pnts)
{
    return Lib().cg_conn_read_short_(file_number, B, Z, Ii, pnts);
}

inline int
cg_n1to1(int fn, int B, int Z, int* n1to1)
{
    return Lib().cg_n1to1_(fn, B, Z, n1to1);
}

inline int
cg_1to1_read(int fn, int B, int Z, int Ii, char* connectname, char* donorname, cgsize_t* range, cgsize_t* donor_range,
             int* transform)
{
    return Lib().cg_1to1_read_(fn, B, Z, Ii, connectname, donorname, range, donor_range, transform);
}

inline int
cg_1to1_id(int fn, int B, int Z, int Ii, double* one21_id)
{
    return Lib().cg_1to1_id_(fn, B, Z, Ii, one21_id);
}

inline int
cg_1to1_write(int fn, int B, int Z, const char* connectname, const char* donorname, const cgsize_t* range,
              const cgsize_t* donor_range, const int* transform, int* Ii)
{
    return Lib().cg_1to1_write_(fn, B, Z, connectname, donorname, range, donor_range, transform, Ii);
}

inline int
cg_n1to1_global(int fn, int B, int* n1to1_global)
{
    return Lib().cg_n1to1_global_(fn, B, n1to1_global);
}

inline int
cg_1to1_read_global(int fn, int B, char** connectname, char** zonename, char** donorname, cgsize_t** range,
                    cgsize_t** donor_range, int** transform)
{
    return Lib().cg_1to1_read_global_(fn, B, connectname, zonename, donorname, range, donor_range, transform);
}

inline int
cg_nbocos(int fn, int B, int Z, int* nbocos)
{
    return Lib().cg_nbocos_(fn, B, Z, nbocos);
}

inline int
cg_boco_info(int fn, int B, int Z, int BC, char* boconame, CGNS_ENUMT(BCType_t) * bocotype,
             CGNS_ENUMT(PointSetType_t) * ptset_type, cgsize_t* npnts, int* NormalIndex, cgsize_t* NormalListSize,
             CGNS_ENUMT(DataType_t) * NormalDataType, int* ndataset)
{
    return Lib().cg_boco_info_(fn, B, Z, BC, boconame, bocotype, ptset_type, npnts, NormalIndex, NormalListSize, NormalDataType,
                               ndataset);
}

inline int
cg_boco_read(int fn, int B, int Z, int BC, cgsize_t* pnts, void* NormalList)
{
    return Lib().cg_boco_read_(fn, B, Z, BC, pnts, NormalList);
}

inline int
cg_boco_id(int fn, int B, int Z, int BC, double* boco_id)
{
    return Lib().cg_boco_id_(fn, B, Z, BC, boco_id);
}

inline int
cg_boco_write(int file_number, int B, int Z, const char* boconame, CGNS_ENUMT(BCType_t) bocotype,
              CGNS_ENUMT(PointSetType_t) ptset_type, cgsize_t npnts, const cgsize_t* pnts, int* BC)
{
    return Lib().cg_boco_write_(file_number, B, Z, boconame, bocotype, ptset_type, npnts, pnts, BC);
}

inline int
cg_boco_normal_write(int file_number, int B, int Z, int BC, const int* NormalIndex, int NormalListFlag,
                     CGNS_ENUMT(DataType_t) NormalDataType, const void* NormalList)
{
    return Lib().cg_boco_normal_write_(file_number, B, Z, BC, NormalIndex, NormalListFlag, NormalDataType, NormalList);
}

inline int
cg_boco_gridlocation_read(int file_number, int B, int Z, int BC, CGNS_ENUMT(GridLocation_t) * location)
{
    return Lib().cg_boco_gridlocation_read_(file_number, B, Z, BC, location);
}

inline int
cg_boco_gridlocation_write(int file_number, int B, int Z, int BC, CGNS_ENUMT(GridLocation_t) location)
{
    return Lib().cg_boco_gridlocation_write_(file_number, B, Z, BC, location);
}

inline int
cg_dataset_read(int fn, int B, int Z, int BC, int DS, char* name, CGNS_ENUMT(BCType_t) * BCType, int* DirichletFlag,
                int* NeumannFlag)
{
    return Lib().cg_dataset_read_(fn, B, Z, BC, DS, name, BCType, DirichletFlag, NeumannFlag);
}

inline int
cg_dataset_write(int file_number, int B, int Z, int BC, const char* name, CGNS_ENUMT(BCType_t) BCType, int* Dset)
{
    return Lib().cg_dataset_write_(file_number, B, Z, BC, name, BCType, Dset);
}

inline int
cg_bcdataset_write(const char* name, CGNS_ENUMT(BCType_t) BCType, CGNS_ENUMT(BCDataType_t) BCDataType)
{
    return Lib().cg_bcdataset_write_(name, BCType, BCDataType);
}

inline int
cg_bcdataset_info(int* n_dataset)
{
    return Lib().cg_bcdataset_info_(n_dataset);
}

inline int
cg_bcdataset_read(int index, char* name, CGNS_ENUMT(BCType_t) * BCType, int* DirichletFlag, int* NeumannFlag)
{
    return Lib().cg_bcdataset_read_(index, name, BCType, DirichletFlag, NeumannFlag);
}

inline int
cg_bcdata_write(int file_number, int B, int Z, int BC, int Dset, CGNS_ENUMT(BCDataType_t) BCDataType)
{
    return Lib().cg_bcdata_write_(file_number, B, Z, BC, Dset, BCDataType);
}

inline int
cg_ndiscrete(int file_number, int B, int Z, int* ndiscrete)
{
    return Lib().cg_ndiscrete_(file_number, B, Z, ndiscrete);
}

inline int
cg_discrete_read(int file_number, int B, int Z, int D, char* discrete_name)
{
    return Lib().cg_discrete_read_(file_number, B, Z, D, discrete_name);
}

inline int
cg_discrete_write(int file_number, int B, int Z, const char* discrete_name, int* D)
{
    return Lib().cg_discrete_write_(file_number, B, Z, discrete_name, D);
}

inline int
cg_discrete_size(int fn, int B, int Z, int D, int* data_dim, cgsize_t* dim_vals)
{
    return Lib().cg_discrete_size_(fn, B, Z, D, data_dim, dim_vals);
}

inline int
cg_discrete_ptset_info(int fn, int B, int Z, int D, CGNS_ENUMT(PointSetType_t) * ptset_type, cgsize_t* npnts)
{
    return Lib().cg_discrete_ptset_info_(fn, B, Z, D, ptset_type, npnts);
}

inline int
cg_discrete_ptset_read(int fn, int B, int Z, int D, cgsize_t* pnts)
{
    return Lib().cg_discrete_ptset_read_(fn, B, Z, D, pnts);
}

inline int
cg_discrete_ptset_write(int fn, int B, int Z, const char* discrete_name, CGNS_ENUMT(GridLocation_t) location,
                        CGNS_ENUMT(PointSetType_t) ptset_type, cgsize_t npnts, const cgsize_t* pnts, int* D)
{
    return Lib().cg_discrete_ptset_write_(fn, B, Z, discrete_name, location, ptset_type, npnts, pnts, D);
}

inline int
cg_n_rigid_motions(int file_number, int B, int Z, int* n_rigid_motions)
{
    return Lib().cg_n_rigid_motions_(file_number, B, Z, n_rigid_motions);
}

inline int
cg_rigid_motion_read(int file_number, int B, int Z, int R, char* name, CGNS_ENUMT(RigidGridMotionType_t) * type)
{
    return Lib().cg_rigid_motion_read_(file_number, B, Z, R, name, type);
}

inline int
cg_rigid_motion_write(int file_number, int B, int Z, const char* name, CGNS_ENUMT(RigidGridMotionType_t) type, int* R)
{
    return Lib().cg_rigid_motion_write_(file_number, B, Z, name, type, R);
}

inline int
cg_n_arbitrary_motions(int file_number, int B, int Z, int* n_arbitrary_motions)
{
    return Lib().cg_n_arbitrary_motions_(file_number, B, Z, n_arbitrary_motions);
}

inline int
cg_arbitrary_motion_read(int file_number, int B, int Z, int A, char* name, CGNS_ENUMT(ArbitraryGridMotionType_t) * type)
{
    return Lib().cg_arbitrary_motion_read_(file_number, B, Z, A, name, type);
}

inline int
cg_arbitrary_motion_write(int file_number, int B, int Z, const char* amotionname, CGNS_ENUMT(ArbitraryGridMotionType_t) type,
                          int* A)
{
    return Lib().cg_arbitrary_motion_write_(file_number, B, Z, amotionname, type, A);
}

inline int
cg_simulation_type_read(int file_number, int B, CGNS_ENUMT(SimulationType_t) * type)
{
    return Lib().cg_simulation_type_read_(file_number, B, type);
}

inline int
cg_simulation_type_write(int file_number, int B, CGNS_ENUMT(SimulationType_t) type)
{
    return Lib().cg_simulation_type_write_(file_number, B, type);
}

inline int
cg_biter_read(int file_number, int B, char* bitername, int* nsteps)
{
    return Lib().cg_biter_read_(file_number, B, bitername, nsteps);
}

inline int
cg_biter_write(int file_number, int B, const char* bitername, int nsteps)
{
    return Lib().cg_biter_write_(file_number, B, bitername, nsteps);
}

inline int
cg_ziter_read(int file_number, int B, int Z, char* zitername)
{
    return Lib().cg_ziter_read_(file_number, B, Z, zitername);
}

inline int
cg_ziter_write(int file_number, int B, int Z, const char* zitername)
{
    return Lib().cg_ziter_write_(file_number, B, Z, zitername);
}

inline int
cg_gravity_read(int file_number, int B, float* gravity_vector)
{
    return Lib().cg_gravity_read_(file_number, B, gravity_vector);
}

inline int
cg_gravity_write(int file_number, int B, float const* gravity_vector)
{
    return Lib().cg_gravity_write_(file_number, B, gravity_vector);
}

inline int
cg_axisym_read(int file_number, int B, float* ref_point, float* axis)
{
    return Lib().cg_axisym_read_(file_number, B, ref_point, axis);
}

inline int
cg_axisym_write(int file_number, int B, float const* ref_point, float const* axis)
{
    return Lib().cg_axisym_write_(file_number, B, ref_point, axis);
}

inline int
cg_rotating_read(float* rot_rate, float* rot_center)
{
    return Lib().cg_rotating_read_(rot_rate, rot_center);
}

inline int
cg_rotating_write(float const* rot_rate, float const* rot_center)
{
    return Lib().cg_rotating_write_(rot_rate, rot_center);
}

inline int
cg_bc_wallfunction_read(int file_number, int B, int Z, int BC, CGNS_ENUMT(WallFunctionType_t) * WallFunctionType)
{
    return Lib().cg_bc_wallfunction_read_(file_number, B, Z, BC, WallFunctionType);
}

inline int
cg_bc_wallfunction_write(int file_number, int B, int Z, int BC, CGNS_ENUMT(WallFunctionType_t) WallFunctionType)
{
    return Lib().cg_bc_wallfunction_write_(file_number, B, Z, BC, WallFunctionType);
}

inline int
cg_bc_area_read(int file_number, int B, int Z, int BC, CGNS_ENUMT(AreaType_t) * AreaType, float* SurfaceArea, char* RegionName)
{
    return Lib().cg_bc_area_read_(file_number, B, Z, BC, AreaType, SurfaceArea, RegionName);
}

inline int
cg_bc_area_write(int file_number, int B, int Z, int BC, CGNS_ENUMT(AreaType_t) AreaType, float SurfaceArea,
                 const char* RegionName)
{
    return Lib().cg_bc_area_write_(file_number, B, Z, BC, AreaType, SurfaceArea, RegionName);
}

inline int
cg_conn_periodic_read(int file_number, int B, int Z, int Ii, float* RotationCenter, float* RotationAngle, float* Translation)
{
    return Lib().cg_conn_periodic_read_(file_number, B, Z, Ii, RotationCenter, RotationAngle, Translation);
}

inline int
cg_conn_periodic_write(int file_number, int B, int Z, int Ii, float const* RotationCenter, float const* RotationAngle,
                       float const* Translation)
{
    return Lib().cg_conn_periodic_write_(file_number, B, Z, Ii, RotationCenter, RotationAngle, Translation);
}

inline int
cg_1to1_periodic_write(int file_number, int B, int Z, int Ii, float const* RotationCenter, float const* RotationAngle,
                       float const* Translation)
{
    return Lib().cg_1to1_periodic_write_(file_number, B, Z, Ii, RotationCenter, RotationAngle, Translation);
}

inline int
cg_1to1_periodic_read(int file_number, int B, int Z, int Ii, float* RotationCenter, float* RotationAngle, float* Translation)
{
    return Lib().cg_1to1_periodic_read_(file_number, B, Z, Ii, RotationCenter, RotationAngle, Translation);
}

inline int
cg_conn_average_read(int file_number, int B, int Z, int Ii, CGNS_ENUMT(AverageInterfaceType_t) * AverageInterfaceType)
{
    return Lib().cg_conn_average_read_(file_number, B, Z, Ii, AverageInterfaceType);
}

inline int
cg_conn_average_write(int file_number, int B, int Z, int Ii, CGNS_ENUMT(AverageInterfaceType_t) AverageInterfaceType)
{
    return Lib().cg_conn_average_write_(file_number, B, Z, Ii, AverageInterfaceType);
}

inline int
cg_1to1_average_write(int file_number, int B, int Z, int Ii, CGNS_ENUMT(AverageInterfaceType_t) AverageInterfaceType)
{
    return Lib().cg_1to1_average_write_(file_number, B, Z, Ii, AverageInterfaceType);
}

inline int
cg_1to1_average_read(int file_number, int B, int Z, int Ii, CGNS_ENUMT(AverageInterfaceType_t) * AverageInterfaceType)
{
    return Lib().cg_1to1_average_read_(file_number, B, Z, Ii, AverageInterfaceType);
}

// Base level (pattern: file, B, "end")
inline int
cg_goto_base_end(int file_number, int B)
{
    return Lib().cg_goto_(file_number, B, "end", NULL);
}

// Single node (pattern: file, B, "NodeType_t", index, "end")
inline int
cg_goto_node_end(int file_number, int B, const char* node_type, int index)
{
    return Lib().cg_goto_(file_number, B, node_type, index, "end", NULL);
}

// Two nodes (pattern: file, B, "NodeType1_t", index1, "NodeType2_t", index2, "end")
inline int
cg_goto_two_nodes_end(int file_number, int B, const char* node1_type, int index1, const char* node2_type, int index2)
{
    return Lib().cg_goto_(file_number, B, node1_type, index1, node2_type, index2, "end", NULL);
}

// Three nodes (pattern: file, B, "NodeType1_t", index1, "NodeType2_t", index2, "NodeType3_t", index3, "end")
inline int
cg_goto_three_nodes_end(int file_number, int B, const char* node1_type, int index1, const char* node2_type, int index2,
                        const char* node3_type, int index3)
{
    return Lib().cg_goto_(file_number, B, node1_type, index1, node2_type, index2, node3_type, index3, "end", NULL);
}

// Four nodes (pattern: file, B, "NodeType1_t", index1, "NodeType2_t", index2, "NodeType3_t", index3, "NodeType4_t", index4,
// "end")
inline int
cg_goto_four_nodes_end(int file_number, int B, const char* node1_type, int index1, const char* node2_type, int index2,
                       const char* node3_type, int index3, const char* node4_type, int index4)
{
    return Lib().cg_goto_(file_number, B, node1_type, index1, node2_type, index2, node3_type, index3, node4_type, index4, "end",
                          NULL);
}

// Five nodes (pattern: file, B, "NodeType1_t", index1, ..., "NodeType5_t", index5, "end")
inline int
cg_goto_five_nodes_end(int file_number, int B, const char* node1_type, int index1, const char* node2_type, int index2,
                       const char* node3_type, int index3, const char* node4_type, int index4, const char* node5_type, int index5)
{
    return Lib().cg_goto_(file_number, B, node1_type, index1, node2_type, index2, node3_type, index3, node4_type, index4,
                          node5_type, index5, "end", NULL);
}

// Six nodes (pattern: file, B, "NodeType1_t", index1, ..., "NodeType6_t", index6, "end")
inline int
cg_goto_six_nodes_end(int file_number, int B, const char* node1_type, int index1, const char* node2_type, int index2,
                      const char* node3_type, int index3, const char* node4_type, int index4, const char* node5_type, int index5,
                      const char* node6_type, int index6)
{
    return Lib().cg_goto_(file_number, B, node1_type, index1, node2_type, index2, node3_type, index3, node4_type, index4,
                          node5_type, index5, node6_type, index6, "end", NULL);
}

// Seven nodes (pattern: file, B, "NodeType1_t", index1, ..., "NodeType7_t", index7, "end")
inline int
cg_goto_seven_nodes_end(int file_number, int B, const char* node1_type, int index1, const char* node2_type, int index2,
                        const char* node3_type, int index3, const char* node4_type, int index4, const char* node5_type,
                        int index5, const char* node6_type, int index6, const char* node7_type, int index7)
{
    return Lib().cg_goto_(file_number, B, node1_type, index1, node2_type, index2, node3_type, index3, node4_type, index4,
                          node5_type, index5, node6_type, index6, node7_type, index7, "end", NULL);
}

// Special case: Dynamic node name (pattern: file, B, "NodeType_t", index, nodename, 0, "end")
inline int
cg_goto_node_dynamic_end(int file_number, int B, const char* node_type, int index, const char* dynamic_name)
{
    return Lib().cg_goto_(file_number, B, node_type, index, dynamic_name, 0, "end", NULL);
}

// Smart variadic cg_goto that routes based on argument count
inline int
cg_goto(int file_number, int B, ...)
{
    va_list args, args_copy;
    va_start(args, B);
    // Simple approach: Count arguments first, then handle each pattern
    va_copy(args_copy, args);

    int arg_count = 0;
    const char* arg;
    do {
        arg = va_arg(args_copy, const char*);
        arg_count++;
        // If this looks like a NodeType_t, skip its int index, too
        if (arg && strlen(arg) > 2 && strcmp(arg + strlen(arg) - 2, "_t") == 0) {
            va_arg(args_copy, int);
            arg_count++;
        }
    } while (arg == NULL || strcmp(arg, "end") != 0);

    va_end(args_copy);

    int result = CG_ERROR;

    // Pattern matching and execution based on argument count
    if (arg_count == 1) {
        // Pattern: cg_goto(file, B, "end")
        const char* end_marker = va_arg(args, const char*);
        if (strcmp(end_marker, "end") == 0) {
            result = cg_goto_base_end(file_number, B);
        }
    }
    else if (arg_count == 3) {
        // Pattern: cg_goto(file, B, "NodeType_t", index, "end")
        const char* node_type = va_arg(args, const char*);
        int index = va_arg(args, int);
        const char* end_marker = va_arg(args, const char*);

        if (strcmp(end_marker, "end") == 0) {
            result = cg_goto_node_end(file_number, B, node_type, index);
        }
    }
    else if (arg_count == 5) {
        // Could be dynamic-node or two-node
        const char* first = va_arg(args, const char*);
        int first_index = va_arg(args, int);
        const char* third = va_arg(args, const char*);
        int fourth = va_arg(args, int);
        const char* fifth = va_arg(args, const char*);

        // 1) Dynamic: NodeType_t, idx, <name>, 0, "end"
        if (strlen(first) > 2 && strcmp(first + strlen(first) - 2, "_t") == 0 && fourth == 0 && strcmp(fifth, "end") == 0) {
            result = cg_goto_node_dynamic_end(file_number, B, first, first_index, third);
        }
        // 2) Two-node: NodeType1_t, idx1, NodeType2_t, idx2, "end"
        else if (strlen(third) > 2 && strcmp(third + strlen(third) - 2, "_t") == 0 && strcmp(fifth, "end") == 0) {
            result = cg_goto_two_nodes_end(file_number, B, first, first_index, third, fourth);
        }
        else {
            result = CG_ERROR;
        }
    }
    else if (arg_count == 7) {
        // Pattern: cg_goto(file, B, "NodeType1_t", index1, "NodeType2_t", index2, "NodeType3_t", index3, "end")
        const char* node1_type = va_arg(args, const char*);
        int index1 = va_arg(args, int);
        const char* node2_type = va_arg(args, const char*);
        int index2 = va_arg(args, int);
        const char* node3_type = va_arg(args, const char*);
        int index3 = va_arg(args, int);
        const char* end_marker = va_arg(args, const char*);

        if (strcmp(end_marker, "end") == 0) {
            result = cg_goto_three_nodes_end(file_number, B, node1_type, index1, node2_type, index2, node3_type, index3);
        }
    }
    else if (arg_count == 9) {
        // Pattern: cg_goto(file, B, "NodeType1_t", index1, "NodeType2_t", index2, "NodeType3_t", index3, "NodeType4_t", index4,
        // "end")
        const char* node1_type = va_arg(args, const char*);
        int index1 = va_arg(args, int);
        const char* node2_type = va_arg(args, const char*);
        int index2 = va_arg(args, int);
        const char* node3_type = va_arg(args, const char*);
        int index3 = va_arg(args, int);
        const char* node4_type = va_arg(args, const char*);
        int index4 = va_arg(args, int);
        const char* end_marker = va_arg(args, const char*);

        if (strcmp(end_marker, "end") == 0) {
            result = cg_goto_four_nodes_end(file_number, B, node1_type, index1, node2_type, index2, node3_type, index3,
                                            node4_type, index4);
        }
    }
    else if (arg_count == 11) {
        // Pattern: cg_goto(file, B, "NodeType1_t", index1, "NodeType2_t", index2, "NodeType3_t", index3, "NodeType4_t", index4,
        // "NodeType5_t", index5, "end")
        const char* node1_type = va_arg(args, const char*);
        int index1 = va_arg(args, int);
        const char* node2_type = va_arg(args, const char*);
        int index2 = va_arg(args, int);
        const char* node3_type = va_arg(args, const char*);
        int index3 = va_arg(args, int);
        const char* node4_type = va_arg(args, const char*);
        int index4 = va_arg(args, int);
        const char* node5_type = va_arg(args, const char*);
        int index5 = va_arg(args, int);
        const char* end_marker = va_arg(args, const char*);

        if (strcmp(end_marker, "end") == 0) {
            result = cg_goto_five_nodes_end(file_number, B, node1_type, index1, node2_type, index2, node3_type, index3,
                                            node4_type, index4, node5_type, index5);
        }
    }
    else if (arg_count == 13) {
        // Pattern: cg_goto(file, B, "NodeType1_t", index1, "NodeType2_t", index2, "NodeType3_t", index3, "NodeType4_t", index4,
        //  "NodeType5_t", index5, "NodeType6_t", index6, "end")
        const char* node1_type = va_arg(args, const char*);
        int index1 = va_arg(args, int);
        const char* node2_type = va_arg(args, const char*);
        int index2 = va_arg(args, int);
        const char* node3_type = va_arg(args, const char*);
        int index3 = va_arg(args, int);
        const char* node4_type = va_arg(args, const char*);
        int index4 = va_arg(args, int);
        const char* node5_type = va_arg(args, const char*);
        int index5 = va_arg(args, int);
        const char* node6_type = va_arg(args, const char*);
        int index6 = va_arg(args, int);
        const char* end_marker = va_arg(args, const char*);

        if (strcmp(end_marker, "end") == 0) {
            result = cg_goto_six_nodes_end(file_number, B, node1_type, index1, node2_type, index2, node3_type, index3, node4_type,
                                           index4, node5_type, index5, node6_type, index6);
        }
    }
    else if (arg_count == 15) {
        // Pattern: cg_goto(file, B, "NodeType1_t", index1, "NodeType2_t", index2, "NodeType3_t", index3, "NodeType4_t", index4,
        // "NodeType5_t", index5, "NodeType6_t", index6, "NodeType7_t", index7, "end")
        const char* node1_type = va_arg(args, const char*);
        int index1 = va_arg(args, int);
        const char* node2_type = va_arg(args, const char*);
        int index2 = va_arg(args, int);
        const char* node3_type = va_arg(args, const char*);
        int index3 = va_arg(args, int);
        const char* node4_type = va_arg(args, const char*);
        int index4 = va_arg(args, int);
        const char* node5_type = va_arg(args, const char*);
        int index5 = va_arg(args, int);
        const char* node6_type = va_arg(args, const char*);
        int index6 = va_arg(args, int);
        const char* node7_type = va_arg(args, const char*);
        int index7 = va_arg(args, int);
        const char* end_marker = va_arg(args, const char*);

        if (strcmp(end_marker, "end") == 0) {
            result = cg_goto_seven_nodes_end(file_number, B, node1_type, index1, node2_type, index2, node3_type, index3,
                                             node4_type, index4, node5_type, index5, node6_type, index6, node7_type, index7);
        }
    }
    else {
        result = CG_ERROR;
    }

    va_end(args);
    return result;
}

inline int
cg_goto_f08(int file_number, int B, ...)
{
    return Lib().cg_goto_f08_(file_number, B);
}

inline int
cg_gorel(int file_number, ...)
{
    return Lib().cg_gorel_(file_number);
}

inline int
cg_gorel_f08(int file_number, ...)
{
    return Lib().cg_gorel_f08_(file_number);
}

inline int
cg_gopath(int file_number, const char* path)
{
    return Lib().cg_gopath_(file_number, path);
}

inline int
cg_golist(int file_number, int B, int depth, char** label, int* num)
{
    return Lib().cg_golist_(file_number, B, depth, label, num);
}

inline int
cg_where(int* file_number, int* B, int* depth, char** label, int* num)
{
    return Lib().cg_where_(file_number, B, depth, label, num);
}

inline int
cg_convergence_read(int* iterations, char** NormDefinitions)
{
    return Lib().cg_convergence_read_(iterations, NormDefinitions);
}

inline int
cg_convergence_write(int iterations, const char* NormDefinitions)
{
    return Lib().cg_convergence_write_(iterations, NormDefinitions);
}

inline int
cg_state_read(char** StateDescription)
{
    return Lib().cg_state_read_(StateDescription);
}

inline int
cg_state_write(const char* StateDescription)
{
    return Lib().cg_state_write_(StateDescription);
}

inline int
cg_equationset_read(int* EquationDimension, int* GoverningEquationsFlag, int* GasModelFlag, int* ViscosityModelFlag,
                    int* ThermalConductivityModelFlag, int* TurbulenceClosureFlag, int* TurbulenceModelFlag)
{
    return Lib().cg_equationset_read_(EquationDimension, GoverningEquationsFlag, GasModelFlag, ViscosityModelFlag,
                                      ThermalConductivityModelFlag, TurbulenceClosureFlag, TurbulenceModelFlag);
}

inline int
cg_equationset_chemistry_read(int* ThermalRelaxationFlag, int* ChemicalKineticsFlag)
{
    return Lib().cg_equationset_chemistry_read_(ThermalRelaxationFlag, ChemicalKineticsFlag);
}

inline int
cg_equationset_elecmagn_read(int* ElecFldModelFlag, int* MagnFldModelFlag, int* ConductivityModelFlag)
{
    return Lib().cg_equationset_elecmagn_read_(ElecFldModelFlag, MagnFldModelFlag, ConductivityModelFlag);
}

inline int
cg_equationset_write(int EquationDimension)
{
    return Lib().cg_equationset_write_(EquationDimension);
}

inline int
cg_governing_read(CGNS_ENUMT(GoverningEquationsType_t) * EquationsType)
{
    return Lib().cg_governing_read_(EquationsType);
}

inline int
cg_governing_write(CGNS_ENUMT(GoverningEquationsType_t) Equationstype)
{
    return Lib().cg_governing_write_(Equationstype);
}

inline int
cg_diffusion_read(int* diffusion_model)
{
    return Lib().cg_diffusion_read_(diffusion_model);
}

inline int
cg_diffusion_write(const int* diffusion_model)
{
    return Lib().cg_diffusion_write_(diffusion_model);
}

inline int
cg_model_read(const char* ModelLabel, CGNS_ENUMT(ModelType_t) * ModelType)
{
    return Lib().cg_model_read_(ModelLabel, ModelType);
}

inline int
cg_model_write(const char* ModelLabel, CGNS_ENUMT(ModelType_t) ModelType)
{
    return Lib().cg_model_write_(ModelLabel, ModelType);
}

inline int
cg_narrays(int* narrays)
{
    return Lib().cg_narrays_(narrays);
}

inline int
cg_array_info(int A, char* ArrayName, CGNS_ENUMT(DataType_t) * DataType, int* DataDimension, cgsize_t* DimensionVector)
{
    return Lib().cg_array_info_(A, ArrayName, DataType, DataDimension, DimensionVector);
}

inline int
cg_array_read(int A, void* Data)
{
    return Lib().cg_array_read_(A, Data);
}

inline int
cg_array_read_as(int A, CGNS_ENUMT(DataType_t) type, void* Data)
{
    return Lib().cg_array_read_as_(A, type, Data);
}

inline int
cg_array_general_read(int A, const cgsize_t* s_rmin, const cgsize_t* s_rmax, CGNS_ENUMT(DataType_t) m_type, int m_numdim,
                      const cgsize_t* m_dimvals, const cgsize_t* m_rmin, const cgsize_t* m_rmax, void* data)
{
    return Lib().cg_array_general_read_(A, s_rmin, s_rmax, m_type, m_numdim, m_dimvals, m_rmin, m_rmax, data);
}

inline int
cg_array_write(const char* ArrayName, CGNS_ENUMT(DataType_t) DataType, int DataDimension, const cgsize_t* DimensionVector,
               const void* Data)
{
    return Lib().cg_array_write_(ArrayName, DataType, DataDimension, DimensionVector, Data);
}

inline int
cg_array_general_write(const char* arrayname, CGNS_ENUMT(DataType_t) s_type, int s_numdim, const cgsize_t* s_dimvals,
                       const cgsize_t* s_rmin, const cgsize_t* s_rmax, CGNS_ENUMT(DataType_t) m_type, int m_numdim,
                       const cgsize_t* m_dimvals, const cgsize_t* m_rmin, const cgsize_t* m_rmax, const void* data)
{
    return Lib().cg_array_general_write_(arrayname, s_type, s_numdim, s_dimvals, s_rmin, s_rmax, m_type, m_numdim, m_dimvals,
                                         m_rmin, m_rmax, data);
}

inline int
cg_nuser_data(int* nuser_data)
{
    return Lib().cg_nuser_data_(nuser_data);
}

inline int
cg_user_data_read(int Index, char* user_data_name)
{
    return Lib().cg_user_data_read_(Index, user_data_name);
}

inline int
cg_user_data_write(const char* user_data_name)
{
    return Lib().cg_user_data_write_(user_data_name);
}

inline int
cg_nintegrals(int* nintegrals)
{
    return Lib().cg_nintegrals_(nintegrals);
}

inline int
cg_integral_read(int IntegralDataIndex, char* IntegralDataName)
{
    return Lib().cg_integral_read_(IntegralDataIndex, IntegralDataName);
}

inline int
cg_integral_write(const char* IntegralDataName)
{
    return Lib().cg_integral_write_(IntegralDataName);
}

inline int
cg_rind_read(int* RindData)
{
    return Lib().cg_rind_read_(RindData);
}

inline int
cg_rind_write(const int* RindData)
{
    return Lib().cg_rind_write_(RindData);
}

inline int
cg_ndescriptors(int* ndescriptors)
{
    return Lib().cg_ndescriptors_(ndescriptors);
}

inline int
cg_descriptor_read(int descr_no, char* descr_name, char** descr_text)
{
    return Lib().cg_descriptor_read_(descr_no, descr_name, descr_text);
}

inline int
cg_descriptor_write(const char* descr_name, const char* descr_text)
{
    return Lib().cg_descriptor_write_(descr_name, descr_text);
}

inline int
cg_nunits(int* nunits)
{
    return Lib().cg_nunits_(nunits);
}

inline int
cg_units_read(CGNS_ENUMT(MassUnits_t) * mass, CGNS_ENUMT(LengthUnits_t) * length, CGNS_ENUMT(TimeUnits_t) * time,
              CGNS_ENUMT(TemperatureUnits_t) * temperature, CGNS_ENUMT(AngleUnits_t) * angle)
{
    return Lib().cg_units_read_(mass, length, time, temperature, angle);
}

inline int
cg_units_write(CGNS_ENUMT(MassUnits_t) mass, CGNS_ENUMT(LengthUnits_t) length, CGNS_ENUMT(TimeUnits_t) time,
               CGNS_ENUMT(TemperatureUnits_t) temperature, CGNS_ENUMT(AngleUnits_t) angle)
{
    return Lib().cg_units_write_(mass, length, time, temperature, angle);
}

inline int
cg_unitsfull_read(CGNS_ENUMT(MassUnits_t) * mass, CGNS_ENUMT(LengthUnits_t) * length, CGNS_ENUMT(TimeUnits_t) * time,
                  CGNS_ENUMT(TemperatureUnits_t) * temperature, CGNS_ENUMT(AngleUnits_t) * angle,
                  CGNS_ENUMT(ElectricCurrentUnits_t) * current, CGNS_ENUMT(SubstanceAmountUnits_t) * amount,
                  CGNS_ENUMT(LuminousIntensityUnits_t) * intensity)
{
    return Lib().cg_unitsfull_read_(mass, length, time, temperature, angle, current, amount, intensity);
}

inline int
cg_unitsfull_write(CGNS_ENUMT(MassUnits_t) mass, CGNS_ENUMT(LengthUnits_t) length, CGNS_ENUMT(TimeUnits_t) time,
                   CGNS_ENUMT(TemperatureUnits_t) temperature, CGNS_ENUMT(AngleUnits_t) angle,
                   CGNS_ENUMT(ElectricCurrentUnits_t) current, CGNS_ENUMT(SubstanceAmountUnits_t) amount,
                   CGNS_ENUMT(LuminousIntensityUnits_t) intensity)
{
    return Lib().cg_unitsfull_write_(mass, length, time, temperature, angle, current, amount, intensity);
}

inline int
cg_exponents_info(CGNS_ENUMT(DataType_t) * DataType)
{
    return Lib().cg_exponents_info_(DataType);
}

inline int
cg_nexponents(int* numexp)
{
    return Lib().cg_nexponents_(numexp);
}

inline int
cg_exponents_read(void* exponents)
{
    return Lib().cg_exponents_read_(exponents);
}

inline int
cg_exponents_write(CGNS_ENUMT(DataType_t) DataType, const void* exponents)
{
    return Lib().cg_exponents_write_(DataType, exponents);
}

inline int
cg_expfull_read(void* exponents)
{
    return Lib().cg_expfull_read_(exponents);
}

inline int
cg_expfull_write(CGNS_ENUMT(DataType_t) DataType, const void* exponents)
{
    return Lib().cg_expfull_write_(DataType, exponents);
}

inline int
cg_conversion_info(CGNS_ENUMT(DataType_t) * DataType)
{
    return Lib().cg_conversion_info_(DataType);
}

inline int
cg_conversion_read(void* ConversionFactors)
{
    return Lib().cg_conversion_read_(ConversionFactors);
}

inline int
cg_conversion_write(CGNS_ENUMT(DataType_t) DataType, const void* ConversionFactors)
{
    return Lib().cg_conversion_write_(DataType, ConversionFactors);
}

inline int
cg_dataclass_read(CGNS_ENUMT(DataClass_t) * dataclass)
{
    return Lib().cg_dataclass_read_(dataclass);
}

inline int
cg_dataclass_write(CGNS_ENUMT(DataClass_t) dataclass)
{
    return Lib().cg_dataclass_write_(dataclass);
}

inline int
cg_gridlocation_read(CGNS_ENUMT(GridLocation_t) * GridLocation)
{
    return Lib().cg_gridlocation_read_(GridLocation);
}

inline int
cg_gridlocation_write(CGNS_ENUMT(GridLocation_t) GridLocation)
{
    return Lib().cg_gridlocation_write_(GridLocation);
}

inline int
cg_ordinal_read(int* Ordinal)
{
    return Lib().cg_ordinal_read_(Ordinal);
}

inline int
cg_ordinal_write(int Ordinal)
{
    return Lib().cg_ordinal_write_(Ordinal);
}

inline int
cg_ptset_info(CGNS_ENUMT(PointSetType_t) * ptset_type, cgsize_t* npnts)
{
    return Lib().cg_ptset_info_(ptset_type, npnts);
}

inline int
cg_ptset_write(CGNS_ENUMT(PointSetType_t) ptset_type, cgsize_t npnts, const cgsize_t* pnts)
{
    return Lib().cg_ptset_write_(ptset_type, npnts, pnts);
}

inline int
cg_ptset_read(cgsize_t* pnts)
{
    return Lib().cg_ptset_read_(pnts);
}

inline int
cg_is_link(int* path_length)
{
    return Lib().cg_is_link_(path_length);
}

inline int
cg_link_read(char** filename, char** link_path)
{
    return Lib().cg_link_read_(filename, link_path);
}

inline int
cg_link_write(const char* nodename, const char* filename, const char* name_in_file)
{
    return Lib().cg_link_write_(nodename, filename, name_in_file);
}

inline int
cg_delete_node(const char* node_name)
{
    return Lib().cg_delete_node_(node_name);
}

inline int
cg_free(void* data)
{
    return Lib().cg_free_(data);
}

inline const char*
cg_get_error(void)
{
    return Lib().cg_get_error_();
}

inline void
cg_error_exit(void)
{
    return Lib().cg_error_exit_();
}

inline void
cg_error_print(void)
{
    return Lib().cg_error_print_();
}
}