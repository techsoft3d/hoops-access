/* PAM input parser object */

#ifndef PAMFILIODEF
#define PAMFILIODEF

#include <stdio.h>
#include "sam/base/base.h"

/* line types */
#define PAMFIL_KEYWORD 1
#define PAMFIL_COMMENT 2
#define PAMFIL_CONTROL 3
#define PAMFIL_NONE    4
#define PAMFIL_EOF     5

/* integer parameters */
#define PAMFIL_LINENUMBER 1

typedef struct vdm_PAMFilio {
    Vint ierr;
    Vchar buffer[256];
    Vint nitems;
    Vint* idata;
    Vint* tdata;
    Vdouble* ddata;
    Vchar** cdata;
    Vchar key[81];
    Vint iscontrol;
    Vint mode;
    Vint nformats;
    Vint formatsize[50];
    Vint formattype[50];
    Vint id;
    vsy_Stack* stack;
} vdm_PAMFilio;

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vdm_PAMFilio*
vdm_PAMFilioBegin(void);
VKI_EXTERN void
vdm_PAMFilioEnd(vdm_PAMFilio* p);
VKI_EXTERN Vint
vdm_PAMFilioError(vdm_PAMFilio* p);
VKI_EXTERN void
vdm_PAMFilioOpen(vdm_PAMFilio* p, Vchar* filename, Vint* status);
VKI_EXTERN void
vdm_PAMFilioClose(vdm_PAMFilio* p);
VKI_EXTERN void
vdm_PAMFilioRewind(vdm_PAMFilio* p);
VKI_EXTERN void
vdm_PAMFilioReadKeyword(vdm_PAMFilio* p, Vint* linetype);
VKI_EXTERN void
vdm_PAMFilioGetKeyword(vdm_PAMFilio* p, Vchar* key);
VKI_EXTERN Vint
vdm_PAMFilioReadDataLine(vdm_PAMFilio* p, Vint* linetype);
VKI_EXTERN Vint
vdm_PAMFilioReadKeyLine(vdm_PAMFilio* p);
VKI_EXTERN void
vdm_PAMFilioReadControlLine(vdm_PAMFilio* p, Vint* nitems, Vchar item[][81]);
VKI_EXTERN void
vdm_PAMFilioSetFormat(vdm_PAMFilio* p, Vint nformats, Vint formatsize[], Vint formattype[]);
VKI_EXTERN void
vdm_PAMFilioDatai(vdm_PAMFilio* p, Vint n, Vint* value);
VKI_EXTERN void
vdm_PAMFilioDataNi(vdm_PAMFilio* p, Vint n, Vint ni, Vint value[]);
VKI_EXTERN void
vdm_PAMFilioDatad(vdm_PAMFilio* p, Vint n, Vdouble* value);
VKI_EXTERN void
vdm_PAMFilio3Datad(vdm_PAMFilio* p, Vint n, Vdouble value[3]);
VKI_EXTERN void
vdm_PAMFilioDatac(vdm_PAMFilio* p, Vint n, Vchar* value);
VKI_EXTERN void
vdm_PAMFilioGetBuffer(vdm_PAMFilio* p, Vint slen, Vchar* buffer);
VKI_EXTERN void
vdm_PAMFilioGetInteger(vdm_PAMFilio* p, Vint type, Vint* value);
VKI_EXTERN void
vdm_PAMFilioGetFilename(vdm_PAMFilio* p, Vchar* filename);
VKI_EXTERN void
vdm_PAMFilioInclude(vdm_PAMFilio* p, Vchar* filename, Vint* status);

#ifdef __cplusplus
}
#endif

#endif
