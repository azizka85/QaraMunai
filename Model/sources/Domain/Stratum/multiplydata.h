#ifndef MULTIPLYDATA_H
#define MULTIPLYDATA_H

#include <qstring.h>

#include <box3d.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Grid;

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT MULTIPLYData
{
public:
    MULTIPLYData();

    QString ArrayName();
    double Mult();
    Box3D &Box();

    void SetArrayName(const QString& arrayName);
    void SetMult(const double& mult);

    void InitVariables();

private:
    QString arrayName;
    double mult;
    Box3D box;
};

}}}}

#endif // MULTIPLYDATA_H
