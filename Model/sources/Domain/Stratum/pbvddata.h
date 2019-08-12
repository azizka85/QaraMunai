#ifndef PBVDDATA_H
#define PBVDDATA_H

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT PBVDData
{
public:
    PBVDData();

    double Depth();
    double PBub();

    void SetDepth(const double& depth);
    void SetPBub(const double& pBub);

    void InitVariables();

private:
    double depth, pBub;
};

}}}}

#endif // PBVDDATA_H
