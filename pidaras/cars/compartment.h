#ifndef _CARS_COMPARTMENT_H
#define _CARS_COMPARTMENT_H
#include "car.h"
namespace Cars {
    class Compartment : public Car {
    protected:
        int compartmentsCount; // количество купе
    public:
        Compartment();
        Compartment(bool supportsInvalids);
        int GetCompartmentsCount() const;
    };
}

#endif