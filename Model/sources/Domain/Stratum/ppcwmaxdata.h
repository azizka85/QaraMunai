#ifndef PPCWMAXDATA_H
#define PPCWMAXDATA_H

#include <qvariant.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT PPCWMAXData
{
public:
    PPCWMAXData();

    QVariant PcMax();
    QVariant SModify();

    void SetPcMax(const QVariant &pcMax);
    void SetSModify(const QVariant& sModify);

    void InitVariables();
private:
    QVariant pcMax, sModify;
};

}}}}

#endif // PPCWMAXDATA_H
