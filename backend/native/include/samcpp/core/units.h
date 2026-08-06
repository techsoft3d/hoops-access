#pragma once

#include "sam/vis/unitsdefs.h"
#include "samcpp/core/base_types.h"
#include "samcpp/core/pimpl.h"
#include "samcpp/core/status.h"

#include <memory>

ACCESSOR_DECL

namespace cae::core {

class Units {
  public:
    /// Unit types
    enum class Type {
        LENGTH = UNITS_LENGTH,           ///< Length unit
        MASS = UNITS_MASS,               ///< Mass unit
        TIME = UNITS_TIME,               ///< Time unit
        TEMP = UNITS_TEMP,               ///< Temperature unit
        TEMP_OFFSET = UNITS_TEMP_OFFSET, ///< Temperature offset unit
        ANGLE = UNITS_ANGLE,             ///< Angle unit
        CHARGE = UNITS_CHARGE            ///< Charge unit
    };

    /// Units
    enum class Unit {
        // Length units
        LENGTH_METER = UNITS_LENGTH_METER,           ///< Meter
        LENGTH_CENTIMETER = UNITS_LENGTH_CENTIMETER, ///< Centimeter
        LENGTH_MILLIMETER = UNITS_LENGTH_MILLIMETER, ///< Millimeter
        LENGTH_MICRON = UNITS_LENGTH_MICRON,         ///< Micrometer
        LENGTH_NANOMETER = UNITS_LENGTH_NANOMETER,   ///< Nanometer
        LENGTH_ANGSTROM = UNITS_LENGTH_ANGSTROM,     ///< Angstrom
        LENGTH_KILOMETER = UNITS_LENGTH_KILOMETER,   ///< Kilometer
        LENGTH_INCH = UNITS_LENGTH_INCH,             ///< Inch
        LENGTH_FOOT = UNITS_LENGTH_FOOT,             ///< Foot
        LENGTH_MILE = UNITS_LENGTH_MILE,             ///< Mile
        LENGTH_USER = UNITS_LENGTH_USER,             ///< User length unit

        // Mass units
        MASS_KILOGRAM = UNITS_MASS_KILOGRAM,                           ///< Kilogram
        MASS_GRAM = UNITS_MASS_GRAM,                                   ///< Gram
        MASS_POUND = UNITS_MASS_POUND,                                 ///< Pound
        MASS_SLUG = UNITS_MASS_SLUG,                                   ///< Slug
        MASS_METRICTON = UNITS_MASS_METRICTON,                         ///< Metric Ton
        MASS_BLOB = UNITS_MASS_BLOB,                                   ///< Blob
        MASS_KILOGRAMFM = UNITS_MASS_KILOGRAMFM,                       ///< Kilogram-force second squared per meter
        MASS_KILOGRAMFMM = UNITS_MASS_KILOGRAMFMM,                     ///< Kilogram-force second squared per millimeter
        MASS_USER = UNITS_MASS_USER,                                   ///< User mass unit
        MASS_NEWTONHOURSQUAREPERMM = UNITS_MASS_NEWTONHOURSQUAREPERMM, ///< Newton hour squared per millimeter
        MASS_MILLIGRAM = UNITS_MASS_MILLIGRAM,                         ///< Milligram

        // Time units
        TIME_SECOND = UNITS_TIME_SECOND,           ///< Second
        TIME_MINUTE = UNITS_TIME_MINUTE,           ///< Minute
        TIME_HOUR = UNITS_TIME_HOUR,               ///< Hour
        TIME_USER = UNITS_TIME_USER,               ///< User time unit
        TIME_MICROSECOND = UNITS_TIME_MICROSECOND, ///< Microsecond
        TIME_MILLISECOND = UNITS_TIME_MILLISECOND, ///< Millisecond

        // Temperature units
        TEMP_KELVIN = UNITS_TEMP_KELVIN,         ///< Kelvin
        TEMP_CELSIUS = UNITS_TEMP_CELSIUS,       ///< Degree Celsius
        TEMP_RANKINE = UNITS_TEMP_RANKINE,       ///< Degree Rankine
        TEMP_FAHRENHEIT = UNITS_TEMP_FAHRENHEIT, ///< Degree Fahrenheit
        TEMP_USER = UNITS_TEMP_USER,             ///< User temperature unit

        // Angle units
        ANGLE_RADIAN = UNITS_ANGLE_RADIAN, ///< Radian
        ANGLE_DEGREE = UNITS_ANGLE_DEGREE, ///< Degree
        ANGLE_CYCLE = UNITS_ANGLE_CYCLE,   ///< Cycle, 2 pi radians
        ANGLE_USER = UNITS_ANGLE_USER,     ///< User angle unit

        // Charge units
        CHARGE_COULOMB = UNITS_CHARGE_COULOMB, ///< Coulomb
        CHARGE_USER = UNITS_CHARGE_USER        ///< User charge unit
    };

    PIMPL_MOVE_ONLY(Units)

    ErrorCode getErrorCode();
    Status    setBase(Type type, Unit value);
    Status    getBase(Type type, Unit *value);
    Status    setConversion(Type type, Unit value);
    Status    getConversion(Type type, Unit *value);
    Status    getDescription(Type type, Unit value, char description[]);
    Status    setConversionFactor(Type type, double value);
    Status    getConversionFactor(Type type, double *value);
    Status    computeConversionFactors();
    Status    copy(Units *from);
    Status    print();

  private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // namespace cae::core
