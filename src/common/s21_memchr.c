#include "../s21_string.h"

void *s21_memchr(const void *str, int c, size_t n) {
    unsigned char *buf = (unsigned char *)str;
    size_t i = 0;
    char *ans = NULL;
    while (i < n && buf) {
        if (*buf == (unsigned char)c) {
            ans = buf;
            i = n;
        }
        buf++;
        i++;
    }
    return ans;
}

