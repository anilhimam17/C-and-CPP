#include <iostream>
using namespace std;

class Bike {
    string name;
    int power;
    int price;

    public:
        Bike() : Bike{"None", 0, 0} {}
        Bike(string name): Bike{name, 0, 0} {}
        Bike(string name, int power, int price) : name{name}, power{power}, price{price} {
            cout << "New object was created" << endl;
            cout << "Name: " << name << endl;
            cout << "Power: " << power << endl;
            cout << "Price: " << price << endl;
        }

        ~Bike() {
            cout << "Destroyed: " << name << endl;
        }
};

int main() {
    Bike cbr = Bike("CBR Fireblade", 650, 700000);
    Bike ninja = Bike("Ninja");
    Bike nobody = Bike();

    return 0;
}