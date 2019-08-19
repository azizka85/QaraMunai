#include <defaultvalues.h>

#include "wconprodentity.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

WCONPRODEntity::WCONPRODEntity(QObject *parent) : QObject (parent) { }

bool WCONPRODEntity::exist()
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        return project->IsLoaded() && project->Stratum().WCONPROD().length() > 0;
    }

    return false;
}

QVariantList WCONPRODEntity::getList(QDateTime date)
{
    QVariantList wconprodList;

    QList<WCONPRODData> list = WCONPRODList(date);

    QMetaObject metaObject = ProjectData::staticMetaObject;

    QMetaEnum wellStatusTypeEnum = metaObject.enumerator(metaObject.indexOfEnumerator("WellStatusType"));
    QMetaEnum wellControlModeEnum = metaObject.enumerator(metaObject.indexOfEnumerator("WellControlMode"));

    for(int i = 0; i < list.length(); i++)
    {
        QVariantMap map = list[i].toMap();

        map["wellStatus"] = QString(wellStatusTypeEnum.valueToKey(map["wellStatus"].toInt()));
        map["wellControl"] = QString(wellControlModeEnum.valueToKey(map["wellControl"].toInt()));

        wconprodList.append(map);
    }

    return wconprodList;
}

QList<WCONPRODData> WCONPRODEntity::WCONPRODList(QDateTime date)
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        if(project->IsLoaded())
        {
            QList<WCONPRODData> wconprodList;

            QList<WCONPRODData> list = project->Stratum().WCONPROD();

            for(int i = 0; i < list.length(); i++)
            {
                if(list[i].Date() == date) wconprodList.append(list[i]);
            }

            return wconprodList;
        }
    }

    return QList<WCONPRODData>();
}



}}}}
