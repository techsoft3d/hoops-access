#pragma once

#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"

namespace cae::core {

/// \brief Maximum name length
/// \hideinitializer
constexpr static size_t MAX_NAME_LENGTH = SYS_MAXNAME;

/// \brief Maximum identifier name length
/// \hideinitializer
constexpr static size_t MAX_IDENTIFIER_NAME_LENGTH = SYS_MAXNAMECHAR;

/// \brief Maximum I dimension
/// \hideinitializer
constexpr static size_t MAX_I = VIS_MAX_MAXI;

/// \brief Maximum J dimension
/// \hideinitializer
constexpr static size_t MAX_J = VIS_MAX_MAXJ;

/// \brief Maximum K dimension
/// \hideinitializer
constexpr static size_t MAX_K = VIS_MAX_MAXK;

/// Precision type
enum class Precision {
    SINGLE = SYS_FLOAT, ///< Single precision
    DOUBLE = SYS_DOUBLE ///< Double precision
};

/// Activation type
enum Flag : int {
    ON = SYS_ON,  ///< Enabled
    OFF = SYS_OFF ///< Disabled
};

/// Data type
enum class DataType {
    NO_DATATYPE = SYS_NODATATYPE,       ///< No data type
    INTEGER = SYS_INTEGER,              ///< Integer
    REAL = SYS_REAL,                    ///< Floating point, real part, double precision
    FLOAT = SYS_FLOAT,                  ///< Floating point single precision
    CHAR = SYS_CHAR,                    ///< Character
    DOUBLE = SYS_DOUBLE,                ///< Floating point double precision
    COMPLEX = SYS_COMPLEX,              ///< Complex number, single precision
    DOUBLE_COMPLEX = SYS_DOUBLECOMPLEX, ///< Complex number, double precision
    LONG = SYS_LONG                     ///< Long integer
};

/// Data layout type
enum class DataLayout {
    NONE = SYS_DATATYPE_NONE,             ///< No data layout
    SCALAR = SYS_SCALAR,                  ///< Scalar
    VECTOR = SYS_VECTOR,                  ///< Vector
    TENSOR_SYMMETRIC = SYS_TENSOR,        ///< Symmetric tensor
    TENSOR_GENERAL = SYS_GENERALTENSOR,   ///< General tensor
    SIX_DOF = SYS_SIXDOF,                 ///< Six degrees of freedom
    MATRIX_DIAGONAL = SYS_MATRIX_DIAG,    ///< Diagonal matrix
    MATRIX_SYMMETRIC = SYS_MATRIX_SYMM,   ///< Symmetric matrix
    MATRIX_UNSYMMETRIC = SYS_MATRIX_USYMM ///< Unsymmetric matrix
};

/// Complex data mode
enum class ComplexMode {
    NONE = SYS_COMPLEX_NONE,                     ///< No complex mode
    REAL = SYS_COMPLEX_REAL,                     ///< Real part only
    MAGNITUDE = SYS_COMPLEX_MAGNITUDE,           ///< Magnitude only
    IMAGINARY = SYS_COMPLEX_IMAGINARY,           ///< Imaginary part only
    PHASE = SYS_COMPLEX_PHASE,                   ///< Phase only
    REAL_IMAGINARY = SYS_COMPLEX_REALIMAGINARY,  ///< Real and imaginary parts
    MAGNITUDE_PHASE = SYS_COMPLEX_MAGNITUDEPHASE ///< Magnitude and phase
};

/// Entity type
enum class EntityType {
    NONE = SYS_NONE,                ///< No entity type specified
    NODE = SYS_NODE,                ///< Node entity
    ELEMENT = SYS_ELEM,             ///< Element entity
    FACE = SYS_FACE,                ///< Face entity
    EDGE = SYS_EDGE,                ///< Edge entity
    INTEGRATION_POINT = SYS_INTPNT, ///< Integration point entity
    PARTICLE = SYS_PARTICLE,        ///< Particle entity
    DOF = SYS_DOF,                  ///< Degree of freedom entity
    MODE = SYS_MODE,                ///< Mode entity
    ANALYTIC_SURF = SYS_ASURF       ///< Analytic surface entity
};

/// Coordinate system type
enum class CoordinateSystemType {
    CARTESIAN = SYS_CARTESIAN,                   ///< Cartesian
    CYLINDRICAL = SYS_CYLINDRICAL,               ///< Cylindrical
    CYLINDRICAL_ALTERNATE = SYS_CYLINDRICAL_ALT, ///< Cylindrical alternate
    SPHERICAL = SYS_SPHERICAL,                   ///< Spherical
    SPHERICAL_ALTERNATE = SYS_SPHERICAL_ALT,     ///< Spherical alternate
    TOROIDAL = SYS_TOROIDAL                      ///< Toroidal
};

/// Node type
enum class NodeType {
    UNDEFINED = VIS_NODE_UNDEFINED, ///< Undefined
    GRID = VIS_NODE_GRID,           ///< Grid node
    SCALAR = VIS_NODE_SCALAR        ///< Scalar node
};

/// Element technology
enum class ElementTechnology {
    UNDEFINED = SYS_TECH_UNDEFINNED,      ///< Undefined or unknown technology
    ISOPARAMETRIC = SYS_TECH_ISOP,        ///< Isoparametric formulation
    REDUCED = SYS_TECH_URED,              ///< Reduced integration
    KIRCHHOFF = SYS_TECH_KIRCHHOFF,       ///< Kirchhoff theory (thin shell/plate)
    MIXED = SYS_TECH_MIXED,               ///< Mixed formulation
    ENHANCED = SYS_TECH_ENHANCED,         ///< Enhanced strain formulation
    ASSUMED_NATURAL_STRAIN = SYS_TECH_ANS ///< Assumed natural strain (ANS) formulation
};

/// Element type, the subset of ElementType with more specific types is defined in \enumtype{SpecificType}
enum class ElementType {
    UNDEFINED = VIS_ELEM_UNDEFINED,          ///< Undefined
    SOLID = VIS_ELEM_SOLID,                  ///< Solid
    SHELL = VIS_ELEM_SHELL,                  ///< Shell
    MEMBRANE = VIS_ELEM_MEMBRANE,            ///< Membrane
    BEAM = VIS_ELEM_BEAM,                    ///< Beam
    TRUSS = VIS_ELEM_TRUSS,                  ///< Truss
    INFINITE_DOMAIN = VIS_ELEM_INFINITE,     ///< Infinite
    GAP = VIS_ELEM_GAP,                      ///< Gap
    JOINT = VIS_ELEM_JOINT,                  ///< Joint
    SPRING_DASHPOT = VIS_ELEM_SPRINGDASHPOT, ///< Spring and dashpot
    RIGID = VIS_ELEM_RIGID,                  ///< Rigid
    CONSTRAINT = VIS_ELEM_CONSTRAINT,        ///< Constraint
    PLOT = VIS_ELEM_PLOT,                    ///< Plot
    MASS = VIS_ELEM_MASS,                    ///< Mass
    INTER = VIS_ELEM_INTER,                  ///< Interface
    SUPER = VIS_ELEM_SUPER,                  ///< Superelement
    REINFORCEMENT = VIS_ELEM_REINFORCEMENT   ///< Reinforcement
};

/// Subset of \enumtype{ElementType} with more specific types
enum class SpecificType {
    SOLID_SOLID = SYS_SOLID_SOLID,                                     ///< Solid (as opposed to fluid) region  \enumref{ElementType::SOLID}
    SOLID_FLUID = SYS_SOLID_FLUID,                                     ///< Fluid region  \enumref{ElementType::SOLID}
    SOLID_SHELL = SYS_SOLID_SHELL,                                     ///< Continuum shell  \enumref{ElementType::SOLID}
    MEMBRANE_STANDARD = SYS_MEMBRANE_STAN,                             ///< Plane stress membrane  \enumref{ElementType::MEMBRANE}
    MEMBRANE_SHEAR = SYS_MEMBRANE_SHEAR,                               ///< Shear panel  \enumref{ElementType::MEMBRANE}
    MEMBRANE_FACE = SYS_MEMBRANE_FACE,                                 ///< Geometry face facet  \enumref{ElementType::MEMBRANE}
    BEAM_STANDARD = SYS_BEAM_STAN,                                     ///< Standard beam  \enumref{ElementType::BEAM}
    BEAM_ROD = SYS_BEAM_ROD,                                           ///< Axial force and torque  \enumref{ElementType::BEAM}
    BEAM_WELD = SYS_BEAM_WELD,                                         ///< Weld beam  \enumref{ElementType::BEAM}
    BEAM_CBEND = SYS_BEAM_CBEND,                                       ///< Curved beam or pipe  \enumref{ElementType::BEAM}
    TRUSS_STANDARD = SYS_TRUSS_STAN,                                   ///< Standard truss  \enumref{ElementType::TRUSS}
    TRUSS_EDGE = SYS_TRUSS_EDGE,                                       ///< Geometry edge segment  \enumref{ElementType::TRUSS}
    SPRINGDASHPOT_SCALAR = SYS_SPRINGDASHPOT_SCALAR,                   ///< Scalar stiffness and damping  \enumref{ElementType::SPRING_DASHPOT}
    SPRINGDASHPOT_LINK = SYS_SPRINGDASHPOT_LINK,                       ///< Link  \enumref{ElementType::SPRING_DASHPOT}
    SPRINGDASHPOT_WELD = SYS_SPRINGDASHPOT_WELD,                       ///< Weld  \enumref{ElementType::SPRING_DASHPOT}
    SPRINGDASHPOT_BUSH = SYS_SPRINGDASHPOT_BUSH,                       ///< Bushing  \enumref{ElementType::SPRING_DASHPOT}
    SPRINGDASHPOT_SCALARDAMP = SYS_SPRINGDASHPOT_SCALARDAMP,           ///< Scalar damping  \enumref{ElementType::SPRING_DASHPOT}
    SPRINGDASHPOT_LINKDAMP = SYS_SPRINGDASHPOT_LINKDAMP,               ///< Vector stiffness and damping  \enumref{ElementType::SPRING_DASHPOT}
    SPRINGDASHPOT_VECTOR = SYS_SPRINGDASHPOT_VECTOR,                   ///< Damper  \enumref{ElementType::SPRING_DASHPOT}
    SPRINGDASHPOT_SEATBELT = SYS_SPRINGDASHPOT_SEATBELT,               ///< Seat belt  \enumref{ElementType::SPRING_DASHPOT}
    SPRINGDASHPOT_TORSION = SYS_SPRINGDASHPOT_TORSION,                 ///< Spring-damper  \enumref{ElementType::SPRING_DASHPOT}
    MASS_SCALAR = SYS_MASS_SCALAR,                                     ///< Scalar  \enumref{ElementType::MASS}
    MASS_LUMP = SYS_MASS_LUMP,                                         ///< Lumped  \enumref{ElementType::MASS}
    MASS_MATRIX = SYS_MASS_MATRIX,                                     ///< Matrix  \enumref{ElementType::MASS}
    MASS_VECTOR = SYS_MASS_VECTOR,                                     ///< Vector  \enumref{ElementType::MASS}
    MASS_VERTEX = SYS_MASS_VERTEX,                                     ///< Geometry vertex point  \enumref{ElementType::MASS}
    RIGID_KINE = SYS_RIGID_KINE,                                       ///< Kinematic coupling  \enumref{ElementType::RIGID}
    RIGID_DIST = SYS_RIGID_DIST,                                       ///< Distributing coupling  \enumref{ElementType::RIGID}
    RIGID_LINK = SYS_RIGID_LINK,                                       ///< Inextensional coupling  \enumref{ElementType::RIGID}
    RIGID_MPC = SYS_RIGID_MPC,                                         ///< Multi-point constraint  \enumref{ElementType::RIGID}
    RIGID_RBE3 = SYS_RIGID_RBE3,                                       ///< Interpolation constraint  \enumref{ElementType::RIGID}
    RIGID_SPLINE = SYS_RIGID_SPLINE,                                   ///< Spline constraint  \enumref{ElementType::RIGID}
    RIGID_JOINT = SYS_RIGID_JOINT,                                     ///< Coincident node joint  \enumref{ElementType::RIGID}
    CONSTRAINT_NONE = SYS_CONSTRAINT_NONE,                             ///< No constraint  \enumref{ElementType::CONSTRAINT}
    CONSTRAINT_MEAN = SYS_CONSTRAINT_MEAN,                             ///< Mean constraint  \enumref{ElementType::CONSTRAINT}
    PLOT_LOD0 = SYS_PLOT_LOD0,                                         ///< Plot level of details 0  \enumref{ElementType::PLOT}
    PLOT_LOD1 = SYS_PLOT_LOD1,                                         ///< Plot level of details 1  \enumref{ElementType::PLOT}
    PLOT_LOD2 = SYS_PLOT_LOD2,                                         ///< Plot level of details 2  \enumref{ElementType::PLOT}
    PLOT_LOD3 = SYS_PLOT_LOD3,                                         ///< Plot level of details 3  \enumref{ElementType::PLOT}
    PLOT_AERO = SYS_PLOT_AERO,                                         ///< Plot aeroelastic  \enumref{ElementType::PLOT}
    INTER_NONE = SYS_INTER_NONE,                                       ///< No known specific type  \enumref{ElementType::INTER}
    INTER_CONTACT = SYS_INTER_CONTACT,                                 ///< Contact  \enumref{ElementType::INTER}
    INTER_INTERIOR = SYS_INTER_INTERIOR,                               ///< Interior  \enumref{ElementType::INTER}
    INTER_WALL = SYS_INTER_WALL,                                       ///< Wall  \enumref{ElementType::INTER}
    INTER_INLET_PRESSURE = SYS_INTER_INLET_PRESSURE,                   ///< Pressure inlet  \enumref{ElementType::INTER}
    INTER_OUTLET_PRESSURE = SYS_INTER_OUTLET_PRESSURE,                 ///< Pressure outlet  \enumref{ElementType::INTER}
    INTER_SURFACE = SYS_INTER_SURF,                                    ///< Surface  \enumref{ElementType::INTER}
    INTER_SYMMETRY = SYS_INTER_SYMMETRY,                               ///< Symmetry  \enumref{ElementType::INTER}
    INTER_PERIODIC_SHADOW = SYS_INTER_PERIODIC_SHADOW,                 ///< Periodic shadow  \enumref{ElementType::INTER}
    INTER_PRESSURE_FARFIELD = SYS_INTER_PRESSURE_FARFIELD,             ///< Pressure farfield  \enumref{ElementType::INTER}
    INTER_INLET_VELOCITY = SYS_INTER_INLET_VELOCITY,                   ///< Velocity inlet  \enumref{ElementType::INTER}
    INTER_PERIODIC = SYS_INTER_PERIODIC,                               ///< Periodic  \enumref{ElementType::INTER}
    INTER_FAN = SYS_INTER_FAN,                                         ///< Fan  \enumref{ElementType::INTER}
    INTER_INLET_MASSFLOW = SYS_INTER_INLET_MASSFLOW,                   ///< Mass flow inlet  \enumref{ElementType::INTER}
    INTER_INTERFACE = SYS_INTER_INTERFACE,                             ///< Interface  \enumref{ElementType::INTER}
    INTER_PARENT = SYS_INTER_PARENT,                                   ///< Parent  \enumref{ElementType::INTER}
    INTER_OUTFLOW = SYS_INTER_OUTFLOW,                                 ///< Outflow  \enumref{ElementType::INTER}
    INTER_AXIS = SYS_INTER_AXIS,                                       ///< Axis  \enumref{ElementType::INTER}
    INTER_USER_DEFINED = SYS_INTER_USER_DEFINED,                       ///< User defined  \enumref{ElementType::INTER}
    INTER_DEGENERATE_LINE = SYS_INTER_DEGENERATE_LINE,                 ///< Degenerate line  \enumref{ElementType::INTER}
    INTER_DIRICHLET = SYS_INTER_DIRICHLET,                             ///< Dirichlet  \enumref{ElementType::INTER}
    INTER_FARFIELD = SYS_INTER_FARFIELD,                               ///< Far field  \enumref{ElementType::INTER}
    INTER_NEUMANN = SYS_INTER_NEUMANN,                                 ///< Neumann  \enumref{ElementType::INTER}
    INTER_GENERAL = SYS_INTER_GENERAL,                                 ///< General  \enumref{ElementType::INTER}
    INTER_INFLOW_SUBSONIC = SYS_INTER_INFLOW_SUBSONIC,                 ///< Inflow subsonic  \enumref{ElementType::INTER}
    INTER_OUTFLOW_SUBSONIC = SYS_INTER_OUTFLOW_SUBSONIC,               ///< Outflow subsonic  \enumref{ElementType::INTER}
    INTER_INFLOW_SUPERSONIC = SYS_INTER_INFLOW_SUPERSONIC,             ///< Inflow supersonic  \enumref{ElementType::INTER}
    INTER_OUTFLOW_SUPERSONIC = SYS_INTER_OUTFLOW_SUPERSONIC,           ///< Outflow supersonic  \enumref{ElementType::INTER}
    INTER_TUNNEL_INFLOW = SYS_INTER_TUNNEL_INFLOW,                     ///< Tunnel inflow  \enumref{ElementType::INTER}
    INTER_SYMMETRY_POLAR = SYS_INTER_SYMMETRY_POLAR,                   ///< Polar symmetry  \enumref{ElementType::INTER}
    INTER_TUNNEL_OUTFLOW = SYS_INTER_TUNNEL_OUTFLOW,                   ///< Tunnel outflow  \enumref{ElementType::INTER}
    INTER_WALL_VISCOUS = SYS_INTER_WALL_VISCOUS,                       ///< Wall viscous  \enumref{ElementType::INTER}
    INTER_WALL_VISCOUS_HEAT_FLUX = SYS_INTER_WALL_VISCOUS_HEAT_FLUX,   ///< Wall viscous with heat flux  \enumref{ElementType::INTER}
    INTER_WALL_VISCOUS_ISOTHERMAL = SYS_INTER_WALL_VISCOUS_ISOTHERMAL, ///< Wall viscous with isothermal  \enumref{ElementType::INTER}
    INTER_WALL_INVISCID = SYS_INTER_WALL_INVISCID,                     ///< Wall inviscid  \enumref{ElementType::INTER}
    INTER_DEGENERATE_POINT = SYS_INTER_DEGENERATE_POINT,               ///< Degenerate point  \enumref{ElementType::INTER}
    INTER_EXTRAPOLATE = SYS_INTER_EXTRAPOLATE,                         ///< Extrapolate  \enumref{ElementType::INTER}
    INTER_SURF_ENVIRONMENT = SYS_INTER_SURF_ENVIRONMENT,               ///< Surface with environment surface  \enumref{ElementType::INTER}
    INTER_STAGNATION = SYS_INTER_STAGNATION,                           ///< Stagnation  \enumref{ElementType::INTER}
    INTER_PRESSURE = SYS_INTER_PRESSURE,                               ///< Pressure  \enumref{ElementType::INTER}
    INTER_BAFFLE = SYS_INTER_BAFFLE,                                   ///< Baffle  \enumref{ElementType::INTER}
    INTER_FREESTREAM = SYS_INTER_FREESTREAM,                           ///< Free stream  \enumref{ElementType::INTER}
    INTER_GASKET = SYS_INTER_GASKET,                                   ///< Gasket  \enumref{ElementType::INTER}
    INTER_COHESIVE = SYS_INTER_COHESIVE,                               ///< Cohesive  \enumref{ElementType::INTER}
    INTER_PATCH = SYS_INTER_PATCH,                                     ///< Patch  \enumref{ElementType::INTER}
    INTER_OPENING = SYS_INTER_OPENING,                                 ///< Opening  \enumref{ElementType::INTER}
    INTER_INLET = SYS_INTER_INLET,                                     ///< Inlet  \enumref{ElementType::INTER}
    INTER_OUTLET = SYS_INTER_OUTLET                                    ///< Outlet  \enumref{ElementType::INTER}
};

///  Node Association type
enum class NodeAssociationType {
    NODE_TYPE = VIS_NODE_FEATYPE,                     ///< Node type \enumtype{NodeType}
    PART_ID = VIS_NODE_PARTID,                        ///< Part identifier
    COORDINATE_SYSTEM_ID = VIS_NODE_CSYSID,           ///< Solution coordinate system identifier or \enumtype{ElementCoordinateSystemConvention}
    IBLANK = VIS_NODE_IBLANK,                         ///< Iblank code
    SPC_FLAGS = VIS_NODE_SPCFLAGS,                    ///< Node single point constraint flags
    REFERENCE_COORDINATE_SYSTEM_ID = VIS_NODE_CREFID, ///< Reference coordinate system identifier
    USER_ID = VIS_NODE_USERID,                        ///< User defined identifier
    MISCELLANEOUS_ID0 = VIS_NODE_MISCID0,             ///< Miscellaneous identifier 0
    MISCELLANEOUS_ID1 = VIS_NODE_MISCID1,             ///< Miscellaneous identifier 1
    MISCELLANEOUS_ID2 = VIS_NODE_MISCID2,             ///< Miscellaneous identifier 2
    MISCELLANEOUS_ID3 = VIS_NODE_MISCID3,             ///< Miscellaneous identifier 3
    MISCELLANEOUS_ID4 = VIS_NODE_MISCID4,             ///< Miscellaneous identifier 4
    MISCELLANEOUS_ID5 = VIS_NODE_MISCID5,             ///< Miscellaneous identifier 5
    MISCELLANEOUS_ID6 = VIS_NODE_MISCID6,             ///< Miscellaneous identifier 6
    MISCELLANEOUS_ID7 = VIS_NODE_MISCID7,             ///< Miscellaneous identifier 7
    MISCELLANEOUS_ID8 = VIS_NODE_MISCID8,             ///< Miscellaneous identifier 8
};

///  Element Association type
enum class ElementAssociationType {
    ELEMENT_TYPE = VIS_FEATYPE,                     ///< Element type \enumtype{ElementType}
    MATERIAL_ID = VIS_MATLID,                       ///< Material identifier
    PROPERTY_ID = VIS_PROPID,                       ///< Property identifier
    PART_ID = VIS_PARTID,                           ///< Part identifier
    COORDINATE_SYSTEM_ID = VIS_CSYSID,              ///< Solution coordinate system identifier or \enumtype{ElementCoordinateSystemConvention}
    IBLANK = VIS_IBLANK,                            ///< Iblank code
    EXTERNAL_ELEMENT_TYPE = VIS_EXTTYPE,            ///< External element type
    USER_ID = VIS_USERID,                           ///< User defined identifier
    ELEMENT_TECHNOLOGY = VIS_FEATECH,               ///< Element technology \enumtype{ElementTechnology}
    ELEMENT_SPECIFIC_TYPE = VIS_FEASPEC,            ///< Element specific type \enumtype{SpecificType}
    MATERIAL_COORDINATE_SYSTEM_ID = VIS_CMATID,     ///< Material coordinate system identifier or \enumtype{ElementCoordinateSystemConvention}
    MATERIAL_COORDINATE_SYSTEM_FLAG = VIS_CMATFLAG, ///< Material coordinate system flag
    MISCELLANEOUS_ID0 = VIS_MISCID0,                ///< Miscellaneous identifier 0
    MISCELLANEOUS_ID1 = VIS_MISCID1,                ///< Miscellaneous identifier 1
    MISCELLANEOUS_ID2 = VIS_MISCID2,                ///< Miscellaneous identifier 2
    MISCELLANEOUS_ID3 = VIS_MISCID3,                ///< Miscellaneous identifier 3
    MISCELLANEOUS_ID4 = VIS_MISCID4,                ///< Miscellaneous identifier 4
    MISCELLANEOUS_ID5 = VIS_MISCID5,                ///< Miscellaneous identifier 5
    MISCELLANEOUS_ID6 = VIS_MISCID6,                ///< Miscellaneous identifier 6
    MISCELLANEOUS_ID7 = VIS_MISCID7,                ///< Miscellaneous identifier 7
    MISCELLANEOUS_ID8 = VIS_MISCID8,                ///< Miscellaneous identifier 8
    ELEMENT_TYPE_2D = VIS_FEATWOD,                  ///< Element two dimension type
    ELEMENT_END_A_TOPOLOGY = VIS_ENDATOPO,          ///< Element end A topology
    ELEMENT_END_B_TOPOLOGY = VIS_ENDBTOPO,          ///< Element end B topology
    ELEMENT_END_A_CONNECTION = VIS_ENDACON,         ///< Element end A connection
    ELEMENT_END_B_CONNECTION = VIS_ENDBCON,         ///< Element end B connection
    ORIENTATION_NODE_INDEX = VIS_ORIENTINDEX,       ///< Orientation node index
    GEOMETRY_VERTEX_ID = VIS_GEOVERT,               ///< Geometry vertex identifier
    GEOMETRY_EDGE_ID = VIS_GEOEDGE,                 ///< Geometry edge identifier
    GEOMETRY_FACE_ID = VIS_GEOFACE,                 ///< Geometry face identifier
    GEOMETRY_BODY_ID = VIS_GEOBODY,                 ///< Geometry body identifier
    ELEMENT_PIN_FLAGS = VIS_PINFLAGS, ///< Element pin flags. A bit is set to release a degree of freedom associated with the end points of beam elements. The first 6 bits reference the translations
                                      ///< and rotations at the first endpoint, the second 6 bits reference the second endpoint
    DOMAIN_REGION = VIS_DOMAIN,       ///< Domain decomposition region identifier
    SUPERELEMENT_ID = VIS_SEID,       ///< Superelement identifier
    SYMMETRY_GROUP_ID = VIS_SYMMID,   ///< Symmetry group identifier
    UNIQUE_FACE_NUMBER = VIS_POLYUNIQUEFACE ///< Unique face number for polyhedral elements
};

enum class ElementEndType {
    ELEMENT_END_NONE = SYS_ELEMEND_NONE,         ///< No element end
    ELEMENT_END_POSITION = SYS_ELEMEND_POSITION, ///< Element end position vector
    ELEMENT_END_OFFSET = SYS_ELEMEND_OFFSET      ///< Element end offset vector
};

///  Element shape
enum class ElementShape {
    UNDEFINED = VIS_SHAPEUNDEFINED, ///< Undefined
    POINT = VIS_SHAPEPOINT,         ///< Point
    LINE = VIS_SHAPELINE,           ///< Line
    TRIANGLE = VIS_SHAPETRI,        ///< Triangle
    QUADRILATERAL = VIS_SHAPEQUAD,  ///< Quadrilateral
    TETRAHEDRON = VIS_SHAPETET,     ///< Tetrahedron
    PYRAMID = VIS_SHAPEPYR,         ///< Pyramid
    WEDGE = VIS_SHAPEWED,           ///< Wedge
    HEXAHEDRON = VIS_SHAPEHEX,      ///< Hexahedron
    POLYGON = VIS_SHAPEPOLYGON,     ///< Polygon
    POLYHEDRON = VIS_SHAPEPOLYHED   ///< Polyhedron
};

///  Result section
enum ResultSection : int {
    NONE = SYS_ELEMSEC_NONE,  ///< None
    BOTTOM = SYS_ELEMSEC_BOT, ///< Bottom
    TOP = SYS_ELEMSEC_TOP,    ///< Top
    MIDDLE = SYS_ELEMSEC_MID, ///< Midsurface
    ALL = SYS_ELEMSEC_ALL     ///< All sections
};

///  Layer position
enum class LayerPosition : int {
    NONE = SYS_LAYERPOSITION_NONE,                   ///< None, unknown
    MIDDLE = SYS_LAYERPOSITION_MID,                  ///< Middle
    BOTTOM_TOP = SYS_LAYERPOSITION_BOTTOP,           ///< Bottom and top
    BOTTOM_MIDDLE_TOP = SYS_LAYERPOSITION_BOTMIDTOP, ///< Bottom, middle and top
    INTEGRATION_POINT = SYS_LAYERPOSITION_INTPNT,    ///< Integration Point
    BOTTOM_MIDDLE = SYS_LAYERPOSITION_BOTMID,        ///< Bottom and middle
    MIDDLE_TOP = SYS_LAYERPOSITION_MIDTOP,           ///< Middle and top
    BOTTOM = SYS_LAYERPOSITION_BOT,                  ///< Bottom
    TOP = SYS_LAYERPOSITION_TOP                      ///< Top
};

///  Strain type
enum class StrainType {
    TENSOR = SYS_STRAINTYPE_TENSOR,          ///< Tensor strain
    ENGINEERING = SYS_STRAINTYPE_ENGINEERING ///< Engineering strain
};

///  Beam section type
enum class BeamSectionType {
    GENERALIZED_PROPERTIES = SYS_BEAMSECT_PROPS, ///< Generalized section properties
    GEOMETRY = SYS_BEAMSECT_GEOMETRY,            ///< Arbitrary geometry defined by closed loops
    BOX = SYS_BEAMSECT_BOX,                      ///< Hollow box
    ANGLE = SYS_BEAMSECT_ANGLE,                  ///< Angle
    I_BEAM = SYS_BEAMSECT_IBEAM,                 ///< I beam
    CIRCLE = SYS_BEAMSECT_CIRCLE,                ///< Solid circle
    TUBE = SYS_BEAMSECT_TUBE,                    ///< Hollow tube
    PANEL = SYS_BEAMSECT_PANEL,                  ///< Panel
    RECTANGLE = SYS_BEAMSECT_RECTANGLE,          ///< Rectangle
    TRAPEZOID = SYS_BEAMSECT_TRAPEZOID,          ///< Trapezoid
    HEXAGON = SYS_BEAMSECT_HEXAGON,              ///< Hollow hexagon
    TEE = SYS_BEAMSECT_TEE,                      ///< Tee
    ZEE = SYS_BEAMSECT_ZEE,                      ///< Zee
    CHANNEL = SYS_BEAMSECT_CHANNEL,              ///< Channel
    SECTOR = SYS_BEAMSECT_SECTOR,                ///< Solid sector
    ELLIPSE = SYS_BEAMSECT_ELLIPSE,              ///< Solid ellipse
    HAT = SYS_BEAMSECT_HAT,                      ///< Hat
    CROSS = SYS_BEAMSECT_CROSS,                  ///< Cross
    DOUBLE_BOX = SYS_BEAMSECT_DBOX,              ///< Double hollow box
    HAT_WITH_BASE = SYS_BEAMSECT_HAT1,           ///< Hat with base
    QUADRANGLE = SYS_BEAMSECT_QUAD,              ///< Quadrangle
    HAT_GENERALIZED = SYS_BEAMSECT_HATG,         ///< Hat general
    SOLID_HEXAHEDRON = SYS_BEAMSECT_SOLIDHEXA,   ///< Solid hexagon
    SEGMENTS = SYS_BEAMSECT_SEGMENTS             ///< Connected segments
};

///  Shell wall type
enum class ShellWallType {
    MONOCOQUE = SYS_SHELLWALL_MONOCOQUE,          ///< Monocoque
    GENERALIZED_PROPERTIES = SYS_SHELLWALL_PROPS, ///< Generalized properties
    LAMINATE = SYS_SHELLWALL_LAMINATE,            ///< Laminated
    CORRUGATED = SYS_SHELLWALL_CORRUGATED,        ///< Corrugated
    PSHELL = SYS_SHELLWALL_PSHELL,                ///< PSHELL
    MATRIX = SYS_SHELLWALL_MATRIX,                ///< Matrix
    GEOMETRY = SYS_SHELLWALL_GEOMETRY             ///< Geometry defined by closed loops
};

/// Integration rule
enum class IntegrationRule {
    UNKNOWN = SYS_RULE_UNKKNOWN, ///< Unknown integration rule
    GAUSS = SYS_RULE_GAUSS,      ///< Gaussian quadrature
    LOBATTO = SYS_RULE_LOBATTO,  ///< Lobatto's rule
    SIMPSON = SYS_RULE_SIMPSON   ///< Simpson's rule
};

///  Axis
enum class Axis {
    X = SYS_XAXIS, ///< X
    Y = SYS_YAXIS, ///< Y
    Z = SYS_ZAXIS  ///< Z
};

/// Plane
enum class Plane {
    XY = SYS_XYPLANE, ///< XY
    XZ = SYS_XZPLANE, ///< XZ
    YZ = SYS_YZPLANE  ///< YZ
};

/// 2D analysis type
enum class AnalysisType2D {
    PLANESTRAIN = SYS_PLANESTRAIN,         ///< Plane strain
    PLANESTRESS = SYS_PLANESTRESS,         ///< Plane stress
    ASYMMETRIC = SYS_AXISYMMETRIC,         ///< Axisymmetric
    ASYMMETRIC_FOURIER = SYS_AXISYMFOURIER ///< Axisymmetric with Fourier modes
};

/// Heat exchange type
enum class HeatExchangeType {
    CONVECTION_LINEAR = SYS_HEATEXCH_LINEAR,   ///< Convection, q = h*area*areafact*(T-Tamb)
    CONVECTION_EXPONENTIAL = SYS_HEATEXCH_EXP, ///< Convection, q = h*area*areafact*(T-Tamb)**exp
    CONVECTION_POWER = SYS_HEATEXCH_POW,       ///< Convection, q = h*area*areafact*(T**exp-Tamb**exp)
    RADIATION = SYS_HEATEXCH_RAD               ///< Radiation, q = sb*emis*area*areafact*(T**4-Tamb**4)
};

/// Result type
enum class ResultType {
    NONE = SYS_RES_NONE,                                   ///< No result type specified
    POSITION = SYS_RES_X,                                  ///< Position
    DISPLACEMENT = SYS_RES_D,                              ///< Displacement
    EXTERNAL_APPLIED_FORCE = SYS_RES_XF,                   ///< External Applied Force
    REACTION_FORCE = SYS_RES_R,                            ///< Reaction Force
    VELOCITY = SYS_RES_V,                                  ///< Velocity
    ACCELERATION = SYS_RES_A,                              ///< Acceleration
    HEAT_FLUX = SYS_RES_HEAT_FLUX,                         ///< Heat Flux
    VOLTAGE = SYS_RES_VOLT,                                ///< Voltage
    DENSITY = SYS_RES_DENS,                                ///< Density
    VISCOSITY = SYS_RES_VISC,                              ///< Viscosity
    CONDUCTIVITY = SYS_RES_COND,                           ///< Thermal Conductivity
    MACH = SYS_RES_MACH,                                   ///< Mach Number
    STREAM = SYS_RES_STREAM,                               ///< Stream Function
    ENTROPY = SYS_RES_ENTROPY,                             ///< Entropy
    MASS_FLUX = SYS_RES_MASS_FLUX,                         ///< Mass Flux
    TEMPERATURE = SYS_RES_TEMP,                            ///< Temperature
    FILM_COEFFICIENT = SYS_RES_FILM_COEF,                  ///< Film Coefficient
    J = SYS_RES_J,                                         ///< Current
    TF = SYS_RES_TF,                                       ///< Total Residual Force
    PRESSURE = SYS_RES_PRES,                               ///< Pressure
    D_MAT = SYS_RES_D_MAT,                                 ///< Damping Matrix
    ELECTRIC_POTENTIAL = SYS_RES_ELEC_POT,                 ///< Electric Potential
    Q = SYS_RES_Q,                                         ///< Electric Charge
    MAGNETIC_POTENTIAL = SYS_RES_MAG_POT,                  ///< Magnetic Potential
    R_J = SYS_RES_R_J,                                     ///< Reaction Current
    R_Q = SYS_RES_R_Q,                                     ///< Reaction Charge
    MASS_FLOW = SYS_RES_MASS_FLOW,                         ///< Mass Flow
    VOLUME = SYS_RES_VOLUME,                               ///< Volume
    VOLUME_FLUX = SYS_RES_VOLUME_FLUX,                     ///< Volume Flux
    UNKNOWN = SYS_RES_UNKNOWN,                             ///< Unknown
    VELOCITY_DIVERGENCE = SYS_RES_V_DIV,                   ///< Velocity Divergence
    STRAIN = SYS_RES_E,                                    ///< Strain
    INERTIA = SYS_RES_INERTIA,                             ///< Rotary Inertia
    DENSITY_GRADIENT = SYS_RES_DENS_GRAD,                  ///< Density Gradient
    P = SYS_RES_P,                                         ///< Momentum
    TIME = SYS_RES_TIME,                                   ///< Time
    STRESS = SYS_RES_S,                                    ///< Stress
    ID = SYS_RES_ID,                                       ///< Identifier
    VELOCITY_GRADIENT = SYS_RES_V_GRAD,                    ///< Velocity Gradient
    USER = SYS_RES_USER,                                   ///< User Selected Variable
    THICKNESS = SYS_RES_THICKNESS,                         ///< Element Thickness
    STIFFNESS = SYS_RES_STIFF,                             ///< Stiffness
    SCALARS = SYS_RES_SCALARS,                             ///< Scalars
    HEAT_GRADIENT = SYS_RES_HEAT_GRAD,                     ///< Heat Gradient
    THERMAL_ENERGY_ERROR = SYS_RES_TE_ERROR,               ///< Thermal Energy Error
    XF_Q = SYS_RES_XF_Q,                                   ///< External Applied Charge
    ENERGY_DENSITY = SYS_RES_ENERGY_DENSITY,               ///< Energy Density
    SDV = SYS_RES_SDV,                                     ///< Solution Dependent Variable
    VIEW_FACTOR = SYS_RES_VIEW_FACT,                       ///< View Factor
    DAMP = SYS_RES_DAMP,                                   ///< Damping
    FREQUENCY = SYS_RES_FREQ,                              ///< Frequency
    STRAIN_ENERGY_DENSITY = SYS_RES_SE_DENSITY,            ///< Strain Energy Density
    K_MAT = SYS_RES_K_MAT,                                 ///< Stiffness Matrix
    M_MAT = SYS_RES_M_MAT,                                 ///< Mass Matrix
    L_VEC = SYS_RES_L_VEC,                                 ///< Load Vector
    ORDER = SYS_RES_ORDER,                                 ///< Order
    AREA = SYS_RES_AREA,                                   ///< Area
    LENGTH = SYS_RES_LENGTH,                               ///< Length
    RADIUS = SYS_RES_RADIUS,                               ///< Radius
    NUMBER = SYS_RES_NUMBER,                               ///< Number
    KINETIC_ENERGY_DENSITY = SYS_RES_KE_DENSITY,           ///< Kinetic Energy Density
    DAMAGE = SYS_RES_DAMAGE,                               ///< Damage
    DIST = SYS_RES_DIST,                                   ///< Distance
    TEMP_DOT = SYS_RES_TEMP_DOT,                           ///< Temperature 1st Time Derivative
    THERMAL_ENERGY = SYS_RES_TE,                           ///< Thermal Energy
    COND_MAT = SYS_RES_COND_MAT,                           ///< Thermal Conductivity Matrix
    CAP_MAT = SYS_RES_CAP_MAT,                             ///< Capacitance Matrix
    FAILURE_INDEX = SYS_RES_FAIL_INDEX,                    ///< Failure Index
    VOID_RATIO = SYS_RES_VOID_RATIO,                       ///< Void Ratio
    TEMPERATURE_GRADIENT = SYS_RES_TEMP_GRAD,              ///< Temperature Gradient
    PRESSURE_COEFFICIENT = SYS_RES_PRES_COEF,              ///< Pressure Coefficient
    LOAD_FACTOR = SYS_RES_LOAD_FACT,                       ///< Load Factor
    PRESSURE_GRADIENT = SYS_RES_PRES_GRAD,                 ///< Pressure Gradient
    PRESURE_DOT = SYS_RES_PRES_DOT,                        ///< Pressure 1st Time Derivative
    PRESURE_DOTDOT = SYS_RES_PRES_DOTDOT,                  ///< Pressure 2nd Time Derivative
    MASS = SYS_RES_MASS,                                   ///< Mass
    HEAT = SYS_RES_HEAT,                                   ///< Heat Generated
    CRACK_DENSITY = SYS_RES_CRACK_DENSITY,                 ///< Crack Density
    ELECTRIC_FIELD = SYS_RES_ELEC_FIELD,                   ///< Electric Field
    ELECTRIC_FLUX = SYS_RES_ELEC_FLUX,                     ///< Electric Flux
    REACTION_HEAT_FLOW = SYS_RES_R_HEAT_FLOW,              ///< Reaction Heat Flow
    MAGNETIC_FLUX = SYS_RES_MAG_FLUX,                      ///< Magnetic Flux
    MAGNETIC_FIELD = SYS_RES_MAG_FIELD,                    ///< Magnetic Field
    CURRENT_DENSITY = SYS_RES_J_DENSITY,                   ///< Current Density
    TURBULENT_KINETIC_ENERGY = SYS_RES_TURB_KE,            ///< Turbulent Kinetic Energy
    TURBUBENT_EDDY_DISSIPATION = SYS_RES_TURB_ED,          ///< Turbulent Dissipation Rate
    CONCENTRATION = SYS_RES_CONC,                          ///< Concentration
    ENTHALPY = SYS_RES_H,                                  ///< Enthalpy
    CONTACT_PRESSURE = SYS_RES_CP,                         ///< Specific Heat
    POROSITY = SYS_RES_POROSITY,                           ///< Porosity
    H_DOT = SYS_RES_H_DOT,                                 ///< Enthalpy Rate
    FACTOR = SYS_RES_FACTOR,                               ///< Factor
    HEAT_FLOW = SYS_RES_HEAT_FLOW,                         ///< Heat flow
    STRESS_AND_MOMENT_RESULTANT = SYS_RES_SFM,             ///< Stress and Moment Resultant
    STRAIN_AND_CURVATURE = SYS_RES_SEK,                    ///< Strain and Curvature
    WEIGHT = SYS_RES_WEIGHT,                               ///< Weight
    KINETIC_ENERGY = SYS_RES_KE,                           ///< Kinetic Energy
    STRAIN_ENERGY = SYS_RES_SE,                            ///< Strain Energy
    DIRECTION = SYS_RES_DIR,                               ///< Direction Vector
    ENERGY = SYS_RES_ENERGY,                               ///< Energy
    SEPARATION = SYS_RES_SEP,                              ///< Separation
    CLOSURE = SYS_RES_CLOSURE,                             ///< Closure
    STATE = SYS_RES_STATE,                                 ///< %State
    CONTACT_STATUS = SYS_RES_STAT,                         ///< %Status
    R_MASS_FLOW = SYS_RES_R_MASS_FLOW,                     ///< Reaction Mass Flow
    XF_MASS_FLOW = SYS_RES_XF_MASS_FLOW,                   ///< External Applied Mass Flow
    STRAIN_RATE = SYS_RES_E_RATE,                          ///< Strain Rate
    STRAIN_ENERGY_ERROR = SYS_RES_SE_ERROR,                ///< Strain Energy Error
    XF_HEAT_FLOW = SYS_RES_XF_HEAT_FLOW,                   ///< External Applied Heat Flow
    NORMAL_CONTAT_DIRECTION = SYS_RES_DIR_COS,             ///< Direction Cosine Matrix
    ELEMENT_FORCE = SYS_RES_SF,                            ///< Element Force
    ELEMENT_DISPLACEMENT = SYS_RES_SD,                     ///< Element Displacement
    YPLUS = SYS_RES_YPLUS,                                 ///< Y Plus
    FRICTION_VELOCITY = SYS_RES_UTAU,                      ///< U Tau
    STRAIN_ENERGY_PERCENT = SYS_RES_SE_PERCENT,            ///< Strain Energy Percent
    KINETIC_ENERGY_PERCENT = SYS_RES_KE_PERCENT,           ///< Kinetic Energy Percent
    DOM_FLUID_PHASE = SYS_RES_DOM_FLUID_PHASE,             ///< Dominant Fluid Phase
    SOUND_MODEL = SYS_RES_SOUND_MODEL,                     ///< Sound Wave %Model Source
    CONTACT_PENETRATION = SYS_RES_PENE_CONTACT,            ///< Contact Penetration
    SAFE_FACT = SYS_RES_SAFE_FACT,                         ///< Safety Factor
    FATIGUE_DAMAGE = SYS_RES_FAT_DAMAGE,                   ///< Fatigue Damage
    FATIGUE_DAMAGE_DIR = SYS_RES_FAT_DAMAGE_DIR,           ///< Fatigue Damage Direction
    FATIGUE_LIFE = SYS_RES_FAT_LIFE,                       ///< Fatigue Life
    GAP = SYS_RES_GAP,                                     ///< Gap
    GRID_POINT_ELEMENT_FORCE = SYS_RES_EN_FORC,            ///< Element Nodal Force
    EN_FLUX = SYS_RES_EN_FLUX,                             ///< Element Nodal Heat Flux
    STRENGTH_SAFE_FACT = SYS_RES_STRENGTH_SAFE_FACT,       ///< Strength Safety Factor
    FATIGUE_SAFE_FACT = SYS_RES_FAT_SAFE_FACT,             ///< Fatigue Safety Factor
    PHASE_DIAMETER = SYS_RES_PHASE_DIAMETER,               ///< Phase Diameter
    MU_LAMB = SYS_RES_MU_LAMB,                             ///< Laminar Viscosity
    MU_TURB = SYS_RES_MU_TURB,                             ///< Turbulent Viscosity
    BODY_FORCE = SYS_RES_BODY_FORCE,                       ///< Body Force
    WALL_SHEAR = SYS_RES_WALL_SHEAR,                       ///< Wall Shear
    VORTICITY = SYS_RES_VORTICITY,                         ///< Vorticity
    REACTION_PROGRESS = SYS_RES_REACTION_PROGRESS,         ///< Reaction Progress
    SOUND_LEVEL = SYS_RES_SOUND_LEVEL,                     ///< Sound Level
    ROTATION_ANGLES = SYS_RES_ROT_ANG,                     ///< Rotation Angle Vector
    VOLUME_FRACTION = SYS_RES_VOF,                         ///< Volume of Fluid
    EDDY_VISCOSITY = SYS_RES_VISC_EDDY,                    ///< Eddy Viscosity
    ROUGHNESS = SYS_RES_ROUGHNESS,                         ///< Roughness
    FRACTION = SYS_RES_FRACTION,                           ///< Fraction
    CONV_COEF = SYS_RES_CONV_COEF,                         ///< Convection Coefficient
    POWER = SYS_RES_POWER,                                 ///< Power
    INTENSITY = SYS_RES_INTENSITY,                         ///< Intensity
    TRACTION = SYS_RES_TRAC,                               ///< Traction
    XF_J = SYS_RES_XF_J,                                   ///< External Applied Current
    PRANDTL = SYS_RES_PRANDTL,                             ///< Prandtl Number
    TURBULENT_DISTANCE = SYS_RES_TURB_DIST,                ///< Turbulent Distance
    REYNOLDS = SYS_RES_REYNOLDS,                           ///< Reynolds Number
    RADIANCE = SYS_RES_RADIANCE,                           ///< Radiance
    FLUENCE = SYS_RES_FLUENCE,                             ///< Fluence
    RC_PROD = SYS_RES_RC_PROD,                             ///< RC Product
    POWER_DENSITY = SYS_RES_POWER_DENSITY,                 ///< Power Density
    WATER_ACCUM = SYS_RES_WATER_ACCUM,                     ///< Water Accumulation
    TURBULENT_DISSIPATION_RATE = SYS_RES_TURB_SD,          ///< Turbulent Specific Dissipation
    THERMAL_ENERGY_DENSITY = SYS_RES_TE_DENSITY,           ///< Thermal Energy Density
    STRENGTH_RATIO = SYS_RES_STRENGTH_RATIO,               ///< Strength Ratio
    DELETED = SYS_RES_DELETED,                             ///< Deleted Entities
    MARG_SAFE = SYS_RES_MARG_SAFE,                         ///< Margin of Safety
    MOMENT = SYS_RES_MOMENT,                               ///< Moment
    ROTATION = SYS_RES_ROTATION,                           ///< Rotation
    TRANSLATION = SYS_RES_TRANSLATION,                     ///< Translation
    FORCE = SYS_RES_FORCE,                                 ///< Force
    DECIBEL = SYS_RES_DECIBEL,                             ///< Decibel
    PROBABILITY = SYS_RES_PROBABILITY,                     ///< Probability
    FORCE_MOMENT = SYS_RES_FORCE_MOMENT,                   ///< Force Moment
    YOUNGS_MODULUS = SYS_RES_YOUNGS_MODULUS,               ///< Young's Modulus
    POISSONS_RATIO = SYS_RES_POISSONS_RATIO,               ///< Poisson's Ratio
    SHEAR_MODULUS = SYS_RES_SHEAR_MODULUS,                 ///< Shear Modulus
    THERMAL_EXPANSION_COEFFICIENT = SYS_RES_TEXP_COEF,     ///< Thermal Expansion Coefficient
    CHEMICAL_SHRINKAGE = SYS_RES_CHEM_SHRINKAGE,           ///< Chemical Shrinkage
    CONVERSION_TIME = SYS_RES_CONVERSIONTIME,              ///< Conversion Time
    CONVERSION_STATUS = SYS_RES_CONVERSIONSTATUS,          ///< Conversion %Status
    EFFECTIVE_MASS_SUMMARY = SYS_RES_EFFECTIVEMASSSUMMARY, ///< Modal Effective Mass Summary
    EFFECTIVE_MASS = SYS_RES_EFFECTIVEMASS,                ///< Modal Effective Mass
    PARTICIPATION_FACTOR = SYS_RES_PARTICIPATIONFACTOR,    ///< Modal Participation Factor
    MASS_FRACTION = SYS_RES_MASSFRACTION,                  ///< Modal Effective Mass Fraction
    RESIDUAL_MOMENT = SYS_RES_TM,                          ///< Total Residual Moment
    HOURGLASS_ENERGY = SYS_RES_HOURGLASS_ENERGY            ///< Hourglass Energy
};

/// Vendor
enum class Vendor {
    UNKNOWN = SYS_VENDOR_UNKNOWN,                     ///< Unknown or not set
    TECH_SOFT_3D = SYS_VENDOR_VKI,                    ///< Tech Soft 3D
    MSC_NASTRAN = SYS_VENDOR_MSC_NASTRAN,             ///< MSC Nastran
    ANSYS = SYS_VENDOR_ANSYS,                         ///< ANSYS
    ABAQUS = SYS_VENDOR_ABAQUS,                       ///< ABAQUS
    LS_DYNA3D = SYS_VENDOR_LS_DYNA3D,                 ///< LS-DYNA
    ALTAIR_OPTISTRUCT = SYS_VENDOR_ALTAIR_OPTISTRUCT, ///< Altair OptiStruct
    NX_NASTRAN = SYS_VENDOR_NX_NASTRAN,               ///< NX Nastran
    ADINA_NASTRAN = SYS_VENDOR_ADINA_NASTRAN          ///< ADINA Nastran
};

/// \brief Maximum degree of freedom count
/// \hideinitializer
constexpr static size_t MAX_DOF = SYS_DOF_MAX;

/// Degree of freedom type
enum class DofType {
    DOF_NONE = SYS_DOF_NONE, ///< Not defined dof
    DOF_TX = SYS_DOF_TX,     ///< Translation in x direction
    DOF_TY = SYS_DOF_TY,     ///< Translation in y direction
    DOF_TZ = SYS_DOF_TZ,     ///< Translation in z direction
    DOF_RX = SYS_DOF_RX,     ///< Rotation in x direction
    DOF_RY = SYS_DOF_RY,     ///< Rotation in y direction
    DOF_RZ = SYS_DOF_RZ,     ///< Rotation in z direction
    DOF_TEMP = SYS_DOF_TEMP, ///< Temperature
    DOF_VOLT = SYS_DOF_VOLT, ///< Voltage
    DOF_WARP = SYS_DOF_WARP, ///< Warp
    DOF_PRES = SYS_DOF_PRES, ///< Pressure
    DOF_VX = SYS_DOF_VX,     ///< vector component, vx, in the global x direction.
    DOF_VY = SYS_DOF_VY,     ///< vector component, vy, in the global y direction.
    DOF_VZ = SYS_DOF_VZ,     ///< vector component, vz, in the global z direction.
    DOF_ELEM = SYS_DOF_ELEM, ///< Internal elemental freedom
    DOF_LAGM = SYS_DOF_LAGM, ///< Lagrange multiplier freedom
    DOF_S0 = SYS_DOF_S0,     ///< Scalar 0
    DOF_S1 = SYS_DOF_S1,     ///< Scalar 1
    DOF_S2 = SYS_DOF_S2,     ///< Scalar 2
    DOF_S3 = SYS_DOF_S3,     ///< Scalar 3
    DOF_S4 = SYS_DOF_S4,     ///< Scalar 4
    DOF_S5 = SYS_DOF_S5,     ///< Scalar 5
    DOF_S6 = SYS_DOF_S6,     ///< Scalar 6
    DOF_S7 = SYS_DOF_S7,     ///< Scalar 7
    DOF_S8 = SYS_DOF_S8,     ///< Scalar 8
    DOF_S9 = SYS_DOF_S9,     ///< Scalar 9
    DOF_S10 = SYS_DOF_S10,   ///< Scalar 10
    DOF_S11 = SYS_DOF_S11,   ///< Scalar 11
    DOF_S12 = SYS_DOF_S12,   ///< Scalar 12
    DOF_S13 = SYS_DOF_S13,   ///< Scalar 13
    DOF_S14 = SYS_DOF_S14,   ///< Scalar 14
    DOF_S15 = SYS_DOF_S15    ///< Scalar 15
};

/// Library file format
enum class FileFormat {
    NATIVE = SYS_NATIVE,                     ///< Native database
    PLOT3D_GRID = SYS_PLOT3D_GRID,           ///< NASA PLOT3D grid file
    PLOT3D_SOLUTION = SYS_PLOT3D_SOLUTION,   ///< NASA PLOT3D solution/function file
    PATRAN_RESULT = SYS_PATRAN_RESULT,       ///< MSC/Patran result file
    GENERIC = SYS_GENERIC,                   ///< Generic file format
    PDA = SYS_PDA,                           ///< PDA file
    LSTC_STATE = SYS_LSTC_STATE,             ///< LSTC/DYNA3D state database
    ABAQUS_ODB = SYS_ABAQUS_ODB,             ///< ABAQUS .odb output database
    ABAQUS_FIL = SYS_ABAQUS_FIL,             ///< ABAQUS .fil data file
    NASTRAN_OUTPUT2 = SYS_NASTRAN_OUTPUT2,   ///< MSC/NASTRAN OUTPUT2 data file
    STL = SYS_STL,                           ///< STL ASCII text format
    STLBIN = SYS_STLBIN,                     ///< STL binary format
    ABAQUS_INPUT = SYS_ABAQUS_INPUT,         ///< ABAQUS .inp input file
    SDRC_UNIVERSAL = SYS_SDRC_UNIVERSAL,     ///< SDRC universal file
    PAM_DAISY = SYS_PAM_DAISY,               ///< ESI/PAM-CRASH DAISY file
    ANSYS_RESULT = SYS_ANSYS_RESULT,         ///< ANSYS results file
    MECHANICA_STUDY = SYS_MECHANICA_STUDY,   ///< PTC/Mechanica design study
    NASTRAN_BULKDATA = SYS_NASTRAN_BULKDATA, ///< MSC/NASTRAN bulk data file
    FDI_NEUTRAL = SYS_FDI_NEUTRAL,           ///< FIDAP neutral file
    PATRAN_NEUTRAL = SYS_PATRAN_NEUTRAL,     ///< MSC/Patran neutral file
    FLUENT_MESH = SYS_FLUENT_MESH,           ///< FLUENT mesh and data file
    ANSYS_INPUT = SYS_ANSYS_INPUT,           ///< ANSYS input (CDWRITE) file
    TECPLOT = SYS_TECPLOT,                   ///< Tecplot file format
    HYPERMESH_ASCII = SYS_HYPERMESH_ASCII,   ///< Altair HyperMesh ASCII file
    LSTC_INPUT = SYS_LSTC_INPUT,             ///< LSTC/DYNA3D input file
    CGNS = SYS_CGNS,                         ///< CGNS database
    MARC_POST = SYS_MARC_POST,               ///< MSC/Marc post data file
    ENSIGHT = SYS_ENSIGHT,                   ///< CEI/Ensight file format
    STARCCM = SYS_STARCCM,                   ///< STAR-CCM results file
    MECHANICA_FNF = SYS_MECHANICA_FNF,       ///< PTC/Mechanica FEM Neutral File
    LSTC_HISTORY = SYS_LSTC_HISTORY,         ///< LSTC/DYNA3D time history database
    NASTRAN_XDB = SYS_NASTRAN_XDB,           ///< MSC/NASTRAN XDB data file
    NASTRAN_H5 = SYS_NASTRAN_H5,             ///< MSC/NASTRAN .h5 data file
    POLYFLOW = SYS_POLYFLOW,                 ///< POLYFLOW mesh file
    FEMAP_NEUTRAL = SYS_FEMAP_NEUTRAL,       ///< FEMAP neutral file
    AUTODYN_RES = SYS_AUTODYN_RES,           ///< AUTODYN results file
    PAM_ERF = SYS_PAM_ERF,                   ///< ESI/PAM-CRASH ERF file
    OPENFOAM = SYS_OPENFOAM,                 ///< OpenFOAM file
    OBJ = SYS_OBJ,                           ///< OBJ file
    COMSOL_SECTION = SYS_COMSOL_SECTION,     ///< COMSOL Sectionwise file
    H3D = SYS_H3D,                           ///< Altair H3D file
    LSTC_STATEFEMZIP = SYS_LSTC_STATEFEMZIP, ///< LSTC/DYNA3D FEMZIP state database
    PAM_INPUT = SYS_PAM_INPUT,               ///< ESI/PAM-CRASH input file
    CFX_RESULT = SYS_CFX_RESULT,             ///< CFX results file
    GMV = SYS_GMV,                           ///< GMV file
    PERMAS_POST = SYS_PERMAS_POST,           ///< INTES/PERMAS result file
    VTK_LEGACY = SYS_VTK_LEGACY,             ///< VTK legacy file format
    SAMCEF = SYS_SAMCEF,                     ///< SAMCEF des file
    AFLR = SYS_AFLR,                         ///< AFLR grid file
    ADAMS = SYS_ADAMS,                       ///< MSC/Adams
    NATIVE_HDF5 = SYS_NATIVE_HDF5,           ///< Native HDF5 database
    MEMORY = SYS_MEMORY,                     ///< Native memory object
    COMSOL_MPH = SYS_COMSOL_MPH,             ///< COMSOL MPH ASCII file
    COMSOL_MPHBIN = SYS_COMSOL_MPHBIN,       ///< COMSOL MPH binary file
    MARC_INPUT = SYS_MARC_INPUT,             ///< MSC/Marc input file
    ANSYS_DPF = SYS_ANSYS_DPF,               ///< ANSYS Data Processing Framework (DPF)
    PLUGIN = SYS_PLUGIN,                     ///< Plugin format
    VTK_VTU = SYS_VTK_VTU                    ///< VTK VTU file
};

/// Element coordinate system conventions
enum ElementCoordinateSystemConvention : int {
    GLOBAL = SYS_ELEMSYS_GLOBAL,                              ///< Global coordinate system
    STANDARD = SYS_ELEMSYS_STANDARD,                          ///< Standard
    POSITION = SYS_ELEMSYS_POSITION,                          ///< Position
    VECTOR = SYS_ELEMSYS_VECTOR,                              ///< Vector
    VECTOR_ELEMENT_NODE = SYS_ELEMSYS_VECTORELEMNODE,         ///< Element nodes vector
    GLOBAL_PROJECTION = SYS_ELEMSYS_GLOBALPROJECT,            ///< Global projection
    CENTROID = SYS_ELEMSYS_CENTROID,                          ///< Centroid
    BISECTOR = SYS_ELEMSYS_BISECTOR,                          ///< Bisector
    NASTRAN_SHELL = SYS_ELEMSYS_NASTRANSHELL,                 ///< Nastran Shell
    BIDIAGONAL = SYS_ELEMSYS_BIDIAGONAL,                      ///< Bidiagonal
    FIRST_EDGE = SYS_ELEMSYS_FIRSTEDGE,                       ///< First edge
    FIRST_EDGE_ANGLE = SYS_ELEMSYS_FIRSTEDGEANGLE,            ///< First Edge plus angle
    MIDEDGE = SYS_ELEMSYS_MIDEDGE,                            ///< Mid Edge
    MIDPOINT = SYS_ELEMSYS_MIDPOINT,                          ///< Mid Point
    GLOBAL_CLOSEST = SYS_ELEMSYS_GLOBALCLOSEST,               ///< Global Closest
    CYLINDRICAL = SYS_ELEMSYS_CYLINDRICAL,                    ///< Cylindrical system
    CYLINDRICAL_ALTERNATE = SYS_ELEMSYS_CYLINDRICAL_ALT,      ///< Cylindrical system alternate
    SPHERICAL = SYS_ELEMSYS_SPHERICAL,                        ///< Spherical system
    SPHERICAL_ALTERNATE = SYS_ELEMSYS_SPHERICAL_ALT,          ///< Spherical system alternate
    ROTATION_ANGLE = SYS_ELEMSYS_ROTANG,                      ///< Rotation angles
    ROTATION_ANGLE_ELEMENT_NODE = SYS_ELEMSYS_ROTANGELEMNODE, ///< Element nodes rotation angles
    UNKNOWN = SYS_ELEMSYS_UNKNOWN                             ///< Unknown system
};

class AnalyticSurface;
class Mesh;
class InteractionPair;
class CoordinateSystem;
class ElementData;
class ElementProperty;
class GlobalProperty;
class MeshInterface;
class Group;
template <typename T>
class HashTable;
class IdTranslator;
class InitialConditionCase;
class IntHashTable;
class IntVector;
template <typename T>
class List;
class LoadCase;
class MaterialProperty;
class Model;
class MultipointConstraintCase;
template <typename T>
class Pointer;
class RestraintCase;
class ResultMetadata;
class RigidBody;
class SolutionProperty;
class State;
class TableFunction;
class Units;

using AnalyticSurfacePtr = Pointer<AnalyticSurface>;
using MeshPtr = Pointer<Mesh>;
using InteractionPairPtr = Pointer<InteractionPair>;
using CoordinateSystemPtr = Pointer<CoordinateSystem>;
using ElementDataPtr = Pointer<ElementData>;
using ElementPropertyPtr = Pointer<ElementProperty>;
using GlobalPropertyPtr = Pointer<GlobalProperty>;
using MeshInterfacePtr = Pointer<MeshInterface>;
using GroupPtr = Pointer<Group>;
template <typename T>
using HashTablePtr = Pointer<HashTable<T>>;
using IdTranslatorPtr = Pointer<IdTranslator>;
using InitialConditionCasePtr = Pointer<InitialConditionCase>;
using IntHashTablePtr = Pointer<IntHashTable>;
using IntVectorPtr = Pointer<IntVector>;
template <typename T>
using ListPtr = Pointer<List<T>>;
using LoadCasePtr = Pointer<LoadCase>;
using MaterialPropertyPtr = Pointer<MaterialProperty>;
using ModelPtr = Pointer<Model>;
using MultipointConstraintCasePtr = Pointer<MultipointConstraintCase>;
using RestraintCasePtr = Pointer<RestraintCase>;
using ResultMetadataPtr = Pointer<ResultMetadata>;
using RigidBodyPtr = Pointer<RigidBody>;
using SolutionPropertyPtr = Pointer<SolutionProperty>;
using StatePtr = Pointer<State>;
using TableFunctionPtr = Pointer<TableFunction>;
using UnitsPtr = Pointer<Units>;
} // namespace cae::core
