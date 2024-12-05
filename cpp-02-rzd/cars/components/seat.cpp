#include "seat.h"

namespace Cars::Components {
    std::string Seat::ToString() const  {
        std::ostringstream os;
        switch(type) {
            case SEAT:
                os << "Сидячее место\t\t";
                break;
            case MAIN_TOP:
                os << "Верхняя полка\t\t";
                break;
            case MAIN_BOTTOM:
                os << "Нижняя полка\t\t";
                break;
            case SIDE_TOP:
                os << "Верхняя боковая\t\t";
                break;
            case SIDE_BOTTOM:
                os << "Нижняя боковая\t\t";
                break;
            case INVALID:
                os << "Место для инвалида\t";
                break;
        }
        os << " №" << std::to_string(number) << "\t\t" << price << " руб.\t";
        if(taken) {
            os << "занято";
        } else {
            os << "свободно";
        }
        return os.str();
    }
}

std::ostream& operator <<(std::ostream& out, Cars::Components::Seat& s) {
    out << s.ToString();
    return out;
}