#include <iostream>
#include "static_class.h"
using namespace std;

int main(int argc, char const *argv[])
{
    StaticClass obj1 = StaticClass("Firt Static Class");
    cout << obj1.get_num_obj() << endl;
    StaticClass obj2 = StaticClass("Second Static Class");
    cout << obj1.get_num_obj() << endl;
    cout << obj2.get_num_obj() << endl;
    cout << StaticClass::get_num_obj() << endl;
    return 0;
}
