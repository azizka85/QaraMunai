#ifndef WELSPECSENTITY_H
#define WELSPECSENTITY_H

#include <qobject.h>
#include <qdatetime.h>
#include <qlist.h>
#include <qmap.h>

#include <welspecsdata.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Stratum;

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

class MODELSHARED_EXPORT WELSPECSEntity : public QObject
{
    Q_OBJECT

public:
    explicit WELSPECSEntity(QObject *parent = nullptr);

    QList<WELSPECSData> &WELSPECS();

    Q_INVOKABLE bool exist();
    Q_INVOKABLE QVariantList getList(QDateTime date);
    Q_INVOKABLE QVariantMap getData();

    QList<WELSPECSData> WELSPECSList(QDateTime date);
    QMap<QString, QList<WELSPECSData>> WELSPECSGroupList();

    QList<int> GetDateIndexes(QDateTime date);
    QList<int> GetGroupIndexes(QString group);

    void AddWELSPECS(WELSPECSData &data);

    void Clear();

private:
    QMap<QDateTime, QList<int>> dateIndexes;
    QMap<QString, QList<int>> groupIndexes;
    QList<WELSPECSData> welSPECS;
};

}}}}

#endif // WELSPECSENTITY_H
