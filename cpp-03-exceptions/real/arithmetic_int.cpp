/*
 * Арифметика с целыми числами. Определены операции сложения, вычитания,
 * умножения и деления для пар <real, int> и <int, real>
 */
#include "real.h"

// Бинарный оператор --- обёртка над соответстующим +=, -= и т. д.
real real::operator+(const int &r) const {
    return clone() += r;
}

real real::operator-(const int &r) const {
    return clone() -= r;
}

real real::operator*(const int &r) const {
    return clone() *= r;
}

real real::operator/(const int &r) const {
    return clone() /= r;
}
// Для коммутативности
real operator+(const int &l, const real &r) {
    return r + l;
}
real operator-(const int &l, const real &r) {
    return (r + -l) * -1;
}
real operator*(const int &l, const real &r) {
    return r * l;
}
real operator/(const int &l, const real &r) {
    return real {r.m, r.n} * l;
}

real &real::operator+=(const int &r) {
    n += r * m;
    update();
    return *this;
}

real &real::operator-=(const int &r) {
    return *this += -r;
}


real &real::operator*=(const int &r) {
    n *= r;
    update();
    return *this;
}

real &real::operator/=(const int &r) {
    m *= r;
    update();
    return *this;
}