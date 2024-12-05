#include "compartment.h"
using namespace Cars;
Compartment::Compartment(): Compartment(false) {};

Compartment::Compartment(bool supportsInvalids): Car() {
    name = "Купейный вагон";
    toilets.push(Components::Toilet(Components::ToiletType::Unisex));
    compartmentsCount = 5;
    int lastSeatId = 0;
    for(int i = 0; i < compartmentsCount * 4; i += 4) {
        seats.push(Components::Seat(Components::MAIN_BOTTOM, i + 1, 7000));
        seats.push(Components::Seat(Components::MAIN_TOP, i + 2, 6000));
        seats.push(Components::Seat(Components::MAIN_BOTTOM, i + 3, 7000));
        seats.push(Components::Seat(Components::MAIN_TOP, i + 4, 8000));
        lastSeatId = i + 4;
    }
    if(supportsInvalids) {
        name += " с местами для инвалидов";
        toilets.push(Components::Toilet(Components::ToiletType::Invalids));
        ++compartmentsCount;
        seats.push(Components::Seat(Components::INVALID, lastSeatId + 1, 7000));
        seats.push(Components::Seat(Components::INVALID, lastSeatId + 2, 7000));
        lastSeatId += 2;
    } else {
        toilets.push(Components::Toilet(Components::ToiletType::Unisex));
        for(int i = 0; i <= 8; i += 4) {
            seats.push(Components::Seat(Components::MAIN_BOTTOM, lastSeatId + i + 1, 7000));
            seats.push(Components::Seat(Components::MAIN_TOP, lastSeatId + i + 2, 6000));
            seats.push(Components::Seat(Components::MAIN_BOTTOM, lastSeatId + i + 3, 7000));
            seats.push(Components::Seat(Components::MAIN_TOP, lastSeatId + i + 4, 8000));
            lastSeatId = i + 4;
        }
        compartmentsCount += 2;
    }
}

int Compartment::GetCompartmentsCount() const {
    return compartmentsCount;
}
