#ifndef ENPCVDDATA_H
#define ENPCVDDATA_H

#include <qvariant.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT ENPCVDData
{
public:
    ENPCVDData();

    double Depth();
    QVariant MaxPcGO();
    QVariant MaxPcWO();

    void SetDepth(const double& depth);
    void SetMaxPcGO(const QVariant& maxPcGO);
    void SetMaxPcWO(const QVariant& maxPcWO);

    void InitVariables();

private:
    double depth;
    QVariant maxPcGO, maxPcWO;
};

}}}}

#endif // ENPCVDDATA_H
