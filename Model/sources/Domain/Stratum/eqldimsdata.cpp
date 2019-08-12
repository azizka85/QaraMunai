#include "eqldimsdata.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

EQLDIMSData::EQLDIMSData()
{
    InitVariables();
}

QVariant EQLDIMSData::NTEQUL() const
{
    return ntEQUL;
}

void EQLDIMSData::SetNTEQUL(const QVariant &ntEQUL)
{
    this->ntEQUL = ntEQUL;
}

void EQLDIMSData::InitVariables()
{
    ntEQUL.clear();
}

}}}}
