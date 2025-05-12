#include <iostream>
using namespace std;

void exercise_1(int *mantissa, int multiplier) {
    *mantissa = *mantissa * multiplier;
}

int findMaxElement(int *arr, size_t size) {
    int max_ele = *arr;
    for (int i = 0; i < size; i++) {
        int ele = *(arr + i);
        if (ele >= max_ele) {
            max_ele = ele;
        }
    }

    return max_ele;
}

void reverse_arr(int *arr, size_t size) {
    int half = (int) (size / 2);
    for (int i = 0; i < half; i++) {
        int temp = *(arr + i);
        *(arr + i) = *(arr + (size - 1 - i));
        *(arr + (size - 1 - i)) = temp;
    }
}

int main(int argc, char const *argv[])
{
    int number = 10;
    int *ptr_int = &number;

    cout << "number before multiplication: " << number << endl;
    exercise_1(ptr_int, 10);
    cout << "number after multiplication: " << number << endl;

    int *arr = new int[10];

    cout << "\nElements of the arr: " << endl;
    for (int i = 0; i < 10; i++) {
        *(arr + i) = i;
        cout << *(arr + i) << endl;
    }

    cout << "Largest element in the array is: " << findMaxElement(arr, 10) << endl;

    cout << "\nReversing the elements of the array: " << endl;
    reverse_arr(arr, 10);
    for (int i = 0; i < 10; i++) {
        cout << *(arr + i) << endl;
    }

    return 0;
}
