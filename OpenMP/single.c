#include <stdio.h>
#include <omp.h>

int main() {
    // Parallel Region
    #pragma omp parallel num_threads(4)
    {
        #pragma omp single
        {
            int i = omp_get_thread_num();
            printf(
                "Task executed by single thread: %d of %d\n",
                i, omp_get_max_threads()
            );
        }
        {
            int j = omp_get_thread_num();
            printf(
                "Task executed by parallel thread: %d of %d\n",
                j, omp_get_max_threads()
            );
        }
    }
}