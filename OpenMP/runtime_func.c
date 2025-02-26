#include <stdio.h>
#include <omp.h>

int main() {
    int dyn = 0, n_threads = 5;

    // Overriding the number of threads allocated by default to set a custom number
    omp_set_dynamic(dyn);
    omp_set_num_threads(n_threads);

    // Sequential Region
    printf("Sequential Region\n");
    printf(
        "Default Threads Running: %d -> Num Threads Custom Set: %d -> Current Thread Num: %d",
        omp_get_dynamic(), omp_get_num_threads(), omp_get_thread_num()
    );

    // Parallel Region
    printf("\n\nParallel Region\n");
    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < 5; i++) {
            printf(
                "Default Threads Running: %d -> Num Threads Custom Set: %d -> Current Thread Num: %d\n",
                omp_get_dynamic(), omp_get_num_threads(), omp_get_thread_num()
            );
        }
    }
}