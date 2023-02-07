#include "test_me.h"

Suite *test_sprint(void) {
  Suite *s = suite_create("\033[45m-=S21_SPRINT1=-\033[0m");
  TCase *tc = tcase_create("s21_sprintf_tc");

  tcase_add_test(tc, s21_sprintf_);
  tcase_add_test(tc, s21_sprintf_);
  tcase_add_test(tc, s21_sprintf_);
  tcase_add_test(tc, s21_sprintf_);
  tcase_add_test(tc, s21_sprintf_);

  suite_add_tcase(s, tc);
  return s;
}
