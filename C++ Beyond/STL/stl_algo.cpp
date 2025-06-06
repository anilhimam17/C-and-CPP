#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Helper Functions
vector<int>::iterator find_val(vector<int>& vec, int input) {
    auto loc = find(vec.begin(), vec.end(), input);
    return loc;
}

void power(vector<int>& vec) {
    for_each(
        vec.begin(), vec.end(), 
        [](int &x) {
            x *= x;
        }
    );
}

int alpha_counter(vector<char>& vec, char& search_val) {
    transform(vec.begin(), vec.end(), vec.begin(), ::tolower);
    return count(vec.begin(), vec.end(), search_val);
}

int main(int argc, char const *argv[])
{
    vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Input for find value
    int input;
    cout << "Enter number for search: ";
    cin >> input;
    auto loc = find_val(vec, input);

    // Returns an iterators compared against end for conditional
    if (loc != vec.end()) {
        cout << "Location of the search ele: " << (loc - vec.begin()) << endl;
    } else {
        cout << "The Element was not found" << endl;
    }

    // Doesn't return a container but modifies the copy / original
    power(vec);
    for (auto ele: vec) {
        cout << ele << endl;
    }

    // Transforms the container and applies a counter
    vector<char> name {'A', 'n', 'i', 'l', ' ', 'H', 'i', 'm', 'a', 'm'};
    cout << "Enter alphabet to count: ";
    char alpha;
    cin >> alpha;
    cout << "Count of " << alpha << " = " << alpha_counter(name, alpha) << endl;

    // Counts on a condition
    int count_cond = count_if(vec.begin(), vec.end(), [](int x) {return x > 20;});
    cout << "The count of numbers > 20 is " << count_cond << endl;
    return 0;
}
