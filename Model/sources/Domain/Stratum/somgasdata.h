#ifndef SOMGASDATA_H
#define SOMGASDATA_H

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT SOMGASData
{
public:
    SOMGASData();

    double SG();
    double SOMin();

    void SetSG(const double& sg);
    void SetSOMin(const double& soMin);

    void InitVariables();

private:
    double sg, soMin;
};

}}}}

#endif // SOMGASDATA_H
