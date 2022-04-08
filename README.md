# cache-efficient-algorithm

Increasing sequential performance of basic matrix transpose and matrix multiply algorithm.

The goal of this repository is to show how memory access patterns can affect the performance of serial algorithms.

1. matrix transpose
    - The sample run of tranpose code with matrix (2048X2048):
    - ![tranpose_sample_run](https://github.com/Vivek2696/cache-efficient-algorithms/blob/master/screenshots/transpose.PNG)
2. matrix multiply
    - The sample run of multiply code with matrix (2048X2048):
    - ![multiply_sample_run](https://github.com/Vivek2696/cache-efficient-algorithms/blob/master/screenshots/multiply.PNG)
3. OpenMP parallel for loop demo:
    - ![openmp_sample_run](https://github.com/Vivek2696/cache-efficient-algorithms/blob/master/screenshots/openmp.PNG)

The performance increase can be seen from above sample runs. The tiled algorithm for both transpose and multiply is giving almost three fold performance. 

The code is ran in several different machine (Windows, Mac with M1 chip, and Linux) as well as tested. The sample run are from WSL (Windows Subsystem for Linux).  
