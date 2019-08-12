#ifndef SOF3DATA_H
#define SOF3DATA_H

#include <qvariant.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT SOF3Data
{
public:
    SOF3Data();

    double SO();

    QVariant KrOW();
    QVariant KrOGWC();

    void SetSO(const double& so);
    void SetKrOW(const QVariant& krow);
    void SetKrOGWC(const QVariant& krogwc);

    void InitVariables();

private:
    double so;
    QVariant krow, krogwc;
};

}}}}

#endif // SOF3DATA_H
