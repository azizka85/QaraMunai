#ifndef COPYENTITY_H
#define COPYENTITY_H

#include <qobject.h>
#include <qlist.h>
#include <qmap.h>

#include <copydata.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Stratum;

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

class MODELSHARED_EXPORT COPYEntity : public QObject
{
    Q_OBJECT

public:
    explicit COPYEntity(QObject *parent = nullptr);

    QList<COPYData>& COPY();

    void AddCopy(COPYData& copyData);

    QList<int> GetIndexes(QString destName);

    void Clear();

private:
    QList<COPYData> copy;
    QMap<QString, QList<int>> destNameIndexes;
};

}}}}

#endif // COPYENTITY_H
