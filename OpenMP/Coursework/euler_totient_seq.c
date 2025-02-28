#include <stdio.h>
#include <unistd.h>
#include <omp.h>

long int euler_totient(long int lb, long int ub);
void run_benchmark(long int range, int cores);

int main(int argc, char** argv) {
    // if (!(argc > 1)) {
    //     exit(-1);
    // }

    // long int lb = atoi(argv[1]);
    // long int ub = atoi(argv[2]);
    // long int totient = 0;

    // Sequential single run bench
    
    // double start = omp_get_wtime();
    // totient = euler_totient(lb, ub);
    // double end = omp_get_wtime();

    // printf("Euler Totient(%ld): %ld -> Time Elapsed: %.2f\n", ub, totient, (double) (end - start));

    run_benchmark(atoi(argv[1]), atoi(argv[2]));
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

void run_benchmark(long int range, int cores) {
    double start, end, time_taken;
    long int totient = 0;

    omp_set_dynamic(0);
    omp_set_num_threads(1);

    start = omp_get_wtime();
    totient = euler_totient(1, range);
    end = omp_get_wtime();

    printf("%ld -> %.2f\n", totient, (double) (end - start));
}