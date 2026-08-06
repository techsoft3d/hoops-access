#ifndef PLUGINMANAGER_DEF
#define PLUGINMANAGER_DEF

#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"

typedef struct vdm_PluginManager vdm_PluginManager;
struct vdm_PluginManager {
    Vint ierr;

#ifdef __cplusplus
  public:
    VKI_EXTERN
    vdm_PluginManager(void);
    VKI_EXTERN void*
    operator new(size_t);
    VKI_EXTERN ~vdm_PluginManager(void);
    VKI_EXTERN void
    operator delete(void*);
    VKI_EXTERN void
    LoadPlugin(Vchar* filename);
    VKI_EXTERN void
    LoadPluginSettings(Vchar* fileMask, vdm_PluginSettings* pluginSettings);
    VKI_EXTERN void
    Shutdown(void);
    VKI_EXTERN Vint
    Error(void);
    VKI_EXTERN void SetErrorLevel(Vint);
    VKI_EXTERN Vint
    GetErrorLevel();
    VKI_EXTERN Vint
    IsSupportedByALoadedProvider(const Vchar* fileMask);
#endif
};

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vdm_PluginManager*
vdm_PluginManagerBegin(void);
VKI_EXTERN void
vdm_PluginManager_Construct(vdm_PluginManager* p);
VKI_EXTERN void
vdm_PluginManagerEnd(vdm_PluginManager* p);
VKI_EXTERN void
vdm_PluginManager_Destruct(vdm_PluginManager* p);
VKI_EXTERN void
vdm_PluginManagerShutdown(vdm_PluginManager* p);
VKI_EXTERN void
vdm_PluginManagerLoadPlugin(vdm_PluginManager* p, Vchar* pathToPluginLibraryWithoutExtension);
VKI_EXTERN void
vdm_PluginManagerLoadPluginSettings(vdm_PluginManager* p, Vchar* fileMask, vdm_PluginSettings* pluginSettings);
VKI_EXTERN Vint
vdm_PluginManagerError(vdm_PluginManager* p);
VKI_EXTERN void
vdm_PluginManagerSetErrorLevel(vdm_PluginManager* p, Vint errorLevel);
VKI_EXTERN Vint
vdm_PluginManagerGetErrorLevel(vdm_PluginManager* p);
VKI_EXTERN Vint
vdm_PluginManagerIsSupportedByALoadedProvider(const Vchar* fileMask);

#ifdef __cplusplus
}
#endif

#endif
