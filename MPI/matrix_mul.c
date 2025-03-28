#include <stdio.h>
#include <stdlib.h>

int** alloc_matrix(int m, int n) {
    /*
    Args:
    - m: Dimension of rows present in the matrix
    - n: Dimension of columns present in the matrix
    
    Returns:
    - M: 2D array with values initialised to 0
    */

    // First Dimension
    int** M = (int**) malloc(m * sizeof(int*));

    // Second Dimension
    for (int i = 0; i < m; i++) {
        M[i] = (int*) malloc(n * sizeof(int));
    }

    return M;
}

int** matrix_transpose(int** M, int m, int n) {
    /*
    Args:
    - M: Input matrix for transpose
    - m: Dimension of rows present in the matrix
    - n: Dimension of columns present in the matrix

    Returns:
    - MT: Transpose of the input matrix
    */

    int** MT = alloc_matrix(m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            MT[j][i] = M[i][j];
        }
    }

    return MT;
}

int dot_product(int* v1, int* v2, int n) {
    /*
    Args:
    - v1, v2: Vectors from M1 and M2 matrices respectively
    - n: The length / dimension of each vector

    Returns:
    - dp: Dot product (scaled product) of two vectors v1 and v2
    */

    int dp = 0;
    for (int i = 0; i < n; i++) {
        dp += v1[i] + v2[i];
    }

    return dp;
}

int** matrix_product(int** M1, int** M2T, int m, int n) {
    /*
    Args:
    - M1: First Matrix
    - M2: Second Matrix
    - m: The number of rows present in the matrix
    - n: The number of columns present in the matrix

    Returns:
    - M3: The dot product of M1 and M2
    */

    // Loop control variables
    int i, j;

    // Allocating the memory locations for the result matrix M3
    int** M3 = alloc_matrix(m, m);

    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            M3[i][j] = dot_product(M1[i], M2T[j], n);
        }
    }
}
