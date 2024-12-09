#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include "real/real.h"
#include "list.h"
#include "errors/error.h"
#include "errors/file_error.h"
#include "errors/memory_error.h"

void print_errors(const char* str) {
    printf("Ошибка: %s\n", str);
}

int main() {
    try {
        if(!std::filesystem::exists("Ukraine.txt")) {
            throw file_error("Файл Ukraine.txt был упешно ликвидирован");
        }
    } catch(const file_error ex) {
        printf("%s\n", ex.what());
    }
    try {
        list<real> l;
        //throw 69;
        //l.push_back(real{1, 0});
        //l.push_back(real{2, 7} / 0);
        l.push_back(real{1, static_cast<int>(1e9)} * real{1, static_cast<int>(1e9)});
        l.push_back(real{1, 5} + real{1, 5});
        l.push_back(real{-1, 5} + real{1, 5});
        l.push_back(real{-2, 5} + real{1, 5});
        l.push_back(real{-2, 5} - real{1, 5});
        l.push_back(real{-1, 5} * real{-2, 5});
        l.push_back(real{1, 5} / real{1, 5});
        l.push_back(real{2, 7} / real{4, 7});
        auto cur = l.begin();
        while (cur != l.end()) {
            printf("%s\n", cur->value.to_string());
            cur = cur->next;
        }
    } catch(const int x) {
        const char* format;
        switch (x) {
            case DENUM_IS_ZERO:
                format = "Деление на ноль";
                break;
            case ILLEGAL_NUMBER:
                format = "Ошибка логарифмирования";
                break;
            case TOO_MUCH:
                format = "Слишком большое число";
                break;
            default:
                format = "Неопознанная ошибка с кодом %d";
                break;
        }
        char* result = (char*)malloc(strlen(format) + 32);
        sprintf(result, format, x);
        print_errors(result);
    } catch(error &x) {
        printf("%s\n", x.what());
    }
    return 0;
}
