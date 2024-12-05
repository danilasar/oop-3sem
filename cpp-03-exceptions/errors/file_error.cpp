#include "file_error.h"

file_error::file_error(const char *message) : error(message) {
    prefix = "Ошибка файловой системы: ";
}
