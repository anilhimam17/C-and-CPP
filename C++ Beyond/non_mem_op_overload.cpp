#include <iostream>
using namespace std;

class MyNumber {
    // Declaring friends for global non member overloads of Unary Operators
    friend MyNumber operator++(MyNumber &obj);  // Prefix Op
    friend MyNumber operator++(MyNumber &obj, int);  // Postfix Op

    // Declaring friends for global non member overloads of Binary Operators
    friend MyNumber operator+(const MyNumber &lhs, const MyNumber &rhs);
    friend MyNumber operator-(const MyNumber &lhs, const MyNumber &rhs);
    friend bool operator>(const MyNumber &lhs, const MyNumber &rhs);
    friend bool operator<(const MyNumber &lhs, const MyNumber &rhs);

    private:
        int num;
    public:
        // Getter and Setter
        int get_num() const {
            return num;
        }
        void set_num(MyNumber new_num) {
            num = new_num.num;
        }

        // Constructors
        MyNumber(int num) : num{num} {};
        MyNumber() : num{0} {};

        // Special Constructors
        MyNumber(const MyNumber &copy_num) : num{copy_num.num} {
            cout << "Copy Constructor was called for: " << num << endl;
        };
        MyNumber(MyNumber &&move_num) : num{std::move(move_num.num)} {
            cout << "Move Constructor was called for: " << num << endl;
        }

        // Destructor
        ~MyNumber() {
            cout << "Destructor was called for: " << num << endl;
        }
};

// Prefix and Postfix overloads for the Increment Operator as global non member functions
MyNumber operator++(MyNumber &obj) {
    ++obj.num;
    return obj;
}
MyNumber operator++(MyNumber &obj, int) {
    MyNumber temp = obj;
    obj.num++;
    return temp;
}

// Global non member overload functions for general ops
MyNumber operator+(const MyNumber &lhs, const MyNumber &rhs) {
    return MyNumber(lhs.num + rhs.num);
}
MyNumber operator-(const MyNumber &lhs, const MyNumber &rhs) {
    return MyNumber(lhs.num - rhs.num);
}

// Global non member overload functions for relational ops
bool operator>(const MyNumber &lhs, const MyNumber &rhs) {
    return lhs.num > rhs.num;
}
bool operator<(const MyNumber &lhs, const MyNumber &rhs) {
    return lhs.num < rhs.num;
}

// Helper functions
void display_num(MyNumber &num) {
    cout << num.get_num() << endl;
}

// Driver Code
int main(int argc, char const *argv[])
{
    MyNumber n1 = MyNumber(100);
    MyNumber n2 = MyNumber(200);

    cout << "Intial values: " << endl;
    cout << "n1: ";
    display_num(n1);
    cout << "n2: ";
    display_num(n2);

    cout << "Increment pre n1: ";
    ++n1;
    display_num(n1);
    cout << "Post Increment n2: ";
    n2++;
    display_num(n2);

    cout << "Addition of n1 and n2: ";
    MyNumber new_num = std::move(n1 + n2);
    cout << "Moved value of new_num: ";
    display_num(new_num);

    if (n1 < new_num) {
        cout << "N1 < new num" << endl;
    }
    if (n2 > new_num) {
        cout << "Something is wrong" << endl;
    } else {
        cout << "Ok!!! N2 < new_num" << endl;
    }

    return 0;
}
