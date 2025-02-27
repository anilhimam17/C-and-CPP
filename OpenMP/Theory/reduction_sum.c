#include <stdio.h>
#include <omp.h>

int main() {
    int i, sum = 0;
    omp_set_num_threads(4);

    #pragma omp parallel
    {
        #pragma omp for reduction(+:sum)
        for (i = 1; i <= 10; i++) {
            int tid = omp_get_thread_num();
            sum += i;
            printf(
                "The sum: %d -> on thread: %d\n", sum, tid);
        }
    }

    printf("Sum of 1 to 10 accross all the threads is: %d\n", sum);
    return 0;
}