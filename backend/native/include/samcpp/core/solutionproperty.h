#pragma once

#include "sam/vis/spropdefs.h"
#include "samcpp/core/coredefs.h"
#include "samcpp/core/pimpl.h"
#include "samcpp/core/status.h"

#include <memory>

ACCESSOR_DECL

namespace cae::core {

class SolutionProperty {
  public:
    /// \brief Solution type
    enum class SolutionType {
        NONE = SYS_SOL_NONE,                      ///< No solution type
        STATIC = SYS_SOL_STATIC,                  ///< Static or steady state solution (fluid steady state)
        VIBRATION = SYS_SOL_VIBRATION,            ///< Vibration solution
        BUCKLING = SYS_SOL_BUCKLING,              ///< Buckling solution
        TRANSIENT = SYS_SOL_TRANSIENT,            ///< Transient or unsteady solution
        SUPERELEMENT = SYS_SOL_SUPERELEMENT,      ///< Superelement solution
        FREQUENCYRESPONSE = SYS_SOL_FREQRESPONSE, ///< Frequency response solution
        COMPLEXEIGENVALUE = SYS_SOL_COMPLEXEIGEN, ///< Complex eigenvalue solution
        QUASISTATIC = SYS_SOL_QUASISTATIC,        ///< Quasistatic solution
        OUTPUT = SYS_SOL_OUTPUT,                  ///< Compute output given degree of freedom solution
        SINGULARMODES = SYS_SOL_SINGULAR          ///< Singular mode solution
    };

    /// \brief Analysis type
    enum class AnalysisType {
        NONE = SYS_ANALYSIS_NONE,                      ///< No analysis type
        STRUCTURAL = SYS_ANALYSIS_STRUCTURAL,          ///< Structural analysis
        THERMAL = SYS_ANALYSIS_THERMAL,                ///< Thermal analysis
        ELECTRIC = SYS_ANALYSIS_ELECTRIC,              ///< Electric analysis
        MAGNETIC = SYS_ANALYSIS_MAGNETIC,              ///< Magnetic analysis
        FLUID = SYS_ANALYSIS_FLUID,                    ///< Fluid analysis
        ACOUSTIC = SYS_ANALYSIS_ACOUSTIC,              ///< Acoustic analysis
        DIFFUSION = SYS_ANALYSIS_DIFFUSION,            ///< Diffusion analysis
        ELECTROCHEMICAL = SYS_ANALYSIS_ELECTROCHEMICAL ///< Electrochemical analysis
    };

    /// \brief Eigenvalue interval type
    enum class EigenIntervalType {
        NONE = SYS_EIGEN_NONE,      ///< No eigenvalue interval
        ALL = SYS_EIGEN_ALL,        ///< All eigenvalues
        LOWEST = SYS_EIGEN_LOWEST,  ///< Lowest eigenvalues
        NEAREST = SYS_EIGEN_NEAREST ///< Nearest eigenvalues to shift
    };

    /// \brief Eigenvalue solver type
    enum class EigenSolverType {
        SUBSPACE = SYS_EIGEN_SUBSPACE, ///< Subspace iteration solver
        LANCZOS = SYS_EIGEN_LANCZOS,   ///< Lanczos solver
        AMLS = SYS_EIGEN_AMLS          ///< Automatic Multi-Level Substructuring solver
    };

    /// \brief Eigenvalue normalization type
    enum class EigenNormType {
        MASS = SYS_EIGEN_NORMMASS, ///< Mass normalization
        MAX = SYS_EIGEN_NORMMAX    ///< Maximum component normalization
    };

    /// \brief Solution property value flag
    enum class PropertyFlag {
        UNDEFINED = SPROP_UNDEFINED,  ///< Property value is undefined
        VALUE = SPROP_VALUE,          ///< Property is specified by direct value
        IDENTIFIER = SPROP_IDENTIFIER ///< Property is specified by identifier reference
    };

    /// \brief Solution property integer type identifiers
    enum class IntegerProperty {
        ANALYSIS = SPROP_ANALYSIS,                     ///< Analysis type (structural, thermal, etc.)
        CASEID = SPROP_CASEID,                         ///< Case Id
        EIGEN_NUM = SPROP_EIGEN_NUM,                   ///< Number of eigenvalues
        EIGEN_TYPE = SPROP_EIGEN_TYPE,                 ///< Eigenvalue interval type (none, all, lowest, nearest)
        EIGEN_SOLVER = SPROP_EIGEN_SOLVER,             ///< Eigenvalue solver (subspace, Lanczos)
        EIGEN_CASE = SPROP_EIGEN_CASE,                 ///< Eigenvalue case
        LCASE_NUM = SPROP_LCASE_NUM,                   ///< Number of load cases
        LCASE = SPROP_LCASE,                           ///< Load case Id [LCASE_NUM]
        LCASE_SENSORNODE = SPROP_LCASE_SENSORNODE,     ///< Load case sensor node [LCASE_NUM]
        LCASE_SENSORDOF = SPROP_LCASE_SENSORDOF,       ///< Load case sensor node degree of freedom tag [LCASE_NUM]
        EIGEN_NORM = SPROP_EIGEN_NORM,                 ///< Eigenvalue normalization (mass, largest vector component)
        EIGEN_SIZE = SPROP_EIGEN_SIZE,                 ///< Eigenvalue block or subspace size
        EIGEN_STEPS = SPROP_EIGEN_STEPS,               ///< Eigenvalue steps or iterations
        LCASE_TCURVE = SPROP_LCASE_TCURVE,             ///< Load case curve Id
        LCASE_TREF = SPROP_LCASE_TREF,                 ///< Load case temperature reference
        LCASE_MODE = SPROP_LCASE_MODE,                 ///< Include load cases as superelement modes
        LCASE_UNIT = SPROP_LCASE_UNIT,                 ///< Treat load cases as individual unit loads
        LCASE_INITIAL_TEMPERATURE = SPROP_LCASE_TINIT, ///< Id of the initial temperature loading if any
        TIME_STEPFIXED = SPROP_TIME_STEPFIXED,         ///< Time step fixed flag
        RCASE = SPROP_RCASE,                           ///< Restraint case Id
        MCASE = SPROP_MCASE,                           ///< Multipoint constraint case Id
        ICASE = SPROP_ICASE,                           ///< Initial condition case Id
        THERMALSTRAIN = SPROP_THERMALSTRAIN,           ///< Thermal strain flag
        LARGESTRAIN = SPROP_LARGESTRAIN,               ///< Large strain flag
        NONLINEAR = SPROP_NONLINEAR,                   ///< Nonlinear analysis flag
        MASSDIAG = SPROP_MASSDIAG,                     ///< Diagonal mass flag
        INERTIARELIEF = SPROP_INERTIARELIEF,           ///< Inertial relief flag
        PRESTRESS = SPROP_PRESTRESS,                   ///< Prestress flag
        PERTURBATION = SPROP_PERTURBATION,             ///< Perturbation flag
        SAVE_FREQ = SPROP_SAVE_FREQ,                   ///< Save frequency
        RESFILE_FREQ = SPROP_RESFILE_FREQ,             ///< Result file save frequency
        HISTFILE_FREQ = SPROP_HISTFILE_FREQ,           ///< History file save frequency
        COUPLED_NUM = SPROP_COUPLED_NUM,               ///< Number of additional coupled analyses
        COUPLED = SPROP_COUPLED,                       ///< Coupled analysis type [COUPLED_NUM]
        RESFILE_NUM = SPROP_RESFILE_NUM,               ///< Number of result quantities
        RESFILE = SPROP_RESFILE,                       ///< Result types [RESFILE_NUM]
        RESFILE_QUA1 = SPROP_RESFILE_QUA1,             ///< Result file qualifier 1 [RESFILE_NUM]
        RESFILE_QUA2 = SPROP_RESFILE_QUA2,             ///< Result file qualifier 2 [RESFILE_NUM]
        RESFILE_NSET = SPROP_RESFILE_NSET,             ///< Result node set
        RESFILE_ESET = SPROP_RESFILE_ESET,             ///< Result element set
        RESPRINT_NUM = SPROP_RESPRINT_NUM,             ///< Number of printed result quantities
        RESPRINT = SPROP_RESPRINT,                     ///< Printed result types [RESPRINT_NUM]
        RESPRINT_QUA1 = SPROP_RESPRINT_QUA1,           ///< Result print qualifier 1 [RESPRINT_NUM]
        RESPRINT_QUA2 = SPROP_RESPRINT_QUA2,           ///< Result print qualifier 2 [RESPRINT_NUM]
        LHSITER_FREQ = SPROP_LHSITER_FREQ,             ///< Matrix reformation iteration frequency
        LHSSTEP_FREQ = SPROP_LHSSTEP_FREQ,             ///< Matrix reformation step frequency
        LHSFORM = SPROP_LHSFORM,                       ///< Left hand side formation
        ITERMAX = SPROP_ITERMAX,                       ///< Iteration maximum
        ESET_DELETE = SPROP_ESET_DELETE,               ///< Element set of deleted elements
        HISTFILE_NUM = SPROP_HISTFILE_NUM,             ///< Number of history quantities
        HISTFILE = SPROP_HISTFILE,                     ///< History types [HISTFILE_NUM]
        HISTFILE_SET = SPROP_HISTFILE_SET,             ///< History entity sets [HISTFILE_NUM]
        MODALDAMP_TCURVE = SPROP_MODALDAMP_TCURVE,     ///< Modal damping frequency curve Id
        MODALDAMP_TYPE = SPROP_MODALDAMP_TYPE,         ///< Modal damping type (critical fraction, Rayleigh)
        FREQ_TYPE = SPROP_FREQ_TYPE,                   ///< Frequency interval type (range, eigenvalue, random)
        FREQ_NUM = SPROP_FREQ_NUM,                     ///< Number of frequency intervals
        FREQ_NPNTS = SPROP_FREQ_NPNTS,                 ///< Frequency number of points [FREQ_NUM]
        FREQRESPONSE_MODAL = SPROP_FREQRESPONSE_MODAL, ///< Frequency response modal flag
        FOURIER_NUM = SPROP_FOURIER_NUM,               ///< Number of Fourier harmonics
        FOURIER = SPROP_FOURIER,                       ///< Fourier harmonics [FOURIER_NUM]
        NSM_ID = SPROP_NSM_ID,                         ///< Non-structural mass Id
        MAX_INCREMENT_STEP = SPROP_MAX_INCREMENT_STEP, ///< Maximum increment step
        CONTACT_NUM = SPROP_CONTACT_NUM,               ///< Number of contact cases
        CONTACT_CASE = SPROP_CONTACT_CASE,             ///< Contact case Ids [CONTACT_NUM]
        RESEXPORT_NUM = SPROP_RESEXPORT_NUM,           ///< Number of exported result quantities
        RESEXPORT = SPROP_RESEXPORT,                   ///< Exported result quantities [RESEXPORT_NUM]
        RESIMPORT_NUM = SPROP_RESIMPORT_NUM,           ///< Number of result quantities to import
        RESIMPORT = SPROP_RESIMPORT,                   ///< Result quantities to import with step Id [RESIMPORT_NUM]
        USER_NUM = SPROP_USER_NUM                      ///< Number of user defined properties
    };

    /// \brief Solution property real type identifiers
    enum class DoubleProperty {
        EIGEN_LOWER = SPROP_EIGEN_LOWER,           ///< Eigenvalue lower bound
        EIGEN_UPPER = SPROP_EIGEN_UPPER,           ///< Eigenvalue upper bound
        EIGEN_SHIFT = SPROP_EIGEN_SHIFT,           ///< Eigenvalue shift
        LCASE_FACTOR = SPROP_LCASE_FACTOR,         ///< Load case factor [LCASE_NUM]
        TIME_INIT = SPROP_TIME_INIT,               ///< Time initial
        TIME_STEP = SPROP_TIME_STEP,               ///< Time step
        TIME_TERM = SPROP_TIME_TERM,               ///< Time termination
        TIME_STEPMIN = SPROP_TIME_STEPMIN,         ///< Time step minimum
        TIME_STEPMAX = SPROP_TIME_STEPMAX,         ///< Time step maximum
        RCASE_FACTOR = SPROP_RCASE_FACTOR,         ///< Restraint case factor
        MASS_FACTOR = SPROP_MASS_FACTOR,           ///< Mass factor
        DAMP_ALPHA = SPROP_DAMP_ALPHA,             ///< Stiffness proportional damping factor (Rayleigh alpha)
        DAMP_BETA = SPROP_DAMP_BETA,               ///< Mass proportional damping factor (Rayleigh beta)
        FTOL = SPROP_FTOL,                         ///< Force convergence tolerance
        UTOL = SPROP_UTOL,                         ///< Displacement convergence tolerance
        ETOL = SPROP_ETOL,                         ///< Energy convergence tolerance
        FREQ_LOWER = SPROP_FREQ_LOWER,             ///< Frequency lower bound [FREQ_NUM]
        FREQ_UPPER = SPROP_FREQ_UPPER,             ///< Frequency upper bound [FREQ_NUM]
        FREQ_BIAS = SPROP_FREQ_BIAS,               ///< Frequency bias [FREQ_NUM]
        TEMPMAXVARIATION = SPROP_TEMPMAXVARIATION, ///< Temperature maximum variation
        DRILLFACTOR = SPROP_DRILLFACTOR            ///< Drill stiffness scale factor
    };

    /// \brief Solution property char type identifiers
    enum class StringProperty {
        TITLE = SPROP_TITLE,                     ///< Title
        SUBTITLE = SPROP_SUBTITLE,               ///< Subtitle
        LABEL = SPROP_LABEL,                     ///< Label
        SUBLABEL = SPROP_SUBLABEL,               ///< Sublabel
        RESFILE_CQUA = SPROP_RESFILE_CQUA,       ///< Result file combined qualifier [RESFILE_NUM]
        RESPRINT_CQUA = SPROP_RESPRINT_CQUA,     ///< Result print combined qualifier [RESPRINT_NUM]
        DESTINATIONFILE = SPROP_DESTINATIONFILE, ///< Name of destination file
        RESIMPORT_FILE = SPROP_RESIMPORTFILE     ///< File name containing result quantities to import
    };

    /* property types */

    PIMPL_MOVE_ONLY(SolutionProperty)

    ErrorCode getErrorCode();
    Status    define(SolutionType type);
    Status    inquire(SolutionType *type);
    Status    redefine(SolutionType type);
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
    Status    getPropertyInformation(IntegerProperty type, int *componentCount);
    Status    getPropertyInformation(DoubleProperty type, int *componentCount);
    Status    getPropertyInformation(StringProperty type, int *componentCount);
    Status    getPropertyName(IntegerProperty type, char name[]);
    Status    getPropertyName(DoubleProperty type, char name[]);
    Status    getPropertyName(StringProperty type, char name[]);
    Status    getPropertyDoubleValue(DoubleProperty type, double values[]);
    Status    getPropertyStringValue(StringProperty type, char values[]);
    Status    setId(int id);
    Status    getId(int *id);
    Status    setName(const char *name);
    Status    getName(char name[]);
    Status    copy(SolutionProperty *from);
    Status    print();

    template <auto IntegerPropertyType, typename typeValue>
    Status setPropertyIntegerValue(typeValue value);

    template <auto IntegerPropertyType, typename typeValue>
    Status getPropertyIntegerValue(typeValue values[]);

    template <auto IntegerPropertyType, typename typeValue>
    Status setPropertyIntegerArray(typeValue values[]);

  private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // namespace cae::core
