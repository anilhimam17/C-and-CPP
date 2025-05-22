#include "SportsMan.h"

// Defining the Getters
std::string SportsMan::get_name() const {
    return name;
}
int SportsMan::get_age() const {
    return age;
}
std::string SportsMan::get_sport() const {
    return sport;
}

// Defining the Setters
void SportsMan::set_name(std::string new_name) {
    this->name = new_name;
}
void SportsMan::set_age(int new_age) {
    this->age = new_age;
}
void SportsMan::set_sport(std::string new_sport) {
    this->sport = new_sport;
}

// Constructors
SportsMan::SportsMan(std::string new_name, int new_age, std::string new_sport)
: name{new_name}, age{new_age}, sport{new_sport} {
    std::cout << "SportsMan Constructor was called for: " << name << std::endl;
};
SportsMan::SportsMan() : SportsMan{"None", 0, "None"} {};

// Special Constructors
SportsMan::SportsMan(const SportsMan &copy_sportsman)
: name{copy_sportsman.name}, age{copy_sportsman.age}, sport{copy_sportsman.sport} {
    std::cout << "SportsMan Copy Constructor was called for: " << name << std::endl;
}
SportsMan::SportsMan(SportsMan &&move_sportsman)
: name{std::move(move_sportsman.name)}, age{std::move(move_sportsman.age)}, sport{std::move(move_sportsman.sport)} {
    std::cout << "SportsMan Move Constructor was called for: " << name << std::endl;
}

// Destructor
SportsMan::~SportsMan() {
    std::cout << "SportsMan Destructor was called for: " << name << std::endl;
};