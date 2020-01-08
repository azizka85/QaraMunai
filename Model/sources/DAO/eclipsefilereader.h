#ifndef ECLIPSEFILEREADER_H
#define ECLIPSEFILEREADER_H

#include <qmetaobject.h>
#include <qdebug.h>
#include <qobject.h>
#include <qstring.h>
#include <qstringlist.h>
#include <qlist.h>
#include <qdatetime.h>
#include <qdir.h>
#include <qfile.h>
#include <qfileinfo.h>
#include <qtextstream.h>

#include <box3d.h>
#include <idatafilereader.h>
#include <projectdata.h>
#include <readfilehelper.h>
#include <defaultvalues.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Grid;
using namespace QaraMunai::Model::Domain::Project;
using namespace QaraMunai::Model::Domain::Stratum;
using namespace QaraMunai::Model::Helpers::Eclipse;

namespace QaraMunai {
namespace Model {
namespace DAO {

class MODELSHARED_EXPORT EclipseFileReader : public IDataFileReader
{
    Q_OBJECT
    Q_ENUMS(Cases)
    Q_ENUMS(Months)   

public:
    explicit EclipseFileReader(QObject *parent = nullptr);

    enum Months { JAN = 1, FEB = 2, MAR = 3, APR = 4, MAY = 5, JUN = 6, JUL = 7, AUG = 8, SEP = 9, OCT = 10, NOV = 11, DEC = 12 };

    enum Cases { /*RUNSPEC*/ RUNSPEC, TITLE, START, METRIC, FIELD, LAB, PVTmM, UNIFOUT, OIL, WATER, GAS, DISGAS, TEMP, NOECHO, IMPLICIT, FULLIMP, IMPES,
        NUMRES, DIMENS, REGDIMS, TABDIMS, EQLDIMS, WELLDIMS, ENDSCALE, BLACKOIL, DEADOIL,
        /*GRID*/ GRID, INIT, GRIDFILE, TOPS, DX, DY, DZ, DXV, DYV, DZV, COORD, ZCORN, ACTNUM, MULTPV, PERMX, PERMY, PERMZ, PORO, NTG, DZNET,
        MULTX, MULTY, MULTZ, MULTXm, MULTYm, MULTZm, MINPV, MINPVV,
        /*PROPS*/ PROPS, STONE, STONE1, STONE2, RSCONST, RSCONSTT, PVTO, PVCO, PMAX, PVCDO, PVDO, PVTW, PVDG, PVTG, ROCKOPTS, ROCK, DENSITY, GRAVITY,
        SWOF, SGOF, SGWFN, SLGOF, SOF2, SOF3, SOF32D, SWFN, SGFN, SOMGAS, SOMWAT, SWATINIT, SWCR, ISWCR, SWL, ISWL, SWLPC, ISWLPC, SWU, ISWU, SGCR, ISGCR,
        SGL, ISGL, SGLPC, ISGLPC, PCG, IPCG, PCW, IPCW, PPCWMAX, KRO, IKRO, KRORW, IKRORW, KRORG, IKRORG, KRW, IKRW, KRWR, IKRWR, KRG, IKRG, KRGR, IKRGR,
        ENKRVD, ENPCVD, ENSPCVD, SCALELIM, SCALECRS, SPECHEAT, SPECROCK, VISCREF, OILVISCT, WATVISCT,
        /*REGIONS*/ REGIONS, PVTNUM, SATNUM, EQLNUM, ENDNUM, FIPNUM,
        /*SOLUTION*/ SOLUTION, EQUIL, RSVD, PBVD, PRVD, PRESSURE, SWAT, SOIL, SGAS, PBUB, RS, AQUANCON, AQUFETP,
        /*SUMMARY*/ SUMMARY, ALL, RUNSUM, RPTONLY,
        /*SCHEDULE*/ SCHEDULE, DIMPLICT, DIMPES, RPTRST, RPTSCHED, WELSPECS, COMPDAT, WCONPROD, WCONINJE, DATES, TSTEP, WCONHIST, WCONINJH, WELTARG,
        /*ANY SECTION*/ INCLUDE, EQUALS, BOX, ENDBOX, COPY, ADD, MULTIPLY, EDIT, DEPTH, PORV, TRANX, TRANY, TRANZ, END
    };

    Q_INVOKABLE void load(ProjectData *data, const QString &filePath);

private:
    QDateTime currentDate;

    Box3D box;

    void InitVariables();
    void ReadFile(ProjectData *projectData, const QString &filePath, QMetaEnum &casesEnum);

    // RUNSPEC
    void ReadTITLE(ProjectData *data, QTextStream &sr);
    void ReadSTART(ProjectData *data, QTextStream &sr);
    void ReadNUMRES(ProjectData *data, QTextStream &sr);
    void ReadDIMENS(ProjectData *data, QTextStream &sr);
    void ReadTABDIMS(ProjectData *data, QTextStream &sr);
    void ReadEQLDIMS(ProjectData *data, QTextStream &sr);
    void ReadENDSCALE(ProjectData *data, QTextStream &sr);

    // GRID
    void ReadMINPV(ProjectData *data, QTextStream &sr);

    // PROPS
    void ReadRSCONST(ProjectData *data, QTextStream &sr);
    void ReadRSCONSTT(ProjectData *data, QTextStream &sr);
    void ReadPVTO(ProjectData *data, QTextStream &sr);
    void ReadPVCO(ProjectData *data, QTextStream &sr);
    void ReadPMAX(ProjectData *data, QTextStream &sr);
    void ReadPVCDO(ProjectData *data, QTextStream &sr);
    void ReadPVDO(ProjectData *data, QTextStream &sr);
    void ReadPVTW(ProjectData *data, QTextStream &sr);
    void ReadPVDG(ProjectData *data, QTextStream &sr);
    void ReadPVTG(ProjectData *data, QTextStream &sr);
    void ReadROCKOPTS(ProjectData *data, QTextStream &sr);
    void ReadROCK(ProjectData *data, QTextStream &sr);
    void ReadDENSITY(ProjectData *data, QTextStream &sr);
    void ReadGRAVITY(ProjectData *data, QTextStream &sr);
    void ReadSWOF(ProjectData *data, QTextStream &sr);
    void ReadSGOF(ProjectData *data, QTextStream &sr);
    void ReadSGWFN(ProjectData *data, QTextStream &sr);
    void ReadSLGOF(ProjectData *data, QTextStream &sr);
    void ReadSOF2(ProjectData *data, QTextStream &sr);
    void ReadSOF3(ProjectData *data, QTextStream &sr);
    void ReadSOF32D(ProjectData *data, QTextStream &sr);
    void ReadSWFN(ProjectData *data, QTextStream &sr);
    void ReadSGFN(ProjectData *data, QTextStream &sr);
    void ReadSOMGAS(ProjectData *data, QTextStream &sr);
    void ReadSOMWAT(ProjectData *data, QTextStream &sr);
    void ReadPPCWMAX(ProjectData *data, QTextStream &sr);
    void ReadENKRVD(ProjectData *data, QTextStream &sr);
    void ReadENPCVD(ProjectData *data, QTextStream &sr);
    void ReadENSPCVD(ProjectData *data, QTextStream &sr);
    void ReadSCALELIM(ProjectData *data, QTextStream &sr);
    void ReadSCALECRS(ProjectData *data, QTextStream &sr);
    void ReadSPECHEAT(ProjectData *data, QTextStream &sr);
    void ReadSPECROCK(ProjectData *data, QTextStream &sr);
    void ReadVISCREF(ProjectData *data, QTextStream &sr);
    void ReadOILVISCT(ProjectData *data, QTextStream &sr);
    void ReadWATVISCT(ProjectData *data, QTextStream &sr);

    // SOLUTION
    void ReadEQUIL(ProjectData *data, QTextStream &sr);
    void ReadRSVD(ProjectData *data, QTextStream &sr);
    void ReadPBVD(ProjectData *data, QTextStream &sr);
    void ReadPRVD(ProjectData *data, QTextStream &sr);
    void ReadAQUANCON(ProjectData *data, QTextStream &sr);
    void ReadAQUFETP(ProjectData *data, QTextStream &sr);

    // SCHEDULE
    void ReadDIMPES(ProjectData *data, QTextStream &sr);
    void ReadWELSPECS(ProjectData *data, QTextStream &sr);
    void ReadCOMPDAT(ProjectData *data, QTextStream &sr);
    void ReadWCONPROD(ProjectData *data, QTextStream &sr);
    void ReadWCONINJE(ProjectData *data, QTextStream &sr);
    void ReadDATES(ProjectData *data, QTextStream &sr);
    void ReadTSTEP(ProjectData *data, QTextStream &sr);
    void ReadWCONHIST(ProjectData *data, QTextStream &sr);
    void ReadWCONINJH(ProjectData *data, QTextStream &sr);
    void ReadWELTARG(ProjectData *data, QTextStream &sr);

    // ANY SECTION
    void ReadINCLUDE(ProjectData *data, QTextStream &sr, QString currentDir, QMetaEnum &casesEnum);
    void ReadEQUALS(ProjectData *data, QTextStream &sr);
    void ReadBOX(QTextStream &sr);
    void ReadENDBOX(ProjectData *data);
    void ReadCOPY(ProjectData *data, QTextStream &sr);
    void ReadADD(ProjectData *data, QTextStream &sr);
    void ReadMULTIPLY(ProjectData *data, QTextStream &sr);
};

}}}

#endif // ECLIPSEFILEREADER_H
