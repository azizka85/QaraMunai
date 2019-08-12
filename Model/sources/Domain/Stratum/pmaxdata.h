#ifndef PMAXDATA_H
#define PMAXDATA_H

#include <qvariant.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT PMAXData
{
public:
    PMAXData();

    QVariant PMax();
    QVariant PMaxComp();
    QVariant PMinComp();
    QVariant NumNodes();

    void SetPMax(const QVariant& pMax);
    void SetPMaxComp(const QVariant& pMaxComp);
    void SetPMinComp(const QVariant& pMinComp);
    void SetNumNodes(const QVariant& numNodes);

    void InitVariables();

private:
    QVariant numNodes, pMaxComp, pMinComp, pMax;
};

}}}}

#endif // PMAXDATA_H
