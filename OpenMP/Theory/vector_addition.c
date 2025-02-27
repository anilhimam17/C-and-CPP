#include <stdio.h>
#include <omp.h>

int main(int argc, char** argv) {
    int a[5] = {1, 3, 5, 7, 9};
    int b[5] = {2, 4, 6, 8, 10};
    int c[5] = {};
    int i = 0;  // Loop Variable to synchronise accross all threads

    printf("Total number of threads in Sequential Region is: %d\n", omp_get_num_threads());
    printf("Now creating 3 threads ...\n");

    // Parallel Block
    #pragma omp parallel for num_threads(3)
    for (i = 0; i < 5; i++) {
        int tid = omp_get_thread_num();
        c[i] = a[i] + b[i];

        if (tid == 0) {  // Executed Addition in Master Thread
            printf(
                "c[%d] = a[%d] + b[%d] -> %d (Main Thread %d of %d)\n",
                i, i, i, c[i], tid, omp_get_num_threads()
            );
        }
        else {  // Executed Addition in Slave Thread
            printf(
                "c[%d] = a[%d] + b[%d] -> %d (Slave Thread %d of %d)\n",
                i, i, i, c[i], tid, omp_get_num_threads()
            );
        }
    }

    // Joining all the threads back to the master in the Sequential Region
    printf("\nJoin, total number of threads: %d\n\n", omp_get_num_threads());

    printf("Total number of threads in Sequential Region is: %d\n", omp_get_num_threads());
    printf("Now creating 5 threads ...\n");

    // Parallel Block
    #pragma omp parallel for num_threads(5)
    for (i = 0; i < 5; i++) {
        int tid = omp_get_thread_num();
        c[i] = a[i] + b[i];

        if (tid == 0) {  // Executed Addition in Master Thread
            printf(
                "c[%d] = a[%d] + b[%d] -> %d (Main Thread %d of %d)\n",
                i, i, i, c[i], tid, omp_get_num_threads()
            );
        }
        else {  // Executed Addition in Slave Thread
            printf(
                "c[%d] = a[%d] + b[%d] -> %d (Slave Thread %d of %d)\n",
                i, i, i, c[i], tid, omp_get_num_threads()
            );
        }
    }

    // Joining all the threads back to the master in the Sequential Region
    printf("\nJoin, total number of threads: %d\n\n", omp_get_num_threads());

    printf("Total number of threads in Sequential Region is: %d\n", omp_get_num_threads());
    printf("Now creating 2 threads ...\n");

    // Parallel Block
    #pragma omp parallel for num_threads(2)
    for (i = 0; i < 5; i++) {
        int tid = omp_get_thread_num();
        c[i] = a[i] + b[i];

        if (tid == 0) {  // Executed Addition in Master Thread
            printf(
                "c[%d] = a[%d] + b[%d] -> %d (Main Thread %d of %d)\n",
                i, i, i, c[i], tid, omp_get_num_threads()
            );
        }
        else {  // Executed Addition in Slave Thread
            printf(
                "c[%d] = a[%d] + b[%d] -> %d (Slave Thread %d of %d)\n",
                i, i, i, c[i], tid, omp_get_num_threads()
            );
        }
    }
    
    // Joining all the threads back to the master in the Sequential Region
    printf("\nJoin, total number of threads: %d\n\n", omp_get_num_threads());

    return 0;
}