C-----------------------------------------------------------------------
C                     Generate isosurfaces in a hexahedron
C-----------------------------------------------------------------------
      PROGRAM INTRO1F
      INCLUDE 'base/fortran/base.inc'
      INCLUDE 'vgl/fortran/vgl.inc'
      INCLUDE 'vis/fortran/vis.inc'
      REAL XHEX(3,8), SHEX(8), RGB(3,4)
      DATA XHEX /
     $   0.,0.,0., 1.,0.,0., 1.,1.,0., 0.,1.,0.,
     $   0.,0.,1., 1.,0.,1., 1.,1.,1., 0.,1.,1. /
      DATA SHEX /
     $   0., 1., 1., 0.,
     $   1., 2., 2., 1.  /
      DATA RGB /
     $   .2,.2,.2, 1.,0.,0., 0.,1.,0., 0.,0.,1. /
C
      DOUBLE PRECISION DF,VC,LEVELS,CMAP,TMAP,THRESHOLD
      INTEGER NLEVELS
C
C                     create draw function object    
C
      CALL VGLF_DRAWFUNBEGIN(DF)
C
C                     set built in print functions    
C
      CALL VGLF_DRAWFUNAPI(DF,DRAWFUN_APIPRINT)
C
C                     vis context and set attributes   
C
      CALL VISF_VISCONTEXTBEGIN(VC)
      CALL VISF_VISCONTEXTSETISOVALTYPE (VC,VIS_ISOVALSURFACE)
C
C                     levels, set three evenly spaced levels   
C
      CALL VISF_LEVELSBEGIN(LEVELS)
      NLEVELS = 3
      CALL VISF_LEVELSDEF (LEVELS,LEVELS_LINEAR,NLEVELS)
      CALL VISF_LEVELSSETMINMAX (LEVELS,0.,2.)
      CALL VISF_LEVELSGENERATE (LEVELS,LEVELS_PADENDS)
C
C                     color map   
C
      CALL VISF_COLORMAPBEGIN(CMAP)
      CALL VISF_COLORMAPSETTYPE (CMAP,COLORMAP_TRUECOLOR)
      CALL VISF_COLORMAPSETRGB (CMAP,NLEVELS+1,0,RGB)
C
C                     transparency map   
C
      CALL VISF_TRANSMAPBEGIN(TMAP)
C
C                     create threshold object and set objects   
C
      CALL VISF_THRESHOLDBEGIN(THRESHOLD)
      CALL VISF_THRESHOLDSETOBJECT (THRESHOLD,VGL_DRAWFUN,DF)
      CALL VISF_THRESHOLDSETOBJECT (THRESHOLD,VIS_VISCONTEXT,VC)
      CALL VISF_THRESHOLDSETOBJECT (THRESHOLD,VIS_LEVELS,LEVELS)
      CALL VISF_THRESHOLDSETOBJECT (THRESHOLD,VIS_COLORMAP,CMAP)
      CALL VISF_THRESHOLDSETOBJECT (THRESHOLD,VIS_TRANSMAP,TMAP)
C
C                     draw threshold surfaces    
C
      CALL VISF_THRESHOLDCURV (THRESHOLD,SHEX,XHEX,VIS_NODATA,0)
C
C                     free all objects    
C
      CALL VGLF_DRAWFUNEND (DF)
      CALL VISF_VISCONTEXTEND (VC)
      CALL VISF_LEVELSEND (LEVELS)
      CALL VISF_COLORMAPEND (CMAP)
      CALL VISF_TRANSMAPEND (TMAP)
      CALL VISF_THRESHOLDEND (THRESHOLD)
C
      END
