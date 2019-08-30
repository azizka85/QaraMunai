#include <defaultvalues.h>

#include "compdatentity.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

COMPDATEntity::COMPDATEntity(QObject *parent) : QObject (parent) { }

QVector<COMPDATData> &COMPDATEntity::COMPDAT()
{
    return compDAT;
}

bool COMPDATEntity::exist()
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        return project->Loaded() && compDAT.length() > 0;
    }

    return false;
}

QVariantList COMPDATEntity::getList(QDateTime date)
{
    QVariantList compdatList;

    QVector<COMPDATData> list = COMPDATList(date);

    QMetaObject metaObject = ProjectData::staticMetaObject;

    QMetaEnum wellStatusTypeEnum = metaObject.enumerator(metaObject.indexOfEnumerator("WellStatusType"));

    for(int i = 0; i < list.length(); i++)
    {
        QVariantMap map = list[i].toMap();

        map["wellStatus"] = QString(wellStatusTypeEnum.valueToKey(map["wellStatus"].toInt()));

        compdatList.append(map);
    }

    return compdatList;
}

QVector<int> COMPDATEntity::GetIndexes(QDateTime date)
{
    return dateIndexes.contains(date) ? dateIndexes[date] : QVector<int>();
}

QVector<COMPDATData> COMPDATEntity::COMPDATList(QDateTime date){
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        if(project->Loaded())
        {
            QVector<COMPDATData> compdatList;

            QVector<int> indexes = GetIndexes(date);

            for(int i = 0; i < indexes.length(); i++) compdatList.append(compDAT[indexes[i]]);

            return compdatList;
        }
    }

    return QVector<COMPDATData>();
}

void COMPDATEntity::AddCOMPDAT(COMPDATData &data)
{
    QDateTime date = data.Date();

    if(!dateIndexes.contains(date)) dateIndexes[date] = QVector<int>();

    dateIndexes[date].append(compDAT.length());

    compDAT.append(data);
}

void COMPDATEntity::Clear()
{
    dateIndexes.clear();
    compDAT.clear();
}

}}}}
