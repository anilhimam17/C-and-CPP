#include <iostream>
#include "SportsMan.h"
#include "MotoGPRider.h"
using namespace std;

void display(const SportsMan &sportsman) {
    cout << sportsman.get_name() << endl;
    cout << sportsman.get_age() << endl;
    cout << sportsman.get_sport() << endl;
    cout << endl;
}
void display(const MotoGPRider &motogprider) {
    cout << motogprider.get_name() << endl;
    cout << motogprider.get_age() << endl;
    cout << motogprider.get_sport() << endl;
    cout << motogprider.get_bike_make() << endl;
    cout << motogprider.get_championship_pts() << endl;
    cout << endl;
}

int main(int argc, char const *argv[])
{
    SportsMan new_sportsman = SportsMan("Marc Marquez", 32, "MotoGP");
    MotoGPRider new_motogprider = MotoGPRider("Fabio Quattararo", 26, "MotoGP", "Yamaha", 58);

    display(new_sportsman);
    display(new_motogprider);
    return 0;
}
