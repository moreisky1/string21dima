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

/*++++++ Common +++++++*/
/*сравнивает две строки, возвращает 0 если равны и 1 если нет*/
int equal(const char* s1, const char* s2);
/*переводит строку в целое число*/
int to_int(const char* str);

char* my_strtok(char *str, const char *delim);

int contains_spec(char sp, char* str);
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
    printf("---> %s\n", cf);
    temp = my_strtok(cf," %");
    while(temp != NULL) {


        // если токен не нулл, вызываю функцию обработчик указателя
        if(temp !=NULL) {
            // если спецификатор содержит %d
            if(contains_spec('d',temp) == 0) {
                printf("Spec action d ---> %s\n", temp);
            } else
            // если спецификатор содержит %c
            if(contains_spec('c',temp) == 0) {
                printf("Spec action c ---> %s\n", temp);
                save_c(va_arg(args,char*),str,&index);
            } else
            // если спецификатор содержит %i
            if(contains_spec('i',temp) == 0) {
                printf("Spec action i ---> %s\n", temp);
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
    printf("---> %s\n", str);
    return 0;
}
/*============================= Saver  ================================================================*/
void save_c(char* spec_c, const char* src, int* index) {
    int i = *index;
    char temp = src[i];
    *spec_c = temp;
    i++;
    *index = i;
}

/*============================= Проверки ================================================================*/
/*++++++ Это целое десятичное число +++++++*/
/*++++++ Это целое восьмеричное число +++++*/
/*++++++ Это целое шестнадцетиричное число */
/*++++++ Это вещественное число +++++++++++*/
/*++++++ Это символ +++++++++++++++++++++++*/
/*Это символ алфавита*/
/*Это не буква и не символ*/
/*содержит спецификатор*/
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

/*============================= Обработчик Вещественные числа (%f) =================================================*/

/*============================= Обработчик Строка (%s) =============================================================*/

/*============================= Обработчик Hex, Oct целое число (%i) ===============================================*/

/*============================= Обработчик Символ (%с) =============================================================*/

/*============================= Обработчик Беззнаковое десятичное целое число (%u) =================================*/

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
int to_int(const char* str) {
    int temp = str[0] - '0';
    int i = 1;

    while (str[i] != '\0') {
        temp = temp * 10 + str[i] -'0';
    }
    return temp;
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
            // printf("--- BUF ---->%c\n",buf[i]);
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

