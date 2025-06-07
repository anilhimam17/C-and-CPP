#include <iostream>
#include <array>
using namespace std;

int main(int argc, char const *argv[])
{
    // Newly declared array
    cout << "Here are the elements of the declared array:" << endl;
    array<int, 5> arr;
    for (int i = 0; i < arr.size(); i++)
        cout << "Element " << i << ": " << arr.at(i) << endl;

    // Declared and initialised
    array<int, 5> arr_init {1, 2, 3, 4};
    cout << "Here are the elements from an almost complete arr:" << endl;
    for (int i = 0; i < arr_init.size(); i++) {
        cout << "Element: " << arr_init.at(i) << endl;
    }
    cout << "Max Size of the almost complete array: " << arr_init.max_size() << endl;

    // Properties of the array
    cout << "Max Size of the Array: " << arr.max_size() << endl;
    cout << "The first element of the array: " << arr.front() << endl;
    cout << "The last element of the array: " << arr.back() << endl;
    cout << "The second element of the array: " << arr.at(arr.front() + 1) << endl;
    cout << "The second last element of the array: " << arr.at(arr.back() - 1) << endl;

    // Custom filled array
    arr.fill(1000);
    cout << "Here are the elements of the newly filled array" << endl;
    for (auto ele: arr)
        cout << "Element: " << ele << endl;

    // Swapped array
    array<int, 5> swap_arr {10, 10, 10};
    arr.swap(swap_arr);
    cout << "Here are elements from the swapped array:" << endl;
    for (auto ele: arr)
        cout << "Element: " << ele << endl;

    // Accessing the raw array
    int* raw_arr = arr.data();
    cout << "Here are elements from the raw array:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Element: " << *(raw_arr + i) << endl;
    }

    return 0;
}
