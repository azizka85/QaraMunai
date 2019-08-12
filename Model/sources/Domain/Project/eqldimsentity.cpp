#include <defaultvalues.h>

#include "eqldimsentity.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

EQLDIMSEntity::EQLDIMSEntity(QObject *parent) : QObject (parent)
{
    initVariables();
}

QVariant EQLDIMSEntity::NTEQUL() const
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        QVariant ntEQUL = project->Stratum().EQLDIMS().NTEQUL();

        if(project->IsLoaded() && ntEQUL.isNull()) ntEQUL = DefaultValues::EQLDIMS_NTEQUL;

        return ntEQUL;
    }

    return QVariant();
}

void EQLDIMSEntity::SetNTEQUL(const QVariant &ntEQUL)
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        project->Stratum().EQLDIMS().SetNTEQUL(ntEQUL);

        NTEQULChanged();
    }
}

void EQLDIMSEntity::initVariables()
{
    SetNTEQUL(QVariant());
}

}}}}
