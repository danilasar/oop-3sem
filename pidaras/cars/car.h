#ifndef _CARS_CAR_H
#define _CARS_CAR_H
#include <iostream>
#include <stdint.h>
#include <string.h>
#include "components/toilet.h"
#include "components/seat.h"
#include "../utils/vector.h"
namespace Cars {
    class Car {
    protected:
        int32_t number;
        std::string name;
        Vector<Components::Toilet> toilets;
        Vector<Components::Seat> seats;
        int seatsTotal;
        int seatsFree;

        Car *prev = nullptr;
        Car *next = nullptr;

    public:
        explicit Car(int number = 0);
        ~Car();

        void AttachTo(Car *car);
        void Deattach();
        Car *GetPreviousCar();
        Car *GetNextCar();
        int GetSeatsCount();
        int GetFreeSeatsCount();
        Vector<Components::Toilet> *GetToilets();
        Vector<Components::Seat> *GetSeats();

        std::string ToString();
        friend std::ostream& operator <<(std::ostream& out, Cars::Car& c);
        friend std::ostream& operator <<(std::ostream& out, Cars::Car c);
    };
}

#endif