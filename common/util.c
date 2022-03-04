#include "util.h"

#include <assert.h>
#include <stdlib.h>
#include "sys/time.h"

double get_time() {
    struct timeval tv;
    gettimeofday(&tv, 0);
    return (tv.tv_sec*1.0 + tv.tv_usec*1e-6);
}

void clear_cache() {
    double *A = (double *)malloc(4096*4096*sizeof(double));
    assert (A != NULL);

    for(int i=0;i<4096*4096;i++)
        A[i] = 2*i;

    double sum = 0;

    for(int i=0;i<4096*4096;i++)
        sum += A[i];

    free(A);
}

bool prime_test(int n) {
    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
