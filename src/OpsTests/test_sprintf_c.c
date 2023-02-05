#include "test_me.h"



Suite *test_sprintf_c(void) {
  Suite *s = suite_create("\033[45m-=S21_SPRINTF_C=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc>");

  tcase_add_test(tc, s21_sprintf_1);
  tcase_add_test(tc, s21_sprintf_2);
  tcase_add_test(tc, s21_sprintf_3);
  tcase_add_test(tc, s21_sprintf_4);
  tcase_add_test(tc, s21_sprintf_5);
  tcase_add_test(tc, s21_sprintf_6);
  tcase_add_test(tc, s21_sprintf_7);
  tcase_add_test(tc, s21_sprintf_8);
  tcase_add_test(tc, s21_sprintf_9);
  tcase_add_test(tc, s21_sprintf_10);
  tcase_add_test(tc, s21_sprintf_11);

  suite_add_tcase(s, tc);
  return s;
}
