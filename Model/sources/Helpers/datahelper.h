#ifndef DATAHELPER_H
#define DATAHELPER_H

#include <qvariant.h>

#include <linearmatrix3d.h>

#include <stratumdata.h>

#include <equalsentity.h>
#include <copyentity.h>
#include <multiplyentity.h>
#include <addentity.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Stratum;
using namespace QaraMunai::Model::Domain::Project;
using namespace QaraMunai::Model::Utils;

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
    static double GetPoFromPVT(StratumData& stratum, int pvtNum, int rowNum);
    static double GetBoFromPVT(StratumData& stratum, int pvtNum, int rowNum);
    static double CalculateBoFromPVT(StratumData& stratum, double p, int pvtNum);
};

}}}

#endif // DATAHELPER_H
