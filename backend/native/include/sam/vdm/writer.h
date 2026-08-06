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
/* Writer object */
#ifndef WRITER_DEF
#define WRITER_DEF

#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"
#include "sam/vis/model.h"
#include "sam/vis/state.h"
#include "sam/vis/history.h"
#include "sam/vis/rprop.h"
#include "sam/vis/redmat.h"
#include "sam/vis/writerfun.h"
#include "sam/vdm/datafun.h"
#include "sam/vdm/lman.h"
#include "sam/vdm/libraries/native/natlib.h"
#include "sam/vdm/libraries/nastran/naslib.h"
#include "sam/vdm/libraries/abaqus/abalib.h"
#include "sam/vdm/libraries/ensight/ensightlib.h"

/* defines for parameters */
#define WRITER_RESTYPE 1
#define WRITER_RESFILE 2

struct vdm_Writer {
    /* this vis_WriterFun must at the beginning and must not be a pointer */
    vis_WriterFun writerInterface;

    Vint ierr;
    vdm_DataFun* datafun;
    vdm_LMan* lman;
    vdm_NatLib* natlib;
    vdm_NASLib* naslib;
    vdm_ABALib* abalib;
    vdm_EnSightLib* ensightlib;
    Vint restype;
    Vchar resfile[SYS_MAXPATHCHAR];

#ifdef __cplusplus
  public:
    VKI_EXTERN
    vdm_Writer(void);
    VKI_EXTERN void*
    operator new(size_t);
    VKI_EXTERN ~vdm_Writer(void);
    VKI_EXTERN void
    operator delete(void*);
    VKI_EXTERN void
    Def(Vchar*);
    VKI_EXTERN Vint
    Error();
    VKI_EXTERN void SetParami(Vint, Vint);
    VKI_EXTERN void
    GetParami(Vint, Vint*);
    VKI_EXTERN void
    SetParamc(Vint, Vchar*);
    VKI_EXTERN void
    GetParamc(Vint, Vchar*);
    VKI_EXTERN void
    Open(void);
    VKI_EXTERN void
    Close(void);
    VKI_EXTERN void
    WriteState(vis_State*, vis_RProp*);
    VKI_EXTERN void
    WriteRedMat(vis_RedMat*, vis_RProp*);
    VKI_EXTERN void
    WriteHistory(vis_History*, vis_RProp*);
    VKI_EXTERN void
    WriteModel(vis_Model*);
#endif
};

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vdm_Writer*
vdm_WriterBegin(void);
VKI_EXTERN void
vdm_Writer_Construct(vdm_Writer* p);
VKI_EXTERN void
vdm_WriterEnd(vdm_Writer* p);
VKI_EXTERN void
vdm_Writer_Destruct(vdm_Writer* p);
VKI_EXTERN Vint
vdm_WriterError(vdm_Writer* p);
VKI_EXTERN void
vdm_WriterDef(vdm_Writer* p, Vchar* filePath);
VKI_EXTERN void
vdm_WriterSetParami(vdm_Writer* p, Vint ptype, Vint iparam);
VKI_EXTERN void
vdm_WriterGetParami(vdm_Writer* p, Vint type, Vint* iparam);
VKI_EXTERN void
vdm_WriterSetParamc(vdm_Writer* p, Vint ptype, Vchar* cparam);
VKI_EXTERN void
vdm_WriterGetParamc(vdm_Writer* p, Vint type, Vchar* cparam);
VKI_EXTERN void
vdm_WriterWriteState(vdm_Writer* p, vis_State* state, vis_RProp* rprop);
VKI_EXTERN void
vdm_WriterWriteRedMat(vdm_Writer* p, vis_RedMat* redmat, vis_RProp* rprop);
VKI_EXTERN void
vdm_WriterWriteHistory(vdm_Writer* p, vis_History* history, vis_RProp* rprop);
VKI_EXTERN void
vdm_WriterWriteModel(vdm_Writer* p, vis_Model* model);
VKI_EXTERN void
vdm_WriterOpen(vdm_Writer* p);
VKI_EXTERN void
vdm_WriterClose(vdm_Writer* p);

#ifdef __cplusplus
}
#endif

#endif
