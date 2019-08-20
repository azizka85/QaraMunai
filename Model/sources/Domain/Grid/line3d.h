#ifndef LINE3D_H
#define LINE3D_H

#include <point3d.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Grid {

class MODELSHARED_EXPORT Line3D
{
public:
    Line3D();
    Line3D(const Point3D& p1, const Point3D& p2);

    Point3D& P1();
    Point3D& P2();

    void SetP1(const Point3D& p1);
    void SetP2(const Point3D& p2);

    void InitVariables();

private:
    Point3D p1, p2;
};

}}}}

#endif // LINE3D_H
