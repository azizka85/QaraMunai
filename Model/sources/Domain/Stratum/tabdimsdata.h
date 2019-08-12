#ifndef TABDIMSDATA_H
#define TABDIMSDATA_H

#include <qvariant.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT TABDIMSData
{
public:
    TABDIMSData();

    QVariant NTSFUN() const;
    QVariant NTPVT() const;
    QVariant NSSFUN() const;

    void SetNTSFUN(const QVariant &ntSFUN);
    void SetNTPVT(const QVariant &ntPVT);
    void SetNSSFUN(const QVariant &nsSFUN);

    void InitVariables();

private:
    QVariant ntSFUN, ntPVT, nsSFUN;
};

}}}}

#endif // TABDIMSDATA_H
