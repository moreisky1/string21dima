#include "test_me.h"

START_TEST(s21_strcpy_1) {
  char str1[100] = "String project";
  char str2[100] = "String project";
  char str3[] = "String project";
  ck_assert_pstr_eq(strcpy(str1, str3), s21_strcpy(str2, str3));
}
END_TEST

START_TEST(s21_strcpy_2) {
  char str1[100] = "Das\0Fas";
  char str2[100] = "Das\0Fas";
  char str3[] = "String project";
  ck_assert_pstr_eq(strcpy(str1, str3), s21_strcpy(str2, str3));
}
END_TEST

START_TEST(s21_strcpy_3) {
  char str1[100] = "Das\0Fas";
  char str2[100] = "Das\0Fas";
  char str3[] = "Stri";
  ck_assert_pstr_eq(strcpy(str1, str3), s21_strcpy(str2, str3));
}
END_TEST

START_TEST(s21_strcpy_4) {
  char str1[100] = "String project";
  char str2[100] = "String project";
  char str3[] = "Das\0Fas";
  ck_assert_pstr_eq(strcpy(str1, str3), s21_strcpy(str2, str3));
}
END_TEST

START_TEST(s21_strcpy_5) {
  char str1[100] = "\0";
  char str2[100] = "\0";
  char str3[] = "String project";
  ck_assert_pstr_eq(strcpy(str1, str3), s21_strcpy(str2, str3));
}
END_TEST

START_TEST(s21_strcpy_6) {
  char str1[100] = "String project";
  char str2[100] = "String project";
  char str3[] = "\0";
  ck_assert_pstr_eq(strcpy(str1, str3), s21_strcpy(str2, str3));
}
END_TEST

START_TEST(s21_strcpy_7) {
  char str1[100] = " ";
  char str2[100] = " ";
  char str3[] = "";
  ck_assert_pstr_eq(strcpy(str1, str3), s21_strcpy(str2, str3));
}
END_TEST

START_TEST(s21_strcpy_8) {
  char str1[100] = "";
  char str2[100] = "";
  char str3[] = " ";
  ck_assert_pstr_eq(strcpy(str1, str3), s21_strcpy(str2, str3));
}
END_TEST

START_TEST(s21_strcpy_9) {
  char str1[100] = "thi00s";
  char str2[100] = "thi00s";
  char str3[] = "\0String project";
  ck_assert_pstr_eq(strcpy(str1, str3), s21_strcpy(str2, str3));
}
END_TEST

Suite *test_strcpy(void) {
  Suite *s = suite_create("\033[45m-=S21_STRCPY=-\033[0m");
  TCase *tc = tcase_create("s21_strcpy_c");

  tcase_add_test(tc, s21_strcpy_1);
  tcase_add_test(tc, s21_strcpy_2);
  tcase_add_test(tc, s21_strcpy_3);
  tcase_add_test(tc, s21_strcpy_4);
  tcase_add_test(tc, s21_strcpy_5);
  tcase_add_test(tc, s21_strcpy_6);
  tcase_add_test(tc, s21_strcpy_7);
  tcase_add_test(tc, s21_strcpy_8);
  tcase_add_test(tc, s21_strcpy_9);
  tcase_add_test(tc, s21_strcpy_10);

  suite_add_tcase(s, tc);
  return s;
}
