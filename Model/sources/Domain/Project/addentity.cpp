#include "addentity.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

ADDEntity::ADDEntity(QObject *parent) : QObject(parent) {  }

QList<ADDData> &ADDEntity::ADD()
{
    return add;
}

void ADDEntity::AddADD(ADDData &addData)
{
    QString name = addData.ArrayName();

    if(!nameIndexes.contains(name)) nameIndexes[name] = QList<int>();

    nameIndexes[name].append(add.length());

    add.append(addData);
}

QList<int> ADDEntity::GetIndexes(QString name)
{
    return nameIndexes.contains(name) ? nameIndexes[name] : QList<int>();
}

void ADDEntity::Clear()
{
    nameIndexes.clear();
    add.clear();
}

}}}}
