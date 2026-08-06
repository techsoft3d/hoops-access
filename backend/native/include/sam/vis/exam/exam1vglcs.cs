using System;
using System.Runtime.InteropServices;
using System.Reflection;
using System.Text;
using DevTools;

public class Exam1vgl
{

    public static float[] xhex = new float[] {
      0.0F,0.0F,0.0F,
      1.0F,0.0F,0.0F,
      1.0F,1.0F,0.0F,
      0.0F,1.0F,0.0F,
      0.0F,0.0F,1.0F,
      1.0F,0.0F,1.0F,
      1.0F,1.0F,1.0F,
      0.0F,1.0F,1.0F };
    public static float[] shex = new float[] {
      0.0F, 1.0F, 1.0F, 0.0F,
      1.0F, 2.0F, 2.0F, 1.0F };
    public static float[] rgb = new float[] {
      0.2F,0.2F,0.2F,
      1.0F,0.0F,0.0F,
      0.0F,1.0F,0.0F,
      0.0F,0.0F,1.0F,
      0.0F,1.0F,1.0F,
      1.0F,0.0F,1.0F,
      1.0F,1.0F,0.0F };

    /*----------------------------------------------------------------------
                  Set environment path
    ----------------------------------------------------------------------*/
    public static void SetEnvironmentPath()
    {
        var pathVariableName = "PATH";
        var scope = EnvironmentVariableTarget.Process;
        var oldPathVariableValue = Environment.GetEnvironmentVariable(pathVariableName, scope);
        var newPathVariableValue = oldPathVariableValue + @";${CEE_SAM_EXTERNAL_LIBRARIES_BIN_PATHS}";
        Environment.SetEnvironmentVariable(pathVariableName, newPathVariableValue, scope);
    }

    /*----------------------------------------------------------------------
                          Generate isosurfaces in a hexahedron
    ----------------------------------------------------------------------*/
    public static void Main()
    {
        SetEnvironmentPath();
        vsy.LicenseValidate(new StringBuilder(HOOPS_LICENSE.KEY));

        IntPtr df;
        IntPtr vc;
        IntPtr levels;
        IntPtr cmap;
        IntPtr threshold;
        IntPtr ogldev;
        IntPtr xfm;
        float[] c = new float[3];
        float[] x = new float[3];
        float[] tm = new float[16];

        vgl.OpenGLDevConnectWIN();
        /* create GL device */
        ogldev = vgl.OpenGLDevBegin();

        /* create draw function object for GL */
        df = vgl.DrawFunBegin();
        vgl.OpenGLDevDrawFun(ogldev, df);

        vgl.DrawFunPositionWindow(df, 200, 200, 400, 400);
        vgl.DrawFunOpenWindow(df, new StringBuilder("Example 1vgl"));
        vgl.DrawFunProjOrtho(df, -2.0F, 2.0F, -2.0F, 2.0F, -2.0F, 2.0F);
        vgl.DrawFunSetMode(df, vgl.VGL_ZBUFFERMODE, vgl.VGL_ON);
        vgl.DrawFunSetMode(df, vgl.VGL_LIGHTMODE, vgl.VGL_ON);
        c[0] = 0.4F; c[1] = 0.4F; c[2] = 0.4F;
        x[0] = 0.0F; x[1] = 0.0F; x[2] = 0.0F;
        vgl.DrawFunLight(df, 0, vgl.VGL_LIGHT_AMBIENT, c, x);
        c[0] = 0.6F; c[1] = 0.6F; c[2] = 0.6F;
        x[0] = 1.0F; x[1] = 1.0F; x[2] = 1.0F;
        vgl.DrawFunLight(df, 1, vgl.VGL_LIGHT_DISTANT, c, x);
        x[0] = -1.0F; x[1] = -1.0F; x[2] = -1.0F;
        vgl.DrawFunLight(df, 2, vgl.VGL_LIGHT_DISTANT, c, x);

        /* create transformation object */
        xfm = vgl.XfmBegin();

        /* vis context and set attributes */
        vc = vislegacy.VisContextBegin();
        vislegacy.VisContextSetIsoValType(vc, vis.VIS_ISOVALSURFACE);

        /* levels, set three evenly spaced levels */
        levels = vislegacy.LevelsBegin();
        int nlevels = 3;
        vislegacy.LevelsDef(levels, vislegacy.LEVELS_LINEAR, nlevels);
        vislegacy.LevelsSetMinMax(levels, 0.0F, 2.0F);
        vislegacy.LevelsGenerate(levels, vislegacy.LEVELS_PADENDS);

        /* color map */
        cmap = vislegacy.ColorMapBegin();
        vislegacy.ColorMapSetType(cmap, vislegacy.COLORMAP_TRUECOLOR);
        vislegacy.ColorMapSetRGB(cmap, nlevels + 1, 0, rgb);

        /* create threshold object and set objects */
        threshold = vislegacy.ThresholdBegin();
        vislegacy.ThresholdSetObject(threshold, vgl.VGL_DRAWFUN, df);
        vislegacy.ThresholdSetObject(threshold, vis.VIS_VISCONTEXT, vc);
        vislegacy.ThresholdSetObject(threshold, vis.VIS_LEVELS, levels);
        vislegacy.ThresholdSetObject(threshold, vis.VIS_COLORMAP, cmap);


        int i;
        /* draw threshold surfaces */
        for (i = 0; i < 30; i++)
        {
            vgl.DrawFunClear(df);
            vgl.DrawFunXfmPush(df);
            vgl.XfmRotate(xfm, i * 12.0F * 0.017453F, vgl.XFM_XAXIS);
            vgl.XfmGetMatrix(xfm, tm);
            vgl.DrawFunXfmLoad(df, tm);
            vislegacy.ThresholdCurv(threshold, shex, xhex, vis.VIS_NODATA, null);
            vgl.DrawFunXfmPop(df);
            vgl.DrawFunSwap(df);
            vgl.DrawFunDelay(df, 1.0F);
        }
        vgl.DrawFunDelay(df, 5.0F);

        /* close window */
        vgl.DrawFunCloseWindow(df);

        /* free all objects */
        vgl.DrawFunEnd(df);
        vislegacy.VisContextEnd(vc);
        vislegacy.LevelsEnd(levels);
        vislegacy.ColorMapEnd(cmap);
        vislegacy.ThresholdEnd(threshold);
        vgl.OpenGLDevEnd(ogldev);
        vgl.XfmEnd(xfm);

        /* disconnect from window system */
        vgl.OpenGLDevDisconnect();
    }
}
