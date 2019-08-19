#ifndef COMPDATENTITY_H
#define COMPDATENTITY_H

#include <qobject.h>
#include <qdatetime.h>
#include <qlist.h>
#include <qmap.h>

#include <compdatdata.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Stratum;

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

class MODELSHARED_EXPORT COMPDATEntity : public QObject
{
    Q_OBJECT

public:
    explicit COMPDATEntity(QObject *parent = nullptr);

    Q_INVOKABLE bool exist();
    Q_INVOKABLE QVariantList getList(QDateTime date);

    QList<COMPDATData> COMPDATList(QDateTime date);
};

}}}}

#endif // COMPDATENTITY_H
