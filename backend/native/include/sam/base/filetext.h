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
 
#ifndef FILETEXT_DEF
#define FILETEXT_DEF
#include <stdio.h>
#include "sam/base/basedefs.h"
#include "sam/base/textfun.h"
struct vsy_FileText { Vint ierr;Vint open;Vint connect;
Vchar path[256];FILE* fd;
#ifdef __cplusplus
public: VKI_EXTERN vsy_FileText(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_FileText(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void OpenFile(Vchar*);VKI_EXTERN
void CloseFile();VKI_EXTERN void ConnectFile(FILE*);
VKI_EXTERN void DisconnectFile();VKI_EXTERN void QueryFile(FILE**);
VKI_EXTERN void String(const Vchar*);VKI_EXTERN void
NoOp();VKI_EXTERN void TextFun(vsy_TextFun*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_FileText* vsy_FileTextBegin(void);VKI_EXTERN
void vsy_FileText_Construct(vsy_FileText* p);VKI_EXTERN
void vsy_FileTextEnd(vsy_FileText* p);VKI_EXTERN void
vsy_FileText_Destruct(vsy_FileText* p);VKI_EXTERN Vint
vsy_FileTextError(vsy_FileText* p);VKI_EXTERN void vsy_FileTextOpenFile(vsy_FileText*
p,Vchar* filename);VKI_EXTERN void vsy_FileTextCloseFile(vsy_FileText*
p);VKI_EXTERN void vsy_FileTextConnectFile(vsy_FileText*
p,FILE* fd);VKI_EXTERN void vsy_FileTextDisconnectFile(vsy_FileText*
p);VKI_EXTERN void vsy_FileTextQueryFile(vsy_FileText*
p,FILE** fd);VKI_EXTERN void vsy_FileTextString(vsy_FileText*
p,const Vchar* stg);VKI_EXTERN void vsy_FileTextNoOp(vsy_FileText*
p);VKI_EXTERN void vsy_FileTextTextFun(vsy_FileText*
p,vsy_TextFun* tf);
#ifdef __cplusplus
}
#endif
#endif

