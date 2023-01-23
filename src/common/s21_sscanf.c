#include "../s21_string.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
/*
 * Необходимо реализовать функцию sscanf из библиотеки stdio.h:
 *
 * Функция должна быть размещена в библиотеке s21_string.h.
 * На реализацию функции накладываются все требования, изложенные в первой части.
 * Должно поддерживаться частичное форматирование:
 *
 * Спецификаторы: c, d, i, f, s, u, %
 * Флаги: -, +, (пробел)
 * Ширина: (число)
 * Точность: .(число)
 * Длина: h, l
 *
 * s21_scanf(строка_из_которой_происходит_ввод, "строка_формат(спецификаторы)", &переременные, ...)
 * */
/*============================= Считыва ==========================================*/
/*============================= Прототипы функций ==========================================*/
/*++++++ Запись в %c +++++++*/
void save_c(char* spec_c, const char* src, int* index);
/*++++++ Запись в %d +++++++*/
void save_d(int* spec_d, const char* src, int* index);
/*++++++ Запись в %i +++++++*/
void save_i(int* spec_i, const char* src, int* index);
/*++++++ Запись в %f +++++++*/
void save_f(double* spec_f, const char* src, int* index);
/*++++++ Запись в %s +++++++*/
void save_c(char* spec_s, const char* src, int* index);
/*++++++ Запись в %u +++++++*/
void save_u(char* spec_u, const char* src, int* index);
/*++++++ Common +++++++*/
/*сравнивает две строки, возвращает 0 если равны и 1 если нет*/
int equal(const char* s1, const char* s2);
/*переводит строку в целое число*/
void to_int(char* str,int* res);

char* my_strtok(char *str, const char *delim);

int contains_spec(char sp, char* str);

int iterator(char sym, int* i);
/*============================= Реализация Основной функции ================================*/
int s21_sscanf(
        const char *str,
        const char *format,...) {
    va_list args;
    va_start(args, format);
    char* temp = " ";
    char cf[1024];
    int i = 0;
    int index = 0;
    while (format[i] != '\0') {
        cf[i] = format[i];
        i++;
    }
    cf [i] = '\0';
    temp = my_strtok(cf,"%");
    while(temp != NULL) {

        // если токен не нулл, вызываю функцию обработчик указателя
        if(temp !=NULL) {
            // если спецификатор содержит %d
            if(contains_spec('d',temp) == 0) {
                save_d(va_arg(args,int*),str, &index);
            } else
            // если спецификатор содержит %c
            if(contains_spec('c',temp) == 0) {
                save_c(va_arg(args,char*),str,&index);
            } else
            // если спецификатор содержит %i
            if(contains_spec('i',temp) == 0) {
                printf("Spec action i ---> %s\n", temp);
                save_i(va_arg(args,int*),str,&index);
            } else
            // если спецификатор содержит %f
            if(contains_spec('f',temp) == 0) {
                printf("Spec action f ---> %s\n", temp);
            } else
            // если спецификатор содержит %s
            if(contains_spec('s',temp) == 0) {
                printf("Spec action s ---> %s\n", temp);
            } else
            // если спецификатор содержит %u
            if(contains_spec('u',temp) == 0) {
                printf("Spec action u ---> %s\n", temp);
            }
            //получаю при каждой итерации цикла следующий токен из форматной строки
            temp = my_strtok(NULL," %");
        }
    }

    va_end(args);

    return 0;
}
/*============================= Проверки ================================================================*/
/*++++++ Это целое десятичное число +++++++*/
/*++++++ Это целое восьмеричное число +++++*/
/*++++++ Это целое шестнадцетиричное число */
/*++++++ Это вещественное число +++++++++++*/
/*++++++ Это символ +++++++++++++++++++++++*/
/*Это символ алфавита*/
/*Это не буква и не символ*/
/* токен содержит спецификатор?*/
int contains_spec(char sp, char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == sp) {
            return (0);
        }
        i++;
    }
    return (1);
}
/*============================= Обработчик Целые числа (%d) ========================================================*/
int iterator(char sym, int* i) {
    if (sym < '0') {
        *i += 1;
        return 1;
    }
    else if (sym > '9') {
        *i += 1;
        return 1;
    }
    else {
        *i += 1;
        return 0;
    }
}

void save_d(int* spec_d, const char* src, int* index) {
    int i = *index;
    int j = 0;
    char temp[32];
        while (iterator(src[i],&i) == 1) {
            if (src[i] == '\0') break;
        }
        i--;
        char t;
    while(iterator(src[i],&i) != 1) {
        if(src[i - 1] =='\0') {
            break;
        }
        t = src[i - 1];
        temp[j] = t;
        j++;
    }
    temp[j] = '\0';
    int l;
    to_int(temp,&l);
    *spec_d = l;
    *index = i;
}
/*============================= Обработчик Вещественные числа (%f) =================================================*/
void save_f(double* spec_f, const char* src, int* index) {

}
/*============================= Обработчик Строка (%s) =============================================================*/
void save_s(char* spec_s, const char* src, int* index) {

}
/*============================= Обработчик Hex, Oct целое число (%i) ===============================================*/
void save_i(int* spec_i, const char* src, int* index) {

}
/*============================= Обработчик Символ (%с) =============================================================*/
void save_c(char* spec_c, const char* src, int* index) {
    int i = *index;
    char temp = src[i];
    *spec_c = temp;
    i++;
    *index = i;
}
/*============================= Обработчик Беззнаковое десятичное целое число (%u) =================================*/
void save_u(char* spec_u, const char* src, int* index) {

}
/*============================= Вспомогательные функции =================================================*/
/*++++++ Одна строка содержит вторую +++++*/

/*++++++ сравнение двух строк Ok +++++++++*/
int equal(const char* s1, const char* s2) {
    int i = 0;
    while(s1[i] != '\0') {
        if(s1[i] != s2[i]) {
            return (1);
        }
        i++;
    }
    return (0);
}

/*++++++++ строка в число OK +++++++++++*/
void to_int(char* str, int* res) {
    int temp ;
    temp = str[0] - '0';
    int i = 0;
    while (iterator(str[i],&i) == 0)  {
        if (str[i] == '\0') break;
        temp = temp * 10 + (str[i] -'0');
    }

    *res = temp;

}

/*my_strtok*/
static char* zero_p = NULL;
static char* buf = NULL;
static size_t length = 0;
static size_t current = 0;

char* my_strtok(char *str, const char *delim) {
    /*разбиваем исходную строку на токены и кэшируем ее*/
    if (str != NULL) {
        size_t len = s21_strlen(str);
        buf = (char*)(malloc(sizeof (char) * (len + 1)));
        size_t i = 0;
        while (str[i] != '\0') {
            buf[i] = str[i];
            i++;
        }
        buf[i] = '\0';
        length = i;
        length++;
        i = 0;
        size_t j = 0;
        while (buf[i] != '\0') {
            while (delim[j] != '\0') {
                if(buf[i] == delim[j]) {

                    buf[i] = '\0';
                    break;
                }
                j++;
            }
            j = 0;
            i++;
        }
    } else {
        /*Получаем очередной токен*/
        if (current == length) {
            if(zero_p != NULL)
                free(zero_p);
            buf = NULL;
            return NULL;
        }
        size_t i = 0;
        if(current == 0) {
            while (buf[current] != '\0') {
                current++;
            }
        }
        while (buf[i] != '\0') {
            i++;
            current++;
        }
        i++;
        if(current != length)
            current++;
        buf += i;
    }
    if(buf != NULL && current != length) {
        while (s21_strlen(buf) == 0 ) {
            buf++;
            current++;
        }
    }
    if(buf == NULL && zero_p != NULL) {
        free(zero_p);
        zero_p = NULL;
    }
    return buf;
}

