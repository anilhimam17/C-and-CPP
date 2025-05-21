#include <iostream>
using namespace std;

class Numbers {
    private:
        int num;
    public:
        // Getters
        int get_num() const {return num;}

        // Constructors
        Numbers() : num{0} {};
        Numbers(int num) : num{num} {};

        // Destructor
        ~Numbers() {
            cout << "Destructor was called for: " << num << endl;
        }

        // Unary Operator Overloads
        Numbers operator--() {
            --num;
            return *this;
        }
        Numbers operator--(int) {
            Numbers temp = *this;
            --num;
            return temp;
        };

        Numbers operator++() {
            ++num;
            return *this;
        }
        Numbers operator++(int) {
            Numbers temp = *this;
            ++num;
            return temp;
        }

        // Binary Operator Overloads
        Numbers operator+(const Numbers &rhs) const {
            return Numbers(this->num + rhs.num);
        };
        Numbers operator-(const Numbers &rhs) const {
            return Numbers(this->num - rhs.num);
        }

        // Relational Operator Overloads
        bool operator<(const Numbers &rhs) const {
            if (this->num < rhs.num)
                return true;
            return false;
        }
        bool operator>(const Numbers &rhs) const {
            if (this->num > rhs.num)
                return true;
            return false;
        }
};

// Helper function
void display_num(const Numbers &num) {
    cout << num.get_num() << endl;
}

int main() {

    Numbers n1 = Numbers(100);
    Numbers n2 = Numbers(200);

    n1++;
    cout << "Increment Post N1: " << endl;
    display_num(n1);
    ++n2;
    cout << "Increment Pre N2: " << endl;
    display_num(n2);

    Numbers n = n1 + n2;
    cout << "Addition: " << endl;
    display_num(n);

    if (n1 < n)
        cout << "N1 < N" << endl;
    else
        cout << "N1 > N" << endl;

    if (n > n2)
        cout << "N > N2" << endl;
    else
        cout << "N2 > N" << endl;
}