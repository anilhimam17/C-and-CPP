/*
Program to find the cores each thread is running on.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mach/mach.h>
#include <omp.h>

int main(int argc, char** argv) {
    // Retrieving the Number of threads in CLI
    if (argc == 2) {
        int tnum = atoi(argv[1]);
        omp_set_num_threads(tnum);
    }

    // Character array to store the names of the cores
    char host[80];

    if (gethostname(host, 80) != 0) {  // Returns 0 if host name acq. success
        host[0] = '\0';
    }
    
    printf(
        "Using %d out of %d threads in Sequential Region\n", 
        omp_get_num_threads(),
        omp_get_max_threads()
    );
    printf(
        "There are %d processors in the system\n",
        omp_get_num_procs()
    );

    // Parallel Block
    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        if (tid == 0) {  // If executing master thread
            printf("There are %d threads in the Parallel Region\n", omp_get_num_threads());
        }
        mach_port_t core = mach_thread_self();
        printf("Thread no: %2d is running on machine %s on core %2d \n", tid, host, core);
    }

    return 0;
}