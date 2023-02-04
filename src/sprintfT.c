#include <stdio.h>
#include <string.h>

#include "s21_string.h"

int main() {
  {
    char str[1000] = "";
    char s21[1000] = "";
    char *str3 = "test: %.1Lg!\ntest: %.2Lg!\ntest: %.3Lg!";
    long double num = 9999.999999;
    printf("%s\n", str3);
    printf("%d|%d\nstr=|%s|\ns21=|%s|\n", sprintf(str, str3, num, num, num),
           s21_sprintf(s21, str3, num, num, num), str, s21);
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
           s21_sprintf(s21, str3, num, num, num, num, num), str, s21);
    printf("%d\n", strcmp(str, s21));
    printf("\n\n");
  }
  {
    char str[1000] = "";
    char s21[1000] = "";
    char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %#5.10g!";
    double num = 0.0000756589367;
    printf("%s\n", str3);
    printf("%d|%d\nstr=|%s|\ns21=|%s|\n",
           sprintf(str, str3, num, num, num, num, num),
           s21_sprintf(s21, str3, num, num, num, num, num), str, s21);
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
           s21_sprintf(s21, str3, num, num, num, num, num), str, s21);
    printf("%d\n", strcmp(str, s21));
    printf("\n\n");
  }
  // {
  //   char str[1000] = "";
  //   char s21[1000] = "";
  //   char* str3 = "%+p Test %+3.p Test %+5.7p TEST %+10p GOD %+.p";
  //   char* val = "32";
  //   char* val2 = "8899";
  //   char* val3 = "91918";
  //   char* val4 = "32311";
  //   char* val5 = "3261";
  //   printf("%s\n", str3);
  //   printf("%d|%d\nstr=|%s|\ns21=|%s|\n",
  //         sprintf(str, str3, val, val2, val3, val4, val5),
  //     s21_sprintf(s21, str3, val, val2, val3, val4, val5),
  //     str, s21
  //     );
  //   printf("%d\n", strcmp(str, s21));
  //   printf("\n\n");
  // }

  return 0;
}