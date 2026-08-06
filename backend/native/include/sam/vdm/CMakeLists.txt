cmake_minimum_required(VERSION 3.21)

project(VdmTools)
message(STATUS "Configuring ${PROJECT_NAME}...")


# Include Vdm source code
# ----------------------------------------------------------
set(CEE_SAM_VDM_SOURCE_FILES
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/adapter.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/adapterlogger.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/attribute.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/datafile.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/datafun.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/dataipc.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/dataset.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/disk.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/elemsect.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/options.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/settings.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/writer.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/abaqus/abadat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/abaqus/abafil.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/abaqus/abafilio.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/abaqus/abalib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/abaqus/abalibio.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/abaqus/vdmodb.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/adams/adamsdat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/adams/adamslib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/adams/adamslibio.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/aflr/aflrfil.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/aflr/aflrfilio.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/altair/h3ddat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/altair/h3dlib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/altair/vdmh3d.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/ansys/ansdat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/ansys/ansfil.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/ansys/ansfilio.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/ansys/anslib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/ansys/anslibio.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/autodyn/autodyndat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/autodyn/autodynlib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/autodyn/vdmautodyn.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/cfx/cfxdat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/cfx/cfxlib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/cgns/cgnsdat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/cgns/cgnsvlib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/cgns/cgnsv_converter.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/cgns/adaptnumericarray.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/comsol/comsoldat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/comsol/comsollib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/comsol/comsollibio.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/dpf/dpf2modelmappings.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/dpf/dpfadapter.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/dpf/dpflib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/dpf/dpfmetadata.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/dpf/dpfmodel.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/ensight/ensightdat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/ensight/ensightlib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/ensight/ensightlibio.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/ensight/ensighttime.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/femap/femapdat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/femap/femaplib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/femap/femaplibio.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/fidap/fdidat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/fidap/fdilib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/fluent/fluentdat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/fluent/fluentlib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/fluent/fluentlibio.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/gmv/gmvdat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/gmv/gmvlib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/gmv/gmvlibio.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/hypermesh/hmafil.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/hypermesh/hmafilio.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/lsdyna/d3ddat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/lsdyna/d3dfil.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/lsdyna/d3dfilio.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/lsdyna/d3dlib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/marc/marcdat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/marc/marcfil.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/marc/marcfilio.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/marc/marclib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/marc/marclibio.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/mechanica/rasdat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/mechanica/rasfil.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/mechanica/raslib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/mem/memlib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/nastran/nasdat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/nastran/nasfil.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/nastran/nasfilio.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/nastran/nash5io.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/nastran/naslib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/nastran/naslibio.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/nastran/nasop2io.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/nastran/vdmnash5.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/nastran/vdmxdb.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/nastran/xdbio.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/native/natdat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/native/natlib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/obj/objfil.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/openfoam/openfoamdat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/openfoam/openfoamlib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/openfoam/openfoamlibio.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/pam/pamdat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/pam/pamfil.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/pam/pamfilio.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/pam/pamlib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/pam/vdmerf.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/patran/patlib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/permas/permasdat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/permas/permaslib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/permas/permaslibio.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/plot3d/plot3dlib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/polyflow/polyflowdat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/polyflow/polyflowlib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/samcef/samcefdat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/samcef/samceflib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/samcef/vdmsamcef.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/sdrc/sdrcdat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/sdrc/sdrclib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/starccm/starccmdat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/starccm/starccmlib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/stl/stlfil.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/tecplot/tecplotdat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/tecplot/tecplotlib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/tecplot/tecplotlibio.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/vtk/vtkdat.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/vtk/vtklib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/vtk/vtklibio.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/vtk/vtuxmlwriter.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/vtk/vtubase64.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/library.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/lman.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/permute.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/plex.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/plugins/pluginadapter.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/plugins/pluginlib.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/plugins/pluginlogger.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/plugins/pluginmanager.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/plugins/pluginmetadata.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/plugins/pluginsettings.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/readersInformation.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/unrecognizeddata.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/vdmadapter.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/vdmoper.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/vdmutil.cpp
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/zfile.cpp
)

set(CEE_SAM_VDM_PUBLIC_HEADER_FILES 
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/adapter.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/attribute.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/datafile.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/datafun.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/dataipc.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/dataset.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/disk.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/elemsect.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/library.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/lman.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/permute.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/plex.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/readersInformation.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/options.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/settings.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/unrecognizeddata.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/vdm.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/vdmadapter.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/vdmdefs.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/lmandefs.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/vdmoper.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/vdmutil.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/writer.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/zfile.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/abaqus/abadat.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/abaqus/abafil.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/abaqus/abalib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/abaqus/vdmaba.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/abaqus/vdmodb.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/adams/adamsdat.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/adams/adamslib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/aflr/aflrfil.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/altair/h3ddat.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/altair/h3dlib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/altair/vdmh3d.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/ansys/ansdat.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/ansys/ansfil.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/ansys/anslib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/autodyn/autodyndat.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/autodyn/autodynlib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/autodyn/vdmautodyn.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/autodyn/vdmautodynres.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/cfx/cfxdat.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/cfx/cfxlib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/cgns/cgnsdat.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/cgns/cgnsvdefs.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/cgns/cgnsvlib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/comsol/comsoldat.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/comsol/comsollib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/dpf/dpflib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/ensight/ensightdat.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/ensight/ensightlib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/ensight/ensighttime.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/femap/femapdat.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/femap/femaplib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/fidap/fdidat.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/fidap/fdilib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/fluent/fluentdat.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/fluent/fluentlib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/gmv/gmvdat.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/gmv/gmvlib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/hypermesh/hmafil.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/lsdyna/d3ddat.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/lsdyna/d3dfil.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/lsdyna/d3dlib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/marc/marcdat.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/marc/marcfil.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/marc/marclib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/marc/vdmmarc.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/mechanica/rasdat.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/mechanica/rasfil.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/mechanica/raslib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/mem/memlib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/nastran/nasdat.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/nastran/nasfil.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/nastran/naslib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/nastran/vdmnash5.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/nastran/vdmxdb.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/native/natdat.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/native/natlib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/obj/objfil.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/openfoam/openfoamdat.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/openfoam/openfoamlib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/pam/pamdat.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/pam/pamfil.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/pam/pamlib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/pam/vdmerf.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/pam/vdmerfres.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/patran/patlib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/permas/permasdat.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/permas/permaslib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/permas/vdmpermas.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/permas/vdmpermasres.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/plot3d/plot3dlib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/polyflow/polyflowdat.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/polyflow/polyflowlib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/samcef/samcefdat.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/samcef/samceflib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/samcef/vdmsamcef.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/samcef/dynamicLoadingWrapperLibrary/loadFunctionPointer.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/sdrc/sdrcdat.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/sdrc/sdrclib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/sdrc/vdmsdrc.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/starccm/starccmdat.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/starccm/starccmlib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/stl/stlfil.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/tecplot/tecplotdat.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/tecplot/tecplotlib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/vtk/vtkdat.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/vtk/vtklib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/plugins/pluginlib.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/plugins/pluginmanager.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/plugins/pluginsettings.h
)

set(CEE_SAM_VDM_HEADER_FILES 
    ${CEE_SAM_VDM_PUBLIC_HEADER_FILES}
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/adapterlogger.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/abaqus/abafilio.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/abaqus/abalibio.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/adams/adamslibio.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/aflr/aflrfilio.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/ansys/ansfilio.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/ansys/anslibio.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/comsol/comsollibio.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/dpf/dpf2modelmappings.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/dpf/dpfadapter.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/dpf/dpfmetadata.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/dpf/dpfmodel.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/ensight/ensightlibio.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/femap/femaplibio.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/fluent/fluentlibio.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/gmv/gmvlibio.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/hypermesh/hmafilio.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/lsdyna/d3dfilio.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/marc/marcfilio.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/marc/marclibio.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/nastran/nasfilio.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/nastran/nash5io.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/nastran/naslibio.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/nastran/nasop2io.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/nastran/xdbio.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/openfoam/openfoamlibio.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/pam/pamfilio.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/permas/permaslibio.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/tecplot/tecplotlibio.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/vtk/vtklibio.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/vtk/vtudataarray.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/vtk/vtuxmlwriter.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/vtk/vtubase64.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/plugins/pluginadapter.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/plugins/pluginlogger.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/plugins/pluginmetadata.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/cgns/cgnsv_converter.h
    ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/cgns/adaptnumericarray.h
)

# Remove files from Cppcheck
if (DEFINED CPP_CHECK_FLAG)
    message(STATUS " - Removing some files for cppcheck")
    list(REMOVE_ITEM CEE_SAM_VDM_SOURCE_FILES ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/nastran/naslib.cpp)
    list(REMOVE_ITEM CEE_SAM_VDM_SOURCE_FILES ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/abaqus/vdmodb.cpp)
endif()

# Include dynamically linking functions
# ----------------------------------------------------------
if(CEE_SAM_INTERFACE_DYNAMIC_LINKING_FLAG)
    message(STATUS " - Adding dynamic loading interface")
    set(CEE_SAM_VDM_SOURCE_FILES ${CEE_SAM_VDM_SOURCE_FILES} ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/samcef/dynamicLoadingWrapperLibrary/libsamcef_wrapper.cpp)
    set(CEE_SAM_VDM_PUBLIC_HEADER_FILES ${CEE_SAM_VDM_PUBLIC_HEADER_FILES} ${CEE_SAM_SRC_SAM_ROOT}/vdm/libraries/samcef/dynamicLoadingWrapperLibrary/libsamcef_wrapper.h)
endif()

# Include C++ interface
# ----------------------------------------------------------
set(CEE_SAM_VDM_SOURCE_CPLUSPLUS_FILES_FILTER cplusplus/*.cxx)
file(GLOB CEE_SAM_VDM_SOURCE_CPLUSPLUS_FILES ${CEE_SAM_VDM_SOURCE_CPLUSPLUS_FILES_FILTER})
list(APPEND CEE_SAM_VDM_SOURCE_FILES ${CEE_SAM_VDM_SOURCE_CPLUSPLUS_FILES})

# Include Fortran interface
# ----------------------------------------------------------
if(CEE_SAM_INTERFACE_FORTRAN)
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/fortran/)
        message(STATUS " - Adding Fortran interface")
        set(CEE_SAM_VDM_SOURCE_FORTRAN_FILES_FILTER fortran/*.c)
    else()
        message(WARNING " - Fortran interface files does not exist")
    endif()
endif()

# Include C# interface
# ----------------------------------------------------------
if(CEE_SAM_INTERFACE_CSHARP)
    # Create csharp folder
    set(CEE_SAM_VDM_CS_FOLDER ${CEE_SAM_SRC_SAM_ROOT}/vdm/csharp)
    if (NOT EXISTS ${CEE_SAM_VDM_CS_FOLDER})
        file(MAKE_DIRECTORY ${CEE_SAM_VDM_CS_FOLDER})
    endif()
    
    # Get cs file
    if(EXISTS ${CEE_SAM_VDM_CS_FOLDER})
        message(STATUS " - Adding C# interface")
        set(CEE_SAM_VDM_SOURCE_CS_FILE ${CEE_SAM_VDM_CS_FOLDER}/vdm.cs)
        if (NOT EXISTS ${CEE_SAM_VDM_SOURCE_CS_FILE})
            file(TOUCH "${CEE_SAM_VDM_SOURCE_CS_FILE}")
        endif()
        if (NOT EXISTS ${CEE_SAM_VDM_SOURCE_CS_FILE})
            message(FATAL_ERROR "Unable to create csharp file ${CEE_SAM_VDM_SOURCE_CS_FILE}!")
        endif()
    else()
        message(WARNING " - C# interface files does not exist")
    endif()
endif()

# Include example programs
# ----------------------------------------------------------
if(CEE_SAM_EXAMPLES)
    if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/exam/CMakeLists.txt")
        message(STATUS " - Adding example programs")
        add_subdirectory(exam)
    endif()
endif()


# Include qual programs
# ----------------------------------------------------------
if(CEE_SAM_QUAL)
    if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/qual/CMakeLists.txt")
        message(STATUS " - Adding qual programs")
        add_subdirectory(qual)
    endif()
endif()


# Setup project
# ----------------------------------------------------------

set(CEE_SAM_VDM_SOURCE_FILES_TO_PARENT ${CEE_SAM_VDM_SOURCE_FILES} PARENT_SCOPE)
set(CEE_SAM_ALL_SOURCE_FILES ${CEE_SAM_ALL_SOURCE_FILES} ${CEE_SAM_VDM_SOURCE_FILES} PARENT_SCOPE)
set(CEE_SAM_VDM_PUBLIC_HEADER_FILES ${CEE_SAM_VDM_PUBLIC_HEADER_FILES} PARENT_SCOPE)
set(CEE_SAM_VDM_HEADER_FILES ${CEE_SAM_VDM_HEADER_FILES} PARENT_SCOPE)
set(CEE_SAM_ALL_HEADER_FILES ${CEE_SAM_ALL_HEADER_FILES} ${CEE_SAM_VDM_HEADER_FILES} PARENT_SCOPE)

if(CEE_SAM_INTERFACE_FORTRAN)
    file(GLOB CEE_SAM_VDM_SOURCE_FORTRAN_FILES ${CEE_SAM_VDM_SOURCE_FORTRAN_FILES_FILTER})
    set(CEE_SAM_ALL_SOURCE_FORTRAN_FILES ${CEE_SAM_ALL_SOURCE_FORTRAN_FILES} ${CEE_SAM_VDM_SOURCE_FORTRAN_FILES} PARENT_SCOPE)
endif()

if(CEE_SAM_INTERFACE_CSHARP)
    set(CEE_SAM_ALL_SOURCE_CS_FILES ${CEE_SAM_ALL_SOURCE_CS_FILES} ${CEE_SAM_VDM_SOURCE_CS_FILE} PARENT_SCOPE)
endif()
