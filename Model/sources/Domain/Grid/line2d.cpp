#include "line2d.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Grid {

Line2D::Line2D()
{
    InitVariables();
}

Line2D::Line2D(const Point2D &p1, const Point2D &p2)
{
    this->p1 = p1;
    this->p2 = p2;
}

Point2D &Line2D::P1()
{
    return p1;
}

Point2D &Line2D::P2()
{
    return p2;
}

void Line2D::SetP1(const Point2D &p1)
{
    this->p1 = p1;
}

void Line2D::SetP2(const Point2D &p2)
{
    this->p2 = p2;
}

void Line2D::InitVariables()
{
    p1.InitVariables();
    p2.InitVariables();
}

}}}}
