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

QVariantList COMPDATEntity::getList()
{
    QVariantList compdatList;

    QList<COMPDATData> list = COMPDATList();

    for(int i = 0; i < list.length(); i++) compdatList.append(list[i].toMap());

    return compdatList;
}

QList<COMPDATData> COMPDATEntity::COMPDATList(){
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        if(project->IsLoaded()) return project->Stratum().COMPDAT();
    }

    return QList<COMPDATData>();
}

}}}}
