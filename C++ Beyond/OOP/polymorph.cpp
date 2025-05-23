#include <iostream>
using namespace std;

class Vehicle {
    string name;
    string transport_medium;
    int number_of_wheel;
    string fuel_type;

    public:
        virtual void display_specs() const {
            cout << "The Specs of the Vehicle are as follows: " << endl;
            cout << name << " " << transport_medium << " " << number_of_wheel << " " << fuel_type << endl;
        }

        string get_name() const {return name;}
        string get_transport_medium() const {return transport_medium;}
        int get_num_wheels() const {return number_of_wheel;}
        string get_fuel_type() const {return fuel_type;}

        Vehicle(string name, string medium, int wheels, string fuel) 
        : name{name}, transport_medium{medium}, number_of_wheel{wheels}, fuel_type{fuel} {
            cout << "Constructor called for: " << name << " " << transport_medium << endl;
        }
        virtual ~Vehicle() {
            cout << "Destructor called for: " <<  name << " " << transport_medium << endl;
        }
};

class Car : public Vehicle {
    int hp;
    
    public:
        virtual void display_specs() const {
            cout << "The Specs of the Car are as follows: " << endl;
            cout << get_name() << " " << get_transport_medium() << " " << get_num_wheels() << " " << get_fuel_type() << " " << hp << endl;
        }

        Car(string name, string medium, int wheels, string fuel, int hp)
        : Vehicle{name, medium, wheels, fuel}, hp{hp} {
            cout << "Constructor called for: " << get_name() << " " << get_transport_medium() << " " << hp << endl;
        }
        virtual ~Car() {
            cout << "Destructor called for: " << get_name() << " " << get_transport_medium() << " " << hp << endl;
        }
};

// Helper function for testing polymorphism
void display(const Vehicle &v) {
    v.display_specs();
}


int main(int argc, char const *argv[])
{
    Vehicle new_v = Vehicle("Airplane", "air", 30, "Aviation Kerosene");
    display(new_v);
    Vehicle *new_car = new Car("Lamborghini", "land", 4, "Petrol", 650);
    display(*new_car);
    return 0;
}
