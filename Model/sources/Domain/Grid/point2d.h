#ifndef POINT2D_H
#define POINT2D_H

#include <qvariant.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Grid {

class MODELSHARED_EXPORT Point2D
{
public:
    Point2D();
    Point2D(double x, double y);

    double X();
    double Y();

    void SetX(const double &x);
    void SetY(const double &y);

    void InitVariables();

    QVariantMap toMap();

private:
    double x, y;
};

}}}}

#endif // POINT2D_H
