#include "adddata.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

ADDData::ADDData()
{
    InitVariables();
}

QString ADDData::ArrayName()
{
    return arrayName;
}

double ADDData::Value()
{
    return value;
}

Box3D &ADDData::Box()
{
    return box;
}

void ADDData::SetArrayName(const QString &arrayName)
{
    this->arrayName = arrayName;
}

void ADDData::SetValue(const double &value)
{
    this->value = value;
}

void ADDData::InitVariables()
{
    arrayName.clear();

    value = 0;

    box.InitVariables();
}

}}}}
