#ifdef CEE_SAM_DATA_PROVIDER_FRAMEWORK
#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/vdm/vdm.h"
#include "sam/vdm/plugins/pluginmanager.h"
#include "sam/vdm/plugins/pluginsettings.h"
#include "sam/vdm/datafile.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

#include <string>

static void
cleanUp(vdm_PluginManager** pluginManager, vdm_PluginSettings** pluginSettingsMap, vdm_DataFun** datafun);

/*----------------------------------------------------------------------
                     VTK Plugin use example reading a vtu file
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    Vchar pluginLibraryPath[SYS_MAXPATHCHAR] = {0};
    Vchar vtuInputfilePath[SYS_MAXPATHCHAR] = {0};

    /* check input arguments */
    if (argc == 3) {
        strcpy(pluginLibraryPath, argv[1]);
        strcpy(vtuInputfilePath, argv[2]);
    }
    else {
        fprintf(stderr, "Usage: %s cdp_vtkPluginPath\n", argv[0]);
        fprintf(stderr, " requires 2 arguments: cdp_vtkPluginPath and vtufilePath\n");
        exit(1);
    }

    /* Set the license */
    vsy_LicenseValidate(HOOPS_LICENSE);

    /* Look for the plugin */
    vdm_PluginManager* pluginManager = vdm_PluginManagerBegin();
    /* Set the log level for only Warnings and Errors */
    vdm_PluginManagerSetErrorLevel(pluginManager, 2);

    /* Load the cdp_VtkPlugin dynamic library*/
    vdm_PluginManagerLoadPlugin(pluginManager, pluginLibraryPath);

    vdm_PluginSettings* vtkPluginSettings = vdm_PluginSettingsBegin();

    vdm_PluginManagerLoadPluginSettings(pluginManager, (Vchar*)".vtu", vtkPluginSettings);

    Vint error = vdm_PluginManagerError(pluginManager);
    if (error) {
        vdm_PluginManagerEnd(pluginManager);
        fprintf(stderr, "%s file does not exist. The library extension must not be included in the path.\n", pluginLibraryPath);
        exit(1);
    }

    /* Create input data function object */
    vdm_DataFun* datafun = vdm_DataFunBegin();
    Vint libType = SYS_PLUGIN;

    datafileinit(libType, datafun);

    /* Set the plugin initialization options (optional) otherwise it will use the default one */
    vdm_PluginSettingsPrint(vtkPluginSettings);
    Vchar optionIdentifier[SYS_MAXNAME] = {0};

    vdm_PluginSettingsInq(vtkPluginSettings, optionIdentifier);
    vdm_Settings* settings = vdm_SettingsBegin();
    vdm_SettingsRegisterPluginSettings(settings, optionIdentifier, vtkPluginSettings);

    vdm_DataFunApplySettings(datafun, settings);

    vdm_DataFunOpen(datafun, 0, vtuInputfilePath, libType);
    Vint ierr = vdm_DataFunError(datafun);
    if (ierr) {
        fprintf(stderr, "Error: opening vtkPlugin\n");
        cleanUp(&pluginManager, &vtkPluginSettings, &datafun);
        exit(1);
    }

    /* Print table of contents */
    vdm_LMan* libraryManager = vdm_LManBegin();
    vdm_LManSetObject(libraryManager, VDM_DATAFUN, datafun);
    vdm_LManSetParami(libraryManager, LMAN_VERBOSE, SYS_ON);
    vdm_LManTOC(libraryManager, "*");

    /* Load state 1: displacement */
    {
        vis_State* stateDisplacement = vis_StateBegin();
        vdm_LManLoadStateFromName(libraryManager, (Vchar*)"D.N", stateDisplacement);

        if (vdm_LManError(libraryManager) == SYS_ERROR_NONE) {
            Vfloat extent[2] = {0.};
            vis_StateSetDerive(stateDisplacement, VIS_VECTOR_MAG);
            vis_StateExtent(stateDisplacement, NULL, extent);
            printf("Displacement Magnitude range min:max = %14e: %14e\n", extent[0], extent[1]);
        }
        vis_StateEnd(stateDisplacement);
    }

    /* Load state 2: stresses */
    {
        vis_State* stateStresses = vis_StateBegin();
        vdm_LManLoadStateFromName(libraryManager, (Vchar*)"S.N", stateStresses);
        Vfloat values[6 * 3] = {0};
        Vint elementIdsCount = 1;
        Vint elementIds[1] = {2};
        vis_StateData(stateStresses, elementIdsCount, elementIds, values);

        if (vdm_LManError(libraryManager) == SYS_ERROR_NONE) {
            Vfloat extent[2] = {0.};
            vis_StateSetDerive(stateStresses, VIS_TENSOR_VONMISES);
            vis_StateExtent(stateStresses, NULL, extent);
            printf("Von Mises Stress range min:max = %14e: %14e\n", extent[0], extent[1]);
        }

        vis_StateEnd(stateStresses);
    }

    /* Free memory */
    vdm_LManEnd(libraryManager);
    vdm_DataFunClose(datafun);
    datafileterm(libType, datafun);
    vdm_SettingsEnd(settings);

    cleanUp(&pluginManager, &vtkPluginSettings, &datafun);

    return 0;
}

static void
cleanUp(vdm_PluginManager** pluginManager, vdm_PluginSettings** pluginSettingsMap, vdm_DataFun** datafun)
{
    if (*datafun) {
        vdm_DataFunEnd(*datafun);
        *datafun = NULL;
    }
    if (*pluginManager) {
        vdm_PluginManagerEnd(*pluginManager);
        *pluginManager = NULL;
    }
    if (*pluginSettingsMap) {
        vdm_PluginSettingsEnd(*pluginSettingsMap);
        *pluginSettingsMap = NULL;
    }
}

#endif
