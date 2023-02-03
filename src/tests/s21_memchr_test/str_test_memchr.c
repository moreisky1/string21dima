#include <stdio.h>
#include <string.h>

#include "../../s21_string.h"

int main() {
  char* s = NULL;
  int c = -1;
  size_t n = 0;
  // int pointer = 0;
  {
    s = "valley";
    c = 97;
    n = 5;
    // pointer = memchr(s, c, n);
    printf("<%s>\t<%c>\t<%ld>\n", s, c, n);
    printf("orig:\t|%s|\n", (char*)memchr(s, c, n));
    printf(" s21:\t|%s|\n", (char*)s21_memchr(s, c, n));
    printf("===================\n");
  }
  {
    s = "valley";
    c = 65;
    n = 5;
    // pointer = memchr(s, c, n);
    printf("<%s>\t<%c>\t<%ld>\n", s, c, n);
    printf("orig:\t|%s|\n", (char*)memchr(s, c, n));
    printf(" s21:\t|%s|\n", (char*)s21_memchr(s, c, n));
    printf("===================\n");
  }
  {
    s = "valley";
    c = 97;
    n = 0;
    // pointer = memchr(s, c, n);
    printf("<%s>\t<%c>\t<%ld>\n", s, c, n);
    printf("orig:\t|%s|\n", (char*)memchr(s, c, n));
    printf(" s21:\t|%s|\n", (char*)s21_memchr(s, c, n));
    printf("===================\n");
  }
  {
    s = NULL;  // если n > 0 то вылетает сега
    c = 97;
    n = 0;
    // pointer = memchr(s, c, n);
    printf("<%s>\t<%c>\t<%ld>\n", s, c, n);
    printf("orig:\t|%s|\n", (char*)memchr(s, c, n));
    printf(" s21:\t|%s|\n", (char*)s21_memchr(s, c, n));
    printf("===================\n");
  }
  {
    s = "valley";
    c = -1;
    n = 5;
    // pointer = memchr(s, c, n);
    printf("<%s>\t<%c>\t<%ld>\n", s, c, n);
    printf("orig:\t|%s|\n", (char*)memchr(s, c, n));
    printf(" s21:\t|%s|\n", (char*)s21_memchr(s, c, n));
    printf("===================\n");
  }

  return 0;
}