#include <stdio.h>
#include <string.h>

#include "../../s21_string.h"

int main() {
  char* str_1 = NULL;
  char* str_2 = NULL;
  // char* str_reserve = NULL;
  size_t n = 0;
  {
    str_1 = strdup("valley");
    str_2 = "river";
    n = 4;
    printf("<%s>\t<%s>\t<%ld>\n", str_1, str_2, n);
    char* str_reserve = strdup(str_1);
    memmove(str_1, str_2, n);
    s21_memmove(str_reserve, str_2, n);
    printf("orig:\t<%s>\n", str_1);
    printf(" s21:\t<%s>\n", str_reserve);
    printf("====================\n");
  }

  {
    str_1 = strdup("");
    str_2 = "river";
    n = 4;
    printf("<%s>\t<%s>\t<%ld>\n", str_1, str_2, n);
    char* str_reserve = strdup(str_1);
    memmove(str_1, str_2, n);
    s21_memmove(str_reserve, str_2, n);
    printf("orig:\t<%s>\n", str_1);
    printf(" s21:\t<%s>\n", str_reserve);
    printf("====================\n");
  }

  {
    str_1 = strdup("valley");
    str_2 = "river";
    n = 20;
    printf("<%s>\t<%s>\t<%ld>\n", str_1, str_2, n);
    char* str_reserve = strdup(str_1);
    memmove(str_1, str_2, n);
    s21_memmove(str_reserve, str_2, n);
    printf("orig:\t<%s>\n", str_1);
    printf(" s21:\t<%s>\n", str_reserve);
    printf("====================\n");
  }

  {
    str_1 = strdup("valley");
    str_2 = "";
    n = 4;
    printf("<%s>\t<%s>\t<%ld>\n", str_1, str_2, n);
    char* str_reserve = strdup(str_1);
    memmove(str_1, str_2, n);
    s21_memmove(str_reserve, str_2, n);
    printf("orig:\t<%s>\n", str_1);
    printf(" s21:\t<%s>\n", str_reserve);
    printf("====================\n");
  }

  {
    str_1 = strdup("valley");
    str_2 = "";
    n = 0;
    printf("<%s>\t<%s>\t<%ld>\n", str_1, str_2, n);
    char* str_reserve = strdup(str_1);
    memmove(str_1, str_2, n);
    s21_memmove(str_reserve, str_2, n);
    printf("orig:\t<%s>\n", str_1);
    printf(" s21:\t<%s>\n", str_reserve);
    printf("====================\n");
  }

  {
    str_1 = strdup("valley");
    str_2 = "river";
    n = 0;
    printf("<%s>\t<%s>\t<%ld>\n", str_1, str_2, n);
    char* str_reserve = strdup(str_1);
    memmove(str_1, str_2, n);
    s21_memmove(str_reserve, str_2, n);
    printf("orig:\t<%s>\n", str_1);
    printf(" s21:\t<%s>\n", str_reserve);
    printf("====================\n");
  }

  {
    str_1 = strdup("valley");
    str_2 = "river";
    n = 1;
    printf("<%s>\t<%s>\t<%ld>\n", str_1, str_2, n);
    char* str_reserve = strdup(str_1);
    memmove(str_1, str_2, n);
    s21_memmove(str_reserve, str_2, n);
    printf("orig:\t<%s>\n", str_1);
    printf(" s21:\t<%s>\n", str_reserve);
    printf("====================\n");
  }

  {
    str_1 = strdup("");
    str_2 = "";
    n = 1;
    printf("<%s>\t<%s>\t<%ld>\n", str_1, str_2, n);
    char* str_reserve = strdup(str_1);
    memmove(str_1, str_2, n);
    s21_memmove(str_reserve, str_2, n);
    printf("orig:\t<%s>\n", str_1);
    printf(" s21:\t<%s>\n", str_reserve);
    printf("====================\n");
  }

  return 0;
}