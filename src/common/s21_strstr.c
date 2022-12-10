#include "../s21_string.h"

char* s21_strstr(const char *haystack, const char *needle) {
    char* result = NULL;
    int i = 0, j = 0;
    int marker = 0;
    while (haystack[i]!='\0') {
        j = 0;
        while (needle[j]!='\0') {
            if (needle[j] != haystack[i+j]) {
                break;
            }
            j++;
        }
        if (needle[j] == '\0') {
            *result = haystack[i];
        }
        i++;
    }
    return result;
}