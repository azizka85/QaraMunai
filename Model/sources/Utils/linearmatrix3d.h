#ifndef LINEARMATRIX3D_H
#define LINEARMATRIX3D_H

#include <qvariant.h>

#include <box3d.h>
#include <linearvector.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Grid;

namespace QaraMunai {
namespace Model {
namespace Utils {

class MODELSHARED_EXPORT LinearMatrix3D : public LinearVector
{
public:
    LinearMatrix3D();

    Box3D& Box();
    int Nx();
    int Ny();

    QVariant operator() (int i, int j, int k);

    void SetBox(const Box3D &box);

private:
    Box3D box;
};

}}}

#endif // LINEARMATRIX3D_H
