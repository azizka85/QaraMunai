#include "box2d.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Grid {

Box2D::Box2D() : Box2D(0, 0, 0, 0) { }

Box2D::Box2D(int i1, int i2, int j1, int j2) : Box1D (i1, i2)
{
    this->j1 = j1;
    this->j2 = j2;
}

int Box2D::J1()
{
    return j1;
}

int Box2D::J2()
{
    return j2;
}

void Box2D::SetJ1(int j1)
{
    this->j1 = j1;
}

void Box2D::SetJ2(int j2)
{
    this->j2 = j2;
}

void Box2D::InitVariables()
{
    Box1D::InitVariables();

    j1 = 0;
    j2 = 0;
}

}}}}
