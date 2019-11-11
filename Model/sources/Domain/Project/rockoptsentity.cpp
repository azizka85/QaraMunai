#include <defaultvalues.h>

#include "rockoptsentity.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

ROCKOPTSEntity::ROCKOPTSEntity(QObject *parent) : QObject (parent)
{
    initVariables();
}

QVariant ROCKOPTSEntity::MAOTP()
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        QVariant maotp = project->Stratum().ROCKOPTS().MAOTP();

        if(project->State() != ProjectData::CLOSED && maotp.isNull()) maotp = DefaultValues::ROCKOPTS_MAOTP;

        return maotp;
    }

    return QVariant();
}

QVariant ROCKOPTSEntity::RPO()
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        QVariant rpo = project->Stratum().ROCKOPTS().RPO();

        if(project->State() != ProjectData::CLOSED && rpo.isNull()) rpo = DefaultValues::ROCKOPTS_RPO;

        return rpo;
    }

    return QVariant();
}

QVariant ROCKOPTSEntity::RegionOption()
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        QVariant regionOption = project->Stratum().ROCKOPTS().RegionOption();

        if(project->State() != ProjectData::CLOSED && regionOption.isNull()) regionOption = DefaultValues::ROCKOPTS_RegionOption;

        return regionOption;
    }

    return QVariant();
}

QVariant ROCKOPTSEntity::IHBOption()
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        QVariant ihbOption = project->Stratum().ROCKOPTS().IHBOption();

        if(project->State() != ProjectData::CLOSED && ihbOption.isNull()) ihbOption = DefaultValues::ROCKOPTS_IHBOption;

        return ihbOption;
    }

    return QVariant();
}

void ROCKOPTSEntity::initVariables()
{
    SetMAOTP(QVariant());
    SetRPO(QVariant());
    SetRegionOption(QVariant());
    SetIHBOption(QVariant());
}

void ROCKOPTSEntity::SetMAOTP(const QVariant &maotp)
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        project->Stratum().ROCKOPTS().SetMAOTP(maotp);

        MAOTPChanged();
    }
}

void ROCKOPTSEntity::SetRPO(const QVariant &rpo)
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        project->Stratum().ROCKOPTS().SetRPO(rpo);

        RPOChanged();
    }
}

void ROCKOPTSEntity::SetRegionOption(const QVariant &regionOption)
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        project->Stratum().ROCKOPTS().SetRegionOption(regionOption);

        RegionOptionChanged();
    }
}

void ROCKOPTSEntity::SetIHBOption(const QVariant &ihbOption)
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        project->Stratum().ROCKOPTS().SetIHBOption(ihbOption);

        IHBOptionChanged();
    }
}

}}}}
