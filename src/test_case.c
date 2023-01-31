#include <stdio.h>
#include "s21_string.h"
#include <string.h>

// void test1(char* a);
void test2(char* a, int b);
// void test3(char* a, char* b, size_t c);

int main () 
    {
    char* a = "";  
    int b = 0;
    // test1(a);
    // a = "123dfsgfnb";
    // test1(a);
    // a = "___________________";
    // test1(a);
    // a = NULL;
    // char b[4096] = "";    
//     // size_t c = 0;
    
    // test1(a);
    test2(a, b);
    a = "apple";  
    b = 98;
    test2(a, b);
    a = "apple";  
    b = 77;
    test2(a, b);
    a = "applep_152p";  
    b = 112;
    test2(a, b);
    // a = NULL;  
    // b = 0;
    // test2(a, b);
    a = "apple";  
    b = 129;
    test2(a, b);
//     }
//     // {
//     // char* a = NULL;  
//     // char* b = NULL;   
//     // // size_t c = 20; 
//     // // printf("куда    <%s>\n",  a);
//     // test2(a, b);
//     // }
//     {
//     char a[4096] = "126fgj";  
//     char b[4096] = "qwe6r";   
//     // size_t c = 5; 
//     // printf("куда    <%s>\n",  a);
//     test2(a, b);
//     }
//     {
//     char a[4096] = "";  // где ищем
//     char b[4096] = "JHB";  // что ищем
//     // size_t c = 20; 
//     // printf("куда    <%s>\n",  a);
//     test2(a, b);
//     }
    // {
    // char a[4096] = "weytryqtrw";  
    // char* b = NULL;   
    // // // size_t c = 20; 
    // // // printf("куда    <%s>\n",  a);
    // test2(a, b);
    // }
    // {
    // char* a = NULL;  
    // char b[4096] = "qwer";   
    // // // size_t c = 20; 
    // // // printf("куда    <%s>\n",  a);
    // test2(a, b);
    // }

//     str1 <qwertyuiop>
// c <113><q>
// <(null)>
// <qwertyuiop>

//  {
//     char a[4096] = "wertyuiopq";  
//     char b[4096] = "q";   
//     size_t c = 4; 
//     // printf("куда    <%s>\n",  a);
//     test3(a, b, c);
//     }
//      {
//     char a[4096] = "";  
//     char b[4096] = "qwerty";   
//     size_t c = 4; 
//     // printf("куда    <%s>\n",  a);
//     test3(a, b, c);
//     }
//       {
//     char a[4096] = "56546ytyhhyASCqCI";  
//     char b[4096] = "";   
//     size_t c = 0; 
//     // printf("куда    <%s>\n",  a);
//     test3(a, b, c);
    
    return 0;
}

// void test1(char* a) {
//     // char * res = s21_strlen(a);
//     printf("<%s>\ns21:<%ld>\nori:<%ld>", a, s21_strlen(a), strlen(a));
//     // printf("после <%d>\n", res);
// }

void test2(char* a, int b) {
    // char* d = strdup(a); // скопировала строку по адресу а в адрес b
    printf("до    <%s> <%c>\n",  a , b);
    // char res[1000] =
    // size_t res;
    // size_t res1;
    char* res = s21_strrchr(a, b);
    char* res1 = strrchr(a, b);
    printf("orig:\t<%s>\n", res1);
    printf(" s21:\t<%s>\n", res);
//     // printf("до    <%s> <%s>\n",  a , b);
//     printf("после <%ld>\n", res); 
//     printf("=====================\n");
//     printf("после <%ld>\n", res1);
//     printf("=====================\n\n");
//     // printf("до <%s> <%s>\n",  d, b);
//     // char res1[100] = strcat(d, b);
//     // printf("после <%s>\n", res1);
//     // printf("индекс %ld\n",  res-a);
// }

// void test3(char* a, char* b, size_t c) {
//     int res = 0;
//     printf("куда    <%s>\n",  a);
//     printf("что     <%s>\n",  b);
//     // char* d = strdup(a);
//     res = s21_memset(a, b, c);
//     printf("вывод s21  <%d>\n", res);
//     res = memcmp(a, b, c);
//     printf("вывод orig <%d>\n", res);
//     printf("размер %ld\n", c);
}