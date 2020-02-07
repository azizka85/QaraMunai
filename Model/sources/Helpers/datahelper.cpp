#include "datahelper.h"

#include <projectdata.h>

namespace QaraMunai {
namespace Model {
namespace Helpers {

void DataHelper::GenerateBlocks(ProjectData *projectData, QVector<Block> &blocks, int nx, int ny, int nz, bool isBlockCentered)
{
    blocks.resize(nx*ny*nz);

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
                Block block = isBlockCentered ? projectData->CalcBlockByBCG(x0, y0, z0, i, j, k) : projectData->CalcBlockByCPG(i, j, k);

                int ind = k*nx*ny + j*nx + i;

                blocks[ind] = block;

                if(k == nz-1 && j == ny-1) x0 = block.P8().X();
                if(k == nz-1) y0 = block.P8().Y();
                z0 = block.P8().Z();
            }
        }
    }
}

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

            Box3D &box = data.Box();

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

void DataHelper::GetPoRangeFromPVT(StratumData &stratum, double p, int pvtNum, int &a, int &b)
{
    a = 0;
    b = GetPVTLength(stratum, pvtNum) - 1;

    while (b - a > 1)
    {
        int r = (a + b) / 2;

        double po = GetPoFromPVT(stratum, pvtNum, r);

        if (po > p) b = r;
        else a = r;
    }
}

double DataHelper::GetBoFromPVT(StratumData &stratum, int pvtNum, int rowNum)
{
    return stratum.PVTO().length() > 0 ? stratum.PVTO()[pvtNum][rowNum].BO() : stratum.PVDO()[pvtNum][rowNum].BO();
}

double DataHelper::GetMoFromPVT(StratumData &stratum, int pvtNum, int rowNum)
{
    return stratum.PVTO().length() > 0 ? stratum.PVTO()[pvtNum][rowNum].MO() : stratum.PVDO()[pvtNum][rowNum].MO();
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

void DataHelper::CalculateDrawBlockArray(ProjectData *projectData, QVector<bool> &existBlock, QVector<bool> &drawBlock)
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

                Block block = projectData->GetBlock(i, j, k);

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

                        Block block1 = projectData->GetBlock(i+1, j, 0);
                        Block block2 = projectData->GetBlock(i+1, j, nz-1);

                        bool found = false;

                        if(block.P6().Z() < block1.P1().Z() && block.P8().Z() < block1.P3().Z())
                        {
                            drawBlock[ind] = true;

                            continue;
                        }

                        if(block.P2().Z() > block2.P5().Z() && block.P4().Z() > block2.P7().Z())
                        {
                            drawBlock[ind] = true;

                            continue;
                        }

                        Segment lside1(block.P2().Z(), block.P6().Z());
                        Segment rside1(block.P4().Z(), block.P8().Z());

                        for(int kk = 0; kk < nz; kk++)
                        {
                            int subInd = kk*nx*ny + j*nx + i+1; // i+1, j, kk

                            Block subBlock = projectData->GetBlock(i+1, j, kk);

                            if(!existBlock[subInd])
                            {
                                Segment lside2(subBlock.P1().Z(), subBlock.P5().Z());
                                Segment rside2(subBlock.P3().Z(), subBlock.P7().Z());

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

                        block1 = projectData->GetBlock(i-1, j, 0);
                        block2 = projectData->GetBlock(i-1, j, nz-1);

                        found = false;

                        if(block.P5().Z() < block1.P2().Z() && block.P7().Z() < block1.P4().Z())
                        {
                            drawBlock[ind] = true;

                            continue;
                        }

                        if(block.P1().Z() > block2.P6().Z() && block.P3().Z() > block2.P8().Z())
                        {
                            drawBlock[ind] = true;

                            continue;
                        }

                        lside1 = Segment(block.P1().Z(), block.P5().Z());
                        rside1 = Segment(block.P3().Z(), block.P7().Z());

                        for(int kk = 0; kk < nz; kk++)
                        {
                            int subInd = kk*nx*ny + j*nx + i-1; // i-1, j, kk

                            Block subBlock = projectData->GetBlock(i-1, j, kk);

                            if(!existBlock[subInd])
                            {
                                Segment lside2(subBlock.P2().Z(), subBlock.P6().Z());
                                Segment rside2(subBlock.P4().Z(), subBlock.P8().Z());

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

                        block1 = projectData->GetBlock(i, j+1, 0);
                        block2 = projectData->GetBlock(i, j+1, nz-1);

                        found = false;

                        if(block.P7().Z() < block1.P1().Z() && block.P8().Z() < block1.P2().Z())
                        {
                            drawBlock[ind] = true;

                            continue;
                        }

                        if(block.P3().Z() > block2.P5().Z() && block.P4().Z() > block2.P6().Z())
                        {
                            drawBlock[ind] = true;

                            continue;
                        }

                        lside1 = Segment(block.P3().Z(), block.P7().Z());
                        rside1 = Segment(block.P4().Z(), block.P8().Z());

                        for(int kk = 0; kk < nz; kk++)
                        {
                            int subInd = kk*nx*ny + (j+1)*nx + i; // i, j+1, kk

                            Block subBlock = projectData->GetBlock(i, j+1, kk);

                            if(!existBlock[subInd])
                            {
                                Segment lside2(subBlock.P1().Z(), subBlock.P5().Z());
                                Segment rside2(subBlock.P2().Z(), subBlock.P6().Z());

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

                        block1 = projectData->GetBlock(i, j-1, 0);
                        block2 = projectData->GetBlock(i, j-1, nz-1);

                        found = false;

                        if(block.P5().Z() < block1.P3().Z() && block.P6().Z() < block1.P4().Z())
                        {
                            drawBlock[ind] = true;

                            continue;
                        }

                        if(block.P1().Z() > block2.P7().Z() && block.P2().Z() > block2.P8().Z())
                        {
                            drawBlock[ind] = true;

                            continue;
                        }

                        lside1 = Segment(block.P1().Z(), block.P5().Z());
                        rside1 = Segment(block.P2().Z(), block.P6().Z());

                        for(int kk = 0; kk < nz; kk++)
                        {
                            int subInd = kk*nx*ny + (j-1)*nx + i; // i, j-1, kk

                            Block subBlock = projectData->GetBlock(i, j-1, kk);

                            if(!existBlock[subInd])
                            {
                                Segment lside2(subBlock.P3().Z(), subBlock.P7().Z());
                                Segment rside2(subBlock.P4().Z(), subBlock.P8().Z());

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

    xMin = xMax = 0;
    yMin = yMax = 0;
    zMin = zMax = 0;

    for(int i = 0; i < nx; i++)
    {
        for(int j = 0; j < ny; j++)
        {
            for(int k = 0; k < nz; k++)
            {
                Block block = projectData->GetBlock(i, j, k);

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

void DataHelper::SetPVTOil(StratumData& stratum, int pvtNum, double p, double rod, double rg, double &mo, double &bo, double &dBo, double &rs, double &drs, double &dro, double &ro, double pBub, double cr)
{
    int a = 0;
    int b = 0;

    GetPoRangeFromPVT(stratum, p, pvtNum, a, b);

    double poA = GetPoFromPVT(stratum, pvtNum, a);
    double poB = GetPoFromPVT(stratum, pvtNum, b);

    double k1 = (poB - p) / (poB - poA);
    double k2 = (p - poA) / (poB - poA);

    if (p < poA) { k1 = 1.0; k2 = 0.0; }
    if (p > poB) { k1 = 0.0; k2 = 1.0; }

    double moA = GetMoFromPVT(stratum, pvtNum, a);
    double moB = GetMoFromPVT(stratum, pvtNum, b);

    double boA = GetBoFromPVT(stratum, pvtNum, a);
    double boB = GetBoFromPVT(stratum, pvtNum, b);

    mo = moA * k1 + moB * k2;
    bo = 1/boA * k1 + 1/boB * k2;

    double bod = boA * k1 + boB * k2;

    double rsA = GetRSFromPVT(stratum, pvtNum, a);
    double rsB = GetRSFromPVT(stratum, pvtNum, b);

    rs = rsA * k1 + rsB * k2;

    dBo = (1.0 / boB - 1.0 / boA) / (poB - poA);

    drs = (rsB - rsA) / (poB - poA);

    dro = (rod + cr * rs * rg) * dBo + cr * rg * bo * drs;

    bo = bod * (1 - 1e-6 * (p - pBub));
    bo = 1 / bo;
    ro = (rod + cr * rs * rg) * bo;
}

void DataHelper::SetPVTWAT(StratumData &stratum, int pvtNum, double p, double rwd, double &mw, double &bw, double &dbw, double &rw, double &drw)
{
    double cw = stratum.PVTW().size() > pvtNum && !stratum.PVTW()[pvtNum].CW().isNull() ? stratum.PVTW()[pvtNum].CW().toDouble() : DefaultValues::PVTW_CW;
    double pr = stratum.PVTW().size() > pvtNum && !stratum.PVTW()[pvtNum].PWRef().isNull() ? stratum.PVTW()[pvtNum].PWRef().toDouble() : DefaultValues::PVTW_PWRef;
    double br = stratum.PVTW().size() > pvtNum && !stratum.PVTW()[pvtNum].BWRef().isNull() ? stratum.PVTW()[pvtNum].BWRef().toDouble() : DefaultValues::PVTW_BWRef;
    double mr = stratum.PVTW().size() > pvtNum && !stratum.PVTW()[pvtNum].MWRef().isNull() ? stratum.PVTW()[pvtNum].MWRef().toDouble() : DefaultValues::PVTW_MWRef;

    double x = cw * (p - pr);

    bw = (1.0 + x + x * x / 2.0) / br;

    double y = (cw - mr) * (p - pr);

    mw = br * mr * bw / (1 + y + y*y/2);

    dbw = cw * (1 + x) / br;

    rw = rwd * bw;
    drw = rwd * dbw;
}

void DataHelper::SetPcForInvSw(StratumData &stratum, int satNum, double pc, double &sw)
{
    // TODO: SW  not only on SWOF
    if(stratum.SWOF().size() > satNum && stratum.SWOF()[satNum].size() > 0)
    {
        int a = 0;
        int b = stratum.SWOF()[satNum].size() - 1;

        while (b - a > 1)
        {
            int r = (a + b) / 2;

            // TODO: Capillary pressure  not only on SWOF and default values are calculated
            double pow = stratum.SWOF()[satNum][r].Pc().toDouble();

            if (pow > pc) a = r;
            else b = r;
        }

        // TODO: Capillary pressure  not only on SWOF and default values are calculated
        double powA = stratum.SWOF()[satNum][a].Pc().toDouble();
        double powB = stratum.SWOF()[satNum][b].Pc().toDouble();

        double k1 = (powB - pc) / (powB - powA);
        double k2 = (pc - powA) / (powB - powA);

        if (pc < powB) { k1 = 0.0; k2 = 1.0; }
        if (pc > powA) { k1 = 1.0; k2 = 0.0; }

        // TODO: SW  not only on SWOF
        double swA = stratum.SWOF()[satNum][a].SW();
        double swB = stratum.SWOF()[satNum][b].SW();

        sw = swA * k1 + swB * k2;
    }
}

void DataHelper::CalcEquilData(ProjectData *projectData, int nx, int ny, int nz, QVector<double> &pw, QVector<double> &po, QVector<double> &sw)
{
    if(!projectData->Stratum().EQLDIMS().NTEQUL().isNull())
    {
        int ntEQUL = projectData->Stratum().EQLDIMS().NTEQUL().toInt();

        if(ntEQUL > 0)
        {
            pw.resize(nx*ny*nz);
            po.resize(nx*ny*nz);
            sw.resize(nx*ny*nz);

            for(int regNum = 0; regNum < ntEQUL; regNum++)
            {
                int regCount = 0;

                for (int i = 0; i < nx; i++)
                {
                    for (int j = 0; j < ny; j++)
                    {
                        for (int k = 0; k < nz; k++)
                        {
                            int eqlNum = projectData->eqlNUM(i, j, k) - 1;

                            if(eqlNum == regNum) regCount++;
                        }
                    }
                }

                QVector<int> bList(regCount);

                int l = 0;

                for (int i = 0; i < nx; i++)
                {
                    for (int j = 0; j < ny; j++)
                    {
                        for (int k = 0; k < nz; k++)
                        {
                            int eqlNum = projectData->eqlNUM(i, j, k) - 1;

                            if(eqlNum == regNum)
                            {
                                int ind = k*nx*ny + j*nx + i;

                                bList[l] = ind;

                                l++;
                            }
                        }
                    }
                }

                std::sort(bList.begin(), bList.end(), [nx, ny, projectData](const int &ind1, const int &ind2) -> bool
                {
                    int i1, j1, k1;
                    int i2, j2, k2;

                    DataHelper::DivideOnAxesNodes(ind1, nx, ny, i1, j1, k1);
                    DataHelper::DivideOnAxesNodes(ind2, nx, ny, i2, j2, k2);

                    return projectData->depth(i1, j1, k1) < projectData->depth(i2, j2, k2);
                });


                if(regNum < projectData->Stratum().EQUIL().size())
                {
                    EQUILData& data = projectData->Stratum().EQUIL()[regNum];

                    double datum = data.DatumDepth();
                    double pDatum = data.DatumP();
                    double dWOC = data.WOCDepth().toDouble();
                    double pWOC = data.WOCPc().toDouble();

                    auto ub = std::lower_bound(bList.begin(), bList.end(), datum, [nx, ny, projectData](const int &ind, const double& datumDepth) -> bool
                    {
                        int i, j, k;

                        DataHelper::DivideOnAxesNodes(ind, nx, ny, i, j, k);
                        double bDepth = projectData->depth(i, j, k);

                        return bDepth < datumDepth;
                    });

                    int m = ub - bList.begin();

                    m = m < 0 ? m+1 : m < bList.size() ? m : m-1;

                    int dIndex = bList[m];

                    int dI, dJ, dK;

                    DataHelper::DivideOnAxesNodes(dIndex, nx, ny, dI, dJ, dK);

                    qDebug() << "Datum index: " << dI << ", " << dJ << ", " << dK;

                    // Oil pressure calculation
                    double ro, rg;
                    double datumBo, datumMo, datumDBo, datumRS, datumRo, datumDRS, datumDRo;

                    int pvtNum = projectData->pvtNUM(dI, dJ, dK) - 1;

                    double datumPBub = projectData->pBub(dI, dJ, dK);

                    ro = projectData->Stratum().DENSITY().length() > pvtNum && !projectData->Stratum().DENSITY()[pvtNum].RO().isNull() ? projectData->Stratum().DENSITY()[pvtNum].RO().toDouble() : DefaultValues::DENSITY_RO;
                    rg = projectData->Stratum().DENSITY().length() > pvtNum && !projectData->Stratum().DENSITY()[pvtNum].RG().isNull() ? projectData->Stratum().DENSITY()[pvtNum].RG().toDouble() : DefaultValues::DENSITY_RG;

                    QMetaObject metaObject = ProjectData::staticMetaObject;
                    QMetaEnum unitsEnum = metaObject.enumerator(metaObject.indexOfEnumerator("UnitType"));
                    ProjectData::UnitType unitType = projectData->Unit().isNull() ? DefaultValues::Unit : static_cast<ProjectData::UnitType>(projectData->Unit().toInt());
                    double cr = UnitHelper::ConvertGasLiquidRatio(ProjectData::METRIC, unitType, 1, unitsEnum).toDouble();

                    cr = 1/cr;

                    double g = UnitHelper::GravityTable[unitType];

                    DataHelper::SetPVTOil(projectData->Stratum(), pvtNum, pDatum, ro, rg, datumMo, datumBo, datumDBo, datumRS, datumDRS, datumDRo, datumRo, datumPBub, cr);

                    for(int r = 0; r < regCount; r++)
                    {
                        int i, j, k;
                        int ind = bList[r];

                        DataHelper::DivideOnAxesNodes(ind, nx, ny, i, j, k);

                        po[ind] = pDatum + datumRo * g * (projectData->depth(i, j, k) - datum);
                    }

                    // Water pressure calculation (TODO: is correct only for Block-centered grid...)
                    ub = std::lower_bound(bList.begin(), bList.end(), dWOC, [nx, ny, projectData](const int &ind, const double& wocDepth) -> bool
                    {
                        int i, j, k;

                        DataHelper::DivideOnAxesNodes(ind, nx, ny, i, j, k);
                        double bDepth = projectData->depth(i, j, k);
                        double dz = projectData->dz(i, j, k);

                        return wocDepth >= bDepth - dz/2 && wocDepth <= bDepth + dz/2; // (TODO: is correct only for Block-centered grid...)
                    });

                    m = ub - bList.begin();

                    m = m < 0 ? m+1 : m < bList.size() ? m : m-1;

                    dIndex = bList[m];

                    DataHelper::DivideOnAxesNodes(dIndex, nx, ny, dI, dJ, dK);

                    qDebug() << "WOC index: " << dI << ", " << dJ << ", " << dK;

                    double wocBw, wocMw, wocDBw, wocRw, wocDRw;
                    double wocMo, wocBo, wocDBo, wocRs, wocDRs, wocDRo, wocRo;

                    pvtNum = projectData->pvtNUM(dI, dJ, dK) - 1;

                    ro = projectData->Stratum().DENSITY().length() > pvtNum && !projectData->Stratum().DENSITY()[pvtNum].RO().isNull() ? projectData->Stratum().DENSITY()[pvtNum].RO().toDouble() : DefaultValues::DENSITY_RO;
                    rg = projectData->Stratum().DENSITY().length() > pvtNum && !projectData->Stratum().DENSITY()[pvtNum].RG().isNull() ? projectData->Stratum().DENSITY()[pvtNum].RG().toDouble() : DefaultValues::DENSITY_RG;

                    double rw = projectData->Stratum().DENSITY().length() > pvtNum && !projectData->Stratum().DENSITY()[pvtNum].RW().isNull() ? projectData->Stratum().DENSITY()[pvtNum].RW().toDouble() : DefaultValues::DENSITY_RW;

                    double wocPBub = projectData->pBub(dI, dJ, dK);

                    DataHelper::SetPVTOil(projectData->Stratum(), pvtNum, po[dIndex], ro, rg, wocMo, wocBo, wocDBo, wocRs, wocDRs, wocDRo, wocRo, wocPBub, cr);

                    double poWOC = po[dIndex] + wocRo * g * (dWOC - projectData->depth(dI, dJ, dK));

                    DataHelper::SetPVTWAT(projectData->Stratum(), pvtNum, poWOC - pWOC, rw, wocMw, wocBw, wocDBw, wocRw, wocDRw);

                    for (int r = 0; r < regCount; r++)
                    {
                        int i, j, k;
                        int ind = bList[r];

                        DataHelper::DivideOnAxesNodes(ind, nx, ny, i, j, k);

                        pw[ind] = poWOC - pWOC + g * rw * (projectData->depth(i, j, k) - dWOC);
                    }

                    // Water saturation calculation
                    for (int r = 0; r < regCount; r++)
                    {
                        int i, j, k;
                        int ind = bList[r];

                        DataHelper::DivideOnAxesNodes(ind, nx, ny, i, j, k);

                        pvtNum = projectData->pvtNUM(i, j, k);

                        double pcOW = po[ind] - pw[ind];

                        int satNum = projectData->satNUM(i, j, k);

                        // TODO: Capillary pressure  not only on SWOF and default values are calculated
                        double powMax = projectData->Stratum().SWOF().size() > satNum && projectData->Stratum().SWOF()[satNum].size() > 0 ? projectData->Stratum().SWOF()[satNum][0].Pc().toDouble() : 0;
                        double powMin = projectData->Stratum().SWOF().size() > satNum && projectData->Stratum().SWOF()[satNum].size() > 0 ? projectData->Stratum().SWOF()[satNum][projectData->Stratum().SWOF()[satNum].size()-1].Pc().toDouble() : 0;

                        // TODO: is correct only for Block-centered grid...
                        double depth = projectData->depth(i, j, k);
                        double dz = projectData->dz(i, j, k);

                        double top = depth - dz / 2;

                        if(dWOC > depth - dz/2 && dWOC <= dWOC <= depth + dz/2)
                        {
                            double delta = dz / 10;

                            sw[ind] = 0;

                            for(int j = 0; j < 10; j++)
                            {
                                double pof = po[ind] + ro * g * (top + (j + 0.5) * delta - depth);
                                double pwf = pw[ind] + rw * g * (top + (j + 0.5) * delta - depth);

                                double pcOWf = pof - pwf;

                                double swf = 0;

                                if (pcOWf >= powMax)
                                {
                                    // TODO: SW  not only on SWOF
                                    swf = projectData->Stratum().SWOF().size() > satNum && projectData->Stratum().SWOF()[satNum].size() > 0 ? projectData->Stratum().SWOF()[satNum][0].SW() : 0;
                                }
                                else if (pcOWf <= powMin)
                                {
                                    // TODO: SW  not only on SWOF
                                    swf = projectData->Stratum().SWOF().size() > satNum && projectData->Stratum().SWOF()[satNum].size() > 0 ? projectData->Stratum().SWOF()[satNum][projectData->Stratum().SWOF()[satNum].size() - 1].SW() : 0;
                                }
                                else if (pcOWf > powMin && pcOWf < powMax)
                                {
                                    SetPcForInvSw(projectData->Stratum(), satNum, pcOWf, swf);
                                }

                                sw[ind] += swf;
                            }

                            sw[ind] = sw[ind] / 10;
                        }
                        else
                        {
                            if (pcOW >= powMax)
                            {
                                sw[ind] = projectData->Stratum().SWOF().size() > satNum && projectData->Stratum().SWOF()[satNum].size() > 0 ? projectData->Stratum().SWOF()[satNum][0].SW() : 0;
                            }
                            else if (pcOW <= powMin)
                            {
                                sw[ind] = projectData->Stratum().SWOF().size() > satNum && projectData->Stratum().SWOF()[satNum].size() > 0 ? projectData->Stratum().SWOF()[satNum][projectData->Stratum().SWOF()[satNum].size() - 1].SW() : 0;
                            }
                            else if (pcOW > powMin && pcOW < powMax)
                            {
                                SetPcForInvSw(projectData->Stratum(), satNum, pcOW, sw[ind]);
                            }
                        }
                    }

                    for (int r = m + 1; r < bList.size(); r++)
                    {
                        int i, j, k;
                        int ind = bList[r];

                        DataHelper::DivideOnAxesNodes(ind, nx, ny, i, j, k);

                        int satNum = projectData->satNUM(i, j, k);

                        double depth = projectData->depth(i, j, k);

                        // TODO: Capillary pressure  not only on SWOF and default values are calculated
                        double powBegin = projectData->Stratum().SWOF().size() > satNum && projectData->Stratum().SWOF()[satNum].size() > 0 ? projectData->Stratum().SWOF()[satNum][0].Pc().toDouble() : 0;
                        double powEnd = projectData->Stratum().SWOF().size() > satNum && projectData->Stratum().SWOF()[satNum].size() > 0 ? projectData->Stratum().SWOF()[satNum][projectData->Stratum().SWOF()[satNum].size() - 1].Pc().toDouble() : 0;

                        if (dWOC >= depth)
                        {
                            pw[ind] = po[ind] - powBegin;
                        }
                        else
                        {
                            po[ind] = pw[ind] + powEnd;
                        }
                    }
                }                                                
            }
        }
    }
}

}}}
