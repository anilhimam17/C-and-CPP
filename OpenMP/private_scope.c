#include <stdio.h>
#include <omp.h>

int main() {
    int i, nPrivate = 4, nSave[4];
    omp_set_num_threads(4);

    /*
    Parallel Region
    Each thread should recieve a private copy of the variable with value = 4
    */
    #pragma omp parallel private(nPrivate) 
    {
        // Running all the threads in parallel with their own private copies and storing the decremented values
        #pragma omp for
        for (i = 0; i < 4; i++) {
            int tid = omp_get_thread_num();
            nPrivate--;
            nSave[tid] = nPrivate;
        }
    }

    // Viewing the Values from each thread
    for (i = 0; i < 4; i++) {
        printf("Data on thread: %d -> %d\n", i, nSave[i]);
    }
    return 0;
}