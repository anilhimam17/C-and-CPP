#ifndef _MOTOGPRIDER_H_
#define _MOTOGPRIDER_H_

#include "SportsMan.h"

// Public Inheritance Achieved in CPP
class MotoGPRider : public SportsMan {
    private:
        std::string bike_make;
        int championship_pts;
    public:
        // Getters
        std::string get_bike_make() const;
        int get_championship_pts() const;

        // Setters
        void set_bike_make(std::string new_bike_make);
        void set_championship_pts(int new_points);

        // Constructors
        MotoGPRider(std::string new_name, int new_age, std::string new_sport, std::string new_bike_make, int new_points);
        MotoGPRider();

        // Special Constructors
        MotoGPRider(const MotoGPRider &copy_rider);
        MotoGPRider(MotoGPRider &&move_rider);

        // Destructor
        ~MotoGPRider();
};

#endif