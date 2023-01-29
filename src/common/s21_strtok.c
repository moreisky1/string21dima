#include "../s21_string.h"

static char* pointer = NULL;
// указатель на элемент после делимитера найденного в прошлом цикле
static char* mem = NULL;  // указатель на возвращаемую лексему
static int flag = 0;  // флаг, поднимаемый после первого выполнения функции

char* s21_strtok(char* str, const char* delim) {
  char* res;
  if (str != NULL) {  // подаётся строка - либо первое выполнение, либо
                      // выполнение для новой строки(опять же, первое)
    flag = 0;         // начало работы
    if (delim != NULL) {
      int flag_break = 0;
      for (int i = 0; i < s21_strlen(str); i++) {
        // int flag_break = 0;
        for (int j = 0; j < s21_strlen(delim); j++) {
          if (str[i] == delim[j]) {
            str[i] = '\0';
            mem = str;
            pointer = str + i + 1;
            flag = 1;
            flag_break = 1;
            break;
          }
        }
        if (s21_strlen(delim) == 0) {
          mem = str;
          pointer = str + s21_strlen(str);
          flag = 1;
          break;
        }
        if (flag_break == 1) {
          break;
        }
      }
    } else if (delim == NULL) {
      mem = NULL;
    }

  } else if (str == NULL) {  // либо вывод новых лексем, либо выход
    if (flag != 0) {  // новые лексемы
      if (delim != NULL) {
        if (s21_strlen(pointer) == 0) {
          mem = NULL;
        } else {
          int flag_start = 0;
          int flag_break = 0;
          for (int i = 0; i < s21_strlen(pointer); i++) {
            for (int j = 0; j < s21_strlen(delim); j++) {
              if (pointer[i] != delim[j]) {
                flag_start = 1;
              }
              if ((pointer[i] == delim[j]) && flag_start == 0) {
                pointer++;
                continue;
              } else if ((pointer[i] == delim[j]) && flag_start != 0) {
                pointer[i] = '\0';
                mem = pointer;
                pointer = pointer + i + 1;
                flag_break = 1;
                break;
              }
              if (pointer[i + 1] == '\0') {
                mem = pointer;
                pointer = pointer + i + 1;
              }
            }
            if (flag_break == 1) {
              break;
            }
          }
        }
      } else if (delim == NULL) {
        mem = NULL;
      }
    } else {  // выход
      ;
    }
  }
  return mem;
}
