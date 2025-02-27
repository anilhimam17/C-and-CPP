#include <stdio.h>
#include <unistd.h>
#include <omp.h>

int main() {
    double time_spent = 0.0;

    // Force setting the number of threads to be run
    omp_set_dynamic(0);
    omp_set_num_threads(10);

    // Sequential Region
    printf("Profiling time using omp_get_wtime() in the Sequential Region\n");
    double start = omp_get_wtime();

    // Sleep times
    usleep(1000000);
    usleep(1000000);
    usleep(1000000);
    usleep(1000000);
    usleep(1000000);

    double stop = omp_get_wtime();
    time_spent = (double) (stop - start);
    printf("Sleep time calculated in the Sequential Region: %.3fs\n", time_spent);

    // Parallel Region
    start = omp_get_wtime();
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            usleep(1000000);
        }
        #pragma omp section
        {
            usleep(1000000);
        }
        #pragma omp section
        {
            usleep(1000000);
        }
        #pragma omp section
        {
            usleep(1000000);
        }
        #pragma omp section
        {
            usleep(1000000);
        }
    }
    stop = omp_get_wtime();
    time_spent = (double) (stop - start);
    printf("Sleep time calculated in the Parallel Region: %.3fs\n", time_spent);

    return 0;
}
