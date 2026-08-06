/* Marc .dat Library helper object */
#ifndef MARCFILIO_DEF
#define MARCFILIO_DEF

#include "sam/base/base.h"

#define MARCFILIO_BUFSIZE 256

typedef struct vdm_MarcFilio {
    FILE* fd;
    Vchar buffer[MARCFILIO_BUFSIZE];
    Vchar l[20][80];
    Vchar key[80];
    Vint fixed;
    Vint ncomma;
    Vint comma[80];
    Vint haskey;
    Vint extended;
    Vint listflag;
    Vint nitems;
    vsy_IntHash* nodeih;
} vdm_MarcFilio;

#ifdef __cplusplus
extern "C" {
#endif
VKI_EXTERN vdm_MarcFilio*
vdm_MarcFilioBegin(void);
VKI_EXTERN void
vdm_MarcFilioEnd(vdm_MarcFilio* p);
VKI_EXTERN void
vdm_MarcFilioOpen(vdm_MarcFilio* p, Vchar* filename, Vint* ierr);
VKI_EXTERN void
vdm_MarcFilioClose(vdm_MarcFilio* p);
VKI_EXTERN void
vdm_MarcFilioKeyword(vdm_MarcFilio* p, Vchar key[]);
VKI_EXTERN void
vdm_MarcFilioDataLine(vdm_MarcFilio* p, Vint* iskeyword);
VKI_EXTERN void
vdm_MarcFilioDatac(vdm_MarcFilio* p, Vint fieldno, Vint begin, Vint end, Vchar data[]);
VKI_EXTERN void
vdm_MarcFilioDatai(vdm_MarcFilio* p, Vint fieldno, Vint begin, Vint end, Vint* data);
VKI_EXTERN void
vdm_MarcFilioDatad(vdm_MarcFilio* p, Vint fieldno, Vint begin, Vint end, Vdouble* data);
VKI_EXTERN void
vdm_MarcFilioSetExtended(vdm_MarcFilio* p, Vint extended);
VKI_EXTERN void
vdm_MarcFilioData4c(vdm_MarcFilio* p, Vchar data1[80], Vchar data2[80], Vchar data3[80], Vchar data4[80]);
VKI_EXTERN void
vdm_MarcFilioSetContinuation(vdm_MarcFilio* p, Vint* cont);
VKI_EXTERN void
vdm_MarcFilioSetList(vdm_MarcFilio* p, Vint flag);
VKI_EXTERN void
vdm_MarcFilioDataItemc(vdm_MarcFilio* p, Vint fieldno, Vchar data[]);
VKI_EXTERN void
vdm_MarcFilioDataItemi(vdm_MarcFilio* p, Vint fieldno, Vint* data);
VKI_EXTERN void
vdm_MarcFilioNumList(vdm_MarcFilio* p, Vint* num);
VKI_EXTERN void
vdm_MarcFilioRewind(vdm_MarcFilio* p);

#ifdef __cplusplus
}
#endif

#endif
