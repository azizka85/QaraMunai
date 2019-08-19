#include "eclipsefilereader.h"

namespace QaraMunai {
namespace Model {
namespace DAO {

EclipseFileReader::EclipseFileReader(QObject *parent) : IDataFileReader(parent)
{
    InitVariables();
}

void EclipseFileReader::load(ProjectData *data, const QString &filePath)
{
    data->initVariables();

    QMetaObject metaObject = staticMetaObject;

    QMetaEnum casesEnum = metaObject.enumerator(metaObject.indexOfEnumerator("Cases"));

    ReadFile(data, filePath, casesEnum);    
}

void EclipseFileReader::InitVariables() { }

void EclipseFileReader::ReadFile(ProjectData *data, const QString &filePath, QMetaEnum &casesEnum)
{
    QString currentDir = QFileInfo(filePath).dir().path();

    QFile file(filePath);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;

    QTextStream sr(&file);

    while (true)
    {
        QString line = ReadFileHelper::GetNextLine(sr);
        if (line == nullptr) break;

        QString keyword = ReadFileHelper::ParseKeyword(line);

        keyword = keyword.replace('-', 'm')
                            .replace('+', 'p');

        int index = casesEnum.keyToValue(keyword.toLatin1());

        switch (index)
        {
            // RUNSPEC
            case RUNSPEC: break;
            case TITLE: ReadTITLE(data, sr); break;
            case START: ReadSTART(data, sr); break;
            case METRIC: data->SetUnit(ProjectData::METRIC); break;
            case FIELD: data->SetUnit(ProjectData::FIELD); break;
            case LAB: data->SetUnit(ProjectData::LAB); break;
            case PVTmM: data->SetUnit(ProjectData::LAB); break;
            case UNIFOUT: break;
            case OIL: break;
            case WATER: break;
            case GAS: data->SetModel(ProjectData::ThreePhase); break;
            case DISGAS: break;
            case TEMP: data->SetTemperatureOption(true); break;
            case NOECHO: break;
            case IMPLICIT: break;
            case FULLIMP: break;
            case IMPES: break;
            case NUMRES: ReadNUMRES(data, sr); break;
            case DIMENS: ReadDIMENS(data, sr); break;
            case REGDIMS: ReadFileHelper::IgnoreParams(sr); break;
            case TABDIMS: ReadTABDIMS(data, sr); break;
            case EQLDIMS: ReadEQLDIMS(data, sr); break;
            case WELLDIMS: ReadFileHelper::IgnoreParams(sr); break;
            case ENDSCALE: ReadENDSCALE(data, sr); break;
            case BLACKOIL: break;
            case DEADOIL: break;

            // GRID
            case GRID: break;
            case INIT: break;
            case GRIDFILE: ReadFileHelper::IgnoreParams(sr); break;
            case TOPS: ReadFileHelper::Read2DArray(sr, box, data->Stratum().TOPS()); break;
            case DX: ReadFileHelper::Read3DArray(sr, box, data->Stratum().DX()); break;
            case DY: ReadFileHelper::Read3DArray(sr, box, data->Stratum().DY()); break;
            case DZ: ReadFileHelper::Read3DArray(sr, box, data->Stratum().DZ()); break;
            case DXV: ReadFileHelper::ReadVector(sr, box, data->Stratum().DXV()); break;
            case DYV: ReadFileHelper::ReadVector(sr, box, data->Stratum().DYV()); break;
            case DZV: ReadFileHelper::ReadVector(sr, box, data->Stratum().DZV()); break;
            case COORD: ReadFileHelper::ReadVector(sr, box, data->Stratum().COORD()); break;
            case ZCORN: ReadFileHelper::ReadVector(sr, box, data->Stratum().ZCORN()); break;
            case ACTNUM: ReadFileHelper::Read3DArray(sr, box, data->Stratum().ACTNUM()); break;
            case MULTPV: ReadFileHelper::Read3DArray(sr, box, data->Stratum().MULTPV()); break;
            case PERMX: ReadFileHelper::Read3DArray(sr, box, data->Stratum().PERMX()); break;
            case PERMY: ReadFileHelper::Read3DArray(sr, box, data->Stratum().PERMY()); break;
            case PERMZ: ReadFileHelper::Read3DArray(sr, box, data->Stratum().PERMZ()); break;
            case PORO: ReadFileHelper::Read3DArray(sr, box, data->Stratum().PORO()); break;
            case NTG: ReadFileHelper::Read3DArray(sr, box, data->Stratum().NTG()); break;
            case DZNET: ReadFileHelper::Read3DArray(sr, box, data->Stratum().DZNET()); break;
            case MULTX: ReadFileHelper::Read3DArray(sr, box, data->Stratum().MULTX()); break;
            case MULTY: ReadFileHelper::Read3DArray(sr, box, data->Stratum().MULTY()); break;
            case MULTZ: ReadFileHelper::Read3DArray(sr, box, data->Stratum().MULTZ()); break;
            case MULTXm: ReadFileHelper::Read3DArray(sr, box, data->Stratum().MULTXm()); break;
            case MULTYm: ReadFileHelper::Read3DArray(sr, box, data->Stratum().MULTYm()); break;
            case MULTZm: ReadFileHelper::Read3DArray(sr, box, data->Stratum().MULTZm()); break;
            case MINPV: ReadMINPV(data, sr); break;
            case MINPVV: ReadFileHelper::Read3DArray(sr, box, data->Stratum().MINPVV()); break;

            // PROPS
            case PROPS: break;
            case STONE: break; // STONE2
            case STONE1: break; // STONE1
            case STONE2: break; // STONE2
            case RSCONST: ReadRSCONST(data, sr); break;
            case RSCONSTT: ReadRSCONSTT(data, sr); break;
            case PVTO: ReadPVTO(data, sr); break;
            case PVCO: ReadPVCO(data, sr); break;
            case PMAX: ReadPMAX(data, sr); break;
            case PVCDO: ReadPVCDO(data, sr); break;
            case PVDO: ReadPVDO(data, sr); break;
            case PVTW: ReadPVTW(data, sr); break;
            case PVDG: ReadPVDG(data, sr); break;
            case PVTG: ReadPVTG(data, sr); break;
            case ROCKOPTS: ReadROCKOPTS(data, sr); break;
            case ROCK: ReadROCK(data, sr); break;
            case DENSITY: ReadDENSITY(data, sr); break;
            case GRAVITY: ReadGRAVITY(data, sr); break;
            case SWOF: ReadSWOF(data, sr); break;
            case SGOF: ReadSGOF(data, sr); break;
            case SGWFN: ReadSGWFN(data, sr); break;
            case SLGOF: ReadSLGOF(data, sr); break;
            case SOF2: ReadSOF2(data, sr); break;
            case SOF3: ReadSOF3(data, sr); break;
            case SOF32D: ReadSOF32D(data, sr); break;
            case SWFN: ReadSWFN(data, sr); break;
            case SGFN: ReadSGFN(data, sr); break;
            case SOMGAS: ReadSOMGAS(data, sr); break;
            case SOMWAT: ReadSOMWAT(data, sr); break;
            case SWATINIT: ReadFileHelper::Read3DArray(sr, box, data->Stratum().SWATINIT()); break;
            case SWCR: ReadFileHelper::Read3DArray(sr, box, data->Stratum().SWCR()); break;
            case ISWCR: ReadFileHelper::Read3DArray(sr, box, data->Stratum().ISWCR()); break;
            case SWL: ReadFileHelper::Read3DArray(sr, box, data->Stratum().SWL()); break;
            case ISWL: ReadFileHelper::Read3DArray(sr, box, data->Stratum().ISWL()); break;
            case SWLPC: ReadFileHelper::Read3DArray(sr, box, data->Stratum().SWLPC()); break;
            case ISWLPC: ReadFileHelper::Read3DArray(sr, box, data->Stratum().ISWLPC()); break;
            case SWU: ReadFileHelper::Read3DArray(sr, box, data->Stratum().SWU()); break;
            case ISWU: ReadFileHelper::Read3DArray(sr, box, data->Stratum().ISWU()); break;
            case SGCR: ReadFileHelper::Read3DArray(sr, box, data->Stratum().SGCR()); break;
            case ISGCR: ReadFileHelper::Read3DArray(sr, box, data->Stratum().ISGCR()); break;
            case SGL: ReadFileHelper::Read3DArray(sr, box, data->Stratum().SGL()); break;
            case ISGL: ReadFileHelper::Read3DArray(sr, box, data->Stratum().ISGL()); break;
            case SGLPC: ReadFileHelper::Read3DArray(sr, box, data->Stratum().SGLPC()); break;
            case ISGLPC: ReadFileHelper::Read3DArray(sr, box, data->Stratum().ISGLPC()); break;
            case PCG: ReadFileHelper::Read3DArray(sr, box, data->Stratum().PCG()); break;
            case IPCG: ReadFileHelper::Read3DArray(sr, box, data->Stratum().IPCG()); break;
            case PCW: ReadFileHelper::Read3DArray(sr, box, data->Stratum().PCW()); break;
            case IPCW: ReadFileHelper::Read3DArray(sr, box, data->Stratum().IPCW()); break;
            case PPCWMAX: ReadPPCWMAX(data, sr); break;
            case KRO: ReadFileHelper::Read3DArray(sr, box, data->Stratum().KRO()); break;
            case IKRO: ReadFileHelper::Read3DArray(sr, box, data->Stratum().IKRO()); break;
            case KRORW: ReadFileHelper::Read3DArray(sr, box, data->Stratum().KRORW()); break;
            case IKRORW: ReadFileHelper::Read3DArray(sr, box, data->Stratum().IKRORW()); break;
            case KRORG: ReadFileHelper::Read3DArray(sr, box, data->Stratum().KRORG()); break;
            case IKRORG: ReadFileHelper::Read3DArray(sr, box, data->Stratum().IKRORG()); break;
            case KRW: ReadFileHelper::Read3DArray(sr, box, data->Stratum().KRW()); break;
            case IKRW: ReadFileHelper::Read3DArray(sr, box, data->Stratum().IKRW()); break;
            case KRWR: ReadFileHelper::Read3DArray(sr, box, data->Stratum().KRWR()); break;
            case IKRWR: ReadFileHelper::Read3DArray(sr, box, data->Stratum().IKRWR()); break;
            case KRG: ReadFileHelper::Read3DArray(sr, box, data->Stratum().KRG()); break;
            case IKRG: ReadFileHelper::Read3DArray(sr, box, data->Stratum().IKRG()); break;
            case KRGR: ReadFileHelper::Read3DArray(sr, box, data->Stratum().KRGR()); break;
            case IKRGR: ReadFileHelper::Read3DArray(sr, box, data->Stratum().IKRGR()); break;
            case ENKRVD: ReadENKRVD(data, sr); break;
            case ENPCVD: ReadENPCVD(data, sr); break;
            case ENSPCVD: ReadENSPCVD(data, sr); break;
            case SCALELIM: ReadSCALELIM(data, sr); break;
            case SCALECRS: ReadSCALECRS(data, sr); break;
            case SPECHEAT: ReadSPECHEAT(data, sr); break;
            case SPECROCK: ReadSPECROCK(data, sr); break;
            case VISCREF: ReadVISCREF(data, sr); break;
            case OILVISCT: ReadOILVISCT(data, sr); break;
            case WATVISCT: ReadWATVISCT(data, sr); break;

            // REGIONS
            case REGIONS: break;
            case PVTNUM: ReadFileHelper::Read3DArray(sr, box, data->Stratum().PVTNUM()); break;
            case SATNUM: ReadFileHelper::Read3DArray(sr, box, data->Stratum().SATNUM()); break;
            case EQLNUM: ReadFileHelper::Read3DArray(sr, box, data->Stratum().EQLNUM()); break;
            case ENDNUM: ReadFileHelper::Read3DArray(sr, box, data->Stratum().ENDNUM()); break;
            case FIPNUM: ReadFileHelper::IgnoreParams(sr); break;

            // SOLUTION
            case SOLUTION: break;
            case EQUIL: ReadEQUIL(data, sr); break;
            case RSVD: ReadRSVD(data, sr); break;
            case PBVD: ReadPBVD(data, sr); break;
            case PRVD: ReadPRVD(data, sr); break;
            case PRESSURE: ReadFileHelper::Read3DArray(sr, box, data->Stratum().PRESSURE()); break;
            case SWAT: ReadFileHelper::Read3DArray(sr, box, data->Stratum().SWAT()); break;
            case SGAS: ReadFileHelper::Read3DArray(sr, box, data->Stratum().SGAS()); break;
            case PBUB: ReadFileHelper::Read3DArray(sr, box, data->Stratum().PBUB()); break;
            case RS: ReadFileHelper::Read3DArray(sr, box, data->Stratum().RS()); break;
            case AQUANCON: ReadAQUANCON(data, sr); break;
            case AQUFETP: ReadAQUFETP(data, sr); break;

            // SUMMARY
            case SUMMARY: break;
            case ALL: break;
            case RUNSUM: break;
            case RPTONLY: break;

            // SCHEDULE
            case SCHEDULE: break;
            case DIMPLICT: break;
            case DIMPES: ReadDIMPES(data, sr); break;
            case RPTRST: ReadFileHelper::IgnoreParams(sr); break;
            case RPTSCHED: ReadFileHelper::IgnoreParams(sr); break;
            case WELSPECS: ReadWELSPECS(data, sr); break;
            case COMPDAT: ReadCOMPDAT(data, sr); break;
            case WCONPROD: ReadWCONPROD(data, sr); break;
            case WCONINJE: ReadWCONINJE(data, sr); break;
            case DATES: ReadDATES(data, sr); break;
            case TSTEP: ReadTSTEP(data, sr); break;
            case WCONHIST: ReadWCONHIST(data, sr); break;
            case WCONINJH: ReadWCONINJH(data, sr); break;
            case WELTARG: ReadWELTARG(data, sr); break;

            // ANY SECTION
            case INCLUDE: ReadINCLUDE(data, sr, currentDir, casesEnum); break;
            case EQUALS: ReadEQUALS(data, sr); break;
            case BOX: ReadBOX(sr); break;
            case ENDBOX: ReadENDBOX(data); break;
            case COPY: ReadCOPY(data, sr); break;
            case ADD: ReadADD(data, sr); break;
            case MULTIPLY: ReadMULTIPLY(data, sr); break;
            case EDIT: break;
            case DEPTH: ReadFileHelper::Read3DArray(sr, box, data->Stratum().DEPTH()); break;
            case PORV: ReadFileHelper::Read3DArray(sr, box, data->Stratum().PORV()); break;
            case TRANX: ReadFileHelper::Read3DArray(sr, box, data->Stratum().TRANX()); break;
            case TRANY: ReadFileHelper::Read3DArray(sr, box, data->Stratum().TRANY()); break;
            case TRANZ: ReadFileHelper::Read3DArray(sr, box, data->Stratum().TRANZ()); break;
            case END: break;

            default: qDebug() << QString("%1: !!!unknown line: %2").arg(index).arg(keyword); break;
        }
    }

    data->SetIsLoaded(true);

    file.close();
}

// RUNSPEC
void EclipseFileReader::ReadTITLE(ProjectData *data, QTextStream &sr)
{
    data->SetTitle(ReadFileHelper::GetNextLine(sr));
}

void EclipseFileReader::ReadSTART(ProjectData *data, QTextStream &sr)
{
    QMetaObject metaObject = staticMetaObject;

    QMetaEnum monthsEnum = metaObject.enumerator(metaObject.indexOfEnumerator("Months"));

    QStringList str = ReadFileHelper::ParseParams(sr);    

    QString dateStr = ReadFileHelper::EclipseDateToStr(str, monthsEnum);

    QDateTime date = ReadFileHelper::StrToDate(dateStr);

    data->SetStartDate(date);

    data->Stratum().DATES().append(date);

    currentDate = date;
}

void EclipseFileReader::ReadNUMRES(ProjectData *data, QTextStream &sr)
{
    QStringList str = ReadFileHelper::ParseParams(sr);

    if(str.length() > 1 && str[0] == "1*") data->SetNumRES(str[0].toInt());
}

void EclipseFileReader::ReadDIMENS(ProjectData *data, QTextStream &sr)
{
    QStringList str = ReadFileHelper::ParseParams(sr);

    int nx = str[0].toInt();
    int ny = str[1].toInt();
    int nz = str[2].toInt();

    data->SetNx(nx);
    data->SetNy(ny);
    data->SetNz(nz);

    box.SetI1(0); box.SetI2(nx - 1);
    box.SetJ1(0); box.SetJ2(ny - 1);
    box.SetK1(0); box.SetK2(nz - 1);
}

void EclipseFileReader::ReadTABDIMS(ProjectData *data, QTextStream &sr)
{
    QStringList str = ReadFileHelper::ParseParams(sr);

    if (str.length() > 1 && str[0] != "1*") data->Stratum().TABDIMS().SetNTSFUN(str[0].toInt());

    if (str.length() > 2 && str[1] != "1*") data->Stratum().TABDIMS().SetNTPVT(str[1].toInt());

    if (str.length() > 3 && str[2] != "1*") data->Stratum().TABDIMS().SetNSSFUN(str[2].toInt());
}

void EclipseFileReader::ReadEQLDIMS(ProjectData *data, QTextStream &sr)
{
    QStringList str = ReadFileHelper::ParseParams(sr);

    if (str.length() > 1 && str[0] != "1*") data->Stratum().EQLDIMS().SetNTEQUL(str[0].toInt());
}

void EclipseFileReader::ReadENDSCALE(ProjectData *data, QTextStream &sr)
{
    QMetaObject metaObject = ENDSCALEEntity::staticMetaObject;

    QMetaEnum directionalTypes = metaObject.enumerator(metaObject.indexOfEnumerator("DirectionalType"));
    QMetaEnum irreversibleTypes = metaObject.enumerator(metaObject.indexOfEnumerator("IrreversibleType"));

    QStringList str = ReadFileHelper::GetNextLineWords(sr);

    if (str.length() > 1 && str[0] != "1*")
    {
        int directionalType = directionalTypes.keyToValue(str[0].toLatin1());

        data->Stratum().ENDSCALE().SetDirectional(directionalType);
    }

    if (str.length() > 2 && str[1] != "1*")
    {
        int irreversibleType = irreversibleTypes.keyToValue(str[1].toLatin1());

        data->Stratum().ENDSCALE().SetIrreversible(irreversibleType);
    }

    if (str.length() > 3 && str[2] != "1*") data->Stratum().ENDSCALE().SetNTENDP(str[2].toInt());

    if (str.length() > 4 && str[3] != "1*") data->Stratum().ENDSCALE().SetMaxNodesEPD(str[3].toInt());
}

// GRID
void EclipseFileReader::ReadMINPV(ProjectData *data, QTextStream &sr)
{
    QStringList str = ReadFileHelper::ParseParams(sr);

    data->Stratum().SetMINPV(str[0].toDouble());
}

// PROPS
void EclipseFileReader::ReadRSCONST(ProjectData *data, QTextStream &sr)
{
    QStringList str = ReadFileHelper::ParseParams(sr);

    data->Stratum().RSCONST().SetRS(str[0].toDouble());
    data->Stratum().RSCONST().SetPBub(str[1].toDouble());
}

void EclipseFileReader::ReadRSCONSTT(ProjectData *data, QTextStream &sr)
{
    int ntPVT = data->Stratum().TABDIMS().NTPVT().isNull() ? DefaultValues::TABDIMS_NTPVT : data->Stratum().TABDIMS().NTPVT().toInt();

    for (int reg = 0; reg < ntPVT; reg++)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);

        RSCONSTData rsCONST;

        rsCONST.SetRS(str[0].toDouble());
        rsCONST.SetPBub(str[1].toDouble());

        data->Stratum().RSCONSTT().append(rsCONST);
    }
}

void EclipseFileReader::ReadPVTO(ProjectData *data, QTextStream &sr)
{
    int ntPVT = data->Stratum().TABDIMS().NTPVT().isNull() ? DefaultValues::TABDIMS_NTPVT : data->Stratum().TABDIMS().NTPVT().toInt();

    for (int reg = 0; reg < ntPVT; reg++)
    {
       QList<PVTOData> pvtoList;

        while (true)
        {
            QStringList str = ReadFileHelper::ParseParams(sr);

            if (str.length() == 0) break;

            double rs = str[0].toDouble();

            for (int i = 0; i < (str.length() - 2) / 3; i++)
            {
                PVTOData pvto;

                pvto.SetRS(rs);

                pvto.SetPO(str[1 + 3 * i].toDouble());
                pvto.SetBO(str[2 + 3 * i].toDouble());
                pvto.SetMO(str[3 + 3 * i].toDouble());

                pvtoList.append(pvto);
            }
        }

        data->Stratum().PVTO().append(pvtoList);
    }
}

void EclipseFileReader::ReadPVCO(ProjectData *data, QTextStream &sr)
{
    int ntPVT = data->Stratum().TABDIMS().NTPVT().isNull() ? DefaultValues::TABDIMS_NTPVT : data->Stratum().TABDIMS().NTPVT().toInt();

    for (int reg = 0; reg < ntPVT; reg++)
    {
        QList<PVCOData> pvcoList;

        QStringList str = ReadFileHelper::ParseParams(sr);

        for (int i = 0; i < (str.length() - 1) / 6; i++)
        {
            PVCOData pvco;

            pvco.SetPO(str[0 + 6 * i].toDouble());

            if (str[1 + 6 * i] != "1*") pvco.SetRS(str[1 + 6 * i].toDouble());
            if (str[2 + 6 * i] != "1*") pvco.SetBO(str[2 + 6 * i].toDouble());
            if (str[3 + 6 * i] != "1*") pvco.SetMO(str[3 + 6 * i].toDouble());
            if (str[4 + 6 * i] != "1*") pvco.SetCO(str[4 + 6 * i].toDouble());
            if (str[5 + 6 * i] != "1*") pvco.SetCVO(str[5 + 6 * i].toDouble());

            pvcoList.append(pvco);
        }

        data->Stratum().PVCO().append(pvcoList);
    }
}

void EclipseFileReader::ReadPMAX(ProjectData *data, QTextStream &sr)
{
    QStringList str = ReadFileHelper::ParseParams(sr);

    if (str.length() > 1 && str[0] != "1*") data->Stratum().PMAX().SetPMax(str[0].toDouble());

    if (str.length() > 2 && str[1] != "1*") data->Stratum().PMAX().SetPMaxComp(str[1].toDouble());
    if (str.length() > 3 && str[2] != "1*") data->Stratum().PMAX().SetPMinComp(str[2].toDouble());

    if (str.length() > 4 && str[3] != "1*") data->Stratum().PMAX().SetNumNodes(str[3].toInt());
}

void EclipseFileReader::ReadPVCDO(ProjectData *data, QTextStream &sr)
{
    int ntPVT = data->Stratum().TABDIMS().NTPVT().isNull() ? DefaultValues::TABDIMS_NTPVT : data->Stratum().TABDIMS().NTPVT().toInt();

    for (int reg = 0; reg < ntPVT; reg++)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);

        PVCDOData pvcdo;

        pvcdo.SetPORef(str[0].toDouble());
        pvcdo.SetBORef(str[1].toDouble());
        pvcdo.SetCO(str[2].toDouble());
        pvcdo.SetMORef(str[3].toDouble());
        pvcdo.SetCVO(str[4].toDouble());

        data->Stratum().PVCDO().append(pvcdo);
    }

}

void EclipseFileReader::ReadPVDO(ProjectData *data, QTextStream &sr)
{
    int ntPVT = data->Stratum().TABDIMS().NTPVT().isNull() ? DefaultValues::TABDIMS_NTPVT : data->Stratum().TABDIMS().NTPVT().toInt();

    for (int reg = 0; reg < ntPVT; reg++)
    {
        QList<PVDOData> pvdoList;

        QStringList str = ReadFileHelper::ParseParams(sr);

        for (int i = 0; i < (str.length()-1) / 3; i++)
        {
            PVDOData pvdo;

            pvdo.SetPO(str[0 + 3*i].toDouble());
            pvdo.SetBO(str[1 + 3*i].toDouble());
            pvdo.SetMO(str[2 + 3*i].toDouble());

            pvdoList.append(pvdo);
        }

        data->Stratum().PVDO().append(pvdoList);
    }
}

void EclipseFileReader::ReadPVTW(ProjectData *data, QTextStream &sr)
{
    int ntPVT = data->Stratum().TABDIMS().NTPVT().isNull() ? DefaultValues::TABDIMS_NTPVT : data->Stratum().TABDIMS().NTPVT().toInt();

    for (int reg = 0; reg < ntPVT; reg++)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);

        PVTWData pvtw;

        if (str.length() > 1 && str[0] != "1*") pvtw.SetPWRef(str[0].toDouble());
        if (str.length() > 2 && str[1] != "1*") pvtw.SetBWRef(str[1].toDouble());
        if (str.length() > 3 && str[2] != "1*") pvtw.SetCW(str[2].toDouble());
        if (str.length() > 4 && str[3] != "1*") pvtw.SetMWRef(str[3].toDouble());
        if (str.length() > 5 && str[4] != "1*") pvtw.SetCVW(str[4].toDouble());

        data->Stratum().PVTW().append(pvtw);
    }
}

void EclipseFileReader::ReadPVDG(ProjectData *data, QTextStream &sr)
{
    int ntPVT = data->Stratum().TABDIMS().NTPVT().isNull() ? DefaultValues::TABDIMS_NTPVT : data->Stratum().TABDIMS().NTPVT().toInt();

    for (int reg = 0; reg < ntPVT; reg++)
    {
        QList<PVDGData> pvdgList;

        QStringList str = ReadFileHelper::ParseParams(sr);

        for (int i = 0; i < (str.length() - 1) / 3; i++)
        {
            PVDGData pvdg;

            pvdg.SetPG(str[0 + i * 3].toDouble());
            pvdg.SetBG(str[1 + i * 3].toDouble());
            pvdg.SetMG(str[2 + i * 3].toDouble());

            pvdgList.append(pvdg);
        }

        data->Stratum().PVDG().append(pvdgList);
    }
}

void EclipseFileReader::ReadPVTG(ProjectData *data, QTextStream &sr)
{
    int ntPVT = data->Stratum().TABDIMS().NTPVT().isNull() ? DefaultValues::TABDIMS_NTPVT : data->Stratum().TABDIMS().NTPVT().toInt();

    for (int reg = 0; reg < ntPVT; reg++)
    {
        QList<PVTGData> pvtgList;

        while (true)
        {
            QStringList str = ReadFileHelper::ParseParams(sr);

            if (str.length() == 0) break;

            double pg = str[0].toDouble();

            for (int i = 0; i < (str.length() - 2) / 3; i++)
            {
                PVTGData pvtg;

                pvtg.SetPG(pg);

                pvtg.SetRV(str[1 + 3 * i].toDouble());
                pvtg.SetBG(str[2 + 3 * i].toDouble());
                pvtg.SetMG(str[3 + 3 * i].toDouble());

                pvtgList.append(pvtg);
            }
        }

        data->Stratum().PVTG().append(pvtgList);
    }
}

void EclipseFileReader::ReadROCKOPTS(ProjectData *data, QTextStream &sr)
{
    QStringList str = ReadFileHelper::GetNextLineWords(sr);

    QMetaObject metaObject = ROCKOPTSEntity::staticMetaObject;

    if (str.length() > 1 && str[0] != "1*")
    {
        QMetaEnum maotpOptions = metaObject.enumerator(metaObject.indexOfEnumerator("MAOTPOptions"));

        data->Stratum().ROCKOPTS().SetMAOTP(maotpOptions.keyToValue(str[0].toLatin1()));
    }
    if (str.length() > 2 && str[1] != "1*")
    {
        QMetaEnum referencePressureOptions = metaObject.enumerator(metaObject.indexOfEnumerator("ReferencePressureOptions"));

        data->Stratum().ROCKOPTS().SetRPO(referencePressureOptions.keyToValue(str[1].toLatin1()));
    }
    if (str.length() > 3 && str[2] != "1*")
    {
        QMetaEnum regionOptions = metaObject.enumerator(metaObject.indexOfEnumerator("RegionOptions"));

        data->Stratum().ROCKOPTS().SetRegionOption(regionOptions.keyToValue(str[2].toLatin1()));
    }
    if (str.length() > 4 && str[3] != "1*")
    {
        QMetaEnum ihbOptions = metaObject.enumerator(metaObject.indexOfEnumerator("IHBOptions"));

        data->Stratum().ROCKOPTS().SetIHBOption(ihbOptions.keyToValue(str[3].toLatin1()));
    }
}

void EclipseFileReader::ReadROCK(ProjectData *data, QTextStream &sr)
{
    int regionOption = !data->Stratum().ROCKOPTS().RegionOption().isNull() ?
                                    data->Stratum().ROCKOPTS().RegionOption().toInt() :
                                    DefaultValues::ROCKOPTS_RegionOption;

    int nt = regionOption == ROCKOPTSEntity::PVTNUM ?
                                data->Stratum().TABDIMS().NTPVT().isNull() ? DefaultValues::TABDIMS_NTPVT : data->Stratum().TABDIMS().NTPVT().toInt() :
                                data->Stratum().TABDIMS().NTSFUN().isNull() ? DefaultValues::TABDIMS_NTSFUN : data->Stratum().TABDIMS().NTSFUN().toInt();

    for (int reg = 0; reg < nt; reg++)
    {
        ROCKData rock;

        QStringList str = ReadFileHelper::ParseParams(sr);

        if (str.length() > 1 && str[0] != "1*") rock.SetPRef(str[0].toDouble());
        if (str.length() > 2 && str[1] != "1*") rock.SetCPP(str[1].toDouble());

        data->Stratum().ROCK().append(rock);
    }
}

void EclipseFileReader::ReadDENSITY(ProjectData *data, QTextStream &sr)
{
    int ntPVT = data->Stratum().TABDIMS().NTPVT().isNull() ? DefaultValues::TABDIMS_NTPVT : data->Stratum().TABDIMS().NTPVT().toInt();

    for (int reg = 0; reg < ntPVT; reg++)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);

        DENSITYData density;

        if (str.length() > 1 && str[0] != "1*") density.SetRO(str[0].toDouble());
        if (str.length() > 2 && str[1] != "1*") density.SetRW(str[1].toDouble());
        if (str.length() > 3 && str[2] != "1*") density.SetRG(str[2].toDouble());

        data->Stratum().DENSITY().append(density);
    }
}

void EclipseFileReader::ReadGRAVITY(ProjectData *data, QTextStream &sr)
{
    int ntPVT = data->Stratum().TABDIMS().NTPVT().isNull() ? DefaultValues::TABDIMS_NTPVT : data->Stratum().TABDIMS().NTPVT().toInt();

    for (int reg = 0; reg < ntPVT; reg++)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);

        GRAVITYData gravity;

        if (str.length() > 1 && str[0] != "1*") gravity.SetGO(str[0].toDouble());
        if (str.length() > 2 && str[1] != "1*") gravity.SetGW(str[1].toDouble());
        if (str.length() > 3 && str[2] != "1*") gravity.SetGG(str[2].toDouble());

        data->Stratum().GRAVITY().append(gravity);
    }
}

void EclipseFileReader::ReadSWOF(ProjectData *data, QTextStream &sr)
{
    int ntSFUN = data->Stratum().TABDIMS().NTSFUN().isNull() ? DefaultValues::TABDIMS_NTSFUN : data->Stratum().TABDIMS().NTSFUN().toInt();

    for (int reg = 0; reg < ntSFUN; reg++)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);

        QList<SWOFData> swofList;

        for (int i = 0; i < (str.length() - 1) / 4; i++)
        {
            SWOFData swof;

            swof.SetSW(str[0 + 4 * i].toDouble());
            if (str[1 + 4 * i] != "1*") swof.SetKrW(str[1 + 4 * i].toDouble());
            if (str[2 + 4 * i] != "1*") swof.SetKrO(str[2 + 4 * i].toDouble());
            if (str[3 + 4 * i] != "1*") swof.SetPc(str[3 + 4 * i].toDouble());

            swofList.append(swof);
        }

        data->Stratum().SWOF().append(swofList);
    }
}

void EclipseFileReader::ReadSGOF(ProjectData *data, QTextStream &sr)
{
    int ntSFUN = data->Stratum().TABDIMS().NTSFUN().isNull() ? DefaultValues::TABDIMS_NTSFUN : data->Stratum().TABDIMS().NTSFUN().toInt();

    for (int reg = 0; reg < ntSFUN; reg++)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);

        QList<SGOFData> sgofList;

        for (int i = 0; i < (str.length() - 1) / 4; i++)
        {
            SGOFData sgof;

            sgof.SetSG(str[0 + 4 * i].toDouble());
            if (str[1 + 4 * i] != "1*") sgof.SetKrG(str[1 + 4 * i].toDouble());
            if (str[2 + 4 * i] != "1*") sgof.SetKrO(str[2 + 4 * i].toDouble());
            if (str[3 + 4 * i] != "1*") sgof.SetPc(str[3 + 4 * i].toDouble());

            sgofList.append(sgof);
        }

        data->Stratum().SGOF().append(sgofList);
    }
}

void EclipseFileReader::ReadSGWFN(ProjectData *data, QTextStream &sr)
{
    int ntSFUN = data->Stratum().TABDIMS().NTSFUN().isNull() ? DefaultValues::TABDIMS_NTSFUN : data->Stratum().TABDIMS().NTSFUN().toInt();

    for (int reg = 0; reg < ntSFUN; reg++)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);

        QList<SGWFNData> sgwfnList;

        for (int i = 0; i < (str.length() - 1) / 4; i++)
        {
            SGWFNData sgwfn;

            sgwfn.SetSG(str[0 + 4 * i].toDouble());
            if (str[1 + 4 * i] != "1*") sgwfn.SetKrG(str[1 + 4 * i].toDouble());
            if (str[2 + 4 * i] != "1*") sgwfn.SetKrW(str[2 + 4 * i].toDouble());
            if (str[3 + 4 * i] != "1*") sgwfn.SetPc(str[3 + 4 * i].toDouble());

            sgwfnList.append(sgwfn);
        }

        data->Stratum().SGWFN().append(sgwfnList);
    }
}

void EclipseFileReader::ReadSLGOF(ProjectData *data, QTextStream &sr)
{
    int ntSFUN = data->Stratum().TABDIMS().NTSFUN().isNull() ? DefaultValues::TABDIMS_NTSFUN : data->Stratum().TABDIMS().NTSFUN().toInt();

    for (int reg = 0; reg < ntSFUN; reg++)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);

        QList<SLGOFData> slgofList;

        for (int i = 0; i < (str.length() - 1) / 4; i++)
        {
            SLGOFData slgof;

            slgof.SetSL(str[0 + 4 * i].toDouble());
            if (str[1 + 4 * i] != "1*") slgof.SetKrG(str[1 + 4 * i].toDouble());
            if (str[2 + 4 * i] != "1*") slgof.SetKrO(str[2 + 4 * i].toDouble());
            if (str[3 + 4 * i] != "1*") slgof.SetPc(str[3 + 4 * i].toDouble());

            slgofList.append(slgof);
        }

        data->Stratum().SLGOF().append(slgofList);
    }
}

void EclipseFileReader::ReadSOF2(ProjectData *data, QTextStream &sr)
{
    int ntSFUN = data->Stratum().TABDIMS().NTSFUN().isNull() ? DefaultValues::TABDIMS_NTSFUN : data->Stratum().TABDIMS().NTSFUN().toInt();

    for (int reg = 0; reg < ntSFUN; reg++)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);

        QList<SOF2Data> sof2List;

        for (int i = 0; i < (str.length() - 1) / 2; i++)
        {
            SOF2Data sof2;

            sof2.SetSO(str[0 + 2 * i].toDouble());
            sof2.SetKrO(str[1 + 2 * i].toDouble());

            sof2List.append(sof2);
        }

        data->Stratum().SOF2().append(sof2List);
    }
}

void EclipseFileReader::ReadSOF3(ProjectData *data, QTextStream &sr)
{
    int ntSFUN = data->Stratum().TABDIMS().NTSFUN().isNull() ? DefaultValues::TABDIMS_NTSFUN : data->Stratum().TABDIMS().NTSFUN().toInt();

    for (int reg = 0; reg < ntSFUN; reg++)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);

        QList<SOF3Data> sof3List;

        for (int i = 0; i < (str.length() - 1) / 3; i++)
        {
            SOF3Data sof3;

            sof3.SetSO(str[0 + 3 * i].toDouble());
            if (str[1 + 3 * i] != "1*") sof3.SetKrOW(str[1 + 3 * i].toDouble());
            if (str[2 + 3 * i] != "1*") sof3.SetKrOGWC(str[2 + 3 * i].toDouble());

            sof3List.append(sof3);
        }

        data->Stratum().SOF3().append(sof3List);
    }
}

void EclipseFileReader::ReadSOF32D(ProjectData *data, QTextStream &sr)
{
    int ntSFUN = data->Stratum().TABDIMS().NTSFUN().isNull() ? DefaultValues::TABDIMS_NTSFUN : data->Stratum().TABDIMS().NTSFUN().toInt();

    for (int reg = 0; reg < ntSFUN; reg++)
    {
        SOF32DData sof32d;

        // SWAT
        QStringList str = ReadFileHelper::ParseParams(sr);

        for (int i = 0; i < str.length() - 1; i++) sof32d.SW().append(str[i].toDouble());

        while (true)
        {
            str = ReadFileHelper::ParseParams(sr);

            if (str.length() == 0) break;

            SOF32DKrOData sof32dKrO;

            sof32dKrO.SetSG(str[0].toDouble());

            for (int i = 1; i < str.length() - 1; i++) sof32dKrO.KrO().append(str[i].toDouble());

            sof32d.SOF32DKrO().append(sof32dKrO);
        }

        data->Stratum().SOF32D().append(sof32d);
    }

}

void EclipseFileReader::ReadSWFN(ProjectData *data, QTextStream &sr)
{
    int ntSFUN = data->Stratum().TABDIMS().NTSFUN().isNull() ? DefaultValues::TABDIMS_NTSFUN : data->Stratum().TABDIMS().NTSFUN().toInt();

    for (int reg = 0; reg < ntSFUN; reg++)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);

        QList<SWFNData> swfnList;

        for (int i = 0; i < (str.length() - 1) / 3; i++)
        {
            SWFNData swfn;

            swfn.SetSW(str[0 + 3 * i].toDouble());
            if (str[1 + 3 * i] != "1*") swfn.SetKrW(str[1 + 3 * i].toDouble());
            if (str[2 + 3 * i] != "1*") swfn.SetPc(str[2 + 3 * i].toDouble());

            swfnList.append(swfn);
        }

        data->Stratum().SWFN().append(swfnList);
    }
}

void EclipseFileReader::ReadSGFN(ProjectData *data, QTextStream &sr)
{
    int ntSFUN = data->Stratum().TABDIMS().NTSFUN().isNull() ? DefaultValues::TABDIMS_NTSFUN : data->Stratum().TABDIMS().NTSFUN().toInt();

    for (int reg = 0; reg < ntSFUN; reg++)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);

        QList<SGFNData> sgfnList;

        for (int i = 0; i < (str.length() - 1) / 3; i++)
        {
            SGFNData sgfn;

            sgfn.SetSG(str[0 + 3 * i].toDouble());
            if (str[1 + 3 * i] != "1*") sgfn.SetKrG(str[1 + 3 * i].toDouble());
            if (str[2 + 3 * i] != "1*") sgfn.SetPc(str[2 + 3 * i].toDouble());

            sgfnList.append(sgfn);
        }

        data->Stratum().SGFN().append(sgfnList);
    }
}

void EclipseFileReader::ReadSOMGAS(ProjectData *data, QTextStream &sr)
{
    int ntSFUN = data->Stratum().TABDIMS().NTSFUN().isNull() ? DefaultValues::TABDIMS_NTSFUN : data->Stratum().TABDIMS().NTSFUN().toInt();

    for (int reg = 0; reg < ntSFUN; reg++)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);

        QList<SOMGASData> somgasList;

        for (int i = 0; i < (str.length() - 1) / 2; i++)
        {
            SOMGASData somgas;

            somgas.SetSG(str[0 + 2 * i].toDouble());
            somgas.SetSOMin(str[1 + 2 * i].toDouble());

            somgasList.append(somgas);
        }

        data->Stratum().SOMGAS().append(somgasList);
    }
}

void EclipseFileReader::ReadSOMWAT(ProjectData *data, QTextStream &sr)
{
    int ntSFUN = data->Stratum().TABDIMS().NTSFUN().isNull() ? DefaultValues::TABDIMS_NTSFUN : data->Stratum().TABDIMS().NTSFUN().toInt();

    for (int reg = 0; reg < ntSFUN; reg++)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);

        QList<SOMWATData> somwatList;

        for (int i = 0; i < (str.length() - 1) / 2; i++)
        {
            SOMWATData somwat;

            somwat.SetSW(str[0 + 2 * i].toDouble());
            somwat.SetSOMin(str[1 + 2 * i].toDouble());

            somwatList.append(somwat);
        }

        data->Stratum().SOMWAT().append(somwatList);
    }
}

void EclipseFileReader::ReadPPCWMAX(ProjectData *data, QTextStream &sr)
{
    int ntSFUN = data->Stratum().TABDIMS().NTSFUN().isNull() ? DefaultValues::TABDIMS_NTSFUN : data->Stratum().TABDIMS().NTSFUN().toInt();

    for (int reg = 0; reg < ntSFUN; reg++)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);

        PPCWMAXData ppcwMAX;

        if (str.length() > 1 && str[0] != "1*") ppcwMAX.SetPcMax(str[0].toDouble());

        if (str.length() > 2 && str[1] != "1*") ppcwMAX.SetSModify(ReadFileHelper::IsYes(str[1]));

        data->Stratum().PPCWMAX().append(ppcwMAX);
    }
}

void EclipseFileReader::ReadENKRVD(ProjectData *data, QTextStream &sr)
{
    int ntENDP = data->Stratum().ENDSCALE().NTENDP().isNull() ? DefaultValues::ENDSCALE_NTENDP : data->Stratum().ENDSCALE().NTENDP().toInt();

    for (int nt = 0; nt < ntENDP; nt++)
    {
        QList<ENKRVDData> enkrvdList;

        QStringList str = ReadFileHelper::ParseParams(sr);

        for (int i = 0; i < (str.length() - 1) / 8; i++)
        {
            ENKRVDData enkrvd;

            enkrvd.SetDepth(str[0 + 8 * i].toDouble());
            if (str[1 + 8 * i] != "1*") enkrvd.SetMaxKrW(str[1 + 8 * i].toDouble());
            if (str[2 + 8 * i] != "1*") enkrvd.SetMaxKrG(str[2 + 8 * i].toDouble());
            if (str[3 + 8 * i] != "1*") enkrvd.SetMaxKrO(str[3 + 8 * i].toDouble());
            if (str[4 + 8 * i] != "1*") enkrvd.SetKrWCO(str[4 + 8 * i].toDouble());
            if (str[5 + 8 * i] != "1*") enkrvd.SetKrGCO(str[5 + 8 * i].toDouble());
            if (str[6 + 8 * i] != "1*") enkrvd.SetKrOCG(str[6 + 8 * i].toDouble());
            if (str[7 + 8 * i] != "1*") enkrvd.SetKrOCW(str[7 + 8 * i].toDouble());

            enkrvdList.append(enkrvd);
        }

        data->Stratum().ENKRVD().append(enkrvdList);
    }
}

void EclipseFileReader::ReadENPCVD(ProjectData *data, QTextStream &sr)
{
    int ntENDP = data->Stratum().ENDSCALE().NTENDP().isNull() ? DefaultValues::ENDSCALE_NTENDP : data->Stratum().ENDSCALE().NTENDP().toInt();

    for (int nt = 0; nt < ntENDP; nt++)
    {
        QList<ENPCVDData> enpcvdList;

        QStringList str = ReadFileHelper::ParseParams(sr);

        for (int i = 0; i < (str.length() - 1) / 3; i++)
        {
            ENPCVDData enpcvd;

            enpcvd.SetDepth(str[0 + 3 * i].toDouble());
            if (str[1 + 3 * i] != "1*") enpcvd.SetMaxPcGO(str[1 + 3 * i].toDouble());
            if (str[2 + 3 * i] != "1*") enpcvd.SetMaxPcWO(str[2 + 3 * i].toDouble());

            enpcvdList.append(enpcvd);
        }

        data->Stratum().ENPCVD().append(enpcvdList);
    }
}

void EclipseFileReader::ReadENSPCVD(ProjectData *data, QTextStream &sr)
{
    int ntENDP = data->Stratum().ENDSCALE().NTENDP().isNull() ? DefaultValues::ENDSCALE_NTENDP : data->Stratum().ENDSCALE().NTENDP().toInt();

    for (int nt = 0; nt < ntENDP; nt++)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);

        QList<ENSPCVDData> enspcvdList;

        for (int i = 0; i < (str.length() - 1) / 3; i++)
        {
            ENSPCVDData enspcvd;

            enspcvd.SetDepth(str[0 + 3 * i].toDouble());
            if (str[1 + 3 * i] != "1*") enspcvd.SetSGL(str[1 + 3 * i].toDouble());
            if (str[2 + 3 * i] != "1*") enspcvd.SetSWL(str[2 + 3 * i].toDouble());

            enspcvdList.append(enspcvd);
        }

        data->Stratum().ENSPCVD().append(enspcvdList);
    }
}

void EclipseFileReader::ReadSCALELIM(ProjectData *data, QTextStream &sr)
{
    int ntENDP = data->Stratum().ENDSCALE().NTENDP().isNull() ? DefaultValues::ENDSCALE_NTENDP : data->Stratum().ENDSCALE().NTENDP().toInt();

    for (int nt = 0; nt < ntENDP; nt++)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);

        QVariant val;

        if (str.length() > 1 && str[0] != "1*") val = str[0].toDouble();

        data->Stratum().SCALELIM().append(val);
    }
}

void EclipseFileReader::ReadSCALECRS(ProjectData *data, QTextStream &sr)
{
    QString str = ReadFileHelper::GetNextLine(sr);

    data->Stratum().SetSCALECRS(ReadFileHelper::IsYes(str));
}

void EclipseFileReader::ReadSPECHEAT(ProjectData *data, QTextStream &sr)
{
    int ntPVT = data->Stratum().TABDIMS().NTPVT().isNull() ? DefaultValues::TABDIMS_NTPVT : data->Stratum().TABDIMS().NTPVT().toInt();

    for (int reg = 0; reg < ntPVT; reg++)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);

        QList<SPECHEATData> specHEATList;

        for (int i = 0; i < (str.length() - 1) / 4; i++)
        {
            SPECHEATData specHEAT;

            specHEAT.SetT(str[0 + 4 * i].toDouble());
            specHEAT.SetCO(str[1 + 4 * i].toDouble());
            specHEAT.SetCW(str[2 + 4 * i].toDouble());
            specHEAT.SetCG(str[3 + 4 * i].toDouble());

            specHEATList.append(specHEAT);
        }

        data->Stratum().SPECHEAT().append(specHEATList);
    }
}

void EclipseFileReader::ReadSPECROCK(ProjectData *data, QTextStream &sr)
{
    int ntSFUN = data->Stratum().TABDIMS().NTSFUN().isNull() ? DefaultValues::TABDIMS_NTSFUN : data->Stratum().TABDIMS().NTSFUN().toInt();

    for (int reg = 0; reg < ntSFUN; reg++)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);

        QList<SPECROCKData> specROCKList;

        for (int i = 0; i < (str.length() - 1) / 2; i++)
        {
            SPECROCKData specROCK;

            specROCK.SetT(str[0 + 2 * i].toDouble());
            specROCK.SetCV(str[1 + 2 * i].toDouble());

            specROCKList.append(specROCK);
        }

        data->Stratum().SPECROCK().append(specROCKList);
    }
}

void EclipseFileReader::ReadVISCREF(ProjectData *data, QTextStream &sr)
{
    int ntPVT = data->Stratum().TABDIMS().NTPVT().isNull() ? DefaultValues::TABDIMS_NTPVT : data->Stratum().TABDIMS().NTPVT().toInt();

    for (int reg = 0; reg < ntPVT; reg++)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);

        VISCREFData viscREF;

        viscREF.SetPRef(str[0].toDouble());
        if (str.length() > 2 && str[1] != "1*") viscREF.SetRSRef(str[1].toDouble());
        if (str.length() > 3 && str[2] != "1*") viscREF.SetGRef(str[2].toDouble());

        data->Stratum().VISCREF().append(viscREF);
    }
}

void EclipseFileReader::ReadOILVISCT(ProjectData *data, QTextStream &sr)
{
    int ntPVT = data->Stratum().TABDIMS().NTPVT().isNull() ? DefaultValues::TABDIMS_NTPVT : data->Stratum().TABDIMS().NTPVT().toInt();

    for (int reg = 0; reg < ntPVT; reg++)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);

        QList<OILVISCTData> oilVISCTList;

        for (int i = 0; i < (str.length() - 1) / 2; i++)
        {
            OILVISCTData oilVISCT;

            oilVISCT.SetT(str[0 + 2 * i].toDouble());
            oilVISCT.SetMO(str[1 + 2 * i].toDouble());

            oilVISCTList.append(oilVISCT);
        }

        data->Stratum().OILVISCT().append(oilVISCTList);
    }
}

void EclipseFileReader::ReadWATVISCT(ProjectData *data, QTextStream &sr)
{
    int ntPVT = data->Stratum().TABDIMS().NTPVT().isNull() ? DefaultValues::TABDIMS_NTPVT : data->Stratum().TABDIMS().NTPVT().toInt();

    for (int reg = 0; reg < ntPVT; reg++)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);

        QList<WATVISCTData> watVISCTList;

        for (int i = 0; i < (str.length() - 1) / 2; i++)
        {
            WATVISCTData watVISCT;

            watVISCT.SetT(str[0 + 2 * i].toDouble());
            watVISCT.SetMW(str[1 + 2 * i].toDouble());

            watVISCTList.append(watVISCT);
        }

        data->Stratum().WATVISCT().append(watVISCTList);
    }
}

// SOLUTION
void EclipseFileReader::ReadEQUIL(ProjectData *data, QTextStream &sr)
{
    int ntEQUL = data->Stratum().EQLDIMS().NTEQUL().isNull() ? DefaultValues::EQLDIMS_NTEQUL : data->Stratum().EQLDIMS().NTEQUL().toInt();

    for (int reg = 0; reg < ntEQUL; reg++)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);

        EQUILData equil;

        equil.SetDatumDepth(str[0].toDouble());
        equil.SetDatumP(str[1].toDouble());
        if (str.length() > 3 && str[2] != "1*") equil.SetWOCDepth(str[2].toDouble());
        if (str.length() > 4 && str[3] != "1*") equil.SetWOCPc(str[3].toDouble());
        if (str.length() > 5 && str[4] != "1*") equil.SetGOCDepth(str[4].toDouble());
        if (str.length() > 6 && str[5] != "1*") equil.SetGOCPc(str[5].toDouble());

        data->Stratum().EQUIL().append(equil);
    }
}

void EclipseFileReader::ReadRSVD(ProjectData *data, QTextStream &sr)
{
    int ntEQUL = data->Stratum().EQLDIMS().NTEQUL().isNull() ? DefaultValues::EQLDIMS_NTEQUL : data->Stratum().EQLDIMS().NTEQUL().toInt();

    for (int reg = 0; reg < ntEQUL; reg++)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);

        QList<RSVDData> rsvdList;

        for (int i = 0; i < (str.length() - 1) / 2; i++)
        {
            RSVDData rsvd;

            rsvd.SetDepth(str[0 + i * 2].toDouble());
            rsvd.SetRS(str[1 + i * 2].toDouble());

            rsvdList.append(rsvd);
        }

        data->Stratum().RSVD().append(rsvdList);
    }
}

void EclipseFileReader::ReadPBVD(ProjectData *data, QTextStream &sr)
{
    int ntEQUL = data->Stratum().EQLDIMS().NTEQUL().isNull() ? DefaultValues::EQLDIMS_NTEQUL : data->Stratum().EQLDIMS().NTEQUL().toInt();

    for (int reg = 0; reg < ntEQUL; reg++)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);

        QList<PBVDData> pbvdList;

        for (int i = 0; i < (str.length() - 1) / 2; i++)
        {
            PBVDData pbvd;

            pbvd.SetDepth(str[0 + i * 2].toDouble());
            pbvd.SetPBub(str[1 + i * 2].toDouble());

            pbvdList.append(pbvd);
        }

        data->Stratum().PBVD().append(pbvdList);
    }
}

void EclipseFileReader::ReadPRVD(ProjectData *data, QTextStream &sr)
{
    int ntEQUL = data->Stratum().EQLDIMS().NTEQUL().isNull() ? DefaultValues::EQLDIMS_NTEQUL : data->Stratum().EQLDIMS().NTEQUL().toInt();

    for (int reg = 0; reg < ntEQUL; reg++)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);

        QList<PRVDData> prvdList;

        for (int i = 0; i < (str.length() - 1) / 2; i++)
        {
            PRVDData prvd;

            prvd.SetDepth(str[0 + i * 2].toDouble());
            prvd.SetPO(str[1 + i * 2].toDouble());

            prvdList.append(prvd);
        }

        data->Stratum().PRVD().append(prvdList);
    }
}

void EclipseFileReader::ReadAQUANCON(ProjectData *data, QTextStream &sr)
{
    QMetaObject metaObject = ProjectData::staticMetaObject;

    QMetaEnum faceTypeEnum = metaObject.enumerator(metaObject.indexOfEnumerator("FaceType"));

    while (true)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);
        if (str.length() == 0) break;

        AQUANCONData aquanCON;

        str[7] = str[7].replace('-', 'm');
        str[7] = str[7].replace('+', 'p');

        aquanCON.SetNum(str[0].toInt());
        aquanCON.SetI1(str[1].toInt() - 1);
        aquanCON.SetI2(str[2].toInt() - 1);
        aquanCON.SetJ1(str[3].toInt() - 1);
        aquanCON.SetJ2(str[4].toInt() - 1);
        aquanCON.SetK1(str[5].toInt() - 1);
        aquanCON.SetK2(str[6].toInt() - 1);
        aquanCON.SetSide(faceTypeEnum.keyToValue(str[7].toLatin1()));
        if (str.length() > 9 && str[8] != "1*") aquanCON.SetInfluxCoef(str[8].toDouble());
        if (str.length() > 10 && str[9] != "1*") aquanCON.SetInfluxMult(str[9].toDouble());

        data->Stratum().AQUANCON().append(aquanCON);
    }
}

void EclipseFileReader::ReadAQUFETP(ProjectData *data, QTextStream &sr)
{
    while (true)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);
        if (str.length() == 0) break;

        AQUFETPData aquFETP;

        aquFETP.SetNum(str[0].toInt());
        aquFETP.SetDatumDepth(str[1].toDouble());
        if (str[2] != "1*") aquFETP.SetDatumP(str[2].toDouble());
        aquFETP.SetVW(str[3].toDouble());
        aquFETP.SetC(str[4].toDouble());
        aquFETP.SetProdIndex(str[5].toDouble());
        aquFETP.SetPVTWNum(str[6].toInt());
        if (str.length() > 8 && str[7] != "1*") aquFETP.SetSALT(str[7].toDouble());

        data->Stratum().AQUFETP().append(aquFETP);
    }
}

void EclipseFileReader::ReadDIMPES(ProjectData *data, QTextStream &sr)
{
    QStringList str = ReadFileHelper::ParseParams(sr);

    if (str.length() > 1 && str[0] != "1*") data->Stratum().DIMPES().SetDSTARG(str[0].toDouble());
    if (str.length() > 2 && str[1] != "1*") data->Stratum().DIMPES().SetDSMAX(str[1].toDouble());
    if (str.length() > 3 && str[2] != "1*") data->Stratum().DIMPES().SetDPMAX(str[2].toDouble());

}

void EclipseFileReader::ReadWELSPECS(ProjectData *data, QTextStream &sr)
{
    while (true)
    {
        QStringList str = ReadFileHelper::ParseParams(sr, 0, false);
        if (str.length() == 0) break;

        WELSPECSData wData;

        wData.SetWellName(str[0]);
        wData.SetWellGroup(str[1] == "1*" ? DefaultValues::WELSPECS_WellGroup : str[1]);
        wData.SetI(str[2].toInt());
        wData.SetJ(str[3].toInt());
        if (str.length() > 5 && str[4] != "1*") wData.SetDepth(str[4].toDouble());

        wData.SetDate(currentDate);

        data->Stratum().WELSPECS().append(wData);
    }
}

void EclipseFileReader::ReadCOMPDAT(ProjectData *data, QTextStream &sr)
{
    QMetaObject metaObject = ProjectData::staticMetaObject;

    QMetaEnum wellStatusTypeEnum = metaObject.enumerator(metaObject.indexOfEnumerator("WellStatusType"));

    while (true)
    {
        QStringList str = ReadFileHelper::ParseParams(sr, 0, false);
        if (str.length() == 0) break;

        COMPDATData compdat;

        compdat.SetWellName(str[0]);
        if (str.length() > 2 && str[1] != "1*") compdat.SetI(str[1].toInt());
        if (str.length() > 3 && str[2] != "1*") compdat.SetJ(str[2].toInt());
        if (str.length() > 4 && str[3] != "1*") compdat.SetK1(str[3].toInt());
        if (str.length() > 5 && str[4] != "1*") compdat.SetK2(str[4].toInt());
        if (str.length() > 6 && str[5] != "1*") compdat.SetWellStatus(wellStatusTypeEnum.keyToValue(str[5].toLatin1()));
        if (str.length() > 7 && str[6] != "1*") compdat.SetSATNUM(str[6].toInt());
        if (str.length() > 8 && str[7] != "1*") compdat.SetTranFactor(str[7].toDouble());
        if (str.length() > 9 && str[8] != "1*") compdat.SetDiameter(str[8].toDouble());
        if (str.length() > 10 && str[9] != "1*") compdat.SetKh(str[9].toDouble());
        if (str.length() > 11 && str[10] != "1*") compdat.SetSkinFactor(str[10].toDouble());

        compdat.SetDate(currentDate);

        data->Stratum().COMPDAT().append(compdat);
    }
}

void EclipseFileReader::ReadWCONPROD(ProjectData *data, QTextStream &sr)
{
    QMetaObject metaObject = ProjectData::staticMetaObject;

    QMetaEnum wellStatusTypeEnum = metaObject.enumerator(metaObject.indexOfEnumerator("WellStatusType"));
    QMetaEnum wellControlModeEnum = metaObject.enumerator(metaObject.indexOfEnumerator("WellControlMode"));

    while (true)
    {
        QStringList str = ReadFileHelper::ParseParams(sr, 0, false);
        if (str.length() == 0) break;

        WCONPRODData wconprod;

        wconprod.SetWellName(str[0]);
        if (str.length() > 2 && str[1] != "1*") wconprod.SetWellStatus(wellStatusTypeEnum.keyToValue(str[1].toLatin1()));
        if (str.length() > 3 && str[2] != "1*") wconprod.SetWellControl(wellControlModeEnum.keyToValue(str[2].toLatin1()));
        if (str.length() > 4 && str[3] != "1*") wconprod.SetORAT(str[3].toDouble());
        if (str.length() > 5 && str[4] != "1*") wconprod.SetWRAT(str[4].toDouble());
        if (str.length() > 6 && str[5] != "1*") wconprod.SetGRAT(str[5].toDouble());
        if (str.length() > 7 && str[6] != "1*") wconprod.SetLRAT(str[6].toDouble());
        if (str.length() > 8 && str[7] != "1*") wconprod.SetRESV(str[7].toDouble());
        if (str.length() > 9 && str[8] != "1*") wconprod.SetBHP(str[8].toDouble());

        wconprod.SetDate(currentDate);

        data->Stratum().WCONPROD().append(wconprod);
    }
}

void EclipseFileReader::ReadWCONINJE(ProjectData *data, QTextStream &sr)
{
    QMetaObject metaObject = ProjectData::staticMetaObject;

    QMetaEnum wellStatusTypeEnum = metaObject.enumerator(metaObject.indexOfEnumerator("WellStatusType"));
    QMetaEnum wellControlModeEnum = metaObject.enumerator(metaObject.indexOfEnumerator("WellControlMode"));
    QMetaEnum fluidTypeEnum = metaObject.enumerator(metaObject.indexOfEnumerator("FluidType"));

    while (true)
    {
        QStringList str = ReadFileHelper::ParseParams(sr, 0, false);
        if (str.length() == 0) break;

        WCONINJEData wconinje;

        wconinje.SetWellName(str[0]);
        if (str.length() > 2 && str[1] != "1*") wconinje.SetInjFluid(fluidTypeEnum.keyToValue(str[1].toLatin1()));
        if (str.length() > 3 && str[2] != "1*") wconinje.SetWellStatus(wellStatusTypeEnum.keyToValue(str[2].toLatin1()));
        if (str.length() > 4 && str[3] != "1*") wconinje.SetWellControl(wellControlModeEnum.keyToValue(str[3].toLatin1()));
        if (str.length() > 5 && str[4] != "1*") wconinje.SetRATE(str[4].toDouble());
        if (str.length() > 6 && str[5] != "1*") wconinje.SetRESV(str[5].toDouble());
        if (str.length() > 7 && str[6] != "1*") wconinje.SetBHP(str[6].toDouble());

        wconinje.SetDate(currentDate);

        data->Stratum().WCONINJE().append(wconinje);
    }
}

void EclipseFileReader::ReadDATES(ProjectData *data, QTextStream &sr)
{
    QMetaObject metaObject = staticMetaObject;

    QMetaEnum monthsEnum = metaObject.enumerator(metaObject.indexOfEnumerator("Months"));

    while (true)
    {
        QStringList str = ReadFileHelper::ParseParams(sr, 0, false);
        if (str.length() == 0) break;

        QString strDate = ReadFileHelper::EclipseDateToStr(str, monthsEnum);

        QDateTime date = ReadFileHelper::StrToDate(strDate);

        data->Stratum().DATES().append(date);

        currentDate = date;
    }
}

void EclipseFileReader::ReadTSTEP(ProjectData *data, QTextStream &sr)
{
    QStringList str = ReadFileHelper::ParseParams(sr);
    if (str.length() == 0) return;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == "/") break;

        double day = str[i].toDouble();

        qint64 seconds = static_cast<qint64>(24*3600*day);

        currentDate = currentDate.addSecs(seconds);

        data->Stratum().DATES().append(currentDate);
    }
}

void EclipseFileReader::ReadWCONHIST(ProjectData *data, QTextStream &sr)
{
    QMetaObject metaObject = ProjectData::staticMetaObject;

    QMetaEnum wellStatusTypeEnum = metaObject.enumerator(metaObject.indexOfEnumerator("WellStatusType"));
    QMetaEnum wellControlModeEnum = metaObject.enumerator(metaObject.indexOfEnumerator("WellControlMode"));

    while (true)
    {
        QStringList str = ReadFileHelper::ParseParams(sr, 0, false);
        if (str.length() == 0) break;

        WCONHISTData wconhist;

        wconhist.SetWellName(str[0]);
        if (str.length() > 2 && str[1] != "1*") wconhist.SetWellStatus(wellStatusTypeEnum.keyToValue(str[1].toLatin1()));
        if (str.length() > 3 && str[2] != "1*") wconhist.SetWellControl(wellControlModeEnum.keyToValue(str[2].toLatin1()));
        if (str.length() > 4 && str[3] != "1*") wconhist.SetORAT(str[3].toDouble());
        if (str.length() > 5 && str[4] != "1*") wconhist.SetWRAT(str[4].toDouble());
        if (str.length() > 6 && str[5] != "1*") wconhist.SetGRAT(str[5].toDouble());

        wconhist.SetDate(currentDate);

        data->Stratum().WCONHIST().append(wconhist);
    }
}

void EclipseFileReader::ReadWCONINJH(ProjectData *data, QTextStream &sr)
{
    QMetaObject metaObject = ProjectData::staticMetaObject;

    QMetaEnum wellStatusTypeEnum = metaObject.enumerator(metaObject.indexOfEnumerator("WellStatusType"));
    QMetaEnum fluidTypeEnum = metaObject.enumerator(metaObject.indexOfEnumerator("FluidType"));

    while (true)
    {
        QStringList str = ReadFileHelper::ParseParams(sr, 0, false);
        if (str.length() == 0) break;

        WCONINJHData wconinjh;

        wconinjh.SetWellName(str[0]);
        if (str.length() > 2 && str[1] != "1*") wconinjh.SetInjFluid(fluidTypeEnum.keyToValue(str[1].toLatin1()));
        if (str.length() > 3 && str[2] != "1*") wconinjh.SetWellStatus(wellStatusTypeEnum.keyToValue(str[2].toLatin1()));
        if (str.length() > 4 && str[3] != "1*") wconinjh.SetRATE(str[3].toDouble());
        if (str.length() > 5 && str[4] != "1*") wconinjh.SetBHP(str[4].toDouble());

        wconinjh.SetDate(currentDate);

        data->Stratum().WCONINJH().append(wconinjh);
    }
}

void EclipseFileReader::ReadWELTARG(ProjectData *data, QTextStream &sr)
{
    QMetaObject metaObject = ProjectData::staticMetaObject;

    QMetaEnum wellControlModeEnum = metaObject.enumerator(metaObject.indexOfEnumerator("WellControlMode"));

    while (true)
    {
        QStringList str = ReadFileHelper::ParseParams(sr, 0, false);
        if (str.length() == 0) break;

        WELTARGData weltarg;

        weltarg.SetWellName(str[0]);
        if (str.length() > 2 && str[1] != "1*") weltarg.SetWellControl(wellControlModeEnum.keyToValue(str[1].toLatin1()));
        if (str.length() > 3 && str[2] != "1*") weltarg.SetValue(str[2].toDouble());

        weltarg.SetDate(currentDate);

        data->Stratum().WELTARG().append(weltarg);
    }
}

// ANY SECTION
void EclipseFileReader::ReadINCLUDE(ProjectData *data, QTextStream &sr, QString currentDir, QMetaEnum &casesEnum)
{
    QStringList str = ReadFileHelper::ParseParams(sr);
    if (str.length() == 0) return;

    QString filename = currentDir + QDir::separator() + str[0].replace("'", "");

    ReadFile(data, filename, casesEnum);
}

void EclipseFileReader::ReadEQUALS(ProjectData *data, QTextStream &sr)
{
    while (true)
    {
        QStringList str = ReadFileHelper::ParseParams(sr, 0, true);
        if (str.length() == 0) break;

        EQUALSData equals;

        equals.SetArrayName(str[0].replace("'", ""));
        equals.SetValue(str[1].toDouble());

        equals.Box().SetI1(str.length() > 3 && str[2] != "1*" ? str[2].toInt() - 1 : box.I1());
        equals.Box().SetI2(str.length() > 4 && str[3] != "1*" ? str[3].toInt() - 1 : box.I2());

        equals.Box().SetJ1(str.length() > 5 && str[4] != "1*" ? str[4].toInt() - 1 : box.J1());
        equals.Box().SetJ2(str.length() > 6 && str[5] != "1*" ? str[5].toInt() - 1 : box.J2());

        equals.Box().SetK1(str.length() > 7 && str[6] != "1*" ? str[6].toInt() - 1 : box.K1());
        equals.Box().SetK2(str.length() > 8 && str[7] != "1*" ? str[7].toInt() - 1 : box.K2());

        data->Stratum().EQUALS().append(equals);
    }
}

void EclipseFileReader::ReadBOX(QTextStream &sr)
{
    QStringList str = ReadFileHelper::ParseParams(sr);
    if (str.length() == 0) return;

    box.SetI1(str[0].toInt() - 1);
    box.SetI2(str[1].toInt() - 1);
    box.SetJ1(str[2].toInt() - 1);
    box.SetJ2(str[3].toInt() - 1);
    box.SetK1(str[4].toInt() - 1);
    box.SetK2(str[5].toInt() - 1);
}

void EclipseFileReader::ReadENDBOX(ProjectData* data)
{
    int nx = data->Nx();
    int ny = data->Ny();
    int nz = data->Nz();

    box.SetI1(0); box.SetI2(nx - 1);
    box.SetJ1(0); box.SetJ2(ny - 1);
    box.SetK1(0); box.SetK2(nz - 1);
}

void EclipseFileReader::ReadCOPY(ProjectData *data, QTextStream &sr)
{
    while (true)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);
        if (str.length() == 0) break;

        COPYData copy;

        copy.SetSOURCE(str[0]);
        copy.SetDESTINATION(str[1]);

        copy.Box().SetI1(str.length() > 3 && str[2] != "1*" ? str[2].toInt() - 1 : box.I1());
        copy.Box().SetI2(str.length() > 4 && str[3] != "1*" ? str[3].toInt() - 1 : box.I2());

        copy.Box().SetJ1(str.length() > 5 && str[4] != "1*" ? str[4].toInt() - 1 : box.J1());
        copy.Box().SetJ2(str.length() > 6 && str[5] != "1*" ? str[5].toInt() - 1 : box.J2());

        copy.Box().SetK1(str.length() > 7 && str[6] != "1*" ? str[6].toInt() - 1 : box.K1());
        copy.Box().SetK2(str.length() > 8 && str[7] != "1*" ? str[7].toInt() - 1 : box.K2());

        data->Stratum().COPY().append(copy);
    }
}

void EclipseFileReader::ReadADD(ProjectData *data, QTextStream &sr)
{
    while (true)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);
        if (str.length() == 0) break;

        ADDData add;

        add.SetArrayName(str[0]);
        add.SetValue(str[1].toDouble());

        add.Box().SetI1(str.length() > 3 && str[2] != "1*" ? str[2].toInt() - 1 : box.I1());
        add.Box().SetI2(str.length() > 4 && str[3] != "1*" ? str[3].toInt() - 1 : box.I2());

        add.Box().SetJ1(str.length() > 5 && str[4] != "1*" ? str[4].toInt() - 1 : box.J1());
        add.Box().SetJ2(str.length() > 6 && str[5] != "1*" ? str[5].toInt() - 1 : box.J2());

        add.Box().SetK1(str.length() > 7 && str[6] != "1*" ? str[6].toInt() - 1 : box.K1());
        add.Box().SetK2(str.length() > 8 && str[7] != "1*" ? str[7].toInt() - 1 : box.K2());

        data->Stratum().ADD().append(add);
    }
}

void EclipseFileReader::ReadMULTIPLY(ProjectData *data, QTextStream &sr)
{
    while (true)
    {
        QStringList str = ReadFileHelper::ParseParams(sr);
        if (str.length() == 0) break;

        MULTIPLYData multiply;

        multiply.SetArrayName(str[0]);
        multiply.SetMult(str[1].toDouble());

        multiply.Box().SetI1(str.length() > 3 && str[2] != "1*" ? str[2].toInt() - 1 : box.I1());
        multiply.Box().SetI2(str.length() > 4 && str[3] != "1*" ? str[3].toInt() - 1 : box.I2());

        multiply.Box().SetJ1(str.length() > 5 && str[4] != "1*" ? str[4].toInt() - 1 : box.J1());
        multiply.Box().SetJ2(str.length() > 6 && str[5] != "1*" ? str[5].toInt() - 1 : box.J2());

        multiply.Box().SetK1(str.length() > 7 && str[6] != "1*" ? str[6].toInt() - 1 : box.K1());
        multiply.Box().SetK2(str.length() > 8 && str[7] != "1*" ? str[7].toInt() - 1 : box.K2());

        data->Stratum().MULTIPLY().append(multiply);
    }
}

}}}
