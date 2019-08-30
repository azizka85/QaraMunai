#ifndef WCONPRODENTITY_H
#define WCONPRODENTITY_H

#include <qmetaobject.h>
#include <qobject.h>
#include <qdatetime.h>
#include <qvector.h>
#include <qmap.h>

#include <wconproddata.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Stratum;

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

class MODELSHARED_EXPORT WCONPRODEntity : public QObject
{
    Q_OBJECT

public:
    explicit WCONPRODEntity(QObject *parent = nullptr);

    QVector<WCONPRODData> &WCONPROD();

    Q_INVOKABLE bool exist();
    Q_INVOKABLE QVariantList getList(QDateTime date);

    QVector<WCONPRODData> WCONPRODList(QDateTime date);

    QVector<int> GetIndexes(QDateTime date);

    void AddWCONPROD(WCONPRODData &data);

    void Clear();

private:
    QMap<QDateTime, QVector<int>> dateIndexes;
    QVector<WCONPRODData> wconPROD;
};

}}}}

#endif // WCONPRODENTITY_H
