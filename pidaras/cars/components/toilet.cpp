#include "toilet.h"
#include "../errors/toilet_error.h"
#include <sstream>

using namespace Cars::Components;
using namespace Cars::Errors;

Toilet::Toilet(ToiletType type) {
    this->type = type;
    is_free = is_working = true;
}

bool Toilet::IsFree() const {
    return is_free;
}

bool Toilet::IsWorking() const {
    return is_working;
}

bool Toilet::IsAvailable() const {
    return is_working && is_free;
}

void Toilet::TakeToilet() {
    if(!IsAvailable()) {
        throw new ToiletError("Туалет недоступен");
    }
    is_free = false;
}

void Toilet::VacateToilet() {
    if(IsFree()) {
        throw new Cars::Errors::ToiletError("Туалет и так свободен");
    }
    is_free = true;
}

void Toilet::OpenToilet() {
    is_working = true;
}

void Toilet::CloseToilet() {
    is_working = false;
}

void Toilet::ToggleToilet() {
    is_working = !is_working;
}

ToiletType Toilet::GetToiletType() const {
    return type;
}

std::string Toilet::ToString() const {
    std::ostringstream os;
    switch(type) {
        case Invalids:
            os << "Инвалидский\t";
            break;
        case Male:
            os << "Мужской\t\t";
            break;
        case Female:
            os << "Женский\t\t";
            break;
        case Unisex:
            os << "Туалет\t\t";
            break;
    }
    if(is_working) {
        os << "открыт";
    } else {
        os << "закрыт";
    }
    os << '\t';
    if(is_free) {
        os << "свободен";
    } else {
        os << "занят";
    }
    return os.str();
}
