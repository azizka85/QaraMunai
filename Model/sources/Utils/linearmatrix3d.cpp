#include "linearmatrix3d.h"

namespace QaraMunai {
namespace Model {
namespace Utils {

LinearMatrix3D::LinearMatrix3D() : LinearVector() {  }

QVariant LinearMatrix3D::operator()(int i, int j, int k)
{
    int nx = Box().Nx();
    int ny = Box().Ny();

    i = i - Box().I1();
    j = j - Box().J1();
    k = k - Box().K1();

    int index = k * nx * ny + j * nx + i;

    return LinearVector::Search(index);
}

}}}
