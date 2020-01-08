#ifndef PVCODATA_H
#define PVCODATA_H

#include <qvariant.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT PVCOData
{
public:
    PVCOData();

    double PO();

    QVariant RS();
    QVariant BO();
    QVariant MO();
    QVariant CO();
    QVariant CVO();

    void SetPO(const double& po);

    void SetRS(const QVariant& rs);
    void SetBO(const QVariant& bo);
    void SetMO(const QVariant& mo);
    void SetCO(const QVariant& co);
    void SetCVO(const QVariant& cvo);

    void InitVariables();

private:
    double po;
    QVariant rs, bo, mo, co, cvo;
};

}}}}

#endif // PVCODATA_H
