#include "test_me.h"

START_TEST(s21_strcmp_1) {
  char s1[] = "String";
  char s2[] = "String";
  int n1 = strcmp(s1, s2);
  int n2 = s21_strcmp(s1, s2);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(s21_strcmp_2) {
  char s1[] = "String";
  char s2[] = "Das";
  int n1 = strcmp(s1, s2);
  int n2 = s21_strcmp(s1, s2);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(s21_strcmp_3) {
  char s1[] = "String";
  char s2[] = "Strinf";
  int n1 = strcmp(s1, s2);
  int n2 = s21_strcmp(s1, s2);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(s21_strcmp_4) {
  char s1[] = "S";
  char s2[] = "";
  int n1 = strcmp(s1, s2);
  int n2 = s21_strcmp(s1, s2);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(s21_strcmp_5) {
  char s1[] = "";
  char s2[] = "S";
  int n1 = strcmp(s1, s2);
  int n2 = s21_strcmp(s1, s2);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(s21_strcmp_6) {
  char s1[] = "";
  char s2[] = "";
  int n1 = strcmp(s1, s2);
  int n2 = s21_strcmp(s1, s2);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST



Suite *test_strcmp(void) {
  Suite *s = suite_create("\033[45m-=S21_STRCMP=-\033[0m");
  TCase *tc = tcase_create("s21_strcmp_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_strcmp_1);
  tcase_add_test(tc, s21_strcmp_2);
  tcase_add_test(tc, s21_strcmp_3);
  tcase_add_test(tc, s21_strcmp_4);
  tcase_add_test(tc, s21_strcmp_5);
  tcase_add_test(tc, s21_strcmp_6);

  suite_add_tcase(s, tc);
  return s;
}
