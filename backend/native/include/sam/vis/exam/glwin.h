/* GLWin Module */
#ifndef GLWIN_DEF
#define GLWIN_DEF

#include <stdlib.h>

#include "sam/base/basedefs.h"
#include "legacy/vgl/drawfun.h"

#ifdef VKI_WIND_X11
#include <X11/Xlib.h>
#include <unistd.h>
#ifdef VKI_3DAPI_OPENGL
#include <GL/glx.h>
#endif
#endif

#ifdef VKI_WIND_WIN32
#include <windows.h>
#ifdef VKI_3DAPI_OPENGL
#include <GL/gl.h>
#endif
#endif

typedef struct _GLWin {
#ifdef VKI_3DAPI_OPENGL
    GLuint fontoffset;
#endif
#ifdef VKI_WIND_X11
    Display* dpy;
    Window win;
#endif
#ifdef VKI_WIND_WIN32
    HWND hWnd;
    HDC hDC;
    HGLRC hRC;
#endif
    int pxmn, pxmx, pymn, pymx;
    float right, left, bottom, top, nearz, farz;
    float projsx, projsy;
    float crgb[3]; /* Current RGB color */
    int polymode;  /* Polygon lighting flag */
    int lightmode; /* Current lighting flag */
} GLWin;

#ifdef __cplusplus
extern "C" {
#endif

GLWin*
GLWinBegin(void);
void
GLWinColor(GLWin*, Vfloat[3]);
void
GLWinTrans(GLWin*, Vfloat);
void
GLWinLineStyle(GLWin*, Vint);
void
GLWinLineWidth(GLWin*, Vint);
void
GLWinPointSize(GLWin*, Vint);
void
GLWinSetMode(GLWin*, Vint, Vint);
void
GLWinTexture(GLWin*, Vint, Vint, Vfloat[][3]);
void
GLWinPolyPoint(GLWin*, Vint, Vfloat[][3]);
void
GLWinPolyPointDC(GLWin*, Vint, Vfloat[3], Vint[][3]);
void
GLWinPolyLine(GLWin*, Vint, Vint, Vfloat[][3]);
void
GLWinPolyLineColor(GLWin*, Vint, Vint, Vfloat[][3], Vfloat[][3]);
void
GLWinPolyLineDC(GLWin*, Vint, Vint, Vfloat[3], Vint[][3]);
void
GLWinPolygon(GLWin*, Vint, Vint, Vfloat[][3], Vint, Vfloat[]);
void
GLWinPolygonColor(GLWin*, Vint, Vint, Vfloat[][3], Vfloat[][3], Vint, Vfloat[]);
void
GLWinPolygonDC(GLWin*, Vint, Vint, Vfloat[3], Vint[][3]);
void
GLWinText(GLWin*, Vfloat[3], Vchar*);
void
GLWinTextDC(GLWin*, Vfloat[3], Vint[3], Vchar*);
void
GLWinEnd(GLWin*);
void
GLWinCreateWindow(GLWin*, Vint, Vint, Vint, Vint);
void
GLWinDestroyWindow(GLWin*);
void
GLWinOrtho(GLWin*, Vfloat, Vfloat, Vfloat, Vfloat, Vfloat, Vfloat);
void
GLWinViewport(GLWin*, Vint, Vint, Vint, Vint);
void
GLWinClear(GLWin*);
void
GLWinSwap(GLWin*);
void
GLWinRotate(GLWin*, Vfloat, Vchar);
void
GLWinTranslate(GLWin*, Vfloat, Vfloat, Vfloat);
void
GLWinXfmPush(GLWin*);
void
GLWinXfmPop(GLWin*);
void
GLWinXfmLoad(GLWin*, Vfloat[4][4]);
void
GLWinXfmGet(GLWin*, Vfloat[4][4]);
void
GLWinDelay(GLWin*, Vfloat);
void
GLWinDrawFun(GLWin*, vgl_DrawFun*);
#ifdef VKI_WIND_WIN32
extern void
sleep(int sec);
#endif

#ifdef __cplusplus
}
#endif

#endif
