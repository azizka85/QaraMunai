#ifndef PVTOENTITY_H
#define PVTOENTITY_H

#include <qobject.h>
#include <qlist.h>
#include <qmap.h>

#include <pvtodata.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Stratum;

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

class MODELSHARED_EXPORT PVTOEntity : public QObject
{
    Q_OBJECT

public:
    explicit PVTOEntity(QObject *parent = nullptr);

    Q_INVOKABLE bool exist();
    Q_INVOKABLE QVariantList getList(int region);

    QList<PVTOData> PVTOList(int region);
};

}}}}

#endif // PVTOENTITY_H
