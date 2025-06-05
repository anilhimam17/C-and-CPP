#include <iostream>
using namespace std;


// Creating a Generic Class for Arrays
template <typename T, int N>
class Array {
    private:
        int size{N};
        T elements[N];

        // Overloaded << operator for output
        friend ostream& operator<<(ostream &os, const Array<T, N> &arr) {
            os << "[" << endl;
            for (auto &element: arr.elements)
                os << " " << element << " ";
            os << "\n]" << endl;

            return os;
        }
    public:
        // Helper Functions
        void fill_value(T value) {
            for (auto &element: elements)
                element = value;
        }

        // Constructors
        Array() : Array{T{}} {};
        Array(T init_value) {
            fill_value(init_value);
        }

        // Destructor
        ~Array() {
            cout << "Array of size " << size << " was destroyed" << endl;
        }
};


int main(int argc, char const *argv[])
{
    Array<string, 10> str_arr{"Hello, World"};
    cout << "Here is a string array:" << endl;
    cout << str_arr << endl;

    Array<int, 5> int_arr{};
    cout << "Here is an integer array:" << endl;
    cout << int_arr << endl;

    Array<string, 5> str_init_arr{};
    cout << "Here is a default string array:" << endl;
    cout << str_init_arr << endl;

    return 0;
}
