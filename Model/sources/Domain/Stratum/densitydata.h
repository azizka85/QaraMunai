#ifndef DENSITYDATA_H
#define DENSITYDATA_H

#include <qvariant.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT DENSITYData
{
public:
    DENSITYData();

    QVariant RO();
    QVariant RW();
    QVariant RG();

    void SetRO(const QVariant& ro);
    void SetRW(const QVariant& rw);
    void SetRG(const QVariant& rg);

    void InitVariables();

private:
    QVariant ro, rw, rg;
};

}}}}

#endif // DENSITYDATA_H
