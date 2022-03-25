#include "multiply.h"
#include "../common/util.h"
#include "../common/basic.h"
#include "../common/naivelinalg.h"

#include <random>
#include <cassert>
#include <cmath>

double timeMultiplyTiled(double* A, double* B, double* C, int N, int tile_size) {
    clear_cache();

    double start = get_time();
    multiply_tiled(A, B, C, N, tile_size);
    return get_time() - start;
}

double timeMultiplyTransposed(double* A, double* B_T, double* C, int N) {
    clear_cache();

    double start = get_time();
    multiply_transposed(A, B_T, C, N);
    return get_time() - start;
}

int main(int argc, char** argv){
    if (argc < 3){
        printf("Usage: ./multiply_runner array_size tile_size [num_trials]\n");
        return 0;
    }

    int num_trials = 1;
    int N = atoi(argv[1]);
    int tile_size = atoi(argv[2]);
    if (argc > 3) num_trials = atoi(argv[3]);

    matrix A, B, C, B_T;
    matrix_create(&A,N,N);
    matrix_create(&B,N,N);
    matrix_create(&C,N,N);
    matrix_create(&B_T,N,N);

    for(int i = 0; i < N*N; i++){
        A.data[i] = rand() % 1000;
        B.data[i] = rand() % 1000;
    }

    //benchmark basic multiply
    double total_elapsed = 0.0;
    for (int t = 0; t < num_trials; t++) {
        clear_cache();

        double start = get_time();
        multiply_basic(A.data, B.data, C.data, N);
        total_elapsed += get_time() - start;
    }
    printf("Average execution time of multiply_basic(): %f\n", total_elapsed/num_trials);

    total_elapsed = 0.0;
    for (int t = 0; t < num_trials; t++) {
        total_elapsed += timeMultiplyTiled(A.data, B.data, C.data, N, tile_size);
    }
    printf("Average execution time of multiply_tiled(): %f\n", total_elapsed/num_trials);

    transpose_basic(B.data, B_T.data, N);

    total_elapsed = 0.0;
    for (int t = 0; t < num_trials; t++) {
        total_elapsed += timeMultiplyTransposed(A.data, B_T.data, C.data, N);
    }
    printf("Average execution time of multiply_transposed(): %f\n", total_elapsed/num_trials);

    matrix_destroy(&A);
    matrix_destroy(&B);
    matrix_destroy(&B_T);
    matrix_destroy(&C);
    return 0;
}
