#ifndef EQUALSDATA_H
#define EQUALSDATA_H

#include <qstring.h>

#include <box3d.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Grid;

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT EQUALSData
{
public:
    EQUALSData();

    QString ArrayName();
    double Value();
    Box3D& Box();

    void SetArrayName(const QString& arrayName);
    void SetValue(const double& value);

    void InitVariables();

private:
    QString arrayName;
    double value;
    Box3D box;
};

}}}}

#endif // EQUALSDATA_H
