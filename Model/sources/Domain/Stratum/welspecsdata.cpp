#include "welspecsdata.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

WELSPECSData::WELSPECSData()
{
    InitVariables();
}

QString WELSPECSData::WellName()
{
    return wellName;
}

QString WELSPECSData::WellGroup()
{
    return wellGroup;
}

int WELSPECSData::I()
{
    return i;
}

int WELSPECSData::J()
{
    return j;
}

QVariant WELSPECSData::Depth()
{
    return depth;
}

QDateTime WELSPECSData::Date()
{
    return date;
}

void WELSPECSData::SetWellName(const QString &wellName)
{
    this->wellName = wellName;
}

void WELSPECSData::SetWellGroup(const QString &wellGroup)
{
    this->wellGroup = wellGroup;
}

void WELSPECSData::SetI(const int &i)
{
    this->i = i;
}

void WELSPECSData::SetJ(const int &j)
{
    this->j = j;
}

void WELSPECSData::SetDepth(const QVariant &depth)
{
    this->depth = depth;
}

void WELSPECSData::SetDate(const QDateTime &date)
{
    this->date = date;
}

void WELSPECSData::InitVariables()
{
    i = j = -1;
    wellName.clear();
    wellGroup.clear();
    date = QDateTime::currentDateTime();
}

}}}}
