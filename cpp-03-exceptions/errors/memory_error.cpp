//
// Created by danilasar on 05.12.2024.
//

#include "memory_error.h"

memory_error::memory_error(const char *message) : error(message) {
    prefix = "Ошибка памяти: ";
}
