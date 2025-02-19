/*
Program that allocates two tasks and wraps them in a parallel pragma to enable 
parallel execution of the tasks.
The created tasks are executed by any thread that is available and have pulled the 
respective task from the thread pool.
*/

#include <stdio.h>
#include <stdlib.h>
#include <mach/mach.h>
#include <omp.h>

int main(int argc, char** argv) {
    int t, tnum;
    double time_spent = 0.0;

    // Reading CLI Arguments
    if (argc == 2) {
        tnum = atoi(argv[1]);
        omp_set_num_threads(tnum);
    }
    else {
        printf("Usage: %s tnum Number of Threads\n", argv[0]);
    }

    /*
    Stops the auto spawning of threads based on system load.
    This reinforces the system to utilise the specified number of threads in
    omp_set_num_threads()
    */
    omp_set_dynamic(0);  
    omp_set_num_threads(tnum);
    
    printf("Creating %d tasks each printing its id.\n", omp_get_num_threads());
    double start = omp_get_wtime();  // Start time of the parallel region.

    // Parallel Region
    #pragma omp parallel
    {
        #pragma omp single
            #pragma omp task
            {
                printf(
                    "Thread num: %2d is running on core %2d\n", 
                    omp_get_thread_num(),
                    mach_thread_self()
                );
            }
        #pragma omp single
            #pragma omp task
            {
                printf(
                    "Thread num: %2d is running on core %2d\n", 
                    omp_get_thread_num(),
                    mach_thread_self()
                );
            }
    }

    double stop_time = omp_get_wtime();
    time_spent = (double) (stop_time - start);

    printf("Execution Time: %lf sec\n", time_spent);

    return 0;
}