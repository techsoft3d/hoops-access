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
 
#ifndef LATEXTEXT_DEF
#define LATEXTEXT_DEF
#include "sam/base/basedefs.h"
#include "sam/base/textfun.h"
struct vsy_LaTeXText { Vint ierr;Vint open;Vint connect;
FILE* fd;Vint bodyflag;Vint headlevel;Vint rulewidth;
Vint listtype;Vint prefmode;Vint boldmode;Vint italmode;
Vint typemode;Vint headform;Vint anchform;Vint titlform;
Vint listform;Vint itemform;Vint tableform;Vint rowform;
Vint colform;Vint interrupt;Vint nform;Vint* nformcols;
Vint* formalign;Vchar*** formlist;Vchar** rowcolors;
Vint align;Vint spec;Vfloat textcolor[3];Vfloat tablecolor[3];
Vfloat backcolor[3];Vint borderwidth;Vint tablewidth;
Vint tablecolorid;Vint textcolorid;Vint newtextcolor;
Vint handleerr;
#ifdef __cplusplus
public: VKI_EXTERN vsy_LaTeXText(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_LaTeXText(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void OpenFile(Vchar*);VKI_EXTERN
void CloseFile();VKI_EXTERN void ConnectFile(FILE*);
VKI_EXTERN void DisconnectFile();VKI_EXTERN void QueryFile(FILE**);
VKI_EXTERN void ColumnAlign(Vint);VKI_EXTERN void ListType(Vint);
VKI_EXTERN void HeadingLevel(Vint);VKI_EXTERN void RuleWidth(Vint);
VKI_EXTERN void SetMode(Vint,Vint);VKI_EXTERN void FormInit(Vint);
VKI_EXTERN void FormTerm(Vint);VKI_EXTERN void FormAction(Vint);
VKI_EXTERN void TextColor(Vfloat[3]);VKI_EXTERN void
TableColor(Vfloat[3]);VKI_EXTERN void BackColor(Vfloat[3]);
VKI_EXTERN void BorderWidth(Vint);VKI_EXTERN void TableWidth(Vint);
VKI_EXTERN void HorizontalRule();VKI_EXTERN void ImageFile(Vchar*);
VKI_EXTERN void String(const Vchar*);VKI_EXTERN void
Space(Vint);VKI_EXTERN void TextFun(vsy_TextFun*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_LaTeXText* vsy_LaTeXTextBegin(void);
VKI_EXTERN void vsy_LaTeXText_Construct(vsy_LaTeXText*
p);VKI_EXTERN void vsy_LaTeXTextEnd(vsy_LaTeXText* p);
VKI_EXTERN void vsy_LaTeXText_Destruct(vsy_LaTeXText*
p);VKI_EXTERN Vint vsy_LaTeXTextError(vsy_LaTeXText*
p);VKI_EXTERN void vsy_LaTeXTextOpenFile(vsy_LaTeXText*
p,Vchar* filename);VKI_EXTERN void vsy_LaTeXTextCloseFile(vsy_LaTeXText*
p);VKI_EXTERN void vsy_LaTeXTextConnectFile(vsy_LaTeXText*
p,FILE* fd);VKI_EXTERN void vsy_LaTeXTextDisconnectFile(vsy_LaTeXText*
p);VKI_EXTERN void vsy_LaTeXTextQueryFile(vsy_LaTeXText*
p,FILE** fd);VKI_EXTERN void vsy_LaTeXTextColumnAlign(vsy_LaTeXText*
p,Vint align);VKI_EXTERN void vsy_LaTeXTextListType(vsy_LaTeXText*
p,Vint listtype);VKI_EXTERN void vsy_LaTeXTextHeadingLevel(vsy_LaTeXText*
p,Vint level);VKI_EXTERN void vsy_LaTeXTextRuleWidth(vsy_LaTeXText*
p,Vint rulewidth);VKI_EXTERN void vsy_LaTeXTextSetMode(vsy_LaTeXText*
p,Vint mode,Vint flag);VKI_EXTERN void vsy_LaTeXTextFormInit(vsy_LaTeXText*
p,Vint form);VKI_EXTERN void vsy_LaTeXTextFormTerm(vsy_LaTeXText*
p,Vint form);VKI_EXTERN void vsy_LaTeXTextFormAction(vsy_LaTeXText*
p,Vint form);VKI_EXTERN void vsy_LaTeXTextTextColor(vsy_LaTeXText*
p,Vfloat c[3]);VKI_EXTERN void vsy_LaTeXTextTableColor(vsy_LaTeXText*
p,Vfloat c[3]);VKI_EXTERN void vsy_LaTeXTextBackColor(vsy_LaTeXText*
p,Vfloat c[3]);VKI_EXTERN void vsy_LaTeXTextBorderWidth(vsy_LaTeXText*
p,Vint borderwidth);VKI_EXTERN void vsy_LaTeXTextTableWidth(vsy_LaTeXText*
p,Vint tablewidth);VKI_EXTERN void vsy_LaTeXTextHorizontalRule(vsy_LaTeXText*
p);VKI_EXTERN void vsy_LaTeXTextImageFile(vsy_LaTeXText*
p,Vchar* filename);VKI_EXTERN void vsy_LaTeXTextString(vsy_LaTeXText*
p,const Vchar* string);VKI_EXTERN void vsy_LaTeXTextSpace(vsy_LaTeXText*
p,Vint nspaces);VKI_EXTERN void vsy_LaTeXTextTextFun(vsy_LaTeXText*
p,vsy_TextFun* textfun);
#ifdef __cplusplus
}
#endif
#endif

