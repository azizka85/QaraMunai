#include "equalsentity.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

EQUALSEntity::EQUALSEntity(QObject *parent) : QObject(parent) { }

QVector<EQUALSData> &EQUALSEntity::EQUALS()
{
    return equals;
}

void EQUALSEntity::AddEQUALS(EQUALSData &equalsData)
{
    QString name = equalsData.ArrayName();

    if(!nameIndexes.contains(name)) nameIndexes[name] = QVector<int>();

    nameIndexes[name].append(equals.length());

    equals.append(equalsData);
}

QVector<int> EQUALSEntity::GetIndexes(QString name)
{
    return nameIndexes[name];
}

void EQUALSEntity::Clear()
{
    nameIndexes.clear();
    equals.clear();
}

}}}}
