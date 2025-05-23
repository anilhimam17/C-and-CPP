#include <iostream>
#include "SportsMan.h"
#include "MotoGPRider.h"
using namespace std;

int main(int argc, char const *argv[])
{
    SportsMan new_sportsman = SportsMan("Marc Marquez", 32, "MotoGP");
    MotoGPRider new_motogprider = MotoGPRider("Fabio Quattararo", 26, "MotoGP", "Yamaha", 58);

    cout << "Here is a SportsMan: " << endl;
    new_sportsman.display_sportsman();
    cout << endl;

    cout << "Here is a MotoGP Rider: " << endl;
    new_motogprider.display_sportsman();
    cout << endl;
    
    return 0;
}
