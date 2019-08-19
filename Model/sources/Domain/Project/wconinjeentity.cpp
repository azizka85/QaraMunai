#include <defaultvalues.h>

#include "wconinjeentity.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

WCONINJEEntity::WCONINJEEntity(QObject *parent) : QObject (parent) { }

bool WCONINJEEntity::exist()
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        return project->IsLoaded() && project->Stratum().WCONINJE().length() > 0;
    }

    return false;
}

QVariantList WCONINJEEntity::getList(QDateTime date)
{
    QVariantList wconinjeList;

    QList<WCONINJEData> list = WCONINJEList(date);

    QMetaObject metaObject = ProjectData::staticMetaObject;

    QMetaEnum wellStatusTypeEnum = metaObject.enumerator(metaObject.indexOfEnumerator("WellStatusType"));
    QMetaEnum wellControlModeEnum = metaObject.enumerator(metaObject.indexOfEnumerator("WellControlMode"));
    QMetaEnum fluidTypeEnum = metaObject.enumerator(metaObject.indexOfEnumerator("FluidType"));

    for(int i = 0; i < list.length(); i++)
    {
        QVariantMap map = list[i].toMap();

        map["wellStatus"] = QString(wellStatusTypeEnum.valueToKey(map["wellStatus"].toInt()));
        map["wellControl"] = QString(wellControlModeEnum.valueToKey(map["wellControl"].toInt()));
        map["injFluid"] = QString(fluidTypeEnum.valueToKey(map["injFluid"].toInt()));

        wconinjeList.append(map);
    }

    return wconinjeList;
}

QList<WCONINJEData> WCONINJEEntity::WCONINJEList(QDateTime date){
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        if(project->IsLoaded())
        {
            QList<WCONINJEData> wconinjeList;

            QList<WCONINJEData> list = project->Stratum().WCONINJE();

            for(int i = 0; i < list.length(); i++)
            {
                if(list[i].Date() == date) wconinjeList.append(list[i]);
            }

            return wconinjeList;
        }
    }

    return QList<WCONINJEData>();
}



}}}}
