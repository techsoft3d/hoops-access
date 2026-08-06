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
/* WriterFun object */
#ifndef WRITERFUN_DEF
#define WRITERFUN_DEF

#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
#include "sam/vis/model.h"
#include "sam/vis/state.h"
#include "sam/vis/history.h"
#include "sam/vis/rprop.h"
#include "sam/vis/redmat.h"

/* defines for function prototypes */
typedef void(VFuncWriterWriteState)(Vobject*, vis_State*, vis_RProp*);
typedef void(VFuncWriterWriteRedMat)(Vobject*, vis_RedMat*, vis_RProp*);
typedef void(VFuncWriterWriteHistory)(Vobject*, vis_History*, vis_RProp*);
typedef void(VFuncWriterWriteModel)(Vobject*, vis_Model*);
typedef void(VFuncWriterGetFilePath)(Vobject*, Vchar*);
typedef void(VFuncWriterGetFileType)(Vobject*, Vint*);

struct vis_WriterFun {
    VFuncWriterWriteState* writeState;
    VFuncWriterWriteRedMat* writeRedMat;
    VFuncWriterWriteHistory* writeHistory;
    VFuncWriterWriteModel* writeModel;
    VFuncWriterGetFilePath* getFilePath;
    VFuncWriterGetFileType* getFileType;

#ifdef __cplusplus
  public:
    VKI_EXTERN
    vis_WriterFun(void);
    VKI_EXTERN void*
    operator new(size_t);
    VKI_EXTERN ~vis_WriterFun(void);
    VKI_EXTERN void
    operator delete(void*);
    VKI_EXTERN void
    SetWriteStateFunction(VFuncWriterWriteState*);
    VKI_EXTERN void
    SetWriteRedMatFunction(VFuncWriterWriteRedMat*);
    VKI_EXTERN void
    SetWriteHistoryFunction(VFuncWriterWriteHistory*);
    VKI_EXTERN void
    SetWriteModelFunction(VFuncWriterWriteModel*);
    VKI_EXTERN void
    SetGetFilePathFunction(VFuncWriterGetFilePath*);
    VKI_EXTERN void
    SetGetFileTypeFunction(VFuncWriterGetFileType*);
    VKI_EXTERN void
    WriteState(vis_State*, vis_RProp*);
    VKI_EXTERN void
    WriteRedMat(vis_RedMat*, vis_RProp*);
    VKI_EXTERN void
    WriteHistory(vis_History*, vis_RProp*);
    VKI_EXTERN void
    WriteModel(vis_Model*);
    VKI_EXTERN void
    GetFilePath(Vchar*);
    VKI_EXTERN void
    GetFileType(Vint*);
#endif
};

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vis_WriterFun*
vis_WriterFunBegin(void);
VKI_EXTERN void
vis_WriterFun_Construct(vis_WriterFun* p);
VKI_EXTERN void
vis_WriterFunEnd(vis_WriterFun* p);
VKI_EXTERN void
vis_WriterFun_Destruct(vis_WriterFun* p);
VKI_EXTERN void
vis_WriterFunSetWriteStateFunction(vis_WriterFun* p, VFuncWriterWriteState* function);
VKI_EXTERN void
vis_WriterFunSetWriteRedMatFunction(vis_WriterFun* p, VFuncWriterWriteRedMat* function);
VKI_EXTERN void
vis_WriterFunSetWriteHistoryFunction(vis_WriterFun* p, VFuncWriterWriteHistory* function);
VKI_EXTERN void
vis_WriterFunSetWriteModelFunction(vis_WriterFun* p, VFuncWriterWriteModel* function);
VKI_EXTERN void
vis_WriterFunSetGetFilePathFunction(vis_WriterFun* p, VFuncWriterGetFilePath* function);
VKI_EXTERN void
vis_WriterFunSetGetFileTypeFunction(vis_WriterFun* p, VFuncWriterGetFileType* function);
VKI_EXTERN void
vis_WriterFunWriteState(vis_WriterFun* p, vis_State* state, vis_RProp* rprop);
VKI_EXTERN void
vis_WriterFunWriteRedMat(vis_WriterFun* p, vis_RedMat* redmat, vis_RProp* rprop);
VKI_EXTERN void
vis_WriterFunWriteHistory(vis_WriterFun* p, vis_History* history, vis_RProp* rprop);
VKI_EXTERN void
vis_WriterFunWriteModel(vis_WriterFun* p, vis_Model* model);
VKI_EXTERN void
vis_WriterFunGetFilePath(vis_WriterFun* p, Vchar* filePath);
VKI_EXTERN void
vis_WriterFunGetFileType(vis_WriterFun* p, Vint* fileType);

#ifdef __cplusplus
}
#endif

#endif
