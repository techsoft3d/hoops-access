#include "samcpp/core/core.h"
#include "samcpp/access/access.h"
#include "sam/hoops_license.h"
#include <vector>
#include <iostream>
#include <iomanip>

static void
print_nodes(cae::core::MeshPtr& mesh);
static void
print_elements(cae::core::MeshPtr& mesh);

/*----------------------------------------------------------------------
                      Read and Print Model Data
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    char inputfile[cae::core::MAX_NAME_LENGTH] = {};

    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " inputfile\n";
        std::cerr << " inputfile is blank, 'bumper.unv' is assumed\n";
        strcpy(inputfile, "bumper.unv");
    }
    else {
        strcpy(inputfile, argv[1]);
    }

    cae::core::license::validate(HOOPS_LICENSE);

    // Open file
    cae::access::DataSource dataSource;
    cae::core::Status status = dataSource.openFile(inputfile, NULL);

    // Check for error
    if (!status) {
        std::cerr << "Error: opening file " << inputfile << '\n';
        exit(1);
    }

    // Load the model from the file
    cae::core::Model model;
    status = dataSource.loadModel(&model);
    if (!status) {
        std::cerr << "Error: Unable to load model information\n";
        exit(1);
    }

    // Get the mesh and print nodes and elements
    cae::core::MeshPtr mesh;
    model.getMesh(mesh);
    if (mesh != NULL) {
        print_nodes(mesh);
        print_elements(mesh);
    }

    return 0;
}

static void
print_nodes(cae::core::MeshPtr& mesh)
{
    int nodeCount = 0;
    mesh->getEntityCount(cae::core::EntityType::NODE, &nodeCount);
    std::cout << "Number of nodes=    " << nodeCount << '\n';
    std::cout << "\nNodes\n";
    double coordinates[3]{0.0, 0.0, 0.0};
    auto previousFlags = std::cout.flags();
    std::cout << std::scientific;
    for (int i = 1; i <= nodeCount; i++) {
        mesh->getCoordinates(1, &i, (double (*)[3])coordinates);
        int nodeId = 0;
        mesh->getNodeAssociation<cae::core::NodeAssociationType::USER_ID>(1, &i, &nodeId);
        int coordinateSystemId = 0;
        mesh->getNodeAssociation<cae::core::NodeAssociationType::COORDINATE_SYSTEM_ID>(1, &i, &coordinateSystemId);
        std::cout << "id= " << nodeId << ", cid= " << coordinateSystemId << ", x= " << coordinates[0] << ' ' << coordinates[1]
                  << ' ' << coordinates[2] << '\n';
    }
    std::cout.flags(previousFlags);
}

static void
print_elements(cae::core::MeshPtr& mesh)
{
    int elementCount = 0;
    mesh->getEntityCount(cae::core::EntityType::ELEMENT, &elementCount);
    std::cout << "Number of elements= " << elementCount << '\n';
    std::cout << "\nElements\n";
    int maxNodesInElement = 0;
    mesh->getMaxElementNodes(&maxNodesInElement);
    /* allocate vectors for internal node ids and user ids */
    std::vector<int> nodeIndexes(maxNodesInElement, 0);
    std::vector<int> nodeIds(maxNodesInElement, 0);
    for (int i = 1; i <= elementCount; i++) {
        cae::core::ElementShape shape;
        int maxi = 0, maxj = 0, maxk = 0;
        mesh->getTopology(i, &shape, &maxi, &maxj, &maxk);
        int nodesInElement = 0;
        mesh->getElementNodes(i, &nodesInElement, nodeIndexes.data());
        int elementId = 0;
        int partId = 0;
        int propertyId = 0;
        int materialId = 0;
        int coordinateSystemId = 0;
        cae::core::ElementType elementType;
        mesh->getElementAssociation<cae::core::ElementAssociationType::USER_ID>(1, &i, &elementId);
        mesh->getElementAssociation<cae::core::ElementAssociationType::PART_ID>(1, &i, &partId);
        mesh->getElementAssociation<cae::core::ElementAssociationType::PROPERTY_ID>(1, &i, &propertyId);
        mesh->getElementAssociation<cae::core::ElementAssociationType::MATERIAL_ID>(1, &i, &materialId);
        mesh->getElementAssociation<cae::core::ElementAssociationType::COORDINATE_SYSTEM_ID>(1, &i, &coordinateSystemId);
        mesh->getElementAssociation<cae::core::ElementAssociationType::ELEMENT_TYPE>(1, &i, &elementType);
        std::cout << "id= " << elementId << ", partid= " << partId << ", pid= " << propertyId << ", mid= " << materialId
                  << ", cid= " << coordinateSystemId << ", nodes= " << nodesInElement << '\n';
        /* interpret shape */
        if (shape == cae::core::ElementShape::POINT) {
            std::cout << " shape= Point(s):";
        }
        else if (shape == cae::core::ElementShape::LINE) {
            std::cout << " shape= Line:";
        }
        else if (shape == cae::core::ElementShape::TRIANGLE) {
            std::cout << " shape= Triangle:";
        }
        else if (shape == cae::core::ElementShape::QUADRILATERAL) {
            std::cout << " shape= Quadrilateral:";
        }
        else if (shape == cae::core::ElementShape::TETRAHEDRON) {
            std::cout << " shape= Tetrahedron:";
        }
        else if (shape == cae::core::ElementShape::PYRAMID) {
            std::cout << " shape= Pyramid:";
        }
        else if (shape == cae::core::ElementShape::WEDGE) {
            std::cout << " shape= Pentahedron:";
        }
        else if (shape == cae::core::ElementShape::HEXAHEDRON) {
            std::cout << " shape= Hexahedron:";
        }
        else if (shape == cae::core::ElementShape::POLYGON) {
            std::cout << " shape= Polygon:";
        }
        else if (shape == cae::core::ElementShape::POLYHEDRON) {
            std::cout << " shape= Polyhedron:";
        }
        std::cout << "  maxi= " << maxi << ", maxj= " << maxj << ", maxk= " << maxk << '\n';
        // Convert internal index to user id
        mesh->getNodeAssociation<cae::core::NodeAssociationType::USER_ID>(nodesInElement, nodeIndexes.data(), nodeIds.data());
        // Print element connectivity
        std::cout << " connectivity=";
        for (int j = 0; j < nodesInElement; j++) {
            std::cout << ' ' << nodeIds[j];
        }
        std::cout << '\n';
    }
}
