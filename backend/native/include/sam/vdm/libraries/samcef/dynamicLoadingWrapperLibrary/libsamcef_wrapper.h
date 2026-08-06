#ifndef LIBSAMCEF_WRAPPER_H
#define LIBSAMCEF_WRAPPER_H
#include "Samres_api.h"

#if defined(_WIN32) || defined(_WIN64)
#define SAMCEF_WRAPPER_API __declspec(dllexport)
#else
#define SAMCEF_WRAPPER_API
#endif

extern "C" {

SAMCEF_WRAPPER_API Samres_api*
createThirdPartyClassInstance();

SAMCEF_WRAPPER_API void
deleteThirdPartyClassInstance(Samres_api*&);

SAMCEF_WRAPPER_API bool
setDebug(Samres_api*&, const bool&);

SAMCEF_WRAPPER_API bool
Init(Samres_api*&, const std::string&, const std::string&, const std::string&, const std::string&, const INTEGER&, INTEGER*,
     INTEGER*);

SAMCEF_WRAPPER_API bool
setSamEnv(Samres_api*&, const std::string&, const std::string&);

SAMCEF_WRAPPER_API bool
initChrono(Samres_api*&);

SAMCEF_WRAPPER_API bool
openFile(Samres_api*& instance, const std::string& iPath, INTEGER* oTest);

SAMCEF_WRAPPER_API bool
closeFile(Samres_api*& instance, const std::string& iPath, INTEGER* oTest);

SAMCEF_WRAPPER_API void
getSamEnv(Samres_api*& instance, const std::string& iVarName, std::string& oVarValue);

SAMCEF_WRAPPER_API bool
getSamcefVersion(Samres_api*&, const std::string&, INTEGER*, INTEGER*, INTEGER*);

SAMCEF_WRAPPER_API bool
requestNumberOfResults(Samres_api*&, INTEGER&, INTEGER*);

SAMCEF_WRAPPER_API bool
requestResultInfos(Samres_api*&, const INTEGER&, INTEGER&, std::string&, std::string&, std::string&, INTEGER&, INTEGER&, INTEGER&,
                   INTEGER&, INTEGER&, INTEGER&, INTEGER&, INTEGER&, std::string&, INTEGER*);
SAMCEF_WRAPPER_API bool
requestUnitCoefficient(Samres_api*&, const std::string&, double&, bool&, INTEGER*);

SAMCEF_WRAPPER_API bool
requestUnitTemperature(Samres_api*&, INTEGER&, bool&, INTEGER*);

SAMCEF_WRAPPER_API bool
requestModel(Samres_api*&, const std::string&, double*&, INTEGER&, INTEGER*);

SAMCEF_WRAPPER_API bool
requestModelText(Samres_api*&, const std::string&, std::string&, INTEGER*);

SAMCEF_WRAPPER_API bool
requestElementInfo(Samres_api*&, const std::string&, double*&, INTARG*&, INTEGER&, INTEGER*);

SAMCEF_WRAPPER_API bool
requestStructureInfo(Samres_api*&, const std::string&, double*&, INTEGER&, INTEGER*);

SAMCEF_WRAPPER_API bool
requestSuperElementType(Samres_api*&, INTEGER*&, INTEGER*&, INTEGER&, INTEGER*);

SAMCEF_WRAPPER_API void
requestSuperElementNxnId(Samres_api*&, const INTEGER&, INTEGER&, INTEGER*);

SAMCEF_WRAPPER_API void
requestUsedSuperElementText(Samres_api*&, const std::string&, const INTEGER&, std::string&, INTEGER*);

SAMCEF_WRAPPER_API bool
requestBeamElementAxes(Samres_api*&, double*&, double*&, double*&, INTARG*&, INTEGER&, INTEGER*);

SAMCEF_WRAPPER_API bool
requestElementMaterialAxes(Samres_api*&, double*&, INTARG*&, INTARG*&, INTARG*&, INTEGER&, INTEGER*);

SAMCEF_WRAPPER_API bool
requestNodeFrames(Samres_api*&, INTEGER*&, INTEGER*&, INTEGER&, INTEGER*);

SAMCEF_WRAPPER_API bool
requestGroupName(Samres_api*&, const INTEGER&, std::string&, INTEGER*);

SAMCEF_WRAPPER_API bool
requestFrames(Samres_api*&, double*&, double*&, double*&, double*&, INTEGER*&, INTEGER*&, INTEGER&, INTEGER*);

SAMCEF_WRAPPER_API bool
endInterface(Samres_api*&, INTEGER*, INTEGER*, INTEGER*);

SAMCEF_WRAPPER_API bool
requestReferenceInfos(Samres_api*&, const INTEGER&, const INTEGER&, std::string&, std::string&, std::string&, INTARG*&, INTEGER&,
                      INTEGER&, INTEGER*);

SAMCEF_WRAPPER_API bool
requestResult(Samres_api*&, const std::string&, const std::string&, double*&, double*&, INTARG*&, INTEGER&, INTEGER&, INTEGER&,
              INTEGER&, std::string&, std::string&, INTEGER*);

SAMCEF_WRAPPER_API bool
requestResultSizeAndLoc(Samres_api*&, const std::string&, const std::string&, INTARG*&, INTEGER&, INTEGER&, INTEGER&,
                        std::string&, INTEGER*);

SAMCEF_WRAPPER_API bool
requestReferenceInfosAndSubcaseId(Samres_api*&, const INTEGER&, const INTEGER&, std::string&, std::string&, std::string&,
                                  INTARG*&, INTEGER&, INTEGER&, INTEGER&, INTEGER*);

SAMCEF_WRAPPER_API bool
requestResultSize(Samres_api*&, const std::string&, const std::string&, INTEGER&, INTEGER&, INTEGER*);

SAMCEF_WRAPPER_API bool
requestUsedSuperElementTransformation(Samres_api*&, const INTEGER&, double*&, INTEGER&, INTEGER*);

SAMCEF_WRAPPER_API bool
requestElementAxes(Samres_api*&, double*&, INTARG*&, INTARG*&, INTEGER&, INTEGER*);

SAMCEF_WRAPPER_API bool
sendProgressLog(Samres_api*&, const int&, const std::string&);

SAMCEF_WRAPPER_API bool
requestErrorContext(Samres_api*&, INTEGER*, std::string&);

SAMCEF_WRAPPER_API bool
getFileTimeStamp(Samres_api*&, const std::string&, INTEGER&);

SAMCEF_WRAPPER_API void
requestResultIsLocVariable(Samres_api*& instance, const std::string&, const std::string&, INTEGER&, INTEGER*);

SAMCEF_WRAPPER_API bool
sendDebugLogMessage(Samres_api*&, const std::string&);
}
#endif
