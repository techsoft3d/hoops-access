#include <stdio.h>
#include "sam/base/base.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Test and demonstrate MachInfo
----------------------------------------------------------------------*/
int
main()
{
    Vint flag;
    Vint numproc;
    Vint totalmem;
    Vint usedmem;
    Vint objectsize;
    Vint filepossize;
    Vint endian;
    Vdouble machprec;
    Vchar sysname[256];
    Vchar hostname[256];
    Vchar username[256];
    Vchar datestg[SYS_MAXDATENAME] = {0};
    Vchar timestg[SYS_MAXTIMENAME] = {0};
    Vchar vlongstg[33];
    Vint day, mon, year;
    Vint sec, min, hour;
    Vlong vli;
    Vfloat cpuusr, cpusys;

    vsy_LicenseValidate(HOOPS_LICENSE);

    printf("\nMachInfo test\n");

    /* query for system name */
    vut_MachInfoSystemName(&flag, sysname);
    if (flag) {
        printf("System name = %s\n", sysname);
    }
    else {
        printf("System name query unsupported\n");
    }
    /* query for host name */
    vut_MachInfoHostName(&flag, hostname);
    if (flag) {
        printf("Host name = %s\n", hostname);
    }
    else {
        printf("Host name query unsupported\n");
    }
    /* query for user name */
    vut_MachInfoUserName(&flag, username);
    if (flag) {
        printf("User name = %s\n", username);
    }
    else {
        printf("User name query unsupported\n");
    }

    /* query for number of processors */
    vut_MachInfoNumProc(&flag, &numproc);
    if (flag) {
        printf("Number of processors = %d\n", numproc);
    }
    else {
        printf("Number of processors query unsupported\n");
    }

    /* query for machine precision */
    vut_MachInfoPrec(&flag, &machprec);
    if (flag) {
        printf("Machine precision = %e\n", machprec);
    }
    else {
        printf("Machine precision query unsupported\n");
    }

    /* query for total physical memory */
    vut_MachInfoTotalMem(&flag, &totalmem);
    if (flag) {
        printf("Total memory (MBytes)= %d\n", totalmem);
    }
    else {
        printf("Total memory (MBytes) query unsupported\n");
    }

    /* query for used physical memory */
    vut_MachInfoUsedMem(&flag, &usedmem);
    if (flag) {
        printf("Used memory (MBytes)= %d\n", usedmem);
    }
    else {
        printf("Used memory (MBytes) query unsupported\n");
    }

    /* query for object size */
    vut_MachInfoObjectSize(&flag, &objectsize);
    if (flag) {
        printf("Object size sizeof(size_t)= %d\n", objectsize);
    }
    else {
        printf("Object size query unsupported\n");
    }

    /* query for file position size */
    vut_MachInfoFilePosSize(&flag, &filepossize);
    if (flag) {
        printf("File position size sizeof(long)= %d\n", filepossize);
    }
    else {
        printf("File position size query unsupported\n");
    }

    /* query for endian */
    /* the flag is always 1 */
    vut_MachInfoEndian(&flag, &endian);
    if (endian == 0) {
        printf("Endian= big\n");
    }
    else {
        printf("Endian= little\n");
    }
    /* date and time strings */
    /* the flag is always 1 */
    vut_MachInfoDateString(&flag, datestg);
    printf("Date: %s\n", datestg);
    vut_MachInfoTimeString(&flag, timestg);
    printf("Time: %s\n", timestg);

    /* date and time integers */
    vut_MachInfoDateInteger(&flag, &day, &mon, &year);
    printf("Date: day= %d, mon= %d, year= %d\n", day, mon, year);
    vut_MachInfoTimeInteger(&flag, &sec, &min, &hour);
    printf("Time: sec= %d, min= %d, hour= %d\n", sec, min, hour);

    /* cpu times, user and system */
    vut_MachInfoCpuTimes(&flag, &cpuusr, &cpusys);
    printf("CpuTimes: usr= %e, sys= %e\n", cpuusr, cpusys);

    /* Vlong string */
    vli = 1234567;
    vut_MachInfoVlongString(vli, vlongstg);
    printf("long int(Vlong)= %s\n", vlongstg);

    /* query for compiled options */
    vut_MachInfoLIBAPI_SOCKETS(&flag);
    if (flag) {
        printf("VKI_LIBAPI_SOCKETS compiled\n");
    }
    else {
        printf("VKI_LIBAPI_SOCKETS not compiled\n");
    }
    return 0;
}
