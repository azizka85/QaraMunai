#ifndef BLOCKPOINTS_H
#define BLOCKPOINTS_H

#include <qobject.h>
#include <qvariant.h>

#include <block.h>
#include <linearvector.h>
#include <linearmatrix2d.h>

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

    Block& nextBlock();

    Q_INVOKABLE void initVariables();

private:
    int cursor;
    Block current;

    void CalcBlockByBCG(LinearMatrix2D &tops, int i, int j, int k, double dx, double dy, double dz);
    void CalcBlockByCPG(LinearVector &coord, LinearVector &zcorn, int i, int j, int k, double dx, double dy, double dz);
};

}}}}

#endif // BLOCKPOINTS_H
