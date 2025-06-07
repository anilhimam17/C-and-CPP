#include <iostream>
#include <deque>
using namespace std;

int main(int argc, char const *argv[])
{
    deque<int> deq;
    cout << "Elements of an uninitialised deque:" << endl;
    for (const auto& ele: deq) {
        cout << "Element: " << ele << endl;
    }

    deque<int> deq_init {1, 2, 3};
    cout << "Elements of an initialised deque:" << endl;
    for (const auto& ele: deq_init) {
        cout << "Element: " << ele << endl;
    }

    deq.push_front({1});
    deq.emplace_front(2);
    cout << "Element of deque of pushing:" << endl;
    for (const auto& ele: deq) {
        cout << ele << endl;
    }

    cout << "Size of deque: " << deq.size() << endl;

    deq_init.pop_front();
    cout << "Elements after popping the front" << endl;
    for (auto ele: deq_init)
        cout << ele << endl;
    return 0;
}
