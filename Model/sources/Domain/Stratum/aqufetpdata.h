#ifndef AQUFETPDATA_H
#define AQUFETPDATA_H

#include <qvariant.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT AQUFETPData
{
public:
    AQUFETPData();

    int Num();
    double DatumDepth();
    QVariant DatumP();
    double VW();
    double C();
    double ProdIndex();
    int PVTWNum();
    QVariant SALT();

    void SetNum(const int& num);
    void SetDatumDepth(const double& datumDepth);
    void SetDatumP(const QVariant& datumP);
    void SetVW(const double& vw);
    void SetC(const double& c);
    void SetProdIndex(const double& prodIndex);
    void SetPVTWNum(const int& pvtwNum);
    void SetSALT(const QVariant& salt);

    void InitVariables();

private:
    int num, pvtwNum;
    double datumDepth, vw, c, prodIndex;
    QVariant datumP, salt;
};

}}}}

#endif // AQUFETPDATA_H
