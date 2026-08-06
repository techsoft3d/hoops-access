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
 
#ifndef PLEX_DEF
#define PLEX_DEF
#include "sam/base/basedefs.h"
#include "sam/base/list.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vdm/datafun.h"
#define PLEX_CLOSEAPPEND 1
typedef struct vdm_Plexh { Vint filetype;Vint idst1;
Vint idst2;vdm_DataFun* df;union { vdm_NatLib* natlib;
#ifndef VKI_NOVDMTOOLS
vdm_NASLib* naslib;vdm_PatLib* patlib;vdm_SDRCLib* sdrclib;
vdm_PLOT3DLib* plot3dlib;vdm_FLUENTLib* fluentlib;vdm_CGNSVLib*
cgnsvlib;vdm_STARCCMLib* starccmlib;vdm_TecplotLib*
tecplotlib;vdm_PERMASLib* permaslib;vdm_MemLib* memlib;
#endif
}lib;}vdm_Plexh;typedef struct vdm_Plex { Vint ierr;
Vint numdatasets;Vint numadd;VConventionType conv;Vint
nodata;Vint idtyp,idoff[3];vsy_List* plexhlist;Vint
openlibtype;Vobject* openlib;vdm_Plexh* curplexh;Vint
closeappend;}vdm_Plex;
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vdm_Plex* vdm_PlexBegin(void);VKI_EXTERN
void vdm_PlexEnd(vdm_Plex* p);VKI_EXTERN Vint vdm_PlexError(vdm_Plex*
p);VKI_EXTERN void vdm_PlexSetNumDatasets(vdm_Plex*
p,Vint numdatasets);VKI_EXTERN void vdm_PlexSetMode(vdm_Plex*
p,Vint mode,Vint flag);VKI_EXTERN void vdm_PlexSetConvention(vdm_Plex*
p,VConventionType convention);VKI_EXTERN void vdm_PlexSetIds(vdm_Plex*
p,Vint idtype,Vint id1off,Vint id2off,Vint id3off);
VKI_EXTERN void vdm_PlexSetParami(vdm_Plex* p,Vint type,
Vint iparam);VKI_EXTERN void vdm_PlexAdd(vdm_Plex* p,
vis_Connect* connect,vdm_Library* library,Vchar* filename,
Vint type);VKI_EXTERN void vdm_PlexReadDataset(vdm_Plex*
p,Vint idst,void* buff);VKI_EXTERN void vdm_PlexReadDatasetCols(vdm_Plex*
p,Vint idst,Vint ncols,Vint cols[],void* buff,Vlong*
lptr);VKI_EXTERN void vdm_PlexSetOpenLib(vdm_Plex* p,
Vint type,Vobject* openlib);
#ifdef __cplusplus
}
#endif
#endif

