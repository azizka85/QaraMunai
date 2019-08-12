#ifndef SGFNDATA_H
#define SGFNDATA_H

#include <qvariant.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT SGFNData
{
public:
    SGFNData();

    double SG();

    QVariant KrG();
    QVariant Pc();

    void SetSG(const double& sg);

    void SetKrG(const QVariant& krg);
    void SetPc(const QVariant& pc);

    void InitVariables();

private:
    double sg;
    QVariant krg, pc;
};

}}}}

#endif // SGFNDATA_H
