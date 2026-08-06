#pragma once

#include "samcpp/access/accessdefs.h"
#include "samcpp/core/base_types.h"
#include "samcpp/core/coredefs.h"
#include "samcpp/core/pimpl.h"
#include "samcpp/core/pointer.h"
#include "samcpp/core/status.h"

#include <memory>

ACCESSOR_DECL

namespace cae::access {

class Options {
  public:
    PIMPL_MOVE_ONLY(Options)

    /// Data and attribute conventions for data processing.
    enum class Convention : unsigned {
        NOINTERLAMINAR = 0,              ///< Ignore interlaminar results.
        DOUBLERESULT = 1,                ///< Generate double precision result datasets.
        SPARSE = 2,                      ///< Generate sparse format for results datasets.
        ALTPART = 3,                     ///< Enable alternate part assignment method for reading and writing Abaqus result files.
        DOUBLE = 4,                      ///< Generate double precision geometry datasets (node coordinates, coordinate systems).
        STRESSINVARIANT = 5,             ///< Generate invariant (stress invariant) results.
        PSHELLTHICK = 6,                 ///< Use PSHELL thickness for shell property cards in NASTRAN files.
        DATASET32 = 7,                   ///< To set dataset name length 32, attribute name 16, attribute value 32.
        NOINTPT = 8,                     ///< Ignore integration point results (e.g., in ABAQUS .odb files).
        NOSETS = 9,                      ///< Do not generate node and element sets (e.g., in ABAQUS .odb or OpenFoam files).
        STARCD = 10,                     ///< Enable StarCD convention for Ensight results files.
        EIP = 11,                        ///< Use element integration point data.
        ELEMCENT = 12,                   ///< Project integration point data to element centroid (Abaqus ODB only).
        FRAMEZERO = 13,                  ///< Generate results datasets for initial conditions.
        NOINTERNALSETS = 14,             ///< Do not read/process internally generated entity sets (Abaqus result files).
        NODEBC = 15,                     ///< Write node boundary conditions (face/edge based BCs on attached nodes).
        WALLINTER = 16,                  ///< Convert exterior faces to wall interface elements.
        CONVERTPOLY = 17,                ///< Convert polygon and polyhedron elements to primitive cell shapes.
        NOEQUIV = 18,                    ///< Do not equivalence (merge) coincident nodes.
        UNIRESULTTYPE = 19,              ///< Assume uniform results over a step (replicate first time step results).
        COMPLEX = 20,                    ///< Complex data support for results datasets.
        LINEAREXTRAP = 21,               ///< Use linear extrapolation from integration points to nodes for certain element types and rules while reading marc result files.
        SECTNUM = 22,                    ///< ODB enforce Link.Layers based on integration point numbering
        NOPARINTER = 23,                 ///< Avoid creating element sets for processor interface boundaries when importing OpenFOAM meshes.
        NOCOMMENT = 24,                  ///< Do not read vendor-specific comment card conventions from input files.
        CGNSLEGACYEXPORT = 25,           ///< To be deprecated. Use legacy export for CGNS files.
        NOHISTORYOUTPUT = 26,            ///< No history output read in odb reader.
        MAPCYLINDRICALALTTOVECTOR = 27,  ///< Downgrade of ElementCoordinateSystemConvention::CYLINDRICAL_ALTERNATE to ElementCoordinateSystemConvention::VECTOR.
        CGNSALWAYSMIXED = 28,            ///< CGNS Export: enforce MIXED type even if model has a single element type.
        ONLYSCALARSHEARPANELSTRESS = 29, ///< The shear panel stress is reported only as a scalar and not as tensor.
        CGNSLEGACYCELLZONENUMBER = 30,   ///< CGNS Export: use old formulae for Cell zone number defines for library dataset.
        CGNSSINGLENGONSECTION2D = 31,    ///< CGNS Export: write all 2D element faces in a single Element_t section.
        NOFIELDOUTPUT = 32,              ///< No field output read in odb reader.
        ORIGINAL_GASKET_STATUS = 33      ///< Use the gasket status from the solver directly instead of mapping into VDM mapping.
    };

    /// Initialization mode for undefined data.
    enum class NoDataValueMode {
        OFF = SYS_OFF, ///< Disable mode - initialize datasets to 0.
        ON = SYS_ON,   ///< Enable mode - initialize datasets to NAN.
        NEW = SYS_NEW  ///< Enable new mode - improved data initialization.
    };

    /// ANSYS part ID numbering method.
    enum class AnsysPartIdNumbering {
        LEGACY_METHOD = ANSLIB_PARTIDUSINGLEGACYMETHOD,        ///< Use legacy method for numbering entities.
        SECTION_NUMBER = ANSLIB_PARTIDUSINGSECNUM,             ///< Use section number for numbering entities.
        REAL_CONSTANT = ANSLIB_PARTIDUSINGREALCONSTREF_NUMBER, ///< Use real constant reference number for numbering entities.
        ELEMENT_TYPE = ANSLIB_PARTIDUSINGELEM_TYPE             ///< Use element type number for numbering entities.
    };

    /// Write format options for VTU export.
    enum class WriteFormat {
        ASCII = EXPORT_ASCII,  ///< Write in ASCII mode.
        BINARY = EXPORT_BINARY ///< Write in Binary mode.
    };

    /// Header precision options for VTU export.
    enum class HeaderPrecision {
        UINT32 = HEADERUINT32, ///< Use UInt32 for header item size.
        UINT64 = HEADERUINT64  ///< Use UInt64 for header item size.
    };

    /// Mode types for reading and writing configuration.
    enum class Mode {
        NODATA_VALUE = VDM_NODATAVALMODE,                               ///< Initialization mode for undefined values. See:  \enumtype{NoDataValueMode}
        RETAIN_MESH = VDM_RETAINCONNECTMODE,                            ///< Retain the Mesh object after reading.
        ABAODB_NO_CLOSE = VDM_ABAODBNOCLOSEMODE,                        ///< Do not close the ODB file while closing the reader.
        INCLUDE_ERROR = VDM_INCLUDEERRORMODE,                           ///< Enable/disable failure of opening INCLUDE files.
        ZLIB_COMPRESSION = VDM_ZLIBCOMPRESSMODE,                        ///< Write with ZLib compression.
        ANSYS_PARTID_NUMBERING = VDM_ANSYS_PARTIDNUMBERINGMODE,         ///< Numbering method for entities on ANSYS result files. See:  \enumtype{AnsysPartIdNumbering}
        CGNS_FAMILY_SPECIFIED = VDM_CGNS_FAMILYSPECIFIED,               ///< CGNS Export: define BC types at Family_t node.
        CGNS_MULTI_ZONES_EXPORT = VDM_CGNS_MULTIZONESEXPORT,            ///< CGNS Export: write each 3D part mesh in dedicated Zone_t node.
        CGNS_ZONE_FACE_CENTER = VDM_CGNS_ZONEFACECENTER,                ///< CGNS Export: Zone GridConnectivity uses FaceCenter.
        DPFLIB_ROTATE_TO_GLOBAL_FRAME = VDM_DPFLIB_ROTATETOGLOBALFRAME, ///< Rotate the model to the global frame in DPFLib.
        DPFLIB_CHECK_VERSION = VDM_DPFLIB_CHECKVERSION,                 ///< Check APDL version in DPFLib.
        WRITE_FORMAT = VDM_WRITEFORMAT,                                 ///< VTU export format (Binary/ASCII). See:  \enumtype{WriteFormat}
        HEADER_PRECISION = VDM_HEADERPRECISION,                         ///< VTU export header type. See:  \enumtype{HeaderPrecision}
        DPFLIB_ASSUME_LICENSING = VDM_DPFLIB_ASSUMELICENSING,           ///< Assume that an ANSYS license is available in DPFLib.
        DEFERRED_READ = VDM_DEFERREDREADMODE,                           ///< Deferred reading mode for indices.
        CGNS_POLY_AS_ELEMENT_ASSOCIATION = VDM_CGNS_POLYASELEMENTASSOC, ///< CGNS Export: PolyData is built from element associations.
        ABAODB_AUTO_UPDATE = VDM_ABAODBAUTOUPDATE                       ///< Abaqus ODB: Upgrade .odb version automatically.
    };

    cae::core::ErrorCode getErrorCode();
    cae::core::Status    enableConvention(Convention convention);
    template <auto ModeType, typename ModeValue>
    cae::core::Status setMode(ModeValue value);
    cae::core::Status setFileFormat(cae::core::FileFormat fileFormat);
    cae::core::Status hasConventionEnabled(Convention convention, bool &flag);
    cae::core::Status getModes(cae::core::IntHashTablePtr &modes);
    cae::core::Status getFileFormat(cae::core::FileFormat *fileFormat);

  private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // namespace cae::access
