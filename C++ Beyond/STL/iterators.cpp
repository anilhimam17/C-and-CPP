#include <iostream>
#include <vector>
using namespace std;

void forward_iter(vector<int>& collection) {
    vector<int>::iterator it = collection.begin();
    cout << "Start of the collection - Forward" << endl;
    while(it != collection.end()) {
        cout << *it << endl;
        it++;
    }
    cout << "End of the collection" << endl;
}

template <typename T>
void backward_iter(T& collection) {
    typename T::reverse_iterator it = collection.rbegin();
    cout << "Start of the collection - Reverse" << endl;
    while(it != collection.rend()) {
        cout << *it << endl;
        it++;
    }
    cout << "End of the collection" << endl;
}


int main(int argc, char const *argv[])
{
    vector<int> ints {1, 2, 3, 4, 5};
    vector<char> chars {'A', 'N', 'I', 'L'};
    forward_iter(ints);
    backward_iter(ints);
    backward_iter(chars);
    return 0;
}
