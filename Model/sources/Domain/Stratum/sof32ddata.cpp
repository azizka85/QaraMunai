#include "sof32ddata.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

SOF32DData::SOF32DData()
{
    InitVariables();
}

QList<double> &SOF32DData::SW()
{
    return sw;
}

QList<SOF32DKrOData> &SOF32DData::SOF32DKrO()
{
    return sof32dKrO;
}

void SOF32DData::InitVariables()
{
    sw.clear();

    sof32dKrO.clear();
}

}}}}
