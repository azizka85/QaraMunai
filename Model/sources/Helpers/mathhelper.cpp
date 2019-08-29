#include <datahelper.h>

#include "mathhelper.h"

namespace QaraMunai {
namespace Model {
namespace Helpers {

Point3D MathHelper::IntersectNotStrong(Line3D &line1, Line3D &line2)
{
    Point3D p = Plane(line1.P1(), line1.P2(), line2.P1()).GetProjectionPoint(line2.P2());

    Point3D res;
    Line3D line(line2.P1(), p);

    bool val = Intersect(line1, line, res);

    if(!val) res = line2.P2();

    return res;
}

bool MathHelper::Intersect(Line3D &line1, Line3D &line2, Point3D &p)
{
    double m1 = line1.P1().X() - line1.P2().X();
    double n1 = line1.P1().Y() - line1.P2().Y();
    double p1 = line1.P1().Z() - line1.P2().Z();

    double m2 = line2.P1().X() - line2.P2().X();
    double n2 = line2.P1().Y() - line2.P2().Y();
    double p2 = line2.P1().Z() - line2.P2().Z();

    bool anyX = false;
    bool anyY = false;
    bool anyZ = false;

    double tx = 0;
    double ty = 0;
    double tz = 0;

    if (ISEQUAL(m2 - m1, 0))
    {
        if (ISEQUAL(line1.P1().X() - line2.P1().X(), 0)) anyX = true;
        else return false;
    }
    else tx = (line1.P1().X() - line2.P1().X()) / (m2 - m1);

    if (ISEQUAL(n2 - n1, 0))
    {
        if (ISEQUAL(line1.P1().Y() - line2.P1().Y(), 0)) anyY = true;
        else return false;
    }
    else ty = (line1.P1().Y() - line2.P1().Y()) / (n2 - n1);

    if (ISEQUAL(p2 - p1, 0))
    {
        if (ISEQUAL(line1.P1().Z() - line2.P1().Z(), 0)) anyZ = true;
        else return false;
    }
    else tz = (line1.P1().Z() - line2.P1().Z()) / (p2 - p1);

    double t = -1;
    if (!anyX) t = tx;
    else if (!anyY) t = ty;
    else if (!anyZ) t = tz;
    else return false;

    if ((!anyX && !ISEQUAL(t - tx, 0)) || (!anyY && !ISEQUAL(t - ty, 0)) || (!anyZ && !ISEQUAL(t - tz, 0))) return false;

    p.SetX(line1.P1().X() + m1 * t);
    p.SetY(line1.P1().Y() + n1 * t);
    p.SetZ(line1.P1().Z() + p1 * t);

    return true;
}

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

Point3D MathHelper::GetAveragePoint(QList<Point3D> &p)
{
    int count = p.length();

    double cx = 0, cy = 0, cz = 0;

    for (int i = 0; i < p.length(); i++)
    {
        cx += p[i].X();
        cy += p[i].Y();
        cz += p[i].Z();
    }

    return Point3D(cx / count, cy / count, cz / count);
}

Point3D MathHelper::GetMassCenter(Point3D &p1, Point3D &p2, Point3D &p3, Point3D &p4, Point3D &p5, Point3D &p6, Point3D &p7, Point3D &p8)
{
    return Point3D((p1.X() + p2.X() + p3.X() + p4.X() + p5.X() + p6.X() + p7.X() + p8.X())/8,
                   (p1.Y() + p2.Y() + p3.Y() + p4.Y() + p5.Y() + p6.Y() + p7.Y() + p8.Y())/8,
                   (p1.Z() + p2.Z() + p3.Z() + p4.Z() + p5.Z() + p6.Z() + p7.Z() + p8.Z())/8);
}

double MathHelper::AbsCrossProduct(Point3D &v1, Point3D &v2)
{
    double a = SQR(v1.Z() * v2.Y() - v1.Y() * v2.Z());
    double b = SQR(v1.X() * v2.Z() - v1.Z() * v2.X());
    double c = SQR(v1.Y() * v2.X() - v1.X() * v2.Y());

    return qSqrt(a + b + c);
}

Point3D MathHelper::CrossProduct(Point3D &a, Point3D &b)
{
    double x = a.Y() * b.Z() - a.Z() * b.Y();
    double y = a.Z() * b.X() - a.X() * b.Z();
    double z = a.X() * b.Y() - a.Y() * b.X();

    return Point3D(x, y, z);
}

Point3D MathHelper::Subtract(Point3D &a, Point3D &b)
{
    return Point3D(a.X() - b.X(), a.Y() - b.Y(), a.Z() - b.Z());
}

Plane MathHelper::PlaneYZ()
{
    Point3D p1(0, 0, 0);
    Point3D p2(0, 10, 0);
    Point3D p3(0, 0, 10);

    return Plane(p1, p2, p3);
}

Plane MathHelper::PlaneXZ()
{
    Point3D p1(10, 0, 0);
    Point3D p2(0, 0, 0);
    Point3D p3(0, 0, 10);

    return Plane(p1, p2, p3);
}

Plane MathHelper::PlaneXY()
{
    Point3D p1(10, 0, 0);
    Point3D p2(0, 10, 0);
    Point3D p3(0, 0, 0);

    return Plane(p1, p2, p3);
}

double MathHelper::CosBetweenPlanes(Plane &plane1, Plane &plane2)
{
    return qAbs(plane1.A() * plane2.A() + plane1.B() * plane2.B() + plane1.C() * plane2.C()) /
          (qSqrt(plane1.A() * plane1.A() + plane1.B() * plane1.B() + plane1.C() * plane1.C()) *
           qSqrt(plane2.A() * plane2.A() + plane2.B() * plane2.B() + plane2.C() * plane2.C()));
}

double MathHelper::GetTriangleArea(Point3D &p0, Point3D &p1, Point3D &p2)
{
    Point3D v1 = Subtract(p1, p0);
    Point3D v2 = Subtract(p1, p2);

    return AbsCrossProduct(v1, v2) / 2.0;
}

double MathHelper::GetTetragonArea(Point3D &p0, Point3D &p1, Point3D &p2, Point3D &p3)
{
    return GetTriangleArea(p0, p1, p2) + GetTriangleArea(p2, p3, p0);
}

double MathHelper::GetPentagonArea(Point3D &p0, Point3D &p1, Point3D &p2, Point3D &p3, Point3D &p4)
{
    return GetTetragonArea(p0, p1, p2, p3) + GetTriangleArea(p3, p4, p0);
}

double MathHelper::GetHexagonArea(Point3D &p0, Point3D &p1, Point3D &p2, Point3D &p3, Point3D &p4, Point3D &p5)
{
    return GetPentagonArea(p0, p1, p2, p3, p4) + GetTriangleArea(p4, p5, p0);
}

double MathHelper::GetContactArea(Point3D &a1Up, Point3D &a1Down, Point3D &b1Up, Point3D &b1Down, Point3D &a2Up, Point3D &a2Down, Point3D &b2Up, Point3D &b2Down, Point3D &contactAreaCenter)
{
    QList<Point3D> points;

    Line3D line1Up(a1Up, b1Up);
    Line3D line1Down(a1Down, b1Down);
    Line3D line2Up(a2Up, b2Up);
    Line3D line2Down(a2Down, b2Down);

    if (a1Up.Z() > a2Up.Z())
    {
        if (a1Down.Z() > a2Up.Z()) { }

        if (a1Down.Z() <= a2Up.Z() && a1Down.Z() > a2Down.Z())
        {
            points.append(a1Down);
            points.append(a2Up);
        }

        if (a1Down.Z() <= a2Down.Z())
        {
            points.append(a2Down);
            points.append(a2Up);
        }
    }
    if (a1Up.Z() <= a2Up.Z() && a1Up.Z() >= a2Down.Z())
    {
        if (a1Down.Z() > a2Down.Z())
        {
            points.append(a1Down);
            points.append(a1Up);
        }
        if (a1Down.Z() <= a2Down.Z())
        {
            points.append(a2Down);
            points.append(a1Up);
        }
    }
    if (a1Up.Z() > a2Down.Z()) { }

    if (a1Down.Z() > a2Up.Z() && b1Down.Z() < b2Up.Z()) points.append(MathHelper::IntersectNotStrong(line1Down, line2Up));
    if (a1Up.Z() > a2Up.Z() && b1Up.Z() < b2Up.Z()) points.append(MathHelper::IntersectNotStrong(line1Up, line2Up));

    if (a1Up.Z() < a2Up.Z() && b1Up.Z() > b2Up.Z()) points.append(MathHelper::IntersectNotStrong(line1Up, line2Up));
    if (a1Down.Z() < a2Up.Z() && b1Down.Z() > b2Up.Z()) points.append(MathHelper::IntersectNotStrong(line1Down, line2Up));

    if (b1Up.Z() > b2Up.Z())
    {
        if (b1Down.Z() > b2Up.Z()) { }

        if (b1Down.Z() <= b2Up.Z() && b1Down.Z() > b2Down.Z())
        {
            points.append(b2Up);
            points.append(b1Down);
        }

        if (b1Down.Z() <= b2Down.Z())
        {
            points.append(b2Up);
            points.append(b2Down);
        }
    }
    if (b1Up.Z() <= b2Up.Z() && b1Up.Z() >= b2Down.Z())
    {
        if (b1Down.Z() > b2Down.Z())
        {
            points.append(b1Up);
            points.append(b1Down);
        }
        if (b1Down.Z() <= b2Down.Z())
        {
            points.append(b1Up);
            points.append(b2Down);
        }
    }
    if (b1Up.Z() > b2Down.Z()) { }

    if (a1Down.Z() < a2Down.Z() && b1Down.Z() > b2Down.Z()) points.append(MathHelper::IntersectNotStrong(line1Down, line2Down));
    if (a1Up.Z() < a2Down.Z() && b1Up.Z() > b2Down.Z()) points.append(MathHelper::IntersectNotStrong(line1Up, line2Down));

    if (a1Up.Z() > a2Down.Z() && b1Up.Z() < b2Down.Z()) points.append(MathHelper::IntersectNotStrong(line1Up, line2Down));
    if (a1Down.Z() > a2Down.Z() && b1Down.Z() < b2Down.Z()) points.append(MathHelper::IntersectNotStrong(line1Down, line2Down));


    contactAreaCenter = MathHelper::GetAveragePoint(points);

    if (points.length() < 3) return 0;

    if (points.length() == 3) return MathHelper::GetTriangleArea(points[0], points[1], points[2]);
    if (points.length() == 4) return MathHelper::GetTetragonArea(points[0], points[1], points[2], points[3]);
    if (points.length() == 5) return MathHelper::GetPentagonArea(points[0], points[1], points[2], points[3], points[4]);
    if (points.length() == 6) return MathHelper::GetHexagonArea(points[0], points[1], points[2], points[3], points[4], points[5]);

    if (points.length() > 6) return 0;
}

}}}
