#ifndef _S21_STRING_H_
#define _S21_STRING_H_
#include <stddef.h>
#include <stdlib.h>

#define s21_size_t long unsigned int
#define S21_NULL (void *)0x0

/*#1
 * tests ---> NON
 * realise ----> NON
 *
 * Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n
 * байтах строки, на которую указывает аргумент str.
 *
 * const void* str --->
 * int c --->
 * size_t n --->
 * return --->
 * */
void* s21_memchr(const void *str, int c, size_t n);

/*#2
 * tests ---> NON
 * realise ----> NON
 *
 * Сравнивает первые n байтов str1 и str2.
 *
 * const void* str1 --->
 * const void* str2 --->
 * size_t n --->
 * return --->
 * */
int s21_memcmp(const void *str1, const void *str2, size_t n);

/*#3
 * tests ---> NON
 * realise ----> NON
 *
 * Копирует n символов из src в dest.
 *
 * void* dest --->
 * const void* src --->
 * size_t n --->
 * */
void* s21_memcpy(void *dest, const void *src, size_t n);

/*#4
 * tests ---> NON
 * realise ----> NON
 *
 * Еще одна функция для копирования n символов из src в dest.
 *
 * void* dest --->
 * const void* src --->
 * size_t n --->
 * return --->
 * */
void* s21_memmove(void *dest, const void *src, size_t n);

/*#5
 * tests ---> NON
 * realise ----> NON
 *
 * Копирует символ c (беззнаковый тип) в первые n символов строки, на которую указывает аргумент str.
 *
 * void* str --->
 * int c --->
 * size_t n --->
 * return --->
 * */
void* s21_memset(void *str, int c, size_t n);

/*#6
 * tests ---> NON
 * realise ----> NON
 *
 * Добавляет строку, на которую указывает src, в конец строки, на которую указывает dest.
 *
 * char* dest --->
 * const char* src --->
 * return --->
 * */
char* s21_strcat(char *dest, const char *src);

/*#7
 * tests ---> NON
 * realise ----> NON
 *
 * Добавляет строку, на которую указывает src, в конец строки, на которую указывает dest, длиной до n символов.
 *
 * char* dest --->
 * const char* src --->
 * size_t n --->
 * return --->
 * */
char* s21_strncat(char *dest, const char *src, size_t n);

/*#8
 * tests ---> NON
 * realise ----> NON
 *
 * Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на которую указывает аргумент str.
 *
 * const char* str --->
 * int c --->
 * return --->
 * */
char* s21_strchr(const char *str, int c);

/*#9
 * tests ---> NON
 * realise ----> NON
 *
 * Сравнивает строку, на которую указывает str1, со строкой, на которую указывает str2.
 *
 * const char* str1 --->
 * const char* str2 --->
 * return --->
 * */
int s21_strcmp(const char *str1, const char *str2);

/*#10
 * tests ---> NON
 * realise ----> NON
 *
 * Сравнивает не более первых n байтов str1 и str2.
 *
 * const char* str1 --->
 * const char* str2 --->
 * size_t n --->
 * return --->
 * */
int s21_strncmp(const char *str1, const char *str2, size_t n);

/*#11
 * tests ---> NON
 * realise ----> NON
 *
 * Копирует строку, на которую указывает src, в dest.
 *
 * char* dest --->
 * const char* src --->
 * return --->
 * */
char* s21_strcpy(char *dest, const char *src);

/*#12
 * tests ---> NON
 * realise ----> NON
 *
 * Копирует до n символов из строки, на которую указывает src, в dest.
 *
 * char* dest --->
 * const char* src --->
 * size_t n --->
 * return --->
 * */
char* s21_strncpy(char *dest, const char *src, size_t n);

/*#13
 * tests ---> NON
 * realise ----> NON
 *
 * Вычисляет длину начального сегмента str1, который полностью состоит из символов, не входящих в str2.
 *
 * const char* str1 --->
 * const char* str2 --->
 * return --->
 * */
size_t s21_strcspn(const char *str1, const char *str2);

/*#14
 * tests ---> NON
 * realise ----> NON
 *
 * Выполняет поиск во внутреннем массиве номера ошибки errnum и возвращает указатель на строку с сообщением об ошибке.
 * Нужно объявить макросы, содержащие массивы сообщений об ошибке для операционных систем mac и linux.
 * Описания ошибок есть в оригинальной библиотеке. Проверка текущей ОС осуществляется с помощью директив.
 *
 * int errnum --->
 * return --->
 * */
char* s21_strerror(int errnum);

/*#15
 * tests ---> NON
 * realise ----> OK
 *
 * Вычисляет длину строки str, не включая завершающий нулевой символ.
 *
 * const char* str ---> измеряемая строка
 * return ---> возвращает количество символов в строке (size_t)
 * */
size_t s21_strlen(const char *str);

/*#16
 * tests ---> NON
 * realise ----> NON
 *
 * Находит первый символ в строке str1, который соответствует любому символу, указанному в str2.
 *
 * const char* str1 --->
 * const char* str2 --->
 * return --->
 * */
char* s21_strpbrk(const char* str1, const char* str2);

/*#17
 * tests ---> NON
 * realise ----> NON
 *
 * Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на которую указывает аргумент str.
 *
 * const char* str --->
 * int c --->
 * return --->
 * */
char* s21_strrchr(const char *str, int c);

/*#18
 * tests ---> NON
 * realise ----> NON
 *
 * Вычисляет длину начального сегмента str1, который полностью состоит из символов str2.
 *
 * const char* str1 --->
 * const char* str2 --->
 * return --->
 * */
size_t s21_strspn(const char *str1, const char *str2);

/*#19
 * tests ---> NON
 * realise ----> NON
 *
 * Находит первое вхождение всей строки needle (не включая завершающий нулевой символ),
 * которая появляется в строке haystack.
 *
 * const char* haystack --->
 * const char* needle --->
 * return --->
 * */
char* s21_strstr(const char *haystack, const char *needle);

/*#20
 * tests ---> NON
 * realise ----> NON
 *
 * Разбивает строку str на ряд токенов, разделенных delim.
 *
 * char* str --->
 * const char* delim --->
 * return --->
 * */
char* s21_strtok(char *str, const char *delim);

/*#21
 * tests ---> NON
 * realise ----> NON
 *
 * Возвращает копию строки (str), преобразованной в верхний регистр.
 * В случае какой-либо ошибки следует вернуть значение NULL
 *
 * const char* str --->
 * return --->
 * */
void* s21_to_upper(const char *str);

/*#22
 * tests ---> NON
 * realise ----> NON
 *
 * Возвращает копию строки (str), преобразованной в нижний регистр.
 * В случае какой-либо ошибки следует вернуть значение NULL
 *
 * const char* str --->
 * return --->
 * */
void* s21_to_lower(const char *str);

/*#23
 * tests ---> NON
 * realise ----> NON
 *
 * Возвращает новую строку, в которой указанная строка (str) вставлена
 * в указанную позицию (start_index) в данной строке (src).
 * В случае какой-либо ошибки следует вернуть значение NULL
 *
 * const char* src --->
 * const char* str --->
 * size_t start_index --->
 * return --->
 * */
void* s21_insert(const char *src, const char *str, size_t start_index);

/*#24
 * tests ---> NON
 * realise ----> NON
 *
 * Возвращает новую строку, в которой удаляются все начальные и конечные
 * вхождения набора заданных символов (trim_chars) из данной строки (src).
 * В случае какой-либо ошибки следует вернуть значение NULL
 *
 * const char* src --->
 * const char* trim_chars --->
 * return --->
 * */
void* s21_trim(const char *src, const char *trim_chars);

/*#25
 * tests ---> NON
 * realise ----> NON
 *
 * считывает форматированный ввод из строки.
 *
 * const char* str --->
 * const char* format --->
 * return --->
 * */
int s21_sscanf(const char *str, const char *format);

/*#26
 * tests ---> NON
 * realise ----> NON
 *
 * отправляет форматированный вывод в строку, на которую указывает str.
 *
 * const char* str --->
 * const char* format --->
 * return --->
 * */
int s21_sprintf(char *str, const char *format);

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#endif // _S21_STRING_H_