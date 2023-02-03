#include "../s21_string.h"

size_t s21_strspn(const char* str1, const char* str2) {
  size_t result = 0;
  char* hay = (char*)str1;
  if (str1 && str2) {  // == (str1 != NULL && str2 != NULL) ?
    while (*hay != '\0') {
      int flag_br = 0;
      char* ned = (char*)str2;
      while (*ned != '\0') {
        if (*hay == *ned) {
          ned++;
          flag_br = 1;
          continue;
        } else {
          ned++;
        }
      }
      if (flag_br == 0) {
        break;
      }
      hay++;
      result++;
    }
  }
  return result;
}