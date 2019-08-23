#ifndef BLOCKPOINTS_H
#define BLOCKPOINTS_H

#include <qobject.h>
#include <qvariant.h>

#include <block.h>
#include <line3d.h>
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
    Q_INVOKABLE double depth();
    Q_INVOKABLE double porosity();
    Q_INVOKABLE double ntg();
    Q_INVOKABLE int pvtNUM();
    Q_INVOKABLE double soil();
    Q_INVOKABLE double swat();
    Q_INVOKABLE double sgas();
    Q_INVOKABLE double pressure();
    Q_INVOKABLE double pw();
    Q_INVOKABLE double rs();
    Q_INVOKABLE double pBUB();
    Q_INVOKABLE double poreVolume();
    Q_INVOKABLE double oilVolume();

    Block& nextBlock();

    Q_INVOKABLE void initVariables();

private:
    int cursor;
    Block current;
    bool pointOrderStandard;

    void CalcBlockByBCG(ProjectData* project);
    void CalcBlockByCPG(ProjectData* project);
};

}}}}

#endif // BLOCKPOINTS_H
