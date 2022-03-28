#ifndef OPENMP_H_
#define OPENMP_H_

/**
 * Simple for loop that does some computation over an array
 * to parallelize using OpenMP
 * @param A: an array of doubles of size n
 * @param n: size of array A
 */
void squares_parallel(double* A, int n);

/**
 * Simple for loop that does some computation over an array
 * to parallelize using OpenMP using prime_test() (see util.h)
 * @param A: an array of bools of size n
 * @param n: size of array A
 */
void primes_parallel(bool* A, int n);

#endif
