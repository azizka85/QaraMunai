#ifndef STRATUMDATA_H
#define STRATUMDATA_H

#include <qvariant.h>
#include <qlist.h>

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
    QList<RSCONSTData>& RSCONSTT();

    QList<QList<PVTOData>>& PVTO();
    QList<QList<PVCOData>>& PVCO();

    PMAXData& PMAX();

    QList<PVCDOData>& PVCDO();

    QList<QList<PVDOData>>& PVDO();

    QList<PVTWData> &PVTW();

    QList<QList<PVDGData>> &PVDG();
    QList<QList<PVTGData>> &PVTG();

    QList<ROCKData> &ROCK();
    QList<DENSITYData> &DENSITY();
    QList<GRAVITYData> &GRAVITY();

    QList<QList<SWOFData>> &SWOF();
    QList<QList<SGOFData> > &SGOF();
    QList<QList<SGWFNData>> &SGWFN();
    QList<QList<SLGOFData>> &SLGOF();
    QList<QList<SOF2Data>> &SOF2();
    QList<QList<SOF3Data>> &SOF3();

    QList<SOF32DData> &SOF32D();

    QList<QList<SWFNData>> &SWFN();
    QList<QList<SGFNData>> &SGFN();
    QList<QList<SOMGASData>> &SOMGAS();
    QList<QList<SOMWATData>> &SOMWAT();

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

    QList<PPCWMAXData> &PPCWMAX();

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

    QList<QList<ENKRVDData>> &ENKRVD();
    QList<QList<ENPCVDData>> &ENPCVD();
    QList<QList<ENSPCVDData>> &ENSPCVD();

    QList<QVariant> &SCALELIM();

    QVariant SCALECRS();

    QList<QList<SPECHEATData>> &SPECHEAT();
    QList<QList<SPECROCKData>> &SPECROCK();

    QList<VISCREFData> &VISCREF();

    QList<QList<OILVISCTData>> &OILVISCT();
    QList<QList<WATVISCTData>> &WATVISCT();

    LinearMatrix3D &PVTNUM();
    LinearMatrix3D &SATNUM();
    LinearMatrix3D &EQLNUM();
    LinearMatrix3D &ENDNUM();

    QList<EQUILData> &EQUIL();

    QList<QList<RSVDData>> &RSVD();
    QList<QList<PBVDData>> &PBVD();
    QList<QList<PRVDData>> &PRVD();

    LinearMatrix3D &PRESSURE();
    LinearMatrix3D &SWAT();
    LinearMatrix3D &SGAS();
    LinearMatrix3D &PBUB();
    LinearMatrix3D &RS();

    QList<AQUANCONData> &AQUANCON();
    QList<AQUFETPData> &AQUFETP();

    DIMPESData& DIMPES();

    QList<WELSPECSData> &WELSPECS();
    QList<COMPDATData> &COMPDAT();
    QList<WCONPRODData> &WCONPROD();
    QList<WCONINJEData> &WCONINJE();

    QList<QDateTime> &DATES();

    QList<WCONHISTData> &WCONHIST();
    QList<WCONINJHData> &WCONINJH();
    QList<WELTARGData> &WELTARG();    

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
    QList<RSCONSTData> rsCONSTT;

    QList<QList<PVTOData>> pvto;
    QList<QList<PVCOData>> pvco;

    PMAXData pmax;

    QList<PVCDOData> pvcdo;

    QList<QList<PVDOData>> pvdo;

    QList<PVTWData> pvtw;

    QList<QList<PVDGData>> pvdg;
    QList<QList<PVTGData>> pvtg;

    QList<ROCKData> rock;
    QList<DENSITYData> density;
    QList<GRAVITYData> gravity;

    QList<QList<SWOFData>> swof;
    QList<QList<SGOFData>> sgof;
    QList<QList<SGWFNData>> sgwfn;
    QList<QList<SLGOFData>> slgof;
    QList<QList<SOF2Data>> sof2;
    QList<QList<SOF3Data>> sof3;

    QList<SOF32DData> sof32d;

    QList<QList<SWFNData>> swfn;
    QList<QList<SGFNData>> sgfn;
    QList<QList<SOMGASData>> somgas;
    QList<QList<SOMWATData>> somwat;

    LinearMatrix3D swatINIT, swcr, iswcr, swl, iswl, swlpc, iswlpc, swu, iswu, sgcr, isgcr, sgl, isgl, sglpc, isglpc, pcg, ipcg, pcw, ipcw;

    QList<PPCWMAXData> ppcwMAX;

    LinearMatrix3D kro, ikro, krorw, ikrorw, krorg, ikrorg, krw, ikrw, krwr, ikrwr, krg, ikrg, krgr, ikrgr;

    QList<QList<ENKRVDData>> enkrvd;
    QList<QList<ENPCVDData>> enpcvd;
    QList<QList<ENSPCVDData>> enspcvd;

    QList<QVariant> scalelim;

    QVariant scleCRS;

    QList<QList<SPECHEATData>> specheat;
    QList<QList<SPECROCKData>> specrock;

    QList<VISCREFData> viscREF;

    QList<QList<OILVISCTData>> oilVISCT;
    QList<QList<WATVISCTData>> watVISCT;

    LinearMatrix3D pvtnum, satnum, eqlnum, endnum;

    QList<EQUILData> equil;

    QList<QList<RSVDData>> rsvd;
    QList<QList<PBVDData>> pbvd;
    QList<QList<PRVDData>> prvd;

    LinearMatrix3D pressure, swat, sgas, pbub, rs;

    QList<AQUANCONData> aquanCON;
    QList<AQUFETPData> aquFETP;

    DIMPESData dimpes;

    QList<WELSPECSData> welSPECS;
    QList<COMPDATData> compDAT;
    QList<WCONPRODData> wconPROD;
    QList<WCONINJEData> wconINJE;

    QList<QDateTime> dates;

    QList<WCONHISTData> wconHIST;
    QList<WCONINJHData> wconINJH;
    QList<WELTARGData> welTARG;    

    LinearMatrix3D depth, porv, tranX, tranY, tranZ;
};

}}}}

#endif // STRATUMDATA_H
