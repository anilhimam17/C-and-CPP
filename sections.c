#include <stdio.h>
#include <omp.h>

// Function Preprocessors
void first_func();
void second_func();
void third_func();
void fourth_func();

int main() {

    // Parallel Region without Sections
    printf("Executing the program in parallel without sections:\n");
    #pragma omp parallel num_threads(4)
    {
        first_func();
        second_func();
        third_func();
        fourth_func();
    }

    // Parallel Region with Sections
    printf("\n\nExecuting the program in parallel with sections:\n");
    #pragma omp parallel sections num_threads(4)
    {
        #pragma omp section
        {
            first_func();
        }
        #pragma omp section
        {
            second_func();
        }
        #pragma omp section
        {
            third_func();
        }
        #pragma omp section
        {
            fourth_func();
        }
    }
    printf("\nExiting the Program.....\n");
}

// Implemented Functions
void first_func() {
    printf(
        "Inside: First Function -> Executed by: %d of %d threads\n", 
        omp_get_thread_num(),
        omp_get_max_threads()
    );
}

void second_func() {
    printf(
        "Inside: Second Function -> Executed by: %d of %d threads\n", 
        omp_get_thread_num(),
        omp_get_max_threads()
    );
}

void third_func() {
    printf(
        "Inside: Third Function -> Executed by: %d of %d threads\n", 
        omp_get_thread_num(),
        omp_get_max_threads()
    );
}

void fourth_func() {
    printf(
        "Inside: Fourth Function -> Executed by: %d of %d threads\n", 
        omp_get_thread_num(),
        omp_get_max_threads()
    );
}