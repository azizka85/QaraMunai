#include <defaultvalues.h>

#include "tabdimsentity.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

TABDIMSEntity::TABDIMSEntity(QObject *parent) : QObject (parent)
{
    initVariables();
}

QVariant TABDIMSEntity::NTSFUN() const
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        QVariant ntSFUN = project->Stratum().TABDIMS().NTSFUN();

        if(project->Loaded() && ntSFUN.isNull()) ntSFUN = DefaultValues::TABDIMS_NTSFUN;

        return ntSFUN;
    }

    return QVariant();
}

QVariant TABDIMSEntity::NTPVT() const
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        QVariant ntPVT = project->Stratum().TABDIMS().NTPVT();

        if(project->Loaded() && ntPVT.isNull()) ntPVT = DefaultValues::TABDIMS_NTPVT;

        return ntPVT;
    }

    return QVariant();
}

QVariant TABDIMSEntity::NSSFUN() const
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        QVariant nsSFUN = project->Stratum().TABDIMS().NSSFUN();

        if(project->Loaded() && nsSFUN.isNull()) nsSFUN = DefaultValues::TABDIMS_NSSFUN;

        return nsSFUN;
    }

    return QVariant();
}

void TABDIMSEntity::SetNTSFUN(const QVariant &ntSFUN)
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        project->Stratum().TABDIMS().SetNTSFUN(ntSFUN);

        NTSFUNChanged();
    }
}

void TABDIMSEntity::SetNTPVT(const QVariant &ntPVT)
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        project->Stratum().TABDIMS().SetNTPVT(ntPVT);

        NTPVTChanged();
    }
}

void TABDIMSEntity::SetNSSFUN(const QVariant &nsSFUN)
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        project->Stratum().TABDIMS().SetNSSFUN(nsSFUN);

        NSSFUNChanged();
    }
}

void TABDIMSEntity::initVariables()
{
    SetNTPVT(QVariant());
    SetNTSFUN(QVariant());
    SetNSSFUN(QVariant());
}

}}}}
