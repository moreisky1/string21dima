#include <stdio.h>
#include <string.h>

#include "s21_string.h"

int main() {
  char* str1 = "aPPle";
  // char* str2 = "sTrAwBeRrY77";
  // char* str3 = "";
  // char* str_null = NULL;
  char n = 80;
  // char* res1 = NULL;
  // char* res2 = NULL;

  printf("===================\n");

  // strlen
  //  printf("template <%s>\ns21 %ld\nori %ld\n", str1, s21_strlen(str1),
  //         strlen(str1));

  // printf("template <%s>\ns21 %ld\nori %ld\n", str2, s21_strlen(str2),
  //        strlen(str2));

  // printf("template <%s>\ns21 %ld\nori %ld\n", str3, s21_strlen(str3),
  //        strlen(str3));

  // printf("template %s\ns21 %ld\nori %ld\n", str_null, s21_strlen(str_null),
  //        strlen(str_null));

  // to_lower/to_upper
  // res1 = s21_to_lower(str1);
  // res2 = s21_to_upper(str1);
  // printf("template <%s>\n", str1);
  // printf("s21_low <%s>\n", res1);
  // printf("s21_up  <%s>\n", res2);
  // printf("===================\n");
  // free(res1);
  // free(res2);

  // res1 = s21_to_lower(str2);
  // res2 = s21_to_upper(str2);
  // printf("template <%s>\n", str2);
  // printf("s21_low <%s>\n", res1);
  // printf("s21_up  <%s>\n", res2);
  // printf("===================\n");
  // free(res1);
  // free(res2);

  // res1 = s21_to_lower(str3);
  // res2 = s21_to_upper(str3);
  // printf("template <%s>\n", str3);
  // printf("s21_low <%s>\n", res1);
  // printf("s21_up  <%s>\n", res2);
  // printf("===================\n");
  // free(res1);
  // free(res2);

  // res1 = s21_to_lower(str_null);
  // res2 = s21_to_upper(str_null);
  // printf("template <%s>\n", str_null);
  // printf("s21_low <%s>\n", res1);
  // printf("s21_up  <%s>\n", res2);
  // printf("===================\n");
  // free(res1);
  // free(res2);

  // strchr
  printf("<%s>\t<%c>\n", str1, n);
  printf("orig: <%s>\n", strchr(str1, n));
  printf(" s21: <%s>\n", s21_strchr(str1, n));
  printf("===================\n");

  n = 97;
  printf("<%s>\t<%c>\n", str1, n);
  printf("orig: <%s>\n", strchr(str1, n));
  printf(" s21: <%s>\n", s21_strchr(str1, n));
  printf("===================\n");

  n = 137;
  printf("<%s>\t<%c>\n", str1, n);
  printf("orig: <%s>\n", strchr(str1, n));
  printf(" s21: <%s>\n", s21_strchr(str1, n));
  printf("===================\n");

  n = 0;
  printf("<%s>\t<%c>\n", str1, n);
  printf("orig: <%s>\n", strchr(str1, n));
  printf(" s21: <%s>\n", s21_strchr(str1, n));
  printf("===================\n");

  return 0;
}