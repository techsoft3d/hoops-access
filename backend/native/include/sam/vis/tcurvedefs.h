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
/* VisTools TCurve (TabularFunction) macro definitions header file */

#ifndef TCURVEDEFS_DEF
#define TCURVEDEFS_DEF

/* types */
#define TCURVE_PWLINEAR   0
#define TCURVE_EQUATION   1
#define TCURVE_EXPRESSION 2
/* types */

/* table parameters */
#define TCURVE_SCALE   1
#define TCURVE_SHIFT   2
#define TCURVE_DIVISOR 3
#define TCURVE_OFFSET  4
/* table parameters */

/* double parameter */
#define TCURVE_TOLERANCE 1
/* double parameter */

/* integer parameter */
#define TCURVE_EXTRAPOLATE 2
/* integer parameter */
#define TCURVE_HINT 3

/* This is used only in NASFil internally. Should be removed from API */
/* hints */
#define TCURVE_TABLEM1 1 /* temperature dependent material curve Form1 */
#define TCURVE_TABLEM2 2 /*                                      Form2 */
#define TCURVE_TABLEM3 3 /*                                      Form3 */
#define TCURVE_TABLES1 4 /* stress dependent material curve */
#define TCURVE_TABLED1 5 /* time (or frequency) dependent load curve Form1 */
#define TCURVE_TABLED2 6 /*                                          Form2 */
#define TCURVE_TABLED3 7 /*                                          Form3 */
/* hints */

#endif
