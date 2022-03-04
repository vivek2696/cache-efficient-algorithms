#ifndef BASIC_H_
#define BASIC_H_

#ifdef __cplusplus
extern "C" {
#endif

// Basic matrix transpose of matrix A to matrix B (B = A^T)
void transpose_basic(double* const A, double* const B, const int N);

// Basic matrix multiplication function that multiplies two NxN matrices
// A and B and stores the resulting NxN matrix in C.
void multiply_basic(double* const A, double* const B, double* const C, const int N);

#ifdef __cplusplus
}
#endif

#endif
