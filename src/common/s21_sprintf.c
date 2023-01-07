#include "../s21_string.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

typedef struct specif {
  char spec;
  char mod;
  char flag;
  int width;
  int precision;
}Specif;

int getCifra(int a);
int printNumber(char * str, int a, Specif sp);
int getValue (char * str, Specif sp, va_list ptr);
int initStruct (char * str, Specif * sp);
int parseToInt(char * str, int * val);
int getCifra1(int a, int b);

int s21_sprintf(char *str, const char *format, ...) {
  Specif sp = {0};
  char * spec = "cdieEfgGosuxXpn%";  
  char * start = str;
  va_list ptr;
  va_start(ptr, format);
  int j = 0;
  while (*format) {
    if (*format == '%') {
      format++;
      char * buf = strndup(format, (int)(format - strpbrk(format, spec)) + 1);
      initStruct(buf, &sp);
      str += getValue(str, sp, ptr);      
    } else {    
      *str = *format;
      str++;
    }
    format++;
  }
  va_end(ptr);
  str = start;

  return 0;
}

int getValue (char * str, Specif sp, va_list ptr) {
  int count = 0;
  if (sp.spec == 'c') {
    *str = (char)va_arg(ptr, int);
    str++;
    count++;
  }
  if (sp.spec == '%') {
    *str = '%';
    str++;
    count++;
  }
  if (sp.spec == 's') {
    char * buf = va_arg(ptr, char *);
    while (*buf){
      *str = *buf;
      count++;      
      str++;
      buf++;
    }      
  }
  if (sp.spec == 'i' || sp.spec == 'd') {
    int a = va_arg(ptr, int);
    count = printNumber(str, a, sp);
  }
  if (sp.spec == 'o' || sp.spec == 'u') {
    int a = va_arg(ptr, int);
    count = printNumber(str, a, sp);
  }
  if (sp.spec == 'x' || sp.spec == 'X') {
    int a = va_arg(ptr, int);
    count = printNumber(str, a, sp);
  }
  if (sp.spec == 'p') {
    sp.spec = 'x';
    int a = va_arg(ptr, int);
    // long long int q = (long long int)&a;
    printf("<%p | %x >", a, a);
    strcat(str, "0x10");
    str += 4;    
    count = printNumber(str, a, sp);
    count += 4;
  }
  return count;
}

int initStruct (char * str, Specif * sp) {
  char * flag = "-+ #0";
  char * modif = "hlL";
  char * spec = "cdieEfgGosuxXpn%";
  while (*str != '\0') {
    if (strchr(flag, *str)) {
      sp->flag = *(strchr(flag, *str));
      str++;
    }
    if (*str >= '0' && *str <= '9') {        // если цифра 
      str += parseToInt(str, &(sp->width));  //то забираю все цифры в число width
    }
    if (*str == '.') {                       // если точка то после число точности 
      str++;
      str += parseToInt(str, &(sp->precision));  //то забираю все цифры в число precision
    }
    if (strchr(modif, *str)) {
      sp->mod = *(strchr(flag, *str));
      str++;
    }
    sp->spec = *str;
    str++;
  }  
  return 0;
}

int parseToInt(char * str, int * val) {
  int count = 0;
  *val = 0;
  while (*str >= '0' && *str <= '9') {
    *val *= 10;
    *val += *str - '0';
    count++;
  }  
  return count;
}

int printNumber(char * str, int a, Specif sp) {
  int count = 0;
  int notation = 16;
  int step = 55;
  if (sp.spec == 'o') {
    notation = 8;
  } else if (sp.spec == 'u' || sp.spec == 'i' || sp.spec == 'd') {
    notation = 10;
  }
  if (sp.spec == 'x') {
    step = 87;
  }
  while (1) {
    int b = getCifra1(a, notation);
    if (b > 9 && notation == 16) {
      *str = b + step;
    } else {
      *str = b + '0';
    }
    str++;
    count++;
    if (a > notation - 1) {
      a %= notation;
    } else {
      break;
    }
  }   
  return count;
}

int getCifra(int a) {
  int result = a;
  if (a > 9) {
    result = getCifra(a / 10);
  }
  return result;  
}

int getCifra1(int a, int b) {
  int result = a;
  if (a > b) {
    result = getCifra1(a / b, b);
  }
  return result;  
}
