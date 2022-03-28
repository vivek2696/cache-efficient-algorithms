#include "../common/util.h"
#include "openmp.h"

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <random>
#include <omp.h>

#include <stdlib.h>

void squares_serial(double* A, int n) {
    for (int i = 0; i < n; i++) {
        A[i] = pow(A[i], 2);
    }
}

void primes_serial(bool* A, int n) {
    for (int i = 0; i < n; i++) {
        A[i] = prime_test(i+2);
    }
}

void foo_warmup(double* A, int n) {
    for (int i = 0; i < n; i++)
        A[i] = A[i] + 1;
}

void bar_warmup(bool* B, int n) {
    for (int i = 0; i < n; i++)
        B[i] = B[i] || (i%2 == 0);
}

int main(int argc, char** argv) {
    // TODO: Benchmark parallel loops
    if (argc < 2) {
        printf("Usage: ./openmp_runner array_size [num_trials=1]\n");
        return 0;
    }
    int num_trials = 1;
    int n_warmup = 5;
    int n = atoi(argv[1]);
    if (argc > 2) num_trials = atoi(argv[2]);

    double elapsed_time = 0.0;
    double* A = (double*)malloc(n*sizeof(double));
    printf("benchmarking squares_serial()...\n");
    for (int t = 0; t < num_trials; t++) {
        for (int i = 0; i < n; i++) A[i] = rand() % 100;
        // warmup
        for (int t = 0; t < n_warmup; t++) {
            foo_warmup(A, n);
        }

        double start = get_time();
        squares_serial(A, n);
        elapsed_time += get_time() - start;
    }
    printf("squares_serial() completed in %f seconds \n", elapsed_time/num_trials);

    elapsed_time = 0.0;
    printf("benchmarking squares_parallel() with %d threads...\n", omp_get_max_threads());
    for (int t = 0; t < num_trials; t++) {
        for (int i = 0; i < n; i++) A[i] = rand() % 100;
        // warmup
        for (int t = 0; t < n_warmup; t++) {
            foo_warmup(A, n);
        }

        double start = get_time();
        squares_parallel(A, n);
        elapsed_time += get_time() - start;
    }
    printf("squares_parallel() completed in %f seconds \n", elapsed_time/num_trials);
    free(A);

    bool* B = (bool*)malloc(n*sizeof(bool));
    elapsed_time = 0.0;
    printf("benchmarking primes_serial()...\n");
    for (int t = 0; t < num_trials; t++) {
        // warmup
        for (int t = 0; t < n_warmup; t++) {
            bar_warmup(B, n);
        }

        double start = get_time();
        primes_serial(B, n);
        elapsed_time += get_time() - start;
    }
    printf("primes_serial() completed in %f seconds \n", elapsed_time/num_trials);

    elapsed_time = 0.0;
    printf("benchmarking primes_parallel() with %d threads...\n", omp_get_max_threads());
    for (int t = 0; t < num_trials; t++) {
        //warmup
        for (int t = 0; t < n_warmup; t++) {
            bar_warmup(B, n);
        }

        double start = get_time();
        primes_parallel(B, n);
        elapsed_time += get_time() - start;
    }
    free(B);
    printf("primes_parallel() completed in %f seconds \n", elapsed_time/num_trials);

    return 0;
}
