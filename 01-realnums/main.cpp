#include <stdio.h>
#include "real/real.h"
#include "list.h"

int main() {
    list<real> l;
    l.push_back(real { 1, 5 } + real { 1, 5});
    l.push_back(real { -1, 5 } + real { 1, 5});
    l.push_back(real { -2, 5 } + real { 1, 5});
    l.push_back(real { -2, 5 } - real { 1, 5});
    l.push_back(real { -1, 5 } * real { -2, 5});
    l.push_back(real { 1, 5 } / real { 1, 5});
    l.push_back(real { 2, 7 } / real { 4, 7});
    auto cur = l.begin();
    while(cur != l.end()) {
        printf("%s\n", cur->value.to_string());
        cur = cur->next;
    }
    return 0;
}
