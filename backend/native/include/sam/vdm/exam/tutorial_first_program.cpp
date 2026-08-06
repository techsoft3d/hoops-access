#include "samcpp/core/core.h"
#include "samcpp/access/access.h"
#include "sam/hoops_license.h"

#include <iostream>
#include <iomanip>

/*----------------------------------------------------------------------
            Read and Print Finite Element Node Coordinates
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    char inputFile[cae::core::MAX_NAME_LENGTH] = {};
    // Check input arguments
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " inputfile\n";
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

    // Load Model object with finite element model
    cae::core::Model model;
    dataSource.loadModel(&model);

    // Get Mesh object created in Model
    cae::core::MeshPtr mesh;
    status = model.getMesh(mesh);

    // Check for errors
    if (!status) {
        std::cerr << "Error: Unable to get connect object from model\n";
        exit(1);
    }

    // Get number of nodes
    int nodeCount = 0;
    mesh->getEntityCount(cae::core::EntityType::NODE, &nodeCount);

    // Print first and last node coordinates
    std::cout << "Node Coordinates\n";

    double coordinates[1][3] = {{0.0, 0.0, 0.0}};
    std::cout << std::fixed << std::setprecision(6);

    // Print first node
    int nodeId = 1;
    mesh->getCoordinates(1, &nodeId, coordinates);
    std::cout << std::setw(10) << 1 << ' ' << std::setw(12) << coordinates[0][0] << ' ' << std::setw(12) << coordinates[0][1]
              << ' ' << std::setw(12) << coordinates[0][2] << '\n';

    // Print last node
    mesh->getCoordinates(1, &nodeCount, coordinates);
    std::cout << std::setw(10) << nodeCount << ' ' << std::setw(12) << coordinates[0][0] << ' ' << std::setw(12)
              << coordinates[0][1] << ' ' << std::setw(12) << coordinates[0][2] << '\n';

    return 0;
}
