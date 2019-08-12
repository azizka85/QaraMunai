#ifndef SOF32DDATA_H
#define SOF32DDATA_H

#include <qlist.h>

#include <sof32dkrodata.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT SOF32DData
{
public:
    SOF32DData();

    QList<double> &SW();
    QList<SOF32DKrOData> &SOF32DKrO();

    void InitVariables();

private:
    QList<double> sw;
    QList<SOF32DKrOData> sof32dKrO;
};

}}}}

#endif // SOF32DDATA_H
