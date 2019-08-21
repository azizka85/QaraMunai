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

QVariant ProjectData::dx(int i, int j, int k)
{
    QVariant val;

    if(stratum.DX().Box().Contains(i, j, k))
        val = stratum.DX()(i, j, k).toDouble();
    else if(stratum.DXV().Count() > i)
        val = stratum.DXV()(i).toDouble();
    else
    {
        QList<int> indexes = equals->GetIndexes("DX");

        if(indexes.length() > 0)
        {
            for(int i = 0; i < indexes.length(); i++)
            {
                EQUALSData& data = equals->EQUALS()[indexes[i]];

                if(data.Box().Contains(i, j, k))
                {
                    val = data.Value();

                    break;
                }
            }
        }
        else
        {
            indexes = copy->GetIndexes("DX");

            if(indexes.length() > 0)
            {
                for(int i = 0; i < indexes.length(); i++)
                {
                    COPYData& data = copy->COPY()[indexes[i]];

                    if(data.Box().Contains(i, j, k))
                    {
                        LinearMatrix3D &array = GetArrayByName(data.SOURCE());

                        val = array(i, j, k);

                        break;
                    }
                }
            }
        }
    }

    QList<int> indexes = multiply->GetIndexes("DX");

    if(indexes.length() > 0)
    {
        for(int i = 0; i < indexes.length(); i++)
        {
            MULTIPLYData& data = multiply->MULTIPLY()[indexes[i]];

            if(data.Box().Contains(i, j, k))
            {
                val = val.toDouble() * data.Mult();
            }
        }
    }

    indexes = add->GetIndexes("DX");

    if(indexes.length() > 0)
    {
        for(int i = 0; i < indexes.length(); i++)
        {
            ADDData& data = add->ADD()[indexes[i]];

            if(data.Box().Contains(i, j, k))
            {
                val = val.toDouble() + data.Value();
            }
        }
    }

    return val;
}

QVariant ProjectData::dy(int i, int j, int k)
{
    QVariant val;

    if(stratum.DY().Box().Contains(i, j, k))
        val = stratum.DY()(i, j, k).toDouble();
    else if(stratum.DYV().Count() > j)
        val = stratum.DYV()(j).toDouble();
    else
    {
        QList<int> indexes = equals->GetIndexes("DY");

        if(indexes.length() > 0)
        {
            for(int i = 0; i < indexes.length(); i++)
            {
                EQUALSData& data = equals->EQUALS()[indexes[i]];

                if(data.Box().Contains(i, j, k))
                {
                    val = data.Value();

                    break;
                }
            }
        }
        else
        {
            indexes = copy->GetIndexes("DY");

            if(indexes.length() > 0)
            {
                for(int i = 0; i < indexes.length(); i++)
                {
                    COPYData& data = copy->COPY()[indexes[i]];

                    if(data.Box().Contains(i, j, k))
                    {
                        LinearMatrix3D &array = GetArrayByName(data.SOURCE());

                        val = array(i, j, k);

                        break;
                    }
                }
            }
        }
    }

    QList<int> indexes = multiply->GetIndexes("DY");

    if(indexes.length() > 0)
    {
        for(int i = 0; i < indexes.length(); i++)
        {
            MULTIPLYData& data = multiply->MULTIPLY()[indexes[i]];

            if(data.Box().Contains(i, j, k))
            {
                val = val.toDouble() * data.Mult();
            }
        }
    }

    indexes = add->GetIndexes("DY");

    if(indexes.length() > 0)
    {
        for(int i = 0; i < indexes.length(); i++)
        {
            ADDData& data = add->ADD()[indexes[i]];

            if(data.Box().Contains(i, j, k))
            {
                val = val.toDouble() + data.Value();
            }
        }
    }

    return val;
}

QVariant ProjectData::dz(int i, int j, int k)
{
    QVariant val;

    if(stratum.DZ().Box().Contains(i, j, k))
        val = stratum.DZ()(i, j, k).toDouble();
    else if(stratum.DZV().Count() > k)
        val = stratum.DZV()(k).toDouble();
    else
    {
        QList<int> indexes = equals->GetIndexes("DZ");

        if(indexes.length() > 0)
        {
            for(int i = 0; i < indexes.length(); i++)
            {
                EQUALSData& data = equals->EQUALS()[indexes[i]];

                if(data.Box().Contains(i, j, k))
                {
                    val = data.Value();

                    break;
                }
            }
        }
        else
        {
            indexes = copy->GetIndexes("DZ");

            if(indexes.length() > 0)
            {
                for(int i = 0; i < indexes.length(); i++)
                {
                    COPYData& data = copy->COPY()[indexes[i]];

                    if(data.Box().Contains(i, j, k))
                    {
                        LinearMatrix3D &array = GetArrayByName(data.SOURCE());

                        val = array(i, j, k);

                        break;
                    }
                }
            }
        }
    }

    QList<int> indexes = multiply->GetIndexes("DZ");

    if(indexes.length() > 0)
    {
        for(int i = 0; i < indexes.length(); i++)
        {
            MULTIPLYData& data = multiply->MULTIPLY()[indexes[i]];

            if(data.Box().Contains(i, j, k))
            {
                val = val.toDouble() * data.Mult();
            }
        }
    }

    indexes = add->GetIndexes("DZ");

    if(indexes.length() > 0)
    {
        for(int i = 0; i < indexes.length(); i++)
        {
            ADDData& data = add->ADD()[indexes[i]];

            if(data.Box().Contains(i, j, k))
            {
                val = val.toDouble() + data.Value();
            }
        }
    }

    return val;
}

QVariant ProjectData::tops(int i, int j)
{
    if(stratum.TOPS().Box().Contains(i, j, 0))
        return stratum.TOPS()(i, j, 0);
    else return QVariant();
}

QVariantMap ProjectData::coordLine(int i, int j)
{
    Line3D line;

    CalcCoordLine(i, j, line);

    return line.toMap();
}

QVariantMap ProjectData::blockDepths(int i, int j, int k, int nx, int ny)
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

LinearMatrix3D &ProjectData::GetArray(ArrayNames name)
{
    switch (name)
    {
        case TOPS: return stratum.TOPS();
        case DX: return stratum.DX();
        case DY: return stratum.DY();
        case DZ: return stratum.DZ();
        case ACTNUM: return stratum.ACTNUM();
        case MULTPV: return stratum.MULTPV();
        case PERMX: return stratum.PERMX();
        case PERMY: return stratum.PERMY();
        case PERMZ: return stratum.PERMZ();
        case PORO: return stratum.PORO();
        case NTG: return stratum.NTG();
        case DZNET: return stratum.DZNET();
        case MULTX: return stratum.MULTX();
        case MULTY: return stratum.MULTY();
        case MULTZ: return stratum.MULTZ();
        case MULTXm: return stratum.MULTXm();
        case MULTYm: return stratum.MULTYm();
        case MULTZm: return stratum.MULTZm();
        case MINPVV: return stratum.MINPVV();
        case SWATINIT: return stratum.SWATINIT();
        case SWCR: return stratum.SWCR();
        case ISWCR: return stratum.ISWCR();
        case SWL: return stratum.SWL();
        case ISWL: return stratum.ISWL();
        case SWLPC: return stratum.SWLPC();
        case ISWLPC: return stratum.ISWLPC();
        case SWU: return stratum.SWU();
        case ISWU: return stratum.ISWU();
        case SGCR: return stratum.SGCR();
        case ISGCR: return stratum.ISGCR();
        case SGL: return stratum.SGL();
        case ISGL: return stratum.ISGL();
        case SGLPC: return stratum.SGLPC();
        case ISGLPC: return stratum.ISGLPC();
        case PCG: return stratum.PCG();
        case IPCG: return stratum.IPCG();
        case PCW: return stratum.PCW();
        case IPCW: return stratum.IPCW();
        case KRO: return stratum.KRO();
        case IKRO: return stratum.IKRO();
        case KRORW: return stratum.KRORW();
        case IKRORW: return stratum.IKRORW();
        case KRORG: return stratum.KRORG();
        case IKRORG: return stratum.IKRORG();
        case KRW: return stratum.KRW();
        case IKRW: return stratum.IKRW();
        case KRWR: return stratum.KRWR();
        case IKRWR: return stratum.IKRWR();
        case KRG: return stratum.KRG();
        case IKRG: return stratum.IKRG();
        case KRGR: return stratum.KRGR();
        case IKRGR: return stratum.IKRGR();
        case PVTNUM: return stratum.PVTNUM();
        case SATNUM: return stratum.SATNUM();
        case EQLNUM: return stratum.EQLNUM();
        case ENDNUM: return stratum.ENDNUM();
        case PRESSURE: return stratum.PRESSURE();
        case SWAT: return stratum.SWAT();
        case SGAS: return stratum.SGAS();
        case PBUB: return stratum.PBUB();
        case RS: return stratum.RS();
        case DEPTH: return stratum.DEPTH();
        case PORV: return stratum.PORV();
        case TRANX: return stratum.TRANX();
        case TRANY: return stratum.TRANY();
        case TRANZ: return stratum.TRANZ();
    }
}

LinearMatrix3D &ProjectData::GetArrayByName(QString arrayName)
{
    QMetaEnum casesEnum = staticMetaObject.enumerator(staticMetaObject.indexOfEnumerator("ArrayNames"));

    arrayName = arrayName.replace('-', 'm')
                            .replace('+', 'p');

    int name = casesEnum.keyToValue(arrayName.toLatin1());

    return GetArray(static_cast<ArrayNames>(name));
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

    copy->Clear();
    add->Clear();
    equals->Clear();
    multiply->Clear();
}

}}}}
