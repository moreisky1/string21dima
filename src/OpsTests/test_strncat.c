#include "test_me.h"

START_TEST(s21_strncat_1) {
  char s1[30] = "String project";
  char s2[30] = "String project";
  char s3[] = "String project";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(s21_strncat_2) {
  char s1[30] = "String project";
  char s2[30] = "String project";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(s21_strncat_3) {
  char s1[30] = "String project";
  char s2[30] = "String project";
  char s3[] = "\n\0\\d\f\\g\7";
  s21_size_t n = 3;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(s21_strncat_4) {
  char s1[30] = "String project";
  char s2[30] = "String project";
  char s3[] = "";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(s21_strncat_5) {
  char s1[30] = "";
  char s2[30] = "";
  char s3[] = "String project";
  s21_size_t n = 13;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(s21_strncat_6) {
  char s1[30] = "";
  char s2[30] = "";
  char s3[] = "String project";
  s21_size_t n = 3;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(s21_strncat_7) {
  char s1[100] = "";
  char s2[100] = "";
  char s3[] = "";
  s21_size_t n = 10;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(s21_strncat_8) {
  char s1[100] = "String project";
  char s2[100] = "String project";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(s21_strncat_9) {
  char s1[100] = "String project";
  char s2[100] = "String project";
  char s3[] = "\0";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(s21_strncat_10) {
  char s1[100] = "String project";
  char s2[100] = "String project";
  char s3[] = "\0\0\0\0";
  s21_size_t n = 4;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(s21_strncat_11) {
  char s1[100] = "String project";
  char s2[100] = "String project";
  char s3[] = "";
  s21_size_t n = 2;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

Suite *test_strncat(void) {
  Suite *s = suite_create("\033[45m-=S21_STRNCAT=-\033[0m");
  TCase *tc = tcase_create("s21_strncat_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_strncat_1);
  tcase_add_test(tc, s21_strncat_2);
  tcase_add_test(tc, s21_strncat_3);
  tcase_add_test(tc, s21_strncat_4);
  tcase_add_test(tc, s21_strncat_5);
  tcase_add_test(tc, s21_strncat_6);
  tcase_add_test(tc, s21_strncat_7);
  tcase_add_test(tc, s21_strncat_8);
  tcase_add_test(tc, s21_strncat_9);
  tcase_add_test(tc, s21_strncat_10);
  tcase_add_test(tc, s21_strncat_11);

  suite_add_tcase(s, tc);
  return s;
}
