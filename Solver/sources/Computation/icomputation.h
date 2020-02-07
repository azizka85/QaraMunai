#ifndef ICOMPUTATION_H
#define ICOMPUTATION_H

#include <qobject.h>

#include <projectdata.h>

#include <solver_global.h>

using namespace QaraMunai::Model::Domain::Project;

namespace QaraMunai {
namespace Solver {
namespace Computation {

class SOLVER_EXPORT IComputation : public QObject
{
    Q_OBJECT

public:
    explicit IComputation(QObject *parent = nullptr) : QObject(parent) { }
    virtual ~IComputation() { }

    virtual qint64 compute(ProjectData *projectData) = 0;
};


}}}

#endif // ICOMPUTATION_H
