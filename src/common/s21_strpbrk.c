#include "../s21_string.h"
/*
 * Описание:
 * Функция выполняет поиск первого вхождения в строку string1 любого
 * из символов строки string2. Возвращает указатель на первое вхождение
 * в string1 найденного символа, или — пустой указатель, если нет ни
 * одного совпадения. Поиск не учитывает завершающий нуль-символ.
 *
 * Параметры:
 * string1 - Строка, в которой выполняется поиск.
 * string2 - Строка, содержащая искомые символы.
 *
 * Возвращаемое значение:
 * Указатель на первое вхождение в string1 найденного символа.
 * Если ни один из символов string2 не присутствует в строке string1,
 * возвращается нулевой указатель.
 * */
char* s21_strpbrk(const char* str1, const char* str2) {
    char* result = NULL;
    int j = 0, i = 0;
    while(str1[i]) {
        while (str2[j]) {
            if(str1[i] == str2[j]) break;
            j++;
        }
        if(str1[i] == str2[j]) {
            result = (char *)str1 + i;
            break;
        }
        j = 0;
        i++;
    }
    return result;
}