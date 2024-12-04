#include <stdio.h>
#include "cars/cars.h"
#include "utils/vector.h"

int main() {
    Cars::Car* car = new Cars::Car();
    for(int i = 5; i < std::min(10, car->GetSeats()->size()); ++i) {
        car->GetSeats()->get(i)->Take();
    }
    std::cout << car->ToString();
    return 0;
}
