#ifndef BOX1D_H
#define BOX1D_H

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Grid {

class MODELSHARED_EXPORT Box1D
{
public:
    Box1D();
    Box1D(int i1, int i2);

    int I1();
    int I2();

    void SetI1(int i1);
    void SetI2(int i2);

    void InitVariables();

private:
    int i1, i2;
};

}}}}

#endif // BOX1D_H
