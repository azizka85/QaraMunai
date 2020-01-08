#ifndef MULTIPLYENTITY_H
#define MULTIPLYENTITY_H

#include <qobject.h>
#include <qvector.h>
#include <qmap.h>

#include <multiplydata.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Stratum;

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

class MODELSHARED_EXPORT MULTIPLYEntity : public QObject
{
    Q_OBJECT

public:
    explicit MULTIPLYEntity(QObject *parent = nullptr);

    QVector<MULTIPLYData> &MULTIPLY();

    void AddMULTIPLY(MULTIPLYData& multiplyData);

    QVector<int> GetIndexes(QString name);

    void Clear();

private:
    QVector<MULTIPLYData> multiply;
    QMap<QString, QVector<int>> nameIndexes;
};

}}}}

#endif // MULTIPLYENTITY_H
