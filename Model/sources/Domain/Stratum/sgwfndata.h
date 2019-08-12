#ifndef SGWFNDATA_H
#define SGWFNDATA_H

#include <qvariant.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT SGWFNData
{
public:
    SGWFNData();

    double SG();

    QVariant KrG();
    QVariant KrW();
    QVariant Pc();

    void SetSG(const double& sg);

    void SetKrG(const QVariant& krg);
    void SetKrW(const QVariant& krw);
    void SetPc(const QVariant& pc);

    void InitVariables();

private:
    double sg;
    QVariant krg, krw, pc;
};

}}}}

#endif // SGWFNDATA_H
