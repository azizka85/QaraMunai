#ifndef UNITHELPER_H
#define UNITHELPER_H

#include <qmetaobject.h>

#include <projectdata.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Project;

namespace QaraMunai {
namespace Model {
namespace Helpers {

class MODELSHARED_EXPORT UnitHelper
{
public:

    // Constants
    constexpr static double GravityTable[] = { 0.0000980665, 0.00694444, 0.000967841 };
    constexpr static double DarcyTable[] = { 0.00852702, 0.00112712, 3.6 };
    constexpr static double AtmosphericPressureTable[] = { 1.01325, 14.6959, 1.0 };
    constexpr static double DensityOfAirTable[] = { 1.2232, 0.076362, 0.0012232 };
    constexpr static double DensityOfWaterTable[] = { 999.014, 62.3664, 0.999014 };
    constexpr static double GasConstantTable[] { 0.083143, 10.732, 820.55776 };

    // General
    static int GetUnitOptionsCount(int unitSrc, QMetaEnum &unitsEnum);
    static int GetUnitOptionIndex(ProjectData::UnitType srcUnit, ProjectData::UnitType destUnit, QMetaEnum &unitsEnum, bool& inverse);

    // Pressure
    constexpr static double BarToPsi = 14.5038;
    constexpr static double BarToAtm = 0.986923;
    constexpr static double PsiToAtm = 0.068046;

    constexpr static double PressureTable[] = { BarToPsi, BarToAtm, PsiToAtm };

    static QVariant ConvertPressure(ProjectData::UnitType srcUnit, ProjectData::UnitType destUnit, double value, QMetaEnum &unitsEnum);

    // Length
    constexpr static double MeterToFoot = 3.28084;

    constexpr static double LengthTable[] = { MeterToFoot };

    static QVariant ConvertLength(ProjectData::UnitType srcUnit, ProjectData::UnitType destUnit, double value, QMetaEnum &unitsEnum);

    // Volume
    constexpr static double CmToCf = 35.31466;
    constexpr static double CmToBbl = 6.289811;
    constexpr static double CfToBbl = 0.1781076;

    constexpr static double VolumeTable[] = { CmToCf, CmToBbl, CfToBbl };

    static QVariant ConvertVolume(ProjectData::UnitType srcUnit, ProjectData::UnitType destUnit, double value, QMetaEnum &unitsEnum);

    // Mass
    constexpr static double KgToLb = 2.204623;

    constexpr static double MassTable[] = { KgToLb };

    static QVariant ConvertMass(ProjectData::UnitType srcUnit, ProjectData::UnitType destUnit, double value, QMetaEnum &unitsEnum);

    // Density
    constexpr static double DMToDF = 0.06242797;
    constexpr static double DMToDL = 1E-3;
    constexpr static double DFToDL = 0.01601846;

    constexpr static double DensityTable[] = { DMToDF, DMToDL, DFToDL };

    static QVariant ConvertDensity(ProjectData::UnitType srcUnit, ProjectData::UnitType destUnit, double value, QMetaEnum &unitsEnum);

    // Gas-liquid ratio
    constexpr static double GLRMToGLRF = 5.614583E-3;
    constexpr static double GLRMToGLRL = 1;
    constexpr static double GLRFToGLRL = 178.1076;

    constexpr static double GLRTable[] = { GLRMToGLRF, GLRMToGLRL, GLRFToGLRL };

    static QVariant ConvertGasLiquidRatio(ProjectData::UnitType srcUnit, ProjectData::UnitType destUnit, double value, QMetaEnum &unitsEnum);

    // Temperatures
    constexpr static double KToR = 0.55555555555555555555555555555556;

    constexpr static double TemperatureTable[] = { KToR };

    static QVariant ConvertTemperature(ProjectData::UnitType srcUnit, ProjectData::UnitType destUnit, double value, QMetaEnum &unitsEnum);
};

}}}

#endif // UNITHELPER_H
