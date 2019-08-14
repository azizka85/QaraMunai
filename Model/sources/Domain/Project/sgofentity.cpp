#include <defaultvalues.h>

#include "sgofentity.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

SGOFEntity::SGOFEntity(QObject *parent) : QObject (parent) { }

bool SGOFEntity::exist()
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        return project->IsLoaded() && project->Stratum().SGOF().length() > 0;
    }

    return false;
}

QVariantList SGOFEntity::getList(int region)
{
    QVariantList swofList;

    QList<SGOFData> list = SGOFList(region);

    for(int i = 0; i < list.length(); i++) swofList.append(list[i].toMap());

    return swofList;
}

QList<SGOFData> SGOFEntity::SGOFList(int region)
{
    QObject* projectData = parent();

    if (projectData != nullptr && region >= 0)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        if(project->IsLoaded() && project->Stratum().SGOF().length() > region) return project->Stratum().SGOF()[region];
    }

    return QList<SGOFData>();
}



}}}}
