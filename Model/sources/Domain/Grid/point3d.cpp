#include "point3d.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Grid {

Point3D::Point3D()
{
    InitVariables();
}

Point3D::Point3D(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

double Point3D::X()
{
    return x;
}

double Point3D::Y()
{
    return y;
}

double Point3D::Z()
{
    return z;
}

Point3D Point3D::Substract(Point3D &v1, Point3D &v2)
{
    return Point3D(v1.X() - v2.X(), v1.Y() - v2.Y(), v1.Z() - v2.Z());
}

void Point3D::SetX(const double &x)
{
    this->x = x;
}

void Point3D::SetY(const double &y)
{
    this->y = y;
}

void Point3D::SetZ(const double &z)
{
    this->z = z;
}

void Point3D::InitVariables()
{
    x = 0;
    y = 0;
    z = 0;
}

QVariantMap Point3D::toMap()
{
    return QVariantMap { { "x", x }, { "y", y }, { "z", z } };
}

}}}}
