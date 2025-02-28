#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <omp.h>

long int euler_totient(long int lb, long int ub);
void run_benchmark(long int range);

int main(int argc, char** argv) {
    run_benchmark(atoi(argv[1]));
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

    // Parallel Region
    #pragma omp parallel
    {
        // Concurrent loop with reduction
        #pragma omp for schedule(static, 1) reduction(+:len)
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
        #pragma omp for schedule(static, 1) reduction(+:tot)
        for (int i = lb; i <= ub; i++) {
            tot += euler_len(i);
        }
    }
    
    return tot;
}

void run_benchmark(long int range) {
    double start, end, time_taken;
    long int totient = 0;

    start = omp_get_wtime();
    totient = euler_totient(1, range);
    end = omp_get_wtime();

    printf("The Euler Totient Sum -> %ld\n", totient);
    printf("Time Elapsed: %.2f\n\n", (double) (end - start));
}