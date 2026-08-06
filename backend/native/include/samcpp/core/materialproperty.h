#pragma once

#include "samcpp/core/base_types.h"
#include "samcpp/core/coredefs.h"
#include "samcpp/core/pimpl.h"
#include "samcpp/core/status.h"

#include <memory>

ACCESSOR_DECL

namespace cae::core {

class MaterialProperty {
  public:
    PIMPL_MOVE_ONLY(MaterialProperty)

    /// Material property value flag
    enum class PropertyFlag {
        UNDEFINED = MPROP_UNDEFINED,  ///< Property value is undefined
        VALUE = MPROP_VALUE,          ///< Property is specified by direct value
        IDENTIFIER = MPROP_IDENTIFIER ///< Property is specified by identifier reference
    };

    /// Material property type
    enum class Type {
        ISOTROPIC = SYS_MAT_ISOTROPIC,       ///< Isotropic material
        LAMINA = SYS_MAT_LAMINA,             ///< Lamina material
        ORTHOTROPIC = SYS_MAT_ORTHOTROPIC,   ///< Orthotropic material
        ANISOTROPIC = SYS_MAT_ANISOTROPIC,   ///< Anisotropic material
        HYPERELASTIC = SYS_MAT_HYPERELASTIC, ///< Hyperelastic material
        GENERIC = SYS_MAT_GENERIC            ///< Generic material
    };

    /// Material property identifiers
    enum class DoubleProperty {
        DENSITY = MPROP_DENSITY,                         ///< Material density
        YOUNG_MODULUS = MPROP_E,                         ///< Young's modulus (elasticity modulus)
        POISSON_RATIO = MPROP_NU,                        ///< Poisson's ratio
        SHEAR_MODULUS = MPROP_G,                         ///< Isotropic shear modulus, torsional shear modulus for 1D
        THERMAL_EXPANSION_COEFFICIENT = MPROP_A,         ///< Coefficient of thermal expansion
        STRUCTURAL_DAMPING_COEFFICIENT = MPROP_GE,       ///< Structural damping coefficient
        REFERENCE_TEMPERATURE = MPROP_TREF,              ///< Reference temperature
        ORTHOTROPIC_ELASTIC_MODULI = MPROP_EORT,         ///< Orthotropic elasticity moduli in 3 directions [3]
        ORTHOTROPIC_POISSON_RATIOS = MPROP_NUORT,        ///< Orthotropic Poisson ratios in 3 directions [3]
        ORTHOTROPIC_SHEAR_MODULI = MPROP_GORT,           ///< Orthotropic shear moduli in 3 directions [3]
        ORTHOTROPIC_EXPANSION_COEFFICIENT = MPROP_AORT,  ///< Orthotropic coefficients of thermal expansion in 3 directions [3]
        STIFFNESS_MATRIX = MPROP_DMAT,                   ///< Stiffness matrix 6x6 symmetric [21]
        THERMAL_EXPANSION_VECTOR = MPROP_AVEC,           ///< Thermal expansion vector 6 components [6]
        STRESS_LIMIT_TENSILE_FIBER = MPROP_SXT,          ///< Tensile stress limit in fiber direction (Xt)
        STRESS_LIMIT_COMPRESSIVE_FIBER = MPROP_SXC,      ///< Compressive stress limit in fiber direction (Xc)
        STRESS_LIMIT_TENSILE_TRANSVERSE = MPROP_SYT,     ///< Tensile stress limit in transverse direction (Yt)
        STRESS_LIMIT_COMPRESSIVE_TRANSVERSE = MPROP_SYC, ///< Compressive stress limit in transverse direction (Yc)
        STRESS_LIMIT_SHEAR_STRESS = MPROP_SHR,           ///< Shear strength in the X-Y plane (S)
        STRAIN_LIMIT_TENSILE_FIBER = MPROP_EXT,          ///< Tensile strain limit in fiber direction
        STRAIN_LIMIT_COMPRESSIVE_FIBER = MPROP_EXC,      ///< Compressive strain limit in fiber direction
        STRAIN_LIMIT_TENSILE_TRANSVERSE = MPROP_EYT,     ///< Tensile strain limit in transverse direction
        STRAIN_LIMIT_COMPRESSIVE_TRANSVERSE = MPROP_EYC, ///< Compressive strain limit in transverse direction
        STRAIN_LIMIT_SHEAR_STRAIN = MPROP_EHR,           ///< Shear strain limit in the X-Y plane
        THERMAL_CONDUCTIVITY = MPROP_K,                  ///< Thermal conductivity (isotropic)
        SPECIFIC_HEAT = MPROP_CP,                        ///< Specific heat capacity
        FILM_COEFFICIENT = MPROP_FILM,                   ///< Film coefficient for convection
        HEAT_GENERATION_CAPABILITY = MPROP_HGEN,         ///< Heat generation capability
        REFERENCE_ENTHALPY = MPROP_EREF,                 ///< Reference enthalpy
        EMISSIVITY = MPROP_EMIS,                         ///< Emissivity for radiation
        ORTHOTROPIC_THERMAL_CONDUCTIVITY = MPROP_KORT,   ///< Thermal conductivity orthotropic (x,y,z) [3]
        ANISOTROPIC_THERMAL_CONDUCTIVITY = MPROP_KMAT,   ///< Thermal conductivity matrix anisotropic [6]
        BULK_MODULUS = MPROP_BULK,                       ///< Bulk modulus
        SPEED_OF_SOUND = MPROP_SOUND,                    ///< Speed of sound in material
        MOONEY_RIVLIN_DISTORTIONAL = MPROP_HYPER_CIJ,    ///< Material constants for distortional deformation (Mooney-Rivlin) [27]
        MOONEY_RIVLIN_VOLUMETRIC = MPROP_HYPER_DI,       ///< Material constants for volumetric deformation (Mooney-Rivlin) [6]
        TSAI_WU_INTERACTION_TERM = MPROP_F12,            ///< Tsai-Wu interaction term for composite failure
        VISCOSITY = MPROP_VISCOSITY,                     ///< Viscosity
        USER_PROPERTY = MPROP_USER                       ///< User-defined property
    };

    /// Material property identifiers
    enum class IntegerProperty {
        MOONEY_RIVLIN_STRAIN_ORDER = MPROP_HYPER_N,                  ///< Order of strain energy potential
        PLASTICITY_HARDENING_TYPE = MPROP_PLASTICITY_HARDENING_TYPE, ///< Plastic hardening type: isotropic or kinematic
        PLASTICITY_TABULAR_DATA = MPROP_PLASTICITY_TABULAR_DATA      ///< Plastic hardening tabular data
    };

    ErrorCode getErrorCode();
    Status    define(Type type);
    Status    inquire(Type *type);
    Status    redefine(Type type);
    Status    setPropertyDoubleValue(DoubleProperty property, double value);
    Status    setPropertyDoubleArray(DoubleProperty property, double values[]);
    Status    setPropertyId(DoubleProperty property, int id);
    Status    unsetProperty(IntegerProperty property);
    Status    unsetProperty(DoubleProperty property);
    Status    getPropertyCount(int *count);
    Status    getIntegerPropertyTypes(int *count, IntegerProperty properties[]);
    Status    getDoublePropertyTypes(int *count, DoubleProperty properties[]);
    Status    getPropertyInformation(IntegerProperty Property, int *componentCount);
    Status    getPropertyInformation(DoubleProperty Property, int *componentCount);
    Status    getPropertyFlag(IntegerProperty property, PropertyFlag *flag);
    Status    getPropertyFlag(DoubleProperty property, PropertyFlag *flag);
    Status    getPropertyId(DoubleProperty property, int *id);
    Status    getPropertyName(IntegerProperty property, char name[]);
    Status    getPropertyName(DoubleProperty property, char name[]);
    Status    getPropertyDoubleValue(DoubleProperty property, double values[]);
    Status    setId(int id);
    Status    getId(int *id);
    Status    setName(const char *name);
    Status    getName(char name[]);
    Status    print();
    Status    copy(MaterialProperty *from);

    template <auto IntegerPropertyValue, typename typeValue>
    Status setPropertyIntegerValue(typeValue value);

    template <auto IntegerPropertyValue, typename typeValue>
    Status getPropertyIntegerValue(typeValue values[]);

  private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // namespace cae::core
