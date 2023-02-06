#include "test_me.h"

START_TEST(s21_strchr_1) {
  char s[] = "String project";
  int ch = 'S';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(s21_strchr_2) {
  char s[] = "String project";
  int ch = '\0';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(s21_strchr_3) {
  char s[] = "String project";
  int ch = ' ';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(s21_strchr_4) {
  char s[] = "String project";
  int ch = 't';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(s21_strchr_5) {
  char s[] = "String project";
  int ch = '0';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

Suite *test_strchr(void) {
  Suite *s = suite_create("\033[45m-=S21_STRCHR=-\033[0m");
  TCase *tc = tcase_create("strchr_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strchr_1);
  tcase_add_test(tc, strchr_2);
  tcase_add_test(tc, strchr_3);
  tcase_add_test(tc, strchr_4);
  tcase_add_test(tc, strchr_5);
  tcase_add_test(tc, strchr_6);
  tcase_add_test(tc, strchr_7);
  tcase_add_test(tc, strchr_8);

  suite_add_tcase(s, tc);
  return s;
}
