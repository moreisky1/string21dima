#include "../s21_string.h"

void* s21_to_lower(const char *str) {
    int i = 0;
    char* result = NULL;
    if (str != NULL) {
        result = (char *) malloc((s21_strlen(str) + 1) * sizeof(char));
        while (str[i] != '\0') {
            result[i] = str[i];
            if (result[i] >= 'A' && result[i] <= 'Z') {
                result[i] = result[i] + 32;
            }
            i++;
        }
        result[i] = '\0';
    }
    return result;
}