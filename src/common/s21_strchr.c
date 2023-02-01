#include "../s21_string.h"

char* s21_strchr(const char* str, int c) {
  char* res = NULL;
  if (c < 0 || c > 127) {
    ;
  } else {
    for (int i = 0; i <= s21_strlen(str); i++) {
      if (str[i] == c) {
        res = (char*)str + i;
        break;
      }
    }
  }
  return res;
}