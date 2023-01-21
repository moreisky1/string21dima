#include <stdio.h>
#include <string.h>

#include "s21_string.h"

int main() {
  char* str1 = "APPLE";
  char* str2 = "sTrAwBeRrY77";
  char* str3 = "";
  char* str_null = NULL;

  char* res1 = NULL;
  // char* res2 = NULL;
  // strlen
  //  printf("template <%s>\ns21 %ld\nori %ld\n", str1, s21_strlen(str1),
  //         strlen(str1));

  // printf("template <%s>\ns21 %ld\nori %ld\n", str2, s21_strlen(str2),
  //        strlen(str2));

  // printf("template <%s>\ns21 %ld\nori %ld\n", str3, s21_strlen(str3),
  //        strlen(str3));

  // printf("template %s\ns21 %ld\nori %ld\n", str_null, s21_strlen(str_null),
  //        strlen(str_null));

  // to_lower
  res1 = s21_to_lower(str1);
  // res2 = s21_to_lower(str1);
  printf("template <%s>\ns21 <%s>\n", str1, res1);
  free(res1);
  // free(res2);

  res1 = s21_to_lower(str2);
  // res2 = s21_to_lower(str2);
  printf("template <%s>\ns21 <%s>\n", str2, res1);
  free(res1);
  // free(res2);

  res1 = s21_to_lower(str3);
  // res2 = s21_to_lower(str3);
  printf("template <%s>\ns21 <%s>\n", str3, res1);
  free(res1);
  // free(res2);

  res1 = s21_to_lower(str_null);
  // res2 = s21_to_lower(str_null);
  printf("template <%s>\ns21 <%s>\n", str_null, res1);
  free(res1);
  // free(res2);
}