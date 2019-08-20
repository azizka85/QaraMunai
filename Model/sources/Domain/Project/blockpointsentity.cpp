#include <defaultvalues.h>

#include "blockpointsentity.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

BlockPointsEntity::BlockPointsEntity(QObject *parent) : QObject (parent) { initVariables(); }

bool BlockPointsEntity::hasNext()
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        if(project->IsLoaded() && cursor < project->Nx()*project->Ny()*project->Nz()) return true;
    }

    return false;
}

QVariantMap BlockPointsEntity::next()
{
    return nextBlock().toMap();
}

void BlockPointsEntity::toFront()
{
    cursor = 0;
    pointOrderStandard = true;

    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        int nx = project->Nx();
        int ny = project->Ny();

        if(project->IsLoaded() && project->Stratum().COORD().Count() > 0)
            pointOrderStandard = CheckPointOrderStandard(project->Stratum().COORD(), project->Stratum().ZCORN(), nx, ny);
    }

    current.InitVariables();
}

double BlockPointsEntity::cellVolume()
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        if(project->IsLoaded()) {

            QVariant val = project->Stratum().MULTPV()(current.I(), current.J(), current.K());

            double mult = val.isNull() ? 1 : val.toDouble();

            return mult * current.Volume();
        }
    }

    return 0;
}

double BlockPointsEntity::depth()
{
    return (current.P1().Z() + current.P2().Z() + current.P3().Z() + current.P4().Z() +
            current.P5().Z() + current.P6().Z() + current.P7().Z() + current.P8().Z()) / 8;
}

double BlockPointsEntity::porosity()
{
    return 0;
}

double BlockPointsEntity::ntg()
{
    return 0;
}

double BlockPointsEntity::poreVolume()
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        if(project->IsLoaded()) return cellVolume()*porosity()*ntg();
    }

    return  0;
}

double BlockPointsEntity::oilVolume()
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        if(project->IsLoaded())
        {
            QMetaObject metaObject = ProjectData::staticMetaObject;

            QMetaEnum unitsEnum = metaObject.enumerator(metaObject.indexOfEnumerator("UnitType"));

            int unit = project->Unit().isNull() ? DefaultValues::Unit : project->Unit().toInt();

            double cv = UnitHelper::ConvertVolume(static_cast<ProjectData::UnitType>(unit), ProjectData::LAB, 1, unitsEnum).toDouble();

            QVariant val = project->Stratum().PVTNUM()(current.I(), current.J(), current.K());

            int pvtNum = val.isNull() ? 1 : val.toInt();


        }
    }

    return  0;
}

Block &BlockPointsEntity::nextBlock()
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        int nx = project->Nx();
        int ny = project->Ny();
        int nz = project->Nz();

        if(project->IsLoaded() && cursor < nx*ny*nz)
        {
            int c = cursor;

            int k = c/nx/ny;

            c = c - k*nx*ny;

            int j = c/nx;
            int i = c - j*nx;

            double dx = project->dx(i, j, k);
            double dy = project->dy(i, j, k);
            double dz = project->dz(i, j, k);

            if(project->Stratum().TOPS().Count() > 0) CalcBlockByBCG(project->Stratum().TOPS(), i, j, k, dx, dy, dz);
            else if(project->Stratum().COORD().Count() > 0) CalcBlockByCPG(project->Stratum().COORD(), project->Stratum().ZCORN(), i, j, k, nx, ny);

            cursor++;
        }
    }

    return current;
}

void BlockPointsEntity::initVariables()
{
    cursor = 0;
    pointOrderStandard = true;
    current.InitVariables();
}

void BlockPointsEntity::CalcBlockByBCG(LinearMatrix2D &tops, int i, int j, int k, double dx, double dy, double dz)
{
    double x1 = 0;
    double y1 = 0;
    double z1 = 0;

    double x2 = 0;
    double y2 = 0;
    double z2 = 0;

    if(k == 0)
    {
        z1 = tops(i, j).toDouble();
        z2 = z1 + dz;
    }
    else if(current.K() < k)
    {
        z1 = current.P1().Z();
        z2 = z1 + dz;
    }
    else
    {
        z1 = current.P1().Z();
        z2 = current.P5().Z();
    }

    if(j == 0)
    {
        y1 = 0;
        y2 = y1 + dy;
    }
    else if(current.J() < j)
    {
        y1 = current.P1().Y();
        y2 = y1 + dy;
    }
    else
    {
        y1 = current.P1().Y();
        y2 = current.P3().Y();
    }

    if(i == 0)
    {
        x1 = 0;
        x2 = x1 + dx;
    }
    else if(current.I() < i)
    {
        x1 = current.P1().X();
        x2 = x1 + dx;
    }
    else
    {
        x1 = current.P1().X();
        x2 = current.P2().X();
    }

    current.SetI(i);
    current.SetJ(j);
    current.SetK(k);

    current.P1().SetX(x1); current.P1().SetY(y1); current.P1().SetZ(z1);
    current.P2().SetX(x2); current.P2().SetY(y1); current.P2().SetZ(z1);
    current.P3().SetX(x1); current.P3().SetY(y2); current.P3().SetZ(z1);
    current.P4().SetX(x2); current.P4().SetY(y2); current.P4().SetZ(z1);
    current.P5().SetX(x1); current.P5().SetY(y1); current.P5().SetZ(z2);
    current.P6().SetX(x2); current.P6().SetY(y1); current.P6().SetZ(z2);
    current.P7().SetX(x1); current.P7().SetY(y2); current.P7().SetZ(z2);
    current.P8().SetX(x2); current.P8().SetY(y2); current.P8().SetZ(z2);
}

bool BlockPointsEntity::CheckPointOrderStandard(LinearVector &coord, LinearVector &zcorn, int nx, int ny)
{
    Line3D coordLine;

    Point3D p1, p2, p3, p4;

    double d1, d2, d3, d4, d5, d6, d7, d8;

    CalcBlockDepths(zcorn, 0, 0, 0, nx, ny, d1, d2, d3, d4, d5, d6, d7, d8);

    CalcCoordLine(coord, 0, 0, nx, coordLine);

    MathHelper::IntersectZPlane(coordLine, d1, p1);

    CalcCoordLine(coord, 1, 0, nx, coordLine);

    MathHelper::IntersectZPlane(coordLine, d2, p2);

    CalcCoordLine(coord, 0, 1, nx, coordLine);

    MathHelper::IntersectZPlane(coordLine, d3, p3);

    CalcCoordLine(coord, 1, 1, nx, coordLine);

    MathHelper::IntersectZPlane(coordLine, d4, p4);

    return p1.X() <= p2.X() &&
            p3.X() <= p4.X() &&
            p1.Y() <= p3.Y() &&
            p2.Y() <= p4.Y();
}

void BlockPointsEntity::CalcCoordLine(LinearVector &coord, int i, int j, int nx, Line3D &coordLine)
{
    int cur = (j*(nx + 1) + i)*6;

    double x1 = coord(cur + 0).toDouble();
    double y1 = coord(cur + 1).toDouble();
    double z1 = coord(cur + 2).toDouble();

    double x2 = coord(cur + 3).toDouble();
    double y2 = coord(cur + 4).toDouble();
    double z2 = coord(cur + 5).toDouble();

    coordLine.P1().SetX(x1);
    coordLine.P1().SetY(y1);
    coordLine.P1().SetZ(z1);

    coordLine.P2().SetX(x2);
    coordLine.P2().SetY(y2);
    coordLine.P2().SetZ(z2);
}

void BlockPointsEntity::CalcBlockDepths(LinearVector &zcorn, int i, int j, int k, int nx, int ny,
                                        double& d1, double& d2, double& d3, double& d4, double& d5, double& d6, double& d7, double& d8)
{
    int cur = k*nx*ny + j*nx + 2*i;

    d1 = zcorn(cur + 0).toDouble();
    d2 = zcorn(cur + 1).toDouble();

    cur = k*nx*ny + 2*j*nx + 2*i;

    d3 = zcorn(cur + 0).toDouble();
    d4 = zcorn(cur + 1).toDouble();

    cur = 2*k*nx*ny + j*nx + 2*i;

    d5 = zcorn(cur + 0).toDouble();
    d6 = zcorn(cur + 1).toDouble();

    cur = 2*k*nx*ny + 2*j*nx + 2*i;

    d7 = zcorn(cur + 0).toDouble();
    d8 = zcorn(cur + 1).toDouble();
}

void BlockPointsEntity::CalcBlockByCPG(LinearVector &coord, LinearVector &zcorn, int i, int j, int k, int nx, int ny)
{
    current.SetI(i);
    current.SetJ(j);
    current.SetK(k);

    Line3D coordLine;

    double d1, d2, d3, d4, d5, d6, d7, d8;

    CalcBlockDepths(zcorn, i, j, k, nx, ny, d1, d2, d3, d4, d5, d6, d7, d8);

    if(pointOrderStandard)
    {
        CalcCoordLine(coord, i, j, nx, coordLine);

        MathHelper::IntersectZPlane(coordLine, d1, current.P1());
        MathHelper::IntersectZPlane(coordLine, d5, current.P5());

        CalcCoordLine(coord, i+1, j, nx, coordLine);

        MathHelper::IntersectZPlane(coordLine, d2, current.P2());
        MathHelper::IntersectZPlane(coordLine, d6, current.P6());

        CalcCoordLine(coord, i, j+1, nx, coordLine);

        MathHelper::IntersectZPlane(coordLine, d3, current.P3());
        MathHelper::IntersectZPlane(coordLine, d7, current.P7());

        CalcCoordLine(coord, i+1, j+1, nx, coordLine);

        MathHelper::IntersectZPlane(coordLine, d4, current.P4());
        MathHelper::IntersectZPlane(coordLine, d8, current.P8());
    }
    else
    {
        CalcCoordLine(coord, i, j, nx, coordLine);

        MathHelper::IntersectZPlane(coordLine, d1, current.P8());
        MathHelper::IntersectZPlane(coordLine, d5, current.P4());

        CalcCoordLine(coord, i+1, j, nx, coordLine);

        MathHelper::IntersectZPlane(coordLine, d2, current.P7());
        MathHelper::IntersectZPlane(coordLine, d6, current.P3());

        CalcCoordLine(coord, i, j+1, nx, coordLine);

        MathHelper::IntersectZPlane(coordLine, d3, current.P6());
        MathHelper::IntersectZPlane(coordLine, d7, current.P2());

        CalcCoordLine(coord, i+1, j+1, nx, coordLine);

        MathHelper::IntersectZPlane(coordLine, d4, current.P5());
        MathHelper::IntersectZPlane(coordLine, d8, current.P1());
    }
}

}}}}
