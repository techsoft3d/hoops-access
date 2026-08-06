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
#ifndef CPAIRDEFS_DEF
#define CPAIRDEFS_DEF

/* CPair types */
#define CPAIR_CONTACT 1
#define CPAIR_COSIM   2
#define CPAIR_CYCLIC  3
#define CPAIR_TIE_DEF 4 /* Contact interface defined as TIE */
/* CPair types */

/* surface types */
#define CPAIR_MASTER 1
#define CPAIR_SLAVE  2
/* surface types */

/* property flags */
#define CPAIR_UNDEFINED 0
#define CPAIR_VALUE     1
#define CPAIR_CURVE     2
/* property flags */

/* integer property types */
#define CPAIR_PID                     0 /* associated Eprop Id */
#define CPAIR_SMALLSLIDING            2
#define CPAIR_SYMMETRIC               7 /* symmetric contact master=slave */
#define CPAIR_SURFTOSURF              8
#define CPAIR_PROJECT                 10
#define CPAIR_NUMSECTOR               11
#define CPAIR_CID                     12
#define CPAIR_MASTER_SET              13
#define CPAIR_SLAVE_SET               14
#define CPAIR_CONTACT_BEHAVIOR        16
#define CPAIR_SEPARATIONTHRESHOLDTYPE 18 /* Contact separation threshold value type */
#define CPAIR_ID                      21 /* cpair identification number */
#define CPAIR_CYCLIC_MATCHING         22 /* all nodes of the cyclic cpair are matching */
#define CPAIR_MATLID                  23 /* material Id of contact behaviour. In Ansys, the material id of the slave element is stored */
/* integer property types */

/* double property types */
#define CPAIR_ADJUST              1
#define CPAIR_SMOOTH              4
#define CPAIR_HCRIT               5
#define CPAIR_EXTENSIONZONE       6
#define CPAIR_POSITIONTOL         9  /* Maximum distance considered for contact or tie */
#define CPAIR_CYCLICTOLERANCE     15 /* Parametric tolerance for cyclic node matching. Used in Nx Nastran's CYCSET record */
#define CPAIR_MINPOSITIONTOL      17 /* Minimum distance considered for contact */
#define CPAIR_SEPARATIONTHRESHOLD 19 /* Contact separation threshold value */
#define CPAIR_BIAS_POSITIONTOL    20 /* eccentricity factor on Position tolerance */
/* double property types */
#define CPAIR_UNUSED 3
#define CPAIR_MAX    24

/* contact behavior */
#define CPAIR_CONTACT_BEHAVIOR_STANDARD      0
#define CPAIR_CONTACT_BEHAVIOR_ROUGH         1 /* no slidding but separation */
#define CPAIR_CONTACT_BEHAVIOR_NO_SEPARATION 2 /* no separation, but slidding */
#define CPAIR_CONTACT_BEHAVIOR_BONDED        3 /* no separation and no slidding */
/* contact behavior */

/* separation threshold types */
#define CPAIR_SEPARATION_FORCE           0 /* Separation based on forces. */
#define CPAIR_SEPARATION_STRESS          1 /* Separation based on absolute stresses: force/area */
#define CPAIR_SEPARATION_STRESS_EXTRAPOL 2 /* Separation based on absolute stress: extrapolating integration point stresses */
#define CPAIR_SEPARATION_STRESS_NODAL    3 /* Relative nodal stress: force/area */
#define CPAIR_SEPARATION_STRESS_RELATIVE 4 /* Separation based on relative stress: extrapolating integration point stresses */
/* separation threshold types */

#endif
