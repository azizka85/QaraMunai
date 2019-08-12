#ifndef SGOFENTITY_H
#define SGOFENTITY_H

#include <qobject.h>
#include <qlist.h>
#include <qmap.h>

#include <sgofdata.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Stratum;

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

class MODELSHARED_EXPORT SGOFEntity : public QObject
{
    Q_OBJECT

public:
    explicit SGOFEntity(QObject *parent = nullptr);

    Q_INVOKABLE bool exist();
    Q_INVOKABLE QVariantList getList(int region);

    QList<SGOFData> SGOFList(int region);
};

}}}}

#endif // SGOFENTITY_H
