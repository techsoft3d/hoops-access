#ifndef THIRD_PARTY_FUNCTION_WRAPPER_H
#define THIRD_PARTY_FUNCTION_WRAPPER_H

#include <string>
#include <memory>
#include "sam/base/dynamicLibraryLoader.h"
#include "sam/vdm/libraries/samcef/dynamicLoadingWrapperLibrary/libsamcef_wrapper.h"

class ThirdPartyFunctionWrapper {
  private:
    std::unique_ptr<DynamicLibraryLoader> libLoader; /* Loader to manage the dynamic library */
    bool isValid = false;                            /* Validity flag*/
    std::string errorMessage;                        /* To store the error message*/

  public:
    ThirdPartyFunctionWrapper(const std::string& libraryName = "")
    {
#ifdef CEE_SAM_INTERFACE_DYNAMIC_LOADING
        try {
            /* Attempt to create the library loader for dynamic loading*/
            libLoader = std::make_unique<DynamicLibraryLoader>(libraryName);
            if (!libLoader->libraryHandle) {
                throw std::runtime_error(" Unable to load the " + libraryName);
            }

            /* Load the functions dynamically at runtime*/
            loadFunctions();

            isValid = true;
        }
        catch (const std::exception& e) {
            /* Store the error message in the member*/
            errorMessage = e.what();
            isValid = false;
        }
#else
        /*Use dynamically linked functions if not using dynamic loading.*/
        useLinkedFunctions();
        isValid = true;
#endif
    }

    bool
    isValidObject() const
    {
        return isValid;
    }

    const std::string&
    getErrorMessage() const
    {
        return errorMessage;
    }

    Samres_api* (*createThirdPartyClassInstanceFunc)() = nullptr;

    void (*deleteThirdPartyClassInstanceFunc)(Samres_api*&) = nullptr;

    bool (*SetDebugFunc)(Samres_api*&, const bool&) = nullptr;

    bool (*InitFunc)(Samres_api*&, const std::string&, const std::string&, const std::string&, const std::string&, const INTEGER&,
                     INTEGER*, INTEGER*) = nullptr;

    bool (*setSamEnvFunc)(Samres_api*&, const std::string&, const std::string&) = nullptr;

    bool (*initChronoFunc)(Samres_api*&) = nullptr;

    bool (*openFileFunc)(Samres_api*&, const std::string&, INTEGER*) = nullptr;

    bool (*closeFileFunc)(Samres_api*&, const std::string&, INTEGER*) = nullptr;

    void (*getSamEnvFunc)(Samres_api*&, const std::string&, std::string&) = nullptr;

    bool (*getSamcefVersionFunc)(Samres_api*&, const std::string&, INTEGER*, INTEGER*, INTEGER*) = nullptr;

    bool (*requestNumberOfResultsFunc)(Samres_api*&, INTEGER&, INTEGER*) = nullptr;

    bool (*requestResultInfosFunc)(Samres_api*&, const INTEGER& iResultIndex, INTEGER& oNbrRef, std::string& oTxtShort,
                                   std::string& oTxtFull, std::string& oTxtReq, INTEGER& oIcode, INTEGER& oItypVi,
                                   INTEGER& oSupport, INTEGER& oResDim, INTEGER& oAxes, INTEGER& oComposite, INTEGER& oComplex,
                                   INTEGER& oResNdim, std::string& oPhysDim, INTEGER* oTest) = nullptr;

    bool (*requestUnitCoefficientFunc)(Samres_api*&, const std::string&, double&, bool&, INTEGER*) = nullptr;

    bool (*requestUnitTemperatureFunc)(Samres_api*&, INTEGER&, bool&, INTEGER*) = nullptr;

    bool (*requestModelFunc)(Samres_api*&, const std::string&, double*&, INTEGER&, INTEGER*) = nullptr;

    bool (*requestModelTextFunc)(Samres_api*&, const std::string&, std::string&, INTEGER*) = nullptr;

    bool (*requestElementInfoFunc)(Samres_api*&, const std::string&, double*&, INTARG*&, INTEGER&, INTEGER*) = nullptr;

    bool (*requestStructureInfoFunc)(Samres_api*&, const std::string&, double*&, INTEGER&, INTEGER*) = nullptr;

    bool (*requestSuperElementTypeFunc)(Samres_api*&, INTEGER*&, INTEGER*&, INTEGER&, INTEGER*) = nullptr;

    void (*requestSuperElementNxnIdFunc)(Samres_api*&, const INTEGER&, INTEGER&, INTEGER*) = nullptr;

    void (*requestUsedSuperElementTextFunc)(Samres_api*&, const std::string&, const INTEGER&, std::string&, INTEGER*) = nullptr;

    bool (*requestBeamElementAxesFunc)(Samres_api*&, double*&, double*&, double*&, INTARG*&, INTEGER&, INTEGER*) = nullptr;
    bool (*requestElementMaterialAxesFunc)(Samres_api*&, double*&, INTARG*&, INTARG*&, INTARG*&, INTEGER&, INTEGER*) = nullptr;
    bool (*requestNodeFramesFunc)(Samres_api*&, INTEGER*&, INTEGER*&, INTEGER&, INTEGER*) = nullptr;
    bool (*requestGroupNameFunc)(Samres_api*&, const INTEGER&, std::string&, INTEGER*) = nullptr;
    bool (*requestFramesFunc)(Samres_api*&, double*&, double*&, double*&, double*&, INTEGER*&, INTEGER*&, INTEGER&,
                              INTEGER*) = nullptr;

    bool (*endFunc)(Samres_api*&, INTEGER*, INTEGER*, INTEGER*) = nullptr;

    bool (*requestResultFunc)(Samres_api*&, const std::string&, const std::string&, double*&, double*&, INTARG*&, INTEGER&,
                              INTEGER&, INTEGER&, INTEGER&, std::string&, std::string&, INTEGER*) = nullptr;

    bool (*requestReferenceInfosFunc)(Samres_api*&, const INTEGER&, const INTEGER&, std::string&, std::string&, std::string&,
                                      INTARG*&, INTEGER&, INTEGER&, INTEGER*) = nullptr;

    bool (*requestUsedSuperElementTransformationFunc)(Samres_api*&, const INTEGER&, double*&, INTEGER&, INTEGER*) = nullptr;

    bool (*requestElementAxesFunc)(Samres_api*&, double*&, INTARG*&, INTARG*&, INTEGER&, INTEGER*) = nullptr;

    bool (*requestResultSizeAndLocFunc)(Samres_api*&, const std::string&, const std::string&, INTARG*&, INTEGER&, INTEGER&,
                                        INTEGER&, std::string&, INTEGER*) = nullptr;

    bool (*requestReferenceInfosAndSubcaseIdFunc)(Samres_api*&, const INTEGER&, const INTEGER&, std::string&, std::string&,
                                                  std::string&, INTARG*&, INTEGER&, INTEGER&, INTEGER&, INTEGER*) = nullptr;

    void (*requestResultIsLocVariableFunc)(Samres_api*&, const std::string&, const std::string&, INTEGER&, INTEGER*) = nullptr;

    bool (*requestResultSizeFunc)(Samres_api*&, const std::string&, const std::string&, INTEGER&, INTEGER&, INTEGER*) = nullptr;

    bool (*getFileTimeStampFunc)(Samres_api*&, const std::string&, INTEGER&) = nullptr;
    bool (*sendProgressLogFunc)(Samres_api*&, const int&, const std::string&) = nullptr;
    bool (*requestErrorContextFunc)(Samres_api*&, INTEGER*, std::string&) = nullptr;
    bool (*sendDebugLogMessageFunc)(Samres_api*&, const std::string&) = nullptr;

#ifdef CEE_SAM_INTERFACE_DYNAMIC_LOADING
    void
    loadFunctions()
    {
        createThirdPartyClassInstanceFunc = libLoader->loadFunction<Samres_api* (*)()>("createThirdPartyClassInstance");
        deleteThirdPartyClassInstanceFunc = libLoader->loadFunction<void (*)(Samres_api*&)>("deleteThirdPartyClassInstance");

        SetDebugFunc = libLoader->loadFunction<bool (*)(Samres_api*&, const bool&)>("setDebug");

        InitFunc = libLoader->loadFunction<bool (*)(Samres_api*&, const std::string&, const std::string&, const std::string&,
                                                    const std::string&, const INTEGER&, INTEGER*, INTEGER*)>("Init");
        setSamEnvFunc = libLoader->loadFunction<bool (*)(Samres_api*&, const std::string&, const std::string&)>("setSamEnv");
        initChronoFunc = libLoader->loadFunction<bool (*)(Samres_api*&)>("initChrono");
        openFileFunc = libLoader->loadFunction<bool (*)(Samres_api*&, const std::string&, INTEGER*)>("openFile");
        closeFileFunc = libLoader->loadFunction<bool (*)(Samres_api*&, const std::string&, INTEGER*)>("closeFile");
        getSamEnvFunc = libLoader->loadFunction<void (*)(Samres_api*&, const std::string&, std::string&)>("getSamEnv");
        getSamcefVersionFunc =
        libLoader->loadFunction<bool (*)(Samres_api*&, const std::string&, INTEGER*, INTEGER*, INTEGER*)>("getSamcefVersion");
        requestNumberOfResultsFunc =
        libLoader->loadFunction<bool (*)(Samres_api*&, INTEGER&, INTEGER*)>("requestNumberOfResults");

        requestResultInfosFunc =
        libLoader
        ->loadFunction<bool (*)(Samres_api*&, const INTEGER&, INTEGER&, std::string&, std::string&, std::string&, INTEGER&,
                                INTEGER&, INTEGER&, INTEGER&, INTEGER&, INTEGER&, INTEGER&, INTEGER&, std::string&, INTEGER*)>(
        "requestResultInfos");

        requestUnitCoefficientFunc =
        libLoader->loadFunction<bool (*)(Samres_api*&, const std::string&, double&, bool&, INTEGER*)>("requestUnitCoefficient");
        requestUnitTemperatureFunc =
        libLoader->loadFunction<bool (*)(Samres_api*&, INTEGER&, bool&, INTEGER*)>("requestUnitTemperature");
        requestModelFunc =
        libLoader->loadFunction<bool (*)(Samres_api*&, const std::string&, double*&, INTEGER&, INTEGER*)>("requestModel");
        requestModelTextFunc =
        libLoader->loadFunction<bool (*)(Samres_api*&, const std::string&, std::string&, INTEGER*)>("requestModelText");
        requestElementInfoFunc =
        libLoader->loadFunction<bool (*)(Samres_api*&, const std::string&, double*&, INTARG*&, INTEGER&, INTEGER*)>(
        "requestElementInfo");
        requestStructureInfoFunc =
        libLoader->loadFunction<bool (*)(Samres_api*&, const std::string&, double*&, INTEGER&, INTEGER*)>("requestStructureInfo");
        requestSuperElementTypeFunc =
        libLoader->loadFunction<bool (*)(Samres_api*&, INTEGER*&, INTEGER*&, INTEGER&, INTEGER*)>("requestSuperElementType");
        requestSuperElementNxnIdFunc =
        libLoader->loadFunction<void (*)(Samres_api*&, const INTEGER&, INTEGER&, INTEGER*)>("requestSuperElementNxnId");
        requestUsedSuperElementTextFunc =
        libLoader->loadFunction<void (*)(Samres_api*&, const std::string&, const INTEGER&, std::string&, INTEGER*)>(
        "requestUsedSuperElementText");

        requestBeamElementAxesFunc =
        libLoader->loadFunction<bool (*)(Samres_api*&, double*&, double*&, double*&, INTARG*&, INTEGER&, INTEGER*)>(
        "requestBeamElementAxes");
        requestElementMaterialAxesFunc =
        libLoader->loadFunction<bool (*)(Samres_api*&, double*&, INTARG*&, INTARG*&, INTARG*&, INTEGER&, INTEGER*)>(
        "requestElementMaterialAxes");
        requestNodeFramesFunc =
        libLoader->loadFunction<bool (*)(Samres_api*&, INTEGER*&, INTEGER*&, INTEGER&, INTEGER*)>("requestNodeFrames");
        requestGroupNameFunc =
        libLoader->loadFunction<bool (*)(Samres_api*&, const INTEGER&, std::string&, INTEGER*)>("requestGroupName");
        requestFramesFunc =
        libLoader
        ->loadFunction<bool (*)(Samres_api*&, double*&, double*&, double*&, double*&, INTEGER*&, INTEGER*&, INTEGER&, INTEGER*)>(
        "requestFrames");

        endFunc = libLoader->loadFunction<bool (*)(Samres_api*&, INTEGER*, INTEGER*, INTEGER*)>("endInterface");

        requestResultFunc =
        libLoader->loadFunction<bool (*)(Samres_api*&, const std::string&, const std::string&, double*&, double*&, INTARG*&,
                                         INTEGER&, INTEGER&, INTEGER&, INTEGER&, std::string&, std::string&, INTEGER*)>(
        "requestResult");

        requestReferenceInfosFunc =
        libLoader->loadFunction<bool (*)(Samres_api*&, const INTEGER&, const INTEGER&, std::string&, std::string&, std::string&,
                                         INTARG*&, INTEGER&, INTEGER&, INTEGER*)>("requestReferenceInfos");

        requestUsedSuperElementTransformationFunc =
        libLoader->loadFunction<bool (*)(Samres_api*&, const INTEGER&, double*&, INTEGER&, INTEGER*)>(
        "requestUsedSuperElementTransformation");
        requestElementAxesFunc =
        libLoader->loadFunction<bool (*)(Samres_api*&, double*&, INTARG*&, INTARG*&, INTEGER&, INTEGER*)>("requestElementAxes");
        requestResultSizeAndLocFunc =
        libLoader->loadFunction<bool (*)(Samres_api*&, const std::string&, const std::string&, INTARG*&, INTEGER&, INTEGER&,
                                         INTEGER&, std::string&, INTEGER*)>("requestResultSizeAndLoc");
        requestReferenceInfosAndSubcaseIdFunc =
        libLoader->loadFunction<bool (*)(Samres_api*&, const INTEGER&, const INTEGER&, std::string&, std::string&, std::string&,
                                         INTARG*&, INTEGER&, INTEGER&, INTEGER&, INTEGER*)>("requestReferenceInfosAndSubcaseId");
        requestResultIsLocVariableFunc =
        libLoader->loadFunction<void (*)(Samres_api*&, const std::string&, const std::string&, INTEGER&, INTEGER*)>(
        "requestResultIsLocVariable");
        requestResultSizeFunc =
        libLoader->loadFunction<bool (*)(Samres_api*&, const std::string&, const std::string&, INTEGER&, INTEGER&, INTEGER*)>(
        "requestResultSize");

        getFileTimeStampFunc = libLoader->loadFunction<bool (*)(Samres_api*&, const std::string&, INTEGER&)>("getFileTimeStamp");
        sendProgressLogFunc = libLoader->loadFunction<bool (*)(Samres_api*&, const int&, const std::string&)>("sendProgressLog");
        requestErrorContextFunc = libLoader->loadFunction<bool (*)(Samres_api*&, INTEGER*, std::string&)>("requestErrorContext");
        sendDebugLogMessageFunc = libLoader->loadFunction<bool (*)(Samres_api*&, const std::string&)>("sendDebugLogMessage");
    }
#else
    void
    useLinkedFunctions()
    {
        /* Use statically linked functions directly (ensure these are linked at compile-time).*/
        createThirdPartyClassInstanceFunc = createThirdPartyClassInstance;
        deleteThirdPartyClassInstanceFunc = deleteThirdPartyClassInstance;
        SetDebugFunc = setDebug;
        InitFunc = Init;
        setSamEnvFunc = setSamEnv;
        initChronoFunc = initChrono;
        openFileFunc = openFile;
        closeFileFunc = closeFile;
        getSamEnvFunc = getSamEnv;
        getSamcefVersionFunc = getSamcefVersion;
        requestNumberOfResultsFunc = requestNumberOfResults;
        requestResultInfosFunc = requestResultInfos;
        requestUnitCoefficientFunc = requestUnitCoefficient;
        requestUnitTemperatureFunc = requestUnitTemperature;
        requestModelFunc = requestModel;
        requestModelTextFunc = requestModelText;
        requestElementInfoFunc = requestElementInfo;
        requestStructureInfoFunc = requestStructureInfo;
        requestSuperElementTypeFunc = requestSuperElementType;
        requestSuperElementNxnIdFunc = requestSuperElementNxnId;
        requestUsedSuperElementTextFunc = requestUsedSuperElementText;
        requestBeamElementAxesFunc = requestBeamElementAxes;
        requestElementMaterialAxesFunc = requestElementMaterialAxes;
        requestNodeFramesFunc = requestNodeFrames;
        requestGroupNameFunc = requestGroupName;
        requestFramesFunc = requestFrames;
        endFunc = endInterface;
        requestResultFunc = requestResult;
        requestReferenceInfosFunc = requestReferenceInfos;
        requestUsedSuperElementTransformationFunc = requestUsedSuperElementTransformation;
        requestElementAxesFunc = requestElementAxes;
        requestResultSizeAndLocFunc = requestResultSizeAndLoc;
        requestReferenceInfosAndSubcaseIdFunc = requestReferenceInfosAndSubcaseId;
        requestResultIsLocVariableFunc = requestResultIsLocVariable;
        requestResultSizeFunc = requestResultSize;
        getFileTimeStampFunc = getFileTimeStamp;
        sendProgressLogFunc = sendProgressLog;
        requestErrorContextFunc = requestErrorContext;
        sendDebugLogMessageFunc = sendDebugLogMessage;
    }
#endif
};

#endif