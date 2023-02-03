#include <stdio.h>
#include <string.h>

#include "../../s21_string.h"

int main() {
  char* str_1 = NULL;
  char* str_2 = NULL;
  size_t n = 0;
  {
    str_1 = "valley";
    str_2 = "valley on fire";
    n = 6;
    printf("<%s>\t<%s>\t<%ld>\n", str_1, str_2, n);
    printf("orig:\t%d\n", memcmp(str_1, str_2, n));
    printf(" s21:\t%d\n", s21_memcmp(str_1, str_2, n));
    printf("===================\n");
  }

  {
    str_1 = "valley";
    str_2 = "valley on fire";
    n = 4;
    printf("<%s>\t<%s>\t<%ld>\n", str_1, str_2, n);
    printf("orig:\t%d\n", memcmp(str_1, str_2, n));
    printf(" s21:\t%d\n", s21_memcmp(str_1, str_2, n));
    printf("===================\n");
  }

  {
    str_1 = "valley";
    str_2 = "valley on fire";
    n = 7;
    printf("<%s>\t<%s>\t<%ld>\n", str_1, str_2, n);
    printf("orig:\t%d\n", memcmp(str_1, str_2, n));
    printf(" s21:\t%d\n", s21_memcmp(str_1, str_2, n));
    printf("===================\n");
  }

  {
    str_1 = "valley on fire it's burning";
    str_2 = "valley on fire";
    n = 24;
    printf("<%s>\t<%s>\t<%ld>\n", str_1, str_2, n);
    printf("orig:\t%d\n", memcmp(str_1, str_2, n));
    printf(" s21:\t%d\n", s21_memcmp(str_1, str_2, n));
    printf("===================\n");
  }

  {
    str_1 = "valley on fire it's burning";
    str_2 = "valley on fire";
    n = 0;
    printf("<%s>\t<%s>\t<%ld>\n", str_1, str_2, n);
    printf("orig:\t%d\n", memcmp(str_1, str_2, n));
    printf(" s21:\t%d\n", s21_memcmp(str_1, str_2, n));
    printf("===================\n");
  }

  {
    str_1 = "valley";
    str_2 = "";
    n = 4;
    printf("<%s>\t<%s>\t<%ld>\n", str_1, str_2, n);
    printf("orig:\t%d\n", memcmp(str_1, str_2, n));
    printf(" s21:\t%d\n", s21_memcmp(str_1, str_2, n));
    printf("===================\n");
  }

  {
    str_1 = "";
    str_2 = "valley on fire";
    n = 4;
    printf("<%s>\t<%s>\t<%ld>\n", str_1, str_2, n);
    printf("orig:\t%d\n", memcmp(str_1, str_2, n));
    printf(" s21:\t%d\n", s21_memcmp(str_1, str_2, n));
    printf("===================\n");
  }

  {
    str_1 = "";
    str_2 = "";
    n = 4;
    printf("<%s>\t<%s>\t<%ld>\n", str_1, str_2, n);
    printf("orig:\t%d\n", memcmp(str_1, str_2, n));
    printf(" s21:\t%d\n", s21_memcmp(str_1, str_2, n));
    printf("===================\n");
  }

  {
    str_1 = "";
    str_2 = "";
    n = 0;
    printf("<%s>\t<%s>\t<%ld>\n", str_1, str_2, n);
    printf("orig:\t%d\n", memcmp(str_1, str_2, n));
    printf(" s21:\t%d\n", s21_memcmp(str_1, str_2, n));
    printf("===================\n");
  }

  return 0;
}