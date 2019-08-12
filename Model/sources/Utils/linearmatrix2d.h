#ifndef LINEARMATRIX2D_H
#define LINEARMATRIX2D_H

#include <qvariant.h>

#include <box2d.h>
#include <linearvector.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Grid;

namespace QaraMunai {
namespace Model {
namespace Utils {

class MODELSHARED_EXPORT LinearMatrix2D : public LinearVector
{
public:
    LinearMatrix2D();

    Box2D &Box();
    int Nx();

    QVariant operator() (int i, int j);

    void SetBox(const Box2D& box);

private:
    Box2D box;
};

}}}

#endif // LINEARMATRIX2D_H
