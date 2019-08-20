#ifndef MATHHELPER_H
#define MATHHELPER_H

#include <point3d.h>
#include <line3d.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Grid;

namespace QaraMunai {
namespace Model {
namespace Helpers {

class MODELSHARED_EXPORT MathHelper
{
public:
    static void IntersectZPlane(Line3D& line, double& z, Point3D& point);
    static double ParallelepipedVolume(Point3D& v1, Point3D& v2, Point3D& v3);
};

}}}

#endif // MATHHELPER_H
