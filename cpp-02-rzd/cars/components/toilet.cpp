#include "toilet.h"
#include "../errors/toilet_error.h"

using namespace Cars::Components;

Toilet::Toilet(ToiletType type) {
    this->type = type;
    is_free = is_working = true;
}

bool Toilet::IsFree() {
    return is_free;
}

bool Toilet::IsWorking() {
    return is_working;
}

bool Toilet::IsAvailable() {
    return is_working && is_free;
}

void Toilet::TakeToilet() {
    if(!IsAvailable()) {
        throw new Cars::Errors::ToiletError("Туалет недоступен");
    }
    is_free = false;
}

void Toilet::VakateToilet() {
    if(IsFree()) {
        throw new Cars::Errors::ToiletError("Туалет и так свободен");
    }
    is_free = true;
}

void OpenToilet() {
    is_working = true;
}

void CloseToilet() {
    is_working = false;
}

void ToggleToilet() {
    is_working = !is_working;
}
