#ifndef BOX3D_H
#define BOX3D_H

#include <box2d.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Grid {

class MODELSHARED_EXPORT Box3D : public Box2D
{
public:
    Box3D();
    Box3D(int i1, int i2, int j1, int j2, int k1, int k2);

    int K1();
    int K2();

    void SetK1(int k1);
    void SetK2(int k2);

    void InitVariables();

private:
    int k1, k2;
};

}}}}

#endif // BOX3D_H
