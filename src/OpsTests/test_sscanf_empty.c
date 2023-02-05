#include "test_me.h"



Suite *test_s21_sscanf_empty(void) {
  Suite *s = suite_create("\033[45m-=S21_s21_SSCANF_EMPTY=-\033[0m");
  TCase *tc = tcase_create("s21_sscanf_tc");

  tcase_add_test(tc, s21_sscanf_5);
  tcase_add_test(tc, s21_sscanf_6);
  tcase_add_test(tc, s21_sscanf_7);
  tcase_add_test(tc, s21_sscanf_8);
  tcase_add_test(tc, s21_sscanf_9);
  tcase_add_test(tc, s21_sscanf_10);
  tcase_add_test(tc, s21_sscanf_11);

  suite_add_tcase(s, tc);
  return s;
}
