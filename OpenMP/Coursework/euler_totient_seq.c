#include <stdio.h>
#include <unistd.h>
#include <omp.h>

long int euler_totient(long int lb, long int ub);
void run_benchmark();

int main(int argc, char** argv) {
    // long int euler_tot = 0;

    // if (!(argc > 1)) {
    //     exit(-1);
    // }

    // long int lb = atoi(argv[1]);
    // long int ub = atoi(argv[2]);

    // long int totient = euler_totient(lb, ub);
    // printf("Euler Totient: %ld\n", totient);

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
    for (i = 1; i <= n; i++) {
        if (calc_hcf(n, i) == 1) {
            len++;
        }
    }

    return len;
}

long int euler_totient(long int lb, long int ub) {
    long int tot = 0;
    for (int i = lb; i <= ub; i++) {
        tot += euler_len(i);
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