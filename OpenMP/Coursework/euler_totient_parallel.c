#include <stdio.h>
#include <unistd.h>
#include <omp.h>

long int euler_totient(long int lb, long int ub);
void run_benchmark();

int main(int argc, char** argv) {
    run_benchmark();
}

int calc_hcf(long int a, long int b) {
    while (b != 0) {
        long int temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

long int euler_len(long int n) {
    long int len, i;
    len = 0;
    
    // Force setting the number of threads
    omp_set_dynamic(0);
    omp_set_num_threads(10);

    // Parallel Region
    #pragma omp parallel
    {
        // Concurrent loop with reduction
        #pragma omp for reduction(+:len)
        for (i = 1; i <= n; i++) {
            if (calc_hcf(n, i) == 1) {
                len++;
            }
        }
    }
    return len;
}

long int euler_totient(long int lb, long int ub) {
    long int tot = 0;

    // Parallel Region
    #pragma omp parallel
    {
        #pragma omp for reduction(+:tot)
        for (int i = lb; i <= ub; i++) {
            tot += euler_len(i);
        }
    }
    
    return tot;
}

void run_benchmark() {
    double start, end, time_taken;
    long int totient = 0;

    for (long int i = 1; i < 1000000; i += 100000) {
        start = omp_get_wtime();
        totient = euler_totient(1, i);
        end = omp_get_wtime();

        printf("The Euler Totient Sum of %ld -> %ld\n", i, totient);
        printf("Time Elapsed: %.2f\n\n", (double) (end - start));
    }
}