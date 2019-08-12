#ifndef SWOFDATA_H
#define SWOFDATA_H

#include <qvariant.h>
#include <qvariant.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT SWOFData
{
public:
    SWOFData();

    double SW();

    QVariant KrW();
    QVariant KrO();
    QVariant Pc();

    void SetSW(const double& sw);

    void SetKrW(const QVariant& krw);
    void SetKrO(const QVariant& kro);
    void SetPc(const QVariant& pc);

    void InitVariables();

    QVariantMap toMap();

private:
    double sw;
    QVariant krw, kro, pc;
};

}}}}

#endif // SWOFDATA_H
