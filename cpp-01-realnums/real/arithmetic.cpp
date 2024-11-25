/*
 * Арифметические операции с двумя экземплярами real
 */
#include "real.h"

real real::operator+(const real &r) const {
    return clone() += r;
}

real real::operator-(const real &r) const {
    return clone() -= r;
}

real real::operator*(const real &r) const {
    return clone() *= r;
}

real real::operator/(const real &r) const {
    return clone() /= r;
}

real &real::operator+=(const real &r) {
    if(m == r.m) {
        n += r.n;
    } else {
        n = n * r.m + m * r.n;
    }
    update();
    return *this;
}

real &real::operator-=(const real &r) {
    return *this += (r * -1);
}


real &real::operator*=(const real &r) {
    n *= r.n;
    m *= r.m;
    update();
    return *this;
}

real &real::operator/=(const real &r) {
    n *= r.m;
    m *= r.n;
    update();
    return *this;
}