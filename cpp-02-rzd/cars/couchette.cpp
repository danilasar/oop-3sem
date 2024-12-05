#include "couchette.h"
using namespace Cars;
Couchette::Couchette(): Compartment(false) {
    name = "Плацкартный вагон";
    compartmentsCount = 7;
    seats.clear();
    for(int i = 0; i < compartmentsCount * 6; i += 6) {
        seats.push(Components::Seat(Components::MAIN_BOTTOM, i + 1, 7000));
        seats.push(Components::Seat(Components::MAIN_TOP, i + 2, 6000));
        seats.push(Components::Seat(Components::MAIN_BOTTOM, i + 3, 7000));
        seats.push(Components::Seat(Components::MAIN_TOP, i + 4, 8000));
        seats.push(Components::Seat(Components::SIDE_BOTTOM, i + 5, 6000));
        seats.push(Components::Seat(Components::SIDE_TOP, i + 6, 5000));
    }
};
