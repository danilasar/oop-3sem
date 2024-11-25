#include <exception>
#include <string>
namespace Cars::Errors {
    class CarError : public std::exception
    {
    protected:
        std::string message;
    public:
        CarError(const std::string& message) : message{message} {}
        const char* what() const noexcept override {
            return message.c_str();
        }
    };
}
