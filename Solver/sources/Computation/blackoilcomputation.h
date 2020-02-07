#ifndef BLACKOILCOMPUTATION_H
#define BLACKOILCOMPUTATION_H

#include <qobject.h>

#include <qelapsedtimer.h>

#include <icomputation.h>

#include <solver_global.h>

namespace QaraMunai {
namespace Solver {
namespace Computation {

class SOLVER_EXPORT BlackOilComputation : public IComputation
{
    Q_OBJECT

public:
    explicit BlackOilComputation(QObject *parent = nullptr);

    Q_INVOKABLE qint64 compute(ProjectData *projectData);

    Q_INVOKABLE void initVariables();

    Q_INVOKABLE void initVariablesForTime();

private:
    double totalProdOil, totalProdWat, totalProdDGas, totalProdFGas;
    double totalInjWat, totalInjGas;

    double prodOil, prodWat, prodDGas, prodFGas;
    double injWat, injGas;

    double pavr;
    double cWIP, cOIP, cFGIP, cDGIP;
};

}}}

#endif // BLACKOILCOMPUTATION_H
