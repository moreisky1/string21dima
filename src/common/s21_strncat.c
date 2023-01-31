#include "../s21_string.h"

char* s21_strncat(char *dest, const char *src, size_t n) {
    if(dest != NULL && src != NULL && n > 0) {
        int i = 0, j = 0;
        while (dest[i] != '\0') {
            i++;
        }
        while (src[j] != '\0') {
            dest[i] = src[j];
            i++;
            j++;
            if(j >= n) {
                break;
            }

        }
        dest[i] = '\0';
    }
    return dest;
}