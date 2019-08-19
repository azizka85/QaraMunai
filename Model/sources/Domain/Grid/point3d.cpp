#include "point3d.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Grid {

Point3D::Point3D()
{
    InitVariables();
}

Point3D::Point3D(double x, double y, double z) : Point2D (x, y)
{
    this->z = z;
}

double Point3D::Z()
{
    return z;
}

Point3D Point3D::Substract(Point3D &v1, Point3D &v2)
{
    return Point3D(v1.X() - v2.X(), v1.Y() - v2.Y(), v1.Z() - v2.Z());
}

void Point3D::SetZ(const double &z)
{
    this->z = z;
}

void Point3D::InitVariables()
{
    Point2D::InitVariables();

    z = 0;
}

QVariantMap Point3D::toMap()
{
    QVariantMap map = Point2D::toMap();

    map["z"] = z;

    return map;
}

}}}}
