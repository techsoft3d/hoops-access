#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "sam/base/base.h"
#include "sam/vis/visdata.h"
#include "sam/vdm/vdm.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/*-------------------------------------------------------------------------------------
            Read Universal Result file and Write Nastran bdf input deck
---------------------------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    Vchar inputFile[256];
    Vchar outputFile[256];

    /* check input arguments */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s inputFile outputFile\n", argv[0]);
        fprintf(stderr, " inputFile  is blank, 'cantilever.unv' is assumed\n");
        fprintf(stderr, " outputFile is blank, 'exam7.bdf' is assumed\n");
        strcpy(inputFile, "cantilever.unv");
        strcpy(outputFile, "exam7.bdf");
    }
    else if (argc < 3) {
        fprintf(stderr, "Usage: %s inputFile outputFile\n", argv[0]);
        fprintf(stderr, " outputFile is blank, 'exam7.bdf' is assumed\n");
        strcpy(inputFile, argv[1]);
        strcpy(outputFile, "exam7.bdf");
    }
    else {
        strcpy(inputFile, argv[1]);
        strcpy(outputFile, argv[2]);
    }

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* Open file */
    vdm_Options* options = vdm_OptionsBegin();
    vdm_OptionsAddConvention(options, VDM_CONVENTION_DOUBLE);

    vdm_LMan* libraryManager = vdm_LManBegin();
    vdm_LManOpenFile(libraryManager, inputFile, options);

    /* check for error */
    Vint ierr = vdm_LManError(libraryManager);
    if (ierr) {
        fprintf(stderr, "Error: opening Import file %s\n", inputFile);
        vdm_OptionsEnd(options);
        vdm_LManCloseFile(libraryManager);
        vdm_LManEnd(libraryManager);
        exit(1);
    }

    /* exporting the input file data into another file */
    vdm_LManSaveFile(libraryManager, outputFile, nullptr);

    ierr = vdm_LManError(libraryManager);
    if (ierr) {
        fprintf(stderr, "Error: Creating export file %s\n", outputFile);
        vdm_OptionsEnd(options);
        vdm_LManCloseFile(libraryManager);
        vdm_LManEnd(libraryManager);
        exit(1);
    }
    else {
        printf("Exported %s successfully.\n", outputFile);
    }

    vdm_OptionsEnd(options);
    vdm_LManCloseFile(libraryManager);
    vdm_LManEnd(libraryManager);

    return 0;
}
