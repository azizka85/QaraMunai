#ifndef PROJECTDATA_H
#define PROJECTDATA_H

#include <qobject.h>
#include <qvariant.h>
#include <qdatetime.h>

#include <stratumdata.h>
#include <tabdimsentity.h>
#include <eqldimsentity.h>
#include <endscaleentity.h>
#include <rockoptsentity.h>

#include <swofentity.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Stratum;

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

    Q_PROPERTY(bool isLoaded READ IsLoaded WRITE SetIsLoaded NOTIFY IsLoadedChanged)
    Q_PROPERTY(QString title READ Title WRITE SetTitle NOTIFY TitleChanged)
    Q_PROPERTY(QDateTime startDate READ StartDate WRITE SetStartDate NOTIFY StartDateChanged)
    Q_PROPERTY(QVariant unit READ Unit WRITE SetUnit NOTIFY UnitChanged)
    Q_PROPERTY(QVariant model READ Model WRITE SetModel NOTIFY ModelChanged)
    Q_PROPERTY(QVariant temperatureOption READ TemperatureOption WRITE SetTemperatureOption NOTIFY TemperatureOptionChanged)
    Q_PROPERTY(QVariant numRES READ NumRES WRITE SetNumRES NOTIFY NumRESChanged)
    Q_PROPERTY(int nx READ Nx WRITE SetNx NOTIFY NxChanged)
    Q_PROPERTY(int ny READ Ny WRITE SetNy NOTIFY NyChanged)
    Q_PROPERTY(int nz READ Nz WRITE SetNz NOTIFY NzChanged)
    Q_PROPERTY(TABDIMSEntity* tabDIMS READ TABDIMS)
    Q_PROPERTY(EQLDIMSEntity* eqlDIMS READ EQLDIMS)
    Q_PROPERTY(ENDSCALEEntity* endSCALE READ ENDSCALE)
    Q_PROPERTY(ROCKOPTSEntity* rockOPTS READ ROCKOPTS)
    Q_PROPERTY(SWOFEntity* swof READ SWOF)

public:
    explicit ProjectData(QObject *parent = nullptr);

    enum UnitType { METRIC = 0, FIELD = 1, LAB = 2 };
    enum ModelType { TwoPhase = 0, ThreePhase = 1 };    
    enum FaceType { Im = 0, Ip = 1, Jm = 2, Jp = 3, Km = 4, Kp = 5 };
    enum WellStatusType { AUTO = 0, OPEN = 1, STOP = 2, SHUT = 3 };
    enum WellControlMode { ORAT = 0, WRAT = 1, GRAT = 2, LRAT = 3, RESV = 4, BHP = 5, RATE = 6 };
    enum FluidType { WATER = 0, GAS = 1, OIL = 2 };

    bool IsLoaded() const;
    QString Title() const;
    QDateTime StartDate() const;
    QVariant Unit() const;
    QVariant Model() const;
    QVariant TemperatureOption() const;

    QVariant NumRES() const;
    int Nx() const;
    int Ny() const;
    int Nz() const;

    StratumData &Stratum();

    TABDIMSEntity* TABDIMS();
    EQLDIMSEntity* EQLDIMS();
    ENDSCALEEntity* ENDSCALE();

    ROCKOPTSEntity* ROCKOPTS();

    SWOFEntity *SWOF();

    void SetIsLoaded(const bool& isLoaded);
    void SetTitle(const QString& title);
    void SetStartDate(const QDateTime& startDate);
    void SetUnit(const QVariant& unit);
    void SetModel(const QVariant& model);
    void SetTemperatureOption(const QVariant& temperatureOption);

    void SetNumRES(const QVariant& numRES);
    void SetNx(int nx);
    void SetNy(int ny);
    void SetNz(int nz);

    Q_INVOKABLE void initVariables();

signals:
    void IsLoadedChanged();
    void TitleChanged();
    void StartDateChanged();
    void UnitChanged();
    void ModelChanged();
    void TemperatureOptionChanged();

    void NumRESChanged();
    void NxChanged();
    void NyChanged();
    void NzChanged();

private:
    bool isLoaded;
    QString title;
    QDateTime startDate;
    QVariant unit;
    QVariant model;
    QVariant temperatureOption;
    QVariant numRES;
    int nx, ny, nz;

    StratumData stratum;

    TABDIMSEntity *tabDIMS;
    EQLDIMSEntity *eqlDIMS;
    ENDSCALEEntity *endSCALE;

    ROCKOPTSEntity *rockOPTS;

    SWOFEntity *swof;
};

}}}}

#endif // PROJECTDATA_H
