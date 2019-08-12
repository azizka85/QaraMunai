#include "linearmatrix2d.h"

namespace QaraMunai {
namespace Model {
namespace Utils {

LinearMatrix2D::LinearMatrix2D() : LinearVector() { }

Box2D& LinearMatrix2D::Box()
{
    return box;
}

int LinearMatrix2D::Nx()
{
    return box.I2() - box.I1() + 1;
}

QVariant LinearMatrix2D::operator()(int i, int j)
{
    i = i - box.I1();
    j = j - box.J1();

    int index = j * Nx() + i;

    return LinearVector::Search(index);
}

void LinearMatrix2D::SetBox(const Box2D &box)
{
    this->box = box;
}

}}}
