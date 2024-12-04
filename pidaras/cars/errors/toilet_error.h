#ifndef _CARS_ERROR_TOILET_H
#define _CARS_ERROR_TOILET_H
#include <exception>
#include <string>
#include "car_error.h"
namespace Cars::Errors {
    class ToiletError : public CarError
    {
    public:
        explicit ToiletError(const std::string &message) noexcept: CarError(message) {

        }
    };
}
#endif