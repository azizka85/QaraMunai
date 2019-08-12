#ifndef GRAVITYDATA_H
#define GRAVITYDATA_H

#include <qvariant.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT GRAVITYData
{
public:
    GRAVITYData();

    QVariant GO();
    QVariant GW();
    QVariant GG();

    void SetGO(const QVariant& go);
    void SetGW(const QVariant& gw);
    void SetGG(const QVariant& gg);

    void InitVariables();

private:
    QVariant go, gw, gg;
};

}}}}

#endif // GRAVITYDATA_H
