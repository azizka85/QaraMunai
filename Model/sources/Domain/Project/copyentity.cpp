#include "copyentity.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

COPYEntity::COPYEntity(QObject *parent) : QObject (parent) {  }

QList<COPYData>& COPYEntity::COPY()
{
    return copy;
}

void COPYEntity::AddCopy(COPYData &copyData)
{
    QString destName = copyData.DESTINATION();

    if(!destNameIndexes.contains(destName)) destNameIndexes[destName] = QList<int>();

    destNameIndexes[destName].append(copy.length());

    copy.append(copyData);
}

QList<int> COPYEntity::GetIndexes(QString destName)
{
    return destNameIndexes.contains(destName) ? destNameIndexes[destName] : QList<int>();
}

void COPYEntity::Clear()
{
    destNameIndexes.clear();
    copy.clear();
}

}}}}
