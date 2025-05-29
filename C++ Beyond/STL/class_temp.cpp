#include <iostream>
#include <vector>
using namespace std;

// Generic Dictionary Class
template <class Key, class Value>
class Dictionary {
    private:
        Key dict_key;
        Value dict_value;
    public:
        // Helper function
        void display_pair() const {
            cout << "Key: " << dict_key << " Value: " << dict_value << endl;
        }

        // Getters
        Key get_key() const {return dict_key;}
        Value get_value() const {return dict_value;}

        // Setters
        void set_key(Key new_key) {
            this->dict_key = new_key;
        }
        void set_value(Value new_value) {
            this->dict_value = new_value;
        }

        // Constructor
        Dictionary(Key new_key, Value new_value) : dict_key{new_key}, dict_value{new_value} {}
};

int main(int argc, char const *argv[])
{
    // Creating a single generic dictionary for string and int
    Dictionary<string, int> str_int_dict = Dictionary<string, int>(string("A"), 10);

    // Creating a vector of a generic dictionary of string and int
    vector<Dictionary<string, int>> vec_str_int;

    // Taking input of the Key Value pairs
    string key;
    int value;
    for (int i = 0; i < 5; i++) {
        cout << "Enter Key: ";
        cin >> key;
        cout << "Enter Value: ";
        cin >> value;
        vec_str_int.push_back(Dictionary<string, int>(key, value));
    }

    // Displaying the Output
    cout << "Single Object Display" << endl;
    str_int_dict.display_pair();
    vec_str_int.push_back(str_int_dict);

    // Displaying output for the runtime defined vector
    cout << "A Vector of elements from the dictionary" << endl;
    for (auto elem: vec_str_int) {
        elem.display_pair();
    }

    return 0;
}
