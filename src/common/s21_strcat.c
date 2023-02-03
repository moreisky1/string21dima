#include "../s21_string.h"
/*
 * Объединение строк. Функция добавляет копию строки src в конец строки dest.
 * Нулевой символ конца строки dest заменяется первым символом строки src,
 * и новый нуль-символ добавляется в конец уже новой строки,
 * сформированной объединением символов двух строк в строке dest.
 * */

char* s21_strcat(char *dest, const char *src) {
    if(dest != NULL && src != NULL) {
        int i = 0, j = 0;
        while (dest[i] != '\0') {
            i++;
        }
        while (src[j] != '\0') {
            dest[i] = src[j];
            i++;
            j++;
        }
        dest[i] = '\0';
    }
    return dest;
}