#include "../s21_string.h"

void* s21_insert(const char *src, const char *str, size_t start_index) {
    size_t src_len = s21_strlen(src);
    size_t str_len = s21_strlen(str);
    char* result = (char*) malloc(sizeof (char) * (src_len + str_len + 1));
    size_t i = 0;
    size_t j = 0;
    size_t g = 0;
    if (src_len > start_index) {
        while(src[i] != '\0') {
            if (i == start_index) {
                while (str[j] !='\0') {
                    result[g] = str[j];
                    j++;
                    g++;
                }
            }
            result[g] = src[i];
            i++;
            g++;
        }
        result[g] = '\0';
    } else {
        while(src[i] != '\0') {
            result[g] = src[i];
            i++;
            g++;
        }

        while (str[j] !='\0') {
            result[g] = str[j];
            j++;
            g++;
        }
        result[g] = '\0';
    }

    return result;
}