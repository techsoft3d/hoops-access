#pragma once

#include "samcpp/core/base_types.h"
#include "samcpp/core/coredefs.h"
#include "samcpp/core/pimpl.h"
#include "samcpp/core/status.h"

#include <memory>

ACCESSOR_DECL

namespace cae::core {

class GlobalProperty {
  public:
    PIMPL_MOVE_ONLY(GlobalProperty)

    /// \brief Global property value flag
    enum class PropertyFlag {
        UNDEFINED = GPROP_UNDEFINED,  ///< Property value not defined
        VALUE = GPROP_VALUE,          ///< Property defined with a value
        IDENTIFIER = GPROP_IDENTIFIER ///< Property defined with an TableFunction identifier
    };

    /// \brief Global character valued property types
    enum class StringProperty {
        TITLE = GPROP_TITLE,                     ///< Title
        SUBTITLE = GPROP_SUBTITLE,               ///< Subtitle
        ORIGINATING_CODE = GPROP_ORIGCODE,       ///< Originating code
        ORIGINATING_VERSION = GPROP_ORIGVERSION, ///< Originating code version
        ORIGINATING_TIME = GPROP_ORIGTIME,       ///< Originating time
        ORIGINATING_DATE = GPROP_ORIGDATE        ///< Originating date
    };

    /// \brief Global integer values property types
    enum class IntegerProperty {
        LIBRARY = GPROP_LIBRARY,                                  ///< Access import library file format type
        AUTOSPC = GPROP_AUTOSPC,                                  ///< Auto SPC flag
        CYCLIC_SECTOR_COUNT = GPROP_CYCLIC_NSEC,                  ///< Cyclic Mode analysis: number of cyclic sectors
        DEFINED_SYMMETRY_COUNT = GPROP_SYMM_NUM,                  ///< cyclic symmetry: number of defined symmetries
        SYMMETRY_IDS = GPROP_SYMM_ID,                             ///< cyclic symmetry: list of symmetries Ids [DEFINED_SYMMETRY_COUNT]
        CYLINDRICAL_COORDINATE_SYSTEM_IDS = GPROP_SYMM_CID,       ///< cyclic symmetry: list of cylind. coord. systems Ids [DEFINED_SYMMETRY_COUNT]
        SYMMETRY_NUMBER_OF_SECTORS = GPROP_SYMM_NSEC,             ///< cyclic symmetry: number of sections for each symmetry [DEFINED_SYMMETRY_COUNT]
        SECTOR_ID = GPROP_SYMM_STAGEID,                           ///< Symmetry group stage or sector Id [DEFINED_SYMMETRY_COUNT]
        CYCLIC_CYLINDRICAL_COORD_SYSTEM_ID = GPROP_CYCLIC_CSYSID, ///< Cyclic Mode analysis: Reference Cylindrical coord syst ID
        PERMANENT_GLUE = GPROP_PERMANENT_GLUE,                    ///< Contact computed at 1st step and frozen for the whole computation
        SYMMETRY_EMBEDDED_SET_ID = GPROP_SYMM_ESET,               ///< Symmetry group embedded element set id [DEFINED_SYMMETRY_COUNT]
        EXPORT_VENDOR = GPROP_EXPORT_VENDOR,                      ///< Export Vendor type
        IMPORT_VENDOR = GPROP_IMPORT_VENDOR,                      ///< Import Vendor type
        AXIS_2D = GPROP_2DAXIS,                                   ///< 2D rotation axis
        PLANE_2D = GPROP_2DPLANE,                                 ///< 2D plane orientation type
        ANALYSIS_TYPE_2D = GPROP_2DTYPE                           ///< 2D analysis type
    };

    /// \brief Global real values property types
    enum class DoubleProperty {
        CYCLIC_ORIGIN = GPROP_CYCLIC_ORIG,                ///< Cyclic Mode analysis: origin of cyclic coordinate System(x, y, z) [3]
        CYCLIC_AXIS = GPROP_CYCLIC_AXIS,                  ///< Cyclic Mode analysis: axis of cyclic coordinate System(x, y, z) [3]
        STEFAN_BOLTZMANN = GPROP_STEFAN_BOLTZMANN,        ///< Stefan Boltzmann constant
        ABSOLUTE_ZERO_TEMPERATURE = GPROP_ABSOLUTE_ZERO,  ///< Absolute Zero Temperature
        SYMMETRY_ORIGIN = GPROP_SYMM_ORIG,                ///< Origin of symmetry coordinate System (x, y, z) [DEFINED_SYMMETRY_COUNT][3]
        SYMMETRY_AXIS = GPROP_SYMM_AXIS,                  ///< Axis of symmetry coordinate System(x, y, z) [DEFINED_SYMMETRY_COUNT][3]
        STRUCTURAL_DAMPING_COEFFICIENT = GPROP_STIFF_DAMP ///< Structural damping coefficient
    };

    ErrorCode getErrorCode();
    Status    setPropertyDoubleValue(DoubleProperty type, double value);
    Status    setPropertyDoubleArray(DoubleProperty type, double values[]);
    Status    setPropertyStringValue(StringProperty type, const char *value);
    Status    unsetProperty(IntegerProperty type);
    Status    unsetProperty(DoubleProperty type);
    Status    unsetProperty(StringProperty type);
    Status    getPropertyCount(int *count);
    Status    getPropertyFlag(IntegerProperty type, PropertyFlag *flag);
    Status    getPropertyFlag(DoubleProperty type, PropertyFlag *flag);
    Status    getPropertyFlag(StringProperty type, PropertyFlag *flag);
    Status    getPropertyInformation(IntegerProperty type, int *componentsCount);
    Status    getPropertyInformation(DoubleProperty type, int *componentsCount);
    Status    getPropertyInformation(StringProperty type, int *componentsCount);
    Status    getPropertyName(IntegerProperty type, char name[]);
    Status    getPropertyName(DoubleProperty type, char name[]);
    Status    getPropertyName(StringProperty type, char name[]);
    Status    getPropertyDoubleValue(DoubleProperty type, double values[]);
    Status    getPropertyStringValue(StringProperty type, char value[]);
    Status    print();

    template <auto IntegerPropertyType, typename PropertyValue>
    Status setPropertyIntegerValue(PropertyValue value);

    template <auto IntegerPropertyType, typename PropertyValue>
    Status setPropertyIntegerArray(PropertyValue values[]);

    template <auto IntegerPropertyType, typename PropertyValue>
    Status getPropertyIntegerValue(PropertyValue values[]);

  private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // namespace cae::core
