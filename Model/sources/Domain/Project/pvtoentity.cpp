#include <defaultvalues.h>

#include "pvtoentity.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

PVTOEntity::PVTOEntity(QObject *parent) : QObject (parent) { }

bool PVTOEntity::exist()
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        return project->State() != ProjectData::CLOSED && project->Stratum().PVTO().length() > 0;
    }

    return false;
}

QVariantList PVTOEntity::getList(int region)
{
    QVariantList pvtoList;

    QVector<PVTOData> list = PVTOList(region);

    for(int i = 0; i < list.length(); i++) pvtoList.append(list[i].toMap());

    return pvtoList;
}

QVector<PVTOData> PVTOEntity::PVTOList(int region)
{
    QObject* projectData = parent();

    if (projectData != nullptr && region >= 0)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        if(project->State() != ProjectData::CLOSED && project->Stratum().PVTO().length() > region) return project->Stratum().PVTO()[region];
    }

    return QVector<PVTOData>();
}



}}}}
