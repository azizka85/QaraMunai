#ifndef ADDENTITY_H
#define ADDENTITY_H

#include <qobject.h>
#include <qlist.h>
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

    QList<ADDData> &ADD();

    void AddADD(ADDData& addData);

    QList<int> GetIndexes(QString name);

    void Clear();

private:
    QList<ADDData> add;
    QMap<QString, QList<int>> nameIndexes;
};

}}}}

#endif // ADDENTITY_H
