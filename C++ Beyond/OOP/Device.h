#ifndef _DEVICE_H_
#define _DEVICE_H_

#include <string>

class Device {
    private:
        std::string name;
        int price;
        int quantity;

    public:
        std::string get_name();
        void set_name(std::string name);

        int get_price();
        void set_price(int price);

        int get_quantity();
        void set_quantity(int quantity);
};

#endif