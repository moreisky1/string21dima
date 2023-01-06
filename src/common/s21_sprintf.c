#include "../s21_string.h"
#include <stdarg.h>


int s21_sprintf(char *str, const char *format, ...) {
  va_list ptr;
  va_start(ptr, format);
  int j = 0;
  for (int i = 0; format[i] != '\0'; i++) {
    if (format[i] == '%') {
      i++;
      if (format[i] == 'c') {
        str[j] = va_arg(ptr, int);
        j++;
      }
      if (format[i] == 's') {
        char * str = va_arg(ptr, char *);
        for (int q = 0; q < s21_strlen(str); q++){
          str[j] = str[q];
          j++;
        }      
      }
    } else {    
      str[j] = format[i];
      j++;
    }
  }
  va_end(ptr);
  return 0;
}