#include "mathhelper.h"

namespace QaraMunai {
namespace Model {
namespace Helpers {

void MathHelper::IntersectZPlane(Line3D &line, double &z, Point3D &point)
{
    double t = (z - line.P1().Z()) / (line.P2().Z() - line.P1().Z());

    double x = line.P1().X() + (line.P2().X() - line.P1().X()) * t;
    double y = line.P1().Y() + (line.P2().Y() - line.P1().Y()) * t;

    point.SetX(x);
    point.SetY(y);
    point.SetZ(z);
}

double MathHelper::ParallelepipedVolume(Point3D &v1, Point3D &v2, Point3D &v3)
{
    return qAbs(v1.X() * v2.Y() * v3.Z() + v2.X() * v3.Y() * v1.Z() + v1.Y() * v2.Z() * v3.X() - v1.Z() * v2.Y() * v3.X() - v3.Y() * v2.Z() * v1.X() - v1.Y() * v2.X() * v3.Z());
}

}}}
