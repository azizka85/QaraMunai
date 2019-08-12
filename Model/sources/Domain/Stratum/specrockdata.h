#ifndef SPECROCKDATA_H
#define SPECROCKDATA_H

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT SPECROCKData
{
public:
    SPECROCKData();

    double T();
    double CV();

    void SetT(const double& t);
    void SetCV(const double& cv);

    void InitVariables();

private:
    double t, cv;
};

}}}}

#endif // SPECROCKDATA_H
