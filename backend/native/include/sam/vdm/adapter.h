/*********************************************************************
 *                                                                   *
 *                          DevTools 3.1.0                           *
 *                                                                   *
 *  These coded instructions, statements and computer programs       *
 *  contain unpublished proprietary information of Tech Soft 3D,     *
 *  and are protected by Federal copyright law.  They may not be     *
 *  disclosed to third parties or copied or duplicated in any form,  *
 *  in whole or in part, without the prior written consent of        *
 *  Tech Soft 3D.                                                    *
 *                                                                   *
 *                 Copyright (C) 2026, Tech Soft 3D                  *
 *                                                                   *
 *********************************************************************/
/*
file       :  adapter.h
description:  C++ brick towards plugins
Notes      :  This file depends on base and vis
*/
#pragma once

#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
#include "sam/vdm/adapterlogger.h"

struct vis_ResultInformation;

//----------------------------------------------------------------------------------------------
// This class responsibility is to ADAPT the data into Global Modules data structure
// recognized by all the vis_Objects
//-----------------------------------------------------------------------------------------------
class Adapter {
  public:
    // open/close
    virtual ~Adapter() = 0;
    virtual void
    open(const vsy::string& filename) = 0;
    virtual void
    close() = 0;

    // getters
    virtual Vobject*
    getObject(Vint objectType) = 0;
    virtual vis_Connect*
    getMesh() = 0;
    virtual Vint
    getResultCount() const = 0;
    virtual Vint
    getSectionInfoCount() const = 0;
    virtual Vint
    getSectionResultCount(Vint sectionIndex) const = 0;
    virtual const Vint*
    getSectionResultDatasetIndexes(Vint sectionIndex, Vint resultIndex) const = 0;
    virtual Vint
    getSectionResultDatasetIndexesCount(Vint sectionIndex, Vint resultIndex) const = 0;
    virtual void
    getResultInfo(Vint resultIndex, vis_ResultInformation* resultInformation) const = 0;
    virtual Vint
    isResult(const vsy::string& globalNameId) = 0;
    virtual vsy::vector<vsy::string>
    getNotifications() = 0;
    virtual Vint
    getErrorsFound() = 0;

    // setters
    virtual void
    setResultIdentifier(Vint resultIndex, Vint resultDatasetIndex, const vsy::string& globalNameId) = 0;
    virtual void
    setSectionIdentifier(Vint sectionIndex, const vsy::string& globalNameId) = 0;

    // publish the options
    virtual void
    setIntegerOption(const vsy::string& optionsNameId, const vsy::string& key, const vsy::string& description, int value) = 0;
    virtual void
    setDoubleOption(const vsy::string& optionsNameId, const vsy::string& key, const vsy::string& description, double value) = 0;
    virtual void
    setStringOption(const vsy::string& optionsNameId, const vsy::string& key, const vsy::string& description,
                    const vsy::string& value) = 0;

    // query
    virtual Vobject*
    loadObject(Vint objectType) = 0;
    virtual vis_Connect*
    loadMesh(Vint connectId = 1) = 0;
    virtual void
    createResultInformation() = 0;
    virtual void
    loadResult(const vsy::string& globalNameId, Vint* dataSize, Vdouble data[]) = 0;
    virtual void
    loadDataset(const vsy::string& globalNameId, Vint datasetType, void* data) = 0;
    virtual void
    getIntegerOption(const vsy::string& optionsNameId, const vsy::string& key, vsy::string& description, Vint& value) = 0;

  protected:
    Adapter(AdapaterLogger::errorMode errorReporting = AdapaterLogger::errorMode::THROW_EXCEPTIONS);

    AdapaterLogger m_logger;
};
