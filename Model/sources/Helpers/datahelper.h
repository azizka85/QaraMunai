#ifndef DATAHELPER_H
#define DATAHELPER_H

#include <qvariant.h>
#include <qvector.h>

#include <qfile.h>

#include <qdebug.h>

#include <block.h>
#include <segment.h>

#include <linearmatrix3d.h>

#include <projectdata.h>
#include <stratumdata.h>

#include <equalsentity.h>
#include <copyentity.h>
#include <multiplyentity.h>
#include <addentity.h>

#include <mathhelper.h>
#include <unithelper.h>

#include <defaultvalues.h>

#include <model_global.h>

#define EPSILON 1E-15

#define ISEQUAL(val1, val2) ((val1 - val2 < EPSILON) && (val1 - val2 > -EPSILON))
#define SQR(a) ((a)*(a))

using namespace QaraMunai::Model::Domain::Grid;
using namespace QaraMunai::Model::Domain::Stratum;
using namespace QaraMunai::Model::Domain::Project;
using namespace QaraMunai::Model::Utils;
using namespace QaraMunai::Model::Helpers;

namespace QaraMunai {
namespace Model {
namespace Helpers {

class MODELSHARED_EXPORT DataHelper
{
public:
    static void GenerateBlocks(ProjectData* projectData, QVector<Block> &blocks, int nx, int ny, int nz, bool isBlockCentered);

    static LinearMatrix3D& GetArray(StratumData& stratum, int name);
    static LinearMatrix3D& GetArrayByName(StratumData& stratum, QString arrayName);
    static QVariant GetEQUALSData(EQUALSEntity* equals, QString arrayName, int i, int j, int k);
    static QVariant GetCOPYData(COPYEntity* copy, StratumData& stratum, QString arrayName, int i, int j, int k);
    static void MULTIPLYValue(MULTIPLYEntity* multiply, QString arrayName, double &val, int i, int j, int k);
    static void ADDValue(ADDEntity* add, QString arrayName, double &val, int i, int j, int k);

    static int GetPVTLength(StratumData& stratum, int pvtNum);
    static double GetRSFromPVT(StratumData& stratum, int pvtNum, int rowNum = -1);
    static double GetPoFromPVT(StratumData& stratum, int pvtNum, int rowNum);
    static void GetPoRangeFromPVT(StratumData& stratum, double p, int pvtNum, int &a, int &b);
    static double GetBoFromPVT(StratumData& stratum, int pvtNum, int rowNum);
    static double GetMoFromPVT(StratumData& stratum, int pvtNum, int rowNum);
    static double CalculateRSBubFromPVT(StratumData& stratum, int pvtNum);
    static double CalculateRSFromPVT(StratumData& stratum, double p, int pvtNum);
    static double CalculatePBubFromPVT(StratumData& stratum, int pvtNum);
    static double CalculatePoFromPVT(StratumData& stratum, double rs, int pvtNum);    
    static double CalculateBoFromPVT(StratumData& stratum, double p, int pvtNum);

    static double CalculateRSFromRSVD(StratumData& stratum, double depth, int eqlNum);
    static double CalculatePBubFromPBVD(StratumData& stratum, double depth, int eqlNum);

    static bool CalcCoordLineCPG(StratumData &stratum, int i, int j, Line3D& coordLine);
    static bool CalcBlockDepthsCPG(StratumData &stratum, int i, int j, int k, int nx, int ny, double &d1, double &d2, double &d3, double &d4, double &d5, double &d6, double &d7, double &d8);
    static bool CheckPointOrderStandardCPG(StratumData &stratum, int nx, int ny);

    static void CalculateExistBlockArray(ProjectData* projectData, QVector<bool> &existBlock);
    static void CalculateDrawBlockArray(ProjectData* projectData, QVector<bool> &existBlock, QVector<bool> &drawBlock);
    static void GetDrawBlocks(ProjectData* projectData, QVector<bool> &drawBlock, QVector<Block> &blocks, double &xMin, double &xMax, double &yMin, double &yMax, double &zMin, double &zMax);
    static void NormalizeBlocks(double xMin, double xMax, double yMin, double yMax, double zMin, double zMax, QVector<Block> &blocks);

    static void DivideOnAxesNodes(int n, int mx, int my, int &nx, int &ny, int &nz);
    static void NumberOfGPUNodes(int n, int mx, int my, int &nx, int &ny, int &nz);

    static void SetPVTOil(StratumData& stratum, int pvtNum, double p, double rod, double rg, double &mo, double &bo, double &dBo, double &rs, double &drs, double &dro, double &ro, double pBub, double cr);
    static void SetPVTWAT(StratumData &stratum, int pvtNum, double p, double rwd, double &mw, double &bw, double &dbw, double &rw, double &drw);

    static void SetPcForInvSw(StratumData &stratum, int satNum, double pc, double &sw);

    static void CalcEquilData(ProjectData* projectData, int nx, int ny, int nz, QVector<double> &pw, QVector<double> &po, QVector<double> &sw);
};

}}}

#endif // DATAHELPER_H
