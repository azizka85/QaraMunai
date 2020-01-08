#ifndef PLANE_H
#define PLANE_H

#include <point3d.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Grid {

class Plane
{
public:
    Plane(double a, double b, double c, double d);
    Plane(Point3D &p1, Point3D &p2, Point3D &p3);

    double A();
    double B();
    double C();
    double D();

    Point3D GetProjectionPoint(Point3D& p);

    void SetA(double& a);
    void SetB(double& b);
    void SetC(double& c);
    void SetD(double& d);

private:
    double a, b, c, d;
};

}}}}

#endif // PLANE_H
