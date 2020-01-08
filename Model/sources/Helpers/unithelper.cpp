#include "unithelper.h"

namespace QaraMunai {
namespace Model {
namespace Helpers {

// Constants
const double UnitHelper::GravityTable[];
const double UnitHelper::DarcyTable[];
const double UnitHelper::AtmosphericPressureTable[];
const double UnitHelper::DensityOfAirTable[];
const double UnitHelper::DensityOfWaterTable[];
const double UnitHelper::GasConstantTable[];

// General
int UnitHelper::GetUnitOptionsCount(int unitSrc, QMetaEnum &unitsEnum)
{
    int unitsCount = unitsEnum.keyCount();

    int count = 0;

    for(int i = 0; i < unitSrc; i++)
    {
        count += unitsCount - i - 1;
    }

    return count;
}

int UnitHelper::GetUnitOptionIndex(ProjectData::UnitType srcUnit, ProjectData::UnitType destUnit, QMetaEnum &unitsEnum, bool& inverse)
{
    int unitSrc = srcUnit;
    int unitDest = destUnit;

    if (unitSrc > unitDest)
    {
        inverse = true;

        int temp = unitSrc;

        unitSrc = unitDest;
        unitDest = temp;
    }

    int optionsCount = GetUnitOptionsCount(unitSrc, unitsEnum);

    return optionsCount + unitDest - unitSrc - 1;
}

// Pressure
const double UnitHelper::PressureTable[];

QVariant UnitHelper::ConvertPressure(ProjectData::UnitType srcUnit, ProjectData::UnitType destUnit, double value, QMetaEnum &unitsEnum)
{
    if (srcUnit == destUnit) return value;

    bool inverse = false;

    int index = GetUnitOptionIndex(srcUnit, destUnit, unitsEnum, inverse);

    int count = sizeof (UnitHelper::PressureTable) / sizeof(*UnitHelper::PressureTable);

    if(index >= count) return QVariant();

    double mult = UnitHelper::PressureTable[index];

    mult = inverse ? 1 / mult : mult;

    return mult * value;
}

// Length
const double UnitHelper::LengthTable[];

QVariant UnitHelper::ConvertLength(ProjectData::UnitType srcUnit, ProjectData::UnitType destUnit, double value, QMetaEnum &unitsEnum)
{
    if (srcUnit == destUnit) return value;

    bool inverse = false;

    int index = GetUnitOptionIndex(srcUnit, destUnit, unitsEnum, inverse);

    int count = sizeof (UnitHelper::LengthTable) / sizeof(*UnitHelper::LengthTable);

    if(index >= count) return QVariant();

    double mult = UnitHelper::LengthTable[index];

    mult = inverse ? 1 / mult : mult;

    return mult * value;
}

//Volume
const double UnitHelper::VolumeTable[];

QVariant UnitHelper::ConvertVolume(ProjectData::UnitType srcUnit, ProjectData::UnitType destUnit, double value, QMetaEnum &unitsEnum)
{
    if (srcUnit == destUnit) return value;

    bool inverse = false;

    int index = GetUnitOptionIndex(srcUnit, destUnit, unitsEnum, inverse);

    int count = sizeof (UnitHelper::VolumeTable) / sizeof(*UnitHelper::VolumeTable);

    if(index >= count) return QVariant();

    double mult = UnitHelper::VolumeTable[index];

    mult = inverse ? 1 / mult : mult;

    return mult * value;
}

// Mass
const double UnitHelper::MassTable[];

QVariant UnitHelper::ConvertMass(ProjectData::UnitType srcUnit, ProjectData::UnitType destUnit, double value, QMetaEnum &unitsEnum)
{
    if (srcUnit == destUnit) return value;

    bool inverse = false;

    int index = GetUnitOptionIndex(srcUnit, destUnit, unitsEnum, inverse);

    int count = sizeof (UnitHelper::MassTable) / sizeof(*UnitHelper::MassTable);

    if(index >= count) return QVariant();

    double mult = UnitHelper::MassTable[index];

    mult = inverse ? 1 / mult : mult;

    return mult * value;
}

// Density
const double UnitHelper::DensityTable[];

QVariant UnitHelper::ConvertDensity(ProjectData::UnitType srcUnit, ProjectData::UnitType destUnit, double value, QMetaEnum &unitsEnum)
{
    if (srcUnit == destUnit) return value;

    bool inverse = false;

    int index = GetUnitOptionIndex(srcUnit, destUnit, unitsEnum, inverse);

    int count = sizeof (UnitHelper::DensityTable) / sizeof(*UnitHelper::DensityTable);

    if(index >= count) return QVariant();

    double mult = UnitHelper::DensityTable[index];

    mult = inverse ? 1 / mult : mult;

    return mult * value;
}

// Gas-liquid ratio
const double UnitHelper::GLRTable[];

QVariant UnitHelper::ConvertGasLiquidRatio(ProjectData::UnitType srcUnit, ProjectData::UnitType destUnit, double value, QMetaEnum &unitsEnum)
{
    if (srcUnit == destUnit) return value;

    bool inverse = false;

    int index = GetUnitOptionIndex(srcUnit, destUnit, unitsEnum, inverse);

    int count = sizeof (UnitHelper::GLRTable) / sizeof(*UnitHelper::GLRTable);

    if(index >= count) return QVariant();

    double mult = UnitHelper::GLRTable[index];

    mult = inverse ? 1 / mult : mult;

    return mult * value;
}

// Temperatures
const double UnitHelper::TemperatureTable[];

QVariant UnitHelper::ConvertTemperature(ProjectData::UnitType srcUnit, ProjectData::UnitType destUnit, double value, QMetaEnum &unitsEnum)
{
    if (srcUnit == destUnit) return value;

    bool inverse = false;

    int index = GetUnitOptionIndex(srcUnit, destUnit, unitsEnum, inverse);

    int count = sizeof (UnitHelper::TemperatureTable) / sizeof(*UnitHelper::TemperatureTable);

    if(index >= count) return QVariant();

    double mult = UnitHelper::TemperatureTable[index];

    mult = inverse ? 1 / mult : mult;

    return mult * value;
}


}}}
