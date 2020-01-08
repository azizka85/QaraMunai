#ifndef SWOF_H
#define SWOF_H

#include <qobject.h>
#include <qvector.h>
#include <qmap.h>

#include <swofdata.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Stratum;

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

class MODELSHARED_EXPORT SWOFEntity : public QObject
{
    Q_OBJECT

public:
    explicit SWOFEntity(QObject *parent = nullptr);

    Q_INVOKABLE bool exist();
    Q_INVOKABLE QVariantList getList(int region);

    QVector<SWOFData> SWOFList(int region);
};

}}}}

#endif // SWOF_H
