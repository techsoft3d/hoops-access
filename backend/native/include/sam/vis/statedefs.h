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
/* State object */
#ifndef STATEDEFS_DEF
#define STATEDEFS_DEF

/* State types */
#define STATE_ELEMNODE 0
#define STATE_NODE     1
#define STATE_ELEM     4

/* integer parameters */
#define STATE_SORTHIGHLOW     2
#define STATE_MAPNONZERO      3
#define STATE_SORTABSVALUE    4
#define STATE_SORTELEMNODEAVE 5
#define STATE_MAPELEM         6
#define STATE_MAPNODE         7
#define STATE_EXTENTNONZERO   15
#define STATE_LISTWIDTH       16
#define STATE_MAPDEFINED      17
#define STATE_MIDSIDE         18
/* integer parameters */

/* element mapping parameter */
#define STATE_MAPAVE    8
#define STATE_MAPMIN    9
#define STATE_MAPMAX    10
#define STATE_MAPABSMIN 11
#define STATE_MAPABSMAX 12
#define STATE_MAPCENT   13
/* element mapping parameter */

/* node mapping parameter */
#define STATE_MAPGEOM        1
#define STATE_NODE_MAPAVE    STATE_MAPAVE
#define STATE_NODE_MAPMIN    STATE_MAPMIN
#define STATE_NODE_MAPMAX    STATE_MAPMAX
#define STATE_NODE_MAPABSMIN STATE_MAPABSMIN
#define STATE_NODE_MAPABSMAX STATE_MAPABSMAX
#define STATE_MAPDIFF        14
/* node mapping parameter */

/* midside parameter */
#define STATE_MIDSIDEAVE   19
#define STATE_MIDSIDECLAMP 20
/* midside parameter */

/* file types */
#define STATE_PATRAN_NEUTRAL -4
#define STATE_TEXT_SUMMARY   -5
#define STATE_TEXT_LISTING   -6
#define STATE_TEXT_SUMMMAX   -7

/* group operations */
#define STATE_EXTENT      7
#define STATE_DEFINED     8
#define STATE_NONZERO     9
#define STATE_OUTBOUND    10
#define STATE_LOCALMIN    11
#define STATE_LOCALMAX    12
#define STATE_LOCALMINMAX 13
/* group operations */

/* operations */
#define STATE_EQUAL         0
#define STATE_PLUSEQUAL     1
#define STATE_MINUSEQUAL    2
#define STATE_MULTIPLYEQUAL 3
#define STATE_DIVIDEEQUAL   4
/* operations */

/* differential operations */
#define STATE_GRAD       0
#define STATE_GRADNORM   1
#define STATE_DIV        2
#define STATE_CURL       3
#define STATE_STRAIN     4
#define STATE_VECTORGRAD 5
/* differential operations */

/* unary functions */
#define STATE_IDENTITY   0
#define STATE_SIN        1
#define STATE_COS        2
#define STATE_TAN        3
#define STATE_ASIN       4
#define STATE_ACOS       5
#define STATE_ATAN       6
#define STATE_SQRT       7
#define STATE_LOG        8
#define STATE_EXP        9
#define STATE_ABS        10
#define STATE_RECIPROCAL 11
#define STATE_UNITY      12
/* unary functions */

/* binary functions */
#define STATE_MIN     1
#define STATE_MAX     2
#define STATE_AVERAGE 3
#define STATE_CROSS   4
#define STATE_DOT     5
#define STATE_SUM     6
/* binary functions */

/* demo options */
#define STATE_DEMO_BEAM  1
#define STATE_DEMO_PLATE 2
/* demo options */
#define STATE_DEMO_COORDS 3
#define STATE_DEMO_X      4
#define STATE_DEMO_Y      5
#define STATE_DEMO_Z      6

/* coordinate system */
#define STATE_GLOBAL   0 /* System state is global*/
#define STATE_LOCAL    1 /* System state is local undeformed*/
#define STATE_ROTANG   2 /* System state is local deformed*/
#define STATE_MATERIAL 3 /* System state is material system*/
/* coordinate system */

/* access member directly */
#define STATE_ISINTEGERDATA         0 /* type to set/get: isIntegerdata */
#define STATE_CYCLICSYSTEMID        1 /* type to set/get: cyclicSystemId */
#define STATE_MISSINGLINKCSYS       2 /* type to set/get: missingLinkCsys */
#define STATE_SYSTEMDEFAULTTOROTANG 3 /* type to set/get: systemDefaultToRotAng */
#define STATE_AVOIDTRANSFORMATION   4 /* type to set/get: avoidTransformation */
#define STATE_SCALEDDIRCOS          5 /* type to set/get: scaleddircos */

#endif
