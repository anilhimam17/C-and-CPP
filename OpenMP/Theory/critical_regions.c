#include <stdio.h>
#include <omp.h>

int main() {
    /*
    - To perform parallel thread calculations on a shared variable without
    read-write errors we utilise critical regions.
    - This should generate an output similar to the reductions
    */
    int i, sum = 0;
    omp_set_num_threads(10);

    #pragma omp parallel num_threads(10)
    {
        #pragma omp for
        for (i = 1; i <= 50; i++) {
            int tid = omp_get_thread_num();

            // Criticial Region: Must be executed only by a single thread at a time
            #pragma omp critical
            {
                sum += i;
                printf("Data on Thread: %d is: %d\n", tid, sum);
            }
        }
    }
    printf("Sum on all the threads is: %d\n", sum);
}