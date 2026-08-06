#pragma once
#ifdef VKI_LIBAPI_ANSYS_DPF

#include <memory>
#include <string>
#include "dpf_api.h"
#include "sam/vis/visdefs.h"
#include "sam/base/stdcontainers.h"

typedef std::unique_ptr<vis_Connect, void (*)(vis_Connect*)> ConnectPtr;
typedef std::unique_ptr<vsy_HashTable, void (*)(vsy_HashTable*)> HashTablePtr;

//----------------------------------------------------------------------------------------------
// This class reponsability is encapsulate the mesh and structure
//-----------------------------------------------------------------------------------------------
class DpfModel {
  public:
    virtual ~DpfModel() {}
    // Create model from given file.
    DpfModel(const std::string& filePath);

    // Create model from given data sources.
    DpfModel(const ansys::dpf::DataSources& data_sources);

    // Meshed region for given timestep.
    ansys::dpf::MeshedRegion
    getMesh(int timestep = 0);

    // Retrieves the time/freq support to have access to the analysis domain
    ansys::dpf::TimeFreqSupport
    getTimeFreqSupport();

    // Retrieves the number of steps
    Vint
    getStepCount();

    // Retrieves result Info
    ansys::dpf::ResultInfo
    getResultInfo();

    // Retrieves Element types
    ansys::dpf::GenericDataContainer
    getElementTypesProvider();

    // Retrieves element type from the mesh provider
    ansys::dpf::PropertyField
    getElementTypesProperty();

    // Retrieves section from the mesh provider
    ansys::dpf::PropertyField
    getElementSectionsProperty();

    // Retrieves materials from the mesh provider
    ansys::dpf::PropertyField
    getElementMaterialsProperty();

    // Retrieves real constants from the mesh provider
    ansys::dpf::PropertyField
    getElementRealConstantsProperty();

    // Retrieves real element type ids from the mesh provider
    ansys::dpf::PropertyField
    getElementTypeIdsProperty();

    // Retrieves SC03 domain ids from the mesh provider
    ansys::dpf::PropertyField
    getSC03DomainIdsProperty();

    // Retrieves the real constants information
    ansys::dpf::Field
    getRealConstantInformation();

    // Closes the files that were kept open to retrieve data.
    void
    ReleaseHandles();

    // Retrieves The connect
    ConnectPtr&
    getConnect();

    // Retrieves The element sets
    HashTablePtr&
    getElementSets();

    // Retrieves The node sets
    HashTablePtr&
    getNodeSets();

    // Retrieves the stream provider
    const ansys::dpf::Operator&
    getStreamProvider() const;

    // Check if this is an apdl file
    bool
    isApdlFile() const;

    // Check if this is an h5dpf file
    bool
    isH5dpfFile() const;

  private:
    void
    init(const ansys::dpf::DataSources& data_sources);

    std::string m_dataSourceKey;
    ansys::dpf::Operator m_mesh_provider;
    ansys::dpf::Operator m_timefreq_support_provider;
    ansys::dpf::Operator m_stream_provider;
    ansys::dpf::Operator m_result_info_provider;
    ansys::dpf::Operator m_element_types_provider;
    ansys::dpf::Operator m_mesh_property_provider;
    ansys::dpf::Operator m_real_constant_provider;

    ConnectPtr m_connect;
    HashTablePtr m_elementSets;
    HashTablePtr m_nodeSets;

    // Retrieves property from the mesh provider
    ansys::dpf::PropertyField
    getMeshProperty(const std::string& propertyName);
};

#endif
