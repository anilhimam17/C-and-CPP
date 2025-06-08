#include <iostream>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
    map<string, int> people {
        {"Anil", 23}, {"Pavan", 21}
    };

    // Traversing the map
    cout << "Traversing all the key-val pairs of the dictionary" << endl;
    for (auto ele: people) {
        cout << "Key: " << ele.first << " Value: " << ele.second << endl;
    }

    // Insertion Approach - 1
    auto mm = pair<string, int> {"Marc", 32};
    people.insert(mm);

    // Insertion Approach - 2
    people.insert(make_pair("Fabio", 27));

    // Insertion Approach - 3
    people["Rafa"] = 37;

    cout << "Traversing the Updated Map" << endl;
    for (auto ele: people) {
        cout << "Key: " << ele.first << " Value: " << ele.second << endl;
    }
    
    // Erasing
    auto it = people.begin();
    while (it != people.end()) {
        if (it->second > 30) {
            it = people.erase(it);
        } else {
            it++;
        }
    }
    cout << "Updated Map of people after removing retirees" << endl;
    for (auto ele: people)
        cout << "Key: " << ele.first << " Value: " << ele.second << endl;
    
    return 0;
}
