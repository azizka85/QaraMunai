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

    initVariables();
}

bool ProjectData::IsLoaded() const
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

void ProjectData::SetIsLoaded(const bool &isLoaded)
{
    this->isLoaded = isLoaded;

    IsLoadedChanged();
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

void ProjectData::initVariables()
{
    SetIsLoaded(false);

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
}

}}}}
