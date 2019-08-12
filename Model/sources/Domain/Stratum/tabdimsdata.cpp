#include "tabdimsdata.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

TABDIMSData::TABDIMSData()
{
    InitVariables();
}

QVariant TABDIMSData::NTSFUN() const
{
    return ntSFUN;
}

QVariant TABDIMSData::NTPVT() const
{
    return ntPVT;
}

QVariant TABDIMSData::NSSFUN() const
{
    return nsSFUN;
}

void TABDIMSData::SetNTSFUN(const QVariant &ntSFUN)
{
    this->ntSFUN = ntSFUN;
}

void TABDIMSData::SetNTPVT(const QVariant &ntPVT)
{
    this->ntPVT = ntPVT;
}

void TABDIMSData::SetNSSFUN(const QVariant &nsSFUN)
{
    this->nsSFUN = nsSFUN;
}

void TABDIMSData::InitVariables()
{
    ntSFUN.clear();
    ntPVT.clear();
    nsSFUN.clear();
}

}}}}
