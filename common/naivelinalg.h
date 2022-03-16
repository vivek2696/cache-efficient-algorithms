#ifndef NAIVELINALG_H
#define NAIVELINALG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

//TODO: automatically detect the cache line size of the target machine
#define NAIVE_LINALG_ALIGNMENT 256

typedef double matrix_data_t; //Float = 4bytes; double = 8bytes

typedef struct {
    matrix_data_t *data;
    int N;
    int M;
} matrix;

#define ARRAY_ELEMENT(dptr, nRows, mCols, i, j) dptr[i*mCols + j]
#define MATPTR_ELEMENT(matptr, i , j) ARRAY_ELEMENT(matptr->data, matptr->N, matptr->M, i, j)
#define MATRIX_ELEMENT(matr, i , j) ARRAY_ELEMENT(matr.data, matr.N, matr.M, i, j)

bool matrix_create(matrix *target, const int N, const int M);
bool matrix_destroy(matrix *target);
bool copy_matrix(matrix *target, const matrix *source);

bool matrix_equality(const matrix *lhs, const matrix *rhs, const double epsilon);


#ifdef __cplusplus
}
#endif

#endif