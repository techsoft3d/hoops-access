#pragma once
#ifdef CEE_SAM_DATA_PROVIDER_FRAMEWORK

#include <string>
#include <vector>
#include <memory>
#include <map>
#include "sam/base/basedefs.h"
#include "cdphlResult.h"
#include "CDPString.h"
#include "CDPDataProviderTypes.h"
#include "cdphlDataProviderInfo.h"
#include "sam/vis/resultInformation.h"
#include "sam/base/stdcontainers.h"

class AdapaterLogger;
class CDPDataProvider;
namespace cdphl {
    class MetaData;
    class Geometry;
    class StateInfo;
} // namespace cdphl

enum class ResultType {
    SCALAR = 1,
    VECTOR,
    DISPLACEMENT,
    STRESS_TENSOR,
    STRAIN_TENSOR,
    RIGID_BODY_TRANSFORMATION,
    VISIBILITY,
    NONE = 99
};
enum class ResultMappingType { NODES = 1, ELEMENTS, ELEMENTNODES, ELEMENTFACES, NONE = 99 };
enum class ItemType { NONE, ELEMENT };

struct PluginResultInfo {
  private:
    Vint m_resultId = -1;
    cdphl::ResultSpec m_resultSpec;
    vis_ResultInformation m_resultInformation;
    Vint m_datasetIndex = -1;
    vsy::string m_globalNameId = "";

  public:
    PluginResultInfo(Vint resultId);
    vis_ResultInformation&
    getResultInformation();
    const vis_ResultInformation&
    getResultInformation() const;
    const cdphl::ResultSpec&
    getResultSpec() const;
    const vsy::string&
    getDatasetName() const;
    void
    setResultSpec(const cdphl::ResultSpec& resultSpec);
    void
    setDatasetIndex(Vint datasetIndex);
    void
    setGlobalNameId(const vsy::string& globalNameId);
    Vint
    getResultId() const;
};

class PluginMetadata {
  private:
    std::vector<cdphl::InitOption> m_initOptions;
    std::vector<PluginResultInfo> m_pluginResultInfos;
    vsy::string m_providerId = "";
    std::shared_ptr<cdphl::Geometry> m_currentGeometry = nullptr;
    vsy::map<vsy::string, Vint> m_datasetNameToResultIndex;

  public:
    void
    setProviderId(const vsy::string& providerId);
    const vsy::string&
    getProviderId() const;
    std::shared_ptr<cdphl::Geometry>
    getCurrentGeometry();

    void
    buildResultsInformation(CDPDataProvider* m_provider, const cdphl::MetaData& m_metaData, AdapaterLogger* logger);
    size_t
    getTotalEntityCount(CDPDataProvider* m_provider, Vint entity, Vint subEntity, size_t geometryIndex, Vint stateId,
                        cdphl::Geometry* currentGeometry, Vint geometryInstanceID, AdapaterLogger* logger) const;
    size_t
    getResultCount() const;
    const vis_ResultInformation&
    getResultInfo(Vint resultIndex) const;
    const PluginResultInfo&
    getPluginResultInfo(Vint resultIndex) const;
    void
    setResultIdentifier(Vint resultIndex, Vint resultDatasetIndex, const vsy::string& globalNameId);
    Vint
    isResult(const vsy::string& globalNameId) const;
    Vint
    getResultIndex(const vsy::string& globalNameId) const;
    void
    clear();
    Vint
    getGeometryInstanceID(const cdphl::MetaData& m_metaData, const cdphl::StateInfo& cdpStateInfo, size_t geometryIndex);
};

#endif
