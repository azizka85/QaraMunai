#ifndef SEGMENT_H
#define SEGMENT_H

#include <qglobal.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Grid {

class MODELSHARED_EXPORT Segment
{
public:
    Segment(double startPoint, double endPoint);

    double StartPoint();
    double EndPoint();

    double Length();

    bool IsIntersect(Segment seg);
    bool IsIntersect(double x1, double x2);

    Segment GetUnionWith(Segment seg);

private:
    double startPoint, endPoint;
};

}}}}

#endif // SEGMENT_H
