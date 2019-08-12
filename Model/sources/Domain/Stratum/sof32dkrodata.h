#ifndef SOF32DKRODATA_H
#define SOF32DKRODATA_H

#include <qlist.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT SOF32DKrOData
{
public:
    SOF32DKrOData();

    double SG();
    QList<double> &KrO();

    void SetSG(const double& sg);

    void InitVariables();

private:
    double sg;
    QList<double> kro;
};

}}}}

#endif // SOF32DKRODATA_H
