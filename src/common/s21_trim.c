#include "../s21_string.h"

int contain_list(char c, const char *list);

void* s21_trim(const char *src, const char *trim_chars) {
    char* result = NULL;
    if (src != NULL) {
        int start = 0, end = 0, i = s21_strlen(src) - 1, len = 0;
        // check start
        while (contain_list(src[start], trim_chars)) {
            start++;
        }
        // check end
        while (contain_list(src[i], trim_chars)) {
            end++;
            i--;
        }

        len = s21_strlen(src) - start - end;

        if (start + end < s21_strlen(src) && start + end > 0) {
            result = (char*) malloc((len + 1) * sizeof (char));
            int j = 0;
            while (j < len) {
                result[j] = src[start + j];
                j++;
            }
            result[j] = '\0';
        } else if (start + end == 0) {
            result = (char *) malloc((s21_strlen(src) + 1) * sizeof(char));
            int j = 0;
            while (src[j] != '\0') {
                result[j] = src[j];
                j++;
            }
            result[j] = '\0';
        }
    } else if (trim_chars == NULL) {
        result = (char *) malloc((s21_strlen(src) + 1) * sizeof(char));
        int j = 0;
        while (src[j] != '\0') {
            result[j] = src[j];
            j++;
        }
        result[j] = '\0';
    } else if (src == NULL) {
        result == NULL;
    }
    return result;
}

int contain_list(char c, const char *list) {
    int result = 0;
    int i = 0;
    while (list[i] != '\0') {
        if (c == list[i]) {
            result = 1;
            break;
        }
        i++;
    }
    return result;
}