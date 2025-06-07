#include <iostream>
#include <vector>
using namespace std;


class Person {
    string name;
    int age;

    friend ostream& operator<<(ostream &os, const Person& person) {
        os << "Name: " << person.name << endl;
        os << "Age: " << person.age << endl;
        return os;
    }

    public:
        string get_name() const {return name;};

        Person() : Person{"None", 0} {};
        Person(string name, int age) : name{name}, age{age} {};

        bool operator>(const Person& rhs) const {
            return this->age > rhs.age;
        }
        bool operator<(const Person& rhs) const {
            return this->age < rhs.age;
        }
        bool operator==(const Person& rhs) const {
            return ((this->name == rhs.name) && (this->age == rhs.age));
        }
};

int main(int argc, char const *argv[])
{
    vector<Person> people {};
    people.push_back(Person {"Anil", 23});
    people.emplace_back("Marc Marquez", 32);
    people.emplace_back("Fabio Quartararo", 27);
    
    cout << "Here are the unsorted people in the vector:" << endl;
    for (auto person: people) {
        cout << person;
    }

    cout << "Here is the sorted people in the vector (ascending):" << endl;
    std::sort(people.begin(), people.end());
    for (auto person: people) {
        cout << person;
    }

    cout << "Here is the sorted people in the vector (descending):" << endl;
    std::sort(
        people.begin(), people.end(), 
        [](const Person& a, const Person& b) {
            return a > b;            
        }
    );
    for (auto person: people) {
        cout << person;
    }

    // Insertion into the vector
    vector<Person> vec(5);
    const auto& loc = std::find(people.begin(), people.end(), Person("Fabio Quartararo", 27));
    people.insert(loc, vec.begin(), vec.end());
    cout << "Here is the new vector with elements inserted:" << endl;
    for (const auto& person: people) {
        cout << person;
    }

    // Properties of the Inserted Vector
    cout << "Size: " << people.size() << endl;
    cout << "Max Size (Supported by Sys): " << people.max_size() << endl;
    cout << "Current Capacity: " << people.capacity() << endl;

    // Adding a new person to check capacity scaling
    people.push_back(Person {"Novak Djokovic", 37});
    cout << "Vector Properties after adding Novak" << endl;
    cout << "Size: " << people.size() << endl;
    cout << "Max Size (Supported by Sys): " << people.max_size() << endl;
    cout << "Current Capacity: " << people.capacity() << endl;

    // Shrinking the Capacity to Size
    people.shrink_to_fit();
    cout << "Current Capacity (Shrink Updated): " << people.capacity() << endl;

    // New reserved vector
    vector<Person> reserved_vector;
    reserved_vector.reserve(9);
    std::copy(people.begin(), people.end(), std::back_inserter(reserved_vector));
    cout << "Vector Properties of the Reserved Vector" << endl;
    cout << "Size: " << reserved_vector.size() << endl;
    cout << "Max Size (Supported by Sys): " << reserved_vector.max_size() << endl;
    cout << "Current Capacity: " << reserved_vector.capacity() << endl;

    reserved_vector.emplace_back("Rafael Nadal", 38);
    cout << "Vector Properties of the Reserved Vector after adding Rafael Nadal" << endl;
    cout << "Size: " << reserved_vector.size() << endl;
    cout << "Max Size (Supported by Sys): " << reserved_vector.max_size() << endl;
    cout << "Current Capacity: " << reserved_vector.capacity() << endl;

    // Erasing all the null elements
    reserved_vector.erase(std::remove_if(
        reserved_vector.begin(), reserved_vector.end(),
        [](const Person& person) {
            return person.get_name().empty() || person.get_name() == "None";
        })
    );
    cout << "Vector Properties of the Reserved Vector after erasing all the null elements:" << endl;
    cout << "Size: " << reserved_vector.size() << endl;
    cout << "Max Size (Supported by Sys): " << reserved_vector.max_size() << endl;
    cout << "Current Capacity: " << reserved_vector.capacity() << endl;
    for (const auto& ele: reserved_vector)
        cout << "Element " << ele << endl;

    // Transforming the elements
    vector<string> tfx_people {};
    std::transform(
        reserved_vector.begin(), reserved_vector.end(), std::back_inserter(tfx_people),
        [](const Person& person) {
            string name = person.get_name();
            std::transform(name.begin(), name.end(), name.begin(), ::toupper);
            return name;
        }
    );
    cout << "Elements of the transformed vector" << endl;
    for (const auto& ele: tfx_people)
        cout << ele << endl;

    return 0;
}
