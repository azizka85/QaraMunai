#ifndef PRVDDATA_H
#define PRVDDATA_H

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT PRVDData
{
public:
    PRVDData();

    double Depth();
    double PO();

    void SetDepth(const double& depth);
    void SetPO(const double& po);

    void InitVariables();

private:
    double depth, po;
};

}}}}

#endif // PRVDDATA_H
