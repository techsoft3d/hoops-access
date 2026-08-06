/*
file       :  pluginadapter.h
description:  C++ brick towards plugin
Notes      :  This file depends on base and vis.
*/
#pragma once
#ifdef CEE_SAM_DATA_PROVIDER_FRAMEWORK
#include <memory> // std::unique_ptr
#include "sam/base/basedefs.h"
#include "sam/vdm/adapter.h"
#include "sam/vdm/plugins/pluginmetadata.h"
#include "sam/vis/visdefs.h"
#include "sam/vis/resultInformation.h"
#include "cdphlMetaData.h"
#include "cdphlInitOptions.h"

class CDPDataProvider;
namespace cdphl {
    class ElementGroup;
    class DataProviderFactory;
} // namespace cdphl

//----------------------------------------------------------------------------------------------
// This class reponsability is to ADAPT the plugin data into Global Modules data structure
// recognized by all the vis_Objects
//-----------------------------------------------------------------------------------------------
class PluginAdapter: public Adapter {
  public:
    // open/close

    PluginAdapter(Vchar* pathToPluginLibrary, Vint errorLevel,
                  AdapaterLogger::errorMode errorReporting = AdapaterLogger::errorMode::THROW_EXCEPTIONS);
    ~PluginAdapter();
    void
    open(const vsy::string& filename);
    void
    close();

    // getters
    Vobject*
    getObject(Vint objectType);
    vis_Connect*
    getMesh();
    Vint
    getResultCount() const;
    Vint
    getSectionInfoCount() const;
    Vint
    getSectionResultCount(Vint sectionIndex) const;
    const Vint*
    getSectionResultDatasetIndexes(Vint sectionIndex, Vint resultIndex) const;
    Vint
    getSectionResultDatasetIndexesCount(Vint sectionIndex, Vint resultIndex) const;
    void
    getResultInfo(Vint resultIndex, vis_ResultInformation* resultInformation) const;
    Vint
    isResult(const vsy::string& globalNameId);
    vsy::vector<vsy::string>
    getNotifications();
    Vint
    getErrorsFound();

    // setters
    void
    setResultIdentifier(Vint resultIndex, Vint resultDatasetIndex, const vsy::string& globalNameId);
    void
    setSectionIdentifier(Vint sectionIndex, const vsy::string& globalNameId);
    void
    setPluginManagerErrorLevel(Vint errorLevel);
    void
    setIntegerOption(const vsy::string& optionsNameId, const vsy::string& key, const vsy::string& description, int value);
    void
    setDoubleOption(const vsy::string& optionsNameId, const vsy::string& key, const vsy::string& description, double value);
    void
    setStringOption(const vsy::string& optionsNameId, const vsy::string& key, const vsy::string& description,
                    const vsy::string& value);

    // query
    Vobject*
    loadObject(Vint objectType);
    vis_Connect*
    loadMesh(Vint connectId = 1);
    void
    createResultInformation();
    void
    loadResult(const vsy::string& globalNameId, Vint* dataSize, Vdouble data[]);
    void
    loadDataset(const vsy::string& globalNameId, Vint datasetType, void* data);
    void
    getIntegerOption(const vsy::string& optionsNameId, const vsy::string& key, vsy::string& description, Vint& value);

  private:
    bool
    isEmpty() const;
    void
    populateFromElementGroup(const cdphl::ElementGroup& cdpElementGroup,
                             const vsy::map<Vint, Vint>& firstNodeIndexPerNodeGroupIndex,
                             const cdphl::ElementGroupInfo& elementGroupInfo);
    void
    loadResults(Vint resultIndex, Vint* allocatedDataSize, Vdouble data[]);

  private: // member variables
    std::unique_ptr<vis_Connect, void (*)(vis_Connect*)> m_connect;

    cdphl::MetaData m_metaData;
    CDPDataProvider* m_provider;
    cdphl::DataProviderFactory* m_providerFactory;
    vsy::map<vsy::string, cdphl::InitOptions> m_InitOptionsDictionary;

    // Storage of the metadata
    PluginMetadata m_pluginMetadata;
};

#endif
