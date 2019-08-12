#include "watvisctdata.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

WATVISCTData::WATVISCTData()
{
    InitVariables();
}

double WATVISCTData::T()
{
    return t;
}

double WATVISCTData::MW()
{
    return mw;
}

void WATVISCTData::SetT(const double &t)
{
    this->t = t;
}

void WATVISCTData::SetMW(const double &mw)
{
    this->mw = mw;
}

void WATVISCTData::InitVariables()
{
    t = 0;
    mw = 0;
}

}}}}
