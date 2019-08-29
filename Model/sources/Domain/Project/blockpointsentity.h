#ifndef BLOCKPOINTS_H
#define BLOCKPOINTS_H

#include <qobject.h>
#include <qvariant.h>

#include <qmath.h>

#include <block.h>
#include <line3d.h>
#include <plane.h>
#include <linearvector.h>
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

    Q_INVOKABLE double tranX();
    Q_INVOKABLE double tranY();
    Q_INVOKABLE double tranZ();

    Q_INVOKABLE bool actnum();

    Q_INVOKABLE double soil();
    Q_INVOKABLE double swat();
    Q_INVOKABLE double sgas();

    Q_INVOKABLE double pressure();
    Q_INVOKABLE double pw();

    Q_INVOKABLE double poreVolume();
    Q_INVOKABLE double oilVolume();

    Block& nextBlock();

    Q_INVOKABLE void initVariables();

private:
    int cursor;
    Block current;

    void CalcBlockByBCG(ProjectData* project, int i, int j, int k);
    void CalcBlockByCPG(ProjectData* project, int i, int j, int k);
};

}}}}

#endif // BLOCKPOINTS_H
