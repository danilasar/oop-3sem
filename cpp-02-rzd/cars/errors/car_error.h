#ifndef _CARS_ERROR_CAR_H
#define _CARS_ERROR_CAR_H
#include <exception>
#include <string>
namespace Cars::Errors {
    class CarError : public std::exception
    {
    protected:
        std::string message;
    public:
        explicit CarError(const std::string& message) : message{message} {}
        const char* what() const noexcept override {
            return message.c_str();
        }
    };
}
#endif