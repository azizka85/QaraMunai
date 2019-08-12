#include "multiplydata.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

MULTIPLYData::MULTIPLYData()
{
    InitVariables();
}

QString MULTIPLYData::ArrayName()
{
    return arrayName;
}

double MULTIPLYData::Mult()
{
    return mult;
}

Box3D &MULTIPLYData::Box()
{
    return box;
}

void MULTIPLYData::SetArrayName(const QString &arrayName)
{
    this->arrayName = arrayName;
}

void MULTIPLYData::SetMult(const double &mult)
{
    this->mult = mult;
}

void MULTIPLYData::InitVariables()
{
    arrayName.clear();

    mult = 0;

    box.InitVariables();
}

}}}}
