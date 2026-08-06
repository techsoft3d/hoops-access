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
/* Solution Property definitions header file */

#ifndef SPROPDEFS_DEF
#define SPROPDEFS_DEF

/* solution types */
#define SYS_SOL_NONE         0
#define SYS_SOL_STATIC       1 /* fluid steady state */
#define SYS_SOL_VIBRATION    2
#define SYS_SOL_BUCKLING     3
#define SYS_SOL_TRANSIENT    4
#define SYS_SOL_SUPERELEMENT 5
#define SYS_SOL_FREQRESPONSE 6
#define SYS_SOL_COMPLEXEIGEN 7
#define SYS_SOL_QUASISTATIC  8
#define SYS_SOL_OUTPUT       9
#define SYS_SOL_SINGULAR     10
/* solution types */
#define SYS_SOL_MAX 10

/* value flags */
#define SPROP_UNDEFINED  0
#define SPROP_VALUE      1
#define SPROP_IDENTIFIER 2
/* value flags */

/* integer property types */
#define SPROP_ANALYSIS           0
#define SPROP_CASEID             22
#define SPROP_EIGEN_NUM          1
#define SPROP_EIGEN_TYPE         34
#define SPROP_EIGEN_SOLVER       38
#define SPROP_EIGEN_CASE         83
#define SPROP_LCASE_NUM          2
#define SPROP_LCASE              3
#define SPROP_LCASE_SENSORNODE   62
#define SPROP_LCASE_SENSORDOF    63
#define SPROP_EIGEN_NORM         39
#define SPROP_EIGEN_SIZE         40
#define SPROP_EIGEN_STEPS        41
#define SPROP_LCASE_TCURVE       23
#define SPROP_LCASE_TREF         25 /* LCase Id defining the node reference temperature */
#define SPROP_LCASE_MODE         60
#define SPROP_LCASE_UNIT         76
#define SPROP_LCASE_TINIT        85 /* Id of the initial temperature loading if any */
#define SPROP_TIME_STEPFIXED     56
#define SPROP_RCASE              8
#define SPROP_MCASE              18
#define SPROP_ICASE              10
#define SPROP_THERMALSTRAIN      14
#define SPROP_LARGESTRAIN        15
#define SPROP_NONLINEAR          16
#define SPROP_MASSDIAG           17
#define SPROP_INERTIARELIEF      24
#define SPROP_PRESTRESS          35
#define SPROP_PERTURBATION       36
#define SPROP_SAVE_FREQ          26
#define SPROP_RESFILE_FREQ       26
#define SPROP_HISTFILE_FREQ      27
#define SPROP_COUPLED_NUM        28
#define SPROP_COUPLED            29
#define SPROP_RESFILE_NUM        30
#define SPROP_RESFILE            31
#define SPROP_RESFILE_QUA1       50
#define SPROP_RESFILE_QUA2       51
#define SPROP_RESFILE_NSET       77
#define SPROP_RESFILE_ESET       78
#define SPROP_RESPRINT_NUM       32
#define SPROP_RESPRINT           33
#define SPROP_RESPRINT_QUA1      53
#define SPROP_RESPRINT_QUA2      54
#define SPROP_LHSITER_FREQ       46
#define SPROP_LHSSTEP_FREQ       47
#define SPROP_LHSFORM            81
#define SPROP_ITERMAX            48
#define SPROP_ESET_DELETE        61
#define SPROP_HISTFILE_NUM       64
#define SPROP_HISTFILE           65
#define SPROP_HISTFILE_SET       66
#define SPROP_MODALDAMP_TCURVE   67
#define SPROP_MODALDAMP_TYPE     68
#define SPROP_FREQ_TYPE          69
#define SPROP_FREQ_NUM           70
#define SPROP_FREQ_NPNTS         73
#define SPROP_FREQRESPONSE_MODAL 75
#define SPROP_FOURIER_NUM        79
#define SPROP_FOURIER            80
#define SPROP_NSM_ID             84
#define SPROP_MAX_INCREMENT_STEP 89 /* Maximum increment steps allowed in a single load case */
#define SPROP_CONTACT_NUM        90 /* Contact set definition number associated with the solution */
#define SPROP_CONTACT_CASE       91 /* Contact set definition Ids associated with the solution */
#define SPROP_RESEXPORT_NUM      92 /* Number of exported result quantities for chaining */
#define SPROP_RESEXPORT          93 /* exported result quantity for chaining */
#define SPROP_RESIMPORT_NUM      95 /* Number of imported result quantities for chaining */
#define SPROP_RESIMPORT          96 /* imported result quantity for chaining */
#define SPROP_USER_NUM           59
/* integer property types */

/* double property types */
#define SPROP_EIGEN_LOWER      11
#define SPROP_EIGEN_UPPER      12
#define SPROP_EIGEN_SHIFT      13
#define SPROP_LCASE_FACTOR     4
#define SPROP_TIME_INIT        5 /* initial time at load case start */
#define SPROP_TIME_STEP        6 /* time step for a load case: initial time step for auto time step */
#define SPROP_TIME_TERM        7 /* termination time for a load case */
#define SPROP_TIME_STEPMIN     42
#define SPROP_TIME_STEPMAX     43
#define SPROP_RCASE_FACTOR     9
#define SPROP_MASS_FACTOR      37
#define SPROP_DAMP_ALPHA       57
#define SPROP_DAMP_BETA        58
#define SPROP_FTOL             44 /* Convergence crit. Force tolerance */
#define SPROP_UTOL             45 /* Convergence crit. Displ tolerance */
#define SPROP_ETOL             87 /* Convergence crit. Energy tolerance */
#define SPROP_FREQ_LOWER       71
#define SPROP_FREQ_UPPER       72
#define SPROP_FREQ_BIAS        74
#define SPROP_TEMPMAXVARIATION 86 /* Auto time step: max temperature variation */
#define SPROP_DRILLFACTOR      88 /* Shell drilling penatly scale factor */
/* double property types */

/* char property types */
#define SPROP_TITLE           19
#define SPROP_SUBTITLE        20
#define SPROP_LABEL           21
#define SPROP_SUBLABEL        49
#define SPROP_RESFILE_CQUA    52
#define SPROP_RESPRINT_CQUA   55
#define SPROP_DESTINATIONFILE 82
#define SPROP_RESIMPORTFILE   94 /* Names of imported result files for chaining */
/* char property types */

#define SPROP_MAX 97

/* user property types */
#define SPROP_USERDIMENUM  -1000000
#define SPROP_USERDIME     -2000000
#define SPROP_USERNAME     -3000000
#define SPROP_USERDATATYPE -4000000
#define SPROP_USERDATA     -5000000
#define SPROP_USERBASE     -5000000
/* user property types */

/* parameters values */
#define SPROP_360                1
#define SPROP_FREQ_RANGE         2
#define SPROP_FREQ_EIGEN         3
#define SPROP_FREQ_SPREAD        4
#define SPROP_MODALDAMP_CRITFRAC 5
#define SPROP_MODALDAMP_RAYLEIGH 6
#define SPROP_FREQ_RANDOM        7

#endif
