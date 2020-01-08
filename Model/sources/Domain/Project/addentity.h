#ifndef ADDENTITY_H
#define ADDENTITY_H

#include <qobject.h>
#include <qvector.h>
#include <qmap.h>

#include <adddata.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Stratum;

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

class MODELSHARED_EXPORT ADDEntity : public QObject
{
    Q_OBJECT

public:
    explicit ADDEntity(QObject *parent = nullptr);

    QVector<ADDData> &ADD();

    void AddADD(ADDData& addData);

    QVector<int> GetIndexes(QString name);

    void Clear();

private:
    QVector<ADDData> add;
    QMap<QString, QVector<int>> nameIndexes;
};

}}}}

#endif // ADDENTITY_H
