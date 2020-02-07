#ifndef DEFAULTVALUES_H
#define DEFAULTVALUES_H

#include <projectdata.h>
#include <endscaleentity.h>
#include <rockoptsentity.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

class MODELSHARED_EXPORT DefaultValues {
public:
    constexpr static ProjectData::UnitType Unit = ProjectData::FIELD;

    constexpr static ProjectData::ModelType Model = ProjectData::TwoPhase;

    constexpr static bool TemperatureOption = false;

    constexpr static int NUMRES = 1;

    constexpr static int TABDIMS_NTSFUN = 1;
    constexpr static int TABDIMS_NTPVT = 1;
    constexpr static int TABDIMS_NSSFUN = 50;

    constexpr static int PVTNUM = 1;
    constexpr static int EQLNUM = 1;
    constexpr static int SATNUM = 1;

    constexpr static int EQLDIMS_NTEQUL = 1;

    constexpr static ENDSCALEEntity::DirectionalType ENDSCALE_Directional = ENDSCALEEntity::NODIR;
    constexpr static ENDSCALEEntity::IrreversibleType ENDSCALE_Irreversible = ENDSCALEEntity::REVERS;
    constexpr static int ENDSCALE_NTENDP = 1;
    constexpr static int ENDSCALE_MaxNodesENDP = 20;

    constexpr static double MULTPV = 1;

    constexpr static double NTG = 1;

    constexpr static double MULTX = 1;
    constexpr static double MULTXm = 1;
    constexpr static double MULTY = 1;
    constexpr static double MULTYm = 1;
    constexpr static double MULTZ = 1;
    constexpr static double MULTZm = 1;

    constexpr static double MINPV = 1.0E-6;
    constexpr static double MINPVV = 1.0E-6;

    constexpr static int PMAX_NumNodes = 30;

    // barsa (METRIC unit)
    constexpr static double PMAX_PMaxComp = 0;

    // barsa (METRIC unit)
    constexpr static double PMAX_PMinComp = 1.0E+20;

    //  1 atma = 14.7psia (LAB unit)
    constexpr static double PVTW_PWRef = 1;

    constexpr static double PVTW_BWRef = 1;

    // 1/bars (METRIC unit)
    constexpr static double PVTW_CW = 4.0E-5;

    // cP (METRIC unit)
    constexpr static double PVTW_MWRef = 0.3;

    // 1/bars (METRIC unit)
    constexpr static double PVTW_CVW = 0;

    // barsa (METRIC unit)
    constexpr static double ROCK_PRef = 1.0132;

    // 1/bars (METRIC unit)
    constexpr static double ROCK_CPP = 4.934E-5;

    constexpr static ROCKOPTSEntity::MAOTPOptions ROCKOPTS_MAOTP = ROCKOPTSEntity::PRESSURE;
    constexpr static ROCKOPTSEntity::ReferencePressureOptions ROCKOPTS_RPO = ROCKOPTSEntity::NOSTORE;
    constexpr static ROCKOPTSEntity::RegionOptions ROCKOPTS_RegionOption = ROCKOPTSEntity::PVTNUM;
    constexpr static ROCKOPTSEntity::IHBOptions ROCKOPTS_IHBOption = ROCKOPTSEntity::DEFLATION;

    // kg/m3 (METRIC unit)
    constexpr static double DENSITY_RO = 600;

    // kg/m3 (METRIC unit)
    constexpr static double DENSITY_RW = 999.014;

    // kg/m3 (METRIC unit)
    constexpr static double DENSITY_RG = 1;

    constexpr static double GRAVITY_GO = 45.5;
    constexpr static double GRAVITY_GW = 1;
    constexpr static double GRAVITY_GG = 0.7773;

    constexpr static bool PPCWMAX_SModify = false;

    constexpr static double AQUANCON_InfluxMult = 1;

    constexpr static double DIMPES_DSTARG = 0.05;
    constexpr static double DIMPES_DSMAX = 0.1;

    // psi (FIELD unit)
    constexpr static double DIMPES_DPMAX = 200;

    const static QString WELSPECS_WellGroup;

    constexpr static ProjectData::WellStatusType COMPDAT_WellStatus = ProjectData::WellStatusType::OPEN;
    constexpr static double COMPDAT_SkinFactor = 0;

    constexpr static ProjectData::WellStatusType WCONPROD_WellStatus = ProjectData::WellStatusType::OPEN;

    // atma (LAB unit)
    constexpr static double WCONPROD_BHP = 100;

    constexpr static ProjectData::WellStatusType WCONINJE_WellStatus = ProjectData::WellStatusType::OPEN;

    // atma (LAB unit)
    constexpr static double WCONINJE_BHP = 1000;

    // atma (LAB unit)
    constexpr static double WCONINJE_BHP_Thermal = 200;

    constexpr static ProjectData::WellStatusType WCONHIST_WellStatus = ProjectData::WellStatusType::OPEN;
    constexpr static double WCONHIST_ORAT = 0;
    constexpr static double WCONHIST_WRAT = 0;
    constexpr static double WCONHIST_GRAT = 0;

    constexpr static ProjectData::WellStatusType WCONINJH_WellStatus = ProjectData::WellStatusType::OPEN;
    constexpr static double WCONINJH_RATE = 0;
    constexpr static double WCONINJH_BHP = 0;
};

}}}}

#endif // DEFAULTVALUES_H
