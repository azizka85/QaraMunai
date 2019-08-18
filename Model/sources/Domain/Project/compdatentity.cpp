#include <defaultvalues.h>

#include "compdatentity.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

COMPDATEntity::COMPDATEntity(QObject *parent) : QObject (parent) { }

bool COMPDATEntity::exist()
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        return project->IsLoaded() && project->Stratum().COMPDAT().length() > 0;
    }

    return false;
}

QVariantList COMPDATEntity::getList(QDateTime date)
{
    QVariantList compdatList;

    QList<COMPDATData> list = COMPDATList(date);

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

QList<COMPDATData> COMPDATEntity::COMPDATList(QDateTime date){
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        if(project->IsLoaded())
        {
            QList<COMPDATData> compdatList;

            QList<COMPDATData> list = project->Stratum().COMPDAT();

            for(int i = 0; i < list.length(); i++)
            {
                if(list[i].Date() == date) compdatList.append(list[i]);
            }

            return compdatList;
        }
    }

    return QList<COMPDATData>();
}

}}}}
