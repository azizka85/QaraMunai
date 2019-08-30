#ifndef WELSPECSENTITY_H
#define WELSPECSENTITY_H

#include <qobject.h>
#include <qdatetime.h>
#include <qvector.h>
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

    QVector<WELSPECSData> &WELSPECS();

    Q_INVOKABLE bool exist();
    Q_INVOKABLE QVariantList getList(QDateTime date);
    Q_INVOKABLE QVariantMap getData();

    QVector<WELSPECSData> WELSPECSList(QDateTime date);
    QMap<QString, QVector<WELSPECSData>> WELSPECSGroupList();

    QVector<int> GetDateIndexes(QDateTime date);
    QVector<int> GetGroupIndexes(QString group);

    void AddWELSPECS(WELSPECSData &data);

    void Clear();

private:
    QMap<QDateTime, QVector<int>> dateIndexes;
    QMap<QString, QVector<int>> groupIndexes;
    QVector<WELSPECSData> welSPECS;
};

}}}}

#endif // WELSPECSENTITY_H
