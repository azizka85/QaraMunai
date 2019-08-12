#ifndef PVDGDATA_H
#define PVDGDATA_H

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT PVDGData
{
public:
    PVDGData();

    double PG();
    double BG();
    double MG();

    void SetPG(const double& pg);
    void SetBG(const double& bg);
    void SetMG(const double& mg);

    void InitVariables();

private:
    double pg, bg, mg;
};

}}}}

#endif // PVDGDATA_H
