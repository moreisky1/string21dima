#include "../s21_string.h"

void* s21_to_upper(const char *str) {
    char* result = NULL;
    if (str != NULL) {
     int i = 0;
        result = (char *) malloc((s21_strlen(str) + 1) * sizeof (char ));
        while(str[i] != '\0') {
         result[i] = str[i];
         if(result[i] >= 'a' && result[i] <= 'z') {
             result[i] = result[i] - 32;
         }
         i++;
        }
        result[i] = '\0';
    }
    return result;
}