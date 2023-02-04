#include "../s21_string.h"

void* s21_memset(void* str, int c, s21_size_t n) {
  char* res = (char*)str;
  s21_size_t length = s21_strlen(res);
  if ((res != NULL)/*&& (n >= 0)*/) {
    for (int i = 0; i < n; i++) {
      res[i] = c;
    }
    // if (n > length) {
    //   res[n] = '\0';
    // }
    str = (void*)res;
  } else
    return str;
}