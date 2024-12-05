#ifndef REALNUMS_FILE_ERROR_H
#define REALNUMS_FILE_ERROR_H
#include "error.h"


class file_error: public error {
    public:
        explicit file_error(const char* message);
};


#endif // REALNUMS_FILE_ERROR_H
