#include <iostream>
using namespace std;

class Rider {
    string name;
    int age;
    string bike_make;
    int championship_pts;
    string const_type;

    public:
        // -- Constructors
        // Default Constructor
        Rider() : name{"None"}, age{0}, bike_make{"None"}, championship_pts{0}, const_type{"Default"} {
            cout << const_type << " constructor was called" << endl;
        }
        
        // Bio Constructor
        Rider(string name, int age) : name{name}, age{age}, bike_make{"None"}, championship_pts{0}, const_type{"Bio"} {
            cout << const_type << " constructor was called" << endl;
        }

        // Championship Constructor
        Rider(string name, string bike_make, int championship_pts)
        : name{name}, age{0}, bike_make{bike_make}, championship_pts{championship_pts}, const_type{"Championship"} {
            cout << const_type << " constructor was called" << endl;
        }

        // -- Destructor
        ~Rider() {
            cout << "The " << const_type << " destructor was called" << endl;
        }
};

int main(int argc, char const *argv[])
{
    {
        Rider rider1 = Rider();
        Rider rider2 = Rider("Marc Marquez", 32);
        Rider rider3 = Rider("Marc Marquez", "Ducati Lenovo", 179);
    }
    return 0;
}
