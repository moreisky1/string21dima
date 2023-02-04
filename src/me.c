#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

// static int con = 0;
void workSprintf();
void test_memchr(const void *str, int c, size_t n);
void test_memcmp(const void *str1, const void *str2, size_t n);
void test_memcpy(void *dest, const void *src, size_t n);
void test_memmove(void *dest, const void *src, size_t n);
void test_memset(void *dest, int src, size_t n);
void test_strchr(const char *str, int c);
void test_strcmp(const char *str1, const char *str2);
void test_strncmp(const char *str1, const char *str2, size_t n);
void test_strspn(const char *str1, const char *str2);
void test_strcspn(const char *str1, const char *str2);
void test_strerror(int errnum);
void test_strlen(const char *str);
void test_strpbrk(const char *str1, const char *str2);
void test_strrchr(const char *str, int c);
void test_insert(const char *src, const char *str, size_t start_index);

int printNumber(char *str, int a, int s);
int getCifra(char *str, long long unsigned a, int b);
int getCifra1(char *str, long long int a, int b);
int bitInCifra(long long unsigned a, int b);
int getCifra2(char *str, unsigned a);

int main() {
  printf("TEST\n\n");
  // for (int i = -2; i < 50; i++)
  // {
  //   test_strerror(i);
  // }

  // str1 = strdup("");
  // str2 = strdup("");  // str3 = strdup("");  // printf("str1 <%s>\ntr2
  // <%s>\nstr3 <%s>\nstr4 <%s>\n", str1, str2, str3, str4); printf("<%s>\n
  // <%s>n%d\n\n", (char *)s21_strncpy(str1, str3, 4), strncpy(str2, str3, 4),
  // strcmp(str1,str2));

  // int *str = NULL;
  // int a = 134;
  // str = &a;
  // long long int b = (long long int)&a;
  // printf("%lld\n", b);
  // printf("%p\n", str);
  // char str1[1024] = "";
  // char str[1024] = "";
  // unsigned int a = 0b11111111111111111111111111111111;

  // unsigned int a1 = 0b1111;
  // unsigned int *p = &a;
  // sprintf(str1, "int = %p", str);
  // getCifra(str1, a, 16);
  // printf("%s\n", str1);
  // getCifra1(str, a, 16);
  // printf("%s\n", str);
  // printf("%x\n", a);

  // double b = 5;
  // char str[1024] = "";
  // char *s = str;
  // double * a = &b;
  // int * p = (int *)a;
  // int * p1 = p+1;
  // s += getCifra2(s, (unsigned)*p1);
  // s += getCifra2(s, (unsigned)*p);
  // printf("%s\n", str);
  /*
    char str[1024] = "";
    char str1[1024] = "";
    long long int b = 8964489;
    char * p = NULL;
    char * s = "Hekow sdf lklsf' ";
    // p = &b;
    long long int b = (long long int)&s;

       sprintf(str1, "int = %llu int = %llo int = %llx int = %llX |%%| pointer =
    %p | %lld|", b, b, b, b, p, (long long int)p);
      // sprintf(str1, "!d = %s ", s);
      // sprintf(str1, "d = %f | d = %e | d = %E | d = %g | d = %G |", b, b, b,
    b, b); printf("%s\n", str1);


    s21_sprintf(str, "int = %llu int = %llo int = %llx int = %llX |%%| pointer =
    %p | %lld|", b, b, b, b, p, (long long int)p);
    // s21_sprintf(str, "|d = %s ", s);
    // s21_sprintf(str, "d = %f | d = %e | d = %E | d = %g | d = %G |", b, b, b,
    b, b); printf("%s\n", str);
    */
  //     b = 0.9876751;
  //     sprintf(str1, "d = %f | d = %e | d = %E | d = %g | d = %G |", b, b, b,
  //     b, b); printf("%s\n", str1);
  // s21_sprintf(str, "d = %f | d = %e | d = %E | d = %g | d = %G |", b, b, b,
  // b, b);
  //   printf("%s\n", str);

  //   b = 8964489.9876751;
  //     sprintf(str1, "d = %#f | d = %e | d = %E | d = %g | d = %G |", b, b, b,
  //     b, b); printf("%s\n", str1);
  // s21_sprintf(str, "d = %#f | d = %e | d = %E | d = %g | d = %G |", b, b, b,
  // b, b);
  //   printf("%s\n", str);

  // f e E g G n
  // u o x X % p d i c s

  // char e = 'Q';
  // char * st = " DAS ";
  // char str2[2024] = "";
  // int q = 456;
  // double w = 0.9876751;
  // char * s = str2;
  // int f = 0;
  // s += sprintf(s, "d = %5d | u = %u | o = %o | x = %x \n", q, q, q, q);
  // s += sprintf(s, "d = %-+ #0f | d = %-+ #0e | d = %-+ #0E | d = %-+ #0X \n",
  // w, w, w, q); s += sprintf(s, "d = %i | d = %s | d = %c | d = %% \n", q, st,
  // e); s += sprintf(s, "d = %-+ #0n | d = %-+ #0p | d = %-+ #0G | d = %-+ #0g
  // \n", &f, st, w, w); printf("%s\n", str2);
  // test_insert("\0", "\0", 0);
  // char m[300] = "It is test string for memcpy";
  // test_memset(m, 67, 10);
  // test_memset(m - 1, 67, 10);
  // test_memset(m + 3, 67, 4);
  workSprintf();  // gcc -Wall -Werror -Wextra -o me %.c

  return 0;
}

// int printNumber(char * str, int a, int s) {
//   int count = 0;
//   // int notation = s;
//   // int step = 87;
//   // while (1) {

//   //   int b = (int)getCifra1(str, a, notation);
//   //   printf("\n");
//   //   if (b > 9 && notation == 16) {
//   //     *str = b + step;
//   //   } else {
//   //     *str = b + '0';
//   //   }
//   //   str++;
//   //   count++;
//   //   if (a > notation - 1) {
//   //     a = a / notation;
//   //   } else {
//   //     break;
//   //   }
//   // }
//   // getCifra1(str, a, s);
//   return count;
// }

// int getCifra(char * str, long long unsigned a, int b) {
//   int count = 0;
//   if (a != 0) {
//     count += getCifra(str, a / b, b);
//     str += count;
//     if (a % b > 9 && b == 16) {
//       *str = a % b + 87;
//     } else {
//       *str = a % b + '0';
//     }
//     count++;
//   }
//   return count;
// }

// int getCifra1(char * str, long long int a, int b) {
//   int count = 0;
//   int buf = 0;
//   int cel = 0;
//   if (b == 16) {cel = 4;}
//   if (b == 8) {cel = 3;}
//   if (b == 4) {cel = 2;}
//   if (b == 2) {cel = 1;}
//   while (a != 0) {
//     buf = bitInCifra(a, cel);
//     printf("%d|", buf);
//     a >>= cel;
//     if (buf > 9 && b == 16) {
//       *str = buf + 87;
//     } else {
//       *str = buf + '0';
//     }
//     str++;
//     count++;
//   }
//   return count;
// }

void workSprintf() {
  {
    char str[2024] = "";
    int a = 123456;
    sprintf(str, "<%%i> -              |%i|", a);
    printf("%s\n", str);
  }
  {
    char str[2024] = "";
    int a = 123456;
    sprintf(str, "<%%li> -             |%li|", (long)a);
    printf("%s\n", str);
  }
  {
    char str[2024] = "";
    int a = 123456;
    sprintf(str, "<%%lli> -            |%lli|", (long long)a);
    printf("%s\n", str);
  }
  {
    char str[2024] = "";
    int a = 123456;
    sprintf(str, "<%%Li> -             |%Li|", (long long)a);
    printf("%s\n", str);
  }
  {
    char str[2024] = "";
    int a = 32767;
    sprintf(str, "<%%hi> -             |%hi|", a);
    printf("%s\n", str);
  }
  {
    char str[2024] = "";
    int a = 123456;
    sprintf(str, "<%%4i> -             |%4i|", a);
    printf("%s\n", str);
  }
  {
    char str[2024] = "";
    int a = 123456;
    sprintf(str, "<%%.4i> -            |%.4i|", a);
    printf("%s\n", str);
  }
  {
    char str[2024] = "";
    int a = 123456;
    sprintf(str, "<%%11i> -            |%11i|", a);
    printf("%s\n", str);
  }
  {
    char str[2024] = "";
    int a = 123456;
    sprintf(str, "<%%.11i> -           |%.11i|", a);
    printf("%s\n", str);
  }
  {
    char str[2024] = "";
    int a = 123456;
    sprintf(str, "<%%0i> -             |%0i|", a);
    printf("%s\n", str);
  }
  {
    char str[2024] = "";
    int a = 123456;
    sprintf(str, "<%%011i> -           |%011i|", a);
    printf("%s\n", str);
  }
  {
    char str[2024] = "";
    int a = 123456;
    sprintf(str, "<%%04i> -            |%04i|", a);
    printf("%s\n", str);
  }
  {
    char str[2024] = "";
    int a = 123456;
    sprintf(str, "<%% .11i> -           |% .11i|", a);
    printf("%s\n", str);
  }
  {
    char str[2024] = "";
    // int a = 123456;
    sprintf(str,
            "<%%0.4i> - error: '0' flag ignored with precision and '%%i' "
            "gnu_printf format ");
    printf("%s\n", str);
  }
  {
    char str[2024] = "";
    int a = 123456;
    sprintf(str, "<%%-i> -             |%-i|", a);
    printf("%s\n%d", str);
  }
  {
    char str[2024] = "";
    int a = 123456;
    sprintf(str, "<%%-4i> -            |%-4i|", a);
    printf("%s\n", str);
  }
  {
    char str[2024] = "";
    int a = 123456;
    sprintf(str, "<%%-11i> -           |%-11i|", a);
    printf("%s\n", str);
  }
  {
    char str[2024] = "";
    // int a = 123456;
    sprintf(str,
            "<%%-011i> - error: '0' flag ignored with '-' flag in "
            "gnu_printf format");
    printf("%s\n", str);
  }
  {
    char str[2024] = "";
    int a = 123456;
    sprintf(str, "<%%-.4i> -           |%-.4i|", a);
    printf("%s\n", str);
  }
  {
    char str[2024] = "";
    int a = 123456;
    sprintf(str, "<%%-.11i> -          |%-.11i|", a);
    printf("%s\n", str);
  }
  {
    char str[2024] = "";
    int a = 123456;
    sprintf(str, "<%%+4i> -            |%+4i|", a);
    printf("%s\n", str);
  }
  {
    char str[2024] = "";
    int a = 123456;
    sprintf(str, "<%%+11i> -           |%+11i|", a);
    printf("%s\n", str);
  }
  {
    char str[2024] = "";
    int a = 123456;
    sprintf(str, "<%%+011i> -          |%+011i|", a);
    printf("%s\n", str);
  }
  {
    char str[2024] = "";
    int a = 123456;
    sprintf(str, "<%%+.11i> -          |%+.11i|", a);
    printf("%s\n", str);
  }
  {
    char str[2024] = "";
    int a = 123456;
    sprintf(str, "<%%+11.11i> -        |%+11.11i|", a);
    printf("%s\n", str);
  }
  {
    char str[2024] = "";
    int a = 123456;
    sprintf(str, "<%%+-11i> -          |%+-11i|", a);
    printf("%s\n", str);
  }
  {
    char str[2024] = "";
    int a = -123456;
    sprintf(str, "<%%+-11i> -          |%+-11i|", a);
    printf("%s\n", str);
  }
  {
    char str[2024] = "";
    int a = -123456;
    sprintf(str, "<%%+*.11i> -         |%+*.11i|", 12, a);
    printf("%s\n", str);
  }
  {
    char str[2024] = "";
    int a = -123456;
    sprintf(str, "<%%+-*i> -           |%+-*i|", 12, a);
    printf("%s\n", str);
  }

  {
    char str[2024] = "";
    int a = 1234567;
    sprintf(str, "<%%+11i> -           |%-+11i|", a);
    printf("%s\n", str);
    sprintf(str, "<%%+11d> -           |%+11d|", a);
    printf("%s\n", str);
    sprintf(str, "<%%11o> -            |%11o|", a);
    printf("%s\n", str);
    sprintf(str, "<%%11x> -            |%11x|", a);
    printf("%s\n", str);
    sprintf(str, "<%%11u> -            |%11u|", a);
    printf("%s\n", str);
    sprintf(str, "<%%+11f> -           |%+11f|", (double)a);
    printf("%s\n", str);
    sprintf(str, "<%%+11e> -           |%+11e|", (double)a);
    printf("%s\n", str);
    sprintf(str, "<%%+11g> -           |%+11g|", (double)a);
    printf("%s\n", str);
  }
}

// int bitInCifra(long long unsigned a, int b) {
//   int result = 1;
//   int count = 0;
//   int x = 2;
//   for (int i = 0; i < b; i++) {
//     if(a & 1) {
//       result += x;
//       count++;
//     }
//     a >>= 1;
//     x *= 2;
//   }
//   if (!count) {
//     result = 0;
//   }
//   return result;
// }

// int getCifra2(char * str, unsigned a) {
//   int count = 0, count1 = 0;
//   unsigned q = 0b10000000000000000000000000000000;
//   while (q != 0) {
//     if(a & q) {
//       *str = '1';
//     } else {
//       *str = '0';
//     }
//     // printf("%u | %u\n", q, a);
//     q >>= 1;
//     str++;
//     count++;
//     count1++;
//     if (count1 % 4 == 0) {
//       *str = ' ';
//       str++;
//       count++;
//     }

//   }
//   return count;
// }

// void test_insert(const char *src, const char *str, size_t start_index) {
//   printf("test%d:\n", con);
//   con++;
//   printf("stc <%s>\nstr <%s>\nn <%ld>\n", src, str, start_index);
//   printf("<%s>\n", (char *)s21_insert(src, str, start_index));
//   printf("\n");
// }

// void test_strspn(const char *str1, const char *str2) {
//   printf("test%d:\n", con);
//   con++;
//   printf("str1 <%s>\nstr2 <%s>\n", str1, str2);
//   printf("<%ld>\n", s21_strspn(str1, str2));
//   printf("<%ld>\n", strspn(str1, str2));
//   printf("\n");
// }

// void test_strrchr(const char *str, int c) {
//   printf("test%d:\n", con);
//   con++;
//   printf("str1 <%s>\nc <%d><%c>\n", str, c, c);
//   printf("<%s>\n", s21_strrchr(str, c));
//   printf("<%s>\n", strrchr(str, c));
//   printf("\n");
// }

// void test_strpbrk(const char *str1, const char *str2) {
//   printf("test%d:\n", con);
//   con++;
//   printf("str1 <%s>\nstr2 <%s>\n", str1, str2);
//   printf("<%s>\n", s21_strpbrk(str1, str2));
//   printf("<%s>\n", strpbrk(str1, str2));
//   printf("\n");
// }

// void test_strlen(const char *str) {
//   printf("test%d:\n", con);
//   con++;
//   printf("str <%s>\n", str);
//   printf("<%ld>\n", s21_strlen(str));
//   printf("<%ld>\n", strlen(str));
//   printf("\n");
// }

// void test_strerror(int errnum) {
//   printf("test%d:\n", con);
//   con++;
//   printf("errnum <%d>\n", errnum);
//   printf("<%s>\n", s21_strerror(errnum));
//   printf("<%s>\n", strerror(errnum));
//   printf("\n");
// }

// void test_strcspn(const char *str1, const char *str2) {
//   printf("test%d:\n", con);
//   con++;
//   printf("str1 <%s>\nstr2 <%s>\n", str1, str2);
//   printf("<%ld>\n", s21_strcspn(str1, str2));
//   printf("<%ld>\n", strcspn(str1, str2));
//   printf("\n");
// }

// void test_memchr(const void *str, int c, size_t n) {
//   printf("str <%s>\nc <%c>\nn <%ld>\n", (char *)str, c, n);
//   printf("<%s>\n", (char *)memchr(str, c, n));
//   printf("<%s>\n\n", (char *)s21_memchr(str, c, n));
// }

// void test_memcmp(const void *str1, const void *str2, size_t n) {
//   printf("str1 <%s>\nstr2 <%s>\nn <%ld>\n", (char *)str1, (char *)str2, n);
//   printf("<%d>\n", memcmp(str1, str2, n));
//   printf("<%d>\n\n", s21_memcmp(str1, str2, n));
// }

// void test_memcpy(void *dest, const void *src, size_t n) {
//   printf("test%d:\n", con);
//   con++;
//   void * p = strdup(dest);
//   void * d = strdup(dest);
//   printf("str1 <%s>\nstr2 <%s>\nn <%ld>\n", (char *)dest, (char *)src, n);
//   printf("<%s>\n", (char *)s21_memcpy(p, src, n));
//   printf("<%s>\n", (char *)memcpy(d, src, n));
//   printf("\n");
//   free(p);
//   free(d);
// }

// void test_memmove(void *dest, const void *src, size_t n) {
//   printf("test%d:\n", con);
//   con++;
//   void * p = strdup(dest);
//   void * d = strdup(dest);
//   printf("str1 <%s>\nstr2 <%s>\nn <%ld>\n", (char *)dest, (char *)src, n);
//   printf("<%s>\n", (char *)s21_memmove(p, src, n));
//   printf("<%s>\n", (char *)memmove(d, src, n));
//   printf("\n");
//   free(p);
//   free(d);
// }

// void test_memset(void *dest, int src, size_t n) {
//   printf("test%d:\n", con);
//   con++;
//   void * p = strdup(dest);
//   void * d = strdup(dest);
//   printf("str1 <%s>\nstr2 <%d><%c>\nn <%ld>\n", (char *)dest, src, src, n);
//   printf("<%s>\n", (char *)s21_memset(p, src, n));
//   printf("<%s>\n", (char *)memset(d, src, n));
//   printf("\n");
//   free(p);
//   free(d);
// }

// void test_strchr(const char *str, int c) {
//   printf("test%d:\n", con);
//   con++;
//   printf("str1 <%s>\nc <%d><%c>\n", str, c, c);
//   printf("<%s>\n", s21_strchr(str, c));
//   printf("<%s>\n", strchr(str, c));
//   printf("\n");
// }

// void test_strcmp(const char *str1, const char *str2) {
//   printf("test%d:\n", con);
//   con++;
//   printf("str1 <%s>\nstr2 <%s>\n", str1, str2);
//   printf("<%d>\n", s21_strcmp(str1, str2));
//   printf("<%d>\n", strcmp(str1, str2));
//   printf("\n");
// }

// void test_strncmp(const char *str1, const char *str2, size_t n) {
//   printf("test%d:\n", con);
//   con++;
//   printf("str1 <%s>\nstr2 <%s>\nn <%ld>\n", str1, str2, n);
//   printf("<%d>\n", s21_strncmp(str1, str2, n));
//   printf("<%d>\n", strncmp(str1, str2, n));
//   printf("\n");
// }