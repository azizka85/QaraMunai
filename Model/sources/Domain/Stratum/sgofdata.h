#ifndef SGOFDATA_H
#define SGOFDATA_H

#include <qvariant.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT SGOFData
{
public:
    SGOFData();

    double SG();

    QVariant KrG();
    QVariant KrO();
    QVariant Pc();

    void SetSG(const double& sg);

    void SetKrG(const QVariant& krg);
    void SetKrO(const QVariant& kro);
    void SetPc(const QVariant& pc);

    void InitVariables();
    QVariantMap toMap();

private:
    double sg;
    QVariant krg, kro, pc;
};

}}}}

#endif // SGOFDATA_H
