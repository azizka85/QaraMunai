#include "box3d.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Grid {

Box3D::Box3D() : Box3D(0, 0, 0, 0, 0, 0) { }

Box3D::Box3D(int i1, int i2, int j1, int j2, int k1, int k2) : Box2D (i1, i2, j1, j2)
{
    this->k1 = k1;
    this->k2 = k2;
}

int Box3D::K1()
{
    return k1;
}

int Box3D::K2()
{
    return k2;
}

void Box3D::SetK1(int k1)
{
    this->k1 = k1;
}

void Box3D::SetK2(int k2)
{
    this->k2 = k2;
}

void Box3D::InitVariables()
{
    Box2D::InitVariables();

    k1 = 0;
    k2 = 0;
}

}}}}
