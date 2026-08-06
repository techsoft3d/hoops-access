using System;
using System.Runtime.InteropServices;
using System.Reflection;
using System.Text;
using DevTools;

public class Exam1
{
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
                          List all Datasets
    ----------------------------------------------------------------------*/
    public static void Main()
    {
        SetEnvironmentPath();
        vsy.LicenseValidate(new StringBuilder(HOOPS_LICENSE.KEY));

        IntPtr sdrclib;
        IntPtr datafun;
        int numnp = 0, numel = 0;
        int numdatasets = 0, numattributes = 0;
        StringBuilder dsname = new StringBuilder(1000);
        long lrec = 0;
        int nrow = 0, ncol = 0, ntyp = 0;

        /* create data function object */
        datafun = vdm.DataFunBegin();

        /* create SDRC Universal File library device */
        int filetype = vdm.VDM_SDRC_UNIVERSAL;
        sdrclib = vdm.SDRCLibBegin();
        vdm.SDRCLibDataFun(sdrclib, datafun);

        /* open library device */
        vdm.DataFunOpen(datafun, 0,
                         new StringBuilder("bumper.unv"), filetype);

        /* get number of nodes and elements */
        vdm.DataFunGetNumEntities(datafun, vsy.SYS_NODE, ref numnp);
        vdm.DataFunGetNumEntities(datafun, vsy.SYS_ELEM, ref numel);
        Console.Write("Number of nodes    = {0}\n", numnp);
        Console.Write("Number of elements = {0}\n", numel);

        /* get library object */
        vdm.DataFunGetLibrary(datafun, out IntPtr library);

        /* get number of datasets on library */
        vdm.LibraryGetNumDatasets(library, ref numdatasets);

        /* print heading */
        Console.Write("Number of datasets = {0}\n", numdatasets);
        Console.Write("  Seq     LRec  NRow     NCol  NTyp  NAtt  Name\n");


        int i;
        /* loop through datasets */
        for (i = 0; i < numdatasets; i++)
        {
            vdm.LibraryGetDataset(library, i, out IntPtr dataset);
            vdm.DatasetInq(dataset, dsname, ref lrec, ref nrow, ref ncol, ref ntyp);
            vdm.DatasetGetNumAttributes(dataset, ref numattributes);
            Console.Write("{0} {1} {2} {3} {4} {5}  {6}\n",
                   i, lrec, nrow, ncol, ntyp, numattributes, dsname);
        }
        /* close library device */
        vdm.DataFunClose(datafun);

        /* free objects */
        vdm.DataFunEnd(datafun);
        vdm.SDRCLibEnd(sdrclib);
    }
}
