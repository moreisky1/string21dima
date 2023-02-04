#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, size_t n) {
  int i = 0;
  int j = 0;
  char *d = (char *)dest;
  char *s = (char *)src;
  //    while (d[i]){
  //        i++;
  //    }
  while (j < n) {
    d[j] = s[j];
    j++;
    //       i++;
  }
  dest = d;
  return dest;
}