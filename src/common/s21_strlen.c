#include "../s21_string.h"

/*#15
 * tests ---> NON
 * realise ----> OK
 *
 * Вычисляет длину строки str, не включая завершающий нулевой символ.
 *
 * const char* str ---> измеряемая строка
 * return ---> возвращает количество символов в строке (size_t)
 * */

size_t s21_strlen(const char *str) {
    size_t result = 0;
    while (str[result] != '\0') {
        result++;
    }
    return result;
}