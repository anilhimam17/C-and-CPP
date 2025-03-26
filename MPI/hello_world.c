#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int p = 0, id = 0;

    // Initialising the MPI construct
    MPI_Init(&argc, &argv);

    // Initialising the size of the communication medium
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    printf("I am %d of process %d\n", id, p);

    // Shutting down MPI
    MPI_Finalize();
    return 0;
}