#include "specrockdata.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

SPECROCKData::SPECROCKData()
{
    InitVariables();
}

double SPECROCKData::T()
{
    return t;
}

double SPECROCKData::CV()
{
    return cv;
}

void SPECROCKData::SetT(const double &t)
{
    this->t = t;
}

void SPECROCKData::SetCV(const double &cv)
{
    this->cv = cv;
}

void SPECROCKData::InitVariables()
{
    t = 0;
    cv = 0;
}

}}}}
