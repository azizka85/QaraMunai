#include "line1d.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Grid {

Line1D::Line1D()
{
    InitVariables();
}

Line1D::Line1D(const double &x1, const double &x2)
{
    this->x1 = x1;
    this->x2 = x2;
}

double Line1D::X1()
{
    return x1;
}

double Line1D::X2()
{
    return x2;
}

void Line1D::SetX1(const double &x1)
{
    this->x1 = x1;
}

void Line1D::SetX2(const double &x2)
{
    this->x2 = x2;
}

void Line1D::InitVariables()
{
    x1 = 0;
    x2 = 0;
}

}}}}
