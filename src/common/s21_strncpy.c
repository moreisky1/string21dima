#include "../s21_string.h"
/*
 * Функция копирует из строки src в буфер dst не более чем len символов
 * (включая нулевой символ), не гарантируя завершения строки нулевым символом
 * (если длина строки src больше или равна len). Если длина строки src меньше
 * len, то буфер добивается до len нуль- символами.
 * */
char *s21_strncpy(char *dest, const char *src, size_t n) {
  int i = 0, j = 0;
  while (i < n) {
    if (src[j] != '\0') {
      dest[i] = src[j];
      j++;
    } else {
      dest[i] = src[j];
    }
    i++;
  }
  // dest[i] = '\0';
  return dest;
}