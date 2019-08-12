#include "unithelper.h"

namespace QaraMunai {
namespace Model {
namespace Helpers {

const double UnitHelper::PressureTable[];

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

double UnitHelper::ConvertPressure(ProjectData::UnitType srcUnit, ProjectData::UnitType destUnit, double value, QMetaEnum &unitsEnum)
{
    if (srcUnit == destUnit) return value;

    bool inverse = false;

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

    int index = optionsCount + unitDest - unitSrc - 1;

    double mult = UnitHelper::PressureTable[index];

    mult = inverse ? 1 / mult : mult;

    return mult * value;
}

}}}
