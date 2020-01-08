#ifndef SOF32DDATA_H
#define SOF32DDATA_H

#include <qvector.h>

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

    QVector<double> &SW();
    QVector<SOF32DKrOData> &SOF32DKrO();

    void InitVariables();

private:
    QVector<double> sw;
    QVector<SOF32DKrOData> sof32dKrO;
};

}}}}

#endif // SOF32DDATA_H
