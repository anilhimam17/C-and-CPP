#include <omp.h>
#include <stdio.h>

int main() {
    omp_set_num_threads(16);

    #pragma omp parallel
    {
        printf("Bye, World\n");
    }

    return 0;
}