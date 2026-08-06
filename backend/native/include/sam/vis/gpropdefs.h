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
/* Solution Property Object */

#ifndef GPROPDEFS_DEF
#define GPROPDEFS_DEF

/* value flags */
#define GPROP_UNDEFINED  0
#define GPROP_VALUE      1
#define GPROP_IDENTIFIER 2
/* value flags */

/* char property types */
#define GPROP_TITLE       3
#define GPROP_SUBTITLE    4
#define GPROP_ORIGCODE    5
#define GPROP_ORIGVERSION 6
#define GPROP_ORIGTIME    7
#define GPROP_ORIGDATE    8
/* char property types */

/* integer property types */
#define GPROP_2DPLANE        0
#define GPROP_2DTYPE         1
#define GPROP_LIBRARY        2
#define GPROP_2DAXIS         15
#define GPROP_AUTOSPC        22
#define GPROP_IMPORT_VENDOR  25
#define GPROP_EXPORT_VENDOR  26
#define GPROP_CYCLIC_NSEC    10 /* Cyclic Mode analysis: number of sections */
#define GPROP_SYMM_NUM       16 /* cyclic symmetry: number of defined symmetries */
#define GPROP_SYMM_ID        17 /* cyclic symmetry: list of symmetries Ids */
#define GPROP_SYMM_CID       18 /* cyclic symmetry: list of cylind. coord. systems Ids */
#define GPROP_SYMM_NSEC      19 /* cyclic symmetry: number of sections for each symmetry */
#define GPROP_SYMM_STAGEID   27 /* Stage or sector number */
#define GPROP_CYCLIC_CSYSID  28 /* Cyclic Mode analysis: Reference Cylindrical coord syst ID */
#define GPROP_PERMANENT_GLUE 29 /* Contact computed at 1st step and frozen for the whole computation */
#define GPROP_SYMM_ESET      24
/* integer property types */

/* double property types */
#define GPROP_CYCLIC_ORIG      11 /* Cyclic Mode analysis: coord. of the center of Reference Cylindrical syt. */
#define GPROP_CYCLIC_AXIS      12 /* Cyclic Mode analysis: coord. of the center of Reference Cylindrical syt. */
#define GPROP_STEFAN_BOLTZMANN 13
#define GPROP_ABSOLUTE_ZERO    14
#define GPROP_SYMM_ORIG        20 /* cyclic symmetry: coordinate of axis points */
#define GPROP_SYMM_AXIS        21 /* cyclic symmetry: axis vectors */
#define GPROP_STIFF_DAMP       23
/* double property types */

#define GPROP_USER_NUM 9
#define GPROP_MAX      30

#define GPROP_USERDIMENUM  -1000000
#define GPROP_USERDIME     -2000000
#define GPROP_USERNAME     -3000000
#define GPROP_USERDATATYPE -4000000
#define GPROP_USERDATA     -5000000
#define GPROP_USERBASE     -5000000

#endif
