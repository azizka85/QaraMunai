#include "box3d.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Grid {

Box3D::Box3D()
{
    InitVariables();
}

Box3D::Box3D(int i1, int i2, int j1, int j2, int k1, int k2)
{
    this->i1 = i1;
    this->i2 = i2;
    this->j1 = j1;
    this->j2 = j2;
    this->k1 = k1;
    this->k2 = k2;
}

int Box3D::I1()
{
    return i1;
}

int Box3D::I2()
{
    return i2;
}

int Box3D::J1()
{
    return j1;
}

int Box3D::J2()
{
    return j2;
}

int Box3D::K1()
{
    return k1;
}

int Box3D::K2()
{
    return k2;
}

void Box3D::SetI1(int i1)
{
    this->i1 = i1;
}

void Box3D::SetI2(int i2)
{
    this->i2 = i2;
}

void Box3D::SetJ1(int j1)
{
    this->j1 = j1;
}

void Box3D::SetJ2(int j2)
{
    this->j2 = j2;
}

void Box3D::SetK1(int k1)
{
    this->k1 = k1;
}

void Box3D::SetK2(int k2)
{
    this->k2 = k2;
}

bool Box3D::Contains(int i, int j, int k)
{
    return (i < 0 || (i >= i1 && i <= i2)) &&
            (j < 0 || (j >= j1 && j <= j2)) &&
            (k < 0 || (k >= k1 && k <= k2));
}

void Box3D::InitVariables()
{
    i1 = -1;
    i2 = -1;
    j1 = -1;
    j2 = -1;
    k1 = -1;
    k2 = -1;
}

}}}}
