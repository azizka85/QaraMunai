#ifndef EQLDIMSDATA_H
#define EQLDIMSDATA_H

#include <qvariant.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT EQLDIMSData
{
public:
    EQLDIMSData();

    QVariant NTEQUL() const;

    void SetNTEQUL(const QVariant &ntEQUL);

    void InitVariables();

private:
    QVariant ntEQUL;
};

}}}}

#endif // EQLDIMSDATA_H
