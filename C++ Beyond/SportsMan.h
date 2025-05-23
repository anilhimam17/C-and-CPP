#ifndef _SPORTSMAN_H_
#define _SPORTSMAN_H_

#include <iostream>
#include <string>

class SportsMan {
    private:
        std::string name;
        int age;
        std::string sport;
    public:
        // Member functions
        void display_sportsman();

        // Getters
        std::string get_name() const;
        int get_age() const;
        std::string get_sport() const;

        // Setters
        void set_name(std::string new_name);
        void set_age(int new_age);
        void set_sport(std::string new_sport);

        // Constructors
        SportsMan(std::string new_name, int new_age, std::string new_sport);
        SportsMan();

        // Special Constructors
        SportsMan(const SportsMan &copy_sportsman);
        SportsMan(SportsMan &&move_sportsman);

        // Destructor
        ~SportsMan();
};

#endif