#include "equalsdata.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

EQUALSData::EQUALSData()
{
    InitVariables();
}

QString EQUALSData::ArrayName()
{
    return arrayName;
}

double EQUALSData::Value()
{
    return value;
}

Box3D &EQUALSData::Box()
{
    return box;
}

void EQUALSData::SetArrayName(const QString &arrayName)
{
    this->arrayName = arrayName;
}

void EQUALSData::SetValue(const double &value)
{
    this->value = value;
}

void EQUALSData::InitVariables()
{
    arrayName.clear();

    value = 0;

    box.InitVariables();
}

}}}}
