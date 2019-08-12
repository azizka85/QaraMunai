#ifndef ROCKDATA_H
#define ROCKDATA_H

#include <qvariant.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT ROCKData
{
public:
    explicit ROCKData();

    QVariant PRef();
    QVariant CPP();

    void SetPRef(const QVariant& pRef);
    void SetCPP(const QVariant& cpp);

    void InitVariables();

private:
    QVariant pRef, cpp;
};

}}}}

#endif // ROCKDATA_H
