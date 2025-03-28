#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

/* Function to compute the highest common factor */
int calc_hcf(long int a, long int b) {
    while (b != 0) {
        long int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

/* Computes the Euler totient (phi) for a single integer n */
long int euler_len(long int n) {
    long int count = 0;
    for (long int i = 1; i <= n; i++) {
        if (calc_hcf(n, i) == 1) {
            count++;
        }
    }
    return count;
}

int main(int argc, char** argv) {
    int world_rank, world_size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    if (argc < 2) {
        if (world_rank == 0) {
            fprintf(stderr, "Usage: %s <euler_range>\n", argv[0]);
        }
        MPI_Finalize();
        return 1;
    }

    int euler_range = atoi(argv[1]);
    double start_time = MPI_Wtime();
    long int total_totient = 0;

    /* Master: dynamic task distribution (rank 0) */
    if (world_rank == 0) {
        int nextTask = 1;
        int numWorkers = world_size - 1;
        MPI_Status status;

        /* Distribute one task to each worker initially */
        for (int i = 1; i <= numWorkers; i++) {
            if (nextTask <= euler_range) {
                MPI_Send(&nextTask, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
                nextTask++;
            } else {
                /* No more tasks available: send termination message (tag 1) */
                int term = 0;
                MPI_Send(&term, 1, MPI_INT, i, 1, MPI_COMM_WORLD);
            }
        }

        /* Dynamically distribute remaining tasks */
        while (nextTask <= euler_range) {
            long int result;
            MPI_Recv(&result, 1, MPI_LONG, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status);
            total_totient += result;
            int task = nextTask;
            MPI_Send(&task, 1, MPI_INT, status.MPI_SOURCE, 0, MPI_COMM_WORLD);
            nextTask++;
        }

        /* Receive results from remaining workers and terminate them */
        for (int i = 1; i <= numWorkers; i++) {
            long int result;
            MPI_Recv(&result, 1, MPI_LONG, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status);
            total_totient += result;
            int term = 0;
            MPI_Send(&term, 1, MPI_INT, status.MPI_SOURCE, 1, MPI_COMM_WORLD);
        }

        double end_time = MPI_Wtime();
        printf("Total totient sum: %ld -> %.2fs\n", total_totient, end_time - start_time);
    }
    /* Worker processes: receive tasks, compute, and send back results */
    else {
        while (1) {
            int task;
            MPI_Status status;
            MPI_Recv(&task, 1, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
            if (status.MPI_TAG == 1) {
                /* Termination message received */
                break;
            }
            long int totient = euler_len(task);
            MPI_Send(&totient, 1, MPI_LONG, 0, 0, MPI_COMM_WORLD);
        }
    }

    MPI_Finalize();
    return 0;
}
