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
/* VdmTools overall header file */

#ifndef VDM_DEF
#define VDM_DEF

#include "sam/base/base.h"
#include "sam/vdm/vdmdefs.h"

#include "sam/vdm/attribute.h"
#include "sam/vdm/dataset.h"
#include "sam/vdm/library.h"
#include "sam/vdm/lman.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/dataipc.h"
#include "sam/vdm/disk.h"
#include "sam/vdm/libraries/abaqus/abafil.h"
#include "sam/vdm/libraries/abaqus/abalib.h"
#include "sam/vdm/libraries/adams/adamslib.h"
#include "sam/vdm/libraries/aflr/aflrfil.h"
#include "sam/vdm/libraries/ansys/ansfil.h"
#include "sam/vdm/libraries/ansys/anslib.h"
#include "sam/vdm/libraries/autodyn/autodynlib.h"
#include "sam/vdm/libraries/cfx/cfxlib.h"
#include "sam/vdm/libraries/cgns/cgnsvlib.h"
#include "sam/vdm/libraries/comsol/comsollib.h"
#include "sam/vdm/libraries/lsdyna/d3dfil.h"
#include "sam/vdm/libraries/lsdyna/d3dlib.h"
#include "sam/vdm/elemsect.h"
#include "sam/vdm/libraries/ensight/ensightlib.h"
#include "sam/vdm/libraries/fidap/fdilib.h"
#include "sam/vdm/libraries/femap/femaplib.h"
#include "sam/vdm/libraries/fluent/fluentlib.h"
#include "sam/vdm/libraries/gmv/gmvlib.h"
#include "sam/vdm/libraries/altair/h3dlib.h"
#include "sam/vdm/libraries/hypermesh/hmafil.h"
#include "sam/vdm/libraries/marc/marclib.h"
#include "sam/vdm/libraries/marc/marcfil.h"
#include "sam/vdm/libraries/mem/memlib.h"
#include "sam/vdm/libraries/nastran/nasfil.h"
#include "sam/vdm/libraries/nastran/naslib.h"
#include "sam/vdm/libraries/native/natlib.h"
#include "sam/vdm/libraries/openfoam/openfoamlib.h"
#include "sam/vdm/libraries/obj/objfil.h"
#include "sam/vdm/libraries/pam/pamfil.h"
#include "sam/vdm/libraries/pam/pamlib.h"
#include "sam/vdm/libraries/patran/patlib.h"
#include "sam/vdm/libraries/permas/permaslib.h"
#include "sam/vdm/libraries/plot3d/plot3dlib.h"
#include "sam/vdm/libraries/polyflow/polyflowlib.h"
#include "sam/vdm/libraries/mechanica/rasfil.h"
#include "sam/vdm/libraries/mechanica/raslib.h"
#include "sam/vdm/libraries/samcef/samceflib.h"
#include "sam/vdm/libraries/sdrc/sdrclib.h"
#include "sam/vdm/libraries/starccm/starccmlib.h"
#include "sam/vdm/libraries/stl/stlfil.h"
#include "sam/vdm/libraries/tecplot/tecplotlib.h"
#include "sam/vdm/libraries/vtk/vtklib.h"
#include "sam/vdm/libraries/dpf/dpflib.h"
#include "sam/vdm/options.h"
#include "sam/vdm/plugins/pluginlib.h"
#include "sam/vdm/settings.h"
#include "sam/vdm/unrecognizeddata.h"
#include "sam/vdm/writer.h"

#endif

//==================================================================================================
/// \file vdm.h
///
/// \defgroup VdmTools VdmTools
/// \brief Data Management and Interoperability
//==================================================================================================
