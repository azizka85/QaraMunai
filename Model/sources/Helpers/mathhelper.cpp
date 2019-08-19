#include "mathhelper.h"

namespace QaraMunai {
namespace Model {
namespace Helpers {

double MathHelper::ParallelepipedVolume(Point3D &v1, Point3D &v2, Point3D &v3)
{
    return qAbs(v1.X() * v2.Y() * v3.Z() + v2.X() * v3.Y() * v1.Z() + v1.Y() * v2.Z() * v3.X() - v1.Z() * v2.Y() * v3.X() - v3.Y() * v2.Z() * v1.X() - v1.Y() * v2.X() * v3.Z());
}

}}}
