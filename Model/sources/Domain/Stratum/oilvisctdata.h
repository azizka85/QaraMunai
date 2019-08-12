#ifndef OILVISCTDATA_H
#define OILVISCTDATA_H

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT OILVISCTData
{
public:
    OILVISCTData();

    double T();
    double MO();

    void SetT(const double& t);
    void SetMO(const double& mo);

    void InitVariables();

private:
    double t, mo;
};

}}}}

#endif // OILVISCTDATA_H
