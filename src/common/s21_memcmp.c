#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, size_t n) {
    int result = 0;
    int i = 0;
    char* st1 = (char*) str1;
    char* st2 = (char*) str2;

    while (i < n) {
        if (st1[i] != st2[i]) {
            break;
        }
        i++;
    }
    if (st1[i] - st2[i] > 0) result = 1;
    if (st1[i] - st2[i] < 0) result = (-1);
    return result;
}