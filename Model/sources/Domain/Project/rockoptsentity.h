#ifndef ROCKOPTSENTITY_H
#define ROCKOPTSENTITY_H

#include <QObject>
#include <QVariant>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

class MODELSHARED_EXPORT ROCKOPTSEntity : public QObject
{
    Q_OBJECT

    Q_ENUMS(MAOTPOptions)
    Q_ENUMS(ReferencePressureOptions)
    Q_ENUMS(RegionOptions)
    Q_ENUMS(IHBOptions)

    Q_PROPERTY(QVariant maotp READ MAOTP WRITE SetMAOTP NOTIFY MAOTPChanged)
    Q_PROPERTY(QVariant rpo READ RPO WRITE SetRPO NOTIFY RPOChanged)
    Q_PROPERTY(QVariant regionOption READ RegionOption WRITE SetRegionOption NOTIFY RegionOptionChanged)
    Q_PROPERTY(QVariant ihbOption READ IHBOption WRITE SetIHBOption NOTIFY IHBOptionChanged)

public:
    explicit ROCKOPTSEntity(QObject *parent = nullptr);

    enum MAOTPOptions {PRESSURE = 0, STRESS = 1};
    enum ReferencePressureOptions {NOSTORE = 0, STORE = 1};
    enum RegionOptions {PVTNUM = 0, SATNUM = 1};
    enum IHBOptions {DEFLATION = 0, ELASTIC = 1};

    QVariant MAOTP();
    QVariant RPO();
    QVariant RegionOption();
    QVariant IHBOption();

    void SetMAOTP(const QVariant& maotp);
    void SetRPO(const QVariant& rpo);
    void SetRegionOption(const QVariant& regionOption);
    void SetIHBOption(const QVariant& ihbOption);

    Q_INVOKABLE void initVariables();

signals:
    void MAOTPChanged();
    void RPOChanged();
    void RegionOptionChanged();
    void IHBOptionChanged();
};

}}}}

#endif // ROCKOPTSENTITY_H
