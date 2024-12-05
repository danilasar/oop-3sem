#ifndef VECTOR_ERORR_H
#define VECTOR_ERORR_H
#include <exception>
#include <string>

class VectorError : public std::exception
{
protected:
    std::string message;
public:
    explicit VectorError(const std::string& message) : message{message} {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};


#endif //PIDARAS_VECTOR_ERORR_H
