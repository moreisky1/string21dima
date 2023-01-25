#include <stdio.h>
#include <string.h>
#include "s21_string.h"

int main () {
  {
    char str[1000] = "";
    char s21[1000] = "";
    char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %#5.10g!";
    double num = 0.0000756589367;
    printf("%s\n", str3);
    printf("%d|%d\nstr=|%s|\ns21=|%s|\n",
      sprintf(str, str3, num, num, num, num, num),
      s21_sprintf(s21, str3, num, num, num, num, num),
      str, s21
      );
    printf("%d\n", strcmp(str, s21));
    printf("\n\n");
  }
  {
    char str[1000] = "";
    char s21[1000] = "";
    char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.10g!";
    double num = 573429.56589367;
    printf("%s\n", str3);
    printf("%d|%d\nstr=|%s|\ns21=|%s|\n",
      sprintf(str, str3, num, num, num, num, num),
      s21_sprintf(s21, str3, num, num, num, num, num),
      str, s21
      );
    printf("%d\n", strcmp(str, s21));
    printf("\n\n");
  }
  {
    char str[1000] = "";
    char s21[1000] = "";
    char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.10g!";
    double num = 573429.56589367;
    printf("%s\n", str3);
    printf("%d|%d\nstr=|%s|\ns21=|%s|\n",
      sprintf(str, str3, num, num, num, num, num),
      s21_sprintf(s21, str3, num, num, num, num, num),
      str, s21
      );
    printf("%d\n", strcmp(str, s21));
    printf("\n\n");
  }
   
  return 0;
}