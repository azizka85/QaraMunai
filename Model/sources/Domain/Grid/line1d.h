#ifndef LINE1D_H
#define LINE1D_H

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Grid {

class MODELSHARED_EXPORT Line1D
{
public:
    Line1D();
    Line1D(const double &x1, const double &x2);

    double X1();
    double X2();

    void SetX1(const double& x1);
    void SetX2(const double& x2);

    void InitVariables();

private:
    double x1, x2;
};

}}}}

#endif // LINE1D_H
