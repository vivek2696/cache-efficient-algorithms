#include "basic.h"
#include "util.h"

void transpose_basic(double* const A, double* const B, const int N) {
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            B[IND(i,j,N)] = A[IND(j,i,N)];
        }
    }
}

void multiply_basic(double* const A, double* const B, double* const C, const int N) {
    //TODO: basic multiply algo
}
