#include "static_class.h"

// Intialising the static class member
int StaticClass::num_obj = 0;

// Declaring the static class function
int StaticClass::get_num_obj() {
    return num_obj;
}

// Constructor
StaticClass::StaticClass(std::string name) : name{name} {
    num_obj++;
}

// Destructor 
StaticClass::~StaticClass() {
    num_obj--;
}
