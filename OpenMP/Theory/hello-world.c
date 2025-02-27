#include <omp.h>
#include <stdio.h>

int main() {
    omp_set_num_threads(16);

    // Parallel Execution Block
    #pragma omp parallel 
    {
        printf("Hello, World\n");
    }

    return 0;
}
