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
#ifndef CONNECTDEFS_DEF
#define CONNECTDEFS_DEF

#define CONNECT_KERNELEXIST 1

/* mode */
#define CONNECT_STATIC  0
#define CONNECT_DYNAMIC 1
/* mode */

/* group operations */
#define CONNECT_UNIQUE           0
#define CONNECT_FREE             1
#define CONNECT_ELEM             2
#define CONNECT_FEATURE          3
#define CONNECT_ASSOC            4
#define CONNECT_SHAPE            5
#define CONNECT_DIMENSION        6
#define CONNECT_EXTENT           7
#define CONNECT_CONTAINED        12 /* elem,face,edge attached to all nodes */
#define CONNECT_USE              13 /* face,edge,node used by n or any elements */
#define CONNECT_CONNECTED        15 /* elem,face,edge attached to n nodes */
#define CONNECT_INCONSISTENT     17 /* 2D elements inconsistent connectivity */
#define CONNECT_CURVATURE        18 /* feature based on curvature discontinuity */
#define CONNECT_SEED             23 /* bounded faces, edges containing seed node */
#define CONNECT_NONMAN           27 /* not equal to two adjacent faces */
#define CONNECT_CORNER           28 /* node attached to linear element or corner */
#define CONNECT_ASSOCANY         29
#define CONNECT_ASSOCDIFF        30
#define CONNECT_INTERSECT        31
#define CONNECT_UNIQUEASSOCDIFF  32
#define CONNECT_FEATUREASSOCDIFF 33
#define CONNECT_UNIQUEASSOC      34
#define CONNECT_FLOOD            35 /* select adjacent element free faces until a feature edge is met, starting from a seed element face */
/* group operations */
#define CONNECT_SILHOUETTE 8 /* view related */
#define CONNECT_INTERVAL   9
#define CONNECT_SAMPLE     20 /* sample based on target minimum distance */

/* region operations */
#define CONNECT_FREEBODY 50 /* Unconnected bodies */
#define CONNECT_TOPOBODY 51 /* topologically similar bodies */
#define CONNECT_MAP      53 /* homogenous regions for mapping */
#define CONNECT_USERID   54 /* VIS_USERID */
/* region operations */
#define CONNECT_TRIPOD 52 /* 3 widely spread nodes */

/* integer parameters */
#define CONNECT_REDEFINETOPO   22
#define CONNECT_EXACTADJACENCY 27
#define CONNECT_LAYERASSOC     34
#define CONNECT_ZEROUSERID     36
/* integer parameters */

/* group integer parameters */
#define CONNECT_ASSOCID       2
#define CONNECT_FEATURESENSE  4
#define CONNECT_NUMBER        14
#define CONNECT_SEEDNODE      24
#define CONNECT_CURVATUREFLAT 26
#define CONNECT_SEEDELEM      28
#define CONNECT_SEEDEDGE      29
#define CONNECT_SEEDFACE      30
#define CONNECT_FEATURENONMAN 33
#define CONNECT_ASSOCFREE     35
/* group integer parameters */
#define CONNECT_ASSOCTYPE      1
#define CONNECT_INTERVALNUMBER 10
#define CONNECT_INTERVALVALUE  11

/* demo shape */
#define CONNECT_DEMO_CUBE     1
#define CONNECT_DEMO_CYLINDER 2
#define CONNECT_DEMO_SPHERE   3
/* demo shape */

/* mesh read format */
#define CONNECT_READ_ASCII      SYS_ASCII
#define CONNECT_READ_BINARY     SYS_BINARY
#define CONNECT_READ_STL        SYS_FILE_STL
#define CONNECT_READ_STL_BINARY SYS_FILE_STLBIN
#define CONNECT_READ_OBJ        SYS_FILE_OBJ
/* mesh read format */

/* mesh write format */
#define CONNECT_WRITE_ASCII            SYS_ASCII
#define CONNECT_WRITE_BINARY           SYS_BINARY
#define CONNECT_WRITE_ABAQUS_INPUT     SYS_ABAQUS_INPUT
#define CONNECT_WRITE_ANSYS_INPUT      SYS_ANSYS_INPUT
#define CONNECT_WRITE_LS_DYNA_INPUT    SYS_LSTC_INPUT
#define CONNECT_WRITE_NASTRAN_BULKDATA SYS_NASTRAN_BULKDATA
#define CONNECT_WRITE_PATRAN_NEUTRAL   SYS_PATRAN_NEUTRAL
#define CONNECT_WRITE_SDRC_UNIVERSAL   SYS_SDRC_UNIVERSAL
/* mesh write format */

/* read/write formats not mentioned in our documentation */
#define CONNECT_GHS3D_DATA      -10
#define CONNECT_GHS3D_NOBOITE   -11
#define CONNECT_TEXT_SUMMARY    -16
#define CONNECT_TEXT_LISTING    -17
#define CONNECT_SRF             -19
#define CONNECT_TETGEN_NODEELEM -20
#define CONNECT_TETGEN_POLY     -21
#define CONNECT_CADENCE_MESH    -22

/* group float array parameters */
#define CONNECT_GROUP_EXTENT CONNECT_EXTENT
/* group float array parameters */

/* these types may need to be distinct from operations */
#define CONNECT_MODELVIEWMATRIX 3
#define CONNECT_SEEDGROUP       25
#define CONNECT_NORMAL          32

/* float parameters */
#define CONNECT_TOLERANCE 16
#define CONNECT_SIZE      31
/* float parameters */

/* group float parameters */
#define CONNECT_FEATUREANGLE    0
#define CONNECT_GROUP_TOLERANCE CONNECT_TOLERANCE
#define CONNECT_CURVATURECHANGE 19
/* group float parameters */
#define CONNECT_SAMPLEDISTANCE 21

#endif
