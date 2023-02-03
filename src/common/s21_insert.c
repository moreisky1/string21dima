#include "../s21_string.h"

void* s21_insert(const char *src, const char *str, size_t start_index) {
    char* result = NULL;
    if (str && src) {
        size_t src_len = s21_strlen(src);
        size_t str_len = s21_strlen(str);
        int size = src_len + str_len + 1;
        result = (char*) malloc(sizeof (char) * (size));
        size_t i = start_index;
        size_t j = str_len;
        size_t g = src_len - i;
        if (src_len >= start_index) {
            s21_memmove(result, src, i);
            s21_memmove(result + i, str, j);
            s21_memmove(result + i + j, src + i, g);
            // while(src[i] != '\0') {
            //     if (i == start_index) {
            //         while (str[j] !='\0') {
            //             result[g] = str[j];
            //             j++;
            //             g++;
            //         }
            //     }
            //     result[g] = src[i];
            //     i++;
            //     g++;
            // }
            // result[g] = '\0';
            result[size] = '\0';
        } else {
            if (!start_index) {
                s21_memmove(result, src, src_len);
                // for (size_t i = 0; i < src_len; i++) {
                //     result[0] = src[i];
                // }
                // result[src_len] = 0;
                result[size] = '\0';
            } else {
                result = NULL;
            }
            /*
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
            */
        }
    }

    return result;
}