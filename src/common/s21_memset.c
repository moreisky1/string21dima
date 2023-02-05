#include "../s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  char *res = (char *)str;
  if (res != S21_NULL) {
    s21_size_t length = s21_strlen(res);
    for (int i = 0; i < n; i++) {
      res[i] = c;
    }
    str = (void *)res;
  }
  return str;
}