#include "linearmatrix3d.h"

namespace QaraMunai {
namespace Model {
namespace Utils {

LinearMatrix3D::LinearMatrix3D() : LinearVector() {  }

int LinearMatrix3D::Nx()
{
    return Box().I2() - Box().I1() + 1;
}

int LinearMatrix3D::Ny()
{
    return Box().J2() - Box().J1() + 1;
}

QVariant LinearMatrix3D::operator()(int i, int j, int k)
{
    i = i - Box().I1();
    j = j - Box().J1();
    k = k - Box().K1();

    int index = k * Nx() * Ny() + j * Nx() + i;

    return LinearVector::Search(index);
}

}}}
