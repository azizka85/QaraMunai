#ifndef WCONINJHDATA_H
#define WCONINJHDATA_H

#include <qvariant.h>
#include <qstring.h>
#include <qdatetime.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT WCONINJHData
{
public:
    WCONINJHData();

    QString WellName();
    QVariant InjFluid();
    QVariant WellStatus();
    QVariant RATE();
    QVariant BHP();
    QDateTime Date();

    void SetWellName(const QString& wellName);
    void SetInjFluid(const QVariant& injFluid);
    void SetWellStatus(const QVariant& wellStatus);
    void SetRATE(const QVariant& rate);
    void SetBHP(const QVariant& bhp);
    void SetDate(const QDateTime& date);

    void InitVariables();
    QVariantMap toMap();

private:
    QString wellName;
    QVariant injFluid, wellStatus, rate, bhp;
    QDateTime date;
};

}}}}

#endif // WCONINJHDATA_H
