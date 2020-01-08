#include <mathhelper.h>

#include "plane.h"

using namespace QaraMunai::Model::Helpers;

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Grid {

Plane::Plane(double a, double b, double c, double d)
{
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
}

Plane::Plane(Point3D &p1, Point3D &p2, Point3D &p3)
{
    Point3D v1 = MathHelper::Subtract(p1, p2);
    Point3D v2 = MathHelper::Subtract(p3, p2);

    Point3D planeNormal = MathHelper::CrossProduct(v1, v2);

    a = planeNormal.X();
    b = planeNormal.Y();
    c = planeNormal.Z();

    d = -a * p1.X() - b * p1.Y() - c * p1.Z();
}

double Plane::A()
{
    return a;
}

double Plane::B()
{
    return b;
}

double Plane::C()
{
    return c;
}

double Plane::D()
{
    return d;
}

Point3D Plane::GetProjectionPoint(Point3D &p)
{
    double t = -(a * p.X() + b * p.Y() + c * p.Z() + d) / (a * a + b * b + c * c);

    double x = p.X() + t * a;
    double y = p.Y() + t * b;
    double z = p.Z() + t * c;

    return Point3D(x, y, z);
}

void Plane::SetA(double &a)
{
    this->a = a;
}

void Plane::SetB(double &b)
{
    this->b = b;
}

void Plane::SetC(double &c)
{
    this->c = c;
}

void Plane::SetD(double &d)
{
    this->d = d;
}

}}}}
