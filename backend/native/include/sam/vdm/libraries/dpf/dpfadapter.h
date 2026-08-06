/*
file       :  dpffacade.h
description:  C++ brick towards DPF Ansys
Notes      :  This file depends on base, vis and dpf.
*/
#pragma once
#ifdef VKI_LIBAPI_ANSYS_DPF

#include <string>
#include <memory> // std::unique_ptr
#include "sam/base/basedefs.h"
#include "sam/vdm/adapter.h"
#include "sam/vdm/libraries/dpf/dpfmetadata.h"
#include "sam/vis/visdefs.h"
#include "sam/vis/resultInformation.h"
#include "dpf_api.h"

class DpfModel;

//----------------------------------------------------------------------------------------------
// This class reponsability is to ADAPT the ansys::dpf data into Global Modules data structure
// recognized by all the vis_Objects
//-----------------------------------------------------------------------------------------------
class DPFAdapter: public Adapter {
  public:
    // open/close

    DPFAdapter(const vsy::string& pathToDPFsharedObject,
               AdapaterLogger::errorMode errorReporting = AdapaterLogger::errorMode::THROW_EXCEPTIONS);
    DPFAdapter(AdapaterLogger::errorMode errorReporting);
    ~DPFAdapter();
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

    // specific to DPFAdapter
    vsy::vector<vsy::string>
    setDefaultResultIdentifier();
    DPFMetaData const*
    getMetaData() const;

  private: // methods
    bool
    isEmpty() const;

    void
    checkDataTypeCompatibilityWithDPF();
    Vint
    getExpectedDataSizeWithOption(Vint elementIndex, Vint sectionCount, const DPFResultInfo& dpfResultInfo, bool optionFlag,
                                  ansys::dpf::Field& currentField);
    Vint
    getExpectedDataSize(Vint elementIndex, Vint sectionCount, const DPFResultInfo& dpfResultInfo,
                        ansys::dpf::Field& currentField);
    Vint
    getMaxDataSize(Vint elementIndex, Vint sectionCount, const DPFResultInfo& dpfResultInfo, ansys::dpf::Field& currentField);

    void
    loadNodalResult(const DPFResultSpec& resultSpec, Vint* allocatedDataSize, Vdouble data[]);
    void
    loadElementResult(const DPFResultSpec& resultSpec, Vdouble data[]);
    void
    loadSection(const vsy::string& globalNameId, Vint data[]);
    void
    loadThickness(const vsy::string& globalNameId, Vdouble data[]);

    const std::vector<DPFResultInfo*>&
    getSectionResults(Vint sectionIndex) const;

    bool
    extrapolateToMidNodes(const DPFResultInfo& dpfResultInfo) const;

    bool
    isFileVersionSupported();

  private: // member variables
    DPFMetaData m_metaData;
    DpfModelPtr m_model;
    bool m_debugMode = false;
    const Vint minimumMajorVersion = 18;
    const Vint minimumMinorVersion = 0;
};
#else
using DPFAdapter = void;
#endif
