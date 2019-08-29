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

        if(project->Loaded() && cursor < project->Nx()*project->Ny()*project->Nz()) return true;
    }

    return false;
}

QVariantMap BlockPointsEntity::next()
{
    return nextBlock().toMap();
}

void BlockPointsEntity::toFront()
{
    initVariables();
}

double BlockPointsEntity::cellVolume()
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        if(project->Loaded()) {

            QVariant val = project->Stratum().MULTPV()(current.I(), current.J(), current.K());

            double mult = val.isNull() ? 1 : val.toDouble();

            return mult * current.Volume();
        }
    }

    return 0;
}

double BlockPointsEntity::tranX()
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        if(project->Loaded())
        {
            int u = project->Unit().isNull() ? DefaultValues::Unit : project->Unit().toInt();

            double Kc = UnitHelper::DarcyTable[u];

            double dxc = project->dx(current.I(), current.J(), current.K());
            double dyc = project->dy(current.I(), current.J(), current.K());
            double dzc = project->dz(current.I(), current.J(), current.K());
            double ntgc = project->ntg(current.I(), current.J(), current.K());
            double depthc = project->depth(current.I(), current.J(), current.K());
            double permXc = project->permX(current.I(), current.J(), current.K());

            double dxl = project->dx(current.I()-1, current.J(), current.K());
            double dyl = project->dy(current.I()-1, current.J(), current.K());
            double dzl = project->dz(current.I()-1, current.J(), current.K());
            double ntgl = project->ntg(current.I()-1, current.J(), current.K());
            double depthl = project->depth(current.I()-1, current.J(), current.K());
            double permXl = project->permX(current.I()-1, current.J(), current.K());

            if(project->BlockCentered())
            {
                if (project->actnum(current.I(), current.J(), current.K()) && project->actnum(current.I() - 1, current.J(), current.K()))
                {
                    double dx1 = dxl;
                    double dy1 = dyl;
                    double dz1 = dzl;
                    double ntg1 = ntgl;
                    double depth1 = depthl;
                    double permx1 = permXl;

                    double dx2 = dxc;
                    double dy2 = dyc;
                    double dz2 = dzc;
                    double ntg2 = ntgc;
                    double depth2 = depthc;
                    double permx2 = permXc;

                    double A = (dx1 * dy1 * dz1 * ntg1 + dx2 * dy2 * dz2 * ntg2) / (dx1 + dx2);
                    double D = ((dx1 + dx2) * (dx1 + dx2) / 4) / ((dx1 + dx2) * (dx1 + dx2) / 4 + (depth1 - depth2) * (depth1 - depth2));
                    double B = (dx1 / permx1 + dx2 / permx2) / 2;

                    return Kc * A * D / B;
                }
            }
            else
            {
                Point3D myBlockCenter = MathHelper::GetMassCenter(current.P1(), current.P2(), current.P3(), current.P4(),
                                                                  current.P5(), current.P6(), current.P7(), current.P8());

                if (project->actnum(current.I(), current.J(), current.K()) && project->actnum(current.I() - 1, current.J(), current.K()))
                {
                    Plane contactPlane(current.P1(), current.P3(), current.P5());

                    Point3D contactAreaCenter;

                    Block lBlock = project->GetBlock(current.I()-1, current.J(), current.K());

                    double a = MathHelper::GetContactArea(current.P5(), current.P1(), current.P7(), current.P3(),
                                                            lBlock.P6(), lBlock.P2(), lBlock.P8(), lBlock.P4(), contactAreaCenter);

                    Point3D hisBlockCenter = MathHelper::GetMassCenter(lBlock.P1(), lBlock.P2(), lBlock.P3(), lBlock.P4(),
                                                                       lBlock.P5(), lBlock.P6(), lBlock.P7(), lBlock.P8());

                    Point3D pc1 = contactAreaCenter;
                    Point3D pc2 = contactAreaCenter;

                    Point3D d1 = MathHelper::Subtract(pc1, myBlockCenter);
                    Point3D d2 = MathHelper::Subtract(pc2, hisBlockCenter);

                    Plane planeYZ = MathHelper::PlaneYZ();
                    Plane planeXZ = MathHelper::PlaneXZ();
                    Plane planeXY = MathHelper::PlaneXY();

                    double ax = a * MathHelper::CosBetweenPlanes(contactPlane, planeYZ);
                    double ay = a * MathHelper::CosBetweenPlanes(contactPlane, planeXZ);
                    double az = a * MathHelper::CosBetweenPlanes(contactPlane, planeXY);

                    double koef1 = (ax * qAbs(d1.X()) + ay * qAbs(d1.Y()) + az * qAbs(d1.Z())) / (d1.X() * d1.X() + d1.Y() * d1.Y() + d1.Z() * d1.Z());
                    double koef2 = (ax * qAbs(d2.X()) + ay * qAbs(d2.Y()) + az * qAbs(d2.Z())) / (d2.X() * d2.X() + d2.Y() * d2.Y() + d2.Z() * d2.Z());

                    double tx = Kc * 1.0 / (1.0 / (permXc * ntgc * koef1) + 1.0 / (permXl * ntgl * koef2));


                    return ISEQUAL(a, 0) ? 0 : tx;
                }
            }
        }
    }

    return 0;
}

double BlockPointsEntity::tranY()
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        if(project->Loaded())
        {
            int u = project->Unit().isNull() ? DefaultValues::Unit : project->Unit().toInt();

            double Kc = UnitHelper::DarcyTable[u];

            double dxc = project->dx(current.I(), current.J(), current.K());
            double dyc = project->dy(current.I(), current.J(), current.K());
            double dzc = project->dz(current.I(), current.J(), current.K());
            double ntgc = project->ntg(current.I(), current.J(), current.K());
            double depthc = project->depth(current.I(), current.J(), current.K());
            double permYc = project->permY(current.I(), current.J(), current.K());

            double dxd = project->dx(current.I(), current.J()-1, current.K());
            double dyd = project->dy(current.I(), current.J()-1, current.K());
            double dzd = project->dz(current.I(), current.J()-1, current.K());
            double ntgd = project->ntg(current.I(), current.J()-1, current.K());
            double depthd = project->depth(current.I(), current.J()-1, current.K());
            double permYd = project->permY(current.I(), current.J()-1, current.K());

            if(project->BlockCentered())
            {
                if (project->actnum(current.I(), current.J(), current.K()) && project->actnum(current.I(), current.J() - 1, current.K()))
                {
                    double dx1 = dxd;
                    double dy1 = dyd;
                    double dz1 = dzd;
                    double ntg1 = ntgd;
                    double depth1 = depthd;
                    double permy1 = permYd;

                    double dx2 = dxc;
                    double dy2 = dyc;
                    double dz2 = dzc;
                    double ntg2 = ntgc;
                    double depth2 = depthc;
                    double permy2 = permYc;

                    double A = (dx1 * dy1 * dz1 * ntg1 + dx2 * dy2 * dz2 * ntg2) / (dy1 + dy2);
                    double D = ((dy1 + dy2) * (dy1 + dy2) / 4) / ((dy1 + dy2) * (dy1 + dy2) / 4 + (depth1 - depth2) * (depth1 - depth2));
                    double B = (dy1 / permy1 + dy2 / permy2) / 2;

                    return Kc * A * D / B;
                }
            }
            else
            {
                Point3D myBlockCenter = MathHelper::GetMassCenter(current.P1(), current.P2(), current.P3(), current.P4(),
                                                                  current.P5(), current.P6(), current.P7(), current.P8());

                if (project->actnum(current.I(), current.J(), current.K()) && project->actnum(current.I(), current.J() - 1, current.K()))
                {
                    Plane contactPlane(current.P1(), current.P2(), current.P6());

                    Point3D contactAreaCenter;

                    Block dBlock = project->GetBlock(current.I(), current.J()-1, current.K());

                    double a = MathHelper::GetContactArea(current.P5(), current.P1(), current.P6(), current.P2(),
                                                            dBlock.P7(), dBlock.P3(), dBlock.P8(), dBlock.P4(), contactAreaCenter);

                    Point3D hisBlockCenter = MathHelper::GetMassCenter(dBlock.P1(), dBlock.P2(), dBlock.P3(), dBlock.P4(),
                                                                       dBlock.P5(), dBlock.P6(), dBlock.P7(), dBlock.P8());

                    Point3D pc1 = contactAreaCenter;
                    Point3D pc2 = contactAreaCenter;

                    Point3D d1 = MathHelper::Subtract(pc1, myBlockCenter);
                    Point3D d2 = MathHelper::Subtract(pc2, hisBlockCenter);

                    Plane planeYZ = MathHelper::PlaneYZ();
                    Plane planeXZ = MathHelper::PlaneXZ();
                    Plane planeXY = MathHelper::PlaneXY();

                    double ax = a * MathHelper::CosBetweenPlanes(contactPlane, planeYZ);
                    double ay = a * MathHelper::CosBetweenPlanes(contactPlane, planeXZ);
                    double az = a * MathHelper::CosBetweenPlanes(contactPlane, planeXY);

                    double koef1 = (ax * qAbs(d1.X()) + ay * qAbs(d1.Y()) + az * qAbs(d1.Z())) / (d1.X() * d1.X() + d1.Y() * d1.Y() + d1.Z() * d1.Z());
                    double koef2 = (ax * qAbs(d2.X()) + ay * qAbs(d2.Y()) + az * qAbs(d2.Z())) / (d2.X() * d2.X() + d2.Y() * d2.Y() + d2.Z() * d2.Z());

                    double ty = Kc * 1.0 / (1.0 / (permYc * ntgc * koef1) + 1.0 / (permYd * ntgd * koef2));


                    return ISEQUAL(a, 0) ? 0 : ty;
                }
            }
        }
    }

    return 0;
}

double BlockPointsEntity::tranZ()
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        if(project->Loaded())
        {
            int u = project->Unit().isNull() ? DefaultValues::Unit : project->Unit().toInt();

            double Kc = UnitHelper::DarcyTable[u];

            double dxc = project->dx(current.I(), current.J(), current.K());
            double dyc = project->dy(current.I(), current.J(), current.K());
            double dzc = project->dz(current.I(), current.J(), current.K());
            double permZc = project->permZ(current.I(), current.J(), current.K());

            double dxb = project->dx(current.I(), current.J(), current.K()-1);
            double dyb = project->dy(current.I(), current.J(), current.K()-1);
            double dzb = project->dz(current.I(), current.J(), current.K()-1);
            double permZb = project->permZ(current.I(), current.J(), current.K()-1);

            if(project->BlockCentered())
            {
                if (project->actnum(current.I(), current.J(), current.K()) && project->actnum(current.I(), current.J(), current.K() - 1))
                {
                    double dx1 = dxb;
                    double dy1 = dyb;
                    double dz1 = dzb;
                    double permz1 = permZb;

                    double dx2 = dxc;
                    double dy2 = dyc;
                    double dz2 = dzc;
                    double permz2 = permZc;

                    double A = (dx1 * dy1 * dz1 + dx2 * dy2 * dz2) / (dz1 + dz2);
                    double B = (dz1 / permz1 + dz2 / permz2) / 2;

                    return Kc * A / B;
                }
            }
            else
            {
                Point3D myBlockCenter = MathHelper::GetMassCenter(current.P1(), current.P2(), current.P3(), current.P4(),
                                                                  current.P5(), current.P6(), current.P7(), current.P8());

                if (project->actnum(current.I(), current.J(), current.K()) && project->actnum(current.I(), current.J(), current.K() - 1))
                {
                    Plane contactPlane(current.P1(), current.P2(), current.P4());

                    QList<Point3D> p = { current.P1(), current.P2(), current.P4(), current.P3() };

                    Point3D contactAreaCenter = MathHelper::GetAveragePoint(p);

                    Block bBlock = project->GetBlock(current.I(), current.J(), current.K()-1);

                    double a = MathHelper::GetTetragonArea(current.P1(), current.P2(), current.P4(), current.P3());

                    Point3D hisBlockCenter = MathHelper::GetMassCenter(bBlock.P1(), bBlock.P2(), bBlock.P3(), bBlock.P4(),
                                                                       bBlock.P5(), bBlock.P6(), bBlock.P7(), bBlock.P8());

                    Point3D pc1 = contactAreaCenter;
                    Point3D pc2 = contactAreaCenter;

                    Point3D d1 = MathHelper::Subtract(pc1, myBlockCenter);
                    Point3D d2 = MathHelper::Subtract(pc2, hisBlockCenter);

                    Plane planeYZ = MathHelper::PlaneYZ();
                    Plane planeXZ = MathHelper::PlaneXZ();
                    Plane planeXY = MathHelper::PlaneXY();

                    double ax = a * MathHelper::CosBetweenPlanes(contactPlane, planeYZ);
                    double ay = a * MathHelper::CosBetweenPlanes(contactPlane, planeXZ);
                    double az = a * MathHelper::CosBetweenPlanes(contactPlane, planeXY);

                    double koef1 = (ax * qAbs(d1.X()) + ay * qAbs(d1.Y()) + az * qAbs(d1.Z())) / (d1.X() * d1.X() + d1.Y() * d1.Y() + d1.Z() * d1.Z());
                    double koef2 = (ax * qAbs(d2.X()) + ay * qAbs(d2.Y()) + az * qAbs(d2.Z())) / (d2.X() * d2.X() + d2.Y() * d2.Y() + d2.Z() * d2.Z());

                    double tz = Kc * 1.0 / (1.0 / (permZc * koef1) + 1.0 / (permZb * koef2));


                    return ISEQUAL(a, 0) ? 0 : tz;
                }
            }
        }
    }

    return 0;
}

bool BlockPointsEntity::actnum()
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        if(project->Loaded()) {

            bool val = project->actnum(current.I(), current.J(), current.K());

            double cPoreVolume = poreVolume();

            if(val && cPoreVolume >= 0 && project->Stratum().MINPVV().Count() > 0)
                val = cPoreVolume > project->Stratum().MINPVV()(current.I(), current.J(), current.K()).toDouble();

            if(val && cPoreVolume >= 0) val = cPoreVolume > project->Stratum().MINPV();
        }
    }

    return false;
}

double BlockPointsEntity::soil()
{
    return 0;
}

double BlockPointsEntity::swat()
{
    return 0;
}

double BlockPointsEntity::sgas()
{
    return 0;
}

double BlockPointsEntity::pressure()
{
    return 0;
}

double BlockPointsEntity::pw()
{
    return 0;
}

double BlockPointsEntity::poreVolume()
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        if(project->Loaded()) {

            QVariant val = project->Stratum().MULTPV()(current.I(), current.J(), current.K());

            double mult = val.isNull() ? 1 : val.toDouble();

            double porosity = project->poro(current.I(), current.J(), current.K());
            double ntg = project->ntg(current.I(), current.J(), current.K());

            return mult * current.Volume() * porosity * ntg;
        }
    }

    return 0;
}

double BlockPointsEntity::oilVolume()
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        if(project->Loaded())
        {
            QMetaObject metaObject = ProjectData::staticMetaObject;

            QMetaEnum unitsEnum = metaObject.enumerator(metaObject.indexOfEnumerator("UnitType"));

            int unit = project->Unit().isNull() ? DefaultValues::Unit : project->Unit().toInt();

            double cv = UnitHelper::ConvertVolume(static_cast<ProjectData::UnitType>(unit), ProjectData::LAB, 1, unitsEnum).toDouble();

            int pvtNum = project->pvtNUM(current.I(), current.J(), current.K());

            double bo = DataHelper::CalculateBoFromPVT(project->Stratum(), pressure(), pvtNum);

            return cv*poreVolume()*(1 - swat())/bo;
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

        if(project->Loaded() && cursor < nx*ny*nz)
        {
            int c = cursor;

            int k = c/nx/ny;

            c = c - k*nx*ny;

            int j = c/nx;
            int i = c - j*nx;

            if(project->BlockCentered()) CalcBlockByBCG(project, i, j, k);
            else CalcBlockByCPG(project, i, j, k);

            cursor++;
        }
    }

    return current;
}

void BlockPointsEntity::initVariables()
{
    cursor = 0;
    current.InitVariables();
}

void BlockPointsEntity::CalcBlockByBCG(ProjectData* project, int i, int j, int k)
{
    double x1 = 0;
    double y1 = 0;
    double z1 = 0;

    double x2 = 0;
    double y2 = 0;
    double z2 = 0;

    double dx = project->dx(i, j, k);
    double dy = project->dy(i, j, k);
    double dz = project->dz(i, j, k);

    if(k == 0)
    {
        z1 = project->tops(i, j);
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

void BlockPointsEntity::CalcBlockByCPG(ProjectData *project, int i, int j, int k)
{
    Line3D coordLine;

    double d1, d2, d3, d4, d5, d6, d7, d8;

    project->CalcBlockDepths(i, j, k, d1, d2, d3, d4, d5, d6, d7, d8);

    current.SetI(i);
    current.SetJ(j);
    current.SetK(k);

    if(project->PointOrderStandard())
    {
        project->CalcCoordLine(i, j, coordLine);

        MathHelper::IntersectZPlane(coordLine, d1, current.P1());
        MathHelper::IntersectZPlane(coordLine, d5, current.P5());

        project->CalcCoordLine(i+1, j, coordLine);

        MathHelper::IntersectZPlane(coordLine, d2, current.P2());
        MathHelper::IntersectZPlane(coordLine, d6, current.P6());

        project->CalcCoordLine(i, j+1, coordLine);

        MathHelper::IntersectZPlane(coordLine, d3, current.P3());
        MathHelper::IntersectZPlane(coordLine, d7, current.P7());

        project->CalcCoordLine(i+1, j+1, coordLine);

        MathHelper::IntersectZPlane(coordLine, d4, current.P4());
        MathHelper::IntersectZPlane(coordLine, d8, current.P8());
    }
    else
    {
        project->CalcCoordLine(i, j, coordLine);

        MathHelper::IntersectZPlane(coordLine, d1, current.P8());
        MathHelper::IntersectZPlane(coordLine, d5, current.P4());

        project->CalcCoordLine(i+1, j, coordLine);

        MathHelper::IntersectZPlane(coordLine, d2, current.P7());
        MathHelper::IntersectZPlane(coordLine, d6, current.P3());

        project->CalcCoordLine(i, j+1, coordLine);

        MathHelper::IntersectZPlane(coordLine, d3, current.P6());
        MathHelper::IntersectZPlane(coordLine, d7, current.P2());

        project->CalcCoordLine(i+1, j+1, coordLine);

        MathHelper::IntersectZPlane(coordLine, d4, current.P5());
        MathHelper::IntersectZPlane(coordLine, d8, current.P1());
    }
}

}}}}
