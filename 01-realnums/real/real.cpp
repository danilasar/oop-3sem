/*
 * Здесь реализованы методы класса real: конструктор, округления, а также приведения к double, string и int
 */
#include "real.h"
#include <stdlib.h>

real::real() {
    dec = n = 0; m = 1;
}

real::real(int n, int m) {
    this->n = n;
    this->m = m;
    update();
}

void real::update() {
    // проверка сликом больших значений
    if(n > max_value || m > max_value) {
        throw REALNUM_ERROR::TOO_MUCH;
    }
    // проверка нуля и минуса в знаменателе
    if(m == 0) {
        throw REALNUM_ERROR::DENUM_IS_ZERO;
    }
    if(m < 0) {
        n *= -1;
        m *= -1;
    }

    // сокращение дроби
    int gcd;
    if(n < 0) {
        gcd = real::gcd(n * -1, m);
    } else {
        gcd = real::gcd(n, m);
    }
    n /= gcd;
    m /= gcd;

    dec = (double)n / m;
}

double real::to_double() const {
    return dec;
}

int real::to_int() const {
    return (int)dec;
}

// преобразовывает рациональное число real в строку вида "n/m"
char *real::to_string() const {
    int strlen = numlen(n) + 1 + numlen(m) + 1; // длины чисел m и n, а также слеш
    char* str = static_cast<char*>(malloc(strlen)); // выделяем память для будущей строки
    int i = 0;
    int_to_string(n, str, &i);
    str[i] = '/';
    ++i;
    int_to_string(m, str, &i);
    str[strlen - 1] = '\0';
    return str;
}


// округление до ближайшего
real real::round() const {
    if(frac().n >= m / 2) {
        return ceil();
    } else {
        return floor();
    }
}

// округление до большего
real real::ceil() const {
    //*(((int*)&fracval) + 1) &= 0x7fffffff; // абсолютное значение fracval
    if(frac().n == 0) {
        return {n, m};
    }
    return *this + real {m, m};
}

// округление до меньшего
real real::floor() const {
    return {m * (int)dec, m};
}

// дробная часть числа
real real::frac() const {
    return {n % m, m};
}

int real::gcd(int a, int b) {
    if (a % b == 0)
        return b;
    if (b % a == 0)
        return a;
    if (a > b)
        return gcd(a % b, b);
    return gcd(a, b%a);
}

real real::clone() const {
    return real(n, m);
}

