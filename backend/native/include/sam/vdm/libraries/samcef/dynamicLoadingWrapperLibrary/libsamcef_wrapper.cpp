#include "libsamcef_wrapper.h"

SAMCEF_WRAPPER_API Samres_api*
createThirdPartyClassInstance()
{
    return new Samres_api();
}

SAMCEF_WRAPPER_API void
deleteThirdPartyClassInstance(Samres_api*& instance)
{
    delete instance;
}

SAMCEF_WRAPPER_API bool
setDebug(Samres_api*& instance, const bool& debug)
{
    return instance->SetDebug(debug);
}

SAMCEF_WRAPPER_API bool
Init(Samres_api*& instance, const std::string& iModel, const std::string& iLCP, const std::string& iOutDir,
     const std::string& iSDBUse, const INTEGER& iZoneMb, INTEGER* oTest, INTEGER* oU6)
{
    return instance->Init(iModel, iLCP, iOutDir, iSDBUse, iZoneMb, oTest, oU6);
}

SAMCEF_WRAPPER_API bool
setSamEnv(Samres_api*& instance, const std::string& a1, const std::string& a2)
{
    return instance->SetSamEnv(a1, a2);
}

SAMCEF_WRAPPER_API bool
initChrono(Samres_api*& instance)
{
    return instance->InitChrono();
}

SAMCEF_WRAPPER_API bool
openFile(Samres_api*& instance, const std::string& iPath, INTEGER* oTest)
{
    return instance->OpenFile(iPath, oTest);
}

SAMCEF_WRAPPER_API bool
closeFile(Samres_api*& instance, const std::string& iPath, INTEGER* oTest)
{
    return instance->CloseFile(iPath, oTest);
}

SAMCEF_WRAPPER_API void
getSamEnv(Samres_api*& instance, const std::string& iVarName, std::string& oVarValue)
{
    instance->GetSamEnv(iVarName, oVarValue);
}

SAMCEF_WRAPPER_API bool
getSamcefVersion(Samres_api*& instance, const std::string& iPath, INTEGER* oVersion, INTEGER* oRelease, INTEGER* oDash)
{
    return instance->GetSamcefVersion(iPath, oVersion, oRelease, oDash);
}

SAMCEF_WRAPPER_API bool
requestNumberOfResults(Samres_api*& instance, INTEGER& oNbrRes, INTEGER* oTest)
{
    return instance->RequestNumberOfResults(oNbrRes, oTest);
}

SAMCEF_WRAPPER_API bool
requestResultInfos(Samres_api*& instance, const INTEGER& iResultIndex, INTEGER& oNbrRef, std::string& oTxtShort,
                   std::string& oTxtFull, std::string& oTxtReq, INTEGER& oIcode, INTEGER& oItypVi, INTEGER& oSupport,
                   INTEGER& oResDim, INTEGER& oAxes, INTEGER& oComposite, INTEGER& oComplex, INTEGER& oResNdim,
                   std::string& oPhysDim, INTEGER* oTest)
{
    return instance->RequestResultInfos(iResultIndex, oNbrRef, oTxtShort, oTxtFull, oTxtReq, oIcode, oItypVi, oSupport, oResDim,
                                        oAxes, oComposite, oComplex, oResNdim, oPhysDim, oTest);
}

SAMCEF_WRAPPER_API bool
requestUnitCoefficient(Samres_api*& instance, const std::string& iUnitType, double& oUnitCoefficient, bool& oIsKnown,
                       INTEGER* oTest)
{
    return instance->RequestUnitCoefficient(iUnitType, oUnitCoefficient, oIsKnown, oTest);
}

SAMCEF_WRAPPER_API bool
requestUnitTemperature(Samres_api*& instance, INTEGER& oUnitTemperature, bool& oIsKnown, INTEGER* oTest)
{
    return instance->RequestUnitTemperature(oUnitTemperature, oIsKnown, oTest);
}

SAMCEF_WRAPPER_API bool
requestModel(Samres_api*& instance, const std::string& iModelType, double*& oModel, INTEGER& oNbVal, INTEGER* oTest)
{
    return instance->RequestModel(iModelType, oModel, oNbVal, oTest);
}

SAMCEF_WRAPPER_API bool
requestModelText(Samres_api*& instance, const std::string& iModelInfo, std::string& oText, INTEGER* oTest)
{
    return instance->RequestModelText(iModelInfo, oText, oTest);
}

SAMCEF_WRAPPER_API bool
requestElementInfo(Samres_api*& instance, const std::string& iElementInfo, double*& oInfo, INTARG*& oElements, INTEGER& oNbVal,
                   INTEGER* oTest)
{
    return instance->RequestElementInfo(iElementInfo, oInfo, oElements, oNbVal, oTest);
}

SAMCEF_WRAPPER_API bool
requestStructureInfo(Samres_api*& instance, const std::string& iStructureInfo, double*& oInfo, INTEGER& oNbVal, INTEGER* oTest)
{
    return instance->RequestStructureInfo(iStructureInfo, oInfo, oNbVal, oTest);
}

SAMCEF_WRAPPER_API bool
requestSuperElementType(Samres_api*& instance, INTEGER*& oSEIds, INTEGER*& oSEType, INTEGER& oNbSE, INTEGER* oTest)
{
    return instance->RequestSuperElementType(oSEIds, oSEType, oNbSE, oTest);
}

SAMCEF_WRAPPER_API void
requestSuperElementNxnId(Samres_api*& instance, const INTEGER& iSeId, INTEGER& oSENxnId, INTEGER* oTest)
{
    instance->RequestSuperElementNxnId(iSeId, oSENxnId, oTest);
}

SAMCEF_WRAPPER_API void
requestUsedSuperElementText(Samres_api*& instance, const std::string& iSEInfo, const INTEGER& iSeId, std::string& oSEInfo,
                            INTEGER* oTest)
{
    instance->RequestUsedSuperElementText(iSEInfo, iSeId, oSEInfo, oTest);
}

SAMCEF_WRAPPER_API bool
requestBeamElementAxes(Samres_api*& instance, double*& oBeamOrientationNode1, double*& oBeamOrientationNode2,
                       double*& oBeamOrientationNode3, INTARG*& oBeamElements, INTEGER& oNbVal, INTEGER* oTest)
{
    return instance->RequestBeamElementAxes(oBeamOrientationNode1, oBeamOrientationNode2, oBeamOrientationNode3, oBeamElements,
                                            oNbVal, oTest);
}

SAMCEF_WRAPPER_API bool
requestElementMaterialAxes(Samres_api*& instance, double*& oElementsRodrigues, INTARG*& oElementsAxes,
                           INTARG*& oElementsMaterialAxes, INTARG*& oElements, INTEGER& oNbVal, INTEGER* oTest)
{
    return instance->RequestElementMaterialAxes(oElementsRodrigues, oElementsAxes, oElementsMaterialAxes, oElements, oNbVal,
                                                oTest);
}

SAMCEF_WRAPPER_API bool
requestNodeFrames(Samres_api*& instance, INTEGER*& oFrameNums, INTEGER*& oNodes, INTEGER& oNbVal, INTEGER* oTest)
{
    return instance->RequestNodeFrames(oFrameNums, oNodes, oNbVal, oTest);
}

SAMCEF_WRAPPER_API bool
requestGroupName(Samres_api*& instance, const INTEGER& iGroup, std::string& oGrName, INTEGER* oTest)
{
    return instance->RequestGroupName(iGroup, oGrName, oTest);
}

SAMCEF_WRAPPER_API bool
endInterface(Samres_api*& instance, INTEGER* oTest, INTEGER* oNbErr, INTEGER* oNbWarn)
{
    return instance->End(oTest, oNbErr, oNbWarn);
}

SAMCEF_WRAPPER_API bool
requestReferenceInfos(Samres_api*& instance, const INTEGER& iResultIndex, const INTEGER& iReferenceIndex, std::string& oTxtShort,
                      std::string& oTxtFull, std::string& oTxtReq, INTARG*& oRefVec, INTEGER& oLRefVec, INTEGER& oRefDim,
                      INTEGER* oTest)
{
    return instance->RequestReferenceInfos(iResultIndex, iReferenceIndex, oTxtShort, oTxtFull, oTxtReq, oRefVec, oLRefVec,
                                           oRefDim, oTest);
}

SAMCEF_WRAPPER_API bool
requestResult(Samres_api*& instance, const std::string& iResultType, const std::string& iReference, double*& oResults,
              double*& oReferences, INTARG*& oLocations, INTEGER& oNbVal, INTEGER& oNbRef, INTEGER& oNbDimRef, INTEGER& oNbDimLoc,
              std::string& oRefMsk, std::string& oLocMsk, INTEGER* oTest)
{
    return instance->RequestResult(iResultType, iReference, oResults, oReferences, oLocations, oNbVal, oNbRef, oNbDimRef,
                                   oNbDimLoc, oRefMsk, oLocMsk, oTest);
}

SAMCEF_WRAPPER_API bool
requestUsedSuperElementTransformation(Samres_api*& instance, const INTEGER& iSeId, double*& oTransformation, INTEGER& oN16,
                                      INTEGER* oTest)
{
    return instance->RequestUsedSuperElementTransformation(iSeId, oTransformation, oN16, oTest);
}

SAMCEF_WRAPPER_API bool
requestResultSizeAndLoc(Samres_api*& instance, const std::string& iResultType, const std::string& iReference, INTARG*& oLocations,
                        INTEGER& oNbVal, INTEGER& oNbRef, INTEGER& oNbDimLoc, std::string& oLocMsk, INTEGER* oTest)
{
    return instance->RequestResultSizeAndLoc(iResultType, iReference, oLocations, oNbVal, oNbRef, oNbDimLoc, oLocMsk, oTest);
}

SAMCEF_WRAPPER_API bool
requestFrames(Samres_api*& instance, double*& oFrameOrigins, double*& oFrameAxis1, double*& oFrameAxis2, double*& oFrameAxis3,
              INTEGER*& oFrameTypes, INTEGER*& oFrameNums, INTEGER& oNbFrames, INTEGER* oTest)
{
    return instance->RequestFrames(oFrameOrigins, oFrameAxis1, oFrameAxis2, oFrameAxis3, oFrameTypes, oFrameNums, oNbFrames,
                                   oTest);
}

SAMCEF_WRAPPER_API bool
requestReferenceInfosAndSubcaseId(Samres_api*& instance, const INTEGER& iResultIndex, const INTEGER& iReferenceIndex,
                                  std::string& oTxtShort, std::string& oTxtFull, std::string& oTxtReq, INTARG*& oRefVec,
                                  INTEGER& oLRefVec, INTEGER& oRefDim, INTEGER& oSubcaseId, INTEGER* oTest)
{
    return instance->RequestReferenceInfosAndSubcaseId(iResultIndex, iReferenceIndex, oTxtShort, oTxtFull, oTxtReq, oRefVec,
                                                       oLRefVec, oRefDim, oSubcaseId, oTest);
}

SAMCEF_WRAPPER_API bool
requestResultSize(Samres_api*& instance, const std::string& iResultType, const std::string& iReference, INTEGER& oNbVal,
                  INTEGER& oNbRef, INTEGER* oTest)
{
    return instance->RequestResultSize(iResultType, iReference, oNbVal, oNbRef, oTest);
}

SAMCEF_WRAPPER_API bool
requestElementAxes(Samres_api*& instance, double*& oElementsRodrigues, INTARG*& oElementsAxes, INTARG*& oElements,
                   INTEGER& oNbVal, INTEGER* oTest)
{
    return instance->RequestElementAxes(oElementsRodrigues, oElementsAxes, oElements, oNbVal, oTest);
}

SAMCEF_WRAPPER_API bool
sendProgressLog(Samres_api*& instance, const int& iSmgKey, const std::string& iSmgMessage)
{
    return instance->SendProgressLog(iSmgKey, iSmgMessage);
}

SAMCEF_WRAPPER_API bool
requestErrorContext(Samres_api*& instance, INTEGER* oIerr, std::string& oErrorContext)
{
    return instance->RequestErrorContext(oIerr, oErrorContext);
}

SAMCEF_WRAPPER_API bool
getFileTimeStamp(Samres_api*& instance, const std::string& iString, INTEGER& oStamp)
{
    return instance->GetFileTimeStamp(iString, oStamp);
}

SAMCEF_WRAPPER_API void
requestResultIsLocVariable(Samres_api*& instance, const std::string& iResultType, const std::string& iReference,
                           INTEGER& oIsVAriable, INTEGER* oTest)
{
    instance->RequestResultIsLocVariable(iResultType, iReference, oIsVAriable, oTest);
}

SAMCEF_WRAPPER_API bool
sendDebugLogMessage(Samres_api*& instance, const std::string& iLogMessage)
{
    return instance->SendDebugLogMessage(iLogMessage);
}