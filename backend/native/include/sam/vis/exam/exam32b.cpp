#include <stdio.h>
#include "sam/base/base.h"
#include "sam/vis/vis.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Manage Analytic Surfaces using ASurf
----------------------------------------------------------------------*/
int
main()
{
    Vint i;
    vsy_HashTable* ht;
    vis_ASurf* asurf;
    Vfloat x[3], r;
    Vfloat a[3], b[3], c[3], length, width;
    Vint type, id, segtype;
    Vint ix[3], numpnt, numseg;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* create HashTable to hold ASurf objects */
    ht = vsy_HashTableBegin();
    /* create ASurf object for a sphere */
    asurf = vis_ASurfBegin();
    vis_ASurfDef(asurf, ASURF_SPHERE);
    x[0] = 0.;
    x[1] = 1.;
    x[2] = 1.;
    r = 2.;
    vis_ASurfSetSphere(asurf, x, r);
    vsy_HashTableInsert(ht, 10, asurf);
    /* create ASurf object for a plane */
    asurf = vis_ASurfBegin();
    vis_ASurfDef(asurf, ASURF_PLANE);
    a[0] = 0.;
    a[1] = 0.;
    a[2] = 0.;
    b[0] = 1.;
    b[1] = 0.;
    b[2] = 0.;
    c[0] = 0.;
    c[1] = 1.;
    c[2] = 0.;
    length = 3.;
    width = 4.;
    vis_ASurfSetPlane(asurf, a, b, c, length, width);
    vsy_HashTableInsert(ht, 20, asurf);
    /* create ASurf object for a surface of revolution */
    asurf = vis_ASurfBegin();
    vis_ASurfDef(asurf, ASURF_SEGMENT_REV);
    /* set local coordinate system */
    a[0] = 0.;
    a[1] = 0.;
    a[2] = 0.;
    b[0] = 1.;
    b[1] = 0.;
    b[2] = 0.;
    c[0] = 0.;
    c[1] = 1.;
    c[2] = 0.;
    vis_ASurfSetSegmentRev(asurf, a, b, c);
    /* points in local x-z plane, revolve about local z axis */
    /* set points */
    x[0] = 2.;
    x[1] = 0.;
    x[2] = 0.;
    vis_ASurfSetPoint(asurf, 1, x);
    x[0] = 2.;
    x[1] = 2.;
    x[2] = 0.;
    vis_ASurfSetPoint(asurf, 2, x);
    x[0] = 1.;
    x[1] = 3.;
    x[2] = 0.;
    vis_ASurfSetPoint(asurf, 3, x);
    /* circle center */
    x[0] = 1.;
    x[1] = 2.;
    x[2] = 0.;
    vis_ASurfSetPoint(asurf, 4, x);
    /* set segments */
    ix[0] = 1;
    ix[1] = 2;
    vis_ASurfSetSegment(asurf, 1, ASURF_SEG_LINE, ix);
    ix[0] = 2;
    ix[1] = 4;
    ix[2] = 3;
    vis_ASurfSetSegment(asurf, 2, ASURF_SEG_ARC, ix);
    vsy_HashTableInsert(ht, 30, asurf);

    /* loop through HashTable */
    vsy_HashTableInitIter(ht);
    while (vsy_HashTableNextIter(ht, &id, (Vobject**)&asurf), asurf) {
        vis_ASurfInq(asurf, &type);
        if (type == ASURF_SPHERE) {
            vis_ASurfGetSphere(asurf, x, &r);
            printf("Sphere, id= %d, x= %f %f %f, r= %f\n", id, x[0], x[1], x[2], r);
        }
        else if (type == ASURF_PLANE) {
            vis_ASurfGetPlane(asurf, a, b, c, &length, &width);
            printf("Plane, id= %d, a= %f %f %f\n", id, a[0], a[1], a[2]);
            printf("               b= %f %f %f\n", b[0], b[1], b[2]);
            printf("               c= %f %f %f\n", c[0], c[1], c[2]);
            printf("               length= %f, width= %f\n", length, width);
        }
        else if (type == ASURF_SEGMENT_REV) {
            vis_ASurfNumPoints(asurf, &numpnt);
            vis_ASurfNumSegments(asurf, &numseg);
            printf("Segment Rev, id= %d, numpnts= %d, numseg= %d\n", id, numpnt, numseg);
            vis_ASurfGetSegmentRev(asurf, a, b, c);
            printf("             a= %f %f %f\n", a[0], a[1], a[2]);
            printf("             b= %f %f %f\n", b[0], b[1], b[2]);
            printf("             c= %f %f %f\n", c[0], c[1], c[2]);
            for (i = 1; i <= numpnt; i++) {
                vis_ASurfGetPoint(asurf, i, x);
                printf(" point, id= %d, x= %f %f %f\n", i, x[0], x[1], x[2]);
            }
            for (i = 1; i <= numseg; i++) {
                vis_ASurfGetSegment(asurf, i, &segtype, ix);
                if (segtype == ASURF_SEG_LINE) {
                    printf(" seg line, id= %d, ix= %d %d\n", i, ix[0], ix[1]);
                }
                else if (segtype == ASURF_SEG_ARC) {
                    printf(" seg arc,  id= %d, ix= %d %d %d\n", i, ix[0], ix[1], ix[2]);
                }
            }
        }
    }
    /* end objects */
    vsy_HashTableForEach(ht, (void (*)(void*))vis_ASurfEnd);
    vsy_HashTableEnd(ht);
    return 0;
}
