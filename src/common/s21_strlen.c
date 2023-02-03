#include "../s21_string.h"

size_t s21_strlen(const char *str) {
  size_t result = 0;
  //   while (str[result] != '\0') {
  //     result++;
  //   }
  for (; *str != '\0'; str++) {
    result++;
  }
  return result;
}