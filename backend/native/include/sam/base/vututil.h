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
 
#ifndef VUTUTIL_DEF
#define VUTUTIL_DEF
#include <stdint.h>
#include "sam/base/basedefs.h"
#ifdef __cplusplus
extern "C" { 
#endif
extern char vut_toupper[128];
#define VUT_toupper(c)vut_toupper[(c)]
#define FNV1_32A_INIT ((uint32_t)0x811c9dc5)
extern void vut_functionMem(void* (*mfun)(size_t),void*
(*rfun)(void*,size_t),void (*ffun)(void*));VKI_EXTERN
void vut_MemorySetFunctions(void* (*mfun)(size_t),void*
(*rfun)(void*,size_t),void (*ffun)(void*));VKI_EXTERN
void vut_MemoryStatistics(size_t* tsize,size_t* msize,
Vint* nmalloc,Vint* nrealloc,Vint* nfree);VKI_EXTERN
void vut_MemoryPrint(void);VKI_EXTERN void* vut_MemoryMalloc(size_t
bytes);VKI_EXTERN void* vut_MemoryRealloc(void* ptr,
size_t bytes);VKI_EXTERN void vut_MemoryFree(void* ptr);
#ifdef VKI_TRACK_MEM
extern void* vut_mallocMemF(size_t bytes,char* file,
int line);extern void* vut_reallocMemF(void* ptr,size_t
bytes,char* file,int line);
#define vut_mallocMem(a)vut_mallocMemF(a,__FILE__,__LINE__)
#define vut_reallocMem(a,b)vut_reallocMemF(a,b,__FILE__,\
__LINE__)
#else
#ifdef VKI_PRINT_MEM
extern void* vut_mallocMemP(size_t bytes,char* file,
int line);extern void* vut_reallocMemP(void* ptr,size_t
bytes,char* file,int line);
#define vut_mallocMem(a)vut_mallocMemP(a,__FILE__,__LINE__)
#define vut_reallocMem(a,b)vut_reallocMemP(a,b,__FILE__,\
__LINE__)
#else
extern void* vut_mallocMem(size_t bytes);extern void*
vut_reallocMem(void* ptr,size_t bytes);
#endif
#endif
extern void vut_freeMem(void* ptr);extern void vut_checkMem(void*
ptr);extern Vint vut_checkMemF(void* ptr);extern Vint
vut_getNumOPENMPThreads(void);extern size_t vut_fromUtf8(const
char* utf8Str,wchar_t* wideCharBuf,size_t maxWideChars);
extern size_t vut_lenUtf8(const char* utf8Str);extern
size_t vut_toUtf8(const wchar_t* wideStr,char* utf8Buf,
size_t maxUtf8Chars);extern size_t vut_MBCSfromUtf8(Vchar
utf8[],Vchar mbcs[],size_t maxMBCSChars);extern int
vut_fseek(FILE* fd,Vlong offset,int whence);extern Vlong
vut_ftell(FILE* fd);extern FILE* vut_fopen(const char*
path,const char* mode);VKI_EXTERN uint32_t vut_hashFnv32a(void
const* buf,size_t len,uint32_t hval);extern void vut_hashSize(Vint
oldsize,Vint* newsize);extern void vut_SortHeapI(Vint
n,Vint iarr[],Vint ibrr[]);extern void vut_SortHeapAbsI(Vint
n,Vint iarr[],Vint ibrr[]);extern void vut_SortHeapL(Vint
n,Vlong larr[],Vint ibrr[]);extern void vut_SortHeapID(Vint
n,Vint iarr[],Vdouble ibrr[]);extern void vut_SortHeapOneI(Vint
n,Vint iarr[]);extern void vut_SortHeapOneL(Vlong n,
Vlong iarr[]);extern void vut_SortHeapOneISeq(Vint n,
Vint iarr[]);extern void vut_SortHeapOneR(Vint n,Vfloat
farr[]);extern void vut_SortHeapOneD(Vint n,Vdouble
farr[]);extern void vut_SortHeapFO(Vint n,Vfloat iarr[],
Vobject* ibrr[]);extern void vut_SortHeapR(Vint n,Vfloat
iarr[],Vint ibrr[]);extern void vut_SortHeapD(Vint n,
Vdouble iarr[],Vint ibrr[]);extern void vut_SortHeapDD(Vint
n,Vdouble iarr[],Vdouble ibrr[]);extern void vut_SortHeapAbsD(Vint
n,Vdouble iarr[],Vint ibrr[]);extern void vut_SortHeapInvAbsD(Vint
n,Vdouble iarr[],Vint ibrr[]);extern void vut_SortHeapC(Vint
n,Vchar* iarr[],Vint ibrr[]);extern void vut_SearchBinaryI(Vint
length,Vint list[],Vint key,Vint* keypos);extern void
vut_SearchBinaryL(Vlong length,Vlong list[],Vlong key,
Vlong* keypos);extern void vut_SearchBinaryR(Vint length,
Vfloat list[],Vfloat key,Vint* keypos);extern void vut_SearchBinaryD(Vint
length,Vdouble list[],Vdouble key,Vint* keypos);extern
void vut_PrintMatrixI(Vint matrix[],Vint n,Vint m,const
Vchar* msg);extern void vut_PrintMatrixR(Vfloat matrix[],
Vint n,Vint m,const Vchar* msg);extern void vut_PrintMatrixCX(Vcomplex
matrix[],Vint n,Vint m,const Vchar* msg);VKI_EXTERN
void vut_PrintMatrixD(Vdouble matrix[],Vint n,Vint m,
const Vchar* msg);extern void vut_PrintLowerTriMatrixD(Vdouble
matrix[],Vint n,const Vchar* msg);extern void vut_StringConvertf2c(Vchar
s[],Vint l,Vchar c[]);extern void vut_StringConvertc2f(Vchar
c[],Vint l,Vchar s[]);extern void vut_StringAbbr(Vchar
s[],Vint nabb,Vchar c[]);extern void vut_StringCheckInteger(Vchar
stg[],Vint* iflag);extern Vint vut_compareStringCase(const
Vchar c[],const Vchar s[]);extern Vint vut_compareStringInsensitive(const
Vchar c[],const Vchar s[],Vint l);extern void vut_StringPlaceNULL(Vchar
s[],Vint l);extern void vut_copyVchar2Vtchar(const Vchar*
c,Vint l,Vtchar s[]);extern void vut_copyVchar2Vwchar(const
Vchar* c,Vint l,Vwchar s[]);extern void vut_copyVwchar2Vtchar(const
Vwchar* c,Vint l,Vtchar s[]);extern void vut_copyVtchar2Vchar(const
Vtchar* c,Vint l,Vchar s[]);extern void vut_printVtchar(const
Vtchar* c);extern void vut_fprintVtchar(FILE* fd,const
Vtchar* c);VKI_EXTERN void vut_brandString(Vchar* brand);
extern void vut_writeControlLine(FILE* fd,Vint type,
Vint objt);extern void vut_readControlLine(FILE* fd,
Vint* type,Vint* swap,Vint* objt,Vint* iver);extern
void vut_copyStringSafe(const Vchar* c,Vint l,Vchar
s[]);extern void vut_StringFindChar(const Vchar* s,
Vchar c,Vint* l);extern void vut_posDirectory(Vchar*
path,Vint* pos);VKI_EXTERN void vut_StringReplace(Vchar*
s,Vchar c,Vchar d);extern void vut_parseInteger(const
Vchar* stg,Vint* ich,Vint* val);extern Vchar* vut_nextToken(Vchar*
stg);extern void vut_fileRoot(Vchar* filename,Vchar
fileroot[]);extern void vut_n1n2(Vint n,Vint _numit,
Vint it,Vint* n1,Vint* n2);extern void vut_CopyC(const
Vchar* a,Vchar b[],Vint n);extern void vut_CopypC(Vint
_numit,Vchar a[],Vchar b[],Vint n);extern void vut_CopyI(Vint
a[],Vint b[],Vint n);extern void vut_CopyIl(Vint a[],
Vint b[],Vlong n);extern void vut_CopyIsize_t(Vint a[],
Vint b[],size_t n);extern void vut_CopypI(Vint _numit,
Vint a[],Vint b[],Vint n);extern void vut_CopyL(Vlong
a[],Vlong b[],Vint n);extern void vut_CopypL(Vint _numit,
Vlong a[],Vlong b[],Vint n);extern void vut_CopyR(Vfloat
a[],Vfloat b[],Vint n);extern void vut_CopypR(Vint _numit,
Vfloat a[],Vfloat b[],Vint n);extern void vut_CopyD(Vdouble
a[],Vdouble b[],Vint n);extern void vut_CopypD(Vint
_numit,Vdouble a[],Vdouble b[],Vint n);extern void vut_CopyDl(Vdouble
a[],Vdouble b[],Vlong n);extern void vut_CopyDR(Vdouble
a[],Vfloat b[],Vint n);extern void vut_CopyRD(Vfloat
a[],Vdouble b[],Vint n);extern void vut_InitB(Vschar
a[],Vint n,Vchar b);extern void vut_InitC(Vchar a[],
Vint n,Vchar b);extern void vut_InitS(Vshort a[],Vint
n,Vshort b);extern void vut_InitI(Vint ia[],Vint n,
Vint ib);extern void vut_InitR(Vfloat a[],Vint n,Vfloat
b);extern void vut_InitD(Vdouble a[],Vint n,Vdouble
b);extern void vut_InitDl(Vdouble a[],Vlong n,Vdouble
b);extern void vut_InitL(Vlong a[],Vint n,Vlong b);
VKI_EXTERN void vut_SizeofDataType(Vint dattype,Vint*
nbytes);extern void vut_ZeroDataType(void* buff,Vlong
lrec,Vint dtyp);extern void vut_ZeroC(Vchar a[],Vlong
n);extern void vut_ZeroS(Vshort a[],Vlong n);extern
void vut_ZeroI(Vint a[],Vlong n);extern void vut_ZeroL(Vlong
a[],Vlong n);extern void vut_ZeroLl(Vlong a[],Vlong
n);extern void vut_ZeroR(Vfloat a[],Vlong n);extern
void vut_ZeroRl(Vfloat a[],Vlong n);VKI_EXTERN void
vut_ZeroD(Vdouble a[],Vlong n);extern void vut_ZeroDl(Vdouble
a[],Vlong n);extern void vut_ZeroP(void* a[],Vlong n);
extern void vut_blankString(Vchar stg[],Vint n);extern
void vut_lowerString(Vchar stg[]);VKI_EXTERN void vut_upperString(Vchar
stg[]);extern void vut_convertStringD2E(Vchar stg[]);
extern void vut_numberString(Vchar stg[],Vint* itype,
Vint* ival,Vfloat* rval);extern void vut_copyStringNonBlank(Vchar
src[],Vchar des[],Vint n);extern void vut_copyNameString(const
Vchar c[],Vchar s[],Vint l);extern void vut_lengthStringNonBlank(Vchar
src[],Vint* n);extern void vut_termStringNonBlank(Vchar
src[]);extern void vut_firstStringNonBlank(Vchar src[],
Vint* n);extern void vut_countlowerspaceString(Vchar
src[],Vint* n);extern void vut_crackDecComps(Vint ncomps,
Vint comps,Vint crack[]);extern void vut_mergeDecComps(Vint
ncomps,Vint crack[],Vint* comps);extern void vut_crackBitFlags(Vint
nflags,Vint flags,Vint crack[]);extern Vint vut_crackBitIdFlag(Vint
flag,Vint bitId);extern void vut_mergeBitFlags(Vint
nflags,Vint crack[],Vint* flags);extern void vut_convertDecCompsBitFlags(Vint
iop,Vint nflags,Vint comps,Vint* flags);extern void
vut_getSwapped(Vint* flag);VKI_EXTERN void vut_swapBytes(Vchar*
bp,Vlong n);VKI_EXTERN void vut_swapBytes8(Vchar* bp,
Vlong n);extern void vut_reverseI(Vint ix[],Vint ixr[],
Vint nix);extern void vut_bandLABEL(Vint n,Vint* adj,
Vlong* xadj,Vint* nnn,Vint* iw,Vint* oldpro,Vint* newpro);
extern void vut_string2number(Vchar string[],Vint stringflag,
Vint* tdata,Vint* idata,Vdouble* ddata);extern Vint
vut_isNanD(Vdouble* a);extern Vint vut_isNanR(Vfloat*
a);extern Vint vut_testSwapD(Vdouble* a);extern Vint
vut_testSwapR(Vfloat* a);extern Vint vut_testSwapI(Vint*
a);extern Vint vut_isEqualToFloatWithTolerance(Vfloat
a,Vfloat b,Vuint epsilonCount);extern Vint vut_isEqualToFloat(Vfloat
a,Vfloat b);extern Vint vut_isEqualToArrayFloatWithTolerance(Vfloat
const* const a,Vfloat const* const b,Vuint arraySize,
Vuint epsilonCount);extern Vint vut_isEqualToArrayFloat(Vfloat
const* const a,Vfloat const* const b,Vuint arraySize);
extern Vint vut_isEqualToDoubleWithTolerance(Vdouble
a,Vdouble b,Vuint epsilonCount);extern Vint vut_isEqualToDouble(Vdouble
a,Vdouble b);extern Vint vut_isEqualToAbsoluteDouble(Vdouble
a,Vdouble b,Vuint epsilonCount);extern Vint vut_isEqualToArrayDoubleWithTolerance(Vdouble
const* const a,Vdouble const* const b,Vuint arraySize,
Vuint epsilonCount);extern Vint vut_isEqualToArrayDouble(Vdouble
const* const a,Vdouble const* const b,Vuint arraySize);
extern Vint vut_isStrictlyLessThanDoubleWithTolerance(Vdouble
a,Vdouble b,Vuint epsilonCount);extern Vint vut_isStrictlyLessThanDouble(Vdouble
a,Vdouble b);extern Vint vut_isStrictlyGreaterThanDoubleWithTolerance(Vdouble
a,Vdouble b,Vuint epsilonCount);extern Vint vut_isStrictlyGreaterThanDouble(Vdouble
a,Vdouble b);extern Vint vut_isLessThanOrEqualToDoubleWithTolerance(Vdouble
a,Vdouble b,Vuint epsilonCount);extern Vint vut_isLessThanOrEqualToDouble(Vdouble
a,Vdouble b);extern Vint vut_isGreaterThanOrEqualToDoubleWithTolerance(Vdouble
a,Vdouble b,Vuint epsilonCount);extern Vint vut_isGreaterThanOrEqualToDouble(Vdouble
a,Vdouble b);extern Vint vut_isEqualToArrayInteger(Vint
const* const a,Vint const* const b,Vuint arraySize);
extern Vint vut_getRegressionsRegenerationFlag(void);
extern void vdm_GradDataVfloat(Vfloat* buff,Vlong num);
extern void vdm_GradDataVdouble(Vdouble* buff,Vlong
num);extern void vdm_NoDataVfloat(Vfloat* buff,Vlong
num);extern void vdm_NoDataVdouble(Vdouble* buff,Vlong
num);extern Vint vut_compareArrays(Vint const* const
array1,const Vint array1Size,Vint const* const array2,
const Vint array2Size);extern Vint vut_areValuesIdenticalInBothArrays(Vint
const* const array1,const Vint array1Size,Vint const*
const array2,const Vint array2Size);
#ifdef __cplusplus
}
#endif
#endif

