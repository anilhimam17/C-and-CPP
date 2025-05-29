#include <iostream>
#include <sstream>
using namespace std;

template <typename T1>
T1 my_max(T1 a, T1 b) {
    return (a > b) ? a : b;
}

template <typename T1, typename T2>
string display(T1 a, T2 b) {
    stringstream oss;
    oss << "Max of A " << a << " B " << b << " is: ";
    return oss.str();
}

int main(int argc, char const *argv[])
{
    cout << "Applying function templates:" << endl;
    cout << display(10, 20) << my_max(10, 20) << endl;
    cout << display(22.01/7, 21.99/7) << my_max((22.01/7), (21.99/7)) << endl;
    cout << display(string("Anil"), string("anil")) << my_max(string("Anil"), string("anil"));
    return 0;
}
