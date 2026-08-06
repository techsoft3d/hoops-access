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
/* Load Case Object */

#ifndef LCASEDEFS_DEF
#define LCASEDEFS_DEF

/* parameters */
#define LCASE_ADDFACTOR 1

/* concentrated load types */
#define LCASE_FORCE  1
#define LCASE_MOMENT 2
#define LCASE_HEAT   3
#define LCASE_TEMP   4
#define LCASE_CSCA   5
#define LCASE_CVEC   6
/* concentrated load types */
#define LCASE_CONC_FORCE  1
#define LCASE_CONC_MOMENT 2
#define LCASE_CONC_HEAT   3
#define LCASE_CONC_TEMP   4
#define LCASE_CONC_SCA    5
#define LCASE_CONC_VEC    6
#define LCASE_CONC_MAX    6
/* use this to get number of force moment definitions */
#define LCASE_FORMOM LCASE_CONC_MAX + 1

/* distributed load types */
#define LCASE_TRAC                 1
#define LCASE_PRES                 2
#define LCASE_TANGFORCE            3
#define LCASE_TANGMOMENT           4
#define LCASE_HEATFLUX             5
#define LCASE_HEATCONV             6
#define LCASE_DMOM                 7
#define LCASE_DSCA                 8
#define LCASE_DVEC                 9
#define LCASE_HEATRAD              10
#define LCASE_HEATRAD_ABSORPTIVITY 11

/* distributed load types */
#define LCASE_DIST_TRAC                 1
#define LCASE_DIST_PRES                 2
#define LCASE_DIST_TANGFORCE            3
#define LCASE_DIST_TANGMOMENT           4
#define LCASE_DIST_HEATFLUX             5
#define LCASE_DIST_HEATCONV             6
#define LCASE_DIST_MOM                  7
#define LCASE_DIST_SCA                  8
#define LCASE_DIST_VEC                  9
#define LCASE_DIST_HEATRAD              10
#define LCASE_DIST_HEATRAD_ABSORPTIVITY 11
#define LCASE_DIST_MAX                  11

/* element load types */
#define LCASE_ACCLELEM 1
#define LCASE_HEATELEM 2
/* element load types */
#define LCASE_ELEM_ACCL 1
#define LCASE_ELEM_HEAT 2
#define LCASE_ELEM_MAX  2

#endif
