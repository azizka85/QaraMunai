#ifndef MATHHELPER_H
#define MATHHELPER_H

#include <qmath.h>

#include <point3d.h>
#include <line3d.h>
#include <plane.h>
#include <segment.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Grid;

namespace QaraMunai {
namespace Model {
namespace Helpers {

class MODELSHARED_EXPORT MathHelper
{
public:
    static Point3D IntersectNotStrong(Line3D &line1, Line3D &line2);
    static bool Intersect(Line3D &line1, Line3D &line2, Point3D& p);
    static void IntersectZPlane(Line3D& line, double& z, Point3D& point);
    static double ParallelepipedVolume(Point3D& v1, Point3D& v2, Point3D& v3);

    static Point3D GetAveragePoint(QList<Point3D> &p);
    static Point3D GetMassCenter(Point3D &p1, Point3D &p2, Point3D &p3, Point3D &p4, Point3D &p5, Point3D &p6, Point3D &p7, Point3D &p8);

    static double AbsCrossProduct(Point3D &v1, Point3D &v2);
    static Point3D CrossProduct(Point3D &a, Point3D &b);
    static Point3D Subtract(Point3D &a, Point3D &b);

    static Plane PlaneYZ();
    static Plane PlaneXZ();
    static Plane PlaneXY();
    static double CosBetweenPlanes(Plane &plane1, Plane &plane2);

    static double GetTriangleArea(Point3D &p0, Point3D &p1, Point3D &p2);
    static double GetTetragonArea(Point3D &p0, Point3D &p1, Point3D &p2, Point3D &p3);
    static double GetPentagonArea(Point3D &p0, Point3D &p1, Point3D &p2, Point3D &p3, Point3D &p4);
    static double GetHexagonArea(Point3D &p0, Point3D &p1, Point3D &p2, Point3D &p3, Point3D &p4, Point3D &p5);
    static double GetContactArea(Point3D &a1Up, Point3D &a1Down, Point3D &b1Up, Point3D &b1Down, Point3D &a2Up, Point3D &a2Down, Point3D &b2Up, Point3D &b2Down, Point3D &contactAreaCenter);

    static bool IsIntersectedSurfaces(Segment lside1, Segment rside1, Segment lside2, Segment rside2);
};

}}}

#endif // MATHHELPER_H
