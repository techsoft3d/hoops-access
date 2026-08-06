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
#ifndef OPTIONS_DEF
#define OPTIONS_DEF

#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/base/inthash.h"

struct vdm_Options {
    VConventionType conventions;
    vsy_IntHash* modes;
    Vint ierr;
    Vint fileFormat;

#ifdef __cplusplus
  public:
    VKI_EXTERN
    vdm_Options(void);
    VKI_EXTERN void*
    operator new(size_t);
    VKI_EXTERN ~vdm_Options(void);
    VKI_EXTERN void
    operator delete(void*);
    VKI_EXTERN Vint
    Error();
    VKI_EXTERN void
    AddConvention(VConventionType convention);
    VKI_EXTERN void
    SetMode(Vint mode, Vint value);
    VKI_EXTERN void SetFileFormat(Vint);
    VKI_EXTERN void
    GetConventions(VConventionType* conventions);
    VKI_EXTERN void
    GetModes(vsy_IntHash** modes);
    VKI_EXTERN void
    GetFileFormat(Vint*);

#endif
};

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vdm_Options*
vdm_OptionsBegin(void);
VKI_EXTERN void
vdm_Options_Construct(vdm_Options* p);
VKI_EXTERN Vint
vdm_OptionsError(vdm_Options* p);
VKI_EXTERN void
vdm_OptionsAddConvention(vdm_Options* p, VConventionType convention);
VKI_EXTERN void
vdm_OptionsSetMode(vdm_Options* p, Vint mode, Vint value);
VKI_EXTERN void
vdm_OptionsSetFileFormat(vdm_Options* p, Vint fileFormat);
VKI_EXTERN void
vdm_OptionsGetModes(vdm_Options* p, vsy_IntHash** modes);
VKI_EXTERN void
vdm_OptionsGetConventions(vdm_Options* p, VConventionType* conventions);
VKI_EXTERN void
vdm_OptionsGetFileFormat(vdm_Options* p, Vint* fileFormat);
VKI_EXTERN void
vdm_OptionsEnd(vdm_Options* p);
VKI_EXTERN void
vdm_Options_Destruct(vdm_Options* p);

#ifdef __cplusplus
}
#endif
#endif
