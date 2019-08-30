#include <projectdata.h>

#include "addentity.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

ADDEntity::ADDEntity(QObject *parent) : QObject(parent) {  }

QVector<ADDData> &ADDEntity::ADD()
{
    return add;
}

void ADDEntity::AddADD(ADDData &addData)
{
    QString name = addData.ArrayName();

    if(!nameIndexes.contains(name)) nameIndexes[name] = QVector<int>();

    nameIndexes[name].append(add.length());

    add.append(addData);
}

QVector<int> ADDEntity::GetIndexes(QString name)
{
    return nameIndexes.contains(name) ? nameIndexes[name] : QVector<int>();
}

void ADDEntity::Clear()
{
    nameIndexes.clear();
    add.clear();
}

}}}}
