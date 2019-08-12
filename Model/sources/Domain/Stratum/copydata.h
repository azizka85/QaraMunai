#ifndef COPYDATA_H
#define COPYDATA_H

#include <qstring.h>

#include <box3d.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Grid;

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT COPYData
{
public:
    COPYData();

    QString SOURCE();
    QString DESTINATION();
    Box3D& Box();

    void SetSOURCE(const QString& source);
    void SetDESTINATION(const QString& destination);

    void InitVariables();

private:
    QString source, destination;
    Box3D box;
};

}}}}

#endif // COPYDATA_H
