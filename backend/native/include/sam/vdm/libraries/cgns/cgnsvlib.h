/* CGNS Library object */
#ifndef CGNSVLIB_DEF
#define CGNSVLIB_DEF

#include <stdio.h>

#include "sam/base/basedefs.h"
#include "sam/base/base.h"
#include "sam/vis/connect.h"
#include "sam/vis/idtran.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/library.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/plex.h"
#include "sam/vdm/libraries/cgns/cgnsdat.h"
#include "sam/vdm/permute.h"
#include "sam/base/timer.h"
#include "sam/vdm/libraries/cgns/cgnsvdefs.h"
#ifdef VKI_LIBAPI_CGNS
#include "cgnslib.h"
#endif
/* defines for function prototypes */
typedef void(VCGNSVLibMonitorFunc)(vdm_CGNSVLib*, Vobject*);

/* defines for search types */
#define CGNSVLIB_SEARCH_OFF           0
#define CGNSVLIB_SEARCH_DIRNUM        1
#define CGNSVLIB_SEARCH_DIRNUMFILENUM 2
#define CGNSVLIB_SEARCH_FILENUM       3

/* defines for write file type */
#define CGNSVLIB_HDF5 1
#define CGNSVLIB_ADF  2

/* defines for buffer size in writemodel: 10M */
#define MAXELEMOFFSETSIZE 10000000

typedef struct vdm_CGNSZoneMesh {
    Vint numnpZone;                      /* number of nodes in the zone */
    Vint nCellsZone;                     /* number of Cell elements in the zone */
    Vint cgnsZone;                       /* Zone number returned by cgns */
    Vint sectionGatherboundary2DZone;    /* Section number gathering 2D surface element of the zone */
    Vint sharedFacesCount;               /* Number of shared faces with other zones */
    vis_IdTran* idtranNodeLocalToGlobal; /* map nodeId local to zone -> globalId */
    vis_Group* groupZoneSharedFaces;     /* group of all elements having face shared by 2 Zones: ie: belonging to diff PartIds */
    vis_Group* groupZoneNodes;           /* group of nodes in the 3D elements connectivity part defining the zone */
    vis_Group* groupZoneElements;        /* group of elements connected to groupZoneNodes: 1D+2D+3D  */
    vis_IdTran** idtranSharedFacesPerZone; /* Idtran of pairs /iel1,ifac1/,/iel2,ifac2/ along Zone interface */

    adaptNumericArray* faceIndexToNGONZone;

    Vchar zoneName[256];
} vdm_CGNSZoneMesh;

struct vdm_CGNSVLib {
    Vint ierr;
    Vint type;
    VConventionType conv;
    Vint nodata;
    Vint retcon;
    Vint status;
    Vint idtyp, idoff[3], idbas[3];
    Vint numnp;
    Vint numel;
    Vint nfree;
    Vint ndim;
    Vint nantyp;
    Vint soltyp;
    Vint twotyp;
    Vint nonlin;
    Vint numcells;
    Vint numfaces;
    Vint ersvec;
    Vint emtcid;
    Vint emtvec;
    Vint partid;
    Vint numpartid;
    Vint featwod;
    Vint polyflag;
    Vfloat fversion;

    Vchar version[16];
    Vchar date[32];
    Vchar time[32];
    Vint numdataset;
    vdm_Library* library;

    vis_Connect* connectpoly;
    vis_Connect* connect;
    vis_GProp* gprop;
    vis_GridFun* gridfun;
    vis_Connect* connectset;
    vis_IdTran* idtrannode;
    vis_IdTran* idtranelem;
    vis_IdTran* idtranface;
    vsy_IntHash* zones; /* hashtable of zones and entity type */
    Vint cursubsectid;

    Vint numdatasetplex;
    vdm_Plex* plex;

    VCGNSVLibMonitorFunc* funmon;
    Vobject* funobjmon;
    Vint abortflag;
    Vint findex; /* cgns file index */
    Vint nbases; /* Number of bases present in the CGNS file */
    vsy_HashTable* etypeh;
    vsy_Dictionary* ecgtypeh;  /* hashtable of elemtypes based on topology : shape,maxi,maxj,maxk */
    vsy_HashTable* bctypeh;    /* hashtable of supported CGNSBCType variable: cgnsbctypes=conversion array CGNS<=>VDM */
    vsy_HashTable* ptsettypeh; /* hashtable of supported point set types CGNSPtSetType */
    Vint B;                    /* Base index number 1<= B <=nbases */
    Vint startB;               /* 1st base index having zone default=1 */
    Vint nzones;               /* Number of zones present in base B */
    Vint nsteps;
    Vint cell_dim; /* Dimension of the cells; 3=volume cells, 2=surface cells and 1=line cells. */
    Vint phys_dim; /* Physic Dimension: Number of coordinates required to define a vector in the field*/
    vdm_Permute* permute;
    Vint* elem0;    /* size=nzones. pointer to the 1st cell of each zone */
    Vint* node0;    /* size=nzones. pointer to the 1st node of each zone */
    Vint* znumel;   /* number of Cell elements per zone, without boundary or interface elements */
    Vint* znumnp;   /* number of nodes per zone */
    Vint nfamilies; /* number of families*/
    Vint* nGeo;
    Vint* nFamBC;       /* [siz=nfamilies] number of BC of a family: =0 or 1 */
    Vchar** FamilyName; /* [siz=nfamilies] name of a family */
    Vchar** FamBCName;  /* [siz=nfamilies] name of a FamilyBC_t */
    void* BCType;       /* [siz=nfamilies] BCType_t type of the family : BCTypeNull, BCTypeUserDefined,
                              BCAxisymmetricWedge, BCDegenerateLine, BCExtrapolate, BCDegeneratePoint,
                              BCDirichlet, BCFarfield, BCNeumann, BCGeneral, BCInflow, BCOutflow,
                              BCInflowSubsonic, BCOutflowSubsonic, BCInflowSupersonic, BCOutflowSupersonic,
                              BCSymmetryPlane, BCTunnelInflow, BCSymmetryPolar, BCTunnelOutflow,
                              BCWallViscous, BCWall, BCWallViscousHeatFlux, BCWallInviscid,
                              BCWallViscousIsothermal, FamilySpecified */
    vsy_IntDict* nodesetinam;
    vsy_IntDict* nodesetspec;
    Vint numnodesets;
    vsy_HashTable* nodesets;
    vsy_IntDict* solnamedict;
    Vint numsols;
    vis_IdTran* nodeid;
    vis_IdTran* nodeidinv;
    vsy_IntDict* zoneIdDict; /* zone Ids dictionnary */
    Vint tnumnp;             /* summ of nodes of all zones: working variable */
    vsy_Dictionary* soldict;
    Vfloat* timval;
    Vint* numtimzones;
    Vchar* zonepointers;
    vsy_IntDict** flowsols;     /* Dictionnary of Flow Solutions pointers for each zone */
    vsy_HashTable** flowcoords; /* Hashtable of Flow coordinates pointers for each zone */
    vsy_HashTable** flowzones;  /* Hashtable of Flow zones pointers for each zone */
    Vint inam;
    Vdouble** coords; /* Arrays of coordinates vectors for each zone size=3*NbNode[izone] */
    Vint* weight;     /* weight array to get 1-to-1 node equivalences in multi zone grid connectivity */
    vsy_Dictionary* nodesetdict;
    Vint numbelem;
    Vint nentgroups;
    vsy_HashTable* enth;
    vsy_IntDict* entd; /* Dictionary of BCs goups */
    vis_Units* units;
    vsy_HashTable* csh;
    Vint numelemsets;        /* number of BC elemenset group */
    vsy_HashTable* elemsets; /* list of idTran of BC element set groups */
    Vint parlibclose;

    Vchar title[81];

    Vint* libdsts;
    vdm_CGNSVLib* parlib;
    vdm_CGNSVLib* curlib;
    vsy_List* spl;
    vsy_HashTable* eph;
    Vint numprp; /* number of Eprop to store Zone UserDefinedData */
    vsy_IntVHash* periodiciv;
    vsy_HashTable* periodicht;
    Vint numperiodic;
    Vchar (*zonenames)[33]; /* Names of all zones */
    Vint parallel;
    Vint isub;
    Vint nsub;
    vdm_CGNSVLib** qsub;
    Vint begnode;
    Vint begelem;
    Vint nmodelnodes;
    Vint nmodelelems;
    Vint search; /* Multiple files search convention CGNSVLIB_SEARCH_OFF/DIRNUM/... */
    Vint* index_dim;
    Vint* ia_elem;
#ifdef VKI_LIBAPI_CGNS
    cgsize_t* numelToCGNSNumel; /* mapping between elements of the model and elements written in cgns file */
#endif
    vsy_HashTable* lch;
    Vint bci;
    Vint bcj;
    Vint bck;
    Vint nlcases;
    Vint ncgnselems;
    vsy_IntVec** elemmap; /* Element mapping table from element zone number to global element number */
    /* get integer values */
    Vint phase;
    /* get string values */
    Vchar source[VDM_SOURCE_SIZE];
    /* dataset for push */
    Vint idst;
    Vint writetype;
    vsy_FltVec* basefv;

    /* Convention parameters */
    Vint doubpre;
    Vint doubres;
    Vint nodebc;
    Vint noequiv;
    Vint legacyExportFlag;           /* 1=>legacy cgns converter | 0=default=> export Polys with optimized method */
    Vint exportAlwaysMixed;          /* default=0 / 1=>export section as mixed type even if only 1 element type */
    Vint legacyCellZoneNumber;       /* default=0 / 1=>export Cell Zone number with old formulea: all elements number */
    Vint singleNGONSection2DElement; /* default=0 / 1=>export all 2D element face in a single section */
    Vint familySpecifiedWriting;     /* default=0 / 1=>export Family_t node and BC info will be written under it*/
    Vint multiZonesExport;           /* default=0 / 1=>each 3D mesh part is written in a dedicated zone */
    Vint multiZonesExportFaceCenter; /* default=0 / MultiZone interfaces described with GridLocation=FaceCenter */
    Vint isRealMultiZonesExport;     /* default=0 / Real multizone export config: multiZonesExport && nzones > 1 */
    Vint PolyDataFromElemEntAssoc;   /* default=0 / assume the uniqueFace structure is defined in ElemEnt association */

    vdm_CGNSPolyData* polyData;
    Vint threadsCount; /* number of threads used in polys Converter */
    vsy_Timer* converterTimer;
    vdm_CGNSZoneMesh** zonesMesh;

#ifdef __cplusplus
  public:
    VKI_EXTERN
    vdm_CGNSVLib(void);
    VKI_EXTERN void*
    operator new(size_t);
    VKI_EXTERN ~vdm_CGNSVLib(void);
    VKI_EXTERN void
    operator delete(void*);
    VKI_EXTERN Vint
    Error();
    VKI_EXTERN void SetMode(Vint, Vint);
    VKI_EXTERN void SetConvention(VConventionType);
    VKI_EXTERN void SetThreadsCount(Vint);
    VKI_EXTERN void SetStatus(Vint);
    VKI_EXTERN void
    SetConnect(vis_Connect*);
    VKI_EXTERN void
    GetConnect(vis_Connect**);
    VKI_EXTERN void SetIds(Vint, Vint, Vint, Vint);
    VKI_EXTERN void
    SetFunction(Vint, Vfunc*, Vobject*);
    VKI_EXTERN void
    SetMonitorFunction(VCGNSVLibMonitorFunc*, Vobject*);
    VKI_EXTERN void
    Abort();
    VKI_EXTERN void
    Open(Vint, Vchar*, Vint);
    VKI_EXTERN void
    Close();
    VKI_EXTERN void
    Append(Vchar*, Vint);
    VKI_EXTERN void
    GetNumEntities(Vint, Vint*);
    VKI_EXTERN void
    GetLibrary(vdm_Library**);
    VKI_EXTERN void
    NumDatasets(Vint*);
    VKI_EXTERN void
    NumAttributes(Vint, Vint*);
    VKI_EXTERN void
    GetAttVal(Vint, Vint, void*);
    VKI_EXTERN void
    InqDataset(Vint, Vchar[], Vlong*, Vint*, Vint*, Vint*);
    VKI_EXTERN void
    InqAttribute(Vint, Vint, Vchar[], Vint*, Vint*);
    VKI_EXTERN void
    ReadDataset(Vint, void*);
    VKI_EXTERN void LibDataset(Vint, Vint);
    VKI_EXTERN void
    DataFun(vdm_DataFun*);
    VKI_EXTERN void
    WriteModel(vis_Model*);
    VKI_EXTERN void
    WriteState(vis_RProp*, vis_State*);
    VKI_EXTERN void SetSearch(Vint);
    VKI_EXTERN void
    GetInteger(Vint, Vint*);
    VKI_EXTERN void
    GetString(Vint, Vchar*);
    VKI_EXTERN void
    NumDomains(Vchar*, Vint, Vint*);
    VKI_EXTERN void SetWriteFileType(Vint);
    VKI_EXTERN void
    SetString(Vint, Vchar*);
    VKI_EXTERN void
    GetUnrecognizedData(vdm_UnrecognizedData**);
#endif
};

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vdm_CGNSVLib*
vdm_CGNSVLibBegin(void);
VKI_EXTERN void
vdm_CGNSVLib_Construct(vdm_CGNSVLib* p);
VKI_EXTERN void
vdm_CGNSVLibEnd(vdm_CGNSVLib* p);
VKI_EXTERN void
vdm_CGNSVLib_Destruct(vdm_CGNSVLib* p);
VKI_EXTERN Vint
vdm_CGNSVLibError(vdm_CGNSVLib* p);
VKI_EXTERN void
vdm_CGNSVLibSetMode(vdm_CGNSVLib* p, Vint mode, Vint flag);
VKI_EXTERN void
vdm_CGNSVLibSetConvention(vdm_CGNSVLib* p, VConventionType convention);
VKI_EXTERN void
vdm_CGNSVLibSetThreadsCount(vdm_CGNSVLib* p, Vint threadsCount);
VKI_EXTERN void
vdm_CGNSVLibSetStatus(vdm_CGNSVLib* p, Vint status);
VKI_EXTERN void
vdm_CGNSVLibSetConnect(vdm_CGNSVLib* p, vis_Connect* connect);
VKI_EXTERN void
vdm_CGNSVLibGetConnect(vdm_CGNSVLib* p, vis_Connect** connect);
VKI_EXTERN void
vdm_CGNSVLibSetIds(vdm_CGNSVLib* p, Vint idtype, Vint id1off, Vint id2off, Vint id3off);
VKI_EXTERN void
vdm_CGNSVLibSetFunction(vdm_CGNSVLib* p, Vint funtype, Vfunc* function, Vobject* object);
VKI_EXTERN void
vdm_CGNSVLibSetMonitorFunction(vdm_CGNSVLib* p, VCGNSVLibMonitorFunc* function, Vobject* object);
VKI_EXTERN void
vdm_CGNSVLibAbort(vdm_CGNSVLib* p);
VKI_EXTERN void
vdm_CGNSVLibOpen(vdm_CGNSVLib* p, Vint mode, Vchar* filename, Vint type);
VKI_EXTERN void
vdm_CGNSVLibClose(vdm_CGNSVLib* p);
VKI_EXTERN void
vdm_CGNSVLibAppend(vdm_CGNSVLib* p, Vchar* filename, Vint type);
VKI_EXTERN void
vdm_CGNSVLibGetNumEntities(vdm_CGNSVLib* p, Vint enttype, Vint* nument);
VKI_EXTERN void
vdm_CGNSVLibGetLibrary(vdm_CGNSVLib* p, vdm_Library** library);
VKI_EXTERN void
vdm_CGNSVLibNumDatasets(vdm_CGNSVLib* p, Vint* numdatasets);
VKI_EXTERN void
vdm_CGNSVLibNumAttributes(vdm_CGNSVLib* p, Vint idst, Vint* numattributes);
VKI_EXTERN void
vdm_CGNSVLibGetAttVal(vdm_CGNSVLib* p, Vint idst, Vint iatt, void* value);
VKI_EXTERN void
vdm_CGNSVLibInqDataset(vdm_CGNSVLib* p, Vint idst, Vchar name[], Vlong* lrec, Vint* nrow, Vint* ncol, Vint* type);
VKI_EXTERN void
vdm_CGNSVLibInqAttribute(vdm_CGNSVLib* p, Vint idst, Vint iatt, Vchar name[], Vint* length, Vint* type);
VKI_EXTERN void
vdm_CGNSVLibReadDataset(vdm_CGNSVLib* p, Vint idst, void* buf);
VKI_EXTERN void
vdm_CGNSVLibLibDataset(vdm_CGNSVLib* p, Vint oper, Vint idst);
VKI_EXTERN void
vdm_CGNSVLibSetString(vdm_CGNSVLib* p, Vint type, Vchar* cvalue);
VKI_EXTERN void
vdm_CGNSVLibGetUnrecognizedData(vdm_CGNSVLib* p, vdm_UnrecognizedData** unrecognizedData);
VKI_EXTERN void
vdm_CGNSVLibDataFun(vdm_CGNSVLib* p, vdm_DataFun* datafun);
VKI_EXTERN void
vdm_CGNSVLibWriteModel(vdm_CGNSVLib* p, vis_Model* model);
VKI_EXTERN void
vdm_CGNSVLibWriteState(vdm_CGNSVLib* p, vis_RProp* rprop, vis_State* state);
VKI_EXTERN void
vdm_CGNSVLibSetSearch(vdm_CGNSVLib* p, Vint search);
VKI_EXTERN void
vdm_CGNSVLibGetInteger(vdm_CGNSVLib* p, Vint type, Vint* ivalue);
VKI_EXTERN void
vdm_CGNSVLibGetString(vdm_CGNSVLib* p, Vint type, Vchar* cvalue);
VKI_EXTERN void
vdm_CGNSVLibNumDomains(vdm_CGNSVLib* p, Vchar* filename, Vint type, Vint* numdomains);
VKI_EXTERN void
vdm_CGNSVLibSetWriteFileType(vdm_CGNSVLib* p, Vint filetype);

#ifdef __cplusplus
}
#endif

#endif
