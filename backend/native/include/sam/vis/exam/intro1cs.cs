using System;
using System.Runtime.InteropServices;
using System.Reflection;
using System.Text;
using DevTools;

public class Intro1
{

    public static float[] xhex = {
      0.0F,0.0F,0.0F, 1.0F,0.0F,0.0F, 1.0F,1.0F,0.0F, 0.0F,1.0F,0.0F,
      0.0F,0.0F,1.0F, 1.0F,0.0F,1.0F, 1.0F,1.0F,1.0F, 0.0F,1.0F,1.0F };
    public static float[] shex = {
      0.0F, 1.0F, 1.0F, 0.0F,
      1.0F, 2.0F, 2.0F, 1.0F };
    public static float[] rgb = {
      0.2F,0.2F,0.2F, 1.0F,0.0F,0.0F, 0.0F,1.0F,0.0F, 0.0F,0.0F,1.0F };

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
        IntPtr tmap;
        IntPtr threshold;

        int nlevels;

        /* create draw function object */
        df = vgl.DrawFunBegin();

        /* set built in print functions */
        vgl.DrawFunAPI(df, vgl.DRAWFUN_APIPRINT);

        /* vis context and set attributes */
        vc = vislegacy.VisContextBegin();
        vislegacy.VisContextSetIsoValType(vc, vis.VIS_ISOVALSURFACE);

        /* levels, set three evenly spaced levels */
        levels = vislegacy.LevelsBegin();
        nlevels = 3;
        vislegacy.LevelsDef(levels, vislegacy.LEVELS_LINEAR, nlevels);
        vislegacy.LevelsSetMinMax(levels, 0.0F, 2.0F);
        vislegacy.LevelsGenerate(levels, vislegacy.LEVELS_PADENDS);

        /* color map */
        cmap = vislegacy.ColorMapBegin();
        vislegacy.ColorMapSetType(cmap, vislegacy.COLORMAP_TRUECOLOR);
        vislegacy.ColorMapSetRGB(cmap, nlevels + 1, 0, rgb);

        /* transparency map */
        tmap = vislegacy.TransMapBegin();

        /* create threshold object and set objects */
        threshold = vislegacy.ThresholdBegin();
        vislegacy.ThresholdSetObject(threshold, vgl.VGL_DRAWFUN, df);
        vislegacy.ThresholdSetObject(threshold, vis.VIS_VISCONTEXT, vc);
        vislegacy.ThresholdSetObject(threshold, vis.VIS_LEVELS, levels);
        vislegacy.ThresholdSetObject(threshold, vis.VIS_COLORMAP, cmap);
        vislegacy.ThresholdSetObject(threshold, vis.VIS_TRANSMAP, tmap);

        /* draw threshold surfaces */
        vislegacy.ThresholdCurv(threshold, shex, xhex, vis.VIS_NODATA, null);

        /* free all objects */
        vgl.DrawFunEnd(df);
        vislegacy.VisContextEnd(vc);
        vislegacy.LevelsEnd(levels);
        vislegacy.ColorMapEnd(cmap);
        vislegacy.TransMapEnd(tmap);
        vislegacy.ThresholdEnd(threshold);
    }
}
