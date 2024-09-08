#include <stdio.h>
#include "real/real.h"

int main() {
    printf("%s\n", (real { 1, 5 } + real { 1, 5}).to_string());
    printf("%s\n", (real { -1, 5 } + real { 1, 5}).to_string());
    printf("%s\n", (real { -2, 5 } + real { 1, 5}).to_string());
    printf("%s\n", (real { -2, 5 } - real { 1, 5}).to_string());
    printf("%s\n", (real { -1, 5 } * real { -2, 5}).to_string());
    printf("%s\n", (real { 1, 5 } / real { 1, 5}).to_string());
    printf("%s\n", (real { 2, 7 } / real { 4, 7}).to_string());
    return 0;
}
