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
/* Material Property Object */

#ifndef MPROPDEFS_DEF
#define MPROPDEFS_DEF

/* value flags */
#define MPROP_UNDEFINED  0
#define MPROP_VALUE      1
#define MPROP_IDENTIFIER 2
/* value flags */

/* integer property types */
#define MPROP_HYPER_N                   31 /* order of strain energy potential */
#define MPROP_PLASTICITY_HARDENING_TYPE 40 /* plastic hardening type: isotropic/kinematic */
#define MPROP_PLASTICITY_TABULAR_DATA   41 /* plastic hardening type: isotropic/kinematic */
/* integer property types */

/* double property types */
#define MPROP_DENSITY 0
#define MPROP_E       1 /* Elasticity Young modulus */
#define MPROP_NU      2 /* Poisson ratio */
#define MPROP_G       3 /* Isotropic shear moduli, torsional shear moduli for 1D */
#define MPROP_A       4 /* coefficient of thermal expansion */
#define MPROP_GE      5 /* structural damping coefficient */
#define MPROP_TREF    6 /* reference temperature */

#define MPROP_EORT  7  /* anisotropic elasticity moduli in 3 directions */
#define MPROP_NUORT 8  /* anisotropic Poisson ratios in 3 directions */
#define MPROP_GORT  9  /* anisotropic shear moduli in 3 directions */
#define MPROP_AORT  10 /* anisotropic coefficients of thermal expansion in 3 directions */
#define MPROP_DMAT  11 /* stiffness matrix 6x6 symmetric */
#define MPROP_AVEC  12 /* thermal expansion vector 6 */

#define MPROP_SXT 13 /* Fail: Tensile stress limit in fiber direction Xt */
#define MPROP_SXC 14 /* Fail: Compressive stress limit in fiber direction Xc */
#define MPROP_SYT 15 /* Fail: Tensile stress limit in transverse direction Yt */
#define MPROP_SYC 16 /* Fail: Compressive stress limit in transverse direction Yc */
#define MPROP_SHR 17 /* Fail: Shear strength in the X-Y plane S */

#define MPROP_K    19 /* Thermal Conductivity */
#define MPROP_CP   20 /* Specific Heat */
#define MPROP_FILM 21 /* Film Coefficient */
#define MPROP_HGEN 22 /* Heat Generation Capability */
#define MPROP_EREF 23 /* Reference Enthalpy */
#define MPROP_EMIS 24 /* Emissivity */
#define MPROP_KORT 25 /* Thermal Conductivity orthotropic (x,y,z) */
#define MPROP_KMAT 26 /* Thermal Conductivity Matrix anisotropic */

#define MPROP_BULK  27 /* Bulk Modulus */
#define MPROP_SOUND 28 /* Speed of Sound */

#define MPROP_HYPER_CIJ 29 /* mater constants distortionnal deformation Mooney-Rivlin */
#define MPROP_HYPER_DI  30 /* mater constants volumetric deformation Mooney-Rivlin */

#define MPROP_F12       32 /* Tsai-Wu Interaction Term */
#define MPROP_VISCOSITY 33 /* Viscosity */

#define MPROP_EXT 34 /* Fail: Tensile strain limit in fiber direction Xt */
#define MPROP_EXC 35 /* Fail: Compressive strain limit in fiber direction Xc */
#define MPROP_EYT 36 /* Fail: Tensile strain limit in transverse direction Yt */
#define MPROP_EYC 37 /* Fail: Compressive strain limit in transverse direction Yc */
#define MPROP_EHR 38 /* Fail: Shear strain in the X-Y plane S */

#define MPROP_USER 39 /* User-defined property */
/* double property types */

#define MPROP_ALLOWTYPE 18 /* not used */

#define MPROP_MAX 42

#endif
