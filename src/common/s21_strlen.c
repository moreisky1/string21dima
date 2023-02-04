#include "../s21_string.h"

s21_size_t s21_strlen(const char *str) {
  s21_size_t result = 0;
  //   while (str[result] != '\0') {
  //     result++;
  //   }
  for (; *str != '\0'; str++) {
    result++;
  }
  return result;
}