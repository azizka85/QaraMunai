#ifndef POINT3D_H
#define POINT3D_H

#include <qvariant.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Grid {

class MODELSHARED_EXPORT Point3D
{
public:
    Point3D();
    Point3D(double x, double y, double z);

    double X();
    double Y();
    double Z();

    static Point3D Substract(Point3D& v1, Point3D& v2);

    void SetX(const double& x);
    void SetY(const double& y);
    void SetZ(const double& z);

    void InitVariables();

    QVariantMap toMap();

private:
    double x, y, z;
};

}}}}

#endif // POINT3D_H
