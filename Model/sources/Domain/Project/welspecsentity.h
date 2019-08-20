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

    Q_INVOKABLE bool exist();
    Q_INVOKABLE QVariantList getList(QVariant date);

    QList<WELSPECSData> WELSPECSList(QVariant date);
};

}}}}

#endif // WELSPECSENTITY_H
