#include <iostream>
#include "Device.h"
using namespace std;

int main() {
    Device newDevice;
    newDevice.set_name("iPhone");
    newDevice.set_price(1100);
    newDevice.set_quantity(1);

    cout << "Here are the specs of the new device: " << endl;
    cout << "Name: " << newDevice.get_name() << endl;
    cout << "Price: " << newDevice.get_price() << endl;
    cout << "Quantity: " << newDevice.get_quantity() << endl;

    int newPrice = 0;
    cout << "\nEnter the new price for the device: ";
    cin >> newPrice;
    newDevice.set_price(newPrice);

    cout << "New Specs: " << endl;
    cout << "Name: " << newDevice.get_name() << endl;
    cout << "Price: " << newDevice.get_price() << endl;
    cout << "Quantity: " << newDevice.get_quantity() << endl;

    return 0;
}