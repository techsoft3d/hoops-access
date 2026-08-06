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
/* DevTools wide include file */
#ifndef BASEDEFS_DEF
#define BASEDEFS_DEF

#ifndef VKI_EXTERN
#define VKI_EXTERN
#endif

/* To qualify a function which needs to be exported internally only */
#ifndef VKI_EXTERN_INTERNAL
#define VKI_EXTERN_INTERNAL
#endif

#ifndef VKI_EXTBLAS
#define VKI_EXTBLAS
#endif

#ifndef VKI_EXTLAPACK
#define VKI_EXTLAPACK
#endif

#ifndef VKI_EXTXDB
#define VKI_EXTXDB
#endif

/* basic operating system */
#if defined(VKI_ARCH_SGI) || defined(VKI_ARCH_SUN) || defined(VKI_ARCH_HP) || defined(VKI_ARCH_IBM) || defined(VKI_ARCH_MAC)
#define VKI_OS_UNIX 1
#endif

#if defined(VKI_ARCH_WIN32)
#define VKI_OS_WIN32 1
#endif

#if defined(VKI_ARCH_LINUX)
#define VKI_OS_LINUX 1
#endif

/* C include for limits */
#include <float.h>
#include <limits.h>
/* C include for NULL, size_t, wchar_t, FILE */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#ifndef VKI_WCHAR_T_NONE
#include <wchar.h>
#else
#ifndef wchar_t
#define wchar_t short
#endif
#endif

/* create a string out of the given input variables */
#define VKI_TOSTRING_(...) #__VA_ARGS__
#define VKI_TOSTRING(S)    VKI_TOSTRING_(S)

#include "sam/base/inthashdefs.h"
/* version information */
#include "sam/base/version.h"

typedef struct vsy_ADTree vsy_ADTree;
typedef struct vsy_BitVec vsy_BitVec;
typedef struct vsy_Calc vsy_Calc;
typedef struct vsy_CVect vsy_CVect;
typedef struct vsy_Concat vsy_Concat;
typedef struct vsy_DataTable vsy_DataTable;
typedef struct vsy_DblDict vsy_DblDict;
typedef struct vsy_DblHash vsy_DblHash;
typedef struct vsy_DblVec vsy_DblVec;
typedef struct vsy_Dictionary vsy_Dictionary;
typedef struct vsy_Echo vsy_Echo;
typedef struct vsy_FileText vsy_FileText;
typedef struct vsy_FltVec vsy_FltVec;
typedef struct vsy_HashTable vsy_HashTable;
typedef struct vsy_Heap vsy_Heap;
typedef struct vsy_HeapInd vsy_HeapInd;
typedef struct vsy_HTMLText vsy_HTMLText;
typedef struct vsy_IntDict vsy_IntDict;
typedef struct vsy_IntHash vsy_IntHash;
typedef struct vsy_IntQue vsy_IntQue;
typedef struct vsy_IntStack vsy_IntStack;
typedef struct vsy_IntVec vsy_IntVec;
typedef struct vsy_IntVHash vsy_IntVHash;
typedef struct vsy_LaTeXText vsy_LaTeXText;
typedef struct vsy_License vsy_License;
typedef struct vsy_LineCon vsy_LineCon;
typedef struct vsy_LinkList vsy_LinkList;
typedef struct vsy_List vsy_List;
typedef struct vsy_PlainText vsy_PlainText;
typedef struct vsy_PQueue vsy_PQueue;
typedef struct vsy_Pred vsy_Pred;
typedef struct vsy_Progress vsy_Progress;
typedef struct vsy_PropSet vsy_PropSet;
typedef struct vsy_PTask vsy_PTask;
typedef struct vsy_Random vsy_Random;
typedef struct vsy_RedPre vsy_RedPre;
typedef struct vsy_RegExp vsy_RegExp;
typedef struct vsy_Stack vsy_Stack;
typedef struct vsy_TextFun vsy_TextFun;
typedef struct vsy_TextTee vsy_TextTee;
typedef struct vsy_Timer vsy_Timer;
typedef struct vsy_Track vsy_Track;
typedef struct vsy_Tree vsy_Tree;
typedef struct vsy_TriCon vsy_TriCon;
typedef struct vsy_VertLoc vsy_VertLoc;
typedef struct vsy_VHashTable vsy_VHashTable;
typedef struct vsy_VSocket vsy_VSocket;
typedef struct vsy_ZMem vsy_ZMem;

typedef char Vchar;
typedef signed char Vschar; /* use for signed numeric operations */
typedef unsigned char Vuchar;
typedef short Vshort;
typedef unsigned short Vushort;
typedef int Vint;
typedef unsigned int Vuint;

#if defined(VKI_ARCH_SGI)
typedef long long Vlong;
#define CEE_SAM_PRId64 "lld"
typedef unsigned long long Vulong;
typedef unsigned long long Vword;
#elif defined(VKI_ARCH_WIN32)
typedef __int64 Vlong;
#define CEE_SAM_PRId64 "lld"
typedef unsigned __int64 Vulong;
typedef unsigned __int64 Vword;
#elif (defined(VKI_ARCH_HP) || defined(VKI_ARCH_SUN) || defined(VKI_ARCH_IBM))
typedef long Vlong;
#define CEE_SAM_PRId64 "ld"
typedef unsigned long Vulong;
typedef unsigned long Vword;
#elif defined(VKI_ARCH_LINUX)
typedef long long Vlong;
#define CEE_SAM_PRId64 "lld"
typedef unsigned long long Vulong;
typedef unsigned long long Vword;
#elif defined(VKI_ARCH_CYGWIN)
typedef long long Vlong;
#define CEE_SAM_PRId64 "lld"
typedef unsigned long long Vulong;
typedef unsigned long long Vword;
#else
typedef long long Vlong;
#define CEE_SAM_PRId64 "lld"
typedef unsigned long long Vulong;
typedef unsigned long long Vword;
#endif

typedef float Vfloat;
typedef double Vdouble;
typedef struct {
    Vulong q[2];
} Vquad;
typedef float Vcomplex[2];
typedef double Vdcomplex[2];
typedef void Vobject;
typedef Vlong VConventionType;

#ifdef VKI_WIDECHAR
typedef wchar_t Vtchar;
#else
typedef char Vtchar;
#endif
typedef wchar_t Vwchar;

#ifdef __cplusplus
extern "C" {
#endif

typedef void(Vfunc)(void);
typedef Vint(VfuncInt)(Vobject*);
typedef void(Vfunc1)(Vobject*);
typedef void(Vfunc2)(Vobject*, Vobject*);

#ifdef __cplusplus
}
#endif

/* version as a hexadecimal value */
/* The form is 0xMMNNPP (MM = major, NN = minor, PP = patch) */
/* The version 1.2.4 will be encoded as 0x010204 */
#define SYS_VERSION ((VKI_VERSION_MAJOR << 16) | (VKI_VERSION_MINOR << 8) | (VKI_VERSION_PATCH))

/* version dotted string */
/* Check if VKI_VERSION_PRE_RELEASE is defined or if it is not empty */
/* If VKI_VERSION_PRE_RELEASE is empty, 5 - - 5 == 10 */
/* Additional check if VKI_VERSION_PRE_RELEASE != -10 because 5 - (-10) -5 == 10 */
#if !defined(VKI_VERSION_PRE_RELEASE) || ((VKI_VERSION_PRE_RELEASE + 0 != -10) && (5 - VKI_VERSION_PRE_RELEASE - 5 == 10))
#define SYS_VERSIONSTR VKI_TOSTRING(VKI_VERSION_MAJOR.VKI_VERSION_MINOR.VKI_VERSION_PATCH)
#else
#define SYS_VERSIONSTR VKI_TOSTRING(VKI_VERSION_MAJOR.VKI_VERSION_MINOR.VKI_VERSION_PATCH - VKI_VERSION_PRE_RELEASE)
#endif

/* entity types */
#define SYS_NONE     0
#define SYS_NODE     1
#define SYS_EDGE     2
#define SYS_FACE     3
#define SYS_ELEM     4
#define SYS_DOF      10
#define SYS_INTPNT   12
#define SYS_PARTICLE 13
#define SYS_MODE     14
#define SYS_ASURF    2660 /* VIS_ASURF object */
/* entity types */

#define SYS_COORDSYS 2100 /* VIS_COORDSYS object */
#define SYS_EQN      11
#define SYS_PANEL    15
#define SYS_CPAIR    2600 /* VIS_CPAIR object */
#define SYS_LIBRARY  6002 /* VDM_LIBRARY object */

/* data types */
#define SYS_NODATATYPE    0
#define SYS_INTEGER       1
#define SYS_REAL          2
#define SYS_FLOAT         2
#define SYS_HOLLERITH     3
#define SYS_CHAR          3
#define SYS_DOUBLE        4
#define SYS_STRING        5
#define SYS_COMPLEX       6
#define SYS_DOUBLECOMPLEX 7
#define SYS_OBJECT        8
#define SYS_SHORT         9
#define SYS_LONG          10
#define SYS_HALF          11
#define SYS_QUARTER       12
#define SYS_WCHAR         13 /* 2 bytes */
#define SYS_24BIT         14 /* 3 bytes */
/* data types */

/* data layout */
#define SYS_DATATYPE_NONE -1
#define SYS_SCALAR        0
#define SYS_VECTOR        1
#define SYS_TENSOR        2
#define SYS_GENERALTENSOR 3
#define SYS_SIXDOF        9
#define SYS_MATRIX_DIAG   6
#define SYS_MATRIX_SYMM   7
#define SYS_MATRIX_USYMM  8
/* data layout */

#define SYS_ELEMRES    5
#define SYS_SCALARS    10 /* scalars must be at the end */
#define SYS_SCALARS1   11
#define SYS_SCALARS2   12
#define SYS_SCALARS3   13
#define SYS_SCALARS4   14
#define SYS_SCALARS5   15
#define SYS_SCALARS6   16
#define SYS_SCALARS7   17
#define SYS_SCALARS8   18
#define SYS_SCALARS9   19
#define SYS_SCALARS10  20
#define SYS_SCALARS11  21
#define SYS_SCALARS12  22
#define SYS_SCALARS13  23
#define SYS_SCALARS14  24
#define SYS_SCALARS15  25
#define SYS_SCALARS16  26
#define SYS_SCALARS17  27
#define SYS_SCALARS18  28
#define SYS_SCALARS19  29
#define SYS_SCALARS20  30
#define SYS_SCALARS21  31
#define SYS_SCALARS22  32
#define SYS_SCALARS23  33
#define SYS_SCALARS24  34
#define SYS_SCALARS25  35
#define SYS_SCALARS26  36
#define SYS_SCALARS27  37
#define SYS_SCALARS28  38
#define SYS_SCALARS29  39
#define SYS_SCALARS30  40
#define SYS_SCALARS31  41
#define SYS_SCALARS32  42
#define SYS_SCALARS33  43
#define SYS_SCALARS34  44
#define SYS_SCALARS35  45
#define SYS_SCALARS36  46
#define SYS_SCALARS37  47
#define SYS_SCALARS38  48
#define SYS_SCALARS39  49
#define SYS_SCALARS40  50
#define SYS_SCALARS41  51
#define SYS_SCALARS42  52
#define SYS_SCALARS43  53
#define SYS_SCALARS44  54
#define SYS_SCALARS45  55
#define SYS_SCALARS46  56
#define SYS_SCALARS47  57
#define SYS_SCALARS48  58
#define SYS_SCALARS49  59
#define SYS_SCALARS50  60
#define SYS_SCALARS51  61
#define SYS_SCALARS52  62
#define SYS_SCALARS53  63
#define SYS_SCALARS54  64
#define SYS_SCALARS55  65
#define SYS_SCALARS56  66
#define SYS_SCALARS57  67
#define SYS_SCALARS58  68
#define SYS_SCALARS59  69
#define SYS_SCALARS60  70
#define SYS_SCALARS61  71
#define SYS_SCALARS62  72
#define SYS_SCALARS63  73
#define SYS_SCALARS64  74
#define SYS_SCALARS65  75
#define SYS_SCALARS66  76
#define SYS_SCALARS67  77
#define SYS_SCALARS68  78
#define SYS_SCALARS69  79
#define SYS_SCALARS70  80
#define SYS_SCALARS71  81
#define SYS_SCALARS72  82
#define SYS_SCALARS73  83
#define SYS_SCALARS74  84
#define SYS_SCALARS75  85
#define SYS_SCALARS76  86
#define SYS_SCALARS77  87
#define SYS_SCALARS78  88
#define SYS_SCALARS79  89
#define SYS_SCALARS80  90
#define SYS_SCALARS81  91
#define SYS_SCALARS82  92
#define SYS_SCALARS83  93
#define SYS_SCALARS84  94
#define SYS_SCALARS85  95
#define SYS_SCALARS86  96
#define SYS_SCALARS87  97
#define SYS_SCALARS88  98
#define SYS_SCALARS89  99
#define SYS_SCALARS90  100
#define SYS_SCALARS91  101
#define SYS_SCALARS92  102
#define SYS_SCALARS93  103
#define SYS_SCALARS94  104
#define SYS_SCALARS95  105
#define SYS_SCALARS96  106
#define SYS_SCALARS97  107
#define SYS_SCALARS98  108
#define SYS_SCALARS99  109
#define SYS_SCALARS100 110
#define SYS_SCALARS101 111
#define SYS_SCALARS102 112
#define SYS_SCALARS103 113
#define SYS_SCALARS104 114
#define SYS_SCALARS105 115
#define SYS_SCALARS106 116
#define SYS_SCALARS107 117
#define SYS_SCALARS108 118
#define SYS_SCALARS109 119
#define SYS_SCALARS110 120
#define SYS_SCALARS111 121
#define SYS_SCALARS112 122
#define SYS_SCALARS113 123
#define SYS_SCALARS114 124
#define SYS_SCALARS115 125
#define SYS_SCALARS116 126
#define SYS_SCALARS117 127
#define SYS_SCALARS118 128
#define SYS_SCALARS119 129
#define SYS_SCALARS120 130
#define SYS_SCALARS121 131
#define SYS_SCALARS122 132
#define SYS_SCALARS123 133
#define SYS_SCALARS124 134
#define SYS_SCALARS125 135
#define SYS_SCALARS126 136
#define SYS_SCALARS127 137
#define SYS_SCALARS128 138
#define SYS_SCALARS129 139
#define SYS_SCALARS130 140
#define SYS_SCALARS131 141
#define SYS_SCALARS132 142
#define SYS_SCALARS133 143
#define SYS_SCALARS134 144
#define SYS_SCALARS135 145
#define SYS_SCALARS136 146
#define SYS_SCALARS137 147
#define SYS_SCALARS138 148
#define SYS_SCALARS139 149
#define SYS_SCALARS140 150
#define SYS_SCALARS141 151
#define SYS_SCALARS142 152
#define SYS_SCALARS143 153
#define SYS_SCALARS144 154
#define SYS_SCALARS145 155
#define SYS_SCALARS146 156
#define SYS_SCALARS147 157
#define SYS_SCALARS148 158
#define SYS_SCALARS149 159
#define SYS_SCALARS150 160
#define SYS_SCALARS151 161
#define SYS_SCALARS152 162
#define SYS_SCALARS153 163
#define SYS_SCALARS154 164
#define SYS_SCALARS155 165
#define SYS_SCALARS156 166
#define SYS_SCALARS157 167
#define SYS_SCALARS158 168
#define SYS_SCALARS159 169
#define SYS_SCALARS160 170
#define SYS_SCALARS161 171
#define SYS_SCALARS162 172
#define SYS_SCALARS163 173
#define SYS_SCALARS164 174
#define SYS_SCALARS165 175
#define SYS_SCALARS166 176
#define SYS_SCALARS167 177
#define SYS_SCALARS168 178
#define SYS_SCALARS169 179
#define SYS_SCALARS170 180
#define SYS_SCALARS171 181
#define SYS_SCALARS172 182
#define SYS_SCALARS173 183
#define SYS_SCALARS174 184
#define SYS_SCALARS175 185
#define SYS_SCALARS176 186
#define SYS_SCALARS177 187
#define SYS_SCALARS178 188
#define SYS_SCALARS179 189
#define SYS_SCALARS180 190
#define SYS_SCALARS181 191
#define SYS_SCALARS182 192
#define SYS_SCALARS183 193
#define SYS_SCALARS184 194
#define SYS_SCALARS185 195
#define SYS_SCALARS186 196
#define SYS_SCALARS187 197
#define SYS_SCALARS188 198
#define SYS_SCALARS189 199
#define SYS_SCALARS190 200
#define SYS_SCALARS191 201
#define SYS_SCALARS192 202
#define SYS_SCALARS193 203
#define SYS_SCALARS194 204
#define SYS_SCALARS195 205
#define SYS_SCALARS196 206
#define SYS_SCALARS197 207
#define SYS_SCALARS198 208
#define SYS_SCALARS199 209
#define SYS_SCALARS200 210
#define SYS_SCALARS201 211
#define SYS_SCALARS202 212
#define SYS_SCALARS203 213
#define SYS_SCALARS204 214
#define SYS_SCALARS205 215
#define SYS_SCALARS206 216
#define SYS_SCALARS207 217
#define SYS_SCALARS208 218
#define SYS_SCALARS209 219
#define SYS_SCALARS210 220
#define SYS_SCALARS211 221
#define SYS_SCALARS212 222
#define SYS_SCALARS213 223
#define SYS_SCALARS214 224
#define SYS_SCALARS215 225
#define SYS_SCALARS216 226
#define SYS_SCALARS217 227
#define SYS_SCALARS218 228
#define SYS_SCALARS219 229
#define SYS_SCALARS220 230
#define SYS_SCALARS221 231
#define SYS_SCALARS222 232
#define SYS_SCALARS223 233
#define SYS_SCALARS224 234
#define SYS_SCALARS225 235
#define SYS_SCALARS226 236
#define SYS_SCALARS227 237
#define SYS_SCALARS228 238
#define SYS_SCALARS229 239
#define SYS_SCALARS230 240
#define SYS_SCALARS231 241
#define SYS_SCALARS232 242
#define SYS_SCALARS233 243
#define SYS_SCALARS234 244
#define SYS_SCALARS235 245
#define SYS_SCALARS236 246
#define SYS_SCALARS237 247
#define SYS_SCALARS238 248
#define SYS_SCALARS239 249
#define SYS_SCALARS240 250
#define SYS_SCALARS241 251
#define SYS_SCALARS242 252
#define SYS_SCALARS243 253
#define SYS_SCALARS244 254
#define SYS_SCALARS245 255
#define SYS_SCALARS246 256
#define SYS_SCALARS247 257
#define SYS_SCALARS248 258
#define SYS_SCALARS249 259
#define SYS_SCALARS250 260
#define SYS_SCALARS251 261
#define SYS_SCALARS252 262
#define SYS_SCALARS253 263
#define SYS_SCALARS254 264
#define SYS_SCALARS255 265
#define SYS_SCALARS256 266

#define SYS_DATATYPE_MAX SYS_SCALARS + 256

/* complex modes */
/* use negative value when creating datasets with no link */
#define SYS_COMPLEX_NONE           0
#define SYS_COMPLEX_REAL           1
#define SYS_COMPLEX_MAGNITUDE      2
#define SYS_COMPLEX_IMAGINARY      3
#define SYS_COMPLEX_PHASE          4
#define SYS_COMPLEX_REALIMAGINARY  5
#define SYS_COMPLEX_MAGNITUDEPHASE 6
/* complex modes */

/* no data value */
#define SYS_NODATAVAL 0xffffffff
/* unmanaged gradient data value */
#define SYS_GRAD_NODATAVAL 0xfffffffe

/* coordinate system types */
#define SYS_CARTESIAN       1
#define SYS_CYLINDRICAL     2
#define SYS_SPHERICAL       3
#define SYS_SPHERICAL_ALT   4
#define SYS_TOROIDAL        5
#define SYS_CYLINDRICAL_ALT 6
/* coordinate system types */

/* axes */
#define SYS_XAXIS 1
#define SYS_YAXIS 2
#define SYS_ZAXIS 3
/* axes */

/* planes */
#define SYS_XYPLANE 12
#define SYS_XZPLANE 13
#define SYS_YZPLANE 23
/* planes */

/* nodataval Options */
#define SYS_OFF 0
#define SYS_ON  1
#define SYS_NEW 2
/* nodataval Options */

/* bits per character */
#define SYS_CHARBITS 8
/* invalid integer */
#define SYS_INVALIDINT 900000000
/* maximum number of threads */
/* OpenMP or SetNumThreads */
#define SYS_THREADS_MAX 64

/* defines for DM operations */
#define SYS_KEEP    0
#define SYS_DELETE  1
#define SYS_UNKNOWN 0
#define SYS_OLD     1

/* defines for shape */
#define SYS_SHAPEUNDEFINED -1
#define SYS_SHAPEPOINT     0
#define SYS_SHAPELINE      1
#define SYS_SHAPETRI       2
#define SYS_SHAPEQUAD      3
#define SYS_SHAPETET       4
#define SYS_SHAPEPYR       5
#define SYS_SHAPEWED       6
#define SYS_SHAPEHEX       7
#define SYS_SHAPEPOLYGON   8
#define SYS_SHAPEPOLYHED   9
#define SYS_SHAPE_MAX      10 /* Total count of element shapes supported */

/* defines for topologies */
#define SYS_TOPO_POINT1   (SYS_SHAPEPOINT << 28) + (1 << 16)
#define SYS_TOPO_LINE2    (SYS_SHAPELINE << 28) + (2 << 16)
#define SYS_TOPO_LINE3    (SYS_SHAPELINE << 28) + (3 << 16)
#define SYS_TOPO_TRI3     (SYS_SHAPETRI << 28) + (2 << 16)
#define SYS_TOPO_TRI6SER  (SYS_SHAPETRI << 28) + (3 << 16)
#define SYS_TOPO_TRI6LAG  (SYS_SHAPETRI << 28) + (3 << 16) + (3 << 8)
#define SYS_TOPO_QUAD4SER (SYS_SHAPEQUAD << 28) + (2 << 16)
#define SYS_TOPO_QUAD4LAG (SYS_SHAPEQUAD << 28) + (2 << 16) + (2 << 8)
#define SYS_TOPO_QUAD8    (SYS_SHAPEQUAD << 28) + (3 << 16)
#define SYS_TOPO_QUAD9    (SYS_SHAPEQUAD << 28) + (3 << 16) + (3 << 8)

/* defines for node types */
#define SYS_NODE_UNDEFINED 0
#define SYS_NODE_GRID      1
#define SYS_NODE_SCALAR    2

/* defines for element types */
#define SYS_ELEM_UNDEFINED     0
#define SYS_ELEM_SOLID         1
#define SYS_ELEM_SHELL         2
#define SYS_ELEM_MEMBRANE      3
#define SYS_ELEM_BEAM          4
#define SYS_ELEM_TRUSS         5
#define SYS_ELEM_INFINITE      6
#define SYS_ELEM_GAP           7
#define SYS_ELEM_JOINT         8
#define SYS_ELEM_SPRINGDASHPOT 9
#define SYS_ELEM_RIGID         10
#define SYS_ELEM_CONSTRAINT    11
#define SYS_ELEM_PLOT          12
#define SYS_ELEM_MASS          13
#define SYS_ELEM_INTER         14
#define SYS_ELEM_SUPER         15
#define SYS_ELEM_REINFORCEMENT 16
#define SYS_ELEM_MAX           17

/* element specific types */
#define SYS_SOLID_SOLID 0
#define SYS_SOLID_FLUID 1
#define SYS_SOLID_SHELL 2

#define SYS_MEMBRANE_STAN  0
#define SYS_MEMBRANE_SHEAR 1
#define SYS_MEMBRANE_FACE  2

#define SYS_BEAM_STAN  0
#define SYS_BEAM_ROD   1
#define SYS_BEAM_WELD  2
#define SYS_BEAM_CBEND 3

#define SYS_TRUSS_STAN 0
#define SYS_TRUSS_EDGE 1

#define SYS_SPRINGDASHPOT_SCALAR     0 /* fx */
#define SYS_SPRINGDASHPOT_LINK       1
#define SYS_SPRINGDASHPOT_WELD       2
#define SYS_SPRINGDASHPOT_BUSH       3 /* fx,fy,fz,mx,my,mz */
#define SYS_SPRINGDASHPOT_SCALARDAMP 4
#define SYS_SPRINGDASHPOT_LINKDAMP   5
#define SYS_SPRINGDASHPOT_VECTOR     6 /* scalar with orientation */
#define SYS_SPRINGDASHPOT_SEATBELT   7
#define SYS_SPRINGDASHPOT_TORSION    8

#define SYS_MASS_SCALAR 0
#define SYS_MASS_LUMP   1
#define SYS_MASS_MATRIX 2
#define SYS_MASS_VECTOR 3 /* not yet used */
#define SYS_MASS_VERTEX 4

#define SYS_RIGID_KINE   0
#define SYS_RIGID_DIST   1
#define SYS_RIGID_LINK   2
#define SYS_RIGID_MPC    3
#define SYS_RIGID_RBE3   4
#define SYS_RIGID_SPLINE 5
#define SYS_RIGID_JOINT  6

#define SYS_CONSTRAINT_NONE 0
#define SYS_CONSTRAINT_MEAN 1

#define SYS_PLOT_LOD0 0
#define SYS_PLOT_LOD1 1
#define SYS_PLOT_LOD2 2
#define SYS_PLOT_LOD3 3
#define SYS_PLOT_AERO 4

#define SYS_INTER_NONE              0
#define SYS_INTER_CONTACT           1
#define SYS_INTER_INTERIOR          2
#define SYS_INTER_WALL              3
#define SYS_INTER_INLET_PRESSURE    4
#define SYS_INTER_OUTLET_PRESSURE   5
#define SYS_INTER_SURF              6
#define SYS_INTER_SYMMETRY          7
#define SYS_INTER_PERIODIC_SHADOW   8
#define SYS_INTER_PRESSURE_FARFIELD 9
#define SYS_INTER_INLET_VELOCITY    10
#define SYS_INTER_PERIODIC          11
#define SYS_INTER_FAN               12
#define SYS_INTER_INLET_MASSFLOW    13
#define SYS_INTER_INTERFACE         14
#define SYS_INTER_PARENT            15
#define SYS_INTER_OUTFLOW           16
#define SYS_INTER_AXIS              17
/* additions for CGNS support */
#define SYS_INTER_USER_DEFINED            18
#define SYS_INTER_DEGENERATE_LINE         19
#define SYS_INTER_DIRICHLET               20
#define SYS_INTER_FARFIELD                21
#define SYS_INTER_NEUMANN                 22
#define SYS_INTER_GENERAL                 23
#define SYS_INTER_INFLOW_SUBSONIC         24
#define SYS_INTER_OUTFLOW_SUBSONIC        25
#define SYS_INTER_INFLOW_SUPERSONIC       26
#define SYS_INTER_OUTFLOW_SUPERSONIC      27
#define SYS_INTER_TUNNEL_INFLOW           28
#define SYS_INTER_SYMMETRY_POLAR          29
#define SYS_INTER_TUNNEL_OUTFLOW          30
#define SYS_INTER_WALL_VISCOUS            31
#define SYS_INTER_WALL_VISCOUS_HEAT_FLUX  32
#define SYS_INTER_WALL_VISCOUS_ISOTHERMAL 33
#define SYS_INTER_WALL_INVISCID           34
#define SYS_INTER_DEGENERATE_POINT        35
#define SYS_INTER_EXTRAPOLATE             36
#define SYS_INTER_SURF_ENVIRONMENT        37
/* additions for STARCMM support */
#define SYS_INTER_STAGNATION 38
#define SYS_INTER_PRESSURE   39
#define SYS_INTER_BAFFLE     40
#define SYS_INTER_FREESTREAM 41

#define SYS_INTER_GASKET   42
#define SYS_INTER_COHESIVE 43
/* additions for OpenFOAM support */
#define SYS_INTER_PATCH 44
/* additions for CFX support */
#define SYS_INTER_OPENING 45

#define SYS_INTER_INLET  46
#define SYS_INTER_OUTLET 47
/* element specific types */
#define SYS_SOLID_STAN              0
#define SYS_SPRINGDASHPOT_INTRINSIC 9
#define SYS_INTER_MAX               47

/* local element systems */
#define SYS_ELEMSYS_GLOBAL          0
#define SYS_ELEMSYS_STANDARD        -1
#define SYS_ELEMSYS_POSITION        -2 /* Orientation node describing the orientation vector */
#define SYS_ELEMSYS_GLOBALPROJECT   -3
#define SYS_ELEMSYS_VECTOR          -4 /* Orientation vector giving x'y' plane */
#define SYS_ELEMSYS_BISECTOR        -5
#define SYS_ELEMSYS_NASTRANSHELL    -6 /* CTRIA6, CQUAD8 material system */
#define SYS_ELEMSYS_VECTORELEMNODE  -8
#define SYS_ELEMSYS_FIRSTEDGE       -9
#define SYS_ELEMSYS_FIRSTEDGEANGLE  -11
#define SYS_ELEMSYS_SPHERICAL_ALT   -13
#define SYS_ELEMSYS_GLOBALCLOSEST   -14
#define SYS_ELEMSYS_CYLINDRICAL     -15
#define SYS_ELEMSYS_SPHERICAL       -16
#define SYS_ELEMSYS_CENTROID        -17
#define SYS_ELEMSYS_ROTANG          -18
#define SYS_ELEMSYS_ROTANGELEMNODE  -19
#define SYS_ELEMSYS_UNKNOWN         -20
#define SYS_ELEMSYS_MIDEDGE         -25
#define SYS_ELEMSYS_BIDIAGONAL      -27
#define SYS_ELEMSYS_MIDPOINT        -28
#define SYS_ELEMSYS_CYLINDRICAL_ALT -29 /* Orientation vector is the radial vector at node A */
/* local element systems */
#define SYS_ELEMSYS_NASTRANSOLID   -10
#define SYS_ELEMSYS_GLOBALPROJECTR -21
#define SYS_ELEMSYS_GLOBALPROJECTS -22
#define SYS_ELEMSYS_GLOBALPROJECTT -23
#define SYS_ELEMSYS_MARCSHELL      -24
#define SYS_ELEMSYS_MAX            30

/* element ends */
#define SYS_ELEMEND_NONE     0
#define SYS_ELEMEND_POSITION -1
#define SYS_ELEMEND_OFFSET   -2
/* element ends */

/* result section types */
#define SYS_ELEMSEC_NONE 0
#define SYS_ELEMSEC_BOT  -1
#define SYS_ELEMSEC_TOP  -2
#define SYS_ELEMSEC_MID  -3
#define SYS_ELEMSEC_ALL  -4
/* result section types */

/* layer positions types */
#define SYS_LAYERPOSITION_NONE      0
#define SYS_LAYERPOSITION_MID       1
#define SYS_LAYERPOSITION_BOTTOP    2
#define SYS_LAYERPOSITION_BOTMIDTOP 3
#define SYS_LAYERPOSITION_INTPNT    4
#define SYS_LAYERPOSITION_BOTMID    5
#define SYS_LAYERPOSITION_MIDTOP    6
#define SYS_LAYERPOSITION_BOT       7
#define SYS_LAYERPOSITION_TOP       8
/* layer positions types */
#define SYS_LAYERPOSITION_B1M 9
#define SYS_LAYERPOSITION_M1T 10
#define SYS_LAYERPOSITION_B5T 11

/* strain types */
#define SYS_STRAINTYPE_TENSOR      0
#define SYS_STRAINTYPE_ENGINEERING 1
/* strain types */

/* beam section types */
#define SYS_BEAMSECT_PROPS     0
#define SYS_BEAMSECT_GEOMETRY  1
#define SYS_BEAMSECT_BOX       2
#define SYS_BEAMSECT_ANGLE     3
#define SYS_BEAMSECT_IBEAM     4
#define SYS_BEAMSECT_CIRCLE    5
#define SYS_BEAMSECT_TUBE      6
#define SYS_BEAMSECT_PANEL     7
#define SYS_BEAMSECT_RECTANGLE 8
#define SYS_BEAMSECT_TRAPEZOID 9
#define SYS_BEAMSECT_HEXAGON   10
#define SYS_BEAMSECT_TEE       11
#define SYS_BEAMSECT_ZEE       12
#define SYS_BEAMSECT_CHANNEL   13
#define SYS_BEAMSECT_SECTOR    14
#define SYS_BEAMSECT_ELLIPSE   15
#define SYS_BEAMSECT_HAT       16
#define SYS_BEAMSECT_CROSS     17
#define SYS_BEAMSECT_DBOX      18
#define SYS_BEAMSECT_HAT1      19
#define SYS_BEAMSECT_QUAD      20
#define SYS_BEAMSECT_HATG      21
#define SYS_BEAMSECT_SOLIDHEXA 22
#define SYS_BEAMSECT_SEGMENTS  23
/* beam section types */
#define SYS_BEAMSECT_MAXSECTIONS 24

/* shell wall types */
#define SYS_SHELLWALL_MONOCOQUE  0
#define SYS_SHELLWALL_PROPS      1
#define SYS_SHELLWALL_LAMINATE   2
#define SYS_SHELLWALL_CORRUGATED 3
#define SYS_SHELLWALL_PSHELL     4
#define SYS_SHELLWALL_MATRIX     5
#define SYS_SHELLWALL_GEOMETRY   6
/* shell wall types */

/* defines for solid mixtures */
#define SYS_SOLIDMIX_SINGLE 0
#define SYS_SOLIDMIX_MULTI  1

/* element technologies */
#define SYS_TECH_UNDEFINNED 0
#define SYS_TECH_ISOP       1
#define SYS_TECH_URED       2
#define SYS_TECH_KIRCHHOFF  3
#define SYS_TECH_MIXED      4
#define SYS_TECH_ENHANCED   5
#define SYS_TECH_ANS        6
/* element technologies */

/* Model Element data property definitions */
#define SYS_PROP_THICKNESS 2
#define SYS_PROP_OFFSET    4
#define SYS_PROP_NORMAL    5
#define SYS_PROP_FIBERBOT  6
#define SYS_PROP_FIBERTOP  7
#define SYS_PROP_ELEMVEC   28
#define SYS_PROP_MATLVEC   29
#define SYS_PROP_ENDAX     35
#define SYS_PROP_ENDBX     36
#define SYS_PROP_OFFSETVEC 37
/* Model Element data property definitions */

/* ElementSet Element data property definitions */
#define SYS_PROP_VOLFACT       3
#define SYS_PROP_AREA          10
#define SYS_PROP_VOLFACT_MASS  40
#define SYS_PROP_VOLFACT_STIFF 41
#define SYS_PROP_VOLFACT_LOAD  42

/* reinforcement section types */
#define SYS_REINFSECT_SMEAR 0
/* reinforcement section types */

/* reinforcement section location types */
#define SYS_REINFSECT_LOCATION_NOTYPE    0
#define SYS_REINFSECT_LOCATION_TYPE_MESH 1
/* reinforcement section location types */

/* defines for basis */
#define SYS_BASIS_SERENDIPITY 0
#define SYS_BASIS_LAGRANGE    1
#define SYS_BASIS_BEZIER      2
#define SYS_BASIS_SPLINE      3
#define SYS_BASIS_NURBS       4
#define SYS_BASIS_HERMITE     5

/* integration rules */
#define SYS_RULE_UNKKNOWN 0
#define SYS_RULE_GAUSS    1
#define SYS_RULE_LOBATTO  2
#define SYS_RULE_SIMPSON  3
/* integration rules */

/* error codes */
#define SYS_ERROR_NONE       0
#define SYS_ERROR_VALUE      1
#define SYS_ERROR_ENUM       2
#define SYS_ERROR_OBJECTTYPE 3
#define SYS_ERROR_MEMORY     4
#define SYS_ERROR_NULLOBJECT 5
#define SYS_ERROR_FILE       6
#define SYS_ERROR_COMPUTE    7
#define SYS_ERROR_OPERATION  8
#define SYS_ERROR_OVERFLOW   9
#define SYS_ERROR_UNDERFLOW  10
#define SYS_ERROR_UNKNOWN    11
#define SYS_ERROR_FORMAT     12
#define SYS_ERROR_LOAD       13
/* Use this as an equivalent to an assert,
   internal consistency errors, etc. */
#define SYS_ERROR_SEVERE  14
#define SYS_ERROR_LICENSE 15
/* error codes */
#define SYS_ERROR_MAX 15

/* string lengths including terminated NULL */
#define SYS_MAXPATHCHAR 1024
#define SYS_MAXNAMECHAR 81
#define SYS_MAXNAME     256
#define SYS_MAXDATENAME 11
#define SYS_MAXTIMENAME 9

/* set callback functions */
#define SYS_FUNCTION_DEBUG   1
#define SYS_FUNCTION_MONITOR 2
#define SYS_FUNCTION_SIZING  3
#define SYS_FUNCTION_ASIZING 4
#define SYS_FUNCTION_GEOPROJ 5

/* defines for matrix ordering */
#define SYS_ORDER_AUTO     0
#define SYS_ORDER_MMD1     1
#define SYS_ORDER_MMD2     2
#define SYS_ORDER_MDF1     3
#define SYS_ORDER_ORIG     4
#define SYS_ORDER_METIS    5
#define SYS_ORDER_BCS_MMD  7
#define SYS_ORDER_RANDOM   14
#define SYS_ORDER_SWEEP    15
#define SYS_ORDER_BAND     16
#define SYS_ORDER_EXTMETIS 17

/* text defines */
#define SYS_TEXT_UNORDERED 0
#define SYS_TEXT_ORDERED   1
#define SYS_TEXT_MENU      2

#define SYS_TEXT_PREFORMATTED 0
#define SYS_TEXT_BOLD         1
#define SYS_TEXT_ITALICS      2
#define SYS_TEXT_TYPEWRITER   3
#define SYS_TEXT_CENTER       4
#define SYS_TEXT_HANDLEERR    5
#define SYS_TEXT_BORDEREQUALS 6
#define SYS_TEXT_TABLETITLES  7

#define SYS_TEXT_HEADING   1
#define SYS_TEXT_ANCHOR    2
#define SYS_TEXT_TITLE     3
#define SYS_TEXT_LIST      4
#define SYS_TEXT_ITEM      5
#define SYS_TEXT_PARAGRAPH 6
#define SYS_TEXT_LINEBREAK 7
#define SYS_TEXT_TABLE     8
#define SYS_TEXT_ROW       9
#define SYS_TEXT_COLUMN    10
#define SYS_TEXT_INTERRUPT 11

#define SYS_TEXT_LEFT   1
#define SYS_TEXT_MIDDLE 2
#define SYS_TEXT_RIGHT  3

/*analysis types*/
#define SYS_ANALYSIS_NONE            0
#define SYS_ANALYSIS_STRUCTURAL      1
#define SYS_ANALYSIS_THERMAL         2
#define SYS_ANALYSIS_ELECTRIC        3
#define SYS_ANALYSIS_MAGNETIC        4
#define SYS_ANALYSIS_FLUID           5
#define SYS_ANALYSIS_ACOUSTIC        6
#define SYS_ANALYSIS_DIFFUSION       7
#define SYS_ANALYSIS_ELECTROCHEMICAL 8
/*analysis types*/

/* analysis type 2D */
#define SYS_PLANESTRAIN   1 /* use this for general planar */
#define SYS_PLANESTRESS   2
#define SYS_AXISYMMETRIC  3
#define SYS_AXISYMFOURIER 4
/* analysis type 2D */

/*eigen value interval types*/
#define SYS_EIGEN_NONE    0
#define SYS_EIGEN_ALL     1
#define SYS_EIGEN_LOWEST  2
#define SYS_EIGEN_NEAREST 3
/*eigen value interval types*/

/*eigen solver types*/
#define SYS_EIGEN_SUBSPACE 5
#define SYS_EIGEN_LANCZOS  6
#define SYS_EIGEN_AMLS     9
/*eigen solver types*/

/*eigenvalue norm types*/
#define SYS_EIGEN_NORMMASS 7
#define SYS_EIGEN_NORMMAX  8
/*eigenvalue norm types*/

/* direct sparse solver types */
#define SYS_SOLVERTYPE_PARDISO    1
#define SYS_SOLVERTYPE_MUMPS      2
#define SYS_SOLVERTYPE_MUMPSPIVOT 3
#define SYS_SOLVERTYPE_LL         4
#define SYS_SOLVERTYPE_MF         5
#define SYS_SOLVERTYPE_MFP        6

/* dof types */
#define SYS_DOF_NONE 0
#define SYS_DOF_TX   1
#define SYS_DOF_TY   2
#define SYS_DOF_TZ   3
#define SYS_DOF_RX   4
#define SYS_DOF_RY   5
#define SYS_DOF_RZ   6
#define SYS_DOF_TEMP 7
#define SYS_DOF_VOLT 8
#define SYS_DOF_WARP 9
#define SYS_DOF_PRES 10
#define SYS_DOF_VX   11
#define SYS_DOF_VY   12
#define SYS_DOF_VZ   13
#define SYS_DOF_ELEM 14
#define SYS_DOF_LAGM 15
#define SYS_DOF_S0   16
#define SYS_DOF_S1   17
#define SYS_DOF_S2   18
#define SYS_DOF_S3   19
#define SYS_DOF_S4   20
#define SYS_DOF_S5   21
#define SYS_DOF_S6   22
#define SYS_DOF_S7   23
#define SYS_DOF_S8   24
#define SYS_DOF_S9   25
#define SYS_DOF_S10  26
#define SYS_DOF_S11  27
#define SYS_DOF_S12  28
#define SYS_DOF_S13  29
#define SYS_DOF_S14  30
#define SYS_DOF_S15  31
/* dof types */
#define SYS_DOF_S   16
#define SYS_DOF_MAX 31

/* material type */
#define SYS_MAT_ISOTROPIC    0
#define SYS_MAT_LAMINA       1
#define SYS_MAT_ORTHOTROPIC  2
#define SYS_MAT_ANISOTROPIC  3
#define SYS_MAT_HYPERELASTIC 4
#define SYS_MAT_GENERIC      5
/* material type */
#define SYS_MAT_MAX 6

/* defines for plastic hardening types */
#define SYS_MAT_HARDENING_ISOTROPIC -1 /* Isotropic plascticity model*/
#define SYS_MAT_HARDENING_KINEMATIC -2 /* Kinematic plascticity model*/

/* heat exchange types */
#define SYS_HEATEXCH_LINEAR 1
#define SYS_HEATEXCH_EXP    2
#define SYS_HEATEXCH_POW    3
#define SYS_HEATEXCH_RAD    4
/* heat exchange types */

/* defines for format types */
#define SYS_ASCII  -1
#define SYS_BINARY -2

#define SYS_FILE_STL    -4
#define SYS_FILE_STLBIN -5
#define SYS_FILE_OBJ    -6

/* our magic number */
#define SYS_MAGIC 7946

/* Library file format */
#define SYS_NATIVE           1
#define SYS_PLOT3D_GRID      2
#define SYS_PLOT3D_SOLUTION  3
#define SYS_PATRAN_RESULT    4
#define SYS_GENERIC          5
#define SYS_PDA              6
#define SYS_LSTC_STATE       7
#define SYS_ABAQUS_ODB       8
#define SYS_ABAQUS_FIL       9
#define SYS_NASTRAN_OUTPUT2  10
#define SYS_STL              11
#define SYS_STLBIN           12
#define SYS_ABAQUS_INPUT     13
#define SYS_SDRC_UNIVERSAL   14
#define SYS_PAM_DAISY        15
#define SYS_ANSYS_RESULT     16
#define SYS_MECHANICA_STUDY  17
#define SYS_NASTRAN_BULKDATA 18
#define SYS_FDI_NEUTRAL      19
#define SYS_PATRAN_NEUTRAL   20
#define SYS_FLUENT_MESH      21
#define SYS_ANSYS_INPUT      22
#define SYS_TECPLOT          23
#define SYS_HYPERMESH_ASCII  24
#define SYS_LSTC_INPUT       25
#define SYS_CGNS             26
#define SYS_MARC_POST        27
#define SYS_ENSIGHT          28
#define SYS_STARCCM          29
#define SYS_MECHANICA_FNF    30
#define SYS_LSTC_HISTORY     32
#define SYS_NASTRAN_XDB      33
#define SYS_NASTRAN_H5       34
#define SYS_POLYFLOW         36
#define SYS_FEMAP_NEUTRAL    37
#define SYS_AUTODYN_RES      38
#define SYS_PAM_ERF          39
#define SYS_OPENFOAM         40
#define SYS_OBJ              41
#define SYS_COMSOL_SECTION   43
#define SYS_H3D              44
#define SYS_LSTC_STATEFEMZIP 45
#define SYS_PAM_INPUT        46
#define SYS_CFX_RESULT       47
#define SYS_GMV              48
#define SYS_PERMAS_POST      49
#define SYS_VTK_LEGACY       50
#define SYS_SAMCEF           51
#define SYS_AFLR             52
#define SYS_ADAMS            53
#define SYS_NATIVE_HDF5      54
#define SYS_MEMORY           55
#define SYS_COMSOL_MPH       56
#define SYS_COMSOL_MPHBIN    57
#define SYS_MARC_INPUT       58
#define SYS_ANSYS_DPF        59
#define SYS_PLUGIN           60
#define SYS_VTK_VTU          61
/* Library file format */
#define SYS_MAXTYPE 62

/* defines for categories */
#define SYS_CATEGORY_NONE              0
#define SYS_CATEGORY_BUCK              1
#define SYS_CATEGORY_VIBE              2
#define SYS_CATEGORY_STAT              3
#define SYS_CATEGORY_TRAN              4
#define SYS_CATEGORY_CONS              5  /* Constraint mode */
#define SYS_CATEGORY_CONC              6  /* nodal attachment mode */
#define SYS_CATEGORY_DIST              7  /* distributed attachment mode */
#define SYS_CATEGORY_INERTIA           8  /* inertia attachment mode */
#define SYS_CATEGORY_EFFINERTIA        9  /* effective inertia attachment mode */
#define SYS_CATEGORY_RIGID             10 /* rigid mode */
#define SYS_CATEGORY_LOAD              11 /* generic load mode */
#define SYS_CATEGORY_FREQUENCYRESPONSE 12 /* Modal Frequency Response */
#define SYS_CATEGORY_MAX               13

/* vendors */
#define SYS_VENDOR_UNKNOWN           0
#define SYS_VENDOR_VKI               1
#define SYS_VENDOR_MSC_NASTRAN       2
#define SYS_VENDOR_ANSYS             3
#define SYS_VENDOR_ABAQUS            4
#define SYS_VENDOR_LS_DYNA3D         5
#define SYS_VENDOR_ALTAIR_OPTISTRUCT 6
#define SYS_VENDOR_NX_NASTRAN        7
#define SYS_VENDOR_ADINA_NASTRAN     SYS_VENDOR_NX_NASTRAN
/* vendors */
#define SYS_VENDOR_MAX 8

/* result types */
#define SYS_RES_NONE           -1
#define SYS_RES_X              0
#define SYS_RES_D              1
#define SYS_RES_XF             2
#define SYS_RES_R              3
#define SYS_RES_V              4
#define SYS_RES_A              5
#define SYS_RES_HEAT_FLUX      6
#define SYS_RES_VOLT           7
#define SYS_RES_DENS           8
#define SYS_RES_VISC           9
#define SYS_RES_COND           10
#define SYS_RES_MACH           11
#define SYS_RES_STREAM         12
#define SYS_RES_ENTROPY        13
#define SYS_RES_MASS_FLUX      14
#define SYS_RES_TEMP           15
#define SYS_RES_FILM_COEF      16
#define SYS_RES_J              17
#define SYS_RES_TF             18
#define SYS_RES_PRES           19
#define SYS_RES_D_MAT          20
#define SYS_RES_ELEC_POT       21
#define SYS_RES_Q              22
#define SYS_RES_MAG_POT        23
#define SYS_RES_R_J            24
#define SYS_RES_MASS_FLOW      25
#define SYS_RES_VOLUME         26
#define SYS_RES_VOLUME_FLUX    27
#define SYS_RES_UNKNOWN        28
#define SYS_RES_V_DIV          29
#define SYS_RES_E              30
#define SYS_RES_INERTIA        31
#define SYS_RES_DENS_GRAD      32
#define SYS_RES_P              33
#define SYS_RES_TIME           34
#define SYS_RES_S              35
#define SYS_RES_ID             36
#define SYS_RES_V_GRAD         37
#define SYS_RES_USER           38
#define SYS_RES_THICKNESS      39
#define SYS_RES_STIFF          40
#define SYS_RES_R_Q            41
#define SYS_RES_SCALARS        42
#define SYS_RES_HEAT_GRAD      43
#define SYS_RES_TE_ERROR       44
#define SYS_RES_XF_Q           45
#define SYS_RES_ENERGY_DENSITY 46
#define SYS_RES_SDV            47
#define SYS_RES_VIEW_FACT      48
#define SYS_RES_DAMP           49
#define SYS_RES_FREQ           50
#define SYS_RES_SE_DENSITY     51
#define SYS_RES_K_MAT          52
#define SYS_RES_M_MAT          53
#define SYS_RES_L_VEC          54
#define SYS_RES_ORDER          55
#define SYS_RES_AREA           56
#define SYS_RES_LENGTH         57
#define SYS_RES_RADIUS         58
#define SYS_RES_NUMBER         59
#define SYS_RES_KE_DENSITY     60
#define SYS_RES_DAMAGE         61
#define SYS_RES_DIST           62
#define SYS_RES_TEMP_DOT       63
#define SYS_RES_TE             64
#define SYS_RES_COND_MAT       65
#define SYS_RES_CAP_MAT        66
#define SYS_RES_FAIL_INDEX     67

#define SYS_RES_VOID_RATIO    69
#define SYS_RES_TEMP_GRAD     70
#define SYS_RES_PRES_COEF     71
#define SYS_RES_LOAD_FACT     72
#define SYS_RES_PRES_GRAD     73
#define SYS_RES_PRES_DOT      74
#define SYS_RES_PRES_DOTDOT   75
#define SYS_RES_MASS          76
#define SYS_RES_HEAT          77
#define SYS_RES_CRACK_DENSITY 78
#define SYS_RES_ELEC_FIELD    79
#define SYS_RES_ELEC_FLUX     80
#define SYS_RES_R_HEAT_FLOW   81
#define SYS_RES_MAG_FLUX      82
#define SYS_RES_MAG_FIELD     83
#define SYS_RES_J_DENSITY     84
#define SYS_RES_TURB_KE       85
#define SYS_RES_TURB_ED       86
#define SYS_RES_CONC          87 /* species concentration */
#define SYS_RES_H             88
#define SYS_RES_CP            89 /* Contact pressure */
#define SYS_RES_POROSITY      90
#define SYS_RES_H_DOT         91
#define SYS_RES_FACTOR        92
#define SYS_RES_HEAT_FLOW     93
#define SYS_RES_SFM           94
#define SYS_RES_SEK           95
#define SYS_RES_WEIGHT        96
#define SYS_RES_KE            97
#define SYS_RES_SE            98
#define SYS_RES_DIR           99
#define SYS_RES_ENERGY        100

#define SYS_RES_SEP 102

#define SYS_RES_CLOSURE 105

#define SYS_RES_STATE        107
#define SYS_RES_STAT         108
#define SYS_RES_R_MASS_FLOW  109
#define SYS_RES_XF_MASS_FLOW 110

#define SYS_RES_E_RATE 113

#define SYS_RES_SE_ERROR 117

#define SYS_RES_XF_HEAT_FLOW    119
#define SYS_RES_DIR_COS         120
#define SYS_RES_SF              121
#define SYS_RES_SD              122
#define SYS_RES_YPLUS           123
#define SYS_RES_UTAU            124
#define SYS_RES_SE_PERCENT      125
#define SYS_RES_KE_PERCENT      126
#define SYS_RES_DOM_FLUID_PHASE 127
#define SYS_RES_SOUND_MODEL     128
#define SYS_RES_PENE_CONTACT    129

#define SYS_RES_SAFE_FACT      139
#define SYS_RES_FAT_DAMAGE     140
#define SYS_RES_FAT_DAMAGE_DIR 141
#define SYS_RES_FAT_LIFE       142

#define SYS_RES_GAP                  144
#define SYS_RES_EN_FORC              145
#define SYS_RES_EN_FLUX              146
#define SYS_RES_STRENGTH_SAFE_FACT   147
#define SYS_RES_FAT_SAFE_FACT        148
#define SYS_RES_PHASE_DIAMETER       149
#define SYS_RES_MU_LAMB              150
#define SYS_RES_MU_TURB              151
#define SYS_RES_BODY_FORCE           152
#define SYS_RES_WALL_SHEAR           153
#define SYS_RES_VORTICITY            154
#define SYS_RES_REACTION_PROGRESS    155
#define SYS_RES_SOUND_LEVEL          156
#define SYS_RES_ROT_ANG              157
#define SYS_RES_VOF                  158
#define SYS_RES_VISC_EDDY            159
#define SYS_RES_ROUGHNESS            160
#define SYS_RES_FRACTION             161
#define SYS_RES_CONV_COEF            162
#define SYS_RES_POWER                163
#define SYS_RES_INTENSITY            164
#define SYS_RES_TRAC                 165
#define SYS_RES_XF_J                 166
#define SYS_RES_PRANDTL              167
#define SYS_RES_TURB_DIST            168
#define SYS_RES_REYNOLDS             169
#define SYS_RES_RADIANCE             170
#define SYS_RES_FLUENCE              171
#define SYS_RES_RC_PROD              172
#define SYS_RES_POWER_DENSITY        173
#define SYS_RES_WATER_ACCUM          174
#define SYS_RES_TURB_SD              175
#define SYS_RES_TE_DENSITY           176
#define SYS_RES_STRENGTH_RATIO       177
#define SYS_RES_DELETED              178
#define SYS_RES_MARG_SAFE            179
#define SYS_RES_MOMENT               180
#define SYS_RES_ROTATION             181
#define SYS_RES_TRANSLATION          182
#define SYS_RES_FORCE                183
#define SYS_RES_DECIBEL              184
#define SYS_RES_PROBABILITY          185
#define SYS_RES_FORCE_MOMENT         186
#define SYS_RES_YOUNGS_MODULUS       187
#define SYS_RES_POISSONS_RATIO       188
#define SYS_RES_SHEAR_MODULUS        189
#define SYS_RES_TEXP_COEF            190
#define SYS_RES_CHEM_SHRINKAGE       191
#define SYS_RES_CONVERSIONTIME       192
#define SYS_RES_CONVERSIONSTATUS     193
#define SYS_RES_EFFECTIVEMASSSUMMARY 194 /* Modal effective mass summary */
#define SYS_RES_EFFECTIVEMASS        195 /* Modal effective mass */
#define SYS_RES_PARTICIPATIONFACTOR  196 /* Modal participation factor */
#define SYS_RES_MASSFRACTION         197 /* Modal effective mass fraction */
#define SYS_RES_TM                   198 /* Total residual moment vector */
#define SYS_RES_HOURGLASS_ENERGY     199 /* Hourglass energy */
                                         /* this number must be smaller than 1000, VDM_ONFILE */
/* result types */
#define SYS_RES_MAX 200

#define SYS_QUA_NONE               -1
#define SYS_QUA_X                  0
#define SYS_QUA_Y                  1
#define SYS_QUA_Z                  2
#define SYS_QUA_MAG                3
#define SYS_QUA_XX                 4
#define SYS_QUA_YY                 5
#define SYS_QUA_ZZ                 6
#define SYS_QUA_XY                 7
#define SYS_QUA_YZ                 8
#define SYS_QUA_ZX                 9
#define SYS_QUA_VONMISES           10
#define SYS_QUA_NXX                11
#define SYS_QUA_NYY                12
#define SYS_QUA_NXY                13
#define SYS_QUA_MXX                14
#define SYS_QUA_MYY                15
#define SYS_QUA_MXY                16
#define SYS_QUA_QXY                17
#define SYS_QUA_QZX                18
#define SYS_QUA_TX                 19
#define SYS_QUA_TY                 20
#define SYS_QUA_TZ                 21
#define SYS_QUA_RX                 22
#define SYS_QUA_RY                 23
#define SYS_QUA_RZ                 24
#define SYS_QUA_MINIMUM            25
#define SYS_QUA_MAXIMUM            26
#define SYS_QUA_INTERMEDIATE       27
#define SYS_QUA_EFF                28
#define SYS_QUA_TOT                29
#define SYS_QUA_INC                30
#define SYS_QUA_REL                31
#define SYS_QUA_ABS                32
#define SYS_QUA_EQUIV              33
#define SYS_QUA_PLAST              34
#define SYS_QUA_CREEP              35
#define SYS_QUA_THERMAL            36
#define SYS_QUA_ELAST              37
#define SYS_QUA_INELAST            38
#define SYS_QUA_REYNOLDS           39
#define SYS_QUA_STAG               40
#define SYS_QUA_CAUCHY             41
#define SYS_QUA_PK                 42
#define SYS_QUA_LOG                43
#define SYS_QUA_TRESCA             44
#define SYS_QUA_YIELD              45
#define SYS_QUA_MEAN               46
#define SYS_QUA_NONLIN             47
#define SYS_QUA_TORSION            48
#define SYS_QUA_SWELLING           49
#define SYS_QUA_CRACKING           50
#define SYS_QUA_NORMAL             51
#define SYS_QUA_SHEAR              52
#define SYS_QUA_PSD                53
#define SYS_QUA_RMS                54
#define SYS_QUA_NOM                55
#define SYS_QUA_COMPONENT          56
#define SYS_QUA_INTERLAMINAR       57
#define SYS_QUA_PLY                58
#define SYS_QUA_BOND               59
#define SYS_QUA_CONSTRAINT         60
#define SYS_QUA_PORE               61
#define SYS_QUA_GASKET             62
#define SYS_QUA_CONTACT            63
#define SYS_QUA_INITIAL            64
#define SYS_QUA_FINAL              65
#define SYS_QUA_TENS               66
#define SYS_QUA_COMP               67
#define SYS_QUA_INFRARED           68
#define SYS_QUA_DIFFUSE            69
#define SYS_QUA_COLLIMATED         70
#define SYS_QUA_SOLAR              71
#define SYS_QUA_SOUND              72
#define SYS_QUA_RADIATIVE          73
#define SYS_QUA_CONDUCTIVE         74
#define SYS_QUA_CONVECTIVE         75
#define SYS_QUA_RESIDUAL           76
#define SYS_QUA_ADJUSTED           77
#define SYS_QUA_PSIDE              78
#define SYS_QUA_MSIDE              79
#define SYS_QUA_LOCAL              80
#define SYS_QUA_INTERNAL           81
#define SYS_QUA_BULK               82
#define SYS_QUA_STATIC             83
#define SYS_QUA_DYNAMIC            84
#define SYS_QUA_SLIP               85
#define SYS_QUA_FREE               86
#define SYS_QUA_FORCED             87
#define SYS_QUA_FLUID              88
#define SYS_QUA_HARMONIC           89
#define SYS_QUA_LORENTZ            90
#define SYS_QUA_BEARING            91
#define SYS_QUA_RADIAL             92
#define SYS_QUA_TANG               93
#define SYS_QUA_AXIAL              94
#define SYS_QUA_GREEN              95
#define SYS_QUA_MEANPRES           96
#define SYS_QUA_DEFORM             97
#define SYS_QUA_GPF                98
#define SYS_QUA_VISC               99
#define SYS_QUA_GLUE               100
#define SYS_QUA_FRICTION           101
#define SYS_QUA_SCALAR             102
#define SYS_QUA_PRINCIPAL          103
#define SYS_QUA_NOZ                104
#define SYS_QUA_ATO                105
#define SYS_QUA_CRM                106
#define SYS_QUA_SOURCE             107
#define SYS_QUA_SUM                108
#define SYS_QUA_NET                109
#define SYS_QUA_ACOUSTIC           110
#define SYS_QUA_RADIOSITY          111
#define SYS_QUA_IRRADIANCE         112
#define SYS_QUA_TRANSMITTED        113
#define SYS_QUA_REFLECTED          114
#define SYS_QUA_INCIDENT           115
#define SYS_QUA_ABSORBED           116
#define SYS_QUA_SOLID              117
#define SYS_QUA_DISSIPATED         118
#define SYS_QUA_OPT                119
#define SYS_QUA_CONC               120
#define SYS_QUA_DIST               121
#define SYS_QUA_ATTACHMENT         122
#define SYS_QUA_INERTIA            123
#define SYS_QUA_REDUCED            124
#define SYS_QUA_MODAL              125
#define SYS_QUA_PARTICLE           126
#define SYS_QUA_NEIGHBORS          127
#define SYS_QUA_SHELL              128
#define SYS_QUA_ERROR              129
#define SYS_QUA_NORM               130
#define SYS_QUA_EIP                131
#define SYS_QUA_PANEL              132
#define SYS_QUA_LCR                133
#define SYS_QUA_PEAK               134
#define SYS_QUA_DIFFERENCE         135
#define SYS_QUA_CYCLIC             136
#define SYS_QUA_SIN                137
#define SYS_QUA_COS                138
#define SYS_QUA_MPC                139
#define SYS_QUA_TURB               140
#define SYS_QUA_SYM                141
#define SYS_QUA_ASYM               142
#define SYS_QUA_DAMAGE             143
#define SYS_QUA_COHESIVE           144
#define SYS_QUA_BOLT               145
#define SYS_QUA_CHOCKING           146
#define SYS_QUA_MECH               147
#define SYS_QUA_ENTHALPY           148
#define SYS_QUA_FLAME              149
#define SYS_QUA_GLASSTRANS         150
#define SYS_QUA_EMITTED            151
#define SYS_QUA_COUPLED            152
#define SYS_QUA_UNCOUPLED          153
#define SYS_QUA_STRUCT             154
#define SYS_QUA_TRANSPORT          155
#define SYS_QUA_WELD               156
#define SYS_QUA_KIRCH              157
#define SYS_QUA_NORMALIZED         158
#define SYS_QUA_APPLIED            159
#define SYS_QUA_GYROSCOPIC         160
#define SYS_QUA_DAMPING            161
#define SYS_QUA_CIRCULATORY_FORCES 162
#define SYS_QUA_TSAI_HILL          163
#define SYS_QUA_TSAI_WU            164
#define SYS_QUA_HASHIN             165
#define SYS_QUA_STRESS             166
#define SYS_QUA_STRAIN             167
#define SYS_QUA_RICE_TRACEY        168
#define SYS_QUA_HOFFMAN            169
#define SYS_QUA_PUCK               170
#define SYS_QUA_LARC04             171
#define SYS_QUA_TRACTION           172
#define SYS_QUA_PLANE_STRESS       173
#define SYS_QUA_FIBER              174
#define SYS_QUA_MATRIX             175
#define SYS_QUA_RATIO              176
#define SYS_QUA_VARIANT            177
#define SYS_QUA_CRITICAL           178
#define SYS_QUA_FULL               179
#define SYS_QUA_MATERIAL           180
#define SYS_QUA_AWEIGHT            181
#define SYS_QUA_INACTIVE           182
#define SYS_QUA_OVERHEATING        183
#define SYS_QUA_UNCONVERGED        184
#define SYS_QUA_VOLUME             185
#define SYS_QUA_VIBE               186
#define SYS_QUA_PENETRATION        187
#define SYS_QUA_BIOT               188
#define SYS_QUA_ENG                189
#define SYS_QUA_CG                 190
#define SYS_QUA_PARTICIPATION      191
#define SYS_QUA_AERO               192
#define SYS_QUA_MASS               193
#define SYS_QUA_RIGID              194
#define SYS_QUA_UNIT               195
#define SYS_QUA_RESTRAINED         196
#define SYS_QUA_UNRESTRAINED       197
#define SYS_QUA_HOMOGENIZED        198
#define SYS_QUA_SHEARPANEL         199
#define SYS_QUA_BENDING            200
#define SYS_QUA_BODY               201
#define SYS_QUA_SPC                202
#define SYS_QUA_ROTATIONAL         203

#define SYS_QUA_MAX 204 /* one more than last define */

#define SYS_QUAVAL_NONE         -1
#define SYS_QUAVAL_PHASE        0
#define SYS_QUAVAL_HARMONIC     1
#define SYS_QUAVAL_ROTORSPEED   2
#define SYS_QUAVAL_NODE         3
#define SYS_QUAVAL_MATERIAL     4
#define SYS_QUAVAL_SET          5
#define SYS_QUAVAL_DESIGNCYCLE  6
#define SYS_QUAVAL_SECTION      7
#define SYS_QUAVAL_INTPNT       8
#define SYS_QUAVAL_CONTACTPAIR  9
#define SYS_QUAVAL_SPECIES      10
#define SYS_QUAVAL_BOLTSEQUENCE 11
#define SYS_QUAVAL_STEP         12
#define SYS_QUAVAL_COUNT        13

#define SYS_QUAVAL_MAX 14 /* one more than last define */

/* maximum number of qualifiers in dataset */
#define SYS_NQUA_MAX 4

/* defines for approximation types */
#define SYS_APPROX_NONE      0
#define SYS_APPROX_LINEAR    1
#define SYS_APPROX_QUADRATIC 2
#define SYS_APPROX_CUBIC     3

/* defines for phases */
#define SYS_PHASE_MASS           1
#define SYS_PHASE_SYMFACTOR      2
#define SYS_PHASE_INITCOND       3
#define SYS_PHASE_PREDICTOR      4
#define SYS_PHASE_STIFF          5
#define SYS_PHASE_FACTOR         6
#define SYS_PHASE_UPDATE         7
#define SYS_PHASE_REACT          8
#define SYS_PHASE_REACTSTIFF     9
#define SYS_PHASE_SOLVE          10
#define SYS_PHASE_GEOMSTIFF      11
#define SYS_PHASE_BUCKLING       12
#define SYS_PHASE_VIBRATION      13
#define SYS_PHASE_OUTPUT         14
#define SYS_PHASE_STATICMODES    15
#define SYS_PHASE_DOFTAB         16
#define SYS_PHASE_INITIALIZATION 17
#define SYS_PHASE_BEGINCASE      18
#define SYS_PHASE_ENDCASE        19

/* defines for object types */
#define VSY_DICTIONARY  1010
#define VSY_HASHTABLE   1020
#define VSY_LIST        1030
#define VSY_STACK       1040
#define VSY_BITVEC      1050
#define VSY_PROPSET     1060
#define VSY_RANDOM      1070
#define VSY_TEXTFUN     1080
#define VSY_TEXTFUN_0   VSY_TEXTFUN
#define VSY_TEXTFUN_1   1081
#define VSY_TEXTFUN_2   1082
#define VSY_TEXTFUN_3   1083
#define VSY_TEXTFUN_4   1084
#define VSY_TEXTFUN_5   1085
#define VSY_TEXTFUN_6   1086
#define VSY_TEXTFUN_7   1087
#define VSY_TEXTFUN_TEE VSY_TEXTFUN_1
#define VSY_HTMLTEXT    1100
#define VSY_PLAINTEXT   1110
#define VSY_CONCAT      1120
#define VSY_DATATABLE   1130
#define VSY_PQUEUE      1140
#define VSY_TRICON      1150
#define VSY_VERTLOC     1160
#define VSY_LINECON     1170
#define VSY_INTVEC      1180
#define VSY_TIMER       1190
#define VSY_PTASK       1200
#define VSY_TEXTTEE     1210
#define VSY_LATEXTEXT   1220
#define VSY_FILETEXT    1230
#define VSY_LINKLIST    1240
#define VSY_ADTREE      1250
#define VSY_DBLVEC      1260
#define VSY_INTHASH     1270
#define VSY_INTDICT     1280
#define VSY_CALC        1290
#define VSY_PROGRESS    1300
#define VSY_INTSTACK    1310
#define VSY_REGEXP      1320
#define VSY_ECHO        1330
#define VSY_FLTVEC      1340
#define VSY_INTQUE      1350
#define VSY_HEAP        1360
#define VSY_HEAPIND     1370
#define VSY_REDPRE      1380
#define VSY_INTVHASH    1390
#define VSY_TREE        1400
#define VSY_PRED        1410
#define VSY_MPC         1411

#define VSY_ZMEM       1430
#define VSY_VHASHTABLE 1440
#define VSY_CVECT      1490

#define VSY_INCLUDEZERO 1

/* defines for undefined values types  */
#define SYS_CHAR_UNDEFINED    CHAR_MAX
#define SYS_SCHAR_UNDEFINED   SCHAR_MAX
#define SYS_UCHAR_UNDEFINED   UCHAR_MAX
#define SYS_SHORT_UNDEFINED   SHRT_MAX
#define SYS_USHORT_UNDEFINED  USHRT_MAX
#define SYS_INT_UNDEFINED     INT_MAX
#define SYS_LONG_UNDEFINED    LLONG_MAX
#define SYS_ULONG_UNDEFINED   ULLONG_MAX
#define SYS_WORD_UNDEFINED    ULLONG_MAX
#define SYS_FLOAT_UNDEFINED   FLT_MAX
#define SYS_DOUBLE_UNDEFINED  DBL_MAX
#define SYS_UINT_UNDEFINED    UINT_MAX
#define SYS_TCHAR_UNDEFINED   CHAR_MAX
#define SYS_WCHAR_T_UNDEFINED WCHAR_MAX

#define SYS_MAX_DEGREES_OF_FREEDOM 6

#endif
