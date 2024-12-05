//
// Created by danilasar on 05.12.2024.
//

#include "error.h"

error::error(const char *message): message{message} { }

const char *error::what() const noexcept {
        char* result = (char*)malloc(strlen(prefix) + strlen(message) + 1);
        strcpy(result, prefix);
        strcat(result, message);
        return result;
}

