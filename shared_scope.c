#include <stdio.h>
#include <omp.h>

int main() {
    int i, commonVar = 4, nSave[4];
    omp_set_num_threads(4);
    
    /*
    Parallel Region
    Enforcing sharing of the variable accross each of the threads
    */
    #pragma omp parallel firstprivate(commonVar)
    {
        #pragma omp for
        for (i = 0; i < 4; i++) {
            int tid = omp_get_thread_num();
            commonVar--;
            nSave[tid] = commonVar;
        }
    }

    // Seqential Region
    for (i = 0; i < 4; i++) {
        printf("Data on thread: %d -> %d\n", i, nSave[i]);
    }
}