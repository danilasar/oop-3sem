#ifndef REALNUMS_ERROR_H
#define REALNUMS_ERROR_H


#include <exception>
#include <cstring>
#include <cstdlib>
#include <cstdio>

class error : public std::exception {
private:
    const char *message;
protected:
    const char *prefix = "Ошибка: ";
public:
    explicit error(const char* message);
    const char* what() const noexcept override;
};


#endif
