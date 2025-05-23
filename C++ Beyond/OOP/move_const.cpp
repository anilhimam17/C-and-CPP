#include <iostream>
#include <utility>
using namespace std;

class Rider {
    private:
        string name;
        int age;
        string bike_make;
        string const_type;
    public:
        // Object Constructors
        Rider(string name, int age, string bike_make, string const_type="Default") 
        : name{name}, age{age}, bike_make{bike_make}, const_type{const_type} {
            cout << "Default Constructor was called for: " << endl;
            cout << name << " " << age << " " << bike_make << " " << const_type << "\n" << endl;
        }
        Rider() : Rider{"None", 0, "None", "Default"} {}

        // Copy Constructor
        Rider(const Rider &source) : name{source.name}, age{source.age}, bike_make{source.bike_make}, const_type{"Copy"} {
            cout << "Copy Constructor was called for: " << endl;
            cout << name << " " << age << " " << bike_make << " " << const_type << "\n" << endl;
        }

        // Move Constructor
        Rider(Rider &&source) : name{std::move(source.name)}, age{source.age}, bike_make{std::move(source.bike_make)}, const_type{"Move"} {
            cout << "Move Constructor was called for: " << endl;
            cout << name << " " << age << " " << bike_make << " " << const_type << "\n" << endl;
            source.age = 0;
        }

        // Destructor
        ~Rider() {
            cout << "Destructor was called for: " << const_type << endl;
            cout << name << " " << age << " " << bike_make << " " << const_type << "\n" << endl;
        }
};

int main(int argc, char const *argv[])
{
    vector <Rider> riders;
    {
        cout << "\nThe following calls should be move constructor calls: " << endl;
        riders.push_back(Rider{"Copy 1", 32, "Ducati Lenovo"});
        riders.push_back(Rider{"Copy 2", 30, "Gresini Ducati"});
    }
    {
        cout << "\nThe following calls should be default constructor calls: " << endl;
        Rider rider1 = Rider{"New Rider 1", 32, "Honda"};
        Rider rider2 = Rider("New Rider 2", 23, "Ducati");
        Rider rider3 = Rider{};
        Rider rider4 = Rider();

        cout << "\nThe following calls should be move constructor calls: " << endl;
        riders.push_back(rider1);
        riders.push_back(rider2);
        riders.push_back(rider3);
        riders.push_back(rider4);
    }

    return 0;
}
