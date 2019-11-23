#include <unithelper.h>
#include <mathhelper.h>
#include <datahelper.h>

#include <defaultvalues.h>

#include "projectdata.h"

using namespace QaraMunai::Model::Helpers;

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

ProjectData::ProjectData(QObject *parent) : QObject(parent)
{
    tabDIMS = new TABDIMSEntity(this);
    eqlDIMS = new EQLDIMSEntity(this);
    endSCALE = new ENDSCALEEntity(this);

    rockOPTS = new ROCKOPTSEntity(this);

    swof = new SWOFEntity(this);
    sgof = new SGOFEntity(this);

    pvto = new PVTOEntity(this);
    pvtg = new PVTGEntity(this);

    welspecs = new WELSPECSEntity(this);
    compdat = new COMPDATEntity(this);
    wconprod = new WCONPRODEntity(this);
    wconinje = new WCONINJEEntity(this);

    copy = new COPYEntity(this);
    add = new ADDEntity(this);
    equals = new EQUALSEntity(this);
    multiply = new MULTIPLYEntity(this);

    initVariables();
}

ProjectData::ProjectState ProjectData::State() const
{
    return state;
}

QString ProjectData::Title() const
{
    return title;
}

QDateTime ProjectData::StartDate() const
{
    return startDate;
}

QVariant ProjectData::Unit() const
{
    return unit;
}

QVariant ProjectData::Model() const
{
    return model;
}

QVariant ProjectData::TemperatureOption() const
{
    return temperatureOption;
}

QVariant ProjectData::NumRES() const
{
    return numRES;
}

int ProjectData::Nx() const
{
    return nx;
}

int ProjectData::Ny() const
{
    return ny;
}

int ProjectData::Nz() const
{
    return nz;
}

bool ProjectData::BlockCentered() const
{
    return isBlockCentered;
}

double ProjectData::dx(int i, int j, int k)
{
    double val = 0;

    if(stratum.DX().Box().Contains(i, j, k))
        val = stratum.DX()(i, j, k).toDouble();

    if(stratum.DXV().Count() > i)
        val = stratum.DXV()(i).toDouble();

    QVariant value = DataHelper::GetEQUALSData(equals, "DX", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    value = DataHelper::GetCOPYData(copy, stratum, "DX", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    DataHelper::MULTIPLYValue(multiply, "DX", val, i, j, k);

    DataHelper::ADDValue(add, "DX", val, i, j, k);

    return val;
}

double ProjectData::dy(int i, int j, int k)
{
    double val = 0;

    if(stratum.DY().Box().Contains(i, j, k))
        val = stratum.DY()(i, j, k).toDouble();

    if(stratum.DYV().Count() > j)
        val = stratum.DYV()(j).toDouble();

    QVariant value = DataHelper::GetEQUALSData(equals, "DY", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    value = DataHelper::GetCOPYData(copy, stratum, "DY", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    DataHelper::MULTIPLYValue(multiply, "DY", val, i, j, k);

    DataHelper::ADDValue(add, "DY", val, i, j, k);

    return val;
}

double ProjectData::dz(int i, int j, int k)
{
    double val = 0;

    if(stratum.DZ().Box().Contains(i, j, k))
        val = stratum.DZ()(i, j, k).toDouble();

    if(stratum.DZV().Count() > k)
        val = stratum.DZV()(k).toDouble();

    QVariant value = DataHelper::GetEQUALSData(equals, "DZ", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    value = DataHelper::GetCOPYData(copy, stratum, "DZ", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    DataHelper::MULTIPLYValue(multiply, "DZ", val, i, j, k);

    DataHelper::ADDValue(add, "DZ", val, i, j, k);

    return val;
}

double ProjectData::tops(int i, int j)
{
    double val = 0;

    if(stratum.TOPS().Box().Contains(i, j, 0))
        val = stratum.TOPS()(i, j, 0).toDouble();

    QVariant value = DataHelper::GetEQUALSData(equals, "TOPS", i, j, 0);

    val = !value.isNull() ? value.toDouble() : val;

    value = DataHelper::GetCOPYData(copy, stratum, "TOPS", i, j, 0);

    val = !value.isNull() ? value.toDouble() : val;

    DataHelper::MULTIPLYValue(multiply, "TOPS", val, i, j, 0);

    DataHelper::ADDValue(add, "TOPS", val, i, j, 0);

    return val;
}

double ProjectData::depth(int i, int j, int k)
{
    double val = 0;

    if(stratum.DEPTH().Box().Contains(i, j, k))
        val = stratum.DEPTH()(i, j, k).toDouble();

    QVariant value = DataHelper::GetEQUALSData(equals, "DEPTH", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    value = DataHelper::GetCOPYData(copy, stratum, "DEPTH", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    DataHelper::MULTIPLYValue(multiply, "DEPTH", val, i, j, k);

    DataHelper::ADDValue(add, "DEPTH", val, i, j, k);

    return val;
}

QVariant ProjectData::block(int i, int j, int k, double x0, double y0, double z0)
{
    return GetBlock(i, j, k, x0, y0, z0).toMap();
}

double ProjectData::poro(int i, int j, int k)
{
    double val = 0;

    if(stratum.PORO().Box().Contains(i, j, k))
        val = stratum.PORO()(i, j, k).toDouble();

    QVariant value = DataHelper::GetEQUALSData(equals, "PORO", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    value = DataHelper::GetCOPYData(copy, stratum, "PORO", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    DataHelper::MULTIPLYValue(multiply, "PORO", val, i, j, k);

    DataHelper::ADDValue(add, "PORO", val, i, j, k);

    return val;
}

double ProjectData::ntg(int i, int j, int k)
{
    double val = 1.0;

    if(stratum.NTG().Box().Contains(i, j, k))
        val = stratum.NTG()(i, j, k).toDouble();

    QVariant value = DataHelper::GetEQUALSData(equals, "NTG", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    value = DataHelper::GetCOPYData(copy, stratum, "NTG", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    DataHelper::MULTIPLYValue(multiply, "NTG", val, i, j, k);

    DataHelper::ADDValue(add, "NTG", val, i, j, k);

    return val;
}

bool ProjectData::actnum(int i, int j, int k)
{
    bool val = true;   

    if(stratum.ACTNUM().Box().Contains(i, j, k))
        val = stratum.ACTNUM()(i, j, k).toBool();

    if(ISEQUAL(poro(i, j, k), 0)) val = false;

    if(ISEQUAL(ntg(i, j, k), 0)) val = false;

    double cPoreVolume = poreVolume(i, j, k);

    if(Stratum().MINPVV().Count() > 0)
        val = cPoreVolume > Stratum().MINPVV()(i, j, k).toDouble();

    val = cPoreVolume > Stratum().MINPV();

    return val;
}

double ProjectData::cellVolume(int i, int j, int k)
{
    QVariant val = Stratum().MULTPV()(i, j, k);

    double mult = val.isNull() ? 1 : val.toDouble();

    Block current = GetBlock(i, j, k);

    return mult * current.Volume();
}

double ProjectData::multX(int i, int j, int k)
{
    double val = 1;

    if(stratum.MULTX().Box().Contains(i, j, k))
        val = stratum.MULTX()(i, j, k).toDouble();

    QVariant value = DataHelper::GetEQUALSData(equals, "MULTX", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    value = DataHelper::GetCOPYData(copy, stratum, "MULTX", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    DataHelper::MULTIPLYValue(multiply, "MULTX", val, i, j, k);

    DataHelper::ADDValue(add, "MULTX", val, i, j, k);

    return val;
}

double ProjectData::multXm(int i, int j, int k)
{
    double val = 1;

    if(stratum.MULTXm().Box().Contains(i, j, k))
        val = stratum.MULTXm()(i, j, k).toDouble();

    QVariant value = DataHelper::GetEQUALSData(equals, "MULTX-", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    value = DataHelper::GetCOPYData(copy, stratum, "MULTX-", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    DataHelper::MULTIPLYValue(multiply, "MULTX-", val, i, j, k);

    DataHelper::ADDValue(add, "MULTX-", val, i, j, k);

    return val;
}

double ProjectData::multY(int i, int j, int k)
{
    double val = 1;

    if(stratum.MULTY().Box().Contains(i, j, k))
        val = stratum.MULTY()(i, j, k).toDouble();

    QVariant value = DataHelper::GetEQUALSData(equals, "MULTY", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    value = DataHelper::GetCOPYData(copy, stratum, "MULTY", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    DataHelper::MULTIPLYValue(multiply, "MULTY", val, i, j, k);

    DataHelper::ADDValue(add, "MULTY", val, i, j, k);

    return val;
}

double ProjectData::multYm(int i, int j, int k)
{
    double val = 1;

    if(stratum.MULTYm().Box().Contains(i, j, k))
        val = stratum.MULTYm()(i, j, k).toDouble();

    QVariant value = DataHelper::GetEQUALSData(equals, "MULTY-", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    value = DataHelper::GetCOPYData(copy, stratum, "MULTY-", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    DataHelper::MULTIPLYValue(multiply, "MULTY-", val, i, j, k);

    DataHelper::ADDValue(add, "MULTY-", val, i, j, k);

    return val;
}

double ProjectData::multZ(int i, int j, int k)
{
    double val = 1;

    if(stratum.MULTZ().Box().Contains(i, j, k))
        val = stratum.MULTZ()(i, j, k).toDouble();

    QVariant value = DataHelper::GetEQUALSData(equals, "MULTZ", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    value = DataHelper::GetCOPYData(copy, stratum, "MULTZ", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    DataHelper::MULTIPLYValue(multiply, "MULTZ", val, i, j, k);

    DataHelper::ADDValue(add, "MULTZ", val, i, j, k);

    return val;
}

double ProjectData::multZm(int i, int j, int k)
{
    double val = 1;

    if(stratum.MULTZm().Box().Contains(i, j, k))
        val = stratum.MULTZm()(i, j, k).toDouble();

    QVariant value = DataHelper::GetEQUALSData(equals, "MULTZ-", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    value = DataHelper::GetCOPYData(copy, stratum, "MULTZ-", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    DataHelper::MULTIPLYValue(multiply, "MULTZ-", val, i, j, k);

    DataHelper::ADDValue(add, "MULTZ-", val, i, j, k);

    return val;
}

double ProjectData::tranX(int i, int j, int k, double z0, double zm1)
{
    double val = 0;

    int u = Unit().isNull() ? DefaultValues::Unit : Unit().toInt();

    double Kc = UnitHelper::DarcyTable[u];

    double ntgc = ntg(i, j, k);
    double permXc = permX(i, j, k);

    double ntgl = ntg(i-1, j, k);
    double permXl = permX(i-1, j, k);

    if(BlockCentered())
    {
        Block current = CalcBlockByBCG(0, 0, z0, i, j, k);
        Block lBlock = CalcBlockByBCG(0, 0, zm1, i-1, j, k);

        double dxc = dx(i, j, k);
        double dyc = dy(i, j, k);
        double dzc = dz(i, j, k);
        double depthc = current.Depth();

        double dxl = dx(i-1, j, k);
        double dyl = dy(i-1, j, k);
        double dzl = dz(i-1, j, k);
        double depthl = lBlock.Depth();


        if (actnum(i, j, k) && actnum(i - 1, j, k))
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

            val = Kc * A * D / B;
        }
    }
    else
    {
        Block current = CalcBlockByCPG(i, j, k);

        Point3D myBlockCenter = MathHelper::GetMassCenter(current.P1(), current.P2(), current.P3(), current.P4(),
                                                          current.P5(), current.P6(), current.P7(), current.P8());

        if (actnum(i, j, k) && actnum(i - 1, j, k))
        {
            Plane contactPlane(current.P1(), current.P3(), current.P5());

            Point3D contactAreaCenter;

            Block lBlock = CalcBlockByCPG(current.I()-1, current.J(), current.K());

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


            val = ISEQUAL(a, 0) ? 0 : tx;
        }
    }

    if(stratum.TRANX().Box().Contains(i, j, k))
        val = stratum.TRANX()(i, j, k).toDouble();

    QVariant value = DataHelper::GetEQUALSData(equals, "TRANX", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    value = DataHelper::GetCOPYData(copy, stratum, "TRANX", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    DataHelper::MULTIPLYValue(multiply, "TRANX", val, i, j, k);

    DataHelper::ADDValue(add, "TRANX", val, i, j, k);

    val = val * multX(i, j, k) * multXm(i, j, k);

    return val;
}

double ProjectData::tranY(int i, int j, int k, double z0, double zm1)
{
    double val = 0;

    int u = Unit().isNull() ? DefaultValues::Unit : Unit().toInt();

    double Kc = UnitHelper::DarcyTable[u];

    double ntgc = ntg(i, j, k);
    double permYc = permY(i, j, k);

    double ntgd = ntg(i, j-1, k);
    double permYd = permY(i, j-1, k);

    if(BlockCentered())
    {
        Block current = CalcBlockByBCG(0, 0, z0, i, j, k);
        Block dBlock = CalcBlockByBCG(0, 0, zm1, i, j-1, k);

        double dxc = dx(i, j, k);
        double dyc = dy(i, j, k);
        double dzc = dz(i, j, k);
        double depthc = current.Depth();

        double dxd = dx(i, j-1, k);
        double dyd = dy(i, j-1, k);
        double dzd = dz(i, j-1, k);
        double depthd = dBlock.Depth();


        if (actnum(i, j, k) && actnum(i, j-1, k))
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

            val = Kc * A * D / B;
        }
    }
    else
    {
        Block current = CalcBlockByCPG(i, j, k);

        Point3D myBlockCenter = MathHelper::GetMassCenter(current.P1(), current.P2(), current.P3(), current.P4(),
                                                          current.P5(), current.P6(), current.P7(), current.P8());

        if (actnum(current.I(), current.J(), current.K()) && actnum(current.I(), current.J() - 1, current.K()))
        {
            Plane contactPlane(current.P1(), current.P2(), current.P6());

            Point3D contactAreaCenter;

            Block dBlock = CalcBlockByCPG(current.I(), current.J()-1, current.K());

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


            val = ISEQUAL(a, 0) ? 0 : ty;
        }
    }

    if(stratum.TRANY().Box().Contains(i, j, k))
        val = stratum.TRANY()(i, j, k).toDouble();

    QVariant value = DataHelper::GetEQUALSData(equals, "TRANY", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    value = DataHelper::GetCOPYData(copy, stratum, "TRANY", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    DataHelper::MULTIPLYValue(multiply, "TRANY", val, i, j, k);

    DataHelper::ADDValue(add, "TRANY", val, i, j, k);

    val = val * multY(i, j, k) * multYm(i, j, k);

    return val;
}

double ProjectData::tranZ(int i, int j, int k)
{
    double val = 0;

    int u = Unit().isNull() ? DefaultValues::Unit : Unit().toInt();

    double Kc = UnitHelper::DarcyTable[u];

    double permZc = permZ(i, j, k);
    double permZb = permZ(i, j, k-1);

    if(BlockCentered())
    {
        double dxc = dx(i, j, k);
        double dyc = dy(i, j, k);
        double dzc = dz(i, j, k);

        double dxb = dx(i, j, k-1);
        double dyb = dy(i, j, k-1);
        double dzb = dz(i, j, k-1);

        if (actnum(i, j, k) && actnum(i, j, k - 1))
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

            val = Kc * A / B;
        }
    }
    else
    {
        Block current = CalcBlockByCPG(i, j, k);

        Point3D myBlockCenter = MathHelper::GetMassCenter(current.P1(), current.P2(), current.P3(), current.P4(),
                                                          current.P5(), current.P6(), current.P7(), current.P8());

        if (actnum(current.I(), current.J(), current.K()) && actnum(current.I(), current.J(), current.K() - 1))
        {
            Plane contactPlane(current.P1(), current.P2(), current.P4());

            QList<Point3D> p = { current.P1(), current.P2(), current.P4(), current.P3() };

            Point3D contactAreaCenter = MathHelper::GetAveragePoint(p);

            Block bBlock = CalcBlockByCPG(current.I(), current.J(), current.K()-1);

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


            val = ISEQUAL(a, 0) ? 0 : tz;
        }
    }

    if(stratum.TRANZ().Box().Contains(i, j, k))
        val = stratum.TRANZ()(i, j, k).toDouble();

    QVariant value = DataHelper::GetEQUALSData(equals, "TRANZ", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    value = DataHelper::GetCOPYData(copy, stratum, "TRANZ", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    DataHelper::MULTIPLYValue(multiply, "TRANZ", val, i, j, k);

    DataHelper::ADDValue(add, "TRANZ", val, i, j, k);

    val = val * multZ(i, j, k) * multZm(i, j, k);

    return val;
}

double ProjectData::poreVolume(int i, int j, int k)
{
    QVariant val = Stratum().MULTPV()(i, j, k);

    double mult = val.isNull() ? 1 : val.toDouble();

    double porosity = poro(i, j, k);
    double cNTG = ntg(i, j, k);

    Block current = GetBlock(i, j, k);

    return mult * current.Volume() * porosity * cNTG;
}

double ProjectData::oilVolume(int i, int j, int k)
{
    QMetaObject metaObject = staticMetaObject;

    QMetaEnum unitsEnum = metaObject.enumerator(metaObject.indexOfEnumerator("UnitType"));

    int unit = Unit().isNull() ? DefaultValues::Unit : Unit().toInt();

    double cv = UnitHelper::ConvertVolume(static_cast<UnitType>(unit), LAB, 1, unitsEnum).toDouble();

    int pvtNum = pvtNUM(i, j, k);

    double bo = DataHelper::CalculateBoFromPVT(Stratum(), pressure(i, j, k), pvtNum);

    return cv*poreVolume(i, j, k)*(1 - swat(i, j, k))/bo;
}

double ProjectData::permX(int i, int j, int k)
{
    double val = 0;

    if(stratum.PERMX().Box().Contains(i, j, k))
        val = stratum.PERMX()(i, j, k).toDouble();

    QVariant value = DataHelper::GetEQUALSData(equals, "PERMX", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    value = DataHelper::GetCOPYData(copy, stratum, "PERMX", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    DataHelper::MULTIPLYValue(multiply, "PERMX", val, i, j, k);

    DataHelper::ADDValue(add, "PERMX", val, i, j, k);

    return val;
}

double ProjectData::permY(int i, int j, int k)
{
    double val = 0;

    if(stratum.PERMY().Box().Contains(i, j, k))
        val = stratum.PERMY()(i, j, k).toDouble();

    QVariant value = DataHelper::GetEQUALSData(equals, "PERMY", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    value = DataHelper::GetCOPYData(copy, stratum, "PERMY", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    DataHelper::MULTIPLYValue(multiply, "PERMY", val, i, j, k);

    DataHelper::ADDValue(add, "PERMY", val, i, j, k);

    return val;
}

double ProjectData::permZ(int i, int j, int k)
{
    double val = 0;

    if(stratum.PERMZ().Box().Contains(i, j, k))
        val = stratum.PERMZ()(i, j, k).toDouble();

    QVariant value = DataHelper::GetEQUALSData(equals, "PERMZ", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    value = DataHelper::GetCOPYData(copy, stratum, "PERMZ", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    DataHelper::MULTIPLYValue(multiply, "PERMZ", val, i, j, k);

    DataHelper::ADDValue(add, "PERMZ", val, i, j, k);

    return val;
}

int ProjectData::pvtNUM(int i, int j, int k)
{
    int val = -1;

    if(stratum.PVTNUM().Box().Contains(i, j, k))
        val = stratum.PVTNUM()(i, j, k).toInt();

    QVariant value = DataHelper::GetEQUALSData(equals, "PVTNUM", i, j, k);

    val = !value.isNull() ? value.toInt() : val;

    value = DataHelper::GetCOPYData(copy, stratum, "PVTNUM", i, j, k);

    val = !value.isNull() ? value.toInt() : val;

    double addValue = 0;

    DataHelper::ADDValue(add, "PVTNUM", addValue, i, j, k);

    val += static_cast<int>(addValue);

    return val;
}

int ProjectData::eqlNUM(int i, int j, int k)
{
    int val = -1;

    if(stratum.EQLNUM().Box().Contains(i, j, k))
        val = stratum.EQLNUM()(i, j, k).toInt();

    QVariant value = DataHelper::GetEQUALSData(equals, "EQLNUM", i, j, k);

    val = !value.isNull() ? value.toInt() : val;

    value = DataHelper::GetCOPYData(copy, stratum, "EQLNUM", i, j, k);

    val = !value.isNull() ? value.toInt() : val;

    double addValue = 0;

    DataHelper::ADDValue(add, "EQLNUM", addValue, i, j, k);

    val += static_cast<int>(addValue);

    return val;
}

double ProjectData::rs(int i, int j, int k)
{
    double cDepth = depth(i, j, k);

    if(stratum.RS().Count() > 0) return stratum.RS()(i, j, k).toDouble();
    else if(stratum.PBUB().Count()) return DataHelper::CalculateRSFromPVT(stratum, stratum.PBUB()(i, j, k).toDouble(), pvtNUM(i, j, k));
    else if(stratum.RSVD().length() > 0) return DataHelper::CalculateRSFromRSVD(stratum, cDepth, eqlNUM(i, j, k));
    else return DataHelper::CalculateRSBubFromPVT(stratum, pvtNUM(i, j, k));
}

double ProjectData::pBub(int i, int j, int k)
{
    double cDepth = depth(i, j, k);

    if(stratum.PBUB().Count() > 0) return stratum.PBUB()(i, j, k).toDouble();
    else if(stratum.RS().Count() > 0)
    {
        double p = DataHelper::CalculatePoFromPVT(stratum, stratum.RS()(i, j, k).toDouble(), pvtNUM(i, j, k));

        if(sgas(i, j, k) > 0 || p > pressure(i, j, k)) p = pressure(i, j, k);

        return p;
    }
    else if(stratum.PBVD().length() > 0) return DataHelper::CalculatePBubFromPBVD(stratum, cDepth, eqlNUM(i, j, k));
    else return DataHelper::CalculatePBubFromPVT(stratum, pvtNUM(i, j, k));
}

double ProjectData::pressure(int i, int j, int k)
{
    double val = 0;

    if(stratum.PRESSURE().Box().Contains(i, j, k))
        val = stratum.PRESSURE()(i, j, k).toDouble();

    QVariant value = DataHelper::GetEQUALSData(equals, "PRESSURE", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    DataHelper::MULTIPLYValue(multiply, "PRESSURE", val, i, j, k);

    DataHelper::ADDValue(add, "PRESSURE", val, i, j, k);

    return val;
}

double ProjectData::swat(int i, int j, int k)
{
    double val = 0;

    if(stratum.SWAT().Box().Contains(i, j, k))
        val = stratum.SWAT()(i, j, k).toDouble();

    QVariant value = DataHelper::GetEQUALSData(equals, "SWAT", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    DataHelper::MULTIPLYValue(multiply, "SWAT", val, i, j, k);

    DataHelper::ADDValue(add, "SWAT", val, i, j, k);

    return val;
}

double ProjectData::soil(int i, int j, int k)
{
    double val = 1 - swat(i, j, k) - sgas(i, j, k);

    if(stratum.SOIL().Box().Contains(i, j, k))
        val = stratum.SOIL()(i, j, k).toDouble();

    QVariant value = DataHelper::GetEQUALSData(equals, "SOIL", i, j, k);

    val = !value.isNull() ? value.toDouble() : val;

    DataHelper::MULTIPLYValue(multiply, "SOIL", val, i, j, k);

    DataHelper::ADDValue(add, "SOIL", val, i, j, k);

    return val;
}

double ProjectData::sgas(int i, int j, int k)
{
    double val = 0;

    if(stratum.SGAS().Box().Contains(i, j, k))
        val = stratum.SGAS()(i, j, k).toDouble();

    return val;
}

Block ProjectData::GetBlock(int i, int j, int k, double x0, double y0, double z0)
{
    return isBlockCentered ? CalcBlockByBCG(x0, y0, z0, i, j, k) : CalcBlockByCPG(i, j, k);
}

Block ProjectData::CalcBlockByBCG(double x0, double y0, double z0, int i, int j, int k)
{
    Block current;

    double x1 = x0;
    double y1 = y0;
    double z1 = z0;

    double deltaX = dx(i, j, k);
    double deltaY = dy(i, j, k);
    double deltaZ = dz(i, j, k);

    double x2 = x0 + deltaX;
    double y2 = y0 + deltaY;
    double z2 = z0 + deltaZ;

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

    return current;
}

Block ProjectData::CalcBlockByCPG(int i, int j, int k)
{
    Line3D coordLine;

    double d1, d2, d3, d4, d5, d6, d7, d8;

    DataHelper::CalcBlockDepthsCPG(stratum, i, j, k, nx, ny, d1, d2, d3, d4, d5, d6, d7, d8);

    Block block;

    block.SetI(i);
    block.SetJ(j);
    block.SetK(k);

    if(DataHelper::CheckPointOrderStandardCPG(stratum, nx, ny))
    {
        DataHelper::CalcCoordLineCPG(stratum, i, j, coordLine);

        MathHelper::IntersectZPlane(coordLine, d1, block.P1());
        MathHelper::IntersectZPlane(coordLine, d5, block.P5());

        DataHelper::CalcCoordLineCPG(stratum, i+1, j, coordLine);

        MathHelper::IntersectZPlane(coordLine, d2, block.P2());
        MathHelper::IntersectZPlane(coordLine, d6, block.P6());

        DataHelper::CalcCoordLineCPG(stratum, i, j+1, coordLine);

        MathHelper::IntersectZPlane(coordLine, d3, block.P3());
        MathHelper::IntersectZPlane(coordLine, d7, block.P7());

        DataHelper::CalcCoordLineCPG(stratum, i+1, j+1, coordLine);

        MathHelper::IntersectZPlane(coordLine, d4, block.P4());
        MathHelper::IntersectZPlane(coordLine, d8, block.P8());
    }
    else
    {
        DataHelper::CalcCoordLineCPG(stratum, i, j, coordLine);

        MathHelper::IntersectZPlane(coordLine, d1, block.P8());
        MathHelper::IntersectZPlane(coordLine, d5, block.P4());

        DataHelper::CalcCoordLineCPG(stratum, i+1, j, coordLine);

        MathHelper::IntersectZPlane(coordLine, d2, block.P7());
        MathHelper::IntersectZPlane(coordLine, d6, block.P3());

        DataHelper::CalcCoordLineCPG(stratum, i, j+1, coordLine);

        MathHelper::IntersectZPlane(coordLine, d3, block.P6());
        MathHelper::IntersectZPlane(coordLine, d7, block.P2());

        DataHelper::CalcCoordLineCPG(stratum, i+1, j+1, coordLine);

        MathHelper::IntersectZPlane(coordLine, d4, block.P5());
        MathHelper::IntersectZPlane(coordLine, d8, block.P1());
    }

    return block;
}

StratumData &ProjectData::Stratum()
{
    return stratum;
}

TABDIMSEntity *ProjectData::TABDIMS()
{
    return tabDIMS;
}

EQLDIMSEntity *ProjectData::EQLDIMS()
{
    return eqlDIMS;
}

ENDSCALEEntity *ProjectData::ENDSCALE()
{
    return endSCALE;
}

ROCKOPTSEntity *ProjectData::ROCKOPTS()
{
    return rockOPTS;
}

SWOFEntity *ProjectData::SWOF()
{
    return swof;
}

SGOFEntity *ProjectData::SGOF()
{
    return sgof;
}

PVTOEntity *ProjectData::PVTO()
{
    return pvto;
}

PVTGEntity *ProjectData::PVTG()
{
    return pvtg;
}

WELSPECSEntity *ProjectData::WELSPECS()
{
    return welspecs;
}

COMPDATEntity *ProjectData::COMPDAT()
{
    return compdat;
}

WCONPRODEntity *ProjectData::WCONPROD()
{
    return wconprod;
}

WCONINJEEntity *ProjectData::WCONINJE()
{
    return wconinje;
}

COPYEntity *ProjectData::COPY()
{
    return copy;
}

ADDEntity *ProjectData::ADD()
{
    return add;
}

EQUALSEntity *ProjectData::EQUALS()
{
    return equals;
}

MULTIPLYEntity *ProjectData::MULTIPLY()
{
    return multiply;
}

QVariantList ProjectData::DATES()
{
    QVector<QDateTime> list = stratum.DATES();
    QVariantList result;

    for (int i = 0; i < list.length(); i++) result.append(list[i].toString("dd.MM.yyyy"));

    return result;
}

void ProjectData::SetState(const ProjectState &state)
{
    this->state = state;

    StateChanged();
}

void ProjectData::SetTitle(const QString &title)
{
    this->title = title;

    TitleChanged();
}

void ProjectData::SetStartDate(const QDateTime &startDate)
{
    this->startDate = startDate;

    StartDateChanged();
}

void ProjectData::SetUnit(const QVariant &unit)
{
    this->unit = unit;

    UnitChanged();
}

void ProjectData::SetModel(const QVariant &model)
{
    this->model = model;

    ModelChanged();
}

void ProjectData::SetTemperatureOption(const QVariant &temperatureOption)
{
    this->temperatureOption = temperatureOption;

    TemperatureOptionChanged();
}

void ProjectData::SetNumRES(const QVariant &numRES)
{
    this->numRES = numRES;

    NumRESChanged();
}

void ProjectData::SetNx(int nx)
{
    this->nx = nx;

    NxChanged();
}

void ProjectData::SetNy(int ny)
{
    this->ny = ny;

    NyChanged();
}

void ProjectData::SetNz(int nz)
{
    this->nz = nz;

    NzChanged();
}

void ProjectData::SetBlockCentered(bool isBlockCentered)
{
    this->isBlockCentered = isBlockCentered;    

    BlockCenteredChanged();
}

void ProjectData::initVariables()
{
    SetTitle("");
    SetStartDate(QDateTime::currentDateTime());
    SetUnit(QVariant());
    SetModel(QVariant());
    SetTemperatureOption(QVariant());

    SetNumRES(QVariant());

    SetNx(0);
    SetNy(0);
    SetNz(0);    

    stratum.InitVariables();

    tabDIMS->initVariables();
    eqlDIMS->initVariables();
    endSCALE->initVariables();

    rockOPTS->initVariables();

    compdat->Clear();
    wconinje->Clear();
    wconprod->Clear();
    welspecs->Clear();

    copy->Clear();
    add->Clear();
    equals->Clear();
    multiply->Clear();

    SetBlockCentered(false);

    SetState(CLOSED);
}

}}}}
