#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "../common/util.h"

/**
 * Tiled version of matrix multiplication that multiplies two NxN matrices
 * A and B using <tile_size>x<tile_size> tiles.
 * @param A: NxN matrix
 * @param B: NxN matrix
 * @param C: NxN matrix, gets result of AxB
 * @param N: size of all square matrices
 * @param tile_size: size of square tiles used in tiling
 */
void multiply_tiled(double* const A, double* const B, double* const C, const int N, const int tile_size);

/**
 * Matrix multiplication function that multiplies two NxN matrices A and B_T, where
 * the second matrix B_T is the same as B from multiply_basic (see common/basic.h)
 * but has been transposed.
 * @param A: NxN matrix
 * @param B_T: NxN matrix, transpose of B in expression "AxB"
 * @param C: NxN matrix, gets result of AxB
 * @param N: size of all square matrices
 */
void multiply_transposed(double* const A, double* const B_T, double* const C, const int N);

#endif
