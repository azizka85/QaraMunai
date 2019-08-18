#ifndef WCONINJEENTITY_H
#define WCONINJEENTITY_H

#include <qobject.h>
#include <qdatetime.h>
#include <qlist.h>
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

    Q_INVOKABLE bool exist();
    Q_INVOKABLE QVariantList getList(QDateTime date);

    QList<WCONINJEData> WCONINJEList(QDateTime date);
};

}}}}


#endif // WCONINJEENTITY_H
