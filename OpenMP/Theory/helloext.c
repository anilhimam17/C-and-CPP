#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char** argv) {
    if (argc == 2) {
        // Command Line arg for the number of threads to be run
        int tnum = atoi(argv[1]);

        // Declaring the Number of Threads
        omp_set_num_threads(tnum);
    }

    // Sequential Region
    printf("There are %d threads in the Sequential Region\n", omp_get_num_threads());
    printf("There is a maximum of %d threads in the System\n", omp_get_max_threads());
    printf("There are %d processors in the system\n", omp_get_num_procs());

    // Parallel Block
    #pragma omp parallel
    {
        // Checking the Thread ID of the current thread
        int tid = omp_get_thread_num();

        printf("There are %d threads in the parallel region\n", omp_get_num_threads());
        if (tid > 0) {
            printf("Hello, World I am the %dth thread in the parallel region\n", tid);
        }
    }

    return 0;
}