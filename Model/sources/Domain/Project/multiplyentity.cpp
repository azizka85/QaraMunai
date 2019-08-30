#include "multiplyentity.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

MULTIPLYEntity::MULTIPLYEntity(QObject *parent) : QObject(parent) {  }

QVector<MULTIPLYData> &MULTIPLYEntity::MULTIPLY()
{
    return multiply;
}

void MULTIPLYEntity::AddMULTIPLY(MULTIPLYData &multiplyData)
{
    QString name = multiplyData.ArrayName();

    if(!nameIndexes.contains(name)) nameIndexes[name] = QVector<int>();

    nameIndexes[name].append(multiply.length());

    multiply.append(multiplyData);
}

QVector<int> MULTIPLYEntity::GetIndexes(QString name)
{
    return nameIndexes[name];
}

void MULTIPLYEntity::Clear()
{
    nameIndexes.clear();
    multiply.clear();
}

}}}}
