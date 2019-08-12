#ifndef WCONHISTDATA_H
#define WCONHISTDATA_H

#include <qvariant.h>
#include <qstring.h>
#include <qdatetime.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT WCONHISTData
{
public:
    WCONHISTData();

    QString WellName();
    QVariant WellStatus();
    QVariant WellControl();
    QVariant ORAT();
    QVariant WRAT();
    QVariant GRAT();
    QDateTime Date();

    void SetWellName(const QString& wellName);
    void SetWellStatus(const QVariant& wellStatus);
    void SetWellControl(const QVariant& wellControl);
    void SetORAT(const QVariant& orat);
    void SetWRAT(const QVariant& wrat);
    void SetGRAT(const QVariant& grat);
    void SetDate(const QDateTime& date);

    void InitVariables();

private:
    QString wellName;
    QVariant wellStatus, wellControl, orat, wrat, grat;
    QDateTime date;
};

}}}}

#endif // WCONHISTDATA_H
