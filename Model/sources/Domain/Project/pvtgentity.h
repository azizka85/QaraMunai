#ifndef PVTGENTITY_H
#define PVTGENTITY_H

#include <qobject.h>
#include <qlist.h>
#include <qmap.h>

#include <pvtgdata.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Stratum;

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

class MODELSHARED_EXPORT PVTGEntity : public QObject
{
    Q_OBJECT

public:
    explicit PVTGEntity(QObject *parent = nullptr);

    Q_INVOKABLE bool exist();
    Q_INVOKABLE QVariantList getList(int region);

    QList<PVTGData> PVTGList(int region);
};

}}}}

#endif // PVTGENTITY_H
