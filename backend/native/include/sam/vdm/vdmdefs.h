/*********************************************************************
 *                                                                   *
 *                          DevTools 3.1.0                           *
 *                                                                   *
 *  These coded instructions, statements and computer programs       *
 *  contain unpublished proprietary information of Tech Soft 3D,     *
 *  and are protected by Federal copyright law.  They may not be     *
 *  disclosed to third parties or copied or duplicated in any form,  *
 *  in whole or in part, without the prior written consent of        *
 *  Tech Soft 3D.                                                    *
 *                                                                   *
 *                 Copyright (C) 2026, Tech Soft 3D                  *
 *                                                                   *
 *********************************************************************/
/* VdmTools macro definitions header file */

#ifndef VDMDEFS_DEF
#define VDMDEFS_DEF

#include <stdio.h>
#include "sam/base/basedefs.h"
#include "sam/vdm/lmandefs.h"
#ifdef VKI_ARCH_LINUX
#include <fenv.h>
#endif

typedef struct vdm_ABALib vdm_ABALib;
typedef struct vdm_ABAFil vdm_ABAFil;
typedef struct vdm_AdamsLib vdm_AdamsLib;
typedef struct vdm_AUTODYNLib vdm_AUTODYNLib;
typedef struct vdm_AFLRFil vdm_AFLRFil;
typedef struct vdm_ANSLib vdm_ANSLib;
typedef struct vdm_ANSFil vdm_ANSFil;
typedef struct vdm_Attribute vdm_Attribute;
typedef struct vdm_CFXLib vdm_CFXLib;
typedef struct vdm_CGNSVLib vdm_CGNSVLib;
typedef struct vdm_COMSOLLib vdm_COMSOLLib;
typedef struct vdm_D3DFil vdm_D3DFil;
typedef struct vdm_D3DLib vdm_D3DLib;
typedef struct vdm_DataFun vdm_DataFun;
typedef struct vdm_DataIPC vdm_DataIPC;
typedef struct vdm_Dataset vdm_Dataset;
typedef struct vdm_EnSightLib vdm_EnSightLib;
typedef struct vdm_ElemSect vdm_ElemSect;
typedef struct vdm_FDILib vdm_FDILib;
typedef struct vdm_FEMAPLib vdm_FEMAPLib;
typedef struct vdm_FLUENTLib vdm_FLUENTLib;
typedef struct vdm_GMVLib vdm_GMVLib;
typedef struct vdm_H3DLib vdm_H3DLib;
typedef struct vdm_HMAFil vdm_HMAFil;
typedef struct vdm_Library vdm_Library;
typedef struct vdm_LMan vdm_LMan;
typedef struct vdm_MarcFil vdm_MarcFil;
typedef struct vdm_MarcLib vdm_MarcLib;
typedef struct vdm_MemLib vdm_MemLib;
typedef struct vdm_NASFil vdm_NASFil;
typedef struct vdm_NASLib vdm_NASLib;
typedef struct vdm_NatLib vdm_NatLib;
typedef struct vdm_OBJFil vdm_OBJFil;
typedef struct vdm_OpenFOAMLib vdm_OpenFOAMLib;
typedef struct vdm_Options vdm_Options;
typedef struct vdm_PAMFil vdm_PAMFil;
typedef struct vdm_PAMLib vdm_PAMLib;
typedef struct vdm_PatLib vdm_PatLib;
typedef struct vdm_PERMASLib vdm_PERMASLib;
typedef struct vdm_POLYFLOWLib vdm_POLYFLOWLib;
typedef struct vdm_PLOT3DLib vdm_PLOT3DLib;
typedef struct vdm_RASFil vdm_RASFil;
typedef struct vdm_RASLib vdm_RASLib;
typedef struct vdm_SAMCEFLib vdm_SAMCEFLib;
typedef struct vdm_SDRCLib vdm_SDRCLib;
typedef struct vdm_STARCCMLib vdm_STARCCMLib;
typedef struct vdm_STLFil vdm_STLFil;
typedef struct vdm_Settings vdm_Settings;
typedef struct vdm_TecplotLib vdm_TecplotLib;
typedef struct vdm_VTKLib vdm_VTKLib;
typedef struct vdm_DPFLib vdm_DPFLib;
typedef struct vdm_PluginLib vdm_PluginLib;
typedef struct vdm_PluginSettings vdm_PluginSettings;
typedef struct vdm_Writer vdm_Writer;
typedef struct vdm_UnrecognizedData vdm_UnrecognizedData;

/* floating point exception types */
#if defined(VKI_ARCH_WIN32)
typedef unsigned int Vfpe;
#elif defined(VKI_ARCH_LINUX)
typedef fenv_t Vfpe;
#else
typedef unsigned int Vfpe;
#endif

/* defines for library device types */
/*this list must be the same as the one found in */
#define VDM_NATIVE           SYS_NATIVE
#define VDM_PLOT3D_GRID      SYS_PLOT3D_GRID
#define VDM_PLOT3D_SOLUTION  SYS_PLOT3D_SOLUTION
#define VDM_PATRAN_RESULT    SYS_PATRAN_RESULT
#define VDM_GENERIC          SYS_GENERIC
#define VDM_PDA              SYS_PDA
#define VDM_LSTC_STATE       SYS_LSTC_STATE
#define VDM_ABAQUS_ODB       SYS_ABAQUS_ODB
#define VDM_ABAQUS_FILBIN    SYS_ABAQUS_FIL
#define VDM_ABAQUS_FIL       SYS_ABAQUS_FIL
#define VDM_NASTRAN_OUTPUT2  SYS_NASTRAN_OUTPUT2
#define VDM_STL              SYS_STL
#define VDM_STLBIN           SYS_STLBIN
#define VDM_ABAQUS_INPUT     SYS_ABAQUS_INPUT
#define VDM_SDRC_UNIVERSAL   SYS_SDRC_UNIVERSAL
#define VDM_PAM_DAISY        SYS_PAM_DAISY
#define VDM_ANSYS_RESULT     SYS_ANSYS_RESULT
#define VDM_MECHANICA_STUDY  SYS_MECHANICA_STUDY
#define VDM_NASTRAN_BULKDATA SYS_NASTRAN_BULKDATA
#define VDM_FDI_NEUTRAL      SYS_FDI_NEUTRAL
#define VDM_PAT_NEUTRAL      SYS_PATRAN_NEUTRAL
#define VDM_PATRAN_NEUTRAL   SYS_PATRAN_NEUTRAL
#define VDM_FLUENT_MESH      SYS_FLUENT_MESH
#define VDM_ANSYS_INPUT      SYS_ANSYS_INPUT
#define VDM_TECPLOT          SYS_TECPLOT
#define VDM_HYPERMESH_ASCII  SYS_HYPERMESH_ASCII
#define VDM_LSTC_INPUT       SYS_LSTC_INPUT
#define VDM_CGNS             SYS_CGNS
#define VDM_MARC_POST        SYS_MARC_POST
#define VDM_ENSIGHT          SYS_ENSIGHT
#define VDM_STARCCM          SYS_STARCCM
#define VDM_MECHANICA_FNF    SYS_MECHANICA_FNF

#define VDM_LSTC_HISTORY SYS_LSTC_HISTORY
#define VDM_NASTRAN_XDB  SYS_NASTRAN_XDB
#define VDM_NASTRAN_H5   SYS_NASTRAN_H5

#define VDM_POLYFLOW      SYS_POLYFLOW
#define VDM_FEMAP_NEUTRAL SYS_FEMAP_NEUTRAL
#define VDM_AUTODYN_RES   SYS_AUTODYN_RES
#define VDM_PAM_ERF       SYS_PAM_ERF
#define VDM_OPENFOAM      SYS_OPENFOAM
#define VDM_OBJ           SYS_OBJ

#define VDM_COMSOL_SECTION   SYS_COMSOL_SECTION
#define VDM_H3D              SYS_H3D
#define VDM_LSTC_STATEFEMZIP SYS_LSTC_STATEFEMZIP
#define VDM_PAM_INPUT        SYS_PAM_INPUT
#define VDM_CFX_RESULT       SYS_CFX_RESULT
#define VDM_GMV              SYS_GMV
#define VDM_PERMAS_POST      SYS_PERMAS_POST
#define VDM_VTK_LEGACY       SYS_VTK_LEGACY
#define VDM_SAMCEF           SYS_SAMCEF
#define VDM_AFLR             SYS_AFLR
#define VDM_ADAMS            SYS_ADAMS
#define VDM_NATIVE_HDF5      SYS_NATIVE_HDF5
#define VDM_MEMORY           SYS_MEMORY
#define VDM_COMSOL_MPH       SYS_COMSOL_MPH
#define VDM_COMSOL_MPHBIN    SYS_COMSOL_MPHBIN
#define VDM_MARC_INPUT       SYS_MARC_INPUT
#define VDM_ANSYS_DPF        SYS_ANSYS_DPF
#define VDM_PLUGIN           SYS_PLUGIN
#define VDM_VTK_VTU          SYS_VTK_VTU

#define VDM_MAXTYPE SYS_MAXTYPE

#define VDM_STATUS_OLD 1
#define VDM_STATUS_NEW 2
#define VDM_STATUS_ADD 3

/* defines for dataset types */
/* this number must be larger than SYS_RES_MAX */
#define VDM_ONFILE       1000
#define VDM_VIRTUAL      1001
#define VDM_ELEMNODEPNTR 1002
#define VDM_ELEMNODESIZE 1003
#define VDM_ELEMNODE     1004
#define VDM_ELEMTYPE     1005
#define VDM_ELEMTYPEINT  1007
#define VDM_ELEMTYPEHOL  1008
#define VDM_EID          1009
#define VDM_MID          1010
#define VDM_PID          1011
#define VDM_PARAMINT     1012
#define VDM_PARAMHOL     1013
#define VDM_ERSCID       1014
#define VDM_COLORELEM    1015
#define VDM_PARTIDELEM   1016
#define VDM_ORIENTELEM   1017

#define VDM_ERSVEC      1018
#define VDM_SETELEM     1019
#define VDM_X           1020
#define VDM_SETNODE     1021
#define VDM_NID         1022
#define VDM_NODETYPE    1023
#define VDM_SETELEMENT  1024
#define VDM_DOFCID      1025
#define VDM_DOF         1026
#define VDM_COLORNODE   1027
#define VDM_PARTIDNODE  1028
#define VDM_COLORMAP    1029
#define VDM_ELEMTOPO    1030
#define VDM_ELEMSPEC    1031
#define VDM_ELEMTWOD    1032
#define VDM_PARAMIJK    1033
#define VDM_IBLANKNODE  1034
#define VDM_ELEMTYPEEXT 1035
#define VDM_ELEMSIZE    1036
#define VDM_ELEMSHAP    1037
#define VDM_ELEMMIJK    1038
#define VDM_ELEMTECH    1039

#define VDM_DIRCOS     1040
#define VDM_ELEMEIPS   1041
#define VDM_CREFID     1042
#define VDM_ELEMSEID   1043
#define VDM_ELEMSYMMID 1044
#define VDM_THICKNESS  1050
#define VDM_NORMAL     1051
#define VDM_OFFSETVEC  1052
#define VDM_FIBERBOT   1053
#define VDM_FIBERTOP   1054
#define VDM_OFFSET     1055

#define VDM_DOMAINNODE 1058
#define VDM_DOMAINELEM 1059
#define VDM_EMTCID     1060
#define VDM_EMTVEC     1061
#define VDM_EMTFLAG    1062

#define VDM_ENDATOPO        1063
#define VDM_ENDBTOPO        1064
#define VDM_ENDACON         1065
#define VDM_ENDBCON         1066
#define VDM_ENDAVEC         1067
#define VDM_ENDBVEC         1068
#define VDM_NODEGEOVERT     1069
#define VDM_NODEGEOEDGE     1070
#define VDM_NODEGEOFACE     1071
#define VDM_NODEGEOBODY     1072
#define VDM_ELEMGEOEDGE     1073
#define VDM_ELEMGEOFACE     1074
#define VDM_ELEMGEOBODY     1075
#define VDM_ELEMEDGEGEOEDGE 1076
#define VDM_ELEMFACEGEOFACE 1077
#define VDM_PINFLAGSELEM    1078
#define VDM_MISCID          101079
#define VDM_MISCID0         101079
#define VDM_MISCID1         101080
#define VDM_MISCID2         101081
#define VDM_MISCID3         101082
#define VDM_MISCID4         101083
#define VDM_MISCID5         101084
#define VDM_MISCID6         101085
#define VDM_MISCID7         101086
#define VDM_MISCID8         101087

#ifdef VKI_PROJECT_DATASETMULTIASSOC
#define VDM_MISCIDELEMFACE  101088
#define VDM_MISCID0ELEMFACE 101088
#define VDM_MISCID1ELEMFACE 101089
#define VDM_MISCID2ELEMFACE 101090
#define VDM_MISCID3ELEMFACE 101091
#define VDM_MISCID4ELEMFACE 101092
#define VDM_MISCID5ELEMFACE 101093
#define VDM_MISCID6ELEMFACE 101094
#define VDM_MISCID7ELEMFACE 101095
#define VDM_MISCID8ELEMFACE 101096

#define VDM_MISCIDELEMEDGE  101097
#define VDM_MISCID0ELEMEDGE 101097
#define VDM_MISCID1ELEMEDGE 101098
#define VDM_MISCID2ELEMEDGE 101099
#define VDM_MISCID3ELEMEDGE 101100
#define VDM_MISCID4ELEMEDGE 101101
#define VDM_MISCID5ELEMEDGE 101092
#define VDM_MISCID6ELEMEDGE 101103
#define VDM_MISCID7ELEMEDGE 101104
#define VDM_MISCID8ELEMEDGE 101105
#endif

#define VDM_PARTNAMEID 1080
#define VDM_PARTNAME   1081

#define VDM_ELEMTANGEDGE     1082
#define VDM_ELEMTANGEDGEINDX 1083
#define VDM_ELEMNORMFACE     1085
#define VDM_ELEMNORMFACEINDX 1086

#define VDM_PARTIJKID 1088
#define VDM_PARTIJK   1089
#define VDM_IDE       1090
#define VDM_IDN       1091

#define VDM_CSYS     1100
#define VDM_CSYSID   1101
#define VDM_CSYSTYPE 1102

#define VDM_UNITSTYPE 1103
#define VDM_UNITS     1104

#define VDM_REST         1110
#define VDM_RESTDISP     1111
#define VDM_RESTINDX     1112
#define VDM_RESTTAG      1113
#define VDM_RESTMAST     1114
#define VDM_RESTNAME     1115
#define VDM_RESTELEM     1116
#define VDM_RESTELEMDISP 1117
#define VDM_RESTELEMINDX 1118
#define VDM_RESTELEMTAG  1119
#define VDM_RESTTID      1120
#define VDM_RESTDOT      1121

#define VDM_LOADACCL 1123
#define VDM_LOADNAME 1124

#define VDM_LOADTEMPNODETID 1125
#define VDM_LOADHEATNODETID 1126
#define VDM_LOADCSCANODETID 1127
#define VDM_LOADCVECNODETID 1128
#define VDM_LOADTID         1129

#define VDM_MATL     1130
#define VDM_MATLID   1131
#define VDM_MATLTYPE 1132
#define VDM_MATLINT  1133
#define VDM_MATLFLAG 1135
#define VDM_MATLNAME 1136

#define VDM_LOADTEMPNODE     1140
#define VDM_LOADHEATNODE     1141
#define VDM_LOADCSCANODE     1142
#define VDM_LOADCVECNODE     1143
#define VDM_LOAD             1144
#define VDM_LOADTEMPNODEINDX 1145
#define VDM_LOADHEATNODEINDX 1146
#define VDM_LOADCSCANODEINDX 1147
#define VDM_LOADCVECNODEINDX 1148
#define VDM_LOADINDX         1149

#define VDM_PROP     1150
#define VDM_PROPID   1151
#define VDM_PROPTYPE 1152
#define VDM_PROPINT  1153
#define VDM_PROPHOL  1154
#define VDM_PROPFLAG 1155
#define VDM_PROPNAME 1156

#define VDM_SOLN     1160
#define VDM_SOLNID   1161
#define VDM_SOLNTYPE 1162
#define VDM_SOLNINT  1163
#define VDM_SOLNHOL  1164
#define VDM_SOLNFLAG 1165

#define VDM_MPCNODE 1170
#define VDM_MPCCOMP 1171
#define VDM_MPCCOEF 1172
#define VDM_MPCSIZE 1173
#define VDM_MPCRHS  1174
#define VDM_MPCELEM 1175
#define VDM_MPCTYPE 1176

#define VDM_FUNC     1180
#define VDM_FUNCID   1181
#define VDM_FUNCTYPE 1182
#define VDM_FUNCINT  1183

#define VDM_INITDOF        1190
#define VDM_INITDOFINDX    1191
#define VDM_INITDOFTAG     1192
#define VDM_INITDOFDOT     1193
#define VDM_INITDOFDOTINDX 1194
#define VDM_INITDOFDOTTAG  1195

#define VDM_LOADPRESEDGE     1200
#define VDM_LOADPRESEDGEINDX 1201
#define VDM_LOADPRESEDGETID  1202
#define VDM_LOADPRESFACE     1205
#define VDM_LOADPRESFACEINDX 1206
#define VDM_LOADPRESFACETID  1207

#define VDM_LOADFLUXEDGE     1210
#define VDM_LOADFLUXEDGEINDX 1211
#define VDM_LOADFLUXEDGETID  1212
#define VDM_LOADFLUXFACE     1215
#define VDM_LOADFLUXFACEINDX 1216
#define VDM_LOADFLUXFACETID  1217

#define VDM_LOADTRACEDGE     1220
#define VDM_LOADTRACEDGEINDX 1221
#define VDM_LOADTRACEDGETID  1222
#define VDM_LOADTRACFACE     1225
#define VDM_LOADTRACFACEINDX 1226
#define VDM_LOADTRACFACETID  1227

#define VDM_LOADHEATELEM     1230
#define VDM_LOADHEATELEMINDX 1231
#define VDM_LOADHEATELEMTID  1232
#define VDM_LOADACCLELEM     1234
#define VDM_LOADACCLELEMINDX 1235
#define VDM_LOADACCLELEMTID  1236

#define VDM_LOADCONVEDGE     1240
#define VDM_LOADCONVEDGEINDX 1241
#define VDM_LOADCONVEDGETID  1242
#define VDM_LOADCONVFACE     1245
#define VDM_LOADCONVFACEINDX 1246
#define VDM_LOADCONVFACETID  1247

#define VDM_LOADDMOMEDGE     1250
#define VDM_LOADDMOMEDGEINDX 1251
#define VDM_LOADDMOMEDGETID  1252
#define VDM_LOADDMOMFACE     1255
#define VDM_LOADDMOMFACEINDX 1256
#define VDM_LOADDMOMFACETID  1257

#define VDM_LOADDSCAEDGE     1260
#define VDM_LOADDSCAEDGEINDX 1261
#define VDM_LOADDSCAEDGETID  1262
#define VDM_LOADDSCAFACE     1265
#define VDM_LOADDSCAFACEINDX 1266
#define VDM_LOADDSCAFACETID  1267

#define VDM_LOADDVECEDGE     1270
#define VDM_LOADDVECEDGEINDX 1271
#define VDM_LOADDVECEDGETID  1272
#define VDM_LOADDVECFACE     1275
#define VDM_LOADDVECFACEINDX 1276
#define VDM_LOADDVECFACETID  1277

#define VDM_LOADHRADEDGE     1290
#define VDM_LOADHRADEDGEINDX 1291
#define VDM_LOADHRADEDGETID  1292
#define VDM_LOADHRADFACE     1295
#define VDM_LOADHRADFACEINDX 1296
#define VDM_LOADHRADFACETID  1297

#define VDM_GLOB     1280
#define VDM_GLOBINT  1283
#define VDM_GLOBHOL  1284
#define VDM_GLOBFLAG 1285

#define VDM_CONT     1300
#define VDM_CONTFLAG 1301
#define VDM_CONTINT  1302
#define VDM_CONTTYPE 1310

#define VDM_CONTMASTASURF    1323
#define VDM_CONTMASTELEMFACE 1324
#define VDM_CONTMASTELEMEDGE 1325

#define VDM_CONTSLAVAREA     1333
#define VDM_CONTSLAVNODE     1334
#define VDM_CONTSLAVELEMFACE 1335
#define VDM_CONTSLAVELEMEDGE 1336
/* Added to store the conversion time for switching behavior between CQUAD4 and CSHEAR (PSHLPNL property) in Nx Nastran */
#define VDM_CONVERSIONTIME 1337
/* Added to store the conversion status for switching behavior between CQUAD4 and CSHEAR (PSHLPNL property) in Nx Nastran */
#define VDM_CONVERSIONSTATUS 1338
/* Modal effective mass summary */
#define VDM_EFFECTIVEMASSSUMMARY 1339
/* Modal effective mass */
#define VDM_EFFECTIVEMASS 1340
/* Modal participation factor */
#define VDM_PARTICIPATIONFACTOR 1341
/* Modal effective mass fraction */
#define VDM_MASSFRACTION 1342
/* Element association for unique faces identifier */
#define VDM_POLYUNIQUEFACE 1343

/* element entity load Heat radiation absorptivity */
#define VDM_LOADHRADABSORPEDGE     1350
#define VDM_LOADHRADABSORPEDGEINDX 1351
#define VDM_LOADHRADABSORPEDGETID  1352
#define VDM_LOADHRADABSORPFACE     1355
#define VDM_LOADHRADABSORPFACEINDX 1356
#define VDM_LOADHRADABSORPFACETID  1357

#define VDM_OUTELEM         2000
#define VDM_OUTELEMNODEAVGD 2001
#define VDM_OUTELEMNODEFREE 2002
#define VDM_OUTHISTELEM     2100
#define VDM_OUTELEMINDEX    2101
#define VDM_OUTNODE         3000
#define VDM_OUTHISTNODE     3100
#define VDM_OUTNODEINDEX    3101
#define VDM_OUTELEMNODE     4000
#define VDM_OUTHISTELEMNODE 4003
#define VDM_OUTHISTMODEL    5100
#define VDM_OUTHISTTIME     5101
#define VDM_OUTHISTSTEP     5102
#define VDM_OUTNODECOMP     5103
#define VDM_OUTELEMCOMP     5104
#define VDM_OUTELEMSECT     5105
#define VDM_OUTELEMLAYS     5106
#define VDM_OUTENTDOF       5107
#define VDM_OUTMODE         5108
#define VDM_OUTMODEINDEX    5109
#define VDM_OUTHISTMODE     5110
#define VDM_OUTPANEL        5111
#define VDM_OUTPANELINDEX   5112
#define VDM_OUTHISTPANEL    5113
#define VDM_OUTEDGEINDEX    5114
#define VDM_OUTFACEINDEX    5115
#define VDM_OUTELEMEIP      5116
#define VDM_OUTMATSIZE      5117
#define VDM_OUTMATEQUN      5118

#define VDM_ASURFTYPE      6000
#define VDM_ASURFSEGS      6001
#define VDM_ASURFSEGTYPE   6002
#define VDM_ASURFPNTS      6003
#define VDM_ASURFDBL       6004
#define VDM_ASURFNAME      6005
#define VDM_ASURFFACET     6006
#define VDM_ASURFFACETTYPE 6007
#define VDM_ASURFTRIM      6008
#define VDM_ASURFTRIMNUM   6009
#define VDM_ASURFNURBS     6010
#define VDM_ASURFNURBSNUM  6011
#define VDM_ASURFNURBSTRIM 6012

#define VDM_RBODY         6100
#define VDM_RBODYFLAG     6101
#define VDM_RBODYINT      6102
#define VDM_RBODYTYPE     6103
#define VDM_RBODYASURF    6104
#define VDM_RBODYELEMFACE 6105
#define VDM_RBODYELEMEDGE 6106
#define VDM_RBODYELEM     6107
#define VDM_RBODYNODE     6108
#define VDM_RBODYNODETYPE 6109

/* defines for modes */
#define VDM_DATASETCOLS_UNDEF -1
#define VDM_DATASETCOLS_UNSUP -2

/* modes */
#define VDM_NODATAVALMODE              1
#define VDM_RETAINCONNECTMODE          2
#define VDM_ABAODBNOCLOSEMODE          3
#define VDM_INCLUDEERRORMODE           4
#define VDM_ZLIBCOMPRESSMODE           5
#define VDM_ANSYS_PARTIDNUMBERINGMODE  6  /* Numbering the entities on the Ansys rst file based on the mode selection*/
#define VDM_CGNS_FAMILYSPECIFIED       7  /* Cgns Export: write BC info in a Family_t section under BASE*/
#define VDM_CGNS_MULTIZONESEXPORT      8  /* Cgns Model Export: write each 3D part mesh in single zone */
#define VDM_CGNS_ZONEFACECENTER        9  /* Cgns Model Export: Zone Gridconnectivity uses FaceCenter */
#define VDM_DPFLIB_ROTATETOGLOBALFRAME 10 /* Rotate the model to the global frame in DPFLib */
#define VDM_DPFLIB_CHECKVERSION        11 /* Check apdl version in DPFLib */
#define VDM_WRITEFORMAT                12 /* Vtu export Binary/Ascii/Appended:not yet done */
#define VDM_HEADERPRECISION            13 /* Vtu export header type = Uint64, Uint32 otherwise */
#define VDM_DPFLIB_ASSUMELICENSING     14 /* Assume that an Ansys license is available in DPFLib */
#define VDM_DEFERREDREADMODE           15 /* Deferred reading mode for indices */
#define VDM_CGNS_POLYASELEMENTASSOC    16 /* Cgns Model Export: PolyData is built from Elem association */
#define VDM_ABAODBAUTOUPDATE           17 /* Abaqus ODB: Upgrade .odb version automatically */
/* modes */

/* no data value */
#define VDM_NODATAVAL SYS_NODATAVAL
/* vtu export format types */
#define EXPORT_ASCII  0
#define EXPORT_BINARY 1
/* vtu export format types */
/* vtu header precision types */
#define HEADERUINT32 0
#define HEADERUINT64 1
/* vtu header precision types */

/* defines for get integer, string */
#define VDM_PHASE       1
#define VDM_SOURCE      2
#define VDM_SOURCE_SIZE 256
/* defines for get integer values */
#define VDM_PHASE_UNDEFINED         0
#define VDM_PHASE_OPENMODEL         1
#define VDM_PHASE_OPENMODELCOMPLETE 2
#define VDM_PHASE_OPENRESULT        3
/* defines for open */
#define VDM_OPENPLEX -1

/* defines for ids offset */
#define VDM_IDS_OFFSET   0
#define VDM_IDS_BASE     1
#define VDM_IDS_ABSOLUTE 2

/* defines for conventions */
#define VDM_CONVENTION_DEF             (VConventionType)0
#define VDM_CONVENTION_NOINTERLAMINAR  (VConventionType)1 << 0
#define VDM_CONVENTION_DOUBLERESULT    (VConventionType)1 << 1
#define VDM_CONVENTION_SPARSE          (VConventionType)1 << 2
#define VDM_CONVENTION_ALTPART         (VConventionType)1 << 3
#define VDM_CONVENTION_DOUBLE          (VConventionType)1 << 4
#define VDM_CONVENTION_STRESSINVARIANT (VConventionType)1 << 5
#define VDM_CONVENTION_PSHELLTHICK     (VConventionType)1 << 6
#define VDM_CONVENTION_DATASET32       (VConventionType)1 << 7
#define VDM_CONVENTION_NOINTPT         (VConventionType)1 << 8
#define VDM_CONVENTION_NOSETS          (VConventionType)1 << 9
#define VDM_CONVENTION_STARCD          (VConventionType)1 << 10
#define VDM_CONVENTION_EIP             (VConventionType)1 << 11
#define VDM_CONVENTION_ELEMCENT        (VConventionType)1 << 12
#define VDM_CONVENTION_FRAMEZERO       (VConventionType)1 << 13
#define VDM_CONVENTION_NOINTERNALSETS  (VConventionType)1 << 14
#define VDM_CONVENTION_NODEBC          (VConventionType)1 << 15
#define VDM_CONVENTION_WALLINTER       (VConventionType)1 << 16
#define VDM_CONVENTION_CONVERTPOLY     (VConventionType)1 << 17
#define VDM_CONVENTION_NOEQUIV         (VConventionType)1 << 18
#define VDM_CONVENTION_UNIRESULTTYPE   (VConventionType)1 << 19
#define VDM_CONVENTION_COMPLEX         (VConventionType)1 << 20
#define VDM_CONVENTION_LINEAREXTRAP    (VConventionType)1 << 21
#define VDM_CONVENTION_SECTNUM         (VConventionType)1 << 22 /* ODB enforce Link.Layers based on integration point numbering */
#define VDM_CONVENTION_NOPARINTER      (VConventionType)1 << 23
#define VDM_CONVENTION_NOCOMMENT       (VConventionType)1 << 24
/* to be deprecated. Use legacy export for CGNS files */
#define VDM_CONVENTION_CGNSLEGACYEXPORT (VConventionType)1 << 25
#define VDM_CONVENTION_NOHISTORYOUTPUT  (VConventionType)1 << 26
/* Downgrade of ELEMSYS_CYLINDRICAL_ALT to ELEMSYS_VECTOR for Siemens */
#define VDM_CONVENTION_MAPCYLINDRICALALTTOVECTOR (VConventionType)1 << 27
/* Cngs Export: enforce MIXED type even if model has a single element type */
#define VDM_CONVENTION_CGNSALWAYSMIXED (VConventionType)1 << 28
/* The shear panel stress is reported only as a scalar and not as tensor */
#define VDM_CONVENTION_ONLYSCALARSHEARPANELSTRESS ((VConventionType)1 << 29)
/* Cgns Export: use old formulae for Cell zone number defines for library dataset */
#define VDM_CONVENTION_CGNSLEGACYCELLZONENUMBER ((VConventionType)1 << 30)
/* Cgns Export: write all 2D element face in a single Element_t section */
#define VDM_CONVENTION_CGNSSINGLENGONSECTION2D ((VConventionType)1 << 31)
/* No field output read in odb reader */
#define VDM_CONVENTION_NOFIELDOUTPUT ((VConventionType)1 << 32)
/* using the gasket status from the solver directly instead of mapping into VDM mapping*/
#define VDM_CONVENTION_ORIGINAL_GASKET_STATUS ((VConventionType)1 << 33)

#define VDM_LIBDATASET_PUSH 1
#define VDM_LIBDATASET_POP  2
#define VDM_LIBDATASET_TOP  3

/* defines for object types */
#define VDM_ATTRIBUTE        6000
#define VDM_DATASET          6001
#define VDM_LIBRARY          6002
#define VDM_DATAFUN          6003
#define VDM_LMAN             6004
#define VDM_DATAIPC          6005
#define VDM_ELEMSECT         6006
#define VDM_UNRECOGNIZEDDATA 6007

/* defines for set and get string */
#define VDM_OPENFOAM_ETC_PATH     1
#define VDM_LIBRARY_PATH          2
#define VDM_ABALIB_UPGRADEODBNAME 3

/* Ansys Part Id numbering types */
#define ANSLIB_PARTIDUSINGLEGACYMETHOD        0 /* Numbering the entities on the Ansys rst file based on the legacy method*/
#define ANSLIB_PARTIDUSINGSECNUM              1 /* Numbering the entities on the Ansys rst file based on the section number*/
#define ANSLIB_PARTIDUSINGREALCONSTREF_NUMBER 2
/* Numbering the entities on the Ansys rst file based on the real constant reference number*/
#define ANSLIB_PARTIDUSINGELEM_TYPE 3 /* Numbering the entities on the Ansys rst file based on the element type number*/
/* Ansys Part Id numbering types */

#endif
