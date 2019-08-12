#ifndef ENDSCALEENTITY_H
#define ENDSCALEENTITY_H

#include <qobject.h>
#include <qvariant.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

class MODELSHARED_EXPORT ENDSCALEEntity : public QObject
{
    Q_OBJECT

    Q_ENUMS(DirectionalType)
    Q_ENUMS(IrreversibleType)

    Q_PROPERTY(QVariant directional READ Directional WRITE SetDirectional NOTIFY DirectionalChanged)
    Q_PROPERTY(QVariant irreversible READ Irreversible WRITE SetIrreversible NOTIFY IrreversibleChanged)
    Q_PROPERTY(QVariant ntENDP READ NTENDP WRITE SetNTENDP NOTIFY NTENDPChanged)
    Q_PROPERTY(QVariant maxNodesEPD READ MaxNodesEPD WRITE SetMaxNodesEPD NOTIFY MaxNodesEPDChanged)


public:
    explicit ENDSCALEEntity(QObject *parent = nullptr);

    enum DirectionalType { NODIR = 0, DIRECT = 1 };
    enum IrreversibleType { REVERS = 0, IRREVERS = 1 };

    QVariant Directional() const;
    QVariant Irreversible() const;
    QVariant NTENDP() const;
    QVariant MaxNodesEPD() const;    

    void SetDirectional(const QVariant &directional);
    void SetIrreversible(const QVariant &irreversible);
    void SetNTENDP(const QVariant &ntENDP);
    void SetMaxNodesEPD(const QVariant &maxNodesEPD);

    Q_INVOKABLE void initVariables();

signals:
    void DirectionalChanged();
    void IrreversibleChanged();
    void NTENDPChanged();
    void MaxNodesEPDChanged();
};

}}}}

#endif // ENDSCALEENTITY_H
