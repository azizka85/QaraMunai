#include "copydata.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

COPYData::COPYData()
{
    InitVariables();
}

QString COPYData::SOURCE()
{
    return source;
}

QString COPYData::DESTINATION()
{
    return destination;
}

Box3D &COPYData::Box()
{
    return box;
}

void COPYData::SetSOURCE(const QString &source)
{
    this->source = source;
}

void COPYData::SetDESTINATION(const QString &destination)
{
    this->destination = destination;
}

void COPYData::InitVariables()
{
    source.clear();
    destination.clear();

    box.InitVariables();
}

}}}}
