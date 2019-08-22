#include <defaultvalues.h>

#include "endscaleentity.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

ENDSCALEEntity::ENDSCALEEntity(QObject *parent) : QObject (parent)
{
    initVariables();
}

QVariant ENDSCALEEntity::Directional() const
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        QVariant directional = project->Stratum().ENDSCALE().Directional();

        if(project->Loaded() && directional.isNull()) directional = DefaultValues::ENDSCALE_Directional;

        return directional;
    }

    return QVariant();
}

QVariant ENDSCALEEntity::Irreversible() const
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        QVariant irreversible = project->Stratum().ENDSCALE().Irreversible();

        if(project->Loaded() && irreversible.isNull()) irreversible = DefaultValues::ENDSCALE_Irreversible;

        return irreversible;
    }

    return QVariant();
}

QVariant ENDSCALEEntity::NTENDP() const
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        QVariant ntENDP = project->Stratum().ENDSCALE().NTENDP();

        if(project->Loaded() && ntENDP.isNull()) ntENDP = DefaultValues::ENDSCALE_NTENDP;

        return ntENDP;
    }

    return QVariant();
}

QVariant ENDSCALEEntity::MaxNodesEPD() const
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        QVariant maxNodesEPD = project->Stratum().ENDSCALE().MaxNodesEPD();

        if(project->Loaded() && maxNodesEPD.isNull()) maxNodesEPD = DefaultValues::ENDSCALE_MaxNodesENDP;

        return maxNodesEPD;
    }

    return QVariant();
}

void ENDSCALEEntity::initVariables()
{
    SetDirectional(QVariant());
    SetIrreversible(QVariant());
    SetNTENDP(QVariant());
    SetMaxNodesEPD(QVariant());
}

void ENDSCALEEntity::SetDirectional(const QVariant &directional)
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        project->Stratum().ENDSCALE().SetDirectional(directional);

        DirectionalChanged();
    }
}

void ENDSCALEEntity::SetIrreversible(const QVariant &irreversible)
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        project->Stratum().ENDSCALE().SetIrreversible(irreversible);

        IrreversibleChanged();
    }
}

void ENDSCALEEntity::SetNTENDP(const QVariant &ntEPD)
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        project->Stratum().ENDSCALE().SetNTENDP(ntEPD);

        NTENDPChanged();
    }
}

void ENDSCALEEntity::SetMaxNodesEPD(const QVariant &maxNodesEPD)
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        project->Stratum().ENDSCALE().SetMaxNodesEPD(maxNodesEPD);

        MaxNodesEPDChanged();
    }
}

}}}}
