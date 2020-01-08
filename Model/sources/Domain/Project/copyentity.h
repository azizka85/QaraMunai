#ifndef COPYENTITY_H
#define COPYENTITY_H

#include <qobject.h>
#include <qvector.h>
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

    QVector<COPYData>& COPY();

    void AddCopy(COPYData& copyData);

    QVector<int> GetIndexes(QString destName);

    void Clear();

private:
    QVector<COPYData> copy;
    QMap<QString, QVector<int>> destNameIndexes;
};

}}}}

#endif // COPYENTITY_H
