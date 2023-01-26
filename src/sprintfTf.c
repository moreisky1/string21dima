#include <string.h>
#include <stdio.h>

#include "s21_string.h"

int main() {
  char str1[10000] = "";
  char str2[10000] = "";
  // {
  // char *str3 = "test1: %e TEST %.e TEST %4e TEST %4.e TEST %4.1e TEST %5.10e!";
  // double num = 76.754589367;
  // printf("%s\n", str3);
  // printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num, num, num, num), s21_sprintf(str2, str3, num, num, num, num, num, num), str1, str2);
  // printf("%d\n\n", strcmp(str1,str2));
  // }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test2: %e TEST %.e TEST %4e TEST %4.e TEST %4.1e TEST %5.10g!";
  double num = 6.754589367;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num, num, num, num), s21_sprintf(str2, str3, num, num, num, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test3: %e TEST %.e TEST %3e TEST %4.e TEST %5.10e!";
  double num = -76.756589367;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num, num, num), s21_sprintf(str2, str3, num, num, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test4: %Le|%.Le!";
  long double num_long = -76.756589;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num_long, num_long), s21_sprintf(str2, str3, num_long, num_long), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test5: %20.10e|%20.15e|%-20.5e!";
  double num = -76.756589;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test6: %Le|%.Le|%+-#Le|%+#.Le|%-#.Le!";
  long double num = 76.756589;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num, num, num), s21_sprintf(str2, str3, num, num, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test7: %5e|test: %6.1e|test: %8.2e!";
  double num = 76.756589;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test8: %10.5e|test: %12.4e!";
  double num = 76.756589;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num), s21_sprintf(str2, str3, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test9: %15.1e|test: %16.2e|test: %18.3e!";
  double num = -7648938790.756589;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test10: %10.4e|test: %25.5e!";
  double num = -7648938790.756589;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num), s21_sprintf(str2, str3, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test11: %+15.e|test: %+#16.e|test: %+#18.0e!";
  double num = 7648938790.756589;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test12: %-26.1e|test: %-18.0e|test: %#-10.e!";
  double num = 7648938790.756589;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test13: %-#15.e|test: %-+25.e!";
  double num = 7648938790.756589;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num), s21_sprintf(str2, str3, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test14: %-15.4e!test: %-26.1e!test: %-18.0e!";
  double num = -365289.3462865487;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test15: %#-10.9e!test: %-+25.15e!";
  double num = -365289.3462865487;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num), s21_sprintf(str2, str3, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test16: %18.7e!test: %10.15e!test: %25.15e!";
  double num = -365289.34628654873789362746834;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test17: %18.7e!test: %10.15e!test: %25.15e!";
  double num = 0;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test18: %15.13e!test: %26.15e!";
  double num = 365289.34628654873789362746834;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num), s21_sprintf(str2, str3, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test19: %18.7e!test: %10.15e!";
  double num = 365289.34628654873789362746834;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num), s21_sprintf(str2, str3, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test20: %- 23.14e!test: %+ 25.15e!";
  double num = 365289.34628654873789362746834;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num), s21_sprintf(str2, str3, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test21: % 15e!test: % -26e!test: %- 18e!";
  double num = -365789.34;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test22: %+- 14e!test: %+ 10e!test: % +25e!";
  double num = -365789.34;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test23: % 14e!test: % -27e!test: %- 19e!";
  double num = 365789.34;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test24: %+- 16e!test: %+ 44e!test: % +35e!";
  double num = 365789.34;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test25: %26Le!test: %18Le!test: %60Le!";
  long double num = -3752765839673496.34;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test26: %- 26Le!test: %+- 18Le!test: %60Le!";
  long double num = 3752765839673496.34;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test27: %020e!test: %-020e!test: %+025e!";
  double num = 837564.4753366;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test28: %-+ 025.5e!test: %- 020.4e|test: %+ 016.6e!";
  double num = 837564.4753366;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test29: % 15.1Le!test: % -26.15Le!test: %- 30.15Le!";
  long double num = 278.723786;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test30: % 15.1Le!test: % -26.13Le!test: %- 30.8Le!";
  long double num = -2358.367776967;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test31: %+- 010.2e!test: %- 025.7e|test: %+- 18.4e!";
  double num = -947.6785643;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test32: |%.1e| |%.2e| |%.3e!";
  double num = -9999.99999;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test33: %.10Le!test: %.6Le!test: %.Le!";
  long double num = -9999.99999;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test34: %.1Le!test: %.2Le!test: %.3Le!";
  long double num = 000000000000000.00000000000;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test35: %.6Le!test: %.Le|test: %+ 0Le!!";
  long double num = 000000000000000.00000000000;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test36: %.1Le!test: %.2Le!test: %.3Le!";
  long double num = -635293201236310753.6495633;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test37: %+ 0Le!test: %.6Le!test: %.15Le!";
  long double num = -635293201236310753.6495633;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test38: %.1Le!test: %.2Le!test: %.3Le!";
  long double num = -236310753.6495633;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test39: %+ 0Le!test: %.6Le!test: %.15Le!";
  long double num = -236300053.6495633;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test40: %+ 0Le!test: %.6Le!test: %.15Le!";
  long double num = -9325781235683689988.;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test41: %.1Le!test: %.2Le!test: %.3Le!";
  long double num = -9325781235683689988.;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test42: %.1Le!test: %.2Le!test: %.3Le!";
  long double num = 823631075973858585858447757573.6495633;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test43: %+ 0Le!test: %.6Le!test: %.15Le!";
  long double num = 823631075973858585858447757573.6495633;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }

  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test44: %25.5Le!test: %Le!test: %-50Le!";
  long double num = -9325781235683689988.;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test45: %+ 0Le!test: %060Le!test: %.15Le!";
  long double num = -9325781235683689988.;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test46: %25.5Le!test: %Le!test: %-50Le!";
  long double num = -9325781235683689988.;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test47: %+ 0Le!test: %060Le!test: %.15Le!";
  long double num = -9325781235683689988.;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test48: %-+.1Le!test: %- .2Le!test: %-0.3Le!";
  long double num = -0.999999;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test49: % 10.12f hgsakul";
  double num = 0.235300;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num), s21_sprintf(str2, str3, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test50: %15Le!test: %100Le!";
  long double num = -3752765839673496.34;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num), s21_sprintf(str2, str3, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test51: % +15Le!test: %100Le!";
  long double num = 3752765839673496.34;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num), s21_sprintf(str2, str3, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test52: %015e!test: %-026e!test: %+018e!";
  double num = -947.6785643;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test53: %+ 50.15Le!test: % +40.15Le!";
  long double num = 278.723786;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num), s21_sprintf(str2, str3, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test54: %+ 50.14Le!test: % +40.14Le!";
  long double num = -2358.367776967;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num), s21_sprintf(str2, str3, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test54: %+ 50.14Le!test: % +40.14Le!";
  long double num = 0.000000000000000000000000000000000000367776967;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num), s21_sprintf(str2, str3, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }{
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test54: %6.4Le!test: % 5.5Le!";
  long double num = -2358.367776967;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num), s21_sprintf(str2, str3, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  {
  memset(str1, '\0', 10000);
  memset(str2, '\0', 10000);
  char *str3 = "test54: %4.6Le!test: %10.4Le!";
  long double num = 0.000000000000000000000000000000000000367776967;
  printf("%s\n", str3);
  printf("%d|%d\nstd=%s\ns21=%s\n", sprintf(str1, str3, num, num), s21_sprintf(str2, str3, num, num), str1, str2);
  printf("%d\n\n", strcmp(str1,str2));
  }
  
  return 0;
}