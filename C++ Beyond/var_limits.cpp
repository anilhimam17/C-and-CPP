#include <iostream>
using namespace std;

#include <climits>
#include <cfloat>

int main(int argc, char const *argv[])
{
    cout << "Bit Precision Limits" << endl;
    cout << "Int_8 Minimum: " << INT8_MIN << endl;
    cout << "Int_16 Minimum: " << INT16_MIN << endl;
    cout << "Int_32 Minimum: " << INT32_MIN << endl;
    cout << "Int_64 Minimum: " << INT64_MIN << endl;
    cout << "Int_8 Maximum: " << INT8_MAX << endl;
    cout << "Int_16 Maximum: " << INT16_MAX << endl;
    cout << "Int_32 Maximum: " << INT32_MAX << endl;
    cout << "Int_64 Maximum: " << INT64_MAX << endl;
    
    cout << "\n\nGeneral Precision Limits" << endl;
    cout << "Int Min: " << INT_MIN << endl;
    cout << "Char Min: " << CHAR_MIN << endl;
    cout << "Short Min: " << SHRT_MIN << endl;
    cout << "Long Min: " << LONG_MIN << endl;
    cout << "Int Max: " << INT_MAX << endl;
    cout << "Char Max: " << CHAR_MAX << endl;
    cout << "Short Max: " << SHRT_MAX << endl;
    cout << "Long Max: " << LONG_MAX << endl;

    int number = 0;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Size of the number: " << sizeof(number) << " in bytes." << endl;
    return 0;
}
