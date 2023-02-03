#include <stdio.h>
#include <string.h>

#include "../../s21_string.h"

int main() {
  char* str1 = "needle_in_haystack";
  char* str2 = "needle";
  char* str3 = "noodle";
  char* empt_hay = "";
  char* empt_ned = "";
  // char* null_hay = NULL;
  // char* null_ned = NULL;

  char* res1 = NULL;
  char* res2 = NULL;

  res1 = s21_strstr(str1, str2);
  res2 = strstr(str1, str2);
  printf("haystack:\t%s\nneedle:\t\t%s\n\ns21_strstr\t%s\nstrstr\t\t%s\n", str1,
         str2, res1, res2);
  printf("=====\n");

  res1 = s21_strstr(str1, str3);
  res2 = strstr(str1, str3);
  printf("haystack:\t%s\nneedle:\t\t%s\n\ns21_strstr\t%s\nstrstr\t\t%s\n", str1,
         str3, res1, res2);
  printf("=====\n");

  res1 = s21_strstr(empt_hay, empt_ned);
  res2 = strstr(empt_hay, empt_ned);
  printf("haystack:\t%s\nneedle:\t\t%s\n\ns21_strstr\t%s\nstrstr\t\t%s\n",
         empt_hay, empt_ned, res1, res2);
  printf("=====\n");

  res1 = s21_strstr(empt_hay, str2);
  res2 = strstr(empt_hay, str2);
  printf("haystack:\t%s\nneedle:\t\t%s\n\ns21_strstr\t%s\nstrstr\t\t%s\n",
         empt_hay, str2, res1, res2);
  printf("=====\n");

  res1 = s21_strstr(str1, empt_ned);
  res2 = strstr(str1, empt_ned);
  printf("haystack:\t%s\nneedle:\t\t%s\n\ns21_strstr\t%s\nstrstr\t\t%s\n", str1,
         empt_ned, res1, res2);
  printf("=====\n");

  // res1 = s21_strstr(null_hay, str2);
  // res2 = strstr(null_hay, str2);
  // printf("haystack:\t%s\nneedle:\t\t%s\n\ns21_strstr\t%s\nstrstr\t\t%s\n",
  //        null_hay, str2, res1, res2);
  // printf("=====\n");

  return 0;
}