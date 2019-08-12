#ifndef SPECHEATDATA_H
#define SPECHEATDATA_H

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT SPECHEATData
{
public:
    SPECHEATData();

    double T();
    double CO();
    double CW();
    double CG();

    void SetT(const double& t);
    void SetCO(const double& co);
    void SetCW(const double& cw);
    void SetCG(const double& cg);

    void InitVariables();

private:
    double t, co, cw, cg;
};

}}}}

#endif // SPECHEATDATA_H
