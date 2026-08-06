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
/* VisTools macro definitions header file */

#ifndef VISDEFS_DEF
#define VISDEFS_DEF

#include "sam/base/basedefs.h"
#include "sam/vis/asurfdefs.h"
#include "sam/vis/connectdefs.h"
#include "sam/vis/cpairdefs.h"
#include "sam/vis/elemdatdefs.h"
#include "sam/vis/epropdefs.h"
#include "sam/vis/gpropdefs.h"
#include "sam/vis/gridfundefs.h"
#include "sam/vis/groupdefs.h"
#include "sam/vis/icasedefs.h"
#include "sam/vis/idtrandefs.h"
#include "sam/vis/lcasedefs.h"
#include "sam/vis/mpropdefs.h"
#include "sam/vis/mcasedefs.h"
#include "sam/vis/rcasedefs.h"
#include "sam/vis/rbodydefs.h"
#include "sam/vis/spropdefs.h"
#include "sam/vis/statedefs.h"
#include "sam/vis/tcurvedefs.h"
#include "sam/vis/unitsdefs.h"

typedef struct vis_ASurf vis_ASurf;
typedef struct vis_BandOpt vis_BandOpt;
typedef struct vis_BeamSectCalculator vis_BeamSectCalculator;
typedef struct vis_CHash vis_CHash;
typedef struct vis_Connect vis_Connect;
typedef struct vis_CoordSys vis_CoordSys;
typedef struct vis_CPair vis_CPair;
typedef struct vis_DataInt vis_DataInt;
typedef struct vis_ElemChk vis_ElemChk;
typedef struct vis_ElemDat vis_ElemDat;
typedef struct vis_EProp vis_EProp;
typedef struct vis_GeomFun vis_GeomFun;
typedef struct vis_GProp vis_GProp;
typedef struct vis_GridFun vis_GridFun;
typedef struct vis_Group vis_Group;
typedef struct vis_History vis_History;
typedef struct vis_ICase vis_ICase;
typedef struct vis_IdTran vis_IdTran;
typedef struct vis_LCase vis_LCase;
typedef struct vis_MassPrp vis_MassPrp;
typedef struct vis_MeshCon vis_MeshCon;
typedef struct vis_MeshMetric vis_MeshMetric;
typedef struct vis_MCase vis_MCase;
typedef struct vis_Model vis_Model;
typedef struct vis_ModelChk vis_ModelChk;
typedef struct vis_MProp vis_MProp;
typedef struct vis_Range vis_Range;
typedef struct vis_RBody vis_RBody;
typedef struct vis_RCase vis_RCase;
typedef struct vis_RedMat vis_RedMat;
typedef struct vis_ResultInformation vis_ResultInformation;
typedef struct vis_ResultMetadata vis_ResultMetadata;
typedef struct vis_RProp vis_RProp;
typedef struct vis_Space vis_Space;
typedef struct vis_SProp vis_SProp;
typedef struct vis_State vis_State;
typedef struct vis_TCurve vis_TCurve;
typedef struct vis_TriangleGeneration vis_TriangleGeneration;
typedef struct vis_Units vis_Units;
typedef struct vis_ZState vis_ZState;
typedef struct vis_WriterFun vis_WriterFun;

/* defines for function prototypes */
typedef void(VTriMeshDebugFunc)(vis_MeshCon*, Vobject*);
typedef void(VTriMeshMonitorFunc)(Vobject*, Vobject*);
typedef void(VTriMeshSizingFunc)(Vobject*, Vobject*, /*C#size3*/ Vdouble[3], Vdouble*);
typedef void(VTriMeshASizingFunc)(Vobject*, Vobject*, /*C#size3*/ Vdouble[3], Vdouble (*)[3]);

/* defines for max isosurface clipping planes */
#define VIS_MAXISOCLIP 6

/* defines for max primlength, array of tris, 12*12*2*3 */
#define VIS_MAXPRIMLENGTH 864

/* defines for max number of data rows */
#define VIS_MAXDATAROWS 16

/* defines for max dimension for refined or p-element */
#define VIS_MAXELEMIJK  13
#define VIS_MAXEDGENODE 13
#define VIS_MAXFACENODE 1024
#define VIS_MAXCELLNODE 2197
#define VIS_MAXELEMNODE 4095
#define VIS_MAXIJK      4096
#define VIS_MAX_MAXI    32767
#define VIS_MAX_MAXJ    32767
#define VIS_MAX_MAXK    32767
/* this is a practical limit for stack arrays */
#define VIS_MAXNODEELEM 1000
/* define for max number of sections */
#define VIS_MAXSECTION 4096

/* defines for on - off flag */
#define VIS_OFF 0
#define VIS_ON  1

/* defines for error flags */
#define VIS_ERROR_NONE       0
#define VIS_ERROR_VALUE      1
#define VIS_ERROR_ENUM       2
#define VIS_ERROR_OBJECTTYPE 3
#define VIS_ERROR_MEMORY     4
#define VIS_ERROR_NULLOBJECT 5
#define VIS_ERROR_FILE       6
#define VIS_ERROR_COMPUTE    7
#define VIS_ERROR_OPERATION  8

/* element shape */
#define VIS_SHAPEUNDEFINED -1
#define VIS_SHAPEPOINT     0
#define VIS_SHAPELINE      1
#define VIS_SHAPETRI       2
#define VIS_SHAPEQUAD      3
#define VIS_SHAPETET       4
#define VIS_SHAPEPYR       5
#define VIS_SHAPEWED       6
#define VIS_SHAPEHEX       7
#define VIS_SHAPEPOLYGON   8
#define VIS_SHAPEPOLYHED   9
/* element shape */

/* node-specific association types (not used for elements) */
#define VIS_SPCFLAGS 7 /* Node single point constraint flags */
#define VIS_CREFID   9 /* Reference coordinate system identifier */
/* node-specific association types */

/* element association types */
/* only add to the end of these, do not change values
   since SurfMesh, TetMesh files may contain them */
#define VIS_FEATYPE        0
#define VIS_MATLID         1
#define VIS_PROPID         2
#define VIS_PARTID         3
#define VIS_CSYSID         4
#define VIS_IBLANK         6
#define VIS_EXTTYPE        8
#define VIS_USERID         10
#define VIS_FEATECH        11
#define VIS_FEASPEC        12
#define VIS_CMATID         13
#define VIS_CMATFLAG       14
#define VIS_MISCID0        15
#define VIS_MISCID1        16
#define VIS_MISCID2        17
#define VIS_MISCID3        18
#define VIS_MISCID4        19
#define VIS_MISCID5        20
#define VIS_MISCID6        21
#define VIS_MISCID7        22
#define VIS_MISCID8        23
#define VIS_FEATWOD        25
#define VIS_ENDATOPO       26
#define VIS_ENDBTOPO       27
#define VIS_ENDACON        28
#define VIS_ENDBCON        29
#define VIS_ORIENTINDEX    30 /* orientation node for 1D element system definition */
#define VIS_GEOVERT        33
#define VIS_GEOEDGE        34
#define VIS_GEOFACE        35
#define VIS_GEOBODY        36
#define VIS_PINFLAGS       41
#define VIS_DOMAIN         42
#define VIS_SEID           43
#define VIS_SYMMID         44 /* symmetry group Id */
#define VIS_POLYUNIQUEFACE 46 /* gives the unique face number. it's signed and used for polys description in fluid mesh */
/* element association types */

/* node association types */
/* only add to the end of these, do not change values
   since SurfMesh, TetMesh files may contain them */
#define VIS_NODE_FEATYPE  VIS_FEATYPE
#define VIS_NODE_PARTID   VIS_PARTID
#define VIS_NODE_CSYSID   VIS_CSYSID
#define VIS_NODE_IBLANK   VIS_IBLANK
#define VIS_NODE_SPCFLAGS VIS_SPCFLAGS
#define VIS_NODE_CREFID   VIS_CREFID
#define VIS_NODE_USERID   VIS_USERID
#define VIS_NODE_MISCID0  VIS_MISCID0
#define VIS_NODE_MISCID1  VIS_MISCID1
#define VIS_NODE_MISCID2  VIS_MISCID2
#define VIS_NODE_MISCID3  VIS_MISCID3
#define VIS_NODE_MISCID4  VIS_MISCID4
#define VIS_NODE_MISCID5  VIS_MISCID5
#define VIS_NODE_MISCID6  VIS_MISCID6
#define VIS_NODE_MISCID7  VIS_MISCID7
#define VIS_NODE_MISCID8  VIS_MISCID8
/* node association types */
#define VIS_MAXNODEASSOC 24

#define VIS_COLORID         5
#define VIS_MISCID          15
#define VIS_EXTNAMEA        31
#define VIS_EXTNAMEB        32
#define VIS_INTERN          37
#define VIS_INTERN0         37
#define VIS_INTERN1         38
#define VIS_INTERN2         39
#define VIS_INTERN3         40
#define VIS_FEATECHMODIFIED 45 /* flag on/off to know if featech, unknown in the original model, was modified by prosolve */
#define VIS_QUALFLAG        24 /* Negative jacobian flag. Used in one example and test programs, but never set */

/* need to add association name to name.c */
#define VIS_MAXASSOC 47

/* Arbitrary maximum number of associations per entity */
#define VIS_MAXASSOC_PER_ENTITY 10000

/* node types */
#define VIS_NODE_UNDEFINED 0
#define VIS_NODE_GRID      1
#define VIS_NODE_SCALAR    2
/* node types */

/* element types */
#define VIS_ELEM_UNDEFINED     SYS_ELEM_UNDEFINED
#define VIS_ELEM_SOLID         SYS_ELEM_SOLID
#define VIS_ELEM_SHELL         SYS_ELEM_SHELL
#define VIS_ELEM_MEMBRANE      SYS_ELEM_MEMBRANE
#define VIS_ELEM_BEAM          SYS_ELEM_BEAM
#define VIS_ELEM_TRUSS         SYS_ELEM_TRUSS
#define VIS_ELEM_INFINITE      SYS_ELEM_INFINITE
#define VIS_ELEM_GAP           SYS_ELEM_GAP
#define VIS_ELEM_JOINT         SYS_ELEM_JOINT
#define VIS_ELEM_SPRINGDASHPOT SYS_ELEM_SPRINGDASHPOT
#define VIS_ELEM_RIGID         SYS_ELEM_RIGID
#define VIS_ELEM_CONSTRAINT    SYS_ELEM_CONSTRAINT
#define VIS_ELEM_PLOT          SYS_ELEM_PLOT
#define VIS_ELEM_MASS          SYS_ELEM_MASS
#define VIS_ELEM_INTER         SYS_ELEM_INTER
#define VIS_ELEM_SUPER         SYS_ELEM_SUPER
#define VIS_ELEM_REINFORCEMENT SYS_ELEM_REINFORCEMENT
/* element types */
#define VIS_ELEM_MAX SYS_ELEM_MAX

/* defines for field types */
#define VIS_SCALAR        0
#define VIS_VECTOR        1
#define VIS_TENSOR        2
#define VIS_GENERALTENSOR 3
#define VIS_ELEMRES       5
#define VIS_SIXDOF        9
#define VIS_SCALARS       10 /* scalars must be at the end */
#define VIS_SCALARS1      11
#define VIS_SCALARS2      12
#define VIS_SCALARS3      13
#define VIS_SCALARS4      14
#define VIS_SCALARS5      15
#define VIS_SCALARS6      16
#define VIS_SCALARS7      17
#define VIS_SCALARS8      18
#define VIS_SCALARS9      19
#define VIS_SCALARS10     20
#define VIS_SCALARS11     21
#define VIS_SCALARS12     22
#define VIS_SCALARS13     23
#define VIS_SCALARS14     24
#define VIS_SCALARS15     25
#define VIS_SCALARS16     26
#define VIS_SCALARS17     27
#define VIS_SCALARS18     28
#define VIS_SCALARS19     29
#define VIS_SCALARS20     30
#define VIS_SCALARS21     31
#define VIS_SCALARS22     32
#define VIS_SCALARS23     33
#define VIS_SCALARS24     34
#define VIS_SCALARS25     35
#define VIS_SCALARS26     36
#define VIS_SCALARS27     37
#define VIS_SCALARS28     38
#define VIS_SCALARS29     39
#define VIS_SCALARS30     40
#define VIS_SCALARS31     41
#define VIS_SCALARS32     42
#define VIS_SCALARS33     43
#define VIS_SCALARS34     44
#define VIS_SCALARS35     45
#define VIS_SCALARS36     46
#define VIS_SCALARS37     47
#define VIS_SCALARS38     48
#define VIS_SCALARS39     49
#define VIS_SCALARS40     50
#define VIS_SCALARS41     51
#define VIS_SCALARS42     52
#define VIS_SCALARS43     53
#define VIS_SCALARS44     54
#define VIS_SCALARS45     55
#define VIS_SCALARS46     56
#define VIS_SCALARS47     57
#define VIS_SCALARS48     58
#define VIS_SCALARS49     59
#define VIS_SCALARS50     60
#define VIS_SCALARS51     61
#define VIS_SCALARS52     62
#define VIS_SCALARS53     63
#define VIS_SCALARS54     64
#define VIS_SCALARS55     65
#define VIS_SCALARS56     66
#define VIS_SCALARS57     67
#define VIS_SCALARS58     68
#define VIS_SCALARS59     69
#define VIS_SCALARS60     70
#define VIS_SCALARS61     71
#define VIS_SCALARS62     72
#define VIS_SCALARS63     73
#define VIS_SCALARS64     74
#define VIS_SCALARS65     75
#define VIS_SCALARS66     76
#define VIS_SCALARS67     77
#define VIS_SCALARS68     78
#define VIS_SCALARS69     79
#define VIS_SCALARS70     80
#define VIS_SCALARS71     81
#define VIS_SCALARS72     82
#define VIS_SCALARS73     83
#define VIS_SCALARS74     84
#define VIS_SCALARS75     85
#define VIS_SCALARS76     86
#define VIS_SCALARS77     87
#define VIS_SCALARS78     88
#define VIS_SCALARS79     89
#define VIS_SCALARS80     90
#define VIS_SCALARS81     91
#define VIS_SCALARS82     92
#define VIS_SCALARS83     93
#define VIS_SCALARS84     94
#define VIS_SCALARS85     95
#define VIS_SCALARS86     96
#define VIS_SCALARS87     97
#define VIS_SCALARS88     98
#define VIS_SCALARS89     99
#define VIS_SCALARS90     100
#define VIS_SCALARS91     101
#define VIS_SCALARS92     102
#define VIS_SCALARS93     103
#define VIS_SCALARS94     104
#define VIS_SCALARS95     105
#define VIS_SCALARS96     106
#define VIS_SCALARS97     107
#define VIS_SCALARS98     108
#define VIS_SCALARS99     109
#define VIS_SCALARS100    110
#define VIS_SCALARS101    111
#define VIS_SCALARS102    112
#define VIS_SCALARS103    113
#define VIS_SCALARS104    114
#define VIS_SCALARS105    115
#define VIS_SCALARS106    116
#define VIS_SCALARS107    117
#define VIS_SCALARS108    118
#define VIS_SCALARS109    119
#define VIS_SCALARS110    120
#define VIS_SCALARS111    121
#define VIS_SCALARS112    122
#define VIS_SCALARS113    123
#define VIS_SCALARS114    124
#define VIS_SCALARS115    125
#define VIS_SCALARS116    126
#define VIS_SCALARS117    127
#define VIS_SCALARS118    128
#define VIS_SCALARS119    129
#define VIS_SCALARS120    130
#define VIS_SCALARS121    131
#define VIS_SCALARS122    132
#define VIS_SCALARS123    133
#define VIS_SCALARS124    134
#define VIS_SCALARS125    135
#define VIS_SCALARS126    136
#define VIS_SCALARS127    137
#define VIS_SCALARS128    138
#define VIS_SCALARS129    139
#define VIS_SCALARS130    140
#define VIS_SCALARS131    141
#define VIS_SCALARS132    142
#define VIS_SCALARS133    143
#define VIS_SCALARS134    144
#define VIS_SCALARS135    145
#define VIS_SCALARS136    146
#define VIS_SCALARS137    147
#define VIS_SCALARS138    148
#define VIS_SCALARS139    149
#define VIS_SCALARS140    150
#define VIS_SCALARS141    151
#define VIS_SCALARS142    152
#define VIS_SCALARS143    153
#define VIS_SCALARS144    154
#define VIS_SCALARS145    155
#define VIS_SCALARS146    156
#define VIS_SCALARS147    157
#define VIS_SCALARS148    158
#define VIS_SCALARS149    159
#define VIS_SCALARS150    160
#define VIS_SCALARS151    161
#define VIS_SCALARS152    162
#define VIS_SCALARS153    163
#define VIS_SCALARS154    164
#define VIS_SCALARS155    165
#define VIS_SCALARS156    166
#define VIS_SCALARS157    167
#define VIS_SCALARS158    168
#define VIS_SCALARS159    169
#define VIS_SCALARS160    170
#define VIS_SCALARS161    171
#define VIS_SCALARS162    172
#define VIS_SCALARS163    173
#define VIS_SCALARS164    174
#define VIS_SCALARS165    175
#define VIS_SCALARS166    176
#define VIS_SCALARS167    177
#define VIS_SCALARS168    178
#define VIS_SCALARS169    179
#define VIS_SCALARS170    180
#define VIS_SCALARS171    181
#define VIS_SCALARS172    182
#define VIS_SCALARS173    183
#define VIS_SCALARS174    184
#define VIS_SCALARS175    185
#define VIS_SCALARS176    186
#define VIS_SCALARS177    187
#define VIS_SCALARS178    188
#define VIS_SCALARS179    189
#define VIS_SCALARS180    190
#define VIS_SCALARS181    191
#define VIS_SCALARS182    192
#define VIS_SCALARS183    193
#define VIS_SCALARS184    194
#define VIS_SCALARS185    195
#define VIS_SCALARS186    196
#define VIS_SCALARS187    197
#define VIS_SCALARS188    198
#define VIS_SCALARS189    199
#define VIS_SCALARS190    200
#define VIS_SCALARS191    201
#define VIS_SCALARS192    202
#define VIS_SCALARS193    203
#define VIS_SCALARS194    204
#define VIS_SCALARS195    205
#define VIS_SCALARS196    206
#define VIS_SCALARS197    207
#define VIS_SCALARS198    208
#define VIS_SCALARS199    209
#define VIS_SCALARS200    210
#define VIS_SCALARS201    211
#define VIS_SCALARS202    212
#define VIS_SCALARS203    213
#define VIS_SCALARS204    214
#define VIS_SCALARS205    215
#define VIS_SCALARS206    216
#define VIS_SCALARS207    217
#define VIS_SCALARS208    218
#define VIS_SCALARS209    219
#define VIS_SCALARS210    220
#define VIS_SCALARS211    221
#define VIS_SCALARS212    222
#define VIS_SCALARS213    223
#define VIS_SCALARS214    224
#define VIS_SCALARS215    225
#define VIS_SCALARS216    226
#define VIS_SCALARS217    227
#define VIS_SCALARS218    228
#define VIS_SCALARS219    229
#define VIS_SCALARS220    230
#define VIS_SCALARS221    231
#define VIS_SCALARS222    232
#define VIS_SCALARS223    233
#define VIS_SCALARS224    234
#define VIS_SCALARS225    235
#define VIS_SCALARS226    236
#define VIS_SCALARS227    237
#define VIS_SCALARS228    238
#define VIS_SCALARS229    239
#define VIS_SCALARS230    240
#define VIS_SCALARS231    241
#define VIS_SCALARS232    242
#define VIS_SCALARS233    243
#define VIS_SCALARS234    244
#define VIS_SCALARS235    245
#define VIS_SCALARS236    246
#define VIS_SCALARS237    247
#define VIS_SCALARS238    248
#define VIS_SCALARS239    249
#define VIS_SCALARS240    250
#define VIS_SCALARS241    251
#define VIS_SCALARS242    252
#define VIS_SCALARS243    253
#define VIS_SCALARS244    254
#define VIS_SCALARS245    255
#define VIS_SCALARS246    256
#define VIS_SCALARS247    257
#define VIS_SCALARS248    258
#define VIS_SCALARS249    259
#define VIS_SCALARS250    260
#define VIS_SCALARS251    261
#define VIS_SCALARS252    262
#define VIS_SCALARS253    263
#define VIS_SCALARS254    264
#define VIS_SCALARS255    265
#define VIS_SCALARS256    266

#define VIS_MAXDATATYPEROWS 256

/* state derived quantities */
/* the derived types for a field type need to be consecutive */
#define VIS_VECTOR_X      326
#define VIS_VECTOR_Y      327
#define VIS_VECTOR_Z      328
#define VIS_VECTOR_MAG    329
#define VIS_VECTOR_VECTOR VIS_VECTOR

#define VIS_TENSOR_XX          331 /* beginning of scalar derived */
#define VIS_TENSOR_YY          332
#define VIS_TENSOR_ZZ          333
#define VIS_TENSOR_XY          334
#define VIS_TENSOR_YZ          335
#define VIS_TENSOR_ZX          336
#define VIS_TENSOR_MEAN        337
#define VIS_TENSOR_VONMISES    338
#define VIS_TENSOR_OCTAHEDRAL  339
#define VIS_TENSOR_DETERMINANT 340
#define VIS_TENSOR_MAXSHEAR    341
#define VIS_TENSOR_ANGSHEAR    342
#define VIS_TENSOR_MINPRINC    343
#define VIS_TENSOR_MIDPRINC    344
#define VIS_TENSOR_MAXPRINC    345
#define VIS_TENSOR_MINPRINCDEV 346
#define VIS_TENSOR_MIDPRINCDEV 347
#define VIS_TENSOR_MAXPRINCDEV 348
#define VIS_TENSOR_INTENSITY   349
#define VIS_TENSOR_EQUDIRECT   350
#define VIS_TENSOR_VONMISES_E  351 /* end of scalar derived */
#define VIS_TENSOR_PRINC       352
#define VIS_TENSOR_PRINCDIRCOS 353
#define VIS_TENSOR_TENSOR      VIS_TENSOR

#define VIS_GENERALTENSOR_GENERALTENSOR VIS_GENERALTENSOR
#define VIS_GENERALTENSOR_XX            361
#define VIS_GENERALTENSOR_XY            362
#define VIS_GENERALTENSOR_XZ            363
#define VIS_GENERALTENSOR_YX            364
#define VIS_GENERALTENSOR_YY            365
#define VIS_GENERALTENSOR_YZ            366
#define VIS_GENERALTENSOR_ZX            367
#define VIS_GENERALTENSOR_ZY            368
#define VIS_GENERALTENSOR_ZZ            369
#define VIS_GENERALTENSOR_SYM           370
#define VIS_GENERALTENSOR_XVEC          371
#define VIS_GENERALTENSOR_YVEC          372
#define VIS_GENERALTENSOR_ZVEC          373

#define VIS_ELEMRES_SHELL_NXX 381
#define VIS_ELEMRES_SHELL_NYY 382
#define VIS_ELEMRES_SHELL_NXY 383
#define VIS_ELEMRES_SHELL_MXX 384
#define VIS_ELEMRES_SHELL_MYY 385
#define VIS_ELEMRES_SHELL_MXY 386
#define VIS_ELEMRES_SHELL_QXZ 387
#define VIS_ELEMRES_SHELL_QYZ 388

#define VIS_ELEMRES_BEAM_NXX 391
#define VIS_ELEMRES_BEAM_MYY 392
#define VIS_ELEMRES_BEAM_MZZ 393
#define VIS_ELEMRES_BEAM_T   394
#define VIS_ELEMRES_BEAM_QXY 395
#define VIS_ELEMRES_BEAM_QZX 396
#define VIS_ELEMRES_BEAM_TB  397

#define VIS_ELEMRES_SPRINGDASHPOT_F  400
#define VIS_ELEMRES_SPRINGDASHPOT_FX 400
#define VIS_ELEMRES_SPRINGDASHPOT_FY 401
#define VIS_ELEMRES_SPRINGDASHPOT_FZ 402
#define VIS_ELEMRES_SPRINGDASHPOT_MX 403
#define VIS_ELEMRES_SPRINGDASHPOT_MY 404
#define VIS_ELEMRES_SPRINGDASHPOT_MZ 405

#define VIS_SIXDOF_SIXDOF VIS_SIXDOF
#define VIS_SIXDOF_TX     411
#define VIS_SIXDOF_TY     412
#define VIS_SIXDOF_TZ     413
#define VIS_SIXDOF_RX     414
#define VIS_SIXDOF_RY     415
#define VIS_SIXDOF_RZ     416
#define VIS_SIXDOF_TMAG   417
#define VIS_SIXDOF_RMAG   418
#define VIS_SIXDOF_TVEC   419
#define VIS_SIXDOF_RVEC   420

#define VIS_SCALARS_SCALAR VIS_SCALAR
#define VIS_SCALARS_0      421
#define VIS_SCALARS_1      422
#define VIS_SCALARS_2      423
#define VIS_SCALARS_3      424
#define VIS_SCALARS_4      425
#define VIS_SCALARS_5      426
#define VIS_SCALARS_6      427
#define VIS_SCALARS_7      428
#define VIS_SCALARS_8      429
#define VIS_SCALARS_9      430
#define VIS_SCALARS_10     431
#define VIS_SCALARS_11     432
#define VIS_SCALARS_12     433
/* state derived quantities */

#define VIS_DERIVE_MAX VIS_SCALARS_0 + 256 /* search to find changes */

/* defines for isosurface clipping type*/
#define VIS_ISOCLIP_NONE 0
#define VIS_ISOCLIP_FULL 1
#define VIS_ISOCLIP_PART 2

/* defines for format types */
#define VIS_EFORMAT  0
#define VIS_FFORMAT  1
#define VIS_IFORMAT  2
#define VIS_GFORMAT  3
#define VIS_XFORMAT  4
#define VIS_E2FORMAT 5
#define VIS_E3FORMAT 6
#define VIS_GXFORMAT 7
#define VIS_FMFORMAT 8

/* defines for listing types */
#define VIS_LISTING 1
#define VIS_SUMMARY 2

/* defines for value flags,
   unique among markers, values and annotation */
#define VIS_VALUEBRACKET 1 << 10
#define VIS_VALUEBACK    1 << 11
#define VIS_DOFBACK      1 << 12

/* defines for element representation display type */
#define VIS_ELEMREP_LINE   0
#define VIS_ELEMREP_SEMI   1
#define VIS_ELEMREP_SOLID  2
#define VIS_ELEMREP_BITMAP 3
#define VIS_ELEMREP_PIXMAP 4
#define VIS_ELEMREP_VALUE  5

/* defines for element axes display */
#define VIS_ELEMAXES_NONE 0
#define VIS_ELEMAXES_XYZ  7
#define VIS_ELEMAXES_X    1
#define VIS_ELEMAXES_Y    1 << 1
#define VIS_ELEMAXES_Z    1 << 2

/* defines for marker type */
#define VIS_TRIANGLE    0
#define VIS_SQUARE      1
#define VIS_DIAMOND     2
#define VIS_HOURGLASS   3
#define VIS_PLUSSIGN    4
#define VIS_CIRCLE      5
#define VIS_DOT         6
#define VIS_POINT       7
#define VIS_DASH        8
#define VIS_SPHERE      9
#define VIS_BOX         10
#define VIS_TETRAHEDRON 11
#define VIS_OCTAHEDRON  12
#define VIS_POINT2      13
#define VIS_POINT4      14
#define VIS_CIRCLE3     15
#define VIS_CIRCLE5     16
#define VIS_CIRCLE7     17
#define VIS_CIRCLE9     18
#define VIS_METER       19
#define VIS_MARKERMAX   19

/* defines for linestyles */
#define VIS_SOLID    0
#define VIS_DASHDASH 1
#define VIS_DOTDOT   2
#define VIS_DOTDASH  3
#define VIS_CYLINDER 4

/* defines for vector flags,
   unique among markers, values and annotation */
#define VIS_VECTORDOUBLEHEAD    1 << 1
#define VIS_VECTORNOHEAD        1 << 3
#define VIS_VECTORTAIL          1 << 4
#define VIS_VECTORTAILREGISTER  1 << 5
#define VIS_VECTORPUSHHEAD      1 << 7
#define VIS_VECTORNOCAP         1 << 8
#define VIS_VECTORROUND         1 << 9
#define VIS_VECTORDOUBLEHEADPEN 1 << 15
#define VIS_VECTORDOUBLEHEADADD 1 << 16
/* defines for vector type */
#define VIS_VECTORLINE     0
#define VIS_VECTORCYLINDER 1
#define VIS_VECTORUMBRELLA 2

/* defines for tensor flags,
   unique among markers, values and annotation */
#define VIS_TENSORBOX    1 << 0
#define VIS_TENSORDIRECT 1 << 2
#define VIS_TENSORSHEAR  1 << 6
/* defines for tensor type */
#define VIS_TENSORCUBE      0
#define VIS_TENSORELLIPSOID 1
#define VIS_TENSORCROWSFEET 2
/* defines for shrink type */
#define VIS_SHRINKNONE    0
#define VIS_SHRINKENTITY  1
#define VIS_SHRINKELEMENT 2
/* defines for mapcolor type */
#define VIS_MAPCOLOR_NONE     0
#define VIS_MAPCOLOR_CONSTANT 1
#define VIS_MAPCOLOR_SMOOTH   2
/* defines for component type */
#define VIS_COMPONENT_PRINCIPAL 0
#define VIS_COMPONENT_BASIC     1
#define VIS_COMPONENT_MAXSHEAR  2

/* defines for axis flags,
   unique among markers, values and annotation */
#define VIS_BACKPLANEFLIP 1 << 13
/* create polyhedron primitives */
#define VIS_CREATEPOLYHEDRON 1 << 14
/* cap cylinder linestyle */
#define VIS_CYLINDERCAP 1 << 17

/* defines for isoval types */
#define VIS_ISOVALPOINT   0
#define VIS_ISOVALLINE    1
#define VIS_ISOVALSURFACE 2
#define VIS_ISOVALVOLUME  3
#define VIS_ISOVALFRINGE  4
#define VIS_ISOVALTONE    5
#define VIS_ISOVALGOURAUD 6
#define VIS_ISOVALTEXTURE 7

#define VIS_INTERP_SHAPE 0
#define VIS_INTERP_CLAMP 1

#define VIS_PRIM_POLY  0
#define VIS_PRIM_MULT  1
#define VIS_PRIM_ARRAY 1
#define VIS_PRIM_STRIP 2

/* defines for isoval flags */
#define VIS_ISOVALACCENT 1 << 0

/* defines for topology types */
#define VIS_TOPOCRITICALPOINT 0
#define VIS_TOPOVORTEXCORE    1
#define VIS_TOPODIVIDE        2

/* defines for stream types */
#define VIS_STREAMLINE    0
#define VIS_STREAMPOINT   1
#define VIS_STREAMRIBBON  2
#define VIS_STREAMTUBE    3
#define VIS_STREAMTWIST   4
#define VIS_STREAMBOX     5
#define VIS_STREAMELLIPSE 6

/* defines for stream exit status */
#define VIS_STREAMZERO        0
#define VIS_STREAMEXIT        1
#define VIS_STREAMBRANCH      2
#define VIS_STREAMMAXSTEPS    3
#define VIS_STREAMMAXEXCEEDED 3
#define VIS_STREAMCOMPUTE     4

/* defines for general flags */
#define VIS_TIMEREVERSE 1 << 20

/* defines for shade type */
#define VIS_NOSHADE     0
#define VIS_FLATSHADE   1
#define VIS_VERTEXSHADE 2
/* defines for size type */
#define VIS_SIZEWORLD  0
#define VIS_SIZEDEVICE 1

/* defines for position */
#define VIS_RIGHT       0
#define VIS_LEFT        1
#define VIS_BOTTOM      2
#define VIS_TOP         3
#define VIS_CENTER      4
#define VIS_BOTTOMRIGHT 5
#define VIS_TOPRIGHT    6
#define VIS_BOTTOMLEFT  7
#define VIS_TOPLEFT     8
/* defines for drag */
#define VIS_DRAG_INIT 1
#define VIS_DRAG_MOVE 2
#define VIS_DRAG_TERM 3
/* defines for actions */
#define VIS_ACTION_NONE      0
#define VIS_ACTION_TRANSLATE 1
#define VIS_ACTION_SCALE     2
#define VIS_ACTION_ROTATE    3

/* defines for normal type */
#define VIS_NODATA     0
#define VIS_CELLDATA   1
#define VIS_VERTEXDATA 2

/* defines for material type */
#define VIS_MAT_ISOTROPIC   0
#define VIS_MAT_LAMINA      1
#define VIS_MAT_ORTHOTROPIC 2
#define VIS_MAT_ANISOTROPIC 3

/* locations */
#define VIS_ELEMLOC_CENTROID 0
#define VIS_ELEMLOC_CORNERS  1
#define VIS_ELEMLOC_NODES    2
#define VIS_ELEMLOC_NATIVE   3

/* mesh generation parameters */
#define VIS_MESH_MAXI             1
#define VIS_MESH_SHAPE            2
#define VIS_MESH_NUMELEMENTS      3
#define VIS_MESH_INWARD           4
#define VIS_MESH_EDGELENGTH       5
#define VIS_MESH_MINEDGELENGTH    6
#define VIS_MESH_SPANANGLE        7
#define VIS_MESH_BOUNDREFINE      8
#define VIS_MESH_MINANGLE         9
#define VIS_MESH_LAGRANGE         10
#define VIS_MESH_GROWTHRATE       11
#define VIS_MESH_CHECK            12
#define VIS_MESH_MINFEATLENGTH    13
#define VIS_MESH_COARSEN          14
#define VIS_MESH_JACOBIANRATIO    15
#define VIS_MESH_MIDSIDEPROJ      16
#define VIS_MESH_MIDSIDEQUAL      17
#define VIS_MESH_MINFEATANGLE     18
#define VIS_MESH_REPAIRINCONS     19
#define VIS_MESH_QUALTARGET       20
#define VIS_MESH_QUALTYPE         21
#define VIS_MESH_INTERREFINE      22
#define VIS_MESH_CHORDHEIGHT      23
#define VIS_MESH_MINHEALLENGTH    24
#define VIS_MESH_MINHEALANGLE     25
#define VIS_MESH_COMPUTENORMAL    26
#define VIS_MESH_NUMLAYERS        27
#define VIS_MESH_LAYERINITLENGTH  28
#define VIS_MESH_LAYERGROWTHRATE  29
#define VIS_MESH_REFINESMOOTH     30
#define VIS_MESH_MAXEDGELENGTH    31
#define VIS_MESH_MAPDETECT        32
#define VIS_MESH_MAPANGLE         33
#define VIS_MESH_MAPRECTONLY      34
#define VIS_MESH_MAXRECTANGLE     35 /* deprecate this one */
#define VIS_MESH_MAXQUADANGLE     35
#define VIS_MESH_UNCONNECT        36
#define VIS_MESH_UNCONNECTLENGTH  37
#define VIS_MESH_UNCONNECTPROJECT 38
#define VIS_MESH_PROGRESS         39
#define VIS_MESH_MAXPROXRATIO     40

#define VIS_MESH_DELAUNAY          42
#define VIS_MESH_QUALMINANG        43
#define VIS_MESH_QUALEDGEALT       44
#define VIS_MESH_REFINETEMPLATE    45
#define VIS_MESH_MAXANGLE          46
#define VIS_MESH_NONOBTUSE         47
#define VIS_MESH_VERBOSE           48
#define VIS_MESH_MAXEDGEALT        49
#define VIS_MESH_GEOMBOX           50
#define VIS_MESH_GEOMSPHERE        52
#define VIS_MESH_GEOMCYLINDER      53
#define VIS_MESH_GEOMHEMISPHERE    54
#define VIS_MESH_REFINEFACTOR      55
#define VIS_MESH_MAXWARPANGLE      56
#define VIS_MESH_MAXSKEWANGLE      57
#define VIS_MESH_POINTSET          58
#define VIS_MESH_HARDMINEDGELENGTH 59
#define VIS_MESH_FUNSIZINGMIN      60
#define VIS_MESH_FUNSIZINGLEGACY   61

#define VIS_MESH_BIT_GENSPLIT 1
#define VIS_MESH_BIT_GENSWAP  2
#define VIS_MESH_BIT_REFSPLIT 4
#define VIS_MESH_BIT_REFSWAP  8

/* streams */
#define VIS_STREAM_FLAG       0
#define VIS_STREAM_INTEGER    1
#define VIS_STREAM_REAL       2
#define VIS_STREAM_HOLLERITH  3
#define VIS_STREAM_IDENTIFIER 4

/* defines for object type */
#define VIS_LEVELS            2010
#define VIS_TRANSMAP          2020
#define VIS_COLORMAP          2030
#define VIS_VISCONTEXT        2040
#define VIS_VISCONTEXT_SCALAR 2041
#define VIS_VISCONTEXT_VECTOR 2042
#define VIS_VISCONTEXT_TENSOR 2043
#define VIS_VISCONTEXT_FONT   2047
#define VIS_VISCONTEXT_AXIS   2048
#define VIS_ISOCLIP           2050
#define VIS_DATAINT           2060
#define VIS_GRIDFUN           2070
#define VIS_CONNECT           2080
#define VIS_STATE             2090
#define VIS_STATE_ROTANG      2091
#define VIS_COORDSYS          2100
#define VIS_IDTRAN            2110
#define VIS_IDTRAN_COLOR      2111
#define VIS_IDTRAN_TRANS      2112
#define VIS_IDTRAN_NODE       2113 /* node set  */
#define VIS_IDTRAN_ELEM       2114 /* element set  */
#define VIS_IDTRAN_DATAINDEX  2115
#define VIS_IDTRAN_ELEMENT    2116 /* element set face/edge */
#define VIS_IDTRAN_NODESURF   2117 /* node set surface */
#define VIS_GROUP             2120
#define VIS_SPACE             2140
#define VIS_BEAM              2150
#define VIS_BEAMSECT          2160
#define VIS_SHELL             2170
#define VIS_SHELLWALL         2180
#define VIS_TRIAD             2190
#define VIS_LEGEND            2200
#define VIS_EDGE              2210
#define VIS_FACE              2220
#define VIS_SEGMENT           2230
#define VIS_CONTOUR           2240
#define VIS_THRESHOLD         2250
#define VIS_MARK              2260
#define VIS_VALUE             2270
#define VIS_SPROP             2280
#define VIS_EPROP             2300
#define VIS_MPROP             2310
#define VIS_LCASE             2320
#define VIS_RCASE             2330
#define VIS_ICASE             2340
#define VIS_MODEL             2350
#define VIS_TOPOCELL          2360
#define VIS_GAPELEM           2370
#define VIS_DISCELEM          2380
#define VIS_MASSELEM          2390
#define VIS_BILLBOARD         2400
#define VIS_RIGIDELEM         2410
#define VIS_INFELEM           2420
#define VIS_DIMENSION         2430
#define VIS_WORKPLANE         2440
#define VIS_MAPMESH           2450
#define VIS_TRIMESH           2460
#define VIS_TETMESH           2470
#define VIS_VOLMESH           2471
#define VIS_GEOMFUN           2480
#define VIS_ELEMCHK           2490
#define VIS_SURFMESH          2500
#define VIS_EXTMESH           2510
#define VIS_MASSPRP           2520
#define VIS_CURVMESH          2530
#define VIS_ELEMDAT           2540
#define VIS_MCASE             2550
#define VIS_TCURVE            2560
#define VIS_MESHQUAL          2570
#define VIS_RPROP             2580
#define VIS_MESHQUAD          2590
#define VIS_CPAIR             2600
#define VIS_HISTORY           2610
#define VIS_PRMCLP            2620
#define VIS_UNITS             2640
#define VIS_TESS              2650
#define VIS_ASURF             2660
#define VIS_REDMAT            2670
#define VIS_HANDLEBOX         2671
#define VIS_POLYBOX           2672
#define VIS_ZSTATE            2673
#define VIS_GPROP             2674
#define VIS_ISOLABEL          2675
#define VIS_RBODY             2676
#define VIS_WRITER            2677

#endif
