#include "oilvisctdata.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

OILVISCTData::OILVISCTData()
{
    InitVariables();
}

double OILVISCTData::T()
{
    return t;
}

double OILVISCTData::MO()
{
    return mo;
}

void OILVISCTData::SetT(const double &t)
{
    this->t = t;
}

void OILVISCTData::SetMO(const double &mo)
{
    this->mo = mo;
}

void OILVISCTData::InitVariables()
{
    t = 0;
    mo = 0;
}

}}}}
