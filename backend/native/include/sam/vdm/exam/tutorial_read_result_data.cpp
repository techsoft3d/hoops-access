#include "samcpp/core/core.h"
#include "samcpp/access/access.h"
#include "sam/hoops_license.h"
#include <vector>
#include <array>
#include <stdexcept>
#include <iostream>
#include <iomanip>

static void
print_displacement(cae::access::DataSource& dataSource, cae::core::MeshPtr& mesh);
static void
print_temperature_gradient(cae::access::DataSource& dataSource, cae::core::MeshPtr& mesh);
static void
print_stress(cae::access::DataSource& dataSource, cae::core::MeshPtr& mesh);
static void
print_result(cae::access::DataSource& dataSource, cae::core::MeshPtr& mesh);
static void
print_section(cae::core::LayerPosition position, int section);

/*----------------------------------------------------------------------
                     Read and Print Results State Data
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    char inputFile[cae::core::MAX_NAME_LENGTH] = {};
    // Check input arguments
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " inputfile [appendfile]\n";
        std::cerr << " inputfile is blank, 'cantilever.unv' is assumed\n";
        strcpy(inputFile, "cantilever.unv");
    }
    else {
        strcpy(inputFile, argv[1]);
    }

    cae::core::license::validate(HOOPS_LICENSE);

    // Open file
    cae::access::Options options;
    options.enableConvention(cae::access::Options::Convention::SPARSE);
    cae::access::DataSource dataSource;
    cae::core::Status status = dataSource.openFile(inputFile, &options);

    // Check for error
    if (!status) {
        std::cerr << "Error: opening file " << inputFile << '\n';
        exit(1);
    }
    // Look for appended file
    for (int i = 2; i < argc; i++) {
        status = dataSource.appendFile(argv[i]);
        // Check for error
        if (!status) {
            std::cerr << "Error: appending file " << argv[i] << " to file " << argv[1] << '\n';
            exit(1);
        }
    }

    // Instance Model object for finite element model
    cae::core::Model model;
    dataSource.loadModel(&model);

    // Get Mesh object created in Model
    cae::core::MeshPtr mesh;
    model.getMesh(mesh);

    int nodesCount = 0;
    int elementsCount = 0;
    mesh->inquire(&nodesCount, &elementsCount);
    std::cout << "number of nodes= " << nodesCount << '\n';
    std::cout << "number of elems= " << elementsCount << '\n';

    // Access and print displacements
    print_displacement(dataSource, mesh);
    // Access and print temperature gradients
    print_temperature_gradient(dataSource, mesh);

    // Access and print stresses
    print_stress(dataSource, mesh);
    // Access and print all results
    print_result(dataSource, mesh);

    return 0;
}

cae::core::State::DerivedType
derivedTypeFromDataLayout(cae::core::DataLayout dataLayout)
{
    switch (dataLayout) {
        case cae::core::DataLayout::SCALAR:
            return cae::core::State::DerivedType::SCALAR;
        case cae::core::DataLayout::VECTOR:
            return cae::core::State::DerivedType::VECTOR;
        case cae::core::DataLayout::TENSOR_SYMMETRIC:
            return cae::core::State::DerivedType::TENSOR;
        case cae::core::DataLayout::TENSOR_GENERAL:
            return cae::core::State::DerivedType::GENERALTENSOR;
        case cae::core::DataLayout::SIX_DOF:
            return cae::core::State::DerivedType::SIX_DOF;
        default:
            throw std::invalid_argument("Unexpected data layout");
    }
}

static void
print_displacement(cae::access::DataSource& dataSource, cae::core::MeshPtr& mesh)
{
    // Allocate array for state indices
    int statesCount = 0;
    dataSource.getStateCount(&statesCount);
    std::vector<int> stateIds(statesCount);

    // Search for displacement results
    int foundStates = 0;
    dataSource.searchState("D.*N:*", statesCount, stateIds.data(), &foundStates);
    // If no displacement, search for temperature
    int thermalflag = 0;
    if (foundStates == 0) {
        thermalflag = 1;
        dataSource.searchState("TEMP.*N:*", statesCount, stateIds.data(), &foundStates);
    }

    if (foundStates == 0) {
        return;
    }

    int nodesCount = 0;
    mesh->getEntityCount(cae::core::EntityType::NODE, &nodesCount);

    // Print first, middle and last node
    int requestedNodesCount = 3;
    int requestedNodeIds[3] = {1, nodesCount / 2, nodesCount};

    cae::core::State state;
    char stateName[cae::core::MAX_NAME_LENGTH] = {};
    auto previousFlags = std::cout.flags();
    std::cout << std::scientific;
    // Loop over displacement states
    for (int i = 0; i < foundStates; i++) {
        cae::core::ResultMetadata resultMetadata;
        dataSource.getMetadata(stateIds[i], &resultMetadata);
        long long length = 0;
        int rowsCount = 0, columnsCount = 0;
        cae::core::DataLayout type;
        resultMetadata.inquire(stateName, &length, &rowsCount, &columnsCount, &type);

        // Print header
        std::cout << "\n\nState: " << stateName << '\n';
        if (thermalflag == 0) {
            std::cout << "\nDisplacements\n";
        }
        else {
            std::cout << "\nTemperatures\n";
        }

        // Load state
        dataSource.loadState(stateName, &state);
        int entityCount = 0;
        cae::core::EntityType enttype, subtype;
        cae::core::DataLayout dataLayout;
        state.inquire(&entityCount, &enttype, &subtype, &dataLayout);

        // Loop over requested nodes
        float values[6] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
        for (int n = 0; n < requestedNodesCount; n++) {
            if (requestedNodeIds[n] == 0) {
                continue;
            }
            int nodeNumber = 0;
            mesh->getNodeAssociation<cae::core::NodeAssociationType::USER_ID>(1, &requestedNodeIds[n], &nodeNumber);
            std::cout << std::setw(8) << nodeNumber;

            float magnitude = 0.0f;
            if (dataLayout == cae::core::DataLayout::SCALAR) {
                state.getData(1, &requestedNodeIds[n], values);
                std::cout << std::setw(14) << values[0] << '\n';
            }
            else if (dataLayout == cae::core::DataLayout::VECTOR) {
                // Print components
                state.getData(1, &requestedNodeIds[n], values);
                std::cout << std::setw(14) << values[0] << ' ' << std::setw(14) << values[1] << ' ' << std::setw(14) << values[2];
                // Print magnitude
                state.setDerivedQuantity(cae::core::State::DerivedType::VECTOR_MAGNITUDE);
                state.getData(1, &requestedNodeIds[n], &magnitude);
                std::cout << "  magnitude= " << std::setw(14) << magnitude << '\n';
            }
            else if (dataLayout == cae::core::DataLayout::SIX_DOF) {
                // Print components
                state.getData(1, &requestedNodeIds[n], values);
                std::cout << std::setw(14) << values[0] << ' ' << std::setw(14) << values[1] << ' ' << std::setw(14) << values[2]
                          << "  " << std::setw(14) << values[3] << ' ' << std::setw(14) << values[4] << ' ' << std::setw(14)
                          << values[5];
                // Print magnitudes
                state.setDerivedQuantity(cae::core::State::DerivedType::SIX_DOF_TRANSLATIONAL_MAGNITUDE);
                state.getData(1, &requestedNodeIds[n], &magnitude);
                float rotationMagnitude;
                state.setDerivedQuantity(cae::core::State::DerivedType::SIX_DOF_ROTATIONAL_MAGNITUDE);
                state.getData(1, &requestedNodeIds[n], &rotationMagnitude);
                std::cout << "  magnitudes= " << std::setw(14) << magnitude << ' ' << std::setw(14) << rotationMagnitude << '\n';
            }
        }
        std::cout << '\n';

        // Print global components if originally local components
        cae::core::State::System systemType;
        state.getCoordinateSystem(&systemType);
        if (systemType == cae::core::State::System::LOCAL_UNDEFORMED) {
            state.transformToCoordinateSystem(cae::core::State::System::GLOBAL, NULL);
            // Loop over requested nodes
            cae::core::State::DerivedType derivedType = derivedTypeFromDataLayout(dataLayout);
            state.setDerivedQuantity(derivedType);
            std::cout << "global system\n";
            for (int n = 0; n < requestedNodesCount; n++) {
                if (requestedNodeIds[n] == 0) {
                    continue;
                }
                int nodeNumber = 0;
                mesh->getNodeAssociation<cae::core::NodeAssociationType::USER_ID>(1, &requestedNodeIds[n], &nodeNumber);
                std::cout << std::setw(8) << nodeNumber;
                if (dataLayout == cae::core::DataLayout::VECTOR) {
                    state.getData(1, &requestedNodeIds[n], values);
                    std::cout << std::setw(14) << values[0] << ' ' << std::setw(14) << values[1] << ' ' << std::setw(14)
                              << values[2] << '\n';
                }
                else if (dataLayout == cae::core::DataLayout::SIX_DOF) {
                    state.getData(1, &requestedNodeIds[n], values);
                    std::cout << std::setw(14) << values[0] << ' ' << std::setw(14) << values[1] << ' ' << std::setw(14)
                              << values[2] << "  " << std::setw(14) << values[3] << ' ' << std::setw(14) << values[4] << ' '
                              << std::setw(14) << values[5] << '\n';
                }
            }
            std::cout << '\n';
        }
        /* print attributes */
        resultMetadata.printAttributes();
    }
    std::cout.flags(previousFlags);
}

static void
print_temperature_gradient(cae::access::DataSource& dataSource, cae::core::MeshPtr& mesh)
{
    int statesCount = 0;
    dataSource.getStateCount(&statesCount); /* Maximum number of states */
    int foundStatesCount = 0;
    std::vector<int> stateIds(statesCount);
    /* search for temperature gradient results states */
    dataSource.searchState("TEMP_GRAD.*E:*", statesCount, stateIds.data(), &foundStatesCount);

    if (foundStatesCount == 0) {
        return;
    }

    int elementsCount = 0;
    int nodesCount = 0;
    mesh->inquire(&nodesCount, &elementsCount);

    // Print first, middle and last element
    int requestedElementsCount = 3;
    int ids[3] = {1, elementsCount / 2, elementsCount};

    // Loop over states
    cae::core::State state;
    auto previousFlags = std::cout.flags();
    std::cout << std::scientific;
    for (int i = 0; i < foundStatesCount; i++) {
        cae::core::ResultMetadata resultMetadata;
        dataSource.getMetadata(stateIds[i], &resultMetadata);
        char stateName[cae::core::MAX_NAME_LENGTH];
        long long length = 0;
        int rowsCount = 0, columnsCount = 0;
        cae::core::DataLayout dataLayout;
        resultMetadata.inquire(stateName, &length, &rowsCount, &columnsCount, &dataLayout);

        // Print header
        std::cout << "\n\nState: " << stateName << '\n';
        std::cout << "\nTemperature Gradients\n";

        dataSource.loadState(stateName, &state);

        // Loop over requested elements
        float values[3] = {0.0f, 0.0f, 0.0f};
        for (int n = 0; n < requestedElementsCount; n++) {
            if (ids[n] == 0) {
                continue;
            }
            int elementNumber = 0;
            mesh->getElementAssociation<cae::core::ElementAssociationType::USER_ID>(1, &ids[n], &elementNumber);
            std::cout << std::setw(8) << ids[n] << ' ' << std::setw(8) << elementNumber;
            state.setDerivedQuantity(cae::core::State::DerivedType::VECTOR);
            // Print components
            state.getData(1, &ids[n], values);
            std::cout << std::setw(14) << values[0] << ' ' << std::setw(14) << values[1] << ' ' << std::setw(14) << values[2];
            // Print magnitude
            state.setDerivedQuantity(cae::core::State::DerivedType::VECTOR_MAGNITUDE);
            float magnitude = 0.0f;
            state.getData(1, &ids[n], &magnitude);
            std::cout << "  magnitude= " << std::setw(14) << magnitude << '\n';
        }
        std::cout << '\n';

        // Print global components if originally local components
        cae::core::State::System systemType;
        state.getCoordinateSystem(&systemType);
        if (systemType == cae::core::State::System::LOCAL_UNDEFORMED) {
            state.transformToCoordinateSystem(cae::core::State::System::GLOBAL, NULL);
            // Loop over requested elements
            state.setDerivedQuantity(cae::core::State::DerivedType::VECTOR);
            std::cout << "global system\n";
            for (int n = 0; n < requestedElementsCount; n++) {
                if (ids[n] == 0) {
                    continue;
                }
                int elementNumber = 0;
                mesh->getElementAssociation<cae::core::ElementAssociationType::USER_ID>(1, &ids[n], &elementNumber);
                std::cout << std::setw(8) << ids[n] << ' ' << std::setw(8) << elementNumber;
                state.getData(1, &ids[n], values);
                std::cout << std::setw(14) << values[0] << ' ' << std::setw(14) << values[1] << ' ' << std::setw(14) << values[2]
                          << '\n';
            }
            std::cout << '\n';
        }
        // Print attributes
        resultMetadata.printAttributes();
    }
    std::cout.flags(previousFlags);
}

static void
print_stress(cae::access::DataSource& dataSource, cae::core::MeshPtr& mesh)
{
    // Determine maximum number of states
    int stateCount = 0;
    dataSource.getStateCount(&stateCount);

    std::vector<int> stateIds(stateCount, 0);

    // Search for element-node and element stress results. Concatenade ids into a single array
    int foundElementNodeStates = 0, foundElementStates = 0;
    dataSource.searchState("S.*EL:*", stateCount, stateIds.data(), &foundElementNodeStates);
    dataSource.searchState("S.*E:*", stateCount, &stateIds[foundElementNodeStates], &foundElementStates);
    foundElementStates += foundElementNodeStates;
    if (foundElementStates == 0) {
        return;
    }

    int elementCount = 0;
    int nodeCount = 0;
    mesh->inquire(&nodeCount, &elementCount);

    // Find maximum number of element nodes
    int maxElementNodesCount = 0;
    mesh->getMaxElementNodes(&maxElementNodesCount);

    // Allocate array to fit maximum element node data
    std::vector<std::array<float, 6>> values(2 * maxElementNodesCount, {0.f, 0.f, 0.f, 0.f, 0.f, 0.f});
    auto previousFlags = std::cout.flags();
    auto previousPrecision = std::cout.precision();
    std::cout << std::scientific << std::setprecision(5);

    // Print first, middle and last element
    int requestedElementsCount = 3;
    int requestedElementIds[3] = {1, elementCount / 2, elementCount};
    // Loop over stress results
    cae::core::State state;
    for (int i = 0; i < foundElementStates; i++) {
        cae::core::ResultMetadata resultMetadata;
        dataSource.getMetadata(stateIds[i], &resultMetadata);
        char stateName[cae::core::MAX_NAME_LENGTH];
        long long length = 0;
        int rowsCount = 0, columnsCount = 0;
        cae::core::DataLayout dataLayout;
        resultMetadata.inquire(stateName, &length, &rowsCount, &columnsCount, &dataLayout);
        if (rowsCount != 6) {
            continue;
        }
        cae::core::EntityType entityType, subEntityType;
        resultMetadata.getEntityType(&entityType, &subEntityType);

        // Print header
        std::cout << "\nState: " << stateName << '\n';
        std::cout << "\nStresses\n";

        dataSource.loadState(stateName, &state);

        // Print stress components first
        state.setDerivedQuantity(cae::core::State::DerivedType::TENSOR);

        // Loop over requested elements
        int nodesInElement = 0;
        cae::core::ComplexMode complexMode;
        state.getComplexMode(&complexMode);
        for (int n = 0; n < requestedElementsCount; n++) {
            if (requestedElementIds[n] == 0) {
                continue;
            }
            int elementNumber = 0;
            mesh->getElementAssociation<cae::core::ElementAssociationType::USER_ID>(1, &requestedElementIds[n], &elementNumber);
            std::cout << std::setw(8) << elementNumber << ", component stresses\n";

            nodesInElement = 1;
            // If result in element nodes, get number of nodes
            if (subEntityType == cae::core::EntityType::NODE) {
                mesh->getElementEntityCount(cae::core::EntityType::NODE, requestedElementIds[n], &nodesInElement);
            }
            state.getData(1, &requestedElementIds[n], (float*)values.data());

            // Loop over nodes in element
            for (int j = 0; j < nodesInElement; j++) {
                if (complexMode == cae::core::ComplexMode::REAL) {
                    std::cout << ' ' << std::setw(12) << values[j][0] << ' ' << std::setw(12) << values[j][1] << ' '
                              << std::setw(12) << values[j][2] << ' ' << std::setw(12) << values[j][3] << ' ' << std::setw(12)
                              << values[j][4] << ' ' << std::setw(12) << values[j][5] << '\n';
                }
                else {
                    float (*complexValues)[12];
                    complexValues = (float (*)[12])values.data();
                    std::cout << ' ' << std::setw(12) << complexValues[j][0] << ' ' << std::setw(12) << complexValues[j][1]
                              << "(i) " << std::setw(12) << complexValues[j][2] << ' ' << std::setw(12) << complexValues[j][3]
                              << "(i) " << std::setw(12) << complexValues[j][4] << ' ' << std::setw(12) << complexValues[j][5]
                              << "(i)\n";
                    std::cout << ' ' << std::setw(12) << complexValues[j][6] << ' ' << std::setw(12) << complexValues[j][7]
                              << "(i) " << std::setw(12) << complexValues[j][8] << ' ' << std::setw(12) << complexValues[j][9]
                              << "(i) " << std::setw(12) << complexValues[j][10] << ' ' << std::setw(12) << complexValues[j][11]
                              << "(i)\n";
                }
            }
        }
        // Skip derived quantities if complex data
        if (complexMode != cae::core::ComplexMode::REAL) {
            continue;
        }

        // Print mean stress
        state.setDerivedQuantity(cae::core::State::DerivedType::TENSOR_MEAN);

        // Loop over requested elements
        for (int n = 0; n < requestedElementsCount; n++) {
            if (requestedElementIds[n] == 0) {
                continue;
            }
            int elementNumber = 0;
            mesh->getElementAssociation<cae::core::ElementAssociationType::USER_ID>(1, &requestedElementIds[n], &elementNumber);
            std::cout << std::setw(8) << elementNumber << ", mean stress\n";

            nodesInElement = 1;
            // If result in element nodes, get number of nodes
            if (subEntityType == cae::core::EntityType::NODE) {
                mesh->getElementEntityCount(cae::core::EntityType::NODE, requestedElementIds[n], &nodesInElement);
            }
            std::vector<float> meanValues(maxElementNodesCount, 0.0f);
            state.getData(1, &requestedElementIds[n], meanValues.data());

            // Loop over nodes in element
            for (int j = 0; j < nodesInElement; j++) {
                std::cout << ' ' << std::setw(12) << meanValues[j] << '\n';
            }
        }
        std::cout << '\n';

        state.setDerivedQuantity(cae::core::State::DerivedType::TENSOR);

        // Print stress in global system if originally in local system
        cae::core::State::System systemType;
        state.getCoordinateSystem(&systemType);
        if (systemType == cae::core::State::System::LOCAL_UNDEFORMED || systemType == cae::core::State::System::LOCAL_DEFORMED) {
            cae::core::State stateRotang;
            if (systemType == cae::core::State::System::LOCAL_DEFORMED) {
                char rotangStateName[cae::core::MAX_NAME_LENGTH] = {};
                resultMetadata.getAttributeValueString("Link.RotAng", rotangStateName);
                dataSource.loadState(rotangStateName, &stateRotang);
                state.setLocalCoordinateSystemDirectionCosines(&stateRotang);
            }
            state.transformToCoordinateSystem(cae::core::State::System::GLOBAL, NULL);
            std::cout << "global system\n";

            // Loop over requested elements
            for (int n = 0; n < requestedElementsCount; n++) {
                if (requestedElementIds[n] == 0) {
                    continue;
                }
                int elementNumber = 0;
                mesh->getElementAssociation<cae::core::ElementAssociationType::USER_ID>(1, &requestedElementIds[n],
                                                                                        &elementNumber);
                std::cout << std::setw(8) << elementNumber << ", component stresses\n";

                nodesInElement = 1;
                // If result in element nodes, get number of nodes
                if (subEntityType == cae::core::EntityType::NODE) {
                    mesh->getElementEntityCount(cae::core::EntityType::NODE, requestedElementIds[n], &nodesInElement);
                }
                state.getData(1, &requestedElementIds[n], (float*)values.data());

                // Loop over nodes in element
                for (int j = 0; j < nodesInElement; j++) {
                    std::cout << ' ' << std::setw(12) << values[j][0] << ' ' << std::setw(12) << values[j][1] << ' '
                              << std::setw(12) << values[j][2] << ' ' << std::setw(12) << values[j][3] << ' ' << std::setw(12)
                              << values[j][4] << ' ' << std::setw(12) << values[j][5] << '\n';
                }
            }
        }
        std::cout << '\n';

        // Print in material system
        cae::core::Status successfullyTransformedCoordinateSystem =
        state.transformToCoordinateSystem(cae::core::State::System::MATERIAL, NULL);
        if (!successfullyTransformedCoordinateSystem) {
            continue;
        }
        // Loop over requested elements
        std::cout << "material system\n";
        for (int n = 0; n < requestedElementsCount; n++) {
            if (requestedElementIds[n] == 0) {
                continue;
            }
            int elementNumber = 0;
            mesh->getElementAssociation<cae::core::ElementAssociationType::USER_ID>(1, &requestedElementIds[n], &elementNumber);
            std::cout << std::setw(8) << elementNumber << ", component stresses\n";

            nodesInElement = 1;
            // If element node get number of nodes
            if (subEntityType == cae::core::EntityType::NODE) {
                mesh->getElementEntityCount(cae::core::EntityType::NODE, requestedElementIds[n], &nodesInElement);
            }
            state.getData(1, &requestedElementIds[n], (float*)values.data());

            // Loop over nodes in element
            for (int j = 0; j < nodesInElement; j++) {
                std::cout << ' ' << std::setw(12) << values[j][0] << ' ' << std::setw(12) << values[j][1] << ' ' << std::setw(12)
                          << values[j][2] << ' ' << std::setw(12) << values[j][3] << ' ' << std::setw(12) << values[j][4] << ' '
                          << std::setw(12) << values[j][5] << '\n';
            }
        }
        resultMetadata.printAttributes();
    }
    std::cout.flags(previousFlags);
    std::cout.precision(previousPrecision);
}

static void
print_result(cae::access::DataSource& dataSource, cae::core::MeshPtr& mesh)
{
    int maxElementNodesCount = 0;
    mesh->getMaxElementNodes(&maxElementNodesCount);
    std::vector<int> connectivity(maxElementNodesCount);

    cae::core::State state;
    auto previousFlags = std::cout.flags();
    std::cout << std::scientific;

    std::vector<float> resultData;
    std::vector<cae::core::LayerPosition> position;
    std::vector<int> layer;
    int maxDataSize = 0;
    int maxSectionSize = 0;
    // Loop over states
    cae::core::ListPtr<char> stateNames;
    int stateCount = 0;
    dataSource.getStateCount(&stateCount);
    dataSource.getStateNames(stateNames);
    for (int nameIndex = 0; nameIndex < stateCount; nameIndex++) {
        cae::core::Pointer<char> name;
        stateNames->get(nameIndex, name);

        cae::core::ResultMetadata resultMetadata;
        dataSource.getMetadata(name.get(), &resultMetadata);

        // Get DataType attribute
        char dataType[cae::core::MAX_NAME_LENGTH];
        resultMetadata.getAttributeValueString("DataType", dataType);

        // Get Contents attribute
        char contents[cae::core::MAX_NAME_LENGTH];
        resultMetadata.getAttributeValueString("Contents", contents);

        // Get result physical dimensions
        char dimensions[cae::core::MAX_NAME_LENGTH] = {};
        resultMetadata.getDimensions(dimensions);

        // Print name
        std::cout << "\n\nState: " << name.get() << '\n';

        // Print DataType, Contents and dimensions
        std::cout << "DataType: " << dataType << '\n';
        std::cout << "Contents: " << contents << '\n';
        std::cout << "Dimensions: " << dimensions << '\n';
        cae::core::EntityType entityType, subentityType;
        resultMetadata.getEntityType(&entityType, &subentityType);
        // Skip states with DOF entity type
        if (entityType == cae::core::EntityType::DOF) {
            resultMetadata.printAttributes();
            continue;
        }

        dataSource.loadState(name.get(), &state);
        int entitiesCount = 0;
        cae::core::DataLayout dataLayout;
        state.inquire(&entitiesCount, &entityType, &subentityType, &dataLayout);

        // Maximum data size, number of locations and sections
        int dataSize = 0;
        int sectionDataSize = 0;
        int maxLocationSize = 0;
        state.getMaxDataCount(&dataSize, &maxLocationSize, &sectionDataSize);
        if (dataSize > maxDataSize) {
            maxDataSize = dataSize;
            resultData.resize(maxDataSize);
        }
        if (sectionDataSize > maxSectionSize) {
            maxSectionSize = sectionDataSize;
            position.resize(maxSectionSize);
            layer.resize(maxSectionSize);
        }

        // Query local or global system
        cae::core::State::System systemType;
        state.getCoordinateSystem(&systemType);
        if (systemType == cae::core::State::System::GLOBAL) {
            std::cout << "system= Global\n";
        }
        else {
            std::cout << "system= Local\n";
        }
        int engineeringStrainFlag = 0;
        state.getEngineeringStrainFlag(&engineeringStrainFlag);
        if (engineeringStrainFlag) {
            std::cout << "strain= Engineering\n";
        }

        int numberOfComponents = 0;
        state.getDerivedQuantityComponentCount(&numberOfComponents);

        // Return all sections
        state.setSection(0);

        // Loop through all entities
        for (int index = 1; index <= entitiesCount; index++) {
            // Select entities to ignore for whatever reason
            if (index != 1)
                continue;
            // Print entity id
            int id = 0;
            if (entityType == cae::core::EntityType::NODE) {
                mesh->getNodeAssociation<cae::core::NodeAssociationType::USER_ID>(1, &index, &id);
                std::cout << "node= " << id << '\n';
            }
            else if (entityType == cae::core::EntityType::ELEMENT || entityType == cae::core::EntityType::FACE ||
                     entityType == cae::core::EntityType::EDGE) {
                mesh->getElementAssociation<cae::core::ElementAssociationType::USER_ID>(1, &index, &id);
                std::cout << "elem= " << id << '\n';
            }
            else if (entityType == cae::core::EntityType::MODE) {
                std::cout << "mode= " << id << '\n';
            }
            // Check if data defined
            int dataStatus = 0;
            state.getStatus(1, &index, &dataStatus);
            if (dataStatus == 0) {
                std::cout << " no data\n";
                continue;
            }

            // Get results data for entity
            state.getData(1, &index, resultData.data());
            // Print data at nodes
            if (entityType == cae::core::EntityType::NODE) {
                for (int j = 0; j < numberOfComponents; j++) {
                    std::cout << ' ' << resultData[j];
                }
                std::cout << '\n';
            }
            // Print data at element faces or edges
            else if (entityType == cae::core::EntityType::FACE || entityType == cae::core::EntityType::EDGE) {
                int elementEntityCount = 0;
                int elementEntities[cae::core::MAX_J] = {};
                state.getElementEntities(index, &elementEntityCount, elementEntities);
                // Element face or edge
                if (subentityType == cae::core::EntityType::NONE) {
                    for (int k = 0; k < elementEntityCount; k++) {
                        std::cout << std::setw(4) << elementEntities[k];
                        for (int j = 0; j < numberOfComponents; j++) {
                            std::cout << ' ' << resultData[k * numberOfComponents + j];
                        }
                        std::cout << '\n';
                    }
                }
                // Element face or edge node
                else {
                    for (int k = 0; k < elementEntityCount; k++) {
                        std::cout << std::setw(4) << elementEntities[k];
                        int nodesInElement = 0;
                        mesh->getElementEntityConnectivity(entityType, index, elementEntities[k], &nodesInElement,
                                                           connectivity.data());
                        for (int n = 0; n < nodesInElement; n++) {
                            std::cout << std::setw(4) << (n + 1);
                            for (int j = 0; j < numberOfComponents; j++) {
                                std::cout << ' '
                                          << resultData[k * numberOfComponents * nodesInElement + n * numberOfComponents + j];
                            }
                            std::cout << '\n';
                        }
                    }
                }
            }
            // Print data at elements
            else if (entityType == cae::core::EntityType::ELEMENT) {
                int numberOfSections = 0;
                state.getSectionCount(1, &index, &numberOfSections);
                // Get layer position
                state.getLayerInformation(index, position.data(), layer.data());
                // Element
                if (subentityType == cae::core::EntityType::NONE) {
                    for (int k = 0; k < numberOfSections; k++) {
                        if (numberOfSections > 1) {
                            print_section(position[k], layer[k]);
                        }
                        for (int j = 0; j < numberOfComponents; j++) {
                            std::cout << ' ' << resultData[k * numberOfComponents + j];
                        }
                        std::cout << '\n';
                    }
                }
                // Element node
                else {
                    int nodesInElement = 0;
                    mesh->getElementNodes(index, &nodesInElement, connectivity.data());
                    for (int k = 0; k < numberOfSections; k++) {
                        if (numberOfSections > 1) {
                            print_section(position[k], layer[k]);
                        }
                        for (int n = 0; n < nodesInElement; n++) {
                            int node = 0;
                            mesh->getNodeAssociation<cae::core::NodeAssociationType::USER_ID>(1, &connectivity[n], &node);
                            std::cout << "node= " << node << '\n';
                            for (int j = 0; j < numberOfComponents; j++) {
                                std::cout << ' '
                                          << resultData[k * numberOfComponents * nodesInElement + n * numberOfComponents + j];
                            }
                            std::cout << '\n';
                        }
                    }
                }
            }
            // Print data at modes
            else if (entityType == cae::core::EntityType::MODE) {
                for (int j = 0; j < numberOfComponents; j++) {
                    std::cout << ' ' << resultData[j];
                }
                std::cout << '\n';
            }
        }
        resultMetadata.printAttributes();
    }
    std::cout.flags(previousFlags);
}

/*----------------------------------------------------------------------
                      print section and type
----------------------------------------------------------------------*/
static void
print_section(cae::core::LayerPosition position, int section)
{
    std::cout << "section= " << section;
    if (position == cae::core::LayerPosition::NONE) {
        std::cout << " none";
    }
    else if (position == cae::core::LayerPosition::MIDDLE) {
        std::cout << " middle";
    }
    else if (position == cae::core::LayerPosition::BOTTOM) {
        std::cout << " bottom";
    }
    else if (position == cae::core::LayerPosition::TOP) {
        std::cout << " top";
    }
    else if (position == cae::core::LayerPosition::INTEGRATION_POINT) {
        std::cout << " eip";
    }
    std::cout << '\n';
}
