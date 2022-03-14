#include <stdlib.h>
#include <math.h>

#include "naivelinalg.h"

bool matrix_create(matrix *target, const int N, const int M){
    target->N = N;
    target->M = M;

    if(N==0 | M==0){
        target->data = NULL;
    }

    // the matrix need to be alligned on a cache line boundry
    int memalign_result = posix_memalign(
        (void**)(&(target->data)),
        NAIVE_LINALG_ALIGNMENT,
        sizeof(matrix_data_t)*N*M
    );

    if(0 != memalign_result || NULL == memalign_result){
        target->data = NULL;
        target->N = 0;
        target->M = 0;
        return false;
    }

    target->N = N;
    target->M = M;
    return true;
}

bool matrix_destroy(matrix *target){
    free(target->data);
    target->data = NULL;
    target->N = 0;
    target->M = 0;
    return true;
}

bool copy_matrix(matrix *target, const matrix * source){
    if(NULL == target || NULL == source){
        return false;
    }
    if(NULL == target->data || NULL == source->data){
        return false;
    }
    if(target->M != source->M || target->N != source->N){
        return false;
    }

    target->N = source->N;
    target->M = source->M;

    for(int i = 0; i < source->N; i++){
        for(int j = 0; j < source->M; j++){
            MATPTR_ELEMENT(target, i, j) = MATPTR_ELEMENT(source, i, j);
        }
    }
    return true;
}

bool matrix_equality(const matrix *lhs, const matrix *rhs, const double epsilon){
    if(lhs->N != rhs->N || lhs->M != lhs->M){
        return false;
    }
    int END = lhs->N * lhs->M; //Scan as 1D array
    matrix_data_t *ldata, *rdata;
    ldata = lhs->data;
    rdata = rhs->data;
    for(int i = 0; i < END; i++){
        if( fabs(ldata[i] - rdata[i]) > epsilon) { return false; }
    }
    return true; //Success
}
