using System;
using System.Runtime.InteropServices;
using System.Reflection;
using System.Text;
using DevTools;

public class Exam41
{

    public static double[][] coords = new double[][] {
    new double[] { 0.0,0.0,0.0},
    new double[] {10.0,0.0,0.0},
    new double[] {10.0,1.0,0.0},
    new double[] { 0.0,1.0,0.0} };

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
                          Generate a Mapped Mesh
    ----------------------------------------------------------------------*/
    public static void Main()
    {
        SetEnvironmentPath();
        vsy.LicenseValidate(new StringBuilder(HOOPS_LICENSE.KEY));

        IntPtr mapmesh;
        IntPtr connect;
        int[] pix = new int[4];
        int numnp = 0, numel = 0;
        int[] aids = new int[1];
        int[] aids1 = new int[1];
        int nix = 0;
        int[] ix = new int[8];
        int[] nodes = new int[1];
        double[] x = new double[3];

        /* create MapMesh object */
        mapmesh = msh.MapMeshBegin();
        msh.MapMeshDef(mapmesh, 4, 1);

        /* create Connect object */
        connect = vis.ConnectBegin();
        vis.ConnectDef(connect, 0, 0);


        int i;
        /* define points */
        for (i = 0; i < 4; i++)
        {
            msh.MapMeshSetPoint(mapmesh, i + 1, coords[i]);
        }
        /* define patch connectivity */
        pix[0] = 1;
        pix[1] = 2;
        pix[2] = 3;
        pix[3] = 4;
        msh.MapMeshSetPatch(mapmesh, 1, vis.VIS_SHAPEQUAD, 2, 0, 0, pix);

        /* set assoc of 100 at edge 4 */
        msh.MapMeshSetPatchAssoc(mapmesh, vis.VIS_MISCID, 1, vsy.SYS_EDGE, 4, 100);

        /* set assoc of 200 at point 2 */
        msh.MapMeshSetPointAssoc(mapmesh, vis.VIS_MISCID1, 2, 200);

        /* set mesh parameters */
        msh.MapMeshSetParami(mapmesh, vis.VIS_MESH_MAXI, 3);
        msh.MapMeshSetPatchParami(mapmesh, 1, vis.VIS_MESH_SHAPE, vis.VIS_SHAPEQUAD);
        msh.MapMeshSetPatchParami(mapmesh, 1, msh.MAPMESH_NUMELEMI, 8);
        msh.MapMeshSetPatchParami(mapmesh, 1, msh.MAPMESH_NUMELEMJ, 2);

        /* generate */
        msh.MapMeshGenerate(mapmesh, connect);

        /* print generated nodes and elements */
        vis.ConnectNumber(connect, vsy.SYS_NODE, ref numnp);
        vis.ConnectNumber(connect, vsy.SYS_ELEM, ref numel);
        Console.Write("numnp= {0}, numel= {1}\n", numnp, numel);

        /* print node information */
        Console.Write("Node information\n");
        for (i = 1; i <= numnp; i++)
        {
            nodes[0] = i;
            vis.ConnectCoordsdv(connect, 1, nodes, x);
            vis.ConnectNodeAssoc(connect, vis.VIS_MISCID, 1, nodes, aids);
            vis.ConnectNodeAssoc(connect, vis.VIS_MISCID1, 1, nodes, aids1);
            Console.Write("id= {0}  x= {1}, y= {2}, z= {3}, aid= {4}, aid1= {5}\n",
                    i, x[0], x[1], x[2], aids[0], aids1[0]);
        }
        /* print element information */
        Console.Write("Element information\n");
        for (i = 1; i <= numel; i++)
        {
            vis.ConnectElemNode(connect, i, ref nix, ix);
            Console.Write("id= {0}  ix= {1} {2} {3} {4} {5} {6} {7} {8}\n",
                    i, ix[0], ix[1], ix[2], ix[3], ix[4], ix[5], ix[6], ix[7]);
        }
        /* end objects */
        vis.ConnectEnd(connect);
        msh.MapMeshEnd(mapmesh);
    }
}
