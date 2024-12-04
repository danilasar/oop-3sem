#include "coach.h"
#include "../utils/vector.h"
using namespace Cars;

Coach::Coach(): Car() {
    toilets = Vector<Components::Toilet>();
    for(int i = 0; i < 60; ++i) {
        seats.push(Components::Seat(Components::SEAT, i, 300));
    }
}
