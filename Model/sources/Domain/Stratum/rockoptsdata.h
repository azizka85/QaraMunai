#ifndef ROCKOPTSDATA_H
#define ROCKOPTSDATA_H

#include <qvariant.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT ROCKOPTSData
{
public:
    ROCKOPTSData();

    QVariant MAOTP();
    QVariant RPO();
    QVariant RegionOption();
    QVariant IHBOption();

    void SetMAOTP(const QVariant& maotp);
    void SetRPO(const QVariant& rpo);
    void SetRegionOption(const QVariant& regionOption);
    void SetIHBOption(const QVariant& ihbOption);

    void InitVariables();

private:
    QVariant maotp, rpo, regionOption, ihbOption;
};

}}}}

#endif // ROCKOPTSDATA_H
