#ifndef SWFNDATA_H
#define SWFNDATA_H

#include <qvariant.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT SWFNData
{
public:
    SWFNData();

    double SW();

    QVariant KrW();
    QVariant Pc();

    void SetSW(const double &sw);

    void SetKrW(const QVariant &krw);
    void SetPc(const QVariant &pc);

    void InitVariables();

private:
    double sw;
    QVariant krw, pc;
};

}}}}

#endif // SWFNDATA_H
