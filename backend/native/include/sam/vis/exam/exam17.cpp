#include "sam/base/base.h"
#include "legacy/vgl/vgl.h"
#include "sam/vis/vis.h"
#include "glwin.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Using Coordinate Systems
----------------------------------------------------------------------*/
int
main()
{
    vis_CoordSys* coordsys;
    vis_CoordSys* coordsysang;
    Vfloat x[3], tm[3][3];
    Vfloat xp[3], tmp[3][3], xpl[3], rap[3];
    Vfloat xa[3], tma[3][3];
    Vfloat vp[3], vlc[3], vpc[3];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create Cylindrical CoordSys */
    coordsys = vis_CoordSysBegin();
    vis_CoordSysDef(coordsys, SYS_CYLINDRICAL);

    /* set origin at 10.,10.,0. */
    x[0] = 10.;
    x[1] = 10.;
    x[2] = 0.;
    /* set orientation, x' along z, y' along x, z' along y */
    tm[0][0] = 0.;
    tm[0][1] = 0.;
    tm[0][2] = 1.;
    tm[1][0] = 1.;
    tm[1][1] = 0.;
    tm[1][2] = 0.;
    tm[2][0] = 0.;
    tm[2][1] = 1.;
    tm[2][2] = 0.;
    vis_CoordSysSetOriginTriad(coordsys, x, tm);

    /* compute local direction cosines at point 20.,20.,10. */
    xp[0] = 20.;
    xp[1] = 20.;
    xp[2] = 10.;
    vis_CoordSysDirCos(coordsys, xp, tmp);
    printf("x''= %f %f %f\n", tmp[0][0], tmp[0][1], tmp[0][2]);
    printf("y''= %f %f %f\n", tmp[1][0], tmp[1][1], tmp[1][2]);
    printf("z''= %f %f %f\n", tmp[2][0], tmp[2][1], tmp[2][2]);

    /* compute equivalent rotation angles of same system */
    vis_CoordSysRotAng(coordsys, xp, rap);
    printf("\n");
    printf("rx''= %f\n", rap[0]);
    printf("ry''= %f\n", rap[1]);
    printf("rz''= %f\n", rap[2]);

    /* define a new system using the computed rotation angles */
    coordsysang = vis_CoordSysBegin();
    vis_CoordSysDef(coordsysang, SYS_CARTESIAN);
    vis_CoordSysSetOriginRotAng(coordsysang, x, rap);

    /* query should match direction cosines */
    vis_CoordSysOriginTriad(coordsysang, xa, tma);
    printf("\n");
    printf("x''= %f %f %f\n", tma[0][0], tma[0][1], tma[0][2]);
    printf("y''= %f %f %f\n", tma[1][0], tma[1][1], tma[1][2]);
    printf("z''= %f %f %f\n", tma[2][0], tma[2][1], tma[2][2]);
    vis_CoordSysEnd(coordsysang);

    /* convert global coordinate to cylindrical coordinates */
    vis_CoordSysConvertCoord(coordsys, xp, xpl);
    printf("\n");
    printf("r    = %f\n", xpl[0]);
    printf("theta= %f\n", xpl[1]);
    printf("z'   = %f\n", xpl[2]);

    /* convert vector vp at xp to local Cartesian system */
    vp[0] = 2.;
    vp[1] = 0.;
    vp[2] = 0.;
    vis_CoordSysConvertVector(coordsys, xp, vp, vlc);
    printf("\n");
    printf("vlc= %f %f %f\n", vlc[0], vlc[1], vlc[2]);

    /* perform inverse. vpc should be same as original vp */
    vis_CoordSysComputeVector(coordsys, xp, vlc, vpc);
    printf("\n");
    printf("vpc= %f %f %f\n", vpc[0], vpc[1], vpc[2]);

    /* free object */
    vis_CoordSysEnd(coordsys);
    return 0;
}
