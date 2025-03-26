#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <mpi.h>

// Function Preprocessors
int thinker();
int guesser();

int main(int argc, char** argv) {
    int p, id;

    // Initialising the MPI Construct
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);

    if (id == 0) {
        thinker();
    } else {
        guesser();
    }

    // Deallocating all the resources
    MPI_Finalize();
    return 0;
}

// Thinker function to think a new number and validate the guess made by the guesser
int thinker() {

    // Variables required for parsing messages between processes
    int number, guess, run = 0;
    char reply;
    MPI_Status status;

    // Initialising the random seed to current runtime instance
    srand(time(NULL));

    // Creating a new target everytime to challenge the guesser
    number = rand() % 1000 + 1;  // Generates new numbers between 1 and 100 inclusive

    reply = 'x';
    while (reply != 'c') {
        // Retrieving the guess made by the Guesser Process
        MPI_Recv(&guess, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
        if (guess == number) {
            reply = 'c';
            break;
        } else if (guess > number) {
            reply = 'h';
        } else {
            reply = 'l';
        }

        // Log for the current run
        printf("Thinker Log -> %d: guessed: %d expected: %d responding: %c\n", run, guess, number, reply);
        run += 1;
        
        // Transmitting the message to the guesser
        MPI_Send(&reply, 1, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
    }

    printf("Thinker Log -> %d: guessed: %d expected: %d responding: %c\n", run, guess, number, reply);
    return 0;
}

// Guesser function to guess new number to match the thought process of the thinker
int guesser() {

    // Variables requried for passing message between processes
    int guess, high, low;
    char reply;
    MPI_Status status;

    // To ensure that there is difference in the seed to generate unique random number between the thinker and guesser
    sleep(2);

    // Initialising the random number generator with a seed
    srand(time(NULL));

    low = 1, high = 1000;
    guess = rand() % 1000 + 1;

    while (1) {
        // Transmitting the new guess for validation
        MPI_Send(&guess, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);

        // Retrieving the response after validation
        MPI_Recv(&reply, 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD, &status);

        // Log for the current run
        printf("Guesser Log -> guessed: %d reply: %d high: %d low: %d\n", guess, reply, high, low);

        if (reply == 'c') {
            printf("Guesser Log -> replied %c\n", reply);
            printf("End of the program\n");
            break;
        } else if (reply == 'h') {
            high = guess;
        } else {
            low = guess;
        }

        // New guess
        guess = low + (rand() % (high - low + 1));
    }
    return 0;
}
