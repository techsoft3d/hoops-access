#include "samcpp/core/core.h"
#include "samcpp/access/access.h"
#include "sam/hoops_license.h"
#include <iostream>

/*-------------------------------------------------------------------------------------
            Translate one file format to another file format
---------------------------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    char inputFile[cae::core::MAX_NAME_LENGTH] = {};
    char outputFile[cae::core::MAX_NAME_LENGTH] = {};

    /* check input arguments */
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " inputFile outputFile\n";
        std::cerr << " inputFile  is blank, 'cantilever.unv' is assumed\n";
        std::cerr << " outputFile is blank, 'tutorial_file_translation.bdf' is assumed\n";
        strcpy(inputFile, "cantilever.unv");
        strcpy(outputFile, "tutorial_file_translation.bdf");
    }
    else if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " inputFile outputFile\n";
        std::cerr << " outputFile is blank, 'tutorial_file_translation.bdf' is assumed\n";
        strcpy(inputFile, argv[1]);
        strcpy(outputFile, "tutorial_file_translation.bdf");
    }
    else {
        strcpy(inputFile, argv[1]);
        strcpy(outputFile, argv[2]);
    }

    cae::core::license::validate(HOOPS_LICENSE);

    // Open input file and enable double precision convention
    cae::access::Options options;
    options.enableConvention(cae::access::Options::Convention::DOUBLE);

    cae::access::DataSource dataSource;
    cae::core::Status status = dataSource.openFile(inputFile, &options);
    /* check for error */
    if (!status) {
        std::cerr << "Error: opening Import file " << inputFile << '\n';
        exit(1);
    }

    // Export to output file
    status = dataSource.saveFile(outputFile, nullptr);
    if (!status) {
        std::cerr << "Error: Creating export file " << outputFile << '\n';
        exit(1);
    }

    std::cout << "Exported " << outputFile << " successfully.\n";

    return 0;
}
