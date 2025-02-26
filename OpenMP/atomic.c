#include <stdio.h>
#include <omp.h>

int main() {
    int commonVar = 0, count = 0;
    int nThreads = 1000;

    #pragma omp parallel num_threads(nThreads)
    {
        int tid = omp_get_thread_num();

        #pragma omp atomic
        commonVar += tid;

        #pragma omp atomic
        count++;
    }

    printf("Sum of threads from (1 .. %d) -> %d\n", nThreads - 1, commonVar);
    printf("Count -> %d\n", count);
}