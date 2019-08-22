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

    QList<int> indexes = equals->GetIndexes(arrayName);

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

    QList<int> indexes = copy->GetIndexes(arrayName);

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
    QList<int> indexes = multiply->GetIndexes(arrayName);

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
    QList<int> indexes = add->GetIndexes(arrayName);

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

double DataHelper::GetPoFromPVT(StratumData &stratum, int pvtNum, int rowNum)
{
    return stratum.PVTO().length() > 0 ? stratum.PVTO()[pvtNum][rowNum].PO() : stratum.PVDO()[pvtNum][rowNum].PO();
}

double DataHelper::GetBoFromPVT(StratumData &stratum, int pvtNum, int rowNum)
{
    return stratum.PVTO().length() > 0 ? stratum.PVTO()[pvtNum][rowNum].BO() : stratum.PVDO()[pvtNum][rowNum].BO();
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

}}}
