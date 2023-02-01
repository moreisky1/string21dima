// #include "../s21_string.h"
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
  int prec;
  char pod;
  int count;
}Specif;

int stringToString(Specif sp, char * str, va_list ptr);
int charToString(Specif sp, char * str, va_list ptr);

int getChar(Specif sp, char * str, char c);
int getWchar(Specif sp, char * str, wchar_t c);

int stringWcpy(char * str, wchar_t * buf, Specif sp);
int stringCpy(char * str, char * buf, Specif sp);
int formatWcharString(Specif sp, char * str, wchar_t * buf);
int formatCharString(Specif sp, char * str, char * buf);

int stringDuble(Specif sp, char *str, long double a);
int getCifer(char * str, __int128_t a, int notation);
int getCiferU(char * str, long long unsigned a, int notation);
int longDefine (int a);

long double getValueModDoub(Specif sp, va_list ptr);
long long getValueModInt(Specif sp, va_list ptr);
long long unsigned getValueModUInt(Specif sp, va_list ptr);

int formatForInputFl (char * str, Specif sp);
int formatForInputInt(Specif sp, char * str);
int fillingInWidthBuffer(Specif sp, char * buf, int n);
int insertMy(char * str, char c, int n);

int getValue (char * str, Specif * sp, va_list ptr);
int initStruct (char * str, Specif * sp, va_list ptr);
int parseToInt(char * str, int * val);

long double myRound(Specif sp, char * str, long double a, int * man);
int doubleToStringG(char * str, long double a, Specif * sp);
int doubleToString(char * str, long double a, Specif sp);
int signedToString(char * str, __int128_t a, Specif sp);
int unsignedToString(char * str, long long unsigned a, Specif sp);

int s21_sprintf(char *str, const char *format, ...);

int s21_sprintf(char *str, const char *format, ...) {
  int count = 0;
  Specif sp = {0};
  char * spec = "cdieEfgGosuxXpn%";  
  char * start = str;
  va_list ptr;
  va_start(ptr, format);
  while (*format) {
    if (*format == '%') {
      format++;
      {
      int a = (long long int)strpbrk(format, spec) - (long long int)format + 1;
      char * buf = (char *)calloc(a, sizeof(char));
      strncpy(buf, format, a);
      initStruct(buf, &sp, ptr);
      free(buf);
      format += a;
      }
      {
      char buf[4096] = "";
      sp.count = count;
      int size = getValue(buf, &sp, ptr);
      if (strchr("feEgG", sp.spec)){
        formatForInputInt(sp, buf);
      }
      
      if (strchr("iduoxXp", sp.spec)){
        formatForInputInt(sp, buf);
      }
      if (strchr("cs", sp.spec)){
        ;
      }
      // todo  lowercase +32
      if (strchr("xge", sp.spec)) {
        for (size_t i = 0; buf[i]; i++) {
          if (64 < buf[i] && 91 > buf[i]) {
            buf[i] += 32;
          }          
        }        
      }
      if (strchr("XGE", sp.spec)) {
        for (size_t i = 0; buf[i]; i++) {
          if (96 < buf[i] && 123 > buf[i]) {
            buf[i] -= 32;
          }          
        }        
      }
      if (strchr("p", sp.spec)) {
        #if defined (__linux__)
        if (sp.flag.pl) {
          memmove(buf + 1, buf, strlen(buf));
          *buf = '+';
        } else if (sp.flag.spase) {
          memmove(buf + 1, buf, strlen(buf));
          *buf = ' ';
        }
        #endif
        for (size_t i = 0; buf[i]; i++) {
          if (64 < buf[i] && 71 > buf[i]) {
            buf[i] += 32;
          }          
        }        
      }
      // todo  lowercase +32
      size = (size > (int)strlen(buf))? size : (int)strlen(buf);
      strcat(str, buf);
      str += size;
      count += size;
      }
          
    } else {
      if (*format != '\0'){
        *str = *format;
        str++;
        count++;
      }
      format++;
    }    
  }
  va_end(ptr);
  *str = '\0';
  str = start;
  return count;
}



int getValue (char * str, Specif * sp, va_list ptr) {
  int count = 0;
  if (sp->spec == 'c') {
    count = charToString(*sp, str, ptr);
  }
  if (sp->spec == '%') {
    *str = '%';
    str++;
    count++;
  }
  if (sp->spec == 'n') {
    *(va_arg(ptr, int *)) = sp->count;
  }
  if (sp->spec == 's') {
    count = stringToString(*sp, str, ptr);      
  }  
  if (sp->spec == 'i' || sp->spec == 'd') {
    long long int a = getValueModInt(*sp, ptr);
    signedToString(str, a, *sp);
  }
  if (sp->spec == 'o' || sp->spec == 'u') {
    long long unsigned int a = getValueModUInt(*sp, ptr);
    unsignedToString(str, a, *sp);
  }
  if (sp->spec == 'x' || sp->spec == 'X') {
    long long unsigned int a = getValueModUInt(*sp, ptr);
    unsignedToString(str, a, *sp);
  }
  if (sp->spec == 'p') {
    sp->flag.grid = 1;
    long long unsigned int a = (long long unsigned)va_arg(ptr, void *);
    #if defined (__linux__)
    if (0 == a) {      
      sp->spec = 's';
      count = formatCharString(*sp, str, STR_NULL);
    } else {
    #endif
      count = unsignedToString(str, a, *sp);
    #if defined (__linux__)
    }
    #endif
  }
  if (sp->spec == 'f') {
    long double a = getValueModDoub(*sp, ptr);
    count = doubleToString(str, a, *sp);
  }
  if (sp->spec == 'e' || sp->spec == 'E') {
    long double a = getValueModDoub(*sp, ptr);
    count = doubleToString(str, a, *sp);
  }
  if (sp->spec == 'g' || sp->spec == 'G') {
    long double a = getValueModDoub(*sp, ptr);
    count = doubleToStringG(str, a, sp);
  }
  return count;
} 

int charToString(Specif sp, char * str, va_list ptr) {
  int count = 0;
  if ('l' == sp.mod) {
    wchar_t buf = va_arg(ptr, wchar_t);
    count = getWchar(sp, str, buf);
  }
  else {
    char buf = va_arg(ptr, int);
    count = getChar(sp, str, buf);
  }
  return count;
}

int getWchar(Specif sp, char * str, wchar_t c) {
  int count = 0;
  char buf[256] = {'\0'};
  wctomb(buf, c);
  char dop = ' ';
  if (sp.flag.zero && !sp.flag.min) {
    dop = '0';
  }
  if ((int)strlen(buf) < sp.width) {
    if (sp.flag.min) {
      // |<-
        strcpy(str, buf);
        for (int i = (int)strlen(buf); i < sp.width; i++) {
          str[i] = dop;
        }
        str[sp.width] = '\0';
      } else {
      // ->|
      for (int i = 0; i < sp.width - (int)strlen(buf); i++) {
        str[i] = dop;
      }
      strcpy(str + (sp.width - (int)strlen(buf)), buf);
    }
    count = sp.width;
  } else {
    strcpy(str, buf);
    count = (int)strlen(buf);
  }
  return count;
}

int getChar(Specif sp, char * str, char c) {
  int count = 0;
  char dop = ' ';
  #if defined (__APPLE__)
  if (sp.flag.zero && !sp.flag.min) {
    dop = '0';
  }
  #endif
  if (1 < sp.width) {
    if (sp.flag.min) {
      // |<-
        *str = c;
        for (int i = 1; i < sp.width; i++) {
          str[i] = dop;
        }
        str[sp.width] = '\0';
      } else {
      // ->|
      for (int i = 0; i < sp.width - 1; i++) {
        str[i] = dop;
      }
      str[sp.width - 1] = c;
    }
    count = sp.width;
  } else {
    *str = c;
    count++;
  }
  return count;
}

int stringToString(Specif sp, char * str, va_list ptr) {
  int count = 0;
  char * null = strdup(STR_NULL);
  if ('l' == sp.mod) {
    wchar_t * buf = va_arg(ptr, wchar_t *);
    if (buf == S21_NULL) {      
      count = formatCharString(sp, str, null);
    } else {
      count = formatWcharString(sp, str, buf);
    }        
  }
  else {
    char * buf = va_arg(ptr, char *);
    if (buf == S21_NULL) {
      buf = null;
    }
    count = formatCharString(sp, str, buf);    
  }
  free(null);
  return count;
}

int formatWcharString(Specif sp, char * str, wchar_t  * buf) {
  int count = 0;
  char bus[4096] = "";
  stringWcpy(bus, buf, sp);
  int size = (sp.precision && sp.prec) ? sp.precision : (int)strlen(bus);
  char dop = ' ';
  if (sp.flag.zero && !sp.flag.min) {
    dop = '0';
  }
  if (size < sp.width) {
    if (sp.flag.min) {
      // |<-
        strcpy(str, bus);
        for (int i = size; i < sp.width; i++) {
          str[i] = dop;
        }
        str[sp.width] = '\0';
      } else {
      // ->|
      for (int i = 0; i < sp.width - size; i++) {
        str[i] = dop;
      }
      strcpy(str + (sp.width - size), bus);
    }
    count = sp.width;
  } else {
    strcpy(str, bus);
    count = size;
  }
  return count;
}

int formatCharString(Specif sp, char * str, char * buf) {
  int count = 0;
  int size = (sp.prec) ? (sp.precision > (int)strlen(buf) ? (int)strlen(buf) : sp.precision) : (int)strlen(buf);
  char dop = ' ';
  #if defined (__APPLE__)
  if (sp.flag.zero && !sp.flag.min) {
    dop = '0';
  }
  #endif
  if (size < sp.width) {
    if (sp.flag.min) {
      // |<-
        stringCpy(str, buf, sp);
        for (int i = size; i < sp.width; i++) {
          str[i] = dop;
        }
        str[sp.width] = '\0';
      } else {
      // ->|
      for (int i = 0; i < sp.width - size; i++) {
        str[i] = dop;
      }
      stringCpy(str + (sp.width - size), buf, sp);
    }
    count = sp.width;
  } else {
    stringCpy(str, buf, sp);
    count = size;
  }
  return count;
}

int stringCpy(char * str, char * buf, Specif sp) {
  if (sp.prec) {
    strncpy(str, buf, sp.precision);
  } else {
    strcpy(str, buf);
  }
  return 0;
}

int stringWcpy(char * str, wchar_t * buf, Specif sp) { 
  if (sp.precision && sp.prec) {
    for (int i = 0; i < sp.precision; i++) {
      /* code */
      char bus[256] = {'\0'};
      wctomb(bus, buf[i]);
      strcpy(str,bus);
      str += strlen(bus);
    }
  } else {
    for (int i = 0; buf[i] != '\0'; i++) {
      /* code */
      char bus[256] = {'\0'};
      wctomb(bus, buf[i]);
      strcpy(str,bus);
      str += strlen(bus);
    }
  }
  return 0;
}

//////////////////// init my struct /////////////

int initStruct (char * str, Specif * sp, va_list ptr) {
  
  char * flag = "-+ #0";
  char * modif = "hlL";
  Specif qwer = {0};
  qwer.precision = 1;
  *sp = qwer;
  while (*str != '\0') {
    while (strchr(flag, *str)) {      
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
      sp->prec = 1;
      if (*str == '*') {
        sp->precision = va_arg(ptr, int);
      } else {
        if ('9' >= *str && '0' <= *str) {
        str += parseToInt(str, &(sp->precision));         //то забираю все цифры в число precision
        } else {
          sp->precision = 0;
        }
      }
    }
    while (strchr(modif, *str)) {
      sp->mod = *str;
      sp->countMod++;
      str++;
    }
    sp->spec = *str;
    sp->pod = *str;
    str++;
  }
  if (!sp->prec && strchr("eEfgG", sp->spec)) {
    sp->precision = 6;
  }
  if (!sp->prec && !(strchr("eEfgG", sp->spec))) {
    sp->precision = 1;
  }
  return 0;
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

//////////////////////////////////////////////////////

////////////////////// Number to String///////////////////////////

int doubleToStringG(char * str, long double a, Specif * sp) {
  char bufE[4096] = "";
  if (!sp->precision) {
    sp->precision = 1;
  }
  int man = 0;
  sp->spec = 'e';
  myRound(*sp, bufE, a, &man);
  sp->spec = 'g';
  if(-4 <= man && man < sp->precision) {
    sp->spec = 'f';
    sp->precision = sp->precision - (man + 1);
  } else {
    sp->spec = 'e';
    sp->precision = sp->precision - 1;
  }
  doubleToString(str, a, *sp);
  sp->spec = 'g';

  // if (strchr("gG", sp->pod) && strcmp(str, "0")){
  //   formatForInputFl(str, *sp);
  // }
  return 0;
}

long double myRound(Specif sp, char * str, long double a, int * man) {
  int round = 5;
  if (0 > a) {
    round *= -1;
  }
  
  if (strchr("eE",sp.spec)) {
    if (/*a < 1e-30 && a > -1e-30*/ a == 0) {
      *str = '0';
      if (sp.precision) {
        *(str + 1) = '.';
        *(str + 2) = '0';
      }
    } else {
      if ((long long int)(a) == 0) {
        while ((long long int)a == 0) {
          a *= 10;
          (*man)--;
        }
      } else {
        while (9 < (long long int)a || -9 > (long long int)a ) {
          a /= 10;
          (*man)++;
        }
      } 
    }
  }
    if (a != 0) {
      double vr = pow(0.1, sp.precision + 1);
      a += round * vr;
    }
  // if (0 > a) {
  //   a = floorl(a * pow(10, sp.precision)) / pow(10, sp.precision);
  // } else {
  //   a = floorl(a * pow(10, sp.precision )) / pow(10, sp.precision);
  // }
  if (strchr("eE",sp.spec)) {
    if (a < 1e-30 && a > -1e-30) {
      *str = '0';
      if (sp.precision) {
        *(str + 1) = '.';
        *(str + 2) = '0';
      }
    } else {
      if ((long long int)(a + 0.1) == 0) {
        while ((long long int)a == 0) {
          a *= 10;
          (*man)--;
        }
      } else {
        while (9 < (long long int)a || -9 > (long long int)a ) {
          a /= 10;
          (*man)++;
        }
      } 
    }
  }
  return a;
}

int getCifer(char * str, __int128_t a, int notation) {
  int count = 0;
  if(9 < a) {
    count += getCifer(str, a / notation, notation);
    str += count;
  }
  int buf = a % notation;
  *str = buf + '0';
  count++;
  return count;
}

int getCiferU(char * str, long long unsigned a, int notation) {
  int count = 0;
  if((long long unsigned)(notation - 1) < a) {
    count += getCiferU(str, a / notation, notation);
    str += count;
  }
  int buf = a % notation;
  if ( buf > 9 && notation == 16) {
    *str = buf + 55;
  } else {
    *str = buf + '0';
  }
  count++;
  return count;
}

int doubleToString(char * str, long double a, Specif sp) {
  if (sp.flag.min) {
    sp.flag.zero = 0;
  }
  if (sp.flag.pl) {
    sp.flag.spase = 0;
  }
  int count = 0;
  char mark = '+';
  int man = 0;
  a = myRound(sp, str, a, &man);
  stringDuble(sp, str, a);
  
  if ('e' == sp.spec || 'E' == sp.spec) {
    if (man < 0) {
      man *= -1;
      mark = '-';
    }
    
    str += strlen(str);
    *str = sp.spec;
    *(str + 1) = mark;
    if (man < 10) {
      *(str + 2) = '0';
      *(str + 3) = '0' + man;
      count += 2;
    } else {
      count += getCifer(str + 2, man, 10);
    }
    count += 2;
  }

  return count;  
}

int stringDuble(Specif sp, char *str, long double a) {
  __int128_t whole = (__int128_t)a;
  char * buf = str;
  long double fractional;
  if (0 > a) {
    fractional = whole - a;
  } else {
    fractional = a - whole;
  }      
  str += signedToString(str, whole, sp);
  if (sp.precision || sp.flag.grid) {
    *str = '.';
    str++;
    
    for (int i = 0; i < sp.precision ; i++) {
      fractional = (fractional - (int)fractional) * 10;
      int buf = (int)fractional;
      *str = buf % 10 + '0';
      str++;
    }
    if (strcmp(str, "0")){
      if (strchr("gG", sp.pod) && !sp.flag.grid) {
        formatForInputFl(buf, sp);
      }
      ;
    }
  }
  return 0;
}

int unsignedToString(char * str, long long unsigned a, Specif sp) {
  int count = 0;
  int notation = 10;
  if (sp.spec == 'o') {
    notation = 8;
  } else if ('x' == sp.spec|| 'X' == sp.spec || 'p' == sp.spec ) {
    notation = 16;
  }
  if (0 == a) {
    *str = '0';
    count++;
  } else {
    int step = getCiferU(str, a, notation);    
    str += step;
    count += step;
  }
  return count;
}

int signedToString(char * str, __int128_t a, Specif sp) {
  int count = 0;
  if (sp.flag.pl && 0 <= a) {
    *str = '+';
    str++;
    count++;
  }
  if (0 > a) {
    *str = '-';
    str++;
    count++;
    a *= -1;
  } else {
    if (!sp.flag.pl && /*!sp.flag.zero && */sp.flag.spase) {
      *str = ' ';
      str++;
      count++;
    }    
  }
  if (0 == a) {
    *str = '0';
    count++;
  } else {
    int step = getCifer(str, a, 10);    
    str += step;
    count += step;
  }
  return count;
}

/////////////////////////////////////////////////

/////////////////////modificator l L ll h///////////////////////////



long double getValueModDoub(Specif sp, va_list ptr) {
  long double result = 0;
  if (sp.mod == '\0') {
    result = va_arg(ptr, double);
  } 
  if (sp.mod == 'L') {
    result = va_arg(ptr, long double);
  } 
  return result;
}

long long getValueModInt(Specif sp, va_list ptr) {
  long long result = 0;  
  if (sp.mod == 'h') {
    result = (short int)va_arg(ptr, int);
  }
  if (sp.mod == 'l') {
    if (1 < sp.countMod) {
      result = va_arg(ptr, long long int);
    } else {
      result = va_arg(ptr, long int);
    }    
  }
  if (sp.mod == '\0') {
    result = va_arg(ptr, int);
  }  
  return result;
}

long long unsigned getValueModUInt(Specif sp, va_list ptr) {
  long long unsigned result = 0;
  // void * p = va_arg(ptr, void *);
  if (sp.mod == 'h') {
    result = (unsigned short int)va_arg(ptr, unsigned int);
  }
  if (sp.mod == 'l') {
    if (1 < sp.countMod) {
      result = va_arg(ptr, long long unsigned int);
    } else {
      result = va_arg(ptr, long unsigned int);
    }    
  }
  if (sp.mod == '\0') {
    result = va_arg(ptr, unsigned int);
  }
  return result;
}

///////////////////////////////////////////////

//////////////////////// format for input ///////////////

int formatForInputFl (char * str, Specif sp) {
  for (int i = strlen(str) - 1; str[i] == '0'; i--){
    str[i] = '\0';
  }
  if (str[strlen(str) - 1] == '.' && !sp.flag.grid) {
    str[strlen(str) - 1] = '\0';
  } 
  return 0;
}

int formatForInputInt(Specif sp, char * str) {
  if (0 == sp.precision && (!strcmp(str, " 0") || !strcmp(str, "0"))) {
    if (!strchr("fgG", sp.spec)) {
      // if (sp.flag.spase) {
      //   *(strchr(str, '0')) = ' ';
      // } else {
        *(strchr(str, '0')) = '\0';
      // }      
    }    
  }
  if (sp.flag.grid && 'o' == sp.spec) {
    if (strcmp(str, " 0") && strcmp(str, "0")) {
      insertMy(str, '0', 1);
    }
  }
  if ('+' == *str || '-' == *str || ' ' == *str) {
    //  i = 1 && size - 1
    if ((int)(strlen(str) - 1) < sp.precision) {
      if(!strchr("gG", sp.spec)) {
        insertMy(str + 1, '0', sp.precision - (strlen(str) - 1));
      }
    }
    if (sp.flag.grid && ('x' == sp.spec || 'X' == sp.spec || 'p' == sp.spec)) {
      if ((strcmp(str, " 0") && strcmp(str, "0")) || 'p' == sp.spec) {
        insertMy(str, 'x', 1);
        insertMy(str, '0', 1);
      }
    }
  } else {
    // i = 0
    #if defined (__linux__)
    if ((int)strlen(str) < sp.precision && (strcmp(str, "0") || strchr("ouxXid", sp.spec))) {// зануление перед нулём
      insertMy(str, '0', sp.precision - strlen(str));
    }
    #endif
    #if defined (__APPLE__)
    if ((int)strlen(str) < sp.precision && (strcmp(str, "0") || strchr("ouxXidp", sp.spec))) {// зануление перед нулём
      insertMy(str, '0', sp.precision - strlen(str));
    }
    #endif
    if (sp.flag.grid && ('x' == sp.spec || 'X' == sp.spec || 'p' == sp.spec)) {
      if ((strcmp(str, " 0") && strcmp(str, "0")) || 'p' == sp.spec) {
        insertMy(str, 'x', 1);
        insertMy(str, '0', 1);
      }
    }
  }
  if ((int)strlen(str) < sp.width) {
    if (sp.flag.min) {
      //  |<-      
      // fillingInWidthBuffer(sp, str + strlen(str), sp.width - strlen(str)); 
      memset(str + strlen(str), ' ', sp.width - strlen(str));     
    } else {
      //  ->|
      if (strchr("eEfdgG", sp.spec)){
        int n = sp.width - strlen(str);
        if (('+' == *str || '-' == *str || ' ' == *str) && sp.flag.zero) {
          memmove(str + n + 1, str + 1, strlen(str));
          fillingInWidthBuffer(sp, str + 1, n); 
        } else {
          memmove(str + n, str, strlen(str));
          fillingInWidthBuffer(sp, str, n); 
        }
      } else {
        int n = sp.width - strlen(str);
        memmove(str + n, str, strlen(str));
        fillingInWidthBuffer(sp, str, n);
      }
    }
  }
  return 0;
}

int insertMy(char * str, char c, int n) {
  memmove(str + n, str, strlen(str));
  memset(str, c, n);
  // for (int i = 0; i < n; i++) {
  //   str[i] = c;
  // }
  return 0;
}

int fillingInWidthBuffer(Specif sp, char * buf, int n) {
  if (sp.flag.zero) {
    memset(buf, '0', n);
  } else {
    memset(buf, ' ', n);
  }
  return 0;
}

//////////////////////////////////////////

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