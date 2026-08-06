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
 
#ifndef HTMLTEXT_DEF
#define HTMLTEXT_DEF
#include "sam/base/basedefs.h"
#include "sam/base/textfun.h"
struct vsy_HTMLText { Vint ierr;Vint open;Vint connect;
FILE* fd;Vint bodyflag;Vint headlevel;Vint rulewidth;
Vint listtype;Vint prefmode;Vint boldmode;Vint italmode;
Vint typemode;Vint centermode;Vint headform;Vint anchform;
Vint titlform;Vint listform;Vint itemform;Vint tableform;
Vint tablerow;Vint tablecol;Vint interrupt;Vint align;
Vint textcolor;Vint tablecolor;Vint backcolor;Vint borderwidth;
Vint tablewidth;Vint handleerr;Vint nrows;Vint tabletitles;
#ifdef __cplusplus
public: VKI_EXTERN vsy_HTMLText(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_HTMLText(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void OpenFile(Vchar*);VKI_EXTERN
void CloseFile();VKI_EXTERN void ConnectFile(FILE*);
VKI_EXTERN void DisconnectFile();VKI_EXTERN void QueryFile(FILE**);
VKI_EXTERN void ListType(Vint);VKI_EXTERN void HeadingLevel(Vint);
VKI_EXTERN void RuleWidth(Vint);VKI_EXTERN void TextColor(Vfloat[3]);
VKI_EXTERN void TableColor(Vfloat[3]);VKI_EXTERN void
BackColor(Vfloat[3]);VKI_EXTERN void BorderWidth(Vint);
VKI_EXTERN void TableWidth(Vint);VKI_EXTERN void SetMode(Vint,
Vint);VKI_EXTERN void FormInit(Vint);VKI_EXTERN void
FormTerm(Vint);VKI_EXTERN void FormAction(Vint);VKI_EXTERN
void HorizontalRule();VKI_EXTERN void Space(Vint);VKI_EXTERN
void ImageFile(Vchar*);VKI_EXTERN void ColumnAlign(Vint);
VKI_EXTERN void String(const Vchar*);VKI_EXTERN void
TextFun(vsy_TextFun*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_HTMLText* vsy_HTMLTextBegin(void);VKI_EXTERN
void vsy_HTMLText_Construct(vsy_HTMLText* p);VKI_EXTERN
void vsy_HTMLTextEnd(vsy_HTMLText* p);VKI_EXTERN void
vsy_HTMLText_Destruct(vsy_HTMLText* p);VKI_EXTERN Vint
vsy_HTMLTextError(vsy_HTMLText* p);VKI_EXTERN void vsy_HTMLTextOpenFile(vsy_HTMLText*
p,Vchar* filename);VKI_EXTERN void vsy_HTMLTextCloseFile(vsy_HTMLText*
p);VKI_EXTERN void vsy_HTMLTextConnectFile(vsy_HTMLText*
p,FILE* fd);VKI_EXTERN void vsy_HTMLTextDisconnectFile(vsy_HTMLText*
p);VKI_EXTERN void vsy_HTMLTextQueryFile(vsy_HTMLText*
p,FILE** fd);VKI_EXTERN void vsy_HTMLTextListType(vsy_HTMLText*
p,Vint listtype);VKI_EXTERN void vsy_HTMLTextHeadingLevel(vsy_HTMLText*
p,Vint level);VKI_EXTERN void vsy_HTMLTextRuleWidth(vsy_HTMLText*
p,Vint rulewidth);VKI_EXTERN void vsy_HTMLTextTextColor(vsy_HTMLText*
p,Vfloat c[3]);VKI_EXTERN void vsy_HTMLTextTableColor(vsy_HTMLText*
p,Vfloat c[3]);VKI_EXTERN void vsy_HTMLTextBackColor(vsy_HTMLText*
p,Vfloat c[3]);VKI_EXTERN void vsy_HTMLTextBorderWidth(vsy_HTMLText*
p,Vint borderwidth);VKI_EXTERN void vsy_HTMLTextTableWidth(vsy_HTMLText*
p,Vint tablewidth);VKI_EXTERN void vsy_HTMLTextSetMode(vsy_HTMLText*
p,Vint mode,Vint flag);VKI_EXTERN void vsy_HTMLTextFormInit(vsy_HTMLText*
p,Vint form);VKI_EXTERN void vsy_HTMLTextFormTerm(vsy_HTMLText*
p,Vint form);VKI_EXTERN void vsy_HTMLTextFormAction(vsy_HTMLText*
p,Vint form);VKI_EXTERN void vsy_HTMLTextHorizontalRule(vsy_HTMLText*
p);VKI_EXTERN void vsy_HTMLTextSpace(vsy_HTMLText* p,
Vint nspaces);VKI_EXTERN void vsy_HTMLTextImageFile(vsy_HTMLText*
p,Vchar* filename);VKI_EXTERN void vsy_HTMLTextColumnAlign(vsy_HTMLText*
p,Vint align);VKI_EXTERN void vsy_HTMLTextString(vsy_HTMLText*
p,const Vchar* string);VKI_EXTERN void vsy_HTMLTextTextFun(vsy_HTMLText*
p,vsy_TextFun* textfun);
#ifdef __cplusplus
}
#endif
#endif

