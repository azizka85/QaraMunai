#ifndef WCONINJEENTITY_H
#define WCONINJEENTITY_H

#include <qobject.h>
#include <qdatetime.h>
#include <qvector.h>
#include <qmap.h>

#include <wconinjedata.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Stratum;

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

class MODELSHARED_EXPORT WCONINJEEntity : public QObject
{
    Q_OBJECT

public:
    explicit WCONINJEEntity(QObject *parent = nullptr);

    QVector<WCONINJEData> &WCONINJE();

    Q_INVOKABLE bool exist();
    Q_INVOKABLE QVariantList getList(QDateTime date);

    QVector<WCONINJEData> WCONINJEList(QDateTime date);

    QVector<int> GetIndexes(QDateTime date);

    void AddWCONINJE(WCONINJEData& data);

    void Clear();

private:
    QMap<QDateTime, QVector<int>> dateIndexes;
    QVector<WCONINJEData> wconINJE;
};

}}}}


#endif // WCONINJEENTITY_H
