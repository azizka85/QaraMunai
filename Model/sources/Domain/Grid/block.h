#ifndef BLOCK_H
#define BLOCK_H

#include <qvariant.h>

#include <point3d.h>
#include <mathhelper.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Grid;
using namespace QaraMunai::Model::Helpers;

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Grid {

class MODELSHARED_EXPORT Block
{
public:
    Block();
    Block(int i, int j, int k, const Point3D& p1, const Point3D& p2, const Point3D& p3,
          const Point3D& p4, const Point3D& p5, const Point3D& p6, const Point3D& p7, const Point3D& p8);

    int I();
    int J();
    int K();

    Point3D& P1();
    Point3D& P2();
    Point3D& P3();
    Point3D& P4();
    Point3D& P5();
    Point3D& P6();
    Point3D& P7();
    Point3D& P8();

    double Volume();

    void SetI(const int& i);
    void SetJ(const int& j);
    void SetK(const int& k);

    void SetP1(const Point3D& p1);
    void SetP2(const Point3D& p2);
    void SetP3(const Point3D& p3);
    void SetP4(const Point3D& p4);
    void SetP5(const Point3D& p5);
    void SetP6(const Point3D& p6);
    void SetP7(const Point3D& p7);
    void SetP8(const Point3D& p8);

    void InitVariables();

    QVariantMap toMap();

private:
    int i, j, k;
    Point3D p1;
    Point3D p2;
    Point3D p3;
    Point3D p4;
    Point3D p5;
    Point3D p6;
    Point3D p7;
    Point3D p8;
};

}}}}

#endif // BLOCK_H
