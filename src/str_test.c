#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

int main(/*int argc, char *argv[]*/) {
  // double x, r;
  // size_t bytes;
  char str1[2042] = "";
  int i = 123456;
  int* p = &i;
  double ii = 123456;
  wchar_t g = 300;
  char t = (char)300;
  // printf("\t==========marker================\n");
  sprintf(str1, "<%%c>\t\t\t|%c|", i);
  printf("%s\n", str1);
  sprintf(str1, "<%%c>\t\t\t|%c|", g);
  printf("%s\n", str1);
  sprintf(str1, "<%%c>\t\t\t|%c|", t);
  printf("%s\n", str1);
  // d - целые
  sprintf(str1, "<%%d>\t\t\t|%d|", i);
  printf("%s\n", str1);
  sprintf(str1, "<%%8d>\t\t\t|%8d|", i);
  printf("%s\n", str1);
  sprintf(str1, "<%%08d>\t\t\t|%08d|", i);
  printf("%s\n", str1);
  sprintf(str1, "<%% 11d>\t\t\t|% 11d|", i);
  printf("%s\n", str1);
  sprintf(str1, "<%%11d>\t\t\t|%11d|", i);
  printf("%s\n", str1);
  sprintf(str1, "<%%.5d>\t\t\t|%.5d|", i);
  printf("%s\n", str1);
  // printf("\n");
  // sprintf(str1, "<%%i>\t\t\t|%i|", i);
  // printf("%s\n", str1);
  // sprintf(str1, "<%%8i>\t\t\t|%8i|", i);
  // printf("%s\n", str1);
  // sprintf(str1, "<%%08i>\t\t\t|%08i|", i);
  // printf("%s\n", str1);
  // sprintf(str1, "<%% 11i>\t\t\t|% 11i|", i);
  // printf("%s\n", str1);
  // sprintf(str1, "<%%11i>\t\t\t|%11i|", i);
  // printf("%s\n", str1);
  // sprintf(str1, "<%%.5i>\t\t\t|%.5i|", i);
  // printf("%s\n", str1);
  // printf("\n");
  // e - научная нотация
  printf("спецификатор e\n");
  sprintf(str1, "<%%.5e>\t\t\t|%.5e|", ii);
  printf("%s\n", str1);
  sprintf(str1, "<%%.4e>\t\t\t|%.4e|", ii);
  printf("%s\n", str1);
  sprintf(str1, "<%%011.4e>\t\t|%011.4e|", ii);
  printf("%s\n", str1);
  sprintf(str1, "<%%11.4e>\t\t|%11.4e|", ii);
  printf("%s\n", str1);
  sprintf(str1, "<%%11e>\t\t\t|%11e|", ii);
  printf("%s\n", str1);
  sprintf(str1, "<%%15e>\t\t\t|%15e|", ii);
  printf("%s\n", str1);
  sprintf(str1, "<%%015e>\t\t\t|%015e|", ii);
  printf("%s\n", str1);
  sprintf(str1, "<%% 15e>\t\t\t|% 15e|", ii);
  printf("%s\n", str1);
  sprintf(str1, "<%%.015e>\t\t|%.015e|", ii);
  printf("%s\n", str1);
  sprintf(str1, "<%%.015E>\t\t|%.015E|", ii);
  printf("%s\n", str1);
  // x - беззнаковое  шестнадцатеричное
  printf("спецификатор x\n");
  sprintf(str1, "<%%x>\t\t\t|%x|", i);
  printf("%s\n", str1);
  sprintf(str1, "<%%#x>\t\t\t|%#x|", i);
  printf("%s\n", str1);
  sprintf(str1, "<%%X>\t\t\t|%X|", i);
  printf("%s\n", str1);
  sprintf(str1, "<%%#X>\t\t\t|%#X|", i);
  printf("%s\n", str1);
  sprintf(str1, "<%%15x>\t\t\t|%15x|", i);
  printf("%s\n", str1);
  sprintf(str1, "<%%#15x>\t\t\t|%#15x|", i);
  printf("%s\n", str1);
  sprintf(str1, "<%%-#15x>\t\t|%-#15x|", i);
  printf("%s\n", str1);
  {
    sprintf(str1, "<%% #15x>\t\t|' ' flag used with '%%x' gnu_printf format|");
    printf("%s\n", str1);  // пробел не работает с шириной у шестнадцатеричных
  }
  sprintf(str1, "<%%0#15x>\t\t|%0#15x|", i);
  printf("%s\n", str1);
  sprintf(str1, "<%%#015x>\t\t|%#015x|", i);
  printf("%s\n", str1);
  sprintf(str1, "<%%#0*x>\t\t\t|%#0*x|", 15, i);
  printf("%s\n", str1);
  sprintf(str1, "<%%#*x>\t\t\t|%#*x|", 015, i);
  printf("%s\n", str1);  // базовый sprintf ломается тут немного
  // o  - восьмеричное число
  printf("спецификатор о\n");
  sprintf(str1, "<%%o>\t\t\t|%o|", i);
  printf("%s\n", str1);
  sprintf(str1, "<%%15o>\t\t\t|%15o|", i);
  printf("%s\n", str1);
  sprintf(str1, "<%%*o>\t\t\t|%*o|", 15, i);
  printf("%s\n", str1);
  sprintf(str1, "<%%-15o>\t\t\t|%-15o|", i);
  printf("%s\n", str1);
  sprintf(str1, "<%%15.2o>\t\t|%15.2o|", i);
  printf("%s\n", str1);
  sprintf(str1, "<%%015o>\t\t\t|%015o|", i);
  printf("%s\n", str1);
  sprintf(str1, "<%%.15o>\t\t\t|%.15o|", i);
  printf("%s\n", str1);
  sprintf(str1,
          "<%%015.2o>\t\t|'0' flag ignored with precision and '%%o' gnu_printf "
          "format|");
  //
  printf("%s\n", str1);
  // p - адрес
  printf("спецификатор p\n");
  sprintf(str1, "<%%p>\t\t\t|%p|", p);
  printf("%s\n", str1);
  sprintf(str1, "<%%8p>\t\t\t|%8p|", p);
  printf("%s\n", str1);
  sprintf(str1, "<%%08p>\t\t\t|'0' flag used with '%%p' gnu_printf format|");
  printf("%s\n", str1);  // 0 с адресом не используется
  sprintf(str1, "<%% 11p>\t\t\t|' ' flag used with '%%p' gnu_printf format|");
  printf("%s\n", str1);  // ' ' с адресом не используется
  sprintf(str1, "<%%20p>\t\t\t|%20p|", p);
  printf("%s\n", str1);
  sprintf(str1, "<%%-20p>\t\t\t|%-20p|", p);
  printf("%s\n", str1);
  sprintf(str1, "<%%*p>\t\t\t|%*p|", -20, p);

  printf("%s\n", str1);
  sprintf(str1, "<%%#20p>\t\t\t|'#' flag used with '%%p' gnu_printf format|");
  printf("%s\n", str1);  // # с адресом не используется
  sprintf(str1, "<%%.5p>\t\t\t|precision used with '%%p' gnu_printf format|");
  printf("%s\n", str1);  // точность с адресом не используется
  return 0;
}
