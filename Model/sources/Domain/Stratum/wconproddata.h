#ifndef WCONPRODDATA_H
#define WCONPRODDATA_H

#include <qvariant.h>
#include <qstring.h>
#include <qdatetime.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT WCONPRODData
{
public:
    WCONPRODData();

    QString WellName();
    QVariant WellStatus();
    QVariant WellControl();
    QVariant ORAT();
    QVariant WRAT();
    QVariant GRAT();
    QVariant LRAT();
    QVariant RESV();
    QVariant BHP();
    QDateTime Date();

    void SetWellName(const QString &wellName);
    void SetWellStatus(const QVariant &wellStatus);
    void SetWellControl(const QVariant &wellControl);
    void SetORAT(const QVariant& orat);
    void SetWRAT(const QVariant& wrat);
    void SetGRAT(const QVariant& grat);
    void SetLRAT(const QVariant& lrat);
    void SetRESV(const QVariant& resv);
    void SetBHP(const QVariant& bhp);
    void SetDate(const QDateTime& date);

    void InitVariables();
    QVariantMap toMap();
private:
    QString wellName;
    QVariant wellStatus, wellControl, orat, wrat, grat, lrat, resv, bhp;
    QDateTime date;
};

}}}}

#endif // WCONPRODDATA_H
