#include "car.h"
#include "components/seat.h"
#include "components/toilet.h"
#include "../utils/vector.h"
using namespace Cars;
Car::Car(int number) {
    seatsTotal = seatsFree = 0;
    name = "Вагон вольного типа";
    this->number = number;
}

std::string Car::ToString() {
    std::ostringstream os;
    int sumPrice = 0, sumEarned = 0;
    os << "===\n" << name << " под номером " << std::to_string(number) << "\n\nМеста:";
    if(seats.size() == 0) {
        os << " отсуствуют\n";
    } else {
        os << '\n';
        for(int i = 0; i < seats.size(); ++i) {
            Components::Seat* seat = seats.get(i);
            os << seat->ToString() << '\n';
            sumPrice += seat->price;
            if(seat->taken) sumEarned += seat->price;
        }
    }
    os << "\nТуалеты:";
    if(toilets.size() == 0) {
        os << " отсуствуют\n";
    } else {
        os << '\n';
        for (int i = 0; i < toilets.size(); ++i) {
            os << toilets.get(i)->ToString() << '\n';
        }
    }
    os << "\nСуммарная стоимость билетов: " << sumPrice << '\n';
    os << "Доход от продажи билетов: " << sumEarned << '\n';
    return os.str();
}

void Car::AttachTo(Car *car) {
    if(prev != nullptr) {
        prev->next = nullptr; // todo throw exception
    }
    prev = car;
}

void Car::Deattach() {
    prev = nullptr;
}

Car *Car::GetPreviousCar() {
    return prev;
}

Car *Car::GetNextCar() {
    return next;
}

int Car::GetSeatsCount() {
    return seatsTotal;
}

int Car::GetFreeSeatsCount() {
    return seatsFree;
}

Car::~Car() {

}

std::ostream& operator <<(std::ostream& out, Car& c) {
    out << c.ToString();
    return out;
}
std::ostream& operator <<(std::ostream& out, Car c) {
    out << &c;
    return out;
}

Vector<Components::Toilet> *Car::GetToilets() {
    return &toilets;
}

Vector<Components::Seat> *Car::GetSeats() {
    return &seats;
}
