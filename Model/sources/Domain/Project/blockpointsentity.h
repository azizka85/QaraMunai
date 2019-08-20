#ifndef BLOCKPOINTS_H
#define BLOCKPOINTS_H

#include <qobject.h>
#include <qvariant.h>

#include <block.h>
#include <line3d.h>
#include <linearvector.h>
#include <linearmatrix2d.h>
#include <mathhelper.h>
#include <unithelper.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Grid;
using namespace QaraMunai::Model::Utils;

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

class MODELSHARED_EXPORT BlockPointsEntity : public QObject
{
    Q_OBJECT

public:
    explicit BlockPointsEntity(QObject *parent = nullptr);

    Q_INVOKABLE bool hasNext();
    Q_INVOKABLE QVariantMap next();
    Q_INVOKABLE void toFront();
    Q_INVOKABLE double cellVolume();
    Q_INVOKABLE double depth();
    Q_INVOKABLE double porosity();
    Q_INVOKABLE double ntg();
    Q_INVOKABLE double poreVolume();
    Q_INVOKABLE double oilVolume();

    Block& nextBlock();

    Q_INVOKABLE void initVariables();

private:
    int cursor;
    Block current;
    bool pointOrderStandard;

    void CalcBlockByBCG(LinearMatrix2D &tops, int i, int j, int k, double dx, double dy, double dz);

    bool CheckPointOrderStandard(LinearVector &coord, LinearVector &zcorn, int nx, int ny);
    void CalcCoordLine(LinearVector &coord, int i, int j, int nx, Line3D& coordLine);
    void CalcBlockDepths(LinearVector &zcorn, int i, int j, int k, int nx, int ny,
                         double &d1, double &d2, double &d3, double &d4, double &d5, double &d6, double &d7, double &d8);
    void CalcBlockByCPG(LinearVector &coord, LinearVector &zcorn, int i, int j, int k, int nx, int ny);
};

}}}}

#endif // BLOCKPOINTS_H
