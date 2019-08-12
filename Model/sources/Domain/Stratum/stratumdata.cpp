#include "stratumdata.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

StratumData::StratumData()
{
    InitVariables();
}

EQLDIMSData &StratumData::EQLDIMS()
{
    return eqlDIMS;
}

ENDSCALEData &StratumData::ENDSCALE()
{
    return endSCALE;
}

ROCKOPTSData &StratumData::ROCKOPTS()
{
    return rockOPTS;
}

TABDIMSData &StratumData::TABDIMS()
{
    return tabDIMS;
}

LinearMatrix2D &StratumData::TOPS()
{
    return tops;
}

LinearMatrix3D &StratumData::DX()
{
    return dx;
}

LinearMatrix3D &StratumData::DY()
{
    return dy;
}

LinearMatrix3D &StratumData::DZ()
{
    return dz;
}

LinearVector &StratumData::DXV()
{
    return dxv;
}

LinearVector &StratumData::DYV()
{
    return dyv;
}

LinearVector &StratumData::DZV()
{
    return dzv;
}

LinearVector &StratumData::COORD()
{
    return coord;
}

LinearVector &StratumData::ZCORN()
{
    return zcorn;
}

LinearMatrix3D &StratumData::ACTNUM()
{
    return actnum;
}

LinearMatrix3D &StratumData::MULTPV()
{
    return multpv;
}

LinearMatrix3D &StratumData::PERMX()
{
    return permx;
}

LinearMatrix3D &StratumData::PERMY()
{
    return permy;
}

LinearMatrix3D &StratumData::PERMZ()
{
    return permz;
}

LinearMatrix3D &StratumData::PORO()
{
    return poro;
}

LinearMatrix3D &StratumData::NTG()
{
    return ntg;
}

LinearMatrix3D &StratumData::DZNET()
{
    return dznet;
}

LinearMatrix3D &StratumData::MULTX()
{
    return multx;
}

LinearMatrix3D &StratumData::MULTY()
{
    return multy;
}

LinearMatrix3D &StratumData::MULTZ()
{
    return multz;
}

LinearMatrix3D &StratumData::MULTXm()
{
    return multxm;
}

LinearMatrix3D &StratumData::MULTYm()
{
    return multym;
}

LinearMatrix3D &StratumData::MULTZm()
{
    return multzm;
}

double StratumData::MINPV()
{
    return minpv;
}

LinearMatrix3D &StratumData::MINPVV()
{
    return minpvv;
}

RSCONSTData &StratumData::RSCONST()
{
    return rsCONST;
}

QList<RSCONSTData> &StratumData::RSCONSTT()
{
    return rsCONSTT;
}

QList<QList<PVTOData> > &StratumData::PVTO()
{
    return pvto;
}

QList<QList<PVCOData> > &StratumData::PVCO()
{
    return pvco;
}

PMAXData &StratumData::PMAX()
{
    return pmax;
}

QList<PVCDOData> &StratumData::PVCDO()
{
    return pvcdo;
}

QList<QList<PVDOData> > &StratumData::PVDO()
{
    return pvdo;
}

QList<PVTWData> &StratumData::PVTW()
{
    return pvtw;
}

QList<QList<PVDGData> > &StratumData::PVDG()
{
    return pvdg;
}

QList<QList<PVTGData> > &StratumData::PVTG()
{
    return pvtg;
}

QList<ROCKData> &StratumData::ROCK()
{
    return rock;
}

QList<DENSITYData> &StratumData::DENSITY()
{
    return density;
}

QList<GRAVITYData> &StratumData::GRAVITY()
{
    return gravity;
}

QList<QList<SWOFData> > &StratumData::SWOF()
{
    return swof;
}

QList<QList<SGOFData>> &StratumData::SGOF()
{
    return sgof;
}

QList<QList<SGWFNData>> &StratumData::SGWFN()
{
    return sgwfn;
}

QList<QList<SLGOFData> > &StratumData::SLGOF()
{
    return slgof;
}

QList<QList<SOF2Data> > &StratumData::SOF2()
{
    return sof2;
}

QList<QList<SOF3Data> > &StratumData::SOF3()
{
    return sof3;
}

QList<SOF32DData> &StratumData::SOF32D()
{
    return sof32d;
}

QList<QList<SWFNData> > &StratumData::SWFN()
{
    return swfn;
}

QList<QList<SGFNData> > &StratumData::SGFN()
{
    return sgfn;
}

QList<QList<SOMGASData> > &StratumData::SOMGAS()
{
    return somgas;
}

QList<QList<SOMWATData> > &StratumData::SOMWAT()
{
    return somwat;
}

LinearMatrix3D &StratumData::SWATINIT()
{
    return swatINIT;
}

LinearMatrix3D &StratumData::SWCR()
{
    return swcr;
}

LinearMatrix3D &StratumData::ISWCR()
{
    return iswcr;
}

LinearMatrix3D &StratumData::SWL()
{
    return swl;
}

LinearMatrix3D &StratumData::ISWL()
{
    return iswl;
}

LinearMatrix3D &StratumData::SWLPC()
{
    return swlpc;
}

LinearMatrix3D &StratumData::ISWLPC()
{
    return iswlpc;
}

LinearMatrix3D &StratumData::SWU()
{
    return swu;
}

LinearMatrix3D &StratumData::ISWU()
{
    return iswu;
}

LinearMatrix3D &StratumData::SGCR()
{
    return sgcr;
}

LinearMatrix3D &StratumData::ISGCR()
{
    return isgcr;
}

LinearMatrix3D &StratumData::SGL()
{
    return sgl;
}

LinearMatrix3D &StratumData::ISGL()
{
    return isgl;
}

LinearMatrix3D &StratumData::SGLPC()
{
    return sglpc;
}

LinearMatrix3D &StratumData::ISGLPC()
{
    return isglpc;
}

LinearMatrix3D &StratumData::PCG()
{
    return pcg;
}

LinearMatrix3D &StratumData::IPCG()
{
    return ipcg;
}

LinearMatrix3D &StratumData::PCW()
{
    return pcw;
}

LinearMatrix3D &StratumData::IPCW()
{
    return ipcw;
}

QList<PPCWMAXData> &StratumData::PPCWMAX()
{
    return ppcwMAX;
}

LinearMatrix3D &StratumData::KRO()
{
    return kro;
}

LinearMatrix3D &StratumData::IKRO()
{
    return ikro;
}

LinearMatrix3D &StratumData::KRORW()
{
    return krorw;
}

LinearMatrix3D &StratumData::IKRORW()
{
    return ikrorw;
}

LinearMatrix3D &StratumData::KRORG()
{
    return krorg;
}

LinearMatrix3D &StratumData::IKRORG()
{
    return ikrorg;
}

LinearMatrix3D &StratumData::KRW()
{
    return krw;
}

LinearMatrix3D &StratumData::IKRW()
{
    return ikrw;
}

LinearMatrix3D &StratumData::KRWR()
{
    return krwr;
}

LinearMatrix3D &StratumData::IKRWR()
{
    return ikrwr;
}

LinearMatrix3D &StratumData::KRG()
{
    return krg;
}

LinearMatrix3D &StratumData::IKRG()
{
    return ikrg;
}

LinearMatrix3D &StratumData::KRGR()
{
    return krgr;
}

LinearMatrix3D &StratumData::IKRGR()
{
    return ikrgr;
}

QList<QList<ENKRVDData> > &StratumData::ENKRVD()
{
    return enkrvd;
}

QList<QList<ENPCVDData> > &StratumData::ENPCVD()
{
    return enpcvd;
}

QList<QList<ENSPCVDData> > &StratumData::ENSPCVD()
{
    return enspcvd;
}

QList<QVariant> &StratumData::SCALELIM()
{
    return scalelim;
}

QVariant StratumData::SCALECRS()
{
    return scleCRS;
}

QList<QList<SPECHEATData> > &StratumData::SPECHEAT()
{
    return specheat;
}

QList<QList<SPECROCKData> > &StratumData::SPECROCK()
{
    return specrock;
}

QList<VISCREFData> &StratumData::VISCREF()
{
    return viscREF;
}

QList<QList<OILVISCTData> > &StratumData::OILVISCT()
{
    return oilVISCT;
}

QList<QList<WATVISCTData> > &StratumData::WATVISCT()
{
    return watVISCT;
}

LinearMatrix3D &StratumData::PVTNUM()
{
    return pvtnum;
}

LinearMatrix3D &StratumData::SATNUM()
{
    return satnum;
}

LinearMatrix3D &StratumData::EQLNUM()
{
    return eqlnum;
}

LinearMatrix3D &StratumData::ENDNUM()
{
    return endnum;
}

QList<EQUILData> &StratumData::EQUIL()
{
    return equil;
}

QList<QList<RSVDData> > &StratumData::RSVD()
{
    return rsvd;
}

QList<QList<PBVDData> > &StratumData::PBVD()
{
    return pbvd;
}

QList<QList<PRVDData> > &StratumData::PRVD()
{
    return prvd;
}

LinearMatrix3D &StratumData::PRESSURE()
{
    return pressure;
}

LinearMatrix3D &StratumData::SWAT()
{
    return swat;
}

LinearMatrix3D &StratumData::SGAS()
{
    return sgas;
}

LinearMatrix3D &StratumData::PBUB()
{
    return pbub;
}

LinearMatrix3D &StratumData::RS()
{
    return rs;
}

QList<AQUANCONData> &StratumData::AQUANCON()
{
    return aquanCON;
}

QList<AQUFETPData> &StratumData::AQUFETP()
{
    return aquFETP;
}

DIMPESData &StratumData::DIMPES()
{
    return dimpes;
}

QList<WELSPECSData> &StratumData::WELSPECS()
{
    return welSPECS;
}

QList<COMPDATData> &StratumData::COMPDAT()
{
    return compDAT;
}

QList<WCONPRODData> &StratumData::WCONPROD()
{
    return wconPROD;
}

QList<WCONINJEData> &StratumData::WCONINJE()
{
    return wconINJE;
}

QList<QDateTime> &StratumData::DATES()
{
    return dates;
}

QList<WCONHISTData> &StratumData::WCONHIST()
{
    return wconHIST;
}

QList<WCONINJHData> &StratumData::WCONINJH()
{
    return wconINJH;
}

QList<WELTARGData> &StratumData::WELTARG()
{
    return welTARG;
}

QList<EQUALSData> &StratumData::EQUALS()
{
    return equals;
}

QList<COPYData> &StratumData::COPY()
{
    return copy;
}

QList<ADDData> &StratumData::ADD()
{
    return add;
}

QList<MULTIPLYData> &StratumData::MULTIPLY()
{
    return multiply;
}

LinearMatrix3D &StratumData::DEPTH()
{
    return depth;
}

LinearMatrix3D &StratumData::PORV()
{
    return porv;
}

LinearMatrix3D &StratumData::TRANX()
{
    return tranX;
}

LinearMatrix3D &StratumData::TRANY()
{
    return tranY;
}

LinearMatrix3D &StratumData::TRANZ()
{
    return tranZ;
}

void StratumData::SetMINPV(const double &minpv)
{
    this->minpv = minpv;
}

void StratumData::SetSCALECRS(const QVariant &scleCRS)
{
    this->scleCRS = scleCRS;
}

void StratumData::InitVariables()
{
    eqlDIMS.InitVariables();
    endSCALE.InitVariables();
    rockOPTS.InitVariables();
    tabDIMS.InitVariables();

    tops.Clear();
    dx.Clear();
    dy.Clear();
    dz.Clear();
    dxv.Clear();
    dyv.Clear();
    dzv.Clear();
    coord.Clear();
    zcorn.Clear();
    actnum.Clear();
    multpv.Clear();
    permx.Clear();
    permy.Clear();
    permz.Clear();
    poro.Clear();
    ntg.Clear();
    dznet.Clear();
    multx.Clear();
    multy.Clear();
    multz.Clear();
    multxm.Clear();
    multym.Clear();
    multzm.Clear();
    minpvv.Clear();

    minpv = 0;

    rsCONST.InitVariables();

    rsCONSTT.clear();

    pvto.clear();
    pvco.clear();

    pmax.InitVariables();

    pvcdo.clear();

    pvdo.clear();

    pvtw.clear();

    pvdg.clear();
    pvtg.clear();

    rock.clear();
    density.clear();
    gravity.clear();

    swof.clear();
    sgof.clear();
    sgwfn.clear();
    slgof.clear();
    sof2.clear();
    sof3.clear();

    sof32d.clear();

    swfn.clear();
    sgfn.clear();
    somgas.clear();
    somwat.clear();

    swatINIT.Clear();
    swcr.Clear();
    iswcr.Clear();
    swl.Clear();
    iswl.Clear();
    swlpc.Clear();
    iswlpc.Clear();
    swu.Clear();
    iswu.Clear();
    sgcr.Clear();
    isgcr.Clear();
    sgl.Clear();
    isgl.Clear();
    sglpc.Clear();
    isglpc.Clear();
    pcg.Clear();
    ipcg.Clear();
    pcw.Clear();
    ipcw.Clear();

    ppcwMAX.clear();

    kro.Clear();
    ikro.Clear();
    krorw.Clear();
    ikrorw.Clear();
    krorg.Clear();
    ikrorg.Clear();
    krw.Clear();
    ikrw.Clear();
    krwr.Clear();
    ikrwr.Clear();
    krg.Clear();
    ikrg.Clear();
    krgr.Clear();
    ikrgr.Clear();

    enkrvd.clear();
    enpcvd.clear();
    enspcvd.clear();

    scalelim.clear();

    scleCRS.clear();

    specheat.clear();
    specrock.clear();

    viscREF.clear();

    oilVISCT.clear();
    watVISCT.clear();

    pvtnum.Clear();
    satnum.Clear();
    eqlnum.Clear();
    endnum.Clear();

    equil.clear();

    rsvd.clear();
    pbvd.clear();
    prvd.clear();

    pressure.Clear();
    swat.Clear();
    sgas.Clear();
    pbub.Clear();
    rs.Clear();

    aquanCON.clear();
    aquFETP.clear();

    dimpes.InitVariables();

    welSPECS.clear();
    compDAT.clear();
    wconPROD.clear();
    wconINJE.clear();

    dates.clear();

    wconHIST.clear();
    wconINJH.clear();
    welTARG.clear();

    equals.clear();
    copy.clear();
    add.clear();
    multiply.clear();

    depth.Clear();
    porv.Clear();
    tranX.Clear();
    tranY.Clear();
    tranZ.Clear();
}

}}}}
