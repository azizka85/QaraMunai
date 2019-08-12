#ifndef BOX2D_H
#define BOX2D_H

#include <box1d.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Grid {

class MODELSHARED_EXPORT Box2D : public Box1D
{
public:
    Box2D();
    Box2D(int i1, int i2, int j1, int j2);

    int J1();
    int J2();

    void SetJ1(int j1);
    void SetJ2(int j2);

    void InitVariables();

private:
    int j1, j2;
};

}}}}

#endif // BOX2D_H
