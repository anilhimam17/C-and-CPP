#include <iostream>
using namespace std;

class Rider {
    private:
        string name;
        int age;
        string bike_make;
        int* championship_pts = new int;
    public:
        // Getter Functions
        string get_name() {
            return this->name;
        }
        int get_age() {
            return this->age;
        }
        string get_bike_make() {
            return this->bike_make;
        }
        int get_championship_pts() {
            return *this->championship_pts;
        }

        // Setter Functions
        void set_name(string new_name) {
            this->name = new_name;
        }
        void set_age(int new_age) {
            this->age = new_age;
        }
        void set_bike_make(string new_make) {
            this->bike_make = new_make;
        }
        void set_championship_pts(int points) {
            *this->championship_pts = points;
        }

        // Full Args Constructor
        Rider(string name, int age, string make, int pts) : name{name}, age{age}, bike_make{make} {
            *this->championship_pts = pts;
        }

        // Default Constructor
        Rider() : Rider{"None", 0, "None", 0} {}

        // Copy Constructor
        Rider(const Rider &copy_rider) 
        : name{copy_rider.name}, age{copy_rider.age}, bike_make{copy_rider.bike_make}, championship_pts{new int(*copy_rider.championship_pts)} {}

        // Destructor
        ~Rider() {
            cout << "Destructor called for " << this->name << endl;
            delete this->championship_pts;
        }

        // Overloading the equality operator
        Rider &operator=(const Rider &rhs) {

            cout << "Overloaded equality operator was called" << endl;

            // If equal we return the current LHS as it is.
            if (this == &rhs)
                return *this;
            
            // Delete the current championship_pts for assigning the new value.
            delete championship_pts;

            // Create a new pointer to integer to store the new value.
            championship_pts = new int;

            // Rest of the values being assigned.
            this->name = rhs.name;
            this->age = rhs.age;
            this->bike_make = rhs.bike_make;

            // Dereference the pointer location for LHS and RHS to apply the assignment operation on the values.
            *this->championship_pts = *rhs.championship_pts;

            // Returning the copied object.
            return *this;
        }

        // Move Assignment Overload
        Rider &operator=(Rider &&rhs) {

            cout << "Overloaded Move Assignment Operator was Called" << endl;
            // If the LHS equals RHS we returns the LHS.
            if (this == &rhs)
                return *this;
            
            // Delete the current championship value and its pointer.
            delete championship_pts;

            // Assign the moved values of the championship points from the r-value.
            this->championship_pts = rhs.championship_pts;

            // Set the r-value ptr to null after moving the value.
            rhs.championship_pts = nullptr;

            // Rest of the assignments.
            this->name = rhs.name;
            this->age = rhs.age;
            this->bike_make = rhs.bike_make;

            return *this;
        }
};

// Helper Function
void display_rider(Rider rider) {
    cout << "Name: " << rider.get_name() << endl;
    cout << "Age: " << rider.get_age() << endl;
    cout << "Bike Make: " << rider.get_bike_make() << endl;
    cout << "Championship Points: " << rider.get_championship_pts() << endl;
}

int main(int argc, char const *argv[])
{
    Rider rider1 = Rider("Marc Marquez", 32, "Ducati Lenovo", 179);
    Rider new_rider = Rider();

    new_rider = rider1;
    display_rider(new_rider);
    cout << endl;

    new_rider = Rider("Pecco", 26, "Ducati Lenovo", 112);
    display_rider(new_rider);
    cout << endl;
    return 0;
}
