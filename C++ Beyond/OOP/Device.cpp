#include "Device.h"

// Getters and Setters
std::string Device::get_name() {
    return name;
}
void Device::set_name(std::string name) {
    this -> name = name;
}

int Device::get_price() {
    return price;
}
void Device::set_price(int price) {
    this -> price = price;
}

int Device::get_quantity() {
    return quantity;
}
void Device::set_quantity(int quantity) {
    this -> quantity = quantity;
}