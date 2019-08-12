#include "linearmatrix3d.h"

namespace QaraMunai {
namespace Model {
namespace Utils {

LinearMatrix3D::LinearMatrix3D() : LinearVector() {  }

Box3D &LinearMatrix3D::Box()
{
    return box;
}

int LinearMatrix3D::Nx()
{
    return box.I2() - box.I1() + 1;
}

int LinearMatrix3D::Ny()
{
    return box.J2() - box.J1() + 1;
}

QVariant LinearMatrix3D::operator()(int i, int j, int k)
{
    i = i - box.I1();
    j = j - box.J1();
    k = k - box.K1();

    int index = k * Nx() * Ny() + j * Nx() + i;

    return LinearVector::Search(index);
}

void LinearMatrix3D::SetBox(const Box3D &box)
{
    this->box = box;
}

}}}
