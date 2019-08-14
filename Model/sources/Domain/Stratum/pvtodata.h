#ifndef PVTODATA_H
#define PVTODATA_H

#include <qvariant.h>
#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT PVTOData
{
public:
    PVTOData();

    double RS();
    double PO();
    double BO();
    double MO();

    void SetRS(const double& rs);
    void SetPO(const double& po);
    void SetBO(const double& bo);
    void SetMO(const double& mo);

    void InitVariables();
    QVariantMap toMap();

private:
    double rs, po, bo, mo;
};

}}}}

#endif // PVTODATA_H
