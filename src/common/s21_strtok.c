#include "../s21_string.h"

static char* pointer = NULL;
// указатель на элемент после делимитера найденного в прошлом цикле
static char* mem = NULL;  // указатель на возвращаемую лексему
static int flag = 0;  // флаг, поднимаемый после первого выполнения функции

char* s21_strtok(char* str, const char* delim) {
  char* res; //delete
  // if (!flag) {
    
  // }
  if (str != NULL) {  // подаётся строка - либо первое выполнение, либо
    mem = NULL;       // выполнение для новой строки(опять же, первое)
    flag = 0;         // начало работы
    if (delim != NULL) {
      int flag_break = 0;
      s21_size_t step = s21_strspn(str, delim);
      str += step;
      s21_size_t n = s21_strlen(str);
      for (int i = 0; i < n; i++) {
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
          if (!s21_strlen(mem)) {
            mem = NULL;
          }
          break;
        }
      }
    } else if (delim == NULL) {
      mem = NULL;
    }

  } else if (str == NULL) {  // либо вывод новых лексем, либо выход
    if (flag != 0) {  // новые лексемы
      if (delim != NULL && *pointer != '\0') {
        s21_size_t step = s21_strspn(pointer, delim);
        if (step == 0) {
          mem = pointer;
        } else {
          pointer += step;
          mem = pointer;
        }
        int n_poin = (int)s21_strlen(pointer);
        char * p = NULL;
        p = s21_strpbrk(pointer, delim);
        if (p != S21_NULL){
          *p = '\0';
          pointer = pointer + (p - pointer) + 1;
        } else {
          // if (pointer[i + 1] == '\0') {
            // mem = pointer;
            pointer = pointer + n_poin;
          // } 
        }
        if (!s21_strlen(mem)) {
          mem = NULL;
        }

        // 
        // if (n_poin == 0) {
        //   mem = NULL;
        // } else {
          
        //   int flag_break = 0;
        //   for (int i = 0; i < n_poin; i++) {
        //     int j = 0;
        //     int flag_start = 0;
        //     int n_delim = (int)s21_strlen(delim);
        //     int glag = 0;
        //     for (j = 0; j < n_delim; j++) {              
        //       if (pointer[i] != delim[j]) {
        //         flag_start = 1;
        //         glag += 1;
        //       }
        //       if ((pointer[i] == delim[j]) && flag_start == 0) {
        //         pointer++;
        //         // flag_start = 0;
        //         break;
        //         // continue;
        //       } else if ((pointer[i] == delim[j]) && flag_start != 0 && glag == n_delim) {
        //         pointer[i] = '\0';
        //         mem = pointer;
        //         pointer = pointer + i + 1;
        //         flag_break = 1;
        //         break;
        //       }

        //                 
            
        //     }

        //     if (flag_break == 1) {
        //       if (!s21_strlen(mem)) {
        //         mem = NULL;
        //       }
        //       break;
        //     }
        //   }
        // }
      } else /*if (delim == NULL)*/ {
        mem = NULL;
      }
    } else {  // выход
      ;
    }
  }
  
  return mem;
}