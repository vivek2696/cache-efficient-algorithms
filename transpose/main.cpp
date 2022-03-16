#include "./transpose.h"
#include "../common/basic.h"
#include "../common/util.h"

#include <random>
#include <cassert>

#include "../common/naivelinalg.h"

double timedTransposeBasic(double *A, double *B, int N){
    clear_cache();

    double start = get_time();
    transpose_basic(A, B, N);
    return get_time() - start;
}

double timedTransposeTiled(double *A, double *B, int N, int tile_size){
    clear_cache();

    double start = get_time();
    transpose_tiled(A, B, N, tile_size);
    return get_time() - start;
}

int main(int argc, char** argv){
    // benchmark the transpose performance.
    if(argc < 3){
        printf("Usage: ./transpose_runner array_size tile_size [num_trails]\n");
        return 0;
    }
    int num_trials = 1;
    int N = atoi(argv[1]);
    int tile_size = atoi(argv[2]);
    if(argc > 3) num_trials = atoi(argv[3]);

    matrix A, B;
    matrix_create(&A,N,N);
    matrix_create(&B,N,N);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            A.data[i*N + j] = rand() * 1000;
        }
    }
    
    double total_elapsed = 0.0;
    for (int i = 0; i < num_trials; i ++){
        total_elapsed += timedTransposeBasic(A.data, B.data, N);
    }
    printf("Average execution time of transpose_basic(): %f\n", total_elapsed / num_trials);

    total_elapsed = 0.0;
    for(int i = 0; i < num_trials; i++){
        total_elapsed += timedTransposeTiled(A.data, B.data, N, tile_size);
    }
    printf("Average execution time of transpose_tiled(): %f\n", total_elapsed / num_trials);

    matrix_destroy(&A);
    matrix_destroy(&B);
    return 0;

}