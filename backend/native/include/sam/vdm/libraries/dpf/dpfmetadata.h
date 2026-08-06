#pragma once
#ifdef VKI_LIBAPI_ANSYS_DPF

#include <vector>
#include <set>
#include <map>
#include <string>
#include <unordered_set>
#include <bitset>
#include <unordered_map>
#include <memory>
#include <mutex>
#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
#include "sam/vis/resultInformation.h"
#include "sam/vdm/adapterlogger.h"
#include "sam/vdm/libraries/dpf/dpf2modelmappings.h"

class DpfModel;
typedef std::unique_ptr<DpfModel> DpfModelPtr;

//----------------------------------------
//
//----------------------------------------

struct DPFMeshInfo {
    struct ElementTypesProperties {
        static const Vint undefinedElementType = -1;
        Vint elementType = 0;
        Vint totalNodeCount = 0;
        Vint nodalForceNodeCount = 0;
        Vint nodalStressNodeCount = 0;
        std::vector<Vint> KEYOPT;
        Vint DOFPerNode = 0;
        Vint newGenerationElement = 0;

        ElementTypesProperties(Vint elementTypeArg, Vint totalNodeCountArg, Vint nodalForceNodeCountArg,
                               Vint nodalStressNodeCountArg, const std::vector<Vint>& KEYOPTArg, Vint DOFPerNodeArg,
                               Vint newGenerationElementArg):
            elementType(elementTypeArg), totalNodeCount(totalNodeCountArg), nodalForceNodeCount(nodalForceNodeCountArg),
            nodalStressNodeCount(nodalStressNodeCountArg), KEYOPT(KEYOPTArg), DOFPerNode(DOFPerNodeArg),
            newGenerationElement(newGenerationElementArg) {};

        static const ElementTypesProperties&
        Empty();
        bool
        isEmpty() const;
    };

    struct SectionProperties {
        Vint NumLayers;
        std::vector<Vdouble> Thickness;
        std::vector<Vint> MatID;
        std::vector<Vdouble> Orientation;
        std::vector<Vint> NumIntPoints;

        SectionProperties(): NumLayers(0) {};
    };

    DPFMeshInfo() = default;

    const ElementTypesProperties&
    getElementTypesProperties(Vlong elementScopingIndex) const;

    ansys::dpf::MeshedRegion meshRegion;
    vsy::string meshRegionName;
    vsy::string unit;
    Vint nodeCount = -1;
    Vint elementCount = -1;
    Vint ignoredElementCount = -1;
    Vlong elementNodeCount = -1;
    Vlong ignoredElementNodeCount = -1;
    Vlong elementCornerNodeCount = -1;
    std::map<Vint, ElementTypesProperties> elementTypeInformationMap;
    std::map<Vint, SectionProperties> sectionPropertiesMap;
    std::map<Vint, std::vector<Vdouble>> realConstantMap;
    std::vector<ansys::dpf::dp_int> elementTypeData;
    std::vector<ansys::dpf::dp_int> elementSectionIdData;
    std::vector<ansys::dpf::dp_int> elementMaterialIdData;
    std::vector<ansys::dpf::dp_int> elementRealConstantIdData;
    std::vector<ansys::dpf::dp_int> elementTypeIdData;
    std::vector<ansys::dpf::dp_int> SC03DomainIdData;
    Vint meshRegionId = -1; // or index to be confirmed
    std::vector<std::string> availableNamedSelections;

    // Scopings
    ansys::dpf::Scoping elementScoping;
    ansys::dpf::Scoping nodeScoping;
};

struct DPFResultInfo {
    DPFResultInfo();
    std::vector<Vint> datasetIndexes;
    Vbyte dpfSectionCount = 1;

    vsy::string operatorName;
    vsy::string dpfNativeName;
    dpfmappings::dpfResultNames dpfResultName = dpfmappings::dpfResultNames::none;
    vsy::string unit;
    Vint dofLabelsCount = 1;
    Vint derivativeOrderCount = 0;

    vsy::string location;
    bool resultWithUnpredictableSize = false;

    std::set<std::string> subResults;
    std::vector<vsy::string> availableQualifiers;

    // Result indexes whose values must be added to the current result
    std::vector<Vint> resultIndexesToBeAdded;

    vis_ResultInformation resultInformation;
};

// used to store data to read element nodes, element center, since sometimes
// depdning on the result we should expect one result per element node
// and sometimes one result per Corner element node

struct EntityInfo {
    Vbyte dataNodeCount = 0; // subentity count
    Vbyte sectionCount = 0;  // entity number of results
    Vbyte layerPosition = SYS_UCHAR_UNDEFINED;
    Vint effectiveOffset = 0;
};

struct Section {
    enum Location { undefinedLocation = 0, elementCenter = 1, cornerNode = 2, elementNode = 3 };
    enum Physics { undefinedPhysics = 0, mechanical = 1, thermal = 2 };

    Section() = default;
    Section(Location _location, Physics _physics): location(_location), physics(_physics) {};

    Location location = undefinedLocation;
    Physics physics = undefinedPhysics;

    static Section
    findSectionSpecifications(const vis_ResultInformation& resultInformation);
    static const std::map<Vint, std::map<Vint, Section>>&
    SECTION_SPECIFICATIONS();
    static bool
    isResultReference(Section::Physics _physics, Vint resultType);
};

struct DPFSectionInfo {
    DPFSectionInfo() = default;

    Section section;

    Vint dpfReportedSectionCount = 1;
    Vint dpfReportedLayerPositions = SYS_LAYERPOSITION_NONE;

    std::vector<EntityInfo> entityInfos;
    Vlong totalEntityCount = -1;

    DPFResultInfo* resultTobuildSectionData = nullptr;
    std::vector<DPFResultInfo*> results; // result ids that uses this section definition
};

struct DPFStateInfo {
    DPFStateInfo() = default;
    DPFStateInfo(Vint stateid, const vsy::string& analysistype, Vint stepindex, Vint substep, Vdouble timeValue,
                 Vdouble frequencyValue, Vdouble loadFactorValue, Vdouble imaginaryFrequencyValue, Vint harmonicindex,
                 const vsy::string& statequalifier);
    Vint stateId = -1;
    vsy::string analysisType;
    Vint stepIndex = -1;
    Vint subStep = -1;

    Vdouble time = SYS_DOUBLE_UNDEFINED;
    Vdouble frequency = SYS_DOUBLE_UNDEFINED;
    Vdouble loadFactor = SYS_DOUBLE_UNDEFINED;
    Vdouble imaginaryFrequency = SYS_DOUBLE_UNDEFINED;
    Vint harmonicIndex = -1;
    vsy::string stateQualifier;
};

struct DPFResultSpec {
    DPFResultSpec() = default;
    Vint resultIndex = -1;
    Vint stateIndex = -1;

    /* == operator to use it in unordered_map */
    bool
    operator==(const DPFResultSpec& rhs) const
    {
        return (resultIndex == rhs.resultIndex && stateIndex == rhs.stateIndex);
    }
};

/* Hasher combination utility */
template<class T>
inline void
hash_combine(std::size_t& s, const T& v)
{
    std::hash<T> h;
    s ^= h(v) + 0x9e3779b9 + (s << 6) + (s >> 2);
}

/* Create a hasher for DPFResultSpec */
template<>
struct std::hash<DPFResultSpec> {
    std::size_t
    operator()(const DPFResultSpec& f) const
    {
        std::size_t res = 0;
        hash_combine(res, f.resultIndex);
        hash_combine(res, f.stateIndex);
        return res;
    }
};

class DPFMetaData {
  public:
    DPFMetaData(AdapaterLogger& logger);

    // methods
    void
    buildMeshInformation(DpfModelPtr& dpfModel);
    void
    buildStatesInformation(DpfModelPtr& dpfModel);
    void
    buildResultsInformation(DpfModelPtr& dpfModel);
    void
    buildSectionInformation(DpfModelPtr& dpfModel);
    void
    buildResultSpecifications();

    vsy::vector<vsy::string>
    useDefaultResultNameAsIdentifier(DpfModelPtr& dpfModel);
    vsy::vector<bool>
    createDefinedFlags(const ansys::dpf::Scoping& elementScope, const ansys::dpf::Scoping& resultScope);

    // setters
    void
    setFilename(const vsy::string& filename);
    void
    setResultIdentifier(Vint resultIndex, Vint resultDatasetIndex, const vsy::string& globalNameId);
    void
    setSectionIdentifier(Vint sectionIndex, const vsy::string& globalNameId);
    void
    setIntegerOption(const vsy::string& optionsNameId, const vsy::string& key, const vsy::string& description, Vint value);

    // queries
    Vint
    isResult(const vsy::string& globalNameId);
    DPFResultSpec
    findDPFResultSpec(const vsy::string& globalNameId) const;
    void
    getResultInfo(DpfModelPtr& dpfModel, Vint resultIndex, vis_ResultInformation* resultInformation) const;
    Vint
    getSectionInfosCount() const;
    DPFSectionInfo*
    findDPFSectionInfo(const vsy::string& globalNameId) const;
    const vsy::string&
    getFilename() const;
    bool
    isOperatorNotSupported(const vsy::string& operatorName) const;
    const std::set<Vint>&
    getUnsupportedElementTypes() const;
    ansys::dpf::FieldsContainer
    getFieldsContainerFromResultSpec(DpfModelPtr& dpfModel, const DPFResultSpec& resultSpec,
                                     const ansys::dpf::Scoping& currentScope) const;
    bool
    hasDpfResultsAtAllElementNodes(DpfModelPtr& dpfModel, const DPFResultInfo& dpfResultInfo, Vint dpfEntityId,
                                   ansys::dpf::Field& currentField) const;
    const ansys::dpf::Scoping&
    getNodeScoping() const;
    const ansys::dpf::Scoping&
    getElementScoping() const;
    Vint
    getElementSectionID(size_t elementIndex) const;
    Vdouble
    getSectionOverallThickness(Vint sectionID) const;
    bool
    hasSectionProperties(Vint sectionID) const;
    std::vector<Vdouble>
    getSectionOrientations(Vint sectionID) const;
    const std::vector<ansys::dpf::dp_int>&
    getElementTypeData() const;
    void
    clear();
    bool
    checkApdlFileVersion() const;
    const DPFMeshInfo&
    getMeshInfo() const;

    // Utility functions
    static std::vector<Vint>
    getFieldIndex(const vis_ResultInformation& resultInformation, ansys::dpf::FieldsContainer const* const fieldsContainer);
    static Vint
    getUniqueFieldIndex(const vis_ResultInformation& resultInformation, ansys::dpf::FieldsContainer const* const fieldsContainer,
                        AdapaterLogger* logger);
    bool
    hasElementTypeInformation() const;

    bool
    hasLicensing() const;

  private:
    vsy::string m_filename;
    vsy::string m_fileExtension;
    // This member allow to run a piece of code once for multilayered solid notification
    std::once_flag onceMultilayerMessageFlag;
    bool rotateResultToGlobalFrame = true;
    bool assumeLicensingAvailable = false;
    bool m_checkApdlFileVersion = true;
    bool m_hasAnsysLicense = false;
    AdapaterLogger& m_logger;

    void
    linkSectionAndResultInformation(DpfModelPtr& dpfModel);
    Vlong
    getTotalEntityCount(const DPFMeshInfo& meshInfo, Vint entity, Vint subEntity) const;
    Vint
    getExpectedValuesPerEntity(DpfModelPtr& dpfModel, Vint dpfEntityId, const DPFResultInfo& dpfResultInfo,
                               ansys::dpf::Field& currentField) const;
    Vint
    getValuesPerEntity(DpfModelPtr& dpfModel, Vint dpfEntityId, const DPFResultInfo& dpfResultInfo, bool maximumValueCountFlag,
                       ansys::dpf::Field& currentField) const;
    Vint
    getMaxValuesPerEntity(DpfModelPtr& dpfModel, Vint dpfEntityId, const DPFResultInfo& dpfResultInfo,
                          ansys::dpf::Field& currentField) const;
    ansys::dpf::FieldsContainer
    getFieldsContainer(DpfModelPtr& dpfModel, const DPFResultInfo& resultInfo, Vint stepIndex, Vint subStep) const;
    ansys::dpf::FieldsContainer
    getFieldsContainer(DpfModelPtr& dpfModel, const DPFResultInfo& resultInfo, Vint stepIndex, Vint subStep,
                       const ansys::dpf::Scoping& currentScope, const vsy::string& globalNameId) const;
    ansys::dpf::FieldsContainer
    getFirstStepAndSubstepFieldsContainer(DpfModelPtr& dpfModel, const DPFResultInfo& resultInfo) const;
    vsy::string
    createGlobalNameId(DpfModelPtr& dpfModel, const DPFResultInfo& resultInfo, Vint stepIndex, Vint subStep) const;

    void
    storeElementTypeData(DpfModelPtr& dpfModel, DPFMeshInfo& meshInfo);
    void
    getElementTypesProperties(DpfModelPtr& dpfModel, DPFMeshInfo& meshInfo);
    void
    getElementSectionProperties(DpfModelPtr& dpfModel, DPFMeshInfo& meshInfo) const;
    void
    getElementMaterialProperties(DpfModelPtr& dpfModel, DPFMeshInfo& meshInfo);
    void
    getElementRealConstantProperties(DpfModelPtr& dpfModel, DPFMeshInfo& meshInfo);
    void
    getElementTypeIdsProperties(DpfModelPtr& dpfModel, DPFMeshInfo& meshInfo);
    void
    getSC03DomainIdProperties(DpfModelPtr& dpfModel, DPFMeshInfo& meshInfo);

    DPFMeshInfo&
    getMeshInfoReference();

    bool
    isResultInLocalFrame(DpfModelPtr& dpfModel, const vsy::string& operatorName, Vint componentCount, Vint entityType) const;

    Vint
    getStepID(DpfModelPtr& dpfModel, Vint stepIndex, Vint subStep) const;

    void
    fillResultInfo(DpfModelPtr& dpfModel, const ansys::dpf::ResultInfo& resultInfo, const Vint stepCount,
                   const std::string& resultName, const std::string& subResultName, Vint& resultIndex);

    void
    addSubResults(DpfModelPtr& dpfModel, const std::set<std::string>& resultNames, const ansys::dpf::ResultInfo& resultInfo,
                  Vint stepCount, Vint resultIndex);

    bool
    hasDpfResultsAtAllElementNodesWithoutElementTypesProperties(DpfModelPtr& dpfModel, const DPFResultInfo& dpfResultInfo,
                                                                Vint dpfEntityId, Vint elementIndex,
                                                                ansys::dpf::Field& currentField) const;

  public:
    vsy::vector<DPFMeshInfo> meshInfos;
    vsy::vector<DPFStateInfo> stateInfos;
    vsy::vector<DPFResultInfo> resultInfos;
    vsy::vector<DPFSectionInfo> sectionInfos;
    vsy::unordered_map<DPFResultSpec, vsy::string> resultSpecificationsToGlobalNameId;

    vsy::vector<DPFResultSpec> resultSpecifications;
    vsy::unordered_map<vsy::string, DPFResultSpec> resultSpecificationsMap;
    vsy::unordered_map<vsy::string, DPFSectionInfo*> sectionsInfoMap;
};
#endif
