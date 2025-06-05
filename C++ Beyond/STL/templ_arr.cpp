#include <iostream>
using namespace std;


// Non - Type template parameter to pass the array length at compile time.
template <int N>
class Array {
    private:
        int size = N;
        int values[N];

        // Overloaded friend function to display the array
        friend ostream& operator<<(ostream &os, const Array<N> &arr) {

            // Sending all the display values to the output stream
            os << "[" << endl;
            for (auto val: arr.values) {
                os << " " << val << " ";
            }
            os << "\n]" << endl;

            // Returning the output stream
            return os;
        }
    public:
        // Constructor
        Array() : Array(0) {};
        Array(int init_value) {
            fill_value(init_value);
        }

        // Destructor
        ~Array() {
            cout << "Array of size: " << size << " was deleted" << endl;
        }

        // Helper functions
        void fill_value(int value) {
            for (auto &item: values) {
                item = value;
            }
        }

        int get_size() {
            return size;
        }

        // Overloaded Subscript Operator
        int& operator[](int index) {
            return values[index];
        }
};


int main(int argc, char const *argv[])
{
    cout << "Here is an array of 5 elements" << endl;
    Array<5> arr;
    cout << arr << endl;
    arr[4] = 10;
    cout << "New Element 4 " << arr[4] << endl;

    cout << "\n\nHere is an array of 10 elements" << endl;
    Array<10> arr_10{10};
    cout << arr_10 << endl;
    cout << "New Element 9 " << arr_10[9] << endl;
    arr_10.fill_value(1000);
    cout << "New arr of 10 elements: " << arr_10 << endl;
    return 0;
}
