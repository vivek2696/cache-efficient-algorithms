#ifndef TRANSPOSE_H
#define TRANSPOSE_H

/** Tiled version of matrix transpose that tranposes a NxN matrix
 * A using <tile_size>x<tile_size> tiles and stores the result in B.
 * @param A: NxN matrix
 * @param B: NxN matrix, gets result of A^T
 * @param N: size of all square matrices
 * @param tile_size: size of square tiles used in tiling
 */
void transpose_tiled(double* A, double* B, int N, int tile_size);

#endif
