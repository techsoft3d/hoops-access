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
/* RegExp object */

#ifndef REGEXP_DEF
#define REGEXP_DEF

#include "sam/base/basedefs.h"

/* defines */
#define REGEXP_MAXDFA 1024
#define REGEXP_MAXTAG 10

#define REGEXP_MAXCHR 128
#define REGEXP_CHRBIT 8
#define REGEXP_BITBLK (REGEXP_MAXCHR / REGEXP_CHRBIT)

/* parameter */
#define REGEXP_SQUAREBRACKET 1
#define REGEXP_POSIX         3

struct vsy_RegExp {
    Vint ierr;
    Vint squarebracket;
    Vint tagstk[REGEXP_MAXTAG]; /* subpat tag stack..*/
    Vchar dfa[REGEXP_MAXDFA];   /* automaton..       */
    Vint sta;                   /* status of lastpat */
    Vchar savexp[REGEXP_MAXDFA];
    Vchar bittab[REGEXP_BITBLK]; /* bit table for CCL */
    Vchar* bol;
    Vchar* bopat[REGEXP_MAXTAG];
    Vchar* eopat[REGEXP_MAXTAG];
    Vint posix; /* posix flag */
};

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vsy_RegExp*
vsy_RegExpBegin(void);
VKI_EXTERN void
vsy_RegExp_Construct(vsy_RegExp* p);
VKI_EXTERN void
vsy_RegExpEnd(vsy_RegExp* p);
VKI_EXTERN void
vsy_RegExp_Destruct(vsy_RegExp* p);
VKI_EXTERN Vint
vsy_RegExpError(vsy_RegExp* p);
VKI_EXTERN void
vsy_RegExpSetParami(vsy_RegExp* p, Vint type, Vint iparam);
VKI_EXTERN void
vsy_RegExpForm(vsy_RegExp* p, Vchar* exp);
VKI_EXTERN void
vsy_RegExpMatch(vsy_RegExp* p, Vchar* stg, Vint* imatch);

#ifdef __cplusplus
}
#endif

#endif
