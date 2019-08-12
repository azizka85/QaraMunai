#include "endscaledata.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

ENDSCALEData::ENDSCALEData()
{
    InitVariables();
}

QVariant ENDSCALEData::Directional() const
{
    return directional;
}

QVariant ENDSCALEData::Irreversible() const
{
    return irreversible;
}

QVariant ENDSCALEData::NTENDP() const
{
    return ntENDP;
}

QVariant ENDSCALEData::MaxNodesEPD() const
{
    return maxNodesEPD;
}

void ENDSCALEData::SetDirectional(const QVariant &directional)
{
    this->directional = directional;
}

void ENDSCALEData::SetIrreversible(const QVariant &irreversible)
{
    this->irreversible = irreversible;
}

void ENDSCALEData::SetNTENDP(const QVariant &ntENDP)
{
    this->ntENDP = ntENDP;
}

void ENDSCALEData::SetMaxNodesEPD(const QVariant &maxNodesEPD)
{
    this->maxNodesEPD = maxNodesEPD;
}

void ENDSCALEData::InitVariables()
{
    directional.clear();
    irreversible.clear();
    ntENDP.clear();
    maxNodesEPD.clear();
}

}}}}
