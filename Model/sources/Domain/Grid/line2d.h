#ifndef LINE2D_H
#define LINE2D_H

#include <point2d.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Grid {

class MODELSHARED_EXPORT Line2D
{
public:
    Line2D();
    Line2D(const Point2D &p1, const Point2D &p2);

    Point2D& P1();
    Point2D& P2();

    void SetP1(const Point2D& p1);
    void SetP2(const Point2D& p2);

    void InitVariables();

private:
    Point2D p1, p2;
};

}}}}

#endif // LINE2D_H
