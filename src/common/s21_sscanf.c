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
/*============================= Структра списка  ==========================================*/
typedef struct Node {
    void* info;
    struct Node *next;
    struct Node *last;
} Node;
/*============================= Прототипы функций ==========================================*/
/*+++++ LinkedList ++++*/
/*add*/
void add_list(Node* node, void* val);
/*get*/
void* get_list(Node* node, int index);
/*size*/
int size_list(Node* node);

/*++++++ Common +++++++*/
/*сравнивает две строки, возвращает 0 если равны и 1 если нет*/
int equal(const char* s1, const char* s2);
/*переводит строку в целое число*/
int to_int(const char* str);

char* my_strtok(char *str, const char *delim);
/*============================= Реализация Основной функции ================================*/
int s21_sscanf(
        const char *str,
        const char *format,...) {
    //Node head;
    va_list args;
    va_start(args, format);
    char f[1024];
    strcpy(f,format);
    char* temp = my_strtok(f," %");
    while(temp != NULL) {

            printf("---> %s\n",temp);

        temp = my_strtok(NULL," %");
    }

    va_end(args);

    //printf("---> %d\n", size_list(&head));
//    add_list(&head,"Hello ");
//    add_list(&head,"World");
//    printf("%s %s --> %d", get_list(&head,0), get_list(&head,1), size_list(&head));


//    s_f head;
//    head.index = 0;
//    head.last = NULL;
//    va_list ap;
//    va_start(ap, format);
//    head.info = va_arg(ap,void*);
//    head.next = NULL;
//
//
//
//    printf("--index->%d\n",head.index);
//    add(&head,va_arg(ap,void*));
//    printf("--index->%d\n",head.index);
//    add(&head,va_arg(ap,void*));
//    printf("--index->%d\n",head.index);

//        /*считывание целого числа*/
//        if (!equal(format, "%d")) {
//            int *z = va_arg(ap, int*);
//            int x = to_int(str);
//            *z = x;
//            counter++;
//        }
        /*считывание вещественного числа*/
//
//    va_end(ap);

    return 0;
}
/*============================= методы списка ===========================================================*/
/*добавить*/
void add_list(Node* node, void* val) {
    if (node->info == NULL) {

        node->info = val;

//        printf("----> %p\n",node->info);
//        printf("----> %p\n",val);
    } else if(node->info != NULL && node->next == NULL) {
        Node* elem = (Node*) malloc(sizeof (Node));
        elem->info = val;
        elem->last = node;
        node->next = elem;

//        printf("----> %p\n",node->info);
//        printf("----> %p\n",val);
    } else if(node->info != NULL && node->next != NULL) {
        Node* temp = node;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        Node* elem = (Node* )malloc(sizeof (Node));
        elem->info = val;
        elem->last = temp;
        temp->next = elem;

//        printf("----> %p\n",node->info);
//        printf("----> %p\n",val);
    }

}

/*вернуть элемент по индексу*/
void* get_list(Node* node, int index) {
    Node* temp = node;
    for(int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->info;
}

/*длинна списка*/
int size_list(Node* node) {
    if(node->info == NULL) return 0;
    Node* temp = node;
    int len = 1;
    while(temp->next != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

/*============================= Проверки ================================================================*/
/*++++++ Это целое десятичное число +++++++*/
/*++++++ Это целое восьмеричное число +++++*/
/*++++++ Это целое шестнадцетиричное число */
/*++++++ Это вещественное число +++++++++++*/
/*++++++ Это символ +++++++++++++++++++++++*/
/*Это символ алфавита*/
/*Это не буква и не символ*/
/*============================= Целые числа (%d) ========================================================*/

/*============================= Вещественные числа (%f) =================================================*/

/*============================= Строка (%s) =============================================================*/

/*============================= Hex, Oct целое число (%i) ===============================================*/

/*============================= Символ (%с) =============================================================*/

/*============================= Беззнаковое десятичное целое число (%u) =================================*/

/*============================= Вспомогательные функции =================================================*/
/*++++++ сравнение двух строк Ok+++++++++*/
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
char* my_strtok(char *str, const char *delim) {

    static char* buf_str = NULL;
    static int token_counter = 0;
    /*Cash*/
    if(str) {
        int i = 0;
        int j = 0;
        /*Разбиение на токены */
        while(str[i] != '\0') {
            while(delim[j] != '\0') {
                if(str[i] == delim[j]) break;
                j++;
            }
            if(str[i] == delim[j]) {buf_str = '\0'; token_counter++;}
            i++;
            j = 0;
        }
        buf_str = str;
    }
    /*Следующий токен*/
    if(!str) {
        int g = 0;
        while (buf_str[g] != '\0')
            g++;
        g++;

        str = buf_str + g;
        buf_str = str;
    }
    if(!str) str = NULL;


    if(token_counter >= 0) token_counter--; else str =NULL;

    return str;
}
