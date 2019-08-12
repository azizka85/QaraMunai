#ifndef WELSPECSDATA_H
#define WELSPECSDATA_H

#include <qvariant.h>
#include <qstring.h>
#include <qdatetime.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT WELSPECSData
{
public:
    WELSPECSData();

    QString WellName();
    QString WellGroup();
    int I();
    int J();
    QVariant Depth();
    QDateTime Date();

    void SetWellName(const QString& wellName);
    void SetWellGroup(const QString& wellGroup);
    void SetI(const int& i);
    void SetJ(const int& j);
    void SetDepth(const QVariant& depth);
    void SetDate(const QDateTime& date);

    void InitVariables();

private:
    int i, j;
    QVariant depth;
    QString wellName, wellGroup;
    QDateTime date;
};

}}}}

#endif // WELSPECSDATA_H
