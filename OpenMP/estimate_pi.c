#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

void sequential_estimate(long int nSteps);
void parallel_estimate(long int nSteps);

int main() {
    long int grid_steps[] = {10000, 100000, 1000000, 10000000, 100000000, 1000000000};

    printf("Sequential Estimate:\n");
    for (int i = 0; i < 6; i++) {
        printf("nSteps = %ld\n", grid_steps[i]);
        sequential_estimate(grid_steps[i]);
    }

    printf("\n\nParallel Estimate:\n");
    for (int i = 0; i < 6; i++) {
        printf("nSteps = %ld\n", grid_steps[i]);
        parallel_estimate(grid_steps[i]);
    }
}

void sequential_estimate(long int nSteps) {
    int i = 0;
    long double step, x, pi, sum = 0.0;

    // Calculating the number of steps for limit sum integration to estimate pi.
    step = 1.0 / nSteps;

    // Start Estimation
    double start = omp_get_wtime();
    for (i = 0; i < nSteps; i++) {
        x = (i + 0.5) * step;
        sum += 4.0 / (1 + (x * x));
    }

    // Final estimate of Pi
    pi = sum * step;
    double stop = omp_get_wtime();

    printf("Estimate of Pi: %.9Lf -> Time Taken: %.3f\n\n", pi, (double) (stop - start));
}

void parallel_estimate(long int nSteps) {
    long double step, pi, sum = 0.0;

    // Calculating the number of steps for limit sum integration to estimate pi.
    step = 1.0 / nSteps;

    // Starting the Estimation
    double start = omp_get_wtime();

    // Setting the number of threads
    omp_set_dynamic(0);
    omp_set_num_threads(1000);

    #pragma omp parallel
    {
        // Declaring the variables in the shared scope within the parallel region
        int i;
        long double x;

        #pragma omp for schedule(static, 1) reduction(+:sum)
        for (i = 0; i < nSteps; i++) {
            x = (i + 0.5) * step;
            sum += 4.0 / (1 + (x * x));
        }
    }

    // Final estimate of Pi
    pi = sum * step;
    double stop = omp_get_wtime();

    printf("Estimate of Pi: %.9Lf -> Time Taken: %.3f\n\n", pi, (double) (stop - start));
}