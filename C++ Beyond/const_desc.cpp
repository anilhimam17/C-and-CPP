#include <iostream>
#include <string>
using namespace std;

class Rider {
    string name;
    int age;
    string bike_make;
    int points;

    // Constructors and Destructors
    public:
        Rider() {
            cout << "Default constructor was called" << endl;
        }
        Rider(string name) {
            cout << "Name Constructor was called" << endl;
        }
        Rider(string name, int age) {
            cout << "Bio data Constructor was called" << endl;
        }
        Rider(string name, string bike_name, int points) {
            cout << "Championship constructor was called" << endl;
        }

        ~Rider() {
            cout << "Destructor was called" << endl;
        }
};

int main(int argc, char const *argv[])
{
    {
        Rider *rider1 = new Rider;
        Rider rider2 = Rider();
        Rider rider3 = Rider("Marc Marquez");
        Rider rider4 = Rider("Marc Marquez", 32);
        Rider rider5 = Rider("Marc Marquez", "Ducati Lenovo", 179);
    }
    return 0;
}
