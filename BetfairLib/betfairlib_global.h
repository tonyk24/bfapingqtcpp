#ifndef BETFAIRLIB_GLOBAL_H
#define BETFAIRLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(BETFAIRLIB_LIBRARY)
#  define BETFAIRLIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define BETFAIRLIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // BETFAIRLIB_GLOBAL_H
