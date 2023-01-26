#include <string.h>
#include <stdio.h>

#include "s21_string.h"

int main() {
  char str[1000] = "";
  char s21_str[1000] = "";
  {
  memset(str, '\0', 1000);
  memset(s21_str, '\0', 1000);
  char *str3 = "Test %o T%nest %o%n";
  int val = 012;
  int val2 = 017;
  int valn1 = 0, valn2 = 0, valn3 = 0, valn4 = 0;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n\n", sprintf(str, str3, val, &valn1, val2, &valn3), s21_sprintf(s21_str, str3, val, &valn2, val2, &valn4), str, s21_str);
  printf("%d|%d\n", valn1, valn2);
  printf("%d|%d\n", valn3, valn4);
  printf("%d\n\n", strcmp(str, s21_str));  
  }
  {
  memset(str, '\0', 1000);
  memset(s21_str, '\0', 1000);
  char *str3 = "Test %n Test";
  int valn1 = 0, valn2 = 0;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n\n", sprintf(str, str3, &valn1), s21_sprintf(s21_str, str3, &valn2), str, s21_str);
  printf("%d|%d\n", valn1, valn2);
  printf("%d\n\n", strcmp(str, s21_str));  
  }
  
   
  return 0;
}
