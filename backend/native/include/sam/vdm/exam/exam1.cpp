#include "sam/base/base.h"
#include "sam/vdm/vdm.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*----------------------------------------------------------------------
                      Print Table of Contents
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    char inputFile[256];
    /* check input arguments */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s inputfile [appendfile]\n", argv[0]);
        fprintf(stderr, " inputfile is blank, 'bumper.unv' is assumed\n");
        strcpy(inputFile, "bumper.unv");
    }
    else {
        strcpy(inputFile, argv[1]);
    }

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* Open file */
    vdm_LMan* libraryManager = vdm_LManBegin();
    vdm_LManOpenFile(libraryManager, inputFile, nullptr);

    /* check for error */
    Vint ierr = vdm_LManError(libraryManager);
    if (ierr) {
        fprintf(stderr, "Error: opening file %s\n", inputFile);
        vdm_LManCloseFile(libraryManager);
        vdm_LManEnd(libraryManager);
        exit(1);
    }
    /* Set verbose mode */
    vdm_LManSetParami(libraryManager, LMAN_VERBOSE, SYS_ON);
    vdm_LManTOC(libraryManager, "*");

    vdm_LManCloseFile(libraryManager);
    vdm_LManEnd(libraryManager);
    return 0;
}
