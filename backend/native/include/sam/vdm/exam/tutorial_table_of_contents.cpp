#include "samcpp/core/core.h"
#include "samcpp/access/access.h"
#include "sam/hoops_license.h"
#include <iostream>

/*----------------------------------------------------------------------
                      Print Table of Contents
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    char inputFile[cae::core::MAX_NAME_LENGTH] = {};
    // Check input arguments
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " inputfile [appendfile]\n";
        std::cerr << " inputfile is blank, 'bumper.unv' is assumed\n";
        strcpy(inputFile, "bumper.unv");
    }
    else {
        strcpy(inputFile, argv[1]);
    }

    cae::core::license::validate(HOOPS_LICENSE);

    // Open file
    cae::access::DataSource dataSource;
    cae::core::Status status = dataSource.openFile(inputFile, nullptr);

    // Check for error
    if (!status) {
        std::cerr << "Error: opening file " << inputFile << '\n';
        exit(1);
    }

    // Set verbose mode and print table of contents
    dataSource.setIntegerParameter(cae::access::DataSource::IntegerParameter::VERBOSE, 1);
    dataSource.printTableOfContents("*");

    return 0;
}
