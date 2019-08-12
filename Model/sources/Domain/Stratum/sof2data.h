#ifndef SOF2DATA_H
#define SOF2DATA_H

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT SOF2Data
{
public:
    SOF2Data();

    double SO();
    double KrO();

    void SetSO(const double& so);
    void SetKrO(const double& kro);

    void InitVariables();

private:
    double so, kro;
};

}}}}

#endif // SOF2DATA_H
