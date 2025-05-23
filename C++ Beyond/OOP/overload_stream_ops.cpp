#include <iostream>
using namespace std;

class Number {
    // Friends of the Class for Stream Ops Overload
    friend std::ostream &operator<<(std::ostream &os, const Number &output_num);
    friend std::istream &operator>>(std::istream &is, Number &input_num);

    private:
        int num;

    public:
        // Getters and Setters
        int get_num() const {return num;}
        void set_num(int num) {this->num = num;};

        // Constructors
        Number(int num) : num{num} {};
        Number() : Number{0} {};

        // Special Constructors
        Number(const Number &copy_num) : num{copy_num.num} {
            cout <<  "The Copy Constructor was called for: " << num << endl;
        }
        Number(Number &&move_num) : num{std::move(move_num.num)} {
            cout << "The Move Constructor was called for: " << num << endl;
        }

        // Destructor
        ~Number() {
            cout << "The Destructor was called for: " << num << endl;
        }
};

// Global non member function overloads for the Number Class stream ops.
std::ostream &operator<<(std::ostream &os, const Number &output_num) {
    os << output_num.num;
    return os;
}
std::istream &operator>>(std::istream &is, Number &input_num) {
    int buff;
    is >> buff;
    input_num.num = buff;
    return is;
}

int main(int argc, char const *argv[])
{
    Number my_num1;
    cout << "Enter number to create a Number instance: ";
    cin >> my_num1;
    cout << "Number number entered: " << my_num1 << endl;

    Number num_copy = my_num1;
    Number num_move = std::move(Number(my_num1.get_num()));
    return 0;
}
