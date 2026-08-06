#pragma once

#include "samcpp/core/base_types.h"
#include "samcpp/core/coredefs.h"
#include "samcpp/core/pimpl.h"
#include "samcpp/core/status.h"

#include <memory>

ACCESSOR_DECL

namespace cae::core {

class ElementProperty {
  public:
    PIMPL_MOVE_ONLY(ElementProperty)

    /// \brief Element property value flag
    enum class PropertyFlag {
        UNDEFINED = EPROP_UNDEFINED,  ///< Property value is undefined
        VALUE = EPROP_VALUE,          ///< Property is specified by direct value
        IDENTIFIER = EPROP_IDENTIFIER ///< Property is specified by identifier reference
    };

    /// \brief Element integer property types
    enum class IntegerProperty {
        MATERIAL_ID = EPROP_MID,                                                     ///< Material Id
        MATERIAL_ID_BENDING = EPROP_MID_BEND,                                        ///< Material Id - bending
        MATERIAL_ID_TRANSVERSAL = EPROP_MID_TRAN,                                    ///< Material Id - transverse shear
        MATERIAL_ID_MEMBRANE_BENDING_COUPLING = EPROP_MID_COUP,                      ///< Material Id - membrane bending coupling
        MATERIAL_COORDINATE_SYSTEM_ID = EPROP_MATLCID,                               ///< Material Id membrane bending coupling
        NO_SEPARATION = EPROP_NOSEPARATION,                                          ///< Gap: No separation option
        NO_SLIP = EPROP_NOSLIP,                                                      ///< Gap: No slip option
        DOF_FLAGS_COUNT = EPROP_DOFFLAG_NUM,                                         ///< Number of dof flags
        INDEPENDENT_DOF_FLAGS = EPROP_DOFFLAG_IND,                                   ///< Independent dof flags [DOF_FLAGS_COUNT]
        DEPENDENT_DOF_FLAGS = EPROP_DOFFLAG_DEP,                                     ///< Dependent dof flags [DOF_FLAGS_COUNT]
        SHELL_LAYER_GLOBAL_ID = EPROP_LAYER_GID,                                     ///< Shell layer global Id [SHELL_LAYERS_COUNT]
        LAYER_MATERIAL_ID = EPROP_LAYER_MID,                                         ///< Layer material Id [SHELL_LAYERS_COUNT]
        LAYER_INTEGRATION_POINT_COUNT = EPROP_LAYER_NIP,                             ///< Number of layer [SHELL_LAYERS_COUNT]
        SHELL_LAYERS_COUNT = EPROP_LAYER_NUM,                                        ///< Number of shell layers
        SHELL_WALL_TYPE = EPROP_SHELLWALL,                                           ///< Shell wall type
        INTEGRATION_RULE = EPROP_RULE,                                               ///< Integration rule
        BEAM_REFLECTION_Y = EPROP_BEAMREFLECTY,                                      ///< Beam section reflect about y axis
        BEAM_REFLECTION_Z = EPROP_BEAMREFLECTZ,                                      ///< Beam section reflect about z axis
        BEAM_SECTION_TYPE = EPROP_BEAMSECT,                                          ///< Beam section type
        BEAM_SECTION_POINTS_COUNT = EPROP_BEAMPNTS_NUM,                              ///< Beam section number of points
        BEAM_SECTION_LOOPS_COUNT = EPROP_BEAMLOOP_NUM,                               ///< Beam section number of loops
        BEAM_SECTION_LOOPS_POINT_COUNT = EPROP_BEAMLOOP_PNTSNUM,                     ///< Beam section loop number of points [BEAM_SECTION_LOOPS_COUNT]
        BEAM_SECTION_LOOP_TYPE = EPROP_BEAMLOOP_TYPE,                                ///< Beam section loop type [BEAM_SECTION_LOOPS_COUNT]
        BEAM_SECTION_LOOP_MATERIAL_ID = EPROP_BEAMLOOP_MID,                          ///< Beam section loop material Id [BEAM_SECTION_LOOPS_COUNT]
        BEAM_SECTION_LOOP_POINTS = EPROP_BEAMLOOP_PNTS,                              ///< Beam section all loop points [BEAM_SECTION_LOOPS_COUNT]
        BEAM_SECTION_SEGMENT_COUNT = EPROP_BEAMSEGS_NUM,                             ///< Beam section number of segments
        TIED = EPROP_TIED,                                                           ///< Tied behavior
        NSM_ID = EPROP_NSM_ID,                                                       ///< Nonstructural mass identifier
        NSM_COUNT = EPROP_NSM_NUM,                                                   ///< Nonstructural mass number of values
        NSM_VALUE_SET_IDS = EPROP_NSM_VAL_SETIDS,                                    ///< Nonstructural mass value set identifiers [NSM_COUNT]
        NSM_LUMPED_MASS_FLAG = EPROP_NSM_VAL_LUMP,                                   ///< Nonstructural lumped mass flag [NSM_COUNT]
        BEND_FLEXFACTOR = EPROP_BEND_FLEXFACTOR,                                     ///< Bend flexibility stress identification factor method
        AMBIENT_ELEMENT_TYPE = EPROP_AMBIENT_TYPE,                                   ///< Ambient element type
        GALERKIN_SPLINE_FUNCTION_TYPE = EPROP_GALERKIN_SPLINE_TYPE,                  ///< Galerkin spline function type to use on kernel
        GALERKIN_DILATION_FUNCTION_TYPE = EPROP_GALERKIN_DILATION_TYPE,              ///< Galerkin dilation function type
        GALERKIN_ESSENTIAL_BC_TYPE = EPROP_GALERKIN_ESSENTIAL_BC_TYPE,               ///< Galerkin essential boundary condition type
        GALERKIN_DOMAIN_INTEGRATION_TYPE = EPROP_GALERKIN_DOMAIN_INTEGRATION_TYPE,   ///< Galerkin domain integration type
        GALERKIN_PRESSURE_SMOOTHING = EPROP_GALERKIN_PRESSURE_SMOOTHING,             ///< Galerkin pressure smoothing flag
        GALERKIN_KERNEL = EPROP_GALERKIN_KERNEL,                                     ///< Galerkin type of kernel support
        GALERKIN_SMOOTHING_STEPS_INTERVAL = EPROP_GALERKIN_SMOOTHING_STEPS_INTERVAL, ///< Galerkin interval of time steps to conduct displacement smoothing
        GALERKIN_SMOOTHING_SCHEME = EPROP_GALERKIN_SMOOTHING_SCHEME,                 ///< Galerkin smoothing scheme for momentum consistent SPG only
        GALERKIN_BOND_FAILURE_TYPE = EPROP_GALERKIN_BOND_FAILURE_TYPE,               ///< Galerkin bond failure mechanism
        GALERKIN_STABILIZATION_TYPE = EPROP_GALERKIN_STABILIZATION_TYPE,             ///< Galerkin stabilization type
        GALERKIN_SELF_CONTACT = EPROP_GALERKIN_SELF_CONTACT,                         ///< Galerkin self contact flag
        GALERKIN_BOX_ID = EPROP_GALERKIN_BOX_ID,                                     ///< Galerkin box id defining the active region
        TENSION_TABLES = EPROP_TENSION_TABLES,                                       ///< Tabular functions Id defining non linear elastic or viscous damper as force relationship
        REINFORCEMENT_SECTION_TYPE = EPROP_REINFSECT,                                ///< Reinforcement section type
        REINFORCEMENT_SECTION_MEMBER_COUNT = EPROP_REINFSECT_NUM,                    ///< Reinforcement section member count
        REINFORCEMENT_SECTION_MATERIAL_ID = EPROP_REINFSECT_MID,                     ///< Reinforcement section material Id [REINFORCEMENT_SECTION_MEMBER_COUNT]
        REINFORCEMENT_COORDINATE_SYSTEM_ID = EPROP_REINFSECT_CID,                    ///< Reinforcement section coordinate system [REINFORCEMENT_SECTION_MEMBER_COUNT]
        REINFORCEMENT_SECTION_LOCATION_TYPE = EPROP_REINFSECT_LOCATION_TYPE,         ///< Reinforcement section location type
        COHESIVE_RESPONSE_TYPE = EPROP_COHESIVE_RESPONSE_TYPE,                       ///< Constitutive cohesive behavior
        FRICTION_TYPE = EPROP_FRICTION_TYPE,                                         ///< Friction type
        HEAT_EXCHANGE_TYPE = EPROP_HEATEXCH,                                         ///< Heat exchange type
        SPRING_DOF_TAG1 = EPROP_DOF1,                                                ///< Degree of freedom tag 1
        SPRING_DOF_TAG2 = EPROP_DOF2                                                 ///< Degree of freedom tag 2
    };

    /// \brief Element real element property Type
    enum class DoubleProperty {
        THICKNESS = EPROP_THICKNESS,                                           ///< Thickness [4]
        MIDSURFACE_OFFSET = EPROP_OFFSET,                                      ///< Offset [4]
        EFFECTIVE_SHEAR_RATIO = EPROP_KS,                                      ///< Effective shear ratio
        BENDING_STIFFNESS = EPROP_BENDSTF,                                     ///< Bending stiffness
        NONSTRUCTURAL_MASS = EPROP_NSM,                                        ///< Nonstructural mass [4]
        SR_BOTTOM_FIBER = EPROP_SRBOT,                                         ///< Fiber distance - bottom
        SR_TOP_FIBER = EPROP_SRTOP,                                            ///< Fiber distance - top
        AREA = EPROP_AREA,                                                     ///< Area [2]
        MOMENT_OF_INERTIA_YY = EPROP_IYY,                                      ///< Moment of inertia about y axis [2]
        MOMENT_OF_INERTIA_ZZ = EPROP_IZZ,                                      ///< Moment of inertia about z axis [2]
        MOMENT_OF_INTERTIA_YZ = EPROP_IYZ,                                     ///< Product of inertia [2]
        TORSIONAL_STIFFNESS = EPROP_J,                                         ///< Torsional constant [2]
        EFFECTIVE_SHEAR_FACTOR_Y_AXIS = EPROP_KSY,                             ///< Effective shear factor along y axis [2]
        EFFECTIVE_SHEAR_FACTOR_Z_AXIS = EPROP_KSZ,                             ///< Effective shear factor along z axis [2]
        SHEAR_CENTER_OFFSET_Y_AXIS = EPROP_DSY,                                ///< Shear center offset along y axis [2]
        SHEAR_CENTER_OFFSET_Z_AXIS = EPROP_DSZ,                                ///< Shear center offset along z axis [2]
        CENTROID_OFFSET_Y_AXIS = EPROP_OFFSETY,                                ///< Offset along y axis [2]
        CENTROID_OFFSET_Z_AXIS = EPROP_OFFSETZ,                                ///< Offset along z axis [2]
        WARPING_COEFFICIENT = EPROP_CW,                                        ///< Warping coefficient [2]
        CONNECTOR_INTERNAL_DIAMETER = EPROP_DIN,                               ///< (1D) connector internal diameter (not used)
        CONNECTOR_EXTERNAL_DIAMETER = EPROP_DOUT,                              ///< (1D) connector external diameter
        BEND_RADIUS = EPROP_BENDRADIUS,                                        ///< (1D BEND) Bend radius at centroid
        STRESS_RECOVERY_LOCATION_C = EPROP_SRC,                                ///< (1D) xz locations for stress data recovery (rz for BEND) [2]
        STRESS_RECOVERY_LOCATION_D = EPROP_SRD,                                ///< (1D) xz locations for stress data recovery (rz for BEND) [2]
        STRESS_RECOVERY_LOCATION_E = EPROP_SRE,                                ///< (1D) xz locations for stress data recovery (rz for BEND) [2]
        STRESS_RECOVERY_LOCATION_F = EPROP_SRF,                                ///< (1D) xz locations for stress data recovery (rz for BEND) [2]
        INITIAL_GAP = EPROP_UZERO,                                             ///< Initial gap
        PRELOAD_FORCE = EPROP_FZERO,                                           ///< Preload force
        COMPRESSION_STIFFNESS = EPROP_KCLOSE,                                  ///< Compression stiffness
        TENSION_STIFFNESS = EPROP_KOPEN,                                       ///< Tension stiffness
        TRANSVERSE_STIFFNESS = EPROP_KTRANS,                                   ///< Transverse stiffness
        STATIC_FRICTION_COEFFICIENT_Y_AXIS = EPROP_MUSY,                       ///< mu: static friction coefficient. mu1 in y-dir if anisotropic: Gap or Cpair
        STATIC_FRICTION_COEFFICIENT_Z_AXIS = EPROP_MUSZ,                       ///< mu2 static friction coefficient in z-dir for anisotropic: Gap
        STATIC_ISOTROPIC_FRICTION_COEFFICIENT = EPROP_MU_ISO,                  ///< For isotropic friction, identical to EPROP_MUSY
        STATIC_ORTHOTROPIC_FRICTION_COEFFICIENT_1 = EPROP_MU1_ORTHO,           ///< For orthotropic friction, 1st parameter, identical to EPROP_MUSY
        STATIC_ORTHOTROPIC_FRICTION_COEFFICIENT_2 = EPROP_MU2_ORTHO,           ///< For orthotropic friction, 2nd parameter, identical to EPROP_MUSZ
        KINETIC_FRICTION_COEFFICIENT_Y_AXIS = EPROP_MUKY,                      ///< kinetic friction coefficient in y-dir: Gap
        KINETIC_FRICTION_COEFFICIENT_Z_AXIS = EPROP_MUKZ,                      ///< kinetic friction coefficient in z-dir: Gap
        STIFFNESS = EPROP_STIFF,                                               ///< Stiffness
        VISCOUS_DAMPING_COEFFICIENT = EPROP_DAMP,                              ///< Viscous damping coefficient
        MASS = EPROP_MASS,                                                     ///< Mass (mx,my,mz) [3]
        OFFSET_VECTOR = EPROP_OFFSETVEC,                                       ///< Offset vector global (x,y,z) [3]
        MOMENTS_OF_INERTIA = EPROP_INERTIA,                                    ///< Mass moments of inertia [6]
        MASS_MASTRIX = EPROP_MASSMATRIX,                                       ///< Mass matrix [21]
        STIFFNESS_MATRIX = EPROP_STIFFMATRIX,                                  ///< Stiffness matrix [21]
        PENALTY_FACTOR = EPROP_PENALTY,                                        ///< Penalty factor
        FILM_COEFFICIENT = EPROP_FILM,                                         ///< Film coefficient
        CONVECTION_EXPONENT = EPROP_CONVEXP,                                   ///< Convection exponent
        HEAT_EXCHANGE_AREA_FACTOR = EPROP_AREAFACT,                            ///< Convection or Radiation Area factor [2]
        STRESS_COEFFICIENT = EPROP_STRSCOEF,                                   ///<
        STIFFNESS_TRANSLATIONAL = EPROP_STIFFTRA,                              ///< Stiffness translation [3]
        STIFFNESS_ROTATIONAL = EPROP_STIFFROT,                                 ///< Stiffness rotation [3]
        DAMPING_TRANSLATIONAL = EPROP_DAMPTRA,                                 ///< Convection exponent [3]
        DAMPING_ROTATIONAL = EPROP_DAMPROT,                                    ///< Viscous damping rotation [3]
        STRESS_RECOVERY_TRANSLATIONAL = EPROP_STRSCOEFTRA,                     ///< Stress recovery coefficient translation
        SR_COEFFICIENT_ROTATION = EPROP_STRSCOEFROT,                           ///< Stress recovery coefficient rotation
        STRAIN_RECOVERY_TRANSLATIONAL = EPROP_STRNCOEFTRA,                     ///< Strain recovery coefficient translation
        STRAIN_RECOVERY_ROTATIONAL = EPROP_STRNCOEFROT,                        ///< Strain recovery coefficient rotation
        BEAM_SECTION_DIMENSIONS = EPROP_BEAMDIME,                              ///< Beam section dimensions [2]
        DOF_WEIGHTING_FACTORS = EPROP_DOFFLAG_WGTS,                            ///< Weighting factors [DOF_FLAGS_COUNT]
        SHELL_MATRIX = EPROP_SHELLMATRIX,                                      ///< Shell wall matrix
        SHELL_ALPHA = EPROP_SHELLALPHA,                                        ///< Shell wall alpha
        Q_MATRIX = EPROP_QMATRIX,                                              ///< Transverse shear matrix
        Q_ALPHA = EPROP_QALPHA,                                                ///< Transverse shear alpha
        BEAM_MATRIX = EPROP_BEAMMATRIX,                                        ///< Beam section matrix
        BEAM_ALPHA = EPROP_BEAMALPHA,                                          ///< Beam section alpha
        LAYER_THICKNESS = EPROP_LAYER_THK,                                     ///< Layer thickness [SHELL_LAYERS_COUNT]
        LAYER_MATERIAL_ORIENTATION_ANGLE = EPROP_LAYER_PHI,                    ///< Layer material orientation [SHELL_LAYERS_COUNT]
        ECCENTRICITY = EPROP_ECC,                                              ///< Eccentricity
        BEAM_ROTATION_ANGLE = EPROP_BEAMROTANGLE,                              ///< Beam section rotation angle
        RIGID_ELEMENT_ALPHA = EPROP_RIGIDALPHA,                                ///< Rigid element alpha
        BEAM_SECTION_POINTS = EPROP_BEAMPNTS,                                  ///< Beam section points [BEAM_SECTION_POINTS_COUNT][2]
        BEAM_SECTION_SEGMENT_THICKNESS = EPROP_BEAMSEGS_THICK,                 ///< Beam section segment thicknesses [BEAM_SECTION_SEGMENT_COUNT]
        BEAM_SECTION_SEGMENT_POINTS = EPROP_BEAMSEGS_PNTS,                     ///< Beam section segment points(y, z) [BEAM_SECTION_SEGMENT_COUNT][2]
        EMISSIVITY = EPROP_EMIS,                                               ///< Emissivity
        STRUCTURAL_DAMPING_COEFFICIENT = EPROP_SDAMP,                          ///< Structural damping coefficient [3]
        STRUCTURAL_DAMPING_TRANSLATION = EPROP_SDAMPTRA,                       ///< Structural damping translation [3]
        STRUCTURAL_DAMPING_ROTATION = EPROP_SDAMPROT,                          ///< Structural damping rotation [3]
        NSM_VALUES = EPROP_NSM_VAL,                                            ///< Nonstructural mass values [NSM_COUNT]
        ARC_ELEMENT_ANGLE = EPROP_BEND_THETA,                                  ///< Bend Arc element angle
        BEND_INTERNAL_PRESSURE = EPROP_BEND_INTERNALPRESSURE,                  ///< Bend internal pressure
        BEND_OFFSET_LOCAL_R = EPROP_BEND_RCOFFSET,                             ///< Bend local r offset EndA/EndB points
        BEND_OFFSET_LOCAL_Z = EPROP_BEND_ZCOFFSET,                             ///< Bend local z offset EndA/EndB points
        BEND_OFFSET_R = EPROP_BEND_ROFFSET,                                    ///< Bend radial offset of neutral axis
        BEND_MEAN_RADIUS = EPROP_BEND_RADIUSMEAN,                              ///< Bend Mean cross section radius
        COHESIVE_LAYER_RELATIVE_LOCATION = EPROP_COHESIVE_LAYER,               ///< Relative location of the cohesive layer
        GASKET_THICKNESS = EPROP_GASKET_THICKNESS,                             ///< Element Gasket thickness
        GALERKIN_DILATION_PARAMETERS = EPROP_GALERKIN_DILATION_PARAMETERS,     ///< Galerkin dilation parameters of the kernel function [3]
        GALERKIN_DEFORMATION_TOLERANCE = EPROP_GALERKIN_DEFORMATION_TOLERANCE, ///< Galerkin deformation tolerance triggering EFG adaptation
        GALERKIN_CRITICAL_BOND_FAILURE = EPROP_GALERKIN_CRITICAL_BOND_FAILURE, ///< Galerkin critical value for bond failure triggering
        GALERKIN_CRITICAL_STRETCH =
        EPROP_GALERKIN_CRITICAL_STRETCH, ///< Galerkin critical relative deformation (stretching or compression ratio) between the two nodes forming the bond for bond failure
        GALERKIN_SHEAR_LOCKING_FACTOR = EPROP_GALERKIN_SHEAR_LOCKING_FACTOR,       ///< Galerkin quadrature factor for surface nodes to suppress shear locking in thin structures
        GALERKIN_PARTICLE_DAMPING = EPROP_GALERKIN_PARTICLE_DAMPING,               ///< Galerkin particle-to-particle damping coefficient
        GALERKIN_LAGRANGIAN_EULERIAN_SWITCH_TIME = EPROP_GALERKIN_SWITCH_TIME_LTE, ///< Galerkin time to switch from updated Lagrangian kernel to Eulerian kernel
        GALERKIN_LENGTH_SCALE = EPROP_GALERKIN_LENGTH_SCALE,                       ///< Galerkin length scale for displacement regularization
        DAMPING_TENSION_COMPRESSION = EPROP_VISCOUS_DAMP_TC,                       ///< Viscous damping coefficients in tension/compression [2]
        DAMPING_EXPONENT_TENSION_COMPRESSION = EPROP_VISCOUS_EXPNT_TC,             ///< Viscous damping exponents in tension/compression [2]
        REINFORCEMENT_SECTION_AREA = EPROP_REINFSECT_AREA,                         ///< Reinforcement section cross-section area  [REINFORCEMENT_SECTION_MEMBER_COUNT]
        REINFORCEMENT_INTERFIBER_DISTANCE = EPROP_REINFSECT_FIBER_DISTANCE,        ///< Reinforcement section inter-fiber distance
        REINFORCEMENT_SECTION_ANGLE = EPROP_REINFSECT_THETA ///< Reinforcement section angle with respect to the default reinforcement system [REINFORCEMENT_SECTION_MEMBER_COUNT]
    };

    /// \brief Element friction type
    enum class FrictionType {
        NO_FRICTION = EPROP_FRICTION_NOFRICTION,            ///< No friction
        BILINEAR_COULOMB = EPROP_FRICTION_BILINEAR_COULOMB, ///< Bilinear Coulomb friction
        BILINEAR_SHEAR = EPROP_FRICTION_BILINEAR_SHEAR      ///< Bilinear Shear friction
    };

    /// \brief Reinforcement section types
    enum class ReinforcementType {
        REINFSECT_SMEAR = SYS_REINFSECT_SMEAR ///< Smeared reinforcement
    };

    /// \brief Reinforcement sections location types
    enum class ReinforcementLocationType {
        REINFSECT_LOCATION_NOTYPE = SYS_REINFSECT_LOCATION_NOTYPE,      ///< Default for unsupported reinforcement section location type
        REINFSECT_LOCATION_TYPE_MESH = SYS_REINFSECT_LOCATION_TYPE_MESH ///< Mesh-based definition
    };

    ErrorCode getErrorCode();
    Status    define(ElementType elementType);
    Status    inquire(ElementType *elementType);
    Status    setPropertyDoubleValue(DoubleProperty type, double value);
    Status    setPropertyDoubleArray(DoubleProperty type, double values[]);
    Status    setPropertyId(DoubleProperty type, int id);
    Status    unsetProperty(IntegerProperty type);
    Status    unsetProperty(DoubleProperty type);
    Status    getPropertyCount(int *count);
    Status    getPropertyFlag(IntegerProperty type, PropertyFlag *flag);
    Status    getPropertyFlag(DoubleProperty type, PropertyFlag *flag);
    Status    getPropertyId(DoubleProperty type, int *id);
    Status    getPropertyInformation(IntegerProperty type, int *componentCount, int *locationCount);
    Status    getPropertyInformation(DoubleProperty type, int *componentCount, int *locationCount);
    Status    getPropertyName(IntegerProperty type, char name[]);
    Status    getPropertyName(DoubleProperty type, char name[]);
    Status    getPropertyDoubleValue(DoubleProperty type, double values[]);
    Status    setId(int id);
    Status    getId(int *id);
    Status    setName(const char *name);
    Status    getName(char name[]);
    Status    evaluateAtElementNodes(DoubleProperty type, ElementShape shape, int maxi, int maxj, double values[]);
    Status    copy(ElementProperty *from);
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
