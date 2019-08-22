#include "projectdata.h"

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

bool ProjectData::Loaded() const
{
    return isLoaded;
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
    double val = 0;

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

    val += addValue;

    return val;
}

QVariantMap ProjectData::coordLine(int i, int j)
{
    Line3D line;

    CalcCoordLine(i, j, line);

    return line.toMap();
}

QVariantMap ProjectData::blockDepths(int i, int j, int k)
{
    double d1, d2, d3, d4, d5, d6, d7, d8;

    CalcBlockDepths(i, j, k, d1, d2, d3, d4, d5, d6, d7, d8);

    return QVariantMap { { "d1", d1 }, { "d2", d2 }, { "d3", d3 }, { "d4", d4 },
                        { "d5", d5 }, { "d6", d6 }, { "d7", d7 }, { "d8", d8 } };
}

bool ProjectData::CalcCoordLine(int i, int j, Line3D &coordLine)
{
    if(!stratum.COORD().Box().Contains(i, j)) return false;

    int cur = (j*(nx + 1) + i)*6;

    double x1 = stratum.COORD()(cur + 0).toDouble();
    double y1 = stratum.COORD()(cur + 1).toDouble();
    double z1 = stratum.COORD()(cur + 2).toDouble();

    double x2 = stratum.COORD()(cur + 3).toDouble();
    double y2 = stratum.COORD()(cur + 4).toDouble();
    double z2 = stratum.COORD()(cur + 5).toDouble();

    coordLine.P1().SetX(x1);
    coordLine.P1().SetY(y1);
    coordLine.P1().SetZ(z1);

    coordLine.P2().SetX(x2);
    coordLine.P2().SetY(y2);
    coordLine.P2().SetZ(z2);

    return true;
}

bool ProjectData::CalcBlockDepths(int i, int j, int k, double &d1, double &d2, double &d3, double &d4, double &d5, double &d6, double &d7, double &d8)
{
    if(!stratum.ZCORN().Box().Contains(i, j, k)) return false;

    int cur = k*nx*ny + j*nx + 2*i;

    d1 = stratum.ZCORN()(cur + 0).toDouble();
    d2 = stratum.ZCORN()(cur + 1).toDouble();

    cur = k*nx*ny + 2*j*nx + 2*i;

    d3 = stratum.ZCORN()(cur + 0).toDouble();
    d4 = stratum.ZCORN()(cur + 1).toDouble();

    cur = 2*k*nx*ny + j*nx + 2*i;

    d5 = stratum.ZCORN()(cur + 0).toDouble();
    d6 = stratum.ZCORN()(cur + 1).toDouble();

    cur = 2*k*nx*ny + 2*j*nx + 2*i;

    d7 = stratum.ZCORN()(cur + 0).toDouble();
    d8 = stratum.ZCORN()(cur + 1).toDouble();

    return true;
}

bool ProjectData::CheckPointOrderStandard()
{
    Line3D coordLine;

    Point3D p1, p2, p3, p4;

    double d1, d2, d3, d4, d5, d6, d7, d8;

    CalcBlockDepths(0, 0, 0, d1, d2, d3, d4, d5, d6, d7, d8);

    CalcCoordLine(0, 0, coordLine);

    MathHelper::IntersectZPlane(coordLine, d1, p1);

    CalcCoordLine(1, 0, coordLine);

    MathHelper::IntersectZPlane(coordLine, d2, p2);

    CalcCoordLine(0, 1, coordLine);

    MathHelper::IntersectZPlane(coordLine, d3, p3);

    CalcCoordLine(1, 1, coordLine);

    MathHelper::IntersectZPlane(coordLine, d4, p4);

    return p1.X() <= p2.X() &&
            p3.X() <= p4.X() &&
            p1.Y() <= p3.Y() &&
            p2.Y() <= p4.Y();
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
    QList<QDateTime> list = stratum.DATES();
    QVariantList result;

    for (int i = 0; i < list.length(); i++) result.append(list[i].toString("dd.MM.yyyy"));

    return result;
}

void ProjectData::SetLoaded(const bool &isLoaded)
{
    this->isLoaded = isLoaded;

    LoadedChanged();
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
    SetLoaded(false);

    SetTitle("");
    SetStartDate(QDateTime::currentDateTime());
    SetUnit(QVariant());
    SetModel(QVariant());
    SetTemperatureOption(QVariant());

    SetNumRES(QVariant());

    SetNx(0);
    SetNy(0);
    SetNz(0);

    SetBlockCentered(false);

    stratum.InitVariables();

    tabDIMS->initVariables();
    eqlDIMS->initVariables();
    endSCALE->initVariables();

    rockOPTS->initVariables();

    copy->Clear();
    add->Clear();
    equals->Clear();
    multiply->Clear();
}

}}}}
