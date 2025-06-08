#include <iostream>
#include <set>
using namespace std;

int main(int argc, char const *argv[])
{
    set<int> nums {};
    set<int> nums_10 {10, 10, 10, 10};

    // Traversing the Sets
    cout << "Default Set" << endl;
    for (auto ele: nums) {
        cout << "Element: " << ele << endl;
    }

    cout << "Initialised Set" << endl;
    auto it = nums_10.begin();
    while (it != nums_10.end()) {
        cout << "Element: " << *it << endl;
        it++;
    }
    cout << "Size of the Set: " << nums_10.size() << endl;
    cout << "Max Size of the Set: " << nums_10.max_size() << endl;

    // Runtime-Insertion
    int input {};
    for (int i = 0; i < 10; i++) {
        cout << "Enter Element for Insertion: ";
        cin >> input;
        if (nums.find(input) == nums.end()) {
            auto insert_stat = nums.insert(input);
            cout << "Insertion Status -> Location: " << *insert_stat.first << " Status: " << insert_stat.second << endl;
        }
    }

    // Traversing the new set
    cout << "Updated set with run-time inputs" << endl;
    for (auto ele: nums) {
        cout << "Element: " << ele << endl;
    }

    // Erasing all the odd numbers
    for (auto it = nums.begin(); it != nums.end(); ) {
        if (*it % 2 == 1) {
            it = nums.erase(it);
        } else {
            it++;
        }
    }
    cout << "Updated set of elements after erasing all the odd numbers" << endl;
    for (auto ele: nums) {
        cout << "Element: " << ele << endl;
    }

    return 0;
}
