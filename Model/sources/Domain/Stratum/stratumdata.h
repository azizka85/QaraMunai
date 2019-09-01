#ifndef STRATUMDATA_H
#define STRATUMDATA_H

#include <qvariant.h>
#include <qvector.h>

#include <eqldimsdata.h>
#include <endscaledata.h>
#include <rockoptsdata.h>
#include <tabdimsdata.h>
#include <linearmatrix3d.h>
#include <rsconstdata.h>
#include <pvtodata.h>
#include <pvcodata.h>
#include <pmaxdata.h>
#include <pvcdodata.h>
#include <pvdodata.h>
#include <pvtwdata.h>
#include <pvdgdata.h>
#include <pvtgdata.h>
#include <rockdata.h>
#include <densitydata.h>
#include <gravitydata.h>
#include <swofdata.h>
#include <sgofdata.h>
#include <sgwfndata.h>
#include <slgofdata.h>
#include <sof2data.h>
#include <sof3data.h>
#include <sof32ddata.h>
#include <swfndata.h>
#include <sgfndata.h>
#include <somgasdata.h>
#include <somwatdata.h>
#include <ppcwmaxdata.h>
#include <enkrvddata.h>
#include <enpcvddata.h>
#include <enspcvddata.h>
#include <specheatdata.h>
#include <specrockdata.h>
#include <viscrefdata.h>
#include <oilvisctdata.h>
#include <watvisctdata.h>
#include <equildata.h>
#include <rsvddata.h>
#include <pbvddata.h>
#include <prvddata.h>
#include <aquancondata.h>
#include <aqufetpdata.h>
#include <dimpesdata.h>
#include <welspecsdata.h>
#include <compdatdata.h>
#include <wconproddata.h>
#include <wconinjedata.h>
#include <wconhistdata.h>
#include <wconinjhdata.h>
#include <weltargdata.h>
#include <equalsdata.h>
#include <copydata.h>
#include <adddata.h>
#include <multiplydata.h>

#include <model_global.h>

using namespace QaraMunai::Model::Utils;

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT StratumData
{
public:
    explicit StratumData();

    EQLDIMSData& EQLDIMS();
    ENDSCALEData& ENDSCALE();
    ROCKOPTSData& ROCKOPTS();
    TABDIMSData& TABDIMS();

    LinearMatrix3D& TOPS();

    LinearMatrix3D& DX();
    LinearMatrix3D& DY();
    LinearMatrix3D& DZ();

    LinearVector& DXV();
    LinearVector& DYV();
    LinearVector& DZV();
    LinearVector& COORD();
    LinearVector& ZCORN();

    LinearMatrix3D& ACTNUM();
    LinearMatrix3D& MULTPV();
    LinearMatrix3D& PERMX();
    LinearMatrix3D& PERMY();
    LinearMatrix3D& PERMZ();
    LinearMatrix3D& PORO();
    LinearMatrix3D& NTG();
    LinearMatrix3D& DZNET();
    LinearMatrix3D& MULTX();
    LinearMatrix3D& MULTY();
    LinearMatrix3D& MULTZ();
    LinearMatrix3D& MULTXm();
    LinearMatrix3D& MULTYm();
    LinearMatrix3D& MULTZm();
    LinearMatrix3D& MINPVV();

    double MINPV();

    RSCONSTData& RSCONST();
    QVector<RSCONSTData>& RSCONSTT();

    QVector<QVector<PVTOData>>& PVTO();
    QVector<QVector<PVCOData>>& PVCO();

    PMAXData& PMAX();

    QVector<PVCDOData>& PVCDO();

    QVector<QVector<PVDOData>>& PVDO();

    QVector<PVTWData> &PVTW();

    QVector<QVector<PVDGData>> &PVDG();
    QVector<QVector<PVTGData>> &PVTG();

    QVector<ROCKData> &ROCK();
    QVector<DENSITYData> &DENSITY();
    QVector<GRAVITYData> &GRAVITY();

    QVector<QVector<SWOFData>> &SWOF();
    QVector<QVector<SGOFData> > &SGOF();
    QVector<QVector<SGWFNData>> &SGWFN();
    QVector<QVector<SLGOFData>> &SLGOF();
    QVector<QVector<SOF2Data>> &SOF2();
    QVector<QVector<SOF3Data>> &SOF3();

    QVector<SOF32DData> &SOF32D();

    QVector<QVector<SWFNData>> &SWFN();
    QVector<QVector<SGFNData>> &SGFN();
    QVector<QVector<SOMGASData>> &SOMGAS();
    QVector<QVector<SOMWATData>> &SOMWAT();

    LinearMatrix3D& SWATINIT();
    LinearMatrix3D& SWCR();
    LinearMatrix3D& ISWCR();
    LinearMatrix3D& SWL();
    LinearMatrix3D& ISWL();
    LinearMatrix3D& SWLPC();
    LinearMatrix3D& ISWLPC();
    LinearMatrix3D& SWU();
    LinearMatrix3D& ISWU();
    LinearMatrix3D& SGCR();
    LinearMatrix3D& ISGCR();
    LinearMatrix3D& SGL();
    LinearMatrix3D& ISGL();
    LinearMatrix3D& SGLPC();
    LinearMatrix3D& ISGLPC();
    LinearMatrix3D& PCG();
    LinearMatrix3D& IPCG();
    LinearMatrix3D& PCW();
    LinearMatrix3D& IPCW();

    QVector<PPCWMAXData> &PPCWMAX();

    LinearMatrix3D& KRO();
    LinearMatrix3D& IKRO();
    LinearMatrix3D& KRORW();
    LinearMatrix3D& IKRORW();
    LinearMatrix3D& KRORG();
    LinearMatrix3D& IKRORG();
    LinearMatrix3D& KRW();
    LinearMatrix3D& IKRW();
    LinearMatrix3D& KRWR();
    LinearMatrix3D& IKRWR();
    LinearMatrix3D& KRG();
    LinearMatrix3D& IKRG();
    LinearMatrix3D& KRGR();
    LinearMatrix3D& IKRGR();

    QVector<QVector<ENKRVDData>> &ENKRVD();
    QVector<QVector<ENPCVDData>> &ENPCVD();
    QVector<QVector<ENSPCVDData>> &ENSPCVD();

    QVector<QVariant> &SCALELIM();

    QVariant SCALECRS();

    QVector<QVector<SPECHEATData>> &SPECHEAT();
    QVector<QVector<SPECROCKData>> &SPECROCK();

    QVector<VISCREFData> &VISCREF();

    QVector<QVector<OILVISCTData>> &OILVISCT();
    QVector<QVector<WATVISCTData>> &WATVISCT();

    LinearMatrix3D &PVTNUM();
    LinearMatrix3D &SATNUM();
    LinearMatrix3D &EQLNUM();
    LinearMatrix3D &ENDNUM();

    QVector<EQUILData> &EQUIL();

    QVector<QVector<RSVDData>> &RSVD();
    QVector<QVector<PBVDData>> &PBVD();
    QVector<QVector<PRVDData>> &PRVD();

    LinearMatrix3D &PRESSURE();
    LinearMatrix3D &SWAT();
    LinearMatrix3D &SOIL();
    LinearMatrix3D &SGAS();
    LinearMatrix3D &PBUB();
    LinearMatrix3D &RS();

    QVector<AQUANCONData> &AQUANCON();
    QVector<AQUFETPData> &AQUFETP();

    DIMPESData& DIMPES();

    QVector<QDateTime> &DATES();

    QVector<WCONHISTData> &WCONHIST();
    QVector<WCONINJHData> &WCONINJH();
    QVector<WELTARGData> &WELTARG();

    LinearMatrix3D& DEPTH();
    LinearMatrix3D& PORV();
    LinearMatrix3D& TRANX();
    LinearMatrix3D& TRANY();
    LinearMatrix3D& TRANZ();

    void SetMINPV(const double &minpv);
    void SetSCALECRS(const QVariant &scleCRS);

    void InitVariables();

private:
    EQLDIMSData eqlDIMS;
    ENDSCALEData endSCALE;
    ROCKOPTSData rockOPTS;
    TABDIMSData tabDIMS;

    LinearMatrix3D tops;

    LinearMatrix3D dx, dy, dz;

    LinearVector dxv, dyv, dzv;
    LinearVector coord, zcorn;

    LinearMatrix3D actnum, multpv;
    LinearMatrix3D permx, permy, permz;
    LinearMatrix3D poro, ntg, dznet;
    LinearMatrix3D multx, multy, multz;
    LinearMatrix3D multxm, multym, multzm;
    LinearMatrix3D minpvv;

    double minpv;

    RSCONSTData rsCONST;
    QVector<RSCONSTData> rsCONSTT;

    QVector<QVector<PVTOData>> pvto;
    QVector<QVector<PVCOData>> pvco;

    PMAXData pmax;

    QVector<PVCDOData> pvcdo;

    QVector<QVector<PVDOData>> pvdo;

    QVector<PVTWData> pvtw;

    QVector<QVector<PVDGData>> pvdg;
    QVector<QVector<PVTGData>> pvtg;

    QVector<ROCKData> rock;
    QVector<DENSITYData> density;
    QVector<GRAVITYData> gravity;

    QVector<QVector<SWOFData>> swof;
    QVector<QVector<SGOFData>> sgof;
    QVector<QVector<SGWFNData>> sgwfn;
    QVector<QVector<SLGOFData>> slgof;
    QVector<QVector<SOF2Data>> sof2;
    QVector<QVector<SOF3Data>> sof3;

    QVector<SOF32DData> sof32d;

    QVector<QVector<SWFNData>> swfn;
    QVector<QVector<SGFNData>> sgfn;
    QVector<QVector<SOMGASData>> somgas;
    QVector<QVector<SOMWATData>> somwat;

    LinearMatrix3D swatINIT, swcr, iswcr, swl, iswl, swlpc, iswlpc, swu, iswu, sgcr, isgcr, sgl, isgl, sglpc, isglpc, pcg, ipcg, pcw, ipcw;

    QVector<PPCWMAXData> ppcwMAX;

    LinearMatrix3D kro, ikro, krorw, ikrorw, krorg, ikrorg, krw, ikrw, krwr, ikrwr, krg, ikrg, krgr, ikrgr;

    QVector<QVector<ENKRVDData>> enkrvd;
    QVector<QVector<ENPCVDData>> enpcvd;
    QVector<QVector<ENSPCVDData>> enspcvd;

    QVector<QVariant> scalelim;

    QVariant scleCRS;

    QVector<QVector<SPECHEATData>> specheat;
    QVector<QVector<SPECROCKData>> specrock;

    QVector<VISCREFData> viscREF;

    QVector<QVector<OILVISCTData>> oilVISCT;
    QVector<QVector<WATVISCTData>> watVISCT;

    LinearMatrix3D pvtnum, satnum, eqlnum, endnum;

    QVector<EQUILData> equil;

    QVector<QVector<RSVDData>> rsvd;
    QVector<QVector<PBVDData>> pbvd;
    QVector<QVector<PRVDData>> prvd;

    LinearMatrix3D pressure, swat, soil, sgas, pbub, rs;

    QVector<AQUANCONData> aquanCON;
    QVector<AQUFETPData> aquFETP;

    DIMPESData dimpes;

    QVector<QDateTime> dates;

    QVector<WCONHISTData> wconHIST;
    QVector<WCONINJHData> wconINJH;
    QVector<WELTARGData> welTARG;

    LinearMatrix3D depth, porv, tranX, tranY, tranZ;
};

}}}}

#endif // STRATUMDATA_H
