#ifndef PROJECTDATA_H
#define PROJECTDATA_H

#include <qobject.h>
#include <qvariant.h>
#include <qdatetime.h>

#include <line3d.h>
#include <stratumdata.h>
#include <tabdimsentity.h>
#include <eqldimsentity.h>
#include <endscaleentity.h>
#include <rockoptsentity.h>

#include <swofentity.h>
#include <sgofentity.h>

#include <pvtoentity.h>
#include <pvtgentity.h>

#include <welspecsentity.h>
#include <compdatentity.h>
#include <wconprodentity.h>
#include <wconinjeentity.h>

#include <copyentity.h>
#include <addentity.h>
#include <equalsentity.h>
#include <multiplyentity.h>

#include <mathhelper.h>
#include <datahelper.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Stratum;
using namespace QaraMunai::Model::Helpers;

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

class MODELSHARED_EXPORT ProjectData : public QObject
{
    Q_OBJECT

    Q_ENUMS(ModelType)
    Q_ENUMS(UnitType)
    Q_ENUMS(FaceType)
    Q_ENUMS(WellStatusType)
    Q_ENUMS(WellControlMode)
    Q_ENUMS(FluidType)
    Q_ENUMS(ArrayNames)

    Q_PROPERTY(bool loaded READ Loaded WRITE SetLoaded NOTIFY LoadedChanged)
    Q_PROPERTY(QString title READ Title WRITE SetTitle NOTIFY TitleChanged)
    Q_PROPERTY(QDateTime startDate READ StartDate WRITE SetStartDate NOTIFY StartDateChanged)
    Q_PROPERTY(QVariant unit READ Unit WRITE SetUnit NOTIFY UnitChanged)
    Q_PROPERTY(QVariant model READ Model WRITE SetModel NOTIFY ModelChanged)
    Q_PROPERTY(QVariant temperatureOption READ TemperatureOption WRITE SetTemperatureOption NOTIFY TemperatureOptionChanged)
    Q_PROPERTY(QVariant numRES READ NumRES WRITE SetNumRES NOTIFY NumRESChanged)
    Q_PROPERTY(int nx READ Nx WRITE SetNx NOTIFY NxChanged)
    Q_PROPERTY(int ny READ Ny WRITE SetNy NOTIFY NyChanged)
    Q_PROPERTY(int nz READ Nz WRITE SetNz NOTIFY NzChanged)
    Q_PROPERTY(bool blockCentered READ BlockCentered WRITE SetBlockCentered NOTIFY BlockCenteredChanged)
    Q_PROPERTY(QVariantList dates READ DATES)
    Q_PROPERTY(TABDIMSEntity* tabDIMS READ TABDIMS)
    Q_PROPERTY(EQLDIMSEntity* eqlDIMS READ EQLDIMS)
    Q_PROPERTY(ENDSCALEEntity* endSCALE READ ENDSCALE)
    Q_PROPERTY(ROCKOPTSEntity* rockOPTS READ ROCKOPTS)
    Q_PROPERTY(SWOFEntity* swof READ SWOF)
    Q_PROPERTY(SGOFEntity* sgof READ SGOF)
    Q_PROPERTY(PVTOEntity* pvto READ PVTO)
    Q_PROPERTY(PVTGEntity* pvtg READ PVTG)
    Q_PROPERTY(WELSPECSEntity* welspecs READ WELSPECS)
    Q_PROPERTY(COMPDATEntity* compdat READ COMPDAT)
    Q_PROPERTY(WCONPRODEntity* wconprod READ WCONPROD)
    Q_PROPERTY(WCONINJEEntity* wconinje READ WCONINJE)
    Q_PROPERTY(COPYEntity* copy READ COPY)
    Q_PROPERTY(ADDEntity* add READ ADD)
    Q_PROPERTY(EQUALSEntity* equals READ EQUALS)
    Q_PROPERTY(MULTIPLYEntity *multiply READ MULTIPLY)

public:
    explicit ProjectData(QObject *parent = nullptr);

    enum UnitType { METRIC = 0, FIELD = 1, LAB = 2 };
    enum ModelType { TwoPhase = 0, ThreePhase = 1 };    
    enum FaceType { Im = 0, Ip = 1, Jm = 2, Jp = 3, Km = 4, Kp = 5 };
    enum WellStatusType { AUTO = 0, OPEN = 1, STOP = 2, SHUT = 3 };
    enum WellControlMode { ORAT = 0, WRAT = 1, GRAT = 2, LRAT = 3, RESV = 4, BHP = 5, RATE = 6 };
    enum FluidType { WATER = 0, GAS = 1, OIL = 2 };
    enum ArrayNames { TOPS, DX, DY, DZ, ACTNUM, MULTPV, PERMX, PERMY, PERMZ, PORO, NTG, DZNET, MULTX, MULTY, MULTZ, MULTXm, MULTYm, MULTZm,
                      MINPVV, SWATINIT, SWCR, ISWCR, SWL, ISWL, SWLPC, ISWLPC, SWU, ISWU, SGCR, ISGCR, SGL, ISGL, SGLPC, ISGLPC, PCG, IPCG,
                      PCW, IPCW, KRO, IKRO, KRORW, IKRORW, KRORG, IKRORG, KRW, IKRW, KRWR, IKRWR, KRG, IKRG, KRGR, IKRGR, PVTNUM, SATNUM,
                      EQLNUM, ENDNUM, PRESSURE, SWAT, SGAS, PBUB, RS, DEPTH, PORV, TRANX, TRANY, TRANZ };

    bool Loaded() const;
    QString Title() const;
    QDateTime StartDate() const;
    QVariant Unit() const;
    QVariant Model() const;
    QVariant TemperatureOption() const;

    QVariant NumRES() const;
    int Nx() const;
    int Ny() const;
    int Nz() const;

    bool BlockCentered() const;

    QVariantList DATES();

    Q_INVOKABLE double dx(int i, int j, int k);
    Q_INVOKABLE double dy(int i, int j, int k);
    Q_INVOKABLE double dz(int i, int j, int k);

    Q_INVOKABLE double tops(int i, int j);

    Q_INVOKABLE double depth(int i, int j, int k);

    Q_INVOKABLE double poro(int i, int j, int k);
    Q_INVOKABLE double ntg(int i, int j, int k);
    Q_INVOKABLE bool actnum(int i, int j, int k, double poreVolume = -1);

    Q_INVOKABLE double multX(int i, int j, int k);
    Q_INVOKABLE double multXm(int i, int j, int k);
    Q_INVOKABLE double multY(int i, int j, int k);
    Q_INVOKABLE double multYm(int i, int j, int k);
    Q_INVOKABLE double multZ(int i, int j, int k);
    Q_INVOKABLE double multZm(int i, int j, int k);

    Q_INVOKABLE double tranX(int i, int j, int k, double poreVolume = -1);

    Q_INVOKABLE double permX(int i, int j, int k);
    Q_INVOKABLE double permY(int i, int j, int k);
    Q_INVOKABLE double permZ(int i, int j, int k);

    Q_INVOKABLE int pvtNUM(int i, int j, int k);
    Q_INVOKABLE int eqlNUM(int i, int j, int k);

    Q_INVOKABLE double rs(int i, int j, int k, double depth = 0);
    Q_INVOKABLE double pBub(int i, int j, int k, double depth = 0);

    Q_INVOKABLE QVariantMap coordLine(int i, int j);
    Q_INVOKABLE QVariantMap blockDepths(int i, int j, int k);

    Q_INVOKABLE double pressure(int i, int j, int k);
    Q_INVOKABLE double pw(int i, int j, int k);
    Q_INVOKABLE double swat(int i, int j, int k);
    Q_INVOKABLE double soil(int i, int j, int k);
    Q_INVOKABLE double sgas(int i, int j, int k);

    bool CalcCoordLine(int i, int j, Line3D& coordLine);
    bool CalcBlockDepths(int i, int j, int k, double &d1, double &d2, double &d3, double &d4, double &d5, double &d6, double &d7, double &d8);
    bool CheckPointOrderStandard();

    StratumData &Stratum();

    TABDIMSEntity* TABDIMS();
    EQLDIMSEntity* EQLDIMS();
    ENDSCALEEntity* ENDSCALE();

    ROCKOPTSEntity* ROCKOPTS();

    SWOFEntity *SWOF();
    SGOFEntity *SGOF();

    PVTOEntity *PVTO();
    PVTGEntity *PVTG();

    WELSPECSEntity *WELSPECS();
    COMPDATEntity *COMPDAT();
    WCONPRODEntity *WCONPROD();
    WCONINJEEntity *WCONINJE();

    COPYEntity *COPY();
    ADDEntity *ADD();
    EQUALSEntity *EQUALS();
    MULTIPLYEntity *MULTIPLY();

    void SetLoaded(const bool& isLoaded);
    void SetTitle(const QString& title);
    void SetStartDate(const QDateTime& startDate);
    void SetUnit(const QVariant& unit);
    void SetModel(const QVariant& model);
    void SetTemperatureOption(const QVariant& temperatureOption);

    void SetNumRES(const QVariant& numRES);
    void SetNx(int nx);
    void SetNy(int ny);
    void SetNz(int nz);

    void SetBlockCentered(bool isBlockCentered);

    Q_INVOKABLE void initVariables();

signals:
    void LoadedChanged();
    void TitleChanged();
    void StartDateChanged();
    void UnitChanged();
    void ModelChanged();
    void TemperatureOptionChanged();

    void NumRESChanged();
    void NxChanged();
    void NyChanged();
    void NzChanged();

    void BlockCenteredChanged();

private:
    bool isLoaded;
    QString title;
    QDateTime startDate;
    QVariant unit;
    QVariant model;
    QVariant temperatureOption;
    QVariant numRES;
    int nx, ny, nz;
    bool isBlockCentered;

    StratumData stratum;

    TABDIMSEntity *tabDIMS;
    EQLDIMSEntity *eqlDIMS;
    ENDSCALEEntity *endSCALE;

    ROCKOPTSEntity *rockOPTS;

    SWOFEntity *swof;
    SGOFEntity *sgof;

    PVTOEntity *pvto;
    PVTGEntity *pvtg;

    WELSPECSEntity *welspecs;
    COMPDATEntity *compdat;
    WCONPRODEntity *wconprod;
    WCONINJEEntity *wconinje;

    COPYEntity *copy;
    ADDEntity *add;
    EQUALSEntity *equals;
    MULTIPLYEntity *multiply;
};

}}}}

#endif // PROJECTDATA_H
