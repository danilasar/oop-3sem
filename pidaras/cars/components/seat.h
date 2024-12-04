#ifndef _SEATS_SEAT_H
#define _SEATS_SEAT_H

namespace Components {

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
    };

}

#endif
