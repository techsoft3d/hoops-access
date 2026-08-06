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
/* Fortran to C header file */
// clang-format off
#ifndef FORTRAN_DEF
#define FORTRAN_DEF

                   /* Definitions:
                    * FMPREFIX:    Fortran Module Prefix
                    * FMNAME:      Fortran Module Name
                    * FMCALL:      Fortran Module Call
                    * Used to declare BLAS functions:
                    * STR_NSTG   
                    * STR_DSTG
                    * STR_NLEN
                    * STR_DLEN
                    */

/*  Fortran callable C routine
FMNAME(lname,uname) (
STR_PSTR(cval1),
float   *fval,
double  *dval,
STR_PSTR(cval2),
int *ival
STR_PLEN(cval1)
STR_PLEN(cval2))
*/

#ifdef   VKI_F77_NONE
#       define L8NG long
#       define UL8NG unsigned long
#  define FMPREFIX                              /* Fortran Module Prefix */
#  define FMNAME(lname, uname) void lname ## _
#  define FMCALL(lname, uname) lname ## _       /* Fortran Module Call */
#  define STR_PSTR(str) char *str
#  define STR_PLEN(str) , int Len ## str
#  define STR_PTR(str)  str
#  define STR_LEN(str)  Len ## str
#  define STR_SDEF(str) char *str; int Len ## str
#  define STR_SPTR(str, ptr) str = (char *)ptr
#  define STR_SLEN(str, len) Len ## str = (int)len
#  define STR_FSTR(str) (char *)str
#  define STR_FLEN(str) , (int)Len ## str
#  define STR_NSTG(str)  str
#  define STR_DSTG       char*
#  define STR_NLEN(str)  ,(int)strlen(str)
#  define STR_DLEN       ,int

#elif defined(__GNUC__) /* GNU compiler */
#   define FMPREFIX
#   define FMNAME(lname, uname) void lname ## _
#   define FMCALL(lname, uname) lname ## _
#   define STR_PSTR(str) char *str
#   define STR_PLEN(str) , int Len ## str
#   define STR_PTR(str)	 str
#   define STR_LEN(str)	 Len ## str
#   define STR_SDEF(str) char *str; int Len ## str
#   define STR_SPTR(str, ptr)   str = (char *)ptr
#   define STR_SLEN(str, len)   Len ## str = (int)len
#   define STR_FSTR(str)	     (char *)str
#   define STR_FLEN(str)	     , (int)Len ## str
#   define STR_NSTG(str)  str
#   define STR_DSTG       char*
#   define STR_NLEN(str)  ,(int)strlen(str)
#   define STR_DLEN       ,int

#elif defined(_AIX)         || \
      defined(__hp9000s300) || \
      defined(__hp9000s700) || \
      defined(__hp9000s800) || \
      defined(hitachi)
# 	 define FMPREFIX
#        ifdef VKI_F77_AIXEXTNAME
# 	    define FMNAME(lname, uname) void lname ## _
# 	    define FMCALL(lname, uname) lname ## _
#        else
# 	    define FMNAME(lname, uname) void lname
# 	    define FMCALL(lname, uname) lname
#        endif
# 	 define STR_PSTR(str)	     char *str
# 	 define STR_PLEN(str)	     , int Len ## str
# 	 define STR_PTR(str)	        str
# 	 define STR_LEN(str)	        Len ## str
# 	 define STR_SDEF(str)	     char *str; int Len ## str
# 	 define STR_SPTR(str, ptr)   str = (char *)ptr
# 	 define STR_SLEN(str, len)   Len ## str = (int)len
# 	 define STR_FSTR(str)	     (char *)str
# 	 define STR_FLEN(str)	     , (int)Len ## str
#   define STR_NSTG(str)  str
#   define STR_DSTG       char*
#   define STR_NLEN(str)  ,(int)strlen(str)
#   define STR_DLEN       ,int

#elif defined(__ia64)                     || \
      defined(__sgi)                      || \
      defined(sparc)                      || \
      defined(__ultrix)                   || \
      defined(DEC_WIN32_ALPHA_FORTRAN)    || \
      defined(__ksr__)                    || \
      defined(__alpha)                    || \
      defined(nec_ews)                    || \
      defined(cdc)                        || \
      defined(__uxp__)                    || \
      defined(__convex__)
#   define FMPREFIX
#   define FMNAME(lname, uname) void lname ## _
#   define FMCALL(lname, uname) lname ## _
#   define STR_PSTR(str)        char *str
#   define STR_PLEN(str)        , int Len ## str
#   define STR_PTR(str)         str
#   define STR_LEN(str)         Len ## str
#   define STR_SDEF(str)        char *str; int Len ## str
#   define STR_SPTR(str, ptr)   str = (char *)ptr
#   define STR_SLEN(str, len)   Len ## str = (int)len
#   define STR_FSTR(str)        (char *)str
#   define STR_FLEN(str)        , (int)Len ## str
#   define STR_NSTG(str)  str
#   define STR_DSTG       char*
#   define STR_NLEN(str)  ,(int)strlen(str)
#   define STR_DLEN       ,int

#elif defined(_CRAY)
#	 include "/usr/include/fortran.h"
#	 define FMPREFIX
#	 define FMNAME(lname, uname) uname
#	 define FMCALL(lname, uname) uname
#	 define STR_PSTR(str)	     _fcd str
#	 define STR_PLEN(str)
#	 define STR_PTR(str)	        _fcdtocp (str)
#	 define STR_LEN(str)	        _fcdlen (str)
#	 define STR_SDEF(str)	     _fcd str
#	 define STR_SPTR(str, ptr)   str = _cptofcd (ptr, _fcdlen (str))
#	 define STR_SLEN(str, len)   str = _cptofcd (_fcdtocp (str), len)
#	 define STR_FSTR(str)	     (_fcd)str
#	 define STR_FLEN(str)

#elif defined(_WIN32)
#if defined(VKI_F77_DIGITAL)
#   define FMPREFIX __stdcall
#   define FMNAME(lname, uname) FMPREFIX uname
#   define FMCALL(lname, uname) uname
#   define STR_PSTR(str)        char *str, int Len ## str
#   define STR_PLEN(str)
#   define STR_PTR(str)         str
#   define STR_LEN(str)         Len ## str
#   define STR_SDEF(str)        char *str; int Len ## str
#   define STR_SPTR(str, ptr)   str = (char *)ptr
#   define STR_SLEN(str, len)   Len ## str = (int)len
#   define STR_FSTR(str)        (char *)str, (int)Len ## str
#   define STR_FLEN(str)
#   define STR_NSTG(str)  str, (int)strlen(str)
#   define STR_DSTG       char*, int
#   define STR_NLEN(str) 
#   define STR_DLEN       
#elif defined(VKI_F77_INTEL)
#   define FMPREFIX __stdcall
#   define FMNAME(lname, uname) FMPREFIX uname
#   define FMCALL(lname, uname) uname
#   define STR_PSTR(str)        char *str, int Len ## str
#   define STR_PLEN(str)
#   define STR_PTR(str)         str
#   define STR_LEN(str)         Len ## str
#   define STR_SDEF(str)        char *str; int Len ## str
#   define STR_SPTR(str, ptr)   str = (char *)ptr
#   define STR_SLEN(str, len)   Len ## str = (int)len
#   define STR_FSTR(str)        (char *)str, (int)Len ## str
#   define STR_FLEN(str)
#   define STR_NSTG(str)  str
#   define STR_DSTG       char*
#   define STR_NLEN(str)  ,(int)strlen(str)
#   define STR_DLEN       ,int
#else
#   define FMPREFIX
#   define FMNAME(lname, uname) lname
#   define FMCALL(lname, uname) lname
#   define STR_PSTR(str) char *str
#   define STR_PLEN(str) , int Len ## str
#   define STR_PTR(str)  str
#   define STR_LEN(str)  Len ## str
#   define STR_SDEF(str) char *str; int Len ## str
#   define STR_SPTR(str, ptr) str = (char *)ptr
#   define STR_SLEN(str, len) Len ## str = (int)len
#   define STR_FSTR(str) (char *)str
#   define STR_FLEN(str) , (int)Len ## str
#   define STR_NSTG(str)  str
#   define STR_DSTG       char*
#   define STR_NLEN(str)  ,(int)strlen(str)
#   define STR_DLEN       ,int
#endif

#else
#   define FMPREFIX
#   define FMNAME(lname, uname) void lname ## _
#   define FMCALL(lname, uname) lname ## _
#   define STR_PSTR(str)        char *str
#   define STR_PLEN(str)        , int Len ## str
#   define STR_PTR(str)         str
#   define STR_LEN(str)         Len ## str
#   define STR_SDEF(str)        char *str; int Len ## str
#   define STR_SPTR(str, ptr)   str = (char *)ptr
#   define STR_SLEN(str, len)   Len ## str = (int)len
#   define STR_FSTR(str)        (char *)str
#   define STR_FLEN(str)        , (int)Len ## str
#   define STR_NSTG(str)  str
#   define STR_DSTG       char*
#   define STR_NLEN(str)  ,(int)strlen(str)
#   define STR_DLEN       ,int

#endif

#endif
// clang-format on
