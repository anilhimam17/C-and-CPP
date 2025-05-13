#include <iostream>
#include <string>
using namespace std;

// Account Class Declaration
class Account {
    private:
        string name;
        int account_number;
        int account_balance;
    public:
        void set_name(string name) {
            this -> name = name;
        }
        string get_name() {
            return name;
        }

        void set_acc_num(int number);
        int get_acc_num();

        void set_acc_balance(int balance);
        int get_acc_balance();
};

// Other Member functions
void Account::set_acc_num(int number) {
    this -> account_number = number;
}
int Account::get_acc_num() {
    return account_number;
}

void Account::set_acc_balance(int balance) {
    this -> account_balance = balance;
}
int Account::get_acc_balance() {
    return account_balance;
}

// Main Function
int main(int argc, char const *argv[])
{
    Account first_acc;
    first_acc.set_name("Anil");
    first_acc.set_acc_balance(1000);
    first_acc.set_acc_num(10);

    cout << "Here are the account details: " << endl;
    cout << "Name: " << first_acc.get_name() << endl;
    cout << "Number: " << first_acc.get_acc_num() << endl;
    cout << "Balance: " << first_acc.get_acc_balance() << endl;
    return 0;
}

