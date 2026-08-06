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
/* Element Property Object */

#ifndef EPROPDEFS_DEF
#define EPROPDEFS_DEF

/* property flags */
#define EPROP_UNDEFINED  0
#define EPROP_VALUE      1
#define EPROP_IDENTIFIER 2
/* property flags */

/* parameters */
#define EPROP_360 1

/* integer property types */
/* these values cannot change for compatibility */
#define EPROP_MID      0
#define EPROP_MID_BEND 1
#define EPROP_MID_TRAN 2
#define EPROP_MID_COUP 3
#define EPROP_MATLCID  5
#define EPROP_RULE     6

#define EPROP_NOSEPARATION 45
#define EPROP_NOSLIP       46

#define EPROP_DOF1 49
#define EPROP_DOF2 50

#define EPROP_HEATEXCH 62

#define EPROP_BEAMSECT    81
#define EPROP_DOFFLAG_NUM 83
#define EPROP_DOFFLAG_IND 85
#define EPROP_DOFFLAG_DEP 86
#define EPROP_SHELLWALL   89

#define EPROP_LAYER_NUM 96
#define EPROP_LAYER_MID 99
#define EPROP_LAYER_NIP 100

#define EPROP_BEAMREFLECTY 102
#define EPROP_BEAMREFLECTZ 103

#define EPROP_BEAMPNTS_NUM     111
#define EPROP_BEAMLOOP_NUM     113
#define EPROP_BEAMLOOP_PNTSNUM 114
#define EPROP_BEAMLOOP_TYPE    115
#define EPROP_BEAMLOOP_MID     116
#define EPROP_BEAMLOOP_PNTS    117
#define EPROP_BEAMSEGS_NUM     118

#define EPROP_LAYER_GID 130

#define EPROP_TIED 136

#define EPROP_NSM_ID         141
#define EPROP_NSM_NUM        142
#define EPROP_NSM_VAL_SETIDS 144
#define EPROP_NSM_VAL_LUMP   145
/* (Elbow/Curved_Pipe) flexibility stress identification factor method  */
#define EPROP_BEND_FLEXFACTOR 150
/* Ambient element type */
#define EPROP_AMBIENT_TYPE 154

/* Element-Free Galerkin Properties */
/* Spline function type to use on kernel */
#define EPROP_GALERKIN_SPLINE_TYPE 158
/* Dilation function type */
#define EPROP_GALERKIN_DILATION_TYPE 159
/* Essential boundary condition type */
#define EPROP_GALERKIN_ESSENTIAL_BC_TYPE 160
/* Domain integration type */
#define EPROP_GALERKIN_DOMAIN_INTEGRATION_TYPE 161

/* Smoothed-Particle Galerkin Properties */
/* Pressure smoothing flag */
#define EPROP_GALERKIN_PRESSURE_SMOOTHING 163
/* Type of kernel support */
#define EPROP_GALERKIN_KERNEL 164
/* Interval of time steps to conduct displacement smoothing */
#define EPROP_GALERKIN_SMOOTHING_STEPS_INTERVAL 165
/* Smoothing scheme for momentum consistent SPG only */
#define EPROP_GALERKIN_SMOOTHING_SCHEME 166
/* Bond failure mechanism */
#define EPROP_GALERKIN_BOND_FAILURE_TYPE 167
/* Stabilization type */
#define EPROP_GALERKIN_STABILIZATION_TYPE 170
/* Self contact flag */
#define EPROP_GALERKIN_SELF_CONTACT 172
/* Box id defining the active region */
#define EPROP_GALERKIN_BOX_ID 173

/* PBUSH1D specific properties */
/* Tables for scale_factor(SHOCKA) and tensions(DAMPER/SPRING/GENER) */
#define EPROP_TENSION_TABLES 179
/* Reinforcement section member count */
#define EPROP_REINFSECT_NUM 180
/* Reinforcement section type */
#define EPROP_REINFSECT 181
/* Reinforcement section material Id */
#define EPROP_REINFSECT_MID 182
/* Reinforcement section coordinate system */
#define EPROP_REINFSECT_CID 185
/* Reinforcement section location type */
#define EPROP_REINFSECT_LOCATION_TYPE 187
/* constitutive cohesive behavior:
   TRACTION SEPARATION: the response is defined directly in terms of traction and separation.
   CONTINUUM: modelize a strain state involving one direct (opening strain) and two transverse shear components.
   GASKET:  the stress state in the cohesive elements is uniaxial. */
#define EPROP_COHESIVE_RESPONSE_TYPE 188
#define EPROP_FRICTION_TYPE          189 /* Friction model type: CPair */
/* integer property types */

/* double property types */
#define EPROP_THICKNESS 7
#define EPROP_OFFSET    8
#define EPROP_KS        9 /* transverse shear factor */
#define EPROP_BENDSTF   10
/* (1D) Non structural mass per unit length */
#define EPROP_NSM   11
#define EPROP_SRBOT 12
#define EPROP_SRTOP 13
/* (1D) Section area */
#define EPROP_AREA 14
/* (1D) Area Moment of inertia */
#define EPROP_IYY 15
/* (1D) Area Moment of inertia */
#define EPROP_IZZ 16
/* (1D) Area pproduct of inertia */
#define EPROP_IYZ 17
/* (1D) Tortionnal stiffness Ixx */
#define EPROP_J 18
/* (1D) Shear stiffness factor in Plane1*/
#define EPROP_KSY 19
/* (1D) Shear stiffness factor in Plane2*/
#define EPROP_KSZ 20
/* (1D) local y coord of neutral axis (A/B) */
#define EPROP_DSY 21
/* (1D) local z coord of neutral axis (A/B) */
#define EPROP_DSZ     22
#define EPROP_OFFSETY 23
#define EPROP_OFFSETZ 24
#define EPROP_CW      25
/* (1D) connector internal diameter (not used) */
#define EPROP_DIN 26
/* (1D) connector external diameter */
#define EPROP_DOUT 27
/* (1D BEND) Bend radius at centroid */
#define EPROP_BENDRADIUS  28
#define EPROP_STRSCOEFROT 29
/* (1D) xz locations for stress data recovery (for BEND it's rz )*/
#define EPROP_SRC 30
/* (1D) xz locations for stress data recovery (for BEND it's rz )*/
#define EPROP_SRD 31
/* (1D) xz locations for stress data recovery (for BEND it's rz )*/
#define EPROP_SRE 32
/* (1D) xz locations for stress data recovery (for BEND it's rz )*/
#define EPROP_SRF         33
#define EPROP_UZERO       34
#define EPROP_FZERO       35
#define EPROP_KCLOSE      36
#define EPROP_KOPEN       37
#define EPROP_KTRANS      38
#define EPROP_MUSY        39 /* mu: static friction coefficient. mu1 in y-dir if anisotropic: Gap or Cpair */
#define EPROP_MUSZ        40 /* mu2 static friction coefficient in z-dir for anisotropic: Gap */
#define EPROP_MU_ISO      39 /* For isotropic friction, identical to EPROP_MUSY */
#define EPROP_MU1_ORTHO   39 /* For orthotropic friction, 1st parameter, identical to EPROP_MUSY */
#define EPROP_MU2_ORTHO   40 /* For orthotropic friction, 2nd parameter, identical to EPROP_MUSZ */
#define EPROP_MUKY        41 /* kinetic friction coefficient in y-dir: Gap */
#define EPROP_MUKZ        42 /* kinetic friction coefficient in z-dir: Gap */
#define EPROP_STIFF       47
#define EPROP_DAMP        48
#define EPROP_MASS        51
#define EPROP_OFFSETVEC   52
#define EPROP_INERTIA     53
#define EPROP_MASSMATRIX  54
#define EPROP_STIFFMATRIX 55
#define EPROP_PENALTY     56
#define EPROP_FILM        61
#define EPROP_CONVEXP     63
#define EPROP_AREAFACT    64
/* CONVEXCH to be deprecated */
#define EPROP_STRSCOEF 65
/* 1D translationnal stiffness [3]*/
#define EPROP_STIFFTRA 74
/* 1D rotationnal stiffness [3]*/
#define EPROP_STIFFROT 75
#define EPROP_DAMPTRA  76
#define EPROP_DAMPROT  77
/* stress recovery factor in trans. dof*/
#define EPROP_STRSCOEFTRA 78
/* strain recovery factor in trans. dof*/
#define EPROP_STRNCOEFTRA 79
/* strain recovery factor in rot. dof*/
#define EPROP_STRNCOEFROT  80
#define EPROP_BEAMDIME     82
#define EPROP_DOFFLAG_WGTS 84
#define EPROP_SHELLMATRIX  90
#define EPROP_SHELLALPHA   91
#define EPROP_QMATRIX      92
#define EPROP_QALPHA       93
#define EPROP_BEAMMATRIX   94
#define EPROP_BEAMALPHA    95
#define EPROP_LAYER_THK    97
#define EPROP_LAYER_PHI    98
#define EPROP_ECC          101
#define EPROP_BEAMROTANGLE 104
/* 109-110 open */
#define EPROP_RIGIDALPHA     108
#define EPROP_BEAMPNTS       112
#define EPROP_BEAMSEGS_THICK 119
#define EPROP_BEAMSEGS_PNTS  120
#define EPROP_EMIS           135
/* structural damping coefficient */
#define EPROP_SDAMP    137
#define EPROP_SDAMPTRA 138
#define EPROP_SDAMPROT 139
#define EPROP_NSM_VAL  143
/* Arc element angle */
#define EPROP_BEND_THETA 146
/* Elbow/Curved_Pipe internal pressure */
#define EPROP_BEND_INTERNALPRESSURE 147
/* local r offset EndA/EndB points */
#define EPROP_BEND_RCOFFSET 148
/* local z offset EndA/EndB points */
#define EPROP_BEND_ZCOFFSET 149
/* (Curved_beam) radial offset of neutral axis  */
#define EPROP_BEND_ROFFSET 151
/* (Elbow/Curved_Pipe) Mean cross section radius */
#define EPROP_BEND_RADIUSMEAN 152
/* Specifies the relative location of the cohesive layer */
#define EPROP_COHESIVE_LAYER 155
/* Element Gasket thickness */
#define EPROP_GASKET_THICKNESS 156
/* Dilation parameters of the kernel function*/
#define EPROP_GALERKIN_DILATION_PARAMETERS 157
/* Deformation tolerance triggering EFG adaptation */
#define EPROP_GALERKIN_DEFORMATION_TOLERANCE 162
/* Critical value for bond failure triggering */
#define EPROP_GALERKIN_CRITICAL_BOND_FAILURE 168
/* Critical relative deformation (stretching or compression ratio) between the two nodes forming the bond for bond failure */
#define EPROP_GALERKIN_CRITICAL_STRETCH 169
/* Quadrature factor for surface nodes to suppress shear locking in thin structures */
#define EPROP_GALERKIN_SHEAR_LOCKING_FACTOR 171
/* Particle-to-particle damping coefficient */
#define EPROP_GALERKIN_PARTICLE_DAMPING 174
/* Time to switch from updated Lagrangian kernel to Eulerian kernel */
#define EPROP_GALERKIN_SWITCH_TIME_LTE 175
/* Length scale for displacement regularization */
#define EPROP_GALERKIN_LENGTH_SCALE 176
/* Viscous damping coef tension/copmpression */
#define EPROP_VISCOUS_DAMP_TC 177
/* Viscous damping exponent tension/copmpression */
#define EPROP_VISCOUS_EXPNT_TC 178
/* Reinforcement section cross-section area  */
#define EPROP_REINFSECT_AREA 183
/* Reinforcement section inter-fiber distance */
#define EPROP_REINFSECT_FIBER_DISTANCE 184
/* Reinforcement section angle with respect to the default reinforcement system */
#define EPROP_REINFSECT_THETA 186
/* double property types */

#define EPROP_CID             4
#define EPROP_UDELTA          43
#define EPROP_KDELTA          44
#define EPROP_NUMDIST         57
#define EPROP_WEIGHTS         58
#define EPROP_DOFFLAGDEP      59
#define EPROP_DOFFLAGIND      60
#define EPROP_CONVEXCH        62
#define EPROP_ELEMPOINT       66
#define EPROP_ELEMLINE        67
#define EPROP_ELEMTRI         68
#define EPROP_ELEMQUAD        69
#define EPROP_ELEMTET         70
#define EPROP_ELEMPYR         71
#define EPROP_ELEMWED         72
#define EPROP_ELEMHEX         73
#define EPROP_SHEAR_F1        87
#define EPROP_SHEAR_F2        88
#define EPROP_SOLIDMIX        105
#define EPROP_MIX_NUM         106
#define EPROP_MIX_MID         107
#define EPROP_KSYZ            121
#define EPROP_SUPER_MASSTYPE  122
#define EPROP_SUPER_STIFFTYPE 123
#define EPROP_SUPER_MASS      124
#define EPROP_SUPER_STIFF     125
#define EPROP_SUPER_ID        126
#define EPROP_SUPER_TRANS     127
#define EPROP_SUPER_ORIGIN    128
#define EPROP_SUPER_DIRCOS    129
#define EPROP_ORIGIN          131
#define EPROP_TRANS           132
#define EPROP_ROTANG          133
#define EPROP_USER_NUM        134
#define EPROP_COMP_PSDIR      140
/* Element formulation options */
#define EPROP_FORMULATION 153
/* one greater */
#define EPROP_MAX 190

#define EPROP_USERDIMENUM  -1000000
#define EPROP_USERDIME     -2000000
#define EPROP_USERNAME     -3000000
#define EPROP_USERDATATYPE -4000000
#define EPROP_USERDATA     -5000000
#define EPROP_USERBASE     -5000000

/* friction types */
#define EPROP_FRICTION_NOFRICTION       0
#define EPROP_FRICTION_BILINEAR_COULOMB 1
#define EPROP_FRICTION_BILINEAR_SHEAR   2
/* friction types */

/*------------------------------------------------------------------------
 * type definitions
 *-------------------------------------------------------------------------*/
/* defines for cohesives */
#define COHESIVE_RESP_NONE               0
#define COHESIVE_RESP_TRACTIONSEPARATION 1
#define COHESIVE_RESP_CONTINUUM          2
#define COHESIVE_RESP_GASKET             3

#endif
