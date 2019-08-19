#ifndef WCONPRODENTITY_H
#define WCONPRODENTITY_H

#include <qmetaobject.h>
#include <qobject.h>
#include <qdatetime.h>
#include <qlist.h>
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

    Q_INVOKABLE bool exist();
    Q_INVOKABLE QVariantList getList(QDateTime date);

    QList<WCONPRODData> WCONPRODList(QDateTime date);
};

}}}}

#endif // WCONPRODENTITY_H
