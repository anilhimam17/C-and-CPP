#include <iostream>
#include <vector>
using namespace std;

void display(int *arr);
void display(vector <int> *v);

int main() {
    int arr[10] = {0};
    vector <int> vec(10, 0);

    display(arr);
    cout << endl;
    display(&vec);

    return 0;
}

void display(int *arr) {
    cout << "Printing an array" << endl;
    for (int i = 0; i < 10; i++) {
        cout << *(arr + i) << endl;
    }
}

void display(vector <int> *v) {
    cout << "Printing a vector" << endl;
    for (auto ele: *v) {
        cout << ele << endl;
    }
}