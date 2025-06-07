#include <iostream>
#include <list>
#include <iterator>
using namespace std;

int main(int argc, char const *argv[])
{
    list<int> nums {1, 2, 3, 4, 5};
    list<int> nums_10(5, 10);

    list<int>::iterator it = nums.begin();
    cout << "Traversing through the list using a while loop and iterator" << endl;
    while (it != nums.end()) {
        cout << "Element: " << *it << endl;
        advance(it, 1);
    }

    cout << "Traversing through the list of initialised values using range-based loops" << endl;
    for (const auto& ele: nums_10) {
        cout << "Element: " << ele << endl;
    }

    // Insertion
    auto it_insert = find(nums.begin(), nums.end(), 4);
    nums.insert(it_insert, nums_10.begin(), nums_10.end());
    cout << "Traversing the elements of the newly inserted list" << endl;
    for (auto& ele: nums) {
        cout << ele << endl;
    }

    // Erasing
    nums.remove_if(
        [](int x) {
            return x == 10;
        }
    );
    cout << "Removing the duplicated elements" << endl;
    for (auto ele: nums) {
        cout << "Element: " << ele << endl;
    }

    // Resizing the list
    nums.resize(8);
    cout << "Resized list:" << endl;
    for (auto ele: nums) {
        cout << "Element: " << ele << endl;
    }

    return 0;
}
