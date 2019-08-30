#include "sof32ddata.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

SOF32DData::SOF32DData()
{
    InitVariables();
}

QVector<double> &SOF32DData::SW()
{
    return sw;
}

QVector<SOF32DKrOData> &SOF32DData::SOF32DKrO()
{
    return sof32dKrO;
}

void SOF32DData::InitVariables()
{
    sw.clear();

    sof32dKrO.clear();
}

}}}}
