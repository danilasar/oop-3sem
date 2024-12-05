#ifndef _CARS_COMPONENTS_TOILET_H
#define _CARS_COMPONENTS_TOILET_H
#include <iostream>
namespace Cars::Components {
    enum ToiletType {
        Invalids,
        Male,
        Female,
        Unisex
    };
    class Toilet {
    private:
        ToiletType type;
        bool is_free;
        bool is_working;
    public:
        explicit Toilet(ToiletType type = Unisex);
        ToiletType GetToiletType() const;

        bool IsFree() const;
        bool IsWorking() const;
        bool IsAvailable() const;

        void TakeToilet();
        void VacateToilet();

        void OpenToilet();
        void CloseToilet();
        void ToggleToilet();

        std::string ToString() const;
    };
};
#endif