#include <stdio.h>
#include <omp.h>

int main() {
    int a[5] = {0, 0, 0, 0, 0};
    
    // Parallel Region
    #pragma omp parallel num_threads(4)
    {
        // Each thread runs once and update upto index 4
        int tid = omp_get_thread_num();
        a[tid] = tid;
        printf("Thread: %d on a[%d] -> %d\n", tid, tid, tid);

        // Place a barrier to update the 5 index of the only after all the elements are filled
        #pragma omp barrier
        a[tid] += tid;
        printf("Thread Barrier - %d: a[%d] -> %d\n", tid, tid, a[tid]);
    }

    printf("\n\nTraversing the Array:\n");
    for (int i = 0; i < 5; i++) {
        printf("Element: %d -> %d\n", i, a[i]);
    }
}