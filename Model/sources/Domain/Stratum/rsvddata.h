#ifndef RSVDDATA_H
#define RSVDDATA_H

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT RSVDData
{
public:
    RSVDData();

    double Depth();
    double RS();

    void SetDepth(const double& depth);
    void SetRS(const double& rs);

    void InitVariables();

private:
    double depth, rs;
};

}}}}

#endif // RSVDDATA_H
