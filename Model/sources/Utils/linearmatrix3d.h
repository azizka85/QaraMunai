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

    int Nx();
    int Ny();

    QVariant operator() (int i, int j, int k);
};

}}}

#endif // LINEARMATRIX3D_H
