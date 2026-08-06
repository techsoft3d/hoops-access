#include <stdlib.h>
#include "sam/base/base.h"
#include "sam/vis/visdata.h"
#include "sam/vdm/vdm.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static void
print_displacement(vdm_LMan* lman, vis_Connect* connect);
static void
print_temperature_gradient(vdm_LMan* lman, vis_Connect* connect);
static void
print_stress(vdm_LMan* lman, vis_Connect* connect);
static void
print_result(vdm_LMan* lman, vis_Connect* connect);
static void
print_section(Vint position, Vint section);

/*----------------------------------------------------------------------
                     Read and Print Results State Data
----------------------------------------------------------------------*/
int
main(int argc, char** argv)
{
    char inputFile[256];
    /* check input arguments */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s inputfile [appendfile]\n", argv[0]);
        fprintf(stderr, " inputfile is blank, 'cantilever.unv' is assumed\n");
        strcpy(inputFile, "cantilever.unv");
    }
    else {
        strcpy(inputFile, argv[1]);
    }

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* Open file */
    vdm_Options* options = vdm_OptionsBegin();
    vdm_OptionsAddConvention(options, VDM_CONVENTION_SPARSE);
    vdm_LMan* lman = vdm_LManBegin();
    vdm_LManOpenFile(lman, inputFile, options);

    /* check for error */
    Vint ierr = vdm_LManError(lman);
    if (ierr) {
        fprintf(stderr, "Error: opening file %s\n", inputFile);
        vdm_LManCloseFile(lman);
        vdm_LManEnd(lman);
        exit(1);
    }
    /* look for appended file */
    for (Vint i = 2; i < argc; i++) {
        vdm_LManAppend(lman, argv[i]);
        /* check for error */
        ierr = vdm_LManError(lman);
        if (ierr) {
            fprintf(stderr, "Error: appending file %s to file %s\n", argv[i], argv[1]);
            exit(1);
        }
    }
    /* instance Model object for finite element model */
    vis_Model* model = vis_ModelBegin();
    vdm_LManLoadModel(lman, model);

    /* get Connect object created in Model */
    vis_Connect* connect;
    vis_ModelGetObject(model, VIS_CONNECT, (Vobject**)&connect);
    Vint nodesCount = 0;
    Vint elementsCount = 0;
    vis_ConnectNumber(connect, SYS_NODE, &nodesCount);
    vis_ConnectNumber(connect, SYS_ELEM, &elementsCount);
    printf("number of nodes= %d\n", nodesCount);
    printf("number of elems= %d\n", elementsCount);

    /* access and print displacments */
    print_displacement(lman, connect);
    /* access and print temperature gradients */
    print_temperature_gradient(lman, connect);

    /* access and print stresses */
    print_stress(lman, connect);
    /* access and print all results */
    print_result(lman, connect);

    vis_ModelDelete(model);
    vis_ModelEnd(model);

    vdm_OptionsEnd(options);
    vdm_LManCloseFile(lman);
    vdm_LManEnd(lman);
    return 0;
}

/*----------------------------------------------------------------------
                      print displacments
----------------------------------------------------------------------*/
static void
print_displacement(vdm_LMan* lman, vis_Connect* connect)
{
    /* allocate array for state indices */
    Vint statesCount = vdm_LManGetNumStates(lman); /* Maximum number of states */
    Vint* stateIds = (Vint*)malloc(statesCount * sizeof(Vint));

    /* search for displacement results */
    Vint thermalflag = 0;
    Vint foundStates = 0;
    vdm_LManSearchState(lman, (Vchar*)"D.*N:*", statesCount, stateIds, &foundStates);
    /* if no displacement, search for temperature */
    if (foundStates == 0) {
        thermalflag = 1;
        vdm_LManSearchState(lman, (Vchar*)"TEMP.*N:*", statesCount, stateIds, &foundStates);
    }

    if (foundStates == 0) {
        free(stateIds);
        return;
    }
    Vint nodesCount = 0;
    vis_ConnectNumber(connect, SYS_NODE, &nodesCount);

    /* print first, middle and last node */
    Vint requestedNodesCount = 3;
    Vint requestedNodeIds[3] = {1, nodesCount / 2, nodesCount};

    /* create state */
    vis_State* state = vis_StateBegin();
    Vchar stateName[SYS_MAXNAME];
    /* loop over displacement states */
    for (Vint i = 0; i < foundStates; i++) {
        vis_ResultMetadata* metadata = vis_ResultMetadataBegin();
        vdm_LManGetMetadata(lman, stateIds[i], metadata);
        Vlong length;
        Vint rowsCount, columnsCount, type;
        vis_ResultMetadataInq(metadata, stateName, &length, &rowsCount, &columnsCount, &type);
        /* print header */
        printf("\n\nState: %s\n", stateName);
        if (thermalflag == 0) {
            printf("\nDisplacements\n");
        }
        else {
            printf("\nTemperatures\n");
        }

        /* load state */
        vdm_LManLoadStateFromName(lman, stateName, state);
        Vint nument, enttype, subtype, datatype;
        vis_StateInq(state, &nument, &enttype, &subtype, &datatype);

        /* loop over requested nodes */
        Vfloat values[6];
        for (Vint n = 0; n < requestedNodesCount; n++) {
            if (requestedNodeIds[n] == 0)
                continue;
            Vint nodeNumber;
            vis_ConnectNodeAssoc(connect, VIS_USERID, 1, &requestedNodeIds[n], &nodeNumber);
            printf("%8d", nodeNumber);
            vis_StateSetDerive(state, datatype);

            Vfloat magnitude;
            if (datatype == VIS_SCALAR) {
                vis_StateData(state, 1, &requestedNodeIds[n], values);
                printf("%14e\n", values[0]);
                /* vector type */
            }
            else if (datatype == VIS_VECTOR) {
                /* print components */
                vis_StateData(state, 1, &requestedNodeIds[n], values);
                printf("%14e %14e %14e", values[0], values[1], values[2]);
                /* print magnitude */
                vis_StateSetDerive(state, VIS_VECTOR_MAG);
                vis_StateData(state, 1, &requestedNodeIds[n], &magnitude);
                printf("  magnitude= %14e\n", magnitude);
                /* six dof vector type */
            }
            else if (datatype == VIS_SIXDOF) {
                /* print components */
                vis_StateData(state, 1, &requestedNodeIds[n], values);
                printf("%14e %14e %14e  %14e %14e %14e", values[0], values[1], values[2], values[3], values[4], values[5]);
                /* print magnitudes */
                vis_StateSetDerive(state, VIS_SIXDOF_TMAG);
                vis_StateData(state, 1, &requestedNodeIds[n], &magnitude);
                Vfloat rotationMagnitude;
                vis_StateSetDerive(state, VIS_SIXDOF_RMAG);
                vis_StateData(state, 1, &requestedNodeIds[n], &rotationMagnitude);
                printf("  magnitudes= %14e %14e\n", magnitude, rotationMagnitude);
            }
        }
        printf("\n");

        /* print global components if originally local components */
        Vint systemType;
        vis_StateGetSystem(state, &systemType);
        if (systemType == STATE_LOCAL) {
            vis_StateTransform(state, STATE_GLOBAL, NULL);
            /* loop over requested nodes */
            vis_StateSetDerive(state, datatype);
            printf("global system\n");
            for (Vint n = 0; n < requestedNodesCount; n++) {
                if (requestedNodeIds[n] == 0)
                    continue;
                Vint nodenumber;
                vis_ConnectNodeAssoc(connect, VIS_USERID, 1, &requestedNodeIds[n], &nodenumber);
                printf("%8d", nodenumber);
                /* vector type */
                if (datatype == VIS_VECTOR) {
                    vis_StateData(state, 1, &requestedNodeIds[n], values);
                    printf("%14e %14e %14e\n", values[0], values[1], values[2]);
                    /* six dof vector type */
                }
                else if (datatype == VIS_SIXDOF) {
                    vis_StateData(state, 1, &requestedNodeIds[n], values);
                    printf("%14e %14e %14e  %14e %14e %14e\n", values[0], values[1], values[2], values[3], values[4], values[5]);
                }
            }
            printf("\n");
        }
        /* print attributes */
        vis_ResultMetadataPrintAttributes(metadata);
        vis_ResultMetadataEnd(metadata);
    }

    /* free memory */
    vis_StateEnd(state);
    free(stateIds);
}

/*----------------------------------------------------------------------
                      print temperature gradients
----------------------------------------------------------------------*/
static void
print_temperature_gradient(vdm_LMan* lman, vis_Connect* connect)
{
    /* allocate array for state ids */
    Vint statesCount = vdm_LManGetNumStates(lman); /* Maximum number of states */
    Vint foundStatesCount;
    Vint* stateIds = (Vint*)malloc(statesCount * sizeof(Vint));
    /* search for temp gradient results states */
    vdm_LManSearchState(lman, (Vchar*)"TEMP_GRAD.*E:*", statesCount, stateIds, &foundStatesCount);

    if (foundStatesCount == 0) {
        free(stateIds);
        return;
    }

    Vint elementsCount;
    vis_ConnectNumber(connect, SYS_ELEM, &elementsCount);

    /* create state */
    vis_State* state = vis_StateBegin();

    /* print first, middle and last element */
    Vint requestedElementsCount;
    requestedElementsCount = 3;
    Vint ids[3] = {1, elementsCount / 2, elementsCount};

    /* loop over states */
    for (Vint i = 0; i < foundStatesCount; i++) {
        vis_ResultMetadata* metadata = vis_ResultMetadataBegin();
        vdm_LManGetMetadata(lman, stateIds[i], metadata);
        Vchar stateName[SYS_MAXNAME];
        Vlong length;
        Vint rowsCount, columnsCount, type;
        vis_ResultMetadataInq(metadata, stateName, &length, &rowsCount, &columnsCount, &type);
        vis_ResultMetadataEnd(metadata);

        /* print header */
        printf("\n\nState: %s\n", stateName);
        printf("\nTemperature Gradients\n");

        /* load state */
        vdm_LManLoadStateFromName(lman, stateName, state);

        /* loop over requested elements */
        Vfloat values[3];
        for (Vint n = 0; n < requestedElementsCount; n++) {
            if (ids[n] == 0)
                continue;
            Vint elementNumber;
            vis_ConnectElemAssoc(connect, VIS_USERID, 1, &ids[n], &elementNumber);
            printf("%8d %8d", ids[n], elementNumber);
            vis_StateSetDerive(state, VIS_VECTOR);
            /* print components */
            vis_StateData(state, 1, &ids[n], values);
            printf("%14e %14e %14e", values[0], values[1], values[2]);
            /* print magnitude */
            vis_StateSetDerive(state, VIS_VECTOR_MAG);
            Vfloat magnitude;
            vis_StateData(state, 1, &ids[n], &magnitude);
            printf("  magnitude= %14e\n", magnitude);
        }
        printf("\n");

        /* print global components if originally local components */
        Vint systemType;
        vis_StateGetSystem(state, &systemType);
        if (systemType == STATE_LOCAL) {
            vis_StateTransform(state, STATE_GLOBAL, NULL);
            /* loop over requested elements */
            vis_StateSetDerive(state, VIS_VECTOR);
            printf("global system\n");
            for (Vint n = 0; n < requestedElementsCount; n++) {
                if (ids[n] == 0)
                    continue;
                Vint elementNumber;
                vis_ConnectElemAssoc(connect, VIS_USERID, 1, &ids[n], &elementNumber);
                printf("%8d %8d", ids[n], elementNumber);
                vis_StateData(state, 1, &ids[n], values);
                printf("%14e %14e %14e\n", values[0], values[1], values[2]);
            }
            printf("\n");
        }
        /* print attributes */
        vis_ResultMetadataPrintAttributes(metadata);
    }

    /* free memory */
    vis_StateEnd(state);
    free(stateIds);
}

/*----------------------------------------------------------------------
                      print stresses
----------------------------------------------------------------------*/
static void
print_stress(vdm_LMan* lman, vis_Connect* connect)
{
    /* determine maximum number of states */
    Vint stateCount = vdm_LManGetNumStates(lman);

    /* allocate array for state ids */
    Vint* stateIds = (Vint*)malloc(stateCount * sizeof(Vint));

    /* search for stress results */
    Vint foundElementNodeStates, foundElementStates;
    vdm_LManSearchState(lman, (Vchar*)"S.*EL:*", stateCount, stateIds, &foundElementNodeStates);
    vdm_LManSearchState(lman, (Vchar*)"S.*E:*", stateCount, &stateIds[foundElementNodeStates], &foundElementStates);
    foundElementStates += foundElementNodeStates;
    if (foundElementStates == 0) {
        free(stateIds);
        return;
    }
    Vint elementCount;
    vis_ConnectNumber(connect, SYS_ELEM, &elementCount);

    /* find maximum number of element nodes */
    Vint maxElementNodesCount;
    vis_ConnectMaxElemNode(connect, &maxElementNodesCount);

    /* allocate array to fit maximum element node data */
    Vfloat(*values)[6] = (Vfloat(*)[6])malloc(2 * maxElementNodesCount * 6 * sizeof(Vfloat));

    /* create state */
    vis_State* state = vis_StateBegin();

    /* print first, middle and last element */
    Vint requestedElementsCount = 3;
    Vint requestedElementIds[3] = {1, elementCount / 2, elementCount};
    /* loop over stress results */
    for (Vint i = 0; i < foundElementStates; i++) {
        vis_ResultMetadata* metadata = vis_ResultMetadataBegin();
        vdm_LManGetMetadata(lman, stateIds[i], metadata);
        Vchar stateName[SYS_MAXNAME];
        Vlong length;
        Vint rowsCount, columnsCount, type;
        vis_ResultMetadataInq(metadata, stateName, &length, &rowsCount, &columnsCount, &type);
        if (rowsCount != 6)
            continue;
        Vint entityType, subEntityType;
        vis_ResultMetadataEntType(metadata, &entityType, &subEntityType);

        /* print header */
        printf("\nState: %s\n", stateName);
        printf("\nStresses\n");

        /* load state */
        vdm_LManLoadStateFromName(lman, stateName, state);
        Vint complexMode;
        vis_StateGetComplexMode(state, &complexMode);

        /* print stress components first */
        vis_StateSetDerive(state, VIS_TENSOR);

        /* loop over requested elements */
        Vint nodesInElement;
        for (Vint n = 0; n < requestedElementsCount; n++) {
            if (requestedElementIds[n] == 0)
                continue;
            Vint elementNumber;
            vis_ConnectElemAssoc(connect, VIS_USERID, 1, &requestedElementIds[n], &elementNumber);
            printf("%8d, component stresses\n", elementNumber);

            nodesInElement = 1;
            /* if element node get number of nodes */
            if (subEntityType == SYS_NODE) {
                vis_ConnectElemNum(connect, SYS_NODE, requestedElementIds[n], &nodesInElement);
            }
            vis_StateData(state, 1, &requestedElementIds[n], (Vfloat*)values);

            /* loop over nodes in element */
            for (Vint j = 0; j < nodesInElement; j++) {
                if (complexMode == SYS_COMPLEX_REAL) {
                    printf(" %12.5e %12.5e %12.5e %12.5e %12.5e %12.5e\n", values[j][0], values[j][1], values[j][2], values[j][3],
                           values[j][4], values[j][5]);
                }
                else {
                    Vfloat(*complexValues)[12];
                    complexValues = (Vfloat(*)[12])values;
                    printf(" %12.5e %12.5e(i) %12.5e %12.5e(i) %12.5e %12.5e(i)\n", complexValues[j][0], complexValues[j][1],
                           complexValues[j][2], complexValues[j][3], complexValues[j][4], complexValues[j][5]);
                    printf(" %12.5e %12.5e(i) %12.5e %12.5e(i) %12.5e %12.5e(i)\n", complexValues[j][6], complexValues[j][7],
                           complexValues[j][8], complexValues[j][9], complexValues[j][10], complexValues[j][11]);
                }
            }
        }
        /* skip derived quantities if complex data */
        if (complexMode != SYS_COMPLEX_REAL)
            continue;
        /* print mean stress second */
        vis_StateSetDerive(state, VIS_TENSOR_MEAN);

        /* loop over requested elements */
        for (Vint n = 0; n < requestedElementsCount; n++) {
            if (requestedElementIds[n] == 0)
                continue;
            Vint elementNumber;
            vis_ConnectElemAssoc(connect, VIS_USERID, 1, &requestedElementIds[n], &elementNumber);
            printf("%8d, mean stress\n", elementNumber);

            nodesInElement = 1;
            /* if element node get number of nodes */
            if (subEntityType == SYS_NODE) {
                vis_ConnectElemNum(connect, SYS_NODE, requestedElementIds[n], &nodesInElement);
            }
            Vfloat* meanValues = (Vfloat*)malloc(maxElementNodesCount * sizeof(Vfloat));
            vis_StateData(state, 1, &requestedElementIds[n], meanValues);

            /* loop over nodes in element */
            for (Vint j = 0; j < nodesInElement; j++) {
                printf(" %12.5e\n", meanValues[j]);
            }
            free(meanValues);
        }
        printf("\n");
        vis_StateSetDerive(state, VIS_TENSOR);

        /* print stress in global if originally in local */
        Vint systemType;
        vis_StateGetSystem(state, &systemType);
        if (systemType == STATE_LOCAL || systemType == STATE_ROTANG) {
            vis_State* staterotang = NULL;
            if (systemType == STATE_ROTANG) {
                staterotang = vis_StateBegin();
                Vchar rotangStateName[SYS_MAXNAME];
                vis_ResultMetadataGetAttributeValueString(metadata, "Link.RotAng", rotangStateName);
                vdm_LManLoadStateFromName(lman, rotangStateName, staterotang);
                vis_StateSetObject(state, VIS_STATE_ROTANG, staterotang);
            }
            vis_StateTransform(state, STATE_GLOBAL, NULL);
            printf("global system\n");

            /* loop over requested elements */
            for (Vint n = 0; n < requestedElementsCount; n++) {
                if (requestedElementIds[n] == 0)
                    continue;
                Vint elementNumber;
                vis_ConnectElemAssoc(connect, VIS_USERID, 1, &requestedElementIds[n], &elementNumber);
                printf("%8d, component stresses\n", elementNumber);

                nodesInElement = 1;
                /* if element node get number of nodes */
                if (subEntityType == SYS_NODE) {
                    vis_ConnectElemNum(connect, SYS_NODE, requestedElementIds[n], &nodesInElement);
                }
                vis_StateData(state, 1, &requestedElementIds[n], (Vfloat*)values);

                /* loop over nodes in element */
                for (Vint j = 0; j < nodesInElement; j++) {
                    printf(" %12.5e %12.5e %12.5e %12.5e %12.5e %12.5e\n", values[j][0], values[j][1], values[j][2], values[j][3],
                           values[j][4], values[j][5]);
                }
            }
            if (systemType == STATE_ROTANG) {
                vis_StateEnd(staterotang);
            }
        }
        printf("\n");
        /* print in material system */
        vis_StateTransform(state, STATE_MATERIAL, NULL);
        if (vis_StateError(state))
            continue;
        /* loop over requested elements */
        printf("material system\n");
        for (Vint n = 0; n < requestedElementsCount; n++) {
            if (requestedElementIds[n] == 0)
                continue;
            Vint elementNumber;
            vis_ConnectElemAssoc(connect, VIS_USERID, 1, &requestedElementIds[n], &elementNumber);
            printf("%8d, component stresses\n", elementNumber);

            nodesInElement = 1;
            /* if element node get number of nodes */
            if (subEntityType == SYS_NODE) {
                vis_ConnectElemNum(connect, SYS_NODE, requestedElementIds[n], &nodesInElement);
            }
            vis_StateData(state, 1, &requestedElementIds[n], (Vfloat*)values);

            /* loop over nodes in element */
            for (Vint j = 0; j < nodesInElement; j++) {
                printf(" %12.5e %12.5e %12.5e %12.5e %12.5e %12.5e\n", values[j][0], values[j][1], values[j][2], values[j][3],
                       values[j][4], values[j][5]);
            }
        }
        /* print attributes */
        vis_ResultMetadataPrintAttributes(metadata);
        vis_ResultMetadataEnd(metadata);
    }
    /* free memory */
    vis_StateEnd(state);
    free(stateIds);
    free(values);
}

/*----------------------------------------------------------------------
                      print result
----------------------------------------------------------------------*/
static void
print_result(vdm_LMan* lman, vis_Connect* connect)
{
    /* allocate connectivity array to fit maximum number */
    Vint maxElementNodesCount;
    vis_ConnectMaxElemNode(connect, &maxElementNodesCount);
    Vint* connectivity = (Vint*)malloc(maxElementNodesCount * sizeof(Vint));

    /* create state  */
    vis_State* state = vis_StateBegin();

    /* pointer for returned results data */
    Vfloat* resultData = NULL;
    Vint* position = NULL;
    Vint* layer = NULL;
    Vint maxDataSize = 0;
    Vint maxSectionSize = 0;
    /* loop over states */
    vsy_List* stateNames;
    Vint statesCount = vdm_LManGetNumStates(lman);
    vdm_LManGetStateNames(lman, &stateNames);
    for (Vint nameIndex = 0; nameIndex < statesCount; nameIndex++) {
        Vchar* name = nullptr;
        vsy_ListRef(stateNames, nameIndex, (Vobject**)&name);

        vis_ResultMetadata* metadata = vis_ResultMetadataBegin();
        vdm_LManGetMetadataFromName(lman, name, metadata);

        /* get DataType attribute */
        Vchar dataType[ATTRIBUTE_MAXVALUE];
        vis_ResultMetadataGetAttributeValueString(metadata, "DataType", dataType);

        /* get Contents attribute */
        Vchar contents[ATTRIBUTE_MAXVALUE];
        vis_ResultMetadataGetAttributeValueString(metadata, "Contents", contents);

        /* get result physical dimensions */
        Vchar dimensions[SYS_MAXNAME];
        vis_ResultMetadataGetDimensions(metadata, dimensions);

        /* print name */
        printf("\n\nState: %s\n", name);

        /* print DataType, Contents and dimensions */
        printf("DataType: %s\n", dataType);
        printf("Contents: %s\n", contents);
        printf("Dimensions: %s\n", dimensions);
        Vint entityType, subentityType, datatype;
        vis_ResultMetadataEntType(metadata, &entityType, &subentityType);
        /* skip states with SYS_DOF entity type */
        if (entityType == SYS_DOF) {
            vis_ResultMetadataPrintAttributes(metadata);
            continue;
        }
        /* load state */
        vdm_LManLoadStateFromName(lman, name, state);

        /* number of entities, datatype */
        Vint entitiesCount;
        vis_StateInq(state, &entitiesCount, &entityType, &subentityType, &datatype);

        /* maximum data size, number of locations and sections */
        Vint dataSize;
        Vint sectionDataSize;
        Vint maxLocationSize;
        vis_StateDataMax(state, &dataSize, &maxLocationSize, &sectionDataSize);
        if (dataSize > maxDataSize) {
            maxDataSize = dataSize;
            resultData = (Vfloat*)realloc(resultData, maxDataSize * sizeof(Vfloat));
        }
        if (sectionDataSize > maxSectionSize) {
            maxSectionSize = sectionDataSize;
            position = (Vint*)realloc(position, maxSectionSize * sizeof(Vint));
            layer = (Vint*)realloc(layer, maxSectionSize * sizeof(Vint));
        }
        /* query local or global system */
        Vint systemType;
        vis_StateGetSystem(state, &systemType);
        if (systemType == STATE_GLOBAL) {
            printf("system= Global\n");
        }
        else {
            printf("system= Local\n");
        }
        Vint engineeringStrainFlag;
        vis_StateGetEngineeringStrain(state, &engineeringStrainFlag);
        if (engineeringStrainFlag) {
            printf("strain= Engineering\n");
        }

        Vint numberOfComponents;
        vis_StateNumDerive(state, &numberOfComponents);

        /* return all sections */
        vis_StateSetSection(state, 0);

        /* loop through all entities */
        for (Vint index = 1; index <= entitiesCount; index++) {
            /* select entities to ignore for whatever reason */
            if (index != 1)
                continue;
            /* print entity id */
            Vint id = 0;
            if (entityType == SYS_NODE) {
                vis_ConnectNodeAssoc(connect, VIS_USERID, 1, &index, &id);
                printf("node= %d\n", id);
            }
            else if (entityType == SYS_ELEM || entityType == SYS_FACE || entityType == SYS_EDGE) {
                vis_ConnectElemAssoc(connect, VIS_USERID, 1, &index, &id);
                printf("elem= %d\n", id);
            }
            else if (entityType == SYS_MODE) {
                printf("mode= %d\n", id);
            }
            /* see if data defined */
            Vint status;
            vis_StateDataStat(state, 1, &index, &status);
            if (status == 0) {
                printf(" no data\n");
                continue;
            }
            /* get results data for entity */
            vis_StateData(state, 1, &index, resultData);
            /* print data */
            /* data at node */
            if (entityType == SYS_NODE) {
                for (Vint j = 0; j < numberOfComponents; j++) {
                    printf(" %e", resultData[j]);
                }
                printf("\n");
                /* data at element face or edge */
            }
            else if (entityType == SYS_FACE || entityType == SYS_EDGE) {
                Vint elementEntityCount;
                Vint elementEntities[VIS_MAX_MAXJ];
                vis_StateDataEnt(state, index, &elementEntityCount, elementEntities);
                /* element face or edge */
                if (subentityType == SYS_NONE) {
                    for (Vint k = 0; k < elementEntityCount; k++) {
                        printf("%4d", elementEntities[k]);
                        for (Vint j = 0; j < numberOfComponents; j++) {
                            printf(" %e", resultData[k * numberOfComponents + j]);
                        }
                        printf("\n");
                    }
                    /* element face or edge node */
                }
                else {
                    for (Vint k = 0; k < elementEntityCount; k++) {
                        printf("%4d", elementEntities[k]);
                        Vint nodesInElement;
                        vis_ConnectElemCon(connect, entityType, index, elementEntities[k], &nodesInElement, connectivity);
                        for (Vint n = 0; n < nodesInElement; n++) {
                            printf("%4d", n + 1);
                            for (Vint j = 0; j < numberOfComponents; j++) {
                                printf(" %e", resultData[k * numberOfComponents * nodesInElement + n * numberOfComponents + j]);
                            }
                            printf("\n");
                        }
                    }
                }
                /* data at element */
            }
            else if (entityType == SYS_ELEM) {
                Vint numberOfSections;
                vis_StateDataSect(state, 1, &index, &numberOfSections);
                /* get layer position */
                vis_StateDataLayers(state, index, position, layer);
                /* element */
                if (subentityType == SYS_NONE) {
                    for (Vint k = 0; k < numberOfSections; k++) {
                        if (numberOfSections > 1) {
                            print_section(position[k], layer[k]);
                        }
                        for (Vint j = 0; j < numberOfComponents; j++) {
                            printf(" %e", resultData[k * numberOfComponents + j]);
                        }
                        printf("\n");
                    }
                    /* element node */
                }
                else {
                    Vint nodesInElement;
                    vis_ConnectElemNode(connect, index, &nodesInElement, connectivity);
                    for (Vint k = 0; k < numberOfSections; k++) {
                        if (numberOfSections > 1) {
                            print_section(position[k], layer[k]);
                        }
                        for (Vint n = 0; n < nodesInElement; n++) {
                            Vint node;
                            vis_ConnectNodeAssoc(connect, VIS_USERID, 1, &connectivity[n], &node);
                            printf("node= %d\n", node);
                            for (Vint j = 0; j < numberOfComponents; j++) {
                                printf(" %e", resultData[k * numberOfComponents * nodesInElement + n * numberOfComponents + j]);
                            }
                            printf("\n");
                        }
                    }
                }
                /* data at mode */
            }
            else if (entityType == SYS_MODE) {
                for (Vint j = 0; j < numberOfComponents; j++) {
                    printf(" %e", resultData[j]);
                }
                printf("\n");
            }
        }
        /* print attributes */
        vis_ResultMetadataPrintAttributes(metadata);
        vis_ResultMetadataEnd(metadata);
    }
    /* free memory */
    vis_StateEnd(state);
    if (resultData) {
        free(resultData);
    }
    if (position) {
        free(position);
        free(layer);
    }
    free(connectivity);
}

/*----------------------------------------------------------------------
                      print section and type
----------------------------------------------------------------------*/
static void
print_section(Vint position, Vint section)
{
    printf("section= %d", section);
    if (position == SYS_LAYERPOSITION_NONE) {
        printf(" none");
    }
    else if (position == SYS_LAYERPOSITION_MID) {
        printf(" middle");
    }
    else if (position == SYS_LAYERPOSITION_BOT) {
        printf(" bottom");
    }
    else if (position == SYS_LAYERPOSITION_TOP) {
        printf(" top");
    }
    else if (position == SYS_LAYERPOSITION_INTPNT) {
        printf(" eip");
    }
    printf("\n");
}
