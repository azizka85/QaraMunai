#ifndef BOX3D_H
#define BOX3D_H

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Grid {

class MODELSHARED_EXPORT Box3D
{
public:
    Box3D();
    Box3D(int i1, int i2, int j1, int j2, int k1, int k2);

    int I1();
    int I2();
    int J1();
    int J2();
    int K1();
    int K2();

    int Nx();
    int Ny();
    int Nz();

    void SetI1(int i1);
    void SetI2(int i2);
    void SetJ1(int j1);
    void SetJ2(int j2);
    void SetK1(int k1);
    void SetK2(int k2);

    bool Contains(int i = -1, int j = -1, int k = -1);

    void InitVariables();

private:
    int i1, i2, j1, j2, k1, k2;
};

}}}}

#endif // BOX3D_H
