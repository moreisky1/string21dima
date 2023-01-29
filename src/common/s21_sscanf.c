#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <wchar.h>
#include "../s21_string.h"

#if defined (__APPLE__)
  #define STR_NULL "(null)"
#endif
#if defined (__linux__)
  #define STR_NULL "(nil)"
#endif

typedef union {
  int *p;
  long double ld;
} UnionVal;

typedef struct specif {
  char spec;
  char mod; 
  int width;
  int setWidth;
  int countMod;
  char pod;
  int count;
  UnionVal val;
  int err;
}Specif;

char toUperChar(char c);
char toLowerChar(char c);

void setValue(va_list ptr, Specif * sp);

long long int oxToDec(char * str, int * n, int notion);
int getIntIDU (char * str, Specif * sp);
int stringToIntOX(char * str, Specif * sp, va_list ptr);

long double getValueModDoub(Specif sp, va_list ptr);
long long getValueModInt(Specif sp, va_list ptr);
long long unsigned getValueModUInt(Specif sp, va_list ptr);

int getValue (char * str, Specif * sp);
int initStruct (char * str, Specif * sp);
int parseToInt(char * str, int * val);

int s21_sscanf(const char *str, const char *format, ...);

int s21_sscanf(const char *str, const char *format, ...) {
  int count = 0;
  Specif sp = {0};
  UnionVal up = {0};
  sp.val = up; 
  char * start = (char *)str;
  char * startf = (char *)format;
  char * spec = "cdieEfgGosuxXpn%"; 
  va_list ptr;
  va_start(ptr, format);
  while (*format) {
    if (*format == '%') {
      format++;
      {
        int a = (long long int)strpbrk(format, spec) - (long long int)format + 1;
        char * buf = strndup(format, a);
        initStruct(buf, &sp);
        free(buf);
        if (sp.err) {
          break;
        }
        format += a;
      }
      {
        sp.count = count;
        int size = getValue((char *)str, &sp);
        if (sp.err) {
          break;
        }
        setValue(ptr, &sp);
        if (!sp.err) {
          count = sp.count;
        } else {
          count = -1;
        }
        str += size;
      }
          
    } else {
      format++;
    }    
  }
  va_end(ptr);
  str = start;
  format = startf;
  return count;
}



int getValue (char * str, Specif * sp) {
  int count = 0;
  int step = 0;
  if (sp->spec == 'c') {
    ;
  }
  if (sp->spec == '%') {
    ;
  }
  if (sp->spec == 'n') {
    sp->val.ld = sp->count;
  }
  if (sp->spec == 's') {
    ;
  }  //-9223372036854775808
     // 9223372036854775808
  if (sp->spec == 'i' || sp->spec == 'd') {
    count = getIntIDU(str, sp);
  }
  if (sp->spec == 'u') {
    count = getIntIDU(str, sp);
  }
  if (sp->spec == 'o' || sp->spec == 'x' || sp->spec == 'X') {
    count = getIntIDU(str, sp);
  }
  if (sp->spec == 'p') {
    ;
  }
  if (sp->spec == 'f') {
    ;
  }
  if (sp->spec == 'e' || sp->spec == 'E') {
    ;
  }
  if (sp->spec == 'g' || sp->spec == 'G') {
    ;
  }
  return count;
}

int getIntIDU (char * str, Specif * sp) {
  int err = 0;
  int count = 0;
  int notion = 10;
  int n = 0;
  if (s21_strchr("xX", sp->spec)) {
    notion = 16;
  }
  if (s21_strchr("o", sp->spec)) {
    notion = 8;
  }
  
  long long int result = 0;
  int mark = 1;
  if ('+' == *str || '-' == *str) {
    if ('-' == *str) {
      mark = -1;     
    }
    if (sp->setWidth) {
      sp->width--;
      if (!sp->width) {
        err = 1;
      }
    }
    str++;
    count++;
  }
  if (!err && s21_strchr("0123456789abcdef", *str)) {  
    if (10 == notion) {
      while ((s21_strchr("0123456789", *str) && 0 != *str) && (sp->width || !sp->setWidth)) {
        result = (result * notion) + (*str - '0');
        sp->width--;
        count++;
        str++;
      }
    }
    if (8 == notion) {
      if ('0' == *str) {
        str++;
        count++;
      }
      while ((s21_strchr("01234567", *str) && 0 != *str) && (sp->width || !sp->setWidth)) {
        result = (result * notion) + (*str - '0');
        sp->width--;
        count++;
        str++;
      }
    }
    if (16 == notion) {
      if (strncmp("0X", str, 2) || strncmp("0x", str, 2)) {
        str += 2;
        count += 2;
      }
      while ((s21_strchr("0123456789abcdef", *str) && 0 != *str) && (sp->width || !sp->setWidth)) {
        result = (result * notion) + ('9' < *str ? toUperChar(*str) - 55 : *str - '0');
        sp->width--;
        count++;
        str++;
      }
    }
    // void *pointer = va_arg(ptr, void *); 
    result *= mark;
    sp->val.ld = result;
  } else {
    sp->err = 1;
  }
  return count;
}

char toUperChar(char c) {
  return (96 < c && 123 > c) ? c - 32 : c;
}

char toLowerChar(char c) {
  return (64 < c && 91 > c) ? c + 32 : c;
}

void setValue(va_list ptr, Specif * sp) {
  if ('*' != sp->pod /*&& '%' == sp->spec*/) {
    void *pointer = va_arg(ptr, void *);
    switch (toLowerChar(sp->spec)) { 
      case 'd':
      case 'i':
      case 'n':
        if (1 == sp->countMod) {
          if ('l' == sp->mod) {
            *(long *)pointer = (long)sp->val.ld;
          } else if ('h' == sp->mod) {
            *(short *)pointer = (short)(long int)lroundl(sp->val.ld);
          } else {
            *(int *)pointer = (int)sp->val.ld;
          }
        }
        if (2 == sp->countMod) {
          if ('l' == sp->mod) {
            *(long long *)pointer = (long long)sp->val.ld;
          } else if ('h' == sp->mod) {
            long long unsigned d = llroundl(sp->val.ld);
            int a = (int)d;
            if (d > 999999999999999999999 || a > 999999999999999999999) {
              printf("!!");
            }
            *(signed char *)pointer = (signed char)a;
          }
        }
        break;
      case 'u':
      case 'x':
      case 'o':
        if (1 == sp->countMod) {
          if ('l' == sp->mod) {
            *(unsigned long *)pointer = (unsigned long)sp->val.ld;
          } else if ('h' == sp->mod) {
            *(unsigned short *)pointer = (unsigned short)(long int)(double)sp->val.ld;
          } else {
            *(unsigned int *)pointer = (unsigned int)sp->val.ld;
          }
        }
        if (2 == sp->countMod) {
          if ('l' == sp->mod) {
            *(unsigned long long *)pointer = (unsigned long long)sp->val.ld;
          } else if ('h' == sp->mod) {
            *(unsigned char *)pointer = (unsigned char)(long int)(double)sp->val.ld;
          }
        }
        break;
      case 'p':
          *(va_arg(ptr, void **)) = (void *)(unsigned long)sp->val.ld;
        break;
      case 'f':
      case 'e':
      case 'g':
        if ('l' == sp->mod) {
          *(va_arg(ptr, double *)) = (double)sp->val.ld;
        } else if ('L' == sp->mod) {
          *(va_arg(ptr, long double *)) = sp->val.ld;
        } else {
          *(va_arg(ptr, float *)) = (float)sp->val.ld;
        }
        break;
      case 'c':
        s21_memcpy(va_arg(ptr, void *), sp->val.p, sp->width ? sp->width : 1);
        break;
      case 's':
        s21_strcpy(va_arg(ptr, char *), (char *)(sp->val.p));
        break;
    }
    sp->count += 1;
  }
  if ('c' == sp->spec || 's' == sp->spec) {
    free(sp->val.p);
  }
}

int stringToIntOX(char * str, Specif * sp, va_list ptr) {
  int notion = 8;
  int n = 0;
  if (s21_strchr("xX", sp->spec)) {
    notion = 16;
  }
  long long int result = 0;  
  if (sp->setWidth) {
    while (s21_strchr("0123456789abcdef", *str)) {
      result +=  oxToDec(str + 1, &n, notion);
      if (s21_strchr("abcdef", *str)) {
        result += (*str - 55) * (long long int)pow(notion, n);
      } else {
        result =  (*str - 48) * (long long int)pow(notion, n);
      }  
      n += 1;
    }
  } else {
    while (s21_strchr("0123456789abcdef", *str) && sp->width) {
      result +=  oxToDec(str + 1, &n, notion);
      if (s21_strchr("abcdef", *str)) {
        result += (*str - 55) * (long long int)pow(notion, n);
      } else {
        result =  (*str - 48) * (long long int)pow(notion, n);
      }  
      n += 1;
    }
  } 
  if ('*' != sp->pod) {
    sp->count += 1;
    if ('l' == sp->mod) {
      *(va_arg(ptr, long unsigned *)) = result;
    } else {
      *(va_arg(ptr, unsigned *)) = result;
    }
  }
  return n;
}

long long int oxToDec(char * str, int * n, int notion) {  
  long long int result = 0;
  if (s21_strchr("0123456789abcdef", *(str + 1))) {
    result +=  oxToDec(str + 1, n, notion);
    if (s21_strchr("abcdef", *str)) {
        result += (*str - 55) * (long long int)pow(notion, *n);
      } else {
        result =  (*str - 48) * (long long int)pow(notion, *n);
      }  
    *n += 1;
  }
  return result;
}

int stringToInt(char * str, long long int * res) {
  long long int result = 0;
  int mark = 1;
  if ('+' == *str || '-' == *str) {
    if ('-' == *str) {
      mark = -1;
    }
    str++;
  }
  while (*str) {
    result = (result * 10) + (*str - 48);
  }  
  *res = result;
  return 0;
}

//////////////////// init my struct /////////////

int initStruct (char * str, Specif * sp) {  
  int err = 0;
  char * modif = "hlL";
  char * spec = "cdieEfgGosuxXpn%";
  Specif qwer = {0};
  *sp = qwer;
  while (*str != '\0' && !err) {
    if (*str == '*') {
      sp->pod = '*';
      str++;
    } else if (*str >= '0' && *str <= '9') {
      str += parseToInt(str, &(sp->width));
      sp->setWidth = 1;
    }
    while (strchr(modif, *str) && !err) {
      if ('\0' == sp->mod) {
        sp->mod = *str;
        sp->countMod = 1;
        str++;
      } else if (sp->mod == *str && sp->countMod < 2) {
        sp->countMod = 2;
        str++;
      } else {
        err = 1;
      }
    }
    if (!sp->spec) {
      if (strchr(spec, *str) && !err) {
        sp->spec = *str;
        str++;
      }
    } else {
      err = 1;
    }    
  }
  return err;
}



int parseToInt(char * str, int * val) {
  int count = 0;
  *val = 0;
  while (*str >= '0' && *str <= '9') {
    *val *= 10;
    *val += *str - '0';
    str++;
    count++;
  }
  
  return count;
}







