#ifndef SRC_GLOBAL_H
#define SRC_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(GRIDB_LIBRARY)
#  define SRCSHARED_EXPORT Q_DECL_EXPORT
#else
#  define SRCSHARED_EXPORT Q_DECL_IMPORT
#endif

/**
 * Repeater a variables x and y from fromX/fromY to toX/toY
 */
#define FORXY(varX, fromX, toX, varY, fromY, toY) FOR((varY), (fromY), (toY)) FOR((varX), (fromX), (toX))
/**
 * Repeat n times for variables var from expression to expression
 */
#define FOR(var, from, to) for(int var = (from); ((from)<=(to)); (var++))


#endif // SRC_GLOBAL_H
