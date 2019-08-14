#ifndef PVTGDATA_H
#define PVTGDATA_H

#include <qvariant.h>
#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT PVTGData
{
public:
    PVTGData();

    double PG();
    double RV();
    double BG();
    double MG();

    void SetPG(const double& pg);
    void SetRV(const double& rv);
    void SetBG(const double& bg);
    void SetMG(const double& mg);

    void InitVariables();
    QVariantMap toMap();

private:
    double pg, rv, bg, mg;
};

}}}}

#endif // PVTGDATA_H
