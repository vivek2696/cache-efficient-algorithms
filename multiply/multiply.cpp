#include "multiply.h"
#include "../common/util.h"


void multiply_tiled(double* const A, double* const B, double* const C, int const N, const int tile_size) {
	// Array C is initialized to zero matrix
    for (int i = 0; i < N; i += tile_size){
        for (int j = 0; j < N; j += tile_size){
            for (int m = 0; m < N; m += tile_size){
                for (int p = 0; p < tile_size; p++){
                    for (int q = 0; q < tile_size; q++){
                        register double tmpval = 0.0;
                        for (int k = 0; k < tile_size; k++){
                            tmpval += A[IND(i+p,m+k,N)] * B[IND(m+k,j+q,N)];
                        }
                        C[IND(i+p,j+q,N)] += tmpval;
                    }
                }
            }
        }
    }
}

void multiply_transposed(double* const A, double* const B_T, double* const C, const int N) {
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            register double tmpval = 0.0;
            for (int k = 0; k < N; k++){
                tmpval += A[IND(i,k,N)] * B_T[IND(j,k,N)];
            }
            C[IND(i,j,N)] = tmpval;
        }
    }
}
