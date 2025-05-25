#include <iostream>
#include <memory>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<unique_ptr<int>> vec_ptrs;

    unique_ptr<int> i1_ptr = make_unique<int>(10);
    auto i2_ptr = make_unique<int>(20);

    vec_ptrs.push_back(std::move(i1_ptr));
    vec_ptrs.push_back(std::move(i2_ptr));

    cout << "Contents of the Vector:" << endl;
    for (const auto &ptr: vec_ptrs) {
        cout << "Value of ptr: " << *ptr << endl;
    }

    cout << "Taking input for 5 other integers into the vector:\n";
    for (int i = 0; i < 5; i++) {
        unique_ptr<int> ptr;
        
        int num = 0;
        cout << "Input Number: ";
        cin >> num;

        // Creating the unique ptr for the runtime input
        ptr = make_unique<int>(num);
        vec_ptrs.push_back(std::move(ptr));
    }

    cout << "\n\nContents of the final Vector:" << endl;
    for (const auto &ptr: vec_ptrs) {
        cout << "Value of ptr: " << *ptr << endl;
    }
    
    return 0;
}
