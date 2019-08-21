#include "multiplyentity.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

MULTIPLYEntity::MULTIPLYEntity(QObject *parent) : QObject(parent) {  }

QList<MULTIPLYData> &MULTIPLYEntity::MULTIPLY()
{
    return multiply;
}

void MULTIPLYEntity::AddMULTIPLY(MULTIPLYData &multiplyData)
{
    QString name = multiplyData.ArrayName();

    if(!nameIndexes.contains(name)) nameIndexes[name] = QList<int>();

    nameIndexes[name].append(multiply.length());

    multiply.append(multiplyData);
}

QList<int> MULTIPLYEntity::GetIndexes(QString name)
{
    return nameIndexes[name];
}

void MULTIPLYEntity::Clear()
{
    nameIndexes.clear();
    multiply.clear();
}

}}}}
