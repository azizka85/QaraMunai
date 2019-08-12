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

QVariantList WCONINJEEntity::getList()
{
    QVariantList wconinjeList;

    QList<WCONINJEData> list = WCONINJEList();

    for(int i = 0; i < list.length(); i++) wconinjeList.append(list[i].toMap());

    return wconinjeList;
}

QList<WCONINJEData> WCONINJEEntity::WCONINJEList(){
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        if(project->IsLoaded()) return project->Stratum().WCONINJE();
    }

    return QList<WCONINJEData>();
}



}}}}
