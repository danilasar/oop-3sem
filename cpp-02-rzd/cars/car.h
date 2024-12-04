#include <iostream>
#include <stdint.h>
#include <string.h>
#include "components/toilet.h"
class Car {
    int32_t number;
    std::string name;

    Car* prev = nullptr;
    Car* next = nullptr;

public:
    Car();
    std::string ToString();
};

std::ostream& operator <<(std::ostream& out, Car& c) {
    out << c.ToString();
}
std::ostream& operator <<(std::ostream& out, Car c) {
    out << &c;
}

