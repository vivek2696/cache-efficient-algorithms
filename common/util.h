#ifndef UTIL_H_
#define UTIL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#define IND(row,col,n) ((row)*n+(col))

double get_time();
void clear_cache();

bool prime_test(int n);

#ifdef __cplusplus
}
#endif

#endif
