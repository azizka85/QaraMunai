#include "copyentity.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

COPYEntity::COPYEntity(QObject *parent) : QObject (parent) {  }

QVector<COPYData> &COPYEntity::COPY()
{
    return copy;
}

void COPYEntity::AddCopy(COPYData &copyData)
{
    QString destName = copyData.DESTINATION();

    if(!destNameIndexes.contains(destName)) destNameIndexes[destName] = QVector<int>();

    destNameIndexes[destName].append(copy.length());

    copy.append(copyData);
}

QVector<int> COPYEntity::GetIndexes(QString destName)
{
    return destNameIndexes.contains(destName) ? destNameIndexes[destName] : QVector<int>();
}

void COPYEntity::Clear()
{
    destNameIndexes.clear();
    copy.clear();
}

}}}}
