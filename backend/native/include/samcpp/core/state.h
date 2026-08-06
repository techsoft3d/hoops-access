#pragma once

#include "samcpp/core/base_types.h"
#include "samcpp/core/coredefs.h"
#include "samcpp/core/pimpl.h"
#include "samcpp/core/pointer.h"
#include "samcpp/core/status.h"

#include <memory>

ACCESSOR_DECL

namespace cae::core {

class State {
  public:
    PIMPL_MOVE_ONLY(State)

    /// Operation type
    enum class Operation {
        EQUAL = STATE_EQUAL,                  ///< Operation =
        PLUS_EQUAL = STATE_PLUSEQUAL,         ///< Operation +=
        MINUS_EQUAL = STATE_MINUSEQUAL,       ///< Operation -=
        MULTIPLY_EQUAL = STATE_MULTIPLYEQUAL, ///< Operation *=
        DIVIDE_EQUAL = STATE_DIVIDEEQUAL      ///< Operation /=
    };

    /// System state type
    enum class System {
        GLOBAL = STATE_GLOBAL,          ///< Global
        LOCAL_UNDEFORMED = STATE_LOCAL, ///< Local undeformed
        LOCAL_DEFORMED = STATE_ROTANG,  ///< Local deformed
        MATERIAL = STATE_MATERIAL       ///< Material system
    };

    /// Unary function type
    enum class UnaryFunction {
        IDENTITY = STATE_IDENTITY,     ///< Identity function
        SIN = STATE_SIN,               ///< Sine function
        COS = STATE_COS,               ///< Cosine function
        TAN = STATE_TAN,               ///< Tangent function
        ASIN = STATE_ASIN,             ///< Arcsine function
        ACOS = STATE_ACOS,             ///< Arccosine function
        ATAN = STATE_ATAN,             ///< Arctangent function
        SQRT = STATE_SQRT,             ///< Square root function
        LOG = STATE_LOG,               ///< Natural logarithm function
        EXP = STATE_EXP,               ///< Exponential function
        ABS = STATE_ABS,               ///< Absolute value function
        RECIPROCAL = STATE_RECIPROCAL, ///< Reciprocal function
        UNITY = STATE_UNITY            ///< Value of 1.
    };

    /// Binary function type
    enum class BinaryFunction {
        MIN = STATE_MIN,         ///< Minimum function
        MAX = STATE_MAX,         ///< Maximum function
        AVERAGE = STATE_AVERAGE, ///< Average function
        CROSS = STATE_CROSS,     ///< Vector cross product function
        DOT = STATE_DOT,         ///< Vector dot product function
        SUM = STATE_SUM          ///< Sum function
    };

    /// Differential operation type
    enum class DifferentialOperation {
        GRADIENT = STATE_GRAD,                ///< Gradient function
        GRADIENT_NORMALIZED = STATE_GRADNORM, ///< Normalized Gradient function
        DIVERGENCE = STATE_DIV,               ///< Divergence function
        CURL = STATE_CURL,                    ///< Curl function
        STRAIN = STATE_STRAIN,                ///< Infinitesimal strain function
        VECTOR_GRADIENT = STATE_VECTORGRAD    ///< Vector gradient function
    };

    /// Group operation type
    enum class GroupOperation {
        EXTENT = STATE_EXTENT,           ///< Elements lying within an interval
        DEFINED = STATE_DEFINED,         ///< Elements with defined data
        NONZERO = STATE_NONZERO,         ///< Elements with non zero value
        OUTBOUND = STATE_OUTBOUND,       ///< Elements lying outside an interval
        LOCAL_MIN = STATE_LOCALMIN,      ///< Elements with local minimum
        LOCAL_MAX = STATE_LOCALMAX,      ///< Elements with local maximum
        LOCAL_MINMAX = STATE_LOCALMINMAX ///< Elements with local min or max
    };

    /// Integer parameter types
    enum class IntegerParameter {
        MAPPING_ELEMENT = STATE_MAPELEM,              ///< Select element mapping type
        MAPPING_NODE = STATE_MAPNODE,                 ///< Select node mapping type
        MAPPING_DEFINED = STATE_MAPDEFINED,           ///< Enable mapping defined entities only
        MAPPING_NONZERO = STATE_MAPNONZERO,           ///< Enable mapping nonzero contributions
        MIDSIDE = STATE_MIDSIDE,                      ///< Select midside node processing
        SORT_DESCENDING = STATE_SORTHIGHLOW,          ///< Enable high to low sort
        SORT_ABSOLUTE_VALUE = STATE_SORTABSVALUE,     ///< Enable absolute value sort
        SORT_ELEMENT_AVERAGE = STATE_SORTELEMNODEAVE, ///< Enable element-average sorting
        EXTENT_IGNORE_ZERO = STATE_EXTENTNONZERO,     ///< Ignore zero-valued entities in extent
        LIST_WIDTH = STATE_LISTWIDTH                  ///< Listing field width
    };

    /// Element mapping parameter types
    enum class ElementMappingParameter {
        AVERAGE = STATE_MAPAVE,             ///< Average to element
        MINIMUM = STATE_MAPMIN,             ///< Minimum to element
        MAXIMUM = STATE_MAPMAX,             ///< Maximum to element
        ABSOLUTE_MINIMUM = STATE_MAPABSMIN, ///< Absolute minimum to element
        ABSOLUTE_MAXIMUM = STATE_MAPABSMAX, ///< Absolute maximum to element
        CENTROIDAL = STATE_MAPCENT          ///< Centroidal value to element
    };

    /// Node mapping parameter types
    enum class NodeMappingParameter {
        AVERAGE = STATE_NODE_MAPAVE,             ///< Average to node
        GEOMETRY = STATE_MAPGEOM,                ///< Geometry weighted average to node
        MINIMUM = STATE_NODE_MAPMIN,             ///< Minimum to node
        MAXIMUM = STATE_NODE_MAPMAX,             ///< Maximum to node
        ABSOLUTE_MINIMUM = STATE_NODE_MAPABSMIN, ///< Absolute minimum to node
        ABSOLUTE_MAXIMUM = STATE_NODE_MAPABSMAX, ///< Absolute maximum to node
        DIFF_TO_NODE = STATE_MAPDIFF             ///< Difference to node
    };

    /// Midside node processing parameter types
    enum class MidsideParameter {
        MIDSIDE_AVERAGE = STATE_MIDSIDEAVE, ///< Average midside node values
        MIDSIDE_CLAMP = STATE_MIDSIDECLAMP  ///< Clamp midside node values
    };

    /// Derived quantity types
    enum class DerivedType {
        VECTOR_X = VIS_VECTOR_X,                                  ///< Vector x component
        VECTOR_Y = VIS_VECTOR_Y,                                  ///< Vector y component
        VECTOR_Z = VIS_VECTOR_Z,                                  ///< Vector z component
        VECTOR_MAGNITUDE = VIS_VECTOR_MAG,                        ///< Vector magnitude
        VECTOR = VIS_VECTOR_VECTOR,                               ///< Vector
        SIX_DOF = VIS_SIXDOF_SIXDOF,                              ///< Six dof vector
        SIX_DOF_TX = VIS_SIXDOF_TX,                               ///< Six dof x translational component
        SIX_DOF_TY = VIS_SIXDOF_TY,                               ///< Six dof y translational component
        SIX_DOF_TZ = VIS_SIXDOF_TZ,                               ///< Six dof z translational component
        SIX_DOF_RX = VIS_SIXDOF_RX,                               ///< Six dof x rotational component
        SIX_DOF_RY = VIS_SIXDOF_RY,                               ///< Six dof y rotational component
        SIX_DOF_RZ = VIS_SIXDOF_RZ,                               ///< Six dof z rotational component
        SIX_DOF_TRANSLATIONAL_MAGNITUDE = VIS_SIXDOF_TMAG,        ///< Six dof translation magnitude
        SIX_DOF_ROTATIONAL_MAGNITUDE = VIS_SIXDOF_RMAG,           ///< Six dof rotation magnitude
        SIX_DOF_TRANSLATION_VECTOR = VIS_SIXDOF_TVEC,             ///< Six dof translation vector
        SIX_DOF_ROTATION_VECTOR = VIS_SIXDOF_RVEC,                ///< Six dof rotation vector
        TENSOR_XX = VIS_TENSOR_XX,                                ///< Tensor xx component
        TENSOR_YY = VIS_TENSOR_YY,                                ///< Tensor yy component
        TENSOR_ZZ = VIS_TENSOR_ZZ,                                ///< Tensor zz component
        TENSOR_XY = VIS_TENSOR_XY,                                ///< Tensor xy component
        TENSOR_YZ = VIS_TENSOR_YZ,                                ///< Tensor yz component
        TENSOR_ZX = VIS_TENSOR_ZX,                                ///< Tensor zx component
        TENSOR_MEAN = VIS_TENSOR_MEAN,                            ///< Tensor mean
        TENSOR_VONMISES_STRESS = VIS_TENSOR_VONMISES,             ///< Tensor Von Mises stress
        TENSOR_VONMISES_STRAIN = VIS_TENSOR_VONMISES_E,           ///< Tensor Von Mises strain
        TENSOR_OCTAHEDRAL = VIS_TENSOR_OCTAHEDRAL,                ///< Tensor octahedral shear
        TENSOR_DETERMINANT = VIS_TENSOR_DETERMINANT,              ///< Tensor determinant
        TENSOR_INTENSITY = VIS_TENSOR_INTENSITY,                  ///< Tensor intensity
        TENSOR_SHEAR_ANGLE = VIS_TENSOR_ANGSHEAR,                 ///< Tensor max shear angle in degrees
        TENSOR_MAXSHEAR = VIS_TENSOR_MAXSHEAR,                    ///< Tensor max shear
        TENSOR_EQUAL_DIRECT = VIS_TENSOR_EQUDIRECT,               ///< Tensor equal direct at max shear
        TENSOR_MIN_PRINCIPAL = VIS_TENSOR_MINPRINC,               ///< Tensor minimum principal value
        TENSOR_MID_PRINCIPAL = VIS_TENSOR_MIDPRINC,               ///< Tensor middle principal value
        TENSOR_MAX_PRINCIPAL = VIS_TENSOR_MAXPRINC,               ///< Tensor maximum principal value
        TENSOR_MIN_PRINCIPAL_DEVIATORIC = VIS_TENSOR_MINPRINCDEV, ///< Tensor minimum principal deviatoric value
        TENSOR_MID_PRINCIPAL_DEVIATORIC = VIS_TENSOR_MIDPRINCDEV, ///< Tensor middle principal deviatoric value
        TENSOR_MAX_PRINCIPAL_DEVIATORIC = VIS_TENSOR_MAXPRINCDEV, ///< Tensor maximum principal deviatoric value
        TENSOR_PRINCIPAL_VALUES = VIS_TENSOR_PRINC,               ///< Tensor principal values
        TENSOR_PRINCIPAL_DIRECTIONS = VIS_TENSOR_PRINCDIRCOS,     ///< Tensor principal directions
        TENSOR = VIS_TENSOR_TENSOR,                               ///< Tensor
        GENERALTENSOR = VIS_GENERALTENSOR_GENERALTENSOR,          ///< General tensor
        TENSOR_GENERAL_XX = VIS_GENERALTENSOR_XX,                 ///< General tensor xx component
        TENSOR_GENERAL_XY = VIS_GENERALTENSOR_XY,                 ///< General tensor xy component
        TENSOR_GENERAL_XZ = VIS_GENERALTENSOR_XZ,                 ///< General tensor xz component
        TENSOR_GENERAL_YX = VIS_GENERALTENSOR_YX,                 ///< General tensor yx component
        TENSOR_GENERAL_YY = VIS_GENERALTENSOR_YY,                 ///< General tensor yy component
        TENSOR_GENERAL_YZ = VIS_GENERALTENSOR_YZ,                 ///< General tensor yz component
        TENSOR_GENERAL_ZX = VIS_GENERALTENSOR_ZX,                 ///< General tensor zx component
        TENSOR_GENERAL_ZY = VIS_GENERALTENSOR_ZY,                 ///< General tensor zy component
        TENSOR_GENERAL_ZZ = VIS_GENERALTENSOR_ZZ,                 ///< General tensor zz component
        TENSOR_GENERAL_SYMMETRIZED = VIS_GENERALTENSOR_SYM,       ///< General tensor symmetrized tensor
        TENSOR_GENERAL_FIRST_ROW = VIS_GENERALTENSOR_XVEC,        ///< General tensor first row vector
        TENSOR_GENERAL_SECOND_ROW = VIS_GENERALTENSOR_YVEC,       ///< General tensor second row vector
        TENSOR_GENERAL_THIRD_ROW = VIS_GENERALTENSOR_ZVEC,        ///< General tensor third row vector
        SHELL_NXX = VIS_ELEMRES_SHELL_NXX,                        ///< Shell Nxx component
        SHELL_NYY = VIS_ELEMRES_SHELL_NYY,                        ///< Shell Nyy component
        SHELL_NXY = VIS_ELEMRES_SHELL_NXY,                        ///< Shell Nxy component
        SHELL_MXX = VIS_ELEMRES_SHELL_MXX,                        ///< Shell Mxx component
        SHELL_MYY = VIS_ELEMRES_SHELL_MYY,                        ///< Shell Myy component
        SHELL_MXY = VIS_ELEMRES_SHELL_MXY,                        ///< Shell Mxy component
        SHELL_QXZ = VIS_ELEMRES_SHELL_QXZ,                        ///< Shell Qxz component
        SHELL_QYZ = VIS_ELEMRES_SHELL_QYZ,                        ///< Shell Qyz component
        BEAM_NXX = VIS_ELEMRES_BEAM_NXX,                          ///< Beam Nxx component
        BEAM_MYY = VIS_ELEMRES_BEAM_MYY,                          ///< Beam Myy component
        BEAM_MZZ = VIS_ELEMRES_BEAM_MZZ,                          ///< Beam Mzz component
        BEAM_T = VIS_ELEMRES_BEAM_T,                              ///< Beam Torque component
        BEAM_QXY = VIS_ELEMRES_BEAM_QXY,                          ///< Beam Qxy component
        BEAM_QZX = VIS_ELEMRES_BEAM_QZX,                          ///< Beam Qzx component
        BEAM_TB = VIS_ELEMRES_BEAM_TB,                            ///< Beam Bimoment component
        SPRINGDASHPOT_F = VIS_ELEMRES_SPRINGDASHPOT_F,            ///< SpringDashpot Force component
        SPRINGDASHPOT_FX = VIS_ELEMRES_SPRINGDASHPOT_FX,          ///< SpringDashpot Force X component
        SPRINGDASHPOT_FY = VIS_ELEMRES_SPRINGDASHPOT_FY,          ///< SpringDashpot Force Y component
        SPRINGDASHPOT_FZ = VIS_ELEMRES_SPRINGDASHPOT_FZ,          ///< SpringDashpot Force Z component
        SPRINGDASHPOT_MX = VIS_ELEMRES_SPRINGDASHPOT_MX,          ///< SpringDashpot Moment X component
        SPRINGDASHPOT_MY = VIS_ELEMRES_SPRINGDASHPOT_MY,          ///< SpringDashpot Moment Y component
        SPRINGDASHPOT_MZ = VIS_ELEMRES_SPRINGDASHPOT_MZ,          ///< SpringDashpot Moment Z component
        SCALAR = VIS_SCALARS_SCALAR,                              ///< Scalar
        SCALARS_0 = VIS_SCALARS_0,                                ///< Zeroth scalar
        SCALARS_1 = VIS_SCALARS_1,                                ///< First scalar
        SCALARS_2 = VIS_SCALARS_2,                                ///< Second scalar
        SCALARS_3 = VIS_SCALARS_3,                                ///< Third scalar
        SCALARS_4 = VIS_SCALARS_4,                                ///< Fourth scalar
        SCALARS_5 = VIS_SCALARS_5,                                ///< Fifth scalar
        SCALARS_6 = VIS_SCALARS_6,                                ///< Sixth scalar
        SCALARS_7 = VIS_SCALARS_7,                                ///< Seventh scalar
        SCALARS_8 = VIS_SCALARS_8,                                ///< Eighth scalar
        SCALARS_9 = VIS_SCALARS_9,                                ///< Ninth scalar
        SCALARS_10 = VIS_SCALARS_10,                              ///< Tenth scalar
        SCALARS_11 = VIS_SCALARS_11,                              ///< Eleventh scalar
        SCALARS_12 = VIS_SCALARS_12,                              ///< Twelfth scalar
    };

    /// Demonstration types
    enum class DemonstrationType {
        BEAM = STATE_DEMO_BEAM,   ///< Create beam bending displacements
        PLATE = STATE_DEMO_PLATE, ///< Create plate bending displacements
    };

    ErrorCode getErrorCode();
    Status    setPrecision(Precision precisionType);
    Status    getPrecision(Precision *precisionType);
    Status    setMeshInterface(MeshInterface *functions);
    Status    getMeshInterface(MeshInterfacePtr &functions);
    Status    setLocalCoordinateSystemIds(IdTranslator *localCoordinateSystemIds);
    Status    getLocalCoordinateSystemIds(IdTranslatorPtr &localCoordinateSystemIds);
    Status    setLocalCoordinateSystemDirectionCosines(State *localCoordinateSystemDirectionCosines);
    Status    getLocalCoordinateSystemDirectionCosines(StatePtr &localCoordinateSystemDirectionCosines);
    Status    setRotationAngleVectors(State *rotationAngleVectors);
    Status    getRotationAngleVectors(StatePtr &rotationAngleVectors);
    Status    setCoordinateSystems(HashTable<CoordinateSystem> *coordinateSystems);
    Status    getCoordinateSystems(HashTablePtr<CoordinateSystem> &coordinateSystems);
    Status    setElementData(HashTable<ElementData> *elementData);
    Status    getElementData(HashTablePtr<ElementData> &elementData);

    template <auto IntegerParameterEnumerator, typename ValueType>
    Status setIntegerParameter(ValueType value);

    Status setComplexMode(ComplexMode mode);
    Status getComplexMode(ComplexMode *mode);
    Status isComplex(int *flag);
    Status define(int entityCount, EntityType entityType, EntityType subentityType, DataLayout layout);
    Status inquire(int *entityCount, EntityType *entityType, EntityType *subentityType, DataLayout *layout);
    Status setEngineeringStrainFlag(int flag);
    Status getEngineeringStrainFlag(int *flag);
    Status setMagnitudePhaseFlag(int flag);
    Status getMagnitudePhaseFlag(int *flag);
    Status clear();
    Status getDefinedDataCount(int *count);
    Status getStatus(int entityCount, int entityIndices[], int status[]);
    Status getStatusAtElementEntity(int elementId, int elementEntityNumber, int *status);
    Status setElementEntities(int elementId, int elementEntityCount, int entityIndices[]);
    Status getElementEntities(int elementId, int *elementEntityCount, int entityIndices[]);
    Status setSectionCount(int entityIndex, int sectionCount);
    Status getSectionCount(int entityCount, int entityIndices[], int sectionCounts[]);
    Status isSectionDefined(int *flag);
    Status setSectionLayerPositionType(int index, LayerPosition layerPosition);
    Status getSectionLayerPositionType(int entityCount, int indices[], LayerPosition layerPositions[]);
    Status setLayerInformation(int index, LayerPosition layerPositions[], int layerNumbers[]);
    Status getLayerInformation(int index, LayerPosition layerPositions[], int layerNumbers[]);
    Status clearDataAtEntity(int index);
    Status setDataAtElementEntity(int elementId, int elementEntityNumber, float data[]);
    Status setDataAtElementEntity(int elementId, int elementEntityNumber, double data[]);
    Status setDataAtEntity(int index, float data[]);
    Status setDataAtEntity(int index, double data[]);
    Status setDerivedQuantity(DerivedType type);
    Status getDerivedQuantity(DerivedType *type);
    Status getDerivedQuantityComponentCount(int *count);
    Status getPrimitiveDerivedQuantity(DataLayout *layout);
    Status setSection(int section);
    Status getSection(int *section);
    Status setCoordinateSystem(System system);
    Status getCoordinateSystem(System *system);
    Status setCoordinateSystemEntityType(EntityType type);
    Status getCoordinateSystemEntityType(EntityType *type);
    Status transformToCoordinateSystem(System system, Group *group);
    Status convertStrainData(StrainType type);
    Status convertComplexData(ComplexMode complexType);
    Status demonstrate(DemonstrationType operation, float factor, Group *group);
    Status deformState(float factor, State *displacements, Group *group);
    Status getData(int entityCount, int indices[], float data[]);
    Status getData(int entityCount, int indices[], double data[]);
    Status getDataAtElement(int elementId, float data[]);
    Status getDataAtElement(int elementId, double data[]);
    Status getDataAtElementEntity(EntityType type, int elementId, int elementEntityNumber, float data[]);
    Status getDataAtElementEntity(EntityType type, int elementId, int elementEntityNumber, double data[]);
    Status getDataAtElementNaturalCoordinates(int elementId, float naturalCoordinates[], float data[]);
    Status getDataAtElementNaturalCoordinates(int elementId, double naturalCoordinates[], double data[]);
    Status getDataAtEntities(int entityCount, int indices[], double data[]);
    Status getDataCountAtEntity(int index, int *totalDataCount, int *locationCount, int *sectionCount);
    Status getMaxDataCount(int *totalDataCount, int *locationCount, int *sectionCount);
    Status getLocalDirectionCosineMatrices(int index, float cosineMatricesArray[][3][3]);
    Status getExtent(Group *group, float extent[]);
    Status getExtentWithLocation(Group *group, float extent[], int indices[], int elementEntityNumbers[]);
    Status getExtentWithLocationAndSection(Group *group, float extent[], int indices[], int elementEntityNumbers[], int sections[]);
    Status computeSum(Group *group, double sum[]);
    Status map(State *source, Group *group);
    Status processMidSideNodes(Group *group);
    Status mapToElementNode(State *source, Group *group, IdTranslator *elementRegionNumber);
    Status operateUnary(Operation operation, float factor, UnaryFunction function, State *statex, Group *group);
    Status operateUnary(Operation operation, double factor, UnaryFunction function, State *statex, Group *group);
    Status operateBinary(Operation operation, float factor, BinaryFunction function, State *statex, State *statey, Group *group);
    Status operateBinary(Operation operation, double factor, BinaryFunction function, State *statex, State *statey, Group *group);
    Status derivative(Operation operation, float factor, DifferentialOperation function, State *statex, Group *group);
    Status setGroupParameter(GroupOperation type, float param[]);
    Status generateSortedEntities(Group *group, IdTranslator *sortedEntities);
    Status generateElementGroup(GroupOperation operation, Group *group, Group *generatedGroup);
    Status generateNodeGroup(GroupOperation operation, Group *group, Group *generatedGroup);
    Status copy(State *source);
    Status getCoordinateSystemIdAtEntity(int index, int *coordinateSystemId);

  private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // namespace cae::core
