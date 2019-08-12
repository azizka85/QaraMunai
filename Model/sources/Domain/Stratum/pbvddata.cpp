#include "pbvddata.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

PBVDData::PBVDData()
{
    InitVariables();
}

double PBVDData::Depth()
{
    return depth;
}

double PBVDData::PBub()
{
    return pBub;
}

void PBVDData::SetDepth(const double &depth)
{
    this->depth = depth;
}

void PBVDData::SetPBub(const double &pBub)
{
    this->pBub = pBub;
}

void PBVDData::InitVariables()
{
    depth = 0;
    pBub = 0;
}

}}}}
