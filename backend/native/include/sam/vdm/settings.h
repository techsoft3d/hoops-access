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
#ifndef LIBRARYSETTINGS_DEF
#define LIBRARYSETTINGS_DEF

/*
file       :  .h
description:
Notes      :
*/
#pragma once

#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"

//----------------------------------------------------------------------------------------------
// This class set the reader settings for a all libraries and plugins
//-----------------------------------------------------------------------------------------------
struct vdm_Settings {
    vsy_Dictionary* pluginSettingsMap;
    Vint errorCode;

#ifdef __cplusplus
  public:
    VKI_EXTERN
    vdm_Settings(void);
    VKI_EXTERN void*
    operator new(size_t);
    VKI_EXTERN ~vdm_Settings(void);
    VKI_EXTERN void
    operator delete(void*);
    VKI_EXTERN void
    RegisterPluginSettings(Vchar*, vdm_PluginSettings*);
    VKI_EXTERN void
    GetPluginSettings(Vchar*, vdm_PluginSettings**);
    VKI_EXTERN void
    GetAllPluginIdentifiers(vsy_List*);
#endif
};

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vdm_Settings*
vdm_SettingsBegin(void);
VKI_EXTERN void
vdm_Settings_Construct(vdm_Settings* p);
VKI_EXTERN void
vdm_SettingsEnd(vdm_Settings* p);
VKI_EXTERN void
vdm_Settings_Destruct(vdm_Settings* p);
VKI_EXTERN void
vdm_SettingsRegisterPluginSettings(vdm_Settings* p, Vchar* pluginNameId, vdm_PluginSettings* pluginSettings);
VKI_EXTERN void
vdm_SettingsGetPluginSettings(vdm_Settings* p, Vchar* pluginNameId, vdm_PluginSettings** pluginSettings);
VKI_EXTERN void
vdm_SettingsGetAllPluginIdentifiers(vdm_Settings* p, vsy_List* pluginNameIds);

#ifdef __cplusplus
}
#endif
#endif
