#ifndef VISCREFDATA_H
#define VISCREFDATA_H

#include <qvariant.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT VISCREFData
{
public:
    VISCREFData();

    double PRef();
    QVariant RSRef();
    QVariant GRef();

    void SetPRef(const double& pRef);
    void SetRSRef(const QVariant& rsRef);
    void SetGRef(const QVariant& gRef);

    void InitVariables();

private:
    double pRef;
    QVariant rsRef, gRef;
};

}}}}

#endif // VISCREFDATA_H
