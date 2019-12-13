#include "datahelper.h"

#include <projectdata.h>

namespace QaraMunai {
namespace Model {
namespace Helpers {

LinearMatrix3D &DataHelper::GetArray(StratumData &stratum, int name)
{
    ProjectData::ArrayNames arrayName = static_cast<ProjectData::ArrayNames>(name);

    switch (arrayName)
    {
        case ProjectData::ArrayNames::TOPS: return stratum.TOPS();
        case ProjectData::ArrayNames::DX: return stratum.DX();
        case ProjectData::ArrayNames::DY: return stratum.DY();
        case ProjectData::ArrayNames::DZ: return stratum.DZ();
        case ProjectData::ArrayNames::ACTNUM: return stratum.ACTNUM();
        case ProjectData::ArrayNames::MULTPV: return stratum.MULTPV();
        case ProjectData::ArrayNames::PERMX: return stratum.PERMX();
        case ProjectData::ArrayNames::PERMY: return stratum.PERMY();
        case ProjectData::ArrayNames::PERMZ: return stratum.PERMZ();
        case ProjectData::ArrayNames::PORO: return stratum.PORO();
        case ProjectData::ArrayNames::NTG: return stratum.NTG();
        case ProjectData::ArrayNames::DZNET: return stratum.DZNET();
        case ProjectData::ArrayNames::MULTX: return stratum.MULTX();
        case ProjectData::ArrayNames::MULTY: return stratum.MULTY();
        case ProjectData::ArrayNames::MULTZ: return stratum.MULTZ();
        case ProjectData::ArrayNames::MULTXm: return stratum.MULTXm();
        case ProjectData::ArrayNames::MULTYm: return stratum.MULTYm();
        case ProjectData::ArrayNames::MULTZm: return stratum.MULTZm();
        case ProjectData::ArrayNames::MINPVV: return stratum.MINPVV();
        case ProjectData::ArrayNames::SWATINIT: return stratum.SWATINIT();
        case ProjectData::ArrayNames::SWCR: return stratum.SWCR();
        case ProjectData::ArrayNames::ISWCR: return stratum.ISWCR();
        case ProjectData::ArrayNames::SWL: return stratum.SWL();
        case ProjectData::ArrayNames::ISWL: return stratum.ISWL();
        case ProjectData::ArrayNames::SWLPC: return stratum.SWLPC();
        case ProjectData::ArrayNames::ISWLPC: return stratum.ISWLPC();
        case ProjectData::ArrayNames::SWU: return stratum.SWU();
        case ProjectData::ArrayNames::ISWU: return stratum.ISWU();
        case ProjectData::ArrayNames::SGCR: return stratum.SGCR();
        case ProjectData::ArrayNames::ISGCR: return stratum.ISGCR();
        case ProjectData::ArrayNames::SGL: return stratum.SGL();
        case ProjectData::ArrayNames::ISGL: return stratum.ISGL();
        case ProjectData::ArrayNames::SGLPC: return stratum.SGLPC();
        case ProjectData::ArrayNames::ISGLPC: return stratum.ISGLPC();
        case ProjectData::ArrayNames::PCG: return stratum.PCG();
        case ProjectData::ArrayNames::IPCG: return stratum.IPCG();
        case ProjectData::ArrayNames::PCW: return stratum.PCW();
        case ProjectData::ArrayNames::IPCW: return stratum.IPCW();
        case ProjectData::ArrayNames::KRO: return stratum.KRO();
        case ProjectData::ArrayNames::IKRO: return stratum.IKRO();
        case ProjectData::ArrayNames::KRORW: return stratum.KRORW();
        case ProjectData::ArrayNames::IKRORW: return stratum.IKRORW();
        case ProjectData::ArrayNames::KRORG: return stratum.KRORG();
        case ProjectData::ArrayNames::IKRORG: return stratum.IKRORG();
        case ProjectData::ArrayNames::KRW: return stratum.KRW();
        case ProjectData::ArrayNames::IKRW: return stratum.IKRW();
        case ProjectData::ArrayNames::KRWR: return stratum.KRWR();
        case ProjectData::ArrayNames::IKRWR: return stratum.IKRWR();
        case ProjectData::ArrayNames::KRG: return stratum.KRG();
        case ProjectData::ArrayNames::IKRG: return stratum.IKRG();
        case ProjectData::ArrayNames::KRGR: return stratum.KRGR();
        case ProjectData::ArrayNames::IKRGR: return stratum.IKRGR();
        case ProjectData::ArrayNames::PVTNUM: return stratum.PVTNUM();
        case ProjectData::ArrayNames::SATNUM: return stratum.SATNUM();
        case ProjectData::ArrayNames::EQLNUM: return stratum.EQLNUM();
        case ProjectData::ArrayNames::ENDNUM: return stratum.ENDNUM();
        case ProjectData::ArrayNames::PRESSURE: return stratum.PRESSURE();
        case ProjectData::ArrayNames::SWAT: return stratum.SWAT();
        case ProjectData::ArrayNames::SOIL: return stratum.SOIL();
        case ProjectData::ArrayNames::SGAS: return stratum.SGAS();
        case ProjectData::ArrayNames::PBUB: return stratum.PBUB();
        case ProjectData::ArrayNames::RS: return stratum.RS();
        case ProjectData::ArrayNames::DEPTH: return stratum.DEPTH();
        case ProjectData::ArrayNames::PORV: return stratum.PORV();
        case ProjectData::ArrayNames::TRANX: return stratum.TRANX();
        case ProjectData::ArrayNames::TRANY: return stratum.TRANY();
        case ProjectData::ArrayNames::TRANZ: return stratum.TRANZ();
    }

    return stratum.TOPS();
}

LinearMatrix3D &DataHelper::GetArrayByName(StratumData &stratum, QString arrayName)
{
    QMetaEnum casesEnum = ProjectData::staticMetaObject.enumerator(ProjectData::staticMetaObject.indexOfEnumerator("ArrayNames"));

    arrayName = arrayName.replace('-', 'm')
                            .replace('+', 'p');

    int name = casesEnum.keyToValue(arrayName.toLatin1());

    return GetArray(stratum, name);

}

QVariant DataHelper::GetEQUALSData(EQUALSEntity *equals, QString arrayName, int i, int j, int k)
{
    QVariant val;

    QVector<int> indexes = equals->GetIndexes(arrayName);

    if(indexes.length() > 0)
    {
        for(int ind = 0; ind < indexes.length(); ind++)
        {
            EQUALSData& data = equals->EQUALS()[indexes[ind]];

            if(data.Box().Contains(i, j, k))
            {
                val = data.Value();

                break;
            }
        }
    }

    return val;
}

QVariant DataHelper::GetCOPYData(COPYEntity *copy, StratumData& stratum, QString arrayName, int i, int j, int k)
{
    QVariant val;

    QVector<int> indexes = copy->GetIndexes(arrayName);

    if(indexes.length() > 0)
    {
        for(int ind = 0; ind < indexes.length(); ind++)
        {
            COPYData& data = copy->COPY()[indexes[ind]];

            if(data.Box().Contains(i, j, k))
            {
                LinearMatrix3D &array = GetArrayByName(stratum, data.SOURCE());

                val = array(i, j, k);

                break;
            }
        }
    }

    return val;
}

void DataHelper::MULTIPLYValue(MULTIPLYEntity *multiply, QString arrayName, double &val, int i, int j, int k)
{
    QVector<int> indexes = multiply->GetIndexes(arrayName);

    if(indexes.length() > 0)
    {
        for(int ind = 0; ind < indexes.length(); ind++)
        {
            MULTIPLYData& data = multiply->MULTIPLY()[indexes[ind]];

            if(data.Box().Contains(i, j, k))
            {
                val = val * data.Mult();
            }
        }
    }
}

void DataHelper::ADDValue(ADDEntity *add, QString arrayName, double &val, int i, int j, int k)
{
    QVector<int> indexes = add->GetIndexes(arrayName);

    if(indexes.length() > 0)
    {
        for(int ind = 0; ind < indexes.length(); ind++)
        {
            ADDData& data = add->ADD()[indexes[ind]];

            if(data.Box().Contains(i, j, k))
            {
                val = val + data.Value();
            }
        }
    }
}

int DataHelper::GetPVTLength(StratumData &stratum, int pvtNum)
{
    return stratum.PVTO().length() > 0 ? stratum.PVTO()[pvtNum].length() : stratum.PVDO()[pvtNum].length();
}

double DataHelper::GetRSFromPVT(StratumData &stratum, int pvtNum, int rowNum)
{
    return stratum.PVTO().length() > 0 ? stratum.PVTO()[pvtNum][rowNum].RS() :
                                         stratum.RSCONSTT().length() > 0 ? stratum.RSCONSTT()[pvtNum].RS() :
                                                                           stratum.RSCONST().RS();
}

double DataHelper::GetPoFromPVT(StratumData &stratum, int pvtNum, int rowNum)
{
    return stratum.PVTO().length() > 0 ? stratum.PVTO()[pvtNum][rowNum].PO() : stratum.PVDO()[pvtNum][rowNum].PO();
}

double DataHelper::GetBoFromPVT(StratumData &stratum, int pvtNum, int rowNum)
{
    return stratum.PVTO().length() > 0 ? stratum.PVTO()[pvtNum][rowNum].BO() : stratum.PVDO()[pvtNum][rowNum].BO();
}

double DataHelper::CalculateRSBubFromPVT(StratumData &stratum, int pvtNum)
{
    if(stratum.PVTO().length() > 0)
    {
        int rowsCount = GetPVTLength(stratum, pvtNum);

        double rsLast = GetRSFromPVT(stratum, pvtNum, rowsCount-1);

        double rs = rsLast;
        int r = rowsCount-1;

        while (r >= 0 && ISEQUAL(rs, rsLast))
        {
            r--;

            rs = GetRSFromPVT(stratum, pvtNum, r);
        }

        r++;

        return GetRSFromPVT(stratum, pvtNum, r);
    }

    return GetRSFromPVT(stratum, pvtNum);
}

double DataHelper::CalculateRSFromPVT(StratumData &stratum, double p, int pvtNum)
{
    int a = 0;
    int b = GetPVTLength(stratum, pvtNum) - 1;

    while (b - a > 1)
    {
        int r = (a + b) / 2;

        double cp = GetPoFromPVT(stratum, pvtNum, r);

        if (cp > p) b = r;
        else a = r;
    }

    double bp = GetPoFromPVT(stratum, pvtNum, b);
    double ap = GetPoFromPVT(stratum, pvtNum, a);

    double k1 = (bp - p) / (bp - ap);
    double k2 = (p - ap) / (bp - ap);

    double aRS = GetRSFromPVT(stratum, pvtNum, a);
    double bRS = GetRSFromPVT(stratum, pvtNum, b);

    return aRS * k1 + bRS * k2;
}

double DataHelper::CalculatePBubFromPVT(StratumData &stratum, int pvtNum)
{
    if(stratum.PVTO().length() > 0)
    {
        int rowsCount = GetPVTLength(stratum, pvtNum);

        double rsLast = GetRSFromPVT(stratum, pvtNum, rowsCount-1);

        double rs = rsLast;
        int r = rowsCount-1;

        while (r >= 0 && ISEQUAL(rs, rsLast))
        {
            r--;

            rs = GetRSFromPVT(stratum, pvtNum, r);
        }

        r++;

        return GetPoFromPVT(stratum, pvtNum, r);
    }

    return 0;
}

double DataHelper::CalculatePoFromPVT(StratumData &stratum, double rs, int pvtNum)
{
    int a = 0;
    int b = GetPVTLength(stratum, pvtNum) - 1;

    while (b - a > 1)
    {
        int r = (a + b) / 2;

        double cRS = GetRSFromPVT(stratum, pvtNum, r);

        if (cRS > rs) b = r;
        else a = r;
    }

    double aRS = GetRSFromPVT(stratum, pvtNum, a);
    double bRS = GetRSFromPVT(stratum, pvtNum, b);

    double k1 = (bRS - rs) / (bRS - aRS);
    double k2 = (rs - aRS) / (bRS - aRS);

    double bp = GetPoFromPVT(stratum, pvtNum, b);
    double ap = GetPoFromPVT(stratum, pvtNum, a);

    return ap * k1 + bp * k2;
}

double DataHelper::CalculateBoFromPVT(StratumData &stratum, double p, int pvtNum)
{
    int a = 0;
    int b = GetPVTLength(stratum, pvtNum) - 1;

    while (b - a > 1)
    {
        int r = (a + b) / 2;

        double cp = GetPoFromPVT(stratum, pvtNum, r);

        if (cp > p) b = r;
        else a = r;
    }

    double bp = GetPoFromPVT(stratum, pvtNum, b);
    double ap = GetPoFromPVT(stratum, pvtNum, a);

    double k1 = (bp - p) / (bp - ap);
    double k2 = (p - ap) / (bp - ap);

    double aBo = GetBoFromPVT(stratum, pvtNum, a);
    double bBo = GetBoFromPVT(stratum, pvtNum, b);

    return aBo * k1 + bBo * k2;
}

double DataHelper::CalculateRSFromRSVD(StratumData &stratum, double depth, int eqlNum)
{
    int a = 0;
    int b = stratum.RSVD()[eqlNum].length() - 1;

    while (b - a > 1)
    {
        int r = (a + b) / 2;

        double cDepth = stratum.RSVD()[eqlNum][r].Depth();

        if (cDepth > depth) b = r;
        else a = r;
    }

    double bDepth = stratum.RSVD()[eqlNum][b].Depth();
    double aDepth = stratum.RSVD()[eqlNum][a].Depth();

    double k1 = (bDepth - depth) / (bDepth - aDepth);
    double k2 = (depth - aDepth) / (bDepth - aDepth);

    double aRS = stratum.RSVD()[eqlNum][a].RS();
    double bRS = stratum.RSVD()[eqlNum][b].RS();

    return aRS * k1 + bRS * k2;
}

double DataHelper::CalculatePBubFromPBVD(StratumData &stratum, double depth, int eqlNum)
{
    int a = 0;
    int b = stratum.PBVD()[eqlNum].length() - 1;

    while (b - a > 1)
    {
        int r = (a + b) / 2;

        double cDepth = stratum.PBVD()[eqlNum][r].Depth();

        if (cDepth > depth) b = r;
        else a = r;
    }

    double bDepth = stratum.PBVD()[eqlNum][b].Depth();
    double aDepth = stratum.PBVD()[eqlNum][a].Depth();

    double k1 = (bDepth - depth) / (bDepth - aDepth);
    double k2 = (depth - aDepth) / (bDepth - aDepth);

    double ap = stratum.PBVD()[eqlNum][a].PBub();
    double bp = stratum.PBVD()[eqlNum][b].PBub();

    return ap * k1 + bp * k2;
}

bool DataHelper::CalcCoordLineCPG(StratumData &stratum, int i, int j, Line3D &coordLine)
{
    int nx = stratum.COORD().Box().Nx();
    // int ny = stratum.COORD().Box().Ny();

    // if(j*(nx+1) + i >= (nx+1)*(ny+1)) return false; //TODO: must be >= (nx+1)*(ny+1)*numRes

    int cur = (j*(nx + 1) + i)*6;

    double x1 = stratum.COORD()(cur + 0).toDouble();
    double y1 = stratum.COORD()(cur + 1).toDouble();
    double z1 = stratum.COORD()(cur + 2).toDouble();

    double x2 = stratum.COORD()(cur + 3).toDouble();
    double y2 = stratum.COORD()(cur + 4).toDouble();
    double z2 = stratum.COORD()(cur + 5).toDouble();

    // if(ISEQUAL(x1-x2, 0) && ISEQUAL(y1-y2, 0)) z2 = z1+10;

    coordLine.P1().SetX(x1);
    coordLine.P1().SetY(y1);
    coordLine.P1().SetZ(z1);

    coordLine.P2().SetX(x2);
    coordLine.P2().SetY(y2);
    coordLine.P2().SetZ(z2);    

    return true;
}

bool DataHelper::CalcBlockDepthsCPG(StratumData &stratum, int i, int j, int k, int nx, int ny, double &d1, double &d2, double &d3, double &d4, double &d5, double &d6, double &d7, double &d8)
{
    if(!stratum.ZCORN().Box().Contains(i, j, k)) return false;

    // cur = pi + 2*i + 2*nx*pj + 4*nx*j + 4*nx*ny*pk + 8*nx*ny*k
    // p = pi + 2*pj + 4*pk

    int cur = 8*nx*ny*k + 4*nx*j + 2*i; // pi={0,1}, pj=0, pk=0

    d1 = stratum.ZCORN()(cur + 0).toDouble(); // pi=0
    d2 = stratum.ZCORN()(cur + 1).toDouble(); // pi=1

    cur = 8*nx*ny*k + 2*nx*(2*j+1) + 2*i; // pi={0,1}, pj=1, pk=0

    d3 = stratum.ZCORN()(cur + 0).toDouble(); // pi=0
    d4 = stratum.ZCORN()(cur + 1).toDouble(); // pi=1

    cur = 4*nx*ny*(2*k+1) + 4*nx*j + 2*i; // pi={0,1}, pj=0, pk=1

    d5 = stratum.ZCORN()(cur + 0).toDouble(); // pi=0
    d6 = stratum.ZCORN()(cur + 1).toDouble(); // pi=1

    cur = 4*nx*ny*(2*k+1) + 2*nx*(2*j+1) + 2*i; // pi={0,1}, pj=1, pk=1

    d7 = stratum.ZCORN()(cur + 0).toDouble(); // pi=0
    d8 = stratum.ZCORN()(cur + 1).toDouble(); // pi=1

    return true;
}

bool DataHelper::CheckPointOrderStandardCPG(StratumData &stratum, int nx, int ny)
{
    Line3D coordLine;

    Point3D p1, p2, p3, p4;

    double d1, d2, d3, d4, d5, d6, d7, d8;

    CalcBlockDepthsCPG(stratum, 0, 0, 0, nx, ny, d1, d2, d3, d4, d5, d6, d7, d8);

    CalcCoordLineCPG(stratum, 0, 0, coordLine);

    MathHelper::IntersectZPlane(coordLine, d1, p1);

    CalcCoordLineCPG(stratum, 1, 0, coordLine);

    MathHelper::IntersectZPlane(coordLine, d2, p2);

    CalcCoordLineCPG(stratum, 0, 1, coordLine);

    MathHelper::IntersectZPlane(coordLine, d3, p3);

    CalcCoordLineCPG(stratum, 1, 1, coordLine);

    MathHelper::IntersectZPlane(coordLine, d4, p4);

    return p1.X() <= p2.X() &&
            p3.X() <= p4.X() &&
            p1.Y() <= p3.Y() &&
            p2.Y() <= p4.Y();
}

void DataHelper::DivideOnAxesNodes(int n, int mx, int my, int &nx, int &ny, int &nz)
{
    nz = n/mx/my;

    int r = n - nz*my*mx;

    ny = r/mx;

    nx = r - ny*mx;
}

void DataHelper::NumberOfGPUNodes(int n, int mx, int my, int &nx, int &ny, int &nz)
{
    DivideOnAxesNodes(n, mx, my, nx, ny, nz);

    if(nx == 0)
    {
        if(ny == 0)
        {
            if(nz > 0)
            {
                ny = my;
                nx = mx;
            }
            else
            {
                nx = 1;
                ny = 1;
                nz = 1;
            }
        }
        else
        {
            nz++;
            nx = mx;
        }
    }
    else
    {
        if(ny > 0 || nz > 0) nx = mx;

        ny++;
        nz++;
    }
}

}}}
