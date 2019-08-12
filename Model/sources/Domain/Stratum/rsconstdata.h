#ifndef RSCONSTDATA_H
#define RSCONSTDATA_H

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT RSCONSTData
{
public:
    RSCONSTData();

    double RS();
    double PBub();

    void SetRS(const double& rs);
    void SetPBub(const double& pBub);

    void InitVariables();

private:
    double rs, pBub;
};

}}}}

#endif // RSCONSTDATA_H
