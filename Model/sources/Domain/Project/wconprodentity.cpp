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

QVariantList WCONPRODEntity::getList()
{
    QVariantList wconprodList;

    QList<WCONPRODData> list = WCONPRODList();

    for(int i = 0; i < list.length(); i++) wconprodList.append(list[i].toMap());

    return wconprodList;
}

QList<WCONPRODData> WCONPRODEntity::WCONPRODList(){
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        if(project->IsLoaded()) return project->Stratum().WCONPROD();
    }

    return QList<WCONPRODData>();
}



}}}}
