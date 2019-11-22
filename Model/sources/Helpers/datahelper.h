#ifndef DATAHELPER_H
#define DATAHELPER_H

#include <qvariant.h>
#include <qvector.h>

#include <qdebug.h>

#include <depth.h>
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
    static LinearMatrix3D& GetArray(StratumData& stratum, int name);
    static LinearMatrix3D& GetArrayByName(StratumData& stratum, QString arrayName);
    static QVariant GetEQUALSData(EQUALSEntity* equals, QString arrayName, int i, int j, int k);
    static QVariant GetCOPYData(COPYEntity* copy, StratumData& stratum, QString arrayName, int i, int j, int k);
    static void MULTIPLYValue(MULTIPLYEntity* multiply, QString arrayName, double &val, int i, int j, int k);
    static void ADDValue(ADDEntity* add, QString arrayName, double &val, int i, int j, int k);

    static int GetPVTLength(StratumData& stratum, int pvtNum);
    static double GetRSFromPVT(StratumData& stratum, int pvtNum, int rowNum = -1);
    static double GetPoFromPVT(StratumData& stratum, int pvtNum, int rowNum);
    static double GetBoFromPVT(StratumData& stratum, int pvtNum, int rowNum);
    static double CalculateRSBubFromPVT(StratumData& stratum, int pvtNum);
    static double CalculateRSFromPVT(StratumData& stratum, double p, int pvtNum);
    static double CalculatePBubFromPVT(StratumData& stratum, int pvtNum);
    static double CalculatePoFromPVT(StratumData& stratum, double rs, int pvtNum);
    static double CalculateBoFromPVT(StratumData& stratum, double p, int pvtNum);

    static double CalculateRSFromRSVD(StratumData& stratum, double depth, int eqlNum);
    static double CalculatePBubFromPBVD(StratumData& stratum, double depth, int eqlNum);

    static bool CalcCoordLineCPG(StratumData &stratum, int i, int j, int nx, Line3D& coordLine);
    static bool CalcBlockDepthsCPG(StratumData &stratum, int i, int j, int k, int nx, int ny, double &d1, double &d2, double &d3, double &d4, double &d5, double &d6, double &d7, double &d8);
    static bool CheckPointOrderStandardCPG(StratumData &stratum, int nx, int ny);

    static void CalculateBlockDepthArray(ProjectData* projectData, QVector<Depth>& depths);
    static void CalculateExistBlockArray(ProjectData* projectData, QVector<bool> &existBlock);
    static void CalculateDrawBlockArray(ProjectData* projectData, QVector<Depth>& depths, QVector<bool> &existBlock, QVector<bool> &drawBlock);
    static void GetDrawBlocks(ProjectData* projectData, QVector<bool> &drawBlock, QVector<Block> &blocks, double &xMin, double &xMax, double &yMin, double &yMax, double &zMin, double &zMax);
    static void NormalizeBlocks(double xMin, double xMax, double yMin, double yMax, double zMin, double zMax, QVector<Block> &blocks);
};

}}}

#endif // DATAHELPER_H
