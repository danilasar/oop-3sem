#include "real.h"

bool real::operator<(const real &r) const {
    return dec < r.dec;
}

bool real::operator<=(const real &r) const {
    return dec <= r.dec;
}

bool real::operator==(const real &r) const {
    return dec == r.dec;
}

bool real::operator!=(const real &r) const {
    return dec != r.dec;
}

bool real::operator>=(const real &r) const {
    return dec >= r.dec;
}

bool real::operator>(const real &r) const {
    return dec > r.dec;
}
