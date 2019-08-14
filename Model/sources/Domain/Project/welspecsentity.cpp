#include <defaultvalues.h>

#include "welspecsentity.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

WELSPECSEntity::WELSPECSEntity(QObject *parent) : QObject (parent) { }

bool WELSPECSEntity::exist()
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        return project->IsLoaded() && project->Stratum().WELSPECS().length() > 0;
    }

    return false;
}

QVariantList WELSPECSEntity::getList()
{
    QVariantList welspecsList;

    QList<WELSPECSData> list = WELSPECSList();

    for(int i = 0; i < list.length(); i++) welspecsList.append(list[i].toMap());

    return welspecsList;
}

QList<WELSPECSData> WELSPECSEntity::WELSPECSList(){
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        if(project->IsLoaded()) return project->Stratum().WELSPECS();
    }

    return QList<WELSPECSData>();
}



}}}}
