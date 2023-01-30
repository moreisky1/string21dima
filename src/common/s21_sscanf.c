#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <wchar.h>
#include <errno.h>

#include "../s21_string.h"

#if defined (__APPLE__)
  #define STR_NULL "(null)"
#endif
#if defined (__linux__)
  #define STR_NULL "(nil)"
#endif

typedef union {
  void *p;
  long double ld;
  long long int li;
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
  char next;
  int countB;
}Specif;

char toUperChar(char c);
char toLowerChar(char c);
int isWhiteSpace(char c);

void setValue(va_list ptr, Specif * sp);
int strToStr(char * str, Specif * sp);

long long int oxToDec(char * str, int * n, int notion);
int getIntIDU (char * str, Specif * sp);
int stringToIntOX(char * str, Specif * sp, va_list ptr);

long double getValueModDoub(Specif sp, va_list ptr);
long long getValueModInt(Specif sp, va_list ptr);
long long unsigned getValueModUInt(Specif sp, va_list ptr);

char* strchrsc(const char* str, int c);

int getValue (char * str, Specif * sp);
int initStruct (char * str, Specif * sp);
int parseToInt(char * str, int * val);

int s21_sscanf(const char *src, const char *format, ...);

int s21_sscanf(const char *src, const char *format, ...) {
  __error();
  char * str = s21_to_lower(src);
  int count = 0;
  int countB = 0;
  
  Specif sp = {0};
  // UnionVal up = {0};
  // sp.val = up; 
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
        sp.countB = countB;
        sp.next = *(format + a);
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
          count = -1;
          break;
        }
        str += size;
        sp.countB += size;
        countB = sp.countB;
        setValue(ptr, &sp);
        if (!sp.err) {
          count = sp.count;
        } else {
          count = -1;
        }
        
      }
          
    } else {
      format++;
    }    
  }
  va_end(ptr);
  str = start;
  format = startf;
  free(str);
  return count;
}

int strToStr(char * str, Specif * sp) {
  
  s21_size_t counter = 0;
  
  // if (sp->setWidth) {
  //   while (**buffer && config.set[(unsigned char)**buffer])
  //     string[counter++] = *(*buffer)++;
  //   free(config.set);
  // } else {
    s21_size_t size = sp->setWidth ? (unsigned long)sp->width : s21_strlen(str);
    char *string = calloc(size + 1, sizeof(char));
    for (s21_size_t i = 0; i < size && *str && !isWhiteSpace(*str); ++i) {
      string[i] = *(str);
      str++;
      counter++;
    }
    sp->val.p = string;
  // }
  return counter < size ? counter : size;
}

int isWhiteSpace(char c) {
char spase[7] = {9, 10, 11, 12, 13, 32, 0};
return strchrsc(spase, c) ? 1 : 0;
}

int strToChar(const char *str, Specif * sp) {
  size_t len = s21_strlen(str);
  size_t size = sp->setWidth ? (sp->width < len ? sp->width : len) : 1;
  char *pointer = malloc(size * sizeof(char));
  int spa = 0;
  s21_memcpy(pointer, str, size);
  
  if (isWhiteSpace(sp->next)) {
    spa += size;
    while (isWhiteSpace(*(str + size))) {
      str++;
      spa++;
    }
  }
  
  sp->val.p = pointer;
  return size > spa ? size : spa;
}

int getValue (char * str, Specif * sp) {
  int count = 0;
  int step = 0;
  switch (toLowerChar(sp->spec)) {
  case 'i':
  case 'd':
  case 'u':
  case 'x':
  case 'o':
    count = getIntIDU(str, sp);
    break;
  case 'p':
    count = getIntIDU(str, sp);
    break;
  case 'n':
    sp->val.li = sp->countB;
    // sp->err = 1;
    break;
  case 'c':
    count = strToChar(str, sp);
    break;
  case 's':
    count = strToChar(str, sp);
    break;
  case '%':
    count = strToChar(str, sp);
    break;
  default:
    break;
  }
  // if (sp->spec == 'c') {
  //   ;
  // }
  // if (sp->spec == '%') {
  //   ;
  // }  
  // if (sp->spec == 's') {
  //   ;
  // }
  // if (sp->spec == 'n') {
  //   sp->val.ld = sp->count;
  // } 
  // if (sp->spec == 'i' || sp->spec == 'd') {
  //   count = getIntIDU(str, sp);
  // }
  // if (sp->spec == 'u') {
  //   count = getIntIDU(str, sp);
  // }
  // if (sp->spec == 'o' || sp->spec == 'x' || sp->spec == 'X') {
  //   count = getIntIDU(str, sp);
  // }
  // if (sp->spec == 'p') {
  //   ;
  // }
  // if (sp->spec == 'f') {
  //   ;
  // }
  // if (sp->spec == 'e' || sp->spec == 'E') {
  //   ;
  // }
  // if (sp->spec == 'g' || sp->spec == 'G') {
  //   ;
  // }
  // if (!count && '') {
  //   sp->err = 1;
  // }
  return count;
}

int getIntIDU (char * str, Specif * sp) {
  long long int max = INT64_MAX;
  long long int result = 0;
  int err = 0;
  int count = 0;
  int notion = 10;
  int n = 0;
  if (strchrsc("xXp", sp->spec)) {
    notion = 16;
  }
  if (strchrsc("o", sp->spec)) {
    notion = 8;
  }
  if (strchrsc("i", sp->spec)) {
    notion = 0;
  }
  char spase[7] = {9, 10, 11, 12, 13, 32, 0};
  while (strchrsc(spase, *str)) {
    str++;
    count++;
  }
  if ('p' == sp->spec && '0' == *str &&  'x' == *(str + 1)) {
    str += 2;
    count += 2;
    if (sp->setWidth) {
      sp->width -= 2;
      if (!sp->width) {
        sp->err = 1;
      }
    }
  }
  int mark = 1;
  if ('+' == *str || '-' == *str) {
    if ('-' == *str) {
      mark = -1;     
    }
    if (sp->setWidth) {
      sp->width--;
      if (!sp->width) {
        sp->err = 1;
      }
    }
    str++;
    count++;
  }
  if (!sp->err && strchrsc("0123456789abcdef", *str)) {
      if (sp->setWidth) {
        int size = (int)s21_strspn(str, "0123456789abcdefx");
        sp->width = sp->width > size ? size : sp->width;
        char * buf = (char *)calloc((sp->width + 1), sizeof(char));
        s21_strncpy(buf, str, sp->width);
        result = strtoll(buf, NULL, notion);
        count += sp->width;
        free(buf);
      } else {
        char * st = str;
        result = strtoll(str, &str, notion);
        count += str - st;
      }
      if (errno == ERANGE && 0 > mark && result == INT64_MAX) {
        result *= mark;
        result -= 1;
      } else {
        result *= mark;
      }
      sp->val.li = result;
    } else {
      if ('p' != sp->spec) {
          sp->err = -1;
      }
    }
    if (isWhiteSpace(sp->next)) {
      str += count;
      while (isWhiteSpace(*str)) {
        str++;
        count++;
      }
    }
    // if (8 == notion) {
    //   if ('0' == *str) {
    //     str++;
    //     count++;
    //   }
    //   while ((strchrsc("01234567", *str) && 0 != *str) && (sp->width || !sp->setWidth)) {
    //     result = (result * notion) + (*str - '0');
    //     sp->width--;
    //     count++;
    //     str++;
    //   }
    // }
    // if (16 == notion) {
    //   if (strncmp("0X", str, 2) || strncmp("0x", str, 2)) {
    //     str += 2;
    //     count += 2;
    //   }
    //   while ((strchrsc("0123456789abcdef", *str) && 0 != *str) && (sp->width || !sp->setWidth)) {
    //     result = (result * notion) + ('9' < *str ? toUperChar(*str) - 55 : *str - '0');
    //     sp->width--;
    //     count++;
    //     str++;
    //   }
    // }
  return count;
}

char toUperChar(char c) {
  return (96 < c && 123 > c) ? c - 32 : c;
}

char toLowerChar(char c) {
  return (64 < c && 91 > c) ? c + 32 : c;
}

void setValue(va_list ptr, Specif * sp) {
  // long long unsigned mi = 9223372036854775807;
  if ('*' != sp->pod /*&& '%' == sp->spec*/) {
    void *pointer = NULL;
    if ('p' != toLowerChar(sp->spec)) {
      pointer = va_arg(ptr, void *);
    }
    
    switch (toLowerChar(sp->spec)) { 
      case 'd':
      case 'i':
      case 'n':
        if (2 == sp->countMod) {
          if ('l' == sp->mod) {
            *(long long *)pointer = (long long)sp->val.li;
          } else if ('h' == sp->mod) {
            *(signed char *)pointer = (signed char)(long int)sp->val.li;
          }
        } else {
          if ('l' == sp->mod) {
            *(long *)pointer = (long)sp->val.li;
          } else if ('h' == sp->mod) {
            *(short *)pointer = (short)(long int)lroundl(sp->val.li);
          } else {
            *(int *)pointer = (int)sp->val.li;
          }
        }
        break;
      case 'u':
      case 'x':
      case 'o':
        if (2 == sp->countMod) {
          if ('l' == sp->mod) {
            *(unsigned long long *)pointer = (unsigned long long)sp->val.li;
          } else if ('h' == sp->mod) {
            *(unsigned char *)pointer = (unsigned char)(long int)(double)sp->val.li;
          }
        } else {
          if ('l' == sp->mod) {
            *(unsigned long *)pointer = (unsigned long)sp->val.li;
          } else if ('h' == sp->mod) {
            *(unsigned short *)pointer = (unsigned short)(long int)(double)sp->val.li;
          } else {
            *(unsigned int *)pointer = (unsigned int)sp->val.li;
          }
        }
        break;
      case 'p':      
          *(va_arg(ptr, void **)) = (void *)sp->val.li;
        break;
      case 'f':
      case 'e':
      case 'g':
        if ('l' == sp->mod) {
          *(double *)pointer = (double)sp->val.ld;
        } else if ('L' == sp->mod) {
          *(long double *)pointer = sp->val.ld;
        } else {
          *(float *)pointer = (float)sp->val.ld;
        }
        break;
      case 'c':
        s21_memcpy(pointer, sp->val.p, sp->setWidth ? sp->width : 1);
        break;
      case 's':
        s21_strcpy((char *)pointer, (char *)(sp->val.p));
        break;
    }
    if ('n' != sp->spec) {
      sp->count += 1;
    }
  }
  if ('c' == sp->spec || 's' == sp->spec) {
    free(sp->val.p);
  }
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

char* strchrsc(const char* str, int c) {
  char* res = NULL;
  int size = (int)s21_strlen(str);
  if (0 <= c && 127 >= c) {
    for (int i = 0; i < size; i++) {
      if (str[i] == c) {
        res = (char*)str + i;
        break;
      }
    }
  }
  return res;
}

