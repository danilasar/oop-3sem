#include <iostream>
#include "components/toilet.h"
class Car {
    Car* prev = nullptr;
    Car* next = nullptr;

public:
    Car();
    std::string ToString();
}
std::ostream& operator <<(std::ostream& out, Car& c) {
    out << c.ToString();
}
std::ostream& operator <<(std::ostream& out, Car c) {
    out << &c;
}

