#ifndef PVDODATA_H
#define PVDODATA_H

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT PVDOData
{
public:
    PVDOData();

    double PO();
    double BO();
    double MO();

    void SetPO(const double& po);
    void SetBO(const double& bo);
    void SetMO(const double& mo);

    void InitVariables();

private:
    double po, bo, mo;
};

}}}}

#endif // PVDODATA_H
