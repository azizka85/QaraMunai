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

void DataHelper::CalculateBlockDepthArray(ProjectData *projectData, QVector<Depth> &depths)
{
    int nx = projectData->Nx();
    int ny = projectData->Ny();
    int nz = projectData->Nz();

    depths.resize(nx*ny*nz);

    double x0 = 0;
    double y0 = 0;
    double z0 = 0;

    for(int i = 0; i < nx; i++)
    {
        y0 = 0;

        for(int j = 0; j < ny; j++)
        {
            z0 = projectData->tops(i, j);

            for(int k = 0; k < nz; k++)
            {
                Block block = projectData->GetBlock(i, j, k, x0, y0, z0);

                int ind = k*nx*ny + j*nx + i;

                depths[ind] = Depth(block.P1().Z(), block.P2().Z(), block.P3().Z(), block.P4().Z(), block.P5().Z(), block.P6().Z(), block.P7().Z(), block.P8().Z());

                if(k == nz-1 && j == ny-1) x0 = block.P8().X();
                if(k == nz-1) y0 = block.P8().Y();
                z0 = block.P8().Z();
            }
        }
    }
}

void DataHelper::CalculateExistBlockArray(ProjectData *projectData, QVector<bool> &existBlock)
{
    int nx = projectData->Nx();
    int ny = projectData->Ny();
    int nz = projectData->Nz();

    existBlock.resize(nx*ny*nz);

    for(int i = 0; i < nx; i++)
    {
        for(int j = 0; j < ny; j++)
        {
            for(int k = 0; k < nz; k++)
            {
                int ind = k*nx*ny + j*nx + i; // i, j, k

                existBlock[ind] = projectData->actnum(i, j, k);
            }
        }
    }
}

void DataHelper::CalculateDrawBlockArray(ProjectData *projectData, QVector<Depth> &depths, QVector<bool> &existBlock, QVector<bool> &drawBlock)
{
    int nx = projectData->Nx();
    int ny = projectData->Ny();
    int nz = projectData->Nz();

    drawBlock.resize(nx*ny*nz);

    for(int i = 0; i < nx; i++)
    {
        for(int j = 0; j < ny; j++)
        {
            for(int k = 0; k < nz; k++)
            {
                int ind = k*nx*ny + j*nx + i; // i, j, k

                drawBlock[ind] = false;

                if(!existBlock[ind]) continue;

                if (i == 0 || i == nx - 1 || j == 0 || j == ny - 1 || k == 0 || k == nz - 1)
                {
                    drawBlock[ind] = existBlock[ind];
                }
                else
                {
                    int ind1 = (k-1)*nx*ny + j*nx + i; // i, j, k-1
                    int ind2 = (k+1)*nx*ny + j*nx + i; // i, j, k+1

                    if(!existBlock[ind1] || !existBlock[ind2]) drawBlock[ind] = true;
                    else
                    {
                        // i+1,j
                        ind1 = j*nx + (i+1); // i+1, j, 0
                        ind2 = (nz-1)*nx*ny + j*nx + (i+1); // i+1, j, nz-1

                        bool found = false;

                        if(depths[ind].H6() < depths[ind1].H1() && depths[ind].H8() < depths[ind1].H3())
                        {
                            drawBlock[ind] = true;

                            continue;
                        }

                        if(depths[ind].H2() > depths[ind2].H5() && depths[ind].H4() > depths[ind2].H7())
                        {
                            drawBlock[ind] = true;

                            continue;
                        }

                        Segment lside1(depths[ind].H2(), depths[ind].H6());
                        Segment rside1(depths[ind].H4(), depths[ind].H8());

                        for(int kk = 0; kk < nz; kk++)
                        {
                            int subInd = kk*nx*ny + j*nx + i+1; // i+1, j, kk

                            if(!existBlock[subInd])
                            {
                                Segment lside2(depths[subInd].H1(), depths[subInd].H5());
                                Segment rside2(depths[subInd].H3(), depths[subInd].H7());

                                if(MathHelper::IsIntersectedSurfaces(lside1, rside1, lside2, rside2))
                                {
                                    found = true;

                                    break;
                                }
                            }
                        }

                        if(found)
                        {
                            drawBlock[ind] = true;

                            continue;
                        }

                        // i-1, j
                        ind1 = j*nx + (i-1); // i-1, j, 0
                        ind2 = (nz-1)*nx*ny + j*nx + (i-1); // i-1, j, nz-1

                        found = false;

                        if(depths[ind].H5() < depths[ind1].H2() && depths[ind].H7() < depths[ind1].H4())
                        {
                            drawBlock[ind] = true;

                            continue;
                        }

                        if(depths[ind].H1() > depths[ind2].H6() && depths[ind].H3() > depths[ind2].H8())
                        {
                            drawBlock[ind] = true;

                            continue;
                        }

                        lside1 = Segment(depths[ind].H1(), depths[ind].H5());
                        rside1 = Segment(depths[ind].H3(), depths[ind].H7());

                        for(int kk = 0; kk < nz; kk++)
                        {
                            int subInd = kk*nx*ny + j*nx + i-1; // i-1, j, kk

                            if(!existBlock[subInd])
                            {
                                Segment lside2(depths[subInd].H2(), depths[subInd].H6());
                                Segment rside2(depths[subInd].H4(), depths[subInd].H8());

                                if(MathHelper::IsIntersectedSurfaces(lside1, rside1, lside2, rside2))
                                {
                                    found = true;

                                    break;
                                }
                            }
                        }

                        if(found)
                        {
                            drawBlock[ind] = true;

                            continue;
                        }

                        // i, j+1
                        ind1 = (j+1)*nx + i; // i, j+1, 0
                        ind2 = (nz-1)*nx*ny + (j+1)*nx + i; // i, j+1, nz-1

                        found = false;

                        if(depths[ind].H7() < depths[ind1].H1() && depths[ind].H8() < depths[ind1].H2())
                        {
                            drawBlock[ind] = true;

                            continue;
                        }

                        if(depths[ind].H3() > depths[ind2].H5() && depths[ind].H4() > depths[ind2].H6())
                        {
                            drawBlock[ind] = true;

                            continue;
                        }

                        lside1 = Segment(depths[ind].H3(), depths[ind].H7());
                        rside1 = Segment(depths[ind].H4(), depths[ind].H8());

                        for(int kk = 0; kk < nz; kk++)
                        {
                            int subInd = kk*nx*ny + (j+1)*nx + i; // i, j+1, kk

                            if(!existBlock[subInd])
                            {
                                Segment lside2(depths[subInd].H1(), depths[subInd].H5());
                                Segment rside2(depths[subInd].H2(), depths[subInd].H6());

                                if(MathHelper::IsIntersectedSurfaces(lside1, rside1, lside2, rside2))
                                {
                                    found = true;

                                    break;
                                }
                            }
                        }

                        if(found)
                        {
                            drawBlock[ind] = true;

                            continue;
                        }

                        // i, j-1
                        ind1 = (j-1)*nx + i; // i, j-1, 0
                        ind2 = (nz-1)*nx*ny + (j-1)*nx + i; // i, j-1, nz-1

                        found = false;

                        if(depths[ind].H5() < depths[ind1].H3() && depths[ind].H6() < depths[ind1].H4())
                        {
                            drawBlock[ind] = true;

                            continue;
                        }

                        if(depths[ind].H1() > depths[ind2].H7() && depths[ind].H2() > depths[ind2].H8())
                        {
                            drawBlock[ind] = true;

                            continue;
                        }

                        lside1 = Segment(depths[ind].H1(), depths[ind].H5());
                        rside1 = Segment(depths[ind].H2(), depths[ind].H6());

                        for(int kk = 0; kk < nz; kk++)
                        {
                            int subInd = kk*nx*ny + (j-1)*nx + i; // i, j-1, kk

                            if(!existBlock[subInd])
                            {
                                Segment lside2(depths[subInd].H3(), depths[subInd].H7());
                                Segment rside2(depths[subInd].H4(), depths[subInd].H8());

                                if(MathHelper::IsIntersectedSurfaces(lside1, rside1, lside2, rside2))
                                {
                                    found = true;

                                    break;
                                }
                            }
                        }

                        if(found)
                        {
                            drawBlock[ind] = true;

                            continue;
                        }
                    }
                }
            }
        }
    }
}

void DataHelper::GetDrawBlocks(ProjectData *projectData, QVector<bool> &drawBlock, QVector<Block> &blocks, double &xMin, double &xMax, double &yMin, double &yMax, double &zMin, double &zMax)
{
    int nx = projectData->Nx();
    int ny = projectData->Ny();
    int nz = projectData->Nz();

    double x0 = xMin = xMax = 0;
    double y0 = yMin = yMax = 0;
    double z0 = zMin = zMax = 0;

    for(int i = 0; i < nx; i++)
    {
        y0 = 0;

        for(int j = 0; j < ny; j++)
        {
            z0 = projectData->tops(i, j);

            for(int k = 0; k < nz; k++)
            {
                Block block = projectData->GetBlock(i, j, k, x0, y0, z0);

                int ind = k*nx*ny + j*nx + i;

                if(drawBlock[ind])
                {
                    if(blocks.size() == 0)
                    {
                        xMin = xMax = block.P1().X();
                        yMin = yMax = block.P1().Y();
                        zMin = zMax = block.P1().Z();
                    }

                    xMin = qMin(xMin, qMin(block.P1().X(), qMin(block.P2().X(), qMin(block.P3().X(), qMin(block.P4().X(), qMin(block.P5().X(), qMin(block.P6().X(), qMin(block.P7().X(), block.P8().X()))))))));
                    yMin = qMin(yMin, qMin(block.P1().Y(), qMin(block.P2().Y(), qMin(block.P3().Y(), qMin(block.P4().Y(), qMin(block.P5().Y(), qMin(block.P6().Y(), qMin(block.P7().Y(), block.P8().Y()))))))));
                    zMin = qMin(zMin, qMin(block.P1().Z(), qMin(block.P2().Z(), qMin(block.P3().Z(), qMin(block.P4().Z(), qMin(block.P5().Z(), qMin(block.P6().Z(), qMin(block.P7().Z(), block.P8().Z()))))))));

                    xMax = qMax(xMax, qMax(block.P1().X(), qMax(block.P2().X(), qMax(block.P3().X(), qMax(block.P4().X(), qMax(block.P5().X(), qMax(block.P6().X(), qMax(block.P7().X(), block.P8().X()))))))));
                    yMax = qMax(yMax, qMax(block.P1().Y(), qMax(block.P2().Y(), qMax(block.P3().Y(), qMax(block.P4().Y(), qMax(block.P5().Y(), qMax(block.P6().Y(), qMax(block.P7().Y(), block.P8().Y()))))))));
                    zMax = qMax(zMax, qMax(block.P1().Z(), qMax(block.P2().Z(), qMax(block.P3().Z(), qMax(block.P4().Z(), qMax(block.P5().Z(), qMax(block.P6().Z(), qMax(block.P7().Z(), block.P8().Z()))))))));

                    blocks.append(block);
                }

                if(k == nz-1 && j == ny-1) x0 = block.P8().X();
                if(k == nz-1) y0 = block.P8().Y();
                z0 = block.P8().Z();
            }
        }
    }
}

void DataHelper::NormalizeBlocks(double xMin, double xMax, double yMin, double yMax, double zMin, double zMax, QVector<Block> &blocks)
{
    double maxD = qMax(qMax(xMax - xMin, yMax - yMin), zMax - zMin);

    double scaleX = (xMax - xMin)/maxD;
    double scaleY = (yMax - yMin)/maxD;
    double scaleZ = (zMax - zMin)/maxD;

    maxD = ISEQUAL(maxD, 0) ? 1 : maxD;

    for(int i = 0; i < blocks.size(); i++)
    {
        double x = blocks[i].P1().X();
        double y = blocks[i].P1().Y();
        double z = blocks[i].P1().Z();

        blocks[i].P1().SetX(-0.5*scaleX + (x-xMin)/maxD);
        blocks[i].P1().SetY(-0.5*scaleY + (y-yMin)/maxD);
        blocks[i].P1().SetZ(-0.5*scaleZ + (z-zMin)/maxD);

        x = blocks[i].P2().X();
        y = blocks[i].P2().Y();
        z = blocks[i].P2().Z();

        blocks[i].P2().SetX(-0.5*scaleX + (x-xMin)/maxD);
        blocks[i].P2().SetY(-0.5*scaleY + (y-yMin)/maxD);
        blocks[i].P2().SetZ(-0.5*scaleZ + (z-zMin)/maxD);

        x = blocks[i].P3().X();
        y = blocks[i].P3().Y();
        z = blocks[i].P3().Z();

        blocks[i].P3().SetX(-0.5*scaleX + (x-xMin)/maxD);
        blocks[i].P3().SetY(-0.5*scaleY + (y-yMin)/maxD);
        blocks[i].P3().SetZ(-0.5*scaleZ + (z-zMin)/maxD);

        x = blocks[i].P4().X();
        y = blocks[i].P4().Y();
        z = blocks[i].P4().Z();

        blocks[i].P4().SetX(-0.5*scaleX + (x-xMin)/maxD);
        blocks[i].P4().SetY(-0.5*scaleY + (y-yMin)/maxD);
        blocks[i].P4().SetZ(-0.5*scaleZ + (z-zMin)/maxD);

        x = blocks[i].P5().X();
        y = blocks[i].P5().Y();
        z = blocks[i].P5().Z();

        blocks[i].P5().SetX(-0.5*scaleX + (x-xMin)/maxD);
        blocks[i].P5().SetY(-0.5*scaleY + (y-yMin)/maxD);
        blocks[i].P5().SetZ(-0.5*scaleZ + (z-zMin)/maxD);

        x = blocks[i].P6().X();
        y = blocks[i].P6().Y();
        z = blocks[i].P6().Z();

        blocks[i].P6().SetX(-0.5*scaleX + (x-xMin)/maxD);
        blocks[i].P6().SetY(-0.5*scaleY + (y-yMin)/maxD);
        blocks[i].P6().SetZ(-0.5*scaleZ + (z-zMin)/maxD);

        x = blocks[i].P7().X();
        y = blocks[i].P7().Y();
        z = blocks[i].P7().Z();

        blocks[i].P7().SetX(-0.5*scaleX + (x-xMin)/maxD);
        blocks[i].P7().SetY(-0.5*scaleY + (y-yMin)/maxD);
        blocks[i].P7().SetZ(-0.5*scaleZ + (z-zMin)/maxD);

        x = blocks[i].P8().X();
        y = blocks[i].P8().Y();
        z = blocks[i].P8().Z();

        blocks[i].P8().SetX(-0.5*scaleX + (x-xMin)/maxD);
        blocks[i].P8().SetY(-0.5*scaleY + (y-yMin)/maxD);
        blocks[i].P8().SetZ(-0.5*scaleZ + (z-zMin)/maxD);
    }
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
