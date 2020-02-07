#ifndef SOLVER_GLOBAL_H
#define SOLVER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SOLVER_LIBRARY)
#  define SOLVER_EXPORT Q_DECL_EXPORT
#else
#  define SOLVER_EXPORT Q_DECL_IMPORT
#endif

#endif // SOLVER_GLOBAL_H
