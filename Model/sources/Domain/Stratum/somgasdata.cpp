#include "somgasdata.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

SOMGASData::SOMGASData()
{
    InitVariables();
}

double SOMGASData::SG()
{
    return sg;
}

double SOMGASData::SOMin()
{
    return soMin;
}

void SOMGASData::SetSG(const double &sg)
{
    this->sg = sg;
}

void SOMGASData::SetSOMin(const double &soMin)
{
    this->soMin = soMin;
}

void SOMGASData::InitVariables()
{
    sg = 0;
    soMin = 0;
}

}}}}
