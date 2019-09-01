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

LinearMatrix3D &StratumData::TOPS()
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

QVector<RSCONSTData> &StratumData::RSCONSTT()
{
    return rsCONSTT;
}

QVector<QVector<PVTOData> > &StratumData::PVTO()
{
    return pvto;
}

QVector<QVector<PVCOData> > &StratumData::PVCO()
{
    return pvco;
}

PMAXData &StratumData::PMAX()
{
    return pmax;
}

QVector<PVCDOData> &StratumData::PVCDO()
{
    return pvcdo;
}

QVector<QVector<PVDOData> > &StratumData::PVDO()
{
    return pvdo;
}

QVector<PVTWData> &StratumData::PVTW()
{
    return pvtw;
}

QVector<QVector<PVDGData> > &StratumData::PVDG()
{
    return pvdg;
}

QVector<QVector<PVTGData> > &StratumData::PVTG()
{
    return pvtg;
}

QVector<ROCKData> &StratumData::ROCK()
{
    return rock;
}

QVector<DENSITYData> &StratumData::DENSITY()
{
    return density;
}

QVector<GRAVITYData> &StratumData::GRAVITY()
{
    return gravity;
}

QVector<QVector<SWOFData> > &StratumData::SWOF()
{
    return swof;
}

QVector<QVector<SGOFData> > &StratumData::SGOF()
{
    return sgof;
}

QVector<QVector<SGWFNData> > &StratumData::SGWFN()
{
    return sgwfn;
}

QVector<QVector<SLGOFData> > &StratumData::SLGOF()
{
    return slgof;
}

QVector<QVector<SOF2Data> > &StratumData::SOF2()
{
    return sof2;
}

QVector<QVector<SOF3Data> > &StratumData::SOF3()
{
    return sof3;
}

QVector<SOF32DData> &StratumData::SOF32D()
{
    return sof32d;
}

QVector<QVector<SWFNData> > &StratumData::SWFN()
{
    return swfn;
}

QVector<QVector<SGFNData> > &StratumData::SGFN()
{
    return sgfn;
}

QVector<QVector<SOMGASData> > &StratumData::SOMGAS()
{
    return somgas;
}

QVector<QVector<SOMWATData> > &StratumData::SOMWAT()
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

QVector<PPCWMAXData> &StratumData::PPCWMAX()
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

QVector<QVector<ENKRVDData> > &StratumData::ENKRVD()
{
    return enkrvd;
}

QVector<QVector<ENPCVDData> > &StratumData::ENPCVD()
{
    return enpcvd;
}

QVector<QVector<ENSPCVDData> > &StratumData::ENSPCVD()
{
    return enspcvd;
}

QVector<QVariant> &StratumData::SCALELIM()
{
    return scalelim;
}

QVariant StratumData::SCALECRS()
{
    return scleCRS;
}

QVector<QVector<SPECHEATData> > &StratumData::SPECHEAT()
{
    return specheat;
}

QVector<QVector<SPECROCKData> > &StratumData::SPECROCK()
{
    return specrock;
}

QVector<VISCREFData> &StratumData::VISCREF()
{
    return viscREF;
}

QVector<QVector<OILVISCTData> > &StratumData::OILVISCT()
{
    return oilVISCT;
}

QVector<QVector<WATVISCTData> > &StratumData::WATVISCT()
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

QVector<EQUILData> &StratumData::EQUIL()
{
    return equil;
}

QVector<QVector<RSVDData> > &StratumData::RSVD()
{
    return rsvd;
}

QVector<QVector<PBVDData> > &StratumData::PBVD()
{
    return pbvd;
}

QVector<QVector<PRVDData> > &StratumData::PRVD()
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

LinearMatrix3D &StratumData::SOIL()
{
    return soil;
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

QVector<AQUANCONData> &StratumData::AQUANCON()
{
    return aquanCON;
}

QVector<AQUFETPData> &StratumData::AQUFETP()
{
    return aquFETP;
}

DIMPESData &StratumData::DIMPES()
{
    return dimpes;
}

QVector<QDateTime> &StratumData::DATES()
{
    return dates;
}

QVector<WCONHISTData> &StratumData::WCONHIST()
{
    return wconHIST;
}

QVector<WCONINJHData> &StratumData::WCONINJH()
{
    return wconINJH;
}

QVector<WELTARGData> &StratumData::WELTARG()
{
    return welTARG;
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
    soil.Clear();
    sgas.Clear();
    pbub.Clear();
    rs.Clear();

    aquanCON.clear();
    aquFETP.clear();

    dimpes.InitVariables();

    dates.clear();

    wconHIST.clear();
    wconINJH.clear();
    welTARG.clear();

    depth.Clear();
    porv.Clear();
    tranX.Clear();
    tranY.Clear();
    tranZ.Clear();
}

}}}}
