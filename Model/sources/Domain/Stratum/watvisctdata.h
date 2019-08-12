#ifndef WATVISCTDATA_H
#define WATVISCTDATA_H

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT WATVISCTData
{
public:
    WATVISCTData();

    double T();
    double MW();

    void SetT(const double& t);
    void SetMW(const double& mw);

    void InitVariables();

private:
    double t, mw;
};

}}}}

#endif // WATVISCTDATA_H
