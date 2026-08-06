#ifdef VKI_LIBAPI_ANSYS_DPF
#pragma once

#include "sam/base/basedefs.h"
#include "sam/base/stdcontainers.h"
#include "dpf_api_base.h"
#include "dpf_api.h"

// Vbyte contains an integer until 255. More than enough for this data
using Vbyte = Vuchar;

namespace dpfmappings {

    enum class dpfResultNames {
        none,
        displacement,
        force,
        temperature,
        energyStiffnessMatrix,
        volume,
        stress,
        elasticStrain,
        elasticStrainEqv,
        totalStrain,
        thermalDissipationEnergy,
        kineticEnergy,
        elementNodalForces,
        HeatFlux,
        temperatureGradient,
        acceleration,
        velocity,
        rotationalAcceleration,
        rotationalVelocity,
        structuralTemperature,
        hourglassEnergy,
        thermalStrains,
        thermalStrainsEqv,
        swellingStrains,
        plasticStrain,
        plasticStrainEqv,
        contactPenetration,
        contactGapDistance,
        contactSlidingDistance,
        contactStatus,
        contactFrictionStress,
        contactStress,
        contactPressure,
        nodalCreepStrain,
        nodalCreepStrainEqv,
        nodalStrain,
        nodalStrainEqv,
        nodalStress,
        creepStrain,
        nodalThermalStrain,
        nodalThermalStrainEqv,
        nodalPlasticStrain,
        nodalPlasticStrainEqv,
        nodalSwellingStrain,
        eulerAngle,
        eulerAnglePly,
        coordinates,
        initialCoordinates
        // This last item must be added to the obfuscation manual_symbols
    };

    class ElementTopology {
      public:
        ElementTopology() = default;
        ElementTopology(Vint shape, Vint maxi, Vint maxj, Vint maxk, Vint featype);
        Vint shape = SYS_SHAPEUNDEFINED;
        Vint maxi = -1;
        Vint maxj = -1;
        Vint maxk = -1;
        Vint featype = SYS_ELEM_UNDEFINED;
    };

    /*get the connect topology given its ansys::dpf::ElementDescriptor*/
    ElementTopology
    getConnectTopology(const ansys::dpf::ElementDescriptor& dpfElementDescriptor);

    /*get the analysis name given the ansys::dpf::analysis_type*/
    vsy::string
    getAnalysisName(const ansys::dpf::ResultInfo::analysis_type& dpfAnalysysType);

    /*get category*/
    Vint
    getCategory(const ansys::dpf::ResultInfo::analysis_type& dpfAnalysysType);

    /*get parent and child entities*/
    std::pair<Vint, Vint>
    getParentAndChildEntities(const ansys::dpf::Location& location);

    /*get result data type*/
    Vint
    getdataType(ansys::dpf::Dimensionality::ENature resultNature);

    /*get result Type given the dpf ansys result name*/
    Vint
    getResultType(dpfResultNames resultName);

    /*get result qualifiers given the dpf ansys result name*/
    vsy::vector<Vint>
    getResultQualifiers(dpfResultNames resultName);

    /*get section locations*/
    Vint
    getLayerPositions(ansys::dpf::eshellLayers dpfShellLayers);

    /*get result name*/
    dpfResultNames
    getDpfResultName(const vsy::string& resultName);

    /*get native name*/
    vsy::string
    getDpfNativeName(const dpfResultNames& dpfResultName);

} // namespace dpfmappings

#endif