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
/* Track object */

#ifndef TRACK_DEF
#define TRACK_DEF

#include "sam/base/basedefs.h"

struct vsy_Track {
    Vint level;
    vsy_Dictionary* dict;
    vsy_Concat* concat;
    size_t totsize;
    size_t maxsize;
    Vint nummalloc;
    Vint numrealloc;
    Vint numfree;
};

#ifdef __cplusplus
extern "C" {
#endif

VKI_EXTERN void
vsy_TrackInit(void);
VKI_EXTERN void
vsy_TrackTerm(void);
VKI_EXTERN void
vsy_TrackVerify(void);
VKI_EXTERN void
vsy_TrackDump(Vchar filename[]);
VKI_EXTERN void
vsy_TrackNum(Vint* num);
VKI_EXTERN void
vsy_TrackCheck(void);
VKI_EXTERN void
vsy_TrackMalloc(void* bfr, size_t size, Vchar* file, Vint line);
VKI_EXTERN void
vsy_TrackRealloc(void* bfr, void* q, size_t size, Vchar* file, Vint line);
VKI_EXTERN void
vsy_TrackFree(void* bfr);

#ifdef __cplusplus
}
#endif

#endif
