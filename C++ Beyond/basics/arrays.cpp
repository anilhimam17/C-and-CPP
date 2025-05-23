#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    // Dec - 1
    int arr_1[] = {1, 2, 3};
    int arr_2[3] = {1, 2, 3};
    int arr_3[5] = {1, 2};
    int arr_4[10] = {0};

    cout << "Array 1" << endl;
    for (int i = 0; i < sizeof(arr_1) / sizeof(int); i++) {
        cout << "arr[" << i << "] " << arr_1[i] << "\n";
    }
    cout << "\n\n";

    cout << "Array 2" << endl;
    for (int i = 0; i < sizeof(arr_2) / sizeof(int); i++) {
        cout << "arr[" << i << "] " << arr_2[i] << "\n";
    }
    cout << "\n\n";
    
    cout << "Array 3" << endl;
    for (int i = 0; i < sizeof(arr_3) / sizeof(int); i++) {
        cout << "arr[" << i << "] " << arr_3[i] << "\n";
    }
    cout << "\n\n";

    cout << "Array 4" << endl;
    for (int i = 0; i < sizeof(arr_4) / sizeof(int); i++) {
        cout << "arr[" << i << "] " << arr_4[i] << "\n";
    }
    cout << "\n\n";

    return 0;
}
