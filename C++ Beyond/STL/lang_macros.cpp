#include <iostream>
using namespace std;

#define Max(a, b) ((a > b) ? a : b)

int main(int argc, char const *argv[])
{
    cout << "Applying language macros as generics: " << endl;
    cout << "Max of 10 and 20: " << Max(10, 20) << endl;
    cout << "Max of 3.14 and 6.64: " << Max((22/7), (6.64e-34)) << endl;
    cout << "Max of Anil and anil: " << Max(std::string("Anil"), std::string("anil")) << endl;
    return 0;
}
