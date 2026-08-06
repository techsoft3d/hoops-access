#ifndef PLUGINOPTIONS_DEF
#define PLUGINOPTIONS_DEF

/*
file       :  .h
description:
Notes      :
*/
#pragma once

#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"

typedef void PluginSettingsAdapter;

//----------------------------------------------------------------------------------------------
// This class set the reader settings for a all libraries and plugins
//-----------------------------------------------------------------------------------------------
struct vdm_PluginSettings {
    Vchar idString[SYS_MAXNAME];
    PluginSettingsAdapter* options;
    Vint errorCode;

#ifdef __cplusplus
  public:
    VKI_EXTERN
    vdm_PluginSettings(void);
    VKI_EXTERN void*
    operator new(size_t);
    VKI_EXTERN ~vdm_PluginSettings(void);
    VKI_EXTERN void
    operator delete(void*);
    VKI_EXTERN Vint
    Error();
    VKI_EXTERN void
    Def(Vchar*);
    VKI_EXTERN void
    Inq(Vchar*);
    VKI_EXTERN Vint
    Count(Vint*, Vint*, Vint*);
    VKI_EXTERN void
    GetInteger(Vint, Vchar*, Vchar*, Vint*);
    VKI_EXTERN void
    GetDouble(Vint, Vchar*, Vchar*, Vdouble*);
    VKI_EXTERN void
    GetString(Vint, Vchar*, Vchar*, Vchar*);
    VKI_EXTERN void
    PushInteger(Vchar*, Vchar*, Vint);
    VKI_EXTERN void
    PushDouble(Vchar*, Vchar*, Vdouble);
    VKI_EXTERN void
    PushString(Vchar*, Vchar*, Vchar*);
    VKI_EXTERN void
    Print();
#endif
};

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vdm_PluginSettings*
vdm_PluginSettingsBegin(void);
VKI_EXTERN void
vdm_PluginSettings_Construct(vdm_PluginSettings* p);
VKI_EXTERN void
vdm_PluginSettingsEnd(vdm_PluginSettings* p);
VKI_EXTERN void
vdm_PluginSettings_Destruct(vdm_PluginSettings* p);
VKI_EXTERN Vint
vdm_PluginSettingsError(vdm_PluginSettings* p);
VKI_EXTERN void
vdm_PluginSettingsDef(vdm_PluginSettings* p, Vchar* idstring);
VKI_EXTERN void
vdm_PluginSettingsInq(vdm_PluginSettings* p, Vchar* idstring);
VKI_EXTERN Vint
vdm_PluginSettingsCount(vdm_PluginSettings* p, Vint* integerkeyCount, Vint* doublekeyCount, Vint* stringkeyCount);
VKI_EXTERN void
vdm_PluginSettingsGetInteger(vdm_PluginSettings* p, Vint integerIndex, Vchar* key, Vchar* description, Vint* value);
VKI_EXTERN void
vdm_PluginSettingsPushInteger(vdm_PluginSettings* p, Vchar* key, Vchar* description, Vint value);
VKI_EXTERN void
vdm_PluginSettingsGetDouble(vdm_PluginSettings* p, Vint doubleIndex, Vchar* key, Vchar* description, Vdouble* value);
VKI_EXTERN void
vdm_PluginSettingsPushDouble(vdm_PluginSettings* p, Vchar* key, Vchar* description, double value);
VKI_EXTERN void
vdm_PluginSettingsGetString(vdm_PluginSettings* p, Vint stringIndex, Vchar* key, Vchar* description, Vchar* value);
VKI_EXTERN void
vdm_PluginSettingsPushString(vdm_PluginSettings* p, Vchar* key, Vchar* description, Vchar* value);
VKI_EXTERN void
vdm_PluginSettingsPrint(vdm_PluginSettings* p);

#ifdef __cplusplus
}
#endif
#endif
