#ifndef REALNUMS_MEMORY_ERROR_H
#define REALNUMS_MEMORY_ERROR_H
#include "error.h"


class memory_error: public error {
public:
    explicit memory_error(const char* message);
};


#endif //REALNUMS_MEMORY_ERROR_H
