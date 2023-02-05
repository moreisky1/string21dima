#include "../s21_string.h"
/*
 * Описание:
 * Функция ищет последнее вхождение символа symbol в строку string.
 * Возвращает указатель на последнее вхождение символа в строке string.
 * Завершающий нулевой символ считается частью строки. Таким образом,
 * он также может быть найден для получения указателя на конец строки.
 *
 * В Си эта функция  определена так:
 * Параметры:
 * string - Строка, в которой выполняется поиск.
 * symbol - Искомый символ. Передается функции как целое число, после
 * конвертируется в char.
 *
 * Возвращаемое значение:
 * Указатель на последнее вхождение символа в строку string.
 * Если значение не найдено, функция возвращает нулевой указатель.
 * */
char *s21_strrchr(const char *str, int c) {
  char *result = S21_NULL;
  int temp = -1;
  int i = 0;
  while (str[i] != '\0') {
    if (str[i] == c) {
      temp = i;
    }
    i++;
  }
  if (str[i] == c) {
    temp = i;
  }
  if (temp >= 0) {
    result = (char *)str + temp;
  }
  return result;
}