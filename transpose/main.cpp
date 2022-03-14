#include "transpose.h"
#include "basic.h"
#include "util.h"

#include <random>
#include <cassert>

#include "naivelinalg.h"

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
    
}