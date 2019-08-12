#ifndef ENSPCVDDATA_H
#define ENSPCVDDATA_H

#include <qvariant.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT ENSPCVDData
{
public:
    ENSPCVDData();

    double Depth();
    QVariant SGL();
    QVariant SWL();

    void SetDepth(const double& depth);
    void SetSGL(const QVariant& sgl);
    void SetSWL(const QVariant& swl);

    void InitVariables();

private:
    double depth;
    QVariant sgl, swl;
};

}}}}

#endif // ENSPCVDDATA_H
