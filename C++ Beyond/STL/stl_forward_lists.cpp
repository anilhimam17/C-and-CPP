#include <iostream>
#include <forward_list>
#include <iterator>
using namespace std;

int main(int argc, char const *argv[])
{
    forward_list<int> f_list {1, 2, 3, 4};

    // Standard Forward List functions
    cout << "Front of the forward list: " << f_list.front() << endl;
    cout << "Maxsize of the forward list: " << f_list.max_size() << endl;
    f_list.push_front({10});
    f_list.emplace_front(100);
    
    // Traversing the elements of the forward list
    cout << "Elements of the Forward List" << endl;
    for (auto ele: f_list)
        cout << "Element: " << ele << endl;

    // Using the *_after functions
    auto loc = find(f_list.begin(), f_list.end(), 3);
    if (loc != f_list.end()) {
        f_list.emplace_after(loc, 1000);
    }
    cout << "Elements of the list after using emplace_after" << endl;
    for (auto it = f_list.begin(); it != f_list.end(); it++) {
        cout << "Element: " << *it << endl;
    }

    loc = find(f_list.begin(), f_list.end(), 1000);
    if (loc != f_list.end()) {
        f_list.insert_after(loc, -1000);
    }
    cout << "Elements of the list after using insert_after" << endl;
    for (auto it = f_list.begin(); it != f_list.end(); it++) {
        cout << "Element: " << *it << endl;
    }

    loc = find(f_list.begin(), f_list.end(), -1000);
    if (loc != f_list.end()) {
        f_list.erase_after(loc);
    }
    cout << "Elements of the list after using erase_after" << endl;
    for (auto it = f_list.begin(); it != f_list.end(); it++) {
        cout << "Element: " << *it << endl;
    }
    return 0;
}
