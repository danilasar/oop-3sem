#include <stdio.h>
#include "cars/cars.h"
#include "utils/vector.h"

int main() {
    std:: cout << "aboba\n";
    Cars::Car* car = new Cars::Compartment();
    for(int i = 5; i < std::min(10, car->GetSeats()->size()); ++i) {
        car->GetSeats()->get(i)->Take();
    }
    std::cout << car->ToString();
    return 0;
}
