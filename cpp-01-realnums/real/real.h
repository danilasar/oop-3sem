#include <cstdint>

// потенциальные исключения
enum REALNUM_ERROR {
    DENUM_IS_ZERO, // знаменатель не может быть нулём
    TOO_MUCH, // слишком большое число в числителе или в знаменателе
    ILLEGAL_NUMBER // число не соответствует ОДЗ (бросается из-под капота log10)
};

class real {
    double dec;
    static int gcd(int a, int b);
    static float log10(int num);
    static int numlen(int num);
    static void int_to_string(int num, char *str, int *index);
    void update();
public:
    // возможные значения числителя и знаменателя ограничены, чтобы избежать многих проблем с арифметикой
    constexpr static const int max_value = (INT32_MAX >> 1) / 2;
    constexpr static const double epsilon = 1e-6;
    // числитель
    int n;
    // знаменатель
    int m;

    real();
    real(int n, int m);

    real operator+(const real& r) const;
    real operator-(const real& r) const;
    real operator*(const real& r) const;
    real operator/(const real& r) const;

    real& operator+=(const real& r);
    real& operator-=(const real& r);
    real& operator*=(const real& r);
    real& operator/=(const real& r);

    real operator+(const int& r) const;
    real operator-(const int& r) const;
    real operator*(const int& r) const;
    real operator/(const int& r) const;

    real& operator+=(const int& r);
    real& operator-=(const int& r);
    real& operator*=(const int& r);
    real& operator/=(const int& r);

    bool operator<(const real& r) const;
    bool operator<=(const real& r) const;
    bool operator==(const real& r) const;
    bool operator!=(const real& r) const;
    bool operator>=(const real& r) const;
    bool operator>(const real& r) const;

    // возвращает результат деления числителя на знаменатель
    double to_double() const;
    // по сути округление до меньшего
    int to_int() const;
    char* to_string() const;
    // округление до ближайшего
    real round() const;
    // округление до большего
    real ceil() const;
    // округление до меньшего
    real floor() const;
    // дробная часть числа
    real frac() const;

    real clone() const;

};

real operator+(const int &l, const real &r);
real operator-(const int &l, const real &r);
real operator*(const int &l, const real &r);
real operator/(const int &l, const real &r);