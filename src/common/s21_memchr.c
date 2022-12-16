#include "../s21_string.h"

int contain(const char *str, int c, size_t n) ;

void* s21_memchr(const void *str, int c, size_t n) {
    void* result = NULL;
    char* src = (char*)str;
    size_t i = 0;
    while(i < n) {
        i++;
        if (src[i] == c) {
            break;
        }
        if (src[i] == '\0') {
            break;
        }
    }
    if(contain((char*)str,c,n) == 1) {
        result = (void*)(str + i);
    }
    return result;
}

int contain(const char *str, int c, size_t n) {
    int res = 0;
    size_t i = 0;
    while(i < n) {
        i++;
        if (str[i] == c) {
            res = 1;
            break;
        }
        if (str[i] == '\0') {
            break;

        }
    }
    return res;
}

