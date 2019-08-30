#include <defaultvalues.h>

#include "pvtgentity.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

PVTGEntity::PVTGEntity(QObject *parent) : QObject (parent) { }

bool PVTGEntity::exist()
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        return project->Loaded() && project->Stratum().PVTO().length() > 0;
    }

    return false;
}

QVariantList PVTGEntity::getList(int region)
{
    QVariantList pvtgList;

    QVector<PVTGData> list = PVTGList(region);

    for(int i = 0; i < list.length(); i++) pvtgList.append(list[i].toMap());

    return pvtgList;
}

QVector<PVTGData> PVTGEntity::PVTGList(int region)
{
    QObject* projectData = parent();

    if (projectData != nullptr && region >= 0)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        if(project->Loaded() && project->Stratum().PVTG().length() > region) return project->Stratum().PVTG()[region];
    }

    return QVector<PVTGData>();
}



}}}}
