#ifndef ENDSCALEDATA_H
#define ENDSCALEDATA_H

#include <qvariant.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT ENDSCALEData
{
public:
    ENDSCALEData();

    QVariant Directional() const;
    QVariant Irreversible() const;
    QVariant NTENDP() const;
    QVariant MaxNodesEPD() const;

    void SetDirectional(const QVariant &directional);
    void SetIrreversible(const QVariant &irreversible);
    void SetNTENDP(const QVariant &ntENDP);
    void SetMaxNodesEPD(const QVariant &maxNodesEPD);

    void InitVariables();

private:
    QVariant directional;
    QVariant irreversible;
    QVariant ntENDP;
    QVariant maxNodesEPD;
};

}}}}

#endif // ENDSCALEDATA_H
