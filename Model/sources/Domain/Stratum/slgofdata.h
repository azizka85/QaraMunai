#ifndef SLGOFDATA_H
#define SLGOFDATA_H

#include <qvariant.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT SLGOFData
{
public:
    SLGOFData();

    double SL();

    QVariant KrG();
    QVariant KrO();
    QVariant Pc();

    void SetSL(const double& sl);

    void SetKrG(const QVariant& krg);
    void SetKrO(const QVariant& kro);
    void SetPc(const QVariant& pc);

    void InitVariables();

private:
    double sl;
    QVariant krg, kro, pc;
};

}}}}

#endif // SLGOFDATA_H
