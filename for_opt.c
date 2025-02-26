#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define LEN 4

int main() {
    int i = 0;
    int a[LEN], b[LEN], c[LEN];

    // Populating the Arrays
    for (i = 0; i < LEN; i++) {
        a[i] = i;
        b[i] = LEN - i;
    }

    // Parallel Region
    printf("Beginning the Parallel Region....\n");
    #pragma omp parallel
    {
        #pragma omp for
        for (i = 0; i < LEN; i++) {
            c[i] = a[i] + b[i];
            int tid = omp_get_thread_num();
            
            if (tid == 0) {
                printf(
                    "c[%d] = a[%d] + b[%d] -> %d (Executed by Main %d of %d)\n",
                    i, i, i, c[i], tid, omp_get_max_threads()
                );
            }
            else {
                printf(
                    "c[%d] = a[%d] + b[%d] -> %d (Executed by Child %d of %d)\n",
                    i, i, i, c[i], tid, omp_get_max_threads()
                );
            }
        }
    }
    printf("Exiting Parallel Region....\n\n");

    // Sequential Region
    printf("Beginning the Sequential Region .....\n");
    #pragma omp for
    for (i = 0; i < LEN; i++) {
        c[i] = a[i] + b[i];
        int tid = omp_get_thread_num();

        if (tid == 0) {
            printf(
                "c[%d] = a[%d] + b[%d] -> %d (Executed by Main %d of %d)\n",
                i, i, i, c[i], tid, omp_get_max_threads()
            );
        }
        else {
            printf(
                "c[%d] = a[%d] + b[%d] -> %d (Executed by Child %d of %d)\n",
                i, i, i, c[i], tid, omp_get_max_threads()
            );
        }
    }
    printf("Completed Program....\n");
    
    return 0;
}