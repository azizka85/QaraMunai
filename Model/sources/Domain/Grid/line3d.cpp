#include "line3d.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Grid {

Line3D::Line3D()
{
    InitVariables();
}

Line3D::Line3D(const Point3D &p1, const Point3D &p2)
{
    this->p1 = p1;
    this->p2 = p2;
}

Point3D &Line3D::P1()
{
    return p1;
}

Point3D &Line3D::P2()
{
    return p2;
}

void Line3D::SetP1(const Point3D &p1)
{
    this->p1 = p1;
}

void Line3D::SetP2(const Point3D &p2)
{
    this->p2 = p2;
}

void Line3D::InitVariables()
{
    p1.InitVariables();
    p2.InitVariables();
}

}}}}
