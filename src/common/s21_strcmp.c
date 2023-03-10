#include "../s21_string.h"

/*
 * Описание:
 * Эта функция сравнивает символы двух строк, string1 и string2.
 * Начиная с первых символов функция strcmp сравнивает поочередно каждую пару
 * символов, и продолжается это до тех пор, пока не будут найдены различные
 * символы или не будет достигнут конец строки.
 *
 * Параметры:
 * string1 - Первая сравниваемая Си-строка.
 * string2 - Вторая сравниваемая Си-строка.
 * Возвращаемое значение:
 * Функция возвращает несколько значений, которые указывают на отношение строк:
 * Нулевое значение говорит о том, что обе строки равны.
 * Значение больше нуля указывает на то, что строка string1 больше строки
 * string2, значение меньше нуля свидетельствует об обратном. Функция strcmp
 * начинает сравнивать по одному символу и как только будут найдены первые
 * неодинаковые символы, функция проанализирует числовые коды этих символов. Чей
 * код окажется больше, та строка и будет считаться большей.
 * */

int s21_strcmp(const char *str1, const char *str2) {
  int result = 0;
  int i = 0;

  while (str1[i]) {
    if (str1[i] != str2[i]) {
      break;
    }
    i++;
  }

  if (str1[i] != str2[i]) result = str1[i] - str2[i];

  return result;
}