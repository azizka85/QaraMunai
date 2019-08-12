#include "box1d.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Grid {

Box1D::Box1D() : Box1D(0, 0) { }

Box1D::Box1D(int i1, int i2)
{
    this->i1 = i1;
    this->i2 = i2;
}

int Box1D::I1()
{
    return i1;
}

int Box1D::I2()
{
    return i2;
}

void Box1D::SetI1(int i1)
{
    this->i1 = i1;
}

void Box1D::SetI2(int i2)
{
    this->i2 = i2;
}

void Box1D::InitVariables()
{
    i1 = 0;
    i2 = 0;
}

}}}}
