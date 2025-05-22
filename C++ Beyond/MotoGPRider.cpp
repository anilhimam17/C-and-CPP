#include "MotoGPRider.h"

// Defining the Getters
std::string MotoGPRider::get_bike_make() const {
    return bike_make;
}
int MotoGPRider::get_championship_pts() const {
    return championship_pts;
}

// Defining the Setters
void MotoGPRider::set_bike_make(std::string new_bike_make) {
    this->bike_make = new_bike_make;
}
void MotoGPRider::set_championship_pts(int new_points) {
    this->championship_pts = new_points;
}

// Constructors
MotoGPRider::MotoGPRider(std::string new_name, int new_age, std::string new_sport, std::string new_bike_make, int new_points) 
: SportsMan{new_name, new_age, new_sport}, bike_make{new_bike_make}, championship_pts{new_points} {
    std::cout << "MotoGPRider Constructor was called for: " << get_name() << " bike make: " << bike_make << std::endl;
}
MotoGPRider::MotoGPRider() : MotoGPRider{"None", 0, "None", "None", 0} {}

// Special Constructors
MotoGPRider::MotoGPRider(const MotoGPRider &copy_rider)
: SportsMan(copy_rider), bike_make{copy_rider.bike_make}, championship_pts{copy_rider.championship_pts} {
    std::cout << "Copy MotoGPRider Constructor was called for: " << bike_make << std::endl;
}
MotoGPRider::MotoGPRider(MotoGPRider &&move_rider)
: SportsMan(std::move(move_rider)), bike_make{std::move(move_rider.bike_make)}, championship_pts{std::move(move_rider.championship_pts)} {
    std::cout << "Move MotoGPRider Constructor was called for: " << bike_make << std::endl;
}

// Destructor
MotoGPRider::~MotoGPRider() {
    std::cout << "MotoGPRider Destructor was called for: " << bike_make << std::endl;
}