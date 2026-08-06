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
 
#ifndef TEXTFUN_DEF
#define TEXTFUN_DEF
#include <stdio.h>
#include "sam/base/basedefs.h"
typedef void(VTextFunOpenFile)(Vobject*,Vchar*);typedef
void(VTextFunCloseFile)(Vobject*);typedef void(VTextFunConnectFile)(Vobject*,
FILE*);typedef void(VTextFunDisconnectFile)(Vobject*);
typedef void(VTextFunQueryFile)(Vobject*,FILE**);typedef
void(VTextFunListType)(Vobject*,Vint);typedef void(VTextFunHeadingLevel)(Vobject*
p,Vint);typedef void(VTextFunRuleWidth)(Vobject* p,
Vint);typedef void(VTextFunSetMode)(Vobject*,Vint,Vint);
typedef void(VTextFunFormInit)(Vobject*,Vint);typedef
void(VTextFunFormTerm)(Vobject*,Vint);typedef void(VTextFunFormAction)(Vobject*,
Vint);typedef void(VTextFunHorizontalRule)(Vobject*);
typedef void(VTextFunImageFile)(Vobject*,Vchar*);typedef
void(VTextFunString)(Vobject*,const Vchar*);typedef
void(VTextFunSpace)(Vobject*,Vint);typedef void(VTextFunTextColor)(Vobject*,
Vfloat[3]);typedef void(VTextFunTableColor)(Vobject*,
Vfloat[3]);typedef void(VTextFunBackColor)(Vobject*,
Vfloat[3]);typedef void(VTextFunBorderWidth)(Vobject*,
Vint);typedef void(VTextFunTableWidth)(Vobject*,Vint);
typedef void(VTextFunColumnAlign)(Vobject*,Vint);
#define TEXTFUN_UNDEFINED -1
#define TEXTFUN_OPENFILE 1
#define TEXTFUN_CLOSEFILE 2
#define TEXTFUN_LISTTYPE 3
#define TEXTFUN_HEADINGLEVEL 4
#define TEXTFUN_RULEWIDTH 5
#define TEXTFUN_SETMODE 6
#define TEXTFUN_FORMINIT 7
#define TEXTFUN_FORMTERM 8
#define TEXTFUN_FORMACTION 9
#define TEXTFUN_HORIZONTALRULE 10
#define TEXTFUN_IMAGEFILE 11
#define TEXTFUN_STRING 12
#define TEXTFUN_CONNECTFILE 13
#define TEXTFUN_DISCONNECTFILE 14
#define TEXTFUN_QUERYFILE 15
#define TEXTFUN_COLUMNALIGN 16
#define TEXTFUN_SPACE 17
#define TEXTFUN_TEXTCOLOR 18
#define TEXTFUN_TABLECOLOR 19
#define TEXTFUN_BACKCOLOR 20
#define TEXTFUN_BORDERWIDTH 21
#define TEXTFUN_TABLEWIDTH 22
#define TEXTFUN_ERROR 23
#define TEXTFUN_MAX 24
#define TEXTFUN_APIPRINT 0
#define TEXTFUN_APIRETURN 1
struct vsy_TextFun { Vint ierr;Vobject* obj;void (*fun[1])(void);
void (*openfile)(Vobject*,Vchar*);void (*closefile)(Vobject*);
void (*listtype)(Vobject*,Vint);void (*headinglevel)(Vobject*,
Vint);void (*rulewidth)(Vobject*,Vint);void (*setmode)(Vobject*,
Vint,Vint);void (*forminit)(Vobject*,Vint);void (*formterm)(Vobject*,
Vint);void (*formaction)(Vobject*,Vint);void (*horizontalrule)(Vobject*);
void (*imagefile)(Vobject*,Vchar*);void (*string)(Vobject*,
const Vchar*);void (*connectfile)(Vobject*,FILE*);void
(*disconnectfile)(Vobject*);void (*queryfile)(Vobject*,
FILE**);void (*columnalign)(Vobject*,Vint);void (*space)(Vobject*,
Vint);void (*textcolor)(Vobject*,Vfloat[3]);void (*tablecolor)(Vobject*,
Vfloat[3]);void (*backcolor)(Vobject*,Vfloat[3]);void
(*borderwidth)(Vobject*,Vint);void (*tablewidth)(Vobject*,
Vint);Vint (*error)(Vobject*);
#ifdef __cplusplus
public: VKI_EXTERN vsy_TextFun(void);VKI_EXTERN void*
operator new(size_t);VKI_EXTERN ~vsy_TextFun(void);
VKI_EXTERN void operator delete(void*);VKI_EXTERN Vint
Error();VKI_EXTERN void Init();VKI_EXTERN void Set(Vint,
Vfunc*);VKI_EXTERN void SetErrorFunction(VfuncInt*);
VKI_EXTERN void Get(Vint,Vfunc**);VKI_EXTERN void SetObj(Vobject*);
VKI_EXTERN void GetObj(Vobject**);VKI_EXTERN void Copy(vsy_TextFun*);
VKI_EXTERN void API(Vint);VKI_EXTERN void OpenFile(Vchar*);
VKI_EXTERN void CloseFile();VKI_EXTERN void ConnectFile(FILE*);
VKI_EXTERN void DisconnectFile();VKI_EXTERN void QueryFile(FILE**);
VKI_EXTERN void ListType(Vint);VKI_EXTERN void HeadingLevel(Vint);
VKI_EXTERN void RuleWidth(Vint);VKI_EXTERN void SetMode(Vint,
Vint);VKI_EXTERN void FormInit(Vint);VKI_EXTERN void
FormTerm(Vint);VKI_EXTERN void FormAction(Vint);VKI_EXTERN
void HorizontalRule();VKI_EXTERN void ImageFile(Vchar*);
VKI_EXTERN void String(const Vchar*);VKI_EXTERN void
Space(Vint);VKI_EXTERN void TextColor(Vfloat[3]);VKI_EXTERN
void TableColor(Vfloat[3]);VKI_EXTERN void BackColor(Vfloat[3]);
VKI_EXTERN void BorderWidth(Vint);VKI_EXTERN void TableWidth(Vint);
VKI_EXTERN void ColumnAlign(Vint);VKI_EXTERN void SetOpenFileFun(VTextFunOpenFile*);
VKI_EXTERN void SetCloseFileFun(VTextFunCloseFile*);
VKI_EXTERN void SetConnectFileFun(VTextFunConnectFile*);
VKI_EXTERN void SetDisconnectFileFun(VTextFunDisconnectFile*);
VKI_EXTERN void SetQueryFileFun(VTextFunQueryFile*);
VKI_EXTERN void SetListTypeFun(VTextFunListType*);VKI_EXTERN
void SetHeadingLevelFun(VTextFunHeadingLevel*);VKI_EXTERN
void SetRuleWidthFun(VTextFunRuleWidth*);VKI_EXTERN
void SetSetModeFun(VTextFunSetMode*);VKI_EXTERN void
SetFormInitFun(VTextFunFormInit*);VKI_EXTERN void SetFormTermFun(VTextFunFormTerm*);
VKI_EXTERN void SetFormActionFun(VTextFunFormAction*);
VKI_EXTERN void SetHorizontalRuleFun(VTextFunHorizontalRule*);
VKI_EXTERN void SetImageFileFun(VTextFunImageFile*);
VKI_EXTERN void SetStringFun(VTextFunString*);VKI_EXTERN
void SetSpaceFun(VTextFunSpace*);VKI_EXTERN void SetTextColorFun(VTextFunTextColor*);
VKI_EXTERN void SetTableColorFun(VTextFunTableColor*);
VKI_EXTERN void SetBackColorFun(VTextFunBackColor*);
VKI_EXTERN void SetBorderWidthFun(VTextFunBorderWidth*);
VKI_EXTERN void SetTableWidthFun(VTextFunTableWidth*);
VKI_EXTERN void SetColumnAlignFun(VTextFunColumnAlign*);
#endif
};
#ifdef __cplusplus
extern "C" { 
#endif
VKI_EXTERN vsy_TextFun* vsy_TextFunBegin(void);VKI_EXTERN
void vsy_TextFun_Construct(vsy_TextFun* p);VKI_EXTERN
void vsy_TextFunEnd(vsy_TextFun* p);VKI_EXTERN void
vsy_TextFun_Destruct(vsy_TextFun* p);VKI_EXTERN Vint
vsy_TextFunError(vsy_TextFun* p);VKI_EXTERN void vsy_TextFunInit(vsy_TextFun*
p);VKI_EXTERN void vsy_TextFunSet(vsy_TextFun* p,Vint
type,Vfunc* function);VKI_EXTERN void vsy_TextFunSetErrorFunction(vsy_TextFun*
p,VfuncInt* function);VKI_EXTERN void vsy_TextFunGet(vsy_TextFun*
p,Vint type,Vfunc** function);VKI_EXTERN void vsy_TextFunSetObj(vsy_TextFun*
p,Vobject* obj);VKI_EXTERN void vsy_TextFunGetObj(vsy_TextFun*
p,Vobject** obj);VKI_EXTERN void vsy_TextFunCopy(vsy_TextFun*
p,vsy_TextFun* fromp);VKI_EXTERN void vsy_TextFunAPI(vsy_TextFun*
p,Vint api);VKI_EXTERN void vsy_TextFunOpenFile(vsy_TextFun*
p,Vchar* pathname);VKI_EXTERN void vsy_TextFunCloseFile(vsy_TextFun*
p);VKI_EXTERN void vsy_TextFunConnectFile(vsy_TextFun*
p,FILE* fd);VKI_EXTERN void vsy_TextFunDisconnectFile(vsy_TextFun*
p);VKI_EXTERN void vsy_TextFunQueryFile(vsy_TextFun*
p,FILE** fd);VKI_EXTERN void vsy_TextFunListType(vsy_TextFun*
p,Vint listtype);VKI_EXTERN void vsy_TextFunHeadingLevel(vsy_TextFun*
p,Vint level);VKI_EXTERN void vsy_TextFunRuleWidth(vsy_TextFun*
p,Vint rulewidth);VKI_EXTERN void vsy_TextFunSetMode(vsy_TextFun*
p,Vint mode,Vint flag);VKI_EXTERN void vsy_TextFunFormInit(vsy_TextFun*
p,Vint form);VKI_EXTERN void vsy_TextFunFormTerm(vsy_TextFun*
p,Vint form);VKI_EXTERN void vsy_TextFunFormAction(vsy_TextFun*
p,Vint formaction);VKI_EXTERN void vsy_TextFunHorizontalRule(vsy_TextFun*
p);VKI_EXTERN void vsy_TextFunImageFile(vsy_TextFun*
p,Vchar* pathname);VKI_EXTERN void vsy_TextFunString(vsy_TextFun*
p,const Vchar* string);VKI_EXTERN void vsy_TextFunSpace(vsy_TextFun*
p,Vint nspaces);VKI_EXTERN void vsy_TextFunTextColor(vsy_TextFun*
p,Vfloat c[3]);VKI_EXTERN void vsy_TextFunTableColor(vsy_TextFun*
p,Vfloat c[3]);VKI_EXTERN void vsy_TextFunBackColor(vsy_TextFun*
p,Vfloat c[3]);VKI_EXTERN void vsy_TextFunBorderWidth(vsy_TextFun*
p,Vint borderwidth);VKI_EXTERN void vsy_TextFunTableWidth(vsy_TextFun*
p,Vint tablewidth);VKI_EXTERN void vsy_TextFunColumnAlign(vsy_TextFun*
p,Vint align);VKI_EXTERN void vsy_TextFunSetOpenFileFun(vsy_TextFun*
p,VTextFunOpenFile* func);VKI_EXTERN void vsy_TextFunSetCloseFileFun(vsy_TextFun*
p,VTextFunCloseFile* func);VKI_EXTERN void vsy_TextFunSetConnectFileFun(vsy_TextFun*
p,VTextFunConnectFile* func);VKI_EXTERN void vsy_TextFunSetDisconnectFileFun(vsy_TextFun*
p,VTextFunDisconnectFile* func);VKI_EXTERN void vsy_TextFunSetQueryFileFun(vsy_TextFun*
p,VTextFunQueryFile* func);VKI_EXTERN void vsy_TextFunSetListTypeFun(vsy_TextFun*
p,VTextFunListType* func);VKI_EXTERN void vsy_TextFunSetHeadingLevelFun(vsy_TextFun*
p,VTextFunHeadingLevel* func);VKI_EXTERN void vsy_TextFunSetRuleWidthFun(vsy_TextFun*
p,VTextFunRuleWidth* func);VKI_EXTERN void vsy_TextFunSetSetModeFun(vsy_TextFun*
p,VTextFunSetMode* func);VKI_EXTERN void vsy_TextFunSetFormInitFun(vsy_TextFun*
p,VTextFunFormInit* func);VKI_EXTERN void vsy_TextFunSetFormTermFun(vsy_TextFun*
p,VTextFunFormTerm* func);VKI_EXTERN void vsy_TextFunSetFormActionFun(vsy_TextFun*
p,VTextFunFormAction* func);VKI_EXTERN void vsy_TextFunSetHorizontalRuleFun(vsy_TextFun*
p,VTextFunHorizontalRule* func);VKI_EXTERN void vsy_TextFunSetImageFileFun(vsy_TextFun*
p,VTextFunImageFile* func);VKI_EXTERN void vsy_TextFunSetStringFun(vsy_TextFun*
p,VTextFunString* func);VKI_EXTERN void vsy_TextFunSetSpaceFun(vsy_TextFun*
p,VTextFunSpace* func);VKI_EXTERN void vsy_TextFunSetTextColorFun(vsy_TextFun*
p,VTextFunTextColor* func);VKI_EXTERN void vsy_TextFunSetTableColorFun(vsy_TextFun*
p,VTextFunTableColor* func);VKI_EXTERN void vsy_TextFunSetBackColorFun(vsy_TextFun*
p,VTextFunBackColor* func);VKI_EXTERN void vsy_TextFunSetBorderWidthFun(vsy_TextFun*
p,VTextFunBorderWidth* func);VKI_EXTERN void vsy_TextFunSetTableWidthFun(vsy_TextFun*
p,VTextFunTableWidth* func);VKI_EXTERN void vsy_TextFunSetColumnAlignFun(vsy_TextFun*
p,VTextFunColumnAlign* func);
#ifdef __cplusplus
}
#endif
#define vsy_TextFunObj(x)(x)->obj
#if !defined(VKI_FUN_NODEFINE)|| defined(VKI_FUN_DEFINE)
#define vsy_TextFunOpenFile(x,a)(x)->openfile((x)->obj,\
(a))
#define vsy_TextFunCloseFile(x)(x)->closefile((x)->obj)
#define vsy_TextFunListType(x,a)(x)->listtype((x)->obj,\
(a))
#define vsy_TextFunHeadingLevel(x,a)(x)->headinglevel((x)->obj,\
(a))
#define vsy_TextFunRuleWidth(x,a)(x)->rulewidth((x)->obj,\
(a))
#define vsy_TextFunSetMode(x,a,b)(x)->setmode((x)->obj,\
(a),(b))
#define vsy_TextFunFormInit(x,a)(x)->forminit((x)->obj,\
(a))
#define vsy_TextFunFormTerm(x,a)(x)->formterm((x)->obj,\
(a))
#define vsy_TextFunFormAction(x,a)(x)->formaction((x)->obj,\
(a))
#define vsy_TextFunHorizontalRule(x)(x)->horizontalrule((x)->obj)
#define vsy_TextFunImageFile(x,a)(x)->imagefile((x)->obj,\
(a))
#define vsy_TextFunString(x,a)(x)->string((x)->obj,\
(a))
#define vsy_TextFunConnectFile(x,a)(x)->connectfile((x)->obj,\
(a))
#define vsy_TextFunDisconnectFile(x)(x)->disconnectfile((x)->obj)
#define vsy_TextFunQueryFile(x,a)(x)->queryfile((x)->obj,\
(a))
#define vsy_TextFunColumnAlign(x,a)(x)->columnalign((x)->obj,\
(a))
#define vsy_TextFunSpace(x,a)(x)->space((x)->obj,(a))
#define vsy_TextFunTextColor(x,a)(x)->textcolor((x)->obj,\
(a))
#define vsy_TextFunTableColor(x,a)(x)->tablecolor((x)->obj,\
(a))
#define vsy_TextFunBackColor(x,a)(x)->backcolor((x)->obj,\
(a))
#define vsy_TextFunBorderWidth(x,a)(x)->borderwidth((x)->obj,\
(a))
#define vsy_TextFunTableWidth(x,a)(x)->tablewidth((x)->obj,\
(a))
#endif
#endif

