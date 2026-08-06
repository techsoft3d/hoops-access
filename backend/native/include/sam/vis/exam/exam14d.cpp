#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "legacy/vis/vislegacy.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/* shell node coordinates */
static Vfloat xs[4][3] = {{1., 0., 0.}, {1., 1., 0.}, {0., 1., 0.}, {0., 0., 0.}};

/* local shell node stresses */
static Vfloat sl[4][6] = {{1., 2., 3., 4., 5., 6.}, {1., 2., 3., 4., 5., 6.}, {1., 2., 3., 4., 5., 6.}, {1., 2., 3., 4., 5., 6.}};

/*----------------------------------------------------------------------
                      Transform Shell Stress to Global System
----------------------------------------------------------------------*/
int
main()
{
    Vint i;
    vis_CoordSys* coordsys;
    vis_ShellElem* shellelem;
    Vfloat tm[4][3][3];
    Vfloat sg[4][6];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create coordsys object */
    coordsys = vis_CoordSysBegin();
    vis_CoordSysDef(coordsys, SYS_CARTESIAN);

    /* create shell object, set topology to linear quad */
    shellelem = vis_ShellElemBegin();
    vis_ShellElemSetTopology(shellelem, VIS_SHAPEQUAD, 2, 0);

    /* set local system to NASTRAN convention */
    vis_ShellElemSetLocalSystem(shellelem, SYS_ELEMSYS_BISECTOR, NULL, 0.);

    /* get stress directions at shell element nodes */
    vis_ShellElemDirCos(shellelem, 0, xs, tm);

    /* transform stress from shell local to global */
    for (i = 0; i < 4; i++) {
        vis_CoordSysSetOriginTriad(coordsys, xs[i], tm[i]);

        printf("sl= %8.4e %8.4e %8.4e %8.4e %8.4e %8.4e\n", sl[i][0], sl[i][1], sl[i][2], sl[i][3], sl[i][4], sl[i][5]);

        vis_CoordSysComputeTensor(coordsys, xs[i], sl[i], sg[i]);

        printf("sg= %8.4e %8.4e %8.4e %8.4e %8.4e %8.4e\n", sg[i][0], sg[i][1], sg[i][2], sg[i][3], sg[i][4], sg[i][5]);
    }

    /* delete objects */
    vis_ShellElemEnd(shellelem);
    vis_CoordSysEnd(coordsys);
    return 0;
}
