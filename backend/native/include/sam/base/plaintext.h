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
 
#ifndef PLAINTEXT_DEF
#define PLAINTEXT_DEF
#include "sam/base/basedefs.h"
#include "sam/base/textfun.h"
#define PLAINTEXT_BORDEREQUALS 1
struct vsy_PlainText { Vint ierr;Vint open;Vint connect;
FILE* fd;Vint numchars;Vint pagewidth;Vint headlevel;
Vint rulewidth;Vint listtype;Vint newitem;Vint itemcounter;
Vint prefmode;Vint boldmode;Vint italmode;Vint typemode;
Vint headform;Vint anchform;Vint titlform;Vint listform;
Vint itemform;Vint tableform;Vint tablerow;Vint tablecol;
Vint interrupt;Vint nform;Vint* nformcols;Vint** formalign;
Vint* colwidth;Vchar*** formlist;Vint align;Vint maxrows;
Vint maxcols;Vint borderwidth;Vint tablewidth;Vfloat
backcolor[3];Vfloat tablecolor[3];Vfloat textcolor[3];
Vint borderequals;Vint tabletitles;Vchar buf[1024];
Vint handleerr;
#ifdef __cplusplus
public: VKI_EXTERN vsy_PlainText(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_PlainText(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void OpenFile(Vchar*);VKI_EXTERN
void CloseFile();VKI_EXTERN void ConnectFile(FILE*);
VKI_EXTERN void DisconnectFile();VKI_EXTERN void QueryFile(FILE**);
VKI_EXTERN void ColumnAlign(Vint);VKI_EXTERN void ListType(Vint);
VKI_EXTERN void HeadingLevel(Vint);VKI_EXTERN void RuleWidth(Vint);
VKI_EXTERN void TextColor(Vfloat[3]);VKI_EXTERN void
TableColor(Vfloat[3]);VKI_EXTERN void BackColor(Vfloat[3]);
VKI_EXTERN void BorderWidth(Vint);VKI_EXTERN void TableWidth(Vint);
VKI_EXTERN void SetMode(Vint,Vint);VKI_EXTERN void FormInit(Vint);
VKI_EXTERN void FormTerm(Vint);VKI_EXTERN void FormAction(Vint);
VKI_EXTERN void HorizontalRule();VKI_EXTERN void ImageFile(Vchar*);
VKI_EXTERN void String(const Vchar*);VKI_EXTERN void
Space(Vint);VKI_EXTERN void SetPageWidth(Vint);VKI_EXTERN
void TextFun(vsy_TextFun*);VKI_EXTERN void GetString(Vchar**);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_PlainText* vsy_PlainTextBegin(void);
VKI_EXTERN void vsy_PlainText_Construct(vsy_PlainText*
p);VKI_EXTERN void vsy_PlainTextEnd(vsy_PlainText* p);
VKI_EXTERN void vsy_PlainText_Destruct(vsy_PlainText*
p);VKI_EXTERN Vint vsy_PlainTextError(vsy_PlainText*
p);VKI_EXTERN void vsy_PlainTextOpenFile(vsy_PlainText*
p,Vchar* filename);VKI_EXTERN void vsy_PlainTextCloseFile(vsy_PlainText*
p);VKI_EXTERN void vsy_PlainTextConnectFile(vsy_PlainText*
p,FILE* fd);VKI_EXTERN void vsy_PlainTextDisconnectFile(vsy_PlainText*
p);VKI_EXTERN void vsy_PlainTextQueryFile(vsy_PlainText*
p,FILE** fd);VKI_EXTERN void vsy_PlainTextColumnAlign(vsy_PlainText*
p,Vint align);VKI_EXTERN void vsy_PlainTextListType(vsy_PlainText*
p,Vint listtype);VKI_EXTERN void vsy_PlainTextHeadingLevel(vsy_PlainText*
p,Vint level);VKI_EXTERN void vsy_PlainTextRuleWidth(vsy_PlainText*
p,Vint rulewidth);VKI_EXTERN void vsy_PlainTextTextColor(vsy_PlainText*
p,Vfloat c[3]);VKI_EXTERN void vsy_PlainTextTableColor(vsy_PlainText*
p,Vfloat c[3]);VKI_EXTERN void vsy_PlainTextBackColor(vsy_PlainText*
p,Vfloat c[3]);VKI_EXTERN void vsy_PlainTextBorderWidth(vsy_PlainText*
p,Vint borderwidth);VKI_EXTERN void vsy_PlainTextTableWidth(vsy_PlainText*
p,Vint tablewidth);VKI_EXTERN void vsy_PlainTextSetMode(vsy_PlainText*
p,Vint mode,Vint flag);VKI_EXTERN void vsy_PlainTextFormInit(vsy_PlainText*
p,Vint form);VKI_EXTERN void vsy_PlainTextFormTerm(vsy_PlainText*
p,Vint form);VKI_EXTERN void vsy_PlainTextFormAction(vsy_PlainText*
p,Vint form);VKI_EXTERN void vsy_PlainTextHorizontalRule(vsy_PlainText*
p);VKI_EXTERN void vsy_PlainTextImageFile(vsy_PlainText*
p,Vchar* filename);VKI_EXTERN void vsy_PlainTextString(vsy_PlainText*
p,const Vchar* string);VKI_EXTERN void vsy_PlainTextSpace(vsy_PlainText*
p,Vint nspaces);VKI_EXTERN void vsy_PlainTextSetPageWidth(vsy_PlainText*
p,Vint pagewidth);VKI_EXTERN void vsy_PlainTextTextFun(vsy_PlainText*
p,vsy_TextFun* textfun);VKI_EXTERN void vsy_PlainTextGetString(vsy_PlainText*
p,Vchar** string);
#ifdef __cplusplus
}
#endif
#endif

