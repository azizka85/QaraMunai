#include <defaultvalues.h>

#include "swofentity.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

SWOFEntity::SWOFEntity(QObject *parent) : QObject (parent) { }

bool SWOFEntity::exist()
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        return project->Loaded() && project->Stratum().SWOF().length() > 0;
    }

    return false;
}

QVariantList SWOFEntity::getList(int region)
{
    QVariantList swofList;

    QVector<SWOFData> list = SWOFList(region);

    for(int i = 0; i < list.length(); i++) swofList.append(list[i].toMap());

    return swofList;
}

QVector<SWOFData> SWOFEntity::SWOFList(int region)
{
    QObject* projectData = parent();

    if (projectData != nullptr && region >= 0)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        if(project->Loaded() && project->Stratum().SWOF().length() > region) return project->Stratum().SWOF()[region];
    }

    return QVector<SWOFData>();
}

}}}}
