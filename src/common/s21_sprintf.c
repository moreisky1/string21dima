#include "../s21_string.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

typedef struct flags {
  int min;
  int pl;
  int spase;
  int grid;
  int zero;
}Flags;

typedef struct specif {
  char spec;
  char mod;
  int countMod;
  Flags flag;
  int width;
  int precision;
}Specif;

int longDefine (int a);
int getCifra(char * str, long long unsigned a, Specif sp);
int getValue (char * str, Specif sp, va_list ptr);
int initStruct (char * str, Specif * sp, va_list ptr);
int parseToInt(char * str, int * val);
int getCifra1(char * str, double a, Specif sp);

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
      {
      int a = (long long int)strpbrk(format, spec) - (long long int)format + 1;
      char * buf = strndup(format, a);
      initStruct(buf, &sp, ptr);
      free(buf);
      format += a;
      }
      {
      char buf[4096] = "";
      int a = getValue(buf, sp, ptr);
      // function for format input
      strcat(str, buf);
      }
          
    } else {
      if (*format != '\0'){
        *str = *format;
        str++;
      }
      format++;
    }    
  }
  va_end(ptr);
  *str = '\0';
  str = start;

  return 0;
}

int formatForInput (Specif sp, char str) {
  char buf[4096] = "";
  int size = strlen(str);
  if (sp.width > size) {
    if (sp.flag.min){
      strcat(buf, str);
      fullingBuffer(sp, buf + size, sp.width - size);
    } else
    {
      fullingBuffer(sp, buf, sp.width - size);
      strcat(buf, str);
    }   
  }
  
  return 0;
}

int fullingBuffer(Specif sp, char buf, int n) {
  if (sp.flag.zero) {
    memset(buf, '0', n);
  } else {
    memset(buf, ' ', n);
  }
  //maybe need '\0'
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
    long long int a = va_arg(ptr, long long int);
    count = getCifra(str, a, sp);
  }
  if (sp.spec == 'o' || sp.spec == 'u') {
    long long int a = va_arg(ptr, long long int);
    count = getCifra(str, a, sp);
  }
  if (sp.spec == 'x' || sp.spec == 'X') {
    long long int a = va_arg(ptr, long long int);
    count = getCifra(str, a, sp);
  }
  if (sp.spec == 'p') {
    sp.spec = 'x';
    long long int a = (long long int)va_arg(ptr, int *);    
    strcat(str, "0x");
    str += 2;    
    count = getCifra(str, a, sp);
    count += 2;
  }
  if (sp.spec == 'f') {
    double a = va_arg(ptr, double);
    count = getCifra1(str, a, sp);
  }
  if (sp.spec == 'e' || sp.spec == 'E') {
    int po = 0;
    double a = va_arg(ptr, double);
    int64_t b = (int64_t)a;
    int mark = 1;
    if (b == 0) {
      mark = 0;
      while (b == 0) {
        a *= 10;
        po++;
        b = (int64_t)a;
      }
    } else {
      while (b > 9) {
        a /= 10;
        po++;
        b = (int64_t)a;
      }
    }    
    count += getCifra1(str, a, sp);
    str += count;
    if (po < 10) {
      *str = sp.spec;
      str++;
      if (mark) {
        *str = '+';
      } else {
        *str = '-';
      }
      str++;
      *str = '0';
      str++;
      count += 3;
      count += getCifra(str, po, sp);
    } else {
      *str = sp.spec;
      str++;
      if (mark) {
        *str = '+';
      } else {
        *str = '-';
      }
      str++;
      count += 2;
      count += getCifra(str, po, sp);
    }
  }
  
  if (sp.spec == 'g' || sp.spec == 'G') {
    double a = va_arg(ptr, double);
    count = getCifra1(str, a, sp);
  }
  return count;
} 


int initStruct (char * str, Specif * sp, va_list ptr) {
  char * flag = "-+ #0";
  char * modif = "hlL";
  char * spec = "cdieEfgGosuxXpn%";
  Specif qwer = {0};
  qwer.precision = 6;
  *sp = qwer;
  while (*str != '\0') {
    if (strchr(flag, *str)) {      
      int * p = (int *)&(sp->flag);
      *(p + (strchr(flag, *str) - flag)) = 1;
      str++;
    }
    if ((*str >= '0' && *str <= '9') || *str == '*') {  // если цифра 
      if (*str == '*') {
        sp->width = va_arg(ptr, int);
      } else {
        str += parseToInt(str, &(sp->width));             //то забираю все цифры в число width
      }
    }
    if (*str == '.') {                                  // если точка то после число точности 
      str++;
      if (*str == '*') {
        sp->precision = va_arg(ptr, int);
      } else {
        str += parseToInt(str, &(sp->precision));         //то забираю все цифры в число precision
      }
    }
    while (strchr(modif, *str)) {
      sp->mod = *str;
      sp->countMod++;
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



int getCifra(char * str, long long unsigned a, Specif sp) {
  int count = 0;
  int notation = 10; // i u d по стандарту
  int step = 55;
  if (sp.spec == 'o') {
    notation = 8;
  } else if (sp.spec == 'x' || sp.spec == 'X') {
    notation = 16;
    if (sp.spec == 'x') {
      step = 87;
    }
  }  
  // а как же ноль?
  if (a == 0) {
    *str = '0';
    count++;
  }
  while (a > 0) {
    count += getCifra(str, a / notation , sp);    
    str += count;
    int buf = a % notation;
    if ( buf > 9 && notation == 16) {
      *str = buf + step;
    } else {
      *str = buf + '0';
    }
    str++;
    count++;
    a /= notation;
  }   
  return count;  
}

int getCifra1(char * str, double a, Specif sp) {
  int count = 0;
  int64_t whole = (int64_t)a;
  double fractional = a - whole;
  sp.spec = 'd';
  // if (whole != 0) {
    count += getCifra(str, whole / 10 , sp);    
    str += count;
    int buf = whole % 10;
    *str = buf + '0';    
    count++;
  // }
  str++;
  *str = '.';
  str++;
  count++;
  
  for (int i = 0; i < sp.precision ; i++) {
    fractional *= 10;
    int buf = (int)fractional;
    *str = buf % 10 + '0';
    str++;
  }
  count += sp.precision;
  return count;  
}

// int isNanInf(const char * str) {
//   int result = 0;
//   if ('-' == *str || '+' == *str) {
//     str++;
//   }
//   char * buf = s21_to_lower(str);
//   if (!strcmp(buf, "nan")) {
//     result = 1;
//   }
//   if (!strcmp(buf, "inf")) {
//     result = 2;
//   }
//   free(buf);
//   return result;  
// }
