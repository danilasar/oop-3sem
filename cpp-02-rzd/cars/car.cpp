#include "car.h"

Car::Car(int number = 0) {
    name = "Вагон вольного типа";
    this->number = number;
}

std::string Car::ToString() {
    return name + " под номером " + number;
}