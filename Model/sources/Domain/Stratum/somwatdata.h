#ifndef SOMWATDATA_H
#define SOMWATDATA_H

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT SOMWATData
{
public:
    SOMWATData();

    double SW();
    double SOMin();

    void SetSW(const double &sw);
    void SetSOMin(const double &soMin);

    void InitVariables();

private:
    double sw, soMin;
};

}}}}

#endif // SOMWATDATA_H
