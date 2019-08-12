#ifndef DIMPESDATA_H
#define DIMPESDATA_H

#include <qvariant.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT DIMPESData
{
public:
    DIMPESData();

    QVariant DSTARG();
    QVariant DSMAX();
    QVariant DPMAX();

    void SetDSTARG(const QVariant& dsTARG);
    void SetDSMAX(const QVariant& dsMAX);
    void SetDPMAX(const QVariant& dpMAX);

    void InitVariables();

private:
    QVariant dsTARG, dsMAX, dpMAX;
};

}}}}

#endif // DIMPESDATA_H
