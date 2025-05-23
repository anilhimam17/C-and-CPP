#include <iostream>
using namespace std;

int main() {
    int *arr_ptr = new int[10];
    
    cout << "Addresses of all the array memory addresses" << endl;
    for (int i = 0; i < 10; i++) {
        cout << arr_ptr + i << endl;
    }

    cout << "\nValues of all the array elements before initialisation" << endl;
    for (int i = 0; i < 10; i++) {
        cout << *arr_ptr++ << endl;
    }

    for (int i = 0; i < 10; i++) {
        *(arr_ptr + i) = i;
    }

    cout << "\nValues of all the array elements after initialisation" << endl;
    for (int i = 0; i < 10; i++) {
        cout << *arr_ptr++ << endl;
    }

    delete [] arr_ptr;
    return 0;
}