#include "../s21_string.h"

void* s21_to_lower(const char* str) {
  char* result;
  size_t i = 0;
  if (str == NULL) {
    result = NULL;
  } else {
    result = malloc(((s21_strlen(str) + 1) * sizeof(char)));
    while (str[i] != '\0') {
      if (str[i] >= 65 && str[i] <= 90) {
        result[i] = str[i] + 32;
      } else {
        result[i] = str[i];
      }
      i++;
    }
    result[i] = '\0';
  }
  return result;
}