#include "blackoilcomputation.h"

namespace QaraMunai {
namespace Solver {
namespace Computation {

BlackOilComputation::BlackOilComputation(QObject *parent) : IComputation(parent)
{
    initVariables();
}

qint64 BlackOilComputation::compute(ProjectData *projectData)
{
    QElapsedTimer timer;

    timer.start();



    return timer.elapsed();
}

void BlackOilComputation::initVariables()
{
    // Total for all time
    totalProdOil = 0;
    totalProdWat = 0;
    totalProdDGas = 0;
    totalProdFGas = 0;

    totalInjWat = 0;
    totalInjGas = 0;

    initVariablesForTime();
}

void BlackOilComputation::initVariablesForTime()
{
    // For current time
    prodOil = 0;
    prodWat = 0;
    prodDGas = 0;
    prodFGas = 0;

    injWat = 0;
    injGas = 0;

    pavr = 0;
    cWIP = 0;
    cOIP = 0;
    cFGIP = 0;
    cDGIP = 0;
}


}}}
