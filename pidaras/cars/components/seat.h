#ifndef COMPONENTS_SEATS_SEAT_H
#define COMPONENTS_SEATS_SEAT_H
#include <iostream>
#include <stdint.h>
#include <string.h>
#include <sstream>

namespace Cars::Components {

    enum SeatType {
        SEAT,
        MAIN_TOP,
        MAIN_BOTTOM,
        SIDE_TOP,
        SIDE_BOTTOM,
        INVALID
    };

    struct Seat {
        SeatType type;
        int number;
        int price;
        bool taken = false;
        std::string ToString() const;
        void Take() {
            taken = true;
        }
    };

}

std::ostream& operator <<(std::ostream& out, Cars::Components::Seat& s);


#endif
