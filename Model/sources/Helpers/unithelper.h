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

    constexpr static double BarToPsi = 14.5038;
    constexpr static double BarToAtm = 0.986923;
    constexpr static double PsiToAtm = 0.068046;

    constexpr static double PressureTable[] = { BarToPsi, BarToAtm, PsiToAtm };

    static int GetUnitOptionsCount(int unitSrc, QMetaEnum &unitsEnum);

    static double ConvertPressure(ProjectData::UnitType srcUnit, ProjectData::UnitType destUnit, double value, QMetaEnum &unitsEnum);
};

}}}

#endif // UNITHELPER_H
