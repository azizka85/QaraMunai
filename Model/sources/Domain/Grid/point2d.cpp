#include "point2d.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Grid {

Point2D::Point2D()
{
    InitVariables();
}

Point2D::Point2D(double x, double y)
{
    this->x = x;
    this->y = y;
}

double Point2D::X()
{
    return x;
}

double Point2D::Y()
{
    return y;
}

void Point2D::SetX(const double &x)
{
    this->x = x;
}

void Point2D::SetY(const double &y)
{
    this->y = y;
}

void Point2D::InitVariables()
{
    x = 0;
    y = 0;
}

QVariantMap Point2D::toMap()
{
    return QVariantMap {{"x", x}, {"y", y}};
}

}}}}
